/*	SCCS Id: @(#)youprop.h	3.4	1999/07/02	*/
/* Copyright (c) 1989 Mike Threepoint				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef YOUPROP_H
#define YOUPROP_H

#include "prop.h"
#include "permonst.h"
#include "mondata.h"
#include "pm.h"


/* KMH, intrinsics patch.
 * Reorganized and rewritten for >32-bit properties.
 * HXxx refers to intrinsic bitfields while in human form.
 * EXxx refers to extrinsic bitfields from worn objects.
 * BXxx refers to the cause of the property being blocked.
 * Xxx refers to any source, including polymorph forms.
 * NoXxx refers to a property being deactivated (addition by Amy).
 */


#define maybe_polyd(if_so,if_not)	(Upolyd ? (if_so) : (if_not))

#define HardcoreAlienMode	(Race_if(PM_HC_ALIEN) && flags.female)

#define CanHavePinkSpells (PinkSpells || u.uprops[PINK_SPELLS].extrinsic || have_pinkspellstone())
#define CanHaveBrightCyanSpells (BrightCyanSpells || u.uprops[BRIGHT_CYAN_SPELLS].extrinsic || have_brightcyanspellstone())
#define CanHaveCyanSpells (CyanSpells || u.uprops[CYAN_SPELLS].extrinsic || have_cyanspellstone())
#define CanHaveBlackSpells (BlackSpells || u.uprops[BLACK_SPELLS].extrinsic || have_blackspellstone() || (uwep && uwep->oartifact == ART_EGRID_BUG) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_EGRID_BUG) )
#define CanHaveOrangeSpells (OrangeSpells || u.uprops[ORANGE_SPELLS].extrinsic || have_orangespellstone())
#define CanHaveRedSpells (RedSpells || u.uprops[RED_SPELLS].extrinsic || have_redspellstone())
#define CanHavePlatinumSpells (PlatinumSpells || u.uprops[PLATINUM_SPELLS].extrinsic || have_platinumspellstone())
#define CanHaveSilverSpells (SilverSpells || u.uprops[SILVER_SPELLS].extrinsic || have_silverspellstone() || (uwep && uwep->oartifact == ART_PORKMAN_S_BALLS_OF_STEEL) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_PORKMAN_S_BALLS_OF_STEEL) || (uwep && uwep->oartifact == ART_DIZZY_METAL_STORM) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_DIZZY_METAL_STORM) )
#define CanHaveMetalSpells (MetalSpells || u.uprops[METAL_SPELLS].extrinsic || have_metalspellstone())
#define CanHaveGreenSpells (GreenSpells || u.uprops[GREEN_SPELLS].extrinsic || have_greenspellstone())
#define CanHaveBlueSpells (BlueSpells || u.uprops[BLUE_SPELLS].extrinsic || have_bluespellstone())
#define CanHaveGraySpells (CompleteGraySpells || u.uprops[COMPLETE_GRAY_SPELLS].extrinsic || have_greyoutstone())
#define CanHaveBrownSpells (BrownSpells || u.uprops[BROWN_SPELLS].extrinsic || have_brownspellstone())
#define CanHaveWhiteSpells (WhiteSpells || u.uprops[WHITE_SPELLS].extrinsic || have_whitespellstone())
#define CanHaveVioletSpells (VioletSpells || u.uprops[VIOLET_SPELLS].extrinsic || have_violetspellstone())
#define CanHaveYellowSpells (YellowSpells || u.uprops[YELLOW_SPELLS].extrinsic || have_yellowspellstone() || (uamul && uamul->oartifact == ART_DIKKIN_S_DRAGON_TEETH && !(Role_if(PM_BARD) && Race_if(PM_KOBOLT) ) ) || (uarmc && uarmc->oartifact == ART_FAILSET_GAMBLE) || (uwep && uwep->oartifact == ART_DIKKIN_S_DEADLIGHT) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_DIKKIN_S_DEADLIGHT) || (uwep && uwep->oartifact == ART_DIKKIN_S_FAVORITE_SPELL) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_DIKKIN_S_FAVORITE_SPELL))

#define SpellColorPink	(CanHavePinkSpells)
#define SpellColorBrightCyan	(!CanHavePinkSpells && CanHaveBrightCyanSpells)
#define SpellColorCyan	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && CanHaveCyanSpells)
#define SpellColorBlack	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && CanHaveBlackSpells)
#define SpellColorOrange	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && CanHaveOrangeSpells)
#define SpellColorRed	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && CanHaveRedSpells)
#define SpellColorPlatinum	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && CanHavePlatinumSpells)
#define SpellColorSilver	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && CanHaveSilverSpells)
#define SpellColorMetal	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && CanHaveMetalSpells)
#define SpellColorGreen	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && CanHaveGreenSpells)
#define SpellColorBlue	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && !CanHaveGreenSpells && CanHaveBlueSpells)
#define SpellColorGray	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && !CanHaveGreenSpells && !CanHaveBlueSpells && CanHaveGraySpells)
#define SpellColorBrown	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && !CanHaveGreenSpells && !CanHaveBlueSpells && !CanHaveGraySpells && CanHaveBrownSpells)
#define SpellColorWhite	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && !CanHaveGreenSpells && !CanHaveBlueSpells && !CanHaveGraySpells && !CanHaveBrownSpells && CanHaveWhiteSpells)
#define SpellColorViolet	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && !CanHaveGreenSpells && !CanHaveBlueSpells && !CanHaveGraySpells && !CanHaveBrownSpells && !CanHaveWhiteSpells && CanHaveVioletSpells)
#define SpellColorYellow	(!CanHavePinkSpells && !CanHaveBrightCyanSpells && !CanHaveCyanSpells && !CanHaveBlackSpells && !CanHaveOrangeSpells && !CanHaveRedSpells && !CanHavePlatinumSpells && !CanHaveSilverSpells && !CanHaveMetalSpells && !CanHaveGreenSpells && !CanHaveBlueSpells && !CanHaveGraySpells && !CanHaveBrownSpells && !CanHaveWhiteSpells && !CanHaveVioletSpells && CanHaveYellowSpells)

#define EnglandMode	(RngeEngland || (uarmc && itemhasappearance(uarmc, APP_LONG_RANGE_CLOAK)) || (uarmu && uarmu->oartifact == ART_BEAM_MULTIPLIER) || (uwep && uwep->oartifact == ART_MINOLONG_ELBOW) || (uarmg && itemhasappearance(uarmg, APP_ENGLISH_GLOVES)) )

#define NastyTrapNation		(NastynationBug || u.uprops[NASTY_NATION_BUG].extrinsic || have_multitrappingstone() || Role_if(PM_WALSCHOLAR) || (uamul && uamul->oartifact == ART_ANASTASIA_S_LURE))
#define PlayerUninformation	(UninformationProblem || u.uprops[UNINFORMATION].extrinsic || have_uninformationstone() || (uarms && uarms->oartifact == ART_FIVE_STAR_PARTY))

#define ManlerIsChasing	(ManlerEffect || u.uprops[MANLER_EFFECT].extrinsic || have_manlerstone() || (uwep && uwep->oartifact == ART_DIZZY_METAL_STORM) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_DIZZY_METAL_STORM))

#define PlayerHearsMessages	(u.uprops[RANDOM_MESSAGES].extrinsic || RandomMessages || have_messagestone() || (uwep && uwep->oartifact == ART_FILTHY_PRESS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_FILTHY_PRESS) )

#define ThereIsNoLite	(NoliteBug || u.uprops[NOLITE_BUG].extrinsic || have_nolightstone() || (uwep && uwep->oartifact == ART_WEAKITE_THRUST) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_WEAKITE_THRUST) )

#define LLMMessages	(MemoryLoss || u.uprops[MEMORY_LOST].extrinsic || (uarmh && uarmh->oartifact == ART_LLLLLLLLLLLLLM) || have_memorylossstone() )

#define MessagesSuppressed	(MessageSuppression || u.uprops[MESSAGE_SUPPRESSION_BUG].extrinsic || have_messagesuppressionstone() )

#define FleeceyScripts	(FleecescriptBug || u.uprops[FLEECESCRIPT_BUG].extrinsic || have_fleecestone() || (uarmh && uarmh->oartifact == ART_TELEVISION_WONDER) || (uimplant && uimplant->oartifact == ART_IME_SPEW) )

#define CurseAsYouUse	(CurseuseEffect || u.uprops[CURSEUSE_EFFECT].extrinsic || have_curseusestone() || (uamul && uamul->oartifact == ART_ARABELLA_S_DICINATOR) )

#define InventoryDoesNotGo	(InventoryLoss || u.uprops[INVENTORY_LOST].extrinsic || (uarmh && uarmh->oartifact == ART_DEEP_INSANITY) || (uarmh && uarmh->oartifact == ART_FLAT_INSANITY) || have_inventorylossstone())

#define AutomaticMorePrompt	(AutomoreBug || u.uprops[AUTOMORE_BUG].extrinsic || have_automorestone() || (uamul && uamul->oartifact == ART_HELIOKOPIS_S_KEYBOARD_CURS) )

#define DisplayDoesNotGo	(DisplayLoss || u.uprops[DISPLAY_LOST].extrinsic || have_displaystone() || (uarmc && uarmc->oartifact == ART_CLOAK_OF_THE_CONSORT && !(moves % 10 == 0)) )
#define DisplayDoesNotGoAtAll	(DisplayLoss || u.uprops[DISPLAY_LOST].extrinsic || have_displaystone() || (uarmc && uarmc->oartifact == ART_CLOAK_OF_THE_CONSORT) )
/* special case in dungeon.c and restore.c!!! */

#define FlimmeringStrips	(FlickerStripBug || u.uprops[FLICKER_STRIP_BUG].extrinsic || have_flickerstripstone() || (uarmh && uarmh->oartifact == ART_VIDEO_DECODER) || (uimplant && uimplant->oartifact == ART_IME_SPEW) )

#define TheInfoIsFucked	(FuckedInfoBug || u.uprops[FUCKED_INFO_BUG].extrinsic || have_infofuckstone())

#define FingerlessGloves	(uarmg && (itemhasappearance(uarmg, APP_FINGERLESS_GLOVES) || itemhasappearance(uarmg, APP_SILK_FINGERLINGS)) )

#define PlayerHearsSoundEffects	(SoundEffectBug || u.uprops[SOUND_EFFECT_BUG].extrinsic || (ublindf && ublindf->oartifact == ART_SOUNDTONE_FM) || have_soundeffectstone())

#define TronEffectIsActive	(TronEffect || u.uprops[TRON_EFFECT].extrinsic || have_tronstone())

#define WeightDisplayIsArbitrary	(ArbitraryWeightBug || u.uprops[ARBITRARY_WEIGHT_BUG].extrinsic || have_weightstone())

#define MenuIsBugged	(MenuBug || u.uprops[MENU_LOST].extrinsic || have_menubugstone())

#define YouHaveBigscript	(BigscriptEffect || (uarmh && uarmh->oartifact == ART_YOU_SEE_HERE_AN_ARTIFACT) || u.uprops[BIGSCRIPT].extrinsic || have_bigscriptstone() )

#define YouGetLotsOfSanity	(SanityTrebleEffect || u.uprops[SANITY_TREBLE_EFFECT].extrinsic || have_sanitytreblestone())

#define RotThirteenCipher	(RotThirteen || u.uprops[ROT_THIRTEEN].extrinsic || have_rotthirteenstone() )

#define TheGameLaaaaags	(LatencyBugEffect || u.uprops[LATENCY_BUG].extrinsic || have_latencystone())

#define YouHaveTheSpeedBug	(Race_if(PM_PLAYER_MECHANIC) || SpeedBug || u.uprops[SPEED_BUG].extrinsic || (uarmf && uarmf->oartifact == ART_UNEVEN_ENGINE) || (uarmf && uarmf->oartifact == ART_ERROR_IN_PLAY_ENCHANTMENT) || have_speedbugstone())

#define YouAreThirsty	(Thirst || u.uprops[THIRST].extrinsic || have_thirststone() || (uwep && uwep->oartifact == ART_LUISA_S_CHARMING_BEAUTY) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_LUISA_S_CHARMING_BEAUTY))

#define YouAreScrewedEternally (LongScrewup || u.uprops[LONG_SCREWUP].extrinsic || have_longscrewupstone())

#define GravationAggravation (GravationEffect || u.uprops[GRAVATION].extrinsic || have_gravationstone())

#define GushieLushie	(GushlushEffect || u.uprops[GUSHLUSH].extrinsic || have_gushlushstone())
#define GushLevel	(GushieLushie ? 1 : u.ulevel)

#define CannotTeleport	((uarm && uarm->oartifact == ART_CHECK_YOUR_ESCAPES) || (uamul && uamul->oartifact == ART_ARABELLA_S_SWOONING_BEAUTY) || NoReturnEffect || u.uprops[NORETURN].extrinsic || have_noreturnstone())

#define YouAreDeaf	(Deafness || (uwep && uwep->oartifact == ART_MEMETAL) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_MEMETAL) || (uwep && uwep->oartifact == ART_VOICESHUTTER) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_VOICESHUTTER) || (uwep && uwep->oartifact == ART_BANG_BANG) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_BANG_BANG) || u.uprops[DEAFNESS].extrinsic || have_deafnessstone() || (uarmh && uarmh->oartifact == ART_YITH_VERSUS_BABY) )

#define MonsterGlyphHallu	(MonsterGlyphChange || u.uprops[MONSTER_GLYPH_BUG].extrinsic || have_monsterglyphstone())

#define PlayerCannotUseSkills	(AllSkillsUnskilled || u.uprops[SKILL_DEACTIVATED].extrinsic || (uarmc && uarmc->oartifact == ART_PALEOLITHIC_ELBOW_CONTRACT) || have_unskilledstone())

/* There used to be long-ass macros here but I think they're causing out of memory errors, so they became functions --Amy */
#define PlayerInHighHeels	(playerwearshighheels())

#define PlayerInSexyFlats	(playerwearssexyflats())

#define CanHaveStilettoHeels	(maybestilettoheels())

#define CanHaveConeHeels	(maybeconeheels())

#define CanHaveBlockHeels	(maybeblockheels())

#define CanHaveWedgeHeels	(maybewedgeheels())

#define PlayerInStilettoHeels	(CanHaveStilettoHeels)

#define PlayerInConeHeels	(!CanHaveStilettoHeels && CanHaveConeHeels)

#define PlayerInBlockHeels	(!CanHaveStilettoHeels && !CanHaveConeHeels && CanHaveBlockHeels)

#define PlayerInWedgeHeels	(!CanHaveStilettoHeels && !CanHaveConeHeels && !CanHaveBlockHeels && CanHaveWedgeHeels)

/*** Resistances to troubles ***/
/* With intrinsics and extrinsics */
#define HFire_resistance	u.uprops[FIRE_RES].intrinsic
#define EFire_resistance	u.uprops[FIRE_RES].extrinsic
#define IntFire_resistance	(HFire_resistance || resists_fire(&youmonst) || is_fire_resistant(youmonst.data))
#define ExtFire_resistance	(EFire_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == FIRE_RES) || (uarmh && uarmh->oartifact == ART_SPECTRAL_RESISTANCE) || (uarmh && uarmh->oartifact == ART_JESTES_TAKA_KURWA) || (uarmu && uarmu->oartifact == ART_BEAM_MULTIPLIER) || (uleft && uleft->oartifact == ART_FIRE_NIGHT) || (uright && uright->oartifact == ART_FIRE_NIGHT) || (uarmf && uarmf->oartifact == ART_YET_ANOTHER_STUPID_IDEA) || (uwep && uwep->oartifact == ART_AND_YOUR_MORTAL_WORLD_SHAL) || (uarmf && uarmf->oartifact == ART_CLICHE_WEAR) || (uarmf && uarmf->oartifact == ART_JOSEFINE_S_EVILNESS) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uwep && uwep->oartifact == ART_SAXS_BEAUTY) || (uarm && uarm->oartifact == ART_REQUIRED_POWER_PLANT_GEAR) || (uwep && uwep->oartifact == ART_PRISMATIC_PROTECTION) || (uarmh && uarmh->oartifact == ART_HAVE_ALL_YOU_NEED) || (uarmf && uarmf->oartifact == ART_BLUEDE) || (uwep && uwep->oartifact == ART_FAEAEAEAEAEAU) || (uarmc && uarmc->oartifact == ART_DRAGONHIDE_ARMER) || (uwep && uwep->oartifact == ART_MISTY_S_MELEE_PLEASURE) || (uimplant && uimplant->oartifact == ART_POTATOROK) || (uarmh && uarmh->oartifact == ART_WAR_MASK_OF_DURIN) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_RUBBER_SHOALS) || (uimplant && uimplant->oartifact == ART_CORONATION_CULMINATION) || (uarmu && uarmu->oartifact == ART_BIENVENIDO_A_MIAMI) || (uarmu && uarmu->oartifact == ART_PRISMATIC_SHIRT) || (uarmf && uarmf->oartifact == ART_GRENEUVENIA_S_HUG) || (uarmh && uarmh->oartifact == ART_MASSIVE_IRON_CROWN_OF_MORG) || (uarmf && uarmf->oartifact == ART_TEMPERATOR) || (uarm && uarm->oartifact == ART_ARMOR_OF_EREBOR) || (uarmc && uarmc->oartifact == ART_FIREBURN_COLDSHATTER) || (uarmf && uarmf->oartifact == ART_NASTIST) || (uwep && uwep->oartifact == ART_STAFF_OF_THE_ARCHMAGI) || (uwep && uwep->oartifact == ART_WHAT_IT_SAYS_ON_THE_TIN) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uarmh && uarmh->oartifact == ART_SECURE_BATHMASTER) || (uwep && uwep->oartifact == ART_WRATH_OF_HEAVEN) || (uwep && uwep->oartifact == ART_COLD_SOUL) || u.uprops[STORM_HELM].extrinsic || u.uprops[ELEMENT_RES].extrinsic || (uarmf && itemhasappearance(uarmf, APP_KOREAN_SANDALS) && (moves % 3 == 0) ) ) )

#define Fire_resistance		(((IntFire_resistance && u.nonintrinsicproperty != FIRE_RES) || (ExtFire_resistance && u.nonextrinsicproperty != FIRE_RES)) && !hybridragontype(AD_FIRE) && !Race_if(PM_TROLLOR) && !Race_if(PM_ANCIPITAL) && !Race_if(PM_SEA_ELF) && !Race_if(PM_SPRIGGAN) && !Role_if(PM_ALTMER) && !NoFire_resistance)
#define StrongFire_resistance	(IntFire_resistance && ExtFire_resistance && Fire_resistance && u.nondoubleproperty != FIRE_RES)

#define NoFire_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FIRE_RES].intrinsic || RngeAids || (uarm && uarm->oartifact == ART_SUPERESCAPE_MAIL) || (u.impossibleproperty == FIRE_RES) || (uarm && uarm->oartifact == ART_ABSOLUTE_MONSTER_MAIL) || (uarm && uarm->oartifact == ART_FLEEING_MINE_MAIL) || (uarmf && uarmf->oartifact == ART_MEPHISTO_S_BROGUES) || (uarmf && uarmf->oartifact == ART_VERA_S_FREEZER) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HCold_resistance	u.uprops[COLD_RES].intrinsic
#define ECold_resistance	u.uprops[COLD_RES].extrinsic
#define IntCold_resistance	(HCold_resistance || resists_cold(&youmonst) || is_cold_resistant(youmonst.data))
#define ExtCold_resistance	(ECold_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == COLD_RES) ) || (uarmh && uarmh->oartifact == ART_SPECTRAL_RESISTANCE) || (uarmg && uarmg->oartifact == ART_SIGNONS_STEEL_TOTAL) || (uarmf && uarmf->oartifact == ART_MEPHISTO_S_BROGUES) || (uarmh && uarmh->oartifact == ART_JESTES_TAKA_KURWA) || (uarmf && uarmf->oartifact == ART_RARE_ASIAN_LADY) || (uarmf && uarmf->oartifact == ART_KATRIN_S_PARALYSIS) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_DUBAI_TOWER_BREAK) || (uarmf && uarmf->oartifact == ART_CLICHE_WEAR) || (uarmu && uarmu->oartifact == ART_BEAM_MULTIPLIER) || (uarmf && uarmf->oartifact == ART_JESSICA_S_TENDERNESS) || (uimplant && uimplant->oartifact == ART_CORONATION_CULMINATION) || (uarmu && uarmu->oartifact == ART_PRISMATIC_SHIRT) || (uarmf && uarmf->oartifact == ART_JOSEFINE_S_EVILNESS) || (uarmc && uarmc->oartifact == ART_DRAGONHIDE_ARMER) || (uwep && uwep->oartifact == ART_SAXS_BEAUTY) || (uarmf && uarmf->oartifact == ART_NASTIST) || (uarmf && uarmf->oartifact == ART_JOHANETTA_S_ROUGH_GENTLENE) || (uarmf && uarmf->oartifact == ART_LARISSA_S_ANGER) || (uarmf && uarmf->oartifact == ART_BLUEDE) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uarmh && uarmh->oartifact == ART_SECURE_BATHMASTER) || (uwep && uwep->oartifact == ART_PRISMATIC_PROTECTION) || (uarmh && uarmh->oartifact == ART_MASSIVE_IRON_CROWN_OF_MORG) || (uarmf && uarmf->oartifact == ART_CHOICE_OF_MATTER) || (uarmu && uarmu->oartifact == ART_BIENVENIDO_A_MIAMI) || (uarmf && uarmf->oartifact == ART_YVONNE_S_MODEL_AMBITION) || (uarmf && uarmf->oartifact == ART_CORINA_S_UNFAIR_SCRATCHER) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uarmh && uarmh->oartifact == ART_HAVE_ALL_YOU_NEED) || (uarmc && uarmc->oartifact == ART_FIREBURN_COLDSHATTER) || (uarm && uarm->oartifact == ART_ARMOR_OF_EREBOR) || (uarmf && uarmf->oartifact == ART_CORINA_S_SNOWY_TREAD) || (uarmc && uarmc->oartifact == ART_CLOAK_OF_THE_CONSORT) || (uwep && uwep->oartifact == ART_STAFF_OF_THE_ARCHMAGI) || (uwep && uwep->oartifact == ART_COLD_SOUL) || (uwep && uwep->oartifact == ART_RELEASE_FROM_CARE) || u.uprops[STORM_HELM].extrinsic || u.uprops[ELEMENT_RES].extrinsic)

#define Cold_resistance		(((IntCold_resistance && u.nonintrinsicproperty != COLD_RES) || (ExtCold_resistance && u.nonextrinsicproperty != COLD_RES)) && !Role_if(PM_ALTMER) && !hybridragontype(AD_COLD) && !NoCold_resistance)
#define StrongCold_resistance	(IntCold_resistance && ExtCold_resistance && Cold_resistance && u.nondoubleproperty != COLD_RES)

#define NoCold_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_COLD_RES].intrinsic || RngeAids || (u.impossibleproperty == COLD_RES) || (uleft && uleft->oartifact == ART_DEATHLY_COLD) || (uright && uright->oartifact == ART_DEATHLY_COLD) || Race_if(PM_PLAYER_SALAMANDER) || Race_if(PM_GAVIL) || Race_if(PM_JAVA) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HSleep_resistance	u.uprops[SLEEP_RES].intrinsic
#define ESleep_resistance	u.uprops[SLEEP_RES].extrinsic
#define IntSleep_resistance	(HSleep_resistance || FemtrapActiveNatalje || resists_sleep(&youmonst) || is_sleep_resistant(youmonst.data))
#define ExtSleep_resistance	(ESleep_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SLEEP_RES) ) || (uleft && uleft->oartifact == ART_FIRE_NIGHT) || (uright && uright->oartifact == ART_FIRE_NIGHT) || (uarmf && uarmf->oartifact == ART_SARAH_S_GRANNY_WEAR) || (uwep && uwep->oartifact == ART_SLEEPLESS_NIGHTS) || (uarmh && uarmh->oartifact == ART_JESTES_TAKA_KURWA) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uarmf && uarmf->oartifact == ART_NASTIST) || (uarmf && uarmf->oartifact == ART_CLICHE_WEAR) || (uarmf && uarmf->oartifact == ART_BLUEDE) || (uarmh && uarmh->oartifact == ART_UNIMPORTANT_ELEMENTS) || (uarmu && uarmu->oartifact == ART_PRISMATIC_SHIRT) || (uimplant && uimplant->oartifact == ART_CORONATION_CULMINATION) || (uarmf && uarmf->oartifact == ART_JESSICA_S_TENDERNESS) || (uarmh && uarmh->oartifact == ART_HAVE_ALL_YOU_NEED) || (uamul && uamul->oartifact == ART_SNOREFEST && (moves % 10 != 0) ) )

#define Sleep_resistance	( !(YouAreThirsty && (u.uhunger > 2000)) && !Race_if(PM_KOBOLT) && !Race_if(PM_DEEP_ELF) && !have_sleepstone() && !NoSleep_resistance && !hybridragontype(AD_SLEE) && ((IntSleep_resistance && u.nonintrinsicproperty != SLEEP_RES) || (ExtSleep_resistance && u.nonextrinsicproperty != SLEEP_RES)) )
#define StrongSleep_resistance	(IntSleep_resistance && ExtSleep_resistance && Sleep_resistance && u.nondoubleproperty != SLEEP_RES)

#define NoSleep_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SLEEP_RES].intrinsic || RngeAids || (uarms && uarms->oartifact == ART_LITTLE_THORN_ROSE) || (u.impossibleproperty == SLEEP_RES) || (uamul && uamul->oartifact == ART_SPELLCASTER_S_DREAM) || (uarmh && uarmh->oartifact == ART_DULLIFIER) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDisint_resistance	u.uprops[DISINT_RES].intrinsic
#define EDisint_resistance	u.uprops[DISINT_RES].extrinsic
#define IntDisint_resistance	(HDisint_resistance || resists_disint(&youmonst) || is_disint_resistant(youmonst.data))
#define ExtDisint_resistance	(EDisint_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == DISINT_RES) ) || (uarmu && uarmu->oartifact == ART_GENTLE_SOFT_CLOTHING) || (uarmc && uarmc->oartifact == ART_INA_S_LAB_COAT) || (uarmc && uarmc->oartifact == ART_INA_S_OVERCOAT) || (uarmf && uarmf->oartifact == ART_MADELEINE_S_GIRL_FOOTSTEPS) || (uarmf && uarmf->oartifact == ART_LISA_S_BUCKLED_BEAUTIES) || (uarmu && uarmu->oartifact == ART_ONYX_MANTLE) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uamul && uamul->oartifact == ART_ARABELLA_S_DICINATOR) || (uarmf && uarmf->oartifact == ART_ARVOGENIA_S_HIGH_HEELSES) || (uamul && uamul->oartifact == ART_ARABELLA_S_SWOONING_BEAUTY) || (uwep && uwep->oartifact == ART_MEANCANE) || (uarmf && uarmf->oartifact == ART_ELENETTES) || (ublindf && ublindf->oartifact == ART_STABLE_STUNT) || (uleft && uleft->oartifact == ART_RING_OF_THE_SCHWARTZ) || (uarmf && uarmf->oartifact == ART_SMELL_LIKE_DOG_SHIT) || (uarmf && uarmf->oartifact == ART_LARISSA_S_ANGER) || (uright && uright->oartifact == ART_RING_OF_THE_SCHWARTZ) || (uarms && uarms->oartifact == ART_ANTINSTANT_DEATH) || (uleft && uleft->oartifact == ART_ACHROMANTIC_RING) || (uright && uright->oartifact == ART_ACHROMANTIC_RING) || (uamul && uamul->oartifact == ART_STINGING_MEDALLION))

#define Disint_resistance	(((IntDisint_resistance && u.nonintrinsicproperty != DISINT_RES) || (ExtDisint_resistance && u.nonextrinsicproperty != DISINT_RES)) && !hybridragontype(AD_DISN) && !NoDisint_resistance)
#define StrongDisint_resistance	(IntDisint_resistance && ExtDisint_resistance && Disint_resistance && u.nondoubleproperty != DISINT_RES)

#define NoDisint_resistance (!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DISINT_RES].intrinsic || (uarmf && uarmf->oartifact == ART_SATAN_S_CHOPPING_BLOCK) || (uarmh && uarmh->oartifact == ART_UBB_RUPTURE) || RngeAids || (u.impossibleproperty == DISINT_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HShock_resistance	u.uprops[SHOCK_RES].intrinsic
#define EShock_resistance	u.uprops[SHOCK_RES].extrinsic
#define IntShock_resistance	(HShock_resistance || resists_elec(&youmonst) || is_elec_resistant(youmonst.data))
#define ExtShock_resistance	(EShock_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SHOCK_RES) ) || (uarmh && uarmh->oartifact == ART_SPECTRAL_RESISTANCE) || (uarmf && uarmf->oartifact == ART_KATRIN_S_PARALYSIS) || (uarmf && uarmf->oartifact == ART_SOLVEJG_S_STINKING_SLIPPER) || (uarmu && uarmu->oartifact == ART_BEAM_MULTIPLIER) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uarmc && uarmc->oartifact == ART_ACIDSHOCK_CASTLECRUSHER) || (uwep && uwep->oartifact == ART_PRISMATIC_PROTECTION) || (uimplant && uimplant->oartifact == ART_CORONATION_CULMINATION) || (uarmf && uarmf->oartifact == ART_JOSEFINE_S_EVILNESS) || (uleft && uleft->oartifact == ART_CORGON_S_RING) || (uright && uright->oartifact == ART_CORGON_S_RING) || (uarmf && uarmf->oartifact == ART_LARISSA_S_ANGER) || (uarmf && uarmf->oartifact == ART_JOHANETTA_S_ROUGH_GENTLENE) || (uwep && uwep->oartifact == ART_YVONNE_S_HONOR) || (uarmf && uarmf->oartifact == ART_PRETTY_ROOMMAID) || (uarmf && uarmf->oartifact == ART_YVONNE_S_MODEL_AMBITION) || (uwep && uwep->oartifact == ART_SAXS_BEAUTY) || (uarmf && uarmf->oartifact == ART_BLUEDE) || (uwep && uwep->oartifact == ART_RESISTOMATIC) || (uarmf && uarmf->oartifact == ART_CLICHE_WEAR) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uarmc && uarmc->oartifact == ART_INA_S_SORROW && u.uhunger < 0) || (uarmh && uarmh->oartifact == ART_HAVE_ALL_YOU_NEED) || (uarmf && uarmf->oartifact == ART_CORINA_S_UNFAIR_SCRATCHER) || (uarmh && uarmh->oartifact == ART_MASSIVE_IRON_CROWN_OF_MORG) || (uarmh && uarmh->oartifact == ART_STORMHELM) || (uarmc && uarmc->oartifact == ART_WEB_OF_THE_CHOSEN) || (uwep && uwep->oartifact == ART_STAFF_OF_THE_ARCHMAGI) || (uwep && uwep->oartifact == ART_FIRE_OF_HEAVEN) || (uwep && uwep->oartifact == ART_COLD_SOUL) || u.uprops[STORM_HELM].extrinsic || u.uprops[ELEMENT_RES].extrinsic)

#define Shock_resistance	(((IntShock_resistance && u.nonintrinsicproperty != SHOCK_RES) || (ExtShock_resistance && u.nonextrinsicproperty != SHOCK_RES)) && !hybridragontype(AD_ELEC) && !Role_if(PM_ALTMER) && !NoShock_resistance )
#define StrongShock_resistance	(IntShock_resistance && ExtShock_resistance && Shock_resistance && u.nondoubleproperty != SHOCK_RES)

#define NoShock_resistance (!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SHOCK_RES].intrinsic || RngeAids || (u.impossibleproperty == SHOCK_RES) || (uwep && uwep->oartifact == ART_SHOCKING_THERAPY) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SHOCKING_THERAPY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HPoison_resistance	u.uprops[POISON_RES].intrinsic
#define EPoison_resistance	u.uprops[POISON_RES].extrinsic
#define IntPoison_resistance	(HPoison_resistance || resists_poison(&youmonst) || is_poison_resistant(youmonst.data))
#define ExtPoison_resistance	(EPoison_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == POISON_RES) ) || (uarmh && uarmh->oartifact == ART_SPECTRAL_RESISTANCE) || (uarmu && uarmu->oartifact == ART_GENTLE_SOFT_CLOTHING) || (uarm && uarm->oartifact == ART_REQUIRED_POWER_PLANT_GEAR) || (uarmc && uarmc->oartifact == ART_ACQUIRED_POISON_RESISTANCE) || (uarmc && uarmc->oartifact == ART_PREMIUM_VISCOSITY) || (uarmh && uarmh->oartifact == ART_BIG_BONNET) || (uarmg && uarmg->oartifact == ART_SIGNONS_STEEL_TOTAL) || (uarmf && uarmf->oartifact == ART_MEPHISTO_S_BROGUES) || (uwep && uwep->oartifact == ART_ALSO_MATTE_MASK) || (uwep && uwep->oartifact == ART_PERNICIOUS_GRID) || (uwep && uwep->oartifact == ART_PRISMATIC_PROTECTION) || (uarmh && uarmh->oartifact == ART_NYPHERISBANE) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_RHEA_S_MISSING_EYESIGHT) || (uarmf && uarmf->oartifact == ART_BLUEDE) || (uleft && uleft->oartifact == ART_RELIABLE_TRINSICS) || (uright && uright->oartifact == ART_RELIABLE_TRINSICS) || (uimplant && uimplant->oartifact == ART_CORONATION_CULMINATION) || (uarmu && uarmu->oartifact == ART_KEITH_S_UNDEROOS) || (uwep && uwep->oartifact == ART_SNAKELASH) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_LAUGHING_AT_MIDNIGHT) || (uwep && uwep->oartifact == ART_SAXS_BEAUTY) || (uarmu && uarmu->oartifact == ART_PRISMATIC_SHIRT) || (uarmc && uarmc->oartifact == ART_HEV_SUIT) || (uarmf && uarmf->oartifact == ART_MAILIE_S_CHALLENGE) || (uarmf && uarmf->oartifact == ART_CLICHE_WEAR) || (uarmh && uarmh->oartifact == ART_MASSIVE_IRON_CROWN_OF_MORG) || (uleft && uleft->oartifact == ART_GREEN_COLOR) || (uright && uright->oartifact == ART_GREEN_COLOR) || (uarmh && uarmh->oartifact == ART_TARI_FEFALAS) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uarmf && uarmf->oartifact == ART_LEATHER_PUMPS_OF_HORROR) || (uarmf && uarmf->oartifact == ART_RHEA_S_COMBAT_PUMPS) || (uamul && uamul->oartifact == ART_WARNED_AND_PROTECTED) || (uarmh && uarmh->oartifact == ART_GREEN_STATUS) || (uamul && uamul->oartifact == ART_GOOD_BEE) || (uamul && uamul->oartifact == ART_BUEING) || (uwep && uwep->oartifact == ART_ERU_ILUVATAR_S_BIBLE) || (uarmh && uarmh->oartifact == ART_WAR_MASK_OF_DURIN) || (uwep && uwep->oartifact == ART_SERPENT_S_TOOTH))

#define Poison_resistance	(((IntPoison_resistance && u.nonintrinsicproperty != POISON_RES) || (ExtPoison_resistance && u.nonextrinsicproperty != POISON_RES)) && !NoPoison_resistance && !hybridragontype(AD_DRST) && !Race_if(PM_POISONER) )
#define StrongPoison_resistance	(IntPoison_resistance && ExtPoison_resistance && Poison_resistance && u.nondoubleproperty != POISON_RES)

#define NoPoison_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_POISON_RES].intrinsic || RngeAids || (u.impossibleproperty == POISON_RES) || (uwep && uwep->oartifact == ART_SWORD_OF_BHELEU) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SWORD_OF_BHELEU) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDrain_resistance	u.uprops[DRAIN_RES].intrinsic
#define EDrain_resistance	u.uprops[DRAIN_RES].extrinsic
#define IntDrain_resistance	(HDrain_resistance || resists_drli(&youmonst) || is_drain_resistant(youmonst.data))
#define ExtDrain_resistance	(EDrain_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == DRAIN_RES) ) || (uarmc && uarmc->oartifact == ART_ALL_IN_ONE_ASCENSION_KIT) || (uleft && uleft->oartifact == ART_MAGICAL_SHOCK) || (uright && uright->oartifact == ART_MAGICAL_SHOCK) || (uarmh && uarmh->oartifact == ART_LLLLLLLLLLLLLM) || (uwep && uwep->oartifact == ART_CUBIC_BONE) || (uarmf && uarmf->oartifact == ART_MAILIE_S_CHALLENGE) || (uarmh && uarmh->oartifact == ART_YOU_ARE_ALREADY_DEAD) || (uarmf && uarmf->oartifact == ART_USE_THE_NORMALNESS_TURNS) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uarmh && uarmh->oartifact == ART_LOW_LOCAL_MEMORY) || (uwep && uwep->oartifact == ART_SANDMAN_VOLUME__) || (uwep && uwep->oartifact == ART_ORTHODOX_MANIFEST) || (uwep && uwep->oartifact == ART_UN_DEATH) || (uarmc && uarmc->oartifact == ART_VEIL_OF_LATONA) || (uwep && uwep->oartifact == ART_UNICORN_DRILL) || (uarmc && uarmc->oartifact == ART_VEIL_OF_MINISTRY) || (uwep && uwep->oartifact == ART_LANCE_OF_LONGINUS) || ((moves % 3 == 0) && uarmc && itemhasappearance(uarmc, APP_DEEP_CLOAK)) || (uarmc && itemhasappearance(uarmc, APP_VAMPIRIC_CLOAK) && (moves % 10 == 0) ) )

#define Drain_resistance	(((IntDrain_resistance && u.nonintrinsicproperty != DRAIN_RES) || (ExtDrain_resistance && u.nonextrinsicproperty != DRAIN_RES)) && !NoDrain_resistance)
#define StrongDrain_resistance	(IntDrain_resistance && ExtDrain_resistance && Drain_resistance && u.nondoubleproperty != DRAIN_RES)

#define NoDrain_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DRAIN_RES].intrinsic || RngeAids || (u.impossibleproperty == DRAIN_RES) || (uamul && uamul->oartifact == ART___TH_NAZGUL) || (uamul && uamul->oartifact == ART_NAZGUL_S_REVENGE) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

/* Intrinsics only */
#define HSick_resistance	u.uprops[SICK_RES].intrinsic
#define ESick_resistance	u.uprops[SICK_RES].extrinsic
#define IntSick_resistance	(HSick_resistance || tech_inuse(T_STAT_RESIST) || youmonst.data->mlet == S_FUNGUS || youmonst.data->mlet == S_MUMMY || youmonst.data->mlet == S_ZOMBIE || youmonst.data->mlet == S_WRAITH || youmonst.data->mlet == S_GHOST || youmonst.data->mlet == S_LICH)
#define ExtSick_resistance	(ESick_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SICK_RES)) || (uarm && uarm->oartifact == ART_ANTISEPSIS_COAT) || (uarmc && uarmc->oartifact == ART_INA_S_LAB_COAT) || (uarmc && uarmc->oartifact == ART_INA_S_OVERCOAT) || (uarmf && uarmf->oartifact == ART_DORA_S_SCRATCHY_HEELS) || (uarm && uarm->oartifact == ART_CHECK_YOUR_ESCAPES) || (uleft && uleft->oartifact == ART_RING_OF_P_HUL) || (uright && uright->oartifact == ART_RING_OF_P_HUL) || (uleft && uleft->oartifact == ART_CORGON_S_RING) || (uright && uright->oartifact == ART_CORGON_S_RING) || (uarm && uarm->oartifact == ART_REQUIRED_POWER_PLANT_GEAR) || (uarmc && uarmc->oartifact == ART_HEV_SUIT) || (uarmu && uarmu->oartifact == ART_THERMAL_BATH) || (uarmh && uarmh->oartifact == ART_NYPHERISBANE) || (uarmc && uarmc->oartifact == ART_CLEANLINESS_LAB) || (uwep && uwep->oartifact == ART_SNAKELASH) || (uarmf && uarmf->oartifact == ART_RHEA_S_COMBAT_PUMPS) || (uarmf && uarmf->oartifact == ART_BASE_FOR_SPEED_ASCENSION) || (uamul && uamul->oartifact == ART_ONE_MOMENT_IN_TIME) || (uleft && uleft->oartifact == ART_GOLDENIVY_S_RAGE) || (uright && uright->oartifact == ART_GOLDENIVY_S_RAGE) || (uleft && uleft->oartifact == ART_GOLDENIVY_S_ENGAGEMENT_RIN) || (uright && uright->oartifact == ART_GOLDENIVY_S_ENGAGEMENT_RIN) || (uamul && uamul->oartifact == ART_PRECIOUS_UNOBTAINABLE_PROP) || defends(AD_DISE,uwep) )

#define Sick_resistance		(((IntSick_resistance && u.nonintrinsicproperty != SICK_RES) || (ExtSick_resistance && u.nonextrinsicproperty != SICK_RES)) && !NoSick_resistance)
#define StrongSick_resistance	(IntSick_resistance && ExtSick_resistance && Sick_resistance && u.nondoubleproperty != SICK_RES)

#define NoSick_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SICK_RES].intrinsic || RngeAids || (u.impossibleproperty == SICK_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define Invulnerable		u.uprops[INVULNERABLE].intrinsic    /* [Tom] */

/* Extrinsics only */
#define HAntimagic		u.uprops[ANTIMAGIC].intrinsic
#define EAntimagic		u.uprops[ANTIMAGIC].extrinsic
#define IntAntimagic	(HAntimagic || tech_inuse(T_POWERFUL_AURA) || u.antimagicshell || (uarmh && uarmh->otyp == HELM_OF_ANTI_MAGIC) || Role_if(PM_UNBELIEVER) || (Upolyd && resists_magm(&youmonst)) )
#define ExtAntimagic	(EAntimagic || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == ANTIMAGIC) ) || (uarmc && uarmc->oartifact == ART_ALL_IN_ONE_ASCENSION_KIT) || (uarmh && uarmh->oartifact == ART_YOU_ARE_ALREADY_DEAD) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uleft && uleft->oartifact == ART_CORGON_S_RING) || (uright && uright->oartifact == ART_CORGON_S_RING) || (uarm && uarm->oartifact == ART_WEB_OF_LOLTH) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_SLEX_WANTS_YOU_TO_DIE_A_PA) || (uarm && uarm->oartifact == ART_ROFLCOPTER_WEB) || have_magicresstone() )

#define Antimagic		(((IntAntimagic && u.nonintrinsicproperty != ANTIMAGIC) || (ExtAntimagic && u.nonextrinsicproperty != ANTIMAGIC)) && !NoAntimagic_resistance && !hybridragontype(AD_MAGM) && !Race_if(PM_UNMAGIC_FISH))
#define StrongAntimagic	(IntAntimagic && ExtAntimagic && Antimagic && u.nondoubleproperty != ANTIMAGIC)

#define NoAntimagic_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_ANTIMAGIC].intrinsic || RngeAids || (u.impossibleproperty == ANTIMAGIC) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HAcid_resistance	u.uprops[ACID_RES].intrinsic
#define EAcid_resistance	u.uprops[ACID_RES].extrinsic
#define IntAcid_resistance	(HAcid_resistance || resists_acid(&youmonst) || is_acid_resistant(youmonst.data))
#define ExtAcid_resistance	(EAcid_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == ACID_RES) ) || (uimplant && uimplant->oartifact == ART_HENRIETTA_S_TENACIOUSNESS) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_LAUGHING_AT_MIDNIGHT) || (uimplant && uimplant->oartifact == ART_THEY_RE_ALL_YELLOW) || (uwep && uwep->oartifact == ART_ACTA_METALLURGICA_VOL___) || (uleft && uleft->oartifact == ART_BILE_PATCH) || (uright && uright->oartifact == ART_BILE_PATCH) || (uarmc && uarmc->oartifact == ART_ACIDSHOCK_CASTLECRUSHER) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uwep && uwep->oartifact == ART_RESISTOMATIC) || (uwep && uwep->otyp == CHEMISTRY_SPACE_AXE) || (uarmh && uarmh->oartifact == ART_MASSIVE_IRON_CROWN_OF_MORG) || (uarmh && uarmh->oartifact == ART_WAR_MASK_OF_DURIN) || (uarmh && uarmh->oartifact == ART_UNIMPORTANT_ELEMENTS))

#define Acid_resistance		(((IntAcid_resistance && u.nonintrinsicproperty != ACID_RES) || (ExtAcid_resistance && u.nonextrinsicproperty != ACID_RES)) && !hybridragontype(AD_ACID) && !NoAcid_resistance)
#define StrongAcid_resistance	(IntAcid_resistance && ExtAcid_resistance && Acid_resistance && u.nondoubleproperty != ACID_RES)

#define NoAcid_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_ACID_RES].intrinsic || RngeAids || (u.impossibleproperty == ACID_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HStone_resistance	u.uprops[STONE_RES].intrinsic
#define EStone_resistance	u.uprops[STONE_RES].extrinsic
#define IntStone_resistance	(HStone_resistance || resists_ston(&youmonst) || is_ston_resistant(youmonst.data) || Role_if(PM_ROCKER))
#define ExtStone_resistance	(EStone_resistance || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == STONE_RES) ) || (uarmh && uarmh->oartifact == ART_STONE_EROSION) || (uarmg && uarmg->oartifact == ART_SIGNONS_STEEL_TOTAL) || (uwep && uwep->oartifact == ART_GILRAEN_SEREGON) || (uarmf && uarmf->oartifact == ART_ELENETTES) || (uarmf && uarmf->oartifact == ART_NATALIA_S_PUNISHER) || (uarmg && uarmg->oartifact == ART_COCKUETRY) || (uarmg && uarmg->oartifact == ART_SPECTRATOR && (moves % 5 == 0) ) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uwep && uwep->oartifact == ART_HERITAGE_DIGGER) || (uarms && uarms->oartifact == ART_AEGIS) || (uarmf && uarmf->oartifact == ART_CORINA_S_UNFAIR_SCRATCHER) || (uwep && uwep->oartifact == ART_STAHNGNIR_S_GIANT_CRUSHER) || (uarmf && uarmf->oartifact == ART_PRETTY_ROOMMAID) || (uarmf && uarmf->oartifact == ART_NASTIST) || (uarmh && uarmh->oartifact == ART_JESTES_TAKA_KURWA) || (uarmf && uarmf->oartifact == ART_YET_ANOTHER_STUPID_IDEA) || (uwep && uwep->oartifact == ART_HELIOKOPIS_S_WIZARDING_AID) || (uamul && uamul->oartifact == ART_PRECIOUS_UNOBTAINABLE_PROP) || (uarmf && uarmf->oartifact == ART_STONEWALL_CHECKERBOARD_DIS) || (uamul && uamul->oartifact == ART_ONE_MOMENT_IN_TIME) || (uwep && uwep->oartifact == ART_SWORD_OF_BHELEU) || (uamul && uamul->oartifact == ART_BALLSY_BASTARD) || (uarmc && uarmc->oartifact == ART_INA_S_SORROW && u.uhunger < 0) || (uarmh && uarmh->oartifact == ART_UNIMPORTANT_ELEMENTS))

#define Stone_resistance	(((IntStone_resistance && u.nonintrinsicproperty != STONE_RES) || (ExtStone_resistance && u.nonextrinsicproperty != STONE_RES)) && !NoStone_resistance)
#define StrongStone_resistance	(IntStone_resistance && ExtStone_resistance && Stone_resistance && u.nondoubleproperty != STONE_RES)

#define NoStone_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_STONE_RES].intrinsic || RngeAids || (u.impossibleproperty == STONE_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HFear_resistance	u.uprops[FEAR_RES].intrinsic
#define EFear_resistance	u.uprops[FEAR_RES].extrinsic
#define IntFear_resistance	(HFear_resistance || Race_if(PM_EROSATOR) || tech_inuse(T_STAT_RESIST))
#define ExtFear_resistance	(EFear_resistance || (uarm && uarm->oartifact == ART_NICE_CYAN_COLOR) || (uarm && uarm->oartifact == ART_OVERRATED_FACE_PROTECTION) || (uwep && uwep->oartifact == ART_YVONNE_S_HONOR) || (uarmc && uarmc->oartifact == ART_TERRIFYING_LOSS) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == FEAR_RES) ) || (uarmf && uarmf->oartifact == ART_GRANDPA_S_BROGUES) || (uarmf && uarmf->oartifact == ART_PARANOIA_STRIDE) || (uwep && uwep->oartifact == ART_USELESSNESS_OF_PLENTY) )

#define Fear_resistance		(((IntFear_resistance && u.nonintrinsicproperty != FEAR_RES) || (ExtFear_resistance && u.nonextrinsicproperty != FEAR_RES)) && !NoFear_resistance)
#define StrongFear_resistance	(IntFear_resistance && ExtFear_resistance && Fear_resistance && u.nondoubleproperty != FEAR_RES)

#define NoFear_resistance	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FEAR_RES].intrinsic || RngeAids || (u.impossibleproperty == FEAR_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))


/*** Troubles ***/
/* Pseudo-property */
#define Punished		(uball)

/* Those implemented solely as timeouts (we use just intrinsic) */
#define HStun			u.uprops[STUNNED].intrinsic
#define EStun			u.uprops[STUNNED].extrinsic
#define Stunned			(HStun || EStun || is_bubble(u.ux, u.uy) || (uarms && uarms->oartifact == ART_VENOMAT) || (uwep && uwep->oartifact == ART_LANCE_OF_LONGINUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_SCHWANZUS_LANGUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SCHWANZUS_LANGUS) || (uarm && uarm->oartifact == ART_ROBE_OF_THE_ARCHMAGI) || (uarm && uarm->oartifact == ART_SHIVANHUNTER_S_UNUSED_PRIZ) || HeavyStunned || ((u.umonnum == PM_STALKER || youmonst.data->mlet == S_BAT) && !Race_if(PM_TRANSFORMER) ) || Race_if(PM_TUMBLRER) )
		/* Note: birds will also be stunned */
#define HeavyStunned		u.uprops[HEAVY_STUNNED].intrinsic

#define HConfusion		u.uprops[CONFUSION].intrinsic
#define EConfusion		u.uprops[CONFUSION].extrinsic
#define Confusion		(u.boomshined || HConfusion || EConfusion || HeavyConfusion || In_illusorycastle(&u.uz) || (uamul && uamul->oartifact == ART_CONFUSTICATOR) || (uarmh && uarmh->oartifact == ART_NEVER_CLEAN) || (uwep && uwep->oartifact == ART_EAMANE_LUINWE) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_EAMANE_LUINWE) || (uarmc && uarmc->oartifact == ART_VEIL_OF_LATONA) || (uarmh && uarmh->oartifact == ART_UNIMPLEMENTED_FEATURE) || (uwep && uwep->oartifact == ART_FEANARO_SINGOLLO) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_FEANARO_SINGOLLO) || (uarms && uarms->oartifact == ART_CCC_CCC_CCCCCCC) || (uarmc && uarmc->oartifact == ART_VEIL_OF_MINISTRY) || (uwep && uwep->oartifact == ART_LANCE_OF_LONGINUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_SCHWANZUS_LANGUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SCHWANZUS_LANGUS) || u.uprops[SENSORY_DEPRIVATION].extrinsic || Race_if(PM_ADDICT))
#define HeavyConfusion		u.uprops[HEAVY_CONFUSION].intrinsic

#define HNumbed		u.uprops[NUMBED].intrinsic
#define ENumbed		u.uprops[NUMBED].extrinsic
#define Numbed		(HNumbed || ENumbed || Race_if(PM_IRRITATOR) || (uarms && uarms->oartifact == ART_NUMBED_CAN_T_DO) || HeavyNumbed)
#define HeavyNumbed		u.uprops[HEAVY_NUMBED].intrinsic

#define HFeared		u.uprops[FEARED].intrinsic
#define EFeared		u.uprops[FEARED].extrinsic
#define Feared		(flags.dudley || ((HFeared || EFeared || HeavyFeared) && !Fear_resistance) )
#define HeavyFeared		u.uprops[HEAVY_FEARED].intrinsic

#define HFrozen		u.uprops[FROZEN].intrinsic
#define EFrozen		u.uprops[FROZEN].extrinsic
#define Frozen		(HFrozen || EFrozen || Race_if(PM_HYPOTHERMIC) || (uarmc && uarmc->oartifact == ART_BROKEN_WINGS) || (uarmc && uarmc->oartifact == ART_GROUNDBUMMER) || (uimplant && uimplant->oartifact == ART_MIGHTY_MOLASS) || (uarms && uarms->oartifact == ART_TYPE_OF_ICE_BLOCK_HATES_YO) || (uwep && uwep->oartifact == ART_LANCE_OF_LONGINUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_SCHWANZUS_LANGUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SCHWANZUS_LANGUS) || HeavyFrozen)
#define HeavyFrozen		u.uprops[HEAVY_FROZEN].intrinsic

#define HBurned		u.uprops[BURNED].intrinsic
#define EBurned		u.uprops[BURNED].extrinsic
#define Burned		(HBurned || EBurned || HeavyBurned || Race_if(PM_BURNINATOR) || (uimplant && uimplant->oartifact == ART_BURN_BABY_BURN) || (uarms && uarms->oartifact == ART_BURNING_DISK) )
#define HeavyBurned		u.uprops[HEAVY_BURNED].intrinsic

#define HDimmed		u.uprops[DIMMED].intrinsic
#define EDimmed		u.uprops[DIMMED].extrinsic
#define Dimmed		(HDimmed || EDimmed || HeavyDimmed || Race_if(PM_INKA) || (uwep && uwep->otyp == TRAFFIC_LIGHT) )
#define HeavyDimmed		u.uprops[HEAVY_DIMMED].intrinsic

#define Blinded			u.uprops[BLINDED].intrinsic
#define EBlinded			u.uprops[BLINDED].extrinsic
#define Blindfolded		(ublindf && ublindf->otyp != LENSES && ublindf->otyp != RADIOGLASSES && ublindf->otyp != BOSS_VISOR && ublindf->otyp != CONDOME && ublindf->otyp != SOFT_CHASTITY_BELT)
		/* ...means blind because of a cover */
#define Blind	((Blinded || EBlinded || Blindfolded || HeavyBlind || u.uprops[SENSORY_DEPRIVATION].extrinsic || flags.blindfox || (!haseyes(youmonst.data) && !Race_if(PM_TRANSFORMER) ) ) && \
		 !(ublindf && ublindf->oartifact == ART_EYES_OF_THE_OVERWORLD && !flags.blindfox ) && !(Race_if(PM_PLAYER_DOLGSMAN) && !flags.blindfox) && !(uwep && uwep->oartifact == ART_DUMBOAK_S_HEW && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_DIMOAK_S_HEW && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_SWORD_OF_ERATHAOL && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_SABER_OF_SABAOTH && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_SWORD_OF_ONOEL && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_GLAIVE_OF_SHAMSIEL && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_LANCE_OF_URIEL && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_HAMMER_OF_BARQUIEL && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_SAMENESS_OF_CHRIS && !flags.blindfox ) && !(uwep && uwep->oartifact == ART_MUB_PUH_MUB_DIT_DIT && !flags.blindfox ) && !(tech_inuse(T_STAT_RESIST) && !flags.blindfox ) && !(uarmh && uarmh->oartifact == ART_BLINDING_FOG && !flags.blindfox ) && !(uarmh && uarmh->oartifact == ART_DARKSIGHT_HELM && !flags.blindfox ) && !(uarms && uarms->oartifact == ART_SHADOWDISK && !flags.blindfox ) )
		/* ...the Eyes operate even when you really are blind
		    or don't have any eyes */
/* added possibility of playing the entire game blind --Amy*/
#define HeavyBlind		u.uprops[HEAVY_BLIND].intrinsic

#define PlayerBleeds			u.uprops[PLAYERBLEEDING].intrinsic
#define Sick			u.uprops[SICK].intrinsic
#define Stoned			u.uprops[STONED].intrinsic
#define Strangled		u.uprops[STRANGLED].intrinsic

#define Prem_death		(u.uprops[PREMDEATH].intrinsic || u.uprops[PREMDEATH].extrinsic)
#define HPrem_death	u.uprops[PREMDEATH].intrinsic
#define EPrem_death	(u.uprops[PREMDEATH].extrinsic || (uarmc && uarmc->oartifact == ART_KYS_YOURSELF) )

#define Vomiting		u.uprops[VOMITING].intrinsic
#define Glib			u.uprops[GLIB].intrinsic
#define EGlib			u.uprops[GLIB].extrinsic
#define IsGlib			(Glib || EGlib || (uarmg && uarmg->oartifact == ART_TANKS_A_LOT) || (uwep && uwep->oartifact == ART_FADED_USELESSNESS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_FADED_USELESSNESS) )
#define Slimed			u.uprops[SLIMED].intrinsic	/* [Tom] */

/* nasty traps with timeouts --Amy */
#define SpeedBug		u.uprops[SPEED_BUG].intrinsic
#define MenuBug		u.uprops[MENU_LOST].intrinsic
#define RMBLoss		u.uprops[RMB_LOST].intrinsic
#define DisplayLoss	u.uprops[DISPLAY_LOST].intrinsic
#define SpellLoss		u.uprops[SPELLS_LOST].intrinsic
#define YellowSpells		u.uprops[YELLOW_SPELLS].intrinsic
#define AutoDestruct		u.uprops[AUTO_DESTRUCT].intrinsic
#define MemoryLoss		u.uprops[MEMORY_LOST].intrinsic
#define InventoryLoss		u.uprops[INVENTORY_LOST].intrinsic
#define BlackNgWalls		u.uprops[BLACK_NG_WALLS].intrinsic
#define Superscroller		u.uprops[SUPERSCROLLER_ACTIVE].intrinsic

#define FreeHandLoss		u.uprops[FREE_HAND_LOST].intrinsic
#define Unidentify		u.uprops[UNIDENTIFY].intrinsic
#define Thirst		u.uprops[THIRST].intrinsic
#define LuckLoss		u.uprops[LUCK_LOSS].intrinsic
#define ShadesOfGrey 		u.uprops[SHADES_OF_GREY].intrinsic
#define IncreasedGravity		u.uprops[INCREASED_GRAVITY].intrinsic
#define FaintActive		u.uprops[FAINT_ACTIVE].intrinsic
#define Itemcursing		u.uprops[ITEMCURSING].intrinsic
#define DifficultyIncreased		u.uprops[DIFFICULTY_INCREASED].intrinsic
#define Deafness		u.uprops[DEAFNESS].intrinsic
#define CasterProblem		u.uprops[CASTER_PROBLEM].intrinsic
#define WeaknessProblem		u.uprops[WEAKNESS_PROBLEM].intrinsic
#define RotThirteen		u.uprops[ROT_THIRTEEN].intrinsic
#define BishopGridbug		u.uprops[BISHOP_GRIDBUG].intrinsic
#define ConfusionProblem		u.uprops[CONFUSION_PROBLEM].intrinsic
#define NoDropProblem		u.uprops[DROP_BUG].intrinsic
#define DSTWProblem		u.uprops[DSTW_BUG].intrinsic
#define StatusTrapProblem		u.uprops[STATUS_FAILURE].intrinsic
#define AlignmentProblem		u.uprops[ALIGNMENT_FAILURE].intrinsic
#define StairsProblem		u.uprops[STAIRSTRAP].intrinsic
#define UninformationProblem		u.uprops[UNINFORMATION].intrinsic

#define IntrinsicLossProblem		u.uprops[INTRINSIC_LOSS].intrinsic
#define BloodLossProblem		u.uprops[BLOOD_LOSS].intrinsic
#define BadEffectProblem		u.uprops[BAD_EFFECTS].intrinsic
#define TrapCreationProblem		u.uprops[AUTOMATIC_TRAP_CREATION].intrinsic
#define AutomaticVulnerabilitiy		u.uprops[REPEATING_VULNERABILITY].intrinsic
#define TeleportingItems		u.uprops[TELEPORTING_ITEMS].intrinsic

#define NastinessProblem		u.uprops[NASTINESS_EFFECTS].intrinsic

#define RecurringAmnesia		u.uprops[RECURRING_AMNESIA].intrinsic
#define BigscriptEffect		u.uprops[BIGSCRIPT].intrinsic
#define BankTrapEffect		u.uprops[BANKBUG].intrinsic
#define MapTrapEffect		u.uprops[MAPBUG].intrinsic
#define TechTrapEffect		u.uprops[TECHBUG].intrinsic
#define RecurringDisenchant		u.uprops[RECURRING_DISENCHANT].intrinsic
#define verisiertEffect		u.uprops[VERISIERTEFFECT].intrinsic
#define ChaosTerrain		u.uprops[CHAOS_TERRAIN].intrinsic
#define Muteness		u.uprops[MUTENESS].intrinsic
#define EngravingDoesntWork		u.uprops[ENGRAVINGBUG].intrinsic
#define MagicDeviceEffect		u.uprops[MAGIC_DEVICE_BUG].intrinsic
#define BookTrapEffect		u.uprops[BOOKBUG].intrinsic
#define LevelTrapEffect		u.uprops[LEVELBUG].intrinsic
#define QuizTrapEffect		u.uprops[QUIZZES].intrinsic

#define CaptchaProblem		u.uprops[CAPTCHA].intrinsic
#define FarlookProblem		u.uprops[FARLOOK_BUG].intrinsic
#define RespawnProblem		u.uprops[RESPAWN_BUG].intrinsic
#define MCReduction		u.uprops[MC_REDUCTION].intrinsic

#define NoStaircase		u.uprops[NO_STAIRCASE].intrinsic

#define FastMetabolismEffect		u.uprops[FAST_METABOLISM].intrinsic
#define NoReturnEffect		u.uprops[NORETURN].intrinsic
#define AlwaysEgotypeMonsters		u.uprops[ALWAYS_EGOTYPES].intrinsic
#define TimeGoesByFaster		u.uprops[FAST_FORWARD].intrinsic
#define FoodIsAlwaysRotten		u.uprops[FOOD_IS_ROTTEN].intrinsic
#define AllSkillsUnskilled		u.uprops[SKILL_DEACTIVATED].intrinsic
#define AllStatsAreLower		u.uprops[STATS_LOWERED].intrinsic
#define PlayerCannotTrainSkills		u.uprops[TRAINING_DEACTIVATED].intrinsic
#define PlayerCannotExerciseStats		u.uprops[EXERCISE_DEACTIVATED].intrinsic

#define TurnLimitation		u.uprops[TURNLIMITATION].intrinsic
#define WeakSight		u.uprops[WEAKSIGHT].intrinsic
#define RandomMessages		u.uprops[RANDOM_MESSAGES].intrinsic

#define Desecration		u.uprops[DESECRATION].intrinsic
#define StarvationEffect		u.uprops[STARVATION_EFFECT].intrinsic
#define NoDropsEffect		u.uprops[NO_DROPS_EFFECT].intrinsic
#define LowEffects		u.uprops[LOW_EFFECTS].intrinsic
#define InvisibleTrapsEffect		u.uprops[INVIS_TRAPS_EFFECT].intrinsic
#define GhostWorld		u.uprops[GHOST_WORLD].intrinsic
#define Dehydration		u.uprops[DEHYDRATION].intrinsic
#define HateTrapEffect		u.uprops[HATE_TRAP_EFFECT].intrinsic
#define TotterTrapEffect		u.uprops[TOTTER_EFFECT].intrinsic
#define Nonintrinsics		u.uprops[NONINTRINSIC_EFFECT].intrinsic
#define Dropcurses		u.uprops[DROPCURSES_EFFECT].intrinsic
#define Nakedness		u.uprops[NAKEDNESS].intrinsic
#define Antileveling		u.uprops[ANTILEVELING].intrinsic
#define ItemStealingEffect		u.uprops[ITEM_STEALING_EFFECT].intrinsic
#define Rebellions		u.uprops[REBELLION_EFFECT].intrinsic
#define CrapEffect		u.uprops[CRAP_EFFECT].intrinsic
#define ProjectilesMisfire		u.uprops[PROJECTILES_MISFIRE].intrinsic
#define WallTrapping		u.uprops[WALL_TRAP_EFFECT].intrinsic

#define DisconnectedStairs		u.uprops[DISCONNECTED_STAIRS].intrinsic
#define InterfaceScrewed		u.uprops[INTERFACE_SCREW].intrinsic
#define Bossfights		u.uprops[BOSSFIGHT].intrinsic
#define EntireLevelMode		u.uprops[ENTIRE_LEVEL].intrinsic
#define BonesLevelChange		u.uprops[BONES_CHANGE].intrinsic
#define AutocursingEquipment		u.uprops[AUTOCURSE_EQUIP].intrinsic
#define HighlevelStatus		u.uprops[HIGHLEVEL_STATUS].intrinsic
#define SpellForgetting		u.uprops[SPELL_FORGETTING].intrinsic
#define SoundEffectBug		u.uprops[SOUND_EFFECT_BUG].intrinsic
#define TimerunBug		u.uprops[TIMERUN_BUG].intrinsic

#define SanityTrebleEffect		u.uprops[SANITY_TREBLE_EFFECT].intrinsic
#define StatDecreaseBug		u.uprops[STAT_DECREASE_BUG].intrinsic
#define SimeoutBug		u.uprops[SIMEOUT_BUG].intrinsic

#define BadPartBug	u.uprops[BAD_PARTS].intrinsic
#define CompletelyBadPartBug	u.uprops[COMPLETELY_BAD_PARTS].intrinsic
#define EvilVariantActive	u.uprops[EVIL_VARIANT_ACTIVE].intrinsic

#define OrangeSpells		u.uprops[ORANGE_SPELLS].intrinsic
#define VioletSpells		u.uprops[VIOLET_SPELLS].intrinsic
#define LongingEffect		u.uprops[LONGING_EFFECT].intrinsic
#define CursedParts		u.uprops[CURSED_PARTS].intrinsic
#define Quaversal		u.uprops[QUAVERSAL].intrinsic
#define AppearanceShuffling		u.uprops[APPEARANCE_SHUFFLING].intrinsic
#define BrownSpells		u.uprops[BROWN_SPELLS].intrinsic
#define Choicelessness		u.uprops[CHOICELESSNESS].intrinsic
#define Goldspells		u.uprops[GOLDSPELLS].intrinsic
#define Deprovement		u.uprops[DEPROVEMENT].intrinsic
#define InitializationFail		u.uprops[INITIALIZATION_FAIL].intrinsic
#define GushlushEffect		u.uprops[GUSHLUSH].intrinsic
#define SoiltypeEffect		u.uprops[SOILTYPE].intrinsic
#define DangerousTerrains		u.uprops[DANGEROUS_TERRAINS].intrinsic
#define FalloutEffect		u.uprops[FALLOUT_EFFECT].intrinsic
#define MojibakeEffect		u.uprops[MOJIBAKE].intrinsic
#define GravationEffect		u.uprops[GRAVATION].intrinsic
#define UncalledEffect		u.uprops[UNCALLED_EFFECT].intrinsic
#define ExplodingDiceEffect		u.uprops[EXPLODING_DICE].intrinsic
#define PermacurseEffect		u.uprops[PERMACURSE_EFFECT].intrinsic
#define ShroudedIdentity		u.uprops[SHROUDED_IDENTITY].intrinsic
#define FeelerGauges		u.uprops[FEELER_GAUGES].intrinsic
#define LongScrewup		u.uprops[LONG_SCREWUP].intrinsic
#define WingYellowChange		u.uprops[WING_YELLOW_GLYPHS].intrinsic
#define LifeSavingBug		u.uprops[LIFE_SAVING_BUG].intrinsic
#define CurseuseEffect		u.uprops[CURSEUSE_EFFECT].intrinsic
#define CutNutritionEffect		u.uprops[CUT_NUTRITION].intrinsic
#define SkillLossEffect		u.uprops[SKILL_LOSS_EFFECT].intrinsic
#define AutopilotEffect		u.uprops[AUTOPILOT_EFFECT].intrinsic
#define MysteriousForceActive		u.uprops[MYSTERIOUS_FORCE_EFFECT].intrinsic
#define MonsterGlyphChange		u.uprops[MONSTER_GLYPH_BUG].intrinsic
#define ChangingDirectives		u.uprops[CHANGING_DIRECTIVES].intrinsic
#define ContainerKaboom		u.uprops[CONTAINER_KABOOM].intrinsic
#define StealDegrading		u.uprops[STEAL_DEGRADING].intrinsic
#define LeftInventoryBug		u.uprops[LEFT_INVENTORY].intrinsic
#define FluctuatingSpeed		u.uprops[FLUCTUATING_SPEED].intrinsic
#define TarmuStrokingNora		u.uprops[TARMU_STROKING_NORA].intrinsic
#define FailureEffects		u.uprops[FAILURE_EFFECTS].intrinsic
#define BrightCyanSpells		u.uprops[BRIGHT_CYAN_SPELLS].intrinsic
#define FrequentationSpawns		u.uprops[FREQUENTATION_SPAWNS].intrinsic
#define PetAIScrewed		u.uprops[PET_AI_SCREWED].intrinsic
#define SatanEffect		u.uprops[SATAN_EFFECT].intrinsic
#define RememberanceEffect		u.uprops[REMEMBERANCE_EFFECT].intrinsic
#define PokelieEffect		u.uprops[POKELIE_EFFECT].intrinsic
#define AlwaysAutopickup		u.uprops[AUTOPICKUP_ALWAYS].intrinsic
#define DywypiProblem		u.uprops[DYWYPI_PROBLEM].intrinsic
#define SilverSpells		u.uprops[SILVER_SPELLS].intrinsic
#define MetalSpells		u.uprops[METAL_SPELLS].intrinsic
#define PlatinumSpells		u.uprops[PLATINUM_SPELLS].intrinsic
#define ManlerEffect		u.uprops[MANLER_EFFECT].intrinsic
#define DoorningEffect		u.uprops[DOORNING_EFFECT].intrinsic
#define NownsibleEffect		u.uprops[NOWNSIBLE_EFFECT].intrinsic
#define ElmStreetEffect		u.uprops[ELM_STREET_EFFECT].intrinsic
#define MonnoiseEffect		u.uprops[MONNOISE_EFFECT].intrinsic
#define RangCallEffect		u.uprops[RANG_CALL_EFFECT].intrinsic
#define RecurringSpellLoss		u.uprops[RECURRING_SPELL_LOSS].intrinsic
#define AntitrainingEffect		u.uprops[ANTI_TRAINING_EFFECT].intrinsic
#define TechoutBug		u.uprops[TECHOUT_BUG].intrinsic
#define StatDecay		u.uprops[STAT_DECAY].intrinsic
#define Movemork		u.uprops[MOVEMORKING].intrinsic

#define LootcutBug		u.uprops[LOOTCUT_BUG].intrinsic
#define MonsterSpeedBug		u.uprops[MONSTER_SPEED_BUG].intrinsic
#define ScalingBug		u.uprops[SCALING_BUG].intrinsic
#define EnmityBug			u.uprops[ENMITY_BUG].intrinsic
#define WhiteSpells		u.uprops[WHITE_SPELLS].intrinsic
#define CompleteGraySpells	u.uprops[COMPLETE_GRAY_SPELLS].intrinsic
#define QuasarVision		u.uprops[QUASAR_BUG].intrinsic
#define MommaBugEffect		u.uprops[MOMMA_BUG].intrinsic
#define HorrorBugEffect		u.uprops[HORROR_BUG].intrinsic
#define ArtificerBug		u.uprops[ARTIFICER_BUG].intrinsic
#define WereformBug		u.uprops[WEREFORM_BUG].intrinsic
#define NonprayerBug		u.uprops[NON_PRAYER_BUG].intrinsic
#define EvilPatchEffect		u.uprops[EVIL_PATCH_EFFECT].intrinsic
#define HardModeEffect		u.uprops[HARD_MODE_EFFECT].intrinsic
#define SecretAttackBug		u.uprops[SECRET_ATTACK_BUG].intrinsic
#define EaterBugEffect		u.uprops[EATER_BUG].intrinsic
#define CovetousnessBug		u.uprops[COVETOUSNESS_BUG].intrinsic
#define NotSeenBug		u.uprops[NOT_SEEN_BUG].intrinsic
#define DarkModeBug		u.uprops[DARK_MODE_BUG].intrinsic
#define AntisearchEffect	u.uprops[ANTISEARCH_EFFECT].intrinsic
#define HomicideEffect		u.uprops[HOMICIDE_EFFECT].intrinsic
#define NastynationBug		u.uprops[NASTY_NATION_BUG].intrinsic
#define WakeupCallBug		u.uprops[WAKEUP_CALL_BUG].intrinsic
#define GrayoutBug		u.uprops[GRAYOUT_BUG].intrinsic
#define GrayCenterBug		u.uprops[GRAY_CENTER_BUG].intrinsic
#define CheckerboardBug		u.uprops[CHECKERBOARD_BUG].intrinsic
#define ClockwiseSpinBug	u.uprops[CLOCKWISE_SPIN_BUG].intrinsic
#define CounterclockwiseSpin	u.uprops[COUNTERCLOCKWISE_SPIN_BUG].intrinsic
#define LagBugEffect		u.uprops[LAG_BUG].intrinsic
#define BlesscurseEffect	u.uprops[BLESSCURSE_EFFECT].intrinsic
#define DeLightBug		u.uprops[DE_LIGHT_BUG].intrinsic
#define DischargeBug		u.uprops[DISCHARGE_BUG].intrinsic
#define TrashingBugEffect	u.uprops[TRASHING_EFFECT].intrinsic
#define FilteringBug		u.uprops[FILTERING_BUG].intrinsic
#define DeformattingBug		u.uprops[DEFORMATTING_BUG].intrinsic
#define FlickerStripBug		u.uprops[FLICKER_STRIP_BUG].intrinsic
#define UndressingEffect	u.uprops[UNDRESSING_EFFECT].intrinsic
#define Hyperbluewalls		u.uprops[HYPERBLUEWALL_BUG].intrinsic
#define NoliteBug			u.uprops[NOLITE_BUG].intrinsic
#define ParanoiaBugEffect	u.uprops[PARANOIA_BUG].intrinsic
#define FleecescriptBug		u.uprops[FLEECESCRIPT_BUG].intrinsic
#define InterruptEffect		u.uprops[INTERRUPT_EFFECT].intrinsic
#define DustbinBug		u.uprops[DUSTBIN_BUG].intrinsic
#define ManaBatteryBug		u.uprops[MANA_BATTERY_BUG].intrinsic
#define Monsterfingers		u.uprops[MONSTERFINGERS_EFFECT].intrinsic
#define MiscastBug		u.uprops[MISCAST_BUG].intrinsic
#define MessageSuppression	u.uprops[MESSAGE_SUPPRESSION_BUG].intrinsic
#define StuckAnnouncement	u.uprops[STUCK_ANNOUNCEMENT_BUG].intrinsic
#define BloodthirstyEffect	u.uprops[BLOODTHIRSTY_EFFECT].intrinsic
#define MaximumDamageBug	u.uprops[MAXIMUM_DAMAGE_BUG].intrinsic
#define LatencyBugEffect	u.uprops[LATENCY_BUG].intrinsic
#define StarlitBug		u.uprops[STARLIT_BUG].intrinsic
#define KnowledgeBug		u.uprops[KNOWLEDGE_BUG].intrinsic
#define HighscoreBug		u.uprops[HIGHSCORE_BUG].intrinsic
#define PinkSpells		u.uprops[PINK_SPELLS].intrinsic
#define GreenSpells		u.uprops[GREEN_SPELLS].intrinsic
#define EvencoreEffect		u.uprops[EVC_EFFECT].intrinsic
#define UnderlayerBug		u.uprops[UNDERLAYER_BUG].intrinsic
#define DamageMeterBug		u.uprops[DAMAGE_METER_BUG].intrinsic
#define ArbitraryWeightBug	u.uprops[ARBITRARY_WEIGHT_BUG].intrinsic
#define FuckedInfoBug		u.uprops[FUCKED_INFO_BUG].intrinsic
#define BlackSpells		u.uprops[BLACK_SPELLS].intrinsic
#define CyanSpells		u.uprops[CYAN_SPELLS].intrinsic
#define HeapEffectBug		u.uprops[HEAP_EFFECT].intrinsic
#define BlueSpells		u.uprops[BLUE_SPELLS].intrinsic
#define TronEffect		u.uprops[TRON_EFFECT].intrinsic
#define RedSpells			u.uprops[RED_SPELLS].intrinsic
#define TooHeavyEffect		u.uprops[TOO_HEAVY_EFFECT].intrinsic
#define ElongationBug		u.uprops[ELONGATION_BUG].intrinsic
#define WrapoverEffect		u.uprops[WRAPOVER_EFFECT].intrinsic
#define DestructionEffect	u.uprops[DESTRUCTION_EFFECT].intrinsic
#define MeleePrefixBug		u.uprops[MELEE_PREFIX_BUG].intrinsic
#define AutomoreBug		u.uprops[AUTOMORE_BUG].intrinsic
#define UnfairAttackBug		u.uprops[UNFAIR_ATTACK_BUG].intrinsic

#define TimeStopped		u.uprops[TIME_STOPPED].intrinsic

#define FemaleTrapFemmy	u.uprops[FEMTRAP_FEMMY].intrinsic
#define FemaleTrapMadeleine	u.uprops[FEMTRAP_MADELEINE].intrinsic
#define FemaleTrapMarlena	u.uprops[FEMTRAP_MARLENA].intrinsic
#define FemaleTrapAnastasia	u.uprops[FEMTRAP_ANASTASIA].intrinsic
#define FemaleTrapJessica	u.uprops[FEMTRAP_JESSICA].intrinsic
#define FemaleTrapSolvejg	u.uprops[FEMTRAP_SOLVEJG].intrinsic
#define FemaleTrapWendy	u.uprops[FEMTRAP_WENDY].intrinsic
#define FemaleTrapKatharina	u.uprops[FEMTRAP_KATHARINA].intrinsic
#define FemaleTrapElena	u.uprops[FEMTRAP_ELENA].intrinsic
#define FemaleTrapThai	u.uprops[FEMTRAP_THAI].intrinsic
#define FemaleTrapElif	u.uprops[FEMTRAP_ELIF].intrinsic
#define FemaleTrapNadja	u.uprops[FEMTRAP_NADJA].intrinsic
#define FemaleTrapSandra	u.uprops[FEMTRAP_SANDRA].intrinsic
#define FemaleTrapNatalje	u.uprops[FEMTRAP_NATALJE].intrinsic
#define FemaleTrapJeanetta	u.uprops[FEMTRAP_JEANETTA].intrinsic
#define FemaleTrapYvonne	u.uprops[FEMTRAP_YVONNE].intrinsic
#define FemaleTrapMaurah	u.uprops[FEMTRAP_MAURAH].intrinsic
#define FemaleTrapMeltem	u.uprops[FEMTRAP_MELTEM].intrinsic
#define FemaleTrapSarah	u.uprops[FEMTRAP_SARAH].intrinsic
#define FemaleTrapClaudia	u.uprops[FEMTRAP_CLAUDIA].intrinsic
#define FemaleTrapLudgera	u.uprops[FEMTRAP_LUDGERA].intrinsic
#define FemaleTrapKati	u.uprops[FEMTRAP_KATI].intrinsic

#define FemtrapActiveFemmy	(FemaleTrapFemmy || u.uprops[FEMTRAP_FEMMY].extrinsic || have_femtrapfemmy())
#define FemtrapActiveMadeleine	(FemaleTrapMadeleine || u.uprops[FEMTRAP_MADELEINE].extrinsic || have_femtrapmadeleine())
#define FemtrapActiveMarlena	(FemaleTrapMarlena || u.uprops[FEMTRAP_MARLENA].extrinsic || have_femtrapmarlena())
#define FemtrapActiveAnastasia	(FemaleTrapAnastasia || u.uprops[FEMTRAP_ANASTASIA].extrinsic || have_femtrapanastasia())
#define FemtrapActiveJessica	(FemaleTrapJessica || u.uprops[FEMTRAP_JESSICA].extrinsic || have_femtrapjessica())
#define FemtrapActiveSolvejg	(FemaleTrapSolvejg || u.uprops[FEMTRAP_SOLVEJG].extrinsic || have_femtrapsolvejg())
#define FemtrapActiveWendy	(FemaleTrapWendy || u.uprops[FEMTRAP_WENDY].extrinsic || have_femtrapwendy())
#define FemtrapActiveKatharina	(FemaleTrapKatharina || u.uprops[FEMTRAP_KATHARINA].extrinsic || have_femtrapkatharina())
#define FemtrapActiveElena	(FemaleTrapElena || u.uprops[FEMTRAP_ELENA].extrinsic || have_femtrapelena())
#define FemtrapActiveThai	(FemaleTrapThai || u.uprops[FEMTRAP_THAI].extrinsic || have_femtrapthai())
#define FemtrapActiveElif	(FemaleTrapElif || u.uprops[FEMTRAP_ELIF].extrinsic || have_femtrapelif())
#define FemtrapActiveNadja	(FemaleTrapNadja || u.uprops[FEMTRAP_NADJA].extrinsic || have_femtrapnadja())
#define FemtrapActiveSandra	(FemaleTrapSandra || u.uprops[FEMTRAP_SANDRA].extrinsic || have_femtrapsandra())
#define FemtrapActiveNatalje	(FemaleTrapNatalje || u.uprops[FEMTRAP_NATALJE].extrinsic || have_femtrapnatalje())
#define FemtrapActiveJeanetta	(FemaleTrapJeanetta || u.uprops[FEMTRAP_JEANETTA].extrinsic || have_femtrapjeanetta())
#define FemtrapActiveYvonne	(FemaleTrapYvonne || u.uprops[FEMTRAP_YVONNE].extrinsic || have_femtrapyvonne())
#define FemtrapActiveMaurah	(FemaleTrapMaurah || u.uprops[FEMTRAP_MAURAH].extrinsic || have_femtrapmaurah())
#define FemtrapActiveMeltem	(FemaleTrapMeltem || u.uprops[FEMTRAP_MELTEM].extrinsic || have_femtrapmeltem())
#define FemtrapActiveSarah	(FemaleTrapSarah || u.uprops[FEMTRAP_SARAH].extrinsic || have_femtrapsarah())
#define FemtrapActiveClaudia	(FemaleTrapClaudia || u.uprops[FEMTRAP_CLAUDIA].extrinsic || have_femtrapclaudia())
#define FemtrapActiveLudgera	(FemaleTrapLudgera || u.uprops[FEMTRAP_LUDGERA].extrinsic || have_femtrapludgera())
#define FemtrapActiveKati	(FemaleTrapKati || u.uprops[FEMTRAP_KATI].extrinsic || have_femtrapkati())

#define RngeIrregularity		(u.uprops[RNGE_IRREGULARITY].intrinsic || u.uprops[RNGE_IRREGULARITY].extrinsic)
#define RngeInternetAccess		(u.uprops[RNGE_INTERNET_ACCESS].intrinsic || u.uprops[RNGE_INTERNET_ACCESS].extrinsic)
#define RngeAntiGovernment		(u.uprops[RNGE_ANTI_GOVERNMENT].intrinsic || u.uprops[RNGE_ANTI_GOVERNMENT].extrinsic)
#define RngeGasFiltering		(u.uprops[RNGE_GAS_FILTERING].intrinsic || u.uprops[RNGE_GAS_FILTERING].extrinsic)
#define RngeVampiricDrain		(u.uprops[RNGE_VAMPIRIC_DRAIN].intrinsic || u.uprops[RNGE_VAMPIRIC_DRAIN].extrinsic)
#define RngePseudoIdentification		(u.uprops[RNGE_PSEUDO_IDENTIFICATION].intrinsic || u.uprops[RNGE_PSEUDO_IDENTIFICATION].extrinsic)
#define RngeGhostSummoning		(u.uprops[RNGE_GHOST_SUMMONING].intrinsic || u.uprops[RNGE_GHOST_SUMMONING].extrinsic)
#define RngePrayer		(u.uprops[RNGE_PRAYER].intrinsic || u.uprops[RNGE_PRAYER].extrinsic)
#define RngeAntiBeheading		(u.uprops[RNGE_ANTI_BEHEADING].intrinsic || u.uprops[RNGE_ANTI_BEHEADING].extrinsic)
#define RngePoland		(u.uprops[RNGE_POLAND].intrinsic || u.uprops[RNGE_POLAND].extrinsic)
#define RngeKicking		(u.uprops[RNGE_KICKING].intrinsic || u.uprops[RNGE_KICKING].extrinsic)
#define RngeToestomping		(u.uprops[RNGE_TOESTOMPING].intrinsic || u.uprops[RNGE_TOESTOMPING].extrinsic)
#define RngeJungleAction		(u.uprops[RNGE_JUNGLE_ACTION].intrinsic || u.uprops[RNGE_JUNGLE_ACTION].extrinsic)
#define RngeUnlikability		(u.uprops[RNGE_UNLIKABILITY].intrinsic || u.uprops[RNGE_UNLIKABILITY].extrinsic)
#define RngeSpellDisruption		(u.uprops[RNGE_SPELL_DISRUPTION].intrinsic || u.uprops[RNGE_SPELL_DISRUPTION].extrinsic)
#define RngeBDSM		(u.uprops[RNGE_BDSM].intrinsic || u.uprops[RNGE_BDSM].extrinsic)
#define RngeSlipping		(u.uprops[RNGE_SLIPPING].intrinsic || u.uprops[RNGE_SLIPPING].extrinsic)
#define RngeMirroring		(u.uprops[RNGE_MIRRORING].intrinsic || u.uprops[RNGE_MIRRORING].extrinsic)
#define RngeTrueSight		(u.uprops[RNGE_TRUE_SIGHT].intrinsic || u.uprops[RNGE_TRUE_SIGHT].extrinsic)
#define RngeLiquidDiet		(u.uprops[RNGE_LIQUID_DIET].intrinsic || u.uprops[RNGE_LIQUID_DIET].extrinsic)
#define RngeAngryGods		(u.uprops[RNGE_ANGRY_GODS].intrinsic || u.uprops[RNGE_ANGRY_GODS].extrinsic)
#define RngeRadioBroadcasts		(u.uprops[RNGE_RADIO_BROADCASTS].intrinsic || u.uprops[RNGE_RADIO_BROADCASTS].extrinsic)
#define RngeOccasionalDamage		(u.uprops[RNGE_OCCASIONAL_DAMAGE].intrinsic || u.uprops[RNGE_OCCASIONAL_DAMAGE].extrinsic)
#define RngeNoise		(u.uprops[RNGE_NOISE].intrinsic || u.uprops[RNGE_NOISE].extrinsic)
#define RngeVortices		(u.uprops[RNGE_VORTICES].intrinsic || u.uprops[RNGE_VORTICES].extrinsic)
#define RngeExplosions		(u.uprops[RNGE_EXPLOSIONS].intrinsic || u.uprops[RNGE_EXPLOSIONS].extrinsic)
#define RngeFatalAttraction		(u.uprops[RNGE_FATAL_ATTRACTION].intrinsic || u.uprops[RNGE_FATAL_ATTRACTION].extrinsic)
#define RngeVoltage		(u.uprops[RNGE_VOLTAGE].intrinsic || u.uprops[RNGE_VOLTAGE].extrinsic)
#define RngeWeeping		(u.uprops[RNGE_WEEPING].intrinsic || u.uprops[RNGE_WEEPING].extrinsic)
#define RngeCastlevania		(u.uprops[RNGE_CASTLEVANIA].intrinsic || u.uprops[RNGE_CASTLEVANIA].extrinsic)
#define RngeEngland		(u.uprops[RNGE_ENGLAND].intrinsic || u.uprops[RNGE_ENGLAND].extrinsic)
#define RngeForgetting		(u.uprops[RNGE_FORGETTING].intrinsic || u.uprops[RNGE_FORGETTING].extrinsic)
#define RngeAntimagicA		(u.uprops[RNGE_ANTIMAGIC_A].intrinsic || u.uprops[RNGE_ANTIMAGIC_A].extrinsic)
#define RngeAntimagicB		(u.uprops[RNGE_ANTIMAGIC_B].intrinsic || u.uprops[RNGE_ANTIMAGIC_B].extrinsic)
#define RngeAntimagicC		(u.uprops[RNGE_ANTIMAGIC_C].intrinsic || u.uprops[RNGE_ANTIMAGIC_C].extrinsic)
#define RngeAntimagicD		(u.uprops[RNGE_ANTIMAGIC_D].intrinsic || u.uprops[RNGE_ANTIMAGIC_D].extrinsic)
#define RngeChina		(u.uprops[RNGE_CHINA].intrinsic || u.uprops[RNGE_CHINA].extrinsic)
#define RngeLightAbsorption		(u.uprops[RNGE_LIGHT_ABSORPTION].intrinsic || u.uprops[RNGE_LIGHT_ABSORPTION].extrinsic)
#define RngeChildbirth		(u.uprops[RNGE_CHILDBIRTH].intrinsic || u.uprops[RNGE_CHILDBIRTH].extrinsic)
#define RngeRedAttunement		(u.uprops[RNGE_RED_ATTUNEMENT].intrinsic || u.uprops[RNGE_RED_ATTUNEMENT].extrinsic)
#define RngePolarOpposites		(u.uprops[RNGE_POLAR_OPPOSITES].intrinsic || u.uprops[RNGE_POLAR_OPPOSITES].extrinsic)
#define RngeSickness		(u.uprops[RNGE_SICKNESS].intrinsic || u.uprops[RNGE_SICKNESS].extrinsic)
#define RngeCoquetry		(u.uprops[RNGE_COQUETRY].intrinsic || u.uprops[RNGE_COQUETRY].extrinsic)
#define RngeIgnorance		(u.uprops[RNGE_IGNORANCE].intrinsic || u.uprops[RNGE_IGNORANCE].extrinsic)
#define RngeVengeance		(u.uprops[RNGE_VENGEANCE].intrinsic || u.uprops[RNGE_VENGEANCE].extrinsic)
#define RngeHighHeeling		(u.uprops[RNGE_HIGH_HEELING].intrinsic || u.uprops[RNGE_HIGH_HEELING].extrinsic)
#define RngeGravity		(u.uprops[RNGE_GRAVITY].intrinsic || u.uprops[RNGE_GRAVITY].extrinsic)
#define RngeWishImprovement		(u.uprops[RNGE_WISH_IMPROVEMENT].intrinsic || u.uprops[RNGE_WISH_IMPROVEMENT].extrinsic)
#define RngePocketMonsters		(u.uprops[RNGE_POCKET_MONSTERS].intrinsic || u.uprops[RNGE_POCKET_MONSTERS].extrinsic)
#define RngeLevuntation		(u.uprops[RNGE_LEVUNTATION].intrinsic || u.uprops[RNGE_LEVUNTATION].extrinsic)
#define RngePermanentOccupation		(u.uprops[RNGE_PERMANENT_OCCUPATION].intrinsic || u.uprops[RNGE_PERMANENT_OCCUPATION].extrinsic)
#define RngeNursery		(u.uprops[RNGE_NURSERY].intrinsic || u.uprops[RNGE_NURSERY].extrinsic)
#define RngeSlexuality		(u.uprops[RNGE_SLEXUALITY].intrinsic || u.uprops[RNGE_SLEXUALITY].extrinsic)
#define RngeAngband		(u.uprops[RNGE_ANGBAND].intrinsic || u.uprops[RNGE_ANGBAND].extrinsic)
#define RngeAnorexia		(u.uprops[RNGE_ANOREXIA].intrinsic || u.uprops[RNGE_ANOREXIA].extrinsic)
#define RngeDnethack		(u.uprops[RNGE_DNETHACK].intrinsic || u.uprops[RNGE_DNETHACK].extrinsic)
#define RngeUnnethack		(u.uprops[RNGE_UNNETHACK].intrinsic || u.uprops[RNGE_UNNETHACK].extrinsic)
#define RngeNethackFourk		(u.uprops[RNGE_NETHACK_FOURK].intrinsic || u.uprops[RNGE_NETHACK_FOURK].extrinsic)
#define RngeMaritalArts		(u.uprops[RNGE_MARITAL_ARTS].intrinsic || u.uprops[RNGE_MARITAL_ARTS].extrinsic)
#define RngeTeamSplat		(u.uprops[RNGE_TEAM_SPLAT].intrinsic || u.uprops[RNGE_TEAM_SPLAT].extrinsic)
#define RngeAbominations		(u.uprops[RNGE_ABOMINATIONS].intrinsic || u.uprops[RNGE_ABOMINATIONS].extrinsic)
#define RngePunishment		(u.uprops[RNGE_PUNISHMENT].intrinsic || u.uprops[RNGE_PUNISHMENT].extrinsic)
#define RngeBloodlust		(u.uprops[RNGE_BLOODLUST].intrinsic || u.uprops[RNGE_BLOODLUST].extrinsic)
#define RngeImmobility		(u.uprops[RNGE_IMMOBILITY].intrinsic || u.uprops[RNGE_IMMOBILITY].extrinsic)
#define RngeBossEncounters		(u.uprops[RNGE_BOSS_ENCOUNTERS].intrinsic || u.uprops[RNGE_BOSS_ENCOUNTERS].extrinsic)
#define RngeIronmanMode		(u.uprops[RNGE_IRONMAN_MODE].intrinsic || u.uprops[RNGE_IRONMAN_MODE].extrinsic)
#define RngeRivers		(u.uprops[RNGE_RIVERS].intrinsic || u.uprops[RNGE_RIVERS].extrinsic)
#define RngeLoudspeakers		(u.uprops[RNGE_LOUDSPEAKERS].intrinsic || u.uprops[RNGE_LOUDSPEAKERS].extrinsic)
#define RngeArmorPreservation		(u.uprops[RNGE_ARMOR_PRESERVATION].intrinsic || u.uprops[RNGE_ARMOR_PRESERVATION].extrinsic)
#define RngeWeakness		(u.uprops[RNGE_WEAKNESS].intrinsic || u.uprops[RNGE_WEAKNESS].extrinsic)
#define RngeFrailness		(u.uprops[RNGE_FRAILNESS].intrinsic || u.uprops[RNGE_FRAILNESS].extrinsic)
#define RngeIronMaiden		(u.uprops[RNGE_IRON_MAIDEN].intrinsic || u.uprops[RNGE_IRON_MAIDEN].extrinsic)
#define RngeDonors		(u.uprops[RNGE_DONORS].intrinsic || u.uprops[RNGE_DONORS].extrinsic)
#define RngeAids		(u.uprops[RNGE_AIDS].intrinsic || u.uprops[RNGE_AIDS].extrinsic)
#define RngeTrapAlert		(u.uprops[RNGE_TRAP_ALERT].intrinsic || u.uprops[RNGE_TRAP_ALERT].extrinsic)
#define RngeExtinction		(u.uprops[RNGE_EXTINCTION].intrinsic || u.uprops[RNGE_EXTINCTION].extrinsic)
#define RngeDefusing		(u.uprops[RNGE_DEFUSING].intrinsic || u.uprops[RNGE_DEFUSING].extrinsic)
#define RngeDenastification		(u.uprops[RNGE_DENASTIFICATION].intrinsic || u.uprops[RNGE_DENASTIFICATION].extrinsic)
#define RngeMultishot		(u.uprops[RNGE_MULTISHOT].intrinsic || u.uprops[RNGE_MULTISHOT].extrinsic)
#define RngeSkillReveal		(u.uprops[RNGE_SKILL_REVEAL].intrinsic || u.uprops[RNGE_SKILL_REVEAL].extrinsic)
#define RngeTechInsight		(u.uprops[RNGE_TECH_INSIGHT].intrinsic || u.uprops[RNGE_TECH_INSIGHT].extrinsic)
#define RngeListening		(u.uprops[RNGE_LISTENING].intrinsic || u.uprops[RNGE_LISTENING].extrinsic)
#define RngeCannibalism		(u.uprops[RNGE_CANNIBALISM].intrinsic || u.uprops[RNGE_CANNIBALISM].extrinsic)
#define RngePolyvision		(u.uprops[RNGE_POLYVISION].intrinsic || u.uprops[RNGE_POLYVISION].extrinsic)
#define RngeHemophilia		(u.uprops[RNGE_HEMOPHILIA].intrinsic || u.uprops[RNGE_HEMOPHILIA].extrinsic)
#define RngeBlastShielding		(u.uprops[RNGE_BLAST_SHIELDING].intrinsic || u.uprops[RNGE_BLAST_SHIELDING].extrinsic)
#define RngeFunnyHallu		(u.uprops[RNGE_FUNNY_HALLU].intrinsic || u.uprops[RNGE_FUNNY_HALLU].extrinsic)
#define RngePolypiling		(u.uprops[RNGE_POLYPILING].intrinsic || u.uprops[RNGE_POLYPILING].extrinsic)
#define RngeSapGeneration		(u.uprops[RNGE_SAP_GENERATION].intrinsic || u.uprops[RNGE_SAP_GENERATION].extrinsic)

/* Hallucination is solely a timeout; its resistance is extrinsic */
#define HHallucination		u.uprops[HALLUC].intrinsic
#define EHallucination		u.uprops[HALLUC].extrinsic

#define EHalluc_resistance	u.uprops[HALLUC_RES].extrinsic
#define Halluc_resistance	((EHalluc_resistance || \
				 (Upolyd && dmgtype(youmonst.data, AD_HALU)) || Race_if(PM_EROSATOR) || tech_inuse(T_STAT_RESIST) || (Role_if(PM_TRANSSYLVANIAN) && uwep && (uwep->otyp == WEDGED_LITTLE_GIRL_SANDAL || uwep->otyp == SOFT_GIRL_SNEAKER || uwep->otyp == STURDY_PLATEAU_BOOT_FOR_GIRLS || uwep->otyp == HUGGING_BOOT || uwep->otyp == BLOCK_HEELED_COMBAT_BOOT || uwep->otyp == WOODEN_GETA || uwep->otyp == LACQUERED_DANCING_SHOE || uwep->otyp == HIGH_HEELED_SANDAL || uwep->otyp == SEXY_LEATHER_PUMP || uwep->otyp == STICKSHOE || uwep->otyp == SPIKED_BATTLE_BOOT || uwep->otyp == INKA_BOOT || uwep->otyp == SOFT_LADY_SHOE || uwep->otyp == STEEL_CAPPED_SANDAL || uwep->otyp == BLOCK_HEELED_SANDAL || uwep->otyp == PROSTITUTE_SHOE || uwep->otyp == DOGSHIT_BOOT) ) ) && !u.halresdeactivated)

#define Hallucination		((HHallucination && !Halluc_resistance) || (u.uprops[MULTISHOES].extrinsic && !Halluc_resistance) || (uwep && uwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_FADED_USELESSNESS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_FADED_USELESSNESS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_SCHWANZUS_LANGUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SCHWANZUS_LANGUS) || (HeavyHallu && !Halluc_resistance) || (EHallucination && !Halluc_resistance) || u.uprops[SENSORY_DEPRIVATION].extrinsic || flags.hippie || ( (u.uprops[DEHYDRATION].extrinsic || Dehydration || have_dehydratingstone()) && ((u.dehydrationtime - moves) < 1) )  )
#define FunnyHallu		(Role_if(PM_GOFF) || RngeFunnyHallu || ishallucinator || HHallucination || u.uprops[MULTISHOES].extrinsic || (uwep && uwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_FADED_USELESSNESS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_FADED_USELESSNESS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_LANCE_OF_LONGINUS) || (uwep && uwep->oartifact == ART_SCHWANZUS_LANGUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_SCHWANZUS_LANGUS) || HeavyHallu || EHallucination || u.uprops[SENSORY_DEPRIVATION].extrinsic || (u.funnyhalluroll != 9999999 && u.usanity > u.funnyhalluroll) || flags.hippie || ( (u.uprops[DEHYDRATION].extrinsic || Dehydration || have_dehydratingstone()) && ((u.dehydrationtime - moves) < 1) )  )
/* added possibility of playing the entire game hallucinating --Amy*/
#define HeavyHallu		u.uprops[HEAVY_HALLU].intrinsic

/* Timeout, plus a worn mask */
#define HFumbling		u.uprops[FUMBLING].intrinsic
#define EFumbling		u.uprops[FUMBLING].extrinsic
#define Fumbling		(HFumbling || EFumbling || u.uprops[MULTISHOES].extrinsic)

#define HWounded_legs		u.uprops[WOUNDED_LEGS].intrinsic
#define EWounded_legs		u.uprops[WOUNDED_LEGS].extrinsic
#define Wounded_legs		((HWounded_legs || EWounded_legs || (uarmf && uarmf->oartifact == ART_CINDERELLA_S_SLIPPERS) || (uarmf && uarmf->oartifact == ART_UNTRAINED_HALF_MARATHON) || u.uprops[MULTISHOES].extrinsic) && !(uarmf && uarmf->oartifact == ART_ELIANE_S_SHIN_SMASH) )

#define HSleeping		u.uprops[SLEEPING].intrinsic
#define ESleeping		u.uprops[SLEEPING].extrinsic
#define Sleeping		(HSleeping || ESleeping || Race_if(PM_KOBOLT))

#define HHunger			u.uprops[HUNGER].intrinsic
#define EHunger			u.uprops[HUNGER].extrinsic
#define IntHunger	(HHunger || Race_if(PM_GIGANT) || Race_if(PM_GAVIL))
#define ExtHunger	(EHunger || (uarmc && uarmc->oartifact == ART_INA_S_LAB_COAT) || (uwep && uwep->oartifact == ART_GIANT_MEAT_STICK) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_GIANT_MEAT_STICK) || (uarmc && uarmc->oartifact == ART_INA_S_OVERCOAT) || (uleft && uleft->oartifact == ART_RING_OF_WOE) || (uarmh && uarmh->oartifact == ART_DRINK_COCA_COLA) || (uarmh && uarmh->oartifact == ART_HAMBURG_ONE) || (uarmc && uarmc->oartifact == ART_FULLY_LIONIZED) || (uarmc && uarmc->oartifact == ART_FAST_CAMO_PREDATOR) || (uright && uright->oartifact == ART_RING_OF_WOE) || (uimplant && uimplant->oartifact == ART_BUCKET_HOUSE) || (uwep && uwep->oartifact == ART_PICK_OF_THE_GRAVE) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_PICK_OF_THE_GRAVE) )

#define Hunger			(IntHunger || ExtHunger)
#define StrongHunger	(IntHunger && ExtHunger && Hunger)


/*** Vision and senses ***/
#define HSee_invisible		u.uprops[SEE_INVIS].intrinsic
#define ESee_invisible		u.uprops[SEE_INVIS].extrinsic
#define IntSee_invisible	(HSee_invisible || perceives(youmonst.data))
#define ExtSee_invisible	(ESee_invisible || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SEE_INVIS) ) || (uarmc && uarmc->oartifact == ART_VISIBLE_INVISIBILITITY) || (uarmh && uarmh->oartifact == ART_CHRISTMAS_MEDAL) || (uimplant && uimplant->oartifact == ART_CORONATION_CULMINATION) || (uimplant && uimplant->oartifact == ART_POTATOROK) || (uamul && uamul->oartifact == ART_ARABELLA_S_DICINATOR) || (uarmc && uarmc->oartifact == ART_CAN_T_KILL_WHAT_YOU_CAN_T_) || (uwep && uwep->oartifact == ART_SECRETS_OF_INVISIBLE_PLEAS))

#define See_invisible		(((IntSee_invisible && u.nonintrinsicproperty != SEE_INVIS) || (ExtSee_invisible && u.nonextrinsicproperty != SEE_INVIS)) && !Race_if(PM_ELEMENTAL) && !NoSee_invisible)
#define StrongSee_invisible	(IntSee_invisible && ExtSee_invisible && See_invisible && u.nondoubleproperty != SEE_INVIS)

#define NoSee_invisible	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SEE_INVIS].intrinsic || RngeAids || (u.impossibleproperty == SEE_INVIS) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HTelepat		u.uprops[TELEPAT].intrinsic
#define ETelepat		u.uprops[TELEPAT].extrinsic
#define IntTelepat	(HTelepat || Race_if(PM_DEVELOPER) || telepathic(youmonst.data) || (Role_if(PM_TOPMODEL) && PlayerInHighHeels) )
#define ExtTelepat	(ETelepat || Race_if(PM_DEVELOPER))

#define Blind_telepat		(!(u.nonintrinsicproperty == TELEPAT) && !Race_if(PM_KUTAR) && IntTelepat && !NoTelepat && !u.powerfailure && !(Role_if(PM_TOPMODEL) && flags.female && !PlayerInHighHeels) )

#define Unblind_telepat		(!(u.nonextrinsicproperty == TELEPAT) && !Race_if(PM_KUTAR) && ExtTelepat && !NoTelepat)
#define StrongTelepat		(IntTelepat && ExtTelepat && Blind_telepat && Unblind_telepat && u.nondoubleproperty != TELEPAT)

#define NoTelepat	( (!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_TELEPAT].intrinsic || Race_if(PM_KUTAR) || RngeAids || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0))) || (uarmc && uarmc->oartifact == ART_GODLESS_VOID) || (u.impossibleproperty == TELEPAT) || (uarmh && uarmh->oartifact == ART_WOLF_KING) || (uarmh && ( (uarmh->otyp == TINFOIL_HELMET) || itemhasappearance(uarmh, APP_ALUMINIUM_HELMET) ) ) )

#define HHallu_party	u.uprops[HALLU_PARTY].intrinsic
#define EHallu_party	u.uprops[HALLU_PARTY].extrinsic
#define Hallu_party	(((HHallu_party && !(u.nonintrinsicproperty == HALLU_PARTY)) || EHallu_party) && !NoHallu_party)
#define NoHallu_party	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_HALLU_PARTY].intrinsic || RngeAids || (u.nonextrinsicproperty == HALLU_PARTY && !HHallu_party) || (u.impossibleproperty == HALLU_PARTY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDrunken_boxing		u.uprops[DRUNKEN_BOXING].intrinsic
#define EDrunken_boxing		u.uprops[DRUNKEN_BOXING].extrinsic
#define Drunken_boxing		(((HDrunken_boxing && !(u.nonintrinsicproperty == DRUNKEN_BOXING)) || EDrunken_boxing) && !NoDrunken_boxing)
#define NoDrunken_boxing	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DRUNKEN_BOXING].intrinsic || RngeAids || (u.nonextrinsicproperty == DRUNKEN_BOXING && !HDrunken_boxing) || (u.impossibleproperty == DRUNKEN_BOXING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HStunnopathy	u.uprops[STUNNOPATHY].intrinsic
#define EStunnopathy	u.uprops[STUNNOPATHY].extrinsic
#define Stunnopathy	(((HStunnopathy && !(u.nonintrinsicproperty == STUNNOPATHY)) || EStunnopathy) && !NoStunnopathy)
#define NoStunnopathy	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_STUNNOPATHY].intrinsic || RngeAids || (u.nonextrinsicproperty == STUNNOPATHY && !HStunnopathy) || (u.impossibleproperty == STUNNOPATHY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HNumbopathy	u.uprops[NUMBOPATHY].intrinsic
#define ENumbopathy	u.uprops[NUMBOPATHY].extrinsic
#define Numbopathy	(((HNumbopathy && !(u.nonintrinsicproperty == NUMBOPATHY)) || ENumbopathy) && !NoNumbopathy)
#define NoNumbopathy	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_NUMBOPATHY].intrinsic || RngeAids || (u.nonextrinsicproperty == NUMBOPATHY && !HNumbopathy) || (u.impossibleproperty == NUMBOPATHY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDimmopathy	u.uprops[DIMMOPATHY].intrinsic
#define EDimmopathy	u.uprops[DIMMOPATHY].extrinsic
#define Dimmopathy	(((HDimmopathy && !(u.nonintrinsicproperty == DIMMOPATHY)) || EDimmopathy) && !NoDimmopathy)
#define NoDimmopathy	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DIMMOPATHY].intrinsic || RngeAids || (u.nonextrinsicproperty == DIMMOPATHY && !HDimmopathy) || (u.impossibleproperty == DIMMOPATHY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HFreezopathy	u.uprops[FREEZOPATHY].intrinsic
#define EFreezopathy	u.uprops[FREEZOPATHY].extrinsic
#define Freezopathy	(((HFreezopathy && !(u.nonintrinsicproperty == FREEZOPATHY)) || EFreezopathy) && !NoFreezopathy)
#define NoFreezopathy	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FREEZOPATHY].intrinsic || RngeAids || (u.nonextrinsicproperty == FREEZOPATHY && !HFreezopathy) || (u.impossibleproperty == FREEZOPATHY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HStoned_chiller		u.uprops[STONED_CHILLER].intrinsic
#define EStoned_chiller		u.uprops[STONED_CHILLER].extrinsic
#define Stoned_chiller		(((HStoned_chiller && !(u.nonintrinsicproperty == STONED_CHILLER)) || EStoned_chiller) && !NoStoned_chiller)
#define NoStoned_chiller	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_STONED_CHILLER].intrinsic || RngeAids || (u.nonextrinsicproperty == STONED_CHILLER && !HStoned_chiller) || (u.impossibleproperty == STONED_CHILLER) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HCorrosivity	u.uprops[CORROSIVITY].intrinsic
#define ECorrosivity	u.uprops[CORROSIVITY].extrinsic
#define Corrosivity	(((HCorrosivity && !(u.nonintrinsicproperty == CORROSIVITY)) || ECorrosivity) && !NoCorrosivity)
#define NoCorrosivity	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_CORROSIVITY].intrinsic || RngeAids || (u.nonextrinsicproperty == CORROSIVITY && !HCorrosivity) || (u.impossibleproperty == CORROSIVITY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HFear_factor	u.uprops[FEAR_FACTOR].intrinsic
#define EFear_factor	u.uprops[FEAR_FACTOR].extrinsic
#define Fear_factor	(((HFear_factor && !(u.nonintrinsicproperty == FEAR_FACTOR)) || EFear_factor) && !NoFear_factor)
#define NoFear_factor	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FEAR_FACTOR].intrinsic || RngeAids || (u.nonextrinsicproperty == FEAR_FACTOR && !HFear_factor) || (u.impossibleproperty == FEAR_FACTOR) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HBurnopathy	u.uprops[BURNOPATHY].intrinsic
#define EBurnopathy	u.uprops[BURNOPATHY].extrinsic
#define Burnopathy	(((HBurnopathy && !(u.nonintrinsicproperty == BURNOPATHY)) || EBurnopathy) && !NoBurnopathy)
#define NoBurnopathy	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_BURNOPATHY].intrinsic || RngeAids || (u.nonextrinsicproperty == BURNOPATHY && !HBurnopathy) || (u.impossibleproperty == BURNOPATHY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HSickopathy	u.uprops[SICKOPATHY].intrinsic
#define ESickopathy	u.uprops[SICKOPATHY].extrinsic
#define Sickopathy	(((HSickopathy && !(u.nonintrinsicproperty == SICKOPATHY)) || ESickopathy) && !NoSickopathy)
#define NoSickopathy	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SICKOPATHY].intrinsic || RngeAids || (u.nonextrinsicproperty == SICKOPATHY && !HSickopathy) || (u.impossibleproperty == SICKOPATHY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HWonderlegs	u.uprops[WONDERLEGS].intrinsic
#define EWonderlegs	u.uprops[WONDERLEGS].extrinsic
#define Wonderlegs	(((HWonderlegs && !(u.nonintrinsicproperty == WONDERLEGS)) || EWonderlegs) && !NoWonderlegs)
#define NoWonderlegs	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_WONDERLEGS].intrinsic || RngeAids || (u.nonextrinsicproperty == WONDERLEGS && !HWonderlegs) || (u.impossibleproperty == WONDERLEGS) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HGlib_combat	u.uprops[GLIB_COMBAT].intrinsic
#define EGlib_combat	u.uprops[GLIB_COMBAT].extrinsic
#define Glib_combat	(((HGlib_combat && !(u.nonintrinsicproperty == GLIB_COMBAT)) || EGlib_combat) && !NoGlib_combat)
#define NoGlib_combat	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_GLIB_COMBAT].intrinsic || RngeAids || (u.nonextrinsicproperty == GLIB_COMBAT && !HGlib_combat) || (u.impossibleproperty == GLIB_COMBAT) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HManaleech	u.uprops[MANALEECH].intrinsic
#define EManaleech	u.uprops[MANALEECH].extrinsic
#define IntManaleech	(HManaleech)
#define ExtManaleech	(EManaleech || (uwep && uwep->oartifact == ART_MANA_EATER) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == MANALEECH) ) || (uarmu && uarmu->oartifact == ART_VICTORIA_IS_EVIL_BUT_PRETT) || (uarmu && uarmu->oartifact == ART_NATALIA_IS_LOVELY_BUT_DANG) || (uarmf && uarmf->oartifact == ART_SOLVEJG_S_STINKING_SLIPPER) || (uarm && flags.female && uarm->oartifact == ART_PRETTY_LITTLE_MAGICAL_GIRL) || (uarmh && uarmh->oartifact == ART_REFUEL_BADLY) || (uamul && uamul->oartifact == ART_BALLSY_BASTARD) || (uamul && uamul->oartifact == ART_MADMAN_S_POWER) || (uamul && uamul->oartifact == ART___TH_NAZGUL) || (uamul && uamul->oartifact == ART_NAZGUL_S_REVENGE) )

#define Manaleech		(((IntManaleech && u.nonintrinsicproperty != MANALEECH) || (ExtManaleech && u.nonextrinsicproperty != MANALEECH)) && !NoManaleech)
#define StrongManaleech	(IntManaleech && ExtManaleech && Manaleech && u.nondoubleproperty != MANALEECH)

#define NoManaleech	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_MANALEECH].intrinsic || RngeAids || (u.impossibleproperty == MANALEECH) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HPeacevision	u.uprops[PEACEVISION].intrinsic
#define EPeacevision	u.uprops[PEACEVISION].extrinsic
#define IntPeacevision	(HPeacevision)
#define ExtPeacevision	(EPeacevision || (uwep && uwep->oartifact == ART_LENA_S_PEACE_OFFERING) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == PEACEVISION) ) )

#define Peacevision		(((IntPeacevision && u.nonintrinsicproperty != PEACEVISION) || (ExtPeacevision && u.nonextrinsicproperty != PEACEVISION)) && !NoPeacevision)
#define StrongPeacevision	(IntPeacevision && ExtPeacevision && Peacevision && u.nondoubleproperty != PEACEVISION)

#define NoPeacevision	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_PEACEVISION].intrinsic || RngeAids || (u.impossibleproperty == PEACEVISION) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HMap_amnesia	u.uprops[MAP_AMNESIA].intrinsic
#define EMap_amnesia	u.uprops[MAP_AMNESIA].extrinsic
#define Map_amnesia	(HMap_amnesia || EMap_amnesia || In_voiddungeon(&u.uz) || In_netherrealm(&u.uz))

#define HWarning		u.uprops[WARNING].intrinsic
#define EWarning		u.uprops[WARNING].extrinsic
#define IntWarning	(HWarning)
#define ExtWarning	(EWarning || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == WARNING) ) || (Role_if(PM_TOPMODEL) && PlayerInHighHeels) )

#define Warning			(((IntWarning && u.nonintrinsicproperty != WARNING) || (ExtWarning && u.nonextrinsicproperty != WARNING)) && !Race_if(PM_KUTAR) && !u.powerfailure && !NoWarning && !(Role_if(PM_TOPMODEL) && flags.female && !PlayerInHighHeels) )
#define StrongWarning	(IntWarning && ExtWarning && Warning && u.nondoubleproperty != WARNING)

#define NoWarning	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_WARNING].intrinsic || RngeAids || (u.impossibleproperty == WARNING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

/* Warning for a specific type of monster */
#define HWarn_of_mon		u.uprops[WARN_OF_MON].intrinsic
#define EWarn_of_mon		u.uprops[WARN_OF_MON].extrinsic
#define Warn_of_mon		(HWarn_of_mon || EWarn_of_mon)

#define HUndead_warning		u.uprops[WARN_UNDEAD].intrinsic
#define EUndead_warning		u.uprops[WARN_UNDEAD].extrinsic
#define Undead_warning		(HUndead_warning || EUndead_warning || (uarmh && uarmh->oartifact == ART_ALL_SEEING_EYE_OF_THE_FLY) || (uarmh && uarmh->oartifact == ART_FLUE_FLUE_FLUEFLUE_FLUE) || (uarmh && uarmh->oartifact == ART_CONTROLLER_HAT))

#define HSearching		u.uprops[SEARCHING].intrinsic
#define ESearching		u.uprops[SEARCHING].extrinsic
#define IntSearching	(HSearching)
#define ExtSearching	(ESearching || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SEARCHING) ) )

#define Searching		(((IntSearching && u.nonintrinsicproperty != SEARCHING) || (ExtSearching && u.nonextrinsicproperty != SEARCHING)) && !Race_if(PM_KUTAR) && !NoSearching)
#define StrongSearching	(IntSearching && ExtSearching && Searching && u.nondoubleproperty != SEARCHING)

#define NoSearching	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SEARCHING].intrinsic || RngeAids || (u.impossibleproperty == SEARCHING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HClairvoyant		u.uprops[CLAIRVOYANT].intrinsic
#define EClairvoyant		u.uprops[CLAIRVOYANT].extrinsic
#define BClairvoyant		u.uprops[CLAIRVOYANT].blocked
#define IntClairvoyant	(HClairvoyant)
#define ExtClairvoyant	(EClairvoyant || (uwep && uwep->oartifact == ART_VARIANT_SOURCE_PACKAGE) || (uwep && uwep->oartifact == ART_TOOTH_OF_SHAI_HULUD) || (uwep && uwep->oartifact == ART_GAME_KNOWLEDGE_CHEAT_SHEET) || (uamul && uamul->oartifact == ART_ARABELLA_S_SWOONING_BEAUTY) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == CLAIRVOYANT) ) || (uamul && uamul->oartifact == ART_WOUUU) || (uarmh && uarmh->oartifact == ART_WSCHIIIIIE_))

#define Clairvoyant		(((IntClairvoyant && u.nonintrinsicproperty != CLAIRVOYANT) || (ExtClairvoyant && u.nonextrinsicproperty != CLAIRVOYANT)) && !BClairvoyant && !NoClairvoyant)
#define StrongClairvoyant	(IntClairvoyant && ExtClairvoyant && Clairvoyant && u.nondoubleproperty != CLAIRVOYANT)

#define NoClairvoyant	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_CLAIRVOYANT].intrinsic || RngeAids || (u.impossibleproperty == CLAIRVOYANT) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HInfravision		u.uprops[INFRAVISION].intrinsic
#define EInfravision		u.uprops[INFRAVISION].extrinsic
#define IntInfravision	(HInfravision || infravision(youmonst.data))
#define ExtInfravision	(EInfravision || (uarmc && uarmc->oartifact == ART_GAGARIN_S_TRANSLATOR) || (uarmf && uarmf->oartifact == ART_ARVOGENIA_S_HIGH_HEELSES) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == INFRAVISION) ) || (uwep && uwep->oartifact == ART_DEMON_MACHINE) )

#define Infravision		(((IntInfravision && u.nonintrinsicproperty != INFRAVISION) || (ExtInfravision && u.nonextrinsicproperty != INFRAVISION)) && !Race_if(PM_KUTAR) && !u.powerfailure && !NoInfravision)
#define StrongInfravision	(IntInfravision && ExtInfravision && Infravision && u.nondoubleproperty != INFRAVISION)

#define NoInfravision	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_INFRAVISION].intrinsic || RngeAids || (u.impossibleproperty == INFRAVISION) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDetect_monsters	u.uprops[DETECT_MONSTERS].intrinsic
#define EDetect_monsters	u.uprops[DETECT_MONSTERS].extrinsic
#define IntDetect_monsters	(HDetect_monsters)
#define ExtDetect_monsters	(EDetect_monsters || (uleft && uleft->oartifact == ART_ARABELLA_S_RADAR) || (uright && uright->oartifact == ART_ARABELLA_S_RADAR) || (uamul && uamul->oartifact == ART_SURTERSTAFF && uwep && (weapon_type(uwep) == P_QUARTERSTAFF) ) || (uwep && uwep->oartifact == ART_RAFSCHAR_S_SUPERWEAPON) || u.uprops[STORM_HELM].extrinsic )

#define Detect_monsters		(((IntDetect_monsters && u.nonintrinsicproperty != DETECT_MONSTERS) || (ExtDetect_monsters && u.nonextrinsicproperty != DETECT_MONSTERS)) && !Race_if(PM_KUTAR) && !u.powerfailure && !NoDetect_monsters)
#define StrongDetect_monsters	(IntDetect_monsters && ExtDetect_monsters && Detect_monsters && u.nondoubleproperty != DETECT_MONSTERS)

#define NoDetect_monsters	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DETECT_MONSTERS].intrinsic || RngeAids || (u.impossibleproperty == DETECT_MONSTERS) || (uarmh && uarmh->oartifact == ART_RADAR_NOT_WORKING) || (isselfhybrid && (moves % 3 == 0) ) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))


/*** Appearance and behavior ***/
#define Adornment		u.uprops[ADORNED].extrinsic

#define HInvis			u.uprops[INVIS].intrinsic
#define EInvis			u.uprops[INVIS].extrinsic
#define BInvis			u.uprops[INVIS].blocked
#define IntInvis	(HInvis || pm_invisible(youmonst.data))
#define ExtInvis	(EInvis || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == INVIS) ) || (uwep && uwep->oartifact == ART_MOVE_IN_THE_SHADOWS) || (uwep && uwep->oartifact == ART_WHEREABOUT_OF_X) || (uarmc && uarmc->oartifact == ART_INVISIBLE_VISIBILITITY) || have_invisoloadstone() || (uarmf && uarmf->oartifact == ART_GORGEOUS_VEIL_MODEL) || (uamul && uamul->oartifact == ART_ARABELLA_S_DICINATOR) || (uarmh && uarmh->oartifact == ART_MARLENA_S_SONG) || (uarmh && uarmh->oartifact == ART_DULLIFIER) || (uarm && uarm->oartifact == ART_VERY_INVISIBLE) || (uarmc && uarmc->oartifact == ART_CAN_T_KILL_WHAT_YOU_CAN_T_) || (uwep && uwep->oartifact == ART_SECRETS_OF_INVISIBLE_PLEAS) )

#define Invis			(((IntInvis && u.nonintrinsicproperty != INVIS) || (ExtInvis && u.nonextrinsicproperty != INVIS)) && !BInvis && !Race_if(PM_ELEMENTAL) && !NoInvisible)
#define Invisible		(Invis && !See_invisible)
		/* Note: invisibility also hides inventory and steed */
#define StrongInvis	(IntInvis && ExtInvis && Invis && u.nondoubleproperty != INVIS)

#define NoInvisible	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_INVIS].intrinsic || RngeAids || (u.impossibleproperty == INVIS) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDisplaced		u.uprops[DISPLACED].intrinsic
#define EDisplaced		u.uprops[DISPLACED].extrinsic
#define IntDisplaced	(HDisplaced)
#define ExtDisplaced	(EDisplaced || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == DISPLACED) ) || (uarmc && uarmc->oartifact == ART_IMAGE_PROJECTOR) || (uwep && uwep->oartifact == ART_SKY_RENDER) || (uarm && uarm->oartifact == ART_VERY_INVISIBLE) || (uwep && uwep->oartifact == ART_LAUGHTERSNEE) || (uarmf && uarmf->oartifact == ART_WATER_FLOWERS) || (uwep && uwep->oartifact == ART_BELTHRONDING) || (uarm && uarm->oartifact == ART_ROBE_OF_THE_ARCHMAGI) || (uarmh && uarmh->oartifact == ART_MARLENA_S_SONG) || (uarm && uarm->oartifact == ART_SHIVANHUNTER_S_UNUSED_PRIZ) || (uarmc && itemhasappearance(uarmc, APP_SHROUDED_CLOAK) && (moves % 10 == 0) ) || ((moves % 3 == 0) && uarmc && itemhasappearance(uarmc, APP_DEEP_CLOAK) ) || (uarmf && itemhasappearance(uarmf, APP_KOREAN_SANDALS) && (moves % 3 == 0) ) )

#define Displaced		(((IntDisplaced && u.nonintrinsicproperty != DISPLACED) || (ExtDisplaced && u.nonextrinsicproperty != DISPLACED)) && !NoDisplaced)
#define StrongDisplaced	(IntDisplaced && ExtDisplaced && Displaced && u.nondoubleproperty != DISPLACED)

#define NoDisplaced	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DISPLACED].intrinsic || RngeAids || (u.impossibleproperty == DISPLACED) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HStealth		u.uprops[STEALTH].intrinsic
#define EStealth		u.uprops[STEALTH].extrinsic
#define BStealth		u.uprops[STEALTH].blocked
#define IntStealth	(HStealth || (Race_if(PM_MOON_ELF) && ((flags.moonphase >= 1 && flags.moonphase <= 3) || (flags.moonphase >= 5 && flags.moonphase <= 7))) )
#define ExtStealth	(EStealth || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == STEALTH) ) || u.uprops[MULTISHOES].extrinsic || (ublindf && ublindf->otyp == EYECLOSER) || (Role_if(PM_TOPMODEL) && PlayerInHighHeels) )

#define Stealth			(((IntStealth && u.nonintrinsicproperty != STEALTH) || (ExtStealth && u.nonextrinsicproperty != STEALTH)) && !BStealth && !NoStealth && !Race_if(PM_OGRO) && !(uwep && uwep->oartifact == ART_ARMORWREAKER) && !(u.twoweap && uswapwep && uswapwep->oartifact == ART_ARMORWREAKER) && !Race_if(PM_ROHIRRIM) && !Race_if(PM_THUNDERLORD) && !(Role_if(PM_TOPMODEL) && flags.female && !PlayerInHighHeels) )
#define StrongStealth	(IntStealth && ExtStealth && Stealth && u.nondoubleproperty != STEALTH)

#define NoStealth	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_STEALTH].intrinsic || RngeAids || (uarmc && itemhasappearance(uarmc, APP_EXCREMENT_CLOAK) ) || (u.impossibleproperty == STEALTH) || (uarmf && itemhasappearance(uarmf, APP_HEAP_OF_SHIT_BOOTS)) || (uarmf && uarmf->oartifact == ART_HENRIETTA_S_DOGSHIT_BOOTS) || FemtrapActiveSolvejg || (uwep && uwep->oartifact == ART_HENRIETTA_S_MISTAKE) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_HENRIETTA_S_MISTAKE) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HExtra_wpn_practice	u.uprops[EXTRA_WEAPON_PRACTICE].intrinsic
#define EExtra_wpn_practice	u.uprops[EXTRA_WEAPON_PRACTICE].extrinsic
#define IntExtra_wpn_practice	(HExtra_wpn_practice)
#define ExtExtra_wpn_practice	(EExtra_wpn_practice || (uwep && uwep->oartifact == ART_ARABELLA_S_BLACK_PRONG) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == EXTRA_WEAPON_PRACTICE) ) || (uarmc && uarmc->oartifact == ART_SKILLS_BEAT_STATS) || (uarm && uarm->oartifact == ART_MOTHERFUCKER_TROPHY) )

#define Extra_wpn_practice	(IntExtra_wpn_practice || ExtExtra_wpn_practice)
#define StrongExtra_wpn_practice	(IntExtra_wpn_practice && ExtExtra_wpn_practice && Extra_wpn_practice)

#define HDeath_resistance	u.uprops[DTBEEM_RES].intrinsic
#define EDeath_resistance	u.uprops[DTBEEM_RES].extrinsic
#define Death_resistance	(HDeath_resistance || EDeath_resistance || (Race_if(PM_ETHEREALOID) && !Upolyd) || Race_if(PM_PLAYER_GOLEM) || resists_death(&youmonst) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == DTBEEM_RES) ) || (uamul && uamul->oartifact == ART_ARABELLA_S_SWOONING_BEAUTY) || (uarmf && uarmf->oartifact == ART_PRADA_S_DEVIL_WEAR) || (uamul && uamul->oartifact == ART_YOU_HAVE_UGH_MEMORY) || (uarmf && uarmf->oartifact == ART_MADELEINE_S_GIRL_FOOTSTEPS) || (uarms && uarms->oartifact == ART_ANTINSTANT_DEATH) )

#define PlayerResistsDeathRays	(Death_resistance || Antimagic)

/* according to Yasdorian, I love aggravate monster. Indeed, many of my artifacts have it. --Amy */
#define HAggravate_monster	u.uprops[AGGRAVATE_MONSTER].intrinsic
#define EAggravate_monster	u.uprops[AGGRAVATE_MONSTER].extrinsic
#define IntAggravate_monster	(HAggravate_monster || Race_if(PM_NEMESIS) || (Race_if(PM_HC_ALIEN) && !flags.female) || (Race_if(PM_HUMANOID_ANGEL) && (u.ualign.record < 0)) || Race_if(PM_OGRO) || Race_if(PM_ROHIRRIM) || Race_if(PM_THUNDERLORD) || (Role_if(PM_PSION) && u.ulevel >= 7) || (Race_if(PM_SYLPH) && u.ulevel >= 18) || (Role_if(PM_PICKPOCKET) && (u.ualign.record < 0)))
#define ExtAggravate_monster	(playerextrinsicaggravatemon())

#define Aggravate_monster	(IntAggravate_monster || ExtAggravate_monster)
#define StrongAggravate_monster	(IntAggravate_monster && ExtAggravate_monster && Aggravate_monster)

#define HConflict		u.uprops[CONFLICT].intrinsic
#define EConflict		u.uprops[CONFLICT].extrinsic
#define IntConflict	(HConflict)
#define ExtConflict	(EConflict || (uarm && uarm->oartifact == ART_HO_OH_S_FEATHERS) || (uarms && uarms->oartifact == ART_SHATTERED_DREAMS) || (uarms && uarms->oartifact == ART_NO_FUTURE_BUT_AGONY) || (uarms && uarms->oartifact == ART_SYSTEMATIC_CHAOS) || (uleft && uleft->oartifact == ART_TASTY_TAME_NASTY) || (uright && uright->oartifact == ART_TASTY_TAME_NASTY) || (uarms && uarms->oartifact == ART_BONUS_HOLD) || (uarmf && uarmf->oartifact == ART_MANUELA_S_TORTURE_HEELS) || (uarmf && uarmf->oartifact == ART_WEAK_FROM_HUNGER) || (uarmf && uarmf->oartifact == ART_MANUELA_S_UNKNOWN_HEELS) || (uarmc && uarmc->oartifact == ART_NOW_IT_S_FOR_REAL) || (uarmf && uarmf->oartifact == ART_ALLYNONE) || (uarmh && uarmh->oartifact == ART_CERTAIN_SLOW_DEATH) || (uarm && uarm->oartifact == ART_QUEEN_ARTICUNO_S_HULL) || (uwep && uwep->oartifact == ART_PROVOCATEUR) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_PROVOCATEUR) || (uwep && uwep->oartifact == ART_CIVIL_WAR) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_CIVIL_WAR) || (uarmf && uarmf->oartifact == ART_FATALITY) || (uarmf && uarmf->oartifact == ART_FUN_ALL_IN_ONE) || (uleft && uleft->oartifact == ART_RING_OF_WOE) || (uright && uright->oartifact == ART_RING_OF_WOE))

#define Conflict		((IntConflict || ExtConflict) && !Is_blackmarket(&u.uz) )
/* Sorry guys and girls, but you need to find another way to clear out Sam's assistants. --Amy */
#define StrongConflict	(IntConflict && ExtConflict && Conflict)

/*** Transportation ***/
#define HJumping		u.uprops[JUMPING].intrinsic
#define EJumping		u.uprops[JUMPING].extrinsic
#define IntJumping	(HJumping || flags.iwbtg)
#define ExtJumping	(EJumping || (uwep && uwep->oartifact == ART_DIZZY_METAL_STORM) || (uarmc && uarmc->oartifact == ART_ROKKO_CHAN_S_SUIT) || (uarm && uarm->oartifact == ART_LUKE_S_JEDI_POWER) || (uarmf && uarmf->oartifact == ART_PRINCE_OF_PERSIA) || (uwep && uwep->oartifact == ART_SUPERGIRL_S_JUMP_AND_RUN_F) || (uamul && uamul->oartifact == ART_ONLY_ONE_ESCAPE) || u.uprops[MULTISHOES].extrinsic)

#define Jumping			(((IntJumping && u.nonintrinsicproperty != JUMPING) || (ExtJumping && u.nonextrinsicproperty != JUMPING)) && !NoJumping)
#define StrongJumping	(IntJumping && ExtJumping && Jumping && u.nondoubleproperty != JUMPING)

#define NoJumping	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_JUMPING].intrinsic || RngeAids || (u.impossibleproperty == JUMPING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HTeleportation		u.uprops[TELEPORT].intrinsic
#define ETeleportation		u.uprops[TELEPORT].extrinsic
#define IntTeleportation	(HTeleportation || can_teleport(youmonst.data) || Race_if(PM_MAIA) || Race_if(PM_HUMANOID_LEPRECHAUN))
#define ExtTeleportation	(ETeleportation || (uarmh && uarmh->oartifact == ART_GO_OTHER_PLACE) || (uarmg && uarmg->oartifact == ART_OUT_OF_CONTROL) || (uarmh && uarmh->oartifact == ART_DOUBLE_JEOPARDY) || (uarms && uarms->oartifact == ART_REFLECTOR_EJECTOR) || (uwep && uwep->otyp == POKER_STICK) || (uarmf && uarmf->oartifact == ART_ERROR_IN_PLAY_ENCHANTMENT) || (uimplant && uimplant->oartifact == ART_ARABELLA_S_SEXY_CHARM) || (uleft && uleft->oartifact == ART_HENRIETTA_S_MAGICAL_AID) || (uright && uright->oartifact == ART_HENRIETTA_S_MAGICAL_AID) || (uleft && uleft->oartifact == ART_BELKAR_S_WARPOPORTATION) || (uright && uright->oartifact == ART_BELKAR_S_WARPOPORTATION) || (uimplant && uimplant->oartifact == ART_POTATOROK) || (uarmu && uarmu->oartifact == ART_LEPRE_LUCK) || (uwep && uwep->oartifact == ART_NEX_XUS) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_NEX_XUS) || (uarmc && uarmc->oartifact == ART_SECANT_WHERELOCATION) || (uarmh && uarmh->oartifact == ART_RANDOMNESS_PREVAILS) || (uleft && uleft->oartifact == ART_GOLDENIVY_S_RAGE) || (uright && uright->oartifact == ART_GOLDENIVY_S_RAGE) || (uleft && uleft->oartifact == ART_GOLDENIVY_S_ENGAGEMENT_RIN) || (uright && uright->oartifact == ART_GOLDENIVY_S_ENGAGEMENT_RIN) || (uleft && uleft->oartifact == ART_WARPCHANGE) || (uright && uright->oartifact == ART_WARPCHANGE) || (uamul && uamul->oartifact == ART_SPACE_CYCLE))

#define Teleportation		(IntTeleportation || ExtTeleportation)
#define StrongTeleportation	(IntTeleportation && ExtTeleportation && Teleportation)

#define HTeleport_control	u.uprops[TELEPORT_CONTROL].intrinsic
#define ETeleport_control	u.uprops[TELEPORT_CONTROL].extrinsic
#define IntTeleport_control	(HTeleport_control || control_teleport(youmonst.data))
#define ExtTeleport_control	(ETeleport_control || (powerfulimplants() && uimplant && uimplant->oartifact == ART_ARABELLA_S_SEXY_CHARM) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == TELEPORT_CONTROL) ) )

#define Teleport_control	(((IntTeleport_control && u.nonintrinsicproperty != TELEPORT_CONTROL) || (ExtTeleport_control && u.nonextrinsicproperty != TELEPORT_CONTROL)) && !Race_if(PM_MAIA) && !(u.uprops[STORM_HELM].extrinsic) && !Race_if(PM_HUMANOID_LEPRECHAUN) && !NoTeleport_control)
#define StrongTeleport_control	(IntTeleport_control && ExtTeleport_control && Teleport_control && u.nondoubleproperty != TELEPORT_CONTROL)

#define NoTeleport_control	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_TELEPORT_CONTROL].intrinsic || RngeAids || (uarmc && uarmc->oartifact == ART_A_REASON_TO_LIVE) || In_mainframe(&u.uz) || In_bellcaves(&u.uz) || In_forging(&u.uz) || In_ordered(&u.uz) || In_deadground(&u.uz) || (uimplant && uimplant->oartifact == ART_POTATOROK && !(powerfulimplants()) ) || (uleft && uleft->oartifact == ART_HENRIETTA_S_MAGICAL_AID) || (uright && uright->oartifact == ART_HENRIETTA_S_MAGICAL_AID) || (uarmh && uarmh->oartifact == ART_RANDOMNESS_PREVAILS) || (u.impossibleproperty == TELEPORT_CONTROL) || (uarmg && uarmg->oartifact == ART_OUT_OF_CONTROL) || (uwep && uwep->otyp == POKER_STICK) || (uarmg && uarmg->oartifact == ART_ARABELLA_S_GREAT_BANISHER) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HLevitation		u.uprops[LEVITATION].intrinsic
#define ELevitation		u.uprops[LEVITATION].extrinsic
#define IntLevitation	(HLevitation || Race_if(PM_LEVITATOR) || (is_floater(youmonst.data) && !Race_if(PM_TRANSFORMER)) )
#define ExtLevitation	(ELevitation || (uleft && uleft->oartifact == ART_FLOAT_EYELER_S_CONDITION) || (uright && uright->oartifact == ART_FLOAT_EYELER_S_CONDITION) || (uwep && uwep->oartifact == ART_IRON_BALL_OF_LEVITATION) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_IRON_BALL_OF_LEVITATION) || u.uprops[MULTISHOES].extrinsic)

#define Levitation		(IntLevitation || ExtLevitation)
	/* Can't touch surface, can't go under water; overrides all others */
#define Lev_at_will		(!Race_if(PM_LEVITATOR) && ((HLevitation & I_SPECIAL) != 0L || \
				 (ELevitation & W_ARTI) != 0L) && \
				 (HLevitation & ~(I_SPECIAL|TIMEOUT)) == 0L && \
				 (ELevitation & ~W_ARTI) == 0L && \
				 (!is_floater(youmonst.data) || Race_if(PM_TRANSFORMER) ) )
#define StrongLevitation	(IntLevitation && ExtLevitation && Levitation)

#define HFlying			u.uprops[FLYING].intrinsic
#define EFlying			u.uprops[FLYING].extrinsic
#define IntFlying	(HFlying || (Race_if(PM_DUTHOL) && u.usteed) || (Race_if(PM_MOON_ELF) && flags.moonphase == FULL_MOON) || is_flyer(youmonst.data) || (is_floater(youmonst.data) && Race_if(PM_TRANSFORMER) ) || (u.usteed && is_flyer(u.usteed->data)) )
#define ExtFlying	(EFlying || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == FLYING) ) || (uwep && uwep->oartifact == ART_PENGUIN_S_THRUSTING_SWORD) || (uleft && uleft->oartifact == ART_JANA_S_DIMINISHER) || (uright && uright->oartifact == ART_JANA_S_DIMINISHER) || (uarm && uarm->oartifact == ART_FLY_LIKE_AN_EAGLE) || (uarmc && uarmc->oartifact == ART_FULL_WINGS) || (uarmc && uarmc->oartifact == ART_DARK_ANGELS) || (uarmc && uarmc->oartifact == ART_FAILSET_GAMBLE) || (uarms && uarms->oartifact == ART_I_IN_THE_SKY) || (uarmf && uarmf->oartifact == ART_MEPHISTO_S_BROGUES) || (uarmf && uarmf->oartifact == ART_CORINA_S_UNFAIR_SCRATCHER) || (uleft && uleft->oartifact == ART_GOLDENIVY_S_RAGE) || (uright && uright->oartifact == ART_GOLDENIVY_S_RAGE) || (uarmh && uarmh->oartifact == ART_GIRLFUL_FARTING_NOISES) || (uleft && uleft->oartifact == ART_GOLDENIVY_S_ENGAGEMENT_RIN) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_JANA_S_MAKE_UP_PUTTY) || (uarmc && uarmc->oartifact == ART_JANA_S_FAIRNESS_CUP) || (uright && uright->oartifact == ART_GOLDENIVY_S_ENGAGEMENT_RIN) || (uamul && uamul->oartifact == ART_STINGING_MEDALLION) || (uwep && uwep->oartifact == ART_SOURCE_CODES_OF_WORK_AVOID) || (uarmf && uarmf->oartifact == ART_RUTH_S_MORTAL_ENEMY) || (uamul && uamul->oartifact == ART_DIKKIN_S_DRAGON_TEETH) || (uarmg && uarmg->oartifact == ART_EXPERTENGAME_THE_ENTIRE_LE) || (uarmf && uarmf->oartifact == ART_EQUIPPED_FOR_TROUBLE) || (uarmg && uarmg->oartifact == ART_DIFFICULTY__) || (uarmf && uarmf->oartifact == ART_GRENEUVENIA_S_HUG) || (uarmh && uarmh->oartifact == ART_FLUE_FLUE_FLUEFLUE_FLUE) || (Role_if(PM_TOPMODEL) && PlayerInHighHeels) )

#define Flying			(((IntFlying && u.nonintrinsicproperty != FLYING) || (ExtFlying && u.nonextrinsicproperty != FLYING)) && !(uarm && uarm->oartifact == ART_WATER_SHYNESS) && !NoFlying && !(Role_if(PM_TOPMODEL) && flags.female && !PlayerInHighHeels) )
#define StrongFlying	(IntFlying && ExtFlying && Flying && u.nondoubleproperty != FLYING)

#define NoFlying	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FLYING].intrinsic || (Race_if(PM_NEMESIS) && uarmc) || RngeAids || (uarmc && uarmc->oartifact == ART_BROKEN_WINGS) || (uarmf && itemhasappearance(uarmf, APP_WEIGHT_ATTACHMENT_BOOTS)) || (uarmc && uarmc->oartifact == ART_GROUNDBUMMER) || (u.impossibleproperty == FLYING) || (uarm && uarm->oartifact == ART_ARMOR_OF_EREBOR) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

	/* May touch surface; does not override any others */

#define Wwalking		( (u.uprops[WWALKING].extrinsic || u.uprops[MULTISHOES].extrinsic) && \
				 !Is_waterlevel(&u.uz))
	/* Don't get wet, can't go under water; overrides others except levitation */
	/* Wwalking is meaningless on water level */

#define HSwimming		u.uprops[SWIMMING].intrinsic
#define ESwimming		u.uprops[SWIMMING].extrinsic	/* [Tom] */
#define IntSwimming	(HSwimming || tech_inuse(T_SILENT_OCEAN) || is_swimmer(youmonst.data) || (u.usteed && is_swimmer(u.usteed->data)) )
#define ExtSwimming	(ESwimming || (uwep && uwep->oartifact == ART_QUICKER_RHEOLOGY) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SWIMMING) ) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_SIGNIFICANT_RNG_JITTER) || (uwep && uwep->oartifact == ART_ETRUSCIAN_SWIMMING_LESSON) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_NEWFOUND_AND_USEFUL) || (uarmc && uarmc->oartifact == ART_WATERFORCE____) || (uarmc && uarmc->oartifact == ART_LAURA_S_SWIMSUIT) || (uwep && uwep->oartifact == ART_TRIDENT_OF_POSEIDON) || (uarmc && uarmc->oartifact == ART_WATERS_OF_OBLIVION) || (uarmf && uarmf->oartifact == ART_SANDRA_S_BEAUTIFUL_FOOTWEA) || (uarmu && uarmu->oartifact == ART_THERMAL_BATH) )

# define Swimming		((IntSwimming || ExtSwimming) && !(uarmf && itemhasappearance(uarmf, APP_FLIPFLOPS) ) && !(uarm && uarm->oartifact == ART_WATER_SHYNESS) )
	/* Get wet, don't go under water unless if amphibious */
#define StrongSwimming	(IntSwimming && ExtSwimming && Swimming)

/* amphibious is special-cased because breathless != amphibious --Amy */
#define HMagical_breathing	u.uprops[MAGICAL_BREATHING].intrinsic
#define EMagical_breathing	u.uprops[MAGICAL_BREATHING].extrinsic
#define IntMagical_breathing	(HMagical_breathing || tech_inuse(T_SILENT_OCEAN) || (Race_if(PM_MOON_ELF) && flags.moonphase == NEW_MOON) || amphibious(youmonst.data) || breathless(youmonst.data) )
#define ExtMagical_breathing	(EMagical_breathing || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == MAGICAL_BREATHING) ) || (uarmh && uarmh->oartifact == ART_SHPX_GUVF_FUVG) || (Role_if(PM_ANACHRONIST) && uwep && uwep->oartifact == ART_ANACHRONONONONAUT_PACKAGE) || (uarm && uarm->oartifact == ART_INCREDIBLY_SEXY_SQUEAKING) || (uarmf && uarmf->oartifact == ART_HERMES__UNFAIRNESS) || (uarmf && uarmf->oartifact == ART_HADES_THE_MEANIE) || (uarmc && uarmc->oartifact == ART_WATERFORCE____) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_JANA_S_MAKE_UP_PUTTY) || (uleft && uleft->oartifact == ART_JANA_S_DIMINISHER) || (uright && uright->oartifact == ART_JANA_S_DIMINISHER) || (uarmc && uarmc->oartifact == ART_JANA_S_SECRET_CAR) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_NEWFOUND_AND_USEFUL) || (uarmc && uarmc->oartifact == ART_JANA_S_GRAVE_WALL) || (uarm && uarm->oartifact == ART_ROCKET_IMPULSE) || (uwep && uwep->oartifact == ART_TRIDENT_OF_POSEIDON) || (uarmh && uarmh->oartifact == ART_VACUUM_CLEANER_DEATH) || (uarmc && uarmc->oartifact == ART_LAURA_S_SWIMSUIT) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_SIGNIFICANT_RNG_JITTER) || (uarmf && uarmf->oartifact == ART_JANA_S_VAGINAL_FUN) || (uarmf && uarmf->oartifact == ART_SHORTFALL) || (uarmf && uarmf->oartifact == ART_SANDRA_S_BEAUTIFUL_FOOTWEA) || (uarmf && uarmf->oartifact == ART_FUN_ALL_IN_ONE) || (uarmf && uarmf->oartifact == ART_ALLYNONE) || (Role_if(PM_TOPMODEL) && PlayerInHighHeels) )

/* like IntMagical_breathing but without the breathless case */
#define AmphibiousMagical_breathing	((HMagical_breathing && u.nonintrinsicproperty != MAGICAL_BREATHING) || tech_inuse(T_SILENT_OCEAN) || (Race_if(PM_MOON_ELF) && flags.moonphase == NEW_MOON) || amphibious(youmonst.data) )

#define Amphibious		(AmphibiousMagical_breathing && u.nonintrinsicproperty != MAGICAL_BREATHING && !NoBreathless)
	/* Get wet, may go under surface */

#define Breathless		(((IntMagical_breathing && u.nonintrinsicproperty != MAGICAL_BREATHING) || (ExtMagical_breathing && u.nonextrinsicproperty != MAGICAL_BREATHING)) && !Role_if(PM_FJORDE) && !NoBreathless && !(Role_if(PM_TOPMODEL) && flags.female && !PlayerInHighHeels) )
#define StrongMagical_breathing	(IntMagical_breathing && ExtMagical_breathing && (Breathless || Amphibious) && u.nondoubleproperty != MAGICAL_BREATHING)

#define NoBreathless	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_MAGICAL_BREATHING].intrinsic || RngeAids || (u.impossibleproperty == MAGICAL_BREATHING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define Underwater		(u.uinwater)
/* Note that Underwater and u.uinwater are both used in code.
   The latter form is for later implementation of other in-water
   states, like swimming, wading, etc. */

#define HPasses_walls		u.uprops[PASSES_WALLS].intrinsic
#define EPasses_walls		u.uprops[PASSES_WALLS].extrinsic
#define IntPasses_walls	(HPasses_walls || passes_walls(youmonst.data))
#define ExtPasses_walls	(EPasses_walls || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == PASSES_WALLS) ) )

#define Passes_walls		(((IntPasses_walls && u.nonintrinsicproperty != PASSES_WALLS) || (ExtPasses_walls && u.nonextrinsicproperty != PASSES_WALLS)) && !NoPasses_walls)
#define Phasing            u.uprops[PASSES_WALLS].intrinsic
#define StrongPasses_walls	(IntPasses_walls && ExtPasses_walls && Passes_walls && u.nondoubleproperty != PASSES_WALLS)

#define NoPasses_walls	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_PASSES_WALLS].intrinsic || RngeAids || (u.impossibleproperty == PASSES_WALLS) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))


/*** Physical attributes ***/
#define HSlow_digestion		u.uprops[SLOW_DIGESTION].intrinsic
#define ESlow_digestion		u.uprops[SLOW_DIGESTION].extrinsic
#define IntSlow_digestion	(HSlow_digestion)
#define ExtSlow_digestion	(ESlow_digestion || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SLOW_DIGESTION) ) || (uarmh && uarmh->oartifact == ART_NEVEREATER) || (uimplant && uimplant->oartifact == ART_BUCKET_HOUSE) || (uarmc && uarmc->oartifact == ART_FEMMY_FATALE) || (uarmh && uarmh->oartifact == ART_WOLF_KING) )

#define Slow_digestion		(((IntSlow_digestion && u.nonintrinsicproperty != SLOW_DIGESTION) || (ExtSlow_digestion && u.nonextrinsicproperty != SLOW_DIGESTION)) && !Race_if(PM_PERVERT) && !Race_if(PM_GIGANT) && !NoSlow_digestion)  /* KMH */
#define StrongSlow_digestion	(IntSlow_digestion && ExtSlow_digestion && Slow_digestion && u.nondoubleproperty != SLOW_DIGESTION)

#define NoSlow_digestion	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SLOW_DIGESTION].intrinsic || RngeAids || (u.impossibleproperty == SLOW_DIGESTION) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

/* Half spell/physical damage only works 50% of the time, so it's more like three quarter spell/physical damage. --Amy */

#define HHalf_spell_damage	u.uprops[HALF_SPDAM].intrinsic
#define EHalf_spell_damage	u.uprops[HALF_SPDAM].extrinsic
#define IntHalf_spell_damage	(HHalf_spell_damage || (Race_if(PM_BOVER) && u.usteed))
#define ExtHalf_spell_damage	(EHalf_spell_damage || (powerfulimplants() && uimplant && uimplant->oartifact == ART_WARY_PROTECTORATE) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_POTATOROK) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == HALF_SPDAM) ) )

#define Half_spell_damage	(((IntHalf_spell_damage && u.nonintrinsicproperty != HALF_SPDAM) || (ExtHalf_spell_damage && u.nonextrinsicproperty != HALF_SPDAM)) && !Race_if(PM_KUTAR) && !NoHalf_spell_damage)
#define StrongHalf_spell_damage	(IntHalf_spell_damage && ExtHalf_spell_damage && Half_spell_damage && u.nondoubleproperty != HALF_SPDAM)

#define NoHalf_spell_damage	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_HALF_SPDAM].intrinsic || RngeAids || (u.impossibleproperty == HALF_SPDAM) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HHalf_physical_damage	u.uprops[HALF_PHDAM].intrinsic
#define EHalf_physical_damage	u.uprops[HALF_PHDAM].extrinsic
#define IntHalf_physical_damage	(HHalf_physical_damage || (Race_if(PM_BOVER) && u.usteed))
#define ExtHalf_physical_damage	(EHalf_physical_damage || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == HALF_PHDAM) ) || (uwep && uwep->otyp == SECRET_WHIP) || (uwep && uwep->otyp == ETERNAL_POLE) || (uarmf && uarmf->oartifact == ART_HUGGING__GROPING_AND_STROK && u.ustuck) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_POTATOROK) || (uarmh && itemhasappearance(uarmh, APP_CLOUDY_HELMET) && isok(u.ux, u.uy) && IS_CLOUD(levl[u.ux][u.uy].typ) ) || (uarmc && (moves % 10 == 0) && itemhasappearance(uarmc, APP_SOFT_CLOAK) ) || (ublindf && ublindf->otyp == SOFT_CHASTITY_BELT) )

#define Half_physical_damage	(((IntHalf_physical_damage && u.nonintrinsicproperty != HALF_PHDAM) || (ExtHalf_physical_damage && u.nonextrinsicproperty != HALF_PHDAM)) && !NoHalf_physical_damage)
#define StrongHalf_physical_damage	(IntHalf_physical_damage && ExtHalf_physical_damage && Half_physical_damage && u.nondoubleproperty != HALF_PHDAM)

#define NoHalf_physical_damage	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_HALF_PHDAM].intrinsic || RngeAids || (u.impossibleproperty == HALF_PHDAM) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define Second_chance		u.uprops[SECOND_CHANCE].extrinsic

#define HRegeneration		u.uprops[REGENERATION].intrinsic
#define ERegeneration		u.uprops[REGENERATION].extrinsic
#define IntRegeneration	(HRegeneration || regenerates(youmonst.data))
#define ExtRegeneration	(ERegeneration || (uimplant && uimplant->oartifact == ART_SIGNIFICANT_RNG_JITTER) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == REGENERATION) ) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_THEY_RE_ALL_YELLOW) || (uarmf && uarmf->oartifact == ART_ERROR_IN_PLAY_ENCHANTMENT) )

#define Regeneration		(((IntRegeneration && u.nonintrinsicproperty != REGENERATION) || (ExtRegeneration && u.nonextrinsicproperty != REGENERATION)) && !NoRegeneration && !Race_if(PM_SYLPH) )
#define StrongRegeneration	(IntRegeneration && ExtRegeneration && Regeneration && u.nondoubleproperty != REGENERATION)

#define NoRegeneration	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_REGENERATION].intrinsic || RngeAids || (u.impossibleproperty == REGENERATION) || (uimplant && uimplant->oartifact == ART_RESTROOM_DRENCHING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HEnergy_regeneration	u.uprops[ENERGY_REGENERATION].intrinsic
#define EEnergy_regeneration	u.uprops[ENERGY_REGENERATION].extrinsic
#define IntEnergy_regeneration	(HEnergy_regeneration || (Race_if(PM_REDGUARD)) )
#define ExtEnergy_regeneration	(EEnergy_regeneration || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == ENERGY_REGENERATION) ) )

#define Energy_regeneration	(((IntEnergy_regeneration && u.nonintrinsicproperty != ENERGY_REGENERATION) || (ExtEnergy_regeneration && u.nonextrinsicproperty != ENERGY_REGENERATION)) && !NoEnergy_regeneration && !Race_if(PM_SYLPH) )
#define StrongEnergy_regeneration	(IntEnergy_regeneration && ExtEnergy_regeneration && Energy_regeneration && u.nondoubleproperty != ENERGY_REGENERATION)

#define NoEnergy_regeneration	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_ENERGY_REGENERATION].intrinsic || RngeAids || (u.impossibleproperty == ENERGY_REGENERATION) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HProtection		u.uprops[PROTECTION].intrinsic
#define EProtection		u.uprops[PROTECTION].extrinsic
#define Protection		(HProtection || EProtection)

#define HProtection_from_shape_changers \
				u.uprops[PROT_FROM_SHAPE_CHANGERS].intrinsic
#define EProtection_from_shape_changers \
				u.uprops[PROT_FROM_SHAPE_CHANGERS].extrinsic
#define Protection_from_shape_changers \
				(HProtection_from_shape_changers || \
				 EProtection_from_shape_changers)

#define HPolymorph		u.uprops[POLYMORPH].intrinsic
#define EPolymorph		u.uprops[POLYMORPH].extrinsic
#define IntPolymorph	(HPolymorph || Race_if(PM_MOULD) || Race_if(PM_PLAYER_MIMIC) || Race_if(PM_TRANSFORMER) || Race_if(PM_WORM_THAT_WALKS) || Race_if(PM_MISSINGNO) || Race_if(PM_WARPER) || Race_if(PM_UNGENOMOLD) || Race_if(PM_DEATHMOLD))
#define ExtPolymorph	(EPolymorph || ((moves % 10 == 0) && uarmc && itemhasappearance(uarmc, APP_CHANGING_CLOAK) ) || (uimplant && uimplant->oartifact == ART_SIGNIFICANT_RNG_JITTER) || (uleft && uleft->oartifact == ART_BELKAR_S_WARPOPORTATION) || (uright && uright->oartifact == ART_BELKAR_S_WARPOPORTATION) || (uarmf && uarmf->oartifact == ART_MALENA_S_LADYNESS) || (uarmf && uarmf->oartifact == ART_NOSE_ENCHANTMENT) || (uarmh && uarmh->oartifact == ART_RANDOMNESS_PREVAILS) || (uarmh && uarmh->oartifact == ART_DOUBLE_JEOPARDY) || (uarmf && uarmf->oartifact == ART_ERROR_IN_PLAY_ENCHANTMENT) || (uleft && uleft->oartifact == ART_SEMI_SHAPE_CONTROL) || (uarmc && uarmc->oartifact == ART_SHAPETAKE_NUMBER_FIVE) || (uright && uright->oartifact == ART_SEMI_SHAPE_CONTROL) || (uamul && uamul->oartifact == ART_SPACE_CYCLE) )

#define Polymorph		(IntPolymorph || ExtPolymorph)
#define StrongPolymorph	(IntPolymorph && ExtPolymorph && Polymorph)

#define HPolymorph_control	u.uprops[POLYMORPH_CONTROL].intrinsic
#define EPolymorph_control	u.uprops[POLYMORPH_CONTROL].extrinsic
#define IntPolymorph_control	(HPolymorph_control)
#define ExtPolymorph_control	(EPolymorph_control || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == POLYMORPH_CONTROL) ) || (uarmu && uarmu->oartifact == ART_VICTORIA_IS_EVIL_BUT_PRETT) || (uarmu && uarmu->oartifact == ART_NATALIA_IS_LOVELY_BUT_DANG) || (uleft && uleft->oartifact == ART_HYPOCRITICAL_FUN) || (uright && uright->oartifact == ART_HYPOCRITICAL_FUN) || (uwep && uwep->oartifact == ART_UNICORN_DRILL) || (uarmf && uarmf->oartifact == ART_MALENA_S_LADYNESS) || (uimplant && uimplant->oartifact == ART_YES_YOU_CAN) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_SIGNIFICANT_RNG_JITTER) || (uarmh && uarmh->oartifact == ART_DICTATORSHIP) )

#define Polymorph_control	(((IntPolymorph_control && u.nonintrinsicproperty != POLYMORPH_CONTROL) || (ExtPolymorph_control && u.nonextrinsicproperty != POLYMORPH_CONTROL)) && !Race_if(PM_MOULD) && !NoPolymorph_control && !Race_if(PM_TRANSFORMER) && !Race_if(PM_POLYINITOR) && !Race_if(PM_DESTABILIZER) && !Race_if(PM_WORM_THAT_WALKS) && !Race_if(PM_WARPER) && !Race_if(PM_MISSINGNO) && !Race_if(PM_UNGENOMOLD) && !Race_if(PM_DEATHMOLD) && !Race_if(PM_AK_THIEF_IS_DEAD_))
#define StrongPolymorph_control	(IntPolymorph_control && ExtPolymorph_control && Polymorph_control && u.nondoubleproperty != POLYMORPH_CONTROL)

#define NoPolymorph_control	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_POLYMORPH_CONTROL].intrinsic || RngeAids || (uarmc && uarmc->oartifact == ART_PERMANENTITIS) || (uarmc && uarmc->oartifact == ART_SHAPETAKE_NUMBER_FIVE) || (u.impossibleproperty == POLYMORPH_CONTROL) || (uarmh && uarmh->oartifact == ART_RANDOMNESS_PREVAILS) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HUnchanging		u.uprops[UNCHANGING].intrinsic
#define EUnchanging		u.uprops[UNCHANGING].extrinsic
#define Unchanging		((HUnchanging || EUnchanging || (uleft && uleft->oartifact == ART_NENYA) || (uright && uright->oartifact == ART_NENYA)) && !(uarmc && uarmc->oartifact == ART_SHAPETAKE_NUMBER_FIVE) && !Race_if(PM_MOULD) && !Race_if(PM_MISSINGNO) && !Race_if(PM_TRANSFORMER) && !Race_if(PM_POLYINITOR) && !Race_if(PM_DESTABILIZER) && !Race_if(PM_WORM_THAT_WALKS) && !Race_if(PM_WARPER) && !Race_if(PM_UNGENOMOLD) && !Race_if(PM_DEATHMOLD) && !Race_if(PM_AK_THIEF_IS_DEAD_))	/* KMH */

#define HFast			u.uprops[FAST].intrinsic
#define EFast			u.uprops[FAST].extrinsic
#define IntFast	(HFast)
#define ExtFast	(EFast || (HFast & ~INTRINSIC) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == FAST) ) || (uwep && uwep->oartifact == ART_FUMATA_YARI) || (uwep && uwep->oartifact == ART_INGRAM_MAC___) || (uarmc && uarmc->oartifact == ART_SPEEDRUNNER_S_DREAM) || (uarmh && uarmh->oartifact == ART_ELONA_S_SNAIL_TRAIL && Race_if(PM_ELONA_SNAIL)) || (uarmh && uarmh->oartifact == ART_REAL_SPEED_DEVIL) || (uarmc && uarmc->oartifact == ART_ROKKO_CHAN_S_SUIT) || (uwep && uwep->oartifact == ART_QUICKER_RHEOLOGY) || (uwep && uwep->oartifact == ART_EAMANE_LUINWE) || (uarmc && uarmc->oartifact == ART_FULLY_LIONIZED) || (uarmh && uarmh->oartifact == ART_LORSKEL_S_SPEED) || (uarmc && uarmc->oartifact == ART_JANA_S_FAIRNESS_CUP) || (uimplant && uimplant->oartifact == ART_KATRIN_S_SUDDEN_APPEARANCE) || (uarmc && uarmc->oartifact == ART_FAST_CAMO_PREDATOR) || (uarmh && uarmh->oartifact == ART_ELESSAR_ELENDIL) || (uamul && uamul->oartifact == ART_ANASTASIA_S_LURE) || (uarmf && uarmf->oartifact == ART_UNTRAINED_HALF_MARATHON) || (uleft && uleft->oartifact == ART_REQUIRED_GLADNESS) || (uwep && uwep->otyp == WIND_BOW) || (uarmf && uarmf->oartifact == ART_VRRRRRRRRRRRR) || (uarmc && uarmc->oartifact == ART_KANGAROO_SNORT) || (uarmc && uarmc->oartifact == ART_FAST_SPEED_BUMP) || (uarmh && uarmh->oartifact == ART_DUE_DUE_DUE_DUE_BRMMMMMMM) || (uarmf && uarmf->oartifact == ART_UNEVEN_ENGINE) || (uwep && uwep->oartifact == ART_FEANARO_SINGOLLO) || (uarm && uarm->oartifact == ART_ROCKET_IMPULSE) || (uarmc && uarmc->oartifact == ART_LIGHTSPEED_TRAVEL) || (uright && uright->oartifact == ART_REQUIRED_GLADNESS) || (uarmf && uarmf->oartifact == ART_HIGH_DESIRE_OF_FATALITY) || (uwep && uwep->oartifact == ART_SPEEDHACK) || (uarmc && uarmc->oartifact == ART_JANA_S_SECRET_CAR) || (uamul && uamul->oartifact == ART_ARABELLA_S_DICINATOR) || (uarmc && uarmc->oartifact == ART_JANA_S_GRAVE_WALL) || (uleft && uleft->oartifact == ART_CRIMINAL_QUEEN) || (uright && uright->oartifact == ART_CRIMINAL_QUEEN) || (uwep && uwep->oartifact == ART_TENSA_ZANGETSU) || (uwep && uwep->oartifact == ART_TARMAC_CHAMPION) || (uwep && uwep->oartifact == ART_ZANKAI_HUNG_ZE_TUNG_DO_HAI) || (uwep && uwep->oartifact == ART_GARNET_ROD) || (uwep && uwep->oartifact == ART_THREE_HEADED_FLAIL) || u.uprops[MULTISHOES].extrinsic || (Role_if(PM_TRANSVESTITE) && PlayerInHighHeels) || (Role_if(PM_TOPMODEL) && PlayerInHighHeels) )

#define Fast			(((IntFast && !(Race_if(PM_NEMESIS) && uarmf) && u.nonintrinsicproperty != FAST) || (ExtFast && u.nonextrinsicproperty != FAST)) && !NoFast && !Race_if(PM_DEVELOPER) && !(uleft && uleft->oartifact == ART_CORGON_S_RING) && !(uright && uright->oartifact == ART_CORGON_S_RING) && !(uarmf && uarmf->oartifact == ART_IMPOSSIBLE_CATWALK) && !Race_if(PM_ITAQUE) && !(Race_if(PM_BOVER) && u.usteed) && !Race_if(PM_MONGUNG) && !HardcoreAlienMode && (!Role_if(PM_TRANSVESTITE) || flags.female) && (!Role_if(PM_TOPMODEL) || !flags.female) )

#define Very_fast		((ExtFast && u.nonextrinsicproperty != FAST) && !Race_if(PM_DEVELOPER) && !(uleft && uleft->oartifact == ART_CORGON_S_RING) && !(uright && uright->oartifact == ART_CORGON_S_RING) && !(uarmf && uarmf->oartifact == ART_IMPOSSIBLE_CATWALK) && !Race_if(PM_ITAQUE) && !(Race_if(PM_BOVER) && u.usteed) && !Race_if(PM_MONGUNG) && !HardcoreAlienMode && !NoFast && !(Role_if(PM_TRANSVESTITE) && !flags.female && !PlayerInHighHeels) && !(Role_if(PM_TOPMODEL) && flags.female && !PlayerInHighHeels) )
#define StrongFast	(IntFast && ExtFast && Fast && u.nondoubleproperty != FAST)

#define NoFast	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FAST].intrinsic || RngeAids || (u.impossibleproperty == FAST) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HReflecting		u.uprops[REFLECTING].intrinsic
#define EReflecting		u.uprops[REFLECTING].extrinsic
#define IntReflecting	(HReflecting || tech_inuse(T_POWERFUL_AURA) || (is_reflector(youmonst.data)) )
#define ExtReflecting	(EReflecting || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == REFLECTING) ) || (moves % 2 == 0 && (uarm && itemhasappearance(uarm, APP_OCTARINE_ROBE)) ) || (moves % 3 == 0 && uarmf && itemhasappearance(uarmf, APP_REFLECTIVE_SLIPPERS)) || (uarmu && uarmu->oartifact == ART_LEGENDARY_SHIRT) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_SLEX_WANTS_YOU_TO_DIE_A_PA) || (uarm && uarm->oartifact == ART_VOLUME_ARMAMENT) || (uarm && uarm->oartifact == ART_DON_SUICUNE_DOES_NOT_APPRO) || (uwep && uwep->otyp == BEAM_REFLECTOR_GUN) || (ublindf && ublindf->otyp == DRAGON_EYEPATCH) || (uarmc && uarmc->oartifact == ART_A_REASON_TO_LIVE) || (uarmc && uarmc->oartifact == ART_ALL_IN_ONE_ASCENSION_KIT) || (uarmc && uarmc->oartifact == ART_RNG_S_GAMBLE) || (uarmh && uarmh->oartifact == ART_YOU_ARE_ALREADY_DEAD) || (uarmg && uarmg->oartifact == ART_PLUG_AND_PRAY) || (uarmg && uarmg->oartifact == ART_IRIS_S_PRECIOUS_METAL) || (uarmg && uarmg->oartifact == ART_SEALED_KNOWLEDGE) || (uarmg && uarmg->oartifact == ART_UNOBTAINABLE_BEAUTIES) )

#define Reflecting		(((IntReflecting && u.nonintrinsicproperty != REFLECTING) || (ExtReflecting && u.nonextrinsicproperty != REFLECTING)) && !NoReflecting && !(uarmc && itemhasappearance(uarmc, APP_ANGBAND_CLOAK)) && !Race_if(PM_ANGBANDER) && !RngeAngband )
#define StrongReflecting	(IntReflecting && ExtReflecting && Reflecting && u.nondoubleproperty != REFLECTING)

#define NoReflecting	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_REFLECTING].intrinsic || RngeAids || (uarm && uarm->oartifact == ART_ARMOR_OF_EREBOR && (moves % 4 == 0) ) || (u.impossibleproperty == REFLECTING) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HFree_action	u.uprops[FREE_ACTION].intrinsic
#define EFree_action	u.uprops[FREE_ACTION].extrinsic
#define IntFree_action	(HFree_action || FemtrapActiveNatalje)
#define ExtFree_action	(EFree_action || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == FREE_ACTION) ) || (uwep && uwep->oartifact == ART_KARATE_KID) || (uarmu && uarmu->oartifact == ART_PEACE_ADVOCATE) || (uarm && uarm->oartifact == ART_LITTLE_BIG_MIDGET) || (uarmf && uarmf->oartifact == ART_KRISTIN_S_CHEATS) || (uarmh && uarmh->oartifact == ART_LOW_LOCAL_MEMORY) || (uarmf && uarmf->oartifact == ART_IMPOSSIBLE_CATWALK) || (uimplant && uimplant->oartifact == ART_NEWFOUND_AND_USEFUL) || (uimplant && uimplant->oartifact == ART_CAN_T_BRING_US_DOWN) || (uarmf && uarmf->oartifact == ART_KHOR_S_REQUIRED_IDEA) || (uwep && uwep->oartifact == ART_MEANCANE) || (uwep && uwep->oartifact == ART_PERNICIOUS_GRID) || (uarmc && uarmc->oartifact == ART_NOUROFIBROMA) || (uarmh && uarmh->oartifact == ART_LLLLLLLLLLLLLM) || (uarm && uarm->oartifact == ART_CHECK_YOUR_ESCAPES) || (uarms && uarms->oartifact == ART_LURTZ_S_WALL) || (uarms && uarms->oartifact == ART_BRASS_GUARD) || (uarmf && uarmf->oartifact == ART_ANASTASIA_S_GENTLENESS) || (uamul && uamul->oartifact == ART_MOSH_PIT_SCRAMBLE) || (uarms && uarms->oartifact == ART_I_M_GETTING_HUNGRY) || (uarm && uarm->oartifact == ART_ESSENTIALITY_EXTREME) || (uarmg && uarmg->oartifact == ART_STOUT_IMMURRING) || (uarmg && uarmg->oartifact == ART_FREE_ACTION_CALLED_FREE_AC) || (uarmc && uarmc->oartifact == ART_PREDATORY_STABILITY) || (uwep && uwep->oartifact == ART_IMMOBILASER) || (uarmf && uarmf->oartifact == ART_FREE_FOR_ENOUGH) || (uarmf && uarmf->oartifact == ART_MANDY_S_ROUGH_BEAUTY) || (uarmf && uarmf->oartifact == ART_WAITING_TIMEOUT) || (uamul && uamul->oartifact == ART_BALLSY_BASTARD) || tech_inuse(T_POWERFUL_AURA) || (uamul && uamul->oartifact == ART___TH_NAZGUL) || (uamul && uamul->oartifact == ART_NAZGUL_S_REVENGE) || (uwep && uwep->oartifact == ART_SOURCE_CODES_OF_WORK_AVOID) )

#define Free_action		(((IntFree_action && u.nonintrinsicproperty != FREE_ACTION) || (ExtFree_action && u.nonextrinsicproperty != FREE_ACTION)) && !NoFree_action) /* [Tom] */
#define StrongFree_action	(IntFree_action && ExtFree_action && Free_action && u.nondoubleproperty != FREE_ACTION)

#define NoFree_action	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FREE_ACTION].intrinsic || RngeAids || (u.impossibleproperty == FREE_ACTION) || (uimplant && uimplant->oartifact == ART_KATRIN_S_SUDDEN_APPEARANCE) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

/* Sustain ability */
#define Fixed_abil		u.uprops[FIXED_ABIL].extrinsic	/* KMH */
#define SustainAbilityOn	(Fixed_abil || Race_if(PM_SUSTAINER) || (uarmh && uarmh->oartifact == ART_SLIPPING_SUCKING) || (uarms && uarms->oartifact == ART_SYSTEMATIC_CHAOS) || (uarms && uarms->oartifact == ART_NO_REDUCTION_ALLOWED) || (uarms && uarms->oartifact == ART_BONUS_HOLD) || (uamul && uamul->oartifact == ART_FIX_EVERYTHING) || (uarmf && uarmf->oartifact == ART_ELENETTES))
/* note by Amy: unless you're the sustainer race, there's 10% chance that stat loss still happens, stat gain is disabled */
#define SustainLossSafe		(Race_if(PM_SUSTAINER) || rn2(10))

#define Lifesaved		u.uprops[LIFESAVED].extrinsic

#define HKeen_memory		u.uprops[KEEN_MEMORY].intrinsic
#define EKeen_memory		u.uprops[KEEN_MEMORY].extrinsic
#define IntKeen_memory	(HKeen_memory || (youmonst.data->mlet == S_QUADRUPED))
#define ExtKeen_memory	(EKeen_memory || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == KEEN_MEMORY) ) || (uarmu && uarmu->oartifact == ART_MEMORIAL_GARMENTS) || (uarmc && uarmc->oartifact == ART_MEMORY_AID) || (uarmc && uarmc->oartifact == ART_REMEMBERING_THE_BAD_TIMES) || (uarmf && uarmf->oartifact == ART_DESERT_MEDITATION) || (uarmh && uarmh->oartifact == ART_VERY_MEMORY) || (uarms && uarms->oartifact == ART_GOLDEN_DAWN) || (uimplant && uimplant->oartifact == ART_UNFORGETTABLE_EVENT) || (uarmh && uarmh->oartifact == ART_TRANSMEMORIZER) || (uamul && uamul->oartifact == ART_ARABELLA_S_DICINATOR) || (uarms && uarms->oartifact == ART_GREXIT_IS_NEAR) || (uamul && uamul->oartifact == ART_COMPUTER_AMULET) )

#define Keen_memory		(((IntKeen_memory && u.nonintrinsicproperty != KEEN_MEMORY) || (ExtKeen_memory && u.nonextrinsicproperty != KEEN_MEMORY)) && !NoKeen_memory)
#define StrongKeen_memory	(IntKeen_memory && ExtKeen_memory && Keen_memory && u.nondoubleproperty != KEEN_MEMORY)

#define NoKeen_memory	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_KEEN_MEMORY].intrinsic || RngeAids || (u.impossibleproperty == KEEN_MEMORY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HSight_bonus		u.uprops[SIGHT_BONUS].intrinsic
#define ESight_bonus		u.uprops[SIGHT_BONUS].extrinsic
#define IntSight_bonus	(HSight_bonus)
#define ExtSight_bonus	(ESight_bonus || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == SIGHT_BONUS) ) || (uwep && uwep->oartifact == ART_PEOPLE_EATING_TRIDENT) || (uwep && uwep->otyp == FIRE_STICK) || (uwep && uwep->otyp == ZOOM_SHOT_CROSSBOW) || (uarmc && uarmc->oartifact == ART_BILLS_PAID) || (uwep && uwep->oartifact == ART_HALLOW_MOONFALL) || (uwep && uwep->oartifact == ART_AXE_OF_THE_DWARVISH_LORDS) || (uarms && uarms->oartifact == ART_SOLAR_POWER) || (uamul && uamul->oartifact == ART_GOOD_BEE) || (uarmf && uarmf->oartifact == ART_GRENEUVENIA_S_HUG) || (uamul && uamul->oartifact == ART_BUEING) || (uarmh && uarmh->oartifact == ART_HAT_OF_THE_ARCHMAGI) )

#define Sight_bonus		(((IntSight_bonus && u.nonintrinsicproperty != SIGHT_BONUS) || (ExtSight_bonus && u.nonextrinsicproperty != SIGHT_BONUS)) && !NoSight_bonus)
#define StrongSight_bonus	(IntSight_bonus && ExtSight_bonus && Sight_bonus && u.nondoubleproperty != SIGHT_BONUS)

#define NoSight_bonus	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SIGHT_BONUS].intrinsic || RngeAids || (u.impossibleproperty == SIGHT_BONUS) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HVersus_curses		u.uprops[VERSUS_CURSES].intrinsic
#define EVersus_curses		u.uprops[VERSUS_CURSES].extrinsic
#define IntVersus_curses	(HVersus_curses)
#define ExtVersus_curses	(EVersus_curses || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == VERSUS_CURSES) ) || (uarmu && uarmu->oartifact == ART_MEMORIAL_GARMENTS) )

#define Versus_curses		(((IntVersus_curses && u.nonintrinsicproperty != VERSUS_CURSES) || (ExtVersus_curses && u.nonextrinsicproperty != VERSUS_CURSES)) && !NoVersus_curses)
#define StrongVersus_curses	(IntVersus_curses && ExtVersus_curses && Versus_curses && u.nondoubleproperty != VERSUS_CURSES)

#define NoVersus_curses	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_VERSUS_CURSES].intrinsic || RngeAids || (u.impossibleproperty == VERSUS_CURSES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HStun_resist		u.uprops[STUN_RES].intrinsic
#define EStun_resist		u.uprops[STUN_RES].extrinsic
#define IntStun_resist	(HStun_resist || Race_if(PM_EROSATOR) || tech_inuse(T_STAT_RESIST))
#define ExtStun_resist	(EStun_resist || (uarmf && uarmf->oartifact == ART_KRISTIN_S_CHEATS) || (uwep && uwep->oartifact == ART_DEATHWRECKER) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == STUN_RES) ) || (uarmu && uarmu->oartifact == ART_TOTAL_CONTROL) || (uwep && uwep->oartifact == ART_LAUGHTERSNEE) || (uwep && uwep->oartifact == ART_OGRESMASHER____) || (uarm && uarm->oartifact == ART_PROTECTION_WITH_A_PRICE) || (uleft && uleft->oartifact == ART_RELIABLE_TRINSICS) || (uright && uright->oartifact == ART_RELIABLE_TRINSICS) || (uwep && uwep->oartifact == ART_JOUSTER_POWER) || (uarmc && uarmc->oartifact == ART_FREQUENT_BUT_WEAK_STATUS) || (uarmh && uarmh->oartifact == ART_CLAUDIA_S_DIRECTION_FINDER) || (uarmh && uarmh->oartifact == ART_UBB_RUPTURE) || (uarmh && uarmh->oartifact == ART_MIND_SHIELDING) || (uarms && uarms->oartifact == ART_FIVE_STAR_PARTY) || (uamul && uamul->oartifact == ART_ONE_MOMENT_IN_TIME) || (uamul && uamul->oartifact == ART_PRECIOUS_UNOBTAINABLE_PROP) || (uamul && uamul->oartifact == ART_RECOVERED_RELIC) )

#define Stun_resist		(((IntStun_resist && u.nonintrinsicproperty != STUN_RES) || (ExtStun_resist && u.nonextrinsicproperty != STUN_RES)) && !hybridragontype(AD_LITE) && !NoStun_resist)
#define StrongStun_resist	(IntStun_resist && ExtStun_resist && Stun_resist && u.nondoubleproperty != STUN_RES)

#define NoStun_resist	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_STUN_RES].intrinsic || RngeAids || (u.impossibleproperty == STUN_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HConf_resist		u.uprops[CONF_RES].intrinsic
#define EConf_resist		u.uprops[CONF_RES].extrinsic
#define IntConf_resist	(HConf_resist || Race_if(PM_EROSATOR) || tech_inuse(T_STAT_RESIST) || FemtrapActiveClaudia )
#define ExtConf_resist	(EConf_resist || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == CONF_RES) ) || (uarmf && uarmf->oartifact == ART_BOOTS_OF_THE_MACHINE) || (uwep && uwep->oartifact == ART_LAUGHTERSNEE) || (uwep && uwep->oartifact == ART_OGRESMASHER____) || (uarmh && uarmh->oartifact == ART_CLAUDIA_S_DIRECTION_FINDER) || (uarmf && uarmf->oartifact == ART_UNFELLABLE_TREE && u.burrowed) || (uarmf && uarmf->oartifact == ART_SANDRA_S_BEAUTIFUL_FOOTWEA) || (uarmf && uarmf->oartifact == ART_SARAH_S_GRANNY_WEAR) || (uarms && uarms->oartifact == ART_FIVE_STAR_PARTY) || (uarmu && uarmu->oartifact == ART_TOTAL_CONTROL) || (uarmc && uarmc->oartifact == ART_FREQUENT_BUT_WEAK_STATUS) )

#define Conf_resist		(((IntConf_resist && u.nonintrinsicproperty != CONF_RES) || (ExtConf_resist && u.nonextrinsicproperty != CONF_RES)) && !Race_if(PM_TONBERRY) && !hybridragontype(AD_LITE) && !NoConf_resist)
#define StrongConf_resist	(IntConf_resist && ExtConf_resist && Conf_resist && u.nondoubleproperty != CONF_RES)

#define NoConf_resist	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_CONF_RES].intrinsic || (uarmh && uarmh->oartifact == ART_UBB_RUPTURE) || RngeAids || (u.impossibleproperty == CONF_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HPsi_resist		u.uprops[PSI_RES].intrinsic
#define EPsi_resist		u.uprops[PSI_RES].extrinsic
#define IntPsi_resist	(HPsi_resist || (Upolyd && attackdamagetype(youmonst.data, AT_BREA, AD_SPC2) ))
#define ExtPsi_resist	(EPsi_resist || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == PSI_RES) ) || (uwep && uwep->oartifact == ART_SWEETHEART_PUMP) || (uarms && uarms->oartifact == ART_REAL_PSYCHOS_WEAR_PURPLE) || (uarms && uarms->oartifact == ART_REAL_MEN_WEAR_PSYCHOS) || (uwep && uwep->oartifact == ART_SIGNO_ONE) || (uwep && uwep->oartifact == ART_PSIGUN) || (uwep && uwep->oartifact == ART_SAXS_BEAUTY) || (uarmu && uarmu->oartifact == ART_PEDIATRIC_GAWKING_GANGS) || (uarmc && uarmc->oartifact == ART_INSANE_MIND_SCREW) || (uarmf && uarmf->oartifact == ART_JESSICA_S_TENDERNESS) || (uarmf && uarmf->oartifact == ART_MAILIE_S_CHALLENGE) || (uarmf && uarmf->oartifact == ART_BLUEDE) || (uarmc && uarmc->oartifact == ART_YOG_SOTHOTH_HELP_ME) || (uarmf && uarmf->oartifact == ART_JOSEFINE_S_EVILNESS) || (uarmh && uarmh->oartifact == ART_NUMBER___) || (uamul && uamul->oartifact == ART_ONE_MOMENT_IN_TIME) || (uwep && uwep->oartifact == ART_YASDORIAN_S_JUNETHACK_IDEN) || (uamul && uamul->oartifact == ART_PRECIOUS_UNOBTAINABLE_PROP) )

#define Psi_resist		(((IntPsi_resist && u.nonintrinsicproperty != PSI_RES) || (ExtPsi_resist && u.nonextrinsicproperty != PSI_RES)) && !hybridragontype(AD_SPC2) && !NoPsi_resist)
#define StrongPsi_resist	(IntPsi_resist && ExtPsi_resist && Psi_resist && u.nondoubleproperty != PSI_RES)

#define NoPsi_resist	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_PSI_RES].intrinsic || RngeAids || (u.impossibleproperty == PSI_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDouble_attack		u.uprops[DOUBLE_ATTACK].intrinsic
#define EDouble_attack		u.uprops[DOUBLE_ATTACK].extrinsic
#define IntDouble_attack	(HDouble_attack)
#define ExtDouble_attack	(EDouble_attack || (uwep && uwep->oartifact == ART_CYCLE_WHACK_WHACK && u.usteed) || (Race_if(PM_PLAYER_ASURA) && u.twoweap) || (uarm && uarm->oartifact == ART_OFFENSE_OWNS_DEFENSE) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_YOU_SHOULD_SURRENDER) || (uarmf && uarmf->oartifact == ART_ELLA_S_BLOODLUST) || (uwep && uwep->oartifact == ART_MELEE_DUALITY) || (u.twoweap && uswapwep && uswapwep->oartifact == ART_MELEE_DUALITY))

#define Double_attack		(((IntDouble_attack && u.nonintrinsicproperty != DOUBLE_ATTACK) || (ExtDouble_attack && u.nonextrinsicproperty != DOUBLE_ATTACK)) && !NoDouble_attack)
#define StrongDouble_attack	(IntDouble_attack && ExtDouble_attack && Double_attack && u.nondoubleproperty != DOUBLE_ATTACK)

#define NoDouble_attack	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DOUBLE_ATTACK].intrinsic || RngeAids || (u.nonextrinsicproperty == DOUBLE_ATTACK && !HDouble_attack) || (u.impossibleproperty == DOUBLE_ATTACK) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HQuad_attack		u.uprops[QUAD_ATTACK].intrinsic
#define EQuad_attack		u.uprops[QUAD_ATTACK].extrinsic
#define IntQuad_attack	(HQuad_attack)
#define ExtQuad_attack	(EQuad_attack || (uarmc && uarmc->oartifact == ART_SUPERMAN_S_SUPER_SUIT) || (uimplant && uimplant->oartifact == ART_IME_SPEW))

#define Quad_attack		(((IntQuad_attack && u.nonintrinsicproperty != QUAD_ATTACK) || (ExtQuad_attack && u.nonextrinsicproperty != QUAD_ATTACK)) && !NoQuad_attack)
#define StrongQuad_attack	(IntQuad_attack && ExtQuad_attack && Quad_attack && u.nondoubleproperty != QUAD_ATTACK)

#define NoQuad_attack	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_QUAD_ATTACK].intrinsic || RngeAids || (u.nonextrinsicproperty == QUAD_ATTACK && !HQuad_attack) || (u.impossibleproperty == QUAD_ATTACK) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HUseTheForce		u.uprops[THE_FORCE].intrinsic
#define EUseTheForce		u.uprops[THE_FORCE].extrinsic
#define IntUseTheForce	(HUseTheForce)
#define ExtUseTheForce	(EUseTheForce || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == THE_FORCE) ) || (uarm && uarm->oartifact == ART_LUKE_S_JEDI_POWER))

#define UseTheForce		(((IntUseTheForce && u.nonintrinsicproperty != THE_FORCE) || (ExtUseTheForce && u.nonextrinsicproperty != THE_FORCE)) && !NoUseTheForce)
#define StrongUseTheForce	(IntUseTheForce && ExtUseTheForce && UseTheForce && u.nondoubleproperty != THE_FORCE)

#define NoUseTheForce	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_THE_FORCE].intrinsic || RngeAids || (u.impossibleproperty == THE_FORCE) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HCont_resist		u.uprops[CONT_RES].intrinsic
#define ECont_resist		u.uprops[CONT_RES].extrinsic
#define IntCont_resist	(HCont_resist)
#define ExtCont_resist	(ECont_resist || (powerfulimplants() && uimplant && uimplant->oartifact == ART_ARABELLA_S_SEXY_CHARM) || (uarmc && uarmc->oartifact == ART_HEV_SUIT) || (uimplant && uimplant->oartifact == ART_POTATOROK) || (uarmc && uarmc->oartifact == ART_INA_S_SORROW && u.uhunger < 0) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == CONT_RES) ) )

#define Cont_resist		(((IntCont_resist && u.nonintrinsicproperty != CONT_RES) || (ExtCont_resist && u.nonextrinsicproperty != CONT_RES)) && !NoCont_resist)
#define StrongCont_resist	(IntCont_resist && ExtCont_resist && Cont_resist && u.nondoubleproperty != CONT_RES)

#define NoCont_resist	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_CONT_RES].intrinsic || RngeAids || (u.impossibleproperty == CONT_RES) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDiscount_action	u.uprops[DISCOUNT_ACTION].intrinsic
#define EDiscount_action	u.uprops[DISCOUNT_ACTION].extrinsic
#define IntDiscount_action	(HDiscount_action)
#define ExtDiscount_action	(EDiscount_action || (uarmf && uarmf->oartifact == ART_LISA_S_BUCKLED_BEAUTIES) || (uwep && uwep->oartifact == ART_HARMONY_VIRGIN) || (uarmf && uarmf->oartifact == ART_ELEVECULT) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_CAN_T_BRING_US_DOWN) || (uarmf && uarmf->oartifact == ART_IMPOSSIBLE_CATWALK) || (uarmu && uarmu->oartifact == ART_PEDIATRIC_GAWKING_GANGS) || (uarmu && uarmu->oartifact == ART_KING_OF_PORN) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == DISCOUNT_ACTION) ) )

#define Discount_action		(((IntDiscount_action && u.nonintrinsicproperty != DISCOUNT_ACTION) || (ExtDiscount_action && u.nonextrinsicproperty != DISCOUNT_ACTION)) && !NoDiscount_action)
#define StrongDiscount_action	(IntDiscount_action && ExtDiscount_action && Discount_action && u.nondoubleproperty != DISCOUNT_ACTION)

#define NoDiscount_action	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DISCOUNT_ACTION].intrinsic || (isevilvariant && Free_action) || RngeAids || (u.impossibleproperty == DISCOUNT_ACTION) || (uimplant && uimplant->oartifact == ART_KATRIN_S_SUDDEN_APPEARANCE) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HFull_nutrient		u.uprops[FULL_NUTRIENT].intrinsic
#define EFull_nutrient		u.uprops[FULL_NUTRIENT].extrinsic
#define IntFull_nutrient	(HFull_nutrient)
#define ExtFull_nutrient	(EFull_nutrient || (powerfulimplants() && uimplant && uimplant->oartifact == ART_ARABELLA_S_SEXY_CHARM) || (uarmh && uarmh->oartifact == ART_SALADIN_S_DESERT_FOX) || (uwep && uwep->oartifact == ART_GIANT_MEAT_STICK) || (uleft && uleft->oartifact == ART_RELIABLE_TRINSICS) || (uright && uright->oartifact == ART_RELIABLE_TRINSICS) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == FULL_NUTRIENT) ) )

#define Full_nutrient		(((IntFull_nutrient && u.nonintrinsicproperty != FULL_NUTRIENT) || (ExtFull_nutrient && u.nonextrinsicproperty != FULL_NUTRIENT)) && !Race_if(PM_PERVERT) && !NoFull_nutrient)
#define StrongFull_nutrient	(IntFull_nutrient && ExtFull_nutrient && Full_nutrient && u.nondoubleproperty != FULL_NUTRIENT)

#define NoFull_nutrient	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_FULL_NUTRIENT].intrinsic || RngeAids || (u.impossibleproperty == FULL_NUTRIENT) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HTechnicality		u.uprops[TECHNICALITY].intrinsic
#define ETechnicality		u.uprops[TECHNICALITY].extrinsic
#define IntTechnicality	(HTechnicality)
#define ExtTechnicality	(ETechnicality || (uarm && uarm->oartifact == ART_REQUIRED_POWER_PLANT_GEAR) || (uwep && uwep->oartifact == ART_TODAY_S_REPAIR) || (powerfulimplants() && uimplant && uimplant->oartifact == ART_ARABELLA_S_SEXY_CHARM) || (powerfulimplants() && uimplant && (goodimplanteffect(uimplant) == TECHNICALITY) ) )

#define Technicality		(((IntTechnicality && u.nonintrinsicproperty != TECHNICALITY) || (ExtTechnicality && u.nonextrinsicproperty != TECHNICALITY)) && !NoTechnicality)
#define StrongTechnicality	(IntTechnicality && ExtTechnicality && Technicality && u.nondoubleproperty != TECHNICALITY)

#define NoTechnicality	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_TECHNICALITY].intrinsic || RngeAids || (u.impossibleproperty == TECHNICALITY) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HScentView		u.uprops[SCENT_VIEW].intrinsic
#define EScentView		u.uprops[SCENT_VIEW].extrinsic
#define IntScentView	(HScentView)
#define ExtScentView	(EScentView || (ublindf && ublindf->oartifact == ART_SCENTFOLD) )

#define ScentView		(((IntScentView && u.nonintrinsicproperty != SCENT_VIEW) || (ExtScentView && u.nonextrinsicproperty != SCENT_VIEW)) && !NoScentView)
#define StrongScentView	(IntScentView && ExtScentView && ScentView && u.nondoubleproperty != SCENT_VIEW)
#define HaveEcholocation	((Role_if(PM_BARD) || (uwep && uwep->oartifact == ART_GAME_KNOWLEDGE_CHEAT_SHEET) || (uwep && uwep->oartifact == ART_PEREGRINE_OF_NIGHT) || Role_if(PM_STAND_USER) || Race_if(PM_ANCIPITAL) || Race_if(PM_BATMAN) || Race_if(PM_CHIROPTERAN) || Race_if(PM_HC_ALIEN) || (Upolyd && youmonst.data->mlet == S_BAT) ) && !NoScentView && u.nonintrinsicproperty != SCENT_VIEW)
#define EcholocationActive	(StrongScentView || HaveEcholocation)

#define NoScentView	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_SCENT_VIEW].intrinsic || RngeAids || (u.impossibleproperty == SCENT_VIEW) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#define HDiminishedBleeding		u.uprops[DIMINISHED_BLEEDING].intrinsic
#define EDiminishedBleeding		u.uprops[DIMINISHED_BLEEDING].extrinsic
#define IntDiminishedBleeding	(HDiminishedBleeding || (Upolyd && !has_blood(youmonst.data)) )
#define ExtDiminishedBleeding	(EDiminishedBleeding || (uwep && uwep->oartifact == ART_SELF_PROTECTION_IMPLEMENT) || (uarmf && uarmf->oartifact == ART_KATI_S_IRRESISTIBLE_STILET) || (uwep && uwep->oartifact == ART_ARABELLA_S_BLACK_PRONG))

#define DiminishedBleeding		(((IntDiminishedBleeding && u.nonintrinsicproperty != DIMINISHED_BLEEDING) || (ExtDiminishedBleeding && u.nonextrinsicproperty != DIMINISHED_BLEEDING)) && !Role_if(PM_BLEEDER) && !Race_if(PM_HEMOPHAGE) && !NoDiminishedBleeding)
#define StrongDiminishedBleeding	(IntDiminishedBleeding && ExtDiminishedBleeding && DiminishedBleeding && u.nondoubleproperty != DIMINISHED_BLEEDING)

#define NoDiminishedBleeding	(!Race_if(PM_IMMUNIZER) && (u.uprops[DEAC_DIMINISHED_BLEEDING].intrinsic || RngeAids || (u.impossibleproperty == DIMINISHED_BLEEDING) || Role_if(PM_BLEEDER) || Race_if(PM_HEMOPHAGE) || (Race_if(PM_HUMANOID_ANGEL) && u.ualign.record < 0)))

#endif /* YOUPROP_H */
