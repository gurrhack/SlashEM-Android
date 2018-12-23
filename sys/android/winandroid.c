#include <string.h>
#include <errno.h>
#include <jni.h>

#include "hack.h"
#include "winandroid.h"
#include "func_tab.h"   /* for extended commands */
#include "dlb.h"

extern short glyph2tile[];

struct window_procs and_procs = {
	"and",
	WC_COLOR | WC_HILITE_PET, /* window port capability options supported */
	0, /* additional window port capability options supported */
	and_init_nhwindows,
	and_player_selection,
	and_askname,
	and_get_nh_event,
	and_exit_nhwindows,
	and_suspend_nhwindows,
	and_resume_nhwindows,
	and_create_nhwindow,
	and_clear_nhwindow,
	and_display_nhwindow,
	and_destroy_nhwindow,
	and_curs,
	and_putstr,
	and_display_file,
	and_start_menu,
	and_add_menu,
	and_end_menu,
	and_select_menu,
	genl_message_menu,
	and_update_inventory,
	and_mark_synch,
	and_wait_synch,
#ifdef CLIPPING
	and_cliparound,
#endif
#ifdef POSITIONBAR
	and_update_positionbar,
#endif
	and_print_glyph,
	and_raw_print,
	and_raw_print_bold,
	and_nhgetch,
	and_nh_poskey,
	and_nhbell,
	and_doprev_message,
	and_yn_function,
	and_getlin,
	and_get_ext_cmd,
	and_number_pad,
	and_delay_output,
#ifdef CHANGE_COLOR
	and_change_color,
	and_get_color_string,
#endif
	and_start_screen,
	and_end_screen,
	genl_outrip,
	and_preference_update
};

static void and_n_getline(const char* question, char* buf, int nMax, int showLog);
static void and_n_getline_r(const char* question, char* buf, int nMax, int showLog, int reentry);

//____________________________________________________________________________________
// Java objects. Make sure they are not garbage collected!
static JNIEnv* jEnv;
static jclass jApp;
static jobject jAppInstance;
static jmethodID jDebugLog;
static jmethodID jReceiveKey;
static jmethodID jReceivePosKey;
static jmethodID jCreateWindow;
static jmethodID jDisplayWindow;
static jmethodID jClearWindow;
static jmethodID jDestroyWindow;
static jmethodID jPutString;
static jmethodID jSetHealthColor;
static jmethodID jRedrawStatus;
static jmethodID jRawPrint;
static jmethodID jSetCursorPos;
static jmethodID jPrintTile;
static jmethodID jYNFunction;
static jmethodID jGetLine;
static jmethodID jStartMenu;
static jmethodID jAddMenu;
static jmethodID jEndMenu;
static jmethodID jSelectMenu;
static jmethodID jCliparound;
static jmethodID jDelayOutput;
static jmethodID jShowDPad;
static jmethodID jShowLog;
static jmethodID jSetUsername;
static jmethodID jSetNumPadOption;
static jmethodID jAskName;

static boolean quit_if_possible;

//____________________________________________________________________________________
//
// Helpers
//____________________________________________________________________________________
jbyteArray create_bytearray(const char* str)
{
	int len = str ? strlen(str) : 0;
	jbyteArray a = (*jEnv)->NewByteArray(jEnv, len);
	jbyte* e = (*jEnv)->GetByteArrayElements(jEnv, a, 0);
	memcpy(e, str, len);
	(*jEnv)->ReleaseByteArrayElements(jEnv, a, e, 0);
	return a;
	// return (*jEnv)->NewStringUTF(jEnv, str);
}

//____________________________________________________________________________________
void destroy_jobject(jstring jstr)
{
	(*jEnv)->DeleteLocalRef(jEnv, jstr);
}

#define JNICallV(func, ...) (*jEnv)->CallVoidMethod(jEnv, jAppInstance, func, ## __VA_ARGS__);
#define JNICallI(func, ...) (*jEnv)->CallIntMethod(jEnv, jAppInstance, func, ## __VA_ARGS__);
#define JNICallO(func, ...) (*jEnv)->CallObjectMethod(jEnv, jAppInstance, func, ## __VA_ARGS__);

//____________________________________________________________________________________
void Java_com_tbd_forkfront_NetHackIO_RunNetHack(JNIEnv* env, jobject thiz, jstring path, jstring username)
{
	char* params[10];
	const char* pChars;

	jEnv = env;
	jAppInstance = thiz;
	jApp = (*jEnv)->GetObjectClass(jEnv, jAppInstance);
	jDebugLog = (*jEnv)->GetMethodID(jEnv, jApp, "debugLog", "([B)V");
	jReceiveKey = (*jEnv)->GetMethodID(jEnv, jApp, "receiveKeyCmd", "()I");
	jReceivePosKey = (*jEnv)->GetMethodID(jEnv, jApp, "receivePosKeyCmd", "(I[I)I");
	jCreateWindow = (*jEnv)->GetMethodID(jEnv, jApp, "createWindow", "(I)I");
	jClearWindow = (*jEnv)->GetMethodID(jEnv, jApp, "clearWindow", "(II)V");
	jDisplayWindow = (*jEnv)->GetMethodID(jEnv, jApp, "displayWindow", "(II)V");
	jDestroyWindow = (*jEnv)->GetMethodID(jEnv, jApp, "destroyWindow", "(I)V");
	jPutString = (*jEnv)->GetMethodID(jEnv, jApp, "putString", "(II[BII)V");
	jSetHealthColor = (*jEnv)->GetMethodID(jEnv, jApp, "setHealthColor", "(I)V");
	jRedrawStatus = (*jEnv)->GetMethodID(jEnv, jApp, "redrawStatus", "()V");
	jRawPrint = (*jEnv)->GetMethodID(jEnv, jApp, "rawPrint", "(I[B)V");
	jSetCursorPos = (*jEnv)->GetMethodID(jEnv, jApp, "setCursorPos", "(III)V");
	jPrintTile = (*jEnv)->GetMethodID(jEnv, jApp, "printTile", "(IIIIIII)V");
	jYNFunction = (*jEnv)->GetMethodID(jEnv, jApp, "ynFunction", "([B[BI)V");
	jGetLine = (*jEnv)->GetMethodID(jEnv, jApp, "getLine", "([BIII)Ljava/lang/String;");
	jStartMenu = (*jEnv)->GetMethodID(jEnv, jApp, "startMenu", "(I)V");
	jAddMenu = (*jEnv)->GetMethodID(jEnv, jApp, "addMenu", "(IIIIII[BII)V");
	jEndMenu = (*jEnv)->GetMethodID(jEnv, jApp, "endMenu", "(I[B)V");
	jSelectMenu = (*jEnv)->GetMethodID(jEnv, jApp, "selectMenu", "(III)[I");
	jCliparound = (*jEnv)->GetMethodID(jEnv, jApp, "cliparound", "(IIII)V");
	jDelayOutput = (*jEnv)->GetMethodID(jEnv, jApp, "delayOutput", "()V");
	jShowDPad = (*jEnv)->GetMethodID(jEnv, jApp, "askDirection", "()V");
	jShowLog = (*jEnv)->GetMethodID(jEnv, jApp, "showLog", "(I)V");
	jSetUsername = (*jEnv)->GetMethodID(jEnv, jApp, "setUsername", "([B)V");
	jSetNumPadOption = (*jEnv)->GetMethodID(jEnv, jApp, "setNumPadOption", "(I)V");
	jAskName = (*jEnv)->GetMethodID(jEnv, jApp, "askName", "(I[Ljava/lang/String;)Ljava/lang/String;");

	if(!(jReceiveKey && jReceivePosKey && jCreateWindow && jClearWindow && jDisplayWindow &&
			jDestroyWindow && jPutString && jRawPrint && jSetCursorPos && jPrintTile &&
			jYNFunction && jGetLine && jStartMenu && jAddMenu && jEndMenu && jSelectMenu &&
			jCliparound && jDelayOutput && jShowDPad && jShowLog && jSetUsername &&
			jSetNumPadOption && jAskName && jSetHealthColor && jRedrawStatus))
	{
		debuglog("baaaaad");
		return;
	}

	pChars = (*jEnv)->GetStringUTFChars(jEnv, path, 0);
	if(chdir(pChars) != 0)
		debuglog("chdir failed %d", errno);
	(*jEnv)->ReleaseStringUTFChars(jEnv, path, pChars);

	params[0] = "slashem";
	params[1] = 0;

	NetHackMain(1, params);
}

//____________________________________________________________________________________
boolean SaveAndExit()
{
	if(!program_state.gameover && program_state.something_worth_saving)
	{
		program_state.done_hup = 0;
		clear_nhwindow(WIN_MESSAGE);
		pline("Saving...");
		if(dosave0())
		{
			program_state.something_worth_saving = 0;
			u.uhp = -1;		/* universal game's over indicator */
			/* make sure they see the Saving message */
			display_nhwindow(WIN_MESSAGE, TRUE);
			exit_nhwindows("Be seeing you...");
			terminate(EXIT_SUCCESS);
		}
		return FALSE;
	}
	return TRUE;
}

//____________________________________________________________________________________
void Java_com_tbd_forkfront_NetHackIO_SaveNetHackState(JNIEnv* env, jobject thiz)
{
	if(!program_state.gameover && program_state.something_worth_saving)
		save_currentstate();
}

//____________________________________________________________________________________
void quit_possible()
{
	if(quit_if_possible)
	{
		quit_if_possible = FALSE;
		if(!SaveAndExit())
		{
			if(and_yn_function("Error saving game. Quit anyway?", ynchars, 'n') == 'y')
				terminate(EXIT_SUCCESS);
		}
	}
}

//____________________________________________________________________________________
void setUsername()
{
	jstring username = create_bytearray(plname);
	JNICallV(jSetUsername, username);
	destroy_jobject(username);

}

//____________________________________________________________________________________
void debuglog(const char *fmt, ...)
{
	char buf[256];

	if(fmt != 0)
	{
		va_list args;
		va_start(args, fmt);
		vsnprintf(buf, sizeof(buf), fmt, args);
		va_end(args);
	}
	else
	{
		strcpy(buf, "(null)");
	}

	jbyteArray jstr = create_bytearray(buf);
	JNICallV(jDebugLog, jstr);
	destroy_jobject(jstr);
}

// For STATUS_COLORS
static int text_attribs = 0;
static int text_color = 0xffffffff;

void
term_start_attr(attr)
int attr;
{
	text_attribs |= 1<<attr;
}

void
term_end_attr(attr)
int attr;
{
	text_attribs &= ~(1<<attr);
}

void
term_start_color(color)
int color;
{
	text_color = nhcolor_to_RGB(color);
}

void
term_end_color()
{
	text_color = 0xffffffff;
}


//____________________________________________________________________________________
//init_nhwindows(int* argcp, char** argv)
//		-- Initialize the windows used by NetHack.  This can also
//		   create the standard windows listed at the top, but does
//		   not display them.
//		-- Any commandline arguments relevant to the windowport
//		   should be interpreted, and *argcp and *argv should
//		   be changed to remove those arguments.
//		-- When the message window is created, the variable
//		   iflags.window_inited needs to be set to TRUE.  Otherwise
//		   all plines() will be done via raw_print().
//		** Why not have init_nhwindows() create all of the "standard"
//		** windows?  Or at least all but WIN_INFO?	-dean
void and_init_nhwindows(int* argcp, char** argv)
{
	//debuglog("and_init_nhwindows()");
	iflags.window_inited = TRUE;
}

//____________________________________________________________________________________
//player_selection()
//		-- Do a window-port specific player type selection.  If
//		   player_selection() offers a Quit option, it is its
//		   responsibility to clean up and terminate the process.
//		   You need to fill in pl_character[0].
void and_player_selection()
{
	int i, result;
	char pick4u = 'n', thisch, lastch = 0;
	char pbuf[QBUFSZ], plbuf[QBUFSZ];
	//int state[] = {0,0,0,0};
	int state = 0;
	winid win;
	anything any;
	menu_item *selected = 0;

	//debuglog("and_player_selection()");

	/* prevent an unnecessary prompt */
	rigid_role_checks();

	while(flags.initalign < 0)
	{
		if(state < 2)
		{
			if(!state)
				flags.initrole = -1;
			flags.initrace = -1;
			state = 0;
		}
		else
			state &= 1;
		flags.initgend = -1;
		flags.initalign = -1;

		/* Select a role */
		result = 1;
		if(flags.initrole < 0)
		{
			/* Prompt for a role */
			win = create_nhwindow(NHW_MENU);
			and_start_menu(win);
			any.a_void = 0; /* zero out all bits */
			any.a_int = randrole()+1;
			and_add_menu(win, NO_GLYPH, &any, '*', 0, ATR_NONE, "Random", MENU_UNSELECTED);
			for(i = 0; roles[i].name.m; i++)
			{
				if(ok_role(i, flags.initrace, flags.initgend, flags.initalign))
				{
					any.a_int = i + 1; /* must be non-zero */
					thisch = lowc(roles[i].name.m[0]);
					if(thisch == lastch)
						thisch = highc(thisch);
					and_add_menu(win, NO_GLYPH, &any, thisch, 0, ATR_NONE, roles[i].name.m, MENU_UNSELECTED);
					lastch = thisch;
				}
			}
			and_end_menu(win, "Pick a role");
			result = and_select_menu(win, PICK_ONE, &selected);
			and_destroy_nhwindow(win);

			if(result > 0)
				flags.initrole = selected[0].item.a_int - 1;
			free((void*)selected), selected = 0;
		}

		if(result <= 0)
		{
		    clearlocks();
		    and_exit_nhwindows("bye");
		    terminate(EXIT_SUCCESS);
		}

		/* Select a race, if necessary */
		if(flags.initrace < 0)
			flags.initrace = pick_race(flags.initrole, flags.initgend, flags.initalign, PICK_RIGID);

		result = 1;
		if(flags.initrace < 0)
		{
			/* tty_clear_nhwindow(BASE_WINDOW); */
			/* tty_putstr(BASE_WINDOW, 0, "Choosing Race"); */
			win = create_nhwindow(NHW_MENU);
			and_start_menu(win);
			any.a_void = 0; /* zero out all bits */
			any.a_int = randrace(flags.initrole)+1;
			and_add_menu(win, NO_GLYPH, &any, '*', 0, ATR_NONE, "random", MENU_UNSELECTED);
			for(i = 0; races[i].noun; i++)
				if(ok_race(flags.initrole, i, flags.initgend, flags.initalign))
				{
					any.a_int = i + 1; /* must be non-zero */
					and_add_menu(win, NO_GLYPH, &any, races[i].noun[0], 0, ATR_NONE, races[i].noun, MENU_UNSELECTED);
				}
			and_end_menu(win, "Pick a race");
			result = and_select_menu(win, PICK_ONE, &selected);
			and_destroy_nhwindow(win);

			if(result > 0)
			{
				flags.initrace = selected[0].item.a_int - 1;
				state |= 1;
			}
			free((void*)selected), selected = 0;
		}

		if(result <= 0)
			continue;

		/* Select a gender, if necessary */
		flags.initgend = pick_gend(flags.initrole, flags.initrace, flags.initalign, PICK_RIGID);

		result = 1;
		/* force compatibility with role/race, try for compatibility with
		 * pre-selected alignment */
		if(flags.initgend < 0)
		{
			/* tty_clear_nhwindow(BASE_WINDOW); */
			/* tty_putstr(BASE_WINDOW, 0, "Choosing Gender"); */
			win = create_nhwindow(NHW_MENU);
			and_start_menu(win);
			any.a_void = 0; /* zero out all bits */
			any.a_int = randgend(flags.initrole, flags.initrace)+1;
			and_add_menu(win, NO_GLYPH, &any, '*', 0, ATR_NONE, "random", MENU_UNSELECTED);
			for(i = 0; i < ROLE_GENDERS; i++)
				if(ok_gend(flags.initrole, flags.initrace, i, flags.initalign))
				{
					any.a_int = i + 1;
					and_add_menu(win, NO_GLYPH, &any, genders[i].adj[0], 0, ATR_NONE, genders[i].adj, MENU_UNSELECTED);
				}
			and_end_menu(win, "Pick a gender");
			result = and_select_menu(win, PICK_ONE, &selected);
			and_destroy_nhwindow(win);

			if(result > 0)
			{
				flags.initgend = selected[0].item.a_int - 1;
				state |= 2;
			}
			free((void*)selected), selected = 0;
		}

		if(result <= 0)
			continue;

		/* Select an alignment, if necessary */
		flags.initalign = pick_align(flags.initrole, flags.initrace, flags.initgend, PICK_RIGID);

		result = 1;
		if(flags.initalign < 0)
		{
			/* tty_clear_nhwindow(BASE_WINDOW); */
			/* tty_putstr(BASE_WINDOW, 0, "Choosing Alignment"); */
			win = and_create_nhwindow(NHW_MENU);
			and_start_menu(win);
			any.a_void = 0; /* zero out all bits */
			any.a_int = randalign(flags.initrole, flags.initrace)+1;
			and_add_menu(win, NO_GLYPH, &any, '*', 0, ATR_NONE, "random", MENU_UNSELECTED);
			for(i = 0; i < ROLE_ALIGNS; i++)
				if(ok_align(flags.initrole, flags.initrace, flags.initgend, i))
				{
					any.a_int = i + 1;
					and_add_menu(win, NO_GLYPH, &any, aligns[i].adj[0], 0, ATR_NONE, aligns[i].adj, MENU_UNSELECTED);
				}
			and_end_menu(win, "Pick an alignment");
			result = and_select_menu(win, PICK_ONE, &selected);
			and_destroy_nhwindow(win);

			if(result > 0)
				flags.initalign = selected[0].item.a_int - 1;
			free((void*)selected), selected = 0;
		}
	}
}

//____________________________________________________________________________________
//get_nh_event()	-- Does window event processing (e.g. exposure events).
//		   A noop for the tty and X window-ports.
void and_get_nh_event()
{
}

//____________________________________________________________________________________
//exit_nhwindows(str)
//		-- Exits the window system.  This should dismiss all windows,
//		   except the "window" used for raw_print().  str is printed
//		   if possible.
void and_exit_nhwindows(const char *str)
{
	//debuglog("exit_nhwindows");
	iflags.window_inited = FALSE;
}

//____________________________________________________________________________________
//suspend_nhwindows(str)
//		-- Prepare the window to be suspended.
void and_suspend_nhwindows(const char *str)
{
}

//____________________________________________________________________________________
//resume_nhwindows()
//		-- Restore the windows after being suspended.
void and_resume_nhwindows()
{
}

//____________________________________________________________________________________
//window = create_nhwindow(type)
//		-- Create a window of type "type."
winid and_create_nhwindow(int type)
{
	return JNICallI(jCreateWindow, type);
}

//____________________________________________________________________________________
//clear_nhwindow(window)
//		-- Clear the given window, when appropriate.
void and_clear_nhwindow(winid wid)
{
#ifdef REINCARNATION
	int isRogueLevel = Is_rogue_level(&u.uz);
#else
	int isRogueLevel = 0;
#endif

	//debuglog("and_clear_nhwindow(%d)", wid);
	JNICallV(jClearWindow, wid, isRogueLevel);
}

//____________________________________________________________________________________
//display_nhwindow(window, boolean blocking)
//		-- Display the window on the screen.  If there is data
//		   pending for output in that window, it should be sent.
//		   If blocking is TRUE, display_nhwindow() will not
//		   return until the data has been displayed on the screen,
//		   and acknowledged by the user where appropriate.
//		-- All calls are blocking in the tty window-port.
//		-- Calling display_nhwindow(WIN_MESSAGE,???) will do a
//		   --more--, if necessary, in the tty window-port.
void and_display_nhwindow(winid wid, BOOLEAN_P blocking)
{
	//debuglog("display_nhwindow(%d)", wid);
	if(wid != WIN_MESSAGE && /*wid != WIN_STATUS && */wid != WIN_MAP)
		blocking = TRUE;
	JNICallV(jDisplayWindow, wid, blocking);
	if(blocking)
		and_nhgetch();
}

//____________________________________________________________________________________
//destroy_nhwindow(window)
//		-- Destroy will dismiss the window if the window has not
//		   already been dismissed.
void and_destroy_nhwindow(winid wid)
{
	JNICallV(jDestroyWindow, wid);
}

//____________________________________________________________________________________
//curs(window, x, y)
//		-- Next output to window will start at (x,y), also moves
//		   displayable cursor to (x,y).  For backward compatibility,
//		   1 <= x < cols, 0 <= y < rows, where cols and rows are
//		   the size of window.
//		-- For variable sized windows, like the status window, the
//		   behavior when curs() is called outside the window's limits
//		   is unspecified. The mac port wraps to 0, with the status
//		   window being 2 lines high and 80 columns wide.
//		-- Still used by curs_on_u(), status updates, screen locating
//		   (identify, teleport).
//		-- NHW_MESSAGE, NHW_MENU and NHW_TEXT windows do not
//		   currently support curs in the tty window-port.
void and_curs(winid wid, int x, int y)
{
	JNICallV(jSetCursorPos, wid, x, y);
}

//____________________________________________________________________________________
//putstr(window, attr, str)
//		-- Print str on the window with the given attribute.  Only
//		   printable ASCII characters (040-0126) must be supported.
//		   Multiple putstr()s are output on separate lines.  Attributes
//		   can be one of
//			ATR_NONE (or 0)
//			ATR_ULINE
//			ATR_BOLD
//			ATR_BLINK
//			ATR_INVERSE
//		   If a window-port does not support all of these, it may map
//		   unsupported attributes to a supported one (e.g. map them
//		   all to ATR_INVERSE).  putstr() may compress spaces out of
//		   str, break str, or truncate str, if necessary for the
//		   display.  Where putstr() breaks a line, it has to clear
//		   to end-of-line.
//		-- putstr should be implemented such that if two putstr()s
//		   are done consecutively the user will see the first and
//		   then the second.  In the tty port, pline() achieves this
//		   by calling more() or displaying both on the same line.
//____________________________________________________________________________________
void and_putstr_ex(winid wid, int attr, const char *str, int append)
{
	jbyteArray jstr = create_bytearray(str);

	if(wid == NHW_STATUS)
	{
		if(flags.botlx)
			append = 0;
		else
			append = 1;
	}
	if(attr)
		attr = 1<<attr;
	else
		attr = text_attribs;

	JNICallV(jPutString, wid, attr, jstr, append, text_color);
	destroy_jobject(jstr);
}

void and_putstr(winid wid, int attr, const char *str)
{
	and_putstr_ex(wid, attr, str, 0);
}

void and_set_health_color(struct color_option colop)
{
	JNICallV(jSetHealthColor, nhcolor_to_RGB(colop.color));
}

void and_bot_updated()
{
	JNICallV(jRedrawStatus);
}

//____________________________________________________________________________________
//display_file(str, boolean complain)
//		-- Display the file named str.  Complain about missing files
//		   iff complain is TRUE.
void and_display_file(const char *name, BOOLEAN_P complain)
{
	//debuglog("and_display_file(%s, %d)", name, complain);

	dlb* f;
	char buf[BUFSZ];
	char *cr;

	and_clear_nhwindow(WIN_MESSAGE);
	f = dlb_fopen(name, "r");
	if(f)
	{
		winid datawin = and_create_nhwindow(NHW_TEXT);
		boolean empty = TRUE;
		while(dlb_fgets(buf, BUFSZ, f))
		{
			if((cr = index(buf, '\n')) != 0)
				*cr = 0;
			if(index(buf, '\t') != 0)
				(void)tabexpand(buf);
			empty = FALSE;
			and_putstr(datawin, 0, buf);
		}
		(void)dlb_fclose(f);
		if(!empty)
			and_display_nhwindow(datawin, TRUE);
		and_destroy_nhwindow(datawin);
	}
}

//____________________________________________________________________________________
//start_menu(window)
//		-- Start using window as a menu.  You must call start_menu()
//		   before add_menu().  After calling start_menu() you may not
//		   putstr() to the window.  Only windows of type NHW_MENU may
//		   be used for menus.
void and_start_menu(winid wid)
{
	JNICallV(jStartMenu, wid);
}

//____________________________________________________________________________________
//add_menu(windid window, int glyph, const anything identifier,
//				char accelerator, char groupacc,
//				int attr, char *str, boolean preselected)
//		-- Add a text line str to the given menu window.  If identifier
//		   is 0, then the line cannot be selected (e.g. a title).
//		   Otherwise, identifier is the value returned if the line is
//		   selected.  Accelerator is a keyboard key that can be used
//		   to select the line.  If the accelerator of a selectable
//		   item is 0, the window system is free to select its own
//		   accelerator.  It is up to the window-port to make the
//		   accelerator visible to the user (e.g. put "a - " in front
//		   of str).  The value attr is the same as in putstr().
//		   Glyph is an optional glyph to accompany the line.  If
//		   window port cannot or does not want to display it, this
//		   is OK.  If there is no glyph applicable, then this
//		   value will be NO_GLYPH.
//		-- All accelerators should be in the range [A-Za-z],
//		   but there are a few exceptions such as the tty player
//		   selection code which uses '*'.
//	        -- It is expected that callers do not mix accelerator
//		   choices.  Either all selectable items have an accelerator
//		   or let the window system pick them.  Don't do both.
//		-- Groupacc is a group accelerator.  It may be any character
//		   outside of the standard accelerator (see above) or a
//		   number.  If 0, the item is unaffected by any group
//		   accelerator.  If this accelerator conflicts with
//		   the menu command (or their user defined alises), it loses.
//		   The menu commands and aliases take care not to interfere
//		   with the default object class symbols.
//		-- If you want this choice to be preselected when the
//		   menu is displayed, set preselected to TRUE.
#ifdef MENU_COLOR
extern struct menucoloring *menu_colorings;
STATIC_OVL boolean
get_menu_coloring(str, color, attr)
char *str;
int *color, *attr;
{
	struct menucoloring *tmpmc;
	if (iflags.use_menu_color)
	for (tmpmc = menu_colorings; tmpmc; tmpmc = tmpmc->next)
#ifdef USE_REGEX_MATCH
#ifdef GNU_REGEX
	if (re_search(&tmpmc->match, str, strlen(str), 0, 9999, 0) >= 0) {
#else
#ifdef POSIX_REGEX
	if (regexec(&tmpmc->match, str, 0, NULL, 0) == 0) {
#endif
#endif
#else
	if (pmatch(tmpmc->match, str)) {
#endif
		*color = tmpmc->color;
		*attr = tmpmc->attr;
		return TRUE;
	}
	return FALSE;
}
#endif /* MENU_COLOR */
void and_add_menu(winid wid, int glyph, const ANY_P *ident, CHAR_P accelerator, CHAR_P groupacc, int attr, const char *str, BOOLEAN_P preselected)
{
	int tile, color;
	if(glyph == NO_GLYPH)
		tile = -1;
	else
		tile = glyph2tile[glyph];

#ifdef MENU_COLOR
	if(iflags.use_menu_color && get_menu_coloring((char*)str, &color, &attr)) {
		color = nhcolor_to_RGB(color);
	} else
#endif
	{
		color = -1;
	}

	jbyteArray jstr = create_bytearray(str);
	JNICallV(jAddMenu, wid, tile, ident->a_int, (int)accelerator, (int)groupacc, 1<<attr, jstr, (int)preselected, color);
	destroy_jobject(jstr);
}

//____________________________________________________________________________________
//end_menu(window, prompt)
//		-- Stop adding entries to the menu and flushes the window
//		   to the screen (brings to front?).  Prompt is a prompt
//		   to give the user.  If prompt is NULL, no prompt will
//		   be printed.
//		** This probably shouldn't flush the window any more (if
//		** it ever did).  That should be select_menu's job.  -dean
void and_end_menu(winid wid, const char *prompt)
{
	jbyteArray jstr;
	if(prompt)
		jstr = create_bytearray(prompt);
	else
		jstr = create_bytearray("");
	JNICallV(jEndMenu, wid, jstr);
	destroy_jobject(jstr);
}

//____________________________________________________________________________________
//int select_menu(windid window, int how, menu_item **selected)
//		-- Return the number of items selected; 0 if none were chosen,
//		   -1 when explicitly cancelled.  If items were selected, then
//		   selected is filled in with an allocated array of menu_item
//		   structures, one for each selected line.  The caller must
//		   free this array when done with it.  The "count" field
//		   of selected is a user supplied count.  If the user did
//		   not supply a count, then the count field is filled with
//		   -1 (meaning all).  A count of zero is equivalent to not
//		   being selected and should not be in the list.  If no items
//		   were selected, then selected is NULL'ed out.  How is the
//		   mode of the menu.  Three valid values are PICK_NONE,
//		   PICK_ONE, and PICK_ANY, meaning: nothing is selectable,
//		   only one thing is selectable, and any number valid items
//		   may selected.  If how is PICK_NONE, this function should
//		   never return anything but 0 or -1.
//		-- You may call select_menu() on a window multiple times --
//		   the menu is saved until start_menu() or destroy_nhwindow()
//		   is called on the window.
//		-- Note that NHW_MENU windows need not have select_menu()
//		   called for them. There is no way of knowing whether
//		   select_menu() will be called for the window at
//		   create_nhwindow() time.
int and_select_menu(winid wid, int how, MENU_ITEM_P **selected)
{
	return and_select_menu_r(wid, how, selected, 0);
}

int and_select_menu_r(winid wid, int how, MENU_ITEM_P **selected, int reentry)
{
	int i, n;
	jintArray a;
	jint* p;
	jint* q;

	//debuglog("and_select_menu");

	a = (jintArray)JNICallO(jSelectMenu, wid, how, reentry);

	*selected = 0;

	//debuglog("returned %d", a);
	if(a == 0)
		return -1;

	n = (*jEnv)->GetArrayLength(jEnv, a);

	if(n > 1) // n should always be 2k (id, count) pairs
	{
		n >>= 1;

		q = p = (*jEnv)->GetIntArrayElements(jEnv, a, 0);
		*selected = (MENU_ITEM_P*)malloc(sizeof(MENU_ITEM_P) * n);
		for(i = 0; i < n; i++)
		{
			(*selected)[i].item.a_int = *p++;
			(*selected)[i].count = *p++;
		}
		(*jEnv)->ReleaseIntArrayElements(jEnv, a, q, 0);
	}
	else if(n == 1)
	{
		// special case: ABORT
		if(!program_state.gameover && program_state.something_worth_saving)
			n = 0;
		else
			n = and_select_menu_r(wid, how, selected, 1);
	}

	destroy_jobject(a);

	return n;
}

//____________________________________________________________________________________
//update_inventory()
//		-- Indicate to the window port that the inventory has been
//		   changed.
//		-- Merely calls display_inventory() for window-ports that
//		   leave the window up, otherwise empty.
void and_update_inventory()
{
	//debuglog("and_update_inventory");
}

//____________________________________________________________________________________
//mark_synch()	-- Don't go beyond this point in I/O on any channel until
//		   all channels are caught up to here.  Can be an empty call
//		   for the moment
void and_mark_synch()
{
	//debuglog("and_mark_synch");
}

//____________________________________________________________________________________
//wait_synch()	-- Wait until all pending output is complete (*flush*() for
//		   streams goes here).
//		-- May also deal with exposure events etc. so that the
//		   display is OK when return from wait_synch().
void and_wait_synch()
{
	//debuglog("and_wait_synch");
}

//____________________________________________________________________________________
#ifdef CLIPPING
//cliparound(x, y)-- Make sure that the user is more-or-less centered on the
//		   screen if the playing area is larger than the screen.
//		-- This function is only defined if CLIPPING is defined.
void and_cliparound(int x, int y)
{
	//debuglog("and_cliparound %dx%d (%dx%d)", x, y, u.ux, u.uy);
	JNICallV(jCliparound, x, y, u.ux, u.uy);
}

#endif

//____________________________________________________________________________________
#ifdef POSITIONBAR
//update_positionbar(char *features)
//		-- Optional, POSITIONBAR must be defined. Provide some
//		   additional information for use in a horizontal
//		   position bar (most useful on clipped displays).
//		   Features is a series of char pairs.  The first char
//		   in the pair is a symbol and the second char is the
//		   column where it is currently located.
//		   A '<' is used to mark an upstairs, a '>'
//		   for a downstairs, and an '@' for the current player
//		   location. A zero char marks the end of the list.
void and_update_positionbar(char *features)
{
	//debuglog("and_update_positionbar");
}

#endif

//____________________________________________________________________________________
//print_glyph(window, x, y, glyph)
//		-- Print the glyph at (x,y) on the given window.  Glyphs are
//		   integers at the interface, mapped to whatever the window-
//		   port wants (symbol, font, color, attributes, ...there's
//		   a 1-1 map between glyphs and distinct things on the map).

int nhcolor_to_RGB(int c)
{
	switch(c)
	{
	case CLR_BLACK:
		return 0xFF555555;
	case CLR_RED:
		return 0xFFFF0000;
	case CLR_GREEN:
		return 0xFF008000;
	case CLR_BROWN:
		return 0xFF4d2121;//A52A2A;
	case CLR_BLUE:
		return 0xFF0000FF;
	case CLR_MAGENTA:
		return 0xFFFF00FF;
	case CLR_CYAN:
		return 0xFF00FFFF;
	case CLR_GRAY:
		return 0xFF909090;
	case NO_COLOR:
		return 0xFFFFFFFF;
	case CLR_ORANGE:
		return 0xFFFFA500;
	case CLR_BRIGHT_GREEN:
		return 0xFF00FF00;
	case CLR_YELLOW:
		return 0xFFFFFF00;
	case CLR_BRIGHT_BLUE:
		return 0xFF00C0FF;
	case CLR_BRIGHT_MAGENTA:
		return 0xFFFF80FF;
	case CLR_BRIGHT_CYAN:
		return 0xFF80FFFF; /* something close to aquamarine */
	case CLR_WHITE:
		return 0xFFFFFFFF;
	default:
		return 0xFF000000; /* black */
	}
}

void and_print_glyph(winid wid, XCHAR_P x, XCHAR_P y, int glyph)
{
	//debuglog("and_print_glyph wid=%d %dx%d", wid, x, y);
	int tile;
	if(glyph == NO_GLYPH)
		tile = -1;
	else
		tile = glyph2tile[glyph];
	int ch;
	int col;
	int special;
	mapglyph(glyph, &ch, &col, &special, x, y);

	special &= ~(MG_CORPSE|MG_INVIS|MG_RIDDEN); // TODO support
	if(!iflags.hilite_pet)
		special &= ~MG_PET;
	//if(!iflags.hilite_pile)
	//	special &= ~MG_OBJPILE;
	if(!iflags.use_inverse)
		special &= ~MG_DETECT;

	JNICallV(jPrintTile, wid, x, y, tile, ch, nhcolor_to_RGB(col), special);
}

//____________________________________________________________________________________
// raw_print(str)	-- Print directly to a screen, or otherwise guarantee that
// 		   the user sees str.  raw_print() appends a newline to str.
// 		   It need not recognize ASCII control characters.  This is
// 		   used during startup (before windowing system initialization
// 		   -- maybe this means only error startup messages are raw),
// 		   for error messages, and maybe other "msg" uses.  E.g.
// 		   updating status for micros (i.e, "saving").
void and_raw_print(const char* str)
{
	jbyteArray jstr = create_bytearray(str);
	JNICallV(jRawPrint, ATR_NONE, jstr);
	destroy_jobject(jstr);
}

//____________________________________________________________________________________
// raw_print_bold(str)
// 		-- Like raw_print(), but prints in bold/standout (if possible).
void and_raw_print_bold(const char* str)
{
	jbyteArray jstr = create_bytearray(str);
	JNICallV(jRawPrint, ATR_BOLD, jstr);
	destroy_jobject(jstr);
}

//____________________________________________________________________________________
//int nhgetch()	-- Returns a single character input from the user.
//		-- In the tty window-port, nhgetch() assumes that tgetch()
//		   will be the routine the OS provides to read a character.
//		   Returned character _must_ be non-zero and it must be
//                   non meta-zero too (zero with the meta-bit set).
int and_nhgetch()
{
	//debuglog("and_nhgetch");
	int c = JNICallI(jReceiveKey);

	quit_if_possible = FALSE;
	if(c == 0x80)
	{
		if(!program_state.gameover && program_state.something_worth_saving)
		{
			c = '\033';
			quit_if_possible = TRUE;
		}
		else
			c = and_nhgetch();
	}
	return c;
}

void and_you_die()
{
	JNICallV(jShowLog, 1);
	and_nhgetch();
}

//____________________________________________________________________________________
//int nh_poskey(int *x, int *y, int *mod)
//		-- Returns a single character input from the user or a
//		   a positioning event (perhaps from a mouse).  If the
//		   return value is non-zero, a character was typed, else,
//		   a position in the MAP window is returned in x, y and mod.
//		   mod may be one of
//
//			CLICK_1		/* mouse click type 1 */
//			CLICK_2		/* mouse click type 2 */
//
//		   The different click types can map to whatever the
//		   hardware supports.  If no mouse is supported, this
//		   routine always returns a non-zero character.

// hack: don't accept dir commands from touch events when mouse is locked. translate to tile position instead
static boolean bMouseLock;
void lock_mouse_cursor(boolean bLock)
{
	bMouseLock = bLock;
}

int and_nh_poskey(int *x, int *y, int *mod)
{
	//debuglog("and_nh_poskey");
	jintArray a = (*jEnv)->NewIntArray(jEnv, 2);
	int c = JNICallI(jReceivePosKey, bMouseLock, a);
	if(!c)
	{
		int* e = (*jEnv)->GetIntArrayElements(jEnv, a, 0);
		*x = e[0];
		*y = e[1];
		*mod = CLICK_1;
		(*jEnv)->ReleaseIntArrayElements(jEnv, a, e, 0);
	}
	quit_if_possible = FALSE;
	if(c == 0x80)
	{
		if(!program_state.gameover && program_state.something_worth_saving)
		{
			c = '\033';
			quit_if_possible = TRUE;
		}
		else
			c = and_nh_poskey(x, y, mod);
	}
	destroy_jobject(a);
	return c;
}

//____________________________________________________________________________________
//nhbell()	-- Beep at user.  [This will exist at least until sounds are
//		   redone, since sounds aren't attributable to windows anyway.]
void and_nhbell()
{
//	debuglog("and_nhbell");
}

//____________________________________________________________________________________
//doprev_message()
//		-- Display previous messages.  Used by the ^P command.
//		-- On the tty-port this scrolls WIN_MESSAGE back one line.
int and_doprev_message()
{
//	debuglog("and_doprev_message");
	JNICallV(jShowLog, 1);
	and_nhgetch();
	return 0;
}

//____________________________________________________________________________________
// char yn_function(const char *ques, const char *choices, char default)
//		-- Print a prompt made up of ques, choices and default.
//		   Read a single character response that is contained in
//		   choices or default.  If choices is NULL, all possible
//		   inputs are accepted and returned.  This overrides
//		   everything else.  The choices are expected to be in
//		   lower case.  Entering ESC always maps to 'q', or 'n',
//		   in that order, if present in choices, otherwise it maps
//		   to default.  Entering any other quit character (SPACE,
//		   RETURN, NEWLINE) maps to default.
//		-- If the choices string contains ESC, then anything after
//		   it is an acceptable response, but the ESC and whatever
//		   follows is not included in the prompt.
//		-- If the choices string contains a '#' then accept a count.
//		   Place this value in the global "yn_number" and return '#'.
//		-- This uses the top line in the tty window-port, other
//		   ports might use a popup.
//		-- If choices is NULL, all possible inputs are accepted and
//		   returned, preserving case (upper or lower.) This means that
//		   if the calling function needs an exact match, it must handle
//		   user input correctness itself.
char and_yn_function(const char *question, const char *choices, CHAR_P def)
{
	char ch;
	char message[BUFSZ];
	char res_ch[2];
	boolean digit_ok, allow_num;
	int esc;
	int nChoices;

	if(choices)
	{
		nChoices = strlen(choices);
		esc = (int)index(choices, '\033');
		if(esc)
			esc -= (int)choices;
		else
			esc = -1;
	}
	else
	{
		esc = -1;
	}
	allow_num = choices && index(choices, '#');

	//if(choices)
	//	debuglog("yn %s [%s](%c)", question, choices, def);
	//else
	//	debuglog("yn %s", question);

	if(iflags.automenu && choices && nChoices <= 4 && esc < 0 && !allow_num)
	{
		int i;
		// pop up dialog
		jbyteArray jq = create_bytearray(question);
		jbyteArray jb = (*jEnv)->NewByteArray(jEnv, nChoices);
		jbyte* pTmp = (*jEnv)->GetByteArrayElements(jEnv, jb, 0);
		memcpy(pTmp, choices, nChoices);
		(*jEnv)->ReleaseByteArrayElements(jEnv, jb, pTmp, 0);
		JNICallV(jYNFunction, jq, jb, def);
		destroy_jobject(jq);
		destroy_jobject(jb);

		ch = and_nhgetch();
		return ch;
	}

	if(choices)
	{
		char choicebuf[QBUFSZ];

		strcpy(choicebuf, choices);
		if(esc >= 0)
		{
			/* anything beyond <esc> is hidden */
			choicebuf[esc] = '\0';
		}
		sprintf(message, "%s [%s]", question, choicebuf);
		if(def)
			sprintf(eos(message), "(%c) ", def);
	}
	else
	{
		strcpy(message, question);
		strcat(message, " ");
	}

	if(strstr(question, "what direction"))
	{
		// directional choice
		and_clear_nhwindow(WIN_MESSAGE);
		and_putstr(WIN_MESSAGE, ATR_BOLD, message);
		if(iflags.automenu)
		{
			JNICallV(jShowDPad);
			ch = and_nhgetch();
			return ch;
		}
		else
		{
			int x = u.ux, y = u.uy, mod = 0;
			int ch = and_nh_poskey(&x, &y, &mod);
			if(!ch)
			{
				x -= u.ux;
				y -= u.uy;
		        if(x > 2*abs(y))
		            x = 1, y = 0;
		        else if(y > 2*abs(x))
		            x = 0, y = 1;
		        else if(x < -2*abs(y))
		            x = -1, y = 0;
		        else if(y < -2*abs(x))
		            x = 0, y = -1;
		        else
		            x = sgn(x), y = sgn(y);

		        if(x == 0 && y == 0)	/* map click on player to "rest" command */
		        	ch = '.';
		        else
		        	ch = xytod(x, y);
			}
			return ch;
		}
	}

	// and_clear_nhwindow(WIN_MESSAGE);
	and_putstr(WIN_MESSAGE, ATR_BOLD, message);

	ch = 0;
	do
	{
		ch = and_nhgetch();
		if(choices)
			ch = lowc(ch);
		else
			break; /* If choices is NULL, all possible inputs are accepted and returned. */

		digit_ok = allow_num && digit(ch);
		if(ch == '\033')
		{
			if(index(choices, 'q'))
				ch = 'q';
			else if(index(choices, 'n'))
				ch = 'n';
			else
				ch = def;
			break;
		}
		else if(index(quitchars, ch))
		{
			ch = def;
			break;
		}
		else if(!index(choices, ch) && !digit_ok)
		{
			and_nhbell();
			ch = (char)0;
			/* and try again... */
		}
		else if(ch == '#' || digit_ok)
		{
			char z, digit_string[2];
			int n_len = 0;
			long value = 0;
			and_putstr_ex(WIN_MESSAGE, ATR_BOLD, "#", 1);
			n_len++;
			digit_string[1] = '\0';
			if(ch != '#')
			{
				digit_string[0] = ch;
				and_putstr_ex(WIN_MESSAGE, ATR_BOLD, digit_string, 1);
				n_len++;
				value = ch - '0';
				ch = '#';
			}
			do
			{ /* loop until we get a non-digit */
				z = lowc(readchar());
				if(digit(z))
				{
					value = (10 * value) + (z - '0');
					if(value < 0)
						break; /* overflow: try again */
					digit_string[0] = z;
					and_putstr(WIN_MESSAGE, ATR_BOLD, digit_string);
					n_len++;
				}
				else if(z == 'y' || index(quitchars, z))
				{
					if(z == '\033')
						value = -1; /* abort */
					z = '\n'; /* break */
				}
				else if(z == 0x7f)
				{
					if(n_len <= 1)
					{
						value = -1;
						break;
					}
					else
					{
						value /= 10;
						and_putstr_ex(WIN_MESSAGE, ATR_BOLD, digit_string, -2);
						n_len--;
					}
				}
				else
				{
					value = -1; /* abort */
					and_nhbell();
					break;
				}
			}
			while(z != '\n');
			if(value > 0)
				yn_number = value;
			else if(value == 0)
				ch = 'n'; /* 0 => "no" */
			else
			{ /* remove number from top line, then try again */
				and_putstr_ex(WIN_MESSAGE, ATR_BOLD, digit_string, -n_len-1);
				n_len = 0;
				ch = (char)0;
			}
		}
	}
	while(!ch);

	/* display selection in the message window */
	if(choices)
	{
		if(isprint(ch) && ch != '#')
		{
			res_ch[0] = ch;
			res_ch[1] = '\x0';
			and_putstr_ex(WIN_MESSAGE, ATR_BOLD, res_ch, 1);
		}
	}
	else
	{
		and_clear_nhwindow(WIN_MESSAGE);
	}

	return ch;
}

//____________________________________________________________________________________
void and_n_getline(const char* question, char* buf, int nMax, int showLog)
{
	and_n_getline_r(question, buf, nMax, showLog, 0);
}

void and_n_getline_r(const char* question, char* buf, int nMax, int showLog, int reentry)
{
	int i, n;
	const jchar* pChars;
	jstring jstr;
	jbyteArray jq;

	jq = create_bytearray(question);
	jstr = (jstring)JNICallO(jGetLine, jq, nMax, showLog, reentry);
	destroy_jobject(jq);


	n = (*jEnv)->GetStringLength(jEnv, jstr);
	if(n >= nMax)
		n = nMax - 1;
    i = 0;
	if(n > 0)
	{
		pChars = (*jEnv)->GetStringChars(jEnv, jstr, 0);
	//debuglog("    returned %c %s", *pChars, pChars);
		if(*pChars == 0x80)
		{
			// special case: ABORT
			if(!program_state.gameover && program_state.something_worth_saving)
			{
				buf[0] = '\033';
				i = 1;
			}
			else
			{
				(*jEnv)->ReleaseStringChars(jEnv, jstr, pChars);
				destroy_jobject(jstr);
				and_n_getline_r(question, buf, nMax, showLog, 1);
				return;
			}
		}
		else if(*pChars == '\033')
		{
			buf[0] = '\033';
			i = 1;
		}
		else
		{
			for(; i < n; i++)
			{
				if(isprint(pChars[i]))
					buf[i] = pChars[i];
				else
					buf[i] = '?';
			}
		}
		(*jEnv)->ReleaseStringChars(jEnv, jstr, pChars);
	}
	destroy_jobject(jstr);
	buf[i] = 0;
}

//____________________________________________________________________________________
// getlin(const char *ques, char *input)
//		-- Prints ques as a prompt and reads a single line of text,
//		   up to a newline.  The string entered is returned without the
//		   newline.  ESC is used to cancel, in which case the string
//		   "\033\000" is returned.
//		-- getlin() must call flush_screen(1) before doing anything.
//		-- This uses the top line in the tty window-port, other
//		   ports might use a popup.
//		-- getlin() can assume the input buffer is at least BUFSZ
//		   bytes in size and must truncate inputs to fit, including
//		   the nul character.
void and_getlin(const char *question, char *input)
{
//	debuglog("and_getlin '%s'", question);
	and_n_getline(question, input, BUFSZ, FALSE);
}

void and_getlin_log(const char *question, char *input)
{
	and_n_getline(question, input, BUFSZ, TRUE);
}

//____________________________________________________________________________________
//askname()	-- Ask the user for a player name.
void and_askname()
{
//	debuglog("ask name");

	int i, n, w;
	const jchar* pChars;
	jstring jstr;

	char** saves = get_saved_games();

	int nSaves = 0;
	while(saves && saves[nSaves])
		nSaves++;

	jclass stringClass = (*jEnv)->FindClass(jEnv, "java/lang/String");
	jobjectArray strings = (*jEnv)->NewObjectArray(jEnv, nSaves, stringClass, 0);
    for(i = 0; i < nSaves; i++)
    	(*jEnv)->SetObjectArrayElement(jEnv, strings, i, (*jEnv)->NewStringUTF(jEnv, saves[i]));

	jstr = (jstring)JNICallO(jAskName, PL_NSIZ, strings);

    for(i = 0; i < nSaves; i++)
    	destroy_jobject((*jEnv)->GetObjectArrayElement(jEnv, strings, i));
	destroy_jobject(strings);

	n = (*jEnv)->GetStringLength(jEnv, jstr) - 1;
	w = n;
	if(n >= PL_NSIZ)
		n = PL_NSIZ - 1;
    i = 0;
	if(n > 0)
	{
		pChars = (*jEnv)->GetStringChars(jEnv, jstr, 0);
		if(*pChars == 0x80 || *pChars == '\033')
		{
			clearlocks();
			and_exit_nhwindows("bye");
			terminate(EXIT_SUCCESS);
		}

		if( pChars[w] == '1' )
			wizard = TRUE;

		for(; i < n; i++)
		{
			if(isprint(pChars[i]))
				plname[i] = pChars[i];
			else
				plname[i] = '?';
		}
		(*jEnv)->ReleaseStringChars(jEnv, jstr, pChars);
	}
	plname[i] = 0;
	destroy_jobject(jstr);
}

//____________________________________________________________________________________
//int get_ext_cmd(void)
//		-- Get an extended command in a window-port specific way.
//		   An index into extcmdlist[] is returned on a successful
//		   selection, -1 otherwise.
int do_ext_cmd_menu()
{
//	debuglog("and_get_ext_cmd");

	winid wid;
	int i, count, what;
	menu_item *selected = NULL;
	anything any;
	char accelerator = 'a', tmp_acc = 0;
	const char *ptr;

	wid = and_create_nhwindow(NHW_MENU);
	and_start_menu(wid);
	// TODO fix too many items in menu causes crash
	for(i = 0; i<100&& (ptr = extcmdlist[i].ef_txt); i++)
	{
		any.a_int = i+1;
		and_add_menu(wid, NO_GLYPH, &any, accelerator, 0, ATR_NONE, ptr, FALSE);

		if(accelerator == 'z')
			accelerator = 'A';
		else if(accelerator == 'Z')
			accelerator = 0;
		else
			accelerator++;
	}
	and_end_menu(wid, "Extended command");
	count = and_select_menu(wid, PICK_ONE, &selected);
	what = count > 0 ? selected->item.a_int - 1 : -1;
	if(selected)
		free(selected);
	and_destroy_nhwindow(wid);

	return (what);
}

const char* complete_ext_cmd(const char* base)
{
	int i, icmd = -1;

	for(i = 0; extcmdlist[i].ef_txt != (char *)0; i++)
	{
		if(!strncmpi(base, extcmdlist[i].ef_txt, strlen(base)))
		{
			if(icmd == -1)	/* no matches yet */
				icmd = i;
			else			/* more than 1 match */
			    return 0;
		}
	}

	if(icmd >= 0)
		return extcmdlist[icmd].ef_txt;

	return 0;
}

void get_ext_cmd_auto(const char *query, register char *bufp)
{
	register int n = 0, nl = 0;
	const char* complete = 0;
	register int c;
	const int maxc = COLNO >= BUFSZ ? BUFSZ-1 : COLNO;

	pline("%s ", query);
	bufp[n] = 0;
	for(;;)
	{
		c = and_nhgetch();
		if(c == EOF || c == '\n')
		{
			bufp[n] = 0;
			break;
		}
		if(c == '\033')
		{
			complete = 0;
			bufp[0] = c;
			bufp[1] = 0;
			break;
		}
		if(c == 0x7f)
		{
			if(n > 0)
				bufp[--n] = 0;
		}
		else if(' ' <= (unsigned char) c && n < maxc)
		{
			bufp[n] = c;
			bufp[++n] = 0;
		}
		complete = complete_ext_cmd(bufp);
		and_putstr_ex(WIN_MESSAGE, ATR_NONE, bufp, -nl-1);
		if(complete)
			and_putstr_ex(WIN_MESSAGE, ATR_INVERSE, complete + n, 1);
		nl = complete ? strlen(complete) : n;
	}
	if(complete)
		strcpy(bufp, complete);
	clear_nhwindow(WIN_MESSAGE);	/* clean up after ourselves */
}


/*
 * Read in an extended command, doing command line completion.  We
 * stop when we have found enough characters to make a unique command.
 */
int do_ext_cmd_text()
{
	debuglog("do_ext_cmd_text");

	int i;
	char buf[BUFSZ];

	get_ext_cmd_auto("#", buf);

	(void) mungspaces(buf);
	if (buf[0] == 0 || buf[0] == '\033') return -1;

	for (i = 0; extcmdlist[i].ef_txt != (char *)0; i++)
		if (!strcmpi(buf, extcmdlist[i].ef_txt)) break;

#ifdef REDO
	if (!in_doagain) {
	    int j;
	    for (j = 0; buf[j]; j++)
		savech(buf[j]);
	    savech('\n');
	}
#endif

	if (extcmdlist[i].ef_txt == (char *)0) {
		pline("%s: unknown extended command.", buf);
		i = -1;
	}

	return i;
}


int and_get_ext_cmd()
{
	if(iflags.automenu)
		return do_ext_cmd_menu();
	return do_ext_cmd_text();
}

//____________________________________________________________________________________
//number_pad(state)
//		-- Initialize the number pad to the given state.
void and_number_pad(int state)
{
//	debuglog("and_number_pad(%d)", state);
	JNICallV(jSetNumPadOption, state);
}

//____________________________________________________________________________________
//delay_output()	-- Causes a visible delay of 50ms in the output.
//		   Conceptually, this is similar to wait_synch() followed
//		   by a nap(50ms), but allows asynchronous operation.
void and_delay_output()
{
//	debuglog("and_delay_output()");
	JNICallV(jDelayOutput);
}

//____________________________________________________________________________________
#ifdef CHANGE_COLOR
void and_change_color(int a,long b,int c)
{
//	debuglog("and_change_color(%d, %d, %d)", a, b, c);
}

//____________________________________________________________________________________
char* and_get_color_string()
{
//	debuglog("and_get_color_string");
	return "";
}
#endif

//____________________________________________________________________________________
//start_screen()	-- Only used on Unix tty ports, but must be declared for
//		   completeness.  Sets up the tty to work in full-screen
//		   graphics mode.  Look at win/tty/termcap.c for an
//		   example.  If your window-port does not need this function
//		   just declare an empty function.
void and_start_screen()
{
//	debuglog("and_start_screen");
}

//____________________________________________________________________________________
//end_screen()	-- Only used on Unix tty ports, but must be declared for
//		   completeness.  The complement of start_screen().
void and_end_screen()
{
//	debuglog("and_end_screen");
}

//____________________________________________________________________________________
//preference_update(preference)
//		-- The player has just changed one of the wincap preference
//		   settings, and the NetHack core is notifying your window
//		   port of that change.  If your window-port is capable of
//		   dynamically adjusting to the change then it should do so.
//		   Your window-port will only be notified of a particular
//		   change if it indicated that it wants to be by setting the
//		   corresponding bit in the wincap mask.
void and_preference_update(const char *pref)
{
//	debuglog("and_preference_update %s", pref);
	//genl_preference_update(pref);
}

int doshowlog()
{
//	debuglog("doshowlog");
	JNICallV(jShowLog, 0);
	return 0;
}

