 
#ifndef WINANDROID_H_
#define WINANDROID_H_

void and_init_nhwindows(int *, char **);
void and_player_selection(void);
void and_askname(void);
void and_get_nh_event(void) ;
void and_exit_nhwindows(const char *);
void and_suspend_nhwindows(const char *);
void and_resume_nhwindows(void);
winid and_create_nhwindow(int);
void and_clear_nhwindow(winid);
void and_display_nhwindow(winid, BOOLEAN_P);
void and_dismiss_nhwindow(winid);
void and_destroy_nhwindow(winid);
void and_curs(winid,int,int);
void and_putstr(winid, int, const char *);
void and_putmixed(winid, int, const char *);
void and_display_file(const char *, BOOLEAN_P);
void and_start_menu(winid);
void and_add_menu(winid,int,const ANY_P *, CHAR_P,CHAR_P,int,const char *, BOOLEAN_P);
void and_end_menu(winid, const char *);
int and_select_menu(winid, int, MENU_ITEM_P **);
char and_message_menu(CHAR_P, int, const char *);
void and_update_inventory(void);
void and_mark_synch(void);
void and_wait_synch(void);
#ifdef CLIPPING
void and_cliparound(int, int);
#endif
#ifdef POSITIONBAR
void and_update_positionbar(char *);
#endif
void and_print_glyph(winid,XCHAR_P,XCHAR_P,int);
void and_raw_print(const char *);
void and_raw_print_bold(const char *);
int and_nhgetch(void);
int and_nh_poskey(int *, int *, int *);
void and_nhbell(void);
int and_doprev_message(void);
char and_yn_function(const char *, const char *, CHAR_P);
void and_getlin(const char *,char *);
void and_getlin_log(const char *,char *);
int and_get_ext_cmd(void);
void and_number_pad(int);
void and_delay_output(void);
#ifdef CHANGE_COLOR
void and_change_color,(int color,long rgb,int reverse);
#ifdef MAC
void and_change_background,(int white_or_black);
short set_and_font_name(winid, char *);
#endif
char * and_get_color_string(void);
#endif
void and_start_screen(void);
void and_end_screen(void);
void and_preference_update(const char *);

int NetHackMain(int argc, char** argv);

#endif
