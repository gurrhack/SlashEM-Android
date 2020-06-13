/*	SCCS Id: @(#)exper.c	3.4	2002/11/20	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

#include "hack.h"

/*STATIC_DCL*/ long newuexp(int);
STATIC_DCL int enermod(int);

#ifndef OVLB

STATIC_DCL NEARDATA const short skill_names_indices[];
STATIC_DCL NEARDATA const char *odd_skill_names[];

#else	/* OVLB */

/* KMH, balance patch -- updated */
STATIC_OVL NEARDATA const short skill_names_indices[P_NUM_SKILLS] = {
	0,                DAGGER,         KNIFE,        AXE,
	PICK_AXE,         SHORT_SWORD,    BROADSWORD,   LONG_SWORD,
	TWO_HANDED_SWORD, SCIMITAR,       PN_SABER,     CLUB,
	PN_PADDLE,        MACE,           MORNING_STAR,   FLAIL,
	PN_HAMMER,        QUARTERSTAFF,   PN_POLEARMS,  SPEAR,
	JAVELIN,          TRIDENT,        LANCE,        BOW,
	SLING,            PN_FIREARMS,    CROSSBOW,       DART,
	SHURIKEN,         BOOMERANG,      PN_WHIP,      UNICORN_HORN,
	PN_LIGHTSABER,
	PN_ATTACK_SPELL,     PN_HEALING_SPELL,
	PN_DIVINATION_SPELL, PN_ENCHANTMENT_SPELL,
	PN_PROTECTION_SPELL,            PN_BODY_SPELL,
	PN_OCCULT_SPELL,
	PN_ELEMENTAL_SPELL,
	PN_CHAOS_SPELL,
	PN_MATTER_SPELL,
	PN_BARE_HANDED,	PN_HIGH_HEELS,
	PN_GENERAL_COMBAT,	PN_SHIELD,	PN_BODY_ARMOR,
	PN_TWO_HANDED_WEAPON,	PN_POLYMORPHING,	PN_DEVICES,
	PN_SEARCHING,	PN_SPIRITUALITY,	PN_PETKEEPING,
	PN_MISSILE_WEAPONS,	PN_TECHNIQUES,	PN_IMPLANTS,	PN_SEXY_FLATS,
	PN_MEMORIZATION,	PN_GUN_CONTROL,	PN_SQUEAKING,	PN_SYMBIOSIS,
	PN_SHII_CHO,	PN_MAKASHI,	PN_SORESU,
	PN_ATARU,	PN_SHIEN,	PN_DJEM_SO,
	PN_NIMAN,	PN_JUYO,	PN_VAAPAD,	PN_WEDI,
	PN_MARTIAL_ARTS, 
	PN_TWO_WEAPONS,
	PN_RIDING,
};


STATIC_OVL NEARDATA const char * const odd_skill_names[] = {
    "no skill",
    "polearms",
    "saber",
    "hammer",
    "whip",
    "paddle",
    "firearms",
    "attack spells",
    "healing spells",
    "divination spells",
    "enchantment spells",
    "protection spells",
    "body spells",
    "occult spells",
    "elemental spells",
    "chaos spells",
    "matter spells",
    "bare-handed combat",
    "high heels",
    "general combat",
    "shield",
    "body armor",
    "two-handed weapons",
    "polymorphing",
    "devices",
    "searching",
    "spirituality",
    "petkeeping",
    "missile weapons",
    "techniques",
    "implants",
    "sexy flats",
    "memorization",
    "gun control",
    "squeaking",
    "symbiosis",
    "form I (Shii-Cho)",
    "form II (Makashi)",
    "form III (Soresu)",
    "form IV (Ataru)",
    "form V (Shien)",
    "form V (Djem So)",
    "form VI (Niman)",
    "form VII (Juyo)",
    "form VII (Vaapad)",
    "form VIII (Wedi)",
    "martial arts",
    "riding",
    "two-weapon combat",
    "lightsaber"
};

#endif	/* OVLB */

#define P_NAME(type) (skill_names_indices[type] > 0 ? \
		      OBJ_NAME(objects[skill_names_indices[type]]) : \
			odd_skill_names[-skill_names_indices[type]])

/*STATIC_OVL*/ long
newuexp(lev)
int lev;
{
	/* KMH, balance patch -- changed again! */
	/*if (lev < 9) return (10L * (1L << lev));
	if (lev < 13) return (10000L * (1L << (lev - 9)));
	if (lev == 13) return (150000L);
	return (50000L * ((long)(lev - 9)));*/
	/*              Old XP routine */
	/* if (lev < 10) return (10L * (1L << lev));            */
	/* if (lev < 20) return (10000L * (1L << (lev - 10)));  */
	/* return (10000000L * ((long)(lev - 19)));             */
/*      if (lev == 1)  return (75L);
	if (lev == 2)  return (150L);
	if (lev == 3)  return (300L);
	if (lev == 4)  return (600L);
	if (lev == 5)  return (1200L); */

	/* completely overhauled by Amy */

	if (!issoviet) {

	if (lev == 1)  return (20L);     /* need 20           */
	if (lev == 2)  return (40L);    /* need 20           */
	if (lev == 3)  return (80L);    /* need 40          */
	if (lev == 4)  return (160L);    /* need 80          */
	if (lev == 5)  return (320L);   /* need 160          */
	if (lev == 6)  return (640L);   /* need 320          */
	if (lev == 7)  return (1280L);   /* need 640         */
	if (lev == 8)  return (2560L);   /* need 1280         */
	if (lev == 9)  return (5000L);   /* need 2440         */
	if (lev == 10) return (10000L);   /* need 5000         */
	if (lev == 11) return (20000L);  /* need 10000         */
	if (lev == 12) return (40000L);  /* need 20000         */
	if (lev == 13) return (80000L);  /* need 40000         */
	if (lev == 14) return (130000L);  /* need 50000         */
	if (lev == 15) return (200000L);  /* need 70000         */
	if (lev == 16) return (280000L);  /* need 80000         */
	if (lev == 17) return (380000L);  /* need 100000         */
	if (lev == 18) return (500000L);  /* need 120000        */
	if (lev == 19) return (650000L);  /* need 150000        */
	if (lev == 20) return (850000L);  /* need 200000        */
	if (lev == 21) return (1100000L); /* need 250000        */
	if (lev == 22) return (1400000L); /* need 300000        */
	if (lev == 23) return (1800000L); /* need 400000        */
	if (lev == 24) return (2300000L); /* need 500000        */
	if (lev == 25) return (3000000L); /* need 700000       */
	if (lev == 26) return (3800000L); /* need 800000       */
	if (lev == 27) return (4800000L); /* need 1000000       */
	if (lev == 28) return (6000000L); /* need 1200000       */
	if (lev == 29) return (8000000L); /* need 2000000      */
	return (15000000L);

	} else {

	if (lev == 1)  return (40L);
	if (lev == 2)  return (80L);
	if (lev == 3)  return (160L);
	if (lev == 4)  return (320L);
	if (lev == 5)  return (640L);
	if (lev == 6)  return (1280L);
	if (lev == 7)  return (2560L);
	if (lev == 8)  return (5120L);
	if (lev == 9)  return (10000L);
	if (lev == 10) return (20000L);
	if (lev == 11) return (40000L);
	if (lev == 12) return (80000L);
	if (lev == 13) return (130000L);
	if (lev == 14) return (200000L);
	if (lev == 15) return (280000L);
	if (lev == 16) return (380000L);
	if (lev == 17) return (480000L);
	if (lev == 18) return (580000L);
	if (lev == 19) return (680000L);
	if (lev == 20) return (850000L);
	if (lev == 21) return (1100000L);
	if (lev == 22) return (1400000L);
	if (lev == 23) return (1800000L);
	if (lev == 24) return (2300000L);
	if (lev == 25) return (3000000L);
	if (lev == 26) return (3800000L);
	if (lev == 27) return (4800000L);
	if (lev == 28) return (6000000L);
	if (lev == 29) return (8000000L);
	return (15000000L);

	}

}

STATIC_OVL int
enermod(en)
int en;
{
	switch (Role_switch) {
		/* WAC 'F' and 'I' get bonus similar to 'W' */
		case PM_FLAME_MAGE:
		case PM_ICE_MAGE:
		case PM_ELECTRIC_MAGE:
		case PM_POISON_MAGE:
		case PM_ACID_MAGE:
		case PM_OCCULT_MASTER:
		case PM_CHAOS_SORCEROR:
		case PM_ELEMENTALIST:
	case PM_PRIEST:
	case PM_WIZARD:
	    return(2 * en);
	case PM_HEALER:
	case PM_KNIGHT:
	    return((3 * en) / 2);
	case PM_BARBARIAN:
	case PM_VALKYRIE:
	    return((3 * en) / 4);
	default:
	    return (en);
	}
}

int
experience(mtmp, nk)	/* return # of exp points for mtmp after nk killed */
	register struct	monst *mtmp;
	register int	nk;
#if defined(MAC_MPW)
# pragma unused(nk)
#endif
{
	register struct permonst *ptr = mtmp->data;
	int	i, tmp, tmp2;

	tmp = 1 + mtmp->m_lev * mtmp->m_lev;

/*	For higher ac values, give extra experience */
	if ((i = find_mac(mtmp)) < 3) tmp += (7 - i) * ((i < 0) ? 2 : 1);

/*	For very fast monsters, give extra experience */
	if (ptr->mmove > NORMAL_SPEED)
	    tmp += (ptr->mmove > (3*NORMAL_SPEED/2)) ? 5 : 3;

/*	For each "special" attack type give extra experience */
	for(i = 0; i < NATTK; i++) {
	    tmp2 = ptr->mattk[i].aatyp;
	    if(tmp2 > AT_BUTT) {

		if(tmp2 == AT_WEAP) tmp += 5;
		else if(tmp2 == AT_MAGC) tmp += 10;
		else tmp += 3;
	    }
	}

/*	For each "special" damage type give extra experience */
	for(i = 0; i < NATTK; i++) {
	    tmp2 = ptr->mattk[i].adtyp;
	    if(tmp2 > AD_PHYS && tmp2 < AD_BLND) tmp += 2*mtmp->m_lev;
	    else if((tmp2 == AD_DRLI) || (tmp2 == AD_STON) ||
	    		(tmp2 == AD_SLIM)) tmp += 50;
	    else if(tmp != AD_PHYS) tmp += mtmp->m_lev;
		/* extra heavy damage bonus */
	    if((int)(ptr->mattk[i].damd * ptr->mattk[i].damn) > 23)
		tmp += mtmp->m_lev;
	    if (tmp2 == AD_WRAP && ptr->mlet == S_EEL) { /* edited by Amy */
		tmp *= 11;
		tmp /= 10;
	    }
	}

/*	For certain "extra nasty" monsters, give even more */
	if (extra_nasty(ptr)) tmp += (rnd(7) * mtmp->m_lev);

/*	For higher level monsters, an additional bonus is given */
	if(mtmp->m_lev > 8) tmp += 50;
	/* Amy edit: high experience levels require lots of XP, but high-level monsters don't give all that much more XP
	 * than low-level ones? gotta fix that... */
	if(mtmp->m_lev > 20) {
		int hilvlmod = (mtmp->m_lev - 19);
		tmp += (hilvlmod * hilvlmod);
	}
	if(mtmp->m_lev > 40) {
		int hilvlmod = (mtmp->m_lev - 39);
		tmp += (hilvlmod * hilvlmod * 100);
	}

#ifdef MAIL
	/* Mail daemons put up no fight. */
	if(mtmp->data == &mons[PM_MAIL_DAEMON]) tmp = 1;
#endif

	return(tmp);
}

void
more_experienced(exp, rexp)
	register int exp, rexp;
{
	if (u.uprops[ANTILEVELING].extrinsic || Antileveling || (uamul && uamul->oartifact == ART_NAZGUL_S_REVENGE) || have_antilevelstone() && !(u.ulevel < 10 && !rn2(u.ulevel + 1)) ) return;

	if ((exp > 0) && Race_if(PM_YEEK)) exp *= 2;
	if ((exp > 0) && uarmc && uarmc->oartifact == ART_TOO_MANY_AFFIXES) exp *= 2;
	if (uarmc && uarmc->oartifact == ART_ARTIFICIAL_FAKE_DIFFICULTY && (exp > 1)) exp /= 2;
	if (Race_if(PM_ETHEREALOID) && (exp > 1)) exp /= 2;

	u.uexp += exp;
	u.urexp += 4*exp + rexp;
	if(exp || flags.showscore) flags.botl = 1;
	if (u.urexp >= (Role_if(PM_WIZARD) ? 1000 : 2000))
		flags.beginner = 0;
}

void
losexp(drainer,force,dresistance)	/* e.g., hit by drain life attack */
const char *drainer;	/* cause of death, if drain should be fatal */
boolean force;		/* Force the loss of an experience level */
boolean dresistance;	/* level drain resistance can protect you */
{
	register int num;
	int expdrain;

#ifdef WIZARD
	/* explicit wizard mode requests to reduce level are never fatal. */
	if (drainer && !strcmp(drainer, "#levelchange"))
		drainer = 0;
#endif

	if (dresistance && Drain_resistance && rn2(StrongDrain_resistance ? 10 : 5) ) return;

	/* level drain is too strong. Let's nerf it a bit. --Amy */
	/* In Soviet Russia, level drain will always drain at least one level, because fuck you, stupid player. You're
	 * not supposed to stand a chance in this game. --Amy */
	if (!force && (u.uexp > 320) && !issoviet && u.ulevel > 1) {
		expdrain = newuexp(u.ulevel) - newuexp(u.ulevel - 1);
		expdrain /= (isfriday ? 3 : 5);
		expdrain = rnz(expdrain);
		if ((u.uexp - expdrain) > newuexp(u.ulevel - 1)) {
			/* drain some experience, but not enough to make you lose a level */
			You_feel("your life draining away!");
			if (PlayerHearsSoundEffects) pline(issoviet ? "Vy tol'ko chto poteryali odin uroven', skoro vy poteryayete vse urovni i umeret'." : "Due-l-ue-l-ue-l!");
			u.uexp -= expdrain;
			return;
		}
	} else if (!force && (u.uexp > 20) && (u.uexp <= 320) && !issoviet && u.ulevel > 1) {
		expdrain = newuexp(u.ulevel) - newuexp(u.ulevel - 1);
		expdrain /= (isfriday ? 3 : 5);
		expdrain *= 3;
		expdrain = rnz(expdrain);
		if ((u.uexp - expdrain) > newuexp(u.ulevel - 1)) {
			/* drain some experience, but not enough to make you lose a level */
			You_feel("your life draining away!");
			if (PlayerHearsSoundEffects) pline(issoviet ? "Vy tol'ko chto poteryali odin uroven', skoro vy poteryayete vse urovni i umeret'." : "Due-l-ue-l-ue-l!");
			u.uexp -= expdrain;
			return;
		}
	} else if (!force && (u.uexp > 10) && !issoviet && u.ulevel == 1) {
		expdrain = 20;
		expdrain /= (isfriday ? 3 : 5);
		expdrain *= 3;
		expdrain = rnz(expdrain);
		if ((u.uexp - expdrain) > 0) {
			/* drain some experience, but not enough to make you lose a level */
			You_feel("your life draining away!");
			if (PlayerHearsSoundEffects) pline(issoviet ? "Vy tol'ko chto poteryali odin uroven', skoro vy poteryayete vse urovni i umeret'." : "Due-l-ue-l-ue-l!");
			u.uexp -= expdrain;
			return;
		}
	}

	if (issoviet) pline("BWAR KHAR (gryaznyy smekh) govorit, chto tip bloka l'da!");

	if (u.ulevel > 1) {
		pline("%s level %d.", Goodbye(), u.ulevel--);
		if (PlayerHearsSoundEffects) pline(issoviet ? "Vy tol'ko chto poteryali odin uroven', skoro vy poteryayete vse urovni i umeret'." : "Due-l-ue-l-ue-l!");
		/* remove intrinsic abilities */
		adjabil(u.ulevel + 1, u.ulevel);
		reset_rndmonst(NON_PM);	/* new monster selection */
	} else {
		if (drainer) {
			u.youaredead = 1;
			killer_format = KILLED_BY;
			killer = drainer;
			done(DIED);
			u.youaredead = 0;
		}
		/* no drainer or lifesaved */
		u.uexp = 0;
	}
	num = newhp();
	u.uhpmax -= num;
	u.uhpmax -= rn2(3);
	u.uhpmax -= rnz(2);
	u.uhpmax -= rnz(3); /* making the drain for gain exploit much harder to perform --Amy */
	if (u.ulevel >= 19) u.uhpmax -= rnd(2);
	if (u.ulevel >= 24) u.uhpmax -= rnd(2);
	if (u.ulevel >= 27) u.uhpmax -= rnd(3);
	if (u.ulevel >= 29) u.uhpmax -= rnd(10);
	if (u.uhpmax < 1) u.uhpmax = 1;
	u.uhp -= num;
	u.uhp -= rn2(3);
	u.uhp -= rnz(3);
	u.uhp -= rnz(2);
	if (u.ulevel >= 19) u.uhp -= rnd(2);
	if (u.ulevel >= 24) u.uhp -= rnd(2);
	if (u.ulevel >= 27) u.uhp -= rnd(3);
	if (u.ulevel >= 29) u.uhp -= rnd(10);
	if (u.uhp < 1) u.uhp = 1;
	else if (u.uhp > u.uhpmax) u.uhp = u.uhpmax;

	/* screwy vanilla programmers... they were so lazy and forgot to make it so that your polymorph form gets drained! */
	if (Upolyd) {
		u.mhmax -= num;
		u.mhmax -= rn2(3);
		u.mhmax -= rnz(2);
		u.mhmax -= rnz(3); /* making the drain for gain exploit much harder to perform --Amy */
		if (u.ulevel >= 19) u.mhmax -= rnd(2);
		if (u.ulevel >= 24) u.mhmax -= rnd(2);
		if (u.ulevel >= 27) u.mhmax -= rnd(3);
		if (u.ulevel >= 29) u.mhmax -= rnd(10);
		if (u.mhmax < 1) u.mhmax = 1;
		u.mh -= num;
		u.mh -= rn2(3);
		u.mh -= rnz(3);
		u.mh -= rnz(2);
		if (u.ulevel >= 19) u.mh -= rnd(2);
		if (u.ulevel >= 24) u.mh -= rnd(2);
		if (u.ulevel >= 27) u.mh -= rnd(3);
		if (u.ulevel >= 29) u.mh -= rnd(10);
		if (u.mh < 1) u.mh = 1;
		else if (u.mh > u.mhmax) u.mh = u.mhmax;
	}

	if (u.ulevel < urole.xlev)
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.lornd + urace.enadv.lornd,
			urole.enadv.lofix + urace.enadv.lofix);
	else
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.hirnd + urace.enadv.hirnd,
			urole.enadv.hifix + urace.enadv.hifix);
	num = enermod(num);		/* M. Stephenson */
	u.uenmax -= num;
	u.uenmax -= rn2(3);
	u.uenmax -= rnz(3);
	u.uenmax -= (rn2(3) ? rnz(1) : rnz(2));
	if (u.uenmax < 0) u.uenmax = 0;
	u.uen -= num;
	u.uen -= rn2(3);
	u.uen -= rnz(3);
	if (u.uen < 0) u.uen = 0;
	else if (u.uen > u.uenmax) u.uen = u.uenmax;

	if (u.uexp > 0)
		u.uexp = newuexp(u.ulevel) - 1;
	flags.botl = 1;
}

/*
 * Make experience gaining similar to AD&D(tm), whereby you can at most go
 * up by one level at a time, extra expr possibly helping you along.
 * After all, how much real experience does one get shooting a wand of death
 * at a dragon created with a wand of polymorph??
 */
void
newexplevel()
{
	if (u.ulevel < MAXULEV && u.uexp >= newuexp(u.ulevel))
	    pluslvl(TRUE);
	else if (u.uexp >= (10000000 + (2000000 * u.xtralevelmult))) {
		You_feel("more experienced.");
		pluslvl(TRUE); /* will increase the xtralevelmult variable */
		/* leveling via EXP can keep giving you skill slots --Amy
		 * but now also via gain level, because that requires more and more potions, too
		 * effect moved to pluslvl() function */
	}
}

/* if your level is rather high already, gain level effects shouldn't always give you a full level --Amy
 * important: increase u.uexp value even when you have anti-experience! */
void
gainlevelmaybe()
{
	if (u.ulevel >= MAXULEV && ((u.uexp + 200000) < (10000000 + (2000000 * u.xtralevelmult)) ) ) {
		u.uexp += 200000;
		flags.botl = TRUE;
		You("gain experience.");
	} else if (u.ulevel < MAXULEV && ((u.uexp + 200000) < newuexp(u.ulevel)) ) {
		u.uexp += 200000;
		flags.botl = TRUE;
		You("gain experience.");
	} else pluslvl(FALSE);
}

void
pluslvl(incr)
boolean incr;	/* true iff via incremental experience growth */
{		/*	(false for potion of gain level)      */
	register int num;

	if (!incr) You_feel("more experienced.");

	if (u.ulevel >= MAXULEV) {
		u.uexp = 10000000; /* reset counter for gain level */
		u.xtralevelmult++;
		u.cnd_overlevelcount++;
		u.weapon_slots++; /* leveling past 30 can keep giving you skill slots --Amy */
	}

	if (u.ulevel < MAXULEV) {

	if ((!ishomicider || rn2(2)) && !((Deprovement || u.uprops[DEPROVEMENT].extrinsic || have_deprovementstone()) && !(u.ulevel < 10 && !rn2(u.ulevel + 1)) && rn2(10) )
) {	/* homicider only gains hp/pw 50% of the time --Amy */
	/* a.k.a. "bullshit downside that every fun new race gets" (term coined by Khor) */

	num = newhp();
	num += rnz(2);
	if (num < 0) num = 0;
	if (Race_if(PM_SPRIGGAN) && !rn2(2)) num = 0;
	num += rn2(3);
	if (u.ulevel >= 19) num += rnd(2);
	if (u.ulevel >= 24) num += rnd(2);
	if (u.ulevel >= 27) num += rnd(3);
	if (u.ulevel >= 29) num += rnd(10);

	if (Race_if(PM_YEEK) || Race_if(PM_DUFFLEPUD) || Race_if(PM_PLAYER_FAIRY)) num /= 2;
	if (Race_if(PM_PLAYER_DOLGSMAN)) {
		num *= 3;
		num /= 4;
	}

	u.uhpmax += num;
	u.uhp += num;

	if ((u.ulevel >= u.urmaxlvlUP && u.ulevel < 30) && !issoviet && (u.uhp < u.uhpmax)) u.uhp = u.uhpmax;
	if (issoviet) pline("Vy dazhe ne poluchayete polnyye linii, potomu chto sovetskiy ne ponimayet, kak rolevyye igry rabotayut!");
	/* In Soviet Russia, you don't get full health on leveling up because seriously, who needs that? --Amy */
	if (Upolyd) {
	    num = rnz(8); /* unfortunately will be lost upon unpolymorphing --Amy */
	    if (num < 0) num = 0;
	    num += rn2(3);

	    if (Race_if(PM_YEEK) || Race_if(PM_DUFFLEPUD) || Race_if(PM_PLAYER_FAIRY)) num /= 2;
	    if (Race_if(PM_PLAYER_DOLGSMAN)) {
		num *= 3;
		num /= 4;
	    }

	    u.mhmax += num;
	    u.mh += num;

		if ((u.ulevel >= u.urmaxlvlUP && u.ulevel < 30) && !issoviet && (u.mh < u.mhmax)) u.mh = u.mhmax;
	}
	if (u.ulevel < urole.xlev)
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.lornd + urace.enadv.lornd,
			urole.enadv.lofix + urace.enadv.lofix);
	else
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.hirnd + urace.enadv.hirnd,
			urole.enadv.hifix + urace.enadv.hifix);

	num = enermod(num);	/* M. Stephenson */
	num += (rn2(3) ? rnz(1) : rnz(2));
	if (num < 0) num = 0;
	num += rn2(3);

	if (Race_if(PM_YEEK) || Race_if(PM_DUFFLEPUD)) num /= 2;

	u.uenmax += num;
	u.uen += num;
	} /* homicider check */

	} else { /* u.ulevel > MAXULEV */

	if ((!ishomicider || rn2(2)) && !((Deprovement || u.uprops[DEPROVEMENT].extrinsic || have_deprovementstone()) && !(u.ulevel < 10 && !rn2(u.ulevel + 1)) && rn2(10) )
) {	/* homicider only gains hp/pw 50% of the time --Amy */
	/* a.k.a. "bullshit downside that every fun new race gets" (term coined by Khor) */

	num = newhp();
	num += rnz(2);
	if (num < 0) num = 0;
	if (num > 1) num /= rnd(12);
	if (Race_if(PM_SPRIGGAN) && !rn2(2)) num = 0;
	num += rn2(2);

	if (Race_if(PM_YEEK) || Race_if(PM_DUFFLEPUD) || Race_if(PM_PLAYER_FAIRY)) num /= 2;
	if (Race_if(PM_PLAYER_DOLGSMAN)) {
		num *= 3;
		num /= 4;
	}

	u.uhpmax += num;
	u.uhp += num;

	if (Upolyd) {
	    num = rnz(8); /* unfortunately will be lost upon unpolymorphing --Amy */
	    if (num < 0) num = 0;
	    if (num > 1) num /= rnd(12);
	    num += rn2(2);

	    if (Race_if(PM_YEEK) || Race_if(PM_DUFFLEPUD) || Race_if(PM_PLAYER_FAIRY)) num /= 2;
	    if (Race_if(PM_PLAYER_DOLGSMAN)) {
		num *= 3;
		num /= 4;
	    }

	    u.mhmax += num;
	    u.mh += num;
	}
	if (u.ulevel < urole.xlev)
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.lornd + urace.enadv.lornd,
			urole.enadv.lofix + urace.enadv.lofix);
	else
	    num = rn1((int)ACURR(A_WIS)/2 + urole.enadv.hirnd + urace.enadv.hirnd,
			urole.enadv.hifix + urace.enadv.hifix);

	num = enermod(num);	/* M. Stephenson */
	num += (rn2(3) ? rnz(1) : rnz(2));
	if (num < 0) num = 0;
	if (num > 1) num /= rnd(12);
	num += rn2(2);

	if (Race_if(PM_YEEK) || Race_if(PM_DUFFLEPUD)) num /= 2;

	u.uenmax += num;
	u.uen += num;

	} /* homicider check */

	} /* u.ulevel > or < MAXULEV */

	if(u.ulevel < MAXULEV) {
	    if (incr) {
		long tmp = newuexp(u.ulevel + 1);
		if (u.uexp >= tmp) u.uexp = tmp - 1;
	    } else {
		u.uexp = newuexp(u.ulevel);
	    }
	    ++u.ulevel;
	    if (u.ulevelmax < u.ulevel) u.ulevelmax = u.ulevel;
	    pline("Welcome to experience level %d.", u.ulevel);
	    adjabil(u.ulevel - 1, u.ulevel);	/* give new intrinsics */
	    reset_rndmonst(NON_PM);		/* new monster selection */
	}

	exprecalc();

	flags.botl = 1;
}

/* compute a random amount of experience points suitable for the hero's
   experience level:  base number of points needed to reach the current
   level plus a random portion of what it takes to get to the next level */
long
rndexp(gaining)
boolean gaining;	/* gaining XP via potion vs setting XP for polyself */
{
	long minexp, maxexp, diff, factor, result;

	minexp = (u.ulevel == 1) ? 0L : newuexp(u.ulevel - 1);
	maxexp = newuexp(u.ulevel);
	/* don't make blessed gain level too strong... --Amy */
	if (gaining && ((newuexp(u.ulevel) - newuexp(u.ulevel - 1)) > 200000)) {
		maxexp = (newuexp(u.ulevel - 1)) + 200000;
	}
	diff = maxexp - minexp,  factor = 1L;
	/* make sure that `diff' is an argument which rn2() can handle */
	while (diff >= (long)LARGEST_INT)
	    diff /= 2L,  factor *= 2L;
	result = minexp + factor * (long)rn2((int)diff);
	/* 3.4.1:  if already at level 30, add to current experience
	   points rather than to threshold needed to reach the current
	   level; otherwise blessed potions of gain level can result
	   in lowering the experience points instead of raising them */
	if (u.ulevel == MAXULEV && gaining) {
	    result += (u.uexp - minexp);
	    /* avoid wrapping (over 400 blessed potions needed for that...) */
	    if (result < u.uexp) result = u.uexp;
	}
	return result;
}

void
exprecalc(void)
{
	register struct obj *acqo;
	struct obj *ubookz;

	while (u.ulevel > u.urmaxlvlUP && u.ulevel < 30) {
		u.urmaxlvlUP++;

		if ( (Role_if(PM_FEMINIST) || Role_if(PM_GRENADONIN)) && !rn2(5)) {

			boolean havegifts = u.ugifts;

			if (!havegifts) u.ugifts++;

			acqo = mk_artifact((struct obj *)0, !rn2(3) ? A_CHAOTIC : rn2(2) ? A_NEUTRAL : A_LAWFUL, TRUE);
			if (acqo) {
			    dropy(acqo);
				if (P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_ISRESTRICTED) {
					unrestrict_weapon_skill(get_obj_skill(acqo, TRUE));
				} else if (P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_UNSKILLED) {
					unrestrict_weapon_skill(get_obj_skill(acqo, TRUE));
					P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_BASIC;
				} else if (rn2(2) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_BASIC) {
					P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_SKILLED;
				} else if (!rn2(4) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_SKILLED) {
					P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_EXPERT;
				} else if (!rn2(10) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_EXPERT) {
					P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_MASTER;
				} else if (!rn2(100) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_MASTER) {
					P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_GRAND_MASTER;
				} else if (!rn2(200) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_GRAND_MASTER) {
					P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_SUPREME_MASTER;
				}

				if (Race_if(PM_RUSMOT)) {
					if (P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_ISRESTRICTED) {
						unrestrict_weapon_skill(get_obj_skill(acqo, TRUE));
					} else if (P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_UNSKILLED) {
						unrestrict_weapon_skill(get_obj_skill(acqo, TRUE));
						P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_BASIC;
					} else if (rn2(2) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_BASIC) {
						P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_SKILLED;
					} else if (!rn2(4) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_SKILLED) {
						P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_EXPERT;
					} else if (!rn2(10) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_EXPERT) {
						P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_MASTER;
					} else if (!rn2(100) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_MASTER) {
						P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_GRAND_MASTER;
					} else if (!rn2(200) && P_MAX_SKILL(get_obj_skill(acqo, TRUE)) == P_GRAND_MASTER) {
						P_MAX_SKILL(get_obj_skill(acqo, TRUE)) = P_SUPREME_MASTER;
					}
				}

			    discover_artifact(acqo->oartifact);

				if (!havegifts) u.ugifts--;
				pline("An artifact appeared beneath you!");

			}

		}

		if (uarmh && uarmh->oartifact == ART_JESTES_TAKA_KURWA) {
			if (u.urmaxlvlUP == 4) NotSeenBug |= FROMOUTSIDE;
			else if (u.urmaxlvlUP == 8) GrayoutBug |= FROMOUTSIDE;
			else if (u.urmaxlvlUP == 12) DifficultyIncreased |= FROMOUTSIDE;
			else if (u.urmaxlvlUP == 16) UnfairAttackBug |= FROMOUTSIDE;
			else if (u.urmaxlvlUP == 20) EnmityBug |= FROMOUTSIDE;
			else if (u.urmaxlvlUP == 25) ElongationBug |= FROMOUTSIDE;
			else if (u.urmaxlvlUP == 30) Antileveling |= FROMOUTSIDE;
		}

		if (Role_if(PM_FEMINIST) && !rn2(3)) {

			boolean femintcheck = 0;
			if (rnd(70) < ACURR(A_INT)) femintcheck = 1;

			if (u.urmaxlvlUP == 3) {
				switch (u.femauspices4) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, your potions will have a chance of not working when quaffed.");
						else pline("Your auspices say: 4 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, your techniques will stop working.");
						else pline("Your auspices say: 4 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, Elbereth engravings will no longer work.");
						else pline("Your auspices say: 4 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, zapping a wand will have a chance to make it explode.");
						else pline("Your auspices say: 4 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, reading a spellbook is no longer safe.");
						else pline("Your auspices say: 4 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, your magical effects will always be very low-level.");
						else pline("Your auspices say: 4 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, you will no longer be able to uncurse your items via scrolls of remove curse, holy water or cancellation.");
						else pline("Your auspices say: 4 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, the 'never mind' or 'nothing happens' messages will cause bad effects.");
						else pline("Your auspices say: 4 8");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, you will repeatedly lose spell memory.");
						else pline("Your auspices say: 4 9");
						break;
					case 10:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, your skill training will occasionally be reduced.");
						else pline("Your auspices say: 4 10");
						break;
					case 11:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 4, your techniques will occasionally receive increased timeouts.");
						else pline("Your auspices say: 4 11");
						break;
				}

			} else if (u.urmaxlvlUP == 5) {
				switch (u.femauspices6) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, your right mouse button will fail.");
						else pline("Your auspices say: 6 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, your display will fail.");
						else pline("Your auspices say: 6 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, there will be low local memory.");
						else pline("Your auspices say: 6 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, you will get BIGscript.");
						else pline("Your auspices say: 6 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, you will be afflicted with weak sight.");
						else pline("Your auspices say: 6 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, you will see flicker strips.");
						else pline("Your auspices say: 6 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, menus will be fleecy-colored.");
						else pline("Your auspices say: 6 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, you start seeing mojibake glyphs.");
						else pline("Your auspices say: 6 8");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 6, all sanity effects will increase your sanity by much more than usual.");
						else pline("Your auspices say: 6 9");
						break;
				}

			} else if (u.urmaxlvlUP == 7) {
				switch (u.femauspices8) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, the entire game will display in shades of grey.");
						else pline("Your auspices say: 8 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, a ROT13 cypher will be activated.");
						else pline("Your auspices say: 8 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, you will have to solve captchas.");
						else pline("Your auspices say: 8 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, you will have to take part in the Nethack Quiz.");
						else pline("Your auspices say: 8 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, there will be sound effects.");
						else pline("Your auspices say: 8 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, walls will become hyper blue.");
						else pline("Your auspices say: 8 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, the pokedex will lie to you.");
						else pline("Your auspices say: 8 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, monsters will make noises.");
						else pline("Your auspices say: 8 8");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 8, increasing stats beyond a certain limit will become much harder.");
						else pline("Your auspices say: 8 9");
						break;
				}

			} else if (u.urmaxlvlUP == 10) {
				switch (u.femauspices11) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become pink.");
						else pline("Your auspices say: 11 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become cyan.");
						else pline("Your auspices say: 11 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become black.");
						else pline("Your auspices say: 11 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become red.");
						else pline("Your auspices say: 11 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become green.");
						else pline("Your auspices say: 11 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become blue.");
						else pline("Your auspices say: 11 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become completely gray.");
						else pline("Your auspices say: 11 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become white.");
						else pline("Your auspices say: 11 8");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become yellow.");
						else pline("Your auspices say: 11 9");
						break;
					case 10:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become orange.");
						else pline("Your auspices say: 11 10");
						break;
					case 11:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become violet.");
						else pline("Your auspices say: 11 11");
						break;
					case 12:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become brown.");
						else pline("Your auspices say: 11 12");
						break;
					case 13:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become bright cyan.");
						else pline("Your auspices say: 11 13");
						break;
					case 14:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become silver.");
						else pline("Your auspices say: 11 14");
						break;
					case 15:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become metal.");
						else pline("Your auspices say: 11 15");
						break;
					case 16:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 11, your spells will become platinum.");
						else pline("Your auspices say: 11 16");
						break;
				}

			} else if (u.urmaxlvlUP == 12) {
				switch (u.femauspices13) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, you will be subjected to random intrinsic loss.");
						else pline("Your auspices say: 13 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, you will start to temporarily lose intrinsics.");
						else pline("Your auspices say: 13 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, you will start suffering from blood loss.");
						else pline("Your auspices say: 13 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, all newly spawned monsters will be hostile.");
						else pline("Your auspices say: 13 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, covetous monsters start using their AI in a smarter way.");
						else pline("Your auspices say: 13 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, identifying items becomes much more difficult.");
						else pline("Your auspices say: 13 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, Satan will cause you to lose a turn when entering a new level.");
						else pline("Your auspices say: 13 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, monsters are generated with movement energy.");
						else pline("Your auspices say: 13 8");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, you will be in the bad part.");
						else pline("Your auspices say: 13 9");
						break;
					case 10:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 13, you will be in the completely bad part.");
						else pline("Your auspices say: 13 10");
						break;
				}

			} else if (u.urmaxlvlUP == 14) {
				switch (u.femauspices15) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, you will get the speed bug.");
						else pline("Your auspices say: 15 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, your multi-turn actions will be interrupted every turn.");
						else pline("Your auspices say: 15 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, you can no longer teleport at all.");
						else pline("Your auspices say: 15 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, all items that you drop will automatically curse themselves.");
						else pline("Your auspices say: 15 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, monsters can randomly move faster than normal.");
						else pline("Your auspices say: 15 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, blessed items that you pick up will instantly become cursed.");
						else pline("Your auspices say: 15 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, using consumables will curse them first.");
						else pline("Your auspices say: 15 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 15, items that monsters steal from you will be degraded.");
						else pline("Your auspices say: 15 8");
						break;
				}

			} else if (u.urmaxlvlUP == 16) {
				switch (u.femauspices17) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, the monster difficulty will be increased.");
						else pline("Your auspices say: 17 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, monsters start spawning much faster.");
						else pline("Your auspices say: 17 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, boss monsters become more common.");
						else pline("Your auspices say: 17 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, rare monsters become common.");
						else pline("Your auspices say: 17 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, high-level monsters become more common.");
						else pline("Your auspices say: 17 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, the minimum level for newly spawned monsters will start scaling with the actual level difficulty.");
						else pline("Your auspices say: 17 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 17, monster attacks use exploding dice to determine their damage.");
						else pline("Your auspices say: 17 7");
						break;
				}

			} else if (u.urmaxlvlUP == 19) {
				switch (u.femauspices20) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, your possessions start randomly unidentifying themselves.");
						else pline("Your auspices say: 20 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, you will get insufficient information about items.");
						else pline("Your auspices say: 20 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, dungeon floors become invisible.");
						else pline("Your auspices say: 20 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, monsters become stronger if many of their species have been generated already.");
						else pline("Your auspices say: 20 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, walls become invisible.");
						else pline("Your auspices say: 20 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, the map will fill up with fake I markers.");
						else pline("Your auspices say: 20 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, I markers become invisible and will cost a turn if you bump into them.");
						else pline("Your auspices say: 20 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 20, you are subjected to the wing yellow changer.");
						else pline("Your auspices say: 20 8");
						break;
				}

			} else if (u.urmaxlvlUP == 21) {
				switch (u.femauspices22) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, you can no longer cure status effects.");
						else pline("Your auspices say: 22 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, the dungeon starts becoming ever more chaotic.");
						else pline("Your auspices say: 22 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, altars and prayer become unsafe.");
						else pline("Your auspices say: 22 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, all newly spawned monsters will be invisible, and see invisible won't help.");
						else pline("Your auspices say: 22 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, all newly spawned traps will be invisible, and there is no way to make them visible again.");
						else pline("Your auspices say: 22 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, empty dungeon floor tiles will quickly turn into walls.");
						else pline("Your auspices say: 22 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, spells with low spell memory are difficult to cast.");
						else pline("Your auspices say: 22 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 22, any trap you trigger will become invisible.");
						else pline("Your auspices say: 22 8");
						break;
				}

			} else if (u.urmaxlvlUP == 24) {
				switch (u.femauspices25) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, the display will intermittently become all gray.");
						else pline("Your auspices say: 25 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, your position and the eight surrounding squares will be obscured.");
						else pline("Your auspices say: 25 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, you will contract the checkerboard disease.");
						else pline("Your auspices say: 25 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, you will no longer be able to identify the type of a trap.");
						else pline("Your auspices say: 25 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, you will no longer be able to determine what monsters are.");
						else pline("Your auspices say: 25 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, leveling up no longer increases your maximum HP and Pw.");
						else pline("Your auspices say: 25 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, some calculations will work as if your level were 1.");
						else pline("Your auspices say: 25 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 25, a manler will start chasing you.");
						else pline("Your auspices say: 25 8");
						break;
				}

			} else if (u.urmaxlvlUP == 27) {
				switch (u.femauspices28) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, your maximum alignment record will decrease over time.");
						else pline("Your auspices say: 28 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, you will start suffering from recurring amnesia.");
						else pline("Your auspices say: 28 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, your items will start to disenchant themselves spontaneously.");
						else pline("Your auspices say: 28 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, all equipment you put on will autocurse.");
						else pline("Your auspices say: 28 4");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, monsters will be able to use their secret attack.");
						else pline("Your auspices say: 28 5");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, you will suffer from random item destruction.");
						else pline("Your auspices say: 28 6");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, monsters learn to use their ranged attacks from infinitely far away.");
						else pline("Your auspices say: 28 7");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, monsters will be able to use unfair attacks.");
						else pline("Your auspices say: 28 8");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 28, the presence of bosses causes a horrible call to ring in your head.");
						else pline("Your auspices say: 28 9");
						break;
				}

			} else if (u.urmaxlvlUP == 29) {
				switch (u.femauspices30) {
					case 1:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, you can no longer open your inventory.");
						else pline("Your auspices say: 30 1");
						break;
					case 2:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, killed monsters no longer drop corpses.");
						else pline("Your auspices say: 30 2");
						break;
					case 3:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, your directional keys will be inverted.");
						else pline("Your auspices say: 30 3");
						break;
					case 4:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, you always have to press Ctrl-R to see what happened.");
						else pline("Your auspices say: 30 8");
						break;
					case 5:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, you will barely be able to see the quasars.");
						else pline("Your auspices say: 30 4");
						break;
					case 6:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, your directional keys will be shifted 45 degrees clockwise.");
						else pline("Your auspices say: 30 5");
						break;
					case 7:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, your directional keys will be shifted 90 degrees counterclockwise.");
						else pline("Your auspices say: 30 6");
						break;
					case 8:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, bumping into monsters will cost a turn unless you use a certain prefix.");
						else pline("Your auspices say: 30 7");
						break;
					case 9:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, you won't see anything unless you stand on specific tiles.");
						else pline("Your auspices say: 30 9");
						break;
					case 10:
						if (femintcheck) pline("You receive an elaborate auspicious message: At experience level 30, your stats will slowly decay.");
						else pline("Your auspices say: 30 10");
						break;
				}

			}

		}

	}
	

	if (isproblematic && !rn2(3)) {
		/* no xlvl check - if you get drained repeatedly, your loss! I'm really mean :D --Amy */

		getnastytrapintrinsic();

	}

	/* slex has so many skills, you keep running out of slots all the damn time! Need to counteract that --Amy */
	while (u.ulevel > u.urmaxlvlN) {
		u.urmaxlvlN++;
		if (u.urmaxlvlN == 10) u.weapon_slots += 5;
		if (u.urmaxlvlN == 20) u.weapon_slots += 5;
		if (u.urmaxlvlN == 30) u.weapon_slots += 5;
	}

	while (Race_if(PM_RODNEYAN) && u.ulevel > u.urmaxlvl) {

		u.urmaxlvl++;

		if (!rn2(2)) {
			ubookz = mkobj(SPBOOK_CLASS, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book appeared at your feet!");
		}

	}

	while (Race_if(PM_ASGARDIAN) && u.ulevel > u.urmaxlvlL) {

		u.urmaxlvlL++;

		if (!rn2(3)) { switch (rnd(52)) {

			case 1: 
			case 2: 
			case 3: 
			    HFire_resistance |= FROMOUTSIDE; pline("Got fire resistance!"); break;
			case 4: 
			case 5: 
			case 6: 
			    HCold_resistance |= FROMOUTSIDE; pline("Got cold resistance!"); break;
			case 7: 
			case 8: 
			case 9: 
			    HSleep_resistance |= FROMOUTSIDE; pline("Got sleep resistance!"); break;
			case 10: 
			case 11: 
			    HDisint_resistance |= FROMOUTSIDE; pline("Got disintegration resistance!"); break;
			case 12: 
			case 13: 
			case 14: 
			    HShock_resistance |= FROMOUTSIDE; pline("Got shock resistance!"); break;
			case 15: 
			case 16: 
			case 17: 
			    HPoison_resistance |= FROMOUTSIDE; pline("Got poison resistance!"); break;
			case 18: 
			    HDrain_resistance |= FROMOUTSIDE; pline("Got drain resistance!"); break;
			case 19: 
			    HSick_resistance |= FROMOUTSIDE; pline("Got sickness resistance!"); break;
			case 20: 
			    HAcid_resistance |= FROMOUTSIDE; pline("Got acid resistance!"); break;
			case 21: 
			case 22: 
			    HHunger |= FROMOUTSIDE; pline("You start to hunger rapidly!"); break;
			case 23: 
			case 24: 
			    HSee_invisible |= FROMOUTSIDE; pline("Got see invisible!"); break;
			case 25: 
			    HTelepat |= FROMOUTSIDE; pline("Got telepathy!"); break;
			case 26: 
			case 27: 
			    HWarning |= FROMOUTSIDE; pline("Got warning!"); break;
			case 28: 
			case 29: 
			    HSearching |= FROMOUTSIDE; pline("Got searching!"); break;
			case 30: 
			case 31: 
			    HStealth |= FROMOUTSIDE; pline("Got stealth!"); break;
			case 32: 
			case 33: 
			    HAggravate_monster |= FROMOUTSIDE; pline("You aggravate monsters!"); break;
			case 34: 
			    HConflict |= FROMOUTSIDE; pline("You start causing conflict!"); break;
			case 35: 
			case 36: 
			    HTeleportation |= FROMOUTSIDE; pline("Got teleportitis!"); break;
			case 37: 
			    HTeleport_control |= FROMOUTSIDE; pline("Got teleport control!"); break;
			case 38: 
			    HFlying |= FROMOUTSIDE; pline("Got flying!"); break;
			case 39: 
			    HSwimming |= FROMOUTSIDE; pline("Got swimming!"); break;
			case 40: 
			    HMagical_breathing |= FROMOUTSIDE; pline("Got unbreathing!"); break;
			case 41: 
			    HSlow_digestion |= FROMOUTSIDE; pline("Got slow digestion!"); break;
			case 42: 
			case 43: 
			    HRegeneration |= FROMOUTSIDE; pline("Got regeneration!"); break;
			case 44: 
			    HPolymorph |= FROMOUTSIDE; pline("Got polymorphitis!"); break;
			case 45: 
			    HPolymorph_control |= FROMOUTSIDE; pline("Got polymorph control!"); break;
			case 46: 
			case 47: 
			    HFast |= FROMOUTSIDE; pline("Got speed!"); break;
			case 48: 
			    HInvis |= FROMOUTSIDE; pline("Got invisibility!"); break;
			case 49: 
			    HManaleech |= FROMOUTSIDE; pline("Got manaleech!"); break;
			case 50: 
			    HPeacevision |= FROMOUTSIDE; pline("Got peacevision!"); break;

			default:
				break;

			}

		}

	}

	while (Role_if(PM_SOCIAL_JUSTICE_WARRIOR) && u.ulevel > u.urmaxlvlK) {

		u.urmaxlvlK++;

		if (!rn2(4)) {
			int wondertech = rnd(MAXTECH-1);
			if (!tech_known(wondertech)) {
			    	learntech(wondertech, FROMOUTSIDE, 1);
				You("learn how to perform a new technique!");
			}

		}

	}

	while (Role_if(PM_WILD_TALENT) && u.ulevel > u.urmaxlvlF) {

		u.urmaxlvlF++;

		if (!rn2(4)) { switch (rnd(52)) {

			case 1: 
			case 2: 
			case 3: 
			    HFire_resistance |= FROMOUTSIDE; pline("Got fire resistance!"); break;
			case 4: 
			case 5: 
			case 6: 
			    HCold_resistance |= FROMOUTSIDE; pline("Got cold resistance!"); break;
			case 7: 
			case 8: 
			case 9: 
			    HSleep_resistance |= FROMOUTSIDE; pline("Got sleep resistance!"); break;
			case 10: 
			case 11: 
			    HDisint_resistance |= FROMOUTSIDE; pline("Got disintegration resistance!"); break;
			case 12: 
			case 13: 
			case 14: 
			    HShock_resistance |= FROMOUTSIDE; pline("Got shock resistance!"); break;
			case 15: 
			case 16: 
			case 17: 
			    HPoison_resistance |= FROMOUTSIDE; pline("Got poison resistance!"); break;
			case 18: 
			    HDrain_resistance |= FROMOUTSIDE; pline("Got drain resistance!"); break;
			case 19: 
			    HSick_resistance |= FROMOUTSIDE; pline("Got sickness resistance!"); break;
			case 20: 
			    HAcid_resistance |= FROMOUTSIDE; pline("Got acid resistance!"); break;
			case 21: 
			case 22: 
			    HHunger |= FROMOUTSIDE; pline("You start to hunger rapidly!"); break;
			case 23: 
			case 24: 
			    HSee_invisible |= FROMOUTSIDE; pline("Got see invisible!"); break;
			case 25: 
			    HTelepat |= FROMOUTSIDE; pline("Got telepathy!"); break;
			case 26: 
			case 27: 
			    HWarning |= FROMOUTSIDE; pline("Got warning!"); break;
			case 28: 
			case 29: 
			    HSearching |= FROMOUTSIDE; pline("Got searching!"); break;
			case 30: 
			case 31: 
			    HStealth |= FROMOUTSIDE; pline("Got stealth!"); break;
			case 32: 
			case 33: 
			    HAggravate_monster |= FROMOUTSIDE; pline("You aggravate monsters!"); break;
			case 34: 
			    HConflict |= FROMOUTSIDE; pline("You start causing conflict!"); break;
			case 35: 
			case 36: 
			    HTeleportation |= FROMOUTSIDE; pline("Got teleportitis!"); break;
			case 37: 
			    HTeleport_control |= FROMOUTSIDE; pline("Got teleport control!"); break;
			case 38: 
			    HFlying |= FROMOUTSIDE; pline("Got flying!"); break;
			case 39: 
			    HSwimming |= FROMOUTSIDE; pline("Got swimming!"); break;
			case 40: 
			    HMagical_breathing |= FROMOUTSIDE; pline("Got unbreathing!"); break;
			case 41: 
			    HSlow_digestion |= FROMOUTSIDE; pline("Got slow digestion!"); break;
			case 42: 
			case 43: 
			    HRegeneration |= FROMOUTSIDE; pline("Got regeneration!"); break;
			case 44: 
			    HPolymorph |= FROMOUTSIDE; pline("Got polymorphitis!"); break;
			case 45: 
			    HPolymorph_control |= FROMOUTSIDE; pline("Got polymorph control!"); break;
			case 46: 
			case 47: 
			    HFast |= FROMOUTSIDE; pline("Got speed!"); break;
			case 48: 
			    HInvis |= FROMOUTSIDE; pline("Got invisibility!"); break;
			case 49: 
			    HManaleech |= FROMOUTSIDE; pline("Got manaleech!"); break;
			case 50: 
			    HPeacevision |= FROMOUTSIDE; pline("Got peacevision!"); break;

			default:
				break;

			}

		}

	}

	while (Race_if(PM_MISSINGNO) && u.ulevel > u.urmaxlvlM) {

		u.urmaxlvlM++;

		if (!rn2(3)) { switch (rnd(178)) {

			case 1: 
			case 2: 
			case 3: 
				if (!tech_known(T_BERSERK)) {    	learntech(T_BERSERK, FROMOUTSIDE, 1);
			    	You("learn how to perform berserk!");
				}
				break;
			case 4: 
			case 5: 
			case 6: 
				if (!tech_known(T_KIII)) {    	learntech(T_KIII, FROMOUTSIDE, 1);
			    	You("learn how to perform kiii!");
				}
				break;
			case 7: 
			case 8: 
			case 9: 
				if (!tech_known(T_RESEARCH)) {    	learntech(T_RESEARCH, FROMOUTSIDE, 1);
			    	You("learn how to perform research!");
				}
				break;
			case 10: 
			case 11: 
			case 12: 
				if (!tech_known(T_SURGERY)) {    	learntech(T_SURGERY, FROMOUTSIDE, 1);
			    	You("learn how to perform surgery!");
				}
				break;
			case 13: 
			case 14: 
			case 15: 
				if (!tech_known(T_REINFORCE)) {    	learntech(T_REINFORCE, FROMOUTSIDE, 1);
			    	You("learn how to perform reinforce memory!");
				}
				break;
			case 16: 
			case 17:
			case 18: 
				if (!tech_known(T_FLURRY)) {    	learntech(T_FLURRY, FROMOUTSIDE, 1);
			    	You("learn how to perform missile flurry!");
				}
				break;
			case 19: 
			case 20: 
			case 21: 
				if (!tech_known(T_PRACTICE)) {    	learntech(T_PRACTICE, FROMOUTSIDE, 1);
			    	You("learn how to perform weapon practice!");
				}
				break;
			case 22: 
			case 23: 
			case 24: 
				if (!tech_known(T_EVISCERATE)) {    	learntech(T_EVISCERATE, FROMOUTSIDE, 1);
			    	You("learn how to perform eviscerate!");
				}
				break;
			case 25: 
			case 26: 
			case 27: 
				if (!tech_known(T_HEAL_HANDS)) {    	learntech(T_HEAL_HANDS, FROMOUTSIDE, 1);
			    	You("learn how to perform healing hands!");
				}
				break;
			case 28: 
			case 29: 
			case 30: 
				if (!tech_known(T_CALM_STEED)) {    	learntech(T_CALM_STEED, FROMOUTSIDE, 1);
			    	You("learn how to perform calm steed!");
				}
				break;
			case 31: 
			case 32: 
			case 33: 
				if (!tech_known(T_TURN_UNDEAD)) {    	learntech(T_TURN_UNDEAD, FROMOUTSIDE, 1);
			    	You("learn how to perform turn undead!");
				}
				break;
			case 34: 
			case 35: 
			case 36: 
				if (!tech_known(T_VANISH)) {    	learntech(T_VANISH, FROMOUTSIDE, 1);
			    	You("learn how to perform vanish!");
				}
				break;
			case 37: 
			case 38: 
			case 39: 
				if (!tech_known(T_CUTTHROAT)) {    	learntech(T_CUTTHROAT, FROMOUTSIDE, 1);
			    	You("learn how to perform cutthroat!");
				}
				break;
			case 40: 
			case 41: 
				if (!tech_known(T_BLESSING)) {    	learntech(T_BLESSING, FROMOUTSIDE, 1);
			    	You("learn how to perform blessing!");
				}
				break;
			case 42: 
			case 43: 
			case 44: 
				if (!tech_known(T_E_FIST)) {    	learntech(T_E_FIST, FROMOUTSIDE, 1);
			    	You("learn how to perform elemental fist!");
				}
				break;
			case 45: 
			case 46: 
			case 47: 
				if (!tech_known(T_PRIMAL_ROAR)) {    	learntech(T_PRIMAL_ROAR, FROMOUTSIDE, 1);
			    	You("learn how to perform primal roar!");
				}
				break;
			case 48: 
			case 49: 
				if (!tech_known(T_LIQUID_LEAP)) {    	learntech(T_LIQUID_LEAP, FROMOUTSIDE, 1);
			    	You("learn how to perform liquid leap!");
				}
				break;
			case 50: 
			case 51: 
			case 52: 
				if (!tech_known(T_CRIT_STRIKE)) {    	learntech(T_CRIT_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform critical strike!");
				}
				break;
			case 53: 
			case 54: 
			case 55: 
				if (!tech_known(T_SIGIL_CONTROL)) {    	learntech(T_SIGIL_CONTROL, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of control!");
				}
				break;
			case 56: 
			case 57: 
			case 58: 
				if (!tech_known(T_SIGIL_TEMPEST)) {    	learntech(T_SIGIL_TEMPEST, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of tempest!");
				}
				break;
			case 59: 
			case 60: 
			case 61: 
				if (!tech_known(T_SIGIL_DISCHARGE)) {    	learntech(T_SIGIL_DISCHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of discharge!");
				}
				break;
			case 62: 
			case 63: 
			case 64: 
				if (!tech_known(T_RAISE_ZOMBIES)) {    	learntech(T_RAISE_ZOMBIES, FROMOUTSIDE, 1);
			    	You("learn how to perform raise zombies!");
				}
				break;
			case 65: 
				if (!tech_known(T_REVIVE)) {    	learntech(T_REVIVE, FROMOUTSIDE, 1);
			    	You("learn how to perform revivification!");
				}
				break;
			case 66: 
			case 67: 
			case 68: 
				if (!tech_known(T_WARD_FIRE)) {    	learntech(T_WARD_FIRE, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against fire!");
				}
				break;
			case 69: 
			case 70: 
			case 71: 
				if (!tech_known(T_WARD_COLD)) {    	learntech(T_WARD_COLD, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against cold!");
				}
				break;
			case 72: 
			case 73: 
			case 74: 
				if (!tech_known(T_WARD_ELEC)) {    	learntech(T_WARD_ELEC, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against electricity!");
				}
				break;
			case 75: 
			case 76: 
			case 77: 
				if (!tech_known(T_TINKER)) {    	learntech(T_TINKER, FROMOUTSIDE, 1);
			    	You("learn how to perform tinker!");
				}
				break;
			case 78: 
			case 79: 
			case 80: 
				if (!tech_known(T_RAGE)) {    	learntech(T_RAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform rage eruption!");
				}
				break;
			case 81: 
			case 82: 
			case 83: 
				if (!tech_known(T_BLINK)) {    	learntech(T_BLINK, FROMOUTSIDE, 1);
			    	You("learn how to perform blink!");
				}
				break;
			case 84: 
			case 85: 
			case 86: 
				if (!tech_known(T_CHI_STRIKE)) {    	learntech(T_CHI_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform chi strike!");
				}
				break;
			case 87: 
			case 88: 
			case 89: 
				if (!tech_known(T_DRAW_ENERGY)) {    	learntech(T_DRAW_ENERGY, FROMOUTSIDE, 1);
			    	You("learn how to perform draw energy!");
				}
				break;
			case 90: 
			case 91: 
			case 92: 
				if (!tech_known(T_CHI_HEALING)) {    	learntech(T_CHI_HEALING, FROMOUTSIDE, 1);
			    	You("learn how to perform chi healing!");
				}
				break;
			case 93: 
			case 94: 
			case 95: 
				if (!tech_known(T_DAZZLE)) {    	learntech(T_DAZZLE, FROMOUTSIDE, 1);
			    	You("learn how to perform dazzle!");
				}
				break;
			case 96: 
			case 97: 
			case 98: 
				if (!tech_known(T_BLITZ)) {    	learntech(T_BLITZ, FROMOUTSIDE, 1);
			    	You("learn how to perform chained blitz!");
				}
				break;
			case 99: 
			case 100: 
			case 101: 
				if (!tech_known(T_PUMMEL)) {    	learntech(T_PUMMEL, FROMOUTSIDE, 1);
			    	You("learn how to perform pummel!");
				}
				break;
			case 102: 
			case 103: 
			case 104: 
				if (!tech_known(T_G_SLAM)) {    	learntech(T_G_SLAM, FROMOUTSIDE, 1);
			    	You("learn how to perform ground slam!");
				}
				break;
			case 105: 
			case 106: 
			case 107: 
				if (!tech_known(T_DASH)) {    	learntech(T_DASH, FROMOUTSIDE, 1);
			    	You("learn how to perform air dash!");
				}
				break;
			case 108: 
			case 109: 
			case 110: 
				if (!tech_known(T_POWER_SURGE)) {    	learntech(T_POWER_SURGE, FROMOUTSIDE, 1);
			    	You("learn how to perform power surge!");
				}
				break;
			case 111: 
			case 112: 
			case 113: 
				if (!tech_known(T_SPIRIT_BOMB)) {    	learntech(T_SPIRIT_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform spirit bomb!");
				}
				break;
			case 114: 
			case 115: 
			case 116: 
				if (!tech_known(T_DRAW_BLOOD)) {    	learntech(T_DRAW_BLOOD, FROMOUTSIDE, 1);
			    	You("learn how to perform draw blood!");
				}
				break;
			case 117: 
				if (!tech_known(T_WORLD_FALL)) {    	learntech(T_WORLD_FALL, FROMOUTSIDE, 1);
			    	You("learn how to perform world fall!");
				}
				break;
			case 118: 
			case 119: 
			case 120: 
				if (!tech_known(T_CREATE_AMMO)) {    	learntech(T_CREATE_AMMO, FROMOUTSIDE, 1);
			    	You("learn how to perform create ammo!");
				}
				break;
			case 121: 
			case 122: 
			case 123: 
				if (!tech_known(T_POKE_BALL)) {    	learntech(T_POKE_BALL, FROMOUTSIDE, 1);
			    	You("learn how to perform poke ball!");
				}
				break;
			case 124: 
			case 125: 
			case 126: 
				if (!tech_known(T_ATTIRE_CHARM)) {    	learntech(T_ATTIRE_CHARM, FROMOUTSIDE, 1);
			    	You("learn how to perform attire charm!");
				}
				break;
			case 127: 
			case 128: 
			case 129: 
				if (!tech_known(T_SUMMON_TEAM_ANT)) {    	learntech(T_SUMMON_TEAM_ANT, FROMOUTSIDE, 1);
			    	You("learn how to perform summon team ant!");
				}
				break;
			case 130: 
			case 131: 
			case 132: 
				if (!tech_known(T_JEDI_JUMP)) {    	learntech(T_JEDI_JUMP, FROMOUTSIDE, 1);
			    	You("learn how to perform jedi jump!");
				}
				break;
			case 133: 
			case 134: 
			case 135: 
				if (!tech_known(T_CHARGE_SABER)) {    	learntech(T_CHARGE_SABER, FROMOUTSIDE, 1);
			    	You("learn how to perform charge saber!");
				}
				break;
			case 136: 
			case 137: 
			case 138: 
				if (!tech_known(T_TELEKINESIS)) {    	learntech(T_TELEKINESIS, FROMOUTSIDE, 1);
			    	You("learn how to perform telekinesis!");
				}
				break;
			case 139: 
				if (!tech_known(T_EGG_BOMB)) {    	learntech(T_EGG_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform egg bomb!");
				}
				break;
			case 140: 
			case 141: 
			case 142: 
				if (!tech_known(T_BOOZE)) {    	learntech(T_BOOZE, FROMOUTSIDE, 1);
			    	You("learn how to perform booze!");
				}
				break;

			case 143: 
			case 144: 
			case 145: 
				if (!tech_known(T_IRON_SKIN)) {    	learntech(T_IRON_SKIN, FROMOUTSIDE, 1);
			    	You("learn how to perform iron skin!");
				}
				break;
			case 146: 
				if (!tech_known(T_POLYFORM)) {    	learntech(T_POLYFORM, FROMOUTSIDE, 1);
			    	You("learn how to perform polyform!");
				}
				break;
			case 147: 
			case 148: 
			case 149: 
				if (!tech_known(T_CONCENTRATING)) {    	learntech(T_CONCENTRATING, FROMOUTSIDE, 1);
			    	You("learn how to perform concentrating!");
				}
				break;
			case 150: 
				if (!tech_known(T_SUMMON_PET)) {    	learntech(T_SUMMON_PET, FROMOUTSIDE, 1);
			    	You("learn how to perform summon pet!");
				}
				break;
			case 151: 
			case 152: 
				if (!tech_known(T_DOUBLE_THROWNAGE)) {    	learntech(T_DOUBLE_THROWNAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform double thrownage!");
				}
				break;
			case 153: 
			case 154: 
			case 155: 
				if (!tech_known(T_SHIELD_BASH)) {    	learntech(T_SHIELD_BASH, FROMOUTSIDE, 1);
			    	You("learn how to perform shield bash!");
				}
				break;
			case 156: 
			case 157: 
				if (!tech_known(T_RECHARGE)) {    	learntech(T_RECHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform recharge!");
				}
				break;
			case 158: 
			case 159: 
			case 160: 
				if (!tech_known(T_SPIRITUALITY_CHECK)) {    	learntech(T_SPIRITUALITY_CHECK, FROMOUTSIDE, 1);
			    	You("learn how to perform spirituality check!");
				}
				break;
			case 161: 
				if (!tech_known(T_EDDY_WIND)) {    	learntech(T_EDDY_WIND, FROMOUTSIDE, 1);
			    	You("learn how to perform eddy wind!");
				}
				break;
			case 162: 
				if (!tech_known(T_BLOOD_RITUAL)) {    	learntech(T_BLOOD_RITUAL, FROMOUTSIDE, 1);
			    	You("learn how to perform blood ritual!");
				}
				break;
			case 163: 
				if (!tech_known(T_ENT_S_POTION)) {    	learntech(T_ENT_S_POTION, FROMOUTSIDE, 1);
			    	You("learn how to perform ent's potion!");
				}
				break;
			case 164: 
			case 165: 
				if (!tech_known(T_LUCKY_GAMBLE)) {    	learntech(T_LUCKY_GAMBLE, FROMOUTSIDE, 1);
			    	You("learn how to perform lucky gamble!");
				}
				break;
			case 166: 
				if (!tech_known(T_DECONTAMINATE)) {    	learntech(T_DECONTAMINATE, FROMOUTSIDE, 1);
			    	You("learn how to perform decontaminate!");
				}
				break;
			case 167: 
				if (!tech_known(T_WONDERSPELL)) {    	learntech(T_WONDERSPELL, FROMOUTSIDE, 1);
			    	You("learn how to perform wonderspell!");
				}
				break;
			case 168: 
				if (!tech_known(T_RESET_TECHNIQUE)) {    	learntech(T_RESET_TECHNIQUE, FROMOUTSIDE, 1);
			    	You("learn how to perform reset technique!");
				}
				break;
			case 169: 
				if (!tech_known(T_DIAMOND_BARRIER)) {    	learntech(T_DIAMOND_BARRIER, FROMOUTSIDE, 1);
			    	You("learn how to perform diamond barrier!");
				}
				break;
			case 170: 
				if (!tech_known(T_ZAP_EM)) {    	learntech(T_ZAP_EM, FROMOUTSIDE, 1);
			    	You("learn how to perform zap em!");
				}
				break;
			case 171: 
				if (!tech_known(T_CARD_TRICK)) {    	learntech(T_CARD_TRICK, FROMOUTSIDE, 1);
			    	You("learn how to perform card trick!");
				}
				break;
			case 172: 
				if (!tech_known(T_SKILLOMORPH)) {    	learntech(T_SKILLOMORPH, FROMOUTSIDE, 1);
			    	You("learn how to perform skillomorph!");
				}
				break;
			case 173: 
				if (!tech_known(T_TERRAIN_CLEANUP)) {    	learntech(T_TERRAIN_CLEANUP, FROMOUTSIDE, 1);
			    	You("learn how to perform terrain cleanup!");
				}
				break;

			default:
				break;

			}

		}
	}

	while (Role_if(PM_DQ_SLIME) && u.ulevel > u.urmaxlvlC) {

		u.urmaxlvlC++;

			int skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

		if (u.urmaxlvlC >= 10) {

			int skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

		}

		if (u.urmaxlvlC >= 20) {

			int skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

		}

		if (u.urmaxlvlC >= 30) {

			int skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

			skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

			skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

			skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

			skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

			skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

			skillimprove = randomgoodskill();

			if (P_MAX_SKILL(skillimprove) == P_ISRESTRICTED) {
				unrestrict_weapon_skill(skillimprove);
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (P_MAX_SKILL(skillimprove) == P_UNSKILLED) {
				unrestrict_weapon_skill(skillimprove);
				P_MAX_SKILL(skillimprove) = P_BASIC;
				pline("You can now learn the %s skill.", P_NAME(skillimprove));
			} else if (rn2(2) && P_MAX_SKILL(skillimprove) == P_BASIC) {
				P_MAX_SKILL(skillimprove) = P_SKILLED;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(4) && P_MAX_SKILL(skillimprove) == P_SKILLED) {
				P_MAX_SKILL(skillimprove) = P_EXPERT;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(10) && P_MAX_SKILL(skillimprove) == P_EXPERT) {
				P_MAX_SKILL(skillimprove) = P_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(100) && P_MAX_SKILL(skillimprove) == P_MASTER) {
				P_MAX_SKILL(skillimprove) = P_GRAND_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else if (!rn2(200) && P_MAX_SKILL(skillimprove) == P_GRAND_MASTER) {
				P_MAX_SKILL(skillimprove) = P_SUPREME_MASTER;
				pline("Your knowledge of the %s skill increases.", P_NAME(skillimprove));
			} else pline("Unfortunately, you feel no different than before.");

		}

	} /* DQ slime check */

	if (isdemagogue) { /* this is done here because you could use the recursion effect to circumvent it --Amy */

		if (u.ulevel == 5) {
			MysteriousForceActive |= FROMOUTSIDE;
		}
		if (u.ulevel == 9) {
			UnfairAttackBug |= FROMOUTSIDE;
		}
		if (u.ulevel == 13) {
			HighlevelStatus |= FROMOUTSIDE;
		}
		if (u.ulevel == 17) {
			TrapCreationProblem |= FROMOUTSIDE;
		}
		if (u.ulevel == 21) {
			UndressingEffect |= FROMOUTSIDE;
		}
		if (u.ulevel == 25) {
			OrangeSpells |= FROMOUTSIDE;
		}
		if (u.ulevel == 30) {
			SatanEffect |= FROMOUTSIDE;
		}

	}

	while (Role_if(PM_BINDER) && u.ulevel > u.urmaxlvlC) {

		u.urmaxlvlC++;

		if (!rn2(3)) {
			ubookz = mkobj(SPBOOK_CLASS, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book appeared at your feet!"); }

	}

	while (Role_if(PM_BARD) && u.ulevel > u.urmaxlvlD) {

		u.urmaxlvlD++;
		/* Yes I know, most of the names make no sense. They're from the bard patch. --Amy */

		if (u.urmaxlvlD == 3) {
			ubookz = mksobj(SPE_SLEEP, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of lullaby appeared at your feet!");
		}
		if (u.urmaxlvlD == 4) {
			ubookz = mksobj(SPE_CURE_BLINDNESS, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of cause blindness appeared at your feet!");
		}
		if (u.urmaxlvlD == 5) {
			ubookz = mksobj(SPE_CONFUSE_MONSTER, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of cacophony appeared at your feet!");
		}
		if (u.urmaxlvlD == 6) {
			ubookz = mksobj(SPE_CURE_SICKNESS, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of cause sickness appeared at your feet!");
		}
		if (u.urmaxlvlD == 7) {
			ubookz = mksobj(SPE_SLOW_MONSTER, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of drowsiness appeared at your feet!");
		}
		if (u.urmaxlvlD == 8) {
			ubookz = mksobj(SPE_HASTE_SELF, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of haste pets appeared at your feet!");
		}
		if (u.urmaxlvlD == 9) {
			ubookz = mksobj(RIN_PROTECTION_FROM_SHAPE_CHAN, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A ring of silence appeared at your feet!");
		}
		if (u.urmaxlvlD == 10) {
			ubookz = mksobj(SPE_CAUSE_FEAR, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of despair appeared at your feet!");
		}
		if (u.urmaxlvlD == 12) {
			ubookz = mksobj(SPE_FORCE_BOLT, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of shatter appeared at your feet!");
		}
		if (u.urmaxlvlD == 14) {
			ubookz = mksobj(CLOAK_OF_DISPLACEMENT, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A cloak of ventriloquism appeared at your feet!");
		}
		if (u.urmaxlvlD == 15) {
			ubookz = mksobj(SPE_CHARM_MONSTER, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of friendship appeared at your feet!");
		}
		if (u.urmaxlvlD == 20) {
			ubookz = mksobj(SPE_POLYMORPH, TRUE, FALSE, FALSE);
			if (ubookz) dropy(ubookz);
			pline("A book of change appeared at your feet!");
		}

	} /* bard check */

	while (Role_if(PM_ZYBORG) && u.ulevel > u.urmaxlvlB) {

		u.urmaxlvlB++;

		if (!rn2(3)) { switch (rnd(178)) {

			case 1: 
			case 2: 
			case 3: 
				if (!tech_known(T_BERSERK)) {    	learntech(T_BERSERK, FROMOUTSIDE, 1);
			    	You("learn how to perform berserk!");
				}
				break;
			case 4: 
			case 5: 
			case 6: 
				if (!tech_known(T_KIII)) {    	learntech(T_KIII, FROMOUTSIDE, 1);
			    	You("learn how to perform kiii!");
				}
				break;
			case 7: 
			case 8: 
			case 9: 
				if (!tech_known(T_RESEARCH)) {    	learntech(T_RESEARCH, FROMOUTSIDE, 1);
			    	You("learn how to perform research!");
				}
				break;
			case 10: 
			case 11: 
			case 12: 
				if (!tech_known(T_SURGERY)) {    	learntech(T_SURGERY, FROMOUTSIDE, 1);
			    	You("learn how to perform surgery!");
				}
				break;
			case 13: 
			case 14: 
			case 15: 
				if (!tech_known(T_REINFORCE)) {    	learntech(T_REINFORCE, FROMOUTSIDE, 1);
			    	You("learn how to perform reinforce memory!");
				}
				break;
			case 16: 
			case 17:
			case 18: 
				if (!tech_known(T_FLURRY)) {    	learntech(T_FLURRY, FROMOUTSIDE, 1);
			    	You("learn how to perform missile flurry!");
				}
				break;
			case 19: 
			case 20: 
			case 21: 
				if (!tech_known(T_PRACTICE)) {    	learntech(T_PRACTICE, FROMOUTSIDE, 1);
			    	You("learn how to perform weapon practice!");
				}
				break;
			case 22: 
			case 23: 
			case 24: 
				if (!tech_known(T_EVISCERATE)) {    	learntech(T_EVISCERATE, FROMOUTSIDE, 1);
			    	You("learn how to perform eviscerate!");
				}
				break;
			case 25: 
			case 26: 
			case 27: 
				if (!tech_known(T_HEAL_HANDS)) {    	learntech(T_HEAL_HANDS, FROMOUTSIDE, 1);
			    	You("learn how to perform healing hands!");
				}
				break;
			case 28: 
			case 29: 
			case 30: 
				if (!tech_known(T_CALM_STEED)) {    	learntech(T_CALM_STEED, FROMOUTSIDE, 1);
			    	You("learn how to perform calm steed!");
				}
				break;
			case 31: 
			case 32: 
			case 33: 
				if (!tech_known(T_TURN_UNDEAD)) {    	learntech(T_TURN_UNDEAD, FROMOUTSIDE, 1);
			    	You("learn how to perform turn undead!");
				}
				break;
			case 34: 
			case 35: 
			case 36: 
				if (!tech_known(T_VANISH)) {    	learntech(T_VANISH, FROMOUTSIDE, 1);
			    	You("learn how to perform vanish!");
				}
				break;
			case 37: 
			case 38: 
			case 39: 
				if (!tech_known(T_CUTTHROAT)) {    	learntech(T_CUTTHROAT, FROMOUTSIDE, 1);
			    	You("learn how to perform cutthroat!");
				}
				break;
			case 40: 
			case 41: 
				if (!tech_known(T_BLESSING)) {    	learntech(T_BLESSING, FROMOUTSIDE, 1);
			    	You("learn how to perform blessing!");
				}
				break;
			case 42: 
			case 43: 
			case 44: 
				if (!tech_known(T_E_FIST)) {    	learntech(T_E_FIST, FROMOUTSIDE, 1);
			    	You("learn how to perform elemental fist!");
				}
				break;
			case 45: 
			case 46: 
			case 47: 
				if (!tech_known(T_PRIMAL_ROAR)) {    	learntech(T_PRIMAL_ROAR, FROMOUTSIDE, 1);
			    	You("learn how to perform primal roar!");
				}
				break;
			case 48: 
			case 49: 
				if (!tech_known(T_LIQUID_LEAP)) {    	learntech(T_LIQUID_LEAP, FROMOUTSIDE, 1);
			    	You("learn how to perform liquid leap!");
				}
				break;
			case 50: 
			case 51: 
			case 52: 
				if (!tech_known(T_CRIT_STRIKE)) {    	learntech(T_CRIT_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform critical strike!");
				}
				break;
			case 53: 
			case 54: 
			case 55: 
				if (!tech_known(T_SIGIL_CONTROL)) {    	learntech(T_SIGIL_CONTROL, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of control!");
				}
				break;
			case 56: 
			case 57: 
			case 58: 
				if (!tech_known(T_SIGIL_TEMPEST)) {    	learntech(T_SIGIL_TEMPEST, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of tempest!");
				}
				break;
			case 59: 
			case 60: 
			case 61: 
				if (!tech_known(T_SIGIL_DISCHARGE)) {    	learntech(T_SIGIL_DISCHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of discharge!");
				}
				break;
			case 62: 
			case 63: 
			case 64: 
				if (!tech_known(T_RAISE_ZOMBIES)) {    	learntech(T_RAISE_ZOMBIES, FROMOUTSIDE, 1);
			    	You("learn how to perform raise zombies!");
				}
				break;
			case 65: 
				if (!tech_known(T_REVIVE)) {    	learntech(T_REVIVE, FROMOUTSIDE, 1);
			    	You("learn how to perform revivification!");
				}
				break;
			case 66: 
			case 67: 
			case 68: 
				if (!tech_known(T_WARD_FIRE)) {    	learntech(T_WARD_FIRE, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against fire!");
				}
				break;
			case 69: 
			case 70: 
			case 71: 
				if (!tech_known(T_WARD_COLD)) {    	learntech(T_WARD_COLD, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against cold!");
				}
				break;
			case 72: 
			case 73: 
			case 74: 
				if (!tech_known(T_WARD_ELEC)) {    	learntech(T_WARD_ELEC, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against electricity!");
				}
				break;
			case 75: 
			case 76: 
			case 77: 
				if (!tech_known(T_TINKER)) {    	learntech(T_TINKER, FROMOUTSIDE, 1);
			    	You("learn how to perform tinker!");
				}
				break;
			case 78: 
			case 79: 
			case 80: 
				if (!tech_known(T_RAGE)) {    	learntech(T_RAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform rage eruption!");
				}
				break;
			case 81: 
			case 82: 
			case 83: 
				if (!tech_known(T_BLINK)) {    	learntech(T_BLINK, FROMOUTSIDE, 1);
			    	You("learn how to perform blink!");
				}
				break;
			case 84: 
			case 85: 
			case 86: 
				if (!tech_known(T_CHI_STRIKE)) {    	learntech(T_CHI_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform chi strike!");
				}
				break;
			case 87: 
			case 88: 
			case 89: 
				if (!tech_known(T_DRAW_ENERGY)) {    	learntech(T_DRAW_ENERGY, FROMOUTSIDE, 1);
			    	You("learn how to perform draw energy!");
				}
				break;
			case 90: 
			case 91: 
			case 92: 
				if (!tech_known(T_CHI_HEALING)) {    	learntech(T_CHI_HEALING, FROMOUTSIDE, 1);
			    	You("learn how to perform chi healing!");
				}
				break;
			case 93: 
			case 94: 
			case 95: 
				if (!tech_known(T_DAZZLE)) {    	learntech(T_DAZZLE, FROMOUTSIDE, 1);
			    	You("learn how to perform dazzle!");
				}
				break;
			case 96: 
			case 97: 
			case 98: 
				if (!tech_known(T_BLITZ)) {    	learntech(T_BLITZ, FROMOUTSIDE, 1);
			    	You("learn how to perform chained blitz!");
				}
				break;
			case 99: 
			case 100: 
			case 101: 
				if (!tech_known(T_PUMMEL)) {    	learntech(T_PUMMEL, FROMOUTSIDE, 1);
			    	You("learn how to perform pummel!");
				}
				break;
			case 102: 
			case 103: 
			case 104: 
				if (!tech_known(T_G_SLAM)) {    	learntech(T_G_SLAM, FROMOUTSIDE, 1);
			    	You("learn how to perform ground slam!");
				}
				break;
			case 105: 
			case 106: 
			case 107: 
				if (!tech_known(T_DASH)) {    	learntech(T_DASH, FROMOUTSIDE, 1);
			    	You("learn how to perform air dash!");
				}
				break;
			case 108: 
			case 109: 
			case 110: 
				if (!tech_known(T_POWER_SURGE)) {    	learntech(T_POWER_SURGE, FROMOUTSIDE, 1);
			    	You("learn how to perform power surge!");
				}
				break;
			case 111: 
			case 112: 
			case 113: 
				if (!tech_known(T_SPIRIT_BOMB)) {    	learntech(T_SPIRIT_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform spirit bomb!");
				}
				break;
			case 114: 
			case 115: 
			case 116: 
				if (!tech_known(T_DRAW_BLOOD)) {    	learntech(T_DRAW_BLOOD, FROMOUTSIDE, 1);
			    	You("learn how to perform draw blood!");
				}
				break;
			case 117: 
				if (!tech_known(T_WORLD_FALL)) {    	learntech(T_WORLD_FALL, FROMOUTSIDE, 1);
			    	You("learn how to perform world fall!");
				}
				break;
			case 118: 
			case 119: 
			case 120: 
				if (!tech_known(T_CREATE_AMMO)) {    	learntech(T_CREATE_AMMO, FROMOUTSIDE, 1);
			    	You("learn how to perform create ammo!");
				}
				break;
			case 121: 
			case 122: 
			case 123: 
				if (!tech_known(T_POKE_BALL)) {    	learntech(T_POKE_BALL, FROMOUTSIDE, 1);
			    	You("learn how to perform poke ball!");
				}
				break;
			case 124: 
			case 125: 
			case 126: 
				if (!tech_known(T_ATTIRE_CHARM)) {    	learntech(T_ATTIRE_CHARM, FROMOUTSIDE, 1);
			    	You("learn how to perform attire charm!");
				}
				break;
			case 127: 
			case 128: 
			case 129: 
				if (!tech_known(T_SUMMON_TEAM_ANT)) {    	learntech(T_SUMMON_TEAM_ANT, FROMOUTSIDE, 1);
			    	You("learn how to perform summon team ant!");
				}
				break;
			case 130: 
			case 131: 
			case 132: 
				if (!tech_known(T_JEDI_JUMP)) {    	learntech(T_JEDI_JUMP, FROMOUTSIDE, 1);
			    	You("learn how to perform jedi jump!");
				}
				break;
			case 133: 
			case 134: 
			case 135: 
				if (!tech_known(T_CHARGE_SABER)) {    	learntech(T_CHARGE_SABER, FROMOUTSIDE, 1);
			    	You("learn how to perform charge saber!");
				}
				break;
			case 136: 
			case 137: 
			case 138: 
				if (!tech_known(T_TELEKINESIS)) {    	learntech(T_TELEKINESIS, FROMOUTSIDE, 1);
			    	You("learn how to perform telekinesis!");
				}
				break;
			case 139: 
				if (!tech_known(T_EGG_BOMB)) {    	learntech(T_EGG_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform egg bomb!");
				}
				break;
			case 140: 
			case 141: 
			case 142: 
				if (!tech_known(T_BOOZE)) {    	learntech(T_BOOZE, FROMOUTSIDE, 1);
			    	You("learn how to perform booze!");
				}
				break;

			case 143: 
			case 144: 
			case 145: 
				if (!tech_known(T_IRON_SKIN)) {    	learntech(T_IRON_SKIN, FROMOUTSIDE, 1);
			    	You("learn how to perform iron skin!");
				}
				break;
			case 146: 
				if (!tech_known(T_POLYFORM)) {    	learntech(T_POLYFORM, FROMOUTSIDE, 1);
			    	You("learn how to perform polyform!");
				}
				break;
			case 147: 
			case 148: 
			case 149: 
				if (!tech_known(T_CONCENTRATING)) {    	learntech(T_CONCENTRATING, FROMOUTSIDE, 1);
			    	You("learn how to perform concentrating!");
				}
				break;
			case 150: 
				if (!tech_known(T_SUMMON_PET)) {    	learntech(T_SUMMON_PET, FROMOUTSIDE, 1);
			    	You("learn how to perform summon pet!");
				}
				break;
			case 151: 
			case 152: 
				if (!tech_known(T_DOUBLE_THROWNAGE)) {    	learntech(T_DOUBLE_THROWNAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform double thrownage!");
				}
				break;
			case 153: 
			case 154: 
			case 155: 
				if (!tech_known(T_SHIELD_BASH)) {    	learntech(T_SHIELD_BASH, FROMOUTSIDE, 1);
			    	You("learn how to perform shield bash!");
				}
				break;
			case 156: 
			case 157: 
				if (!tech_known(T_RECHARGE)) {    	learntech(T_RECHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform recharge!");
				}
				break;
			case 158: 
			case 159: 
			case 160: 
				if (!tech_known(T_SPIRITUALITY_CHECK)) {    	learntech(T_SPIRITUALITY_CHECK, FROMOUTSIDE, 1);
			    	You("learn how to perform spirituality check!");
				}
				break;
			case 161: 
				if (!tech_known(T_EDDY_WIND)) {    	learntech(T_EDDY_WIND, FROMOUTSIDE, 1);
			    	You("learn how to perform eddy wind!");
				}
				break;
			case 162: 
				if (!tech_known(T_BLOOD_RITUAL)) {    	learntech(T_BLOOD_RITUAL, FROMOUTSIDE, 1);
			    	You("learn how to perform blood ritual!");
				}
				break;
			case 163: 
				if (!tech_known(T_ENT_S_POTION)) {    	learntech(T_ENT_S_POTION, FROMOUTSIDE, 1);
			    	You("learn how to perform ent's potion!");
				}
				break;
			case 164: 
			case 165: 
				if (!tech_known(T_LUCKY_GAMBLE)) {    	learntech(T_LUCKY_GAMBLE, FROMOUTSIDE, 1);
			    	You("learn how to perform lucky gamble!");
				}
				break;
			case 166: 
				if (!tech_known(T_DECONTAMINATE)) {    	learntech(T_DECONTAMINATE, FROMOUTSIDE, 1);
			    	You("learn how to perform decontaminate!");
				}
				break;
			case 167: 
				if (!tech_known(T_WONDERSPELL)) {    	learntech(T_WONDERSPELL, FROMOUTSIDE, 1);
			    	You("learn how to perform wonderspell!");
				}
				break;
			case 168: 
				if (!tech_known(T_RESET_TECHNIQUE)) {    	learntech(T_RESET_TECHNIQUE, FROMOUTSIDE, 1);
			    	You("learn how to perform reset technique!");
				}
				break;
			case 169: 
				if (!tech_known(T_DIAMOND_BARRIER)) {    	learntech(T_DIAMOND_BARRIER, FROMOUTSIDE, 1);
			    	You("learn how to perform diamond barrier!");
				}
				break;
			case 170: 
				if (!tech_known(T_ZAP_EM)) {    	learntech(T_ZAP_EM, FROMOUTSIDE, 1);
			    	You("learn how to perform zap em!");
				}
				break;
			case 171: 
				if (!tech_known(T_CARD_TRICK)) {    	learntech(T_CARD_TRICK, FROMOUTSIDE, 1);
			    	You("learn how to perform card trick!");
				}
				break;
			case 172: 
				if (!tech_known(T_SKILLOMORPH)) {    	learntech(T_SKILLOMORPH, FROMOUTSIDE, 1);
			    	You("learn how to perform skillomorph!");
				}
				break;
			case 173: 
				if (!tech_known(T_TERRAIN_CLEANUP)) {    	learntech(T_TERRAIN_CLEANUP, FROMOUTSIDE, 1);
			    	You("learn how to perform terrain cleanup!");
				}
				break;

			default:
				break;

		      }

		}

	}

	while (Role_if(PM_ANACHRONOUNBINDER) && u.ulevel > u.urmaxlvlJ) {

		u.urmaxlvlJ++;

		int maxtrainingamount = 0;
		int skillnumber = 0;
		int actualskillselection = 0;
		int amountofpossibleskills = 1;
		int i;

		for (i = 0; i < P_NUM_SKILLS; i++) {
			if (P_SKILL(i) != P_ISRESTRICTED) continue;

			if (P_ADVANCE(i) > 0 && P_ADVANCE(i) >= maxtrainingamount) {
				if (P_ADVANCE(i) > maxtrainingamount) {
					amountofpossibleskills = 1;
					skillnumber = i;
					maxtrainingamount = P_ADVANCE(i);
				} else if (!rn2(amountofpossibleskills + 1)) {
					amountofpossibleskills++;
					skillnumber = i;
				} else {
					amountofpossibleskills++;
				}
			}
		}

		if (skillnumber > 0 && maxtrainingamount > 0) {
			unrestrict_weapon_skill(skillnumber);
			P_MAX_SKILL(skillnumber) = (maxtrainingamount >= 5000 ? P_SUPREME_MASTER : maxtrainingamount >= 500 ? P_GRAND_MASTER : maxtrainingamount >= 50 ? P_MASTER : P_EXPERT);
			pline("You can now learn the %s skill, with a new cap of %s.", P_NAME(skillnumber), maxtrainingamount >= 5000 ? "supreme master" : maxtrainingamount >= 500 ? "grand master" : maxtrainingamount >= 50 ? "master" : "expert");
		} else {
			pline("You've trained no unknown skills since your last level up and therefore you unfortunately don't learn anything new.");
		}

	} /* acu check */

	while (Role_if(PM_MYSTIC) && u.ulevel > u.urmaxlvlH) {

		u.urmaxlvlH++;

		if (!rn2(3)) { switch (rnd(178)) {

			case 1: 
			case 2: 
			case 3: 
				if (!tech_known(T_BERSERK)) {    	learntech(T_BERSERK, FROMOUTSIDE, 1);
			    	You("learn how to perform berserk!");
				}
				break;
			case 4: 
			case 5: 
			case 6: 
				if (!tech_known(T_KIII)) {    	learntech(T_KIII, FROMOUTSIDE, 1);
			    	You("learn how to perform kiii!");
				}
				break;
			case 7: 
			case 8: 
			case 9: 
				if (!tech_known(T_RESEARCH)) {    	learntech(T_RESEARCH, FROMOUTSIDE, 1);
			    	You("learn how to perform research!");
				}
				break;
			case 10: 
			case 11: 
			case 12: 
				if (!tech_known(T_SURGERY)) {    	learntech(T_SURGERY, FROMOUTSIDE, 1);
			    	You("learn how to perform surgery!");
				}
				break;
			case 13: 
			case 14: 
			case 15: 
				if (!tech_known(T_REINFORCE)) {    	learntech(T_REINFORCE, FROMOUTSIDE, 1);
			    	You("learn how to perform reinforce memory!");
				}
				break;
			case 16: 
			case 17:
			case 18: 
				if (!tech_known(T_FLURRY)) {    	learntech(T_FLURRY, FROMOUTSIDE, 1);
			    	You("learn how to perform missile flurry!");
				}
				break;
			case 19: 
			case 20: 
			case 21: 
				if (!tech_known(T_PRACTICE)) {    	learntech(T_PRACTICE, FROMOUTSIDE, 1);
			    	You("learn how to perform weapon practice!");
				}
				break;
			case 22: 
			case 23: 
			case 24: 
				if (!tech_known(T_EVISCERATE)) {    	learntech(T_EVISCERATE, FROMOUTSIDE, 1);
			    	You("learn how to perform eviscerate!");
				}
				break;
			case 25: 
			case 26: 
			case 27: 
				if (!tech_known(T_HEAL_HANDS)) {    	learntech(T_HEAL_HANDS, FROMOUTSIDE, 1);
			    	You("learn how to perform healing hands!");
				}
				break;
			case 28: 
			case 29: 
			case 30: 
				if (!tech_known(T_CALM_STEED)) {    	learntech(T_CALM_STEED, FROMOUTSIDE, 1);
			    	You("learn how to perform calm steed!");
				}
				break;
			case 31: 
			case 32: 
			case 33: 
				if (!tech_known(T_TURN_UNDEAD)) {    	learntech(T_TURN_UNDEAD, FROMOUTSIDE, 1);
			    	You("learn how to perform turn undead!");
				}
				break;
			case 34: 
			case 35: 
			case 36: 
				if (!tech_known(T_VANISH)) {    	learntech(T_VANISH, FROMOUTSIDE, 1);
			    	You("learn how to perform vanish!");
				}
				break;
			case 37: 
			case 38: 
			case 39: 
				if (!tech_known(T_CUTTHROAT)) {    	learntech(T_CUTTHROAT, FROMOUTSIDE, 1);
			    	You("learn how to perform cutthroat!");
				}
				break;
			case 40: 
			case 41: 
				if (!tech_known(T_BLESSING)) {    	learntech(T_BLESSING, FROMOUTSIDE, 1);
			    	You("learn how to perform blessing!");
				}
				break;
			case 42: 
			case 43: 
			case 44: 
				if (!tech_known(T_E_FIST)) {    	learntech(T_E_FIST, FROMOUTSIDE, 1);
			    	You("learn how to perform elemental fist!");
				}
				break;
			case 45: 
			case 46: 
			case 47: 
				if (!tech_known(T_PRIMAL_ROAR)) {    	learntech(T_PRIMAL_ROAR, FROMOUTSIDE, 1);
			    	You("learn how to perform primal roar!");
				}
				break;
			case 48: 
			case 49: 
				if (!tech_known(T_LIQUID_LEAP)) {    	learntech(T_LIQUID_LEAP, FROMOUTSIDE, 1);
			    	You("learn how to perform liquid leap!");
				}
				break;
			case 50: 
			case 51: 
			case 52: 
				if (!tech_known(T_CRIT_STRIKE)) {    	learntech(T_CRIT_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform critical strike!");
				}
				break;
			case 53: 
			case 54: 
			case 55: 
				if (!tech_known(T_SIGIL_CONTROL)) {    	learntech(T_SIGIL_CONTROL, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of control!");
				}
				break;
			case 56: 
			case 57: 
			case 58: 
				if (!tech_known(T_SIGIL_TEMPEST)) {    	learntech(T_SIGIL_TEMPEST, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of tempest!");
				}
				break;
			case 59: 
			case 60: 
			case 61: 
				if (!tech_known(T_SIGIL_DISCHARGE)) {    	learntech(T_SIGIL_DISCHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of discharge!");
				}
				break;
			case 62: 
			case 63: 
			case 64: 
				if (!tech_known(T_RAISE_ZOMBIES)) {    	learntech(T_RAISE_ZOMBIES, FROMOUTSIDE, 1);
			    	You("learn how to perform raise zombies!");
				}
				break;
			case 65: 
				if (!tech_known(T_REVIVE)) {    	learntech(T_REVIVE, FROMOUTSIDE, 1);
			    	You("learn how to perform revivification!");
				}
				break;
			case 66: 
			case 67: 
			case 68: 
				if (!tech_known(T_WARD_FIRE)) {    	learntech(T_WARD_FIRE, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against fire!");
				}
				break;
			case 69: 
			case 70: 
			case 71: 
				if (!tech_known(T_WARD_COLD)) {    	learntech(T_WARD_COLD, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against cold!");
				}
				break;
			case 72: 
			case 73: 
			case 74: 
				if (!tech_known(T_WARD_ELEC)) {    	learntech(T_WARD_ELEC, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against electricity!");
				}
				break;
			case 75: 
			case 76: 
			case 77: 
				if (!tech_known(T_TINKER)) {    	learntech(T_TINKER, FROMOUTSIDE, 1);
			    	You("learn how to perform tinker!");
				}
				break;
			case 78: 
			case 79: 
			case 80: 
				if (!tech_known(T_RAGE)) {    	learntech(T_RAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform rage eruption!");
				}
				break;
			case 81: 
			case 82: 
			case 83: 
				if (!tech_known(T_BLINK)) {    	learntech(T_BLINK, FROMOUTSIDE, 1);
			    	You("learn how to perform blink!");
				}
				break;
			case 84: 
			case 85: 
			case 86: 
				if (!tech_known(T_CHI_STRIKE)) {    	learntech(T_CHI_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform chi strike!");
				}
				break;
			case 87: 
			case 88: 
			case 89: 
				if (!tech_known(T_DRAW_ENERGY)) {    	learntech(T_DRAW_ENERGY, FROMOUTSIDE, 1);
			    	You("learn how to perform draw energy!");
				}
				break;
			case 90: 
			case 91: 
			case 92: 
				if (!tech_known(T_CHI_HEALING)) {    	learntech(T_CHI_HEALING, FROMOUTSIDE, 1);
			    	You("learn how to perform chi healing!");
				}
				break;
			case 93: 
			case 94: 
			case 95: 
				if (!tech_known(T_DAZZLE)) {    	learntech(T_DAZZLE, FROMOUTSIDE, 1);
			    	You("learn how to perform dazzle!");
				}
				break;
			case 96: 
			case 97: 
			case 98: 
				if (!tech_known(T_BLITZ)) {    	learntech(T_BLITZ, FROMOUTSIDE, 1);
			    	You("learn how to perform chained blitz!");
				}
				break;
			case 99: 
			case 100: 
			case 101: 
				if (!tech_known(T_PUMMEL)) {    	learntech(T_PUMMEL, FROMOUTSIDE, 1);
			    	You("learn how to perform pummel!");
				}
				break;
			case 102: 
			case 103: 
			case 104: 
				if (!tech_known(T_G_SLAM)) {    	learntech(T_G_SLAM, FROMOUTSIDE, 1);
			    	You("learn how to perform ground slam!");
				}
				break;
			case 105: 
			case 106: 
			case 107: 
				if (!tech_known(T_DASH)) {    	learntech(T_DASH, FROMOUTSIDE, 1);
			    	You("learn how to perform air dash!");
				}
				break;
			case 108: 
			case 109: 
			case 110: 
				if (!tech_known(T_POWER_SURGE)) {    	learntech(T_POWER_SURGE, FROMOUTSIDE, 1);
			    	You("learn how to perform power surge!");
				}
				break;
			case 111: 
			case 112: 
			case 113: 
				if (!tech_known(T_SPIRIT_BOMB)) {    	learntech(T_SPIRIT_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform spirit bomb!");
				}
				break;
			case 114: 
			case 115: 
			case 116: 
				if (!tech_known(T_DRAW_BLOOD)) {    	learntech(T_DRAW_BLOOD, FROMOUTSIDE, 1);
			    	You("learn how to perform draw blood!");
				}
				break;
			case 117: 
				if (!tech_known(T_WORLD_FALL)) {    	learntech(T_WORLD_FALL, FROMOUTSIDE, 1);
			    	You("learn how to perform world fall!");
				}
				break;
			case 118: 
			case 119: 
			case 120: 
				if (!tech_known(T_CREATE_AMMO)) {    	learntech(T_CREATE_AMMO, FROMOUTSIDE, 1);
			    	You("learn how to perform create ammo!");
				}
				break;
			case 121: 
			case 122: 
			case 123: 
				if (!tech_known(T_POKE_BALL)) {    	learntech(T_POKE_BALL, FROMOUTSIDE, 1);
			    	You("learn how to perform poke ball!");
				}
				break;
			case 124: 
			case 125: 
			case 126: 
				if (!tech_known(T_ATTIRE_CHARM)) {    	learntech(T_ATTIRE_CHARM, FROMOUTSIDE, 1);
			    	You("learn how to perform attire charm!");
				}
				break;
			case 127: 
			case 128: 
			case 129: 
				if (!tech_known(T_SUMMON_TEAM_ANT)) {    	learntech(T_SUMMON_TEAM_ANT, FROMOUTSIDE, 1);
			    	You("learn how to perform summon team ant!");
				}
				break;
			case 130: 
			case 131: 
			case 132: 
				if (!tech_known(T_JEDI_JUMP)) {    	learntech(T_JEDI_JUMP, FROMOUTSIDE, 1);
			    	You("learn how to perform jedi jump!");
				}
				break;
			case 133: 
			case 134: 
			case 135: 
				if (!tech_known(T_CHARGE_SABER)) {    	learntech(T_CHARGE_SABER, FROMOUTSIDE, 1);
			    	You("learn how to perform charge saber!");
				}
				break;
			case 136: 
			case 137: 
			case 138: 
				if (!tech_known(T_TELEKINESIS)) {    	learntech(T_TELEKINESIS, FROMOUTSIDE, 1);
			    	You("learn how to perform telekinesis!");
				}
				break;
			case 139: 
				if (!tech_known(T_EGG_BOMB)) {    	learntech(T_EGG_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform egg bomb!");
				}
				break;
			case 140: 
			case 141: 
			case 142: 
				if (!tech_known(T_BOOZE)) {    	learntech(T_BOOZE, FROMOUTSIDE, 1);
			    	You("learn how to perform booze!");
				}
				break;

			case 143: 
			case 144: 
			case 145: 
				if (!tech_known(T_IRON_SKIN)) {    	learntech(T_IRON_SKIN, FROMOUTSIDE, 1);
			    	You("learn how to perform iron skin!");
				}
				break;
			case 146: 
				if (!tech_known(T_POLYFORM)) {    	learntech(T_POLYFORM, FROMOUTSIDE, 1);
			    	You("learn how to perform polyform!");
				}
				break;
			case 147: 
			case 148: 
			case 149: 
				if (!tech_known(T_CONCENTRATING)) {    	learntech(T_CONCENTRATING, FROMOUTSIDE, 1);
			    	You("learn how to perform concentrating!");
				}
				break;
			case 150: 
				if (!tech_known(T_SUMMON_PET)) {    	learntech(T_SUMMON_PET, FROMOUTSIDE, 1);
			    	You("learn how to perform summon pet!");
				}
				break;
			case 151: 
			case 152: 
				if (!tech_known(T_DOUBLE_THROWNAGE)) {    	learntech(T_DOUBLE_THROWNAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform double thrownage!");
				}
				break;
			case 153: 
			case 154: 
			case 155: 
				if (!tech_known(T_SHIELD_BASH)) {    	learntech(T_SHIELD_BASH, FROMOUTSIDE, 1);
			    	You("learn how to perform shield bash!");
				}
				break;
			case 156: 
			case 157: 
				if (!tech_known(T_RECHARGE)) {    	learntech(T_RECHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform recharge!");
				}
				break;
			case 158: 
			case 159: 
			case 160: 
				if (!tech_known(T_SPIRITUALITY_CHECK)) {    	learntech(T_SPIRITUALITY_CHECK, FROMOUTSIDE, 1);
			    	You("learn how to perform spirituality check!");
				}
				break;
			case 161: 
				if (!tech_known(T_EDDY_WIND)) {    	learntech(T_EDDY_WIND, FROMOUTSIDE, 1);
			    	You("learn how to perform eddy wind!");
				}
				break;
			case 162: 
				if (!tech_known(T_BLOOD_RITUAL)) {    	learntech(T_BLOOD_RITUAL, FROMOUTSIDE, 1);
			    	You("learn how to perform blood ritual!");
				}
				break;
			case 163: 
				if (!tech_known(T_ENT_S_POTION)) {    	learntech(T_ENT_S_POTION, FROMOUTSIDE, 1);
			    	You("learn how to perform ent's potion!");
				}
				break;
			case 164: 
			case 165: 
				if (!tech_known(T_LUCKY_GAMBLE)) {    	learntech(T_LUCKY_GAMBLE, FROMOUTSIDE, 1);
			    	You("learn how to perform lucky gamble!");
				}
				break;
			case 166: 
				if (!tech_known(T_DECONTAMINATE)) {    	learntech(T_DECONTAMINATE, FROMOUTSIDE, 1);
			    	You("learn how to perform decontaminate!");
				}
				break;
			case 167: 
				if (!tech_known(T_WONDERSPELL)) {    	learntech(T_WONDERSPELL, FROMOUTSIDE, 1);
			    	You("learn how to perform wonderspell!");
				}
				break;
			case 168: 
				if (!tech_known(T_RESET_TECHNIQUE)) {    	learntech(T_RESET_TECHNIQUE, FROMOUTSIDE, 1);
			    	You("learn how to perform reset technique!");
				}
				break;
			case 169: 
				if (!tech_known(T_DIAMOND_BARRIER)) {    	learntech(T_DIAMOND_BARRIER, FROMOUTSIDE, 1);
			    	You("learn how to perform diamond barrier!");
				}
				break;
			case 170: 
				if (!tech_known(T_ZAP_EM)) {    	learntech(T_ZAP_EM, FROMOUTSIDE, 1);
			    	You("learn how to perform zap em!");
				}
				break;
			case 171: 
				if (!tech_known(T_CARD_TRICK)) {    	learntech(T_CARD_TRICK, FROMOUTSIDE, 1);
			    	You("learn how to perform card trick!");
				}
				break;
			case 172: 
				if (!tech_known(T_SKILLOMORPH)) {    	learntech(T_SKILLOMORPH, FROMOUTSIDE, 1);
			    	You("learn how to perform skillomorph!");
				}
				break;
			case 173: 
				if (!tech_known(T_TERRAIN_CLEANUP)) {    	learntech(T_TERRAIN_CLEANUP, FROMOUTSIDE, 1);
			    	You("learn how to perform terrain cleanup!");
				}
				break;

			default:
				break;

		      }

		}

	}

	/* Lorskel wants wild talents to learn random techniques, and I agree that this is supposed to be the case. --Amy */
	while (Role_if(PM_WILD_TALENT) && u.ulevel > u.urmaxlvlG) {

		u.urmaxlvlG++;

		if (!rn2(5)) { switch (rnd(178)) {

			case 1: 
			case 2: 
			case 3: 
				if (!tech_known(T_BERSERK)) {    	learntech(T_BERSERK, FROMOUTSIDE, 1);
			    	You("learn how to perform berserk!");
				}
				break;
			case 4: 
			case 5: 
			case 6: 
				if (!tech_known(T_KIII)) {    	learntech(T_KIII, FROMOUTSIDE, 1);
			    	You("learn how to perform kiii!");
				}
				break;
			case 7: 
			case 8: 
			case 9: 
				if (!tech_known(T_RESEARCH)) {    	learntech(T_RESEARCH, FROMOUTSIDE, 1);
			    	You("learn how to perform research!");
				}
				break;
			case 10: 
			case 11: 
			case 12: 
				if (!tech_known(T_SURGERY)) {    	learntech(T_SURGERY, FROMOUTSIDE, 1);
			    	You("learn how to perform surgery!");
				}
				break;
			case 13: 
			case 14: 
			case 15: 
				if (!tech_known(T_REINFORCE)) {    	learntech(T_REINFORCE, FROMOUTSIDE, 1);
			    	You("learn how to perform reinforce memory!");
				}
				break;
			case 16: 
			case 17:
			case 18: 
				if (!tech_known(T_FLURRY)) {    	learntech(T_FLURRY, FROMOUTSIDE, 1);
			    	You("learn how to perform missile flurry!");
				}
				break;
			case 19: 
			case 20: 
			case 21: 
				if (!tech_known(T_PRACTICE)) {    	learntech(T_PRACTICE, FROMOUTSIDE, 1);
			    	You("learn how to perform weapon practice!");
				}
				break;
			case 22: 
			case 23: 
			case 24: 
				if (!tech_known(T_EVISCERATE)) {    	learntech(T_EVISCERATE, FROMOUTSIDE, 1);
			    	You("learn how to perform eviscerate!");
				}
				break;
			case 25: 
			case 26: 
			case 27: 
				if (!tech_known(T_HEAL_HANDS)) {    	learntech(T_HEAL_HANDS, FROMOUTSIDE, 1);
			    	You("learn how to perform healing hands!");
				}
				break;
			case 28: 
			case 29: 
			case 30: 
				if (!tech_known(T_CALM_STEED)) {    	learntech(T_CALM_STEED, FROMOUTSIDE, 1);
			    	You("learn how to perform calm steed!");
				}
				break;
			case 31: 
			case 32: 
			case 33: 
				if (!tech_known(T_TURN_UNDEAD)) {    	learntech(T_TURN_UNDEAD, FROMOUTSIDE, 1);
			    	You("learn how to perform turn undead!");
				}
				break;
			case 34: 
			case 35: 
			case 36: 
				if (!tech_known(T_VANISH)) {    	learntech(T_VANISH, FROMOUTSIDE, 1);
			    	You("learn how to perform vanish!");
				}
				break;
			case 37: 
			case 38: 
			case 39: 
				if (!tech_known(T_CUTTHROAT)) {    	learntech(T_CUTTHROAT, FROMOUTSIDE, 1);
			    	You("learn how to perform cutthroat!");
				}
				break;
			case 40: 
			case 41: 
				if (!tech_known(T_BLESSING)) {    	learntech(T_BLESSING, FROMOUTSIDE, 1);
			    	You("learn how to perform blessing!");
				}
				break;
			case 42: 
			case 43: 
			case 44: 
				if (!tech_known(T_E_FIST)) {    	learntech(T_E_FIST, FROMOUTSIDE, 1);
			    	You("learn how to perform elemental fist!");
				}
				break;
			case 45: 
			case 46: 
			case 47: 
				if (!tech_known(T_PRIMAL_ROAR)) {    	learntech(T_PRIMAL_ROAR, FROMOUTSIDE, 1);
			    	You("learn how to perform primal roar!");
				}
				break;
			case 48: 
			case 49: 
				if (!tech_known(T_LIQUID_LEAP)) {    	learntech(T_LIQUID_LEAP, FROMOUTSIDE, 1);
			    	You("learn how to perform liquid leap!");
				}
				break;
			case 50: 
			case 51: 
			case 52: 
				if (!tech_known(T_CRIT_STRIKE)) {    	learntech(T_CRIT_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform critical strike!");
				}
				break;
			case 53: 
			case 54: 
			case 55: 
				if (!tech_known(T_SIGIL_CONTROL)) {    	learntech(T_SIGIL_CONTROL, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of control!");
				}
				break;
			case 56: 
			case 57: 
			case 58: 
				if (!tech_known(T_SIGIL_TEMPEST)) {    	learntech(T_SIGIL_TEMPEST, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of tempest!");
				}
				break;
			case 59: 
			case 60: 
			case 61: 
				if (!tech_known(T_SIGIL_DISCHARGE)) {    	learntech(T_SIGIL_DISCHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of discharge!");
				}
				break;
			case 62: 
			case 63: 
			case 64: 
				if (!tech_known(T_RAISE_ZOMBIES)) {    	learntech(T_RAISE_ZOMBIES, FROMOUTSIDE, 1);
			    	You("learn how to perform raise zombies!");
				}
				break;
			case 65: 
				if (!tech_known(T_REVIVE)) {    	learntech(T_REVIVE, FROMOUTSIDE, 1);
			    	You("learn how to perform revivification!");
				}
				break;
			case 66: 
			case 67: 
			case 68: 
				if (!tech_known(T_WARD_FIRE)) {    	learntech(T_WARD_FIRE, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against fire!");
				}
				break;
			case 69: 
			case 70: 
			case 71: 
				if (!tech_known(T_WARD_COLD)) {    	learntech(T_WARD_COLD, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against cold!");
				}
				break;
			case 72: 
			case 73: 
			case 74: 
				if (!tech_known(T_WARD_ELEC)) {    	learntech(T_WARD_ELEC, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against electricity!");
				}
				break;
			case 75: 
			case 76: 
			case 77: 
				if (!tech_known(T_TINKER)) {    	learntech(T_TINKER, FROMOUTSIDE, 1);
			    	You("learn how to perform tinker!");
				}
				break;
			case 78: 
			case 79: 
			case 80: 
				if (!tech_known(T_RAGE)) {    	learntech(T_RAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform rage eruption!");
				}
				break;
			case 81: 
			case 82: 
			case 83: 
				if (!tech_known(T_BLINK)) {    	learntech(T_BLINK, FROMOUTSIDE, 1);
			    	You("learn how to perform blink!");
				}
				break;
			case 84: 
			case 85: 
			case 86: 
				if (!tech_known(T_CHI_STRIKE)) {    	learntech(T_CHI_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform chi strike!");
				}
				break;
			case 87: 
			case 88: 
			case 89: 
				if (!tech_known(T_DRAW_ENERGY)) {    	learntech(T_DRAW_ENERGY, FROMOUTSIDE, 1);
			    	You("learn how to perform draw energy!");
				}
				break;
			case 90: 
			case 91: 
			case 92: 
				if (!tech_known(T_CHI_HEALING)) {    	learntech(T_CHI_HEALING, FROMOUTSIDE, 1);
			    	You("learn how to perform chi healing!");
				}
				break;
			case 93: 
			case 94: 
			case 95: 
				if (!tech_known(T_DAZZLE)) {    	learntech(T_DAZZLE, FROMOUTSIDE, 1);
			    	You("learn how to perform dazzle!");
				}
				break;
			case 96: 
			case 97: 
			case 98: 
				if (!tech_known(T_BLITZ)) {    	learntech(T_BLITZ, FROMOUTSIDE, 1);
			    	You("learn how to perform chained blitz!");
				}
				break;
			case 99: 
			case 100: 
			case 101: 
				if (!tech_known(T_PUMMEL)) {    	learntech(T_PUMMEL, FROMOUTSIDE, 1);
			    	You("learn how to perform pummel!");
				}
				break;
			case 102: 
			case 103: 
			case 104: 
				if (!tech_known(T_G_SLAM)) {    	learntech(T_G_SLAM, FROMOUTSIDE, 1);
			    	You("learn how to perform ground slam!");
				}
				break;
			case 105: 
			case 106: 
			case 107: 
				if (!tech_known(T_DASH)) {    	learntech(T_DASH, FROMOUTSIDE, 1);
			    	You("learn how to perform air dash!");
				}
				break;
			case 108: 
			case 109: 
			case 110: 
				if (!tech_known(T_POWER_SURGE)) {    	learntech(T_POWER_SURGE, FROMOUTSIDE, 1);
			    	You("learn how to perform power surge!");
				}
				break;
			case 111: 
			case 112: 
			case 113: 
				if (!tech_known(T_SPIRIT_BOMB)) {    	learntech(T_SPIRIT_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform spirit bomb!");
				}
				break;
			case 114: 
			case 115: 
			case 116: 
				if (!tech_known(T_DRAW_BLOOD)) {    	learntech(T_DRAW_BLOOD, FROMOUTSIDE, 1);
			    	You("learn how to perform draw blood!");
				}
				break;
			case 117: 
				if (!tech_known(T_WORLD_FALL)) {    	learntech(T_WORLD_FALL, FROMOUTSIDE, 1);
			    	You("learn how to perform world fall!");
				}
				break;
			case 118: 
			case 119: 
			case 120: 
				if (!tech_known(T_CREATE_AMMO)) {    	learntech(T_CREATE_AMMO, FROMOUTSIDE, 1);
			    	You("learn how to perform create ammo!");
				}
				break;
			case 121: 
			case 122: 
			case 123: 
				if (!tech_known(T_POKE_BALL)) {    	learntech(T_POKE_BALL, FROMOUTSIDE, 1);
			    	You("learn how to perform poke ball!");
				}
				break;
			case 124: 
			case 125: 
			case 126: 
				if (!tech_known(T_ATTIRE_CHARM)) {    	learntech(T_ATTIRE_CHARM, FROMOUTSIDE, 1);
			    	You("learn how to perform attire charm!");
				}
				break;
			case 127: 
			case 128: 
			case 129: 
				if (!tech_known(T_SUMMON_TEAM_ANT)) {    	learntech(T_SUMMON_TEAM_ANT, FROMOUTSIDE, 1);
			    	You("learn how to perform summon team ant!");
				}
				break;
			case 130: 
			case 131: 
			case 132: 
				if (!tech_known(T_JEDI_JUMP)) {    	learntech(T_JEDI_JUMP, FROMOUTSIDE, 1);
			    	You("learn how to perform jedi jump!");
				}
				break;
			case 133: 
			case 134: 
			case 135: 
				if (!tech_known(T_CHARGE_SABER)) {    	learntech(T_CHARGE_SABER, FROMOUTSIDE, 1);
			    	You("learn how to perform charge saber!");
				}
				break;
			case 136: 
			case 137: 
			case 138: 
				if (!tech_known(T_TELEKINESIS)) {    	learntech(T_TELEKINESIS, FROMOUTSIDE, 1);
			    	You("learn how to perform telekinesis!");
				}
				break;
			case 139: 
				if (!tech_known(T_EGG_BOMB)) {    	learntech(T_EGG_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform egg bomb!");
				}
				break;
			case 140: 
			case 141: 
			case 142: 
				if (!tech_known(T_BOOZE)) {    	learntech(T_BOOZE, FROMOUTSIDE, 1);
			    	You("learn how to perform booze!");
				}
				break;

			case 143: 
			case 144: 
			case 145: 
				if (!tech_known(T_IRON_SKIN)) {    	learntech(T_IRON_SKIN, FROMOUTSIDE, 1);
			    	You("learn how to perform iron skin!");
				}
				break;
			case 146: 
				if (!tech_known(T_POLYFORM)) {    	learntech(T_POLYFORM, FROMOUTSIDE, 1);
			    	You("learn how to perform polyform!");
				}
				break;
			case 147: 
			case 148: 
			case 149: 
				if (!tech_known(T_CONCENTRATING)) {    	learntech(T_CONCENTRATING, FROMOUTSIDE, 1);
			    	You("learn how to perform concentrating!");
				}
				break;
			case 150: 
				if (!tech_known(T_SUMMON_PET)) {    	learntech(T_SUMMON_PET, FROMOUTSIDE, 1);
			    	You("learn how to perform summon pet!");
				}
				break;
			case 151: 
			case 152: 
				if (!tech_known(T_DOUBLE_THROWNAGE)) {    	learntech(T_DOUBLE_THROWNAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform double thrownage!");
				}
				break;
			case 153: 
			case 154: 
			case 155: 
				if (!tech_known(T_SHIELD_BASH)) {    	learntech(T_SHIELD_BASH, FROMOUTSIDE, 1);
			    	You("learn how to perform shield bash!");
				}
				break;
			case 156: 
			case 157: 
				if (!tech_known(T_RECHARGE)) {    	learntech(T_RECHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform recharge!");
				}
				break;
			case 158: 
			case 159: 
			case 160: 
				if (!tech_known(T_SPIRITUALITY_CHECK)) {    	learntech(T_SPIRITUALITY_CHECK, FROMOUTSIDE, 1);
			    	You("learn how to perform spirituality check!");
				}
				break;
			case 161: 
				if (!tech_known(T_EDDY_WIND)) {    	learntech(T_EDDY_WIND, FROMOUTSIDE, 1);
			    	You("learn how to perform eddy wind!");
				}
				break;
			case 162: 
				if (!tech_known(T_BLOOD_RITUAL)) {    	learntech(T_BLOOD_RITUAL, FROMOUTSIDE, 1);
			    	You("learn how to perform blood ritual!");
				}
				break;
			case 163: 
				if (!tech_known(T_ENT_S_POTION)) {    	learntech(T_ENT_S_POTION, FROMOUTSIDE, 1);
			    	You("learn how to perform ent's potion!");
				}
				break;
			case 164: 
			case 165: 
				if (!tech_known(T_LUCKY_GAMBLE)) {    	learntech(T_LUCKY_GAMBLE, FROMOUTSIDE, 1);
			    	You("learn how to perform lucky gamble!");
				}
				break;
			case 166: 
				if (!tech_known(T_DECONTAMINATE)) {    	learntech(T_DECONTAMINATE, FROMOUTSIDE, 1);
			    	You("learn how to perform decontaminate!");
				}
				break;
			case 167: 
				if (!tech_known(T_WONDERSPELL)) {    	learntech(T_WONDERSPELL, FROMOUTSIDE, 1);
			    	You("learn how to perform wonderspell!");
				}
				break;
			case 168: 
				if (!tech_known(T_RESET_TECHNIQUE)) {    	learntech(T_RESET_TECHNIQUE, FROMOUTSIDE, 1);
			    	You("learn how to perform reset technique!");
				}
				break;
			case 169: 
				if (!tech_known(T_DIAMOND_BARRIER)) {    	learntech(T_DIAMOND_BARRIER, FROMOUTSIDE, 1);
			    	You("learn how to perform diamond barrier!");
				}
				break;
			case 170: 
				if (!tech_known(T_ZAP_EM)) {    	learntech(T_ZAP_EM, FROMOUTSIDE, 1);
			    	You("learn how to perform zap em!");
				}
				break;
			case 171: 
				if (!tech_known(T_CARD_TRICK)) {    	learntech(T_CARD_TRICK, FROMOUTSIDE, 1);
			    	You("learn how to perform card trick!");
				}
				break;
			case 172: 
				if (!tech_known(T_SKILLOMORPH)) {    	learntech(T_SKILLOMORPH, FROMOUTSIDE, 1);
			    	You("learn how to perform skillomorph!");
				}
				break;
			case 173: 
				if (!tech_known(T_TERRAIN_CLEANUP)) {    	learntech(T_TERRAIN_CLEANUP, FROMOUTSIDE, 1);
			    	You("learn how to perform terrain cleanup!");
				}
				break;

			default:
				break;

		      }

		}

	}

	if (Race_if(PM_PLAYER_SLIME) && !((Deprovement || u.uprops[DEPROVEMENT].extrinsic || have_deprovementstone()) && !(u.ulevel < 10 && !rn2(u.ulevel + 1)) && rn2(10) ) && Role_if(PM_DQ_SLIME) && (u.ulevel > u.urmaxlvlI) ) {

		u.urmaxlvlI++;

		u.uhpmax += rnd(10);
		u.uenmax += rnd(10);

	}

	while (isamerican && Role_if(PM_GLADIATOR) && (u.ulevel > u.urmaxlvlE) ) {

		u.urmaxlvlE++;

		if (!rn2(2)) { switch (rnd(178)) {

			case 1: 
			case 2: 
			case 3: 
				if (!tech_known(T_BERSERK)) {    	learntech(T_BERSERK, FROMOUTSIDE, 1);
			    	You("learn how to perform berserk!");
				}
				break;
			case 4: 
			case 5: 
			case 6: 
				if (!tech_known(T_KIII)) {    	learntech(T_KIII, FROMOUTSIDE, 1);
			    	You("learn how to perform kiii!");
				}
				break;
			case 7: 
			case 8: 
			case 9: 
				if (!tech_known(T_RESEARCH)) {    	learntech(T_RESEARCH, FROMOUTSIDE, 1);
			    	You("learn how to perform research!");
				}
				break;
			case 10: 
			case 11: 
			case 12: 
				if (!tech_known(T_SURGERY)) {    	learntech(T_SURGERY, FROMOUTSIDE, 1);
			    	You("learn how to perform surgery!");
				}
				break;
			case 13: 
			case 14: 
			case 15: 
				if (!tech_known(T_REINFORCE)) {    	learntech(T_REINFORCE, FROMOUTSIDE, 1);
			    	You("learn how to perform reinforce memory!");
				}
				break;
			case 16: 
			case 17:
			case 18: 
				if (!tech_known(T_FLURRY)) {    	learntech(T_FLURRY, FROMOUTSIDE, 1);
			    	You("learn how to perform missile flurry!");
				}
				break;
			case 19: 
			case 20: 
			case 21: 
				if (!tech_known(T_PRACTICE)) {    	learntech(T_PRACTICE, FROMOUTSIDE, 1);
			    	You("learn how to perform weapon practice!");
				}
				break;
			case 22: 
			case 23: 
			case 24: 
				if (!tech_known(T_EVISCERATE)) {    	learntech(T_EVISCERATE, FROMOUTSIDE, 1);
			    	You("learn how to perform eviscerate!");
				}
				break;
			case 25: 
			case 26: 
			case 27: 
				if (!tech_known(T_HEAL_HANDS)) {    	learntech(T_HEAL_HANDS, FROMOUTSIDE, 1);
			    	You("learn how to perform healing hands!");
				}
				break;
			case 28: 
			case 29: 
			case 30: 
				if (!tech_known(T_CALM_STEED)) {    	learntech(T_CALM_STEED, FROMOUTSIDE, 1);
			    	You("learn how to perform calm steed!");
				}
				break;
			case 31: 
			case 32: 
			case 33: 
				if (!tech_known(T_TURN_UNDEAD)) {    	learntech(T_TURN_UNDEAD, FROMOUTSIDE, 1);
			    	You("learn how to perform turn undead!");
				}
				break;
			case 34: 
			case 35: 
			case 36: 
				if (!tech_known(T_VANISH)) {    	learntech(T_VANISH, FROMOUTSIDE, 1);
			    	You("learn how to perform vanish!");
				}
				break;
			case 37: 
			case 38: 
			case 39: 
				if (!tech_known(T_CUTTHROAT)) {    	learntech(T_CUTTHROAT, FROMOUTSIDE, 1);
			    	You("learn how to perform cutthroat!");
				}
				break;
			case 40: 
			case 41: 
				if (!tech_known(T_BLESSING)) {    	learntech(T_BLESSING, FROMOUTSIDE, 1);
			    	You("learn how to perform blessing!");
				}
				break;
			case 42: 
			case 43: 
			case 44: 
				if (!tech_known(T_E_FIST)) {    	learntech(T_E_FIST, FROMOUTSIDE, 1);
			    	You("learn how to perform elemental fist!");
				}
				break;
			case 45: 
			case 46: 
			case 47: 
				if (!tech_known(T_PRIMAL_ROAR)) {    	learntech(T_PRIMAL_ROAR, FROMOUTSIDE, 1);
			    	You("learn how to perform primal roar!");
				}
				break;
			case 48: 
			case 49: 
				if (!tech_known(T_LIQUID_LEAP)) {    	learntech(T_LIQUID_LEAP, FROMOUTSIDE, 1);
			    	You("learn how to perform liquid leap!");
				}
				break;
			case 50: 
			case 51: 
			case 52: 
				if (!tech_known(T_CRIT_STRIKE)) {    	learntech(T_CRIT_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform critical strike!");
				}
				break;
			case 53: 
			case 54: 
			case 55: 
				if (!tech_known(T_SIGIL_CONTROL)) {    	learntech(T_SIGIL_CONTROL, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of control!");
				}
				break;
			case 56: 
			case 57: 
			case 58: 
				if (!tech_known(T_SIGIL_TEMPEST)) {    	learntech(T_SIGIL_TEMPEST, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of tempest!");
				}
				break;
			case 59: 
			case 60: 
			case 61: 
				if (!tech_known(T_SIGIL_DISCHARGE)) {    	learntech(T_SIGIL_DISCHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform sigil of discharge!");
				}
				break;
			case 62: 
			case 63: 
			case 64: 
				if (!tech_known(T_RAISE_ZOMBIES)) {    	learntech(T_RAISE_ZOMBIES, FROMOUTSIDE, 1);
			    	You("learn how to perform raise zombies!");
				}
				break;
			case 65: 
				if (!tech_known(T_REVIVE)) {    	learntech(T_REVIVE, FROMOUTSIDE, 1);
			    	You("learn how to perform revivification!");
				}
				break;
			case 66: 
			case 67: 
			case 68: 
				if (!tech_known(T_WARD_FIRE)) {    	learntech(T_WARD_FIRE, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against fire!");
				}
				break;
			case 69: 
			case 70: 
			case 71: 
				if (!tech_known(T_WARD_COLD)) {    	learntech(T_WARD_COLD, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against cold!");
				}
				break;
			case 72: 
			case 73: 
			case 74: 
				if (!tech_known(T_WARD_ELEC)) {    	learntech(T_WARD_ELEC, FROMOUTSIDE, 1);
			    	You("learn how to perform ward against electricity!");
				}
				break;
			case 75: 
			case 76: 
			case 77: 
				if (!tech_known(T_TINKER)) {    	learntech(T_TINKER, FROMOUTSIDE, 1);
			    	You("learn how to perform tinker!");
				}
				break;
			case 78: 
			case 79: 
			case 80: 
				if (!tech_known(T_RAGE)) {    	learntech(T_RAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform rage eruption!");
				}
				break;
			case 81: 
			case 82: 
			case 83: 
				if (!tech_known(T_BLINK)) {    	learntech(T_BLINK, FROMOUTSIDE, 1);
			    	You("learn how to perform blink!");
				}
				break;
			case 84: 
			case 85: 
			case 86: 
				if (!tech_known(T_CHI_STRIKE)) {    	learntech(T_CHI_STRIKE, FROMOUTSIDE, 1);
			    	You("learn how to perform chi strike!");
				}
				break;
			case 87: 
			case 88: 
			case 89: 
				if (!tech_known(T_DRAW_ENERGY)) {    	learntech(T_DRAW_ENERGY, FROMOUTSIDE, 1);
			    	You("learn how to perform draw energy!");
				}
				break;
			case 90: 
			case 91: 
			case 92: 
				if (!tech_known(T_CHI_HEALING)) {    	learntech(T_CHI_HEALING, FROMOUTSIDE, 1);
			    	You("learn how to perform chi healing!");
				}
				break;
			case 93: 
			case 94: 
			case 95: 
				if (!tech_known(T_DAZZLE)) {    	learntech(T_DAZZLE, FROMOUTSIDE, 1);
			    	You("learn how to perform dazzle!");
				}
				break;
			case 96: 
			case 97: 
			case 98: 
				if (!tech_known(T_BLITZ)) {    	learntech(T_BLITZ, FROMOUTSIDE, 1);
			    	You("learn how to perform chained blitz!");
				}
				break;
			case 99: 
			case 100: 
			case 101: 
				if (!tech_known(T_PUMMEL)) {    	learntech(T_PUMMEL, FROMOUTSIDE, 1);
			    	You("learn how to perform pummel!");
				}
				break;
			case 102: 
			case 103: 
			case 104: 
				if (!tech_known(T_G_SLAM)) {    	learntech(T_G_SLAM, FROMOUTSIDE, 1);
			    	You("learn how to perform ground slam!");
				}
				break;
			case 105: 
			case 106: 
			case 107: 
				if (!tech_known(T_DASH)) {    	learntech(T_DASH, FROMOUTSIDE, 1);
			    	You("learn how to perform air dash!");
				}
				break;
			case 108: 
			case 109: 
			case 110: 
				if (!tech_known(T_POWER_SURGE)) {    	learntech(T_POWER_SURGE, FROMOUTSIDE, 1);
			    	You("learn how to perform power surge!");
				}
				break;
			case 111: 
			case 112: 
			case 113: 
				if (!tech_known(T_SPIRIT_BOMB)) {    	learntech(T_SPIRIT_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform spirit bomb!");
				}
				break;
			case 114: 
			case 115: 
			case 116: 
				if (!tech_known(T_DRAW_BLOOD)) {    	learntech(T_DRAW_BLOOD, FROMOUTSIDE, 1);
			    	You("learn how to perform draw blood!");
				}
				break;
			case 117: 
				if (!tech_known(T_WORLD_FALL)) {    	learntech(T_WORLD_FALL, FROMOUTSIDE, 1);
			    	You("learn how to perform world fall!");
				}
				break;
			case 118: 
			case 119: 
			case 120: 
				if (!tech_known(T_CREATE_AMMO)) {    	learntech(T_CREATE_AMMO, FROMOUTSIDE, 1);
			    	You("learn how to perform create ammo!");
				}
				break;
			case 121: 
			case 122: 
			case 123: 
				if (!tech_known(T_POKE_BALL)) {    	learntech(T_POKE_BALL, FROMOUTSIDE, 1);
			    	You("learn how to perform poke ball!");
				}
				break;
			case 124: 
			case 125: 
			case 126: 
				if (!tech_known(T_ATTIRE_CHARM)) {    	learntech(T_ATTIRE_CHARM, FROMOUTSIDE, 1);
			    	You("learn how to perform attire charm!");
				}
				break;
			case 127: 
			case 128: 
			case 129: 
				if (!tech_known(T_SUMMON_TEAM_ANT)) {    	learntech(T_SUMMON_TEAM_ANT, FROMOUTSIDE, 1);
			    	You("learn how to perform summon team ant!");
				}
				break;
			case 130: 
			case 131: 
			case 132: 
				if (!tech_known(T_JEDI_JUMP)) {    	learntech(T_JEDI_JUMP, FROMOUTSIDE, 1);
			    	You("learn how to perform jedi jump!");
				}
				break;
			case 133: 
			case 134: 
			case 135: 
				if (!tech_known(T_CHARGE_SABER)) {    	learntech(T_CHARGE_SABER, FROMOUTSIDE, 1);
			    	You("learn how to perform charge saber!");
				}
				break;
			case 136: 
			case 137: 
			case 138: 
				if (!tech_known(T_TELEKINESIS)) {    	learntech(T_TELEKINESIS, FROMOUTSIDE, 1);
			    	You("learn how to perform telekinesis!");
				}
				break;
			case 139: 
				if (!tech_known(T_EGG_BOMB)) {    	learntech(T_EGG_BOMB, FROMOUTSIDE, 1);
			    	You("learn how to perform egg bomb!");
				}
				break;
			case 140: 
			case 141: 
			case 142: 
				if (!tech_known(T_BOOZE)) {    	learntech(T_BOOZE, FROMOUTSIDE, 1);
			    	You("learn how to perform booze!");
				}
				break;

			case 143: 
			case 144: 
			case 145: 
				if (!tech_known(T_IRON_SKIN)) {    	learntech(T_IRON_SKIN, FROMOUTSIDE, 1);
			    	You("learn how to perform iron skin!");
				}
				break;
			case 146: 
				if (!tech_known(T_POLYFORM)) {    	learntech(T_POLYFORM, FROMOUTSIDE, 1);
			    	You("learn how to perform polyform!");
				}
				break;
			case 147: 
			case 148: 
			case 149: 
				if (!tech_known(T_CONCENTRATING)) {    	learntech(T_CONCENTRATING, FROMOUTSIDE, 1);
			    	You("learn how to perform concentrating!");
				}
				break;
			case 150: 
				if (!tech_known(T_SUMMON_PET)) {    	learntech(T_SUMMON_PET, FROMOUTSIDE, 1);
			    	You("learn how to perform summon pet!");
				}
				break;
			case 151: 
			case 152: 
				if (!tech_known(T_DOUBLE_THROWNAGE)) {    	learntech(T_DOUBLE_THROWNAGE, FROMOUTSIDE, 1);
			    	You("learn how to perform double thrownage!");
				}
				break;
			case 153: 
			case 154: 
			case 155: 
				if (!tech_known(T_SHIELD_BASH)) {    	learntech(T_SHIELD_BASH, FROMOUTSIDE, 1);
			    	You("learn how to perform shield bash!");
				}
				break;
			case 156: 
			case 157: 
				if (!tech_known(T_RECHARGE)) {    	learntech(T_RECHARGE, FROMOUTSIDE, 1);
			    	You("learn how to perform recharge!");
				}
				break;
			case 158: 
			case 159: 
			case 160: 
				if (!tech_known(T_SPIRITUALITY_CHECK)) {    	learntech(T_SPIRITUALITY_CHECK, FROMOUTSIDE, 1);
			    	You("learn how to perform spirituality check!");
				}
				break;
			case 161: 
				if (!tech_known(T_EDDY_WIND)) {    	learntech(T_EDDY_WIND, FROMOUTSIDE, 1);
			    	You("learn how to perform eddy wind!");
				}
				break;
			case 162: 
				if (!tech_known(T_BLOOD_RITUAL)) {    	learntech(T_BLOOD_RITUAL, FROMOUTSIDE, 1);
			    	You("learn how to perform blood ritual!");
				}
				break;
			case 163: 
				if (!tech_known(T_ENT_S_POTION)) {    	learntech(T_ENT_S_POTION, FROMOUTSIDE, 1);
			    	You("learn how to perform ent's potion!");
				}
				break;
			case 164: 
			case 165: 
				if (!tech_known(T_LUCKY_GAMBLE)) {    	learntech(T_LUCKY_GAMBLE, FROMOUTSIDE, 1);
			    	You("learn how to perform lucky gamble!");
				}
				break;
			case 166: 
				if (!tech_known(T_DECONTAMINATE)) {    	learntech(T_DECONTAMINATE, FROMOUTSIDE, 1);
			    	You("learn how to perform decontaminate!");
				}
				break;
			case 167: 
				if (!tech_known(T_WONDERSPELL)) {    	learntech(T_WONDERSPELL, FROMOUTSIDE, 1);
			    	You("learn how to perform wonderspell!");
				}
				break;
			case 168: 
				if (!tech_known(T_RESET_TECHNIQUE)) {    	learntech(T_RESET_TECHNIQUE, FROMOUTSIDE, 1);
			    	You("learn how to perform reset technique!");
				}
				break;
			case 169: 
				if (!tech_known(T_DIAMOND_BARRIER)) {    	learntech(T_DIAMOND_BARRIER, FROMOUTSIDE, 1);
			    	You("learn how to perform diamond barrier!");
				}
				break;
			case 170: 
				if (!tech_known(T_ZAP_EM)) {    	learntech(T_ZAP_EM, FROMOUTSIDE, 1);
			    	You("learn how to perform zap em!");
				}
				break;
			case 171: 
				if (!tech_known(T_CARD_TRICK)) {    	learntech(T_CARD_TRICK, FROMOUTSIDE, 1);
			    	You("learn how to perform card trick!");
				}
				break;
			case 172: 
				if (!tech_known(T_SKILLOMORPH)) {    	learntech(T_SKILLOMORPH, FROMOUTSIDE, 1);
			    	You("learn how to perform skillomorph!");
				}
				break;
			case 173: 
				if (!tech_known(T_TERRAIN_CLEANUP)) {    	learntech(T_TERRAIN_CLEANUP, FROMOUTSIDE, 1);
			    	You("learn how to perform terrain cleanup!");
				}
				break;

			default:
				break;


			}

		}

	}

	/* now, set the levels accordingly --Amy */
	if (u.urmaxlvl < u.ulevel) u.urmaxlvl = u.ulevel;
	if (u.urmaxlvlB < u.ulevel) u.urmaxlvlB = u.ulevel;
	if (u.urmaxlvlC < u.ulevel) u.urmaxlvlC = u.ulevel;
	if (u.urmaxlvlD < u.ulevel) u.urmaxlvlD = u.ulevel;
	if (u.urmaxlvlE < u.ulevel) u.urmaxlvlE = u.ulevel;
	if (u.urmaxlvlF < u.ulevel) u.urmaxlvlF = u.ulevel;
	if (u.urmaxlvlG < u.ulevel) u.urmaxlvlG = u.ulevel;
	if (u.urmaxlvlH < u.ulevel) u.urmaxlvlH = u.ulevel;
	if (u.urmaxlvlI < u.ulevel) u.urmaxlvlI = u.ulevel;
	if (u.urmaxlvlJ < u.ulevel) u.urmaxlvlJ = u.ulevel;
	if (u.urmaxlvlK < u.ulevel) u.urmaxlvlK = u.ulevel;
	if (u.urmaxlvlL < u.ulevel) u.urmaxlvlL = u.ulevel;
	if (u.urmaxlvlM < u.ulevel) u.urmaxlvlM = u.ulevel;
	if (u.urmaxlvlUP < u.ulevel) u.urmaxlvlUP = u.ulevel;

}

/*exper.c*/
