#include "stdafx.h"
#include "Weapons.h"
#include "Vehicle.h"
#include "Local.h"
#include "Other.h"
#include "Protections.h"
#include "SelectedPlayer.h"
#include "Offsets.h"
#include "Ini Vehicles.h"
#include "Something.h"
#include "Vehicle Spawner Preview.h"
#include "Map.h"
#include "Blackhole.h"
#include "GUI.h"
//#include "curl.h"
#include "Recovery.h"
#include "Network.h"
#include "All Players.h"
#include <filesystem>
#include <algorithm>	// for replace
#include <chrono>	// for chrono::time_point
#include <codecvt>	// for codecvt_utf8_*
#include <list>		// for recursive_directory_iterator stack
#include <locale>	// for wstring_convert
#include <memory>	// for shared_ptr
#include <vector>	// for canonical's .. handling
#include "Scripts.h"
#include "Misc.h"
#include "Teleport.h"
#include "auth.h"
#include "types.h"
#include "Stuff.h"


static char* LPName[] = {
	    "Doll Box",
		"Chip Card",
		"Sasquatch Figure",
		"Beast Figure",
		"Rsr Figure",
		"Rs Comm Figure",
		"Pogo Figure",
		"Bubble Figure",
		"Rage Figure",
		"Alien Figure",
		"Chest",
		"Health",
		"Armour",
		"Snack",
		"Money",
		"Money Case",
		"Money Walet",
		"Money Purse",
		"Money Dep Bag",
		"Money Med Bag",
		"Money Paper Bag",
		"Money Security case",
		"Gang Money",
		"Pistol",
		"Combatpistol",
		"Pistol 50",
		"Appistol",
		"Microsmg",
		"Smg",
		"ASSAULTSMG",
		"Assaultrifle",
		"Carbinerifle",
		"Advancedrifle",
		"Mg",
		"Combatmg",
		"Pumpshotgun",
		"Sawnoffshotgun",
		"Assaultshotgun",
		"Sniperrifle",
		"Heavysniper",
		"Grenadelauncher",
		"Rpg",
		"Minigun",
		"Grenade",
		"Smokegrenade",
		"Stickybomb",
		"Molotov",
		"Stungun",
		"Fireextinguisher",
		"Petrolcan",
		"Loudhailer",
		"Knife",
		"Nightstick",
		"Hammer",
		"Bat",
		"Crowbar",
		"Golfclub",
		"Ammo Bullet Mp",
		"Ammo Missile Mp",
		"Ammo Grenadelauncher Mp",
		"AMMO Pistol",
		"AMMO Smg",
		"AMMO Rifle",
		"AMMO Mg",
		"AMMO Shotgun",
		"AMMO Sniper",
		"AMMO Grenadelauncher",
		"AMMO Rpg",
		"AMMO Minigun",
		"AMMO Flaregun",
		"AMMO Firework",
		"Vehicle Health Standard",
		"Vehicle Health Low Glow",
		"Vehicle Armour Standard",
		"Vehicle Weapon Pistol",
		"Vehicle Weapon Combatpistol",
		"VEHICLE Weapon Pistol 50",
		"Vehicle Weapon Appistol",
		"Vehicle Weapon Microsmg",
		"Vehicle Weapon Smg",
		"Vehicle Weapon Sawnoff",
		"VEHICLE Weapon ASSAULTSMG",
		"Vehicle Weapon Grenade",
		"Vehicle Weapon Smokegrenade",
		"Vehicle Weapon Stickybomb",
		"Vehicle Weapon Molotov",
		"VEHICLE MONEY VARIABLE",
	    "Portable Crate Unfixed",
	    "PORTABLE CRATE UNFIXED LOW GLOW",
	    "Portable Package",
	    "Dlc Vehicle Package",
	    "Submarine",
	    "Parachute",
	    "Handcuff Key",
	    "Camera",
		"Weapon BOTTLE",
		"Weapon SPECIALCARBINE",
		"Weapon SNSPISTOL",
		"Weapon BULLPUPRIFLE",
		"Weapon HEAVYPISTOL",
		"Weapon DAGGER",
		"Weapon VINTAGEPISTOL",
		"Weapon GUSENBERG",
		"Weapon FIREWORK",
		"Weapon MUSKET",
		"Weapon HOMINGLAUNCHER",
		"Weapon PROXMINE",
		"Weapon HATCHET",
		"Weapon RAILGUN",
		"Weapon FLAREGUN",
		"Weapon BULLPUPSHOTGUN",
		"Weapon MACHINEPISTOL",
		"Weapon MARKSMANPISTOL",
		"Weapon HEAVYSHOTGUN",
		"Weapon MARKSMANRIFLE",
		"Weapon COMPACTRIFLE",
		"Weapon DBSHOTGUN",
		"Weapon MACHETE",
		"Weapon FLASHLIGHT",
		"Weapon KNUCKLE",
		"Weapon COMBATPDW",
		"Weapon SWITCHBLADE",
		"Weapon REVOLVER",
		"Weapon AUTOSHOTGUN",
		"Weapon MINISMG",
		"Weapon COMPACTLAUNCHER",
		"Weapon PIPEBOMB",
		"Weapon POOLCUE",
		"Weapon BATTLEAXE",
		"Weapon WRENCH",
		"Weapon ASSAULTRIFLE MK2",
		"Weapon CARBINERIFLE MK2",
		"Weapon COMBATMG MK2",
		"Weapon HEAVYSNIPER MK2",
		"Weapon PISTOL MK2",
		"Weapon SMG MK2",
		"Weapon SNSPISTOL MK2",
		"Weapon REVOLVER MK2",
		"Weapon BULLPUPRIFLE MK2",
		"Weapon SPECIALCARBINE MK2",
		"Weapon PUMPSHOTGUN MK2",
		"Weapon MARKSMANRIFLE MK2",
		"Weapon DOUBLEACTION",
		"Weapon STONE HATCHET",
		"Weapon NAVYREVOLVER",
		"Pickup Large Radius",

};

int weapon_name_pos = 0;
int radio_status_variable = 0;
static char* weapon_name[] = {
	"PISTOL",
			"COMBATPISTOL",
			"APPISTOL",
			"PISTOL50",
			"SMG",
			"MICROSMG",
			"ASSAULTRIFLE",
			"CARBINERIFLE",
			"ADVANCEDRIFLE",
			"MG",
			"COMBATMG",
			"PUMPSHOTGUN",
			"SAWNOFFSHOTGUN",
			"ASSAULTSHOTGUN",
			"HEAVYSNIPER",
			"SNIPERRIFLE",
			"GRENADELAUNCHER",
			"RPG",
			"MINIGUN",
			"GRENADE",
			"SMOKEGRENADE",
			"STICKYBOMB",
			"MOLOTOV",
			"PETROLCAN",
			"GADGET PARACHUTE",
			"KNIFE",
			"NIGHTSTICK",
			"HAMMER",
			"BAT",
			"CROWBAR",
			"GOLFCLUB",
			"ASSAULTMG",
			"ASSAULTSMG",
			"ASSAULTSNIPER",
			"BULLPUPSHOTGUN",
			"BOTTLE",
			"SPECIALCARBINE",
			"SNSPISTOL",
			"HEAVYPISTOL",
			"BULLPUPRIFLE",
			"GUSENBERG",
			"VINTAGEPISTOL",
			"DAGGER",
			"MUSKET",
			"FIREWORK",
			"FLAREGUN",
			"HEAVYSHOTGUN",
			"MARKSMANRIFLE",
			"PROXMINE",
			"HOMINGLAUNCHER",
			"HATCHET",
			"COMBATPDW",
			"KNUCKLE",
			"MARKSMANPISTOL",
			"MACHETE",
			"MACHINEPISTOL",
			"DBSHOTGUN",
			"COMPACTRIFLE",
			"FLASHLIGHT",
			"REVOLVER",
			"SWITCHBLADE",
			"AUTOSHOTGUN",
			"MINISMG",
			"COMPACTLAUNCHER",
			"BATTLEAXE",
			"PIPEBOMB",
			"POOLCUE",
			"WRENCH",
			"ASSAULTRIFLE MK2",
			"CARBINERIFLE MK2",
			"COMBATMG MK2",
			"HEAVYSNIPER MK2",
			"PISTOL MK2",
			"SMG MK2",
			"BULLPUPRIFLE MK2",
			"MARKSMANRIFLE MK2",
			"PUMPSHOTGUN MK2",
			"REVOLVER MK2",
			"SNSPISTOL MK2",
			"SPECIALCARBINE MK2",
			"DOUBLEACTION",
			"RAYPISTOL",
			"RAYCARBINE",
			"RAYMINIGUN",
			"STONE HATCHET",
			"NAVYREVOLVER",
			"CERAMICPISTOL",
			"GADGETPISTOL",
			"MILITARYRIFLE",
			"COMBATSHOTGUN",
			"HEAVYRIFLE",
			"EMPLAUNCHER",
			"FERTILIZERCAN",
			"STUNGUN MP",
			"METALDETECTOR",
			"TACTICALRIFLE",
			"PRECISIONRIFLE",
};

static char* Menu_UI_Name[] = {
	"Rain",
	"Stride",
	"Jiggy",
	"Independence",
	"Sterling",
	"Quantum",
	"Gaymer",
	"Foxy Free",
	"Blasts",
	"Hell Vengence",
};

int Cutscene_int = 0;
static char* Cutscene[] =
{
	"abigail_mcs_1_concat", "abigail_mcs_2", "ac_ig_3_p3_b", "ah_1_ext_t6", "ah_1_int", "ah_1_mcs_1", "ah_2_ext_alt", "ah_2_ext_p4", "ah_3a_explosion", "ah_3a_ext", "ah_3a_int", "ah_3a_mcs_3", "ah_3a_mcs_6", "ah_3b_ext", "ah_3b_int", "ah_3b_mcs_1", "ah_3b_mcs_2", "ah_3b_mcs_3", "ah_3b_mcs_4", "ah_3b_mcs_5", "ah_3b_mcs_6_p1", "ah_3b_mcs_7", "armenian_1_int", "armenian_1_mcs_1", "armenian_2_int", "armenian_2_mcs_6", "armenian_3_int", "armenian_3_mcs_3", "armenian_3_mcs_4", "armenian_3_mcs_5", "armenian_3_mcs_6", "armenian_3_mcs_7", "armenian_3_mcs_8", "armenian_3_mcs_9_concat", "arm_1_mcs_2_concat", "arm_2_mcs_4", "ass_int_2_alt1", "ass_mcs_1", "bar_1_rcm_p2", "bar_2_rcm", "bar_3_rcm", "bar_4_rcm", "bar_5_rcm_p2", "bss_1_mcs_2", "bss_1_mcs_3", "bs_1_int", "bs_2a_2b_int", "bs_2a_ext", "bs_2a_int", "bs_2a_mcs_1", "bs_2a_mcs_10", "bs_2a_mcs_11", "bs_2a_mcs_2", "bs_2a_mcs_3_alt", "bs_2a_mcs_4", "bs_2a_mcs_5", "bs_2a_mcs_6", "bs_2a_mcs_7_p1", "bs_2a_mcs_8", "bs_2a_mcs_8_p3", "bs_2b_ext_alt1a", "bs_2b_ext_alt2", "bs_2b_int", "bs_2b_mcs_1", "bs_2b_mcs_3", "carbine_mag_offset_test", "car_1_ext_concat", "car_1_int_concat", "car_2_mcs_1", "car_2_mcs_1_merged", "car_4_ext", "car_4_mcs_1", "car_5_ext", "car_5_mcs_1", "car_steal_3_mcs_1", "car_steal_3_mcs_2", "car_steal_3_mcs_3", "chinese_1_int", "chinese_2_int", "chi_1_mcs_1", "chi_1_mcs_4_concat", "chi_2_mcs_5", "choice_int", "cletus_mcs_1_concat", "dhp1_mcs_1", "drf_mic_1_cs_1", "drf_mic_1_cs_2", "drf_mic_2_cs_1", "drf_mic_2_cs_2", "drf_mic_3_cs_1", "drf_mic_3_cs_2", "ef_1_rcm", "ef_2_rcm", "ef_3_rcm_concat", "eps_4_mcs_1", "eps_4_mcs_2", "eps_4_mcs_3", "ep_1_rcm_concat", "ep_2_rcm", "ep_3_rcm_alt1", "ep_4_rcm", "ep_4_rcm_concat", "ep_5_rcm", "ep_6_rcm", "ep_7_rcm", "ep_8_rcm", "es_1_rcm_concat", "es_1_rcm_p1", "es_2_rcm_concat", "es_3_mcs_1", "es_3_mcs_2", "es_3_rcm", "es_4_rcm_p1", "es_4_rcm_p2_concat", "exile_1_int", "exile_2_int", "exile_3_int", "exl_1_mcs_1_p3_b", "exl_2_mcs_3", "exl_3_ext", "family_1_int", "family_2_int", "family_2_mcs_2", "family_2_mcs_3", "family_2_mcs_4", "family_3_ext", "family_3_int", "family_3_intp1", "family_3_intp1_2", "family_3_intp1_3", "family_3_intp2", "family_3_intp2_1", "family_3_mcs_1", "fam_3_mcs_1", "fam_3_mcs_1_b", "family_4_mcs_2", "family_4_mcs_3_concat", "family_5_int", "family_5_mcs_1", "family_5_mcs_2", "family_5_mcs_3", "family_5_mcs_4", "family_5_mcs_5", "family_5_mcs_5_p4", "family_5_mcs_5_p5", "fam_1_ext_2", "fam_1_ext_alt2", "fam_1_ext_alt3", "fam_1_mcs_2", "fam_3_mcs_1", "fam_4_int_alt1", "fam_5_mcs_6", "fam_5_mcs_6_p3_b", "fam_5_mcs_6_p4", "fam_6_int", "fam_6_int_p3_t7", "fam_6_mcs_1", "fam_6_mcs_2_concat", "fam_6_mcs_3", "fam_6_mcs_4", "fam_6_mcs_5", "fam_6_mcs_6", "fam_6_mcs_6_p4_b", "fbi_1_ext", "fbi_1_int", "fbi_1_jan_kill", "fbi_1_mcs_1_concat", "fbi_2_ext", "fbi_2_int", "fbi_2_mcs_1", "fbi_2_mcs_2", "fbi_2_mcs_3b", "fbi_2_mcs_3_p1a", "fbi_3_int", "fbi_3_mcs_1", "fbi_3_mcs_2", "fbi_3_mcs_3", "fbi_3_mcs_4p2", "fbi_3_mcs_5", "fbi_3_mcs_5p2", "fbi_3_mcs_6p1_b", "fbi_3_mcs_6p2", "fbi_3_mcs_7", "fbi_3_mcs_8", "fbi_4_int", "fbi_4_mcs_2_concat", "fbi_4_mcs_3_concat", "fbi_5a_mcs_1", "fbi_5a_mcs_10", "fbi_5b_mcs_1", "fbi_5_ext", "fbi_5_int", "fin_a_ext", "fin_a_int", "fin_a_mcs_1", "fin_b_ext", "fin_b_mcs_1_aandb", "fin_b_mcs_2", "fin_c2_mcs_1", "fin_c2_mcs_5", "fin_c_ext", "fin_c_int", "fin_c_mcs_1", "fin_c_mcs_1_p1_a", "fin_ext_p1", "fin_ext_p2", "fos_ep_1_p0", "fos_ep_1_p1", "fos_ep_1_p2", "fos_ep_1_p3", "fos_ep_1_p3b", "fos_ep_1_p3c", "fos_ep_1_p3d", "fos_ep_1_p3e", "fos_ep_1_p4", "fos_ep_1_p5", "fos_ep_1_p5b", "fos_ep_1_p6", "fos_ep_1_p6b", "fos_ep_1_p7", "fos_ep_1_p8", "fos_ep_1_p9", "fos_ep_2_p1", "fos_ep_2_p2", "fos_ep_2_p3", "fos_ep_2_p5b", "fos_ep_2_p5c", "fos_ep_2_p5d", "fos_ep_2_p6_alt1", "fos_tracey_1_p1", "fos_tracey_1_p2", "fos_tracey_1_p2b", "fos_tracey_1_p3", "franklin_1_int", "fra_0_int", "fra_0_int_p1_alt", "fra_0_mcs_1", "fra_0_mcs_4_p2_t3", "fra_0_mcs_5_p1", "fra_1_mcs_1", "fra_2_ext", "fra_2_ig_4_alt1_concat", "fra_2_int", "handposes", "hao_mcs_1", "hun_2_mcs_1", "jh2_fina_mcs4_a1a2", "jhrs_1_int_p2", "jhrs_1_int_p3", "jhrs_1_int_p4", "jhrs_2_hero_shot", "jhrs_2_hero_shot_a", "jhrs_2_int_p1_t2", "jhrs_2_int_p1_t3", "jhrs_2_int_p2", "jhrs_2_int_p2_t5", "jhrs_2_int_p3a", "jhrs_2_int_p3_t2", "jhrs_2_int_p3_t3", "jhrs_2_int_p4", "jhrs_2_int_p5", "jhrs_2_int_p6", "jhrs_3_int_p2a", "jhrs_4_int_p1", "jhrs_5_int_p1", "jhrs_5_int_p1b", "jhrs_5_int_p2", "jhrs_5_int_p3_t1", "jhrs_5_int_p3_t3", "jhrs_6_int_p1", "jhrs_6_int_p2", "jhrs_6_int_p3", "jhrs_6_int_p4", "jh_1_ig_3", "jh_1_int", "jh_1_mcs_4p2", "jh_1_mcs_4_p1_alt1", "jh_2a_intp4", "jh_2a_mcs_1", "jh_2b_int", "jh_2b_mcs_1", "jh_2_arrest_fail_c", "jh_2_celeb", "jh_2_fin_a_mcs4_a1", "jh_end_pt2_a1_p2_a", "josh_1_int", "josh_1_int_concat", "josh_2_intp1_t4", "josh_3_intp1", "josh_4_int_concat", "lamar_1_int", "lam_1_mcs_1_concat", "lam_1_mcs_2", "lam_1_mcs_3", "lester_1_int", "les_1a_mcs_0", "les_1a_mcs_1", "les_1a_mcs_2", "les_1a_mcs_3", "les_1a_mcs_4", "les_1b_mcs_1", "lsdhs_mcs_2", "lsdhs_mcs_3_p1_concat", "lsdhs_mcs_3_p2", "lsdh_2a_ext", "lsdh_2a_int", "lsdh_2a_rf_01", "lsdh_2b_int", "lsdh_2b_mcs_1", "lsdh_int", "martin_1_ext", "martin_1_int", "martin_1_mcs_1", "maude_mcs_1", "maude_mcs_2", "maude_mcs_3", "maude_mcs_4", "maude_mcs_5", "melt_int_10_p1", "melt_int_10_p2", "melt_int_1_p1", "melt_int_1_p1_t4", "melt_int_1_p2", "melt_int_2", "melt_int_3", "melt_int_4", "melt_int_5", "melt_int_6", "melt_int_7", "melt_int_8_p1", "melt_int_8_p2", "melt_int_8_p3", "melt_int_9", "merge_test_crowd1", "merge_test_doug", "mic_1_int", "mic_1_mcs_1", "mic_1_mcs_2", "mic_1_mcs_3", "mic_2_int", "mic_2_mcs_1", "mic_2_mcs_3_concat", "mic_3_ext", "mic_3_int", "mic_3_int_p1_alt", "mic_3_mcs_1_p1_a2", "mic_4_int", "mmb_1_rcm", "mmb_2_rcm", "mmb_3_rcm", "mp_intro_concat", "mp_intro_mcs_10_a1", "mp_intro_mcs_10_a2", "mp_intro_mcs_10_a3", "mp_intro_mcs_10_a4", "mp_intro_mcs_10_a5", "mp_intro_mcs_11", "mp_intro_mcs_11_a1", "mp_intro_mcs_12_a1", "mp_intro_mcs_12_a2", "mp_intro_mcs_12_a3", "mp_intro_mcs_13", "mp_intro_mcs_14_b", "mp_intro_mcs_16_a1", "mp_intro_mcs_16_a2", "mp_intro_mcs_17_a5", "mp_intro_mcs_17_a8", "mp_intro_mcs_17_a9", "mp_intro_mcs_8_a1", "mp_intro_mcs_8_a1_cc", "mp_int_mcs_12_a3_3", "mp_int_mcs_12_a3_4", "mp_int_mcs_15_a1_b", "mp_int_mcs_15_a2b", "mp_int_mcs_15_a3", "mp_int_mcs_15_a4", "mp_int_mcs_17_a1", "mp_int_mcs_17_a2", "mp_int_mcs_17_a3", "mp_int_mcs_17_a4", "mp_int_mcs_17_a6", "mp_int_mcs_17_a7", "mp_int_mcs_18_a1", "mp_int_mcs_18_a2", "mp_int_mcs_5_alt1", "mp_int_mcs_5_alt2", "mp_int_mcs_7_a1", "nextgen_fx_test", "ng_optimise_concat", "ng_optimise_test", "nmt_1_rcm", "nmt_2_mcs_2", "nmt_2_rcm", "nmt_3_rcm", "oscar_mcs_1", "paper_1_rcm_alt1", "pap_1_mcs_1", "pap_1_rcm", "pap_2_mcs_1", "pap_2_rcm_p2", "pap_3_rcm", "pap_4_rcm", "pro_mcs_1", "pro_mcs_2", "pro_mcs_3_pt1", "pro_mcs_5", "pro_mcs_6", "pro_mcs_6_p1", "pro_mcs_6_p2_a1_b", "pro_mcs_6_p2_alt1", "pro_mcs_7_concat", "rbhs_int", "rbhs_mcs_1", "rbhs_mcs_3", "rbhs_msc_3_p3", "rbh_2ab_mcs_6", "rbh_2a_ext1_a1_p1", "rbh_2a_ext_1", "rbh_2a_int", "rbh_2a_mcs_2_p3", "rbh_2a_mcs_2_p7", "rbh_2a_mcs_4", "rbh_2a_mcs_5", "rifle_grip_mesh", "sas_1_rcm_concat", "sas_2_rcm_t7", "scrap_1_rcm", "scrap_2_rcm", "sdrm_mcs_2", "sol_1_ext", "sol_1_int_alt", "sol_1_mcs_1_concat", "sol_1_mcs_2", "sol_1_mcs_3", "sol_2_ext_concat", "sol_2_int_alt1", "sol_3_int", "sol_5_mcs_1", "sol_5_mcs_2", "sol_5_mcs_2_p5", "testbed_veh_blend", "test_arm_2_mcs_6", "test_jh_2a_intp4", "tmom_1_rcm", "tmom_2_rcm", "tonya_mcs_1", "tonya_mcs_2", "tonya_mcs_3", "trevor_1_int", "trevor_2_int", "trevor_drive_int", "trv2_mcs_8", "trvram_1", "trvram_2_concat", "trvram_3", "trvram_4", "trvram_5_con", "trv_1_mcs_1_p1", "trv_1_mcs_3_concat", "trv_1_mcs_4", "trv_2_mcs_4_concat", "trv_2_mcs_6", "trv_4_mcs_2", "trv_5_ext", "trv_5_int", "trv_dri_ext", "trv_dri_mcs_concat", "under_int_1", "under_int_1_p2", "under_int_2", "under_int_2_p2", "under_int_3", "under_int_4", "under_int_4_p2", "under_int_4_p3", "under_int_5", "under_int_5_p2", "under_int_6", "under_int_6_p2", "under_int_6_p3", "under_int_7", "apa_fin_cel_apt2", "apa_fin_cel_apt3", "apa_fin_cel_apt4", "apa_hum_fin_int", "apa_nar_int", "apa_nar_mid", "apa_pri_int", "low_drv_ext", "low_drv_int", "low_fin_ext", "low_fin_int", "low_fin_mcs1", "low_fun_ext", "low_fun_int", "low_fun_mcs1", "low_int", "low_pho_ext", "low_pho_int", "low_tra_ext", "low_tra_int", "heist_int", "mph_fin_cel_apt", "mph_fin_cel_bar", "mph_fin_cel_roo", "mph_fin_cel_str", "mph_fin_cel_tre", "mph_hum_arm_ext", "mph_hum_del_ext", "mph_hum_emp_ext", "mph_hum_fin_ext", "mph_hum_fin_int", "mph_hum_fin_mcs1", "mph_hum_int", "mph_hum_key_ext", "mph_hum_key_mcs1", "mph_hum_mid", "mph_hum_val_ext", "mph_nar_bik_ext", "mph_nar_cok_ext", "mph_nar_fin_ext", "mph_nar_fin_int", "mph_nar_int", "mph_nar_met_ext", "mph_nar_mid", "mph_nar_tra_ext", "mph_nar_wee_ext", "mph_pac_bik_ext", "mph_pac_con_ext", "mph_pac_fin_ext", "mph_pac_fin_int", "mph_pac_fin_mcs0", "mph_pac_fin_mcs1", "mph_pac_fin_mcs2", "mph_pac_hac_ext", "mph_pac_hac_mcs1", "mph_pac_int", "mph_pac_mid", "mph_pac_pho_ext", "mph_pac_wit_mcs1", "mph_pac_wit_mcs2", "mph_pri_bus_ext", "mph_pri_fin_ext", "mph_pri_fin_int", "mph_pri_fin_mcs1", "mph_pri_fin_mcs2", "mph_pri_int", "mph_pri_mid", "mph_pri_pla_ext", "mph_pri_sta_ext", "mph_pri_sta_mcs1", "mph_pri_sta_mcs2", "mph_pri_unf_ext", "mph_pri_unf_mcs1", "mph_tut_car_ext", "mph_tut_ext", "mph_tut_fin_int", "mph_tut_int", "mph_tut_mcs1", "mph_tut_mid", "impexp_int", "impexp_int_l1", "hang_int", "hang_int_plane", "bunk_int", "iaa_int", "iaaj_ext", "iaaj_int", "sil_int", "sil_pred_mcs1", "silj_ext", "silj_int", "silj_mcs1", "silj_mcs2", "sub_int", "subj_ext", "subj_mcs0", "subj_mcs1", "bmad_intro", "club_intro", "club_intro2", "club_open", "dixn_intro", "smun_intro", "smun_intro2", "tale_intro", "arena_int", "arena_int2",

};

void Auth(std::string name)
{
	/*name = "Login";

	std::string iniPath = "C:\\Foxy\\Ini Auth\\" + name + ".ini";
	if (DoesPresetKeyExists1(name, "", ".ini")) {
		Hash Model = static_cast<DWORD>(atoll(ReadPresetKey1(name, "Vehicle", "Model").c_str()));

		std::string username, password;
		username = st(ReadPresetKey1(name, "Authed", "Username"));
		password = st(ReadPresetKey1(name, "Authed", "Password"));
		std::string API = "api/v7/auth?username=" + username + "&password=" + password;

		std::string strResponse;
		std::string site = "svkr.fun";
		std::string param = API;


	}
	*/

}
int reded = 255, greened = 0, blued = 0;
void RGBFaded4() {
	if (reded > 0 && blued == 0) {
		reded--;
		greened++;
	}
	if (greened > 0 && reded == 0) {
		greened--;
		blued++;
	}
	if (blued > 0 && greened == 0) {
		reded++;
		blued--;
	}
}

float Rain_ = 0;
float waves = 0;
float shoreamplitude = 0;
float shoreminamplitude = 0;
float shoremaxamplitude = 0;
float shoremaxnoise = 0;
float rippledisturbedamplitude = 0;
float oceanwaveamplitude = 0;
float oceanwaveminamplitude = 0;
float oceanwavemaxamplitude = 0;
float ripplebumpinesseamplitude = 0;
float ripplebumpinesseminamplitude = 0;
float ripplebumpinessemaxamplitude = 0;
float Cloudss = 0;
float s0uthwind = 0;
float WindDirection = 0;
float snowlevel = 0;
float mooncycle = 0;
float Snow_ = 0;

int Timehour = 0;
int Timemin = 0;
int Timesec = 0;

int NumberKeyboarde() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}

int vity = 0;
static char* grav[] = {
	"Normal", "Low", "Lower",
};

int WaterStrenght_int = 0;
static char* WaterStrenght[] = {
	"Normal", "Calm", "Really Intense",
};

int WeatherMixing_int = 0;
static char* WeatherMixing[] = {
	"Clear",
	"Clouds",
	"Blizzard",
	"Overcast",
	"Smog",
	"Smog",
	"Thunder",
	"Snowlight",
	"xmas",
	"Halloween",
	"Neutral",
};
int WeatherMixing2_int = 0;
static char* WeatherMixing2[] = {
	"Clear",
	"Clouds",
	"Blizzard",
	"Overcast",
	"Smog",
	"Smog",
	"Thunder",
	"Snowlight",
	"xmas",
	"Halloween",
	"Neutral",
};
float WeatherMixingFactorOfTransition = 0.f;


static char* marker_name[] = {
"Cone",
"Vertical Cylinder",
"Thick Chevron Up",
"Thin Chevron Up",
"Checkered Flag",
"Checkered Flag Circle",
"Verticle Circle",
"Plane Model",
"Lost MC 1",
"Lost MC 2",
"Number 0",
"Number 1",
"Number 2",
"Number 3",
"Number 4",
"Number 5",
"Number 6",
"Number 7",
"Number 8",
"Number 9",
"Chevron 1",
"Chevron 2",
"Chevron 3",
"Horizontal Circle",
"Replay Icon",
"Horizontal Circle Small",
"Horizontal Circle Arrow",
"Horizontal Split Circle",
"Debug Sphere",
"Money Sign",
"Horizontal Bars",
"Wolf Head",
"Question Mark",
"Plane",
"Helicopter",
"Boat",
"Car",
"Motorcycle",
"Bike",
"Truck",
"Parachute",
"Jetpack",
"Sawblade",
};

MODULEINFO g_MainModuleInfo = { 0 };
void SetName(char* name)
{
	DWORD64 start = DWORD64(g_MainModuleInfo.lpBaseOfDll);

	uintptr_t nameOffset1 = Memory::get_base_offsetted(0x28B59BC);
	uintptr_t nameOffset2 = Memory::get_base_offsetted(0x28BB8C4);
	uintptr_t nameOffset3 = Memory::get_base_offsetted(0x2CE7FEC); // go test okay boss
	uintptr_t nameOffset4 = Memory::get_base_offsetted(0x2CEAFBF);
	uintptr_t nameOffset5 = Memory::get_base_offsetted(0x2CEE3BF);
	uintptr_t nameOffset6 = Memory::get_base_offsetted(0x2CEE654);
	uintptr_t nameOffset7 = Memory::get_multilayer_pointer(Foxy_Engine::getWorldPtr(), { OFFSET_PLAYER, OFFSET_PLAYER_INFO, 0x7C });

	memcpy(reinterpret_cast<void*>(nameOffset1), name, 16);
	memcpy(reinterpret_cast<void*>(nameOffset2), name, 16);
	memcpy(reinterpret_cast<void*>(nameOffset3), name, 16);
	memcpy(reinterpret_cast<void*>(nameOffset4), name, 16);
	memcpy(reinterpret_cast<void*>(nameOffset5), name, 16);
	memcpy(reinterpret_cast<void*>(nameOffset6), name, 16);
	memcpy(reinterpret_cast<void*>(nameOffset7), name, 16);

	notifyMap(Menu::Tools::StringToChar("~b~Setting New Name To " + (std::string)name));
	notifyMap("~q~Join a new session to apply the new name");
}

void PrintToScreen(char* text, float x, float y, int r, int g, int b, int a, float scaleX, float scaleY, int centerText, int font)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_CENTRE(centerText);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

int intapart = 1;
int friendoption = 1;


int red0 = 255;
int blue0 = 255;
int green0 = 255;
int red1 = 255;
int blue1 = 255;
int green1 = 255;
int red2 = 255;
int blue2 = 255;
int green2 = 255;
int red3 = 255;
int blue3 = 255;
int green3 = 255;
int red4 = 255;
int blue4 = 255;
int green4 = 255;

int Xposbone = 1; int Yposbone = 1; int Zposbone = 1; int Xrotbone = 1; int Yrotbone = 1; int Zrotbone = 1; int Softpinnig = 0; int colision = 0; int fixedRot = 0;


/*void SpawnCrashVehicle(Player playerId, char* vehicle, int id1, int id2) {
	Hash hash = GAMEPLAY::GET_HASH_KEY(vehicle);
	DWORD index = 0xFF;
	#define modelInfo  Foxy_Engine::GetModelInfo(hash, index);
	try {
			modelInfo->m_handlingType = id1;
			while (!STREAMING::HAS_MODEL_LOADED(hash)) {
				STREAMING::REQUEST_MODEL(hash);
				WAIT(10);
			}
			auto VectorPos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(playerId), TRUE);
			auto CreatedVehicle = create_vehicle(hash, VectorPos, 0.f, TRUE, FALSE);
			DECORATOR::DECOR_SET_INT(CreatedVehicle, "MPBitset", 0);
			ENTITY::_SET_ENTITY_REGISTER(CreatedVehicle, TRUE);
			auto NetworkID = NETWORK::VEH_TO_NET(CreatedVehicle);
			if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(CreatedVehicle))
				NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NetworkID, TRUE);
			VEHICLE::SET_VEHICLE_IS_STOLEN(CreatedVehicle, FALSE);
			modelInfo->m_handlingType = id2;
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		
	}
	catch (...) {
		printf("Crash failed! Game crashed...");
	}
}*/

bool MoveObject = true;
bool snowfoottrack = false;
bool snowtiretrack = false;

bool entityproof = true;
bool ProofBullet = false;
bool ProofExplosion = false;
bool ProofFire = false;
bool ProofSteam = false;
bool ProofInterior = false;
bool proofMelee = false;
bool ProofWater = false;
bool ProofCollision = false;

#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())

	void Grab_Sprite(char* TEXTURE_DICT, char* SPRITE)
	{
		//airbus
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(TEXTURE_DICT, 0);
		if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(TEXTURE_DICT)) {
			Vector3 texture_res = GRAPHICS::GET_TEXTURE_RESOLUTION(TEXTURE_DICT, SPRITE);
			GRAPHICS::DRAW_SPRITE(TEXTURE_DICT, SPRITE, Menu::Settings::menuX, 1.090f, 0.1f, 0.0889f, 0, 255, 255, 255, 255);
		}
	}

	float scaleX = 10, scaleY = 10, scaleZ = 255;// Z 999999999 just to be safe!!!
	int rw = 255, gw = 0, bw = 0;

	void RGBFadee()
	{
		if (rw > 0 && bw == 0) {
			rw--;
			gw++;
		}
		if (gw > 0 && rw == 0) {
			gw--;
			bw++;
		}
		if (bw > 0 && gw == 0) {
			rw++;
			bw--;
		}
	}



	//	std::vector<char*> Stuntlist = {
	int propListPos = 0;
	std::vector<char*> propList = {
		"prop_cj_big_boat",
			"prop_mp_ramp_03",
			"prop_a4_pile_01",
			"prop_a4_sheet_01",
			"prop_abat_roller_static",
			"prop_abat_slide",
			"prop_acc_guitar_01",
			"prop_aerial_01a",
			"prop_afsign_amun",
			"prop_afsign_vbike",
			"prop_agave_01",
			"prop_aiprort_sign_01",
			"prop_aircon_l_01",
			"prop_aircon_m_09",
			"prop_aircon_s_01a",
			"prop_aircon_s_02a",
			"prop_airhockey_01",
			"prop_air_bagloader",
			"prop_air_bagloader2",
			"prop_air_barrier",
			"prop_air_bench_01",
			"prop_air_bench_02",
			"prop_air_bigradar_l1",
			"prop_air_bigradar_slod",
			"prop_air_blastfence_01",
			"prop_air_blastfence_02",
			"prop_air_bridge01",
			"prop_air_bridge02",
			"prop_air_cargoloader_01",
			"prop_air_cargo_01a",
			"prop_air_cargo_01b",
			"prop_air_chock_01",
			"prop_air_fueltrail1",
			"prop_air_fueltrail2",
			"prop_air_gasbogey_01",
			"prop_air_generator_01",
			"prop_air_generator_03",
			"prop_air_hoc_paddle_01",
			"prop_air_hoc_paddle_02",
			"prop_air_lights_01a",
			"prop_air_lights_01b",
			"prop_air_lights_03a",
			"prop_air_luggtrolley",
			"prop_air_mast_01",
			"prop_air_mast_02",
			"prop_air_monhut_01",
			"prop_air_monhut_02",
			"prop_air_monhut_03",
			"prop_air_propeller01",
			"prop_air_radar_01",
			"prop_air_stair_01",
			"prop_air_towbar_01",
			"prop_air_towbar_02",
			"prop_air_towbar_03",
			"prop_air_trailer_4a",
			"prop_air_trailer_4b",
			"prop_air_trailer_4c",
			"prop_air_watertank1",
			"prop_air_watertank2",
			"prop_air_windsock_base",
			"prop_air_woodsteps",
			"prop_alarm_01",
			"prop_alarm_02",
			"prop_alien_egg_01",
			"prop_aloevera_01",
			"prop_amanda_note_01",
			"prop_amanda_note_01b",
			"prop_amb_40oz_02",
			"prop_amb_40oz_03",
			"prop_amb_beer_bottle",
			"prop_amb_ciggy_01",
			"prop_amb_donut",
			"prop_amb_handbag_01",
			"prop_amb_phone",
			"prop_amp_01",
			"prop_am_box_wood_01",
			"prop_anim_cash_note",
			"prop_anim_cash_note_b",
			"prop_anim_cash_pile_01",
			"prop_anim_cash_pile_02",
			"prop_apple_box_01",
			"prop_apple_box_02",
			"prop_arcade_01",
			"prop_arcade_02",
			"prop_arc_blueprints_01",
			"prop_armchair_01",
			"prop_armenian_gate",
			"prop_armour_pickup",
			"prop_arm_gate_l",
			"prop_arm_wrestle_01",
			"prop_artgallery_02_dl",
			"prop_artgallery_02_dr",
			"prop_artgallery_dl",
			"prop_artgallery_dr",
			"prop_artifact_01",
			"prop_ashtray_01",
			"prop_asteroid_01",
			"prop_atm_02",
			"prop_atm_03",
			"prop_attache_case_01",
			"prop_aviators_01",
			"prop_a_base_bars_01",
			"prop_a_trailer_door_01",
			"prop_bahammenu",
			"prop_ballistic_shield",
			"prop_ballistic_shield_lod1",
			"prop_bandsaw_01",
			"prop_bank_shutter",
			"prop_bank_vaultdoor",
			"prop_barn_door_l",
			"prop_barn_door_r",
			"prop_barrachneon",
			"prop_barrel_01a",
			"prop_barrel_02a",
			"prop_barrel_02b",
			"prop_barrel_03a",
			"prop_barrel_03d",
			"prop_barrel_float_1",
			"prop_barrel_float_2",
			"prop_barriercrash_03",
			"prop_barriercrash_04",
			"prop_barrier_wat_01a",
			"prop_barrier_wat_03b",
			"prop_barrier_work01c",
			"prop_barry_table_detail",
			"prop_bar_coastbarr",
			"prop_bar_coastchamp",
			"prop_bar_coastdusc",
			"prop_bar_coastmount",
			"prop_bar_cooler_01",
			"prop_bar_cooler_03",
			"prop_bar_fridge_01",
			"prop_bar_fridge_02",
			"prop_bar_fridge_03",
			"prop_bar_fridge_04",
			"prop_bar_ice_01",
			"prop_bar_napkindisp",
			"prop_bar_pump_01",
			"prop_bar_pump_04",
			"prop_bar_pump_05",
			"prop_bar_pump_10",
			"prop_bar_sink_01",
			"prop_bar_stool_01",
			"prop_basejump_target_01",
			"prop_basketball_net",
			"prop_bath_dirt_01",
			"prop_battery_01",
			"prop_battery_02",
			"prop_bball_arcade_01",
			"prop_bbq_2",
			"prop_bbq_3",
			"prop_beachbag_01",
			"prop_beachbag_02",
			"prop_beachbag_combo_01",
			"prop_beachball_02",
			"prop_beachflag_le",
			"prop_beach_bars_01",
			"prop_beach_bars_02",
			"prop_beach_bbq",
			"prop_beach_dip_bars_01",
			"prop_beach_dip_bars_02",
			"prop_beach_fire",
			"prop_beach_lg_float",
			"prop_beach_lg_stretch",
			"prop_beach_lg_surf",
			"prop_beach_punchbag",
			"prop_beach_rings_01",
			"prop_beach_sculp_01",
			"prop_beach_towel_02",
			"prop_beach_volball01",
			"prop_beach_volball02",
			"prop_beerneon",
			"prop_beer_bison",
			"prop_beer_box_01",
			"prop_beer_neon_01",
			"prop_beer_neon_02",
			"prop_beggers_sign_01",
			"prop_beggers_sign_02",
			"prop_bench_01b",
			"prop_bench_01c",
			"prop_bench_04",
			"prop_beta_tape",
			"prop_beware_dog_sign",
			"prop_bh1_03_gate_l",
			"prop_bh1_03_gate_r",
			"prop_bh1_08_mp_gar",
			"prop_bh1_09_mp_gar",
			"prop_bh1_09_mp_l",
			"prop_bh1_09_mp_r",
			"prop_bh1_16_display",
			"prop_bh1_44_door_01l",
			"prop_bh1_44_door_01r",
			"prop_bh1_48_backdoor_l",
			"prop_bh1_48_backdoor_r",
			"prop_bh1_48_gate_1",
			"prop_bhhotel_door_l",
			"prop_bhhotel_door_r",
			"prop_big_bag_01",
			"prop_big_clock_01",
			"prop_big_shit_01",
			"prop_big_shit_02",
			"prop_bikerack_2",
			"prop_bikini_disp_01",
			"prop_bikini_disp_02",
			"prop_billboard_01",
			"prop_billboard_02",
			"prop_billboard_03",
			"prop_billboard_04",
			"prop_billboard_09wall",
			"prop_billboard_10",
			"prop_billboard_11",
			"prop_billb_frame01a",
			"prop_billb_frame01b",
			"prop_billb_frame02a",
			"prop_binoc_01",
			"prop_bin_04a",
			"prop_bin_10a",
			"prop_bin_10b",
			"prop_bin_11a",
			"prop_bin_beach_01d",
			"prop_bin_delpiero",
			"prop_bin_delpiero_b",
			"prop_biolab_g_door",
			"prop_biotech_store",
			"prop_bison_winch",
			"prop_blackjack_01",
			"prop_bleachers_01",
			"prop_blox_spray",
			"prop_bmu_01",
			"prop_bmu_01_b",
			"prop_bmu_02",
			"prop_bmu_02_ld",
			"prop_bmu_02_ld_cab",
			"prop_bmu_02_ld_sup",
			"prop_bmu_track01",
			"prop_bmu_track02",
			"prop_bmu_track03",
			"prop_bodyarmour_02",
			"prop_bodyarmour_03",
			"prop_bodyarmour_04",
			"prop_bollard_01a",
			"prop_bollard_01b",
			"prop_bomb_01",
			"prop_bomb_01_s",
			"prop_bonesaw",
			"prop_bongos_01",
			"prop_bong_01",
			"prop_boogbd_stack_01",
			"prop_boogbd_stack_02",
			"prop_boogieboard_01",
			"prop_boogieboard_02",
			"prop_boombox_01",
			"prop_bottle_cap_01",
			"prop_bowling_ball",
			"prop_bowling_pin",
			"prop_bowl_crisps",
			"prop_boxcar5_handle",
			"prop_boxing_glove_01",
			"prop_boxpile_10a",
			"prop_boxpile_10b",
			"prop_box_ammo01a",
			"prop_box_ammo02a",
			"prop_box_ammo03a_set",
			"prop_box_ammo03a_set2",
			"prop_box_guncase_01a",
			"prop_box_guncase_02a",
			"prop_box_guncase_03a",
			"prop_box_tea01a",
			"prop_box_wood05a",
			"prop_box_wood05b",
			"prop_box_wood08a",
			"prop_breadbin_01",
			"prop_bread_rack_01",
			"prop_bread_rack_02",
			"prop_broken_cboard_p1",
			"prop_broken_cboard_p2",
			"prop_broken_cell_gate_01",
			"prop_broom_unit_01",
			"prop_bskball_01",
			"prop_bs_map_door_01",
			"prop_buckets_02",
			"prop_bucket_01a",
			"prop_bucket_01b",
			"prop_bucket_02a",
			"prop_buck_spade_01",
			"prop_buck_spade_02",
			"prop_buck_spade_03",
			"prop_bumper_01",
			"prop_bumper_02",
			"prop_bumper_03",
			"prop_bumper_car_01",
			"prop_burto_gate_01",
			"prop_bush_dead_02",
			"prop_bush_grape_01",
			"prop_bush_ivy_01_1m",
			"prop_bush_lrg_01",
			"prop_bush_lrg_01b",
			"prop_bush_lrg_01c",
			"prop_bush_med_01",
			"prop_bush_med_02",
			"prop_bush_neat_01",
			"prop_bush_neat_02",
			"prop_bush_ornament_01",
			"prop_bush_ornament_02",
			"prop_busker_hat_01",
			"prop_byard_bench01",
			"prop_byard_bench02",
			"prop_byard_block_01",
			"prop_byard_boat01",
			"prop_byard_boat02",
			"prop_byard_chains01",
			"prop_byard_dingy",
			"prop_byard_elecbox01",
			"prop_byard_elecbox02",
			"prop_byard_floatpile",
			"prop_byard_float_01",
			"prop_byard_float_01b",
			"prop_byard_hoist",
			"prop_byard_hoist_2",
			"prop_byard_hoses01",
			"prop_byard_hoses02",
			"prop_byard_ladder01",
			"prop_byard_machine01",
			"prop_byard_machine02",
			"prop_byard_motor_01",
			"prop_byard_motor_02",
			"prop_byard_net02",
			"prop_byard_phone",
			"prop_byard_pipes01",
			"prop_byard_pipe_01",
			"prop_byard_planks01",
			"prop_byard_pulley01",
			"prop_byard_rack",
			"prop_byard_ramp",
			"prop_byard_rampold",
			"prop_byard_rowboat1",
			"prop_byard_scfhold01",
			"prop_byard_sleeper01",
			"prop_byard_sleeper02",
			"prop_byard_steps_01",
			"prop_byard_tank_01",
			"prop_byard_trailer01",
			"prop_byard_trailer02",
			"prop_b_board_blank",
			"prop_c4_final",
			"prop_c4_final_green",
			"prop_cabinet_01",
			"prop_cabinet_01b",
			"prop_cabinet_02b",
			"prop_cablespool_01a",
			"prop_cablespool_01b",
			"prop_cablespool_02",
			"prop_camera_strap",
			"prop_candy_pqs",
			"prop_can_canoe",
			"prop_cap_01",
			"prop_cap_01b",
			"prop_cap_row_01",
			"prop_cap_row_01b",
			"prop_cap_row_02",
			"prop_cap_row_02b",
			"prop_carcreeper",
			"prop_cargo_int",
			"prop_carjack",
			"prop_carjack_l2",
			"prop_carrier_bag_01",
			"prop_carrier_bag_01_lod",
			"prop_cartwheel_01",
			"prop_carwash_roller_horz",
			"prop_carwash_roller_vert",
			"prop_car_battery_01",
			"prop_car_bonnet_01",
			"prop_car_bonnet_02",
			"prop_car_door_01",
			"prop_car_engine_01",
			"prop_car_exhaust_01",
			"prop_car_ignition",
			"prop_car_seat",
			"prop_casey_sec_id",
			"prop_cash_case_01",
			"prop_cash_case_02",
			"prop_cash_crate_01",
			"prop_cash_dep_bag_01",
			"prop_cash_envelope_01",
			"prop_cash_note_01",
			"prop_cash_pile_01",
			"prop_cash_pile_02",
			"prop_cash_trolly",
			"prop_casino_door_01l",
			"prop_casino_door_01r",
			"prop_cattlecrush",
			"prop_cat_tail_01",
			"prop_cctv_02_sm",
			"prop_cctv_cont_01",
			"prop_cctv_cont_03",
			"prop_cementmixer_01a",
			"prop_cementmixer_02a",
			"prop_ceramic_jug_01",
			"prop_ceramic_jug_cork",
			"prop_ch1_07_door_01l",
			"prop_ch2_05d_g_door",
			"prop_ch2_07b_20_g_door",
			"prop_ch2_09b_door",
			"prop_ch2_09c_garage_door",
			"prop_ch3_01_trlrdoor_l",
			"prop_ch3_01_trlrdoor_r",
			"prop_ch3_04_door_01l",
			"prop_ch3_04_door_01r",
			"prop_ch3_04_door_02",
			"prop_chair_01a",
			"prop_chair_01b",
			"prop_chair_02",
			"prop_chair_03",
			"prop_chair_pile_01",
			"prop_chall_lamp_01",
			"prop_chall_lamp_01n",
			"prop_chall_lamp_02",
			"prop_chateau_chair_01",
			"prop_cheetah_covered",
			"prop_chem_grill",
			"prop_chem_grill_bit",
			"prop_chem_vial_02",
			"prop_chem_vial_02b",
			"prop_cherenneon",
			"prop_chickencoop_a",
			"prop_chip_fryer",
			"prop_choc_ego",
			"prop_choc_meto",
			"prop_choc_pq",
			"prop_ch_025c_g_door_01",
			"prop_cigar_01",
			"prop_cigar_pack_01",
			"prop_cigar_pack_02",
			"prop_clapper_brd_01",
			"prop_cleaver",
			"prop_cliff_paper",
			"prop_clippers_01",
			"prop_clothes_rail_02",
			"prop_clothes_rail_03",
			"prop_clothes_rail_2b",
			"prop_clothes_tub_01",
			"prop_clown_chair",
			"prop_cntrdoor_ld_l",
			"prop_cntrdoor_ld_r",
			"prop_coathook_01",
			"prop_cockneon",
			"prop_coffee_cup_trailer",
			"prop_coffee_mac_02",
			"prop_coffin_02",
			"prop_coffin_02b",
			"prop_coke_block_01",
			"prop_coke_block_half_a",
			"prop_coke_block_half_b",
			"prop_compressor_01",
			"prop_compressor_02",
			"prop_compressor_03",
			"prop_com_gar_door_01",
			"prop_com_ls_door_01",
			"prop_conc_sacks_02a",
			"prop_cone_float_1",
			"prop_conschute",
			"prop_consign_01c",
			"prop_consign_02a",
			"prop_conslift_base",
			"prop_conslift_brace",
			"prop_conslift_cage",
			"prop_conslift_steps",
			"prop_console_01",
			"prop_construcionlamp_01",
			"prop_const_fence01a",
			"prop_const_fence01b",
			"prop_const_fence02a",
			"prop_cons_crate",
			"prop_cons_plank",
			"prop_cons_ply01",
			"prop_cons_ply02",
			"prop_container_01a",
			"prop_container_01b",
			"prop_container_01c",
			"prop_container_01d",
			"prop_container_01e",
			"prop_container_01f",
			"prop_container_03mb",
			"prop_container_05mb",
			"prop_container_door_mb_l",
			"prop_container_door_mb_r",
			"prop_container_hole",
			"prop_container_ld",
			"prop_container_ld2",
			"prop_container_old1",
			"prop_contnr_pile_01a",
			"prop_controller_01",
			"prop_control_rm_door_01",
			"prop_cont_chiller_01",
			"prop_cooker_03",
			"prop_copier_01",
			"prop_copper_pan",
			"prop_coral_bush_01",
			"prop_coral_flat_01",
			"prop_coral_flat_01_l1",
			"prop_coral_flat_02",
			"prop_coral_flat_brainy",
			"prop_coral_flat_clam",
			"prop_coral_grass_01",
			"prop_coral_grass_02",
			"prop_coral_kelp_01",
			"prop_coral_kelp_01_l1",
			"prop_coral_kelp_02",
			"prop_coral_kelp_02_l1",
			"prop_coral_kelp_03",
			"prop_coral_kelp_03_l1",
			"prop_coral_kelp_04",
			"prop_coral_kelp_04_l1",
			"prop_coral_pillar_01",
			"prop_coral_pillar_02",
			"prop_coral_spikey_01",
			"prop_coral_stone_03",
			"prop_coral_sweed_03",
			"prop_coral_sweed_04",
			"prop_cora_clam_01",
			"prop_cork_board",
			"prop_couch_01",
			"prop_couch_03",
			"prop_couch_04",
			"prop_couch_lg_02",
			"prop_couch_lg_05",
			"prop_couch_sm_07",
			"prop_crane_01_truck1",
			"prop_crane_01_truck2",
			"prop_cranial_saw",
			"prop_crashed_heli",
			"prop_cratepile_07a_l1",
			"prop_crate_01a",
			"prop_crate_02a",
			"prop_crate_08a",
			"prop_crate_float_1",
			"prop_creosote_b_01",
			"prop_crisp",
			"prop_crisp_small",
			"prop_crosssaw_01",
			"prop_cs1_14b_traind",
			"prop_cs1_14b_traind_dam",
			"prop_cs4_05_tdoor",
			"prop_cs4_10_tr_gd_01",
			"prop_cs4_11_door",
			"prop_cs6_03_door_l",
			"prop_cs6_03_door_r",
			"prop_cs_20m_rope",
			"prop_cs_30m_rope",
			"prop_cs_abattoir_switch",
			"prop_cs_aircon_01",
			"prop_cs_aircon_fan",
			"prop_cs_amanda_shoe",
			"prop_cs_ashtray",
			"prop_cs_bandana",
			"prop_cs_bar",
			"prop_cs_beachtowel_01",
			"prop_cs_beer_bot_01",
			"prop_cs_beer_bot_01b",
			"prop_cs_beer_bot_01lod",
			"prop_cs_beer_bot_02",
			"prop_cs_beer_bot_40oz_03",
			"prop_cs_beer_bot_test",
			"prop_cs_binder_01",
			"prop_cs_bin_01",
			"prop_cs_bin_01_lid",
			"prop_cs_bin_01_skinned",
			"prop_cs_bin_02",
			"prop_cs_bin_03",
			"prop_cs_book_01",
			"prop_cs_bottle_opener",
			"prop_cs_bowie_knife",
			"prop_cs_bowl_01",
			"prop_cs_bowl_01b",
			"prop_cs_box_clothes",
			"prop_cs_box_step",
			"prop_cs_brain_chunk",
			"prop_cs_bs_cup",
			"prop_cs_bucket_s",
			"prop_cs_bucket_s_lod",
			"prop_cs_burger_01",
			"prop_cs_business_card",
			"prop_cs_cardbox_01",
			"prop_cs_cash_note_01",
			"prop_cs_cctv",
			"prop_cs_champ_flute",
			"prop_cs_ciggy_01",
			"prop_cs_ciggy_01b",
			"prop_cs_clothes_box",
			"prop_cs_coke_line",
			"prop_cs_cont_latch",
			"prop_cs_crackpipe",
			"prop_cs_credit_card",
			"prop_cs_creeper_01",
			"prop_cs_crisps_01",
			"prop_cs_cuffs_01",
			"prop_cs_diaphram",
			"prop_cs_dildo_01",
			"prop_cs_documents_01",
			"prop_cs_duffel_01",
			"prop_cs_duffel_01b",
			"prop_cs_dumpster_01a",
			"prop_cs_dumpster_lidl",
			"prop_cs_dumpster_lidr",
			"prop_cs_dvd",
			"prop_cs_dvd_case",
			"prop_cs_dvd_player",
			"prop_cs_envolope_01",
			"prop_cs_fertilizer",
			"prop_cs_film_reel_01",
			"prop_cs_folding_chair_01",
			"prop_cs_fork",
			"prop_cs_frank_photo",
			"prop_cs_freightdoor_l1",
			"prop_cs_freightdoor_r1",
			"prop_cs_fridge",
			"prop_cs_fridge_door",
			"prop_cs_fuel_hose",
			"prop_cs_fuel_nozle",
			"prop_cs_gascutter_1",
			"prop_cs_gascutter_2",
			"prop_cs_glass_scrap",
			"prop_cs_gravyard_gate_l",
			"prop_cs_gravyard_gate_r",
			"prop_cs_gunrack",
			"prop_cs_hand_radio",
			"prop_cs_heist_bag_01",
			"prop_cs_heist_bag_02",
			"prop_cs_heist_bag_strap_01",
			"prop_cs_heist_rope",
			"prop_cs_heist_rope_b",
			"prop_cs_hotdog_01",
			"prop_cs_hotdog_02",
			"prop_cs_h_bag_strap_01",
			"prop_cs_ice_locker",
			"prop_cs_ice_locker_door_l",
			"prop_cs_ice_locker_door_r",
			"prop_cs_ilev_blind_01",
			"prop_cs_ironing_board",
			"prop_cs_katana_01",
			"prop_cs_kettle_01",
			"prop_cs_keyboard_01",
			"prop_cs_keys_01",
			"prop_cs_kitchen_cab_l2",
			"prop_cs_lazlow_ponytail",
			"prop_cs_lazlow_shirt_01",
			"prop_cs_lazlow_shirt_01b",
			"prop_cs_leaf",
			"prop_cs_leg_chain_01",
			"prop_cs_lester_crate",
			"prop_cs_lipstick",
			"prop_cs_magazine",
			"prop_cs_marker_01",
			"prop_cs_meth_pipe",
			"prop_cs_milk_01",
			"prop_cs_mini_tv",
			"prop_cs_mopbucket_01",
			"prop_cs_mop_s",
			"prop_cs_mouse_01",
			"prop_cs_nail_file",
			"prop_cs_newspaper",
			"prop_cs_office_chair",
			"prop_cs_overalls_01",
			"prop_cs_package_01",
			"prop_cs_padlock",
			"prop_cs_pamphlet_01",
			"prop_cs_panel_01",
			"prop_cs_panties",
			"prop_cs_panties_02",
			"prop_cs_panties_03",
			"prop_cs_paper_cup",
			"prop_cs_para_ropebit",
			"prop_cs_para_ropes",
			"prop_cs_pebble",
			"prop_cs_pebble_02",
			"prop_cs_petrol_can",
			"prop_cs_phone_01",
			"prop_cs_photoframe_01",
			"prop_cs_pills",
			"prop_cs_plane_int_01",
			"prop_cs_planning_photo",
			"prop_cs_plant_01",
			"prop_cs_plate_01",
			"prop_cs_polaroid",
			"prop_cs_police_torch",
			"prop_cs_pour_tube",
			"prop_cs_power_cell",
			"prop_cs_power_cord",
			"prop_cs_protest_sign_01",
			"prop_cs_protest_sign_02",
			"prop_cs_rage_statue_p1",
			"prop_cs_rage_statue_p2",
			"prop_cs_remote_01",
			"prop_cs_rolled_paper",
			"prop_cs_rope_tie_01",
			"prop_cs_rub_binbag_01",
			"prop_cs_rub_box_01",
			"prop_cs_rub_box_02",
			"prop_cs_r_business_card",
			"prop_cs_sack_01",
			"prop_cs_saucer_01",
			"prop_cs_sc1_11_gate",
			"prop_cs_scissors",
			"prop_cs_script_bottle",
			"prop_cs_script_bottle_01",
			"prop_cs_server_drive",
			"prop_cs_sheers",
			"prop_cs_shirt_01",
			"prop_cs_shopping_bag",
			"prop_cs_shot_glass",
			"prop_cs_silver_tray",
			"prop_cs_sink_filler",
			"prop_cs_sink_filler_02",
			"prop_cs_sm_27_gate",
			"prop_cs_sol_glasses",
			"prop_cs_spray_can",
			"prop_cs_steak",
			"prop_cs_stock_book",
			"prop_cs_street_binbag_01",
			"prop_cs_street_card_01",
			"prop_cs_street_card_02",
			"prop_cs_sub_hook_01",
			"prop_cs_sub_rope_01",
			"prop_cs_swipe_card",
			"prop_cs_tablet",
			"prop_cs_tablet_02",
			"prop_cs_toaster",
			"prop_cs_trolley_01",
			"prop_cs_trowel",
			"prop_cs_truck_ladder",
			"prop_cs_tshirt_ball_01",
			"prop_cs_tv_stand",
			"prop_cs_t_shirt_pile",
			"prop_cs_valve",
			"prop_cs_vent_cover",
			"prop_cs_vial_01",
			"prop_cs_walkie_talkie",
			"prop_cs_walking_stick",
			"prop_cs_whiskey_bottle",
			"prop_cs_whiskey_bot_stop",
			"prop_cs_wrench",
			"prop_cub_door_lifeblurb",
			"prop_cub_lifeblurb",
			"prop_cuff_keys_01",
			"prop_cup_saucer_01",
			"prop_curl_bar_01",
			"prop_damdoor_01",
			"prop_dart_1",
			"prop_dart_2",
			"prop_dart_bd_01",
			"prop_dart_bd_cab_01",
			"prop_defilied_ragdoll_01",
			"prop_desert_iron_01",
			"prop_detergent_01a",
			"prop_detergent_01b",
			"prop_devin_box_01",
			"prop_devin_rope_01",
			"prop_diggerbkt_01",
			"prop_direct_chair_01",
			"prop_direct_chair_02",
			"prop_display_unit_01",
			"prop_display_unit_02",
			"prop_disp_cabinet_002",
			"prop_disp_cabinet_01",
			"prop_disp_razor_01",
			"prop_distantcar_day",
			"prop_distantcar_night",
			"prop_distantcar_truck",
			"prop_dj_deck_01",
			"prop_dj_deck_02",
			"prop_dock_ropefloat",
			"prop_dock_ropetyre1",
			"prop_dock_ropetyre2",
			"prop_dock_ropetyre3",
			"prop_dock_rtg_01",
			"prop_dock_rtg_ld",
			"prop_dock_shippad",
			"prop_dock_sign_01",
			"prop_dock_woodpole1",
			"prop_dock_woodpole2",
			"prop_dog_cage_01",
			"prop_dog_cage_02",
			"prop_dolly_01",
			"prop_dolly_02",
			"prop_donut_01",
			"prop_donut_02",
			"prop_donut_02b",
			"prop_door_01",
			"prop_door_balcony_frame",
			"prop_door_balcony_left",
			"prop_door_balcony_right",
			"prop_door_bell_01",
			"prop_double_grid_line",
			"prop_dress_disp_01",
			"prop_dress_disp_02",
			"prop_drop_armscrate_01",
			"prop_drop_armscrate_01b",
			"prop_drop_crate_01",
			"prop_drop_crate_01_set",
			"prop_drop_crate_01_set2",
			"prop_drug_burner",
			"prop_drug_package",
			"prop_drug_package_02",
			"prop_drywallpile_01",
			"prop_drywallpile_02",
			"prop_dt1_13_groundlight",
			"prop_dt1_13_walllightsource",
			"prop_dt1_20_mp_door_l",
			"prop_dt1_20_mp_door_r",
			"prop_dt1_20_mp_gar",
			"prop_ducktape_01",
			"prop_dummy_01",
			"prop_dummy_car",
			"prop_dummy_light",
			"prop_dummy_plane",
			"prop_dumpster_3a",
			"prop_dumpster_3step",
			"prop_dumpster_4a",
			"prop_dumpster_4b",
			"prop_d_balcony_l_light",
			"prop_d_balcony_r_light",
			"prop_ear_defenders_01",
			"prop_ecg_01",
			"prop_ecg_01_cable_01",
			"prop_ecg_01_cable_02",
			"prop_ecola_can",
			"prop_egg_clock_01",
			"prop_ejector_seat_01",
			"prop_elecbox_03a",
			"prop_elecbox_10",
			"prop_el_guitar_01",
			"prop_el_guitar_02",
			"prop_el_guitar_03",
			"prop_employee_month_01",
			"prop_employee_month_02",
			"prop_energy_drink",
			"prop_entityxf_covered",
			"prop_epsilon_door_l",
			"prop_epsilon_door_r",
			"prop_etricmotor_01",
			"prop_exer_bike_01",
			"prop_faceoffice_door_l",
			"prop_faceoffice_door_r",
			"prop_face_rag_01",
			"prop_facgate_01",
			"prop_facgate_01b",
			"prop_facgate_02pole",
			"prop_facgate_02_l",
			"prop_facgate_03post",
			"prop_facgate_08_frame",
			"prop_facgate_08_ld2",
			"prop_facgate_id1_27",
			"prop_fac_machine_02",
			"prop_fag_packet_01",
			"prop_fan_01",
			"prop_fan_palm_01a",
			"prop_fax_01",
			"prop_fbi3_coffee_table",
			"prop_fbibombbin",
			"prop_fbibombcupbrd",
			"prop_fbibombfile",
			"prop_fbibombplant",
			"prop_feeder1",
			"prop_feed_sack_01",
			"prop_feed_sack_02",
			"prop_fence_log_01",
			"prop_fence_log_02",
			"prop_ff_shelves_01",
			"prop_ff_sink_01",
			"prop_ff_sink_02",
			"prop_fib_badge",
			"prop_fib_broken_window",
			"prop_fib_skylight_piece",
			"prop_film_cam_01",
			"prop_fireescape_01a",
			"prop_fireescape_01b",
			"prop_fireescape_02a",
			"prop_fireescape_02b",
			"prop_fire_driser_1a",
			"prop_fire_hosereel",
			"prop_fishing_rod_01",
			"prop_fishing_rod_02",
			"prop_fish_slice_01",
			"prop_flagpole_1a",
			"prop_flagpole_2a",
			"prop_flagpole_3a",
			"prop_flare_01",
			"prop_flare_01b",
			"prop_flash_unit",
			"prop_flatbed_strap",
			"prop_flatbed_strap_b",
			"prop_flatscreen_overlay",
			"prop_flattrailer_01a",
			"prop_flattruck_01a",
			"prop_fleeca_atm",
			"prop_flight_box_01",
			"prop_flight_box_insert",
			"prop_flight_box_insert2",
			"prop_flipchair_01",
			"prop_floor_duster_01",
			"prop_fncconstruc_02a",
			"prop_fridge_03",
			"prop_front_seat_01",
			"prop_front_seat_02",
			"prop_front_seat_03",
			"prop_front_seat_04",
			"prop_front_seat_05",
			"prop_front_seat_06",
			"prop_front_seat_07",
			"prop_front_seat_row_01",
			"prop_fruitstand_b_nite",
			"prop_fruit_basket",
			"prop_ftowel_01",
			"prop_ftowel_07",
			"prop_ftowel_08",
			"prop_ftowel_10",
			"prop_f_b_insert_broken",
			"prop_f_duster_01_s",
			"prop_f_duster_02",
			"prop_gaffer_arm_bind",
			"prop_gaffer_arm_bind_cut",
			"prop_gaffer_leg_bind",
			"prop_gaffer_leg_bind_cut",
			"prop_gaffer_tape",
			"prop_gaffer_tape_strip",
			"prop_game_clock_01",
			"prop_game_clock_02",
			"prop_garden_dreamcatch_01",
			"prop_garden_edging_01",
			"prop_garden_edging_02",
			"prop_garden_zapper_01",
			"prop_gar_door_05_l",
			"prop_gar_door_05_r",
			"prop_gar_door_a_01",
			"prop_gar_door_plug",
			"prop_gascage01",
			"prop_gascyl_ramp_01",
			"prop_gascyl_ramp_door_01",
			"prop_gas_grenade",
			"prop_gas_mask_hang_01",
			"prop_gatecom_02",
			"prop_gate_airport_01",
			"prop_gate_bridge_ld",
			"prop_gate_cult_01_l",
			"prop_gate_cult_01_r",
			"prop_gate_docks_ld",
			"prop_gate_farm_01a",
			"prop_gate_farm_post",
			"prop_gate_frame_06",
			"prop_gate_military_01",
			"prop_gate_prison_01",
			"prop_gate_tep_01_l",
			"prop_gate_tep_01_r",
			"prop_gazebo_03",
			"prop_gd_ch2_08",
			"prop_generator_02a",
			"prop_generator_03a",
			"prop_generator_04",
			"prop_ghettoblast_02",
			"prop_girder_01a",
			"prop_glasscutter_01",
			"prop_glass_suck_holder",
			"prop_glf_roller",
			"prop_glf_spreader",
			"prop_gold_bar",
			"prop_gold_cont_01",
			"prop_gold_cont_01b",
			"prop_gold_trolly",
			"prop_gold_trolly_full",
			"prop_gold_trolly_strap_01",
			"prop_golf_bag_01",
			"prop_golf_bag_01b",
			"prop_golf_bag_01c",
			"prop_golf_ball",
			"prop_golf_ball_p2",
			"prop_golf_tee",
			"prop_golf_wood_01",
			"prop_grain_hopper",
			"prop_grapes_01",
			"prop_grapes_02",
			"prop_grass_dry_02",
			"prop_grass_dry_03",
			"prop_gravestones_01a",
			"prop_gravestones_02a",
			"prop_gravestones_03a",
			"prop_gravestones_04a",
			"prop_gravestones_05a",
			"prop_gravestones_06a",
			"prop_gravestones_07a",
			"prop_gravestones_08a",
			"prop_gravestones_09a",
			"prop_gravestones_10a",
			"prop_gravetomb_01a",
			"prop_gravetomb_02a",
			"prop_griddle_01",
			"prop_griddle_02",
			"prop_grumandoor_l",
			"prop_grumandoor_r",
			"prop_gshotsensor_01",
			"prop_gun_case_01",
			"prop_gun_case_02",
			"prop_gun_frame",
			"prop_hacky_sack_01",
			"prop_handdry_01",
			"prop_handdry_02",
			"prop_handrake",
			"prop_handtowels",
			"prop_hand_toilet",
			"prop_hanger_door_1",
			"prop_hard_hat_01",
			"prop_hat_box_01",
			"prop_hat_box_02",
			"prop_hat_box_03",
			"prop_hat_box_04",
			"prop_hat_box_05",
			"prop_hat_box_06",
			"prop_haybailer_01",
			"prop_haybale_01",
			"prop_haybale_02",
			"prop_haybale_stack_01",
			"prop_hd_seats_01",
			"prop_headphones_01",
			"prop_headset_01",
			"prop_hedge_trimmer_01",
			"prop_helipad_01",
			"prop_helipad_02",
			"prop_henna_disp_01",
			"prop_henna_disp_02",
			"prop_henna_disp_03",
			"prop_hifi_01",
			"prop_hobo_stove_01",
			"prop_hockey_bag_01",
			"prop_hole_plug_01",
			"prop_holster_01",
			"prop_homeless_matress_01",
			"prop_homeless_matress_02",
			"prop_hose_1",
			"prop_hose_2",
			"prop_hose_3",
			"prop_hose_nozzle",
			"prop_hospitaldoors_start",
			"prop_hospital_door_l",
			"prop_hospital_door_r",
			"prop_hotel_clock_01",
			"prop_hotel_trolley",
			"prop_hottub2",
			"prop_huf_rag_01",
			"prop_huge_display_01",
			"prop_huge_display_02",
			"prop_hunterhide",
			"prop_hw1_03_gardoor_01",
			"prop_hw1_04_door_l1",
			"prop_hw1_04_door_r1",
			"prop_hw1_23_door",
			"prop_hwbowl_pseat_6x1",
			"prop_hwbowl_seat_01",
			"prop_hwbowl_seat_02",
			"prop_hwbowl_seat_03",
			"prop_hwbowl_seat_03b",
			"prop_hwbowl_seat_6x6",
			"prop_hydro_platform_01",
			"prop_ice_box_01",
			"prop_ice_box_01_l1",
			"prop_ice_cube_01",
			"prop_ice_cube_02",
			"prop_ice_cube_03",
			"prop_id2_11_gdoor",
			"prop_id2_20_clock",
			"prop_idol_01",
			"prop_idol_01_error",
			"prop_idol_case",
			"prop_idol_case_01",
			"prop_idol_case_02",
			"prop_id_21_gardoor_01",
			"prop_id_21_gardoor_02",
			"prop_indus_meet_door_l",
			"prop_indus_meet_door_r",
			"prop_ind_barge_01",
			"prop_ind_barge_02",
			"prop_ind_coalcar_01",
			"prop_ind_coalcar_02",
			"prop_ind_coalcar_03",
			"prop_ind_conveyor_01",
			"prop_ind_conveyor_02",
			"prop_ind_conveyor_04",
			"prop_ind_crusher",
			"prop_ind_deiseltank",
			"prop_ind_light_01a",
			"prop_ind_light_01b",
			"prop_ind_light_01c",
			"prop_ind_mech_01c",
			"prop_ind_mech_02a",
			"prop_ind_mech_02b",
			"prop_ind_mech_03a",
			"prop_ind_mech_04a",
			"prop_ind_oldcrane",
			"prop_ind_washer_02",
			"prop_inflatearch_01",
			"prop_inflategate_01",
			"prop_ing_camera_01",
			"prop_ing_crowbar",
			"prop_inhaler_01",
			"prop_int_gate01",
			"prop_in_tray_01",
			"prop_irish_sign_01",
			"prop_irish_sign_02",
			"prop_irish_sign_03",
			"prop_irish_sign_04",
			"prop_irish_sign_05",
			"prop_irish_sign_06",
			"prop_irish_sign_07",
			"prop_irish_sign_08",
			"prop_irish_sign_09",
			"prop_irish_sign_10",
			"prop_irish_sign_11",
			"prop_irish_sign_12",
			"prop_irish_sign_13",
			"prop_iron_01",
			"prop_jb700_covered",
			"prop_jeans_01",
			"prop_jetski_ramp_01",
			"prop_jet_bloodsplat_01",
			"prop_jewel_02a",
			"prop_jewel_02b",
			"prop_jewel_02c",
			"prop_jewel_03a",
			"prop_jewel_03b",
			"prop_jewel_04a",
			"prop_jewel_04b",
			"prop_jewel_pickup_new_01",
			"prop_juice_dispenser",
			"prop_juice_pool_01",
			"prop_jukebox_01",
			"prop_jukebox_02",
			"prop_jyard_block_01a",
			"prop_j_disptray_01",
			"prop_j_disptray_01b",
			"prop_j_disptray_01_dam",
			"prop_j_disptray_02",
			"prop_j_disptray_02_dam",
			"prop_j_disptray_03",
			"prop_j_disptray_03_dam",
			"prop_j_disptray_04",
			"prop_j_disptray_04b",
			"prop_j_disptray_05",
			"prop_j_disptray_05b",
			"prop_j_heist_pic_01",
			"prop_j_heist_pic_02",
			"prop_j_heist_pic_03",
			"prop_j_heist_pic_04",
			"prop_j_neck_disp_01",
			"prop_j_neck_disp_02",
			"prop_j_neck_disp_03",
			"prop_kayak_01",
			"prop_kayak_01b",
			"prop_kebab_grill",
			"prop_keg_01",
			"prop_kettle",
			"prop_kettle_01",
			"prop_keyboard_01a",
			"prop_keyboard_01b",
			"prop_kino_light_01",
			"prop_kino_light_03",
			"prop_kitch_juicer",
			"prop_kitch_pot_fry",
			"prop_kitch_pot_huge",
			"prop_kitch_pot_lrg",
			"prop_kitch_pot_lrg2",
			"prop_kitch_pot_med",
			"prop_kitch_pot_sm",
			"prop_knife",
			"prop_knife_stand",
			"prop_kt1_06_door_l",
			"prop_kt1_06_door_r",
			"prop_kt1_10_mpdoor_l",
			"prop_kt1_10_mpdoor_r",
			"prop_ladel",
			"prop_laptop_02_closed",
			"prop_laptop_jimmy",
			"prop_laptop_lester",
			"prop_laptop_lester2",
			"prop_large_gold",
			"prop_large_gold_alt_a",
			"prop_large_gold_alt_b",
			"prop_large_gold_alt_c",
			"prop_large_gold_empty",
			"prop_lawnmower_01",
			"prop_ld_alarm_01",
			"prop_ld_alarm_01_dam",
			"prop_ld_alarm_alert",
			"prop_ld_ammo_pack_01",
			"prop_ld_ammo_pack_02",
			"prop_ld_ammo_pack_03",
			"prop_ld_armour",
			"prop_ld_balcfnc_01a",
			"prop_ld_balcfnc_02a",
			"prop_ld_balcfnc_02c",
			"prop_ld_bankdoors_02",
			"prop_ld_barrier_01",
			"prop_ld_binbag_01",
			"prop_ld_bomb",
			"prop_ld_bomb_01",
			"prop_ld_bomb_01_open",
			"prop_ld_bomb_anim",
			"prop_ld_cable",
			"prop_ld_cable_tie_01",
			"prop_ld_can_01",
			"prop_ld_case_01",
			"prop_ld_case_01_lod",
			"prop_ld_case_01_s",
			"prop_ld_contact_card",
			"prop_ld_container",
			"prop_ld_contain_dl",
			"prop_ld_contain_dl2",
			"prop_ld_contain_dr",
			"prop_ld_contain_dr2",
			"prop_ld_crate_01",
			"prop_ld_crate_lid_01",
			"prop_ld_crocclips01",
			"prop_ld_crocclips02",
			"prop_ld_dummy_rope",
			"prop_ld_fags_01",
			"prop_ld_fags_02",
			"prop_ld_fan_01",
			"prop_ld_fan_01_old",
			"prop_ld_faucet",
			"prop_ld_ferris_wheel",
			"prop_ld_fireaxe",
			"prop_ld_flow_bottle",
			"prop_ld_fragwall_01a",
			"prop_ld_garaged_01",
			"prop_ld_gold_tooth",
			"prop_ld_greenscreen_01",
			"prop_ld_handbag",
			"prop_ld_handbag_s",
			"prop_ld_hat_01",
			"prop_ld_haybail",
			"prop_ld_hdd_01",
			"prop_ld_health_pack",
			"prop_ld_hook",
			"prop_ld_int_safe_01",
			"prop_ld_jail_door",
			"prop_ld_jeans_01",
			"prop_ld_jeans_02",
			"prop_ld_jerrycan_01",
			"prop_ld_keypad_01",
			"prop_ld_keypad_01b",
			"prop_ld_keypad_01b_lod",
			"prop_ld_lap_top",
			"prop_ld_monitor_01",
			"prop_ld_peep_slider",
			"prop_ld_pipe_single_01",
			"prop_ld_planning_pin_01",
			"prop_ld_planning_pin_02",
			"prop_ld_planning_pin_03",
			"prop_ld_purse_01",
			"prop_ld_purse_01_lod",
			"prop_ld_rail_01",
			"prop_ld_rail_02",
			"prop_ld_rope_t",
			"prop_ld_rubble_01",
			"prop_ld_rubble_02",
			"prop_ld_rubble_03",
			"prop_ld_rubble_04",
			"prop_ld_rub_binbag_01",
			"prop_ld_scrap",
			"prop_ld_shirt_01",
			"prop_ld_shoe_01",
			"prop_ld_shoe_02",
			"prop_ld_shovel",
			"prop_ld_shovel_dirt",
			"prop_ld_snack_01",
			"prop_ld_suitcase_01",
			"prop_ld_suitcase_02",
			"prop_ld_test_01",
			"prop_ld_toilet_01",
			"prop_ld_tooth",
			"prop_ld_tshirt_01",
			"prop_ld_tshirt_02",
			"prop_ld_vault_door",
			"prop_ld_wallet_01",
			"prop_ld_wallet_01_s",
			"prop_ld_wallet_02",
			"prop_ld_wallet_pickup",
			"prop_ld_w_me_machette",
			"prop_leaf_blower_01",
			"prop_lectern_01",
			"prop_letterbox_04",
			"prop_lev_crate_01",
			"prop_lev_des_barge_01",
			"prop_lev_des_barge_02",
			"prop_lifeblurb_01",
			"prop_lifeblurb_01b",
			"prop_lifeblurb_02",
			"prop_lifeblurb_02b",
			"prop_life_ring_02",
			"prop_lift_overlay_01",
			"prop_lift_overlay_02",
			"prop_litter_picker",
			"prop_loggneon",
			"prop_logpile_05",
			"prop_logpile_06",
			"prop_logpile_06b",
			"prop_logpile_07",
			"prop_logpile_07b",
			"prop_log_01",
			"prop_log_02",
			"prop_log_03",
			"prop_loose_rag_01",
			"prop_lrggate_01c_l",
			"prop_lrggate_01c_r",
			"prop_lrggate_01_l",
			"prop_lrggate_01_pst",
			"prop_lrggate_01_r",
			"prop_lrggate_02_ld",
			"prop_lrggate_03a",
			"prop_lrggate_03b",
			"prop_lrggate_03b_ld",
			"prop_lrggate_04a",
			"prop_lrggate_05a",
			"prop_lrggate_06a",
			"prop_luggage_01a",
			"prop_luggage_02a",
			"prop_luggage_03a",
			"prop_luggage_04a",
			"prop_luggage_05a",
			"prop_luggage_06a",
			"prop_luggage_07a",
			"prop_luggage_08a",
			"prop_luggage_09a",
			"prop_magenta_door",
			"prop_makeup_trail_01",
			"prop_makeup_trail_02",
			"prop_map_door_01",
			"prop_mast_01",
			"prop_mat_box",
			"prop_mb_cargo_01a",
			"prop_mb_cargo_02a",
			"prop_mb_cargo_03a",
			"prop_mb_cargo_04a",
			"prop_mb_cargo_04b",
			"prop_mb_crate_01a",
			"prop_mb_crate_01a_set",
			"prop_mb_crate_01b",
			"prop_mb_hesco_06",
			"prop_mb_ordnance_01",
			"prop_mb_ordnance_03",
			"prop_mb_sandblock_01",
			"prop_mb_sandblock_02",
			"prop_mb_sandblock_03",
			"prop_mb_sandblock_04",
			"prop_mb_sandblock_05",
			"prop_medal_01",
			"prop_medstation_02",
			"prop_medstation_03",
			"prop_medstation_04",
			"prop_med_bag_01",
			"prop_med_bag_01b",
			"prop_med_jet_01",
			"prop_megaphone_01",
			"prop_mem_candle_04",
			"prop_mem_candle_05",
			"prop_mem_candle_06",
			"prop_mem_reef_01",
			"prop_mem_reef_02",
			"prop_mem_reef_03",
			"prop_mem_teddy_01",
			"prop_mem_teddy_02",
			"prop_metalfoodjar_01",
			"prop_metal_plates01",
			"prop_metal_plates02",
			"prop_meth_bag_01",
			"prop_michaels_credit_tv",
			"prop_michael_backpack",
			"prop_michael_balaclava",
			"prop_michael_door",
			"prop_michael_sec_id",
			"prop_microphone_02",
			"prop_microwave_1",
			"prop_micro_01",
			"prop_micro_02",
			"prop_micro_cs_01",
			"prop_micro_cs_01_door",
			"prop_military_pickup_01",
			"prop_mil_crate_01",
			"prop_mil_crate_02",
			"prop_minigun_01",
			"prop_mobile_mast_1",
			"prop_mobile_mast_2",
			"prop_money_bag_01", //flashmod scr_trev1_trailer_boosh scr_trevor1
			"prop_monitor_01c",
			"prop_monitor_01d",
			"prop_monitor_02",
			"prop_monitor_03b",
			"prop_motel_door_09",
			"prop_mouse_01",
			"prop_mouse_01a",
			"prop_mouse_01b",
			"prop_mouse_02",
			"prop_movie_rack",
			"prop_mp3_dock",
			"prop_mp_arrow_barrier_01",
			"prop_mp_barrier_01",
			"prop_mp_barrier_01b",
			"prop_mp_barrier_02",
			"prop_mp_barrier_02b",
			"prop_mp_base_marker",
			"prop_mp_boost_01",
			"prop_mp_cant_place_lrg",
			"prop_mp_cant_place_med",
			"prop_mp_cant_place_sm",
			"prop_mp_cone_01",
			"prop_mp_cone_02",
			"prop_mp_cone_03",
			"prop_mp_cone_04",
			"prop_mp_drug_package",
			"prop_mp_drug_pack_blue",
			"prop_mp_drug_pack_red",
			"prop_mp_icon_shad_lrg",
			"prop_mp_icon_shad_med",
			"prop_mp_icon_shad_sm",
			"prop_mp_max_out_lrg",
			"prop_mp_max_out_med",
			"prop_mp_max_out_sm",
			"prop_mp_num_0",
			"prop_mp_num_1",
			"prop_mp_num_2",
			"prop_mp_num_3",
			"prop_mp_num_4",
			"prop_mp_num_5",
			"prop_mp_num_6",
			"prop_mp_num_7",
			"prop_mp_num_8",
			"prop_mp_num_9",
			"prop_mp_placement",
			"prop_mp_placement_lrg",
			"prop_mp_placement_maxd",
			"prop_mp_placement_med",
			"prop_mp_placement_red",
			"prop_mp_placement_sm",
			"prop_mp_ramp_01",
			"prop_mp_ramp_02",
			"prop_mp_repair",
			"prop_mp_repair_01",
			"prop_mp_respawn_02",
			"prop_mp_rocket_01",
			"prop_mp_spike_01",
			"prop_mr_rasberryclean",
			"prop_mr_raspberry_01",
			"prop_muscle_bench_01",
			"prop_muscle_bench_02",
			"prop_muscle_bench_03",
			"prop_muscle_bench_04",
			"prop_muscle_bench_05",
			"prop_muscle_bench_06",
			"prop_muster_wboard_01",
			"prop_muster_wboard_02",
			"prop_m_pack_int_01",
			"prop_necklace_board",
			"prop_news_disp_02a_s",
			"prop_new_drug_pack_01",
			"prop_nigel_bag_pickup",
			"prop_night_safe_01",
			"prop_notepad_01",
			"prop_notepad_02",
			"prop_novel_01",
			"prop_npc_phone",
			"prop_npc_phone_02",
			"prop_office_alarm_01",
			"prop_office_desk_01",
			"prop_offroad_bale01",
			"prop_offroad_bale02_l1_frag_",
			"prop_offroad_barrel01",
			"prop_offroad_tyres01",
			"prop_off_chair_01",
			"prop_off_chair_03",
			"prop_off_chair_04",
			"prop_off_chair_04b",
			"prop_off_chair_04_s",
			"prop_off_chair_05",
			"prop_off_phone_01",
			"prop_oiltub_01",
			"prop_oiltub_02",
			"prop_oiltub_03",
			"prop_oiltub_05",
			"prop_oiltub_06",
			"prop_oil_derrick_01",
			"prop_oil_guage_01",
			"prop_oil_spool_02",
			"prop_oil_valve_01",
			"prop_oil_valve_02",
			"prop_oil_wellhead_01",
			"prop_oil_wellhead_03",
			"prop_oil_wellhead_04",
			"prop_oil_wellhead_05",
			"prop_oil_wellhead_06",
			"prop_oldplough1",
			"prop_old_boot",
			"prop_old_churn_01",
			"prop_old_churn_02",
			"prop_old_deck_chair",
			"prop_old_deck_chair_02",
			"prop_old_farm_01",
			"prop_old_farm_02",
			"prop_old_wood_chair",
			"prop_old_wood_chair_lod",
			"prop_orang_can_01",
			"prop_outdoor_fan_01",
			"prop_out_door_speaker",
			"prop_overalls_01",
			"prop_owl_totem_01",
			"prop_paints_can01",
			"prop_paints_can02",
			"prop_paints_can03",
			"prop_paints_can04",
			"prop_paints_can05",
			"prop_paints_can06",
			"prop_paints_can07",
			"prop_paint_brush01",
			"prop_paint_brush02",
			"prop_paint_brush03",
			"prop_paint_brush04",
			"prop_paint_brush05",
			"prop_paint_roller",
			"prop_paint_spray01a",
			"prop_paint_spray01b",
			"prop_paint_stepl01",
			"prop_paint_stepl01b",
			"prop_paint_stepl02",
			"prop_paint_tray",
			"prop_paint_wpaper01",
			"prop_pallettruck_01",
			"prop_palm_fan_02_a",
			"prop_palm_fan_02_b",
			"prop_palm_fan_03_a",
			"prop_palm_fan_03_b",
			"prop_palm_fan_03_c",
			"prop_palm_fan_03_d",
			"prop_palm_fan_04_a",
			"prop_palm_fan_04_b",
			"prop_palm_fan_04_c",
			"prop_palm_fan_04_d",
			"prop_palm_huge_01a",
			"prop_palm_huge_01b",
			"prop_palm_med_01a",
			"prop_palm_med_01b",
			"prop_palm_med_01c",
			"prop_palm_med_01d",
			"prop_palm_sm_01a",
			"prop_palm_sm_01d",
			"prop_palm_sm_01e",
			"prop_palm_sm_01f",
			"prop_paper_bag_01",
			"prop_paper_bag_small",
			"prop_paper_ball",
			"prop_paper_box_01",
			"prop_paper_box_02",
			"prop_paper_box_03",
			"prop_paper_box_04",
			"prop_paper_box_05",
			"prop_pap_camera_01",
			"prop_parachute",
			"prop_parapack_01",
			"prop_parasol_01",
			"prop_parasol_01_b",
			"prop_parasol_01_c",
			"prop_parasol_01_down",
			"prop_parasol_02",
			"prop_parasol_02_b",
			"prop_parasol_02_c",
			"prop_parasol_03",
			"prop_parasol_03_b",
			"prop_parasol_03_c",
			"prop_parasol_04e",
			"prop_parasol_04e_lod1",
			"prop_parasol_bh_48",
			"prop_parking_sign_06",
			"prop_parking_sign_07",
			"prop_parking_sign_1",
			"prop_parking_sign_2",
			"prop_parking_wand_01",
			"prop_park_ticket_01",
			"prop_partsbox_01",
			"prop_passport_01",
			"prop_patio_heater_01",
			"prop_patio_lounger1",
			"prop_patio_lounger1b",
			"prop_patio_lounger1_table",
			"prop_patio_lounger_2",
			"prop_patio_lounger_3",
			"prop_patriotneon",
			"prop_paynspray_door_l",
			"prop_paynspray_door_r",
			"prop_pc_01a",
			"prop_pc_02a",
			"prop_peanut_bowl_01",
			"prop_ped_pic_01",
			"prop_ped_pic_01_sm",
			"prop_ped_pic_02",
			"prop_ped_pic_02_sm",
			"prop_ped_pic_03",
			"prop_ped_pic_03_sm",
			"prop_ped_pic_04",
			"prop_ped_pic_04_sm",
			"prop_ped_pic_05",
			"prop_ped_pic_05_sm",
			"prop_ped_pic_06",
			"prop_ped_pic_06_sm",
			"prop_ped_pic_07",
			"prop_ped_pic_07_sm",
			"prop_ped_pic_08",
			"prop_ped_pic_08_sm",
			"prop_pencil_01",
			"prop_pharm_sign_01",
			"prop_phonebox_05a",
			"prop_phone_ing",
			"prop_phone_ing_02",
			"prop_phone_ing_03",
			"prop_phone_overlay_01",
			"prop_phone_overlay_02",
			"prop_phone_overlay_anim",
			"prop_phone_proto",
			"prop_phone_proto_back",
			"prop_phone_proto_battery",
			"prop_picnictable_02",
			"prop_piercing_gun",
			"prop_pier_kiosk_01",
			"prop_pier_kiosk_02",
			"prop_pier_kiosk_03",
			"prop_pile_dirt_01",
			"prop_pile_dirt_02",
			"prop_pile_dirt_03",
			"prop_pile_dirt_04",
			"prop_pile_dirt_06",
			"prop_pile_dirt_07",
			"prop_ping_pong",
			"prop_pipes_01a",
			"prop_pipes_01b",
			"prop_pipes_03b",
			"prop_pipes_04a",
			"prop_pipes_05a",
			"prop_pipes_conc_01",
			"prop_pipes_conc_02",
			"prop_pipe_single_01",
			"prop_pistol_holster",
			"prop_pitcher_01_cs",
			"prop_pizza_box_01",
			"prop_pizza_box_02",
			"prop_pizza_oven_01",
			"prop_planer_01",
			"prop_plant_01a",
			"prop_plant_01b",
			"prop_plant_base_01",
			"prop_plant_base_02",
			"prop_plant_base_03",
			"prop_plant_cane_01a",
			"prop_plant_cane_01b",
			"prop_plant_cane_02a",
			"prop_plant_cane_02b",
			"prop_plant_clover_01",
			"prop_plant_clover_02",
			"prop_plant_fern_01a",
			"prop_plant_fern_01b",
			"prop_plant_fern_02a",
			"prop_plant_fern_02b",
			"prop_plant_fern_02c",
			"prop_plant_flower_01",
			"prop_plant_flower_02",
			"prop_plant_flower_03",
			"prop_plant_flower_04",
			"prop_plant_group_01",
			"prop_plant_group_02",
			"prop_plant_group_03",
			"prop_plant_group_04",
			"prop_plant_group_05",
			"prop_plant_group_05b",
			"prop_plant_group_05c",
			"prop_plant_group_05d",
			"prop_plant_group_06a",
			"prop_plant_group_06b",
			"prop_plant_group_06c",
			"prop_plant_int_02a",
			"prop_plant_int_02b",
			"prop_plant_int_05a",
			"prop_plant_int_05b",
			"prop_plant_int_06a",
			"prop_plant_int_06b",
			"prop_plant_int_06c",
			"prop_plant_paradise",
			"prop_plant_paradise_b",
			"prop_plastic_cup_02",
			"prop_plas_barier_01a",
			"prop_plate_04",
			"prop_plate_stand_01",
			"prop_plate_warmer",
			"prop_player_gasmask",
			"prop_player_phone_01",
			"prop_player_phone_02",
			"prop_pliers_01",
			"prop_plywoodpile_01a",
			"prop_plywoodpile_01b",
			"prop_podium_mic",
			"prop_police_door_l",
			"prop_police_door_l_dam",
			"prop_police_door_r",
			"prop_police_door_r_dam",
			"prop_police_door_surround",
			"prop_police_phone",
			"prop_police_radio_handset",
			"prop_police_radio_main",
			"prop_poly_bag_01",
			"prop_poly_bag_money",
			"prop_poolball_1",
			"prop_poolball_10",
			"prop_poolball_11",
			"prop_poolball_12",
			"prop_poolball_13",
			"prop_poolball_14",
			"prop_poolball_15",
			"prop_poolball_2",
			"prop_poolball_3",
			"prop_poolball_4",
			"prop_poolball_5",
			"prop_poolball_6",
			"prop_poolball_7",
			"prop_poolball_8",
			"prop_poolball_9",
			"prop_poolball_cue",
			"prop_poolskimmer",
			"prop_pooltable_02",
			"prop_pooltable_3b",
			"prop_pool_ball_01",
			"prop_pool_cue",
			"prop_pool_rack_01",
			"prop_pool_rack_02",
			"prop_pool_tri",
			"prop_porn_mag_01",
			"prop_porn_mag_02",
			"prop_porn_mag_03",
			"prop_porn_mag_04",
			"prop_portable_hifi_01",
			"prop_portacabin01",
			"prop_portasteps_01",
			"prop_portasteps_02",
			"prop_postcard_rack",
			"prop_poster_tube_01",
			"prop_poster_tube_02",
			"prop_postit_drive",
			"prop_postit_gun",
			"prop_postit_it",
			"prop_postit_lock",
			"prop_potatodigger",
			"prop_pot_01",
			"prop_pot_02",
			"prop_pot_03",
			"prop_pot_04",
			"prop_pot_05",
			"prop_pot_06",
			"prop_pot_plant_02a",
			"prop_pot_plant_02b",
			"prop_pot_plant_02c",
			"prop_pot_plant_02d",
			"prop_pot_plant_03a",
			"prop_pot_plant_04a",
			"prop_pot_plant_05d_l1",
			"prop_pot_plant_bh1",
			"prop_pot_rack",
			"prop_power_cell",
			"prop_power_cord_01",
			"prop_premier_fence_01",
			"prop_premier_fence_02",
			"prop_printer_01",
			"prop_printer_02",
			"prop_pris_bars_01",
			"prop_pris_bench_01",
			"prop_pris_door_01_l",
			"prop_pris_door_01_r",
			"prop_pris_door_02",
			"prop_pris_door_03",
			"prop_prlg_gravestone_05a_l1",
			"prop_prlg_gravestone_06a",
			"prop_projector_overlay",
			"prop_prologue_phone",
			"prop_prop_tree_01",
			"prop_prop_tree_02",
			"prop_protest_sign_01",
			"prop_protest_table_01",
			"prop_prototype_minibomb",
			"prop_proxy_chateau_table",
			"prop_punch_bag_l",
			"prop_pylon_01",
			"prop_pylon_02",
			"prop_pylon_03",
			"prop_pylon_04",
			"prop_p_jack_03_col",
			"prop_p_spider_01a",
			"prop_p_spider_01c",
			"prop_p_spider_01d",
			"prop_ql_revolving_door",
			"prop_quad_grid_line",
			"prop_radiomast01",
			"prop_radiomast02",
			"prop_rad_waste_barrel_01",
			"prop_ragganeon",
			"prop_rag_01",
			"prop_railsleepers01",
			"prop_railsleepers02",
			"prop_railstack01",
			"prop_railstack02",
			"prop_railstack03",
			"prop_railstack04",
			"prop_railstack05",
			"prop_rail_boxcar",
			"prop_rail_boxcar2",
			"prop_rail_boxcar3",
			"prop_rail_boxcar4",
			"prop_rail_boxcar5",
			"prop_rail_boxcar5_d",
			"prop_rail_buffer_01",
			"prop_rail_buffer_02",
			"prop_rail_controller",
			"prop_rail_crane_01",
			"prop_rail_points01",
			"prop_rail_points02",
			"prop_rail_sigbox01",
			"prop_rail_sigbox02",
			"prop_rail_signals02",
			"prop_rail_tankcar",
			"prop_rail_tankcar2",
			"prop_rail_tankcar3",
			"prop_rail_wellcar",
			"prop_rail_wellcar2",
			"prop_range_target_01",
			"prop_range_target_02",
			"prop_range_target_03",
			"prop_rebar_pile01",
			"prop_recyclebin_02a",
			"prop_recyclebin_02b",
			"prop_recyclebin_02_c",
			"prop_recyclebin_02_d",
			"prop_recyclebin_03_a",
			"prop_recyclebin_04_a",
			"prop_recyclebin_04_b",
			"prop_recyclebin_05_a",
			"prop_ret_door",
			"prop_ret_door_02",
			"prop_ret_door_03",
			"prop_ret_door_04",
			"prop_rf_conc_pillar",
			"prop_riding_crop_01",
			"prop_riot_shield",
			"prop_rio_del_01",
			"prop_roadcone01a",
			"prop_roadcone01b",
			"prop_roadcone01c",
			"prop_roadcone02a",
			"prop_roadcone02b",
			"prop_roadcone02c",
			"prop_roadheader_01",
			"prop_rock_1_a",
			"prop_rock_1_b",
			"prop_rock_1_c",
			"prop_rock_1_d",
			"prop_rock_1_e",
			"prop_rock_1_f",
			"prop_rock_1_g",
			"prop_rock_1_h",
			"prop_rock_1_i",
			"prop_rock_2_a",
			"prop_rock_2_c",
			"prop_rock_2_d",
			"prop_rock_2_f",
			"prop_rock_2_g",
			"prop_rock_3_a",
			"prop_rock_3_b",
			"prop_rock_3_c",
			"prop_rock_3_d",
			"prop_rock_3_e",
			"prop_rock_3_f",
			"prop_rock_3_g",
			"prop_rock_3_h",
			"prop_rock_3_i",
			"prop_rock_3_j",
			"prop_rock_4_c",
			"prop_rock_4_d",
			"prop_rock_chair_01",
			"prop_rolled_sock_01",
			"prop_rolled_sock_02",
			"prop_rolled_yoga_mat",
			"prop_roller_car_01",
			"prop_roller_car_02",
			"prop_ron_door_01",
			"prop_roofpipe_01",
			"prop_roofpipe_02",
			"prop_roofpipe_03",
			"prop_roofpipe_04",
			"prop_roofpipe_05",
			"prop_roofpipe_06",
			"prop_roofvent_011a",
			"prop_roofvent_01a",
			"prop_roofvent_01b",
			"prop_roofvent_02a",
			"prop_roofvent_02b",
			"prop_roofvent_03a",
			"prop_roofvent_04a",
			"prop_roofvent_05a",
			"prop_roofvent_05b",
			"prop_roofvent_07a",
			"prop_roofvent_08a",
			"prop_roofvent_09a",
			"prop_roofvent_10a",
			"prop_roofvent_10b",
			"prop_roofvent_11b",
			"prop_roofvent_11c",
			"prop_roofvent_12a",
			"prop_roofvent_13a",
			"prop_roofvent_15a",
			"prop_roofvent_16a",
			"prop_rope_family_3",
			"prop_rope_hook_01",
			"prop_roundbailer01",
			"prop_roundbailer02",
			"prop_rub_bike_01",
			"prop_rub_bike_02",
			"prop_rub_bike_03",
			"prop_rub_binbag_sd_01",
			"prop_rub_binbag_sd_02",
			"prop_rub_busdoor_01",
			"prop_rub_busdoor_02",
			"prop_rub_buswreck_01",
			"prop_rub_buswreck_03",
			"prop_rub_buswreck_06",
			"prop_rub_cabinet",
			"prop_rub_cabinet01",
			"prop_rub_cabinet02",
			"prop_rub_cabinet03",
			"prop_rub_cage01a",
			"prop_rub_carpart_02",
			"prop_rub_carpart_03",
			"prop_rub_carpart_04",
			"prop_rub_chassis_01",
			"prop_rub_chassis_02",
			"prop_rub_chassis_03",
			"prop_rub_cont_01a",
			"prop_rub_cont_01b",
			"prop_rub_cont_01c",
			"prop_rub_flotsam_01",
			"prop_rub_flotsam_02",
			"prop_rub_flotsam_03",
			"prop_rub_frklft",
			"prop_rub_litter_01",
			"prop_rub_litter_02",
			"prop_rub_litter_03",
			"prop_rub_litter_03b",
			"prop_rub_litter_03c",
			"prop_rub_litter_04",
			"prop_rub_litter_04b",
			"prop_rub_litter_05",
			"prop_rub_litter_06",
			"prop_rub_litter_07",
			"prop_rub_litter_09",
			"prop_rub_litter_8",
			"prop_rub_matress_01",
			"prop_rub_matress_02",
			"prop_rub_matress_03",
			"prop_rub_matress_04",
			"prop_rub_monitor",
			"prop_rub_pile_01",
			"prop_rub_pile_02",
			"prop_rub_planks_01",
			"prop_rub_planks_02",
			"prop_rub_planks_03",
			"prop_rub_planks_04",
			"prop_rub_railwreck_1",
			"prop_rub_railwreck_2",
			"prop_rub_railwreck_3",
			"prop_rub_scrap_02",
			"prop_rub_scrap_03",
			"prop_rub_scrap_04",
			"prop_rub_scrap_05",
			"prop_rub_scrap_06",
			"prop_rub_scrap_07",
			"prop_rub_stool",
			"prop_rub_sunktyre",
			"prop_rub_t34",
			"prop_rub_trainers_01",
			"prop_rub_trolley01a",
			"prop_rub_trolley02a",
			"prop_rub_trolley03a",
			"prop_rub_trukwreck_1",
			"prop_rub_trukwreck_2",
			"prop_rub_tyre_01",
			"prop_rub_tyre_02",
			"prop_rub_tyre_03",
			"prop_rub_tyre_dam1",
			"prop_rub_tyre_dam2",
			"prop_rub_tyre_dam3",
			"prop_rub_washer_01",
			"prop_rub_wheel_01",
			"prop_rub_wheel_02",
			"prop_rub_wreckage_3",
			"prop_rub_wreckage_4",
			"prop_rub_wreckage_5",
			"prop_rub_wreckage_6",
			"prop_rub_wreckage_7",
			"prop_rub_wreckage_8",
			"prop_rub_wreckage_9",
			"prop_rural_windmill_l1",
			"prop_rural_windmill_l2",
			"prop_rus_olive",
			"prop_rus_olive_wint",
			"prop_sacktruck_01",
			"prop_sacktruck_02a",
			"prop_safety_glasses",
			"prop_sam_01",
			"prop_sandwich_01",
			"prop_satdish_2_a",
			"prop_satdish_2_f",
			"prop_satdish_2_g",
			"prop_satdish_3_b",
			"prop_satdish_3_c",
			"prop_satdish_3_d",
			"prop_satdish_l_01",
			"prop_satdish_s_03",
			"prop_satdish_s_05a",
			"prop_satdish_s_05b",
			"prop_sc1_06_gate_l",
			"prop_sc1_06_gate_r",
			"prop_sc1_12_door",
			"prop_sc1_21_g_door_01",
			"prop_scaffold_pole",
			"prop_scafold_01a",
			"prop_scafold_01c",
			"prop_scafold_01f",
			"prop_scafold_02a",
			"prop_scafold_02c",
			"prop_scafold_03a",
			"prop_scafold_03b",
			"prop_scafold_03c",
			"prop_scafold_03f",
			"prop_scafold_04a",
			"prop_scafold_05a",
			"prop_scafold_06a",
			"prop_scafold_06b",
			"prop_scafold_06c",
			"prop_scafold_07a",
			"prop_scafold_08a",
			"prop_scafold_09a",
			"prop_scafold_frame1a",
			"prop_scafold_frame1b",
			"prop_scafold_frame1c",
			"prop_scafold_frame1f",
			"prop_scafold_frame2a",
			"prop_scafold_frame2b",
			"prop_scafold_frame2c",
			"prop_scafold_frame3a",
			"prop_scafold_frame3c",
			"prop_scafold_rail_01",
			"prop_scafold_rail_02",
			"prop_scafold_rail_03",
			"prop_scafold_xbrace",
			"prop_scalpel",
			"prop_scn_police_torch",
			"prop_scourer_01",
			"prop_scrap_2_crate",
			"prop_scrap_win_01",
			"prop_scrim_01",
			"prop_scythemower",
			"prop_section_garage_01",
			"prop_securityvan_lightrig",
			"prop_security_case_01",
			"prop_security_case_02",
			"prop_sec_gate_01b",
			"prop_sec_gate_01c",
			"prop_sec_gate_01d",
			"prop_set_generator_01",
			"prop_sewing_fabric",
			"prop_sewing_machine",
			"prop_sglasses_stand_01",
			"prop_sglasses_stand_02",
			"prop_sglasses_stand_02b",
			"prop_sglasses_stand_03",
			"prop_sglasss_1b_lod",
			"prop_sglasss_1_lod",
			"prop_shamal_crash",
			"prop_shelves_01",
			"prop_shelves_02",
			"prop_shelves_03",
			"prop_shopping_bags01",
			"prop_shopping_bags02",
			"prop_shop_front_door_l",
			"prop_shop_front_door_r",
			"prop_shots_glass_cs",
			"prop_shower_01",
			"prop_shower_rack_01",
			"prop_shower_towel",
			"prop_showroom_door_l",
			"prop_showroom_door_r",
			"prop_showroom_glass_1b",
			"prop_shredder_01",
			"prop_shrub_rake",
			"prop_shuttering01",
			"prop_shuttering02",
			"prop_shuttering03",
			"prop_shuttering04",
			"prop_sh_beer_pissh_01",
			"prop_sh_bong_01",
			"prop_sh_cigar_01",
			"prop_sh_joint_01",
			"prop_sh_mr_rasp_01",
			"prop_sh_shot_glass",
			"prop_sh_tall_glass",
			"prop_sh_tt_fridgedoor",
			"prop_sh_wine_glass",
			"prop_side_lights",
			"prop_side_spreader",
			"prop_sign_airp_01a",
			"prop_sign_airp_02a",
			"prop_sign_airp_02b",
			"prop_sign_big_01",
			"prop_sign_mallet",
			"prop_sign_road_04g_l1",
			"prop_single_grid_line",
			"prop_single_rose",
			"prop_sink_01",
			"prop_sink_02",
			"prop_sink_03",
			"prop_sink_04",
			"prop_sink_05",
			"prop_sink_06",
			"prop_skate_flatramp",
			"prop_skate_funbox",
			"prop_skate_halfpipe",
			"prop_skate_kickers",
			"prop_skate_quartpipe",
			"prop_skate_rail",
			"prop_skate_spiner",
			"prop_skid_chair_01",
			"prop_skid_chair_02",
			"prop_skid_chair_03",
			"prop_skid_sleepbag_1",
			"prop_skid_tent_01",
			"prop_skid_tent_01b",
			"prop_skid_tent_03",
			"prop_skip_01a",
			"prop_skip_02a",
			"prop_skip_03",
			"prop_skip_04",
			"prop_skip_05a",
			"prop_skip_05b",
			"prop_skip_06a",
			"prop_skip_08a",
			"prop_skip_08b",
			"prop_skip_10a",
			"prop_skip_rope_01",
			"prop_skunk_bush_01",
			"prop_skylight_01",
			"prop_skylight_02",
			"prop_skylight_03",
			"prop_skylight_04",
			"prop_skylight_05",
			"prop_skylight_06a",
			"prop_skylight_06b",
			"prop_skylight_06c",
			"prop_sky_cover_01",
			"prop_slacks_01",
			"prop_slacks_02",
			"prop_sluicegate",
			"prop_sluicegatel",
			"prop_sluicegater",
			"prop_slush_dispenser",
			"prop_sm1_11_doorl",
			"prop_sm1_11_doorr",
			"prop_sm1_11_garaged",
			"prop_smg_holster_01",
			"prop_sm_10_mp_door",
			"prop_sm_14_mp_gar",
			"prop_sm_19_clock",
			"prop_sm_27_door",
			"prop_sm_27_gate",
			"prop_sm_27_gate_02",
			"prop_sm_27_gate_03",
			"prop_sm_27_gate_04",
			"prop_sm_locker_door",
			"prop_snow_bailer_01",
			"prop_snow_barrel_pile_03",
			"prop_snow_bench_01",
			"prop_snow_bin_01",
			"prop_snow_bin_02",
			"prop_snow_bush_01_a",
			"prop_snow_bush_02_a",
			"prop_snow_bush_02_b",
			"prop_snow_bush_03",
			"prop_snow_bush_04",
			"prop_snow_bush_04b",
			"prop_snow_cam_03",
			"prop_snow_cam_03a",
			"prop_snow_diggerbkt_01",
			"prop_snow_dumpster_01",
			"prop_snow_elecbox_16",
			"prop_snow_facgate_01",
			"prop_snow_field_01",
			"prop_snow_field_02",
			"prop_snow_field_03",
			"prop_snow_field_04",
			"prop_snow_flower_01",
			"prop_snow_flower_02",
			"prop_snow_fnclink_03crnr2",
			"prop_snow_fnclink_03h",
			"prop_snow_fnclink_03i",
			"prop_snow_fncwood_14a",
			"prop_snow_fncwood_14b",
			"prop_snow_fncwood_14c",
			"prop_snow_fncwood_14d",
			"prop_snow_fncwood_14e",
			"prop_snow_fnc_01",
			"prop_snow_gate_farm_03",
			"prop_snow_grain_01",
			"prop_snow_grass_01",
			"prop_snow_light_01",
			"prop_snow_oldlight_01b",
			"prop_snow_rail_signals02",
			"prop_snow_rub_trukwreck_2",
			"prop_snow_side_spreader_01",
			"prop_snow_streetlight01",
			"prop_snow_streetlight_01_frag_",
			"prop_snow_sub_frame_01a",
			"prop_snow_sub_frame_04b",
			"prop_snow_telegraph_01a",
			"prop_snow_telegraph_02a",
			"prop_snow_telegraph_03",
			"prop_snow_traffic_rail_1a",
			"prop_snow_traffic_rail_1b",
			"prop_snow_trailer01",
			"prop_snow_tree_03_e",
			"prop_snow_tree_03_h",
			"prop_snow_tree_03_i",
			"prop_snow_tree_04_d",
			"prop_snow_tree_04_f",
			"prop_snow_truktrailer_01a",
			"prop_snow_tyre_01",
			"prop_snow_t_ml_01",
			"prop_snow_t_ml_02",
			"prop_snow_t_ml_03",
			"prop_snow_wall_light_15a",
			"prop_snow_watertower01",
			"prop_snow_watertower01_l2",
			"prop_snow_watertower03",
			"prop_snow_woodpile_04a",
			"prop_soap_disp_01",
			"prop_soap_disp_02",
			"prop_solarpanel_01",
			"prop_solarpanel_02",
			"prop_solarpanel_03",
			"prop_sol_chair",
			"prop_space_pistol",
			"prop_space_rifle",
			"prop_speaker_01",
			"prop_speaker_02",
			"prop_speaker_03",
			"prop_speaker_05",
			"prop_speaker_06",
			"prop_speaker_07",
			"prop_speaker_08",
			"prop_speedball_01",
			"prop_sponge_01",
			"prop_sports_clock_01",
			"prop_spot_01",
			"prop_spot_clamp",
			"prop_spot_clamp_02",
			"prop_sprayer",
			"prop_spraygun_01",
			"prop_spray_backpack_01",
			"prop_spray_jackframe",
			"prop_spray_jackleg",
			"prop_sprink_crop_01",
			"prop_sprink_golf_01",
			"prop_sprink_park_01",
			"prop_spycam",
			"prop_squeegee",
			"prop_ss1_05_mp_door",
			"prop_ss1_08_mp_door_l",
			"prop_ss1_08_mp_door_r",
			"prop_ss1_10_door_l",
			"prop_ss1_10_door_r",
			"prop_ss1_14_garage_door",
			"prop_ss1_mpint_door_l",
			"prop_ss1_mpint_door_r",
			"prop_ss1_mpint_garage",
			"prop_ss1_mpint_garage_cl",
			"prop_stag_do_rope",
			"prop_start_finish_line_01",
			"prop_start_grid_01",
			"prop_staticmixer_01",
			"prop_stat_pack_01",
			"prop_steam_basket_01",
			"prop_steam_basket_02",
			"prop_steps_big_01",
			"prop_stickbfly",
			"prop_stickhbird",
			"prop_still",
			"prop_stockade_wheel",
			"prop_stockade_wheel_flat",
			"prop_stool_01",
			"prop_storagetank_01",
			"prop_storagetank_02",
			"prop_storagetank_03",
			"prop_storagetank_03a",
			"prop_storagetank_03b",
			"prop_storagetank_04",
			"prop_storagetank_05",
			"prop_storagetank_06",
			"prop_storagetank_07a",
			"prop_stripmenu",
			"prop_strip_door_01",
			"prop_strip_pole_01",
			"prop_studio_light_02",
			"prop_studio_light_03",
			"prop_sub_chunk_01",
			"prop_sub_cover_01",
			"prop_sub_crane_hook",
			"prop_sub_frame_01a",
			"prop_sub_frame_01b",
			"prop_sub_frame_01c",
			"prop_sub_frame_02a",
			"prop_sub_frame_03a",
			"prop_sub_frame_04a",
			"prop_sub_frame_04b",
			"prop_sub_gantry",
			"prop_sub_release",
			"prop_sub_trans_01a",
			"prop_sub_trans_02a",
			"prop_sub_trans_03a",
			"prop_sub_trans_04a",
			"prop_sub_trans_05b",
			"prop_sub_trans_06b",
			"prop_suitcase_01",
			"prop_suitcase_01b",
			"prop_suitcase_01c",
			"prop_suitcase_01d",
			"prop_suitcase_02",
			"prop_suitcase_03",
			"prop_suitcase_03b",
			"prop_surf_board_ldn_01",
			"prop_surf_board_ldn_02",
			"prop_surf_board_ldn_03",
			"prop_surf_board_ldn_04",
			"prop_syringe_01",
			"prop_s_pine_dead_01",
			"prop_tablesaw_01",
			"prop_tablesmall_01",
			"prop_table_02",
			"prop_table_03b_cs",
			"prop_table_04",
			"prop_table_04_chr",
			"prop_table_05",
			"prop_table_05_chr",
			"prop_table_06",
			"prop_table_06_chr",
			"prop_table_07",
			"prop_table_07_l1",
			"prop_table_08",
			"prop_table_08_chr",
			"prop_table_08_side",
			"prop_table_mic_01",
			"prop_table_para_comb_04",
			"prop_table_tennis",
			"prop_table_ten_bat",
			"prop_taco_01",
			"prop_taco_02",
			"prop_tail_gate_col",
			"prop_tapeplayer_01",
			"prop_target_arm",
			"prop_target_arm_b",
			"prop_target_arm_long",
			"prop_target_arm_sm",
			"prop_target_backboard",
			"prop_target_backboard_b",
			"prop_target_blue",
			"prop_target_blue_arrow",
			"prop_target_bull",
			"prop_target_bull_b",
			"prop_target_comp_metal",
			"prop_target_comp_wood",
			"prop_target_frame_01",
			"prop_target_inner1",
			"prop_target_inner2",
			"prop_target_inner2_b",
			"prop_target_inner3",
			"prop_target_inner3_b",
			"prop_target_inner_b",
			"prop_target_orange_arrow",
			"prop_target_oran_cross",
			"prop_target_ora_purp_01",
			"prop_target_purp_arrow",
			"prop_target_purp_cross",
			"prop_target_red",
			"prop_target_red_arrow",
			"prop_target_red_blue_01",
			"prop_target_red_cross",
			"prop_tarp_strap",
			"prop_taxi_meter_1",
			"prop_taxi_meter_2",
			"prop_tea_trolly",
			"prop_tea_urn",
			"prop_telegraph_01a",
			"prop_telegraph_01b",
			"prop_telegraph_01c",
			"prop_telegraph_01d",
			"prop_telegraph_01e",
			"prop_telegraph_01f",
			"prop_telegraph_01g",
			"prop_telegraph_02a",
			"prop_telegraph_02b",
			"prop_telegraph_03",
			"prop_telegraph_04a",
			"prop_telegraph_04b",
			"prop_telegraph_05a",
			"prop_telegraph_05b",
			"prop_telegraph_05c",
			"prop_telegraph_06a",
			"prop_telegraph_06b",
			"prop_telegraph_06c",
			"prop_telegwall_01a",
			"prop_telegwall_01b",
			"prop_telegwall_02a",
			"prop_telegwall_03a",
			"prop_telegwall_03b",
			"prop_telegwall_04a",
			"prop_telescope",
			"prop_telescope_01",
			"prop_temp_block_blocker",
			"prop_tennis_bag_01",
			"prop_tennis_ball",
			"prop_tennis_ball_lobber",
			"prop_tennis_rack_01",
			"prop_tennis_rack_01b",
			"prop_test_boulder_01",
			"prop_test_boulder_02",
			"prop_test_boulder_03",
			"prop_test_boulder_04",
			"prop_test_elevator",
			"prop_test_elevator_dl",
			"prop_test_elevator_dr",
			"prop_tick",
			"prop_tick_02",
			"prop_till_01_dam",
			"prop_till_02",
			"prop_till_03",
			"prop_time_capsule_01",
			"prop_tint_towel",
			"prop_tint_towels_01",
			"prop_tint_towels_01b",
			"prop_toaster_01",
			"prop_toaster_02",
			"prop_toiletfoot_static",
			"prop_toilet_01",
			"prop_toilet_02",
			"prop_toilet_03",
			"prop_toilet_brush_01",
			"prop_toilet_cube_01",
			"prop_toilet_cube_02",
			"prop_toilet_roll_01",
			"prop_toilet_roll_02",
			"prop_toilet_roll_03",
			"prop_toilet_roll_04",
			"prop_toilet_roll_05",
			"prop_toilet_shamp_01",
			"prop_toilet_shamp_02",
			"prop_toilet_soap_01",
			"prop_toilet_soap_02",
			"prop_toilet_soap_03",
			"prop_toilet_soap_04",
			"prop_toolchest_01",
			"prop_toolchest_02",
			"prop_toolchest_03",
			"prop_toolchest_04",
			"prop_toolchest_05",
			"prop_tool_adjspanner",
			"prop_tool_bench01",
			"prop_tool_bluepnt",
			"prop_tool_box_01",
			"prop_tool_box_02",
			"prop_tool_box_03",
			"prop_tool_box_04",
			"prop_tool_box_05",
			"prop_tool_box_06",
			"prop_tool_box_07",
			"prop_tool_broom",
			"prop_tool_broom2",
			"prop_tool_broom2_l1",
			"prop_tool_cable01",
			"prop_tool_cable02",
			"prop_tool_consaw",
			"prop_tool_drill",
			"prop_tool_fireaxe",
			"prop_tool_hammer",
			"prop_tool_hardhat",
			"prop_tool_jackham",
			"prop_tool_mallet",
			"prop_tool_mopbucket",
			"prop_tool_nailgun",
			"prop_tool_pickaxe",
			"prop_tool_pliers",
			"prop_tool_rake",
			"prop_tool_rake_l1",
			"prop_tool_sawhorse",
			"prop_tool_screwdvr01",
			"prop_tool_screwdvr02",
			"prop_tool_screwdvr03",
			"prop_tool_shovel",
			"prop_tool_shovel006",
			"prop_tool_shovel2",
			"prop_tool_shovel3",
			"prop_tool_shovel4",
			"prop_tool_shovel5",
			"prop_tool_sledgeham",
			"prop_tool_spanner01",
			"prop_tool_spanner02",
			"prop_tool_spanner03",
			"prop_tool_torch",
			"prop_tool_wrench",
			"prop_toothbrush_01",
			"prop_toothb_cup_01",
			"prop_toothpaste_01",
			"prop_tornado_wheel",
			"prop_torture_01",
			"prop_torture_ch_01",
			"prop_tourist_map_01",
			"prop_towel2_01",
			"prop_towel2_02",
			"prop_towel_01",
			"prop_towel_rail_01",
			"prop_towel_rail_02",
			"prop_towel_shelf_01",
			"prop_towel_small_01",
			"prop_towercrane_01a",
			"prop_towercrane_02a",
			"prop_towercrane_02b",
			"prop_towercrane_02c",
			"prop_towercrane_02d",
			"prop_towercrane_02e",
			"prop_towercrane_02el",
			"prop_towercrane_02el2",
			"prop_traffic_rail_1c",
			"prop_traffic_rail_2",
			"prop_trailer01",
			"prop_trailer01_up",
			"prop_trailer_01_new",
			"prop_trailer_door_closed",
			"prop_trailer_door_open",
			"prop_trailer_monitor_01",
			"prop_trailr_base",
			"prop_trailr_base_static",
			"prop_train_ticket_02",
			"prop_tram_pole_double01",
			"prop_tram_pole_double02",
			"prop_tram_pole_double03",
			"prop_tram_pole_roadside",
			"prop_tram_pole_single01",
			"prop_tram_pole_single02",
			"prop_tram_pole_wide01",
			"prop_tree_birch_01",
			"prop_tree_birch_02",
			"prop_tree_birch_03",
			"prop_tree_birch_03b",
			"prop_tree_birch_04",
			"prop_tree_birch_05",
			"prop_tree_cedar_02",
			"prop_tree_cedar_03",
			"prop_tree_cedar_04",
			"prop_tree_cedar_s_01",
			"prop_tree_cedar_s_02",
			"prop_tree_cedar_s_04",
			"prop_tree_cedar_s_05",
			"prop_tree_cedar_s_06",
			"prop_tree_cypress_01",
			"prop_tree_eng_oak_01",
			"prop_tree_eucalip_01",
			"prop_tree_fallen_01",
			"prop_tree_fallen_02",
			"prop_tree_fallen_pine_01",
			"prop_tree_jacada_01",
			"prop_tree_jacada_02",
			"prop_tree_lficus_02",
			"prop_tree_lficus_03",
			"prop_tree_lficus_05",
			"prop_tree_lficus_06",
			"prop_tree_log_01",
			"prop_tree_log_02",
			"prop_tree_maple_02",
			"prop_tree_maple_03",
			"prop_tree_mquite_01",
			"prop_tree_oak_01",
			"prop_tree_olive_01",
			"prop_tree_pine_01",
			"prop_tree_pine_02",
			"prop_tree_stump_01",
			"prop_trevor_rope_01",
			"prop_trev_sec_id",
			"prop_trev_tv_01",
			"prop_triple_grid_line",
			"prop_tri_finish_banner",
			"prop_tri_pod",
			"prop_tri_pod_lod",
			"prop_tri_start_banner",
			"prop_tri_table_01",
			"prop_trough1",
			"prop_truktrailer_01a",
			"prop_tshirt_box_02",
			"prop_tshirt_shelf_1",
			"prop_tshirt_shelf_2",
			"prop_tshirt_shelf_2a",
			"prop_tshirt_shelf_2b",
			"prop_tshirt_shelf_2c",
			"prop_tshirt_stand_01",
			"prop_tshirt_stand_01b",
			"prop_tshirt_stand_02",
			"prop_tshirt_stand_04",
			"prop_tt_screenstatic",
			"prop_tumbler_01",
			"prop_tumbler_01b",
			"prop_tumbler_01_empty",
			"prop_tunnel_liner01",
			"prop_tunnel_liner02",
			"prop_tunnel_liner03",
			"prop_turkey_leg_01",
			"prop_turnstyle_01",
			"prop_tv_02",
			"prop_tv_03_overlay",
			"prop_tv_04",
			"prop_tv_05",
			"prop_tv_06",
			"prop_tv_07",
			"prop_tv_cabinet_03",
			"prop_tv_cabinet_04",
			"prop_tv_cabinet_05",
			"prop_tv_cam_02",
			"prop_tv_flat_01",
			"prop_tv_flat_01_screen",
			"prop_tv_flat_02b",
			"prop_tv_flat_03",
			"prop_tv_flat_03b",
			"prop_tv_flat_michael",
			"prop_tv_test",
			"prop_tyre_rack_01",
			"prop_tyre_spike_01",
			"prop_t_coffe_table",
			"prop_t_shirt_ironing",
			"prop_t_shirt_row_01",
			"prop_t_shirt_row_02",
			"prop_t_shirt_row_02b",
			"prop_t_shirt_row_03",
			"prop_t_shirt_row_04",
			"prop_t_shirt_row_05l",
			"prop_t_shirt_row_05r",
			"prop_t_sofa",
			"prop_t_sofa_02",
			"prop_t_telescope_01b",
			"prop_umpire_01",
			"prop_utensil",
			"prop_valet_03",
			"prop_vault_shutter",
			"prop_vb_34_tencrt_lighting",
			"prop_vcr_01",
			"prop_veg_corn_01",
			"prop_veg_crop_01",
			"prop_veg_crop_02",
			"prop_veg_crop_04",
			"prop_veg_crop_04_leaf",
			"prop_veg_crop_05",
			"prop_veg_crop_06",
			"prop_veg_crop_orange",
			"prop_veg_crop_tr_01",
			"prop_veg_crop_tr_02",
			"prop_veg_grass_01_a",
			"prop_veg_grass_01_b",
			"prop_veg_grass_01_c",
			"prop_veg_grass_01_d",
			"prop_veg_grass_02_a",
			"prop_vehicle_hook",
			"prop_vend_coffe_01",
			"prop_vend_condom_01",
			"prop_vend_fags_01",
			"prop_vend_fridge01",
			"prop_vend_snak_01",
			"prop_venice_board_01",
			"prop_venice_board_02",
			"prop_venice_board_03",
			"prop_venice_counter_01",
			"prop_venice_counter_02",
			"prop_venice_counter_03",
			"prop_venice_counter_04",
			"prop_venice_shop_front_01",
			"prop_venice_sign_09",
			"prop_venice_sign_10",
			"prop_venice_sign_11",
			"prop_venice_sign_12",
			"prop_venice_sign_14",
			"prop_venice_sign_15",
			"prop_venice_sign_16",
			"prop_venice_sign_17",
			"prop_venice_sign_18",
			"prop_ventsystem_01",
			"prop_ventsystem_02",
			"prop_ventsystem_03",
			"prop_ventsystem_04",
			"prop_ven_market_stool",
			"prop_ven_market_table1",
			"prop_ven_shop_1_counter",
			"prop_vertdrill_01",
			"prop_voltmeter_01",
			"prop_v_15_cars_clock",
			"prop_v_5_bclock",
			"prop_v_bmike_01",
			"prop_v_cam_01",
			"prop_v_door_44",
			"prop_v_hook_s",
			"prop_v_m_phone_01",
			"prop_v_m_phone_o1s",
			"prop_v_parachute",
			"prop_waiting_seat_01",
			"prop_wait_bench_01",
			"prop_walllight_ld_01b",
			"prop_wall_light_08a",
			"prop_wall_light_10a",
			"prop_wall_light_10b",
			"prop_wall_light_10c",
			"prop_wall_light_11",
			"prop_wall_light_12",
			"prop_wall_light_17b",
			"prop_wall_light_18a",
			"prop_wall_vent_01",
			"prop_wall_vent_02",
			"prop_wall_vent_03",
			"prop_wall_vent_04",
			"prop_wall_vent_05",
			"prop_wall_vent_06",
			"prop_wardrobe_door_01",
			"prop_warehseshelf01",
			"prop_warehseshelf02",
			"prop_warehseshelf03",
			"prop_warninglight_01",
			"prop_washer_01",
			"prop_washer_02",
			"prop_washer_03",
			"prop_washing_basket_01",
			"prop_watercrate_01",
			"prop_wateringcan",
			"prop_watertower01",
			"prop_watertower02",
			"prop_watertower03",
			"prop_watertower04",
			"prop_waterwheela",
			"prop_waterwheelb",
			"prop_water_bottle",
			"prop_water_bottle_dark",
			"prop_water_corpse_01",
			"prop_water_corpse_02",
			"prop_water_ramp_01",
			"prop_water_ramp_02",
			"prop_water_ramp_03",
			"prop_weed_01",
			"prop_weed_02",
			"prop_weed_block_01",
			"prop_weed_bottle",
			"prop_weed_pallet",
			"prop_weed_tub_01",
			"prop_weed_tub_01b",
			"prop_weight_10k",
			"prop_weight_15k",
			"prop_weight_1_5k",
			"prop_weight_20k",
			"prop_weight_2_5k",
			"prop_weight_5k",
			"prop_weight_rack_01",
			"prop_weight_rack_02",
			"prop_welding_mask_01",
			"prop_weld_torch",
			"prop_wheat_grass_empty",
			"prop_wheat_grass_glass",
			"prop_wheelbarrow01a",
			"prop_wheelbarrow02a",
			"prop_wheelchair_01",
			"prop_wheel_01",
			"prop_wheel_02",
			"prop_wheel_03",
			"prop_wheel_04",
			"prop_wheel_05",
			"prop_wheel_06",
			"prop_wheel_hub_01",
			"prop_wheel_hub_02_lod_02",
			"prop_wheel_rim_01",
			"prop_wheel_rim_02",
			"prop_wheel_rim_03",
			"prop_wheel_rim_04",
			"prop_wheel_rim_05",
			"prop_wheel_tyre",
			"prop_whisk",
			"prop_white_keyboard",
			"prop_winch_hook_long",
			"prop_winch_hook_short",
			"prop_windmill2",
			"prop_windmill_01_l1",
			"prop_windmill_01_slod",
			"prop_windmill_01_slod2",
			"prop_windowbox_a",
			"prop_windowbox_b",
			"prop_windowbox_broken",
			"prop_windowbox_small",
			"prop_win_plug_01",
			"prop_win_plug_01_dam",
			"prop_win_trailer_ld",
			"prop_wok",
			"prop_woodpile_02a",
			"prop_worklight_01a_l1",
			"prop_worklight_03a_l1",
			"prop_worklight_03b_l1",
			"prop_worklight_04a",
			"prop_worklight_04b_l1",
			"prop_worklight_04c_l1",
			"prop_worklight_04d_l1",
			"prop_workwall_01",
			"prop_workwall_02",
			"prop_wreckedcart",
			"prop_wrecked_buzzard",
			"prop_w_board_blank",
			"prop_w_board_blank_2",
			"prop_w_fountain_01",
			"prop_w_r_cedar_01",
			"prop_w_r_cedar_dead",
			"prop_xmas_tree_int",
			"prop_xmas_ext",
			"prop_yacht_lounger",
			"prop_yacht_seat_01",
			"prop_yacht_seat_02",
			"prop_yacht_seat_03",
			"prop_yacht_table_01",
			"prop_yacht_table_02",
			"prop_yacht_table_03",
			"prop_yaught_chair_01",
			"prop_yaught_sofa_01",
			"prop_yell_plastic_target",
			"prop_yoga_mat_01",
			"prop_yoga_mat_02",
			"prop_yoga_mat_03",
			"prop_ztype_covered",
			"p_ing_skiprope_01",
			"p_ing_skiprope_01_s",
			"p_skiprope_r_s",
			"test_prop_gravestones_04a",
			"test_prop_gravestones_05a",
			"test_prop_gravestones_07a",
			"test_prop_gravestones_08a",
			"test_prop_gravestones_09a",
			"test_prop_gravetomb_01a",
			"test_prop_gravetomb_02a",
			"prop_cs_dog_lead_a_s",
			"prop_cs_dog_lead_b_s",
			"prop_welding_mask_01_s",
			"prop_wheelchair_01_s",
			"p_a4_sheets_s",
			"p_amanda_note_01_s",
			"p_armchair_01_s",
			"p_arm_bind_cut_s",
			"p_ashley_neck_01_s",
			"p_banknote_onedollar_s",
			"p_banknote_s",
			"p_binbag_01_s",
			"p_bison_winch_s",
			"p_bloodsplat_s",
			"p_blueprints_01_s",
			"p_brain_chunk_s",
			"p_bs_map_door_01_s",
			"p_cablecar_s",
			"p_cablecar_s_door_l",
			"p_cablecar_s_door_r",
			"p_cash_envelope_01_s",
			"p_cctv_s",
			"p_chem_vial_02b_s",
			"p_clb_officechair_s",
			"p_cletus_necklace_s",
			"p_clothtarp_down_s",
			"p_clothtarp_s",
			"p_clothtarp_up_s",
			"p_controller_01_s",
			"p_crahsed_heli_s",
			"p_cs1_14b_train_s",
			"p_cs1_14b_train_s_col",
			"p_cs1_14b_train_s_colopen",
			"p_csbporndudes_necklace_s",
			"p_csh_strap_01_pro_s",
			"p_csh_strap_01_s",
			"p_csh_strap_03_s",
			"p_cs_15m_rope_s",
			"p_cs_bandana_s",
			"p_cs_beachtowel_01_s",
			"p_cs_beverly_lanyard_s",
			"p_cs_bowl_01b_s",
			"p_cs_ciggy_01b_s",
			"p_cs_clothes_box_s",
			"p_cs_coke_line_s",
			"p_cs_cuffs_02_s",
			"p_cs_duffel_01_s",
			"p_cs_laz_ptail_s",
			"p_cs_leaf_s",
			"p_cs_mp_jet_01_s",
			"p_cs_newspaper_s",
			"p_cs_pamphlet_01_s",
			"p_cs_panties_03_s",
			"p_cs_para_ropebit_s",
			"p_cs_para_ropes_s",
			"p_cs_polaroid_s",
			"p_cs_police_torch_s",
			"p_cs_pour_tube_s",
			"p_cs_power_cord_s",
			"p_cs_rope_tie_01_s",
			"p_cs_sack_01_s",
			"p_cs_saucer_01_s",
			"p_cs_scissors_s",
			"p_cs_script_s",
			"p_cs_shirt_01_s",
			"p_cs_shot_glass_2_s",
			"p_cs_shot_glass_s",
			"p_cs_sub_hook_01_s",
			"p_cs_toaster_s",
			"p_cs_tracy_neck2_s",
			"p_cs_trolley_01_s",
			"p_defilied_ragdoll_01_s",
			"p_devin_box_01_s",
			"p_dinechair_01_s",
			"p_d_scuba_mask_s",
			"p_d_scuba_tank_s",
			"p_ecg_01_cable_01_s",
			"p_fib_rubble_s",
			"p_finale_bld_ground_s",
			"p_finale_bld_pool_s",
			"p_fin_vaultdoor_s",
			"p_flatbed_strap_s",
			"p_folding_chair_01_s",
			"p_gaffer_tape_s",
			"p_gaffer_tape_strip_s",
			"p_gasmask_s",
			"p_gcase_s",
			"p_hand_toilet_s",
			"p_hw1_22_doors_s",
			"p_hw1_22_table_s",
			"p_ice_box_01_s",
			"p_ice_box_proxy_col",
			"p_idol_case_s",
			"p_ilev_p_easychair_s",
			"p_inhaler_01_s",
			"p_jimmyneck_03_s",
			"p_jimmy_necklace_s",
			"p_kitch_juicer_s",
			"p_lamarneck_01_s",
			"p_laptop_02_s",
			"p_large_gold_s",
			"p_lazlow_shirt_s",
			"p_laz_j01_s",
			"p_laz_j02_s",
			"p_ld_cable_tie_01_s",
			"p_ld_crocclips01_s",
			"p_ld_crocclips02_s",
			"p_ld_heist_bag_s_1",
			"p_ld_heist_bag_s_2",
			"p_ld_heist_bag_s_pro",
			"p_ld_heist_bag_s_pro2_s",
			"p_ld_heist_bag_s_pro_o",
			"p_leg_bind_cut_s",
			"p_lestersbed_s",
			"p_lev_sofa_s",
			"p_lifeinv_neck_01_s",
			"p_loose_rag_01_s",
			"p_mbbed_s",
			"p_medal_01_s",
			"p_med_jet_01_s",
			"p_meth_bag_01_s",
			"p_michael_backpack_s",
			"p_michael_scuba_mask_s",
			"p_michael_scuba_tank_s",
			"p_mp_showerdoor_s",
			"p_mrk_harness_s",
			"p_mr_raspberry_01_s",
			"p_novel_01_s",
			"p_b1rd_neck_01_s",
			"p_b1rd_neck_02_s",
			"p_orleans_mask_s",
			"p_ortega_necklace_s",
			"p_oscar_necklace_s",
			"p_overalls_02_s",
			"p_pistol_holster_s",
			"p_po1_01_doorm_s",
			"p_police_radio_hset_s",
			"p_poly_bag_01_s",
			"p_pour_wine_s",
			"p_rail_controller_s",
			"p_res_sofa_l_s",
			"p_rpulley_s",
			"p_sec_case_02_s",
			"p_shower_towel_s",
			"p_single_rose_s",
			"p_smg_holster_01_s",
			"p_soloffchair_s",
			"p_spinning_anus_s",
			"p_steve_scuba_hood_s",
			"p_stretch_necklace_s",
			"p_syringe_01_s",
			"p_s_scuba_mask_s",
			"p_s_scuba_tank_s",
			"p_till_01_s",
			"p_tmom_earrings_s",
			"p_tourist_map_01_s",
			"p_trevor_prologe_bally_s",
			"p_trev_rope_01_s",
			"p_trev_ski_mask_s",
			"p_tumbler_01_s",
			"p_tumbler_02_s1",
			"p_tumbler_cs2_s",
			"p_tv_cam_02_s",
			"p_t_shirt_pile_s",
			"p_v_43_safe_s",
			"p_v_ilev_chopshopswitch_s",
			"p_v_med_p_sofa_s",
			"p_v_res_tt_bed_s",
			"p_wade_necklace_s",
			"p_wboard_clth_s",
			"p_weed_bottle_s",
			"p_whiskey_bottle_s",
			"p_winch_long_s",
			"s_prop_hdphones",
			"s_prop_hdphones_1",
			"v_ilev_fib_door1_s",
			"v_res_msonbed_s",
			"v_res_tre_sofa_s",
			"v_tre_sofa_mess_a_s",
			"v_tre_sofa_mess_b_s",
			"v_tre_sofa_mess_c_s",
			"prop_ar_arrow_1",
			"prop_ar_arrow_2",
			"prop_ar_arrow_3",
			"prop_ar_ring_01",
			"prop_mk_arrow_3d",
			"prop_mk_arrow_flat",
			"prop_mk_bike_logo_1",
			"prop_mk_bike_logo_2",
			"prop_mk_boost",
			"prop_mk_cone",
			"prop_mk_cylinder",
			"prop_mk_flag",
			"prop_mk_flag_2",
			"prop_mk_heli",
			"prop_mk_lap",
			"prop_mk_mp_ring_01",
			"prop_mk_mp_ring_01b",
			"prop_mk_num_0",
			"prop_mk_num_1",
			"prop_mk_num_2",
			"prop_mk_num_3",
			"prop_mk_num_4",
			"prop_mk_num_5",
			"prop_mk_num_6",
			"prop_mk_num_7",
			"prop_mk_num_8",
			"prop_mk_num_9",
			"prop_mk_plane",
			"prop_mk_race_chevron_01",
			"prop_mk_race_chevron_02",
			"prop_mk_race_chevron_03",
			"prop_mk_repair",
			"prop_mk_ring",
			"prop_mk_ring_flat",
			"prop_mk_sphere",
			"prop_mk_tri_cycle",
			"prop_mk_tri_run",
			"prop_mk_tri_swim",
			"prop_mp_arrow_ring",
			"prop_mp_halo",
			"prop_mp_halo_lrg",
			"prop_mp_halo_med",
			"prop_mp_halo_point",
			"prop_mp_halo_point_lrg",
			"prop_mp_halo_point_med",
			"prop_mp_halo_point_sm",
			"prop_mp_halo_rotate",
			"prop_mp_halo_rotate_lrg",
			"prop_mp_halo_rotate_med",
			"prop_mp_halo_rotate_sm",
			"prop_mp_halo_sm",
			"prop_mp_pointer_ring",
			"prop_mp_solid_ring",
			"cj_parachute",
			"gb_cap_use",
			"gb_specs_use",
			"cj_proc_tin2",
			"proc_coral_01",
			"proc_fern_02",
			"proc_litter_01",
			"proc_litter_02",
			"proc_mntn_stone01",
			"proc_mntn_stone02",
			"proc_mntn_stone03",
			"proc_searock_01",
			"proc_searock_02",
			"proc_searock_03",
			"proc_sml_stones01",
			"proc_sml_stones02",
			"proc_sml_stones03",
			"proc_trolley_lakebed",
			"prop_bush_gorse_dry",
			"prop_bush_gorse_lush",
			"prop_coral_01",
			"prop_coral_02",
			"prop_coral_03",
			"prop_sapling_01",
			"prop_seabrain_01",
			"prop_seagroup_02",
			"prop_sealife_01",
			"prop_sealife_02",
			"prop_sealife_03",
			"prop_sealife_04",
			"prop_sealife_05",
			"prop_seaweed_01",
			"prop_seaweed_02",
			"prop_starfish_01",
			"prop_starfish_02",
			"prop_starfish_03",
			"p_dock_rtg_ld_cab",
			"p_dock_rtg_ld_spdr",
			"p_dock_rtg_ld_wheel",
			"p_amb_bag_bottle_01",
			"p_amb_brolly_01",
			"p_amb_brolly_01_s",
			"p_amb_clipboard_01",
			"p_amb_coffeecup_01",
			"p_amb_joint_01",
			"p_amb_lap_top_01",
			"p_amb_lap_top_02",
			"p_amb_phone_01",
			"p_car_keys_01",
			"p_counter_01_glass",
			"p_counter_01_glass_plug",
			"p_counter_02_glass",
			"p_counter_03_glass",
			"p_counter_04_glass",
			"p_cs_cam_phone",
			"p_cs_comb_01",
			"p_cs_laptop_02",
			"p_cs_laptop_02_w",
			"p_cs_locker_01",
			"p_cs_locker_02",
			"p_cs_locker_door_01",
			"p_cs_locker_door_01b",
			"p_cs_locker_door_02",
			"p_cs_paper_disp_02",
			"p_cs_paper_disp_1",
			"p_disp_02_door_01",
			"p_ferris_car_01",
			"p_f_duster_handle_01",
			"p_f_duster_head_01",
			"p_int_jewel_mirror",
			"p_int_jewel_plant_01",
			"p_int_jewel_plant_02",
			"p_jewel_necklace_02",
			"p_ld_am_ball_01",
			"p_ld_coffee_vend_01",
			"p_ld_conc_cyl_01",
			"p_ld_frisbee_01",
			"p_ld_heist_bag_01",
			"p_ld_sax",
			"p_ld_soc_ball_01",
			"p_new_j_counter_01",
			"p_new_j_counter_02",
			"p_new_j_counter_03",
			"p_num_plate_01",
			"p_num_plate_02",
			"p_num_plate_03",
			"p_num_plate_04",
			"p_oil_slick_01",
			"p_pharm_unit_01",
			"p_pharm_unit_02",
			"p_planning_board_01",
			"p_planning_board_02",
			"p_planning_board_03",
			"p_planning_board_04",
			"p_secret_weapon_02",
			"p_stinger_02",
			"p_stinger_03",
			"p_stinger_04",
			"p_stinger_piece_01",
			"p_stinger_piece_02",
			"p_watch_01",
			"p_watch_02",
			"p_watch_03",
			"p_watch_04",
			"p_watch_05",
			"p_watch_06",
			"p_abat_roller_1",
			"p_abat_roller_1_col",
			"p_amb_drain_water_double",
			"p_amb_drain_water_longstrip",
			"p_amb_drain_water_single",
			"p_attache_case_01_s",
			"p_balaclavamichael_s",
			"p_barierbase_test_s",
			"p_barier_test_s",
			"p_beefsplitter_s",
			"p_cargo_chute_s",
			"p_cigar_pack_02_s",
			"p_cs_locker_01_s",
			"p_cs_script_bottle_s",
			"p_dock_crane_cable_s",
			"p_dock_crane_cabl_s",
			"p_dock_crane_sld_s",
			"p_dumpster_t",
			"p_fag_packet_01_s",
			"p_ferris_wheel_amo_l",
			"p_ferris_wheel_amo_l2",
			"p_ferris_wheel_amo_p",
			"p_gar_door_01_s",
			"p_gar_door_02_s",
			"p_gar_door_03_s",
			"p_gdoor1colobject_s",
			"p_gdoor1_s",
			"p_jewel_necklace01_s",
			"p_jewel_necklace02_s",
			"p_jewel_pickup33_s",
			"p_ld_coffee_vend_s",
			"p_ld_heist_bag_s",
			"p_ld_stinger_s",
			"p_litter_picker_s",
			"p_mast_01_s",
			"p_notepad_01_s",
			"p_oil_pjack_01_amo",
			"p_oil_pjack_01_frg_s",
			"p_oil_pjack_02_amo",
			"p_oil_pjack_02_frg_s",
			"p_oil_pjack_03_amo",
			"p_oil_pjack_03_frg_s",
			"p_pallet_02a_s",
			"p_panties_s",
			"p_parachute1_mp_s",
			"p_parachute1_s",
			"p_parachute1_sp_s",
			"p_parachute_fallen_s",
			"p_parachute_s",
			"p_parachute_s_shop",
			"p_para_broken1_s",
			"p_patio_lounger1_s",
			"p_phonebox_02_s",
			"p_pliers_01_s",
			"p_rcss_folded",
			"p_rcss_s",
			"p_ringbinder_01_s",
			"p_sec_gate_01_s",
			"p_sec_gate_01_s_col",
			"p_shoalfish_s",
			"p_sofa_s",
			"p_sub_crane_s",
			"p_sunglass_m_s",
			"p_tennis_bag_01_s",
			"p_tram_crash_s",
			"p_watch_01_s",
			"p_watch_02_s",
			"p_watch_03_s",
			"p_waterboardc_s",
			"p_yacht_chair_01_s",
			"p_yacht_sofa_01_s",
			"p_yoga_mat_01_s",
			"p_yoga_mat_02_s",
			"p_yoga_mat_03_s",
			"pop_v_bank_door_l",
			"pop_v_bank_door_r",
			"p_cut_door_01",
			"p_cut_door_02",
			"p_cut_door_03",
			"p_jewel_door_l",
			"p_jewel_door_r1",
			"p_amb_bagel_01",
			"p_cs_bbbat_01",
			"p_cs_bottle_01",
			"p_cs_clipboard",
			"p_cs_joint_01",
			"p_cs_joint_02",
			"p_cs_lighter_01",
			"p_cs_papers_01",
			"p_cs_papers_02",
			"p_cs_papers_03",
			"p_ing_bagel_01",
			"p_ing_microphonel_01",
			"p_ld_bs_bag_01",
			"p_ld_id_card_002",
			"p_ld_id_card_01",
			"p_rc_handset",
			"p_whiskey_notop",
			"p_whiskey_notop_empty",
			"proc_drkyel001",
			"proc_flower1",
			"proc_flower_wild_04",
			"proc_weeds01a",
			"proc_weeds01b",
			"proc_weeds01c",
			"prop_test_bed",
			"proair_hoc_puck",
			"p_film_set_static_01",
			"rock_4_cl_2_1",
			"rock_4_cl_2_2",
			"w_am_baseball",
			"w_am_baseball_hi",
			"w_am_brfcase",
			"w_am_case",
			"w_am_digiscanner",
			"w_am_digiscanner_hi",
			"w_am_fire_exting",
			"w_am_flare",
			"w_am_flare_hi",
			"w_am_jerrycan",
			"w_ar_advancedrifle",
			"w_ar_advancedrifle_hi",
			"w_ar_advancedrifle_mag1",
			"w_ar_advancedrifle_mag2",
			"w_ar_assaultrifle",
			"w_ar_assaultrifle_hi",
			"w_ar_assaultrifle_mag1",
			"w_ar_assaultrifle_mag2",
			"w_ar_carbinerifle",
			"w_ar_carbinerifle_hi",
			"w_ar_carbinerifle_mag1",
			"w_ar_carbinerifle_mag2",
			"w_at_ar_afgrip",
			"w_at_ar_afgrip_hi",
			"w_at_ar_flsh",
			"w_at_ar_flsh_hi",
			"w_at_ar_supp",
			"w_at_ar_supp_02",
			"w_at_ar_supp_02_hi",
			"w_at_ar_supp_hi",
			"w_at_pi_flsh",
			"w_at_pi_flsh_hi",
			"w_at_pi_supp",
			"w_at_pi_supp_hi",
			"w_at_railcover_01",
			"w_at_railcover_01_hi",
			"w_at_scope_large",
			"w_at_scope_large_hi",
			"w_at_scope_macro",
			"w_at_scope_macro_hi",
			"w_at_scope_max",
			"w_at_scope_max_hi",
			"w_at_scope_medium",
			"w_at_scope_medium_hi",
			"w_at_scope_small",
			"w_at_scope_small_hi",
			"w_at_sr_supp",
			"w_at_sr_supp_hi",
			"w_ex_grenadefrag",
			"w_ex_grenadefrag_hi",
			"w_ex_grenadesmoke",
			"w_ex_molotov",
			"w_ex_molotov_hi",
			"w_ex_pe",
			"w_ex_pe_hi",
			"w_lr_40mm",
			"w_lr_40mm_pu",
			"w_lr_grenadelauncher",
			"w_lr_grenadelauncher_hi",
			"w_lr_rpg",
			"w_lr_rpg_hi",
			"w_lr_rpg_rocket",
			"w_lr_rpg_rocket_pu",
			"w_me_bat",
			"w_me_crowbar",
			"w_me_gclub",
			"w_me_hammer",
			"w_me_knife_01",
			"w_me_nightstick",
			"w_mg_combatmg",
			"w_mg_combatmg_hi",
			"w_mg_combatmg_mag1",
			"w_mg_combatmg_mag2",
			"w_mg_mg",
			"w_mg_mg_hi",
			"w_mg_mg_mag1",
			"w_mg_mg_mag2",
			"w_mg_minigun",
			"w_mg_minigun_hi",
			"w_pi_appistol",
			"w_pi_appistol_hi",
			"w_pi_appistol_mag1",
			"w_pi_appistol_mag2",
			"w_pi_combatpistol",
			"w_pi_combatpistol_hi",
			"w_pi_combatpistol_mag1",
			"w_pi_combatpistol_mag2",
			"w_pi_pistol",
			"w_pi_pistol50",
			"w_pi_pistol50_hi",
			"w_pi_pistol50_mag1",
			"w_pi_pistol50_mag2",
			"w_pi_pistol_hi",
			"w_pi_pistol_mag1",
			"w_pi_pistol_mag2",
			"w_pi_stungun",
			"w_pi_stungun_hi",
			"w_sb_assaultsmg",
			"w_sb_assaultsmg_hi",
			"w_sb_assaultsmg_mag1",
			"w_sb_assaultsmg_mag2",
			"w_sb_microsmg",
			"w_sb_microsmg_hi",
			"w_sb_microsmg_mag1",
			"w_sb_microsmg_mag2",
			"w_sb_smg",
			"w_sb_smg_hi",
			"w_sb_smg_mag1",
			"w_sb_smg_mag2",
			"w_sg_assaultshotgun",
			"w_sg_assaultshotgun_hi",
			"w_sg_assaultshotgun_mag1",
			"w_sg_assaultshotgun_mag2",
			"w_sg_bullpupshotgun",
			"w_sg_bullpupshotgun_hi",
			"w_sg_pumpshotgun",
			"w_sg_pumpshotgun_hi",
			"w_sg_sawnoff",
			"w_sg_sawnoff_hi",
			"w_sr_heavysniper",
			"w_sr_heavysniper_hi",
			"w_sr_heavysniper_mag1",
			"w_sr_sniperrifle",
			"w_sr_sniperrifle_hi",
			"w_sr_sniperrifle_mag1",
				"db_apart_01_",
				"db_apart_02_",
				"ela_wdn_04_",
				"hei_hw1_06_road",
				"lf_house_04_",
				"lf_house_05_",
				"lf_house_09_",
				"lf_house_20_",
				"prop_helipad_02",
				"db_apart_01d_",
				"db_apart_01_",
				"db_apart_02d_",
				"db_apart_02_",
				"db_apart_03d_",
				"db_apart_03_",
				"dt1_lod_slod3",
				"id1_lod_slod4",
				"hw1_lod_slod4",
				"po1_lod_slod4",
				"sc1_lod_slod4",
				"ss1_lod_slod3",
				"ap1_lod_slod4",
				"kt1_lod_slod4",
				"bh1_lod_slod3",
				"sp1_lod_slod4",
				"sm_lod_slod4",
				"vb_lod_slod4",
				"ch1_lod_slod3a",
				"ch2_lod4_s3c",
				"dt1_tc_dufo_core",
				"sc1_lod_slod4",
				"dt1_lod_slod3",

		
	};

	int Gunlist1 = 0; 
	std::vector<char*> Gunlist = {
		"w_am_baseball",
			"w_am_baseball_hi",
			"w_am_brfcase",
			"w_am_case",
			"w_am_digiscanner",
			"w_am_digiscanner_hi",
			"w_am_fire_exting",
			"w_am_flare",
			"w_am_flare_hi",
			"w_am_jerrycan",
			"w_ar_advancedrifle",
			"w_ar_advancedrifle_hi",
			"w_ar_advancedrifle_mag1",
			"w_ar_advancedrifle_mag2",
			"w_ar_assaultrifle",
			"w_ar_assaultrifle_hi",
			"w_ar_assaultrifle_mag1",
			"w_ar_assaultrifle_mag2",
			"w_ar_carbinerifle",
			"w_ar_carbinerifle_hi",
			"w_ar_carbinerifle_mag1",
			"w_ar_carbinerifle_mag2",
			"w_at_ar_afgrip",
			"w_at_ar_afgrip_hi",
			"w_at_ar_flsh",
			"w_at_ar_flsh_hi",
			"w_at_ar_supp",
			"w_at_ar_supp_02",
			"w_at_ar_supp_02_hi",
			"w_at_ar_supp_hi",
			"w_at_pi_flsh",
			"w_at_pi_flsh_hi",
			"w_at_pi_supp",
			"w_at_pi_supp_hi",
			"w_at_railcover_01",
			"w_at_railcover_01_hi",
			"w_at_scope_large",
			"w_at_scope_large_hi",
			"w_at_scope_macro",
			"w_at_scope_macro_hi",
			"w_at_scope_max",
			"w_at_scope_max_hi",
			"w_at_scope_medium",
			"w_at_scope_medium_hi",
			"w_at_scope_small",
			"w_at_scope_small_hi",
			"w_at_sr_supp",
			"w_at_sr_supp_hi",
			"w_ex_grenadefrag",
			"w_ex_grenadefrag_hi",
			"w_ex_grenadesmoke",
			"w_ex_molotov",
			"w_ex_molotov_hi",
			"w_ex_pe",
			"w_ex_pe_hi",
			"w_lr_40mm",
			"w_lr_40mm_pu",
			"w_lr_grenadelauncher",
			"w_lr_grenadelauncher_hi",
			"w_lr_rpg",
			"w_lr_rpg_hi",
			"w_lr_rpg_rocket",
			"w_lr_rpg_rocket_pu",
			"w_me_bat",
			"w_me_crowbar",
			"w_me_gclub",
			"w_me_hammer",
			"w_me_knife_01",
			"w_me_nightstick",
			"w_mg_combatmg",
			"w_mg_combatmg_hi",
			"w_mg_combatmg_mag1",
			"w_mg_combatmg_mag2",
			"w_mg_mg",
			"w_mg_mg_hi",
			"w_mg_mg_mag1",
			"w_mg_mg_mag2",
			"w_mg_minigun",
			"w_mg_minigun_hi",
			"w_pi_appistol",
			"w_pi_appistol_hi",
			"w_pi_appistol_mag1",
			"w_pi_appistol_mag2",
			"w_pi_combatpistol",
			"w_pi_combatpistol_hi",
			"w_pi_combatpistol_mag1",
			"w_pi_combatpistol_mag2",
			"w_pi_pistol",
			"w_pi_pistol50",
			"w_pi_pistol50_hi",
			"w_pi_pistol50_mag1",
			"w_pi_pistol50_mag2",
			"w_pi_pistol_hi",
			"w_pi_pistol_mag1",
			"w_pi_pistol_mag2",
			"w_pi_stungun",
			"w_pi_stungun_hi",
			"w_sb_assaultsmg",
			"w_sb_assaultsmg_hi",
			"w_sb_assaultsmg_mag1",
			"w_sb_assaultsmg_mag2",
			"w_sb_microsmg",
			"w_sb_microsmg_hi",
			"w_sb_microsmg_mag1",
			"w_sb_microsmg_mag2",
			"w_sb_smg",
			"w_sb_smg_hi",
			"w_sb_smg_mag1",
			"w_sb_smg_mag2",
			"w_sg_assaultshotgun",
			"w_sg_assaultshotgun_hi",
			"w_sg_assaultshotgun_mag1",
			"w_sg_assaultshotgun_mag2",
			"w_sg_bullpupshotgun",
			"w_sg_bullpupshotgun_hi",
			"w_sg_pumpshotgun",
			"w_sg_pumpshotgun_hi",
			"w_sg_sawnoff",
			"w_sg_sawnoff_hi",
			"w_sr_heavysniper",
			"w_sr_heavysniper_hi",
			"w_sr_heavysniper_mag1",
			"w_sr_sniperrifle",
			"w_sr_sniperrifle_hi",
			"w_sr_sniperrifle_mag1",
	};

	int StuntlistPos = 0;
	std::vector<char*> Stuntlist = {
		"prop_skate_flatramp",
		"prop_skate_funbox",
		"prop_skate_halfpipe",
		"prop_skate_kickers",
		"prop_skate_quartpipe",
		"prop_skate_rail",
		"prop_skate_spiner",
		"stt_prop_c4_stack",
		"stt_prop_corner_sign_01",
		"stt_prop_corner_sign_02",
		"stt_prop_corner_sign_03",
		"stt_prop_corner_sign_04",
		"stt_prop_corner_sign_05",
		"stt_prop_corner_sign_06",
		"stt_prop_corner_sign_07",
		"stt_prop_corner_sign_08",
		"stt_prop_corner_sign_09",
		"stt_prop_corner_sign_10",
		"stt_prop_corner_sign_11",
		"stt_prop_corner_sign_12",
		"stt_prop_corner_sign_13",
		"stt_prop_corner_sign_14",
		"stt_prop_flagpole_1a",
		"stt_prop_flagpole_1b",
		"stt_prop_flagpole_1c",
		"stt_prop_flagpole_1d",
		"stt_prop_flagpole_1e",
		"stt_prop_flagpole_1f",
		"stt_prop_flagpole_2a",
		"stt_prop_flagpole_2b",
		"stt_prop_flagpole_2c",
		"stt_prop_flagpole_2d",
		"stt_prop_flagpole_2e",
		"stt_prop_flagpole_2f",
		"stt_prop_hoop_constraction_01a",
		"stt_prop_hoop_small_01",
		"stt_prop_hoop_tyre_01a",
		"stt_prop_lives_bottle",
		"stt_prop_race_gantry_01",
		"stt_prop_race_start_line_01",
		"stt_prop_race_start_line_01b",
		"stt_prop_race_start_line_02",
		"stt_prop_race_start_line_02b",
		"stt_prop_race_start_line_03",
		"stt_prop_race_start_line_03b",
		"stt_prop_race_tannoy",
		"stt_prop_ramp_adj_flip_m",
		"stt_prop_ramp_adj_flip_mb",
		"stt_prop_ramp_adj_flip_s",
		"stt_prop_ramp_adj_flip_sb",
		"stt_prop_ramp_adj_hloop",
		"stt_prop_ramp_adj_loop",
		"stt_prop_ramp_jump_l",
		"stt_prop_ramp_jump_m",
		"stt_prop_ramp_jump_s",
		"stt_prop_ramp_jump_xl",
		"stt_prop_ramp_jump_xs",
		"stt_prop_ramp_jump_xxl",
		"stt_prop_ramp_multi_loop_rb",
		"stt_prop_ramp_spiral_l",
		"stt_prop_ramp_spiral_l_l",
		"stt_prop_ramp_spiral_l_m",
		"stt_prop_ramp_spiral_l_s",
		"stt_prop_ramp_spiral_l_xxl",
		"stt_prop_ramp_spiral_m",
		"stt_prop_ramp_spiral_s",
		"stt_prop_ramp_spiral_xxl",
		"stt_prop_sign_circuit_01",
		"stt_prop_sign_circuit_02",
		"stt_prop_sign_circuit_03",
		"stt_prop_sign_circuit_04",
		"stt_prop_sign_circuit_05",
		"stt_prop_sign_circuit_06",
		"stt_prop_sign_circuit_07",
		"stt_prop_sign_circuit_08",
		"stt_prop_sign_circuit_09",
		"stt_prop_sign_circuit_10",
		"stt_prop_sign_circuit_11",
		"stt_prop_sign_circuit_11b",
		"stt_prop_sign_circuit_12",
		"stt_prop_sign_circuit_13",
		"stt_prop_sign_circuit_13b",
		"stt_prop_sign_circuit_14",
		"stt_prop_sign_circuit_14b",
		"stt_prop_sign_circuit_15",
		"stt_prop_slow_down",
		"stt_prop_speakerstack_01a",
		"stt_prop_startline_gantry",
		"stt_prop_stunt_bblock_huge_01",
		"stt_prop_stunt_bblock_huge_02",
		"stt_prop_stunt_bblock_huge_03",
		"stt_prop_stunt_bblock_huge_04",
		"stt_prop_stunt_bblock_huge_05",
		"stt_prop_stunt_bblock_hump_01",
		"stt_prop_stunt_bblock_hump_02",
		"stt_prop_stunt_bblock_lrg1",
		"stt_prop_stunt_bblock_lrg2",
		"stt_prop_stunt_bblock_lrg3",
		"stt_prop_stunt_bblock_mdm1",
		"stt_prop_stunt_bblock_mdm2",
		"stt_prop_stunt_bblock_mdm3",
		"stt_prop_stunt_bblock_qp",
		"stt_prop_stunt_bblock_qp2",
		"stt_prop_stunt_bblock_qp3",
		"stt_prop_stunt_bblock_sml1",
		"stt_prop_stunt_bblock_sml2",
		"stt_prop_stunt_bblock_sml3",
		"stt_prop_stunt_bblock_xl1",
		"stt_prop_stunt_bblock_xl2",
		"stt_prop_stunt_bblock_xl3",
		"stt_prop_stunt_bowling_ball",
		"stt_prop_stunt_bowling_pin",
		"stt_prop_stunt_bowlpin_stand",
		"stt_prop_stunt_domino",
		"stt_prop_stunt_jump15",
		"stt_prop_stunt_jump30",
		"stt_prop_stunt_jump45",
		"stt_prop_stunt_jump_l",
		"stt_prop_stunt_jump_lb",
		"stt_prop_stunt_jump_loop",
		"stt_prop_stunt_jump_m",
		"stt_prop_stunt_jump_mb",
		"stt_prop_stunt_jump_s",
		"stt_prop_stunt_jump_sb",
		"stt_prop_stunt_landing_zone_01",
		"stt_prop_stunt_ramp",
		"stt_prop_stunt_soccer_ball",
		"stt_prop_stunt_soccer_goal",
		"stt_prop_stunt_soccer_lball",
		"stt_prop_stunt_soccer_sball",
		"stt_prop_stunt_target",
		"stt_prop_stunt_target_small",
		"stt_prop_stunt_track_bumps",
		"stt_prop_stunt_track_cutout",
		"stt_prop_stunt_track_dwlink",
		"stt_prop_stunt_track_dwlink_02",
		"stt_prop_stunt_track_dwsh15",
		"stt_prop_stunt_track_dwshort",
		"stt_prop_stunt_track_dwslope15",
		"stt_prop_stunt_track_dwslope30",
		"stt_prop_stunt_track_dwslope45",
		"stt_prop_stunt_track_dwturn",
		"stt_prop_stunt_track_dwuturn",
		"stt_prop_stunt_track_exshort",
		"stt_prop_stunt_track_fork",
		"stt_prop_stunt_track_funlng",
		"stt_prop_stunt_track_funnel",
		"stt_prop_stunt_track_hill",
		"stt_prop_stunt_track_hill2",
		"stt_prop_stunt_track_jump",
		"stt_prop_stunt_track_link",
		"stt_prop_stunt_track_otake",
		"stt_prop_stunt_track_sh15",
		"stt_prop_stunt_track_sh30",
		"stt_prop_stunt_track_sh45",
		"stt_prop_stunt_track_sh45_a",
		"stt_prop_stunt_track_short",
		"stt_prop_stunt_track_slope15",
		"stt_prop_stunt_track_slope30",
		"stt_prop_stunt_track_slope45",
		"stt_prop_stunt_track_start",
		"stt_prop_stunt_track_start_02",
		"stt_prop_stunt_track_straight",
		"stt_prop_stunt_track_straightice",
		"stt_prop_stunt_track_st_01",
		"stt_prop_stunt_track_st_02",
		"stt_prop_stunt_track_turn",
		"stt_prop_stunt_track_turnice",
		"stt_prop_stunt_track_uturn",
		"stt_prop_stunt_tube_crn",
		"stt_prop_stunt_tube_crn2",
		"stt_prop_stunt_tube_crn_15d",
		"stt_prop_stunt_tube_crn_30d",
		"stt_prop_stunt_tube_crn_5d",
		"stt_prop_stunt_tube_cross",
		"stt_prop_stunt_tube_end",
		"stt_prop_stunt_tube_ent",
		"stt_prop_stunt_tube_fn_01",
		"stt_prop_stunt_tube_fn_02",
		"stt_prop_stunt_tube_fn_03",
		"stt_prop_stunt_tube_fn_04",
		"stt_prop_stunt_tube_fn_05",
		"stt_prop_stunt_tube_fork",
		"stt_prop_stunt_tube_gap_01",
		"stt_prop_stunt_tube_gap_02",
		"stt_prop_stunt_tube_gap_03",
		"stt_prop_stunt_tube_hg",
		"stt_prop_stunt_tube_jmp",
		"stt_prop_stunt_tube_jmp2",
		"stt_prop_stunt_tube_l",
		"stt_prop_stunt_tube_m",
		"stt_prop_stunt_tube_qg",
		"stt_prop_stunt_tube_s",
		"stt_prop_stunt_tube_speed",
		"stt_prop_stunt_tube_speeda",
		"stt_prop_stunt_tube_speedb",
		"stt_prop_stunt_tube_xs",
		"stt_prop_stunt_tube_xxs",
		"stt_prop_stunt_wideramp",
		"stt_prop_track_bend2_bar_l",
		"stt_prop_track_bend2_bar_l_b",
		"stt_prop_track_bend2_l",
		"stt_prop_track_bend2_l_b",
		"stt_prop_track_bend_15d",
		"stt_prop_track_bend_15d_bar",
		"stt_prop_track_bend_180d",
		"stt_prop_track_bend_180d_bar",
		"stt_prop_track_bend_30d",
		"stt_prop_track_bend_30d_bar",
		"stt_prop_track_bend_5d",
		"stt_prop_track_bend_5d_bar",
		"stt_prop_track_bend_bar_l",
		"stt_prop_track_bend_bar_l_b",
		"stt_prop_track_bend_bar_m",
		"stt_prop_track_bend_l",
		"stt_prop_track_bend_l_b",
		"stt_prop_track_bend_m",
		"stt_prop_track_block_01",
		"stt_prop_track_block_02",
		"stt_prop_track_block_03",
		"stt_prop_track_chicane_l",
		"stt_prop_track_chicane_l_02",
		"stt_prop_track_chicane_r",
		"stt_prop_track_chicane_r_02",
		"stt_prop_track_cross",
		"stt_prop_track_cross_bar",
		"stt_prop_track_fork",
		"stt_prop_track_fork_bar",
		"stt_prop_track_funnel",
		"stt_prop_track_funnel_ads_01a",
		"stt_prop_track_funnel_ads_01b",
		"stt_prop_track_funnel_ads_01c",
		"stt_prop_track_jump_01a",
		"stt_prop_track_jump_01b",
		"stt_prop_track_jump_01c",
		"stt_prop_track_jump_02a",
		"stt_prop_track_jump_02b",
		"stt_prop_track_jump_02c",
		"stt_prop_track_link",
		"stt_prop_track_slowdown",
		"stt_prop_track_slowdown",
		"stt_prop_track_slowdown_t1",
		"stt_prop_track_slowdown_t2",
		"stt_prop_track_speedup",
		"stt_prop_track_speedup_t1",
		"stt_prop_track_speedup_t2",
		"stt_prop_track_start",
		"stt_prop_track_start_02",
		"stt_prop_track_stop_sign",
		"stt_prop_track_straight_bar_l",
		"stt_prop_track_straight_bar_m",
		"stt_prop_track_straight_bar_s",
		"stt_prop_track_straight_l",
		"stt_prop_track_straight_lm",
		"stt_prop_track_straight_lm_bar",
		"stt_prop_track_straight_m",
		"stt_prop_track_straight_s",
		"stt_prop_track_tube_01",
		"stt_prop_track_tube_02",
		"stt_prop_tyre_wall_01",
		"stt_prop_tyre_wall_010",
		"stt_prop_tyre_wall_011",
		"stt_prop_tyre_wall_012",
		"stt_prop_tyre_wall_013",
		"stt_prop_tyre_wall_01",
		"stt_prop_tyre_wall_015",
		"stt_prop_tyre_wall_02",
		"stt_prop_tyre_wall_03",
		"stt_prop_tyre_wall_04",
		"stt_prop_tyre_wall_05",
		"stt_prop_tyre_wall_06",
		"stt_prop_tyre_wall_07",
		"stt_prop_tyre_wall_08",
		"stt_prop_tyre_wall_09",
		"stt_prop_tyre_wall_0l010",
		"stt_prop_tyre_wall_0l012",
		"stt_prop_tyre_wall_0l013",
		"stt_prop_tyre_wall_0l014",
		"stt_prop_tyre_wall_0l015",
		"stt_prop_tyre_wall_0l018",
		"stt_prop_tyre_wall_0l019",
		"stt_prop_tyre_wall_0l020",
		"stt_prop_tyre_wall_0l04",
		"stt_prop_tyre_wall_0l05",
		"stt_prop_tyre_wall_0l06",
		"stt_prop_tyre_wall_0l07",
		"stt_prop_tyre_wall_0l08",
		"stt_prop_tyre_wall_0l1",
		"stt_prop_tyre_wall_0l16",
		"stt_prop_tyre_wall_0l17",
		"stt_prop_tyre_wall_0l2",
		"stt_prop_tyre_wall_0l3",
		"stt_prop_tyre_wall_0r010",
		"stt_prop_tyre_wall_0r011",
		"stt_prop_tyre_wall_0r012",
		"stt_prop_tyre_wall_0r013",
		"stt_prop_tyre_wall_0r014",
		"stt_prop_tyre_wall_0r015",
		"stt_prop_tyre_wall_0r016",
		"stt_prop_tyre_wall_0r017",
		"stt_prop_tyre_wall_0r018",
		"stt_prop_tyre_wall_0r019",
		"stt_prop_tyre_wall_0r04",
		"stt_prop_tyre_wall_0r05",
		"stt_prop_tyre_wall_0r06",
		"stt_prop_tyre_wall_0r07",
		"stt_prop_tyre_wall_0r08",
		"stt_prop_tyre_wall_0r09",
		"stt_prop_tyre_wall_0r1",
		"stt_prop_tyre_wall_0r2",
		"stt_prop_tyre_wall_0r3",
		"stt_prop_wallride_01",
		"stt_prop_wallride_01b",
		"stt_prop_wallride_02",
		"stt_prop_wallride_02b",
		"stt_prop_wallride_04",
		"stt_prop_wallride_05",
		"stt_prop_wallride_05b",
		"stt_prop_wallride_45l",
		"stt_prop_wallride_45la",
		"stt_prop_wallride_45r",
		"stt_prop_wallride_45ra",
		"stt_prop_wallride_90l",
		"stt_prop_wallride_90lb",
		"stt_prop_wallride_90r",
		"stt_prop_wallride_90rb",
	};


     char* Stuntlist1[] = {
		"prop_skate_flatramp",
		"prop_skate_funbox",
		"prop_skate_halfpipe",
		"prop_skate_kickers",
		"prop_skate_quartpipe",
		"prop_skate_rail",
		"prop_skate_spiner",
		"stt_prop_c4_stack",
		"stt_prop_corner_sign_01",
		"stt_prop_corner_sign_02",
		"stt_prop_corner_sign_03",
		"stt_prop_corner_sign_04",
		"stt_prop_corner_sign_05",
		"stt_prop_corner_sign_06",
		"stt_prop_corner_sign_07",
		"stt_prop_corner_sign_08",
		"stt_prop_corner_sign_09",
		"stt_prop_corner_sign_10",
		"stt_prop_corner_sign_11",
		"stt_prop_corner_sign_12",
		"stt_prop_corner_sign_13",
		"stt_prop_corner_sign_14",
		"stt_prop_flagpole_1a",
		"stt_prop_flagpole_1b",
		"stt_prop_flagpole_1c",
		"stt_prop_flagpole_1d",
		"stt_prop_flagpole_1e",
		"stt_prop_flagpole_1f",
		"stt_prop_flagpole_2a",
		"stt_prop_flagpole_2b",
		"stt_prop_flagpole_2c",
		"stt_prop_flagpole_2d",
		"stt_prop_flagpole_2e",
		"stt_prop_flagpole_2f",
		"stt_prop_hoop_constraction_01a",
		"stt_prop_hoop_small_01",
		"stt_prop_hoop_tyre_01a",
		"stt_prop_lives_bottle",
		"stt_prop_race_gantry_01",
		"stt_prop_race_start_line_01",
		"stt_prop_race_start_line_01b",
		"stt_prop_race_start_line_02",
		"stt_prop_race_start_line_02b",
		"stt_prop_race_start_line_03",
		"stt_prop_race_start_line_03b",
		"stt_prop_race_tannoy",
		"stt_prop_ramp_adj_flip_m",
		"stt_prop_ramp_adj_flip_mb",
		"stt_prop_ramp_adj_flip_s",
		"stt_prop_ramp_adj_flip_sb",
		"stt_prop_ramp_adj_hloop",
		"stt_prop_ramp_adj_loop",
		"stt_prop_ramp_jump_l",
		"stt_prop_ramp_jump_m",
		"stt_prop_ramp_jump_s",
		"stt_prop_ramp_jump_xl",
		"stt_prop_ramp_jump_xs",
		"stt_prop_ramp_jump_xxl",
		"stt_prop_ramp_multi_loop_rb",
		"stt_prop_ramp_spiral_l",
		"stt_prop_ramp_spiral_l_l",
		"stt_prop_ramp_spiral_l_m",
		"stt_prop_ramp_spiral_l_s",
		"stt_prop_ramp_spiral_l_xxl",
		"stt_prop_ramp_spiral_m",
		"stt_prop_ramp_spiral_s",
		"stt_prop_ramp_spiral_xxl",
		"stt_prop_sign_circuit_01",
		"stt_prop_sign_circuit_02",
		"stt_prop_sign_circuit_03",
		"stt_prop_sign_circuit_04",
		"stt_prop_sign_circuit_05",
		"stt_prop_sign_circuit_06",
		"stt_prop_sign_circuit_07",
		"stt_prop_sign_circuit_08",
		"stt_prop_sign_circuit_09",
		"stt_prop_sign_circuit_10",
		"stt_prop_sign_circuit_11",
		"stt_prop_sign_circuit_11b",
		"stt_prop_sign_circuit_12",
		"stt_prop_sign_circuit_13",
		"stt_prop_sign_circuit_13b",
		"stt_prop_sign_circuit_14",
		"stt_prop_sign_circuit_14b",
		"stt_prop_sign_circuit_15",
		"stt_prop_slow_down",
		"stt_prop_speakerstack_01a",
		"stt_prop_startline_gantry",
		"stt_prop_stunt_bblock_huge_01",
		"stt_prop_stunt_bblock_huge_02",
		"stt_prop_stunt_bblock_huge_03",
		"stt_prop_stunt_bblock_huge_04",
		"stt_prop_stunt_bblock_huge_05",
		"stt_prop_stunt_bblock_hump_01",
		"stt_prop_stunt_bblock_hump_02",
		"stt_prop_stunt_bblock_lrg1",
		"stt_prop_stunt_bblock_lrg2",
		"stt_prop_stunt_bblock_lrg3",
		"stt_prop_stunt_bblock_mdm1",
		"stt_prop_stunt_bblock_mdm2",
		"stt_prop_stunt_bblock_mdm3",
		"stt_prop_stunt_bblock_qp",
		"stt_prop_stunt_bblock_qp2",
		"stt_prop_stunt_bblock_qp3",
		"stt_prop_stunt_bblock_sml1",
		"stt_prop_stunt_bblock_sml2",
		"stt_prop_stunt_bblock_sml3",
		"stt_prop_stunt_bblock_xl1",
		"stt_prop_stunt_bblock_xl2",
		"stt_prop_stunt_bblock_xl3",
		"stt_prop_stunt_bowling_ball",
		"stt_prop_stunt_bowling_pin",
		"stt_prop_stunt_bowlpin_stand",
		"stt_prop_stunt_domino",
		"stt_prop_stunt_jump15",
		"stt_prop_stunt_jump30",
		"stt_prop_stunt_jump45",
		"stt_prop_stunt_jump_l",
		"stt_prop_stunt_jump_lb",
		"stt_prop_stunt_jump_loop",
		"stt_prop_stunt_jump_m",
		"stt_prop_stunt_jump_mb",
		"stt_prop_stunt_jump_s",
		"stt_prop_stunt_jump_sb",
		"stt_prop_stunt_landing_zone_01",
		"stt_prop_stunt_ramp",
		"stt_prop_stunt_soccer_ball",
		"stt_prop_stunt_soccer_goal",
		"stt_prop_stunt_soccer_lball",
		"stt_prop_stunt_soccer_sball",
		"stt_prop_stunt_target",
		"stt_prop_stunt_target_small",
		"stt_prop_stunt_track_bumps",
		"stt_prop_stunt_track_cutout",
		"stt_prop_stunt_track_dwlink",
		"stt_prop_stunt_track_dwlink_02",
		"stt_prop_stunt_track_dwsh15",
		"stt_prop_stunt_track_dwshort",
		"stt_prop_stunt_track_dwslope15",
		"stt_prop_stunt_track_dwslope30",
		"stt_prop_stunt_track_dwslope45",
		"stt_prop_stunt_track_dwturn",
		"stt_prop_stunt_track_dwuturn",
		"stt_prop_stunt_track_exshort",
		"stt_prop_stunt_track_fork",
		"stt_prop_stunt_track_funlng",
		"stt_prop_stunt_track_funnel",
		"stt_prop_stunt_track_hill",
		"stt_prop_stunt_track_hill2",
		"stt_prop_stunt_track_jump",
		"stt_prop_stunt_track_link",
		"stt_prop_stunt_track_otake",
		"stt_prop_stunt_track_sh15",
		"stt_prop_stunt_track_sh30",
		"stt_prop_stunt_track_sh45",
		"stt_prop_stunt_track_sh45_a",
		"stt_prop_stunt_track_short",
		"stt_prop_stunt_track_slope15",
		"stt_prop_stunt_track_slope30",
		"stt_prop_stunt_track_slope45",
		"stt_prop_stunt_track_start",
		"stt_prop_stunt_track_start_02",
		"stt_prop_stunt_track_straight",
		"stt_prop_stunt_track_straightice",
		"stt_prop_stunt_track_st_01",
		"stt_prop_stunt_track_st_02",
		"stt_prop_stunt_track_turn",
		"stt_prop_stunt_track_turnice",
		"stt_prop_stunt_track_uturn",
		"stt_prop_stunt_tube_crn",
		"stt_prop_stunt_tube_crn2",
		"stt_prop_stunt_tube_crn_15d",
		"stt_prop_stunt_tube_crn_30d",
		"stt_prop_stunt_tube_crn_5d",
		"stt_prop_stunt_tube_cross",
		"stt_prop_stunt_tube_end",
		"stt_prop_stunt_tube_ent",
		"stt_prop_stunt_tube_fn_01",
		"stt_prop_stunt_tube_fn_02",
		"stt_prop_stunt_tube_fn_03",
		"stt_prop_stunt_tube_fn_04",
		"stt_prop_stunt_tube_fn_05",
		"stt_prop_stunt_tube_fork",
		"stt_prop_stunt_tube_gap_01",
		"stt_prop_stunt_tube_gap_02",
		"stt_prop_stunt_tube_gap_03",
		"stt_prop_stunt_tube_hg",
		"stt_prop_stunt_tube_jmp",
		"stt_prop_stunt_tube_jmp2",
		"stt_prop_stunt_tube_l",
		"stt_prop_stunt_tube_m",
		"stt_prop_stunt_tube_qg",
		"stt_prop_stunt_tube_s",
		"stt_prop_stunt_tube_speed",
		"stt_prop_stunt_tube_speeda",
		"stt_prop_stunt_tube_speedb",
		"stt_prop_stunt_tube_xs",
		"stt_prop_stunt_tube_xxs",
		"stt_prop_stunt_wideramp",
		"stt_prop_track_bend2_bar_l",
		"stt_prop_track_bend2_bar_l_b",
		"stt_prop_track_bend2_l",
		"stt_prop_track_bend2_l_b",
		"stt_prop_track_bend_15d",
		"stt_prop_track_bend_15d_bar",
		"stt_prop_track_bend_180d",
		"stt_prop_track_bend_180d_bar",
		"stt_prop_track_bend_30d",
		"stt_prop_track_bend_30d_bar",
		"stt_prop_track_bend_5d",
		"stt_prop_track_bend_5d_bar",
		"stt_prop_track_bend_bar_l",
		"stt_prop_track_bend_bar_l_b",
		"stt_prop_track_bend_bar_m",
		"stt_prop_track_bend_l",
		"stt_prop_track_bend_l_b",
		"stt_prop_track_bend_m",
		"stt_prop_track_block_01",
		"stt_prop_track_block_02",
		"stt_prop_track_block_03",
		"stt_prop_track_chicane_l",
		"stt_prop_track_chicane_l_02",
		"stt_prop_track_chicane_r",
		"stt_prop_track_chicane_r_02",
		"stt_prop_track_cross",
		"stt_prop_track_cross_bar",
		"stt_prop_track_fork",
		"stt_prop_track_fork_bar",
		"stt_prop_track_funnel",
		"stt_prop_track_funnel_ads_01a",
		"stt_prop_track_funnel_ads_01b",
		"stt_prop_track_funnel_ads_01c",
		"stt_prop_track_jump_01a",
		"stt_prop_track_jump_01b",
		"stt_prop_track_jump_01c",
		"stt_prop_track_jump_02a",
		"stt_prop_track_jump_02b",
		"stt_prop_track_jump_02c",
		"stt_prop_track_link",
		"stt_prop_track_slowdown",
		"stt_prop_track_slowdown",
		"stt_prop_track_slowdown_t1",
		"stt_prop_track_slowdown_t2",
		"stt_prop_track_speedup",
		"stt_prop_track_speedup_t1",
		"stt_prop_track_speedup_t2",
		"stt_prop_track_start",
		"stt_prop_track_start_02",
		"stt_prop_track_stop_sign",
		"stt_prop_track_straight_bar_l",
		"stt_prop_track_straight_bar_m",
		"stt_prop_track_straight_bar_s",
		"stt_prop_track_straight_l",
		"stt_prop_track_straight_lm",
		"stt_prop_track_straight_lm_bar",
		"stt_prop_track_straight_m",
		"stt_prop_track_straight_s",
		"stt_prop_track_tube_01",
		"stt_prop_track_tube_02",
		"stt_prop_tyre_wall_01",
		"stt_prop_tyre_wall_010",
		"stt_prop_tyre_wall_011",
		"stt_prop_tyre_wall_012",
		"stt_prop_tyre_wall_013",
		"stt_prop_tyre_wall_01",
		"stt_prop_tyre_wall_015",
		"stt_prop_tyre_wall_02",
		"stt_prop_tyre_wall_03",
		"stt_prop_tyre_wall_04",
		"stt_prop_tyre_wall_05",
		"stt_prop_tyre_wall_06",
		"stt_prop_tyre_wall_07",
		"stt_prop_tyre_wall_08",
		"stt_prop_tyre_wall_09",
		"stt_prop_tyre_wall_0l010",
		"stt_prop_tyre_wall_0l012",
		"stt_prop_tyre_wall_0l013",
		"stt_prop_tyre_wall_0l014",
		"stt_prop_tyre_wall_0l015",
		"stt_prop_tyre_wall_0l018",
		"stt_prop_tyre_wall_0l019",
		"stt_prop_tyre_wall_0l020",
		"stt_prop_tyre_wall_0l04",
		"stt_prop_tyre_wall_0l05",
		"stt_prop_tyre_wall_0l06",
		"stt_prop_tyre_wall_0l07",
		"stt_prop_tyre_wall_0l08",
		"stt_prop_tyre_wall_0l1",
		"stt_prop_tyre_wall_0l16",
		"stt_prop_tyre_wall_0l17",
		"stt_prop_tyre_wall_0l2",
		"stt_prop_tyre_wall_0l3",
		"stt_prop_tyre_wall_0r010",
		"stt_prop_tyre_wall_0r011",
		"stt_prop_tyre_wall_0r012",
		"stt_prop_tyre_wall_0r013",
		"stt_prop_tyre_wall_0r014",
		"stt_prop_tyre_wall_0r015",
		"stt_prop_tyre_wall_0r016",
		"stt_prop_tyre_wall_0r017",
		"stt_prop_tyre_wall_0r018",
		"stt_prop_tyre_wall_0r019",
		"stt_prop_tyre_wall_0r04",
		"stt_prop_tyre_wall_0r05",
		"stt_prop_tyre_wall_0r06",
		"stt_prop_tyre_wall_0r07",
		"stt_prop_tyre_wall_0r08",
		"stt_prop_tyre_wall_0r09",
		"stt_prop_tyre_wall_0r1",
		"stt_prop_tyre_wall_0r2",
		"stt_prop_tyre_wall_0r3",
		"stt_prop_wallride_01",
		"stt_prop_wallride_01b",
		"stt_prop_wallride_02",
		"stt_prop_wallride_02b",
		"stt_prop_wallride_04",
		"stt_prop_wallride_05",
		"stt_prop_wallride_05b",
		"stt_prop_wallride_45l",
		"stt_prop_wallride_45la",
		"stt_prop_wallride_45r",
		"stt_prop_wallride_45ra",
		"stt_prop_wallride_90l",
		"stt_prop_wallride_90lb",
		"stt_prop_wallride_90r",
		"stt_prop_wallride_90rb",
	};


	bool waterdostuff;
	bool Worldglow;
	bool WorldglowRGB;
	float world_glow_intensity = 255.f;
	float world_glow_range = 255.f;
	int world_glow_red = 255;
	int world_glow_blue = 255;
	int world_glow_green = 255;
	bool Worldglow1;
	bool WorldglowRGB1;
	float world_glow_intensity1 = 255.f;
	float world_glow_range1 = 255.f;
	float world_glow_shadow = 255.f;
	int world_glow_red1 = 255;
	int world_glow_blue1 = 255;
	int world_glow_green1 = 255;


	bool Worldglow2;
	bool WorldglowRGB2;
	float world_glow_intensity2 = 255.f;
	float world_glow_range2 = 255.f;
	int world_glow_red2 = 255;
	int world_glow_blue2 = 255;
	int world_glow_green2 = 255;
	float hardness = 0;
	float radius = 0;
	float falloff = 0;

	bool Worldglow3;
	bool WorldglowRGB3;
	float world_glow_intensity3 = 255.f;
	float world_glow_range3 = 255.f;
	float world_glow_shadow3 = 255.f;
	int world_glow_red3 = 255;
	int world_glow_blue3 = 255;
	int world_glow_green3 = 255;
	float hardness2 = 0;
	float radius2 = 0; 
	float falloff2 = 0;
	int shadowid = 0;

bool crashthisnigga2;

int Explosionfick = 38;
int Explosionfickkkk = 38;

char* objtree = "Prop_tree_cedar_02";
int Treeint = 0;
static char* Treename[] = {
	"Cedar Two", "Cedar", "Cypress", "Eucaliptus", "Jacada", "Lficus", "Log", "Maple", "Mquite", "Test Trunk", "Test Trunk Base", "Snow", "Snow Two", "Root", "Generic", "Birch",
};


char* Name = "vw_prop_vw_colle_prbubble";

int RpDropint = 0;// set the first object to 0
static char* PickupName[] = { // add name of the statues or card, This is the name user will see
	"Princess", "Alien", "Rage", "Sasquatch", "Generic","Card Queen", "Card King",
};

char* Ammo = "PICKUP_AMMO_FIREWORK";

int Ammodropint = 0;// set the first object to 0
static char* Pickupammo[] = { // add name of the statues or card, This is the name user will see
	"Firework", "Flare", "Mingun", "RPG", "Grenade Launcher","Sniper", "Shotgun", "MG", "Rifle", "SMG", "Pistol",
};

char* Models = "";
char* Models2 = "PICKUP_MONEY_VARIABLE";

char* Health = "pickup_health_standard";

int Healthdropint = 0;// set the first object to 0
static char* Pickuphealth[] = { // add name of the statues or card, This is the name user will see
	"Normal", "Vehicle", "Armor",
};


static char* Attachveh[] = { // Attachvehint
	"Attach Vehicle", "Detach Vehicle", "Attach To Player", "Detach from Player",
};

int Attachvehint = 0;

bool notify = false;

std::vector<Hash> blacklistedObjects = {
	0x9CF21E0F ,0x34315488,//need 2 of this obj , 
	0x6A27FEB1, 0xCB2ACC8,
	0xC6899CDE, 0xD14B5BA3,
	0xD9F4474C, 0x32A9996C,
	0x69D4F974, 0xCAFC1EC3,
	0x79B41171, 0x1075651,
	0xC07792D4, 0x781E451D,
	0x762657C6, 0xC2E75A21,
	0xC3C00861, 0x81FB3FF0,
	0x45EF7804, 0xE65EC0E4,
	0xE764D794, 0xFBF7D21F,
	0xE1AEB708, 0xA5E3D471,
	0xD971BBAE, 0xCF7A9A9D,
	0xC2CC99D8, 0x8FB233A4,
	0x24E08E1F, 0x337B2B54,
	0xB9402F87, 0x4F2526DA
};

void attach_entity_to_entity(Entity entity1, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, BOOL collision, BOOL isPed, int vertexIndex, BOOL fixedRot) {
	Vector3 pos = { xPos, yPos, zPos }; 
	Vector3 rot = { xRot, yRot, zRot };
	ENTITY::ATTACH_ENTITY_TO_ENTITY(entity1, entity2, boneIndex, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, p9, useSoftPinning, collision, isPed, vertexIndex, fixedRot);
	//Hooking::attach_entity_to_entity(entity1, entity2, boneIndex, &pos, &rot, p9, useSoftPinning, collision, isPed, vertexIndex, fixedRot, false);
}
std::vector<Object> CrashObject;

void set_entity_coords(Entity entity, Vector3 coords, bool Xaxis, bool Yaxis, bool Zaxis) {
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(entity, coords.x, coords.y, coords.z, Xaxis, Yaxis, Zaxis);
	//Hooking::set_entity_coords(entity, &coords, Xaxis, Yaxis, Zaxis);
}

void notifyy()
{

}


int drivestyle = 0;
int drivesp = 0;
int timeint = 2000;

int selectedPlayer;

Ped player_ped_id()
{
	return PLAYER::PLAYER_PED_ID();
}

Ped get_player_ped(Player player)
{
	const auto gpa = Foxy_Engine::GetPlayerAddress(player);

	if (gpa) {
		return Foxy_Engine::AddressToEntity(gpa);
	}
	return NULL;
}

Player player_id()
{
	for (int i = 0; i < 32; i++) {
		if (get_player_ped(i) == player_ped_id())
			return i;
	}
	return NULL;
}

Vehicle get_vehicle_ped_is_in(Ped pedID, bool lastVehicle)
{
	return PED::GET_VEHICLE_PED_IS_IN(pedID, lastVehicle);
	//return Hooking::get_vehicle_ped_is_in(pedID, lastVehicle);
}

Vector3 get_entity_coords(Entity entity, bool alive) {
	return ENTITY::GET_ENTITY_COORDS(entity, alive);
	//return Hooking::get_entity_coords(entity, alive);//steam not works
}

Vector3 get_player_coords(Player plr)
{
	if (get_player_ped(plr))
	{
		return get_entity_coords(get_player_ped(plr), 1); // normal i want the player error 
	}
}

int NotificationCEO(char* text, char* text2, char* Subject)
{
	YTD13();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("Foxy", "FoxyLogo", true, 7, text2, Subject, 1.0, "___FREE");
	return UI::_DRAW_NOTIFICATION(1, 1);

}


Hash weaponsList[] = {
	0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
	0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
	0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
	0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
	0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
	0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
	0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
	0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
	0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
	0x34A67B97, 0xFBAB5776, 0x060EC506, // Miscellaneous
	0xAF3696A1, 0x476BF155, 0xB62D1F67,// 1.46
	2441047180, 3126027122, 727643628, //Casino Hiest
	94989220, 1470379660, 2636060646, //Cayo Perico
	1578808251, 3980609624, //Summer dlc 2
	1703483498, 465894841,  //Creator club weapon 
	350597077, 3520460075 //1.67 
};

char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}
int rww1 = 255, gww1 = 0, bww1 = 0;
void RGBFadeeee()
{
	if (rww1 > 0 && bww1 == 0) {
		rww1--;
		gww1++;
	}
	if (gww1 > 0 && rww1 == 0) {
		gww1--;
		bww1++;
	}
	if (bww1 > 0 && gww1 == 0) {
		rww1++;
		bww1--;
	}
}
void colorful(){
	Menu::Settings::titleRect = { rww1, gww1, bww1, 255 };
	Menu::Settings::scroller = { rww1, gww1, bww1, 255 };
	Menu::Settings::optionRect = { rww1, gww1, bww1, 200 };
	Menu::Settings::SubTitle = { rww1, gww1, bww1, 255 };
}

int lol = 0;
static char* Pickupmod[] = { // Attachvehint
	"Money", "Armour", "Health",
};


int lul = 0;
static char* PickupEnt[] = { // Attachvehint
	"Asteroid", "UFO", "Tree", "RP Troll", "DownTown","Dino", "Shark", "ScareCrow", "Cow Sign", "Beaver", 
};

int shooto = 0;
int Remtp = 0;
int RemKE = 0;
static char* RemoteTP[] = { // Attachvehint
	"To Player", "To You", "To Cage", "In is Car", "Maze Bank Roof", "Airport", "Waypoint",
};

static char* Killenginestuff[] = { 
	"Slow", "Fast",
};

static char* Shooto[] = { // Attachvehint
	"Efftects", "Explosives", "Objects",
};

using namespace Reee;
int eclone[1000];
int egcount = 1;
int expldplayer = 1;

int r1 = 255, g1 = 0, b1 = 0;
void RGBFadeee2()
{
	if (r1 > 0 && b1 == 0) {
		r1--;
		g1++;
	}
	if (g1 > 0 && r1 == 0) {
		g1--;
		b1++;
	}
	if (b1 > 0 && g1 == 0) {
		r1++;
		b1--;
	}
}

int lgt = 12, lgt2 = 0, light = 0;
void sfddsbv()
{
	if (lgt > 0 && light == 0) {
		lgt--;
		lgt2++;
	}
}





void SpawnVeh(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 0);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 0, 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		if (spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		if (vehSpawnFade) {
			NETWORK::NETWORK_FADE_IN_ENTITY(veh, 1);
		}

		if (spawnmaxed)
		{
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
		}
		if (spbypass) {
			globalHandle(0x41183A).As<BOOL>() = 1;
			globalHandle(4267883).As<BOOL>() = 1;
			globalHandle(4266905).As<BOOL>() = 1;
			globalHandle(4268190).As<BOOL>() = 1;
			globalHandle(4270934).As<BOOL>() = 1;
		}
		else {
			globalHandle(0x41183A).As<BOOL>() = 0;
			globalHandle(4267883).As<BOOL>() = 0;
			globalHandle(4266905).As<BOOL>() = 0;
			globalHandle(4268190).As<BOOL>() = 0;
			globalHandle(4270934).As<BOOL>() = 0;

		}
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

void Blame(int selectedPed, Vector3 pos, int type, bool isAudable, bool isInvisible, float camShake, float damage)
{
	int Playerped = get_player_ped(selectedPlayer);
	for (int x = 0; x < 32; x++) {
		if (get_player_ped(x) && x != player_id() && x != selectedPlayer) {
			Vector3 playerPos = get_player_coords(x);
			owned_explossion_bypass(true);
			Foxy_Engine::add_owned_explosion(Playerped, &playerPos, 1, true, false, 2.f, 1.f);
			owned_explossion_bypass(false);
		}
	}
}


bool isPlayerFriend(Player player, bool result)
{
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13))
	{
		result = NETWORK::NETWORK_IS_FRIEND(&NETWORK_HANDLE[0]);
		return true;
	}
	return false;
}

void SetPedMovementClipset(char* clipset) {
	STREAMING::REQUEST_ANIM_SET(clipset);
	while (!STREAMING::HAS_ANIM_SET_LOADED(clipset)) WAIT(0);
	PED::SET_PED_MOVEMENT_CLIPSET(PLAYER::PLAYER_PED_ID(), clipset, 1.0f);
}

int shoop = 0;
std::vector<char*> walkDicts{
	"move_m@generic",
	"move_f@generic",
	"move_cop@action",
	"move_m@gangster@generic",
	"move_m@hipster@a",
	"move_m@hobo@a",
	"move_m@fat@a",
	"move_lester_CaneUp",
	"move_m@drunk@a",
	"move_m@drunk@moderatedrunk",
	"move_m@drunk@verydrunk",
	"move_f@sexy@a",
	"move_m@alien",
	"move_m@business@a",
	"move_m@casual@a",
	"move_m@clipboard",
	"move_m@coward",
	"move_m@fire",
	"move_m@flee@a",
	"move_m@hiking",
	"move_m@hurry@a",
	"move_injured_generic",
	"move_m@intimidation@1h",
	"move_m@muscle@a",
	"move_m@quick",
	"move_m@sad@a",
	"move_m@shadyped@a",
	"move_m@shocked@a",
	"move_f@arrogant@a",
	"move_f@handbag",
	"move_f@heels@c",
	"move_p_m_one",
	"MOVE_M@LEAF_BLOWER",
	"move_m@bail_bond_tazered",
	"MOVE_M@TOUGH_GUY@",
	"move_m@bag",


};


int walk_style_choose = 0;
std::vector<char*> walkNames{
	"Generic Male",
	"Generic Female",
	"Cop",
	"Gangster",
	"Hipster",
	"Hobo",
	"Obese",
	"Lester",
	"Drunk",
	"Moderate Drunk",
	"Very Drunk",
	"Sexy",
	"Alien",
	"Buisness",
	"Casual",
	"Clipboard",
	"Coward",
	"Burning",
	"Flee",
	"Hiking",
	"Hurry",
	"Injured",
	"Intimidation",
	"Muscular",
	"Quick",
	"Sad",
	"Shady",
	"Shocked",
	"Arrogant",
	"Handbag Walk",
	"Heels",
	"Thug",
	"Leaf Blower",
	"Tazered",
	"TOUGH GUY!",
	"Bag",
};


Object spwndObjects[1024];
char* spwndObjectsNames[1024];
float MoveX = 1.f;
float MoveY = 1.f;
float MoveZ = 1.f;
float yaw1 = 1.f;
float pitch1 = 1.f;
float roll1 = 1.f;
int spwnObjC;
bool freezeSpawn;
bool freezeObj;
Object latestObj;
Object selecObj;
bool collisionObj = false;
Object SpawnObject(char* name, Vector3 coords) {
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Object obj = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(name), pos.x, pos.y, pos.z, true, 1, 0);
	Vector3 c00rds = ENTITY::GET_ENTITY_COORDS(obj, 1);
	spwndObjects[spwnObjC] = obj;
	spwndObjectsNames[spwnObjC] = name;
	spwnObjC++;
	MoveX = c00rds.x;
	MoveY = c00rds.y;
	MoveZ = c00rds.z;
	roll1 = 0.f;
	yaw1 = 0.f;
	pitch1 = 0.f;
	ENTITY::FREEZE_ENTITY_POSITION(obj, freezeSpawn);
	freezeObj = freezeSpawn;
	return obj;
}

int Args = 255;
int Event_ID = 255;
int StructSizeArgs = 255;

int playerAlpha = 255;

bool firsttime2 = true;

Ped playerPed = PLAYER::PLAYER_PED_ID();

bool Firstboot = true;
int crashPlayerTimer;

size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
	string data((const char*)ptr, (size_t)size * nmemb);
	*((stringstream*)stream) << data << endl;
	return size * nmemb;
}

bool Invisibleee = false;
bool Modegod = false;
bool Camfree = false;
bool freeze_map = false;
bool frr = false;
bool Hulkkk = false;
bool nw = false;
bool tiny = false;
bool sm = false;

bool FreezeProtection = false;
bool crash_protection = false;
bool BlockMoney = false;
bool ExplosionProtection = false;

bool reccontrolblocc = false;
bool Antihostk = false;
bool Swap1 = false;
bool Swap2 = false;
bool Swap3 = false;
bool Swap4 = true;
bool WeaponP = false;
bool BlockallEvent = false;
bool ExplosionP = false;
bool ControlP = false;
bool FireP = false;
bool WeatherP = false;
bool VotekickP = false;
bool FreezeP = false;
bool Blockweather = false;
bool BlockOzarkcunt = false;
bool nevermental = false;
bool VehicleInvisible = false;
bool VehicleInvisible1 = false;
bool VehicleInvisible2 = false;
bool Fixloop = false;
bool Matrix = false;
bool BypassSpeedLimit = false; 
bool PoolCrash1 = false;
bool ground = false;
bool SlowMotionn = false;
bool SA = false;
bool rgbTheme = false;

bool Remgunobjtree = false;
bool RpDDROP = false;
bool Fps = true;
bool HealthDrop = false;
bool VHealthDrop = false;
bool ArmorDrop = false;
bool VArmorDrop = false;
//Ban Player
bool badsportplayersoftban = false;

//War Protection
bool pedwarprotection = false;
bool vehiclewarprotection = false;
bool objectwarprotection = false;
bool clearloopwarprotection = false;

//menu detection event 
int TimePD9;
int Timerfoxy = 5000;
bool FoxyEvent = true;
bool FoxyEvent2 = true;
bool FoxyEvent3 = true;

//Silkroad Super Powers 
bool grav_target_locked = false;

// Inferno
bool DragonMode = false;
bool DragonMode1 = false;
bool Inferno = false;
bool ElectricEyes = false;
bool SuperMan = false;
bool FlyFloat = false;
bool FireField = false;
bool ForceField = false;
bool ElectroForw = false;
bool Inferno_Info = true;



// Electro 
bool ElectricBody2 = false;
bool Electro = false;
bool Electro_Info = true;


//Hulk 
bool Hulk_Info = true;


//Animal Rider 
bool Animal_Rider = false;
bool Animal_Rider_Info = true;

//Apocalypse
bool Apocalypse = false;
bool Apocalypse_Info = true;

//SuperMan
bool SuperManSk = false;
bool SuperMan_InfoSk = true;

//Angle Of Death 
bool Angel_OF_DEATH = false;
bool Angel_OF_DEATH_Info = true;

float AODMoveX1 = -0.f;
float AODMoveY1 = -.2f;
float AODMoveZ1 = -0.2f;
float AODyaw1 = 360.f;
float AODpitch1 = 5.7f;
float AODroll1 = 250.f;

float AODMoveX2 = -0.f;
float AODMoveY2 = -.2f;
float AODMoveZ2 = 0.2f;
float AODyaw2 = 360.f;
float AODpitch2 = 9.7f;
float AODroll2 = 280.f;

float AODMoveX3 = 0.f;
float AODMoveY3 = -.2f;
float AODMoveZ3 = 0.f;
float AODyaw3 = 0.f;
float AODpitch3 = 100.0f;
float AODroll3 = 160.f;

std::string plateSymbols[35] = {
	"0", "1", "0", "1", "1", "0",
	"0", "1", "1", "0", "1", "1",
	"1", "1", "1", "1", "0",
	"0", "0", "0", "0", "0",
	"0", "0", "1", "0", "1",
	"1", "0", "0", "1", "0", "1",
	"0", "1",
};

auto IsPedShooting(std::int32_t p)
{
	return PED::GET_PED_CONFIG_FLAG(p, 58, TRUE);
}

bool Unlimited = false;
bool FoxyId = true;
bool Explodegunn = false;
int ficksize = 10;

int Vehicle_Hash = 0;
int Vehicle_Hash2 = 0;
int Vehicle_Hash3 = 0;
int Vehicle_Hash6 = 0;
int Vehicle_Hash7 = 0;
int Vehicle_Hash8 = 0;
int Vehicle_Hash5 = 0;


char* EntiThing = "prop_asteroid_01";

char* test1 = "HUD_CONNPROB";
char* test2 = "TRAN_JOINFAIL";
char* test3 = "TRAN_RETNFM";
char* test4 = "1";
/*sVar0 = "HUD_CONNPROB";
	sVar1 = "TRAN_JOINFAIL";
	sVar2 = "TRAN_RETNFM";*/

int distancee = 1;
int secondaryColor1, primaryColor1;
int pearlescentColor1, wheelColor1;
bool nocollision = false;
bool nocollision2 = false;

char* Animals[] =
{
	"A_C_Humpback", "A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
	"A_C_Rhesus","A_C_Rottweiler", "A_C_Pug", "A_C_Poodle","A_C_Westy","A_C_Seagull","A_C_SharkTiger","A_C_Shepherd", "A_C_Cat_01", "A_C_Rabbit_01", "A_C_KillerWhale", "A_C_SharkHammer", "A_C_SharkTiger", "A_C_Dolphin",
	"A_C_Panther", "A_C_Rabbit_02", "A_C_Chimp_02", "A_C_Boar_02", "A_C_Coyote_02", "A_C_Deer_02", "A_C_MtLion_02", "A_C_Pug_02", 
};

char* Crash[] =
{
	"A_C_Humpback", "A_C_Fish", "A_C_KillerWhale", "A_C_SharkHammer", "A_C_SharkTiger", "A_C_Dolphin",
};

char* Storycharacter[] =
{
	 "IG_TylerDix","IG_Wade","IG_Zimbor","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
	"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
	"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
	"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
	"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
	"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
	"CS_AmandaTownley","CS_Andreas", "cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
	"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
	"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
	"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
	"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor",
};
char* CorePtfxNames[] = {
		"bul_gravel_heli",
"ent_dst_concrete_large",
"bul_wood_splinter",
"fire_wrecked_plane_cockpit",
"wheel_fric_water",
"proj_flare_trail",
"exp_grd_grenade_lod",
"ent_amb_fbi_cinder",
"muz_smoking_barrel_minigun",
"ent_dst_gen_gobstop",
"ent_dst_inflate_ball",
"water_splash_ped_wade",
"exp_grd_plane_post",
"ent_ray_paleto_gas_flames",
"eject_stungun",
"ent_amb_wind_grass_dir",
"ent_amb_steam_pipe_lgt",
"ped_underwater_disturb_dirt",
"water_boat_wash",
"water_splash_obj_in",
"blood_stab",
"ent_brk_metal_frag",
"bul_water_heli",
"ent_sht_oil",
"bul_decal_water_heli",
"ent_sht_water_tower",
"env_snow_flakes",
"bul_hay",
"trail_splash_oil",
"bul_sand_loose_heli",
"ent_sht_beer_barrel",
"veh_sub_crush",
"ent_anim_paparazzi_flash",
"veh_vent_heli_anh",
"exp_grd_petrol_pump",
"ent_ray_meth_fires",
"veh_exhaust_hidden",
"exp_air_molotov",
"ent_anim_snot_blow",
"water_amph_car_rev",
"mel_carmetal",
"bul_concrete",
"ent_anim_cig_exhale_mth_car",
"exp_air_rpg_lod",
"veh_trailer_petrol_spray",
"water_amph_quad_bow",
"env_smoke_fbi",
"water_splash_vehicle",
"blood_shark_attack",
"ent_dst_wood_chunky",
"td_blood_shotgun",
"exp_grd_grenade_smoke",
"ent_dst_elec_fire_sp",
"ped_foot_decal_oil",
"fire_wrecked_train",
"exp_hydrant",
"ent_amb_wind_leaves",
"ent_amb_wind_litter_swirl",
"wheel_fric_hard_dusty_Bike",
"ent_amb_tap_drip",
"exp_air_grenade_lod",
"water_splash_sub_wade",
"ped_foot_decal_mud",
"water_splash_plane_in",
"ent_amb_trev1_trailer_sp_s",
"td_blood_throat",
"blood_melee_punch",
"wheel_fric_sandWet_Bike",
"ent_dst_polystyrene",
"exp_air_molotov_lod",
"blood_exit",
"eject_minigun",
"wheel_fric_grass",
"fire_wheel_bike",
"fire_petroltank_car",
"ent_amb_water_splash_wide",
"veh_backfire",
"weap_hvy_turbulance_water",
"ent_amb_leaves_pine",
"ent_amb_fountain_double",
"ent_amb_exhaust_thin",
"ent_dst_inflate_ring",
"eject_auto",
"bang_concrete",
"ent_amb_wind_leaves_dir",
"ent_amb_rapid_dir_splash_wide",
"fire_petroltank_car_bullet",
"muz_pistol_silencer",
"ent_sht_gloopy_liquid",
"ent_sht_petrol",
"ent_ray_ch2_farm_resi_dble",
"blood_chopper",
"ent_amb_elec_crackle",
"ent_dst_gen_paper",
"ent_ray_train_water_wash",
"ent_sht_flame",
"ent_anim_cig_exhale_nse",
"exp_grd_plane_sp",
"veh_vent_rc",
"veh_vent_heli_skylift",
"ent_amb_fbi_smoulder_lg",
"ent_amb_fbi_fire_beam",
"ent_sht_bush_foliage",
"ped_foot_woodchips",
"ent_dst_sweet_boxes",
"ped_foot_sand_deep",
"ped_foot_gravel",
"ent_dst_cig_packets",
"ent_amb_wind_litter_dust_dir",
"ent_dst_wood_splinter",
"bul_gravel",
"water_amph_prop",
"ent_brk_concrete",
"ent_sht_steam",
"ent_amb_steam_prison",
"water_splash_plane_trail",
"ent_amb_water_drips_spawned",
"veh_exhaust_heli_misfire",
"wheel_fric_sand_LOD",
"exp_air_rpg_plane",
"water_jetski_bow1",
"proj_missile_trail",
"fire_petroltank_heli",
"exp_grd_plane",
"ent_amb_water_drips_lg",
"ent_amb_smoke_gaswork",
"proj_flare_fuse_fp",
"ent_amb_smoke_chicken",
"water_jetski_entry2",
"bang_mud",
"exp_air_rpg_plane_sp",
"water_boat_entry",
"fire_petrol_one",
"ent_amb_cold_air_floor",
"ent_col_tree_oranges",
"ent_amb_fbi_smoke_land_lt",
"ent_anim_cig_smoke",
"ent_amb_fbi_fire_door",
"fire_petroltank_truck",
"veh_vent_heli_frogger",
"ent_amb_wind_litter_dir",
"bul_stungun_metal",
"veh_respray_smoke",
"ent_amb_foundry_molten_pour",
"blood_stab_uw",
"veh_downwash",
"water_amph_quad_rev",
"ent_brk_sparking_wires",
"water_amph_car_bow",
"veh_panel_open_car",
"ent_amb_fountain_rodeo",
"wheel_spin_gravel",
"ent_amb_fbi_smoke_linger_hvy",
"ent_amb_torch_fire",
"ent_anim_leaf_blower",
"ent_ray_shipwreck_oil",
"sp_petrolcan_splash",
"ped_parachute_open",
"ent_amb_trop_fish_swarm_angel",
"ent_anim_street_sweep",
"wheel_fric_grass_bike",
"water_boat_rev",
"ent_ray_shipwreck_bubbles",
"bang_wood",
"proj_tank_trail",
"bul_glass",
"water_splash_bike_wade",
"ent_amb_wind_hay",
"glass_smash",
"ent_amb_tnl_bubbles_sml",
"ent_amb_sprinkler_crop",
"fire_wrecked_tank",
"ent_ray_pro1_water_drip",
"lens_bug_dirt",
"liquid_splash_oil",
"ent_amb_smoke_scrap",
"blood_animal_maul",
"bang_blood",
"ent_amb_water_roof_drips_thin",
"ent_ray_ch2_farm_fire_u_l",
"ent_amb_wind_litter_dust",
"ent_brk_gate_smoke",
"ent_amb_fbi_smoke_door_med",
"veh_prop_sub",
"bul_mud_heli",
"bul_cardboard",
"bul_carmetal_heli",
"ped_foot_dirt_dry",
"fire_petroltank_plane",
"ent_col_rocks",
"muz_assault_rifle",
"water_splash_veh_out",
"weap_veh_turbulance_sand",
"ent_amb_wind_rand_litter",
"ent_dst_gen_water_spray",
"ent_amb_butterflys_swarm",
"ent_amb_steam_vent_open_lgt",
"veh_vent_heli_cargobob",
"veh_light_red",
"water_boat_bow",
"env_interior_dusty",
"ent_amb_rapid_area_spray_hvy",
"bul_decal_oil",
"trail_splash_blood",
"ent_amb_jazuzzi",
"ped_underwater_disturb_sand",
"ent_dst_gen_food",
"water_boat_prop",
"ent_anim_dusty_hands",
"exp_grd_tankshell_lod",
"ent_amb_foundry_fogball",
"bul_glass_mini",
"veh_exhaust_heli_skylift",
"veh_panel_shut_car",
"fire_wrecked_heli_cockpit",
"ent_amb_fbi_fire_drip",
"bul_plastic",
"bul_dirt_heli",
"ent_amb_beach_campfire",
"water_splash_obj_trail",
"exp_grd_sticky_sp",
"veh_panel_shut_truck",
"ent_ray_finale_vault_haze",
"ent_amb_trop_fish_swarm_col",
"water_amph_car_entry",
"bullet_tracer_railgun",
"ped_blood_pool_water",
"weap_hvy_turbulance_dirt",
"fire_wrecked_car",
"veh_plane_eject",
"ent_ray_prologue_elec_crackle",
"exp_grd_petrol_pump_sp",
"ent_amb_tnl_bubbles_lge",
"td_blood_stab",
"exp_sht_flame",
"ent_ray_heli_aprtmnt_water",
"veh_exhaust_heli",
"muz_stungun",
"ent_ray_fam3_dust_motes",
"wheel_fric_sandWet_Tank",
"wheel_decal_slush",
"ent_amb_steam",
"ent_amb_rapid_rock_drips",
"env_wind_debris_countryside",
"blood_armour_heavy",
"water_splash_ped_out",
"ent_dst_rubbish",
"ent_amb_fbi_falling_debris_sp",
"muz_hunter",
"veh_exhaust_plane_start",
"muz_buzzard",
"veh_air_turbulance_dirt",
"wheel_decal_water_Bike_Deep",
"ent_dst_glass_bottles",
"fire_petrol_two",
"wheel_spin_mud",
"env_cloud",
"exp_grd_boat_lod",
"bul_glass_shotgun",
"water_jetski_prop",
"env_dust_motes_int_recycle",
"ent_amb_sewer_drips_lg",
"ent_amb_smoke_foundry",
"env_dust_devil_urban_sma",
"bul_rubber_dust",
"exp_grd_plane_lod",
"ent_brk_wood_splinter",
"lens_rain",
"veh_downwash_sand",
"wheel_decal_petrol_Bike",
"ent_amb_falling_palm_leaves",
"lens_noir",
"exp_grd_boat_sp",
"ent_ray_finale1_fire",
"scrape_plastic",
"ent_anim_welder",
"ent_anim_weed_smoke",
"water_splash_bike_out",
"veh_exhaust_spacecraft",
"veh_exhaust_heli_cargobob_misfire",
"ent_brk_steam_burst",
"env_gunsmoke",
"veh_prop_submersible",
"exp_extinguisher",
"water_boat_entry2",
"veh_exhaust_plane",
"water_boat_Tropic_bow",
"water_splash_ped_in",
"bul_leaves",
"ent_amb_fbi_smoke_fogball",
"liquid_splash_blood",
"weap_veh_turbulance_default",
"lens_smoke",
"env_wind_debris",
"lens_blaze",
"exp_air_blimp2_sp",
"env_dust_devil_urban_lrg",
"exp_water",
"ent_ray_finale_vault_sparks",
"weap_hvy_turbulance_default",
"ent_amb_steam_pipe_hvy",
"bul_mud",
"ent_amb_fire_ring",
"ent_ray_pro1_water_splash_spawn",
"ent_amb_drain_splash",
"ent_amb_exhaust_thick",
"exp_grd_molotov_lod",
"ent_amb_sprinkler_golf",
"ent_brk_tree_trunk_bark",
"ent_amb_rapid_dir_splash_light",
"ent_amb_barrel_fire",
"ped_foot_water",
"eject_auto_fp",
"bul_foam",
"water_splash_ped_bubbles",
"ent_col_bush_leaves",
"exp_grd_rpg_post",
"fire_map_quick",
"blood_mist",
"ped_foot_dusty",
"ent_amb_trop_fish_swarm_lil",
"wtr_rocks_wall_splash",
"wheel_fric_sand",
"shotgun_water",
"bul_concrete_heli",
"water_boat_dinghy_bow_mounted",
"ent_amb_fbi_fire_wall_lg",
"ent_amb_foundry_dust",
"scrape_metal",
"exp_hydrant_decals_sp",
"exp_grd_boat_spawn",
"ent_amb_sewer_drips_med",
"fire_petrol_script",
"ent_amb_stoner_vent_smoke",
"muz_alternate_star_fp",
"wheel_spin_leaves",
"ent_anim_bm_water_scp",
"ent_sht_molten_liquid",
"bul_concrete_minigun",
"exp_bird_crap",
"ent_amb_dust_motes",
"ent_sht_paint_cans",
"veh_light_amber",
"ent_dst_paint_cans",
"veh_downwash_foliage",
"exp_grd_train",
"weap_veh_turbulance_foliage",
"liquid_splash_gloopy",
"exp_air_blimp_sp",
"env_interior_chickenfarm",
"exp_sht_steam",
"ent_amb_falling_leaves_m",
"veh_plane_damage",
"blood_nose",
"muz_smoking_barrel",
"scrape_mud",
"water_boat_Suntrap_bow",
"ent_sht_water",
"ent_ray_heli_aprtmnt_l_fire",
"fire_wrecked_truck_vent",
"proj_missile_underwater",
"ent_col_palm_leaves",
"wheel_spin_water_deep",
"wheel_spin_blood",
"ent_dst_gen_liquid_burst",
"ent_dst_wood_planks",
"ent_amb_steam_vent_round",
"ent_brk_tree_leaves",
"scrape_veg",
"ent_amb_moths_swarm",
"exp_air_rpg_plane_lod",
"wheel_fric_gravel",
"td_blood_hatchet",
"ent_amb_peeing",
"bul_decal_blood",
"exp_air_rpg_sp",
"wheel_decal_water_Bike",
"bul_grass",
"ent_sht_cactus",
"blood_entry_head_sniper",
"weap_veh_turbulance_dirt",
"veh_oil_slick",
"ped_scrape_sand_underwater",
"ped_foot_decal_water",
"lens_snow",
"td_blood_hatchet_back",
"ent_amb_sprinkler_city_sml",
"ent_amb_insect_plane",
"water_boat_jetmax_bow",
"exp_grd_flare",
"wheel_fric_hard",
"proj_flare_fuse",
"muz_pistol_fp",
"veh_exhaust_heli_cargobob",
"bul_wood_splinter_heli",
"ent_amb_sewer_drips_spawned_lg",
"ent_ray_heli_aprtmnt_s_fire",
"ent_amb_rapid_area_spray",
"wheel_fric_water_Bike",
"sp_fbi_fire_drip_trails",
"ent_ray_ch2_farm_fire_dble",
"veh_vent_boat",
"exp_grd_molotov",
"veh_exhaust_titan",
"ent_amb_fbi_smoulder_sm",
"ent_dst_gen_plastic_cont",
"exp_grd_vehicle_lod",
"wheel_spin_grass",
"lens_water_run",
"ent_dst_office_paper",
"wheel_fric_leaves_Bike",
"ent_amb_wind_grass",
"liquid_splash_petrol",
"veh_train_sparks",
"ent_dst_gen_cardboard",
"water_splash_whale_wade",
"ent_amb_sparking_wires",
"scrape_sand_underwater",
"ent_dst_plant_leaves",
"ent_brk_lamppost_base",
"ent_amb_waterfall_splash_p",
"liquid_splash_pee",
"wheel_fric_gravel_LOD",
"muz_smoking_barrel_shotgun",
"bul_paper",
"muz_rpg",
"ped_foot_gravel_deep",
"bul_brick",
"mel_concrete",
"ent_ray_heli_aprtmnt_embers",
"bul_glass_tv",
"wheel_decal_mud",
"liquid_splash_paint",
"ent_amb_fbi_light_door",
"muz_smoking_barrel_fp",
"veh_exhaust_start_bike",
"water_splash_veh_in",
"fire_wrecked_plane",
"ent_ray_tanker_petrol_spray",
"ent_amb_wind_hay_dir",
"ent_amb_candle_flame",
"muz_assault_rifle_fp",
"ped_foot_chickenfarm",
"exp_grd_grenade",
"ent_amb_wfall_splash_sml",
"exp_grd_vehicle_spawn",
"ent_dst_electrical",
"bul_carmetal",
"veh_slipstream",
"exp_grd_boat",
"ent_amb_leaves_oak_g",
"wheel_fric_hard_dusty_Tank",
"water_jetski_bow1_mounted",
"veh_vent_plane_duster",
"fire_wrecked_truck",
"ent_amb_wind_tree_leaves",
"water_cannon_jet",
"ent_ray_ch2_farm_smoke_dble",
"ent_ray_heli_aprtmnt_exp",
"env_dust_devil_rural_sma",
"ent_dst_concrete",
"ent_ray_heli_aprtmnt_sprk_wrs",
"env_wind_debris_city",
"ent_sht_blood",
"exp_grd_propane",
"veh_vent_plane_lazer",
"fire_wrecked_bike",
"veh_panel_shut_tank",
"water_boat_exit",
"bang_sand_underwater",
"ent_sht_paper_bails",
"ent_amb_smoke_general",
"blood_entry_shotgun",
"ent_dst_upholstery",
"veh_exhaust_velum",
"ent_amb_elec_crackle_sp",
"_fog_plane",
"exp_grd_sticky_lod",
"blood_entry_sniper",
"wheel_decal_mud_Bike",
"fire_object",
"proj_disturb_dust",
"bullet_shotgun_tracer",
"ent_ray_ch2_farm_fire_l_l_l",
"ent_amb_foundry_heat_haze",
"ent_dst_donuts",
"wheel_fric_sandWet_LOD",
"water_splash_sub_in",
"veh_wind_litter_dir",
"ent_amb_cig_smoke_linger",
"ent_dst_hobo_trolley",
"shark_underwater_trails",
"ent_anim_pneumatic_drill",
"ped_breath_water",
"bul_chickenfarm",
"proj_grenade_trail",
"exp_grd_vehicle_post",
"weap_hvy_turbulance_sand",
"ent_col_electrical",
"veh_exhaust_vulkan",
"veh_plane_propeller_destroy",
"scr_fbi_falling_dust",
"proj_grenade_smoke",
"scr_agency3b_sprinkler_off",
"ent_brk_blood",
"exp_grd_bzgas_smoke",
"ent_sht_petrol_fire",
"ent_amb_water_drips_spawned_lg",
"ent_amb_abattoir_saw_blood",
"bul_decal_water",
"veh_exhaust_truck_rig",
"ent_amb_snow_mist_upper",
"wheel_decal_water_Tank",
"ent_amb_fbi_falling_debris",
"ent_dst_elec_fire",
"env_dust_motes_int_hvy",
"exp_grd_petrol_pump_spawn",
"fire_wrecked_car_vent",
"water_splash_shark_wade",
"veh_panel_shut_feltzer2010",
"wheel_fric_gravel_Bike",
"ent_dst_newspaper",
"ent_brk_wood_planks",
"mel_glass",
"blood_headshot",
"ent_dst_wet_sand",
"blood_throat",
"fire_wrecked_boat",
"trail_splash_water",
"ent_anim_bm_water_mist",
"ent_amb_fly_zapped_spawned",
"exp_grd_rpg_sp",
"env_bar_haze",
"exp_grd_sticky",
"veh_petrol_leak_bullet",
"sp_ent_sparking_wires",
"exp_grd_gas_can",
"ent_amb_sewer_drips_spawned",
"ent_amb_sprinkler_city",
"water_splash_sub_out",
"ent_amb_fbi_smoke_ramp_lt",
"veh_exhaust_tug",
"glass_windscreen",
"ent_dst_elec_crackle",
"proj_molotov_flame_fp",
"eject_heli_gun",
"ent_sht_extinguisher",
"ent_amb_stoner_dust_drop",
"ent_anim_gardener_plant",
"wheel_fric_hard_tank",
"veh_panel_open_carHK",
"water_splash_animal_wade",
"fire_wheel",
"veh_light_red_trail",
"ent_amb_falling_cherry_bloss",
"ped_foot_decal_petrol",
"ent_dst_inflatable",
"bang_carmetal",
"wtr_sea_pole_splash",
"bang_blood_car",
"ent_amb_vent_haze_sm",
"water_splash_ped",
"ent_amb_int_fireplace_sml",
"muz_tank",
"ent_amb_pro_elec_fires",
"wheel_decal_oil_Bike",
"veh_wingtip",
"ent_sht_cardboard",
"exp_grd_vehicle_sp",
"proj_laser_player",
"ent_amb_river_splash_gen",
"exp_grd_tankshell",
"ent_amb_foundry_steam",
"water_jetski_rev",
"ped_parachute_trail",
"env_interior_foundry",
"ent_amb_water_drips_med",
"rim_fric_hard",
"wheel_fric_grass_LOD",
"ent_brk_coins",
"ent_amb_rapid_dir_spray",
"veh_sub_dive",
"ent_amb_fbi_fire_fogball",
"ent_anim_animal_graze",
"exp_air_blimp",
"muz_minigun_alt",
"ent_amb_stoner_falling_wchips",
"wheel_decal_water_deep",
"exp_grd_rpg_plane_sp",
"veh_exhaust_truck",
"blood_mist_prop",
"env_wind_debris_woodland",
"bullet_tracer_jet",
"ent_amb_leaves_ficus_g",
"veh_overturned_exhaust",
"blood_entry",
"eject_shotgun",
"muz_alternate_star",
"sp_fire_trail_heli",
"ent_brk_uprooted",
"ent_amb_foundry_steam_spawn",
"ent_amb_int_waterfall_splash",
"exp_grd_barrel",
"exp_grd_vehicle",
"ent_amb_wind_litter",
"muz_shotgun",
"ent_ray_heli_aprtmnt_h_fire",
"veh_downwash_dirt",
"water_jetski_exit",
"exp_grd_rpg_lod",
"weap_petrol_can",
"fire_ped_smoulder",
"ent_amb_fly_zapped",
"veh_air_debris",
"ent_sht_dust",
"veh_panel_open_truck",
"ent_amb_fbi_fire_dub_door",
"wheel_fric_sand_Bike",
"wheel_fric_leaves",
"env_dust_devil_rural_lrg",
"bullet_tracer",
"ent_dst_chick_carcass",
"ent_amb_sewer_drips_sm",
"wheel_burnout",
"scrape_sand",
"ent_amb_cockroach_swarm",
"ent_amb_generator_smoke",
"muz_laser",
"env_gunsmoke_paper_factory",
"veh_vent_heli",
"ent_amb_river_mist_gen",
"ent_amb_insect_swarm",
"bul_tarmac_heli",
"muz_smoking_barrel_rocket",
"ent_amb_fire_gaswork",
"ent_amb_cluckb_steam",
"water_amph_quad_entry",
"ent_col_tree_leaves",
"ent_amb_stoner_woodchip_drop",
"water_splash_veh_trail",
"ent_dst_inflate_ball_clr",
"exp_grd_gren_sp",
"wheel_fric_leaves_Tank",
"weap_extinguisher",
"env_wind_debris_desert",
"ent_brk_banknotes",
"ent_amb_fountain_mansion2",
"ent_amb_stoner_rubble_drop",
"ped_foot_bushes",
"ent_amb_sol1_plane_wreck",
"wheel_fric_mud_Bike",
"veh_wheel_burst",
"fire_vehicle",
"ent_anim_cig_exhale_mth",
"ped_water_drips",
"ent_ray_paleto_gas_plume_amb_L",
"eject_pistol",
"glass_side_window_PC",
"water_splash_plane_wade",
"ent_amb_cockroaches",
"ped_bang_sand_underwater",
"veh_exhaust_plane_misfire",
"ent_dst_pineapple",
"ped_foot_water_puddle",
"ent_amb_bubble_stream",
"ped_wade_mud",
"ent_dst_metal_frag",
"water_splash_bicycle_out",
"ent_amb_fbi_live_wires",
"veh_air_turbulance_sand",
"eject_shotgun_fp",
"exp_grd_plane_spawn",
"mp_parachute_smoke",
"_fog_foundry",
"ent_dst_mail",
"weap_hvy_turbulance_foliage",
"ent_amb_abattoir_carcass",
"ent_anim_hen_flee",
"ent_col_falling_snow",
"exp_sht_extinguisher",
"ent_dst_crispbags",
"wheel_spin_sand",
"water_boat_LOD",
"ent_sht_beer_containers",
"veh_exhaust_start",
"ent_amb_wfall_splash_lg",
"ent_amb_fbi_smoke_creep",
"bang_metal",
"fire_ped_limb",
"water_amph_quad_bow_mounted",
"ent_amb_water_drips_dam_med",
"veh_air_turbulance_foliage",
"ent_amb_trop_fish_swarm",
"ent_ray_heli_aprtmnt_s_fire_sq",
"ent_anim_cig_exhale_nse_car",
"veh_exhaust_misfire",
"bullet_tracer_mg",
"wheel_fric_gravel_Tank",
"ent_amb_fbi_smoke_door_lt",
"proj_molotov_trail",
"veh_vent_plane",
"veh_light_clear",
"scrape_dirt_dry",
"ent_amb_fbi_smoke_land_hvy",
"fire_wrecked_rc",
"wheel_decal_petrol",
"ent_ray_paleto_gas_plume_amb",
"water_cannon_spray",
"ent_amb_cold_air_vent",
"bul_stungun",
"wheel_decal_sand_deep",
"blood_mouth",
"veh_exhaust_cuban800",
"proj_laser_enemy",
"water_splash_plane_out",
"ent_amb_wfall_splash_med",
"ent_amb_falling_leaves_l",
"fire_wrecked_heli",
"ent_brk_cactus",
"liquid_splash_water",
"bang_dirt_dry",
"proj_rpg_trail",
"water_heli_blades",
"bul_plaster_brittle",
"env_wind_sand_dune",
"ent_amb_fbi_fire_lg",
"fire_wrecked_tank_cockpit",
"eject_sniper_amrifle",
"bul_decal_mud",
"bul_brick_heli",
"scrape_blood_car",
"wheel_spin_water",
"ent_amb_water_drips_sm",
"ent_amb_fbi_smoke_stair_gather",
"wheel_decal_oil",
"veh_faggio_exhaust",
"td_blood_melee_blunt",
"wheel_fric_mud",
"lens_test",
"ent_amb_floating_debris",
"ent_col_gen_tree_dust",
"weap_heist_flare_trail",
"bang_hydraulics",
"exp_air_plane_rpg_spawn",
"ent_ray_heli_aprtmnt_silt",
"ent_amb_smoke_foundry_white",
"wheel_decal_blood_Bike",
"wheel_decal_mud_Tank",
"ent_amb_trev1_trailer_sp_f",
"ent_amb_dry_ice_vent",
"sp_foundry_sparks",
"ent_amb_waterfall_pool",
"muz_smg",
"eject_pistol_fp",
"scr_fbi_ground_debris",
"env_stripclub_haze",
"blood_stungun",
"veh_wingtip_cargo",
"bul_bushes",
"bang_plastic",
"ent_amb_stoner_falling_debris",
"ent_sht_extinguisher_water",
"fire_map",
"ent_amb_fountain_pour",
"weap_veh_turbulance_water",
"weap_smoke_grenade",
"water_splash_generic",
"scrape_blood",
"ent_amb_moths_cupboard",
"bul_glass_heli",
"ent_amb_smoke_factory_white",
"muz_railgun",
"exp_air_rpg",
"eject_sniper",
"veh_vent_plane_titan",
"ent_sht_rubbish",
"water_jetmax_exit",
"wheel_fric_sand_Tank",
"ent_amb_trevor_tap_drip",
"veh_exhaust_cargo",
"td_blood_pistol",
"ent_amb_fbi_smoke_ramp_hvy",
"veh_debris_trail",
"wtr_rocks_rnd_splash",
"ent_ray_fin_petrol_splash",
"veh_exhaust_trailer_chimney",
"fire_wrecked_bus",
"veh_exhaust_afterburner",
"ent_amb_fbi_smoke_ramp_med",
"exp_grd_rpg_spawn",
"ent_dst_snow_tombs",
"exp_grd_rpg_plane",
"ent_amb_steam_vent_open_hvy",
"glass_shards",
"ent_sht_telegraph_pole",
"ent_dst_rocks",
"ent_amb_steam_vent_rnd_hvy",
"ent_amb_fbi_smoke_land_med",
"ent_amb_smoke_factory",
"eject_smg_fp",
"ent_dst_box_noodle",
"ent_amb_wind_litter_dust_swirl",
"exp_air_grenade",
"ent_amb_acid_bath",
"blood_melee_blunt",
"fire_petroltank_boat",
"fire_ped_body",
"blood_armour",
"ent_dst_bread",
"water_splash_veh_wade",
"ent_amb_fbi_door_smoke",
"ent_amb_fbi_smoke_door_hvy",
"ped_wade_sand",
"exp_air_blimp2",
"veh_vent_bike",
"veh_rotor_break_tail",
"scrape_concrete",
"muz_pistol",
"water_boat_dinghy_bow",
"ent_brk_sparking_wires_sp",
"ped_breath",
"ent_amb_stoner_landing",
"ped_underwater_trails",
"bul_sand_loose",
"ped_foot_decal_blood",
"water_splash_bicycle_in",
"lens_water",
"veh_wheel_puncture",
"veh_wheel_puncture_rc",
"wheel_spin_sandWet",
"ent_amb_fbi_fire_sm",
"water_splash_bike_trail",
"ped_breath_scuba",
"ent_ray_paleto_gas_window_fire",
"water_splash_bicycle_trail",
"blood_fall",
"env_wind_debris_mountain",
"ent_dst_pumpkin",
"ent_amb_water_roof_pour_long",
"sp_fire_trail_plane",
"wheel_fric_dusty_LOD",
"ent_amb_waterfall_runoff",
"ent_dst_ceramics",
"wheel_decal_sand_wet_deep",
"veh_sub_leak",
"ent_amb_water_roof_pour",
"ent_dst_egg_mulch",
"wheel_decal_puddle",
"wheel_fric_hard_Bike",
"ent_dst_gen_choc",
"proj_molotov_flame",
"env_smoke_fbi_thin",
"ent_dst_litter",
"water_splash_bicycle_wade",
"scr_agency3b_sprinkler_on",
"water_amph_car_bow_mounted",
"veh_exhaust_boat",
"veh_air_turbulance_water",
"fire_extinguish",
"wheel_fric_hard_dusty",
"ped_blood_drips",
"veh_air_turbulance_default",
"ent_anim_blown_radiator",
"bul_grass_heli",
"ent_amb_fly_swarm",
"exp_grd_rpg",
"ent_amb_falling_leaves_s",
"ent_anim_bbq",
"veh_oil_leak",
"ent_amb_rapid_dir_splash",
"muz_smg_fp",
"bul_dirt",
"bul_decal_petrol",
"bul_tarmac",
"fire_petroltank_bike",
"ent_amb_vent_haze_lg",
"veh_downwash_water",
"ped_foot_sand_wet_deep",
"wheel_decal_blood",
"env_fog",
"blood_wheel",
"veh_petrol_leak_bike",
"ent_amb_int_waterfall_runoff",
"ent_dst_glass_bulb",
"env_dust_motes",
"ent_sht_electrical_box",
"ent_amb_fbi_smoke_edge_lip",
"ent_amb_fbi_smoke_linger_lt",
"ent_amb_water_roof_drips",
"ent_dst_dust",
"ent_amb_int_fireplace",
"wheel_decal_water",
"ent_amb_wind_leaves_swirl",
"ent_dst_rocks_small",
"fire_map_slow",
"ent_amb_waterfall_splash",
"ent_amb_dry_ice_area",
"fire_petrol_pool",
"water_splash_bike_in",
"ent_anim_fish_flee_bubbles",
"bang_sand",
"fire_petrol_half",
"ent_anim_cig_smoke_car",
"ent_amb_fbi_fire_wall_sm",
"veh_petrol_leak",
"ent_dst_inflate_lilo",
"eject_sniper_heavy",
"exp_grd_petrol_pump_post",
"env_smoke_grenade",
"bul_water",
"ent_sht_feathers",
"ent_brk_champagne_case",
"ent_anim_fish_breath_bubbles",
"wheel_fric_grass_Tank",
"glass_side_window",
"ent_ray_prologue_elec_crackle_sp",
"trail_splash_petrol",
"muz_minigun",
"ped_wade_sand_wet",
"wheel_decal_puddle_Bike",
"water_boat_Marques_bow",
"veh_exhaust_car",
"ent_amb_snow_mist_base",
"ped_parachute_canopy_trail",
"ent_amb_foundry_arc_heat",
"veh_rotor_break",
};
char* Female[] =
{
	"s_f_y_clubbar_02", "s_f_y_beachbarstaff_01", "s_f_y_casino_01","S_F_Y_Stripper_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01", "U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","A_F_Y_Tennis_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01", "A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02", "A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01",
	"U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","MP_F_Misty_01", "S_F_M_SweatShop_01", "MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite",
};

char* Unclassed[] =
{
	 "U_M_Y_ImpoRage", "U_M_Y_Zombie_01", "S_M_Y_Swat_01", "S_M_Y_Pilot_01", "S_M_M_MovAlien_01", "S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
	"S_M_Y_PrisMuscl_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
	"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
	"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01", "S_M_Y_Swat_01", "U_M_Y_FIBMugger_01", "U_M_M_FIBArchitect", "U_M_Y_MilitaryBum", "MP_M_FIBSec_01", "S_M_M_FIBOffice_01","S_M_M_FIBOffice_02", "U_M_Y_MilitaryBum", "S_M_M_Marine_01","S_M_M_Marine_02", "S_M_Y_Prisoner_01",
	"A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03", "A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01", "A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03", "CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang","CSB_Ramp_hic","CSB_Ramp_hipster", "CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_TrafficWarden","G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
	"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
	"HC_Driver","HC_Gunman","HC_Hacker", "A_M_M_ACult_01","A_M_M_AfriAmer_01", "A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02", "A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02", "A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02","A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02", "A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02", "CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
	"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero",
	"S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport", 
	 "IG_RoosterMcCraw", "CSB_Charlie_Reed", "IG_Charlie_Reed", "IG_Pernell_Moss", "S_M_M_CCrew_02", "CSB_AviSchwartzman_03", "IG_AviSchwartzman_03", "U_M_M_Juggernaut_03", "CS_DrFriedlander_02",
	 "IG_DrFriedlander_02", "CS_NervousRon_02", "IG_NervousRon_02", "CSB_Chef_03", "IG_Chef_03", "CSB_Dax", "IG_Dax", "CSB_Luchadora", "IG_Luchadora", "IG_HippyLeader", "CSB_Labrat", "IG_Labrat",
	  "IG_Furry", "IG_Fooliganz_01", "IG_Fooliganz_02", "IG_AcidLabCook", "IG_GunVanSeller", "G_F_M_Fooliganz_01", "A_F_M_GenStreet_01", "U_M_M_YuleMonster", "S_M_M_HazmatWorker_01", 
	  "G_M_M_FriedlanderGoons_01", "G_M_M_Fooliganz_01", "A_M_M_BankRobber_01",
};

int attacker_model_pos = 0;
static char* attacker_model_list[] = {
	"IG_Furry",
		 "U_M_Y_ImpoRage", "U_M_Y_Zombie_01", "S_M_Y_Swat_01", "S_M_Y_Pilot_01", "S_M_M_MovAlien_01", "S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
	"S_M_Y_PrisMuscl_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
	"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
	"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01", "S_M_Y_Swat_01", "U_M_Y_FIBMugger_01", "U_M_M_FIBArchitect", "U_M_Y_MilitaryBum", "MP_M_FIBSec_01", "S_M_M_FIBOffice_01","S_M_M_FIBOffice_02", "U_M_Y_MilitaryBum", "S_M_M_Marine_01","S_M_M_Marine_02", "S_M_Y_Prisoner_01",
	"A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03", "A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01", "A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03", "CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang","CSB_Ramp_hic","CSB_Ramp_hipster", "CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_TrafficWarden","G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
	"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
	"HC_Driver","HC_Gunman","HC_Hacker", "A_M_M_ACult_01","A_M_M_AfriAmer_01", "A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02", "A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02", "A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02","A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02", "A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02", "CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
	"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero",
	"S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
	 "IG_RoosterMcCraw", "CSB_Charlie_Reed", "IG_Charlie_Reed", "IG_Pernell_Moss", "S_M_M_CCrew_02", "CSB_AviSchwartzman_03", "IG_AviSchwartzman_03", "U_M_M_Juggernaut_03", "CS_DrFriedlander_02",
	"IG_DrFriedlander_02", "CS_NervousRon_02", "IG_NervousRon_02", "CSB_Chef_03", "IG_Chef_03", "CSB_Dax", "IG_Dax", "CSB_Luchadora", "IG_Luchadora", "IG_HippyLeader", "CSB_Labrat", "IG_Labrat",
	 "IG_Fooliganz_01", "IG_Fooliganz_02", "IG_AcidLabCook", "IG_GunVanSeller", "G_F_M_Fooliganz_01", "A_F_M_GenStreet_01", "U_M_M_YuleMonster", "S_M_M_HazmatWorker_01",
	 "G_M_M_FriedlanderGoons_01", "G_M_M_Fooliganz_01", "A_M_M_BankRobber_01",
	"s_f_y_clubbar_02", "s_f_y_beachbarstaff_01", "s_f_y_casino_01","S_F_Y_Stripper_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01", "U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","A_F_Y_Tennis_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01", "A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02", "A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01",
	"U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","MP_F_Misty_01", "S_F_M_SweatShop_01", "MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","s_f_y_clubbar_02", "s_f_y_beachbarstaff_01", "s_f_y_casino_01","S_F_Y_Stripper_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01", "U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","A_F_Y_Tennis_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01", "A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02", "A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01",
	"U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","MP_F_Misty_01", "S_F_M_SweatShop_01", "MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite", "IG_TylerDix","IG_Wade","IG_Zimbor","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
	"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
	"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
	"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
	"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
	"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
	"CS_AmandaTownley","CS_Andreas", "cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
	"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
	"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
	"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
	"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","A_C_Humpback", "A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
	"A_C_Rhesus","A_C_Rottweiler", "A_C_Pug", "A_C_Poodle","A_C_Westy","A_C_Seagull","A_C_SharkTiger","A_C_Shepherd", "A_C_Cat_01", "A_C_Rabbit_01", "A_C_KillerWhale", "A_C_SharkHammer", "A_C_SharkTiger", "A_C_Dolphin",
	"A_C_Panther", "A_C_Rabbit_02", "A_C_Chimp_02", "A_C_Boar_02", "A_C_Coyote_02", "A_C_Deer_02", "A_C_MtLion_02", "A_C_Pug_02",
};
char* weapon_name_list[] = {
	"WEAPON_PISTOL",
			"WEAPON_COMBATPISTOL",
			"WEAPON_APPISTOL",
			"WEAPON_PISTOL50",
			"WEAPON_SMG",
			"WEAPON_MICROSMG",
			"WEAPON_ASSAULTRIFLE",
			"WEAPON_CARBINERIFLE",
			"WEAPON_ADVANCEDRIFLE",
			"WEAPON_MG",
			"WEAPON_COMBATMG",
			"WEAPON_PUMPSHOTGUN",
			"WEAPON_SAWNOFFSHOTGUN",
			"WEAPON_ASSAULTSHOTGUN",
			"WEAPON_HEAVYSNIPER",
			"WEAPON_SNIPERRIFLE",
			"WEAPON_GRENADELAUNCHER",
			"WEAPON_RPG",
			"WEAPON_MINIGUN",
			"WEAPON_GRENADE",
			"WEAPON_SMOKEGRENADE",
			"WEAPON_STICKYBOMB",
			"WEAPON_MOLOTOV",
			"WEAPON_PETROLCAN",
			"GADGET_PARACHUTE",
			"WEAPON_KNIFE",
			"WEAPON_NIGHTSTICK",
			"WEAPON_HAMMER",
			"WEAPON_BAT",
			"WEAPON_CROWBAR",
			"WEAPON_GOLFCLUB",
			"WEAPON_ASSAULTMG",
			"WEAPON_ASSAULTSMG",
			"WEAPON_ASSAULTSNIPER",
			"WEAPON_BULLPUPSHOTGUN",
			"WEAPON_BOTTLE",
			"WEAPON_SPECIALCARBINE",
			"WEAPON_SNSPISTOL",
			"WEAPON_HEAVYPISTOL",
			"WEAPON_BULLPUPRIFLE",
			"WEAPON_GUSENBERG",
			"WEAPON_VINTAGEPISTOL",
			"WEAPON_DAGGER",
			"WEAPON_MUSKET",
			"WEAPON_FIREWORK",
			"WEAPON_FLAREGUN",
			"WEAPON_HEAVYSHOTGUN",
			"WEAPON_MARKSMANRIFLE",
			"WEAPON_PROXMINE",
			"WEAPON_HOMINGLAUNCHER",
			"WEAPON_HATCHET",
			"WEAPON_COMBATPDW",
			"WEAPON_KNUCKLE",
			"WEAPON_MARKSMANPISTOL",
			"WEAPON_MACHETE",
			"WEAPON_MACHINEPISTOL",
			"WEAPON_DBSHOTGUN",
			"WEAPON_COMPACTRIFLE",
			"WEAPON_FLASHLIGHT",
			"WEAPON_REVOLVER",
			"WEAPON_SWITCHBLADE",
			"WEAPON_AUTOSHOTGUN",
			"WEAPON_MINISMG",
			"WEAPON_COMPACTLAUNCHER",
			"WEAPON_BATTLEAXE",
			"WEAPON_PIPEBOMB",
			"WEAPON_POOLCUE",
			"WEAPON_WRENCH",
			"WEAPON_ASSAULTRIFLE_MK2",
			"WEAPON_CARBINERIFLE_MK2",
			"WEAPON_COMBATMG_MK2",
			"WEAPON_HEAVYSNIPER_MK2",
			"WEAPON_PISTOL_MK2",
			"WEAPON_SMG_MK2",
			"WEAPON_BULLPUPRIFLE_MK2",
			"WEAPON_MARKSMANRIFLE_MK2",
			"WEAPON_PUMPSHOTGUN_MK2",
			"WEAPON_REVOLVER_MK2",
			"WEAPON_SNSPISTOL_MK2",
			"WEAPON_SPECIALCARBINE_MK2",
			"WEAPON_DOUBLEACTION",
			"WEAPON_RAYPISTOL",
			"WEAPON_RAYCARBINE",
			"WEAPON_RAYMINIGUN",
			"WEAPON_STONE_HATCHET",
			"WEAPON_NAVYREVOLVER",
			"WEAPON_CERAMICPISTOL",
			"WEAPON_GADGETPISTOL",
			"WEAPON_MILITARYRIFLE",
			"WEAPON_COMBATSHOTGUN",
			"WEAPON_HEAVYRIFLE",
			"WEAPON_EMPLAUNCHER",
			"WEAPON_FERTILIZERCAN",
			"WEAPON_STUNGUN_MP",
			"WEAPON_METALDETECTOR",
			"WEAPON_TACTICALRIFLE",
			"WEAPON_PRECISIONRIFLE",
};

bool cloneprotection = false;

bool Bottriggerr = false;
bool garage_save_bypass = false;

bool freecamclip = false;

bool expand = false;

Entity gravent;
Vector3 GET_CAMERA_DIRECTION(float distance)
{
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924;
	float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));

	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;


}

void NoClippp()
{
	auto ped = PLAYER::PLAYER_PED_ID();
	auto pos = ENTITY::GET_ENTITY_COORDS(ped, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, pos.x, pos.y, pos.z, true, true, true);

	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
	{
		Vector3 pos = add(&ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 1.f));
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), pos.x, pos.y, pos.z, true, true, true);
	}
}
void Furry_attacker(char* weapon) {
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	Hash railgun = GAMEPLAY::GET_HASH_KEY(weapon);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY("IG_Furry");
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
	PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
	WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
	PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
	AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
	PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
	egcount++;
}

void Furry_Crash(char* weapon) {
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	Hash railgun = GAMEPLAY::GET_HASH_KEY(weapon);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY("IG_Furry");
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
	PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
	WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
	PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
	AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
	PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
	PED::APPLY_DAMAGE_TO_PED(eclone[egcount], 1000, false);
	egcount++;
}

bool attacker_invincible = false;
bool attacker_has_cop = false;
bool attacker_keep_task = false;
bool attacker_weapon_switch = false; 
int attacker_armour = 0;
int attacker_accuracy = 0;
int attacker_shoot_rate = 0;
void custom_attacker(char* model, char* weapon) {
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	Hash railgun = GAMEPLAY::GET_HASH_KEY(weapon);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY(model);
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	Ped attacker = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	if(attacker_invincible){ ENTITY::SET_ENTITY_INVINCIBLE(attacker, true); }else{ ENTITY::SET_ENTITY_INVINCIBLE(attacker, false); }
	PED::SET_PED_COMBAT_ABILITY(attacker, 100);
	WEAPON::GIVE_WEAPON_TO_PED(attacker, railgun, railgun, 9999, 9999);
	if(attacker_weapon_switch){ PED::SET_PED_CAN_SWITCH_WEAPON(attacker, true); }else{ PED::SET_PED_CAN_SWITCH_WEAPON(attacker, false); }
	AI::TASK_COMBAT_PED(attacker, selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(attacker, 1000);
	PED::SET_PED_COMBAT_RANGE(attacker, 1000);
	if(attacker_keep_task){ PED::SET_PED_KEEP_TASK(attacker, true); }else{ PED::SET_PED_KEEP_TASK(attacker, false); }
	if (attacker_has_cop){ PED::SET_PED_AS_COP(attacker, true); }else{ PED::SET_PED_AS_COP(attacker, false); }
	PED::SET_PED_ARMOUR(attacker, attacker_armour);
	PED::SET_PED_ACCURACY(attacker, attacker_accuracy);
	PED::SET_PED_SHOOT_RATE(attacker, attacker_shoot_rate);
	egcount++;
}

void poolped1()
{
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY("Player_Zero");
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
	PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
	WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
	PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
	AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
	PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
	egcount++;
}


void poolped2()
{
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY("Player_One");
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
	PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
	WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
	PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
	AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
	PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
	egcount++;
}


void poolped3()
{
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY("Player_Two");
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
	PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
	WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
	PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
	AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
	PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
	PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
	egcount++;
}


void NoClip7()
{
	auto ped = PLAYER::PLAYER_PED_ID();
	auto pos = ENTITY::GET_ENTITY_COORDS(ped, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, pos.x, pos.y, pos.z, true, true, true);

	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
	{
		Vector3 pos = add(&ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 1.f));
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), pos.x, pos.y, pos.z, true, true, true);
	}

}



bool threedwaypoint = true;
void wasted(char* text1, char* text2)
{
	int textstyle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("mp_big_message_freemode");
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED)
	{
	
	}
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(textstyle, "SHOW_SHARD_WASTED_MP_MESSAGE");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(text1);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(text2);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(5);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(textstyle, 181, 235, 245, 175, 1);

}


void Smash()
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Player tempPed = PLAYER::PLAYER_ID();
				Vector3 rot1 = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 dir1 = rot_to_direction(&rot1);
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);
				AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", veh[offsettedID], "docks_heist_finale_2a_sounds", 0, 0);
				ENTITY::SET_ENTITY_HEADING(veh[offsettedID], ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, dir1.x * 500.0f, dir1.y * 500.0f, dir1.z * 500.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);


			}
		}
	}
}
void NoClipElectro()
{
	Vector3 rota = CAM::GET_GAMEPLAY_CAM_ROT(0.1);
	Vector3 dira = GET_CAMERA_DIRECTION(0.1);
	float d = 0.09;
	if (CONTROLS::IS_CONTROL_PRESSED(0, 52), CONTROLS::IS_CONTROL_PRESSED(0, 55))
		d -= 0.0;
	int vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 Position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), TRUE);
	int ent = vehicle == 0 ? PLAYER::PLAYER_PED_ID() : vehicle;
	ENTITY::SET_ENTITY_COLLISION(ent, true, 0);
	ENTITY::SET_ENTITY_ROTATION(ent, rota.x, rota.y, rota.z, 0.1, 0.1);
	ENTITY::SET_ENTITY_COORDS(ent, Position.x, Position.y, Position.z - 0, 0, 0, 0, 0.1);
	if (IsKeyPressed(VK_KEY_V))
	{
		if (ent == vehicle)
			if (ent == PLAYER::PLAYER_PED_ID())
			{
				ENTITY::SET_ENTITY_COLLISION(ent, false, 0);
				ENTITY::SET_ENTITY_ROTATION(ent, rota.x, rota.y, rota.z, 0.2, 0.1);


			}
		ENTITY::SET_ENTITY_COORDS(ent, Position.x + (dira.x), Position.y + (dira.y), Position.z + (dira.z), 0, 0, 0, 0.1);

	}
}

void Electrocute()
{
	const int numElements = 10;
	const int arrSize = numElements * 3 + 3;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), veh, true);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_trev1_trailer_boosh", Pos.x, Pos.y, Pos.z, 0, 0, 0, 1, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				PED::APPLY_DAMAGE_TO_PED(veh[offsettedID], 999, true);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_trev1_trailer_boosh", Pos.x, Pos.y, Pos.z, 0, 0, 0, 1, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_family4");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_family4");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_fam4_trailer_sparks", Pos.x, Pos.y, Pos.z, 0, 0, 0, 1, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				char* dict = "rcmcollect_paperleadinout@";//anim
				char* anim = "meditiate_idle";
				STREAMING::REQUEST_ANIM_DICT(dict);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.1f, 0, 0, 0);//Right Hand
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.1f, 0, 0, 0);//Left Hand
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			}
		}
	}
}

void TracePedsElectro()
{
	const int numElements = 10;
	const int arrSize = numElements * 1 + 1;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), veh, true);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);
				Player playerHandle = PLAYER::GET_PLAYER_PED(veh[offsettedID]);
				Player playerPed = PLAYER::PLAYER_PED_ID();
				Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS((veh[offsettedID]), 0, 0, 0);
				Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 0, 0);
				GRAPHICS::DRAW_LINE(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 10, 250, 255, 255);
				GRAPHICS::DRAW_SPRITE("shared", "emptydot_32", getcoords1.x, getcoords1.y, getcoords1.z, 0.05f, 0.05f, 10, 250, 255, 200);
			}
		}
	}
}

void QuickHeal()
{
	float fHealth = Memory::get_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH });
	float fHealthMax = Memory::get_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH_MAX });
	float value = 20.f;
	value += fHealth;
	if (fHealth < fHealthMax) {
		fHealth = value;
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, value);
	}
	if (fHealth == fHealthMax) {
		fHealth = fHealthMax;
	}
}
void getrandomint(int one, int two) {
	GAMEPLAY::GET_RANDOM_INT_IN_RANGE(one, two);
}

void Electric()
{
	const int numElements = 10;
	const int arrSize = numElements * 3 + 3;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), veh, true);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);

				int Handle = PLAYER::GET_PLAYER_PED(veh[offsettedID]);
				char* dict = "ragdoll@human";
				char* anim = "electrocute";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(Handle, dict, anim, 8.0, 0.0, -1, 0, 0, 0, 0, 0);

			}
		}
	}
}

void vehicle_tornado() {
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	int vehs[arrSize];
	vehs[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
	for (int i = 0; i < count; ++i)
	{
		int offsettedID = i * 2 + 2;
		if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
		{
			if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(vehs[offsettedID], true, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), true, true, true, true, false, true);
			}
		}
	}
}
void ped_tornado() {
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;
	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(peds[OffsetID], true, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), true, true, true, true, false, true);
		}
	}
}
double cDegreeToRadian2(double n) {
	return n * 0.017453292519943295;
}

Vector3 cRotationToDirection2(Vector3 rot) {
	double num = cDegreeToRadian2(rot.z);
	double num2 = cDegreeToRadian2(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}


int rudolf_noclip = 0;
int rudolf_hostile = 0;

//Apocalypse
int apocalyspe_peds = 0;
int apocalyspe_lights = 0;
int apocalyspe_weather = 0;
int apocalyspe_flames = 0;
int apocalyspe_tornado = 0;
int apocalyspe_missile = 0;

//SuperMan
int superman_fly = 0;
int superman_eyes = 0;
int superman_jump = 0;
int superman_speed = 0;

int stoopid = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 20);
void dumbdumb() {
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		printf("Inject from Single Player for a more stable gameplay, contact the discord staff if support is needed!!\n");
		//Sleep(8000);
		//exit(0);
	}
	wasted("Foxy","Paid");

	char* rpc = "Foxy Menu Dev";
	NETWORK::NETWORK_SET_RICH_PRESENCE(1,1,1,1);
	NETWORK::_NETWORK_SET_RICH_PRESENCE_2(1, rpc);

	notify_center("Foxy", "Menu");
	NotificationCEO("Open The Menu By Pressing ~b~F6", "Foxy", "Reborn");
	//Foxy_Engine::settooltips(stoopid);
	while (true)
	{
		//GRAPHICS::DRAW_SPRITE("mpdebugmap", "debugmap", 0.4995f, 0.50f, 1.f, 1.f, 0.0f, 0, 0, 0, 255);//aimdot
		Menu::Checks::Controlls();
		//Features
		Local::UpdateLoop();
		Protections::UpdateLoop();
		Weap::UpdateLoop();
		Network::UpdateLoop();
		Veh::UpdateLoop();
		SPlayer::UpdateLoop();
		BH::UpdateLoop();
		AP::UpdateLoop();
		Recovery::UpdateLoop();
		Misc::UpdateLoop();
		SPlayer::OnlineplayerWepmods();

		if (Hulk_Info)
		{
			if (Local::Hulk == true)
			{
				YTD13();
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" HULK", 0.05f, 0.36f, 26, 74, 7, 255, 0.6500f, 0.8500f, 0, 6); // Info Left
				PrintToScreen(" HULK", 0.0512f, 0.3612f, 78, 235, 16, 255, 0.6500f, 0.8500f, 0, 6); // Info Left

				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 78, 235, 16, 180);// Background left color
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left black
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 78, 235, 16, 250);//RockStar Logo
				GRAPHICS::DRAW_SPRITE("commonmenu", "shop_NEW_Star", 0.4995f, 0.50f, 0.03f, 0.03f, 0.0f, 255, 255, 255, 200);//aimdot
				PrintToScreen(" Press [ SpaceBar ] To Jump Away", 0.06f, 0.42f, 78, 235, 16, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ Mouse Right ] To Grab", 0.06f, 0.44f, 78, 235, 16, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ Mouse Left ] To Throw", 0.06f, 0.46f, 78, 235, 16, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ G ] To Smash ( Air/Ground )", 0.06f, 0.48f, 78, 235, 16, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 78, 235, 16, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 252, 184, 250, 255);// Background left color
			}
		}
		if (Electro_Info)
		{
			if (Electro == true)
			{
				YTD13();
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" ELECTRO", 0.0512f, 0.36f, 14, 65, 66, 255, 0.6500f, 0.8500f, 0, 6); // Name 1 Left
				PrintToScreen(" ELECTRO", 0.05f, 0.3612f, 10, 250, 255, 255, 0.6500f, 0.8500f, 0, 6); // Name 2 Left
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 10, 250, 255, 180);// Background left
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenutu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 10, 250, 255, 250);//RockStar Logo
				GRAPHICS::DRAW_SPRITE("commonmenu", "shop_NEW_Star", 0.4995f, 0.50f, 0.03f, 0.03f, 0.0f, 255, 255, 255, 200);//aimdot
				PrintToScreen(" Press [ M ] For Electric Gravity Pulse", 0.06f, 0.42f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ N ] For Electric Ped Attack", 0.06f, 0.44f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ V ] For Electric Transport", 0.06f, 0.46f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ Mouse L/R ] To Grab & Throw Cars", 0.06f, 0.48f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ G ] For Force Smash", 0.06f, 0.5f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ B ] For Quick Healing", 0.06f, 0.52f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 252, 184, 250, 255);// Background left color
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 10, 250, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left


			}
		}
		if (Inferno_Info)
		{
			if (Inferno == true)
			{
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" INFERNO", 0.0512f, 0.36f, 235, 62, 14, 255, 0.6500f, 0.8500f, 0, 6); // Name 1 Left
				PrintToScreen(" INFERNO", 0.05f, 0.3612f, 250, 144, 0, 255, 0.6500f, 0.8500f, 0, 6); // Name 2 Left
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 250, 144, 0, 180);// Background left
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenutu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 250, 144, 0, 250);//RockStar Logo
				GRAPHICS::DRAW_SPRITE("shared", "emptydot_32", 0.4995f, 0.50f, 0.03f, 0.03f, 0.0f, 255, 255, 255, 60);//aimdot
				GRAPHICS::DRAW_SPRITE("shared", "emptydot_32", 0.4995f, 0.50f, 0.01f, 0.01f, 0.0f, 250, 144, 0, 200);//aimdot
				PrintToScreen(" Press [ CTRL ] To No Clip", 0.06f, 0.42f, 250, 144, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ Right ] To Grab & Burn [ Left ]", 0.06f, 0.44f, 250, 144, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ V + Right ] For Fire Attack", 0.06f, 0.46f, 250, 144, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ V + Left ] For Heavy Fire Blast", 0.06f, 0.48f, 250, 144, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 252, 184, 250, 255);// Background left color
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 250, 144, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left


			}
		}
		if (Animal_Rider_Info)
		{
			if (Animal_Rider == true)
			{
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" RUDOLF", 0.0512f, 0.36f, 245, 7, 154, 255, 0.6500f, 0.8500f, 0, 6); // Name 1 Left
				PrintToScreen(" RUDOLF", 0.05f, 0.3612f, 237, 175, 214, 255, 0.6500f, 0.8500f, 0, 6); // Name 2 Left

				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 237, 175, 214, 180);// Background left color
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left black
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 237, 175, 214, 250);//RockStar Logo
				PrintToScreen(" Press [ 1 ] To Spawn Rudolf", 0.06f, 0.42f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 2 ] To Fly Rudolf", 0.06f, 0.44f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 3 ] Set Rudolf Hostile Mod", 0.06f, 0.46f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 4 ] To Detach Yourself", 0.06f, 0.48f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 5 ] To Riding Set Animation", 0.06f, 0.50f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ W ] To Move", 0.06f, 0.52f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 237, 175, 214, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 252, 184, 250, 255);// Background left color


			}
		}
		if (Apocalypse_Info)
		{
			if (Apocalypse == true)
			{
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" APOCALYPSE", 0.0512f, 0.36f, 103, 14, 150, 255, 0.6500f, 0.8500f, 0, 6); // Name 1 Left
				PrintToScreen(" APOCALYPSE", 0.05f, 0.3612f, 166, 0, 255, 255, 0.6500f, 0.8500f, 0, 6); // Name 2 Left

				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 166, 0, 255, 180);// Background left color
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left black
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 166, 0, 255, 250);//RockStar Logo
				PrintToScreen(" Press [ 1 ] Set All Ped Crazy", 0.06f, 0.42f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 2 ] Lights Off", 0.06f, 0.44f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 3 ] Set Crazy Weather", 0.06f, 0.46f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 4 ] Set Flame On Everything", 0.06f, 0.48f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 5 ] Everything Fly Away", 0.06f, 0.50f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 6 ] AirStriker Shower", 0.06f, 0.52f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 166, 0, 255, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 31, 22, 36, 255);// Background left color


			}
		}
		if (SuperMan_InfoSk)
		{
			if (SuperManSk == true)
			{
				GRAPHICS::DRAW_SPRITE("frontend", "gtav_logo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" SUPERMAN", 0.0512f, 0.36f, 181, 119, 4, 255, 0.6500f, 0.8500f, 0, 6); // Name 1 Left
				PrintToScreen(" SUPERMAN", 0.05f, 0.3612f, 247, 163, 7, 255, 0.6500f, 0.8500f, 0, 6); // Name 2 Left

				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 166, 0, 255, 180);// Background left color
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left black
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 247, 163, 7, 250);//RockStar Logo
				PrintToScreen(" Press [ 1 ] Set Fly Mode", 0.06f, 0.42f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 2 ] Laser Eyes", 0.06f, 0.44f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 3 ] Super Jump", 0.06f, 0.46f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ 4 ] Crazy Speed", 0.06f, 0.48f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				//PrintToScreen(" Press [ 5 ] Everything Fly Away", 0.06f, 0.50f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				//PrintToScreen(" Press [ 6 ] AirStriker Shower", 0.06f, 0.52f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 247, 163, 7, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 219, 172, 83, 255);// Background left color


			}
		}
		if (badsportplayersoftban)
		{
			Hash model = GAMEPLAY::GET_HASH_KEY("ADDER");
			int Playerped = get_player_ped(selectedPlayer);
			int hashplayer = NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_PED_ID());
			if (STREAMING::IS_MODEL_VALID(model)) {
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), FALSE);
				float forward = 5.f;
				float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
				Vehicle veh = VEHICLE::CREATE_VEHICLE(model, Coords.x, Coords.y, Coords.z, heading, true, true);
				ENTITY::SET_ENTITY_VISIBLE(veh, false, false);
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
				VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
				DECORATOR::DECOR_SET_INT(veh, "Player_Vehicle", hashplayer);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 0, 0);
				auto networkId = NETWORK::VEH_TO_NET(veh);
				ENTITY::_SET_ENTITY_REGISTER(veh, true);
				if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh)) {
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
				}
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(veh, FALSE);
				Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
				WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
					WAIT(0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, 250, 1, airStrike, Playerped, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, 250, 1, airStrike, Playerped, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, 250, 1, airStrike, Playerped, 1, 0, -1.0);
				FIRE::ADD_OWNED_EXPLOSION(Playerped, coords.x, coords.y, coords.z, 73, 250, false, true, false);
				WAIT(150);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}
		}


		if (SuperManSk)
		{
			if (IsKeyPressed(VK_KEY_1))
			{
				if (superman_fly == 0)
				{
					superman_fly = 1;
					NotificationCEO("Fly Mode Is On", "Foxy", "Reborn");
					WAIT(200);
				}
				else
				{
					superman_fly = 0;
					NotificationCEO("Fly Mode Is Off", "Foxy", "Reborn");
					GAMEPLAY::_0x2587A48BC88DFADF(false);
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_2))
			{
				if (superman_eyes == 0)
				{
					superman_eyes = 1;
					NotificationCEO("Attack Mode Is On", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					superman_eyes = 0;
					NotificationCEO("Attack Mode Is Off", "Foxy", "Reborn");
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_3))
			{
				if (superman_jump == 0)
				{
					superman_jump = 1;
					NotificationCEO("Super Jump Is On", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					superman_jump = 0;
					NotificationCEO("Super Jump Is Off", "Foxy", "Reborn");
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_4))
			{
				if (superman_speed == 0)
				{
					superman_speed = 1;
					NotificationCEO("Crazy Speed Is On", "Foxy", "Reborn");
					Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 10.f);
					WAIT(200);

				}
				else
				{
					superman_speed = 0;
					NotificationCEO("Crazy Speed Is Off", "Foxy", "Reborn");
					Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1.0);
					WAIT(200);
				}
			}

			if (superman_fly == 1) {
				PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
				PED::SET_PED_RAGDOLL_ON_COLLISION(playerPedId, !SuperManSk);
				PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPedId, !SuperManSk);
				PED::SET_PED_CAN_RAGDOLL(playerPedId, !SuperManSk);
				if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
				{
					if (GetAsyncKeyState(VK_SHIFT))
					{
						ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 6, 0);
					}
					if (GetAsyncKeyState(0x53))
					{
						ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, -6, 0);
					}
					if (GetAsyncKeyState(VK_SPACE))
					{
						ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 0, 6);
					}
				}
			}
			if (superman_eyes == 1) {
				Local::SV4 = SuperManSk;
			}
			if (superman_jump == 1) {
				if (!ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_ID()) && IsKeyPressed(VK_SPACE)) {
					GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
					ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 200, 0);
				}
			}
			if (superman_speed) { 

				if (IsKeyPressed('W'))
				{
					Ped ped = PLAYER::PLAYER_PED_ID();
					Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
					ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, 1.3, 0, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
					PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), 1);
					PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.59);

				}
			
			
			}
			
		}


		if (Apocalypse)
		{
			if (IsKeyPressed(VK_KEY_1))
			{
				if (apocalyspe_peds == 0)
				{
					apocalyspe_peds = 1;
					NotificationCEO("All Peds Are Now Dangerous", "Foxy", "Reborn");
					WAIT(200);
				}
				else
				{
				apocalyspe_peds = 0;
				NotificationCEO("Peds Should Be Calm Now", "Foxy", "Reborn");
				GAMEPLAY::_0x2587A48BC88DFADF(false);
				WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_2))
			{
				if (apocalyspe_lights == 0)
				{
					apocalyspe_lights = 1;
					NotificationCEO("Lights Ran Out", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					apocalyspe_lights = 0;
					NotificationCEO("Lights Are Back Up", "Foxy", "Reborn");
					GRAPHICS::_SET_BLACKOUT(false);
					GRAPHICS::_SET_BLACKOUT2(false);
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_3))
			{
				if (apocalyspe_weather == 0)
				{
					apocalyspe_weather = 1;
					NotificationCEO("Weather Is Acting", "Foxy", "Reborn");
					GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Halloween");
					Rain_ = 999;
					waves = 999;
					shoreamplitude = 999;
					shoreminamplitude = 999;
					shoremaxamplitude = 999;
					shoremaxnoise = 999;
					rippledisturbedamplitude = 999;
					oceanwaveamplitude = 999;
					oceanwaveminamplitude = 999;
					oceanwavemaxamplitude = 999;
					ripplebumpinesseamplitude = 999;
					ripplebumpinesseminamplitude = 999;
					ripplebumpinessemaxamplitude = 999;
					WAIT(200);

				}
				else
				{
					apocalyspe_weather = 0;
					NotificationCEO("Weather Is Now Calm", "Foxy", "Reborn");
					GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear");
					 Rain_ = 0;
					 waves = 0;
					 shoreamplitude = 0;
					 shoreminamplitude = 0;
					 shoremaxamplitude = 0;
					 shoremaxnoise = 0;
					 rippledisturbedamplitude = 0;
					 oceanwaveamplitude = 0;
					 oceanwaveminamplitude = 0;
					 oceanwavemaxamplitude = 0;
					 ripplebumpinesseamplitude = 0;
					 ripplebumpinesseminamplitude = 0;
					 ripplebumpinessemaxamplitude = 0;
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_4))
			{
				if (apocalyspe_flames == 0)
				{
					apocalyspe_flames = 1;
					NotificationCEO("Hell Demise", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					apocalyspe_flames = 0;
					NotificationCEO("Fire's Are Calming Down", "Foxy", "Reborn");
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_5))
			{
				if (apocalyspe_tornado == 0)
				{
					apocalyspe_tornado = 1;
					NotificationCEO("A Tornado Has Spawned", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					apocalyspe_tornado = 0;
					NotificationCEO("The Tornado Has Disappear", "Foxy", "Reborn");
					WAIT(200);
				}
			}
			if (IsKeyPressed(VK_KEY_6)) {
				if (apocalyspe_missile == 0)
				{
					apocalyspe_missile = 1;
					NotificationCEO("Missile Are Raining Down", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					apocalyspe_missile = 0;
					NotificationCEO("Missile Stoped", "Foxy", "Reborn");
					WAIT(200);
				}
			}
			if (apocalyspe_peds == 1) {
				GAMEPLAY::_0x2587A48BC88DFADF(true);
			}
			if (apocalyspe_lights == 1) {
				GRAPHICS::_SET_BLACKOUT(true);
				GRAPHICS::_SET_BLACKOUT2(true);
			}
			if (apocalyspe_flames == 1) {
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				FIRE::START_SCRIPT_FIRE(pos.x + 5 , pos.y, pos.z, 80, false);
				FIRE::START_SCRIPT_FIRE(pos.x, pos.y + 5, pos.z, 80, false);
				FIRE::START_SCRIPT_FIRE(pos.x, pos.y + 10, pos.z + 10, 80, false);
				FIRE::START_SCRIPT_FIRE(pos.x + 20, pos.y + 20, pos.z, 80, false);

			}
			if (apocalyspe_tornado) { vehicle_tornado(); ped_tornado(); }
			if (apocalyspe_missile == 1) {
				Vector3 Playerpos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				if ((timeGetTime() - Misc::TimePD2) > 400)
				{
					float ang = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 10.0f) * 3.14159265359f;
					float rad = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 10.0f) * 15.0f;
					float x = Playerpos.x + rad * cos(ang);
					float y = Playerpos.y + rad * sin(ang);
					Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
					WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
					while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
						WAIT(0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(x, y, 200.0f, x, y, 0, 250, 1, airStrike, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
					Misc::TimePD2 = timeGetTime();
				}
			}
		}


		if (Angel_OF_DEATH_Info)
		{
			if (Angel_OF_DEATH == true)
			{
				YTD13();
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.415f, 0.204f, 0.104f, 0.0f, 0, 0, 0, 100);// Background left
				PrintToScreen(" ANGEL OF DEATH", 0.05f, 0.36f, 255, 89, 89, 255, 0.6500f, 0.8500f, 0, 6); // Info Left
				PrintToScreen(" ANGEL OF DEATH", 0.0512f, 0.3612f, 135, 0, 0, 255, 0.6500f, 0.8500f, 0, 6); // Info Left

				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.204f, 0.154f, 0.0f, 135, 0, 0, 180);// Background left color
				GRAPHICS::DRAW_SPRITE("GTAOlogo", "GTAOTransitionLogo", 0.14f, 0.49f, 0.20f, 0.15f, 0.0f, 25, 25, 25, 255);// Background left black
				GRAPHICS::DRAW_SPRITE("shared", "bggradient_32x1024", 0.14f, 0.46f, 0.20f, 0.09f, 0.0f, 25, 25, 25, 140);//BG Shader
				GRAPHICS::DRAW_SPRITE("commonmenu", "rockstar", 0.225f, 0.55f, 0.025f, 0.025f, 0.0f, 135, 0, 0, 250);//RockStar Logo
				GRAPHICS::DRAW_SPRITE("commonmenu", "Shop_Ammo_Icon_A", 0.4995f, 0.50f, 0.03f, 0.03f, 0.0f, 255, 255, 255, 200);//aimdot
				PrintToScreen(" Press [ + ] To Demon Model", 0.06f, 0.42f, 135, 0, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ B ] To Breath Fire", 0.06f, 0.44f, 135, 0, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ CONTROL ] To No Clip", 0.06f, 0.46f, 135, 0, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ N ] To Burn All Peds Around", 0.06f, 0.48f, 135, 0, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Press [ SHIFT ] For Fire Trail Run", 0.06f, 0.50f, 135, 0, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				PrintToScreen(" Foxy Free Menu", 0.06f, 0.54f, 135, 0, 0, 255, 0.4000f, 0.4000f, 0, 6); // Info Left
				GRAPHICS::DRAW_SPRITE("Foxy", "SuperPowerLogo", 0.14f, 0.49f, 0.14f, 0.12f, 0.0f, 252, 184, 250, 255);// Background left color
			}
		}


		if (Animal_Rider)
		{
		starter:;
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Hash lion_hash = GAMEPLAY::GET_HASH_KEY("A_C_Deer_02");
			Vector3 Me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Ped mtlion = ENTITY::GET_ENTITY_ATTACHED_TO(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
			Vector3 rota = CAM::GET_GAMEPLAY_CAM_ROT(0.1);
			Vector3 dira = GET_CAMERA_DIRECTION(0.1);
			ENTITY::SET_ENTITY_COLLISION(mtlion, true, true);
			
			auto pos = ENTITY::GET_ENTITY_COORDS(mtlion, false);
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			if (rudolf_noclip == 1)
			{
				ENTITY::SET_ENTITY_COORDS(mtlion, pos.x, pos.y, pos.z, 5, 100, heading, 0.0f); 
				ENTITY::SET_ENTITY_ROTATION(mtlion, rota.x, rota.y, rota.z, 0.1, 0.1);
			}
			
			if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
			{
				if (rudolf_noclip == 0) {
					Vector3 pos = add(&ENTITY::GET_ENTITY_COORDS(mtlion, false), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 10.f));
					AI::TASK_GO_STRAIGHT_TO_COORD(mtlion, pos.x, pos.y, pos.z, 5, 100, heading, 0.0f); ENTITY::SET_ENTITY_ROTATION(mtlion, rota.x, rota.y, rota.z, 0.1, 0.1);
				}
				else if (rudolf_noclip == 1) {
					Vector3 pos = add(&ENTITY::GET_ENTITY_COORDS(mtlion, false), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 10.f));
					ENTITY::SET_ENTITY_COORDS(mtlion, pos.x, pos.y, pos.z, 5, 100, heading, 0.0f); ENTITY::SET_ENTITY_ROTATION(mtlion, rota.x, rota.y, rota.z, 0.1, 0.1);
				}
			}

			if (IsKeyPressed(VK_KEY_1))
			{
				STREAMING::REQUEST_MODEL(lion_hash);
				if (STREAMING::HAS_MODEL_LOADED(lion_hash));
				{
					int Handle = PED::CREATE_PED(1, lion_hash, Me.x, Me.y, Me.z, 0, 1, 1);
					if (ENTITY::DOES_ENTITY_EXIST(Handle))
					{
						char* anim2 = "mp_safehouselost_table@";
						char* animID2 = "lost_table_negative_a";
						ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, Handle, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);
						ENTITY::SET_ENTITY_INVINCIBLE(Handle, true);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(lion_hash);
						WAIT(200);
						AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 1, 1, 16, 0, 0, false, 0, false);

					}
				}
			}
			if (IsKeyPressed(VK_KEY_2))
			{
				if (rudolf_noclip == 0)
				{
					rudolf_noclip = 1;
					NotificationCEO("Flying Mod", "Foxy", "Reborn");
					WAIT(200);
					
				}
				else
				{
					rudolf_noclip = 0;
					NotificationCEO("Walking Mod", "Foxy", "Reborn");
					WAIT(200);
				}
			}

			if (IsKeyPressed(VK_KEY_3))
			{
				if (rudolf_hostile == 0)
				{
					rudolf_hostile = 1;
					NotificationCEO("Hostile Mod", "Foxy", "Reborn");
					WAIT(200);

				}
				else
				{
					rudolf_hostile = 0;
					NotificationCEO("Friendly Mod", "Foxy", "Reborn");
					WAIT(200);
				}
			}

			if (IsKeyPressed(VK_KEY_4))
			{
				ENTITY::DETACH_ENTITY(playerPed, 1, 1);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
				goto starter;
			}
			if (IsKeyPressed(VK_KEY_5))
			{
				char* anim2 = "mp_safehouselost_table@";
				char* animID2 = "lost_table_negative_a";
				AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 1, 1, 16, 0, 0, false, 0, false);
				goto starter;
			}
			if (rudolf_hostile == 1) {
				Local::super_vision_rudolf();
			}
		}

		if (FireField)
		{
			Vector3 coords = PED::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 52301, 0.0f, 0.0f, 0.0f);
			Vector3 Mouth = PED::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 14201, 0.0f, 0.0f, 0.0f);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 12, 1, 1, 0, 0);
			FIRE::ADD_EXPLOSION(Mouth.x, Mouth.y, Mouth.z, 12, 1, 1, 0, 0);
		}
		if (garage_save_bypass) {

			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_CAN_SAVE_IN_GARAGE(veh, true);
		}

		if (DragonMode)
		{

			Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 dir = rot_to_direction(&rot);
			Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			float spawnDistance = get_distance(&camPosition, &playerPosition);
			float spawnDistance1 = get_distance(&camPosition, &playerPosition);
			float spawnDistance2 = get_distance(&camPosition, &playerPosition);
			float spawnDistance3 = get_distance(&camPosition, &playerPosition);
			float spawnDistance4 = get_distance(&camPosition, &playerPosition);
			float spawnDistance5 = get_distance(&camPosition, &playerPosition);
			float spawnDistance6 = get_distance(&camPosition, &playerPosition);
			spawnDistance += 3;
			spawnDistance1 += 6;
			spawnDistance2 += 9;
			spawnDistance3 += 12;
			spawnDistance4 += 15;
			spawnDistance5 += 18;
			spawnDistance6 += 21;
			Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));
			Vector3 spawnPosition1 = add(&camPosition, &multiply(&dir, spawnDistance1));
			Vector3 spawnPosition2 = add(&camPosition, &multiply(&dir, spawnDistance2));
			Vector3 spawnPosition3 = add(&camPosition, &multiply(&dir, spawnDistance3));
			Vector3 spawnPosition4 = add(&camPosition, &multiply(&dir, spawnDistance4));
			Vector3 spawnPosition5 = add(&camPosition, &multiply(&dir, spawnDistance5));
			Vector3 spawnPosition6 = add(&camPosition, &multiply(&dir, spawnDistance5));
			FIRE::ADD_EXPLOSION(spawnPosition.x - 0.5, spawnPosition.y, spawnPosition.z, 11, 1, 0, 1, 0); //fire
			FIRE::ADD_EXPLOSION(spawnPosition1.x - 0.5, spawnPosition1.y, spawnPosition1.z, 11, 1, 0, 1, 0); //fire

			FIRE::ADD_EXPLOSION(spawnPosition2.x - 0.5, spawnPosition2.y, spawnPosition2.z, 11, 1, 0, 1, 0); //fire
			FIRE::ADD_EXPLOSION(spawnPosition3.x - 0.5, spawnPosition3.y, spawnPosition3.z, 11, 1, 0, 1, 0); //fire

			FIRE::ADD_EXPLOSION(spawnPosition4.x - 0.5, spawnPosition4.y, spawnPosition4.z, 11, 1, 0, 1, 0); //fire
			FIRE::ADD_EXPLOSION(spawnPosition5.x - 0.5, spawnPosition5.y, spawnPosition5.z, 11, 1, 0, 1, 0); //fire

			FIRE::ADD_EXPLOSION(spawnPosition6.x - 0.5, spawnPosition5.y, spawnPosition5.z, 58, 10000, 1, 1, 0); //final explosion
			FIRE::ADD_EXPLOSION(spawnPosition6.x - 0.5, spawnPosition5.y, spawnPosition5.z, 19, 10000, 1, 1, 0); //final explosion
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX  fire ball 4.f
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_ie_jug_mask_flame", spawnPosition6.x - 0.5, spawnPosition6.y, spawnPosition6.z + 1.f, 0, 0, 0, 4.f, 0, 0.5f, 0);

			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX  fire ball 4.f
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_ie_jug_mask_flame", spawnPosition6.x - 0.5, spawnPosition6.y, spawnPosition6.z + 1.f, 0, 0, 0, 4.f, 0, 0.5f, 0);

			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX  fire ball 4.f
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_ie_jug_mask_flame", spawnPosition6.x - 0.5, spawnPosition6.y, spawnPosition6.z + 1.f, 0, 0, 0, 4.f, 0, 0.5f, 0);

			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX  fire ball 4.f
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_ie_jug_mask_flame", spawnPosition6.x - 0.5, spawnPosition6.y, spawnPosition6.z + 1.f, 0, 0, 0, 4.f, 0, 0.5f, 0);


		}

		if (DragonMode1)
		{


			Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 dir = rot_to_direction(&rot);
			Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			float spawnDistance = get_distance(&camPosition, &playerPosition);
			float spawnDistance1 = get_distance(&camPosition, &playerPosition);
			float spawnDistance2 = get_distance(&camPosition, &playerPosition);
			float spawnDistance3 = get_distance(&camPosition, &playerPosition);
			float spawnDistance4 = get_distance(&camPosition, &playerPosition);
			float spawnDistance5 = get_distance(&camPosition, &playerPosition);
			spawnDistance += 3;
			spawnDistance1 += 6;
			spawnDistance2 += 9;
			spawnDistance3 += 12;
			spawnDistance4 += 15;
			spawnDistance5 += 18;
			Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));
			Vector3 spawnPosition1 = add(&camPosition, &multiply(&dir, spawnDistance1));
			Vector3 spawnPosition2 = add(&camPosition, &multiply(&dir, spawnDistance2));
			Vector3 spawnPosition3 = add(&camPosition, &multiply(&dir, spawnDistance3));
			Vector3 spawnPosition4 = add(&camPosition, &multiply(&dir, spawnDistance4));
			Vector3 spawnPosition5 = add(&camPosition, &multiply(&dir, spawnDistance5));
			FIRE::ADD_EXPLOSION(spawnPosition.x - 0.5, spawnPosition.y, spawnPosition.z, 12, 1, 1, 0, 0); //fire
			FIRE::ADD_EXPLOSION(spawnPosition1.x - 0.5, spawnPosition1.y, spawnPosition1.z, 12, 1, 1, 0, 0); //fire

			FIRE::ADD_EXPLOSION(spawnPosition2.x - 0.5, spawnPosition2.y, spawnPosition2.z, 12, 1, 1, 0, 0); //fire
			FIRE::ADD_EXPLOSION(spawnPosition3.x - 0.5, spawnPosition3.y, spawnPosition3.z, 12, 1, 1, 0, 0); //fire

			FIRE::ADD_EXPLOSION(spawnPosition4.x - 0.5, spawnPosition4.y, spawnPosition4.z, 12, 1, 1, 0, 0); //fire
			FIRE::ADD_EXPLOSION(spawnPosition5.x - 0.5, spawnPosition5.y, spawnPosition5.z, 12, 1, 1, 0, 0); //fire

			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX  fire ball 4.f
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_ie_jug_mask_flame", spawnPosition5.x - 0.5, spawnPosition5.y, spawnPosition5.z + 1.f, 0, 0, 0, 4.f, 0, 0.5f, 0);


		}
		if (ElectricEyes)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 1.5f, 0, 0, 0);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 14201, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);

		}
		if (Angel_OF_DEATH)
		{
			//

			GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
			GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());

			STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), AODMoveX1, AODMoveY1, AODMoveZ1, AODpitch1, AODroll1, AODyaw1, SKEL_R_Clavicle, 1, 1, 1, 1);


			STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), AODMoveX2, AODMoveY2, AODMoveZ2, AODpitch2, AODroll2, AODyaw2, SKEL_L_Clavicle, 1, 1, 1, 1);

			STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), AODMoveX3, AODMoveY3, AODMoveZ3, AODpitch3, AODroll3, AODyaw3, SKEL_Spine_Root, 1, 1, 1, 1);

			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, SKEL_L_Foot, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, SKEL_R_Foot, 1.f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);

			if (IsKeyPressed(VK_KEY_N))
			{
				const int ElementAmount = 10;
				const int ArrSize = ElementAmount * 2 + 2;

				Ped* peds = new Ped[ArrSize];
				peds[0] = ElementAmount;

				int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

				for (int i = 0; i < PedFound; i++)
				{
					int OffsetID = i * 2 + 2;
					RequestControlOfEnt(peds[OffsetID]);
					if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
					{
						FIRE::START_ENTITY_FIRE(peds[OffsetID]);
					}
				}
			}
			

			if (IsKeyPressed(VK_CONTROL)) {
				NoClip7();
				/// "rcmextreme3", "jump_fall",
				char* dict = "rcmextreme3";
				char* anim = "jump_fall";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, 16, 0, 0, false, 0, false);
			}


			if (IsKeyPressed(VK_SHIFT)) {
				if (IsKeyPressed('W'))
				{
					Ped ped = PLAYER::PLAYER_PED_ID();
					Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
					ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, 1.3, 0, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
					PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), 1);
					PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 44.6f);

				}
			}


			if (IsKeyPressed(VK_KEY_ADD))
			{
				int ModelHash = GAMEPLAY::GET_HASH_KEY("A_M_Y_MusclBeac_01");
				if (STREAMING::IS_MODEL_IN_CDIMAGE(ModelHash))
				{
					if (STREAMING::IS_MODEL_VALID(ModelHash))
					{
						STREAMING::REQUEST_MODEL(ModelHash);
						if (STREAMING::HAS_MODEL_LOADED(ModelHash))
						{
							PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), ModelHash);
							PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 0, 2, 0, 0);//Face
							PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, 0, 99, 0);//Black Shirt
							PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 0, 99, 0);//Black pants
							PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 0, 1, 0, 0);
						}
					}
				}
			}

			if (IsKeyPressed(VK_KEY_B))
			{


				STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), AODMoveX1, AODMoveY1, AODMoveZ1, AODpitch1, AODroll1, AODyaw1, SKEL_R_Clavicle, 1, 1, 1, 1);


				STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), AODMoveX2, AODMoveY2, AODMoveZ2, AODpitch2, AODroll2, AODyaw2, SKEL_L_Clavicle, 1, 1, 1, 1);

				STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), AODMoveX3, AODMoveY3, AODMoveZ3, AODpitch3, AODroll3, AODyaw3, SKEL_Spine_Root, 1, 1, 1, 1);


				STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), 0.02f, 0.2, 0.0, 90.0, -100.0, 90.f, SKEL_Head, 1, 1, 1, 1);

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, SKEL_L_Foot, 1.f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_ie_jug_mask_flame", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, SKEL_R_Foot, 1.f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			}
		}
		if (Inferno){

			GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
			GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
			WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), true);

			ElectricEyes = true;



			if (IsKeyPressed(VK_SPACE)) // jump

			{
				ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 1.5, 0, 0, 0, 0, true, true, true, true, false, true);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_prologue_door_blast", PLAYER::PLAYER_PED_ID(), 0.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.2f, 0, 0, 0);

			}

			if (IsKeyPressed(VK_KEY_V))
			{
				if (IsKeyPressed(VK_LBUTTON)) // heavy attack
				{
					ElectricEyes = false;
					WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), 0);
					DragonMode = true;
					PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
					PED::RESET_PED_VISIBLE_DAMAGE(PLAYER::PLAYER_PED_ID());
					STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");// FX Attachment
					GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
					GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_prologue_door_blast", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 2.5f, 0, 0, 0);// Left Eye
					char* dict = "rcmbarry";
					char* anim = "bar_1_attack_alien_wins_aln";
					STREAMING::REQUEST_ANIM_DICT(dict);
					AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, 16, 0, 0, false, 0, false);


				}
				else
				{
					ElectricEyes = true;
					DragonMode = false;
				}

				if (IsKeyPressed(VK_RBUTTON))
				{
					ElectricEyes = false;
					DragonMode1 = true;
					Player tempPed = PLAYER::PLAYER_ID();
					AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Missile_Incoming_Hit", tempPed, "DOCKS_HEIST_FINALE_2B_SOUNDS", 0, 0);
					char* dict = "rcmbarry";
					char* anim = "bar_1_attack_alien_wins_aln";
					STREAMING::REQUEST_ANIM_DICT(dict);// Anim
					AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, 16, 0, 0, false, false, false);// Anim
				}
				else
				{
					DragonMode1 = false;
					ElectricEyes = true;
				}
			}



			if (SuperMan)
			{


				int Handle = PLAYER::PLAYER_PED_ID();
				if (IsKeyPressed(VK_CONTROL)) {
					NoClippp();
					FlyFloat = true;
					FireField = true;

				}
				else
				{
					FlyFloat = false;
					FireField = false;
				}



				if (IsKeyPressed(VK_KEY_G))
				{
					ForceField = true;
					FlyFloat = false;
					Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 1, 1.35, 0, 0, 0, true, true, true, true, false, true);
					AUDIO::SET_VEHICLE_BOOST_ACTIVE(PLAYER::PLAYER_PED_ID(), 1);

				}
				else
				{
					ForceField = false;
					FlyFloat = false;
					AUDIO::SET_VEHICLE_BOOST_ACTIVE(PLAYER::PLAYER_PED_ID(), false);
				}
			}

			if (IsKeyPressed(VK_CONTROL))
			{
				SuperMan = true;
				char* dict = "ladderswatermounts";// Anim
				char* anim = "swimmounttoladderleft";// Anim
				STREAMING::REQUEST_ANIM_DICT(dict);// Anim
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, 16, 0, 0, 0, 0, 0);// Anim
				Player tempPed = PLAYER::PLAYER_ID();
				AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Missile_Incoming_Miss", tempPed, "DOCKS_HEIST_FINALE_2B_SOUNDS", 0, 0);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_prologue_door_blast", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 1.0f, 0, 0, 0);// Left Eye


				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_prologue_door_blast", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.4f, 0, 0, 0);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_prologue_door_blast", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.4f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			}
			else
			{
				SuperMan = false;
			}



			if (IsKeyPressed(VK_SHIFT))
			{
				auto Yourself = PLAYER::PLAYER_PED_ID();
				WEAPON::SET_CURRENT_PED_WEAPON(Yourself, $("WEAPON_UNARMED"), 1);

				Entity EntityTarget;
				DWORD equippedWeapon;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();

				Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 dir = cRotationToDirection2(rot);
				Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				float spawnDistance = get_distance(&camPosition, &playerPosition);
				spawnDistance += 6;
				Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));

				Player tempPed = PLAYER::PLAYER_ID();

				if (grav_target_locked)
				{
					if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
					{


						STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");
						GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
						GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_prologue_door_blast", EntityTarget, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.5, false, false, false);
						GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
						char* dict = "rcmbarry";
						char* anim = "bar_1_attack_alien_wins_aln";
						STREAMING::REQUEST_ANIM_DICT(dict);
						AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, 16, 0, 0, false, 0, false);// Anim
						Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
						PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
						if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
						{
							EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
						}

						RequestControlOfEnt(EntityTarget);

						if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
							ENTITY::SET_ENTITY_HEADING(
								EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);
						FIRE::START_ENTITY_FIRE(EntityTarget);
						PED::APPLY_DAMAGE_TO_PED(EntityTarget, 19, true);


						if (GetAsyncKeyState(VK_LBUTTON))
						{
							// inferno powers
							char* dict = "melee@unarmed@streamed_core_fps";
							char* anim = "long_-90_punch";
							STREAMING::REQUEST_ANIM_DICT(dict);
							AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, 16, 0, 0, false, 0, false);// Anim
							AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
							STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_prologue");
							GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_prologue");
							GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_prologue_door_blast", EntityTarget, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1, false, false, false);
							ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
							ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
								0.0f, 0, 0, 1, 1, 0, 1);
							grav_target_locked = false;
							PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
						}
					}
				}
				if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
				{
					grav_target_locked = true;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
			else
			{
				ElectricEyes = true;
			}

		}
		else
		{
			ElectricEyes = false;
		}


		if (ElectricBody2)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_family4");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_family4");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_fam4_trailer_sparks", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.1f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_family4");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_family4");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_fam4_trailer_sparks", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.1f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_family4");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_family4");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_fam4_trailer_sparks", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 0.2f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_family4");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_family4");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_fam4_trailer_sparks", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 0.1f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_family4");// FX Attachment
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_family4");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_fam4_trailer_sparks", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 14201, 0.1f, 0, 0, 0);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);

		}

		if (Electro)
		{
			GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
			WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), true);
			//VK_SPACE
			if (IsKeyPressed(VK_SPACE)) // jump

			{
				ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 0.15, 0, 0, 0, 0, true, true, true, true, false, true);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), 0.02f, 0, 0, 0, 0, 0, 31086, 1.0f, 0, 0, 0);// Left Eye
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), -0.02f, 0, 0, 0, 0, 0, 31086, 1.0f, 0, 0, 0);// right eye
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);


				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), 0.02f, 0, 0, 0, 0, 0, 45509, 1.0f, 0, 0, 0);// Left Eye
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), -0.02f, 0, 0, 0, 0, 0, 40269, 1.0f, 0, 0, 0);// right eye
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 45509, 0.3f, 0, 0, 0);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 40269, 0.3f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 45509, 0.02f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 40269, 0.02f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.2f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 3.0, false, false, false);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 3.0, false, false, false);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
			}
			

			if (IsKeyPressed(VK_KEY_B))
			{

				WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), 0);
				char* dict = "amb@world_human_muscle_flex@arms_at_side@base";
				char* anim = "base";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
				GRAPHICS::SET_TIMECYCLE_MODIFIER("RaceTurbo");
				PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
				PED::RESET_PED_VISIBLE_DAMAGE(PLAYER::PLAYER_PED_ID());
				QuickHeal();
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), 0.01f, 0, 0, 0, 0, 0, 45509, 1.0f, 0, 0, 0);// Left Eye
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), -0.01f, 0, 0, 0, 0, 0, 40269, 1.0f, 0, 0, 0);// right eye
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				QuickHeal();
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.3f, 0, 0, 0);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.3f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				QuickHeal();
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.03f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.03f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				QuickHeal();
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.2f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 3.0, false, false, false);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 3.0, false, false, false);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
			}
			else
			{
                GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
			}


			if (IsKeyPressed(VK_KEY_V))
			{

				AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
				NoClipElectro();
				ElectroForw = true;
				Electric();
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), 0.02f, 0, 0, 0, 0, 0, 0, 1.0f, 0, 0, 0);// Left Eye

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.3f, 0, 0, 0);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.3f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);


			}
			else
			{

				ElectroForw = false;
				ENTITY::SET_ENTITY_COLLISION(PLAYER::PLAYER_PED_ID(), 1, 1);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
			}

			Entity EntityTarget;
			DWORD equippedWeapon;
			WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

			Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 dir = cRotationToDirection2(rot);
			Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			float spawnDistance = get_distance(&camPosition, &playerPosition);
			spawnDistance += 6;
			Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


			Player tempPed = PLAYER::PLAYER_ID();
			if (grav_target_locked)
			{
				const int numElements = 10;
				const int arrSize = numElements * 2 + 2;  //Start at index 2, and the odd elements are padding
				int vehs[arrSize];
				vehs[0] = numElements;
				int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
				if (!CUTSCENE::IS_CUTSCENE_ACTIVE() && !CUTSCENE::IS_CUTSCENE_PLAYING() && !STREAMING::IS_NETWORK_LOADING_SCENE() && !NETWORK::NETWORK_IS_IN_MP_CUTSCENE() && !INTERIOR::IS_INTERIOR_SCENE())
				{
					for (int i = 0; i < count; ++i)
					{
						int offsettedID = i * 2 + 2;
						if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
						{
							if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
							{
								if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
								{
									if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &vehs[offsettedID]) && GetAsyncKeyState(VK_RBUTTON))
									{

										Vector3 vehsPos = ENTITY::GET_ENTITY_COORDS(vehs[offsettedID], 0);
										PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
										if (ENTITY::IS_ENTITY_A_PED(vehs[offsettedID]) && PED::IS_PED_IN_ANY_VEHICLE(vehs[offsettedID], 1))
										{
											vehs[offsettedID] = PED::GET_VEHICLE_PED_IS_IN(vehs[offsettedID], 0);
										}

										RequestControlOfEnt(vehs[offsettedID]);

										if (ENTITY::IS_ENTITY_A_VEHICLE(vehs[offsettedID]))
											ENTITY::SET_ENTITY_HEADING(
												vehs[offsettedID], ENTITY::GET_ENTITY_HEADING(tempPed));

										ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehs[offsettedID], spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);
										STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
										GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
										GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", vehs[offsettedID], 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.5, false, false, false);
										GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
										char* dict = "rcmcollect_paperleadinout@";
										char* anim = "meditiate_idle";
										STREAMING::REQUEST_ANIM_DICT(dict);
										AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);

										if (GetAsyncKeyState(VK_LBUTTON))
										{
											AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", vehs[offsettedID], "docks_heist_finale_2a_sounds", 0, 0);
											ENTITY::SET_ENTITY_HEADING(vehs[offsettedID], ENTITY::GET_ENTITY_HEADING(tempPed));
											ENTITY::APPLY_FORCE_TO_ENTITY(vehs[offsettedID], 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
												0.0f, 0, 0, 1, 1, 0, 1);
											grav_target_locked = false;
											PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
											STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
											GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
											GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", vehs[offsettedID], 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0f, false, false, false);
										}
									}
								}
								if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &vehs[offsettedID]))
								{
									grav_target_locked = true;
									PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
								}
							}
						}
					}
				}
			}
			
			if (IsKeyPressed(VK_KEY_G))
			{

				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), 0.02f, 0, 0, 0, 0, 0, 31086, 1.0f, 0, 0, 0);// Left Eye
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_mp_house");// FX Attachment
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_mp_house");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_sh_lighter_sparks", PLAYER::PLAYER_PED_ID(), -0.02f, 0, 0, 0, 0, 0, 31086, 1.0f, 0, 0, 0);// right eye
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.2f, 0, 0, 0);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);

				Smash();
			}


			if (IsKeyPressed(VK_KEY_V))
			{
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2, false, false, false);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
			}

			if (IsKeyPressed(VK_KEY_N))
			{
				TracePedsElectro();
				Electrocute();
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2, false, false, false);
				GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
			}
			if (IsKeyPressed(VK_KEY_M))
			{

				void EMP0();
				{
					const int numElements = 10;
					const int arrSize = numElements * 3 + 3;
					Vehicle veh[arrSize];
					veh[0] = numElements;
					int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
					if (veh != NULL)
					{
						for (int i = 1; i <= count; i++)
						{
							int offsettedID = i;
							if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
							{
								Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);
								VEHICLE::SET_VEHICLE_ENGINE_ON(veh[offsettedID], false, false, false);
								VEHICLE::SET_VEHICLE_GRAVITY(veh[offsettedID], false);
								ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], true, 0, 0, 1.0, 0, 0, 0, true, true, true, true, false, true);
								STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
								GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
								GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_trev1_trailer_boosh", Pos.x, Pos.y, Pos.z - 0.5, 0.0, 0.0, 0.0, 1.5, false, false, false);
								GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
								STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
								GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
								GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_trev1_trailer_boosh", Pos.x, Pos.y, Pos.z - 0.5, 0.0, 0.0, 0.0, 1.5, false, false, false);
								GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);
								STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
								GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
								GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_trev1_trailer_boosh", Pos.x, Pos.y, Pos.z - 0.5, 0.0, 0.0, 0.0, 1.5, false, false, false);
								GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(10, 250, 255);

								char* dict = "rcmcollect_paperleadinout@";
								char* anim = "meditiate_idle";
								STREAMING::REQUEST_ANIM_DICT(dict);
								STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
								GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
								GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.4f, 0, 0, 0);//Right Hand
								GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
								STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");// FX Attachment
								GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
								GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.4f, 0, 0, 0);//Left Hand
								GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR(72, 236, 232);
							}
						}
					}
				}
			}
			GAMEPLAY::SET_OVERRIDE_WEATHER("THUNDER");
		}


		else
		{
			ElectricBody2 = false;
			//GAMEPLAY::SET_OVERRIDE_WEATHER("CLEAR");
		}


		if (Bottriggerr)
		{
			PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), PED::GET_PED_BONE_COORDS(gravent, 0x796e, 0.0f, 0.0f, 0.0f).x, PED::GET_PED_BONE_COORDS(gravent, 0x796e, 0.0f, 0.0f, 0.0f).y, PED::GET_PED_BONE_COORDS(gravent, 0x796e, 0.0f, 0.0f, 0.0f).z, TRUE);
		}
		else
		{

		}

		if (notify)
		{
			
		}
		else
		{

		}

		if (threedwaypoint)
		{
			RGBFadee();
			Player playerPed = PLAYER::PLAYER_PED_ID();
			Vector3 pos = get_blip_marker();
			if (waypoint)
				GRAPHICS::DRAW_MARKER(1, pos.x, pos.y,
					pos.z - 1, 0, 0, 0, 0, 0, 0, scaleX, scaleY, scaleZ, rw, gw, bw, 200, 0, 0, 2, 0, 0, 0, 0);
		}

		if (Invisibleee)
		{
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 0, false);
		}
		else
		{
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 1, true);
		}

		if (nocollision)
		{
			int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 20);
			Rot.z = Rot.z + 120.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, 0, 0, Rot.z, 20, 10);
		}

		if (nocollision2)
		{
			int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z + 2.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, 0, 0, Rot.z, 2, 1);
		}

		if (reccontrolblocc)
		{
			Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, false); // REQUEST_CONTROL_EVENT
		}

		if (Explodegunn)
		{
			if (IsPedShooting(PLAYER::PLAYER_PED_ID())) {
				Vector3 coords;
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &coords);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, Explosionfick, ficksize, true, false, 0.f);
			}
		}

		if (Matrix)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				std::string textInput = plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35];
				char* plateText = (strcpy((char*)malloc(textInput.length() + 1), textInput.c_str()));
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), plateText);
			}
		}
		else
		{

		}

		if (entityproof) { ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), ProofBullet, ProofFire, ProofExplosion, ProofCollision, proofMelee, ProofSteam, ProofInterior, ProofWater); }
		if (snowfoottrack) { GRAPHICS::_SET_FORCE_PED_FOOTSTEPS_TRACKS(true); } else { GRAPHICS::_SET_FORCE_PED_FOOTSTEPS_TRACKS(false); }

		if (snowtiretrack) { GRAPHICS::_SET_FORCE_VEHICLE_TRAILS(true); } else { GRAPHICS::_SET_FORCE_VEHICLE_TRAILS(false); }


		if (nevermental)
		{
			STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_MENTAL_STATE"), 0.1, 1);
		}

		if (Modegod)
		{
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		}
		else
		{
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		}

		if (sm)
		{
			GAMEPLAY::SET_TIME_SCALE(0.2);
		}
		else
		{
			GAMEPLAY::SET_TIME_SCALE(1);
		}

		if (nw)
		{
			Menu::Settings::wantedlevel.r = 0;
			Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, 0);
		}
		else
		{
			/*Player player = PLAYER::PLAYER_ID();
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
			PLAYER::SET_PLAYER_WANTED_LEVEL(player, 0, false);
			PLAYER::SET_MAX_WANTED_LEVEL(5);*/ //DWORD ListModel = $(Name);
		}

		if (RpDDROP)
		{
			if ((timeGetTime() - SPlayer::TimePD2) > timeint)
			{
				Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				DWORD ListModel = $(Name);
				STREAMING::REQUEST_MODEL(ListModel);
				if (!STREAMING::HAS_MODEL_LOADED(ListModel)) {
					WAIT(0);
				}
				else {
					Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x1E9A99F8, playerPosition.x, playerPosition.y, playerPosition.z + 5, 0, 2500, ListModel, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ListModel);
				}
			}
		}

		if (Fps)
		{
			float LastFrameTime = GAMEPLAY::GET_FRAME_TIME();
			int getFPS = (1.0f / LastFrameTime);
			char FPStext[60];
			snprintf(FPStext, sizeof(FPStext), "FPS: %d", getFPS);
			Menu::fps(FPStext);
		}




		if (HealthDrop)
		{
			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY(Models), playerPosition.x, playerPosition.y, playerPosition.z, 0, 1, 1, false, true);
			//OBJECT::CREATE_AMBIENT_PICKUP(pickups, playerPosition.x, playerPosition.y, playerPosition.z + 5, 0, 2500, modelhash, FALSE, TRUE);
		}

		if (ArmorDrop)
		{
			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("pickup_armour_standard"), playerPosition.x, playerPosition.y, playerPosition.z, 0, 1, 1, false, true);
		}


		if (VHealthDrop)
		{
			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("pickup_vehicle_health_standard"), playerPosition.x, playerPosition.y, playerPosition.z, 0, 1, 1, false, true);
		}

		if (VArmorDrop)
		{
			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("pickup_vehicle_armour_standard"), playerPosition.x, playerPosition.y, playerPosition.z, 0, 1, 1, false, true);
		}

		if (Remgunobjtree)
		{
			DWORD treehash = GAMEPLAY::GET_HASH_KEY(objtree); // = DWORD treehash = $(objtree);
			if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer))) {
				{
					Vector3 PlayerPos;
					WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
					STREAMING::REQUEST_MODEL(treehash);
					while (!STREAMING::HAS_MODEL_LOADED(treehash)) WAIT(0);

					Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(treehash, PlayerPos.x, PlayerPos.y, PlayerPos.z, 1, 0, TRUE);
					ENTITY::FREEZE_ENTITY_POSITION(object, true);

				}
			}
		}



		if (PoolCrash1) {
			Vector3 Coords;
			Coords.x = -100.747620f; Coords.y = -100.950623f; Coords.z = 1005.971106f;                
			TPto(Coords);
			WAIT(50);
			poolped1();
			//WAIT(50);
			poolped2();
			//WAIT(50);
			poolped3();
			//WAIT(50);
		}

		if (BypassSpeedLimit)
		{
			int s = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

			ENTITY::SET_ENTITY_MAX_SPEED(s, 1000000000);
		}
		else
		{

		}




		if (frr)
		{
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.5);
			
		}

		if (Antihostk)
		{
			Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, false); // REQUEST_CONTROL_EVENT
		}

		if (reccontrolblocc)
		{
			Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, false); // REQUEST_CONTROL_EVENT
		}

		if (BlockallEvent)
		{
			Foxy_Engine::defuseEvent(SCRIPT_ARRAY_DATA_VERIFY_EVENT, true);
			Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, true);
			Foxy_Engine::defuseEvent(GIVE_CONTROL_EVENT,  true);
			Foxy_Engine::defuseEvent(WEAPON_DAMAGE_EVENT, true);
			Foxy_Engine::defuseEvent(REQUEST_PICKUP_EVENT, true);
			Foxy_Engine::defuseEvent(REQUEST_MAP_PICKUP_EVENT, true);
			Foxy_Engine::defuseEvent(RESPAWN_PLAYER_PED_EVENT, true);
			Foxy_Engine::defuseEvent(GIVE_WEAPON_EVENT,  true);
			Foxy_Engine::defuseEvent(REMOVE_WEAPON_EVENT, true);
			Foxy_Engine::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
			Foxy_Engine::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, true);
			Foxy_Engine::defuseEvent(FIRE_EVENT, true);
			Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
			Foxy_Engine::defuseEvent(START_PROJECTILE_EVENT, true);
			Foxy_Engine::defuseEvent(ALTER_WANTED_LEVEL_EVENT, true);
			Foxy_Engine::defuseEvent(CHANGE_RADIO_STATION_EVENT, true);
			Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
			Foxy_Engine::defuseEvent(PLAYER_TAUNT_EVENT, true);
			Foxy_Engine::defuseEvent(PLAYER_CARD_STAT_EVENT, true);
			Foxy_Engine::defuseEvent(DOOR_BREAK_EVENT, true);
			Foxy_Engine::defuseEvent(SCRIPTED_GAME_EVENT, true);
			Foxy_Engine::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, true);
			Foxy_Engine::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
			Foxy_Engine::defuseEvent(MARK_AS_NO_LONGER_NEEDED_EVENT, true);
			Foxy_Engine::defuseEvent(CONVERT_TO_SCRIPT_ENTITY_EVENT, true);
			Foxy_Engine::defuseEvent(SCRIPT_WORLD_STATE_EVENT, true);
			Foxy_Engine::defuseEvent(INCIDENT_ENTITY_EVENT, true);
			Foxy_Engine::defuseEvent(CLEAR_AREA_EVENT, true);
			Foxy_Engine::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_STOP_SYNCED_SCENE_EVENT, true);
			Foxy_Engine::defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, true);
			Foxy_Engine::defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_START_PED_ARREST_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_START_PED_UNCUFF_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_ENTITY_AREA_STATUS_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_GARAGE_OCCUPIED_STATUS_EVENT, true);
			Foxy_Engine::defuseEvent(PED_CONVERSATION_LINE_EVENT, true);
			Foxy_Engine::defuseEvent(SCRIPT_ENTITY_STATE_CHANGE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_PLAY_SOUND_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_STOP_SOUND_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_BANK_REQUEST_EVENT, true);
			Foxy_Engine::defuseEvent(REQUEST_DOOR_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_TRAIN_REPORT_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
			Foxy_Engine::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, true);
			Foxy_Engine::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, true);
			Foxy_Engine::defuseEvent(REQUEST_DETACHMENT_EVENT, true);
			Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, true);
			Foxy_Engine::defuseEvent(GIVE_PICKUP_REWARDS_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_CRC_HASH_CHECK_EVENT, true);
			Foxy_Engine::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, true);
			Foxy_Engine::defuseEvent(NETWORK_RESPONDED_TO_THREAT_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_SHOUT_TARGET_POSITION, true);
			Foxy_Engine::defuseEvent(PICKUP_DESTROYED_EVENT, true);
			Foxy_Engine::defuseEvent(UPDATE_PLAYER_SCARS_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_CHECK_EXE_SIZE_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_PTFX_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_PED_SEEN_DEAD_PED_EVENT, true);
			Foxy_Engine::defuseEvent(REMOVE_STICKY_BOMB_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_CHECK_CODE_CRCS_EVENT, true);
			Foxy_Engine::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, true);
			Foxy_Engine::defuseEvent(PED_PLAY_PAIN_EVENT, true);
			Foxy_Engine::defuseEvent(CACHE_PLAYER_HEAD_BLEND_DATA_EVENT, true);
			Foxy_Engine::defuseEvent(REMOVE_PED_FROM_PEDGROUP_EVENT, true);
			Foxy_Engine::defuseEvent(REPORT_MYSELF_EVENT, true);
			Foxy_Engine::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
			Foxy_Engine::defuseEvent(ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT, true);
			Foxy_Engine::defuseEvent(NETWORK_CHECK_CATALOG_CRC, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(SCRIPT_ARRAY_DATA_VERIFY_EVENT, false);
			Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, false);
			Foxy_Engine::defuseEvent(GIVE_CONTROL_EVENT,  false);
			Foxy_Engine::defuseEvent(WEAPON_DAMAGE_EVENT, false);
			Foxy_Engine::defuseEvent(REQUEST_PICKUP_EVENT, false);
			Foxy_Engine::defuseEvent(REQUEST_MAP_PICKUP_EVENT, false);
			Foxy_Engine::defuseEvent(RESPAWN_PLAYER_PED_EVENT, false);
			Foxy_Engine::defuseEvent(GIVE_WEAPON_EVENT,  false);
			Foxy_Engine::defuseEvent(REMOVE_WEAPON_EVENT, false);
			Foxy_Engine::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, false);
			Foxy_Engine::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, false);
			Foxy_Engine::defuseEvent(FIRE_EVENT, false);
			Foxy_Engine::defuseEvent(EXPLOSION_EVENT, false);
			Foxy_Engine::defuseEvent(START_PROJECTILE_EVENT, false);
			Foxy_Engine::defuseEvent(ALTER_WANTED_LEVEL_EVENT, false);
			Foxy_Engine::defuseEvent(CHANGE_RADIO_STATION_EVENT, false);
			Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, false);
			Foxy_Engine::defuseEvent(PLAYER_TAUNT_EVENT, false);
			Foxy_Engine::defuseEvent(PLAYER_CARD_STAT_EVENT, false);
			Foxy_Engine::defuseEvent(DOOR_BREAK_EVENT, false);
			Foxy_Engine::defuseEvent(SCRIPTED_GAME_EVENT, false);
			Foxy_Engine::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, false);
			Foxy_Engine::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, false);
			Foxy_Engine::defuseEvent(MARK_AS_NO_LONGER_NEEDED_EVENT, false);
			Foxy_Engine::defuseEvent(CONVERT_TO_SCRIPT_ENTITY_EVENT, false);
			Foxy_Engine::defuseEvent(SCRIPT_WORLD_STATE_EVENT, false);
			Foxy_Engine::defuseEvent(INCIDENT_ENTITY_EVENT, false);
			Foxy_Engine::defuseEvent(CLEAR_AREA_EVENT, false);
			Foxy_Engine::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_STOP_SYNCED_SCENE_EVENT, false);
			Foxy_Engine::defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, false);
			Foxy_Engine::defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_START_PED_ARREST_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_START_PED_UNCUFF_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_ENTITY_AREA_STATUS_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_GARAGE_OCCUPIED_STATUS_EVENT, false);
			Foxy_Engine::defuseEvent(PED_CONVERSATION_LINE_EVENT, false);
			Foxy_Engine::defuseEvent(SCRIPT_ENTITY_STATE_CHANGE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_PLAY_SOUND_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_STOP_SOUND_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_BANK_REQUEST_EVENT, false);
			Foxy_Engine::defuseEvent(REQUEST_DOOR_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_TRAIN_REPORT_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, false);
			Foxy_Engine::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, false);
			Foxy_Engine::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, false);
			Foxy_Engine::defuseEvent(REQUEST_DETACHMENT_EVENT, false);
			Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, false);
			Foxy_Engine::defuseEvent(GIVE_PICKUP_REWARDS_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_CRC_HASH_CHECK_EVENT, false);
			Foxy_Engine::defuseEvent(BLOW_UP_VEHICLE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, false);
			Foxy_Engine::defuseEvent(NETWORK_RESPONDED_TO_THREAT_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_SHOUT_TARGET_POSITION, false);
			Foxy_Engine::defuseEvent(PICKUP_DESTROYED_EVENT, false);
			Foxy_Engine::defuseEvent(UPDATE_PLAYER_SCARS_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_CHECK_EXE_SIZE_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_PTFX_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_PED_SEEN_DEAD_PED_EVENT, false);
			Foxy_Engine::defuseEvent(REMOVE_STICKY_BOMB_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_CHECK_CODE_CRCS_EVENT, false);
			Foxy_Engine::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, false);
			Foxy_Engine::defuseEvent(PED_PLAY_PAIN_EVENT, false);
			Foxy_Engine::defuseEvent(CACHE_PLAYER_HEAD_BLEND_DATA_EVENT, false);
			Foxy_Engine::defuseEvent(REMOVE_PED_FROM_PEDGROUP_EVENT, false);
			Foxy_Engine::defuseEvent(REPORT_MYSELF_EVENT, false);
			Foxy_Engine::defuseEvent(REPORT_CASH_SPAWN_EVENT, false);
			Foxy_Engine::defuseEvent(ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT, false);
			Foxy_Engine::defuseEvent(NETWORK_CHECK_CATALOG_CRC, false);
		}

		if (ExplosionP)
		{
			Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(EXPLOSION_EVENT, false);
		}

		if (FireP)
		{
			Foxy_Engine::defuseEvent(FIRE_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(FIRE_EVENT, false);
		}

		if (WeaponP)
		{
			Foxy_Engine::defuseEvent(REMOVE_WEAPON_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(REMOVE_WEAPON_EVENT, false);
		}

		if (Blockweather)
		{
		}

		if (BlockOzarkcunt)
		{
			Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
		}
		else
		{
			Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, false);
		}





		if (Swap1)
		{
			uint CageHash[] = { 959275690, 1396140175, -1326042488, -1363719163, 1688773919, 3334677549, };
			Vector3 Playercoord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			for (Hash hash : CageHash) {
				ENTITY::CREATE_MODEL_SWAP(Playercoord.x, Playercoord.y, Playercoord.z, 10.0f, hash, $("prop_ld_lap_top"), 0);
			}

		}
		else
		{
			NULL;
		}

		if (Swap2)
		{
			Hash kosa = GAMEPLAY::GET_HASH_KEY("KOSATKA");//1336872304
			uint BadObjects2[] = { 1336872304, };
			Vector3 pp = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			for (Hash hash : BadObjects2) {
				ENTITY::CREATE_MODEL_SWAP(pp.x, pp.y, pp.z, 10.0f, hash, $("prop_ld_lap_top"), 0);
			}

		}

		if (Swap3)
		{
			Hash kosa = GAMEPLAY::GET_HASH_KEY("TITAN"); //1981688531
			uint BadObjects3[] = { 1981688531, };
			Vector3 pp = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			for (Hash hash : BadObjects3) {
				ENTITY::CREATE_MODEL_SWAP(pp.x, pp.y, pp.z, 10.0f, hash, $("prop_ld_lap_top"), 0);
			}
		}

		if (Swap4)
		{
			ENTITY::_SET_ENTITY_COORDS_2(PLAYER::PLAYER_PED_ID(), 9999.f, 9999.f, 9999.f, 1, 0, 0, 1);
		}





		Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));

		if (VehicleInvisible1)
		{
			int Handle = PLAYER::PLAYER_PED_ID();
			int Handle2 = PED::GET_VEHICLE_PED_IS_IN(Handle, 0);
			ENTITY::SET_ENTITY_COLLISION(Handle, false, false);
			ENTITY::SET_ENTITY_COLLISION(Handle2, false, false);
			ENTITY::SET_ENTITY_VISIBLE(Veh, false, 0);
		}
		else
		{
			int Handle = PLAYER::PLAYER_PED_ID();
			int Handle2 = PED::GET_VEHICLE_PED_IS_IN(Handle, 0);

			ENTITY::SET_ENTITY_VISIBLE(Veh, true, 0);
			ENTITY::SET_ENTITY_COLLISION(Handle, true, true);
			ENTITY::SET_ENTITY_COLLISION(Handle2, true, true);
		}

		if (VehicleInvisible2)
		{

			ENTITY::SET_ENTITY_VISIBLE(Veh, false, 0);
		}
		else
		{
			ENTITY::SET_ENTITY_VISIBLE(Veh, true, 0);
		}

		if (VehicleInvisible)
		{
			ENTITY::SET_ENTITY_VISIBLE(Veh, false, 0);
		}
		else
		{
			ENTITY::SET_ENTITY_VISIBLE(Veh, true, 0);
		}

		if (cloneprotection)
		{
			if (!CUTSCENE::IS_CUTSCENE_ACTIVE() && !CUTSCENE::IS_CUTSCENE_PLAYING() && !STREAMING::IS_NETWORK_LOADING_SCENE() && !NETWORK::NETWORK_IS_IN_MP_CUTSCENE() && !INTERIOR::IS_INTERIOR_SCENE())
			{
				Ped Closest;
				Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				if (PED::GET_CLOSEST_PED(MyPos.x, MyPos.y, MyPos.z, 5, true, true, &Closest, false, true, -1))
				{
					if (ENTITY::GET_ENTITY_MODEL(Closest) == ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()))
					{
						if (!PED::IS_PED_A_PLAYER(Closest))
						{
							if (ENTITY::DOES_ENTITY_EXIST(Closest))
							{
								if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Closest))
								{
									if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Closest))
									{
										ENTITY::DETACH_ENTITY(Closest, 1, 1);
										ENTITY::SET_ENTITY_COORDS(Closest, 6000.0, 6000.0, 6000.0, true, false, false, true);
										ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Closest, 1, 1);
										PED::DELETE_PED(&Closest);
										ENTITY::DELETE_ENTITY(&Closest);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{

		}

		if (Fixloop)
		{
			uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
			VEHICLE::SET_VEHICLE_FIXED(Vehicle);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
		}
		else
		{

		}

		if (expand)
		{
			PLAYER::_EXPAND_WORLD_LIMITS(50000.0, 50000.0, 50.0);
			PLAYER::_EXPAND_WORLD_LIMITS(-50000.0, -50000.0, 50.0);
		}
		else
		{

		}

		if (SA)
		{
			if (IsPedShooting(PLAYER::PLAYER_PED_ID()))
			{
				Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 Dir = rot_to_direction(&Rot);
				Vector3 CPosition = CAM::GET_GAMEPLAY_CAM_COORD();
				Vector3 PlayerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				float spawnDistance = get_distance(&CPosition, &PlayerPosition);
				spawnDistance += distancee;                                                         //nndnndhfjf
				Vector3 SPosition = add(&CPosition, &multiply(&Dir, spawnDistance));
				DWORD Model = $(EntiThing);
				Object ObJect = OBJECT::CREATE_OBJECT(Model, SPosition.x, SPosition.y, SPosition.z, 1, 1, 1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
				if (ENTITY::DOES_ENTITY_EXIST(ObJect))
				{
					ENTITY::SET_ENTITY_RECORDS_COLLISIONS(ObJect, true);
					for (float f = 0.0f; f < 75.0f; f++) {
						if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(ObJect))break;
						ENTITY::APPLY_FORCE_TO_ENTITY(ObJect, 1, Dir.x * 10.0f, Dir.y * 10.0f, Dir.z * 10.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
						WAIT(0);
					}
					Vector3 Coordinates = ENTITY::GET_ENTITY_COORDS(ObJect, 1);
					FIRE::ADD_EXPLOSION(Coordinates.x, Coordinates.y, Coordinates.z, 9, 25.0f, 1, 1, 0.5f);
				}
			}
		}

		if (ground)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				int myVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(myVehicle);
			}
		}

		if (Unlimited)
		{
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			if (bPlayerExists)
			{
				PLAYER::SPECIAL_ABILITY_FILL_METER(player, 1);
			}
		}

		if (FoxyId)
		{
			PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), 956);
		}
		

		if (Worldglow) {
			if (WorldglowRGB) {
				RGBFaded4();
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				GRAPHICS::DRAW_LIGHT_WITH_RANGE(Coords.x, Coords.y, Coords.z, reded, greened, blued, world_glow_range, world_glow_intensity);
			}
			else {
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				GRAPHICS::DRAW_LIGHT_WITH_RANGE(Coords.x, Coords.y, Coords.z, world_glow_red, world_glow_green, world_glow_blue, world_glow_range, world_glow_intensity);
			}
		}
		if (Worldglow1) {
			if (WorldglowRGB1) {
				RGBFaded4();
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				GRAPHICS::DRAW_LIGHT_WITH_RANGE(Coords.x, Coords.y, Coords.z, reded, greened, blued, 99999.00000f, world_glow_intensity1);
			}
			else {
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				GRAPHICS::_DRAW_LIGHT_WITH_RANGE_AND_SHADOW(Coords.x, Coords.y, Coords.z, world_glow_red1, world_glow_green1, world_glow_blue1, 99999.00000f, world_glow_intensity1, world_glow_shadow);
			}
		}
		if (Worldglow2) {
			if (WorldglowRGB2) {
				RGBFaded4();
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				Vector3 direction = GET_CAMERA_DIRECTION(0.1);
				GRAPHICS::DRAW_SPOT_LIGHT(Coords.x, Coords.y, Coords.z, direction.x, direction.y, direction.z, reded, greened, blued, world_glow_range2, world_glow_intensity2, hardness, radius, falloff);
			}
			else {
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				Vector3 direction = GET_CAMERA_DIRECTION(0.1);
				GRAPHICS::DRAW_SPOT_LIGHT(Coords.x, Coords.y, Coords.z, direction.x, direction.y, direction.z, world_glow_red2, world_glow_green2, world_glow_blue2, world_glow_range2, world_glow_intensity2, hardness, radius, falloff);
			}
		}
		if (Worldglow3) {
			if (WorldglowRGB3) {
				RGBFaded4();
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				Vector3 direction = GET_CAMERA_DIRECTION(0.1);
				GRAPHICS::_DRAW_SPOT_LIGHT_WITH_SHADOW(Coords.x, Coords.y, Coords.z, direction.x, direction.y, direction.z, reded, greened, blued, world_glow_range3, world_glow_intensity3, hardness2, radius2, falloff2, shadowid);
			}
			else {
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				Vector3 direction = GET_CAMERA_DIRECTION(0.1);
				GRAPHICS::_DRAW_SPOT_LIGHT_WITH_SHADOW(Coords.x, Coords.y, Coords.z, direction.x, direction.y, direction.z, world_glow_red3, world_glow_green3, world_glow_blue3, world_glow_range3, world_glow_intensity3, hardness2, radius2, falloff2, shadowid);
			}
		}

		if (waterdostuff)
		{
			Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			WATER::MODIFY_WATER(Coords.x, Coords.y, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 2, Coords.y, -10, 10);
			WATER::MODIFY_WATER(Coords.x, Coords.y + 2, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 2, Coords.y + 2, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 4, Coords.y, -10, 10);
			WATER::MODIFY_WATER(Coords.x, Coords.y + 4, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 4, Coords.y + 4, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 6, Coords.y, -10, 10);
			WATER::MODIFY_WATER(Coords.x, Coords.y + 6, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 6, Coords.y + 6, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 8, Coords.y, -10, 10);
			WATER::MODIFY_WATER(Coords.x, Coords.y + 8, -10, 10);
			WATER::MODIFY_WATER(Coords.x + 8, Coords.y + 8, -10, 10);
		}

		if (rgbTheme)
		{
			Menu::Settings::titleRect = { r1, g1, b1, 255 };
			Menu::Settings::scroller = { b1, r1, g1, 255 };
			Menu::Settings::optionRect = { b1, g1, r1, 200 };
			Menu::Settings::SubTitle = { b1, g1, r1, 255 };
		}



		if (SlowMotionn)
		{
			GAMEPLAY::SET_TIME_SCALE(0.2);
		}
		else
		{
			GAMEPLAY::SET_TIME_SCALE(1);
		}

		if (freeze_map)
		{
			
		}


		
		if (Camfree)
		{
			static bool lock;
			static std::int32_t cam;
			static float dist;

			auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			auto coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

			Vector3 p_coord = { 0,0,0 };

			int Handle = PLAYER::PLAYER_PED_ID();
			int Handle2 = PED::GET_VEHICLE_PED_IS_IN(Handle, 0);

			ENTITY::SET_ENTITY_VISIBLE(Handle, false, 0);

			//ENTITY::SET_ENTITY_COLLISION(Handle, false, false);
			//ENTITY::SET_ENTITY_COLLISION(Handle2, false, false);
			VehicleInvisible1 = true;
			VehicleInvisible = true;
			if (!CAM::DOES_CAM_EXIST(cam)) {
				cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
				CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
				CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
			}
			if (!Camfree)
			{
				Vector3 BenAndJerrys = CAM::GET_CAM_COORD(cam);
				ENTITY::SET_ENTITY_COORDS(Handle, BenAndJerrys.x, BenAndJerrys.y, BenAndJerrys.z, 0, 0, 0, 1);
				CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
				CAM::SET_CAM_ACTIVE(cam, 0);
				CAM::DESTROY_CAM(cam, true);
				PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);

			}
			else if (!Camfree == false)
			{
				ENTITY::SET_ENTITY_COLLISION(Handle, true, true);
				ENTITY::SET_ENTITY_COLLISION(Handle2, true, true);

				Vector3 BenAndJerrys = CAM::GET_CAM_COORD(cam);
				if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
				{
					ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), BenAndJerrys.x, BenAndJerrys.y, BenAndJerrys.z, 0, 0, 0, 1);
				}
				else
				{
					ENTITY::SET_ENTITY_COORDS(Handle, BenAndJerrys.x, BenAndJerrys.y, BenAndJerrys.z, 0, 0, 0, 1);
				}

			}

			CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
			CAM::SET_CAM_ACTIVE(cam, 1);
			CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

			p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

			//ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
			//PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

			auto speed = .5f;
			if (IsKeyPressed(VK_LSHIFT))
			{
				speed += .3f;
			}

			if (IsKeyPressed(VK_KEY_S))
			{
				speed /= -1;
				auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
				CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
			}

			if (IsKeyPressed(VK_KEY_W))
			{
				auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
				CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
			}

		}
		else
		{
			static bool lock;
			static std::int32_t cam;
			static float dist;
			auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
			Vector3 p_coord = { 0,0,0 };

			int Handle = PLAYER::PLAYER_PED_ID();
			int Handle2 = PED::GET_VEHICLE_PED_IS_IN(Handle, 0);

			CAM::SET_CAM_ACTIVE(cam, false);
			CAM::DESTROY_CAM(cam, true);
			PLAYER::SET_PLAYER_CONTROL(Handle, true, 0);
			CAM::RENDER_SCRIPT_CAMS(false, false, 3000, 1, 0);

			VehicleInvisible1 = false;
			VehicleInvisible = false;

		}

		if (freecamclip == true)
		{
			if (GetAsyncKeyState(VK_F5))
			{
				if (Camfree == true)
				{
					Camfree = false;
				}
				else if (Camfree == false)
				{
					Camfree = true;
				}
				else
				{

				}
			}
		}


		if (pedwarprotection)
		{
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped* peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				RequestControlOfEnt(peds[OffsetID]);
				if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
				{
					ENTITY::DETACH_ENTITY(peds[OffsetID], 1, 1);
					ENTITY::SET_ENTITY_COORDS(peds[OffsetID], 6000.0, 6000.0, 6000.0, true, false, false, true);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(peds[OffsetID], 1, 1);
					PED::DELETE_PED(&peds[OffsetID]);
					ENTITY::DELETE_ENTITY(&peds[OffsetID]);
				}
			}
		}
		else
		{ }
		char* warobjects[13446] = { "prop_mp_ramp_03", "prop_a4_pile_01", "prop_a4_sheet_01", "prop_abat_roller_static", "prop_abat_slide", "prop_acc_guitar_01", "prop_aerial_01a", "prop_afsign_amun", "prop_afsign_vbike", "prop_agave_01", "prop_aiprort_sign_01", "prop_aircon_l_01", "prop_aircon_m_09", "prop_aircon_s_01a", "prop_aircon_s_02a", "prop_airhockey_01", "prop_air_bagloader", "prop_air_bagloader2", "prop_air_barrier", "prop_air_bench_01", "prop_air_bench_02", "prop_air_bigradar_l1", "prop_air_bigradar_slod", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_bridge01", "prop_air_bridge02", "prop_air_cargoloader_01", "prop_air_cargo_01a", "prop_air_cargo_01b", "prop_air_chock_01", "prop_air_fueltrail1", "prop_air_fueltrail2", "prop_air_gasbogey_01", "prop_air_generator_01", "prop_air_generator_03", "prop_air_hoc_paddle_01", "prop_air_hoc_paddle_02", "prop_air_lights_01a", "prop_air_lights_01b", "prop_air_lights_03a", "prop_air_luggtrolley", "prop_air_mast_01", "prop_air_mast_02", "prop_air_monhut_01", "prop_air_monhut_02", "prop_air_monhut_03", "prop_air_propeller01", "prop_air_radar_01", "prop_air_stair_01", "prop_air_towbar_01", "prop_air_towbar_02", "prop_air_towbar_03", "prop_air_trailer_4a", "prop_air_trailer_4b", "prop_air_trailer_4c", "prop_air_watertank1", "prop_air_watertank2", "prop_air_windsock_base", "prop_air_woodsteps", "prop_alarm_01", "prop_alarm_02", "prop_alien_egg_01", "prop_aloevera_01", "prop_amanda_note_01", "prop_amanda_note_01b", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_ciggy_01", "prop_amb_donut", "prop_amb_handbag_01", "prop_amb_phone", "prop_amp_01", "prop_am_box_wood_01", "prop_anim_cash_note", "prop_anim_cash_note_b", "prop_anim_cash_pile_01", "prop_anim_cash_pile_02", "prop_apple_box_01", "prop_apple_box_02", "prop_arcade_01", "prop_arcade_02", "prop_arc_blueprints_01", "prop_armchair_01", "prop_armenian_gate", "prop_armour_pickup", "prop_arm_gate_l", "prop_arm_wrestle_01", "prop_artgallery_02_dl", "prop_artgallery_02_dr", "prop_artgallery_dl", "prop_artgallery_dr", "prop_artifact_01", "prop_ashtray_01", "prop_asteroid_01", "prop_atm_02", "prop_atm_03", "prop_attache_case_01", "prop_aviators_01", "prop_a_base_bars_01", "prop_a_trailer_door_01", "prop_bahammenu", "prop_ballistic_shield", "prop_ballistic_shield_lod1", "prop_bandsaw_01", "prop_bank_shutter", "prop_bank_vaultdoor", "prop_barn_door_l", "prop_barn_door_r", "prop_barrachneon", "prop_barrel_01a", "prop_barrel_02a", "prop_barrel_02b", "prop_barrel_03a", "prop_barrel_03d", "prop_barrel_float_1", "prop_barrel_float_2", "prop_barriercrash_03", "prop_barriercrash_04", "prop_barrier_wat_01a", "prop_barrier_wat_03b", "prop_barrier_work01c", "prop_barry_table_detail", "prop_bar_coastbarr", "prop_bar_coastchamp", "prop_bar_coastdusc", "prop_bar_coastmount", "prop_bar_cooler_01", "prop_bar_cooler_03", "prop_bar_fridge_01", "prop_bar_fridge_02", "prop_bar_fridge_03", "prop_bar_fridge_04", "prop_bar_ice_01", "prop_bar_napkindisp", "prop_bar_pump_01", "prop_bar_pump_04", "prop_bar_pump_05", "prop_bar_pump_10", "prop_bar_sink_01", "prop_bar_stool_01", "prop_basejump_target_01", "prop_basketball_net", "prop_bath_dirt_01", "prop_battery_01", "prop_battery_02", "prop_bball_arcade_01", "prop_bbq_2", "prop_bbq_3", "prop_beachbag_01", "prop_beachbag_02", "prop_beachbag_combo_01", "prop_beachball_02", "prop_beachflag_le", "prop_beach_bars_01", "prop_beach_bars_02", "prop_beach_bbq", "prop_beach_dip_bars_01", "prop_beach_dip_bars_02", "prop_beach_fire", "prop_beach_lg_float", "prop_beach_lg_stretch", "prop_beach_lg_surf", "prop_beach_punchbag", "prop_beach_rings_01", "prop_beach_sculp_01", "prop_beach_towel_02", "prop_beach_volball01", "prop_beach_volball02", "prop_beerneon", "prop_beer_bison", "prop_beer_box_01", "prop_beer_neon_01", "prop_beer_neon_02", "prop_beggers_sign_01", "prop_beggers_sign_02", "prop_bench_01b", "prop_bench_01c", "prop_bench_04", "prop_beta_tape", "prop_beware_dog_sign", "prop_bh1_03_gate_l", "prop_bh1_03_gate_r", "prop_bh1_08_mp_gar", "prop_bh1_09_mp_gar", "prop_bh1_09_mp_l", "prop_bh1_09_mp_r", "prop_bh1_16_display", "prop_bh1_44_door_01l", "prop_bh1_44_door_01r", "prop_bh1_48_backdoor_l", "prop_bh1_48_backdoor_r", "prop_bh1_48_gate_1", "prop_bhhotel_door_l", "prop_bhhotel_door_r", "prop_big_bag_01", "prop_big_clock_01", "prop_big_shit_01", "prop_big_shit_02", "prop_bikerack_2", "prop_bikini_disp_01", "prop_bikini_disp_02", "prop_billboard_01", "prop_billboard_02", "prop_billboard_03", "prop_billboard_04", "prop_billboard_09wall", "prop_billboard_10", "prop_billboard_11", "prop_billb_frame01a", "prop_billb_frame01b", "prop_billb_frame02a", "prop_binoc_01", "prop_bin_04a", "prop_bin_10a", "prop_bin_10b", "prop_bin_11a", "prop_bin_beach_01d", "prop_bin_delpiero", "prop_bin_delpiero_b", "prop_biolab_g_door", "prop_biotech_store", "prop_bison_winch", "prop_blackjack_01", "prop_bleachers_01", "prop_blox_spray", "prop_bmu_01", "prop_bmu_01_b", "prop_bmu_02", "prop_bmu_02_ld", "prop_bmu_02_ld_cab", "prop_bmu_02_ld_sup", "prop_bmu_track01", "prop_bmu_track02", "prop_bmu_track03", "prop_bodyarmour_02", "prop_bodyarmour_03", "prop_bodyarmour_04", "prop_bollard_01a", "prop_bollard_01b", "prop_bomb_01", "prop_bomb_01_s", "prop_bonesaw", "prop_bongos_01", "prop_bong_01", "prop_boogbd_stack_01", "prop_boogbd_stack_02", "prop_boogieboard_01", "prop_boogieboard_02", "prop_boombox_01", "prop_bottle_cap_01", "prop_bowling_ball", "prop_bowling_pin", "prop_bowl_crisps", "prop_boxcar5_handle", "prop_boxing_glove_01", "prop_boxpile_10a", "prop_boxpile_10b", "prop_box_ammo01a", "prop_box_ammo02a", "prop_box_ammo03a_set", "prop_box_ammo03a_set2", "prop_box_guncase_01a", "prop_box_guncase_02a", "prop_box_guncase_03a", "prop_box_tea01a", "prop_box_wood05a", "prop_box_wood05b", "prop_box_wood08a", "prop_breadbin_01", "prop_bread_rack_01", "prop_bread_rack_02", "prop_broken_cboard_p1", "prop_broken_cboard_p2", "prop_broken_cell_gate_01", "prop_broom_unit_01", "prop_bskball_01", "prop_bs_map_door_01", "prop_buckets_02", "prop_bucket_01a", "prop_bucket_01b", "prop_bucket_02a", "prop_buck_spade_01", "prop_buck_spade_02", "prop_buck_spade_03", "prop_bumper_01", "prop_bumper_02", "prop_bumper_03", "prop_bumper_car_01", "prop_burto_gate_01", "prop_bush_dead_02", "prop_bush_grape_01", "prop_bush_ivy_01_1m", "prop_bush_lrg_01", "prop_bush_lrg_01b", "prop_bush_lrg_01c", "prop_bush_med_01", "prop_bush_med_02", "prop_bush_neat_01", "prop_bush_neat_02", "prop_bush_ornament_01", "prop_bush_ornament_02", "prop_busker_hat_01", "prop_byard_bench01", "prop_byard_bench02", "prop_byard_block_01", "prop_byard_boat01", "prop_byard_boat02", "prop_byard_chains01", "prop_byard_dingy", "prop_byard_elecbox01", "prop_byard_elecbox02", "prop_byard_floatpile", "prop_byard_float_01", "prop_byard_float_01b", "prop_byard_hoist", "prop_byard_hoist_2", "prop_byard_hoses01", "prop_byard_hoses02", "prop_byard_ladder01", "prop_byard_machine01", "prop_byard_machine02", "prop_byard_motor_01", "prop_byard_motor_02", "prop_byard_net02", "prop_byard_phone", "prop_byard_pipes01", "prop_byard_pipe_01", "prop_byard_planks01", "prop_byard_pulley01", "prop_byard_rack", "prop_byard_ramp", "prop_byard_rampold", "prop_byard_rowboat1", "prop_byard_scfhold01", "prop_byard_sleeper01", "prop_byard_sleeper02", "prop_byard_steps_01", "prop_byard_tank_01", "prop_byard_trailer01", "prop_byard_trailer02", "prop_b_board_blank", "prop_c4_final", "prop_c4_final_green", "prop_cabinet_01", "prop_cabinet_01b", "prop_cabinet_02b", "prop_cablespool_01a", "prop_cablespool_01b", "prop_cablespool_02", "prop_camera_strap", "prop_candy_pqs", "prop_can_canoe", "prop_cap_01", "prop_cap_01b", "prop_cap_row_01", "prop_cap_row_01b", "prop_cap_row_02", "prop_cap_row_02b", "prop_carcreeper", "prop_cargo_int", "prop_carjack", "prop_carjack_l2", "prop_carrier_bag_01", "prop_carrier_bag_01_lod", "prop_cartwheel_01", "prop_carwash_roller_horz", "prop_carwash_roller_vert", "prop_car_battery_01", "prop_car_bonnet_01", "prop_car_bonnet_02", "prop_car_door_01", "prop_car_engine_01", "prop_car_exhaust_01", "prop_car_ignition", "prop_car_seat", "prop_casey_sec_id", "prop_cash_case_01", "prop_cash_case_02", "prop_cash_crate_01", "prop_cash_dep_bag_01", "prop_cash_envelope_01", "prop_cash_note_01", "prop_cash_pile_01", "prop_cash_pile_02", "prop_cash_trolly", "prop_casino_door_01l", "prop_casino_door_01r", "prop_cattlecrush", "prop_cat_tail_01", "prop_cctv_02_sm", "prop_cctv_cont_01", "prop_cctv_cont_03", "prop_cementmixer_01a", "prop_cementmixer_02a", "prop_ceramic_jug_01", "prop_ceramic_jug_cork", "prop_ch1_07_door_01l", "prop_ch2_05d_g_door", "prop_ch2_07b_20_g_door", "prop_ch2_09b_door", "prop_ch2_09c_garage_door", "prop_ch3_01_trlrdoor_l", "prop_ch3_01_trlrdoor_r", "prop_ch3_04_door_01l", "prop_ch3_04_door_01r", "prop_ch3_04_door_02", "prop_chair_01a", "prop_chair_01b", "prop_chair_02", "prop_chair_03", "prop_chair_pile_01", "prop_chall_lamp_01", "prop_chall_lamp_01n", "prop_chall_lamp_02", "prop_chateau_chair_01", "prop_cheetah_covered", "prop_chem_grill", "prop_chem_grill_bit", "prop_chem_vial_02", "prop_chem_vial_02b", "prop_cherenneon", "prop_chickencoop_a", "prop_chip_fryer", "prop_choc_ego", "prop_choc_meto", "prop_choc_pq", "prop_ch_025c_g_door_01", "prop_cigar_01", "prop_cigar_pack_01", "prop_cigar_pack_02", "prop_clapper_brd_01", "prop_cleaver", "prop_cliff_paper", "prop_clippers_01", "prop_clothes_rail_02", "prop_clothes_rail_03", "prop_clothes_rail_2b", "prop_clothes_tub_01", "prop_clown_chair", "prop_cntrdoor_ld_l", "prop_cntrdoor_ld_r", "prop_coathook_01", "prop_cockneon", "prop_coffee_cup_trailer", "prop_coffee_mac_02", "prop_coffin_02", "prop_coffin_02b", "prop_coke_block_01", "prop_coke_block_half_a", "prop_coke_block_half_b", "prop_compressor_01", "prop_compressor_02", "prop_compressor_03", "prop_com_gar_door_01", "prop_com_ls_door_01", "prop_conc_sacks_02a", "prop_cone_float_1", "prop_conschute", "prop_consign_01c", "prop_consign_02a", "prop_conslift_base", "prop_conslift_brace", "prop_conslift_cage", "prop_conslift_steps", "prop_console_01", "prop_construcionlamp_01", "prop_const_fence01a", "prop_const_fence01b", "prop_const_fence02a", "prop_cons_crate", "prop_cons_plank", "prop_cons_ply01", "prop_cons_ply02", "prop_container_01a", "prop_container_01b", "prop_container_01c", "prop_container_01d", "prop_container_01e", "prop_container_01f", "prop_container_03mb", "prop_container_05mb", "prop_container_door_mb_l", "prop_container_door_mb_r", "prop_container_hole", "prop_container_ld", "prop_container_ld2", "prop_container_old1", "prop_contnr_pile_01a", "prop_controller_01", "prop_control_rm_door_01", "prop_cont_chiller_01", "prop_cooker_03", "prop_copier_01", "prop_copper_pan", "prop_coral_bush_01", "prop_coral_flat_01", "prop_coral_flat_01_l1", "prop_coral_flat_02", "prop_coral_flat_brainy", "prop_coral_flat_clam", "prop_coral_grass_01", "prop_coral_grass_02", "prop_coral_kelp_01", "prop_coral_kelp_01_l1", "prop_coral_kelp_02", "prop_coral_kelp_02_l1", "prop_coral_kelp_03", "prop_coral_kelp_03_l1", "prop_coral_kelp_04", "prop_coral_kelp_04_l1", "prop_coral_pillar_01", "prop_coral_pillar_02", "prop_coral_spikey_01", "prop_coral_stone_03", "prop_coral_sweed_03", "prop_coral_sweed_04", "prop_cora_clam_01", "prop_cork_board", "prop_couch_01", "prop_couch_03", "prop_couch_04", "prop_couch_lg_02", "prop_couch_lg_05", "prop_couch_sm_07", "prop_crane_01_truck1", "prop_crane_01_truck2", "prop_cranial_saw", "prop_crashed_heli", "prop_cratepile_07a_l1", "prop_crate_01a", "prop_crate_02a", "prop_crate_08a", "prop_crate_float_1", "prop_creosote_b_01", "prop_crisp", "prop_crisp_small", "prop_crosssaw_01", "prop_cs1_14b_traind", "prop_cs1_14b_traind_dam", "prop_cs4_05_tdoor", "prop_cs4_10_tr_gd_01", "prop_cs4_11_door", "prop_cs6_03_door_l", "prop_cs6_03_door_r", "prop_cs_20m_rope", "prop_cs_30m_rope", "prop_cs_abattoir_switch", "prop_cs_aircon_01", "prop_cs_aircon_fan", "prop_cs_amanda_shoe", "prop_cs_ashtray", "prop_cs_bandana", "prop_cs_bar", "prop_cs_beachtowel_01", "prop_cs_beer_bot_01", "prop_cs_beer_bot_01b", "prop_cs_beer_bot_01lod", "prop_cs_beer_bot_02", "prop_cs_beer_bot_40oz_03", "prop_cs_beer_bot_test", "prop_cs_binder_01", "prop_cs_bin_01", "prop_cs_bin_01_lid", "prop_cs_bin_01_skinned", "prop_cs_bin_02", "prop_cs_bin_03", "prop_cs_book_01", "prop_cs_bottle_opener", "prop_cs_bowie_knife", "prop_cs_bowl_01", "prop_cs_bowl_01b", "prop_cs_box_clothes", "prop_cs_box_step", "prop_cs_brain_chunk", "prop_cs_bs_cup", "prop_cs_bucket_s", "prop_cs_bucket_s_lod", "prop_cs_burger_01", "prop_cs_business_card", "prop_cs_cardbox_01", "prop_cs_cash_note_01", "prop_cs_cctv", "prop_cs_champ_flute", "prop_cs_ciggy_01", "prop_cs_ciggy_01b", "prop_cs_clothes_box", "prop_cs_coke_line", "prop_cs_cont_latch", "prop_cs_crackpipe", "prop_cs_credit_card", "prop_cs_creeper_01", "prop_cs_crisps_01", "prop_cs_cuffs_01", "prop_cs_diaphram", "prop_cs_dildo_01", "prop_cs_documents_01", "prop_cs_duffel_01", "prop_cs_duffel_01b", "prop_cs_dumpster_01a", "prop_cs_dumpster_lidl", "prop_cs_dumpster_lidr", "prop_cs_dvd", "prop_cs_dvd_case", "prop_cs_dvd_player", "prop_cs_envolope_01", "prop_cs_fertilizer", "prop_cs_film_reel_01", "prop_cs_folding_chair_01", "prop_cs_fork", "prop_cs_frank_photo", "prop_cs_freightdoor_l1", "prop_cs_freightdoor_r1", "prop_cs_fridge", "prop_cs_fridge_door", "prop_cs_fuel_hose", "prop_cs_fuel_nozle", "prop_cs_gascutter_1", "prop_cs_gascutter_2", "prop_cs_glass_scrap", "prop_cs_gravyard_gate_l", "prop_cs_gravyard_gate_r", "prop_cs_gunrack", "prop_cs_hand_radio", "prop_cs_heist_bag_01", "prop_cs_heist_bag_02", "prop_cs_heist_bag_strap_01", "prop_cs_heist_rope", "prop_cs_heist_rope_b", "prop_cs_hotdog_01", "prop_cs_hotdog_02", "prop_cs_h_bag_strap_01", "prop_cs_ice_locker", "prop_cs_ice_locker_door_l", "prop_cs_ice_locker_door_r", "prop_cs_ilev_blind_01", "prop_cs_ironing_board", "prop_cs_katana_01", "prop_cs_kettle_01", "prop_cs_keyboard_01", "prop_cs_keys_01", "prop_cs_kitchen_cab_l2", "prop_cs_lazlow_ponytail", "prop_cs_lazlow_shirt_01", "prop_cs_lazlow_shirt_01b", "prop_cs_leaf", "prop_cs_leg_chain_01", "prop_cs_lester_crate", "prop_cs_lipstick", "prop_cs_magazine", "prop_cs_marker_01", "prop_cs_meth_pipe", "prop_cs_milk_01", "prop_cs_mini_tv", "prop_cs_mopbucket_01", "prop_cs_mop_s", "prop_cs_mouse_01", "prop_cs_nail_file", "prop_cs_newspaper", "prop_cs_office_chair", "prop_cs_overalls_01", "prop_cs_package_01", "prop_cs_padlock", "prop_cs_pamphlet_01", "prop_cs_panel_01", "prop_cs_panties", "prop_cs_panties_02", "prop_cs_panties_03", "prop_cs_paper_cup", "prop_cs_para_ropebit", "prop_cs_para_ropes", "prop_cs_pebble", "prop_cs_pebble_02", "prop_cs_petrol_can", "prop_cs_phone_01", "prop_cs_photoframe_01", "prop_cs_pills", "prop_cs_plane_int_01", "prop_cs_planning_photo", "prop_cs_plant_01", "prop_cs_plate_01", "prop_cs_polaroid", "prop_cs_police_torch", "prop_cs_pour_tube", "prop_cs_power_cell", "prop_cs_power_cord", "prop_cs_protest_sign_01", "prop_cs_protest_sign_02", "prop_cs_rage_statue_p1", "prop_cs_rage_statue_p2", "prop_cs_remote_01", "prop_cs_rolled_paper", "prop_cs_rope_tie_01", "prop_cs_rub_binbag_01", "prop_cs_rub_box_01", "prop_cs_rub_box_02", "prop_cs_r_business_card", "prop_cs_sack_01", "prop_cs_saucer_01", "prop_cs_sc1_11_gate", "prop_cs_scissors", "prop_cs_script_bottle", "prop_cs_script_bottle_01", "prop_cs_server_drive", "prop_cs_sheers", "prop_cs_shirt_01", "prop_cs_shopping_bag", "prop_cs_shot_glass", "prop_cs_silver_tray", "prop_cs_sink_filler", "prop_cs_sink_filler_02", "prop_cs_sm_27_gate", "prop_cs_sol_glasses", "prop_cs_spray_can", "prop_cs_steak", "prop_cs_stock_book", "prop_cs_street_binbag_01", "prop_cs_street_card_01", "prop_cs_street_card_02", "prop_cs_sub_hook_01", "prop_cs_sub_rope_01", "prop_cs_swipe_card", "prop_cs_tablet", "prop_cs_tablet_02", "prop_cs_toaster", "prop_cs_trolley_01", "prop_cs_trowel", "prop_cs_truck_ladder", "prop_cs_tshirt_ball_01", "prop_cs_tv_stand", "prop_cs_t_shirt_pile", "prop_cs_valve", "prop_cs_vent_cover", "prop_cs_vial_01", "prop_cs_walkie_talkie", "prop_cs_walking_stick", "prop_cs_whiskey_bottle", "prop_cs_whiskey_bot_stop", "prop_cs_wrench", "prop_cub_door_lifeblurb", "prop_cub_lifeblurb", "prop_cuff_keys_01", "prop_cup_saucer_01", "prop_curl_bar_01", "prop_damdoor_01", "prop_dart_1", "prop_dart_2", "prop_dart_bd_01", "prop_dart_bd_cab_01", "prop_defilied_ragdoll_01", "prop_desert_iron_01", "prop_detergent_01a", "prop_detergent_01b", "prop_devin_box_01", "prop_devin_rope_01", "prop_diggerbkt_01", "prop_direct_chair_01", "prop_direct_chair_02", "prop_display_unit_01", "prop_display_unit_02", "prop_disp_cabinet_002", "prop_disp_cabinet_01", "prop_disp_razor_01", "prop_distantcar_day", "prop_distantcar_night", "prop_distantcar_truck", "prop_dj_deck_01", "prop_dj_deck_02", "prop_dock_ropefloat", "prop_dock_ropetyre1", "prop_dock_ropetyre2", "prop_dock_ropetyre3", "prop_dock_rtg_01", "prop_dock_rtg_ld", "prop_dock_shippad", "prop_dock_sign_01", "prop_dock_woodpole1", "prop_dock_woodpole2", "prop_dog_cage_01", "prop_dog_cage_02", "prop_dolly_01", "prop_dolly_02", "prop_donut_01", "prop_donut_02", "prop_donut_02b", "prop_door_01", "prop_door_balcony_frame", "prop_door_balcony_left", "prop_door_balcony_right", "prop_door_bell_01", "prop_double_grid_line", "prop_dress_disp_01", "prop_dress_disp_02", "prop_drop_armscrate_01", "prop_drop_armscrate_01b", "prop_drop_crate_01", "prop_drop_crate_01_set", "prop_drop_crate_01_set2", "prop_drug_burner", "prop_drug_package", "prop_drug_package_02", "prop_drywallpile_01", "prop_drywallpile_02", "prop_dt1_13_groundlight", "prop_dt1_13_walllightsource", "prop_dt1_20_mp_door_l", "prop_dt1_20_mp_door_r", "prop_dt1_20_mp_gar", "prop_ducktape_01", "prop_dummy_01", "prop_dummy_car", "prop_dummy_light", "prop_dummy_plane", "prop_dumpster_3a", "prop_dumpster_3step", "prop_dumpster_4a", "prop_dumpster_4b", "prop_d_balcony_l_light", "prop_d_balcony_r_light", "prop_ear_defenders_01", "prop_ecg_01", "prop_ecg_01_cable_01", "prop_ecg_01_cable_02", "prop_ecola_can", "prop_egg_clock_01", "prop_ejector_seat_01", "prop_elecbox_03a", "prop_elecbox_10", "prop_el_guitar_01", "prop_el_guitar_02", "prop_el_guitar_03", "prop_employee_month_01", "prop_employee_month_02", "prop_energy_drink", "prop_entityxf_covered", "prop_epsilon_door_l", "prop_epsilon_door_r", "prop_etricmotor_01", "prop_exer_bike_01", "prop_faceoffice_door_l", "prop_faceoffice_door_r", "prop_face_rag_01", "prop_facgate_01", "prop_facgate_01b", "prop_facgate_02pole", "prop_facgate_02_l", "prop_facgate_03post", "prop_facgate_08_frame", "prop_facgate_08_ld2", "prop_facgate_id1_27", "prop_fac_machine_02", "prop_fag_packet_01", "prop_fan_01", "prop_fan_palm_01a", "prop_fax_01", "prop_fbi3_coffee_table", "prop_fbibombbin", "prop_fbibombcupbrd", "prop_fbibombfile", "prop_fbibombplant", "prop_feeder1", "prop_feed_sack_01", "prop_feed_sack_02", "prop_fence_log_01", "prop_fence_log_02", "prop_ff_shelves_01", "prop_ff_sink_01", "prop_ff_sink_02", "prop_fib_badge", "prop_fib_broken_window", "prop_fib_skylight_piece", "prop_film_cam_01", "prop_fireescape_01a", "prop_fireescape_01b", "prop_fireescape_02a", "prop_fireescape_02b", "prop_fire_driser_1a", "prop_fire_hosereel", "prop_fishing_rod_01", "prop_fishing_rod_02", "prop_fish_slice_01", "prop_flagpole_1a", "prop_flagpole_2a", "prop_flagpole_3a", "prop_flare_01", "prop_flare_01b", "prop_flash_unit", "prop_flatbed_strap", "prop_flatbed_strap_b", "prop_flatscreen_overlay", "prop_flattrailer_01a", "prop_flattruck_01a", "prop_fleeca_atm", "prop_flight_box_01", "prop_flight_box_insert", "prop_flight_box_insert2", "prop_flipchair_01", "prop_floor_duster_01", "prop_fncconstruc_02a", "prop_fridge_03", "prop_front_seat_01", "prop_front_seat_02", "prop_front_seat_03", "prop_front_seat_04", "prop_front_seat_05", "prop_front_seat_06", "prop_front_seat_07", "prop_front_seat_row_01", "prop_fruitstand_b_nite", "prop_fruit_basket", "prop_ftowel_01", "prop_ftowel_07", "prop_ftowel_08", "prop_ftowel_10", "prop_f_b_insert_broken", "prop_f_duster_01_s", "prop_f_duster_02", "prop_gaffer_arm_bind", "prop_gaffer_arm_bind_cut", "prop_gaffer_leg_bind", "prop_gaffer_leg_bind_cut", "prop_gaffer_tape", "prop_gaffer_tape_strip", "prop_game_clock_01", "prop_game_clock_02", "prop_garden_dreamcatch_01", "prop_garden_edging_01", "prop_garden_edging_02", "prop_garden_zapper_01", "prop_gar_door_05_l", "prop_gar_door_05_r", "prop_gar_door_a_01", "prop_gar_door_plug", "prop_gascage01", "prop_gascyl_ramp_01", "prop_gascyl_ramp_door_01", "prop_gas_grenade", "prop_gas_mask_hang_01", "prop_gatecom_02", "prop_gate_airport_01", "prop_gate_bridge_ld", "prop_gate_cult_01_l", "prop_gate_cult_01_r", "prop_gate_docks_ld", "prop_gate_farm_01a", "prop_gate_farm_post", "prop_gate_frame_06", "prop_gate_military_01", "prop_gate_prison_01", "prop_gate_tep_01_l", "prop_gate_tep_01_r", "prop_gazebo_03", "prop_gd_ch2_08", "prop_generator_02a", "prop_generator_03a", "prop_generator_04", "prop_ghettoblast_02", "prop_girder_01a", "prop_glasscutter_01", "prop_glass_suck_holder", "prop_glf_roller", "prop_glf_spreader", "prop_gold_bar", "prop_gold_cont_01", "prop_gold_cont_01b", "prop_gold_trolly", "prop_gold_trolly_full", "prop_gold_trolly_strap_01", "prop_golf_bag_01", "prop_golf_bag_01b", "prop_golf_bag_01c", "prop_golf_ball", "prop_golf_ball_p2", "prop_golf_tee", "prop_golf_wood_01", "prop_grain_hopper", "prop_grapes_01", "prop_grapes_02", "prop_grass_dry_02", "prop_grass_dry_03", "prop_gravestones_01a", "prop_gravestones_02a", "prop_gravestones_03a", "prop_gravestones_04a", "prop_gravestones_05a", "prop_gravestones_06a", "prop_gravestones_07a", "prop_gravestones_08a", "prop_gravestones_09a", "prop_gravestones_10a", "prop_gravetomb_01a", "prop_gravetomb_02a", "prop_griddle_01", "prop_griddle_02", "prop_grumandoor_l", "prop_grumandoor_r", "prop_gshotsensor_01", "prop_gun_case_01", "prop_gun_case_02", "prop_gun_frame", "prop_hacky_sack_01", "prop_handdry_01", "prop_handdry_02", "prop_handrake", "prop_handtowels", "prop_hand_toilet", "prop_hanger_door_1", "prop_hard_hat_01", "prop_hat_box_01", "prop_hat_box_02", "prop_hat_box_03", "prop_hat_box_04", "prop_hat_box_05", "prop_hat_box_06", "prop_haybailer_01", "prop_haybale_01", "prop_haybale_02", "prop_haybale_stack_01", "prop_hd_seats_01", "prop_headphones_01", "prop_headset_01", "prop_hedge_trimmer_01", "prop_helipad_01", "prop_helipad_02", "prop_henna_disp_01", "prop_henna_disp_02", "prop_henna_disp_03", "prop_hifi_01", "prop_hobo_stove_01", "prop_hockey_bag_01", "prop_hole_plug_01", "prop_holster_01", "prop_homeless_matress_01", "prop_homeless_matress_02", "prop_hose_1", "prop_hose_2", "prop_hose_3", "prop_hose_nozzle", "prop_hospitaldoors_start", "prop_hospital_door_l", "prop_hospital_door_r", "prop_hotel_clock_01", "prop_hotel_trolley", "prop_hottub2", "prop_huf_rag_01", "prop_huge_display_01", "prop_huge_display_02", "prop_hunterhide", "prop_hw1_03_gardoor_01", "prop_hw1_04_door_l1", "prop_hw1_04_door_r1", "prop_hw1_23_door", "prop_hwbowl_pseat_6x1", "prop_hwbowl_seat_01", "prop_hwbowl_seat_02", "prop_hwbowl_seat_03", "prop_hwbowl_seat_03b", "prop_hwbowl_seat_6x6", "prop_hydro_platform_01", "prop_ice_box_01", "prop_ice_box_01_l1", "prop_ice_cube_01", "prop_ice_cube_02", "prop_ice_cube_03", "prop_id2_11_gdoor", "prop_id2_20_clock", "prop_idol_01", "prop_idol_01_error", "prop_idol_case", "prop_idol_case_01", "prop_idol_case_02", "prop_id_21_gardoor_01", "prop_id_21_gardoor_02", "prop_indus_meet_door_l", "prop_indus_meet_door_r", "prop_ind_barge_01", "prop_ind_barge_02", "prop_ind_coalcar_01", "prop_ind_coalcar_02", "prop_ind_coalcar_03", "prop_ind_conveyor_01", "prop_ind_conveyor_02", "prop_ind_conveyor_04", "prop_ind_crusher", "prop_ind_deiseltank", "prop_ind_light_01a", "prop_ind_light_01b", "prop_ind_light_01c", "prop_ind_mech_01c", "prop_ind_mech_02a", "prop_ind_mech_02b", "prop_ind_mech_03a", "prop_ind_mech_04a", "prop_ind_oldcrane", "prop_ind_washer_02", "prop_inflatearch_01", "prop_inflategate_01", "prop_ing_camera_01", "prop_ing_crowbar", "prop_inhaler_01", "prop_int_gate01", "prop_in_tray_01", "prop_irish_sign_01", "prop_irish_sign_02", "prop_irish_sign_03", "prop_irish_sign_04", "prop_irish_sign_05", "prop_irish_sign_06", "prop_irish_sign_07", "prop_irish_sign_08", "prop_irish_sign_09", "prop_irish_sign_10", "prop_irish_sign_11", "prop_irish_sign_12", "prop_irish_sign_13", "prop_iron_01", "prop_jb700_covered", "prop_jeans_01", "prop_jetski_ramp_01", "prop_jet_bloodsplat_01", "prop_jewel_02a", "prop_jewel_02b", "prop_jewel_02c", "prop_jewel_03a", "prop_jewel_03b", "prop_jewel_04a", "prop_jewel_04b", "prop_jewel_pickup_new_01", "prop_juice_dispenser", "prop_juice_pool_01", "prop_jukebox_01", "prop_jukebox_02", "prop_jyard_block_01a", "prop_j_disptray_01", "prop_j_disptray_01b", "prop_j_disptray_01_dam", "prop_j_disptray_02", "prop_j_disptray_02_dam", "prop_j_disptray_03", "prop_j_disptray_03_dam", "prop_j_disptray_04", "prop_j_disptray_04b", "prop_j_disptray_05", "prop_j_disptray_05b", "prop_j_heist_pic_01", "prop_j_heist_pic_02", "prop_j_heist_pic_03", "prop_j_heist_pic_04", "prop_j_neck_disp_01", "prop_j_neck_disp_02", "prop_j_neck_disp_03", "prop_kayak_01", "prop_kayak_01b", "prop_kebab_grill", "prop_keg_01", "prop_kettle", "prop_kettle_01", "prop_keyboard_01a", "prop_keyboard_01b", "prop_kino_light_01", "prop_kino_light_03", "prop_kitch_juicer", "prop_kitch_pot_fry", "prop_kitch_pot_huge", "prop_kitch_pot_lrg", "prop_kitch_pot_lrg2", "prop_kitch_pot_med", "prop_kitch_pot_sm", "prop_knife", "prop_knife_stand", "prop_kt1_06_door_l", "prop_kt1_06_door_r", "prop_kt1_10_mpdoor_l", "prop_kt1_10_mpdoor_r", "prop_ladel", "prop_laptop_02_closed", "prop_laptop_jimmy", "prop_laptop_lester", "prop_laptop_lester2", "prop_large_gold", "prop_large_gold_alt_a", "prop_large_gold_alt_b", "prop_large_gold_alt_c", "prop_large_gold_empty", "prop_lawnmower_01", "prop_ld_alarm_01", "prop_ld_alarm_01_dam", "prop_ld_alarm_alert", "prop_ld_ammo_pack_01", "prop_ld_ammo_pack_02", "prop_ld_ammo_pack_03", "prop_ld_armour", "prop_ld_balcfnc_01a", "prop_ld_balcfnc_02a", "prop_ld_balcfnc_02c", "prop_ld_bankdoors_02", "prop_ld_barrier_01", "prop_ld_binbag_01", "prop_ld_bomb", "prop_ld_bomb_01", "prop_ld_bomb_01_open", "prop_ld_bomb_anim", "prop_ld_cable", "prop_ld_cable_tie_01", "prop_ld_can_01", "prop_ld_case_01", "prop_ld_case_01_lod", "prop_ld_case_01_s", "prop_ld_contact_card", "prop_ld_container", "prop_ld_contain_dl", "prop_ld_contain_dl2", "prop_ld_contain_dr", "prop_ld_contain_dr2", "prop_ld_crate_01", "prop_ld_crate_lid_01", "prop_ld_crocclips01", "prop_ld_crocclips02", "prop_ld_dummy_rope", "prop_ld_fags_01", "prop_ld_fags_02", "prop_ld_fan_01", "prop_ld_fan_01_old", "prop_ld_faucet", "prop_ld_ferris_wheel", "prop_ld_fireaxe", "prop_ld_flow_bottle", "prop_ld_fragwall_01a", "prop_ld_garaged_01", "prop_ld_gold_tooth", "prop_ld_greenscreen_01", "prop_ld_handbag", "prop_ld_handbag_s", "prop_ld_hat_01", "prop_ld_haybail", "prop_ld_hdd_01", "prop_ld_health_pack", "prop_ld_hook", "prop_ld_int_safe_01", "prop_ld_jail_door", "prop_ld_jeans_01", "prop_ld_jeans_02", "prop_ld_jerrycan_01", "prop_ld_keypad_01", "prop_ld_keypad_01b", "prop_ld_keypad_01b_lod", "prop_ld_lap_top", "prop_ld_monitor_01", "prop_ld_peep_slider", "prop_ld_pipe_single_01", "prop_ld_planning_pin_01", "prop_ld_planning_pin_02", "prop_ld_planning_pin_03", "prop_ld_purse_01", "prop_ld_purse_01_lod", "prop_ld_rail_01", "prop_ld_rail_02", "prop_ld_rope_t", "prop_ld_rubble_01", "prop_ld_rubble_02", "prop_ld_rubble_03", "prop_ld_rubble_04", "prop_ld_rub_binbag_01", "prop_ld_scrap", "prop_ld_shirt_01", "prop_ld_shoe_01", "prop_ld_shoe_02", "prop_ld_shovel", "prop_ld_shovel_dirt", "prop_ld_snack_01", "prop_ld_suitcase_01", "prop_ld_suitcase_02", "prop_ld_test_01", "prop_ld_toilet_01", "prop_ld_tooth", "prop_ld_tshirt_01", "prop_ld_tshirt_02", "prop_ld_vault_door", "prop_ld_wallet_01", "prop_ld_wallet_01_s", "prop_ld_wallet_02", "prop_ld_wallet_pickup", "prop_ld_w_me_machette", "prop_leaf_blower_01", "prop_lectern_01", "prop_letterbox_04", "prop_lev_crate_01", "prop_lev_des_barge_01", "prop_lev_des_barge_02", "prop_lifeblurb_01", "prop_lifeblurb_01b", "prop_lifeblurb_02", "prop_lifeblurb_02b", "prop_life_ring_02", "prop_lift_overlay_01", "prop_lift_overlay_02", "prop_litter_picker", "prop_loggneon", "prop_logpile_05", "prop_logpile_06", "prop_logpile_06b", "prop_logpile_07", "prop_logpile_07b", "prop_log_01", "prop_log_02", "prop_log_03", "prop_loose_rag_01", "prop_lrggate_01c_l", "prop_lrggate_01c_r", "prop_lrggate_01_l", "prop_lrggate_01_pst", "prop_lrggate_01_r", "prop_lrggate_02_ld", "prop_lrggate_03a", "prop_lrggate_03b", "prop_lrggate_03b_ld", "prop_lrggate_04a", "prop_lrggate_05a", "prop_lrggate_06a", "prop_luggage_01a", "prop_luggage_02a", "prop_luggage_03a", "prop_luggage_04a", "prop_luggage_05a", "prop_luggage_06a", "prop_luggage_07a", "prop_luggage_08a", "prop_luggage_09a", "prop_magenta_door", "prop_makeup_trail_01", "prop_makeup_trail_02", "prop_map_door_01", "prop_mast_01", "prop_mat_box", "prop_mb_cargo_01a", "prop_mb_cargo_02a", "prop_mb_cargo_03a", "prop_mb_cargo_04a", "prop_mb_cargo_04b", "prop_mb_crate_01a", "prop_mb_crate_01a_set", "prop_mb_crate_01b", "prop_mb_hesco_06", "prop_mb_ordnance_01", "prop_mb_ordnance_03", "prop_mb_sandblock_01", "prop_mb_sandblock_02", "prop_mb_sandblock_03", "prop_mb_sandblock_04", "prop_mb_sandblock_05", "prop_medal_01", "prop_medstation_02", "prop_medstation_03", "prop_medstation_04", "prop_med_bag_01", "prop_med_bag_01b", "prop_med_jet_01", "prop_megaphone_01", "prop_mem_candle_04", "prop_mem_candle_05", "prop_mem_candle_06", "prop_mem_reef_01", "prop_mem_reef_02", "prop_mem_reef_03", "prop_mem_teddy_01", "prop_mem_teddy_02", "prop_metalfoodjar_01", "prop_metal_plates01", "prop_metal_plates02", "prop_meth_bag_01", "prop_michaels_credit_tv", "prop_michael_backpack", "prop_michael_balaclava", "prop_michael_door", "prop_michael_sec_id", "prop_microphone_02", "prop_microwave_1", "prop_micro_01", "prop_micro_02", "prop_micro_cs_01", "prop_micro_cs_01_door", "prop_military_pickup_01", "prop_mil_crate_01", "prop_mil_crate_02", "prop_minigun_01", "prop_mobile_mast_1", "prop_mobile_mast_2", "prop_money_bag_01","prop_monitor_01c", "prop_monitor_01d", "prop_monitor_02", "prop_monitor_03b", "prop_motel_door_09", "prop_mouse_01", "prop_mouse_01a", "prop_mouse_01b", "prop_mouse_02", "prop_movie_rack", "prop_mp3_dock", "prop_mp_arrow_barrier_01", "prop_mp_barrier_01", "prop_mp_barrier_01b", "prop_mp_barrier_02", "prop_mp_barrier_02b", "prop_mp_base_marker", "prop_mp_boost_01", "prop_mp_cant_place_lrg", "prop_mp_cant_place_med", "prop_mp_cant_place_sm", "prop_mp_cone_01", "prop_mp_cone_02", "prop_mp_cone_03", "prop_mp_cone_04", "prop_mp_drug_package", "prop_mp_drug_pack_blue", "prop_mp_drug_pack_red", "prop_mp_icon_shad_lrg", "prop_mp_icon_shad_med", "prop_mp_icon_shad_sm", "prop_mp_max_out_lrg", "prop_mp_max_out_med", "prop_mp_max_out_sm", "prop_mp_num_0", "prop_mp_num_1", "prop_mp_num_2", "prop_mp_num_3", "prop_mp_num_4", "prop_mp_num_5", "prop_mp_num_6", "prop_mp_num_7", "prop_mp_num_8", "prop_mp_num_9", "prop_mp_placement", "prop_mp_placement_lrg", "prop_mp_placement_maxd", "prop_mp_placement_med", "prop_mp_placement_red", "prop_mp_placement_sm", "prop_mp_ramp_01", "prop_mp_ramp_02", "prop_mp_repair", "prop_mp_repair_01", "prop_mp_respawn_02", "prop_mp_rocket_01", "prop_mp_spike_01", "prop_mr_rasberryclean", "prop_mr_raspberry_01", "prop_muscle_bench_01", "prop_muscle_bench_02", "prop_muscle_bench_03", "prop_muscle_bench_04", "prop_muscle_bench_05", "prop_muscle_bench_06", "prop_muster_wboard_01", "prop_muster_wboard_02", "prop_m_pack_int_01", "prop_necklace_board", "prop_news_disp_02a_s", "prop_new_drug_pack_01", "prop_nigel_bag_pickup", "prop_night_safe_01", "prop_notepad_01", "prop_notepad_02", "prop_novel_01", "prop_npc_phone", "prop_npc_phone_02", "prop_office_alarm_01", "prop_office_desk_01", "prop_offroad_bale01", "prop_offroad_bale02_l1_frag_", "prop_offroad_barrel01", "prop_offroad_tyres01", "prop_off_chair_01", "prop_off_chair_03", "prop_off_chair_04", "prop_off_chair_04b", "prop_off_chair_04_s", "prop_off_chair_05", "prop_off_phone_01", "prop_oiltub_01", "prop_oiltub_02", "prop_oiltub_03", "prop_oiltub_05", "prop_oiltub_06", "prop_oil_derrick_01", "prop_oil_guage_01", "prop_oil_spool_02", "prop_oil_valve_01", "prop_oil_valve_02", "prop_oil_wellhead_01", "prop_oil_wellhead_03", "prop_oil_wellhead_04", "prop_oil_wellhead_05", "prop_oil_wellhead_06", "prop_oldplough1", "prop_old_boot", "prop_old_churn_01", "prop_old_churn_02", "prop_old_deck_chair", "prop_old_deck_chair_02", "prop_old_farm_01", "prop_old_farm_02", "prop_old_wood_chair", "prop_old_wood_chair_lod", "prop_orang_can_01", "prop_outdoor_fan_01", "prop_out_door_speaker", "prop_overalls_01", "prop_owl_totem_01", "prop_paints_can01", "prop_paints_can02", "prop_paints_can03", "prop_paints_can04", "prop_paints_can05", "prop_paints_can06", "prop_paints_can07", "prop_paint_brush01", "prop_paint_brush02", "prop_paint_brush03", "prop_paint_brush04", "prop_paint_brush05", "prop_paint_roller", "prop_paint_spray01a", "prop_paint_spray01b", "prop_paint_stepl01", "prop_paint_stepl01b", "prop_paint_stepl02", "prop_paint_tray", "prop_paint_wpaper01", "prop_pallettruck_01", "prop_palm_fan_02_a", "prop_palm_fan_02_b", "prop_palm_fan_03_a", "prop_palm_fan_03_b", "prop_palm_fan_03_c", "prop_palm_fan_03_d", "prop_palm_fan_04_a", "prop_palm_fan_04_b", "prop_palm_fan_04_c", "prop_palm_fan_04_d", "prop_palm_huge_01a", "prop_palm_huge_01b", "prop_palm_med_01a", "prop_palm_med_01b", "prop_palm_med_01c", "prop_palm_med_01d", "prop_palm_sm_01a", "prop_palm_sm_01d", "prop_palm_sm_01e", "prop_palm_sm_01f", "prop_paper_bag_01", "prop_paper_bag_small", "prop_paper_ball", "prop_paper_box_01", "prop_paper_box_02", "prop_paper_box_03", "prop_paper_box_04", "prop_paper_box_05", "prop_pap_camera_01", "prop_parachute", "prop_parapack_01", "prop_parasol_01", "prop_parasol_01_b", "prop_parasol_01_c", "prop_parasol_01_down", "prop_parasol_02", "prop_parasol_02_b", "prop_parasol_02_c", "prop_parasol_03", "prop_parasol_03_b", "prop_parasol_03_c", "prop_parasol_04e", "prop_parasol_04e_lod1", "prop_parasol_bh_48", "prop_parking_sign_06", "prop_parking_sign_07", "prop_parking_sign_1", "prop_parking_sign_2", "prop_parking_wand_01", "prop_park_ticket_01", "prop_partsbox_01", "prop_passport_01", "prop_patio_heater_01", "prop_patio_lounger1", "prop_patio_lounger1b", "prop_patio_lounger1_table", "prop_patio_lounger_2", "prop_patio_lounger_3", "prop_patriotneon", "prop_paynspray_door_l", "prop_paynspray_door_r", "prop_pc_01a", "prop_pc_02a", "prop_peanut_bowl_01", "prop_ped_pic_01", "prop_ped_pic_01_sm", "prop_ped_pic_02", "prop_ped_pic_02_sm", "prop_ped_pic_03", "prop_ped_pic_03_sm", "prop_ped_pic_04", "prop_ped_pic_04_sm", "prop_ped_pic_05", "prop_ped_pic_05_sm", "prop_ped_pic_06", "prop_ped_pic_06_sm", "prop_ped_pic_07", "prop_ped_pic_07_sm", "prop_ped_pic_08", "prop_ped_pic_08_sm", "prop_pencil_01", "prop_pharm_sign_01", "prop_phonebox_05a", "prop_phone_ing", "prop_phone_ing_02", "prop_phone_ing_03", "prop_phone_overlay_01", "prop_phone_overlay_02", "prop_phone_overlay_anim", "prop_phone_proto", "prop_phone_proto_back", "prop_phone_proto_battery", "prop_picnictable_02", "prop_piercing_gun", "prop_pier_kiosk_01", "prop_pier_kiosk_02", "prop_pier_kiosk_03", "prop_pile_dirt_01", "prop_pile_dirt_02", "prop_pile_dirt_03", "prop_pile_dirt_04", "prop_pile_dirt_06", "prop_pile_dirt_07", "prop_ping_pong", "prop_pipes_01a", "prop_pipes_01b", "prop_pipes_03b", "prop_pipes_04a", "prop_pipes_05a", "prop_pipes_conc_01", "prop_pipes_conc_02", "prop_pipe_single_01", "prop_pistol_holster", "prop_pitcher_01_cs", "prop_pizza_box_01", "prop_pizza_box_02", "prop_pizza_oven_01", "prop_planer_01", "prop_plant_01a", "prop_plant_01b", "prop_plant_base_01", "prop_plant_base_02", "prop_plant_base_03", "prop_plant_cane_01a", "prop_plant_cane_01b", "prop_plant_cane_02a", "prop_plant_cane_02b", "prop_plant_clover_01", "prop_plant_clover_02", "prop_plant_fern_01a", "prop_plant_fern_01b", "prop_plant_fern_02a", "prop_plant_fern_02b", "prop_plant_fern_02c", "prop_plant_flower_01", "prop_plant_flower_02", "prop_plant_flower_03", "prop_plant_flower_04", "prop_plant_group_01", "prop_plant_group_02", "prop_plant_group_03", "prop_plant_group_04", "prop_plant_group_05", "prop_plant_group_05b", "prop_plant_group_05c", "prop_plant_group_05d", "prop_plant_group_06a", "prop_plant_group_06b", "prop_plant_group_06c", "prop_plant_int_02a", "prop_plant_int_02b", "prop_plant_int_05a", "prop_plant_int_05b", "prop_plant_int_06a", "prop_plant_int_06b", "prop_plant_int_06c", "prop_plant_paradise", "prop_plant_paradise_b", "prop_plastic_cup_02", "prop_plas_barier_01a", "prop_plate_04", "prop_plate_stand_01", "prop_plate_warmer", "prop_player_gasmask", "prop_player_phone_01", "prop_player_phone_02", "prop_pliers_01", "prop_plywoodpile_01a", "prop_plywoodpile_01b", "prop_podium_mic", "prop_police_door_l", "prop_police_door_l_dam", "prop_police_door_r", "prop_police_door_r_dam", "prop_police_door_surround", "prop_police_phone", "prop_police_radio_handset", "prop_police_radio_main", "prop_poly_bag_01", "prop_poly_bag_money", "prop_poolball_1", "prop_poolball_10", "prop_poolball_11", "prop_poolball_12", "prop_poolball_13", "prop_poolball_14", "prop_poolball_15", "prop_poolball_2", "prop_poolball_3", "prop_poolball_4", "prop_poolball_5", "prop_poolball_6", "prop_poolball_7", "prop_poolball_8", "prop_poolball_9", "prop_poolball_cue", "prop_poolskimmer", "prop_pooltable_02", "prop_pooltable_3b", "prop_pool_ball_01", "prop_pool_cue", "prop_pool_rack_01", "prop_pool_rack_02", "prop_pool_tri", "prop_porn_mag_01", "prop_porn_mag_02", "prop_porn_mag_03", "prop_porn_mag_04", "prop_portable_hifi_01", "prop_portacabin01", "prop_portasteps_01", "prop_portasteps_02", "prop_postcard_rack", "prop_poster_tube_01", "prop_poster_tube_02", "prop_postit_drive", "prop_postit_gun", "prop_postit_it", "prop_postit_lock", "prop_potatodigger", "prop_pot_01", "prop_pot_02", "prop_pot_03", "prop_pot_04", "prop_pot_05", "prop_pot_06", "prop_pot_plant_02a", "prop_pot_plant_02b", "prop_pot_plant_02c", "prop_pot_plant_02d", "prop_pot_plant_03a", "prop_pot_plant_04a", "prop_pot_plant_05d_l1", "prop_pot_plant_bh1", "prop_pot_rack", "prop_power_cell", "prop_power_cord_01", "prop_premier_fence_01", "prop_premier_fence_02", "prop_printer_01", "prop_printer_02", "prop_pris_bars_01", "prop_pris_bench_01", "prop_pris_door_01_l", "prop_pris_door_01_r", "prop_pris_door_02", "prop_pris_door_03", "prop_prlg_gravestone_05a_l1", "prop_prlg_gravestone_06a", "prop_projector_overlay", "prop_prologue_phone", "prop_prop_tree_01", "prop_prop_tree_02", "prop_protest_sign_01", "prop_protest_table_01", "prop_prototype_minibomb", "prop_proxy_chateau_table", "prop_punch_bag_l", "prop_pylon_01", "prop_pylon_02", "prop_pylon_03", "prop_pylon_04", "prop_p_jack_03_col", "prop_p_spider_01a", "prop_p_spider_01c", "prop_p_spider_01d", "prop_ql_revolving_door", "prop_quad_grid_line", "prop_radiomast01", "prop_radiomast02", "prop_rad_waste_barrel_01", "prop_ragganeon", "prop_rag_01", "prop_railsleepers01", "prop_railsleepers02", "prop_railstack01", "prop_railstack02", "prop_railstack03", "prop_railstack04", "prop_railstack05", "prop_rail_boxcar", "prop_rail_boxcar2", "prop_rail_boxcar3", "prop_rail_boxcar4", "prop_rail_boxcar5", "prop_rail_boxcar5_d", "prop_rail_buffer_01", "prop_rail_buffer_02", "prop_rail_controller", "prop_rail_crane_01", "prop_rail_points01", "prop_rail_points02", "prop_rail_sigbox01", "prop_rail_sigbox02", "prop_rail_signals02", "prop_rail_tankcar", "prop_rail_tankcar2", "prop_rail_tankcar3", "prop_rail_wellcar", "prop_rail_wellcar2", "prop_range_target_01", "prop_range_target_02", "prop_range_target_03", "prop_rebar_pile01", "prop_recyclebin_02a", "prop_recyclebin_02b", "prop_recyclebin_02_c", "prop_recyclebin_02_d", "prop_recyclebin_03_a", "prop_recyclebin_04_a", "prop_recyclebin_04_b", "prop_recyclebin_05_a", "prop_ret_door", "prop_ret_door_02", "prop_ret_door_03", "prop_ret_door_04", "prop_rf_conc_pillar", "prop_riding_crop_01", "prop_riot_shield", "prop_rio_del_01", "prop_roadcone01a", "prop_roadcone01b", "prop_roadcone01c", "prop_roadcone02a", "prop_roadcone02b", "prop_roadcone02c", "prop_roadheader_01", "prop_rock_1_a", "prop_rock_1_b", "prop_rock_1_c", "prop_rock_1_d", "prop_rock_1_e", "prop_rock_1_f", "prop_rock_1_g", "prop_rock_1_h", "prop_rock_1_i", "prop_rock_2_a", "prop_rock_2_c", "prop_rock_2_d", "prop_rock_2_f", "prop_rock_2_g", "prop_rock_3_a", "prop_rock_3_b", "prop_rock_3_c", "prop_rock_3_d", "prop_rock_3_e", "prop_rock_3_f", "prop_rock_3_g", "prop_rock_3_h", "prop_rock_3_i", "prop_rock_3_j", "prop_rock_4_c", "prop_rock_4_d", "prop_rock_chair_01", "prop_rolled_sock_01", "prop_rolled_sock_02", "prop_rolled_yoga_mat", "prop_roller_car_01", "prop_roller_car_02", "prop_ron_door_01", "prop_roofpipe_01", "prop_roofpipe_02", "prop_roofpipe_03", "prop_roofpipe_04", "prop_roofpipe_05", "prop_roofpipe_06", "prop_roofvent_011a", "prop_roofvent_01a", "prop_roofvent_01b", "prop_roofvent_02a", "prop_roofvent_02b", "prop_roofvent_03a", "prop_roofvent_04a", "prop_roofvent_05a", "prop_roofvent_05b", "prop_roofvent_07a", "prop_roofvent_08a", "prop_roofvent_09a", "prop_roofvent_10a", "prop_roofvent_10b", "prop_roofvent_11b", "prop_roofvent_11c", "prop_roofvent_12a", "prop_roofvent_13a", "prop_roofvent_15a", "prop_roofvent_16a", "prop_rope_family_3", "prop_rope_hook_01", "prop_roundbailer01", "prop_roundbailer02", "prop_rub_bike_01", "prop_rub_bike_02", "prop_rub_bike_03", "prop_rub_binbag_sd_01", "prop_rub_binbag_sd_02", "prop_rub_busdoor_01", "prop_rub_busdoor_02", "prop_rub_buswreck_01", "prop_rub_buswreck_03", "prop_rub_buswreck_06", "prop_rub_cabinet", "prop_rub_cabinet01", "prop_rub_cabinet02", "prop_rub_cabinet03", "prop_rub_cage01a", "prop_rub_carpart_02", "prop_rub_carpart_03", "prop_rub_carpart_04", "prop_rub_chassis_01", "prop_rub_chassis_02", "prop_rub_chassis_03", "prop_rub_cont_01a", "prop_rub_cont_01b", "prop_rub_cont_01c", "prop_rub_flotsam_01", "prop_rub_flotsam_02", "prop_rub_flotsam_03", "prop_rub_frklft", "prop_rub_litter_01", "prop_rub_litter_02", "prop_rub_litter_03", "prop_rub_litter_03b", "prop_rub_litter_03c", "prop_rub_litter_04", "prop_rub_litter_04b", "prop_rub_litter_05", "prop_rub_litter_06", "prop_rub_litter_07", "prop_rub_litter_09", "prop_rub_litter_8", "prop_rub_matress_01", "prop_rub_matress_02", "prop_rub_matress_03", "prop_rub_matress_04", "prop_rub_monitor", "prop_rub_pile_01", "prop_rub_pile_02", "prop_rub_planks_01", "prop_rub_planks_02", "prop_rub_planks_03", "prop_rub_planks_04", "prop_rub_railwreck_1", "prop_rub_railwreck_2", "prop_rub_railwreck_3", "prop_rub_scrap_02", "prop_rub_scrap_03", "prop_rub_scrap_04", "prop_rub_scrap_05", "prop_rub_scrap_06", "prop_rub_scrap_07", "prop_rub_stool", "prop_rub_sunktyre", "prop_rub_t34", "prop_rub_trainers_01", "prop_rub_trolley01a", "prop_rub_trolley02a", "prop_rub_trolley03a", "prop_rub_trukwreck_1", "prop_rub_trukwreck_2", "prop_rub_tyre_01", "prop_rub_tyre_02", "prop_rub_tyre_03", "prop_rub_tyre_dam1", "prop_rub_tyre_dam2", "prop_rub_tyre_dam3", "prop_rub_washer_01", "prop_rub_wheel_01", "prop_rub_wheel_02", "prop_rub_wreckage_3", "prop_rub_wreckage_4", "prop_rub_wreckage_5", "prop_rub_wreckage_6", "prop_rub_wreckage_7", "prop_rub_wreckage_8", "prop_rub_wreckage_9", "prop_rural_windmill_l1", "prop_rural_windmill_l2", "prop_rus_olive", "prop_rus_olive_wint", "prop_sacktruck_01", "prop_sacktruck_02a", "prop_safety_glasses", "prop_sam_01", "prop_sandwich_01", "prop_satdish_2_a", "prop_satdish_2_f", "prop_satdish_2_g", "prop_satdish_3_b", "prop_satdish_3_c", "prop_satdish_3_d", "prop_satdish_l_01", "prop_satdish_s_03", "prop_satdish_s_05a", "prop_satdish_s_05b", "prop_sc1_06_gate_l", "prop_sc1_06_gate_r", "prop_sc1_12_door", "prop_sc1_21_g_door_01", "prop_scaffold_pole", "prop_scafold_01a", "prop_scafold_01c", "prop_scafold_01f", "prop_scafold_02a", "prop_scafold_02c", "prop_scafold_03a", "prop_scafold_03b", "prop_scafold_03c", "prop_scafold_03f", "prop_scafold_04a", "prop_scafold_05a", "prop_scafold_06a", "prop_scafold_06b", "prop_scafold_06c", "prop_scafold_07a", "prop_scafold_08a", "prop_scafold_09a", "prop_scafold_frame1a", "prop_scafold_frame1b", "prop_scafold_frame1c", "prop_scafold_frame1f", "prop_scafold_frame2a", "prop_scafold_frame2b", "prop_scafold_frame2c", "prop_scafold_frame3a", "prop_scafold_frame3c", "prop_scafold_rail_01", "prop_scafold_rail_02", "prop_scafold_rail_03", "prop_scafold_xbrace", "prop_scalpel", "prop_scn_police_torch", "prop_scourer_01", "prop_scrap_2_crate", "prop_scrap_win_01", "prop_scrim_01", "prop_scythemower", "prop_section_garage_01", "prop_securityvan_lightrig", "prop_security_case_01", "prop_security_case_02", "prop_sec_gate_01b", "prop_sec_gate_01c", "prop_sec_gate_01d", "prop_set_generator_01", "prop_sewing_fabric", "prop_sewing_machine", "prop_sglasses_stand_01", "prop_sglasses_stand_02", "prop_sglasses_stand_02b", "prop_sglasses_stand_03", "prop_sglasss_1b_lod", "prop_sglasss_1_lod", "prop_shamal_crash", "prop_shelves_01", "prop_shelves_02", "prop_shelves_03", "prop_shopping_bags01", "prop_shopping_bags02", "prop_shop_front_door_l", "prop_shop_front_door_r", "prop_shots_glass_cs", "prop_shower_01", "prop_shower_rack_01", "prop_shower_towel", "prop_showroom_door_l", "prop_showroom_door_r", "prop_showroom_glass_1b", "prop_shredder_01", "prop_shrub_rake", "prop_shuttering01", "prop_shuttering02", "prop_shuttering03", "prop_shuttering04", "prop_sh_beer_pissh_01", "prop_sh_bong_01", "prop_sh_cigar_01", "prop_sh_joint_01", "prop_sh_mr_rasp_01", "prop_sh_shot_glass", "prop_sh_tall_glass", "prop_sh_tt_fridgedoor", "prop_sh_wine_glass", "prop_side_lights", "prop_side_spreader", "prop_sign_airp_01a", "prop_sign_airp_02a", "prop_sign_airp_02b", "prop_sign_big_01", "prop_sign_mallet", "prop_sign_road_04g_l1", "prop_single_grid_line", "prop_single_rose", "prop_sink_01", "prop_sink_02", "prop_sink_03", "prop_sink_04", "prop_sink_05", "prop_sink_06", "prop_skate_flatramp", "prop_skate_funbox", "prop_skate_halfpipe", "prop_skate_kickers", "prop_skate_quartpipe", "prop_skate_rail", "prop_skate_spiner", "prop_skid_chair_01", "prop_skid_chair_02", "prop_skid_chair_03", "prop_skid_sleepbag_1", "prop_skid_tent_01", "prop_skid_tent_01b", "prop_skid_tent_03", "prop_skip_01a", "prop_skip_02a", "prop_skip_03", "prop_skip_04", "prop_skip_05a", "prop_skip_05b", "prop_skip_06a", "prop_skip_08a", "prop_skip_08b", "prop_skip_10a", "prop_skip_rope_01", "prop_skunk_bush_01", "prop_skylight_01", "prop_skylight_02", "prop_skylight_03", "prop_skylight_04", "prop_skylight_05", "prop_skylight_06a", "prop_skylight_06b", "prop_skylight_06c", "prop_sky_cover_01", "prop_slacks_01", "prop_slacks_02", "prop_sluicegate", "prop_sluicegatel", "prop_sluicegater", "prop_slush_dispenser", "prop_sm1_11_doorl", "prop_sm1_11_doorr", "prop_sm1_11_garaged", "prop_smg_holster_01", "prop_sm_10_mp_door", "prop_sm_14_mp_gar", "prop_sm_19_clock", "prop_sm_27_door", "prop_sm_27_gate", "prop_sm_27_gate_02", "prop_sm_27_gate_03", "prop_sm_27_gate_04", "prop_sm_locker_door", "prop_snow_bailer_01", "prop_snow_barrel_pile_03", "prop_snow_bench_01", "prop_snow_bin_01", "prop_snow_bin_02", "prop_snow_bush_01_a", "prop_snow_bush_02_a", "prop_snow_bush_02_b", "prop_snow_bush_03", "prop_snow_bush_04", "prop_snow_bush_04b", "prop_snow_cam_03", "prop_snow_cam_03a", "prop_snow_diggerbkt_01", "prop_snow_dumpster_01", "prop_snow_elecbox_16", "prop_snow_facgate_01", "prop_snow_field_01", "prop_snow_field_02", "prop_snow_field_03", "prop_snow_field_04", "prop_snow_flower_01", "prop_snow_flower_02", "prop_snow_fnclink_03crnr2", "prop_snow_fnclink_03h", "prop_snow_fnclink_03i", "prop_snow_fncwood_14a", "prop_snow_fncwood_14b", "prop_snow_fncwood_14c", "prop_snow_fncwood_14d", "prop_snow_fncwood_14e", "prop_snow_fnc_01", "prop_snow_gate_farm_03", "prop_snow_grain_01", "prop_snow_grass_01", "prop_snow_light_01", "prop_snow_oldlight_01b", "prop_snow_rail_signals02", "prop_snow_rub_trukwreck_2", "prop_snow_side_spreader_01", "prop_snow_streetlight01", "prop_snow_streetlight_01_frag_", "prop_snow_sub_frame_01a", "prop_snow_sub_frame_04b", "prop_snow_telegraph_01a", "prop_snow_telegraph_02a", "prop_snow_telegraph_03", "prop_snow_traffic_rail_1a", "prop_snow_traffic_rail_1b", "prop_snow_trailer01", "prop_snow_tree_03_e", "prop_snow_tree_03_h", "prop_snow_tree_03_i", "prop_snow_tree_04_d", "prop_snow_tree_04_f", "prop_snow_truktrailer_01a", "prop_snow_tyre_01", "prop_snow_t_ml_01", "prop_snow_t_ml_02", "prop_snow_t_ml_03", "prop_snow_wall_light_15a", "prop_snow_watertower01", "prop_snow_watertower01_l2", "prop_snow_watertower03", "prop_snow_woodpile_04a", "prop_soap_disp_01", "prop_soap_disp_02", "prop_solarpanel_01", "prop_solarpanel_02", "prop_solarpanel_03", "prop_sol_chair", "prop_space_pistol", "prop_space_rifle", "prop_speaker_01", "prop_speaker_02", "prop_speaker_03", "prop_speaker_05", "prop_speaker_06", "prop_speaker_07", "prop_speaker_08", "prop_speedball_01", "prop_sponge_01", "prop_sports_clock_01", "prop_spot_01", "prop_spot_clamp", "prop_spot_clamp_02", "prop_sprayer", "prop_spraygun_01", "prop_spray_backpack_01", "prop_spray_jackframe", "prop_spray_jackleg", "prop_sprink_crop_01", "prop_sprink_golf_01", "prop_sprink_park_01", "prop_spycam", "prop_squeegee", "prop_ss1_05_mp_door", "prop_ss1_08_mp_door_l", "prop_ss1_08_mp_door_r", "prop_ss1_10_door_l", "prop_ss1_10_door_r", "prop_ss1_14_garage_door", "prop_ss1_mpint_door_l", "prop_ss1_mpint_door_r", "prop_ss1_mpint_garage", "prop_ss1_mpint_garage_cl", "prop_stag_do_rope", "prop_start_finish_line_01", "prop_start_grid_01", "prop_staticmixer_01", "prop_stat_pack_01", "prop_steam_basket_01", "prop_steam_basket_02", "prop_steps_big_01", "prop_stickbfly", "prop_stickhbird", "prop_still", "prop_stockade_wheel", "prop_stockade_wheel_flat", "prop_stool_01", "prop_storagetank_01", "prop_storagetank_02", "prop_storagetank_03", "prop_storagetank_03a", "prop_storagetank_03b", "prop_storagetank_04", "prop_storagetank_05", "prop_storagetank_06", "prop_storagetank_07a", "prop_stripmenu", "prop_strip_door_01", "prop_strip_pole_01", "prop_studio_light_02", "prop_studio_light_03", "prop_sub_chunk_01", "prop_sub_cover_01", "prop_sub_crane_hook", "prop_sub_frame_01a", "prop_sub_frame_01b", "prop_sub_frame_01c", "prop_sub_frame_02a", "prop_sub_frame_03a", "prop_sub_frame_04a", "prop_sub_frame_04b", "prop_sub_gantry", "prop_sub_release", "prop_sub_trans_01a", "prop_sub_trans_02a", "prop_sub_trans_03a", "prop_sub_trans_04a", "prop_sub_trans_05b", "prop_sub_trans_06b", "prop_suitcase_01", "prop_suitcase_01b", "prop_suitcase_01c", "prop_suitcase_01d", "prop_suitcase_02", "prop_suitcase_03", "prop_suitcase_03b", "prop_surf_board_ldn_01", "prop_surf_board_ldn_02", "prop_surf_board_ldn_03", "prop_surf_board_ldn_04", "prop_syringe_01", "prop_s_pine_dead_01", "prop_tablesaw_01", "prop_tablesmall_01", "prop_table_02", "prop_table_03b_cs", "prop_table_04", "prop_table_04_chr", "prop_table_05", "prop_table_05_chr", "prop_table_06", "prop_table_06_chr", "prop_table_07", "prop_table_07_l1", "prop_table_08", "prop_table_08_chr", "prop_table_08_side", "prop_table_mic_01", "prop_table_para_comb_04", "prop_table_tennis", "prop_table_ten_bat", "prop_taco_01", "prop_taco_02", "prop_tail_gate_col", "prop_tapeplayer_01", "prop_target_arm", "prop_target_arm_b", "prop_target_arm_long", "prop_target_arm_sm", "prop_target_backboard", "prop_target_backboard_b", "prop_target_blue", "prop_target_blue_arrow", "prop_target_bull", "prop_target_bull_b", "prop_target_comp_metal", "prop_target_comp_wood", "prop_target_frame_01", "prop_target_inner1", "prop_target_inner2", "prop_target_inner2_b", "prop_target_inner3", "prop_target_inner3_b", "prop_target_inner_b", "prop_target_orange_arrow", "prop_target_oran_cross", "prop_target_ora_purp_01", "prop_target_purp_arrow", "prop_target_purp_cross", "prop_target_red", "prop_target_red_arrow", "prop_target_red_blue_01", "prop_target_red_cross", "prop_tarp_strap", "prop_taxi_meter_1", "prop_taxi_meter_2", "prop_tea_trolly", "prop_tea_urn", "prop_telegraph_01a", "prop_telegraph_01b", "prop_telegraph_01c", "prop_telegraph_01d", "prop_telegraph_01e", "prop_telegraph_01f", "prop_telegraph_01g", "prop_telegraph_02a", "prop_telegraph_02b", "prop_telegraph_03", "prop_telegraph_04a", "prop_telegraph_04b", "prop_telegraph_05a", "prop_telegraph_05b", "prop_telegraph_05c", "prop_telegraph_06a", "prop_telegraph_06b", "prop_telegraph_06c", "prop_telegwall_01a", "prop_telegwall_01b", "prop_telegwall_02a", "prop_telegwall_03a", "prop_telegwall_03b", "prop_telegwall_04a", "prop_telescope", "prop_telescope_01", "prop_temp_block_blocker", "prop_tennis_bag_01", "prop_tennis_ball", "prop_tennis_ball_lobber", "prop_tennis_rack_01", "prop_tennis_rack_01b", "prop_test_boulder_01", "prop_test_boulder_02", "prop_test_boulder_03", "prop_test_boulder_04", "prop_test_elevator", "prop_test_elevator_dl", "prop_test_elevator_dr", "prop_tick", "prop_tick_02", "prop_till_01_dam", "prop_till_02", "prop_till_03", "prop_time_capsule_01", "prop_tint_towel", "prop_tint_towels_01", "prop_tint_towels_01b", "prop_toaster_01", "prop_toaster_02", "prop_toiletfoot_static", "prop_toilet_01", "prop_toilet_02", "prop_toilet_03", "prop_toilet_brush_01", "prop_toilet_cube_01", "prop_toilet_cube_02", "prop_toilet_roll_01", "prop_toilet_roll_02", "prop_toilet_roll_03", "prop_toilet_roll_04", "prop_toilet_roll_05", "prop_toilet_shamp_01", "prop_toilet_shamp_02", "prop_toilet_soap_01", "prop_toilet_soap_02", "prop_toilet_soap_03", "prop_toilet_soap_04", "prop_toolchest_01", "prop_toolchest_02", "prop_toolchest_03", "prop_toolchest_04", "prop_toolchest_05", "prop_tool_adjspanner", "prop_tool_bench01", "prop_tool_bluepnt", "prop_tool_box_01", "prop_tool_box_02", "prop_tool_box_03", "prop_tool_box_04", "prop_tool_box_05", "prop_tool_box_06", "prop_tool_box_07", "prop_tool_broom", "prop_tool_broom2", "prop_tool_broom2_l1", "prop_tool_cable01", "prop_tool_cable02", "prop_tool_consaw", "prop_tool_drill", "prop_tool_fireaxe", "prop_tool_hammer", "prop_tool_hardhat", "prop_tool_jackham", "prop_tool_mallet", "prop_tool_mopbucket", "prop_tool_nailgun", "prop_tool_pickaxe", "prop_tool_pliers", "prop_tool_rake", "prop_tool_rake_l1", "prop_tool_sawhorse", "prop_tool_screwdvr01", "prop_tool_screwdvr02", "prop_tool_screwdvr03", "prop_tool_shovel", "prop_tool_shovel006", "prop_tool_shovel2", "prop_tool_shovel3", "prop_tool_shovel4", "prop_tool_shovel5", "prop_tool_sledgeham", "prop_tool_spanner01", "prop_tool_spanner02", "prop_tool_spanner03", "prop_tool_torch", "prop_tool_wrench", "prop_toothbrush_01", "prop_toothb_cup_01", "prop_toothpaste_01", "prop_tornado_wheel", "prop_torture_01", "prop_torture_ch_01", "prop_tourist_map_01", "prop_towel2_01", "prop_towel2_02", "prop_towel_01", "prop_towel_rail_01", "prop_towel_rail_02", "prop_towel_shelf_01", "prop_towel_small_01", "prop_towercrane_01a", "prop_towercrane_02a", "prop_towercrane_02b", "prop_towercrane_02c", "prop_towercrane_02d", "prop_towercrane_02e", "prop_towercrane_02el", "prop_towercrane_02el2", "prop_traffic_rail_1c", "prop_traffic_rail_2", "prop_trailer01", "prop_trailer01_up", "prop_trailer_01_new", "prop_trailer_door_closed", "prop_trailer_door_open", "prop_trailer_monitor_01", "prop_trailr_base", "prop_trailr_base_static", "prop_train_ticket_02", "prop_tram_pole_double01", "prop_tram_pole_double02", "prop_tram_pole_double03", "prop_tram_pole_roadside", "prop_tram_pole_single01", "prop_tram_pole_single02", "prop_tram_pole_wide01", "prop_tree_birch_01", "prop_tree_birch_02", "prop_tree_birch_03", "prop_tree_birch_03b", "prop_tree_birch_04", "prop_tree_birch_05", "prop_tree_cedar_02", "prop_tree_cedar_03", "prop_tree_cedar_04", "prop_tree_cedar_s_01", "prop_tree_cedar_s_02", "prop_tree_cedar_s_04", "prop_tree_cedar_s_05", "prop_tree_cedar_s_06", "prop_tree_cypress_01", "prop_tree_eng_oak_01", "prop_tree_eucalip_01", "prop_tree_fallen_01", "prop_tree_fallen_02", "prop_tree_fallen_pine_01", "prop_tree_jacada_01", "prop_tree_jacada_02", "prop_tree_lficus_02", "prop_tree_lficus_03", "prop_tree_lficus_05", "prop_tree_lficus_06", "prop_tree_log_01", "prop_tree_log_02", "prop_tree_maple_02", "prop_tree_maple_03", "prop_tree_mquite_01", "prop_tree_oak_01", "prop_tree_olive_01", "prop_tree_pine_01", "prop_tree_pine_02", "prop_tree_stump_01", "prop_trevor_rope_01", "prop_trev_sec_id", "prop_trev_tv_01", "prop_triple_grid_line", "prop_tri_finish_banner", "prop_tri_pod", "prop_tri_pod_lod", "prop_tri_start_banner", "prop_tri_table_01", "prop_trough1", "prop_truktrailer_01a", "prop_tshirt_box_02", "prop_tshirt_shelf_1", "prop_tshirt_shelf_2", "prop_tshirt_shelf_2a", "prop_tshirt_shelf_2b", "prop_tshirt_shelf_2c", "prop_tshirt_stand_01", "prop_tshirt_stand_01b", "prop_tshirt_stand_02", "prop_tshirt_stand_04", "prop_tt_screenstatic", "prop_tumbler_01", "prop_tumbler_01b", "prop_tumbler_01_empty", "prop_tunnel_liner01", "prop_tunnel_liner02", "prop_tunnel_liner03", "prop_turkey_leg_01", "prop_turnstyle_01", "prop_tv_02", "prop_tv_03_overlay", "prop_tv_04", "prop_tv_05", "prop_tv_06", "prop_tv_07", "prop_tv_cabinet_03", "prop_tv_cabinet_04", "prop_tv_cabinet_05", "prop_tv_cam_02", "prop_tv_flat_01", "prop_tv_flat_01_screen", "prop_tv_flat_02b", "prop_tv_flat_03", "prop_tv_flat_03b", "prop_tv_flat_michael", "prop_tv_test", "prop_tyre_rack_01", "prop_tyre_spike_01", "prop_t_coffe_table", "prop_t_shirt_ironing", "prop_t_shirt_row_01", "prop_t_shirt_row_02", "prop_t_shirt_row_02b", "prop_t_shirt_row_03", "prop_t_shirt_row_04", "prop_t_shirt_row_05l", "prop_t_shirt_row_05r", "prop_t_sofa", "prop_t_sofa_02", "prop_t_telescope_01b", "prop_umpire_01", "prop_utensil", "prop_valet_03", "prop_vault_shutter", "prop_vb_34_tencrt_lighting", "prop_vcr_01", "prop_veg_corn_01", "prop_veg_crop_01", "prop_veg_crop_02", "prop_veg_crop_04", "prop_veg_crop_04_leaf", "prop_veg_crop_05", "prop_veg_crop_06", "prop_veg_crop_orange", "prop_veg_crop_tr_01", "prop_veg_crop_tr_02", "prop_veg_grass_01_a", "prop_veg_grass_01_b", "prop_veg_grass_01_c", "prop_veg_grass_01_d", "prop_veg_grass_02_a", "prop_vehicle_hook", "prop_vend_coffe_01", "prop_vend_condom_01", "prop_vend_fags_01", "prop_vend_fridge01", "prop_vend_snak_01", "prop_venice_board_01", "prop_venice_board_02", "prop_venice_board_03", "prop_venice_counter_01", "prop_venice_counter_02", "prop_venice_counter_03", "prop_venice_counter_04", "prop_venice_shop_front_01", "prop_venice_sign_09", "prop_venice_sign_10", "prop_venice_sign_11", "prop_venice_sign_12", "prop_venice_sign_14", "prop_venice_sign_15", "prop_venice_sign_16", "prop_venice_sign_17", "prop_venice_sign_18", "prop_ventsystem_01", "prop_ventsystem_02", "prop_ventsystem_03", "prop_ventsystem_04", "prop_ven_market_stool", "prop_ven_market_table1", "prop_ven_shop_1_counter", "prop_vertdrill_01", "prop_voltmeter_01", "prop_v_15_cars_clock", "prop_v_5_bclock", "prop_v_bmike_01", "prop_v_cam_01", "prop_v_door_44", "prop_v_hook_s", "prop_v_m_phone_01", "prop_v_m_phone_o1s", "prop_v_parachute", "prop_waiting_seat_01", "prop_wait_bench_01", "prop_walllight_ld_01b", "prop_wall_light_08a", "prop_wall_light_10a", "prop_wall_light_10b", "prop_wall_light_10c", "prop_wall_light_11", "prop_wall_light_12", "prop_wall_light_17b", "prop_wall_light_18a", "prop_wall_vent_01", "prop_wall_vent_02", "prop_wall_vent_03", "prop_wall_vent_04", "prop_wall_vent_05", "prop_wall_vent_06", "prop_wardrobe_door_01", "prop_warehseshelf01", "prop_warehseshelf02", "prop_warehseshelf03", "prop_warninglight_01", "prop_washer_01", "prop_washer_02", "prop_washer_03", "prop_washing_basket_01", "prop_watercrate_01", "prop_wateringcan", "prop_watertower01", "prop_watertower02", "prop_watertower03", "prop_watertower04", "prop_waterwheela", "prop_waterwheelb", "prop_water_bottle", "prop_water_bottle_dark", "prop_water_corpse_01", "prop_water_corpse_02", "prop_water_ramp_01", "prop_water_ramp_02", "prop_water_ramp_03", "prop_weed_01", "prop_weed_02", "prop_weed_block_01", "prop_weed_bottle", "prop_weed_pallet", "prop_weed_tub_01", "prop_weed_tub_01b", "prop_weight_10k", "prop_weight_15k", "prop_weight_1_5k", "prop_weight_20k", "prop_weight_2_5k", "prop_weight_5k", "prop_weight_rack_01", "prop_weight_rack_02", "prop_welding_mask_01", "prop_weld_torch", "prop_wheat_grass_empty", "prop_wheat_grass_glass", "prop_wheelbarrow01a", "prop_wheelbarrow02a", "prop_wheelchair_01", "prop_wheel_01", "prop_wheel_02", "prop_wheel_03", "prop_wheel_04", "prop_wheel_05", "prop_wheel_06", "prop_wheel_hub_01", "prop_wheel_hub_02_lod_02", "prop_wheel_rim_01", "prop_wheel_rim_02", "prop_wheel_rim_03", "prop_wheel_rim_04", "prop_wheel_rim_05", "prop_wheel_tyre", "prop_whisk", "prop_white_keyboard", "prop_winch_hook_long", "prop_winch_hook_short", "prop_windmill2", "prop_windmill_01_l1", "prop_windmill_01_slod", "prop_windmill_01_slod2", "prop_windowbox_a", "prop_windowbox_b", "prop_windowbox_broken", "prop_windowbox_small", "prop_win_plug_01", "prop_win_plug_01_dam", "prop_win_trailer_ld", "prop_wok", "prop_woodpile_02a", "prop_worklight_01a_l1", "prop_worklight_03a_l1", "prop_worklight_03b_l1", "prop_worklight_04a", "prop_worklight_04b_l1", "prop_worklight_04c_l1", "prop_worklight_04d_l1", "prop_workwall_01", "prop_workwall_02", "prop_wreckedcart", "prop_wrecked_buzzard", "prop_w_board_blank", "prop_w_board_blank_2", "prop_w_fountain_01", "prop_w_r_cedar_01", "prop_w_r_cedar_dead", "prop_xmas_tree_int", "prop_xmas_ext", "prop_yacht_lounger", "prop_yacht_seat_01", "prop_yacht_seat_02", "prop_yacht_seat_03", "prop_yacht_table_01", "prop_yacht_table_02", "prop_yacht_table_03", "prop_yaught_chair_01", "prop_yaught_sofa_01", "prop_yell_plastic_target", "prop_yoga_mat_01", "prop_yoga_mat_02", "prop_yoga_mat_03", "prop_ztype_covered", "p_ing_skiprope_01", "p_ing_skiprope_01_s", "p_skiprope_r_s", "test_prop_gravestones_04a", "test_prop_gravestones_05a", "test_prop_gravestones_07a", "test_prop_gravestones_08a", "test_prop_gravestones_09a", "test_prop_gravetomb_01a", "test_prop_gravetomb_02a", "prop_cs_dog_lead_a_s", "prop_cs_dog_lead_b_s", "prop_welding_mask_01_s", "prop_wheelchair_01_s", "p_a4_sheets_s", "p_amanda_note_01_s", "p_armchair_01_s", "p_arm_bind_cut_s", "p_ashley_neck_01_s", "p_banknote_onedollar_s", "p_banknote_s", "p_binbag_01_s", "p_bison_winch_s", "p_bloodsplat_s", "p_blueprints_01_s", "p_brain_chunk_s", "p_bs_map_door_01_s", "p_cablecar_s", "p_cablecar_s_door_l", "p_cablecar_s_door_r", "p_cash_envelope_01_s", "p_cctv_s", "p_chem_vial_02b_s", "p_clb_officechair_s", "p_cletus_necklace_s", "p_clothtarp_down_s", "p_clothtarp_s", "p_clothtarp_up_s", "p_controller_01_s", "p_crahsed_heli_s", "p_cs1_14b_train_s", "p_cs1_14b_train_s_col", "p_cs1_14b_train_s_colopen", "p_csbporndudes_necklace_s", "p_csh_strap_01_pro_s", "p_csh_strap_01_s", "p_csh_strap_03_s", "p_cs_15m_rope_s", "p_cs_bandana_s", "p_cs_beachtowel_01_s", "p_cs_beverly_lanyard_s", "p_cs_bowl_01b_s", "p_cs_ciggy_01b_s", "p_cs_clothes_box_s", "p_cs_coke_line_s", "p_cs_cuffs_02_s", "p_cs_duffel_01_s", "p_cs_laz_ptail_s", "p_cs_leaf_s", "p_cs_mp_jet_01_s", "p_cs_newspaper_s", "p_cs_pamphlet_01_s", "p_cs_panties_03_s", "p_cs_para_ropebit_s", "p_cs_para_ropes_s", "p_cs_polaroid_s", "p_cs_police_torch_s", "p_cs_pour_tube_s", "p_cs_power_cord_s", "p_cs_rope_tie_01_s", "p_cs_sack_01_s", "p_cs_saucer_01_s", "p_cs_scissors_s", "p_cs_script_s", "p_cs_shirt_01_s", "p_cs_shot_glass_2_s", "p_cs_shot_glass_s", "p_cs_sub_hook_01_s", "p_cs_toaster_s", "p_cs_tracy_neck2_s", "p_cs_trolley_01_s", "p_defilied_ragdoll_01_s", "p_devin_box_01_s", "p_dinechair_01_s", "p_d_scuba_mask_s", "p_d_scuba_tank_s", "p_ecg_01_cable_01_s", "p_fib_rubble_s", "p_finale_bld_ground_s", "p_finale_bld_pool_s", "p_fin_vaultdoor_s", "p_flatbed_strap_s", "p_folding_chair_01_s", "p_gaffer_tape_s", "p_gaffer_tape_strip_s", "p_gasmask_s", "p_gcase_s", "p_hand_toilet_s", "p_hw1_22_doors_s", "p_hw1_22_table_s", "p_ice_box_01_s", "p_ice_box_proxy_col", "p_idol_case_s", "p_ilev_p_easychair_s", "p_inhaler_01_s", "p_jimmyneck_03_s", "p_jimmy_necklace_s", "p_kitch_juicer_s", "p_lamarneck_01_s", "p_laptop_02_s", "p_large_gold_s", "p_lazlow_shirt_s", "p_laz_j01_s", "p_laz_j02_s", "p_ld_cable_tie_01_s", "p_ld_crocclips01_s", "p_ld_crocclips02_s", "p_ld_heist_bag_s_1", "p_ld_heist_bag_s_2", "p_ld_heist_bag_s_pro", "p_ld_heist_bag_s_pro2_s", "p_ld_heist_bag_s_pro_o", "p_leg_bind_cut_s", "p_lestersbed_s", "p_lev_sofa_s", "p_lifeinv_neck_01_s", "p_loose_rag_01_s", "p_mbbed_s", "p_medal_01_s", "p_med_jet_01_s", "p_meth_bag_01_s", "p_michael_backpack_s", "p_michael_scuba_mask_s", "p_michael_scuba_tank_s", "p_mp_showerdoor_s", "p_mrk_harness_s", "p_mr_raspberry_01_s", "p_novel_01_s", "p_b1rd_neck_01_s", "p_b1rd_neck_02_s", "p_orleans_mask_s", "p_ortega_necklace_s", "p_oscar_necklace_s", "p_overalls_02_s", "p_pistol_holster_s", "p_po1_01_doorm_s", "p_police_radio_hset_s", "p_poly_bag_01_s", "p_pour_wine_s", "p_rail_controller_s", "p_res_sofa_l_s", "p_rpulley_s", "p_sec_case_02_s", "p_shower_towel_s", "p_single_rose_s", "p_smg_holster_01_s", "p_soloffchair_s", "p_spinning_anus_s", "p_steve_scuba_hood_s", "p_stretch_necklace_s", "p_syringe_01_s", "p_s_scuba_mask_s", "p_s_scuba_tank_s", "p_till_01_s", "p_tmom_earrings_s", "p_tourist_map_01_s", "p_trevor_prologe_bally_s", "p_trev_rope_01_s", "p_trev_ski_mask_s", "p_tumbler_01_s", "p_tumbler_02_s1", "p_tumbler_cs2_s", "p_tv_cam_02_s", "p_t_shirt_pile_s", "p_v_43_safe_s", "p_v_ilev_chopshopswitch_s", "p_v_med_p_sofa_s", "p_v_res_tt_bed_s", "p_wade_necklace_s", "p_wboard_clth_s", "p_weed_bottle_s", "p_whiskey_bottle_s", "p_winch_long_s", "s_prop_hdphones", "s_prop_hdphones_1", "v_ilev_fib_door1_s", "v_res_msonbed_s", "v_res_tre_sofa_s", "v_tre_sofa_mess_a_s", "v_tre_sofa_mess_b_s", "v_tre_sofa_mess_c_s", "prop_ar_arrow_1", "prop_ar_arrow_2", "prop_ar_arrow_3", "prop_ar_ring_01", "prop_mk_arrow_3d", "prop_mk_arrow_flat", "prop_mk_bike_logo_1", "prop_mk_bike_logo_2", "prop_mk_boost", "prop_mk_cone", "prop_mk_cylinder", "prop_mk_flag", "prop_mk_flag_2", "prop_mk_heli", "prop_mk_lap", "prop_mk_mp_ring_01", "prop_mk_mp_ring_01b", "prop_mk_num_0", "prop_mk_num_1", "prop_mk_num_2", "prop_mk_num_3", "prop_mk_num_4", "prop_mk_num_5", "prop_mk_num_6", "prop_mk_num_7", "prop_mk_num_8", "prop_mk_num_9", "prop_mk_plane", "prop_mk_race_chevron_01", "prop_mk_race_chevron_02", "prop_mk_race_chevron_03", "prop_mk_repair", "prop_mk_ring", "prop_mk_ring_flat", "prop_mk_sphere", "prop_mk_tri_cycle", "prop_mk_tri_run", "prop_mk_tri_swim", "prop_mp_arrow_ring", "prop_mp_halo", "prop_mp_halo_lrg", "prop_mp_halo_med", "prop_mp_halo_point", "prop_mp_halo_point_lrg", "prop_mp_halo_point_med", "prop_mp_halo_point_sm", "prop_mp_halo_rotate", "prop_mp_halo_rotate_lrg", "prop_mp_halo_rotate_med", "prop_mp_halo_rotate_sm", "prop_mp_halo_sm", "prop_mp_pointer_ring", "prop_mp_solid_ring", "cj_parachute", "gb_cap_use", "gb_specs_use", "cj_proc_tin2", "proc_coral_01", "proc_fern_02", "proc_litter_01", "proc_litter_02", "proc_mntn_stone01", "proc_mntn_stone02", "proc_mntn_stone03", "proc_searock_01", "proc_searock_02", "proc_searock_03", "proc_sml_stones01", "proc_sml_stones02", "proc_sml_stones03", "proc_trolley_lakebed", "prop_bush_gorse_dry", "prop_bush_gorse_lush", "prop_coral_01", "prop_coral_02", "prop_coral_03", "prop_sapling_01", "prop_seabrain_01", "prop_seagroup_02", "prop_sealife_01", "prop_sealife_02", "prop_sealife_03", "prop_sealife_04", "prop_sealife_05", "prop_seaweed_01", "prop_seaweed_02", "prop_starfish_01", "prop_starfish_02", "prop_starfish_03", "p_dock_rtg_ld_cab", "p_dock_rtg_ld_spdr", "p_dock_rtg_ld_wheel", "p_amb_bag_bottle_01", "p_amb_brolly_01", "p_amb_brolly_01_s", "p_amb_clipboard_01", "p_amb_coffeecup_01", "p_amb_joint_01", "p_amb_lap_top_01", "p_amb_lap_top_02", "p_amb_phone_01", "p_car_keys_01", "p_counter_01_glass", "p_counter_01_glass_plug", "p_counter_02_glass", "p_counter_03_glass", "p_counter_04_glass", "p_cs_cam_phone", "p_cs_comb_01", "p_cs_laptop_02", "p_cs_laptop_02_w", "p_cs_locker_01", "p_cs_locker_02", "p_cs_locker_door_01", "p_cs_locker_door_01b", "p_cs_locker_door_02", "p_cs_paper_disp_02", "p_cs_paper_disp_1", "p_disp_02_door_01", "p_ferris_car_01", "p_f_duster_handle_01", "p_f_duster_head_01", "p_int_jewel_mirror", "p_int_jewel_plant_01", "p_int_jewel_plant_02", "p_jewel_necklace_02", "p_ld_am_ball_01", "p_ld_coffee_vend_01", "p_ld_conc_cyl_01", "p_ld_frisbee_01", "p_ld_heist_bag_01", "p_ld_sax", "p_ld_soc_ball_01", "p_new_j_counter_01", "p_new_j_counter_02", "p_new_j_counter_03", "p_num_plate_01", "p_num_plate_02", "p_num_plate_03", "p_num_plate_04", "p_oil_slick_01", "p_pharm_unit_01", "p_pharm_unit_02", "p_planning_board_01", "p_planning_board_02", "p_planning_board_03", "p_planning_board_04", "p_secret_weapon_02", "p_stinger_02", "p_stinger_03", "p_stinger_04", "p_stinger_piece_01", "p_stinger_piece_02", "p_watch_01", "p_watch_02", "p_watch_03", "p_watch_04", "p_watch_05", "p_watch_06", "p_abat_roller_1", "p_abat_roller_1_col", "p_amb_drain_water_double", "p_amb_drain_water_longstrip", "p_amb_drain_water_single", "p_attache_case_01_s", "p_balaclavamichael_s", "p_barierbase_test_s", "p_barier_test_s", "p_beefsplitter_s", "p_cargo_chute_s", "p_cigar_pack_02_s", "p_cs_locker_01_s", "p_cs_script_bottle_s", "p_dock_crane_cable_s", "p_dock_crane_cabl_s", "p_dock_crane_sld_s", "p_dumpster_t", "p_fag_packet_01_s", "p_ferris_wheel_amo_l", "p_ferris_wheel_amo_l2", "p_ferris_wheel_amo_p", "p_gar_door_01_s", "p_gar_door_02_s", "p_gar_door_03_s", "p_gdoor1colobject_s", "p_gdoor1_s", "p_jewel_necklace01_s", "p_jewel_necklace02_s", "p_jewel_pickup33_s", "p_ld_coffee_vend_s", "p_ld_heist_bag_s", "p_ld_stinger_s", "p_litter_picker_s", "p_mast_01_s", "p_notepad_01_s", "p_oil_pjack_01_amo", "p_oil_pjack_01_frg_s", "p_oil_pjack_02_amo", "p_oil_pjack_02_frg_s", "p_oil_pjack_03_amo", "p_oil_pjack_03_frg_s", "p_pallet_02a_s", "p_panties_s", "p_parachute1_mp_s", "p_parachute1_s", "p_parachute1_sp_s", "p_parachute_fallen_s", "p_parachute_s", "p_parachute_s_shop", "p_para_broken1_s", "p_patio_lounger1_s", "p_phonebox_02_s", "p_pliers_01_s", "p_rcss_folded", "p_rcss_s", "p_ringbinder_01_s", "p_sec_gate_01_s", "p_sec_gate_01_s_col", "p_shoalfish_s", "p_sofa_s", "p_sub_crane_s", "p_sunglass_m_s", "p_tennis_bag_01_s", "p_tram_crash_s", "p_watch_01_s", "p_watch_02_s", "p_watch_03_s", "p_waterboardc_s", "p_yacht_chair_01_s", "p_yacht_sofa_01_s", "p_yoga_mat_01_s", "p_yoga_mat_02_s", "p_yoga_mat_03_s", "pop_v_bank_door_l", "pop_v_bank_door_r", "p_cut_door_01", "p_cut_door_02", "p_cut_door_03", "p_jewel_door_l", "p_jewel_door_r1", "p_amb_bagel_01", "p_cs_bbbat_01", "p_cs_bottle_01", "p_cs_clipboard", "p_cs_joint_01", "p_cs_joint_02", "p_cs_lighter_01", "p_cs_papers_01", "p_cs_papers_02", "p_cs_papers_03", "p_ing_bagel_01", "p_ing_microphonel_01", "p_ld_bs_bag_01", "p_ld_id_card_002", "p_ld_id_card_01", "p_rc_handset", "p_whiskey_notop", "p_whiskey_notop_empty", "proc_drkyel001", "proc_flower1", "proc_flower_wild_04", "proc_weeds01a", "proc_weeds01b", "proc_weeds01c", "prop_test_bed", "proair_hoc_puck", "p_film_set_static_01", "rock_4_cl_2_1", "rock_4_cl_2_2", "w_am_baseball", "w_am_baseball_hi", "w_am_brfcase", "w_am_case", "w_am_digiscanner", "w_am_digiscanner_hi", "w_am_fire_exting", "w_am_flare", "w_am_flare_hi", "w_am_jerrycan", "w_ar_advancedrifle", "w_ar_advancedrifle_hi", "w_ar_advancedrifle_mag1", "w_ar_advancedrifle_mag2", "w_ar_assaultrifle", "w_ar_assaultrifle_hi", "w_ar_assaultrifle_mag1", "w_ar_assaultrifle_mag2", "w_ar_carbinerifle", "w_ar_carbinerifle_hi", "w_ar_carbinerifle_mag1", "w_ar_carbinerifle_mag2", "w_at_ar_afgrip", "w_at_ar_afgrip_hi", "w_at_ar_flsh", "w_at_ar_flsh_hi", "w_at_ar_supp", "w_at_ar_supp_02", "w_at_ar_supp_02_hi", "w_at_ar_supp_hi", "w_at_pi_flsh", "w_at_pi_flsh_hi", "w_at_pi_supp", "w_at_pi_supp_hi", "w_at_railcover_01", "w_at_railcover_01_hi", "w_at_scope_large", "w_at_scope_large_hi", "w_at_scope_macro", "w_at_scope_macro_hi", "w_at_scope_max", "w_at_scope_max_hi", "w_at_scope_medium", "w_at_scope_medium_hi", "w_at_scope_small", "w_at_scope_small_hi", "w_at_sr_supp", "w_at_sr_supp_hi", "w_ex_grenadefrag", "w_ex_grenadefrag_hi", "w_ex_grenadesmoke", "w_ex_molotov", "w_ex_molotov_hi", "w_ex_pe", "w_ex_pe_hi", "w_lr_40mm", "w_lr_40mm_pu", "w_lr_grenadelauncher", "w_lr_grenadelauncher_hi", "w_lr_rpg", "w_lr_rpg_hi", "w_lr_rpg_rocket", "w_lr_rpg_rocket_pu", "w_me_bat", "w_me_crowbar", "w_me_gclub", "w_me_hammer", "w_me_knife_01", "w_me_nightstick", "w_mg_combatmg", "w_mg_combatmg_hi", "w_mg_combatmg_mag1", "w_mg_combatmg_mag2", "w_mg_mg", "w_mg_mg_hi", "w_mg_mg_mag1", "w_mg_mg_mag2", "w_mg_minigun", "w_mg_minigun_hi", "w_pi_appistol", "w_pi_appistol_hi", "w_pi_appistol_mag1", "w_pi_appistol_mag2", "w_pi_combatpistol", "w_pi_combatpistol_hi", "w_pi_combatpistol_mag1", "w_pi_combatpistol_mag2", "w_pi_pistol", "w_pi_pistol50", "w_pi_pistol50_hi", "w_pi_pistol50_mag1", "w_pi_pistol50_mag2", "w_pi_pistol_hi", "w_pi_pistol_mag1", "w_pi_pistol_mag2", "w_pi_stungun", "w_pi_stungun_hi", "w_sb_assaultsmg", "w_sb_assaultsmg_hi", "w_sb_assaultsmg_mag1", "w_sb_assaultsmg_mag2", "w_sb_microsmg", "w_sb_microsmg_hi", "w_sb_microsmg_mag1", "w_sb_microsmg_mag2", "w_sb_smg", "w_sb_smg_hi", "w_sb_smg_mag1", "w_sb_smg_mag2", "w_sg_assaultshotgun", "w_sg_assaultshotgun_hi", "w_sg_assaultshotgun_mag1", "w_sg_assaultshotgun_mag2", "w_sg_bullpupshotgun", "w_sg_bullpupshotgun_hi", "w_sg_pumpshotgun", "w_sg_pumpshotgun_hi", "w_sg_sawnoff", "w_sg_sawnoff_hi", "w_sr_heavysniper", "w_sr_heavysniper_hi", "w_sr_heavysniper_mag1", "w_sr_sniperrifle", "w_sr_sniperrifle_hi", "w_sr_sniperrifle_mag1", "db_apart_01_", "db_apart_02_", "ela_wdn_04_", "hei_hw1_06_road", "lf_house_04_", "lf_house_05_", "lf_house_09_", "lf_house_20_", "prop_helipad_02", "db_apart_01d_", "db_apart_01_", "db_apart_02d_", "db_apart_02_", "db_apart_03d_", "db_apart_03_", "dt1_lod_slod3", "id1_lod_slod4", "hw1_lod_slod4", "po1_lod_slod4", "sc1_lod_slod4", "ss1_lod_slod3", "ap1_lod_slod4", "kt1_lod_slod4", "bh1_lod_slod3", "sp1_lod_slod4", "sm_lod_slod4", "vb_lod_slod4", "ch1_lod_slod3a", "ch2_lod4_s3c", "dt1_tc_dufo_core", "sc1_lod_slod4", "dt1_lod_slod3", };
		if (objectwarprotection)
		{
			{	
				const int ElementAmount = 10;
				const int ArrSize = ElementAmount * 2 + 2;
				Object* obj = new Object[ArrSize];
				obj[0] = ElementAmount;
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				int ObjectFound = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 100, GAMEPLAY::GET_HASH_KEY(warobjects[13446]), 1, 0, 1);

				for (int i = 0; i < ObjectFound; i++) {
					int OffsetID = i * 2 + 2;

					if (ENTITY::DOES_ENTITY_EXIST(obj[OffsetID]) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj[OffsetID], PLAYER::PLAYER_PED_ID())) {
						RequestControlOfEnt(obj[OffsetID]);
						int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj[OffsetID]);
						NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
						Protections::RequestControlOfid(netID);
						ENTITY::DETACH_ENTITY(obj[OffsetID], 1, 1);
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj[OffsetID])) {
							ENTITY::SET_ENTITY_COORDS(obj[OffsetID], 6000.0, 6000.0, 6000.0, true, false, false, true);
							ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj[OffsetID], 1, 1);
							ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj[OffsetID]);
							OBJECT::DELETE_OBJECT(&obj[OffsetID]);
							ENTITY::DELETE_ENTITY(&obj[OffsetID]);
						}
					}
				}
			}
		}
		else
		{

		}
		if (clearloopwarprotection)
		{
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			notifyMap("Press Delete To Clear the Zone");
			if (GetAsyncKeyState(0x0C))
			{
				GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 80, 0);
				GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 80, 0);
				GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 80, 0, 0, 0, 0, 0);
				WAIT(1300);
			}
			

		}
		else
		{

		}

		if (vehiclewarprotection)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;  //Start at index 2, and the odd elements are padding
			int vehs[arrSize];
			vehs[0] = numElements;
			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			if (!CUTSCENE::IS_CUTSCENE_ACTIVE() && !CUTSCENE::IS_CUTSCENE_PLAYING() && !STREAMING::IS_NETWORK_LOADING_SCENE() && !NETWORK::NETWORK_IS_IN_MP_CUTSCENE() && !INTERIOR::IS_INTERIOR_SCENE())
			{
				for (int i = 0; i < count; ++i)
				{
					int offsettedID = i * 2 + 2;
					if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
					{
						if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
						{
							if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
							{
								RequestControlOfEnt(vehs[offsettedID]);
								ENTITY::DETACH_ENTITY(vehs[offsettedID], 1, 1);
								ENTITY::SET_ENTITY_COORDS(vehs[offsettedID], 6000.0, 6000.0, 6000.0, true, false, false, true);
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehs[offsettedID], 1, 1);
								VEHICLE::DELETE_VEHICLE(&vehs[offsettedID]);
								ENTITY::DELETE_ENTITY(&vehs[offsettedID]);
							}
						}
					}
				}
			}
		}
		else
		{

		}


		if (FoxyEvent)
		{
				for (int i = 0; i < 33; i++) {
					if (auto Join = NETWORK::NETWORK_JOIN_TRANSITION(i))
					{
						char* rockstarID;
						int NETWORK_HANDLE[76];
						NETWORK::NETWORK_HANDLE_FROM_PLAYER(Join, &NETWORK_HANDLE[0], 13);
						if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
							rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
						}
						std::string PlayerName = PLAYER::GET_PLAYER_NAME(Join);
						std::string RID = rockstarID;
						std::string RID1 = " RID: ";
						std::string Message = " Just join your session";
						std::string Combined = PlayerName + RID1 + RID + Message;
						const char* name = (Combined).c_str();

						NotificationCEO(&((char*)name)[0], (char*)"Foxy", &((char*)"Player Join")[0]);
					}
				}
		}


		if (FoxyEvent2)
		{
			for (int i = 0; i < 33; i++) {
				if (auto Leaving = NETWORK::NETWORK_LEAVE_TRANSITION())
				{

					char* rockstarID;
					int NETWORK_HANDLE[76];
					NETWORK::NETWORK_HANDLE_FROM_PLAYER(Leaving, &NETWORK_HANDLE[0], 13);
					if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
						rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
					}
					std::string PlayerName = PLAYER::GET_PLAYER_NAME(Leaving);
					std::string RID = rockstarID;
					std::string RID1 = " RID: ";
					std::string Message = " Just left your session";
					std::string Combined = PlayerName + RID1 + RID + Message;
					const char* name = (Combined).c_str();

					NotificationCEO(&((char*)name)[0], (char*)"Foxy", &((char*)"Player Left")[0]);
				}
			}
		}

		if (FoxyEvent3)
		{

		}

		switch (Menu::Settings::currentMenu)
		{

		case mainmenu:
		{
			Menu::Title("");
			Menu::SubTitle("Main");
			Menu::MenuOption("Fight Assist", FA);
			Menu::MenuOption("Local", self);
			Menu::MenuOption("Network", network);
			Menu::MenuOption("Vehicle", vehicles);
			Menu::MenuOption("Weapons", weapons);
			Menu::MenuOption("Teleport", tp);
			Menu::MenuOption("World", world);
			Menu::MenuOption("Hot Keys", hotkeys);
			Menu::MenuOption("Settings", settings);
			if (Menu::Option("Join Foxy Discord")) { system("start https://discord.gg/Ps4bEwPJSH"); }
			//if (Menu::Option("Get Hash WEAPON_TACTICALRIFLE")) { std::cout << $("WEAPON_TACTICALRIFLE ~n~"); }
			//if (Menu::Option("Get Hash WEAPON_PRECISIONRIFLE")) { std::cout << $("WEAPON_PRECISIONRIFLE ~n~"); }



			

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Fight Assist Sub");

			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Local Sub");

			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Network Sub");

			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Vehicle Sub");

			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Weapons Sub");

			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Teleport Sub");

			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("World Sub");

			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Hotkey Sub");

			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Settings Sub");

			}



		}
		break;
#pragma region Local Menu
		case self:
		{
			Menu::Title("");
			Menu::SubTitle("Local");
			Menu::MenuOption("Wardrobe", outfits);
			Menu::MenuOption("Animations & Scenarios", animations);
			Menu::MenuOption("Bodyguards", Bguards);
			Menu::MenuOption("Glow", fancy);
			Menu::MenuOption("Vision", vis);
			Menu::MenuOption("Model Changer", modelchanger);
			Menu::MenuOption("Effects", effect);
			Menu::MenuOption("Super Powers", SuperPowers);
			Menu::MenuOption("Entity Health Flags", EntityProofss);
			if (Menu::ListVector("Walk Style", walkNames, walk_style_choose)) { SetPedMovementClipset(walkDicts[walk_style_choose]); }
			Menu::Toggle("Invincible", Modegod);
			Menu::Toggle("Never Wanted", Local::NeverWanted);
			Menu::Toggle("Invisible", Invisibleee);
			Menu::Toggle("Off Radar", Local::OffRadar);
			Menu::Toggle("Super Vision", Local::SV);
			Menu::Toggle("No Ragdoll", Local::NoRagdoll);
			Menu::Toggle("Fly", Local::Fly);
			Menu::Toggle("Firebreath", Local::FB);
			Menu::Toggle("Forcefield", Local::Force);
			Menu::Toggle("No Clip", Local::NoClip);
			Menu::Toggle("Free Cam", Camfree);
			Menu::Toggle("Walk on air", Local::walkinair);
			Menu::Toggle("Super Run", Local::SuperRun);
			Menu::Toggle("Fast Run", frr);
			Menu::Toggle("Super Jump", Local::Superjump);
			Menu::Toggle("Ultra Jump", Local::Ultrajump);
			Menu::Toggle("Fast Swim", Local::Swim);
			Menu::Toggle1("Auto Generate Health", Local::isAutoRegHealth, [] { Local::AutoRegHealth(Local::isAutoRegHealth); });
			Menu::Toggle1("Auto Generate Armor", Local::isAutoRegArmour, [] { Local::AutoRegArmour(Local::isAutoRegArmour); });
			Menu::Toggle("Mobile Radio", Local::MobileRadio);
			Menu::Toggle("Unlimited Ability", Unlimited);
			Menu::Toggle("Slow Motion", SlowMotionn);
			Menu::Toggle("Shrink", Local::TinyPlayer);
			Menu::Toggle("Explode Waypoint", Local::OS);
			if (Menu::Option("Suicide")) { Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0); }
			Menu::Toggle("Super Punch", Local::Superpunch);
			Menu::Toggle("No Phone", Local::Nophone);
			Menu::Toggle("Anti Afk", Local::antiafk);
			Menu::Toggle("Ped Size", Local::Pedscale);
			Menu::Float("Ped Wide", Local::pedwith, 1.f, 10.f, 1.f);
			Menu::Float("Ped Height", Local::pedsize, 1.f, 10.f, 1.f);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Wardrobe Sub");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Animations & Scenarios Sub");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Bodyguards Sub");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Glow Sub");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Vision Effects Sub");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Models Sub");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Characther Effects Sub");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Super Powers Sub");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Set Your Entity Health Flags");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Choose A Walking Style");

			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Won't be able to take damage");
				
			}
			if (Menu::Settings::currentOption == 12) {
				Menu::OptionInfo("Bribe Authorities Permanently");
			}
			if (Menu::Settings::currentOption == 13) {
				Menu::OptionInfo("Be Invisible To Others");
			}
			if (Menu::Settings::currentOption == 14) {
				Menu::OptionInfo("Hides Your Blip From Others Radar");
			}
			if (Menu::Settings::currentOption == 15) {
				Menu::OptionInfo("Blows up anything in your eyesight");
			}
			if (Menu::Settings::currentOption == 16) {
				Menu::OptionInfo("Disable Ragdoll Animations");
			}
			if (Menu::Settings::currentOption == 17) {
				Menu::OptionInfo("Fly Around");
			}
			if (Menu::Settings::currentOption == 18) {
				Menu::OptionInfo("Enables \"Firebreath\"");
			}
			if (Menu::Settings::currentOption == 19) {
				Menu::OptionInfo("Forcefield Around Your Player");
			}
			if (Menu::Settings::currentOption == 20) {
				Menu::OptionInfo("Clip Trough Entities");
			}
			if (Menu::Settings::currentOption == 21) {
				Menu::OptionInfo("Control Your Cam");
			}
			if (Menu::Settings::currentOption == 22) {
				Menu::OptionInfo("Walk In The Air | Q & Z");
			}
			if (Menu::Settings::currentOption == 23) {
				Menu::OptionInfo("Run 2 times as fast");
			}
			if (Menu::Settings::currentOption == 24) {
				Menu::OptionInfo("Run Faster");
			}
			if (Menu::Settings::currentOption == 25) {
				Menu::OptionInfo("Jump Higher");
			}
			if (Menu::Settings::currentOption == 26) {
				Menu::OptionInfo("Jump Extremely High");
			}
			if (Menu::Settings::currentOption == 27) {
				Menu::OptionInfo("Swim 2 Times As Fast");
			}
			if (Menu::Settings::currentOption == 28) {
				Menu::OptionInfo("Auto Regen Health");
			}
			if (Menu::Settings::currentOption == 29) {
				Menu::OptionInfo("Auto Regen Armour");
			}
			if (Menu::Settings::currentOption == 30) {
				Menu::OptionInfo("Radio On Foot");
			}
			if (Menu::Settings::currentOption == 31) {
				Menu::OptionInfo("Unlimited Single Player Ability");
			}
			if (Menu::Settings::currentOption == 32) {
				Menu::OptionInfo("Run In Slowmotion");
			}
			if (Menu::Settings::currentOption == 33) {
				Menu::OptionInfo("Shrink Your Player");
       		}
			if (Menu::Settings::currentOption == 34) {
				Menu::OptionInfo("Barrage your waypoint with explosions");
			}
			if (Menu::Settings::currentOption == 35) {
				Menu::OptionInfo("Good Bye Cruel World");
			}
			if (Menu::Settings::currentOption == 36) {
				Menu::OptionInfo("Explosive Punch");
			}
			if (Menu::Settings::currentOption == 37) {
				Menu::OptionInfo("Like Stop Calling Me");
			}
			if (Menu::Settings::currentOption == 38) {
				Menu::OptionInfo("Wont Get Kick If You Are Afk");
			}
			if (Menu::Settings::currentOption == 39) {
				Menu::OptionInfo("Activate Model Scale Changer");
			}
			if (Menu::Settings::currentOption == 40) {
				Menu::OptionInfo("Change The Model Width");
			}
			if (Menu::Settings::currentOption == 41) {
				Menu::OptionInfo("Change The Model Height");
			}


		}
		break;
		case EntityProofss:
		{
			Menu::Title("");
			Menu::SubTitle("Entity Health Flags");
			Menu::Toggle("Bullet Proof", ProofBullet);
			Menu::Toggle("Explosion Proof", ProofExplosion);
			Menu::Toggle("Collision Proof", ProofCollision);
			Menu::Toggle("Water Proof", ProofWater);
			Menu::Toggle("Fire Proof", ProofFire);
			Menu::Toggle("Steam Proof", ProofSteam);
			Menu::Toggle("Melee Proof", proofMelee);
			Menu::Toggle("Interior Proof", ProofInterior);


			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Bullet Won't Damage You");

			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Explosion Won't Damage You");

			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Collision Won't Damage You");

			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Water Won't Damage You");

			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Fire Won't Damage You");

			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Steam Won't Damage You");

			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Melee Attacks Won't Damage You");

			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Give You Interior God Mode");

			}
		}
		break;
		case Coreptfx:
		{
			Menu::Title("");
			Menu::SubTitle("Core Ptfx");
			for (int i = 0; i < ARRAYSIZE(CorePtfxNames); i++)
			{
				if (Menu::Option(CorePtfxNames[i]))
				{
					STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
					GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
					GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(CorePtfxNames[i], PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 3.f, false, false, false);
				}
			}
		}
		break;
		case modelchanger:
		{
			Menu::Title("");
			Menu::SubTitle("Model Selection");
			Menu::MenuOption("Animals", animals);
			//Menu::MenuOption("Crash", Crash1);
			Menu::MenuOption("Story Mode", Storycharacter1);
			Menu::MenuOption("Female", Female1);
			Menu::MenuOption("Unclassed", Unclassed1);
		}
		break;
		case animals:
		{
			Menu::Title("");
			Menu::SubTitle("Model Changer [Animals]");
			for (int i = 0; i < ARRAYSIZE(Animals); i++)
			{
				if (Menu::Option(Animals[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(Animals[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
				}
			}
		}
		break;
		case Storycharacter1:
		{
			Menu::Title("");
			Menu::SubTitle("Model Changer [Story Mode]");
			for (int i = 0; i < ARRAYSIZE(Storycharacter); i++)
			{
				if (Menu::Option(Storycharacter[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(Storycharacter[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					for each (Hash weapon in weaponsList)
					{
						WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
					}
				}
			}
		}
		break;
		case Crash1:
		{
			Menu::Title("");
			Menu::SubTitle("Model Changer [Crash]");
			for (int i = 0; i < ARRAYSIZE(Crash); i++)
			{
				if (Menu::Option(Crash[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(Crash[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					for each (Hash weapon in weaponsList)
					{
						WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
					}
				}
			}
		}
		break;
		case Female1:
		{
			Menu::Title("");
			Menu::SubTitle("Model Changer [Female]");
			for (int i = 0; i < ARRAYSIZE(Female); i++)
			{
				if (Menu::Option(Female[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(Female[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					for each (Hash weapon in weaponsList)
					{
						WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
					}
				}
			}
		}
		break;
		case Unclassed1:
		{
			Menu::Title("");
			Menu::SubTitle("Model Changer [Unclassed]");
			for (int i = 0; i < ARRAYSIZE(Unclassed); i++)
			{
				if (Menu::Option(Unclassed[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(Unclassed[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					for each (Hash weapon in weaponsList)
					{
						WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
					}
				}
			}
		}
		break;
		case outfits:
		{
			//police
			Menu::Title("");
			Menu::SubTitle("Premade Outfits");
			Menu::MenuOption("Outfit editor", outfit);
			Menu::Toggle("Ghost", Local::O1);
			Menu::Toggle("Penguin", Local::O2);
			Menu::Toggle("Splinter", Local::O3);
			Menu::Toggle("Pilot", Local::O4);
			Menu::Toggle("Night Soldier", Local::O5);
			Menu::Toggle("Favorie", Local::O6);
			Menu::Toggle("Balla", Local::O7);
			Menu::Toggle("Elf", Local::O8);
			Menu::Toggle("Thug", Local::O9);
			Menu::Toggle("Santa", Local::O10);
			Menu::Toggle("Snowman", Local::O11);
			Menu::Toggle("Dead Eyes", Local::O12);


			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Outfit Editor Sub");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 12) {
				Menu::OptionInfo("Custom Outfit");
			}
			if (Menu::Settings::currentOption == 13) {
				Menu::OptionInfo("Custom Outfit");
			}
		}
		break;
		case SuperPowers:
		{
			Menu::Title("");
			Menu::SubTitle("Super Powers");
			Menu::Toggle("Super Vision RailGun", Local::SV);
			Menu::Toggle("Super Vision RayGun", Local::SV2);
			Menu::Toggle("Super Vision Lazer Bullets", Local::SV3);
			Menu::Toggle("Super Vision Grenade", Local::SV5);
			Menu::Toggle("Super Vision Missile", Local::SV6);
			Menu::Toggle("SilkRoad Hulk Power", Local::Hulk);
			Menu::Toggle("SilkRoad Angel Of Death Power", Angel_OF_DEATH);
			Menu::Toggle("SilkRoad Rudolf Power", Animal_Rider);
			Menu::Toggle("SilkRoad Super Man", SuperManSk);
			Menu::Toggle("SilkRoad Inferno Power", Inferno);
			Menu::Toggle("SilkRoad Electro Power", Electro);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Shoot RailGun Bullets From Your Eyes");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Shoot RayGun Bullets From Your Eyes");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Shoot Lazer Bullets From Your Eyes");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Shoot Motar shells From Your Eyes");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Shoot Missile From Your Eyes");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("SilkRoad Xbox 360 Super Powers Hulk");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("SilkRoad Xbox 360 Super Powers Demon");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("SilkRoad Xbox 360 Super Powers Rudolf");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("SilkRoad Xbox 360 Super Powers SuperMan");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("SilkRoad Xbox 360 Super Powers Inferno");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("SilkRoad Xbox 360 Super Powers Electro");
			}
			
		}
		break;
		case outfit: //Sub Menus
		{
			Local::Outfit();
		}
		break;
		case fancy: //Sub Menus
		{
			Local::ParticleEffects();
		}
		break;
		case fancy2: //Sub Menus
		{
			Local::ParticleEffects2();
		}
		break;
		case Bguards:
		{
			Local::Mainbodyguardss();
		}
		break;
		case modelsub:
		{
			Local::Modelss();
		}
		break;
		case BodyguardWeapons:
		{
			Local::Weaponss();
		}
		break;
		case vis:
		{
			Local::Visions();
		}
		break;
		case animations:
		{
			Local::Anim();
		}
		break;
		case scen:
		{
			Local::Scen();
		}
		break;
		case animations1:
		{
			Local::Anim1();
		}
		break;
		case scen11:
		{
			Local::Scen1();
		}
		break;
		case effect:
		{
			Local::Effects();
		}
		break;
#pragma endregion
#pragma region Network
		case network:
		{
			Network::MainMenu();
		}
		break;
		case ESPMENU:
		{
			Network::ESPMenu();
		}
		break;
		case recovery:
		{
			Recovery::RecoveryMenu();
		}
		break;
		case players:
		{
			Network::Players();
		}
		break;
		case spoofname:
		{
			//Network::namespoof();
		}
		break;
		case lvl:
		{
			Recovery::rpthing();
		}
		break;
		case unloc:
		{
			Recovery::Allunlocks();
		}
		break;
		case StatEdt:
		{
			Recovery::StatEdit();
		}
		break;
		case TuneableMenu:
		{
			Recovery::TuneableMenu1();
		}
		break;
		case BusinessMenu:
		{
			Recovery::BusinessMenu1();
		}
		break;
		case RecoveryManagerMenu: {
			Recovery::RecoveryManagerMenu1();
		}
		break;
		case MoneyMenu:
		{
			Recovery::MoneyMenu1();
		}
		break;
		case HeistMenu:
		{
			Recovery::HeistMenu1();
		}
		break;
		case ne:
		{
			Protections::see();
		}
		break;
		case warprotection:
		{
			Menu::Title("");
			Menu::SubTitle("Modding War");
			Menu::Toggle("Block Crash", Protections::Crasherzz);
			Menu::Toggle("Block Ped", pedwarprotection);
			Menu::Toggle("Block Vehicle", vehiclewarprotection);
			//Menu::Toggle("Block Object", objectwarprotection);
			Menu::Toggle("Clear Loop", clearloopwarprotection);
			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Block Crash Object, Models, Invalids");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Block Ped From Getting Close");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Block Ped From Getting Close");
			}
			//if (Menu::Settings::currentOption == 4) {
				//Menu::OptionInfo("Block Object From Getting Attached");
			//}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Clear The Map Arround You");
			}
		}
		break;
		case se:
		{
			Menu::Title("");
			Menu::SubTitle("Network Events And Models");
			Menu::Toggle("Block Votekick", Antihostk);
			Menu::Toggle("Block Freeze", FreezeProtection);
			Menu::Toggle("Block Crash Model", Protections::Crasherzz);
			Menu::Toggle("Block Req Control", reccontrolblocc);
			Menu::Toggle("Block Fire", FireP);
			Menu::Toggle("Block Explosions", Protections::ExplosionProtection);
			Menu::Toggle("Block Weapons Removal", WeaponP);
			Menu::Toggle("Block All Game Event Possible", BlockallEvent);
			Menu::Toggle("Block Ozark cunt ragdoll", BlockOzarkcunt);
			if (Menu::Option("~f~[ ~w~Model Swap ~f~]")){}
			Menu::Toggle("Block Cage", Protections::Swap1);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Blocks Votekicks");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Blocks Freezing");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Blocks Crash Model");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Blocks Request Vehicle Control");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Blocks Fire");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Blocks Explosions");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Blocks Weapons Removal");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Might Break Your Game");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Block Request Ragdoll");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Blocks Cages From Other Modder");
			}

		}
		break;
		case a:
		{
			Protections::aa();
		}
		break;
		case mds:
		{
			Menu::Title("");
			Menu::SubTitle("Drop all");
			if (Menu::Int("Amount", SPlayer::CashAmount, 0, 2500))
			{
				{
					if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
					{
						SPlayer::CashAmount = NumberKeyboard();
					}
				}
			}
			Menu::Int("Delay", SPlayer::CashInt, 0, 2000, 100);
			Menu::Int("Height", SPlayer::CashHeight, 1, 5, 1);
			Menu::Toggle("Drop Money", SPlayer::Dropall);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Select the amount of money to be dropped");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Select the delay between bag drops.");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Select the height of the bag spawning");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Drop money to everyone in lobby");
			}
		}
		break;
#pragma endregion
#pragma region Weapon Stuff
		case weapons:
		{
			Menu::Title("");
			Menu::SubTitle("Weapons");
			Menu::MenuOption("Vehicles", shootvehicles);
			Menu::MenuOption("Entities", Entityss);
			Menu::MenuOption("Explotion Impact", Impactt);
			Menu::MenuOption("Pickups [ ~r~Use At Your Own Risk~w~ ]", shootstuff);
			Menu::MenuOption("Customization", guns);
			Menu::Toggle("Infinite", Weap::InfiniteAmmo);
			Menu::Toggle("Explosive", Weap::ExplosiveAmmo);
			Menu::Toggle("Money [ ~r~Use At Your Own Risk~w~ ]", Weap::MoneyGun);
			Menu::Toggle("Rapid", Weap::RapidFire);
			Menu::Toggle("Airstrike", Weap::AirstrikeGun);
			Menu::Toggle("Onehit", Weap::Onehit);
			Menu::Toggle("Rope Gun", Weap::ROPEGUN);
			Menu::Toggle("Delete", Weap::DeleteGun);
			Menu::Toggle("Aimbot", Weap::Aimbot);
			Menu::Toggle("Triggerbot", Bottriggerr);
			Menu::Toggle("Lasersight", Weap::laser);
			Menu::Toggle("Rainbow", Weap::RainbowG);
			Menu::Toggle("Gravity Gun", Weap::GravityGunf);
			Menu::Toggle("RPG", Weap::RpG);
			Menu::Toggle("Fireworks", Weap::RPG2);
			Menu::Toggle("Water", Weap::WaterShoot);
			Menu::Toggle("Fire", Weap::FireAmmo);
			Menu::Toggle("Ped", Weap::PedGun);
			if (Menu::Option("Give All Weapons")) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				for each (Hash weapon in weaponsList)
				{
					WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
				}
			}
			Menu::Toggle("Flame Thrower", Weap::Flametrow);
			Menu::Toggle("Drive Gun", Weap::Drivegun);
			Menu::Toggle("Create Portal", Weap::TeleyGun);
			Menu::Toggle("Unfair Aimbot", Weap::Aimbot2);
			Menu::MenuOption("External Option", ExternalWeapOption);
			Menu::Toggle("Insight Missile Option Copied funnies", Weap::GuidedMissileInsight);
			//Menu::Toggle("Star Wars [ Beta ]", Local::STRW);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Vehicles Sub");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Entities Sub");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Explotion Impact Sub");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Pickups Sub");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Customization Sub");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Supplies You With Infinite Ammunition");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Shoot Explosive Bullets");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Shoot Money Bags");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("No Delay On Your Weapon");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Use Your Bullets Like a Flare");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("One Shot One Kill No Luck Just Skill");
			}
			if (Menu::Settings::currentOption == 12) {
				Menu::OptionInfo("Attach Entities To Entities With Rope");
			}
			if (Menu::Settings::currentOption == 13) {
				Menu::OptionInfo("Delete Entities With Your Bullets");
			}
			if (Menu::Settings::currentOption == 14) {
				Menu::OptionInfo("Auto Headshotting All Players");
			}
			if (Menu::Settings::currentOption == 15) {
				Menu::OptionInfo("Auto Shoot");
			}
			if (Menu::Settings::currentOption == 16) {
				Menu::OptionInfo("Enables Laser Sight");
			}
			if (Menu::Settings::currentOption == 17) {
				Menu::OptionInfo("Your Weapon's Camo Will Shift");
			}
			if (Menu::Settings::currentOption == 18) {
				Menu::OptionInfo("Pickup Entites");
			}
			if (Menu::Settings::currentOption == 19) {
				Menu::OptionInfo("Shoot with RPG Rounds");
			}
			if (Menu::Settings::currentOption == 20) {
				Menu::OptionInfo("Shoot with Firework Rounds");
			}
			if (Menu::Settings::currentOption == 21) {
				Menu::OptionInfo("Water Impact");
			}
			if (Menu::Settings::currentOption == 22) {
				Menu::OptionInfo("Fire Impact");
			}
			if (Menu::Settings::currentOption == 23) {
				Menu::OptionInfo("Random Ped Impact");
			}
			if (Menu::Settings::currentOption == 24) {
				Menu::OptionInfo("Give Yourself All Weapons");
			}
			if (Menu::Settings::currentOption == 25) {
				Menu::OptionInfo("Shoot Flames Out Of Your Canon");
			}
			if (Menu::Settings::currentOption == 26) {
				Menu::OptionInfo("Tp In The Last Vehicle You Shot");
			}
			if (Menu::Settings::currentOption == 27) {
				Menu::OptionInfo("Portal Gun");
			}
			if (Menu::Settings::currentOption == 28) {
				Menu::OptionInfo("Kill Everyone Around You");
			}
			if (Menu::Settings::currentOption == 29) {
				Menu::OptionInfo("External Options Sub");
			}
			if (Menu::Settings::currentOption == 30) {
				Menu::OptionInfo("Insight wannabe");
			}
		
		
		}
		break;
		case shootvehicles:
		{
			Menu::Title("");
			Menu::SubTitle("Shoot Vehicles");
			Menu::Toggle("Lazer", Weap::ShootCars);
			Menu::Toggle("Annihilator", Weap::ShootCars1);
			Menu::Toggle("Oppressor", Weap::ShootCars2);
			Menu::Toggle("Vader", Weap::ShootCars3);
			Menu::Toggle("Rebel", Weap::ShootCars4);
			Menu::Toggle("Adder", Weap::ShootCars5);
			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Toggle And Fire Vehicle");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Toggle And Fire Vehicle");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Toggle And Fire Vehicle");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Toggle And Fire Vehicle");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Toggle And Fire Vehicle");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Toggle And Fire Vehicle");
			}
		}
		break;
		case ExternalWeapOption:
		{
			Menu::Title("");
			Menu::SubTitle("External Options");
			//Menu::Toggle("Insane Powered Bullet", Weap::bulletforce);
			Menu::Toggle("Bullet Damage", Weap::bulletforcePed);
			Menu::Toggle("Muzzle Velocity", Weap::bulletforceStreetVehicle);
			Menu::Toggle("No Bullet Spread", Weap::bulletforceHeli);
			Menu::Toggle("Speed Cola", Weap::bulletforceReload);
			Menu::Toggle("No Recoil", Weap::bulletforceRecoil);
			if (Menu::Option("Reset All Multiplier")) { 
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_RECOIL }, 1.f);
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 50.f);
				Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1.0f);
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_MUZZLE_VELOCITY }, 1.f);
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_SPREAD }, 1.f);
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_SHOT_TIME }, 1.f);
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_RELOAD_MULTIPLY }, 1.f);
				Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_RELOAD_SPEED }, 1.f);

			}
			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Bullet Does More Damage");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Quicker Velocity");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("No Bullet Spread");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Never Played Black Ops 2 ?!?");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Diseable All Recoil");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Reset All The Game Basic Values");
			}
		}
		break;
		case Impactt:
		{
			Menu::Title("");
			Menu::SubTitle("Shoot Impact");
			Menu::Toggle("Fire Types", Explodegunn);
			if (Menu::Int("Type", Explosionfick, 1, 73))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					Explosionfick = NumberKeyboard();
				}
			}
			if (Menu::Int("Hight", ficksize, 1, 10))
			{
				if (IsKeyPressed(VK_NUMPAD5)) {
					ficksize = NumberKeyboard();
				}
			}
			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Enable Impact");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Edit Impact");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Edit Hight");
			}
		}
		break;
		case Entityss:
		{
			Menu::Title("");
			Menu::SubTitle("Shoot Entities");
			if (Menu::Addintchar("Model:", PickupEnt, lul, 0, 9))
			{
				if (lul == 0)
				{
					EntiThing = "prop_asteroid_01"; 
				}
				if (lul == 1)
				{
					EntiThing = "p_spinning_anus_s"; 
				}
				if (lul == 2)
				{
					EntiThing = "prop_xmas_tree_int";
					
				}
				if (lul == 3)
				{
					EntiThing = "vw_prop_vw_colle_alien";

				}
				if (lul == 4)
				{
					EntiThing = "dt1_lod_slod3";

				}
				if (lul == 5)
				{
					EntiThing = "ch3_01_dino";

				}
				if (lul == 6)
				{
					EntiThing = "vb_34_beachn_02_shark";

				}
				if (lul == 7)
				{
					EntiThing = "cs2_08_crowman";

				}
				if (lul == 8)
				{
					EntiThing = "ap1_01_a_keepclear";

				}
				if (lul == 9)
				{
					EntiThing = "plg_04_beaver001";

				}
			}
			if (Menu::Int("Distance:", distancee, 1, 100, 1))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::hornpower = NumberKeyboard();
				}
			}
			Menu::Toggle("Enable", SA);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Edit Model | Press Enter To Select");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Edit Distance");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Enable");
			}
		}
		break;
		case shootstuff:
		{
			Menu::Title("");
			Menu::SubTitle("Shoot Pickups");
			if (Menu::Addintchar("Pick Up Selection", LPName, Weap::LPNPos1, 0, 145)) {}
			Menu::Toggle("Enable", Weap::somethinggun);
			
			if (Menu::Int("Amount", Weap::Amount, 0, 2500))
			{
				{
					if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
					{
						Weap::Amount = NumberKeyboard();
					}
				}
			}




			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Enable");
			}
			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Edit Model");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Edit Amount");
			}
		}
		break;
#pragma endregion 
#pragma region Vehicle Stuff
		case vehicles:
		{
			Menu::Title("");
			Menu::SubTitle("Vehicles");
			Menu::MenuOption("Customize Vehicle", cs);
			Menu::MenuOption("Vehicle Spawner", vehspawnersub);
			Menu::MenuOption("Modded Vehicles", modveh);
			Menu::MenuOption("Funny Car Builder", funnycar);
			Menu::MenuOption("Acrobatics", vehacro);
			Menu::MenuOption("Weapons", vw);
			Menu::MenuOption("Particles", vp);
			Menu::MenuOption("Horn Boost", hornbooostt);
			if (Menu::Option("Max Upgrade")) {
				{

					Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
					VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, 0);
					VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
					for (int i = 0; i < 50; i++)
					{
						VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
					}
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Foxy");
				}
			}
			Menu::Toggle("Invincible", Veh::cargod);
			Menu::Toggle("Invisible", VehicleInvisible2);
			Menu::Toggle("Vehicle Fly", Veh::FlyCar);
			Menu::Toggle("No Clip", Veh::Flying);
			if (Menu::Float("Speed:", Veh::Speed, 0.0f, 1000.0f, 0.1f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::hornpower = NumberKeyboard();
				}
			}
			Menu::Toggle("Rainbow Car", Veh::Rainbowcar);
			Menu::Toggle("Instant Brake", Veh::InstantBreak);
			Menu::Toggle("No Bike Fall", Veh::bikeNoFall);
			Menu::Toggle("Container Rider", Veh::CR);
			Menu::Toggle("Auto Repair", Fixloop);
			Menu::Toggle("Matrix Plate", Matrix);
			Menu::Toggle("Drift Vehicle", Veh::DV);
			Menu::Toggle("Drive on Water", Veh::DriveWater);
			Menu::Toggle("Bypass Speed Limit", BypassSpeedLimit);
			Menu::Toggle("Ground Vehicle", ground);
			Menu::Toggle("Glitchy Vehicle", nocollision);
			Menu::Toggle("360 Vehicle", nocollision2);
			if (Menu::Option("Add Blip")) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0);
				Vehicle e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(e, 1);
				for (int i = 0; i < 350; i++) {
					NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(e));
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
				}
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(e, true, true);
				for (int i = 0; i < 350; i++)NETWORK::SET_NETWORK_ID_CAN_MIGRATE(e, 0);
				VEHICLE::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(e, 1);
				int b;
				char bname[] = "Vehicle";
				b = UI::ADD_BLIP_FOR_ENTITY(e);
				UI::SET_BLIP_SPRITE(b, 60);
				UI::SET_BLIP_NAME_FROM_TEXT_FILE(b, bname);
			}
			if (Menu::Option("Add Ramp")) {
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
				{
					Vector3 Him = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
					int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
					STREAMING::REQUEST_MODEL(0xB157C9E4);
					if (STREAMING::HAS_MODEL_LOADED(0xB157C9E4))
					{
						Entity My_Objects = OBJECT::CREATE_OBJECT(0xB157C9E4, Him.x, Him.y, Him.z, 1, 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(My_Objects))
						{
							ENTITY::SET_ENTITY_COLLISION(My_Objects, true, true);
							ENTITY::SET_ENTITY_ALPHA(My_Objects, 120, false);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(My_Objects, VehicleID, 0, 0, 6.3, -0.3, 13.5, 0, 177.5, 0, 0, true, 0, 2, 1);
						}
					}
				}
				else {
					notifyMap("Get in a vehicle");
				}
			}
			if (Menu::Option("Flip Car")) {
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
			}
			if (Menu::Option("Open Doors")) {
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
			}
			if (Menu::Option("Close Doors")) {
				VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
			}
			if (Menu::Option("Change Smoke Color"))//NEW
			{

				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
				VEHICLE::TOGGLE_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));


			}
			if (Menu::Option("Custom Plate")) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CharKeyboard());
			}
			if (Menu::Option("Change Plate to Foxy")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Foxy");
			}
			if (Menu::Option("Repair Vehicle")) {
				uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				VEHICLE::SET_VEHICLE_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
			}
			if (Menu::Option("Clean Vehicle")) {
				GRAPHICS::WASH_DECALS_FROM_VEHICLE(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 100.0f);
			}
			if (Menu::Option("Add Big Ramp")) {
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
				{
					Vector3 Him = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
					int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
					STREAMING::REQUEST_MODEL(3681122061);
					if (STREAMING::HAS_MODEL_LOADED(3681122061))
					{
						Entity My_Objects = OBJECT::CREATE_OBJECT(3681122061, Him.x, Him.y, Him.z, 1, 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(My_Objects))
						{
							ENTITY::SET_ENTITY_COLLISION(My_Objects, true, true);
							ENTITY::SET_ENTITY_ALPHA(My_Objects, 120, false);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(My_Objects, VehicleID, 0, 0, 6.3, -0.3, 13.5, 0, 177.5, 0, 0, true, 0, 2, 1);
						}
					}
				}
			}
			Menu::Toggle("Sport Mode", Veh::SportMode);
			Menu::Toggle("Beyblade", Veh::BeyBlade);
			Menu::Toggle("Save Any Vehicle In Your Garage", garage_save_bypass);
		

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Customize Vehicle Sub");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Vehicle Spawner Sub");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Modded Vehicles");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Funny Car Sub");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Acrobatics Sub");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Weapons Sub");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Particles Sub");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Horn Boost Sub");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Max Settings On Your Vehicle");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Unable To Take Damage");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Make Your Vehicle Invisible");
			}
			if (Menu::Settings::currentOption == 12) {
				Menu::OptionInfo("Fly Around In Your Vehicle");
			}
			if (Menu::Settings::currentOption == 13) {
				Menu::OptionInfo("Clip Trough Entities In Your Vehicle");
			}
			if (Menu::Settings::currentOption == 14) {
				Menu::OptionInfo("Vehicle No Clip Speed");
			}
			if (Menu::Settings::currentOption == 15) {
				Menu::OptionInfo("Your Vehicle Will Smoothly Change Color");
			}
			if (Menu::Settings::currentOption == 16) {
				Menu::OptionInfo("Instantly Stops Your Vehicle | R");
			}
			if (Menu::Settings::currentOption == 17) {
				Menu::OptionInfo("Unable To Fall Off Your Bike");
			}
			if (Menu::Settings::currentOption == 18) {
				Menu::OptionInfo("Ride On Containers");
			}
			if (Menu::Settings::currentOption == 19) {
				Menu::OptionInfo("Auto Repair Your Vehicle");
			}
			if (Menu::Settings::currentOption == 20) {
				Menu::OptionInfo("Shifting Numbers On Your Plate");
			}
			if (Menu::Settings::currentOption == 21) {
				Menu::OptionInfo("Drifts Your Vehicle");
			}
			if (Menu::Settings::currentOption == 22) {
				Menu::OptionInfo("Drive On Water");
			}
			if (Menu::Settings::currentOption == 23) {
				Menu::OptionInfo("Bypass Your Vehicle's Speed Limit");
			}
			if (Menu::Settings::currentOption == 24) {
				Menu::OptionInfo("Grounds Your Vehicle");
			}
			if (Menu::Settings::currentOption == 25) {
				Menu::OptionInfo("Glitch Your Vehicle");
			}
			if (Menu::Settings::currentOption == 26) {
				Menu::OptionInfo("Donuts");
			}
			if (Menu::Settings::currentOption == 27) {
				Menu::OptionInfo("Adds An Icon On Your Vehicle");
			}
			if (Menu::Settings::currentOption == 28) {
				Menu::OptionInfo("Adds a Ramp On Your Vehicle");
			}
			if (Menu::Settings::currentOption == 29) {
				Menu::OptionInfo("Flips Your Car To An Upright Position");
			}
			if (Menu::Settings::currentOption == 30) {
				Menu::OptionInfo("Opens All Doors");
			}
			if (Menu::Settings::currentOption == 31) {
				Menu::OptionInfo("Closes All Doors");
			}
			if (Menu::Settings::currentOption == 32) {
				Menu::OptionInfo("Change Your Smoke Color");
			}
			if (Menu::Settings::currentOption == 33) {
				Menu::OptionInfo("Choose Your Numberplate's Text");
			}
			if (Menu::Settings::currentOption == 34) {
				Menu::OptionInfo("Change The Plate To I Am War");
			}
			if (Menu::Settings::currentOption == 35) {
				Menu::OptionInfo("Fix Your Vehicle");
			}
			if (Menu::Settings::currentOption == 36) {
				Menu::OptionInfo("Clean Your Vehicle");
			}
			if (Menu::Settings::currentOption == 37) {
				Menu::OptionInfo("Skate Park Ramp");
			}
			if (Menu::Settings::currentOption == 38) {
				Menu::OptionInfo("Fly Like Luna Menu");
			}
			if (Menu::Settings::currentOption == 39) {
				Menu::OptionInfo("Let It RIP");
			}

		}
		break;
#pragma endregion
#pragma region Vehicle Menu
		case hornbooostt:
		{
			Menu::Title("");
			Menu::SubTitle("Hornboost");
			Menu::Toggle("Boost Effect", Veh::Boosttt);
			if (Menu::Int("Boost Level:", Veh::Boostttt, 0, 1000, 10))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::hornpower = NumberKeyboard();
				}
			}
			Menu::Toggle("Enable Boost", Veh::Boost);
		}
		break;
		case multi:
		{
			Veh::Multi();
		}
		break;
		case LSCWW:
		{
			Spawner::MLSC();
		}
		break;
		case Bennyss:
		{
			Spawner::Bennyss();
		}
		break;
		case wars:
		{
			Spawner::wars();
		}
		break;
		case Resprayss:
		{
			Spawner::Resprayss1();
		}
		break;
		case vehacro:
		{
			Veh::Acro();
		}
		break;
		case cs:
		{
			Menu::Title("");
			Menu::SubTitle("Customize Vehicle");
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		
			Menu::MenuOption("Vehicle Stats", multi);
			if (carhash == 0x25C5AF13 || carhash == 0xC397F748 || carhash == 0xAED64A63 || carhash == 0x9C669788 || carhash == 0x877358AD || carhash == 0x95466BDB || carhash == 0x866BCE26 || carhash == 0xD2D5E00E || carhash == 0x4131F378 || carhash == 0xBCDE91F0 || carhash == 0x710A2B9B || carhash == 0xE33A477B || carhash == 0x86618EDA || carhash == 0x0D4EA603 || carhash == 0x42BC5E19 || carhash == 0x94DA98EF || carhash == 0x00FDFFB0 || carhash == 0x779B4F2D || carhash == 0xEE6024BC)
			{
				Menu::MenuOption("Bennys", Bennyss);// puts bennys if its a cars from above^
			}/*check if the hash exists and if there vehicle hash existe then puts Arena Wars LSC*/
			else if (carhash == 0x8D45DF49 || carhash == 0xA7DCC35C || carhash == 0xBE11EFC6 || carhash == 0x20314B42 || carhash == 0x32174AFC || carhash == 0xD556917C || carhash == 0x67D52852 || carhash == 0x49E25BA1 || carhash == 0x287FA449 || carhash == 0x71D3B6F0 || carhash == 0x93F09558 || carhash == 0x9804F4C7 || carhash == 0x8526E2F5 || carhash == 0x163F8520 || carhash == 0x7F81A829 || carhash == 0x8F49AE28 || carhash == 0x798682A2 || carhash == 0xFE5F0722 || carhash == 0xD6FB0F30 || carhash == 0xAE0A3D4F || carhash == 0x27D79225 || carhash == 0x9B065C9E || carhash == 0x8644331A || carhash == 0xEEF345EC || carhash == 0xD039510B || carhash == 0x3C26BD0C || carhash == 0x56D42971 || carhash == 0x669EB40A || carhash == 0xBBA2A2F7 || carhash == 0x5BEB3CE0 || carhash == 0xDD71BFEB || carhash == 0x256E92BA || carhash == 0x5BA0FF1E || carhash == 0xA29F78B0 || carhash == 0xFD128DFD || carhash == 0x1A861243 || carhash == 0x619C1B82 || carhash == 0xD2F77E37 || carhash == 0x4C3FFF49 || carhash == 0xBA5334A)
			{
				Menu::MenuOption("Arena Wars LSC", wars);// puts Arena Wars LSC if its a cars from above^
			}
			else
			{                  /*check if the player exists and if there vehicle existe then puts LSC*/
				Menu::MenuOption("Los Santos Customs", LSCWW);
			}
		}
		break;
		case vw:
		{
			Veh::CarGunMain();
		}
		break;
		case vp:
		{
			Veh::vp();
		}
		break;
		case modveh:
		{
			Ini::IniMenu();
		}
		break;
		case IPL:
		{
			Map::IPLS();
		}
		break;
#pragma endregion
#pragma endregion World
		case world:
		{
			Menu::Title("");
			Menu::SubTitle("World");
			Menu::MenuOption("Map Modifications", maps);
			Menu::MenuOption("Spawn Map Section", spawnmap);
			Menu::MenuOption("Black Hole", blackhole);
			Menu::MenuOption("AI Driver", driver);
			Menu::MenuOption("Pedestrians & Vehicles", pedveh);
			Menu::MenuOption("Weather", weather);
			Menu::MenuOption("Time", times);
			Menu::MenuOption("Water", Water);
			Menu::MenuOption("Snow", Snoweditor);
			Menu::MenuOption("Wind", Wind);
			Menu::MenuOption("Light", Lighting);
			Menu::MenuOption("Radio", Radioeditor);
			Menu::MenuOption("Cutscene Editor", Cutsceneeditor);
			Menu::MenuOption("HUD Editor", freemodetheme);
			Menu::Toggle("Hide Hud", Misc::Hidehudtoggle);
			Menu::Toggle("No Vehicle Sell Cooldown", Misc::Sell);
			Menu::Toggle("Missile Rain", Misc::AirstrikeShower);
			Menu::Toggle("Stone Rain", Misc::AS);
			Menu::Toggle("Expand World", expand);
			
			if (Menu::Option("Skip Cutscenes"))
			{
				CUTSCENE::STOP_CUTSCENE;
				CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
			}
			if (Menu::Option("Spawn A Car To Sell")) 
			{
				{
					Ped You = PLAYER::PLAYER_PED_ID();
					BOOL AreYouReal = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());
					if (AreYouReal)
					{
						ENTITY::SET_ENTITY_COORDS(You, -368.0f, -130.607f, 37.648f, 0, 0, 0, 1);
						WAIT(400);
						Hash hash = GAMEPLAY::GET_HASH_KEY("PENUMBRA");
						STREAMING::REQUEST_MODEL(hash);
						while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
						Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0);
						Vehicle veh = VEHICLE::CREATE_VEHICLE(hash, pos.x, pos.y, pos.z, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 1);
						VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
						VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 120);
						VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, rand() % 255, rand() % 255, rand() % 255);
						VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
						VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
						VEHICLE::SET_VEHICLE_MOD(veh, 16, 5, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 12, 2, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 11, 3, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 14, 14, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 15, 3, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 13, 2, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 6);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, 5);
						VEHICLE::SET_VEHICLE_MOD(veh, 23, 14, 2);
						VEHICLE::SET_VEHICLE_MOD(veh, 0, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 1, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 2, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 3, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 4, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 5, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 6, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 7, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 8, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 9, 1, 0);
						VEHICLE::SET_VEHICLE_MOD(veh, 10, 1, 0);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 0, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 1, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 2, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 3, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
						WAIT(60);

						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);

						WAIT(10);

					}
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
					{
						Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
						if (ENTITY::DOES_ENTITY_EXIST(playerVeh) && !ENTITY::IS_ENTITY_DEAD(playerVeh))
							Other::set_vehicle_max_upgrades(playerVeh, true, false, 1, "190k", true, 100, 0, 100, 1, 2);
					}
					Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 255, 119);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 255, 119);
				}
			}
			if (Menu::Option("Solo Session"))
			{
				Sleep(10000);
				WAIT(250);
			}
			if (Menu::Addintchar("Gravity Level:", grav, vity, 0, 2))
			{
				if (vity == 0)
				{
					GAMEPLAY::SET_GRAVITY_LEVEL(0);
				}
				if (vity == 1)
				{
					GAMEPLAY::SET_GRAVITY_LEVEL(2);
				}
				if (vity == 2)
				{
					GAMEPLAY::SET_GRAVITY_LEVEL(2);
				}
			}

			
			Menu::Toggle("Apocalypse", Apocalypse);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Map Modifications Sub");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Spawn Map");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Black Hole Sub");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("AI Driver Sub");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Pedestrians & Vehicles Sub");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Weather Sub");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Time Sub");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Water Sub");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Snow Sub");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Wind Sub");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Light Sub");
			}
			if (Menu::Settings::currentOption == 12) {
				Menu::OptionInfo("Radio Editor Sub");
			}
			if (Menu::Settings::currentOption == 13) {
				Menu::OptionInfo("Cutscene Editor Sub");
			}
			if (Menu::Settings::currentOption == 14) {
				Menu::OptionInfo("Change HUD Color");
			}
			if (Menu::Settings::currentOption == 15) {
				Menu::OptionInfo("Hides HUD");
			}
			if (Menu::Settings::currentOption == 16) {
				Menu::OptionInfo("Bypass LSC Vehicle Sale Cooldown");
			}
			if (Menu::Settings::currentOption == 17) {
				Menu::OptionInfo("Missiles Raining From The Sky");
			}
			if (Menu::Settings::currentOption == 18) {
				Menu::OptionInfo("Meteors Raining From The Sky");
			}
			if (Menu::Settings::currentOption == 19) {
				Menu::OptionInfo("INFINITE WORLD");
			}
			if (Menu::Settings::currentOption == 20) {
				Menu::OptionInfo("Lag is Normal Just Wait");
			}
			if (Menu::Settings::currentOption == 21) {
				Menu::OptionInfo("Spawn a 190k Car To Sell");
			}
			if (Menu::Settings::currentOption == 22) {
				Menu::OptionInfo("Make Your Game Lonely (Online Public Session)");
			}
			if (Menu::Settings::currentOption == 23) {
				Menu::OptionInfo("Select A Gravity Type");
			}
			if (Menu::Settings::currentOption == 24) {
				Menu::OptionInfo("Apocalypse [IN DEV]");
			}
		}
		break;
		case maps:
		{
			Map::MapMainMenu();
		}
		break;
		case blackhole:
		{
			BH::Sub();
		}
		break;
		case blackhole2:
		{
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			BH::Sub2();
		}
		break;
		case times:
		{
			Menu::Title("");
			Menu::SubTitle("Time");
			if (Menu::Int("Hour:", Timehour, 0, 23))
			{
				NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(Timehour, Timemin, Timesec);
			}
			if (Menu::Int("Minute:", Timemin, 0, 60))
			{
				NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(Timehour, Timemin, Timesec);
			}
			if (Menu::Int("Second:", Timesec, 0, 60));
			{
				TIME::SET_CLOCK_TIME(Timehour, Timemin, Timesec);
			}
			Menu::Toggle("Freeze Time", Misc::ft);
		}
		break;
		case Snoweditor:
		{
			Menu::Title("");
			Menu::SubTitle("Snow");
			if (Menu::Float("Choose Snow Particule Intensity", snowlevel, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					snowlevel = NumberKeyboarde();
					GAMEPLAY::_SET_SNOW_LEVEL(snowlevel);
				}
			}
			Menu::Toggle("Snow Foot Track", snowfoottrack);
			Menu::Toggle("Snow Tire Track", snowtiretrack);
		}
		break;
		case Water:
		{
			Menu::Title("");
			Menu::SubTitle("Water");
			if (Menu::Float("Choose Wave Intensity", waves, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					waves = NumberKeyboarde();
					WATER::_SET_CURRENT_INTENSITY(waves);
				}
			}
			if (Menu::Float("Choose Shore Amplitude", shoreamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					shoreamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_SHOREWAVEAMPLITUDE(shoreamplitude);
				}
			}
			if (Menu::Float("Choose Shore Max Amplitude", shoremaxamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					shoremaxamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_SHOREWAVEMAXAMPLITUDE(shoremaxamplitude);
				}
			}
			if (Menu::Float("Choose Shore Min Amplitude", shoreminamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					shoreminamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_SHOREWAVEMINAMPLITUDE(shoreminamplitude);
				}
			}
			if (Menu::Float("Choose Shore Noise", shoremaxnoise, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					shoremaxnoise = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_OCEANNOISEMINAMPLITUDE(shoremaxnoise);
				}
			}
			if (Menu::Float("Choose Ocean Wave Amplitude", oceanwaveamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					oceanwaveamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_OCEANWAVEAMPLITUDE(oceanwaveamplitude);
				}
			}
			if (Menu::Float("Choose Ocean Wave Max Amplitude", oceanwavemaxamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					oceanwavemaxamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_OCEANWAVEMAXAMPLITUDE(oceanwavemaxamplitude);
				}
			}
			if (Menu::Float("Choose Ocean Wave Min Amplitude", oceanwaveminamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					oceanwaveminamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_OCEANWAVEMINAMPLITUDE(oceanwaveminamplitude);
				}
			}
			if (Menu::Float("Choose Ripple Bumpiness", ripplebumpinesseamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					ripplebumpinesseamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_RIPPLEBUMPINESS(ripplebumpinesseamplitude);
				}
			}
			if (Menu::Float("Choose Ripple Bumpiness Max", ripplebumpinessemaxamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					ripplebumpinessemaxamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_RIPPLEMAXBUMPINESS(ripplebumpinessemaxamplitude);
				}
			}
			if (Menu::Float("Choose Ripple Bumpiness Min", ripplebumpinesseminamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					ripplebumpinesseminamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_RIPPLEMINBUMPINESS(ripplebumpinesseminamplitude);
				}
			}
			if (Menu::Float("Choose Ripple Disturbed", rippledisturbedamplitude, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					rippledisturbedamplitude = NumberKeyboarde();
					GAMEPLAY::WATER_OVERRIDE_SET_RIPPLEDISTURB(rippledisturbedamplitude);
				}
			}
			if (Menu::Addintchar("Water Comportement", WaterStrenght, WaterStrenght_int, 0, 2))
			{
				if (WaterStrenght_int == 0)
				{
					GAMEPLAY::WATER_OVERRIDE_SET_STRENGHT(0.f);
				}
				if (WaterStrenght_int == 1)
				{
					GAMEPLAY::WATER_OVERRIDE_SET_STRENGHT(1.f);
				}
				if (WaterStrenght_int == 2)
				{
					GAMEPLAY::WATER_OVERRIDE_SET_STRENGHT(3.f);
				}
			}
			if (Menu::Float("Choose Rain Intensity", Rain_, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					Rain_ = NumberKeyboarde();
					GAMEPLAY::_SET_RAIN_FX_INTENSITY(Rain_);
				}
			}
		}
		break;
		case Lighting:
		{
			Menu::Title("");
			Menu::SubTitle("Lighting");
			Menu::Toggle("Glowing World", Worldglow);
			Menu::Toggle("Glowing World Fade Color", WorldglowRGB);
			if (Menu::Float("Choose Glow Intensity", world_glow_intensity, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_intensity = NumberKeyboarde();
				}
			}
			if (Menu::Float("Choose Glow Range", world_glow_range, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_range = NumberKeyboarde();
				}
			}
			if (Menu::Int("Red", world_glow_red, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_red = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", world_glow_green, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_green = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", world_glow_blue, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_blue = NumberKeyboard();
				}
			}

			Menu::Toggle("VFX Color", Worldglow1);
			Menu::Toggle("VFX Fade Color", WorldglowRGB1);
			if (Menu::Float("VFX Color Intensity", world_glow_intensity1, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_intensity1 = NumberKeyboarde();
				}
			}
			if (Menu::Float("VFX Shadow", world_glow_shadow, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_shadow = NumberKeyboarde();
				}
			}
			if (Menu::Int("Red", world_glow_red1, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_red1 = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", world_glow_green1, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_green1 = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", world_glow_blue1, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_blue1 = NumberKeyboard();
				}
			}

			Menu::Toggle("Spot Light", Worldglow2);
			Menu::Toggle("Spot Light Fade Color", WorldglowRGB2);
			if (Menu::Float("Spot Light Color Intensity", world_glow_intensity2, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_intensity2 = NumberKeyboarde();
				}
			}

			if (Menu::Float("Spot Light Range", world_glow_range2, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_range2 = NumberKeyboarde();
				}
			}
			if (Menu::Float("Spot Light Hardness", hardness, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					hardness = NumberKeyboarde();
				}
			}
			if (Menu::Float("Spot Light Radius", radius, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					radius = NumberKeyboarde();
				}
			}
			if (Menu::Float("Spot Light Fall Off", falloff, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					falloff = NumberKeyboarde();
				}
			}
			if (Menu::Int("Red", world_glow_red2, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_red2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", world_glow_green2, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_green2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", world_glow_blue2, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_blue2 = NumberKeyboard();
				}
			}


			Menu::Toggle("Spot Light Whit Shadow", Worldglow3);
			Menu::Toggle("Spot Light Fade Color", WorldglowRGB3);
			if (Menu::Float("Spot Light Color Intensity", world_glow_intensity3, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_intensity3 = NumberKeyboarde();
				}
			}

			if (Menu::Float("Spot Light Range", world_glow_range3, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					world_glow_range3 = NumberKeyboarde();
				}
			}
			if (Menu::Float("Spot Light Hardness", hardness2, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					hardness2 = NumberKeyboarde();
				}
			}
			if (Menu::Float("Spot Light Radius", radius2, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					radius2 = NumberKeyboarde();
				}
			}
			if (Menu::Float("Spot Light Fall Off", falloff2, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					falloff2 = NumberKeyboarde();
				}
			}
			if (Menu::Int("Shadow", shadowid, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					shadowid = NumberKeyboard();
				}
			}
			if (Menu::Int("Red", world_glow_red3, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_red3 = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", world_glow_green3, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_green3 = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", world_glow_blue3, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					world_glow_blue3 = NumberKeyboard();
				}
			}



		}
		break;
		case Radioeditor:
		{
			Menu::Title("");
			Menu::SubTitle("Radio");
			Menu::Toggle("Mobile Radio", Local::MobileRadio);
			if (Menu::Option("Freeze/Unfreeze Radio Station")) {
				if (radio_status_variable == 0) {
					AUDIO::FREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME());
					radio_status_variable = 1;
				}
				else if (radio_status_variable == 1) {
					AUDIO::UNFREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME());
					radio_status_variable = 0;
				}
			}
			if (Menu::Option("Skip Music")) { AUDIO::SKIP_RADIO_FORWARD(); }
			if (Menu::Option("Los Santos Rock Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_01_CLASS_ROCK"); }
			if (Menu::Option("Non-Stop-Pop FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_02_POP"); }
			if (Menu::Option("Radio Los Santos")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_03_HIPHOP_NEW"); }
			if (Menu::Option("Channel X")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_04_PUNK"); }
			if (Menu::Option("West Coast Talk Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_05_TALK_01"); }
			if (Menu::Option("Rebel Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_06_COUNTRY"); }
			if (Menu::Option("Soulwax FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_07_DANCE_01"); }
			if (Menu::Option("East Los FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_08_MEXICAN"); }
			if (Menu::Option("West Coast Classics")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_09_HIPHOP_OLD"); }
			if (Menu::Option("Blue Ark")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_12_REGGAE"); }
			if (Menu::Option("Worldwide FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_13_JAZZ"); }
			if (Menu::Option("FlyLo FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_14_DANCE_02"); }
			if (Menu::Option("The Lowdown 91.1")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_15_MOTOWN"); }
			if (Menu::Option("The Lab")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_20_THELAB"); }
			if (Menu::Option("Radio Mirror Park")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_16_SILVERLAKE"); }
			if (Menu::Option("Space 103.2")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_17_FUNK"); }
			if (Menu::Option("Vinewood Boulevard Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_18_90S_ROCK"); }
			if (Menu::Option("Blonded Los Santos 97.8 FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_21_DLC_XM17"); }
			if (Menu::Option("Blaine County Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_11_TALK_02"); }
			if (Menu::Option("Los Santos Underground Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_22_DLC_BATTLE_MIX1_RADIO"); }
			if (Menu::Option("Music Locker")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_35_SHORT"); }
			if (Menu::Option("Motomami Los Santos")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_37_SHORT"); }
			if (Menu::Option("Kult FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_34_SHORT"); }
			if (Menu::Option("Still Slipping Los Santos")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_27_DLC_PRHEI4"); }
			if (Menu::Option("Ifruit Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_23_DLC_SHORT"); }
			if (Menu::Option("Media Player")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_36_SHORT"); }
			if (Menu::Option("Self Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_19_USER"); }
			if (Menu::Option("Hidden Radio Classic Rock")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_01_CLASS_ROCK"); }
			if (Menu::Option("Hidden Radio Ambient Bright")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_AMBIENT_TV_BRIGHT"); }
			if (Menu::Option("Hidden Radio Ambient")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_AMBIENT_TV"); }
			if (Menu::Option("Hidden Radio Adds")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_ADVERTS"); }
			if (Menu::Option("Hidden Radio Popular")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_02_POP"); }
			if (Menu::Option("Hidden Radio Hiphop")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_03_HIPHOP_NEW"); }
			if (Menu::Option("Hidden Radio Punk")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_04_PUNK"); }
			if (Menu::Option("Hidden Radio Country")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_06_COUNTRY"); }
			if (Menu::Option("Hidden Radio Dance")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_07_DANCE_01"); }
			if (Menu::Option("Hidden Radio Old Hiphop")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_09_HIPHOP_OLD"); }
			if (Menu::Option("Hidden Radio Reggae")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_12_REGGAE"); }
			if (Menu::Option("Hidden Radio Motwon")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_15_MOTOWN"); }
			if (Menu::Option("Hidden Radio Silverlake")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_16_SILVERLAKE"); }
			if (Menu::Option("Hidden Radio Strip Club")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_STRIP_CLUB"); }
			if (Menu::Option("Hidden Radio Biker Classic Rock")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_CLASSIC_ROCK"); }
			if (Menu::Option("Hidden Radio Biker Moder Rock")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_MODERN_ROCK"); }
			if (Menu::Option("Hidden Radio Biker Punk")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_PUNK"); }
			if (Menu::Option("Hidden Radio Biker Hiphop")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_HIP_HOP"); }
			if (Menu::Option("Battle Mix 1")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_22_DLC_BATTLE_MIX1_CLUB"); }
			if (Menu::Option("Battle Mix 2")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX1_CLUB_PRIV"); }
			if (Menu::Option("Battle Mix 3")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX2_CLUB_PRIV"); }
			if (Menu::Option("Battle Mix 4")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_23_DLC_BATTLE_MIX2_CLUB"); }
			if (Menu::Option("Battle Mix 5")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_25_DLC_BATTLE_MIX4_CLUB"); }
			if (Menu::Option("Battle Mix 6")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX4_CLUB_PRIV"); }
			if (Menu::Option("Battle Mix 7")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_24_DLC_BATTLE_MIX3_CLUB"); }
			if (Menu::Option("Battle Mix 8")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX3_CLUB_PRIV"); }
			if (Menu::Option("Battle Mix Warmup")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_26_DLC_BATTLE_CLUB_WARMUP"); }
		}
		break;
		case Cutsceneeditor:
		{
			Menu::Title("");
			Menu::SubTitle("Cutscene Editor");
			if (Menu::Option("Skip Cutscenes"))
			{
				CUTSCENE::STOP_CUTSCENE;
				CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
				CUTSCENE::REMOVE_CUTSCENE();
			}
			for (int i = 0; i < ARRAYSIZE(Cutscene); i++)
			{
				if (Menu::Option(Cutscene[i]))
				{
					CUTSCENE::REQUEST_CUTSCENE(Cutscene[i], 8);
					while (!CUTSCENE::HAS_CUTSCENE_LOADED()) WAIT(0);
					CUTSCENE::SET_CUTSCENE_FADE_VALUES(0, 0, 1, 0);
					CUTSCENE::START_CUTSCENE(0);
					CAM::SET_WIDESCREEN_BORDERS(0, 0);
					AUDIO::SET_RADIO_TO_STATION_NAME("OFF");
				}
			}

			
		}
		break;
		case Wind:
		{
			Menu::Title("");
			Menu::SubTitle("Wind");
			if (Menu::Float("Choose Wind Intensity", s0uthwind, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					s0uthwind = NumberKeyboarde();
					GAMEPLAY::SET_WIND_SPEED(s0uthwind);
				}
			}
			if (Menu::Float("Choose Wind Direction", WindDirection, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					WindDirection = NumberKeyboarde();
					GAMEPLAY::SET_WIND_DIRECTION(WindDirection);
				}
			}
			if (Menu::Option("North East")) { GAMEPLAY::SET_WIND_DIRECTION(1.0); }
			if (Menu::Option("North West")) { GAMEPLAY::SET_WIND_DIRECTION(7.0); }
			if (Menu::Option("East")) { GAMEPLAY::SET_WIND_DIRECTION(2.0); }
			if (Menu::Option("South")) { GAMEPLAY::SET_WIND_DIRECTION(4.0); }
			if (Menu::Option("South West")) { GAMEPLAY::SET_WIND_DIRECTION(5.0); }
			if (Menu::Option("South East")) { GAMEPLAY::SET_WIND_DIRECTION(3.0); }
			if (Menu::Option("West")) { GAMEPLAY::SET_WIND_DIRECTION(6.0); }
		}
		break;
		case weather:
		{
			Menu::Title("");
			Menu::SubTitle("Weather");
			if (Menu::Float("Choose Moon Cycle", mooncycle, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					mooncycle = NumberKeyboarde();
					GRAPHICS::_0x2C328AF17210F009(mooncycle);
				}
			}
			if (Menu::Option("~f~[ ~w~Weather ~f~]")) {}
			if (Menu::Option("Sunny")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
			if (Menu::Option("Clouds")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }
			if (Menu::Option("Blizzard")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
			if (Menu::Option("Overcast")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
			if (Menu::Option("Smog")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
			if (Menu::Option("Foggy")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
			if (Menu::Option("Thunder")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
			if (Menu::Option("Lighting")) { GAMEPLAY::_CREATE_LIGHTNING_THUNDER(); }
			if (Menu::Option("Snowlight")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); }
			if (Menu::Option("Snow")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("xmas"); }
			if (Menu::Option("Halloween")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Halloween"); }
			if (Menu::Option("Neutral")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Neutral"); }
			if (Menu::Addintchar("Mix Weather One", WeatherMixing, WeatherMixing_int, 0, 10)) {}
			if (Menu::Addintchar("Mix Weather Two", WeatherMixing2, WeatherMixing2_int, 0, 10)) {}
			if (Menu::Float("Apply Mix Weather", WeatherMixingFactorOfTransition, 0.00f, 1.f))
			{
				DWORD HashWeather1 = GAMEPLAY::GET_HASH_KEY(WeatherMixing[WeatherMixing_int]);
				DWORD HashWeather2 = GAMEPLAY::GET_HASH_KEY(WeatherMixing2[WeatherMixing2_int]);
				GAMEPLAY::_SET_WEATHER_TYPE_TRANSITION(HashWeather1, HashWeather2, WeatherMixingFactorOfTransition);
			}
			if (Menu::Option("~f~[ ~w~clouds ~f~]")) {}
			if (Menu::Float("Choose Cloud Opacity", Cloudss, 0, 100000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					Cloudss = NumberKeyboarde();
					GAMEPLAY::_SET_CLOUD_HAT_OPACITY(Cloudss);
				}
			}
			if (Menu::Option("Fully Clear Sky")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("noclouds", 2.f); }
			if (Menu::Option("Clear Sky")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("clear 01", 2.f); }
			if (Menu::Option("Cirrocumulus Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("cirrocumulus", 2.f); }
			if (Menu::Option("Cirrus Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("cirrus", 2.f); }
			if (Menu::Option("Cloudy Sky")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("cloudy 01", 2.f); }
			if (Menu::Option("Contrails Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("contrails", 2.f); }
			if (Menu::Option("Puffy Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("puffs", 2.f); }
			if (Menu::Option("Small Rain Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("rain", 2.f); }
			if (Menu::Option("Big Rain Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("shower", 2.f); }
			if (Menu::Option("Snowy Storm Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("snowy 01", 2.f); }
			if (Menu::Option("Storm Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("stormy 01", 2.f); }
			if (Menu::Option("Stratoscumulus Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("stratoscumulus", 2.f); }
			if (Menu::Option("Stripey Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("stripey", 2.f); }
			if (Menu::Option("Wispy Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("wispy", 2.f); }
			if (Menu::Option("Altostratus Cloud")) { GAMEPLAY::_SET_CLOUD_HAT_TRANSITION("altostratus", 2.f); }
			if (Menu::Option("Reset Clouds")) { GAMEPLAY::_CLEAR_CLOUD_HAT(); }
		}
		break;
		case pedveh:
		{
			Misc::MiscMainSub();
		}
		break;
		case spawnmap:
		{

			Menu::Title("");
			Menu::SubTitle("Spawn Map Section");
			if (Menu::Option("~f~[ ~w~Will Spawn In Front Of You ~f~]"))
			{
			}
			Menu::Toggle("Free Cam", Camfree);
			Menu::Toggle("Set Map Freezed", freeze_map);
			if (Menu::Option("Map 1"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("ela_wdn_04_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 2"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("sc1_lod_slod4");//  hei_hw1_06_road = crash
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 3"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("lf_house_04_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 4"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("lf_house_05_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}//done
			if (Menu::Option("Map 5"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("lf_house_09_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 6"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("lf_house_20_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 7"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("prop_helipad_02");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 8"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("db_apart_01d_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 9"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("db_apart_01_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}//done
			if (Menu::Option("Map 10"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("db_apart_02d_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 11"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("db_apart_02_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 12"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("db_apart_03d_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 13"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("db_apart_03_");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 14"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("ch2_lod4_s3c"); // dt1_lod_slod3 dt1_tc_dufo_core hei_hw1_06_road
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 15"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("id1_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 16"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("hw1_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 17"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("po1_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 18"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("ss1_lod_slod3");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 19"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("ap1_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 20"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("kt1_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 21"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("bh1_lod_slod3");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 22"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("sp1_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 23"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("sm_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 24"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("vb_lod_slod4");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			if (Menu::Option("Map 25"))
			{
				Hash map = GAMEPLAY::GET_HASH_KEY("ch1_lod_slod3a");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(map);
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, bonepos.x + 4.f, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::FREEZE_ENTITY_POSITION(map, freeze_map);
			}
			

		}
		break;
		case driver:
		{
			
			Menu::Title("");
			Menu::SubTitle("AI Vehicle Stuff");
			if (Menu::Option("Auto Drive - Drive To Waypoint"))
			{
				Player you = PLAYER::PLAYER_PED_ID();
				Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				Vector3 Coords = get_blip_marker();
				AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(you, Veh, Coords.x, Coords.y, Coords.z, drivesp, drivestyle, 0);
			}
			if (Menu::Option("Quit Ride")) {
				AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
				Sleep(10);
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
				ENTITY::SET_ENTITY_HEADING(PLAYER::GET_PLAYERS_LAST_VEHICLE(), ENTITY::GET_ENTITY_HEADING(playerPed));
				PED::SET_PED_INTO_VEHICLE(playerPed, PLAYER::GET_PLAYERS_LAST_VEHICLE(), -1);
			}

			//	if (Addoption("Stop")) AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
			if (Menu::Option("~f~[ ~w~Auto Drive Setting ~f~]"))
			{
			}
			if (Menu::Int("Drive Speed", drivesp, 0, 120))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					drivesp = NumberKeyboard();
				}
			}
			if (Menu::Option("Normal"))
			{
				drivestyle = 1;
			}
			if (Menu::Option("Avoid Vehicles"))
			{
				drivestyle = 4;
			}
			if (Menu::Option("Avoid Ped"))
			{
				drivestyle = 2;
			}
			if (Menu::Option("Sometimes Overtake Traffic"))
			{
				drivestyle = 5;
			}
			if (Menu::Option("Rushed"))
			{
				drivestyle = 1074528293;
			}
			if (Menu::Option("Ignore Lights "))
			{
				drivestyle = 2883621;
			}
			if (Menu::Option("Avoid Traffic"))
			{
				drivestyle = 786468;
			}
		}
		break;
		case DropAllMenu:
		{
			Menu::Title("");
			Menu::SubTitle("Preset Drop");
			Menu::Toggle("Burton Lsc Rp", Network::burtonrp);
			Menu::Toggle("Burton Lsc Casino Chips", Network::burtonMoney);
			if (Menu::Option("Tp To Burton Drop")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -372.533752f, -135.402649f, 39.f, 1, 0, 0, 1);
			}
			Menu::Toggle("Helipad Rp", Network::Helirp);
			Menu::Toggle("Helipad Casino Chips", Network::HeliMoney);
			if (Menu::Option("Tp To Helipad Drop")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -695.529f, -1458.844f, 5.010f, 1, 0, 0, 1);
			}
			Menu::Toggle("Airport Rp", Network::Airportrp);
			Menu::Toggle("Airport Casino Chips", Network::AirportMoney);
			if (Menu::Option("Tp To Airport Drop")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -989.282f, -2999.507f, 14.010f, 1, 0, 0, 1);
			}
			Menu::Toggle("EasterEgg Rp", Network::easteregg2);
			Menu::Toggle("EasterEgg Casino Chips", Network::EasterEgg1);
			//ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1046, -2538, 20, 1, 0, 0, 1);
		}
		break;
		case spooferkek:
		{
			Menu::Title("");
			Menu::SubTitle("Spoofer");
			if (Menu::Option("~f~[ ~w~Your Info Spoofer ~f~]"))
			{
			}
			if (Menu::Option("Pick R'ID")) {
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) || IsKeyPressed(VK_RETURN))
				{
					Foxy_Engine::spoofed_rid = CharKeyboard();
				}
			}
			if (Menu::Option("Spoof R'ID")) {
				Foxy_Engine::spoof_rid ? Foxy_Engine::networkHandleChecker() : NULL;
			}
			if (Menu::Option("Spoof Name")) {
				char* newname;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(newname);
			}
			if (Menu::Option("~r~Spoof Name")) {
				char* newname;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~r~" + (std::string)newname));
			}
			if (Menu::Option("~q~Spoof Name")) {
				char* newname1;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname1 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~q~" + (std::string)newname1));
			}
			if (Menu::Option("~g~Spoof Name")) {
				char* newname2;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~g~" + (std::string)newname2));
			}
			if (Menu::Option("~b~Spoof Name")) {
				char* newname3;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname3 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~b~" + (std::string)newname3));
			}
			if (Menu::Option("~y~Spoof Name")) {
				char* newname4;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname4 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~y~" + (std::string)newname4));
			}
			if (Menu::Option("~p~Spoof Name")) {
				char* newname5;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname5 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~p~" + (std::string)newname5));
			}
			if (Menu::Option("~o~Spoof Name")) {
				char* newname6;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname6 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~o~" + (std::string)newname6));
			}
			if (Menu::Option("~italic~Spoof Name")) {
				char* newname7;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname7 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~italic~" + (std::string)newname7));
			}
			if (Menu::Option("~bold~Spoof Name")) {
				char* newname8;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname8 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~bold~" + (std::string)newname8));
			}
			if (Menu::Option("~WS~Spoof Name")) {
				char* newname9;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname9 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~WS~" + (std::string)newname9));
			}
			if (Menu::Option("~c~Spoof Name")) {
				char* newname10;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname10 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~c~" + (std::string)newname10));

			}
			if (Menu::Option("~m~Spoof Name")) {
				char* newname11;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname11 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~m~" + (std::string)newname11));

			}
			if (Menu::Option("~u~Spoof Name")) {
				char* newname12;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname12 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~u~" + (std::string)newname12));

			}
			if (Menu::Option("~d~Spoof Name")) {
				char* newname13;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname13 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~d~" + (std::string)newname13));

			}
			if (Menu::Option("~f~Spoof Name")) {
				char* newname14;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname14 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~f~" + (std::string)newname14));

			}
			if (Menu::Option("Skip Line")) {
				char* newname15;
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter a name", "", "", "name", "", "", 16);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				{
					newname15 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
				}
				Network::SetName(Menu::Tools::StringToChar("~n~" + (std::string)newname15));

			}

			if (Menu::Option("� Rockstar Developer �")) {
				Network::SetName("� Rockstar Developer �");

			}

			if (Menu::Option("� Rockstar Admin �")) {
				Network::SetName("� Rockstar Admin �");

			}

			//	� Rockstar Developer �	
			// � = box 
			// ~�~ = rockstar emblem 
			//Menu::Break("Other Player Spoofer");
			//Menu::Toggle("Spoof Rank", Network::Spooflvl);
			//Menu::Toggle("Spoof Money", Network::Spoofmoney);
			//Menu::Toggle("Spoof K/D", Network::Spoofkd);
			//Menu::Toggle("Spoof Kill", Network::Spoofkill);


		}
		break;
#pragma region Selected Player
		case Onlineselecc:
		{
			Menu::Title("");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			Menu::SubTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
			Menu::Toggle("Spectate Player", SPlayer::SpectateBool);//PoolCrash1
		//	Menu::Toggle("2Take1 Ped Pool", PoolCrash1);//PoolCrash1
			Menu::MenuOption("Marker", Markersub);// Done Info
			Menu::MenuOption("Control Player vehicle", Remotecontrol);
			Menu::MenuOption("LSC", LSCSelectedPlayer);
			Menu::MenuOption("Script Event", RemoteEvent);// done info
			Menu::MenuOption("All Drop [ ~r~Use At Your Own Risk~w~ ]", gae1); // Done Info
			Menu::MenuOption("Gift Vehicle", Giftvehiclep);
			Menu::MenuOption("Grief", grief);
			Menu::MenuOption("Mini Menu", gae2);
			Menu::MenuOption("Assorted", gae3);// done
			Menu::MenuOption("Black Hole", blackhole2);// Done
			Menu::MenuOption("Attach Object", Objectsub);//done
			if (Menu::Option("Host Kick")){ NETWORK::NETWORK_SESSION_KICK_PLAYER((selectedPlayer)); }
			if (Menu::Addintchar("Attach", Attachveh, Attachvehint, 0, 3))
			{
				if (Attachvehint == 0)
				{
					Player player = PLAYER::PLAYER_ID();
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					int Bone = PED::GET_PED_BONE_INDEX(playerPed, 24816);
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						notifyMap("Spam it");
						ENTITY::ATTACH_ENTITY_TO_ENTITY(vehicle, playerPed, Bone, 0.0f, -0.3f, 0.0f, 0.0f, 90.0f, 180.0f, 1, 0, 0, 2, 1, 1);
					}
					else
					{
						notifyMap("The player is too far away, or not in any vehicle");
					}
				}
				if (Attachvehint == 1)
				{
					Player player = PLAYER::PLAYER_ID();
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
					Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
					if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false))
					{
						if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh))
							while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh));

						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
						VEHICLE::DELETE_VEHICLE(&veh);
					}
				}
				if (Attachvehint == 2)
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPedId, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
				}
				if (Attachvehint == 3)
				{
					ENTITY::DETACH_ENTITY(playerPedId, true, true);
				}
			}

			if (Menu::Addintchar("Teleport", RemoteTP, Remtp, 0, 6))
			{
				if (Remtp == 0)
				{
					Entity handle;
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
					PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
					ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
				}
				if (Remtp == 1)
				{

					Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), FALSE);
					if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
					{
						int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
						RequestControlOfEnt(vehicle);
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
						{
							ENTITY::SET_ENTITY_COORDS(vehicle, playerCoords.x, playerCoords.y, playerCoords.z, true, false, false, true);//
						}
						notifyMap("Spam it");
					}
					else
					{
						notifyMap("Player not in a vehicle or too far away!");
					}
				}
				if (Remtp == 2)
				{
					if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
					{
						int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
						RequestControlOfEnt(vehicle);
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
						{
							ENTITY::SET_ENTITY_COORDS(vehicle, -1991.348, 3200.953, 32.39795, true, false, false, true);//
						}
						notifyMap("Spam it");
					}
					else
					{
						notifyMap("Player not in a vehicle or too far away!");
					}
				}
				if (Remtp == 3)
				{
					Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
					for (int i = -1; i < 16; i++)
					{
						if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
						{
							PED::SET_PED_INTO_VEHICLE(playerPedId, veh, i);
						}
					}
				}
				if (Remtp == 4)
				{
					if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
					{
						int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
						RequestControlOfEnt(vehicle);
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
						{
							ENTITY::SET_ENTITY_COORDS(vehicle, -74.94243f, -818.63446f, 326.174347f, true, false, false, true);//
						}
						notifyMap("Spam it");
					}
					else
					{
						notifyMap("Player not in a vehicle or too far away!");
					}

				}
				if (Remtp == 5)
				{
					if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
					{
						int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
						RequestControlOfEnt(vehicle);
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
						{
							ENTITY::SET_ENTITY_COORDS(vehicle, -1074, -3201, 13, true, false, false, true);//
						}
						notifyMap("Spam it");
					}
					else
					{
						notifyMap("Player not in a vehicle or too far away!");
					}

				}
				if (Remtp == 6)
				{
					int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
					if (UI::DOES_BLIP_EXIST(WaypointHandle))
					{
						Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
						if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
						{
							int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
							RequestControlOfEnt(vehicle);
							if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
							{
								ENTITY::SET_ENTITY_COORDS(vehicle, WaypointPos.x, WaypointPos.y, WaypointPos.z + 35.0f, 0, 0, 0, 1);
							}
							notifyMap("Spam it");
						}
						else
						{
							notifyMap("Player not in a vehicle or too far away!");
						}
					}
					else
					{
						notifyMap("Set A Waypoint!");
					}

				}
			}
		}
		break;
		case Giftvehiclep:
		{
			Menu::Title("");
			Menu::SubTitle("Gift Vehicle");
			Menu::MenuOption("Mercenaries Update", mercenariesdlc2);
			Menu::MenuOption("Drug Wars Update", Drugwarsdlc2);
			Menu::MenuOption("Tuner Update Gift", tunerdlc2);
			Menu::MenuOption("Cayo Update Gift", cayodlc2);
			Menu::MenuOption("Summer Update Gift", summerdlc2);
			Menu::MenuOption("Casino Update Gift", casinodlc2);
			Menu::MenuOption("Super Sport Gift", SSdlc2);
			Menu::MenuOption("Sport Gift", Sports2);
			Menu::MenuOption("Sport Classic Gift", SportClassic2);
			Menu::MenuOption("OffRoad Gift", Offroad2);
			Menu::MenuOption("Sedans Gift", Sedans2);
			Menu::MenuOption("Coupes Gift", Coupes2);
			Menu::MenuOption("Muscle Gift", Muscle2);
			Menu::MenuOption("Boat Gift", Boats2);
			Menu::MenuOption("Commercial Gift", Commercial2);
			Menu::MenuOption("Compact Gift", Compacts2);
			Menu::MenuOption("Cycles Gift", Cycles2);
			Menu::MenuOption("Emergency Gift", Emergency2);
			Menu::MenuOption("Helicopter Gift", Helicopters2);
			Menu::MenuOption("Industrial Gift", Industrial2);
			Menu::MenuOption("Military Gift", Military2);
			Menu::MenuOption("Planes Gift", Planes2);
			Menu::MenuOption("Service Gift", Service2);
			Menu::MenuOption("Motorcycle Gift", Motorcycles2);
			Menu::MenuOption("Suv Gift", SUV2);
			Menu::MenuOption("Trailer Gift", Trailer2);
			Menu::MenuOption("Trains Gift", Trains2);
			Menu::MenuOption("Utility Gift", uUtility2);
		}
		break;
		case RemoteEvent:
		{
			Menu::Title("");
			Menu::SubTitle("Script Event");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			if (Menu::Option("Error Message"))
			{
				DWORD64 args[2] = { 153488394, selectedPlayer };
				Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
			}
			if (Menu::Option("Send To Cayo Perico"))
			{
				DWORD64 args[4] = { 373376135, selectedPlayer };
				Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
			}
			if (Menu::Option("Kick"))
			{
				DWORD64 kick[4] = { -1587276086,selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick, 5, 1 << selectedPlayer);
				DWORD64 kick2[4] = { 1463355688,selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick2, 5, 1 << selectedPlayer);
				DWORD64 kick3[24] = { 575344561, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick3, 5, 1 << selectedPlayer);
				DWORD64 kick4[3] = { 515799090, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick4, 5, 1 << selectedPlayer);
				DWORD64 kick5[4] = { 1767220965, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick5, 5, 1 << selectedPlayer);
				DWORD64 kick6[4] = { 1433396036, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick6, 5, 1 << selectedPlayer);
				DWORD64 kick7[4] = { 1305720168, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick7, 5, 1 << selectedPlayer);
				DWORD64 kick8[4] = { -275229102, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick8, 5, 1 << selectedPlayer);
				DWORD64 kick9[6] = { -654645351, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick9, 5, 1 << selectedPlayer);
				DWORD64 kick10[4] = { 1848973789, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick10, 5, 1 << selectedPlayer);
				DWORD64 kick11[4] = { 202252150, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick11, 5, 1 << selectedPlayer);
				DWORD64 kick12[4] = { -1503282114, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick12, 5, 1 << selectedPlayer);
				DWORD64 kick13[3] = { -194543830, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick13, 5, 1 << selectedPlayer);
				DWORD64 kick14[4] = { -2063448951, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick14, 5, 1 << selectedPlayer);
				DWORD64 kick15[3] = { 797978700, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick15, 5, 1 << selectedPlayer);
				DWORD64 kick16[3] = { -176858990, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick16, 5, 1 << selectedPlayer);
				DWORD64 kick17[2] = { 1731962870, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick17, 5, 1 << selectedPlayer);
				DWORD64 kick18[8] = { 1152266822, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick18, 5, 1 << selectedPlayer);
				DWORD64 kick19[2] = { 257478565, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick19, 5, 1 << selectedPlayer);
				DWORD64 kick20[2] = { 23010443, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick20, 5, 1 << selectedPlayer);
				DWORD64 kick21[7] = { 496476216, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick21, 5, 1 << selectedPlayer);
				DWORD64 kick22[3] = { 1455421717, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick22, 5, 1 << selectedPlayer);
				DWORD64 kick23[5] = { -419415284, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick23, 5, 1 << selectedPlayer);
				DWORD64 kick24[4] = { 641157117, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick24, 5, 1 << selectedPlayer);
				DWORD64 kick25[5] = { 1358851648, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick25, 5, 1 << selectedPlayer);
				DWORD64 kick26[2] = { -525866785, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick26, 5, 1 << selectedPlayer);
				DWORD64 kick27[2] = { -1277389265, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick27, 5, 1 << selectedPlayer);
				DWORD64 kick28[3] = { -892744477, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick28, 5, 1 << selectedPlayer);
				DWORD64 kick29[9] = { -1005623606, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick29, 5, 1 << selectedPlayer);

				DWORD64 kick31[6] = { -375628860, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick31, 5, 1 << selectedPlayer);
				DWORD64 kick32[6] = { 1103127469, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick32, 5, 1 << selectedPlayer);
				DWORD64 kick33[6] = { 323285304, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick33, 5, 1 << selectedPlayer);
				DWORD64 kick34[6] = { -1951335381, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick34, 5, 1 << selectedPlayer);
				DWORD64 kick35[6] = { 259469385, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick35, 5, 1 << selectedPlayer);
				DWORD64 kick36[6] = { 1186559054, selectedPlayer }; Foxy_Engine::trigger_script_event(1, kick36, 5, 1 << selectedPlayer);


			}
			if (Menu::Option("Contact Jobs"))
			{
				DWORD64 args[4] = { 259469385, selectedPlayer };
				Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
			}
			if (Menu::Option("Infinite Loading Player Apart Invite")) {
				unsigned int Bit = (1 << selectedPlayer);
				uint64_t infiniteload[9] = { 1249026189, selectedPlayer, 0, -1, 1, 115, 0, 0, 0 };
				Foxy_Engine::trigger_script_event(1, infiniteload, 4, Bit);
			}
			Menu::Int("Apart Invite Value", intapart, 1, 200);
			if (Menu::Option("Custom Apart Invite")) {
				unsigned int Bit = (1 << selectedPlayer);
				uint64_t infiniteload[9] = { 1321657966, selectedPlayer, 0, -1, 1, intapart, 0, 0, 0 };
				Foxy_Engine::trigger_script_event(1, infiniteload, 4, Bit);
			}
			if (Menu::Option("~f~[ ~w~Desync Event ~f~]"))
			{
			}
			if (Menu::Option("Desync Crash Event")) {
				unsigned int Bit = (1 << selectedPlayer);
				uint64_t infiniteload[9] = { -353458099, selectedPlayer, 0, -1, 1, 13, 0, 0, 0 };
				Foxy_Engine::trigger_script_event(1, infiniteload, 4, Bit);
				NotificationCEO("1/3", "Foxy", "Free");
				WAIT(600);
				DWORD64 args[4] = { -1101672680, selectedPlayer };
				Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
				NotificationCEO("2/3", "Foxy", "Free");
				WAIT(200);
				DWORD64 argss[2] = { 901348601, selectedPlayer };
				Foxy_Engine::trigger_script_event(1, argss, 5, 1 << selectedPlayer);
				NotificationCEO("3/3", "Foxy", "Free");
			}
			if (Menu::Option("Desync Event 2"))
			{
				DWORD64 args[4] = { -1604421397, selectedPlayer };
				Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
			}
		}
		break;
		case Remotecontrol:
		{
			Menu::Title("");
			Menu::SubTitle("Control Vehicle");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			if (Menu::Option("~f~[ ~w~Acrobatics ~f~]"))
			{
			}
			if (Menu::Option("Kick Flip")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, 0, 10.0f, 20.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
				
			}
			if (Menu::Option("Heel Flip")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				       ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, true, 0, 0, 5.0f, -2.0f, 0, 0, true, true, true, true, false, true);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Back Flip")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				         ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, true, 0, 0, 6.0f, 0, 2.0f, 0, true, true, true, true, false, true);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}

			}
			if (Menu::Option("Double Back Flip")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				        ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, true, 0, 0, 12.0f, 0, 4.0f, 0, true, true, true, true, false, true);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("360")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				      ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, 20.f, 0.0f, 20.f, 0.f, 0.f, 0, 1, 1, 1, 0, 1);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Bunny Hop")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				      ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, true, 0, 0, 7.0f, 0, 0, 0, true, true, true, true, false, true);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Launch Up")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				       ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Crush Vehicle")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				       ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, true, 0, 0, -40.0f, 0, 0, 0, true, true, true, true, false, true);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Spinning Jump")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				       ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, 0, 20.f, 20.0f, 20.f, 0.f, 0.f, 0, 1, 1, 1, 0, 1);
					}
					notifyMap("Force Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Stop Vehicle")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 0);
					}
					notifyMap("Speed Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("~f~[ ~w~Boost ~f~]"))
			{
			}
			if (Menu::Option("Boost Vehicle")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 500);
					}
					notifyMap("Boost Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Boost Backward Vehicle")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, - 500.0f);
					}
					notifyMap("Boost Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;
		case LSCSelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("Remote LSC");
			Menu::MenuOption("Neon", NeonSelectedPlayer);
			Menu::MenuOption("Paint", ColourSelectedPlayer);
			Menu::MenuOption("HeadLight Colour", LightSelectedPlayer);
			Menu::MenuOption("Vehicle Horn", HornSelectedPlayer);
			Menu::MenuOption("F1 Wheel", WheelSelectedPlayer);
			Menu::MenuOption("Benny's [Be Spoke] Wheel", WheelSelectedPlayer2);
			Menu::MenuOption("Vehicle Livery", LiverySelectedPlayer);
			if (Menu::Option("Repair Vehicle")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_FIXED(vehicle);
						VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0);
					}
					notifyMap("Repair Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Upgrade Vehicle")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_FIXED(vehicle);
						VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0);
						VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						for (int i = 0; i < 50; i++)
						{
							VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
						}
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Foxy");
					}
					notifyMap("Upgrade Apllied");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;
		case NeonSelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("LSC Neon");

			if (Menu::Option("Enable Neons")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 0, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 2, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 3, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 4, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 5, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 6, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 7, 1);

					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 255, 0, 0);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			      	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 0, 255, 0);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Blue")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				      VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
				      VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 0, 0, 255);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Hot Pink")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 226, 35, 157);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Yellow")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 247, 244, 0);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Orange")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 247, 91, 0);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Aqua")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 40, 255, 255);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("White")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 255, 255, 255);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Magenta")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 102, 0, 35);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Purple")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 53, 0, 83);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Dark Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 0, 118, 0);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Rose Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
			    	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 8);
			    	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, 161, 0, 0);
					}
					notifyMap("Neon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}





		}
		break;
		case LightSelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("HeadLight Colour");
			if (Menu::Option("~f~[ ~w~Apply Colour First ~f~]"))
			{
			}
			if (Menu::Option("Xenon")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						Spawner::ToggleXenon(vehicle);
					}
					notifyMap("Xenon Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("~f~[ ~w~Colour ~f~]"))
			{
			}
			if (Menu::Option("White")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 1);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}

			}
			if (Menu::Option("Blue")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 1);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Electric Blue")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 2);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Mint Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 3);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Lime Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 4);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Yellow")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 5);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 6);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Orange")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 7);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 8);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Pony Pink")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 9);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Pink")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 10);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Purple")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 11);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Black light")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 12);
					}
					notifyMap("Headlight Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;

		case LiverySelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("Livery Options");
			if (Menu::Option("Stock Livery")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 0, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("2")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 1, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("3")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 2, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("4")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 3, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("5")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 4, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("6")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 5, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("7")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 6, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("8")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 7, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("9")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 8, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("10")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 9, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("11")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 10, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("12")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 11, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("13")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 12, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("48")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 13, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("15")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 48, 14, 0);
					}
					notifyMap("Livery Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;
		case HornSelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("Horn Options");
			if (Menu::Option("Stock Horns")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 0, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("2")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 1, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("3")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 2, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("4")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 3, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("5")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 4, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("6")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 5, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("7")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 6, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("8")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 7, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("9")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 8, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("10")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 9, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("11")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 10, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("12")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 11, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("13")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 12, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("14")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 13, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("15")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 14, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("16")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 15, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("17")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 16, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("18")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 17, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("19")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 18, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("20")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 19, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("21")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 20, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("22")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 21, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("23")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 22, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("24")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 23, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("25")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 24, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("26")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 25, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("27")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 26, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("28")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 27, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("29")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 28, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("30")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 29, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("31")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 30, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("32")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 31, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("33")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 32, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("34")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 33, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("35")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 34, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("36")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 35, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("37")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 36, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("38")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 37, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("39")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 38, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("40")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 39, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("41")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 40, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("42")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 41, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("43")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 42, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("44")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 43, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("45")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 44, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("46")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 45, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("47")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 46, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("48")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 47, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("49")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 48, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("50")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 14, 49, 0);
					}
					notifyMap("Horn Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}

		}
		break;
		case WheelSelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("Wheel Options");
			if (Menu::Option("Stock Wheels")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 0, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Classic 5")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 1, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Classic 5 [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 2, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Retro Star")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 3, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Retro Star [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 4, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Triplex")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 5, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Triplex [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 6, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("70s Spec")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 7, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("70s Spec [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 8, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Super 5R")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 9, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Super 5R [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 10, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Speedster")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 11, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Speedster [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 12, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("GP-90")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 13, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("GP-90 [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 14, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Superspoke")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 15, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Superspoke [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 16, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gridline")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 17, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gridline [STR]")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 18, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Snowflake")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 19, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 20, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic 2")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 21, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic 3")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 22, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic 4")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 23, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic 5")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 24, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic 6")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 25, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Atomic 7")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 26, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;
		case WheelSelectedPlayer2:
		{
			Menu::Title("");
			Menu::SubTitle("Wheel Options");
			if (Menu::Option("Chrome OG Hunnets")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 0, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold OG Hunnets")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 1, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Wires")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 2, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Wires")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 3, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Spoked Out")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 4, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Spoked Out")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 5, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Knock-Offs")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 6, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Knock-Offs")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 7, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Bigger Worm")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 8, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Bigger Worm")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 9, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Vintage Wire")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 10, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Vintage Wire")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 11, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Classic Wire")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 12, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Classic Wire")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 13, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Smoothie")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 14, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Smoothie")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 15, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Classic Rod")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 16, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Classic Rod")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 17, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Chrome Dollar")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 18, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Gold Dollar")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 9);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 19, 0);
					}
					notifyMap("Wheel Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;
		case ColourSelectedPlayer:
		{
			Menu::Title("");
			Menu::SubTitle("Paint Options");
			if (Menu::Option("~f~[ ~w~Primary ~f~]"))
			{
			}
			if (Menu::Option("Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 255, 0, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 0, 255, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Blue")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 0, 0, 255);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Hot Pink")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 226, 35, 157);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Yellow")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 247, 244, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Orange")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 247, 91, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Aqua")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 40, 255, 255);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("White")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{

						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 255, 255, 255);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Magenta")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 102, 0, 35);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Purple")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 53, 0, 83);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Dark Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 0, 118, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Rose Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 161, 0, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}


			if (Menu::Option("~f~[ ~w~Secondary ~f~]"))
			{
			}
			if (Menu::Option("Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 255, 0, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 0, 255, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Blue")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 0, 0, 255);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Hot Pink")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 226, 35, 157);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Yellow")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 247, 244, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Orange")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 247, 91, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Aqua")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 40, 255, 255);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("White")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 255, 255, 255);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Magenta")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 102, 0, 35);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Purple")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 53, 0, 83);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Dark Green")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						//VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 0, 118, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 0, 118, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Rose Red")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						//VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 161, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 161, 0, 0);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}


			if (Menu::Option("~f~[ ~w~Modded Colour ~f~]"))
			{
			}
			if (Menu::Option("Modded Pink")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 20, 6, 12);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 20, 6, 12);
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::GET_VEHICLE_EXTRA_COLOURS(vehicle, &pearlescentColor1, &wheelColor1);;
						VEHICLE::SET_VEHICLE_EXTRA_COLOURS(vehicle, 135, wheelColor1);
					}
					notifyMap("Colour Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Pinky Black")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
					RequestControlOfEnt(vehicle);
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle);
						VEHICLE::GET_VEHICLE_COLOURS(vehicle, &primaryColor1, &secondaryColor1);
						VEHICLE::SET_VEHICLE_COLOURS(vehicle, 12, secondaryColor1);
						WAIT(250);
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::GET_VEHICLE_EXTRA_COLOURS(vehicle, &pearlescentColor1, &wheelColor1);;
						VEHICLE::SET_VEHICLE_EXTRA_COLOURS(vehicle, 135, wheelColor1);
					}
					notifyMap("Color Added");
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
		}
		break;
		case Markersub:
		{
			Menu::Title("");
			Menu::SubTitle("Marker Options");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			if (Menu::Addintchar("Marker Style", marker_name, SPlayer::intmarker, 0, 42)) {}
			Menu::Int("Marker Visibility", SPlayer::intvisibility, 1, 255);
			Menu::Int("Marker Direction X", SPlayer::intdirx, 1, 360);
			Menu::Int("Marker Direction Y", SPlayer::intdiry, 1, 360);
			Menu::Int("Marker Direction Z", SPlayer::intdirz, 1, 360);
			Menu::Int("Marker Rotation X", SPlayer::introtx, 1, 360);
			Menu::Int("Marker Rotation Y", SPlayer::introty, 1, 360);
			Menu::Int("Marker Rotation Z", SPlayer::introtz, 1, 360);
			Menu::Int("Marker Scale X", SPlayer::intscax, 1, 10);
			Menu::Int("Marker Scale Y", SPlayer::intscay, 1, 10);
			Menu::Int("Marker Scale Z", SPlayer::intscaz, 1, 10);
			
		}
		break;
		case ObjectListAttachSP1:
		{
			Menu::Title("");
			Menu::SubTitle("Attach Object [Stunt Race]");

			

			Menu::Int("Colision", colision, 0, 1);
			Menu::Int("Soft Pinning", Softpinnig, 0, 1);
			Menu::Int("Fixed Rotation", fixedRot, 0, 1);
			Menu::Int("Direction X", Xposbone, 1, 360);
			Menu::Int("Direction Y", Yposbone, 1, 360);
			Menu::Int("Direction Z", Zposbone, 1, 360);
			Menu::Int("Rotation X", Xrotbone, 1, 360);
			Menu::Int("Rotation Y", Yrotbone, 1, 360);
			Menu::Int("Rotation Z", Zrotbone, 1, 360);

			for (int i = 0; i < ARRAYSIZE(Stuntlist1); i++)
			{
				if (Menu::Option(Stuntlist1[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(Stuntlist1[i]);
					Ped selecty = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
					Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(model, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(object, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_Head), Xposbone, Yposbone, Zposbone, Xrotbone, Yrotbone, Zrotbone, false, Softpinnig, colision, false, 2, fixedRot);
				}
			}
		}
		break;

		case Objectsub:
		{
			Menu::Title("");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			Menu::MenuOption("Stunt Object List", ObjectListAttachSP1);//done
			Menu::SubTitle("Attach Object Options");
			if (Menu::Option("Delete All Visible")) {
				for (int i = 0; i < 5; i++) {
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
					GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 99, 0);
					GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 99, 0);
					GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 99, 0, 0, 0, 0, 0);
					for (int i = 0; i < 136; i++) {
						Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(propList[i]), 0, 0, 1);

						if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer))) {
							RequestControlOfEnt(obj);
							int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
							NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
							SPlayer::RequestControlOfid(netID);
							ENTITY::DETACH_ENTITY(obj, 1, 1);
							if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
								ENTITY::DELETE_ENTITY(&obj);
							}
						}
					}
				}
			}
			if (Menu::Option("Cone Man"))
			{
				Ped selecty = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Hash cone = GAMEPLAY::GET_HASH_KEY("prop_roadcone01c");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
				STREAMING::REQUEST_MODEL(cone);
				while (!STREAMING::HAS_MODEL_LOADED(cone)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(cone, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_Head), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object1 = OBJECT::CREATE_OBJECT_NO_OFFSET(cone, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object1, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_L_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object2 = OBJECT::CREATE_OBJECT_NO_OFFSET(cone, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object2, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_R_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
			}//prop_alien_egg_01
			if (Menu::Option("Egg Man"))
			{
				Ped selecty = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Hash egg = GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
				STREAMING::REQUEST_MODEL(egg);
				while (!STREAMING::HAS_MODEL_LOADED(egg)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_Head), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object1 = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object1, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_L_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object2 = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object2, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_R_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
			}
			if (Menu::Option("Minigun Man"))
			{
				Ped selecty = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Hash egg = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
				STREAMING::REQUEST_MODEL(egg);
				while (!STREAMING::HAS_MODEL_LOADED(egg)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_Head), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object1 = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object1, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_L_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object2 = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object2, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_R_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
			}
			if (Menu::Option("Map Man"))
			{
				Ped SelectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Hash map = GAMEPLAY::GET_HASH_KEY("dt1_lod_slod3");
				Vector3 playerpos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
				STREAMING::REQUEST_MODEL(map);// just to show you
				while (!STREAMING::HAS_MODEL_LOADED(map)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(map, playerpos.x, playerpos.y, playerpos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object, SelectedPlayer, PED::GET_PED_BONE_INDEX(SelectedPlayer, SKEL_Head), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object1 = OBJECT::CREATE_OBJECT_NO_OFFSET(map, playerpos.x, playerpos.y, playerpos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object1, SelectedPlayer, PED::GET_PED_BONE_INDEX(SelectedPlayer, SKEL_L_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object2 = OBJECT::CREATE_OBJECT_NO_OFFSET(map, playerpos.x, playerpos.y, playerpos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object2, SelectedPlayer, PED::GET_PED_BONE_INDEX(SelectedPlayer, SKEL_R_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
			}
			if (Menu::Option("Tree Man"))
			{
				Ped selecty = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Hash egg = GAMEPLAY::GET_HASH_KEY("Prop_tree_jacada_02");
				Vector3 bonepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				STREAMING::REQUEST_MODEL(egg);
				while (!STREAMING::HAS_MODEL_LOADED(egg)) WAIT(0);

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_Head), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object1 = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object1, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_L_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);

				Object object2 = OBJECT::CREATE_OBJECT_NO_OFFSET(egg, bonepos.x, bonepos.y, bonepos.z, 1, 0, TRUE);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(object2, selecty, PED::GET_PED_BONE_INDEX(selecty, SKEL_R_Hand), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
			}
			if (Menu::Option("~f~[ ~w~Vehicle ~f~]")) {}
			if (Menu::Option("Attach Volatus"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("VOLATUS");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Volatol"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("VOLATOL");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Adder"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Adder");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Police Vehicle"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("POLICE");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach BMX"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("BMX");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Cargoplane"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("CARGOPLANE");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Hotknife"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Hotknife");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Veto"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("VETO");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
			if (Menu::Option("Attach Veto2"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("VETO2");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}

				}
			}
		}
		break;
		case helpful:
		{
			Menu::Title("");
			Menu::SubTitle("Helpfull");
			Menu::MenuOption("All Drop", gae1);
			Menu::MenuOption("Give Vehicle", Giftvehiclep);
		}
		break; 
		case friendlist:
		{
			Menu::Title("");
			Menu::SubTitle("Friendlist");
            Menu::Int("Option Choice", friendoption, 1, 3);
			if (Menu::Option("[1] Send A Message")) {}
			if (Menu::Option("[2] View Profile")){}
			if (Menu::Option("[3] Invite Him [In Dev]")) {}
			
			std::int32_t friend_count = NETWORK::NETWORK_GET_FRIEND_COUNT();
			for (std::int32_t i = 0; i < friend_count; i++) {
				const char* raw_name = NETWORK::NETWORK_GET_FRIEND_NAME(i);
				if (raw_name != nullptr) {
					std::string name(raw_name);
					if (NETWORK::NETWORK_IS_FRIEND_INDEX_ONLINE(i)) {
						name += " [ ~g~Connected ~w~]";
						if (NETWORK::NETWORK_IS_FRIEND_IN_SAME_TITLE((char*)raw_name)) {
							name += " [ Playing Gta V In ]";
							if (NETWORK::NETWORK_IS_FRIEND_IN_MULTIPLAYER((char*)raw_name)) {
								name += " [ ~b~Multiplayer ~w~]";
							}
							else {
								name += " [ ~y~Single Player ~w~]";
							}
						}
					}
					else {
						name += " [ ~r~Disconnected~w~ ]";
					}
					if (friendoption == 0)
					{
						notifyBottom("Why Did You Even Try");
					}
					if (friendoption == 1) 
					{
						if (Menu::Option(Menu::Tools::StringToChar(name)))
						{
							GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 60);
							while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
							std::uint64_t* buffer = std::make_unique<std::uint64_t[]>(13).get();
							NETWORK::NETWORK_HANDLE_FROM_FRIEND(i, reinterpret_cast<std::int32_t*>(buffer), 13);
							NETWORK::NETWORK_SEND_TEXT_MESSAGE(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT(), reinterpret_cast<std::int32_t*>(buffer));
						}
					}
					if (friendoption == 2)
					{
						if (Menu::Option(Menu::Tools::StringToChar(name)))
						{
							std::uint64_t* buffer = std::make_unique<std::uint64_t[]>(13).get();
							NETWORK::NETWORK_HANDLE_FROM_FRIEND(i, reinterpret_cast<std::int32_t*>(buffer), 13);
							NETWORK::NETWORK_SHOW_PROFILE_UI(reinterpret_cast<std::int32_t*>(buffer));
						}
					}
					if (friendoption == 3)
					{
						notifyBottom("Invite In Dev");
					}
				}
			}
		}
		break;
		case gae1:
		{
			Menu::Title("");
			Menu::SubTitle("All Drop [ ~r~Use At Your Own Risk~w~ ]");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			if (Menu::Option("~f~[ ~w~Money Drop ~f~]")) {}
			if (Menu::Int("Cash Value Amount", SPlayer::CashAmount, 0, 2500))
			{
				{
					if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
					{
						SPlayer::CashAmount = NumberKeyboard();
					}
				}
			}
			Menu::Int("Money Drop Delay", SPlayer::CashInt, 0, 5000, 100);
			Menu::Int("Money Drop Height", SPlayer::CashHeight, 1, 5, 1);
			Menu::Toggle("Drop Money", SPlayer::Moneydrop);

			if (Menu::Option("~f~[ ~w~Money Drop Rain ~f~]")) {}
			if (Menu::Int("Cash Value Amount", SPlayer::CashAmount2, 0, 2500))
			{
				{
					if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
					{
						SPlayer::CashAmount = NumberKeyboard();
					}
				}
			}
			Menu::Int("Drop Money Delay [RAIN]", SPlayer::CashInt2, 0, 5000, 100);
			Menu::Toggle("Drop Money [RAIN]", SPlayer::Moneydrop2);
			if (Menu::Option("~f~[ ~w~Rp Drop ~f~]")) {}

			Menu::Int("RP Height", SPlayer::Rphieght, 1, 5, 1);
			Menu::Toggle("Drop RP", SPlayer::Rpdrop);

			if (Menu::Option("~f~[ ~w~Rp Drop Rain ~f~]")) {}
			Menu::Int(" Rp Delay [RAIN]", SPlayer::RpInt2, 0, 5000, 100);
			Menu::Toggle("Drop Rp [RAIN]", SPlayer::Rpdrop2);

			if (Menu::Option("~f~[ ~w~Ped Drop ~f~]")) {}
			if (Menu::Option("Drop 10 K"))
			{
				STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("A_C_Seagull"));
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
				if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("A_C_Seagull")))
				{
					int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("A_C_Seagull"), coords.x, coords.y, coords.z, 0, 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Ped))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("A_C_Seagull"));
						RequestControlOfEnt(Ped);
						PED::SET_PED_MONEY(Ped, 10000);
						ENTITY::SET_ENTITY_HEALTH(Ped, 0);

					}

				}
			}

			if (Menu::Option("~f~[ ~w~Ammo Drop ~f~]")) {}
			if (Menu::Option("Drop Ammo"))
			{
				int modelhash = GAMEPLAY::GET_HASH_KEY("prop_ld_ammo_pack_01");
				Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				DWORD pickup = $(Ammo);
				STREAMING::REQUEST_MODEL(modelhash);
				if (!STREAMING::HAS_MODEL_LOADED(modelhash)) {
					WAIT(0);
				}
				else {
					Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
					OBJECT::CREATE_AMBIENT_PICKUP(pickup, playerPosition.x, playerPosition.y, playerPosition.z + 5, 0, 2500, modelhash, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(pickup);
				}
			}
			if (Menu::Addintchar("Type:", Pickupammo, Ammodropint, 0, 10)) // put the same number of models in the list
			{
				if (Ammodropint == 0)// = first name of the list 
				{
					Ammo = "PICKUP_AMMO_FIREWORK";
				}
				if (Ammodropint == 1)
				{
					Ammo = "PICKUP_AMMO_FLAREGUN";
				}
				if (Ammodropint == 2)
				{
					Ammo = "PICKUP_AMMO_MINIGUN";
				}
				if (Ammodropint == 3)
				{
					Ammo = "PICKUP_AMMO_RPG";
				}
				if (Ammodropint == 4)
				{
					Ammo = "PICKUP_AMMO_GRENADELAUNCHER";
				}
				if (Ammodropint == 5)
				{
					Ammo = "PICKUP_AMMO_SNIPER";
				}
				if (Ammodropint == 6)
				{
					Ammo = "PICKUP_AMMO_SHOTGUN";
				}
				if (Ammodropint == 7)
				{
					Ammo = "PICKUP_AMMO_MG";
				}
				if (Ammodropint == 8)
				{
					Ammo = "PICKUP_AMMO_RIFLE";
				}
				if (Ammodropint == 9)
				{
					Ammo = "PICKUP_AMMO_SMG";
				}
				if (Ammodropint == 10)
				{
					Ammo = "PICKUP_AMMO_PISTOL";
				}

			}

			if (Menu::Option("~f~[ ~w~Health ~f~]")) {}
			Menu::Toggle("Health Drop", HealthDrop);
			Menu::Toggle("Armour Drop", ArmorDrop);

			if (Menu::Option("~f~[ ~w~Vehicle Health ~f~]")) {}
			Menu::Toggle("Vehicle Health Drop", VHealthDrop);
			Menu::Toggle("Vehicle Armour Drop", VArmorDrop);

			if (Menu::Option("~f~[ ~w~Casino Card ~f~]")) {}
			Menu::Int("Card Height", SPlayer::Cardhieght, 1, 5, 1);
			Menu::Toggle("Casino Card Drop", SPlayer::Carddrop);

			/*if (Menu::Option("~f~[ ~w~Sync Drop Test ~f~]")) {}

			if (Menu::Option("Desking wanna be")) 
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
				Hash RPHASH = GAMEPLAY::GET_HASH_KEY("prop_gold_bar");
				Hash Variable = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_CASE");
				STREAMING::REQUEST_MODEL(RPHASH);
				if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(Variable, pos.x, pos.y, pos.z, 0, 100000, RPHASH, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
					Hash MoneyNameHash = GAMEPLAY::GET_HASH_KEY("SERVICE_EARN_PICKUP");
					globalHandle(4536533).As<int>() = 0;
					globalHandle(4536533 + 4).As<int>() = 0;
					globalHandle(4536533 + 1).As<int>() = INT_MAX - 1;
					globalHandle(4536533 + 2).As<int>() = 100000;
					globalHandle(4536533 + 3).As<int>() = MoneyNameHash;
					globalHandle(4536533 + 6).As<int>() = 0;
					globalHandle(4536533 + 7).As<int>() = INT_MAX;
					globalHandle(4536533).As<int>() = 1;
					NETWORKCASH::NETWORK_EARN_FROM_PICKUP(100000);
				}
				
			}
			if (Menu::Option("Test Drop [Wanna Be Movie]"))
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
				Hash RPHASH = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_wifaaward_01a");
				Hash RPHASH1 = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_filmreel_01a");
				Hash RPHASH2 = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_alienhead_01a");
				Hash RPHASH3 = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_clapperboard_01a");
				Hash RPHASH4 = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_headdress_01a");
				Hash RPHASH5 = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_mummyhead_01a");
				Hash RPHASH6 = GAMEPLAY::GET_HASH_KEY("sum_prop_ac_monstermask_01a");
				STREAMING::REQUEST_MODEL(RPHASH);
				STREAMING::REQUEST_MODEL(RPHASH1);
				STREAMING::REQUEST_MODEL(RPHASH2);
				STREAMING::REQUEST_MODEL(RPHASH3);
				STREAMING::REQUEST_MODEL(RPHASH4);
				STREAMING::REQUEST_MODEL(RPHASH5);
				STREAMING::REQUEST_MODEL(RPHASH6);
				if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH, FALSE, TRUE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH1, FALSE, TRUE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH2, FALSE, TRUE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH3, FALSE, TRUE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH4, FALSE, TRUE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH5, FALSE, TRUE);
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + 5, 0, 1, RPHASH6, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH2);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH3);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH4);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH5);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH6);
				}
			}
			if (Menu::Option("Cayo Perico drop 3"))
			{
				Hash Variable = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_SECURITY_CASE");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
				Hash RPHASH = GAMEPLAY::GET_HASH_KEY("prop_gold_bar");
				STREAMING::REQUEST_MODEL(RPHASH);
				if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(Variable, pos.x, pos.y, pos.z + 5, 0, 5000, RPHASH, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
				}
			}
			if (Menu::Option("Cayo Perico drop 4"))
			{
				Hash Variable = GAMEPLAY::GET_HASH_KEY("PICKUP_GANG_ATTACK_MONEY");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
				Hash RPHASH = GAMEPLAY::GET_HASH_KEY("prop_gold_bar");
				STREAMING::REQUEST_MODEL(RPHASH);
				if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(Variable, pos.x, pos.y, pos.z + 5, 0, 5000, RPHASH, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
				}
			}*/



		}
		break;
		case gae2:
		{
			Menu::Title("");
			Menu::SubTitle("Mini Menu"); //
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			Menu::MenuOption("Weapon Mods", wepmodsonline);
			//Menu::MenuOption("Vehicle Modifications", vehmodsonline);
			Menu::MenuOption("Chat Commands", chatcommands);
			if (Menu::Option("Blame Kill"))
			{
				int Playerped = get_player_ped(selectedPlayer);
				for (int x = 0; x < 32; x++) 
				{
					if (get_player_ped(x) && x != player_id() && x != selectedPlayer) {
						Vector3 playerPos = get_player_coords(x);
						owned_explossion_bypass(true);
						Foxy_Engine::add_owned_explosion(Playerped, &playerPos, 1, true, false, 2.f, 1.f);
						owned_explossion_bypass(false);
					}
				}
			}
			if (Menu::Option("Semi God"))
			{
				Hash oball = GAMEPLAY::GET_HASH_KEY("prop_juicestand");
				STREAMING::REQUEST_MODEL(oball);
				while (!STREAMING::HAS_MODEL_LOADED(oball))
					WAIT(0);
				int orangeball = OBJECT::CREATE_OBJECT(oball, 0, 0, 0, true, 1, 0);
				RequestControlOfEnt(orangeball);
				ENTITY::SET_ENTITY_VISIBLE(orangeball, 0, 0);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(orangeball, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);

			}
			if (Menu::Option("Give All Weapons")) {
				uint Weapons[] = { 0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
	                               0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
	                               0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
	                               0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
	                               0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
	                               0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
	                               0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
	                               0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
	                               0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
	                               0x34A67B97, 0xFBAB5776, 0x060EC506, // Miscellaneous
	                               0xAF3696A1, 0x476BF155, 0xB62D1F67,// 1.46
	                               2441047180, 3126027122, 727643628, //Casino Hiest
	                               94989220, 1470379660, 2636060646, //Cayo Perico
								   1578808251, 3980609624, //Summer dlc 2
					               1703483498, 465894841,  //Creator club weapon 
					               350597077 //1.67 
				};
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), Weapons[i], 9999, 1);
				}
			}
			if (Menu::Option("Set Vehicle In Godmode")) {

				Entity car = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0);
				ENTITY::SET_ENTITY_INVINCIBLE(car, true);
			}
		}
		break;
		case chatcommands:
		{
			Menu::Title("");
			Menu::SubTitle("Mini Menu");
			Menu::Toggle("Enable Chat Commands", Foxy_Engine::chat_cmd_on);
			Menu::Toggle("Enable !snow on/off", Foxy_Engine::command1on);
			Menu::Toggle("Enable !kill all", Foxy_Engine::command2on);
		}
		break;
		case wepmodsonline:
		{
			Menu::Title("");
			Menu::SubTitle("Weapon Mods");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
		    Menu::Toggle("Money Gun [ ~r~Use At Your Own Risk~w~ ]", SPlayer::Shootmoney);
		    Menu::Toggle("Shoot Cars", SPlayer::Shootcars);
			Menu::Int("Explosion Type", SPlayer::exptypeonline, 0, 73);
			Menu::Toggle("Explosive Ammo", SPlayer::Shootexp);
			Menu::Toggle("Give Lag Gun", SPlayer::Shootcarrs);
			Menu::Toggle("Give Lag Gun V2", SPlayer::Shootcarrrs);
			Menu::Toggle("Airstrike Gun", SPlayer::Shootairstrike);
			Menu::Toggle("Delete Gun", SPlayer::Deletegunr);
			Menu::Toggle("Ped Gun", SPlayer::PedGunv2);
			Menu::Toggle("Fire Gun", SPlayer::FireGun);
			Menu::Toggle("Water Gun", SPlayer::WaterGun);
			Menu::Toggle("Tree Gun", Remgunobjtree);
			if (Menu::Addintchar("Tree Models:", Treename, Treeint, 0, 15))
			{
				if (Treeint == 0)
				{
					objtree = "Prop_tree_cedar_02";
				}
				if (Treeint == 1)
				{
					objtree = "Prop_tree_cedar_s_01";
				}
				if (Treeint == 2)
				{
					objtree = "Prop_tree_cypress_01";

				}
				if (Treeint == 3)
				{
					objtree = "Prop_tree_eucalip_01";

				}
				if (Treeint == 4)
				{
					objtree = "Prop_tree_jacada_02";

				}
				if (Treeint == 5)
				{
					objtree = "Prop_tree_lficus_02";

				}
				if (Treeint == 6)
				{
					objtree = "Prop_tree_log_01";

				}
				if (Treeint == 7)
				{
					objtree = "Prop_tree_maple_02";

				}
				if (Treeint == 8)
				{
					objtree = "Prop_tree_mquite_01";

				}
				if (Treeint == 9)
				{
					objtree = "test_tree_forest_trunk_04";

				}
				if (Treeint == 10)
				{
					objtree = "test_tree_forest_trunk_base_01";

				}
				if (Treeint == 11)
				{
					objtree = "Prop_snow_t_ml_03";

				}
				if (Treeint == 12)
				{
					objtree = "Prop_snow_tree_04_f";

				}
				if (Treeint == 13)
				{
					objtree = "Des_protree_root";

				}
				if (Treeint == 14)
				{
					objtree = "Prop_Prop_tree_01";

				}
				if (Treeint == 15)
				{
					objtree = "Prop_tree_birch_05";

				}
			}
			Menu::Toggle("RP Statues Gun [ ~r~Use At Your Own Risk~w~ ]", SPlayer::ShootRp);
			Menu::Toggle("Insane Vehicle Gun", SPlayer::Insanegun);


			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Selected Player Shoot Money");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Selected Player Shoot Car");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Selecte Explosion Type");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Selected Player Shoot Explosion");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Selected Player Shoot Cargoplane");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Selected Player Shoot Submarine");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Selected Player Shoot Airstrike");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Selected Player Delete Gun");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Selected Player Shoot Peds");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Selected Player Shoot Fire");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Selected Player Shoot Water");
			}
			if (Menu::Settings::currentOption == 12) {
				Menu::OptionInfo("Selected Player Shoot Tree");
			}
			if (Menu::Settings::currentOption == 13) {
				Menu::OptionInfo("Tree Selection");
			}
			if (Menu::Settings::currentOption == 14) {
				Menu::OptionInfo("Selected Player Shoot RP");
			}
			if (Menu::Settings::currentOption == 15) {
				Menu::OptionInfo("Insane Gun Vehicle [DEV Option]");
			}
		
		}
		break;
		case vehmodsonline:
		{
			Menu::Title("");
			Menu::SubTitle("Vehicle Modifications");
			Menu::Break("Horn Mods");
			Menu::Toggle("Vehicle Fly", SPlayer::Remotefly);

			if (Menu::Settings::currentOption == 1) {
				Menu::OptionInfo("Selected Player Vehicle Can Fly");
			}
			if (Menu::Settings::currentOption == 2) {
				Menu::OptionInfo("Selected Player Shoot Car");
			}
			if (Menu::Settings::currentOption == 3) {
				Menu::OptionInfo("Selecte Explosion Type");
			}
			if (Menu::Settings::currentOption == 4) {
				Menu::OptionInfo("Selected Player Shoot Explosion");
			}
			if (Menu::Settings::currentOption == 5) {
				Menu::OptionInfo("Selected Player Shoot Cargoplane");
			}
			if (Menu::Settings::currentOption == 6) {
				Menu::OptionInfo("Selected Player Shoot Submarine");
			}
			if (Menu::Settings::currentOption == 7) {
				Menu::OptionInfo("Selected Player Shoot Airstrike");
			}
			if (Menu::Settings::currentOption == 8) {
				Menu::OptionInfo("Selected Player Delete Gun");
			}
			if (Menu::Settings::currentOption == 9) {
				Menu::OptionInfo("Selected Player Shoot Peds");
			}
			if (Menu::Settings::currentOption == 10) {
				Menu::OptionInfo("Selected Player Shoot Fire");
			}
			if (Menu::Settings::currentOption == 11) {
				Menu::OptionInfo("Selected Player Shoot Water");
			}

		}
		break;
		case gibemecar:
		{
			Menu::Title("");
			Menu::SubTitle("Give Car");
			Menu::Toggle("Toreador", SPlayer::givecarr1);
		}
		break;
		case gae3:
		{
			Menu::Title("");
			//SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
			Menu::SubTitle("Assorted");
			if (Menu::Option("Clone Player")) {
				PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1, 1, 1);
			}
			if (Menu::Option("Show Profile")) {
				int handle[76]; //var num3 = sub_34009(A_0, (A_1) + 264, (A_1) + 272);
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, &handle[0], 13);
				NETWORK::NETWORK_SHOW_PROFILE_UI(&handle[0]);


			}

			if (Menu::Option("Add Friend")) {
				int handle[76]; //var num3 = sub_34009(A_0, (A_1) + 264, (A_1) + 272);
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, &handle[0], 13);
				NETWORK::NETWORK_ADD_FRIEND(&handle[0], "Join the War");


			}

			if (Menu::Option("Send Message")) {

				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 60);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				int handle[76]; //var num3 = sub_34009(A_0, (A_1) + 264, (A_1) + 272);
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, &handle[0], 13);
				NETWORK::NETWORK_SEND_TEXT_MESSAGE(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT(), &handle[0]);

			}
		}
		break;
		case grief:
		{
			Menu::Title("");
			Menu::SubTitle("Grief");
			Menu::MenuOption("General", gg);
			Menu::MenuOption("Vehicle", spv);
		}
		break;
		case crashing:
		{
			Menu::Title("");
			Menu::SubTitle("crash");
		//	Menu::Toggle("Badsport Player V1 ", badsportplayersoftban);
			if (Menu::Option("Pick Up Crash"))
			{
					if (SPlayer::SpectateBool == true)
					{
						notifyMap("You can't crash the player, while spactating said player");
					}
					else
					{
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(selectedPlayer, false);
						int i = 0;
						while (i < 25)
						{
							i++;
							STREAMING::REQUEST_MODEL(0x113FD533);
							if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
							{
								auto pukick = OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, coords.x, coords.y, coords.z + 1, 0, 40000, 0x113FD533, 0, 1);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(pukick, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
							}
					}   }

			}
			if (Menu::Option("Force Crash")) {
				if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
				{
					int i = 0;
					while (i < 25)
					{
						i++;
						int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
						RequestControlOfEnt(vehicle);
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
						{
							ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 1, 1, 1, 0, 1);
						}
						notifyMap("Force Apllied");
					}
				}
				else
				{
					notifyMap("Player not in a vehicle or too far away!");
				}
			}
			if (Menu::Option("Desync Crash"))
			{
				Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Foxy_Engine::remove_weapon(ped, -0000000000);
				Foxy_Engine::remove_weapon(ped, -000000000001);
				Foxy_Engine::remove_weapon(ped, -0xFFFFFFFFFFFFFF); // delete invalids guns 
				Foxy_Engine::remove_weapon(ped, 0);

				uint64_t _events_f[12] = { -988842806, selectedPlayer, -72614, 63007, 59027, -12012, -26996, 33398, 33398, 63007, -72614, 59027 };// crash event
				Foxy_Engine::trigger_script_event(1, _events_f, 12, 1 << selectedPlayer);

				uint64_t _events_fs[4] = { -1320260596, selectedPlayer, -1330780407, 479 };// crash event
				Foxy_Engine::trigger_script_event(1, _events_fs, 4, 1 << selectedPlayer);

				uint64_t _events_a[46] = { -2043109205, selectedPlayer, -2147483647, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534 };
				uint64_t _events_p[46] = { -988842806, selectedPlayer, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534,65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, -2147483647, 65534, 65534, 65534, -2147483647 };
				uint64_t _events_c[46] = { 153488394, selectedPlayer, -2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 };
				uint64_t _events_g[46] = { -988842806, selectedPlayer, 868904806, 262276366, -747991709, 1545080914, -51510646, 1790326295, 389113600, -617567498, -601391132, -564503258, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550 };

				Foxy_Engine::trigger_script_event(1, _events_g, 46, 1 << selectedPlayer);
				Foxy_Engine::trigger_script_event(1, _events_a, 46, 1 << selectedPlayer);
				Foxy_Engine::trigger_script_event(1, _events_p, 46, 1 << selectedPlayer);
				Foxy_Engine::trigger_script_event(1, _events_c, 46, 1 << selectedPlayer);


			}
			Menu::Toggle("Fps Crash V1 ", SPlayer::fpscrash);
			Menu::Toggle("Fps Crash V2", SPlayer::fpscrash2);
			if (Menu::Option("crash Pool"))
			{
				int i = 0;
				while (i < 25)
				{
					i++;
					int model = GAMEPLAY::GET_HASH_KEY("Player_Zero");
					int model2 = GAMEPLAY::GET_HASH_KEY("Player_One");
					int model3 = GAMEPLAY::GET_HASH_KEY("Player_Two");

					Player nigga = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				    STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) SYSTEM::WAIT(0);
					Vector3 fposition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(nigga, 0.0, 5.0, 0.0);
					PED::CREATE_PED(1, model, fposition.x, fposition.y, fposition.z, ENTITY::GET_ENTITY_HEADING(nigga), TRUE, TRUE);

					STREAMING::REQUEST_MODEL(model2);
					while (!STREAMING::HAS_MODEL_LOADED(model2)) SYSTEM::WAIT(0);
					PED::CREATE_PED(1, model2, fposition.x, fposition.y, fposition.z, ENTITY::GET_ENTITY_HEADING(nigga), TRUE, TRUE);

					STREAMING::REQUEST_MODEL(model3);
					while (!STREAMING::HAS_MODEL_LOADED(model3)) SYSTEM::WAIT(0);
					PED::CREATE_PED(1, model3, fposition.x, fposition.y, fposition.z, ENTITY::GET_ENTITY_HEADING(nigga), TRUE, TRUE);
				}
			}
			if (Menu::Option("Model Action Crash"))
			{
				if (SPlayer::SpectateBool == true)
				{
					notifyMap("You can't crash the player, while spactating said player");
				}
				else {
					Hash Model_crash_Action = GAMEPLAY::GET_HASH_KEY("A_C_MtLion");
					{
						STREAMING::REQUEST_MODEL(Model_crash_Action);
						if (STREAMING::HAS_MODEL_LOADED(Model_crash_Action));
						{
							Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
							int Handle = PED::CREATE_PED(1, Model_crash_Action, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
							int Handle2 = PED::CREATE_PED(1, Model_crash_Action, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
							int Weaponhash = GAMEPLAY::GET_HASH_KEY("weapon_machete");
							if (ENTITY::DOES_ENTITY_EXIST(Handle))
							{
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
								WEAPON::GIVE_WEAPON_TO_PED(Handle, Weaponhash, 1, false, true);
								PED::SET_PED_COMBAT_ABILITY(Handle, 100);
								AI::TASK_COMBAT_PED(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
								PED::SET_PED_KEEP_TASK(Handle, true);

							}
							if (ENTITY::DOES_ENTITY_EXIST(Handle2))
							{
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle2, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
								WEAPON::GIVE_WEAPON_TO_PED(Handle2, Weaponhash, 1, false, true);
								PED::SET_PED_COMBAT_ABILITY(Handle2, 100);
								AI::TASK_COMBAT_PED(Handle2, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
								PED::SET_PED_KEEP_TASK(Handle2, true);
							}
						}
					}
				}
				
			}
			if (Menu::Option("Crash Models Sync"))
			{
				Entity handle;
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
				PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
				ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
				int model = GAMEPLAY::GET_HASH_KEY("A_C_Humpback");
				int model2 = GAMEPLAY::GET_HASH_KEY("A_C_Fish");
				int model3 = GAMEPLAY::GET_HASH_KEY("A_C_KillerWhale");
				int model4 = GAMEPLAY::GET_HASH_KEY("A_C_SharkHammer");
				int model5 = GAMEPLAY::GET_HASH_KEY("A_C_Dolphin");
				

				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				WAIT(10);


				STREAMING::REQUEST_MODEL(model2);
				while (!STREAMING::HAS_MODEL_LOADED(model2)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model2);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model2);
				WAIT(10);

				STREAMING::REQUEST_MODEL(model3);
				while (!STREAMING::HAS_MODEL_LOADED(model3)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model3);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model3);
				WAIT(10);

				STREAMING::REQUEST_MODEL(model4);
				while (!STREAMING::HAS_MODEL_LOADED(model4)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model4);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model4);
				WAIT(10);

				STREAMING::REQUEST_MODEL(model5);
				while (!STREAMING::HAS_MODEL_LOADED(model5)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model5);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model5);
				WAIT(10);
			}
			if (Menu::Option("Crash"))
			{
				if (SPlayer::SpectateBool == true)
				{
					notifyMap("You can't crash the player, while spactating said player");
				}
				else
				{
					Player nigga = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
					STREAMING::REQUEST_MODEL(0x856cfb02);
					while (!STREAMING::HAS_MODEL_LOADED(0x856cfb02)) SYSTEM::WAIT(0);
					Vector3 fposition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(nigga, 0.0, 5.0, 0.0);
					PED::CREATE_PED(1, 0x856cfb02, fposition.x, fposition.y, fposition.z, ENTITY::GET_ENTITY_HEADING(nigga), TRUE, TRUE);
					crashthisnigga2 = false;


					//block this 
					Vector3 pos = get_player_coords(selectedPlayer);

					for (int i = 0; i < blacklistedObjects.size(); i++) {
						Object tempObject = OBJECT::CREATE_OBJECT(blacklistedObjects[i], pos.x, pos.y, pos.z, true, false, false);
						attach_entity_to_entity(tempObject, get_player_ped(selectedPlayer), SKEL_Spine0, 0, 0, 0, 0, 0, 0, false, false, false, true, 2, true);
						CrashObject.push_back(tempObject);
					}

					if (GetTickCount() > 650 + crashPlayerTimer) {
						for (int i = 0; i < CrashObject.size(); i++) {
							ENTITY::DETACH_ENTITY(CrashObject.at(i), 1, 0);
							ENTITY::SET_ENTITY_AS_MISSION_ENTITY(CrashObject.at(i), 1, 1);
							ENTITY::DELETE_ENTITY(&CrashObject.at(i));
						}
						CrashObject.clear();
						notifyMap("~g~Crashing! Wait A Few Seconds...");
						crashthisnigga2 = false;
					}
				}
			}
			if (Menu::Option("CrashV2"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Adder");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash2 = GAMEPLAY::GET_HASH_KEY("police");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash2);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash2));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash2, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash3 = GAMEPLAY::GET_HASH_KEY("Hotknife");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash3);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash3));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash3, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash5 = GAMEPLAY::GET_HASH_KEY("a_c_husky");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash5);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash5));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash5, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash6 = GAMEPLAY::GET_HASH_KEY("a_c_humpback");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash6);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash6));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash6, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash7 = GAMEPLAY::GET_HASH_KEY("a_c_dolphin");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash7);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash7));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash7, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash8 = GAMEPLAY::GET_HASH_KEY("a_c_killerwhale");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash8);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash8));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash8, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vector3 pos = get_player_coords(selectedPlayer);

				for (int i = 0; i < blacklistedObjects.size(); i++) {
					Object tempObject = OBJECT::CREATE_OBJECT(blacklistedObjects[i], pos.x, pos.y, pos.z, true, false, false);
					attach_entity_to_entity(tempObject, get_player_ped(selectedPlayer), SKEL_Spine0, 0, 0, 0, 0, 0, 0, false, false, false, true, 2, true);
					CrashObject.push_back(tempObject);
				}

				if (GetTickCount() > 650 + crashPlayerTimer) {
					for (int i = 0; i < CrashObject.size(); i++) {
						ENTITY::DETACH_ENTITY(CrashObject.at(i), 1, 0);
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(CrashObject.at(i), 1, 1);
						ENTITY::DELETE_ENTITY(&CrashObject.at(i));
					}
					CrashObject.clear();
					notifyMap("~g~Crashing! Wait A Few Seconds...");
					crashthisnigga2 = false;
				}
			}
			if (Menu::Option("Furry Crash")) {
				for (int i = 0; i < 10; i++)
				{
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
					Furry_Crash("WEAPON_STUNGUN");
				}

			}
			if (Menu::Option("Crash [~r~MAPPING~w~]"))
			{
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("dt1_lod_slod3");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = OBJECT::CREATE_OBJECT(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
						}
					}
				}
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("dt1_tc_dufo_core");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = OBJECT::CREATE_OBJECT(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
						}
					}
				}
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("hei_hw1_06_road");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = OBJECT::CREATE_OBJECT(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
						}
					}
				}
				Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Adder");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
						}
					}
				}
				Vehicle_Hash2 = GAMEPLAY::GET_HASH_KEY("police");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash2);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash2));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash2, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
						}
					}
				}
				Vehicle_Hash3 = GAMEPLAY::GET_HASH_KEY("Hotknife");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash3);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash3));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash3, Coords.x, Coords.y, Coords.z, 0, true, false);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash5 = GAMEPLAY::GET_HASH_KEY("a_c_husky");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash5);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash5));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash5, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash6 = GAMEPLAY::GET_HASH_KEY("a_c_humpback");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash6);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash6));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash6, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash7 = GAMEPLAY::GET_HASH_KEY("a_c_dolphin");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash7);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash7));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash7, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vehicle_Hash8 = GAMEPLAY::GET_HASH_KEY("a_c_killerwhale");
				{
					STREAMING::REQUEST_MODEL(Vehicle_Hash8);
					if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash8));
					{
						Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						int Handle = PED::CREATE_PED(1, Vehicle_Hash8, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
						if (ENTITY::DOES_ENTITY_EXIST(Handle))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);

						}
					}
				}
				Vector3 pos = get_player_coords(selectedPlayer);

				for (int i = 0; i < blacklistedObjects.size(); i++) {
					Object tempObject = OBJECT::CREATE_OBJECT(blacklistedObjects[i], pos.x, pos.y, pos.z, true, false, false);
					attach_entity_to_entity(tempObject, get_player_ped(selectedPlayer), SKEL_Spine0, 0, 0, 0, 0, 0, 0, false, false, false, true, 2, true);
					CrashObject.push_back(tempObject);
				}

				if (GetTickCount() > 650 + crashPlayerTimer) {
					for (int i = 0; i < CrashObject.size(); i++) {
						ENTITY::DETACH_ENTITY(CrashObject.at(i), 1, 0);
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(CrashObject.at(i), 1, 1);
						ENTITY::DELETE_ENTITY(&CrashObject.at(i));
					}
					CrashObject.clear();
					notifyMap("~g~Crashing! Wait A Few Seconds...");
					crashthisnigga2 = false;
				}
			}
			if (Menu::Option("Cherax Crash"))
			{
				int Pizza_Hash;
				int Pizza2_Hash;
				int i = 0;
				while (i < 12)
				{
					i++; //FIB_heist_lights 
					Pizza_Hash = GAMEPLAY::GET_HASH_KEY("prop_pizza_box_01");
					Pizza2_Hash = GAMEPLAY::GET_HASH_KEY("prop_pizza_box_02");
					{
						STREAMING::REQUEST_MODEL(Pizza_Hash);
						if (STREAMING::HAS_MODEL_LOADED(Pizza_Hash));
						{
							Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
							int Handle = OBJECT::CREATE_OBJECT_NO_OFFSET(Pizza_Hash, Coords.x, Coords.y, Coords.z, 1, 0, TRUE);
							int Handle2 = OBJECT::CREATE_OBJECT_NO_OFFSET(Pizza2_Hash, Coords.x, Coords.y, Coords.z, 1, 0, TRUE);
							if (ENTITY::DOES_ENTITY_EXIST(Handle))
							{
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle2, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
							}
						}
					}
				}
				WAIT(200);
				notifyMap("Cherax Crash Done");
			}

		}
		break;
		case gg:
		{
			Menu::Title("");
			Menu::SubTitle("General Grief");
			Menu::MenuOption("Crash Options", crashing);
			Menu::MenuOption("Griefer Options", attackersub);
			Menu::Toggle("Forcefield", SPlayer::Force);
			Menu::Toggle("Freeze", SPlayer::Freezeplayer);
			//Menu::Toggle("Jump", SPlayer::Jumpplayer);
			//Menu::Toggle("Ragdoll", SPlayer::Ragdollplayer);
			Menu::Toggle("Cage", SPlayer::mf);
			if (Menu::Option("Remove Cages")) {
				uint BadObjects[] = { 959275690, 1396140175, -1326042488, -1363719163, 1688773919, 3334677549, };
				Vector3 pp = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
				for (Hash hash : BadObjects) {
					ENTITY::CREATE_MODEL_SWAP(pp.x, pp.y, pp.z, 10.0f, hash, $("prop_ld_lap_top"), 0);
				}
			}
			//Menu::Toggle("Fire Loop", SPlayer::Fireloop);
			//Menu::Toggle("Water Loop", SPlayer::Waterloop);
			
			if (Menu::Option("Airstrike Player")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
				WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
					WAIT(0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			}
			Menu::Int("Explosion Type", expldplayer, 0, 73);
			if (Menu::Option("Explode Player"))
			{
				Vector3 GetPlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
				FIRE::ADD_EXPLOSION(GetPlayerCoords.x, GetPlayerCoords.y, GetPlayerCoords.z, expldplayer, 2000, true, false, 10);
				PED::EXPLODE_PED_HEAD(PLAYER::GET_PLAYER_PED(selectedPlayer), 0x145F1012);
			}
			if (Menu::Option("Ram Player")) {
				float offset;
				Hash vehmodel = GAMEPLAY::GET_HASH_KEY("BUS");
				STREAMING::REQUEST_MODEL(vehmodel);

				while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
				Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0.0, -10.0, 0.0);

				if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
				{
					Vector3 dim1, dim2;
					GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

					offset = dim2.y * 1.6;

					Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
					float rot = (ENTITY::GET_ENTITY_ROTATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0)).z;

					Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z, rot, 1, 1);

					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
					ENTITY::SET_ENTITY_VISIBLE(veh, true, 0);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 700.0);
				}

			}

			if (Menu::Option("Barrage Player")) {
				float offset;
				Hash vehmodel = GAMEPLAY::GET_HASH_KEY("molotok");
				STREAMING::REQUEST_MODEL(vehmodel);
				auto war = $("VEHICLE_WEAPON_TAMPA_MORTAR");
				if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				{
					WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
					while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
						WAIT(0);
					returntampar:;
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0.0, -10.0, 0.0);
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);

					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 1.f, pCoords.y + 0.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 0.f, pCoords.y + 1.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 0.f, pCoords.y + -1.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 2.f, pCoords.y + -2.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + 2.f, pCoords.y + 2.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + -2.f, pCoords.y + 2.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(pCoords.x + 0.f, pCoords.y + 0.f, pCoords.z + 10.f, pCoords.x + -3.f, pCoords.y + 3.f, pCoords.z + 0.f, 250, 1, war, playerPed, 1, 0, -1.0);
					goto molotokk;
				}

				if (WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				{
					goto returntampar;
				}
			molotokk:;

				while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
				Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0.0, -10.0, 0.0);

				if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
				{
					Vector3 dim1, dim2;
					GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

					offset = dim2.y * 1.6;

					Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
					float rot = (ENTITY::GET_ENTITY_ROTATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0)).z;

					Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z + 20.f, rot, 1, 1);

					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
					ENTITY::SET_ENTITY_VISIBLE(veh, true, 0);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 700.0);
				}

			}
			if (Menu::Option("Jesus")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				Hash pedm = GAMEPLAY::GET_HASH_KEY("U_M_M_Jesus_01");
				STREAMING::REQUEST_MODEL(pedm);
				while (!STREAMING::HAS_MODEL_LOADED(pedm))
					WAIT(0);
				eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
				ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
				PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
				WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
				AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
				PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
				PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
				egcount++;
			}
			if (Menu::Option("Lion")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_UNARMED");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				Hash pedm = GAMEPLAY::GET_HASH_KEY("A_C_MtLion");
				STREAMING::REQUEST_MODEL(pedm);
				while (!STREAMING::HAS_MODEL_LOADED(pedm))
					WAIT(0);
				eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
				ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
				PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
				AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
				PED::SET_PED_AS_ENEMY(eclone[egcount], 1);
				PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
				PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
				PED::SET_PED_KEEP_TASK(eclone[egcount], true);
				egcount++;
			}
			if (Menu::Option("Swat")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(selectedplayer, 0);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Hash model = GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01");
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model))
					WAIT(0);
				int createdmodel = PED::CREATE_PED(26, model, pCoords.x, pCoords.y, pCoords.z, 1, 1, 0);
				ENTITY::SET_ENTITY_INVINCIBLE(createdmodel, false);
				int vehmodel = GAMEPLAY::GET_HASH_KEY("RIOT");
				STREAMING::REQUEST_MODEL(vehmodel);
				while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
				Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x, pCoords.y, pCoords.z, 0.0, 1, 1);
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				Hash weapon = GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE");
				WEAPON::GIVE_WEAPON_TO_PED(createdmodel, weapon, weapon, 9999, 9999);
				PED::SET_PED_INTO_VEHICLE(createdmodel, veh, -1);
				AI::TASK_COMBAT_PED(createdmodel, selectedplayer, 1, 1);
				ENTITY::SET_ENTITY_INVINCIBLE(createdmodel, false);
				PED::SET_PED_COMBAT_ABILITY(createdmodel, 100);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdmodel, true);
				AI::TASK_COMBAT_PED(createdmodel, selectedplayer, 1, 1);
				PED::SET_PED_AS_ENEMY(createdmodel, 1);
				PED::SET_PED_COMBAT_RANGE(createdmodel, 1000);
				PED::SET_PED_KEEP_TASK(createdmodel, true);
				PED::SET_PED_AS_COP(createdmodel, 1000);
				PED::SET_PED_ALERTNESS(createdmodel, 1000);
			}
		}
		break;
		case attackersub: {
			Menu::Title("");
			Menu::SubTitle("Attacker Editor");
			Menu::Toggle("Griefer Invincible", attacker_invincible);
			Menu::Toggle("Griefer Is A Cop", attacker_has_cop);
			Menu::Toggle("Griefer Keep Task", attacker_keep_task);
			Menu::Toggle("Can Switch Weapons", attacker_weapon_switch);
			if (Menu::Int("Set Griefer Armour:", attacker_armour, 0, 100))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					attacker_armour = NumberKeyboarde();
				}
			}
			if (Menu::Int("Set Griefer Accuracy:", attacker_accuracy, 0, 1000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					attacker_accuracy = NumberKeyboarde();
				}
			}
			if (Menu::Int("Set Griefer Fire Rate:", attacker_shoot_rate, 0, 1000))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
				{
					attacker_shoot_rate = NumberKeyboarde();
				}
			}
			if (Menu::Addintchar("Griefer Model", attacker_model_list, attacker_model_pos, 0, 801)) {}
			if (Menu::Addintchar("Griefer Weapon", weapon_name, weapon_name_pos, 0, 96)) {}
			if (Menu::Option("Spawn Custom Griefer")) {
				custom_attacker(attacker_model_list[attacker_model_pos], weapon_name_list[weapon_name_pos]);
			}
			if (Menu::Option("Furry Griefer")) {
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_HOMINGLAUNCHER");
				Furry_attacker("WEAPON_GRENADELAUNCHER");
				Furry_attacker("WEAPON_RPG");
			}
			if (Menu::Option("Furry Griefer Stungun")) {
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");
				Furry_attacker("WEAPON_STUNGUN");

			}

		}
		break;
		case protections:
		{
			Protections::MainMenu();
		}
		break;
		case spv:
		{
			Menu::Title("");
			Menu::SubTitle("Vehicle Grief");
			if (Menu::Option("Kick From Vehicle"))
			{
				SPlayer::kickfromveh();
			}
			if (Menu::Option("Boost Vehicle"))
			{
				SPlayer::boosttoggle();
			}
			Menu::Toggle("Freeze Vehicle", SPlayer::ft);
			Menu::Toggle("Fuck Vehicle", SPlayer::mf1);
		}
		break;
#pragma endregion

		
#pragma region Hot Keys
		case hotkeys:
		{
			Menu::Title("Hot Keys");
			Menu::SubTitle("Hot Keys");
			Menu::Toggle("Repair Vehicle (F4)", Local::F4);
			Menu::Toggle("Teleport to Waypoint (F7)", Local::F7);
			Menu::Toggle("Noclip (F5)", freecamclip);
			
			
		}
		break;
#pragma endregion 
#pragma region gunstore
		case guns:
		{
			Weap::maingunmenu();
		}
		break;

		case II:
		{
			Weap::marktwoguns();
		}
		break;

		case HeavyGuns:
		{
			Weap::heavyguns();
		}
		break;

		case SniperRifles:
		{
			Weap::sniperrifles();
		}
		break;

		case Rifes:
		{
			Weap::rifes();
		}
		break;

		case Handguns:
		{
			Weap::handguns();
		}
		break;

		case Shotgun:
		{
			Weap::shotgun();
		}
		break;

		case MachineGuns:
		{
			Weap::machineguns();
		}
		break;

		case New_DLC_foursix:
		{
			Weap::new_DLC_foursix();
		}
		break;

		case tints:
		{
			Weap::Tints();
		}
		break;

		case ThrownWeapons:
		{
			Weap::thorwable();

		}
		break;

		case Melee:
		{
			Weap::meleee();
		}
		break;

		case KnuckleDuster:
		{
			Weap::knuckleduster();
		}
		break;

		case SwitchBlade:
		{
			Weap::switchblade();
		}
		break;

		case RAYMINIGUN:
		{
			Weap::Raygun();
		}
		break;

		case RAYCARBINE:
		{
			Weap::RAYCarbine();
		}
		break;

		case RAYPISTOL:
		{
			Weap::RAYPistol();
		}
		break;

		case Marksman_Rifle_Mk_II:
		{
			Weap::MarksmanRifleMkII();
		}
		break;

		case Tints_m:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_m:
		{
			Weap::camos_m();
		}
		break;

		case Muzzle_m:
		{
			Weap::muzzle_m();
		}
		break;

		case Barrel_m:
		{
			Weap::barrel_m();
		}
		break;

		case Attachment_m:
		{
			Weap::attachment_m();
		}
		break;

		case Scope_m:
		{
			Weap::scope_m();
		}
		break;

		case Magazine_m:
		{
			Weap::magazine_m();

		}
		break;

		case Pump_Shotgun_Mk_II:
		{
			Weap::pump_Shotgun_Mk_II();
		}
		break;

		case Muzzle_sg:
		{
			Weap::muzzle_sg();
		}
		break;

		case Tints_sg:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_sg:
		{
			Weap::camos_sg();
		}
		break;

		case Attachment_sg:
		{
			Weap::attachment_sg();
		}
		break;

		case Scope_sg:
		{
			Weap::scope_sg();
		}
		break;

		case Magazine_sg:
		{
			Weap::magazine_sg();
		}
		break;

		case Bullpup_Rifle_Mk_II:
		{
			Weap::bullpup_Rifle_Mk_II();
		}
		break;

		case Tints_b:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_b:
		{
			Weap::camos_b();
		}
		break;

		case Muzzle_b:
		{
			Weap::muzzle_b();
		}
		break;

		case Barrel_b:
		{
			Weap::barrel_b();
		}
		break;

		case Attachment_b:
		{
			Weap::attachment_b();
		}
		break;

		case Scope_b:
		{
			Weap::scope_b();
		}
		break;

		case Magazine_b:
		{
			Weap::magazine_b();
		}
		break;

		case Special_Carbine_Mk_II:
		{
			Weap::special_Carbine_Mk_II();
		}
		break;

		case Tints_sc:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_sc:
		{
			Weap::camos_sc();
		}
		break;

		case Muzzle_sc:
		{
			Weap::muzzle_sc();
		}
		break;

		case Barrel_sc:
		{
			Weap::barrel_sc();
		}
		break;

		case Attachment_sc:
		{
			Weap::attachment_sc();
		}
		break;

		case Scope_sc:
		{
			Weap::scope_sc();
		}
		break;

		case Magazine_sc:
		{
			Weap::magazine_sc();
		}
		break;

		case Revolver_Mk_II:
		{
			Weap::revolver_Mk_II();
		}
		break;

		case Tints_r:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_r:
		{
			Weap::camos_r();
		}
		break;

		case Attachment_r:
		{
			Weap::attachment_r();
		}
		break;

		case Magazine_r:
		{
			Weap::magazine_r();
		}
		break;

		case SNS_Pistol_Mk_II:
		{
			Weap::sNS_Pistol_Mk_II();
		}
		break;

		case Tints_sn:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_sn:
		{
			Weap::camos_sn();
		}
		break;

		case Attachment_sn:
		{
			Weap::attachment_sn();
		}
		break;

		case Magazine_sn:
		{
			Weap::magazine_sn();
		}
		break;

		case Heavy_Sniper_Mk_II:
		{
			Weap::heavy_Sniper_Mk_II();
		}
		break;

		case Tints_hs:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_hs:
		{
			Weap::camos_hs();
		}
		break;

		case Muzzle_hs:
		{
			Weap::muzzle_hs();
		}
		break;

		case Barrel_hs:
		{
			Weap::barrel_hs();
		}
		break;

		case Attachment_hs:
		{
			Weap::attachment_hs();
		}
		break;

		case Scope_hs:
		{
			Weap::scope_hs();
		}
		break;

		case Magazine_hs:
		{
			Weap::magazine_hs();
		}
		break;

		case Combat_MG_Mk_II:
		{
			Weap::combat_MG_Mk_II();
		}
		break;

		case Tints_mg:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_mg:
		{
			Weap::camos_mg();
		}
		break;

		case Muzzle_mg:
		{
			Weap::muzzle_mg();
		}
		break;

		case Barrel_mg:
		{
			Weap::barrel_mg();
		}
		break;

		case Attachment_mg:
		{
			Weap::attachment_mg();
		}
		break;

		case Scope_mg:
		{
			Weap::scope_mg();
		}
		break;

		case Magazine_mg:
		{
			Weap::magazine_mg();
		}
		break;

		case Carbine_Rifle_Mk_II:
		{
			Weap::carbine_Rifle_Mk_II();
		}
		break;

		case Tints_c:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_c:
		{
			Weap::camos_c();
		}
		break;

		case Muzzle_c:
		{
			Weap::muzzle_c();
		}
		break;

		case Barrel_c:
		{
			Weap::barrel_c();
		}
		break;

		case Attachment_c:
		{
			Weap::attachment_c();
		}
		break;

		case Scope_c:
		{
			Weap::scope_c();
		}
		break;

		case Magazine_c:
		{
			Weap::magazine_c();
		}
		break;

		case Assault_Rifle_Mk_II:
		{
			Weap::assault_Rifle_Mk_II();
		}
		break;

		case Tints_a:
		{
			Weap::mk2tints();

		}
		break;

		case Camos_a:
		{
			Weap::camos_a();
		}
		break;

		case Muzzle_a:
		{
			Weap::muzzle_a();
		}
		break;

		case Barrel_a:
		{
			Weap::barrel_a();
		}
		break;

		case Attachment_a:
		{
			Weap::attachment_a();
		}
		break;

		case Scope_a:
		{
			Weap::scope_a();
		}
		break;

		case Magazine_a:
		{
			Weap::magazine_a();
		}
		break;

		case SMG_Mk_II:
		{
			Weap::sMG_Mk_II();
		}
		break;

		case Tints_s:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_s:
		{
			Weap::camos_s();
		}
		break;

		case Muzzle_s:
		{
			Weap::muzzle_s();
		}
		break;

		case Barrel_s:
		{
			Weap::barrel_s();
		}
		break;

		case Attachment_s:
		{
			Weap::attachment_s();
		}
		break;

		case Scope_s:
		{
			Weap::scope_s();
		}
		break;

		case Magazine_s:
		{
			Weap::magazine_s();
		}
		break;

		case MK2_Pistol:
		{
			Weap::mK2_Pistol();
		}
		break;

		case Tints_P:
		{
			Weap::mk2tints();
		}
		break;

		case Camos_p:
		{
			Weap::camos_p();
		}
		break;

		case Attachment_p:
		{
			Weap::attachment_p();
		}
		break;

		case Magazine_p:
		{
			Weap::magazine_p();
		}
		break;
		case cal:
		{
			Weap::call();
		}
		break;

		case sns:
		{
			Weap::snss();

		}
		break;

		case Pistol:
		{
			Weap::pistol();
		}
		break;

		case MarksmanPistol:
		{
			Weap::marksmanPistol();
		}
		break;
		case Revolver:
		{
			Weap::revolver();
		}
		break;
		case vintage:
		{
			Weap::Vintage();
		}
		break;
		case MACHINE:
		{
			Weap::mACHINE();
		}
		break;
		case app:
		{
			Weap::App();
		}
		break;
		case combat:
		{
			Weap::Combat();
		}
		break;
		case heavy:
		{
			Weap::HEavy();
		}
		break;
		case FlareGun:
		{
			Weap::flareGun();
		}
		break;
		case StunGun:
		{
			Weap::stunGun();
		}
		break;
		case Autoshotgun:
		{
			Weap::autoshotgun();
		}
		break;
		case SawnoffShotgun:
		{
			Weap::sawnoffShotgun();
		}
		break;
		case DoubleBarrelShotgun:
		{
			Weap::doubleBarrelShotgun();
		}
		break;
		case HeavyShotgun:
		{
			Weap::HeavyshOtgun();
		}
		break;
		case BullpupShotgun:
		{
			Weap::bullpupShotgun();
		}
		break;
		case AssaultShotgun:
		{
			Weap::assaultShotgun();
		}
		break;
		case pump:
		{
			Weap::PumP();
		}
		break;
		case combatSG:
		{
			Weap::Combatsg();
		}
		break;
		case Musket:
		{
			Weap::musket();
		}
		break;

		case Gusenberg:
		{
			Weap::gusenberg();
		}
		break;

		case AssultSMG:
		{
			Weap::assultSMG();
		}
		break;

		case MicroSMG:
		{
			Weap::microSMG();
		}
		break;

		case smg:
		{
			Weap::ssmg();
		}
		break;

		case CombatPDW:
		{
			Weap::combatPDW();
		}
		break;

		case CombatMG:
		{
			Weap::combatMG();
		}
		break;

		case MG:
		{
			Weap::MGg();
		}
		break;

		case BullpupRiflev2:
		{
			Weap::Bullpupriflev2();
		}
		break;

		case MiliTaryrifle:
		{
			Weap::Militaryrifle();
		}
		break;//Militaryrifle

		case SpecialCarbine:
		{
			Weap::Specialcarbine();
		}
		break;

		case AdvancedRifle:
		{
			Weap::Advancedrifle();
		}
		break;

		case CarbineRifle:
		{
			Weap::Carbinerifle();

		}
		break;

		case AssaultRifle:
		{
			Weap::assaultRifle();
		}
		break;

		case CompactRifle:
		{
			Weap::Compactrifle();
		}
		break;

		case MarksmanRifle:
		{
			Weap::Marksmanrifle();
		}
		break;

		case sp:
		{
			Weap::spp();
		}
		break;

		case HeavySniper:
		{
			Weap::Heavysniper();
		}
		break;

		case RPG:
		{
			Weap::RPGg();
		}
		break;

		case Minigun:
		{
			Weap::MinigunN();
		}
		break;

		case GrenadeLauncher:
		{
			Weap::GrenadeLauncherR();
		}
		break;

		case Firework:
		{
			Weap::FireworkK();
		}
		break;

		case HomingLauncher:
		{
			Weap::HomingLauncherr();
		}
		break;

		case GrenadeLauncherSmoke:
		{
			Weap::GrenadeLauncherSmokee();
		}

		break;

		case CompactLauncher:
		{
			Weap::CompactLauncherr();
		}
		break;

		case Railgun:
		{
			Weap::Railgunn();
		}
		break;
#pragma endregion
#pragma region vehspawner
		case vehspawnersub: {
			Menu::Title("Vehicle Spawner");

			Menu::SubTitle("Vehicle Spawner");
			Menu::Toggle("Spawn in Car", Reee::spawnincar);
			Menu::Toggle("Spawn Maxed", Reee::spawnmaxed);
			Menu::Toggle("Plane Spawn Fly Boost", Reee::skyplane);
			//Menu::Toggle("Basic Vehicle Info", Reee::Vehinfo);
			Menu::Toggle("Fade In Spawned", Reee::vehSpawnFade);
			Menu::Toggle("Bypass Game Despawn", Reee::spbypass);
			Menu::Toggle("Store The Vehicle", Reee::GiftVehicle);
			Menu::Toggle("Spawn In GodMode", Reee::SetGodMode);
			Menu::Toggle("Spawn Whit Foxy License Plate", Reee::LicensePlate);
			Menu::Toggle("Spawn Whit A Modded Color", Reee::RandomModdedColor);
			if (Menu::Option("Spawn By Name"))
			{
				Reee::SpawnVehicle(CharKeyboard());
			}
			if (Menu::Option("~f~[ ~w~Last DlC Vehicles ~f~]")){}
			Menu::MenuOption("Mercenaries Update", mercenariesdlc);
			Menu::MenuOption("Drug Wars Update", Drugwarsdlc);
			Menu::MenuOption("Tuner Update", tunerdlc);
			Menu::MenuOption("Cayo Update", cayodlc);
			Menu::MenuOption("Summer Update", summerdlc);
			Menu::MenuOption("Casino", newdlc);
			if (Menu::Option("~f~[ ~w~Cars ~f~]")) {}
			Menu::MenuOption("Super", Super);
			Menu::MenuOption("Sports", Sports);
			Menu::MenuOption("Sport Classic", SportClassic);
			Menu::MenuOption("Offroad", Offroad);
			Menu::MenuOption("Sedans", Sedans);
			Menu::MenuOption("Coupes", Coupes);
			Menu::MenuOption("Muscle", Muscle);
			Menu::MenuOption("Utility & Vans", uUtility);
			Menu::MenuOption("Commercial", Commercial);
			Menu::MenuOption("Compacts", Compacts);
			Menu::MenuOption("Emergency", Emergency);
			Menu::MenuOption("SUV", SUV);
			if (Menu::Option("~f~[ ~w~Flying Vehicles ~f~]")) {}
			Menu::MenuOption("Helicopters", Helicopters);
			Menu::MenuOption("Planes", Planes);
			if (Menu::Option("~f~[ ~w~Other Vehicles ~f~]")) {}
			Menu::MenuOption("Motorcycles", Motorcycles);
			Menu::MenuOption("Industrial", Industrial);
			Menu::MenuOption("Cycles", Cycles);
			Menu::MenuOption("Trailer", Trailer);
			Menu::MenuOption("Trains", Trains);
			Menu::MenuOption("Service", Service);
			Menu::MenuOption("Boats", Boats);
			Menu::MenuOption("Industrial", Industrial);
			Menu::MenuOption("Military", Military);

		}
		break;//tunerspinSpawner
		case mercenariesdlc2: { Spawner::MercenariespinSpawnergift(); } break;
		case Drugwarsdlc2: { Spawner::DrugwarspinSpawnergift(); } break;
		case tunerdlc2: { Spawner::tunerspinSpawnergift(); } break;
		case cayodlc2: { Spawner::cayospinSpawnergift(); } break;
		case summerdlc2: { Spawner::summerspinSpawnergift(); } break;
		case casinodlc2: { Spawner::CasinospinSpawnergift(); } break;
		case SSdlc2: { Spawner::SSspinSpawnergift(); } break;
		case Sports2: { Spawner::sportspinSpawnergift(); } break;
		case SportClassic2: { Spawner::sportclassicsspinSpawnergift(); } break;
		case Offroad2: { Spawner::OffRoadspinSpawnergift(); } break;
		case Sedans2: { Spawner::SedansspinSpawnergift(); } break;
		case Coupes2: { Spawner::CoupesspinSpawnergift(); } break;
		case Muscle2: { Spawner::MusclespinSpawnergift(); } break;
		case Boats2: { Spawner::BoatspinSpawnergift(); } break;
		case Commercial2: { Spawner::CommercialspinSpawnergift(); } break;
		case Compacts2: { Spawner::CompactsspinSpawnergift(); } break;
		case Cycles2: { Spawner::CyclesspinSpawnergift(); } break;
		case Emergency2: { Spawner::EmergencyspinSpawnergift(); } break;
		case Helicopters2: { Spawner::HelicoptersspinSpawnergift(); } break;
		case Industrial2: { Spawner::IndustrialspinSpawnergift(); } break;
		case Military2: { Spawner::MilitaryspinSpawnergift(); } break;
		case Planes2: { Spawner::PlanesspinSpawnergift(); } break;
		case Service2: { Spawner::ServicespinSpawnergift(); } break;
		case Motorcycles2: { Spawner::MotorcyclespinSpawnergift(); } break;
		case SUV2: { Spawner::SUVspinSpawnergift(); } break;
		case Trailer2: { Spawner::TrailerspinSpawnergift(); } break;
		case Trains2: { Spawner::TranspinSpawnergift(); } break;
		case uUtility2: { Spawner::UtilityspinSpawnergift(); } break;

		case mercenariesdlc: { Spawner::MercenariespinSpawner(); } break;
		case Drugwarsdlc: { Spawner::DrugwarspinSpawner(); } break;
		case tunerdlc: { Spawner::tunerspinSpawner(); } break;
		case cayodlc: { Spawner::cayospinSpawner(); } break;
		case summerdlc: { Spawner::summerspinSpawner(); } break;
		case Sports: { Spawner::sportspinSpawner(); } break;
		case SportClassic: { Spawner::sportclassicsspinSpawner(); } break;
		case Offroad: { Spawner::OffRoadspinSpawner(); } break;
		case Sedans: { Spawner::SedansspinSpawner(); } break;
		case Coupes: { Spawner::CoupesspinSpawner(); } break;
		case Muscle: { Spawner::MusclespinSpawner(); } break;
		case Boats: { Spawner::BoatspinSpawner(); } break;
		case Commercial: { Spawner::CommercialspinSpawner(); } break;
		case Compacts: { Spawner::CompactsspinSpawner(); } break;
		case Cycles: { Spawner::CyclesspinSpawner(); } break;
		case Emergency: { Spawner::EmergencyspinSpawner(); } break;
		case Helicopters: { Spawner::HelicoptersspinSpawner(); } break;
		case Industrial: { Spawner::IndustrialspinSpawner(); } break;
		case Military: { Spawner::MilitaryspinSpawner(); } break;
		case Planes: { Spawner::PlanesspinSpawner(); } break;
		case Service: { Spawner::ServicespinSpawner(); } break;
		case Motorcycles: { Spawner::MotorcyclespinSpawner(); } break;
		case SUV: { Spawner::SUVspinSpawner(); } break;
		case Trailer: { Spawner::TrailerspinSpawner(); } break;
		case Trains: { Spawner::TranspinSpawner(); } break;
		case uUtility: { Spawner::UtilityspinSpawner();} break;
#pragma region dlcc	 
		case newdlc:
			Menu::Title("");
			drawvehicle;
			Menu::SubTitle("Casino");
			if (Menu::Settings::currentOption == 1) {
				previewCar("CARACARA2");
			}
			if (Menu::Settings::currentOption == 2) {
				previewCar("DRAFTER");
			}
			if (Menu::Settings::currentOption == 3) {
				previewCar("DYNASTY");
			}
			if (Menu::Settings::currentOption == 4) {
				previewCar("EMERUS");
			}
			if (Menu::Settings::currentOption == 5) {
				previewCar("GAUNTLET3");
			}
			if (Menu::Settings::currentOption == 6) {
				previewCar("GAUNTLET4");
			}
			if (Menu::Settings::currentOption == 7) {
				previewCar("HELLION");
			}
			if (Menu::Settings::currentOption == 8) {
				previewCar("ISSI7");
			}
			if (Menu::Settings::currentOption == 9) {
				previewCar("JUGULAR");
			}
			if (Menu::Settings::currentOption == 10) {
				previewCar("LOCUST");
			}
			if (Menu::Settings::currentOption == 11) {
				previewCar("NEBULA");
			}
			if (Menu::Settings::currentOption == 12) {
				previewCar("NEO");
			}
			if (Menu::Settings::currentOption == 13) {
				previewCar("NOVAK");
			}
			if (Menu::Settings::currentOption == 14) {
				previewCar("PARAGON");
			}
			if (Menu::Settings::currentOption == 15) {
				previewCar("S80");
			}
			if (Menu::Settings::currentOption == 16) {
				previewCar("THRAX");
			}
			if (Menu::Settings::currentOption == 17) {
				previewCar("ZION3");
			}
			if (Menu::Settings::currentOption == 18) {

				previewCar("ZORRUSSO");
			}
			if (Menu::Option("Caracara 2"))
			{
				SpawnVeh("CARACARA2");
			}
			if (Menu::Option("Drafter"))
			{
				SpawnVeh("DRAFTER");
			}
			if (Menu::Option("Dynasty"))
			{
				SpawnVeh("DYNASTY");
			}
			if (Menu::Option("Emerus"))
			{
				SpawnVeh("EMERUS");
			}
			if (Menu::Option("Gauntlet 3"))
			{
				SpawnVeh("GAUNTLET3");
			}
			if (Menu::Option("Gauntlet 4"))
			{
				SpawnVeh("GAUNTLET4");
			}
			if (Menu::Option("Hellion"))
			{
				SpawnVeh("HELLION");
			}
			if (Menu::Option("Issi 7"))
			{
				SpawnVeh("ISSI7");
			}
			if (Menu::Option("Jagular"))
			{
				SpawnVeh("JUGULAR");
			}
			if (Menu::Option("Locust"))
			{
				SpawnVeh("LOCUST");
			}
			if (Menu::Option("Nebula"))
			{
				SpawnVeh("NEBULA");
			}
			if (Menu::Option("Neo"))
			{
				SpawnVeh("NEO");
			}
			if (Menu::Option("Novak"))
			{
				SpawnVeh("NOVAK");
			}
			if (Menu::Option("Paragon"))
			{
				SpawnVeh("PARAGON");
			}
			if (Menu::Option("S 80"))
			{
				SpawnVeh("S80");
			}
			if (Menu::Option("Thrax"))
			{
				SpawnVeh("THRAX");
			}
			if (Menu::Option("Zion 3"))
			{
				SpawnVeh("ZION3");
			}
			if (Menu::Option("Zorrusso"))
			{
				SpawnVeh("ZORRUSSO");
			}
			break;
#pragma endregion
		case Super:
			Menu::Title("Super");

			Menu::SubTitle("Super");

			if (Menu::Settings::currentOption == 1) {
				previewCar("ADDER");
			}
			if (Menu::Settings::currentOption == 2) {
				previewCar("autarch");
			}
			if (Menu::Settings::currentOption == 3) {
				previewCar("BANSHEE2");
			}
			if (Menu::Settings::currentOption == 4) {
				previewCar("BULLET");
			}
			if (Menu::Settings::currentOption == 5) {
				previewCar("CHEETAH");
			}
			if (Menu::Settings::currentOption == 6) {
				previewCar("deluxo");
			}
			if (Menu::Settings::currentOption == 7) {
				previewCar("ENTITYXF");
			}
			if (Menu::Settings::currentOption == 8) {
				previewCar("FMJ");
			}
			if (Menu::Settings::currentOption == 9) {
				previewCar("SHEAVA");
			}
			if (Menu::Settings::currentOption == 10) {
				previewCar("INFERNUS");
			}
			if (Menu::Settings::currentOption == 11) {
				previewCar("NERO");
			}
			if (Menu::Settings::currentOption == 12) {
				previewCar("NERO2");
			}
			if (Menu::Settings::currentOption == 13) {
				previewCar("OSIRIS");
			}
			if (Menu::Settings::currentOption == 14) {
				previewCar("LE7B");
			}
			if (Menu::Settings::currentOption == 15) {
				previewCar("DEVESTE");
			}
			if (Menu::Settings::currentOption == 16) {
				previewCar("ITALIGTB");
			}
			if (Menu::Settings::currentOption == 17) {
				previewCar("ITALIGTB2");
			}
			if (Menu::Settings::currentOption == 18) {
				previewCar("PFISTER811");
			}
			if (Menu::Settings::currentOption == 19) {
				previewCar("PROTOTIPO");
			}
			if (Menu::Settings::currentOption == 20) {
				previewCar("REAPER");
			}
			if (Menu::Settings::currentOption == 21) {
				previewCar("SULTANRS");
			}
			if (Menu::Settings::currentOption == 22) {
				previewCar("T20");
			}
			if (Menu::Settings::currentOption == 23) {
				previewCar("TEMPESTA");
			}
			if (Menu::Settings::currentOption == 24) {
				previewCar("TURISMOR");
			}
			if (Menu::Settings::currentOption == 25) {
				previewCar("TYRUS");
			}
			if (Menu::Settings::currentOption == 26) {
				previewCar("tezeract");
			}
			if (Menu::Settings::currentOption == 27) {
				previewCar("entity2");
			}
			if (Menu::Settings::currentOption == 28) {
				previewCar("VACCA");
			}
			if (Menu::Settings::currentOption == 29) {
				previewCar("VOLTIC");
			}
			if (Menu::Settings::currentOption == 30) {
				previewCar("ZENTORNO");
			}
			if (Menu::Settings::currentOption == 31) {
				previewCar("visione");
			}
			if (Menu::Settings::currentOption == 32) {
				previewCar("Vigilante");
			}
			if (Menu::Settings::currentOption == 33) {
				previewCar("VOLTIC2");
			}
			if (Menu::Settings::currentOption == 34) {
				previewCar("PENETRATOR");
			}
			if (Menu::Settings::currentOption == 35) {
				previewCar("GP1");
			}

			if (Menu::Option("Adder"))
			{
				SpawnVeh("ADDER");
			}
			if (Menu::Option("Autarch"))
			{
				SpawnVeh("autarch");
			}
			if (Menu::Option("Banshee"))
			{
				SpawnVeh("BANSHEE2");
			}
			if (Menu::Option("Bullet"))
			{
				SpawnVeh("BULLET");
			}
			if (Menu::Option("Cheetah"))
			{
				SpawnVeh("CHEETAH");
			}
			if (Menu::Option("Deluxo"))
			{
				SpawnVeh("deluxo");
			}
			if (Menu::Option("Entity XF"))
			{
				SpawnVeh("ENTITYXF");
			}
			if (Menu::Option("FMJ"))
			{
				SpawnVeh("FMJ");
			}
			if (Menu::Option("Sheava"))
			{
				SpawnVeh("SHEAVA");
			}
			if (Menu::Option("Infernus"))
			{
				SpawnVeh("INFERNUS");
			}
			if (Menu::Option("Nero"))
			{
				SpawnVeh("NERO");
			}
			if (Menu::Option("Nero 2"))
			{
				SpawnVeh("NERO2");
			}
			if (Menu::Option("Osiris"))
			{
				SpawnVeh("OSIRIS");
			}
			if (Menu::Option("LE7B"))
			{
				SpawnVeh("LE7B");
			}
			if (Menu::Option("Deveste"))
			{
				SpawnVeh("DEVESTE");
			}
			if (Menu::Option("ItaliGTB"))
			{
				SpawnVeh("ITALIGTB");
			}
			if (Menu::Option("ItaliGTB 2"))
			{
				SpawnVeh("ITALIGTB2");
			}
			if (Menu::Option("Pfister 811"))
			{
				SpawnVeh("PFISTER811");
			}
			if (Menu::Option("Prototipo"))
			{
				SpawnVeh("PROTOTIPO");
			}
			if (Menu::Option("Adder"))
			{
				SpawnVeh("REAPER");
			}
			if (Menu::Option("Sultan RS"))
			{
				SpawnVeh("SULTANRS");
			}
			if (Menu::Option("T 20"))
			{
				SpawnVeh("t20");
			}
			if (Menu::Option("Tempesta"))
			{
				SpawnVeh("TEMPESTA");
			}
			if (Menu::Option("Turismo R"))
			{
				SpawnVeh("turismor");
			}
			if (Menu::Option("Tyrus"))
			{
				SpawnVeh("tyrus");
			}
			if (Menu::Option("Tezeract"))
			{
				SpawnVeh("tezeract");
			}
			if (Menu::Option("Entity2"))
			{
				SpawnVeh("entity2");
			}
			if (Menu::Option("Vacca"))
			{
				SpawnVeh("VACCA");
			}
			if (Menu::Option("Voltic"))
			{
				SpawnVeh("VOLTIC");
			}
			if (Menu::Option("Zentorno"))
			{
				SpawnVeh("ZENTORNO");
			}
			if (Menu::Option("Visione"))
			{
				SpawnVeh("visione");
			}
			if (Menu::Option("Vigilante"))
			{
				SpawnVeh("Vigilante");
			}
			if (Menu::Option("Penetrator"))
			{
				SpawnVeh("PENETRATOR");
			}
			if (Menu::Option("GP 1"))
			{
				SpawnVeh("gp1");
			}

			break;
			case pbright:
			{
				Spawner::brightcolors();
			}
			break;
			case sbright:
			{
				Spawner::sbright1();
			}
			break;
			case ResprayssED:
			{
				Spawner::ResprayssED1();
			}
			break;
			case Smoke:
			{
				Spawner::Smoke1();
			}
			break;
			case TRGB:
			{
				Spawner::TRGB1();
			}
			break;
			case Primaryyy:
			{
				Spawner::Primaryyy1();
			}
			break;
			case Chrome:
			{
				Spawner::Chrome1();
			}
			break;
			case ClassicMetallic:
			{
				Spawner::ClassicMetallic1();
			}
			break;
			case Secondaryyy:
			{
				Spawner::SecondaryStuff();
			}
			break;
			case pearlescents:
			{
				Spawner::pearlescents1();
			}
			break;
			case picker:
			{
				Spawner::picker1();
			}
			break;
			case Chromes:
			{
				Spawner::Chromes1();
			}
			break;
			case ClassicMetallics:
			{
				Spawner::ClassicMetallics1();
			}
			break;
			case Mattes:
			{
				Spawner::Mattes1();
			}	
			break;
			case Metals:
			{
				Spawner::Metals1();
			}
			break;
			case Metalss:
			{
				Spawner::Metalss1();
			}
			break;
			case Wheels:
			{
				Spawner::Wheels();
			}
			break;
			case wheelclass:
			{
				Spawner::wheelclass();
			}
			break;
			case wheelmatte:
			{
				Spawner::wheelmatte();
			}
			break;
			case wheelmetal:
			{
				Spawner::wheelmetal();
			}
			break;
			case Matte:
			{
				Spawner::Matte1();
			}
			break;
			case wheelcolour:
			{
				Spawner::Primaryyy1();
			}
			break;
			case BackWheels:
			{
				Spawner::BW();
			}
			break;
			case Rims:
			{
				Spawner::Rims1();
			}
			break;
			case Tunerrims:
			{
				Spawner::Tuner();
			}
			break;
			case SUVrims:
			{
				Spawner::SUV33();
			}
			break;
			case Lowriderrims:
			{
				Spawner::Lowrider34();
			}
			break;
			case Sportrims:
			{
				Spawner::Spawnstrim35();
			}
			break;
			case Offroadrims:
			{
				Spawner::OffRoad36();
			}
			break;
			case Musclerims:
			{
				Spawner::Musclespin37();
			}
			break;
			case Highendrims:
			{
				Spawner::Highend17();
			}
			break;
			case Plate:
			{
				Spawner::plade71();
			}
			break;
			case Light:
			{
				Spawner::light();
			}
			break;
			case NEEE:
			{
				Spawner::NeonOptions();
			}
			break;
			case Neonnn:
			{
				Spawner::NeonOptions2();
			}
			break;
			case fbumper:
			{
				Spawner::frontbumerstuff();
			}
			break;
			case rbumper:
			{
				Spawner::reabomberstuff();
			}
			break;
			case Hood:
			{
				Spawner::HoodStuff();
			}
			break;
			case Roof:
			{
				Spawner::RoofStuff();
			}
			break;
			case Grill:
			{
				Spawner::GrillStuff();
			}
			break;
			case Skirts:
			{
				Spawner::SkirtsStuff();
			}
			break;
			case Exhaust:
			{
				Spawner::ExhaustStuff();
			}
			break;
			case Spoiler:
			{
				Spawner::SpoilerStuff();
			}
			break;
			case Platee:
			{
				Spawner::PlateeStuff();
			}
			break;
#pragma endregion
#pragma region Fight Assist
			case FA:
			{
				Menu::Title("");
				Menu::SubTitle("Fight Assist");
				Menu::MenuOption("PvP(s)", FA1);
				Menu::MenuOption("Race", FA2);
				Menu::MenuOption("Vehicle", FA3);
			}
			break;
			case FA1:
			{
				Menu::Title("");
				Menu::SubTitle("PvP(s)");
				Menu::Toggle("One Shot One Kill No Luck Just Skill", Weap::Onehit);
				Menu::Toggle("Aimbot", Weap::Aimbot);
				Menu::Toggle("Infinite Ammo", Weap::InfiniteAmmo);
				Menu::Toggle1("Auto Generate Health", Local::isAutoRegHealth, [] { Local::AutoRegHealth(Local::isAutoRegHealth); });
				Menu::Toggle1("Auto Generate Armor", Local::isAutoRegArmour, [] { Local::AutoRegArmour(Local::isAutoRegArmour); });
				if (Menu::Option("Oppressor Mk.II"))
				{
					Reee::SpawnVehicle("oppressor2");
				}
				if (Menu::Option("Give All Weapons")) {
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					for each (Hash weapon in weaponsList)
					{
						WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
					}
				}
			}
			break;
			case FA2:
			{
				Menu::Title("");
				Menu::SubTitle("Race Assist");
				if (Menu::Option("~f~[ ~w~Other Player ~f~]")) {}
				Menu::Toggle("Freeze Vehicle", SPlayer::ft1234);
				Menu::Toggle("Fuck Vehicle", SPlayer::mf11234);
				if (Menu::Addintchar("Kill Engine", Killenginestuff, RemKE, 0, 1))
				{
					if (Remtp == 0)
					{
						for (int i = 0; i < 32; i++)
						{
							if (i != PLAYER::PLAYER_ID())
							{
								if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(i), 0));
								Player playerPed = PLAYER::GET_PLAYER_PED(i);
								Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
								{
									RequestControlOfEnt(veh);
									VEHICLE::SET_VEHICLE_ENGINE_HEALTH(veh, 0);
								}
							}
						}
					}
					if (Remtp == 1)
					{
						for (int i = 0; i < 32; i++)
						{
							if (i != PLAYER::PLAYER_ID())
							{
								if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(i), 0)); 
								Player playerPed = PLAYER::GET_PLAYER_PED(i);
								Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
								{
									RequestControlOfEnt(veh);
									VEHICLE::SET_VEHICLE_ENGINE_HEALTH(veh, -1);
								}
							}
						}
					}
				}
				
				if (Menu::Option("Pup Tires"))
				{
					for (int i = 0; i < 32; i++)
					{
						if (i != PLAYER::PLAYER_ID())
						{
							Vehicle selectedlPlayerveh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
							bool isveh = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);

							if (isveh)
							{
								VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedlPlayerveh, true);

								for (int i = 5; i--;)
								{
									VEHICLE::SET_VEHICLE_TYRE_BURST(selectedlPlayerveh, i, true, 1000.f);
								}
							}
							else
							{

							}
						}
					}
				}
				if (Menu::Option("Kick From Vehicle")) {
					for (int i = 0; i < 32; i++)
					{
						if (i != PLAYER::PLAYER_ID())
						{
							RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
							AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
							AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
							AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						}
					}
				};
				if (Menu::Option("~f~[ ~w~You ~f~]")){}
				Menu::Toggle("Instant Brake", Veh::InstantBreak);
				if (Menu::Int("Boost Level:", Veh::Boostttt, 0, 1000, 10))
				{
					if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
						Menu::Settings::hornpower = NumberKeyboard();
					}
				}
				Menu::Toggle("Enable Boost", Veh::Boost);
				Menu::Toggle("No Bike Fall", Veh::bikeNoFall);
				Menu::Toggle("Container Rider", Veh::CR);
			}
			break;
			case FA3:
			{
				Menu::Title("");
				Menu::SubTitle("Vehicle Assist");
				Menu::Toggle("Invincible", Veh::cargod);
				Menu::Toggle("Fly", Veh::FlyCar);
				Menu::Toggle("Shoot Explosives", Veh::Shootrpg6);
				if (Menu::Option("Adder"))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY("ADDER");
					auto coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
					float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
					if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
						STREAMING::REQUEST_MODEL(model);
						while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
						Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
						VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
						VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
						WAIT(0);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					}
				}
				if (Menu::Option("Oppressor Mk.II"))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY("oppressor2");
					auto coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
					float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
					if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
						STREAMING::REQUEST_MODEL(model);
						while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
						Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
						VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
						VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
						WAIT(0);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					}
				}
			}
			break;
			case tp:
			{
				Foxy_EngineTP::Teleportmainsub();
			}
			break;
			case TPClothingStore:
			{
				Foxy_EngineTP::Clothingstoress();
			}
			break;
			case TPBarbers:
			{
				Foxy_EngineTP::Barberss();
			}
			break;
			case TPLSC:
			{
				Foxy_EngineTP::telelsc();
			}
			break;
			case TPOVehicle:
			{
				Foxy_EngineTP::vehtpting();
			}
			break;
			case TPAmmunation:
			{
				Foxy_EngineTP::TPAmmu();
			}
			break;
			case TPSports:
			{
				Foxy_EngineTP::tpsportss();
			}
			break;
			case TPStores:
			{
				Foxy_EngineTP::Clothingstoress();
			}
			break;
			case TPCinema:
			{
				Foxy_EngineTP::Cinemakek();
			}
			break;
			case TPTattos:
			{
				Foxy_EngineTP::TPtattoo();
			}
			break;
			case TPAir:
			{
				Foxy_EngineTP::TPairports();
			}
			break;
			case TPFun:
			{
				Foxy_EngineTP::tpnotfun();
			}
			break;
			case TPOther:
			{
				Foxy_EngineTP::TPmisc();
			}
			break;
			case TPUnderwater:
			{
				Foxy_EngineTP::underwater();
			}
			break;
			case TPATMs:
			{
				Foxy_EngineTP::atmtp();
			}
			break;
			case TPBanks:
			{
				Foxy_EngineTP::bankss();
			}
			break;
			case TPRp:
			{
				Foxy_EngineTP::Rpss();
			}
			break;
			case TPServices:
			{
				Foxy_EngineTP::servicesss();
			}
			break;
			case TPAparts:
			{
				Foxy_EngineTP::aparts();
			}
			break;
			case settings:
			{
				Menu::Title("");
				Menu::SubTitle("Settings");
				Menu::MenuOption("Credit", Thanks);
				if (Menu::Addintchar("Choose A UI", Menu_UI_Name, Menu::Settings::CurHeader, 0, 9)) {}
				if (Menu::Option("Move Left")) {
					Menu::Settings::menuX = 0.17f;
				}
				if (Menu::Option("Move Right")) {
					Menu::Settings::menuX = 0.81f;
				}
				if (Menu::Option("Black Menu UI")) {

					Menu::Settings::titleRect = { 0, 0, 0, 255 };
					Menu::Settings::scroller = { 0, 0, 0, 255 };
					Menu::Settings::optionRect = { 0, 0, 0, 200 };
					Menu::Settings::SubTitle = { 0, 0, 0, 255 };
					Menu::Settings::toggler = { 255 };
					Menu::Settings::toggleg = { 255 };
					Menu::Settings::toggleb = { 255 };
				}
				if (Menu::Option("Normal Menu UI")) {

					Menu::Settings::titleRect = { 181, 235, 245, 255 };
					Menu::Settings::scroller = { 0, 184, 217, 255 };//181, 235, 245
					Menu::Settings::optionRect = { 181, 235, 245, 200 };
					Menu::Settings::SubTitle = { 0, 0, 0, 255 };
					Menu::Settings::toggler = { 143 };
					Menu::Settings::toggleg = { 255 };
					Menu::Settings::toggleb = { 223 };
				}
				if (Menu::Option("Red Menu UI")) {
					Menu::Settings::titleRect = { 100, 0, 0, 255 };
					Menu::Settings::scroller = { 120, 20, 0, 255 };
					Menu::Settings::optionRect = { 255, 0, 0, 100 };
					Menu::Settings::toggler = { 255 };
					Menu::Settings::toggleg = { 0 };
					Menu::Settings::toggleb = { 225 };
				}
				if (Menu::Option("Green Menu UI")) {
					Menu::Settings::titleRect = { 0, 180, 0, 255 };
					Menu::Settings::scroller = { 0, 255, 0, 255 };
					Menu::Settings::optionRect = { 25, 180, 0, 100 };
					Menu::Settings::toggler = { 122 };
					Menu::Settings::toggleg = { 245 };
					Menu::Settings::toggleb = { 169 };
				}
				if (Menu::Option("Pink Menu UI")) {
					Menu::Settings::titleRect = { 255, 0, 255, 255 };
					Menu::Settings::scroller = { 255, 0, 255, 255 };
					Menu::Settings::optionRect = { 137, 70, 209, 100 };
					Menu::Settings::toggler = { 240 };
					Menu::Settings::toggleg = { 189 };
					Menu::Settings::toggleb = { 233 };
				}
				if (Menu::Option("Blue Menu UI")) {
					Menu::Settings::titleRect = { 0, 0, 0, 255 };
					Menu::Settings::scroller = { 0, 0, 255, 190 };
					Menu::Settings::optionRect = { 0, 0, 255, 150 };
					Menu::Settings::toggler = { 76 };
					Menu::Settings::toggleg = { 0 };
					Menu::Settings::toggleb = { 255 };
				}
				if (Menu::Option("Uninject Foxy")) {
					//Foxy_Engine::RemoveHooking();
					Foxy_Engine::Unhook();
				}
				if (Menu::Option("Close Console")) {
					fclose(stdout);
					fclose(stdin);
					fclose(stderr);

					FreeConsole();
				}
				/*if (Menu::Float2("Background2 H", Menu::Settings::Header3H, -85.f, 85.f)) {}
				if (Menu::Float2("Background3 Y", Menu::Settings::Header4Y, -85.f, 85.f)) {}
				if (Menu::Float2("Background2 Y", Menu::Settings::Header3Y, -85.f, 85.f)) {}
				if (Menu::Float2("Background3 H", Menu::Settings::Header4H, -85.f, 85.f)) {}

				if (Menu::Float2("Credit X", Menu::Settings::CreditX, -85.f, 85.f)) {}
				if (Menu::Float2("Credit Y", Menu::Settings::CreditY, -85.f, 85.f)) {}
				if (Menu::Float2("Credit W", Menu::Settings::CreditW, -85.f, 85.f)) {}
				if (Menu::Float2("Credit H", Menu::Settings::CreditH, -85.f, 85.f)) {}*/
			}
			break;
			case Thanks:
			{
				Menu::Title("");
				Menu::SubTitle("Credits");
				if (Menu::Option("Menu Devlopper : Foxy")) {}
				if (Menu::Option("Launcher Devlopper : Uno")) {}
			}
			break;
			case freemodetheme:
			{
				Menu::Title("");
				Menu::SubTitle("Freemode Themes");
				Menu::MenuOption("Custom HUD", customfreemodetheme);
				if (Menu::Option("Black HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, 0, 0, 0, 255);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, 0, 0, 0, 255);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, 0, 0, 0, 255);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, 0, 0, 0, 255);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, 0, 0, 200, 255);
					notifyMap("Press esc to apply");
				}
				if (Menu::Option("Blue HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, 0, 0, 255, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, 0, 0, 255, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, 0, 0, 255, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, 0, 0, 255, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, 0, 0, 255, 150);
					notifyMap("Press esc to apply");
				}
				if (Menu::Option("Red HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, 255, 0, 0, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, 255, 0, 0, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, 255, 0, 0, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, 255, 0, 0, 150);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, 255, 0, 0, 150);
					notifyMap("Press esc to apply");
				}
				if (Menu::Option("Pink HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, 137, 70, 209, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, 137, 70, 209, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, 137, 70, 209, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, 137, 70, 209, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, 137, 70, 209, 100);
					notifyMap("Press esc to apply");
				}
				if (Menu::Option("Green HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, 25, 180, 0, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, 25, 180, 0, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, 25, 180, 0, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, 25, 180, 0, 100);
					UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, 25, 180, 0, 100);
					notifyMap("Press esc to apply");
				}
			}
			break;
			case customfreemodetheme:
			{
				Menu::Title("");
				Menu::SubTitle("Custom HUD");
				Menu::Int("Custom Freemode Red", red0, 0, 255);
				Menu::Int("Custom Freemode Green", green0, 0, 255);
				Menu::Int("Custom Freemode Blue", blue0, 0, 255);
				if (Menu::Option("Set Freemode HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, red0, green0, blue0, 100);
					notifyMap("Press esc to apply");
				}
				Menu::Int("Custom Michael Red", red1, 0, 255);
				Menu::Int("Custom Michael Green", green1, 0, 255);
				Menu::Int("Custom Michael Blue", blue1, 0, 255);
				if (Menu::Option("Set Michael HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, red1, green1, blue1, 100);
					notifyMap("Press esc to apply");
				}
				Menu::Int("Custom Franklin Red", red2, 0, 255);
				Menu::Int("Custom Franklin Green", green2, 0, 255);
				Menu::Int("Custom Franklin Blue", blue2, 0, 255);
				if (Menu::Option("Set Franklin HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, red2, green2, blue2, 100);
					notifyMap("Press esc to apply");
				}
				Menu::Int("Custom Trevor Red", red3, 0, 255);
				Menu::Int("Custom Trevor Green", green3, 0, 255);
				Menu::Int("Custom Trevor Blue", blue3, 0, 255);
				if (Menu::Option("Set Trevor HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, red3, green3, blue3, 100);
					notifyMap("Press esc to apply");
				}
				Menu::Int("Custom Waypoint Red", red4, 0, 255);
				Menu::Int("Custom Waypoint Green", green4, 0, 255);
				Menu::Int("Custom Waypoint Blue", blue4, 0, 255);
				if (Menu::Option("Set Waypoint HUD"))
				{
					UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, red4, green4, blue4, 100);
					notifyMap("Press esc to apply");
				}
			}
			break;
			case funnycar1:
			{
				Menu::Title("");
				Menu::SubTitle("Spawn Objects");
				if (Menu::Option("Input Object")) {
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
					latestObj = SpawnObject(CharKeyboard(), pos);
				}
				if (Menu::ListVector("All Objects", propList, propListPos)) {
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
					latestObj = SpawnObject(propList[propListPos], pos);
				}
				if (Menu::ListVector("Stunts And Ramps", Stuntlist, StuntlistPos)) {
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
					latestObj = SpawnObject(Stuntlist[StuntlistPos], pos);
				}
				if (Menu::ListVector("All Weapons", Gunlist, Gunlist1)) {
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
					latestObj = SpawnObject(Gunlist[Gunlist1], pos);
				}

				Menu::Option("[~q~Spawned Objects List~w~]");
				for (int i = 0; i < spwnObjC; i++)
				{
					if (ENTITY::DOES_ENTITY_EXIST(spwndObjects[i])) {
						if (Menu::MenuOption(spwndObjectsNames[i], editObj))
						{
							latestObj = spwndObjects[i];
							ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1);
							selecObj = i;
							Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
							Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
							MoveX = objCoords.x;
							MoveY = objCoords.y;
							MoveZ = objCoords.z;
							roll1 = objRot.y;
							yaw1 = objRot.z;
							pitch1 = objRot.x;
						}
					}
				}
			}
			break;
			case editObj:
			{
				Menu::Title("");
				Menu::SubTitle("Position");


				if (Menu::Toggle("Collision", collisionObj)) {
					if (collisionObj); {
						/*Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 top1world = { entitylocation.x + 3.0f, NULL, entitylocation.y + 3.0f, NULL, entitylocation.z + 2.8f, NULL };
						Vector3 top2world = { entitylocation.x - 3.0f, NULL, entitylocation.y + 3.0f, NULL, entitylocation.z + 2.8f, NULL };
						Vector3 top3world = { entitylocation.x + 3.0f, NULL, entitylocation.y - 3.0f, NULL, entitylocation.z + 2.8f, NULL };
						Vector3 top4world = { entitylocation.x - 3.0f, NULL, entitylocation.y - 3.0f, NULL, entitylocation.z + 2.8f, NULL };
						Vector3 bottom1world = { entitylocation.x + 3.0f, NULL, entitylocation.y + 3.0f, NULL, entitylocation.z - 2.8f, NULL };
						Vector3 bottom2world = { entitylocation.x - 3.0f, NULL, entitylocation.y + 3.0f, NULL, entitylocation.z - 2.8f, NULL };
						Vector3 bottom3world = { entitylocation.x + 3.0f, NULL, entitylocation.y - 3.0f, NULL, entitylocation.z - 2.8f, NULL };
						Vector3 bottom4world = { entitylocation.x - 3.0f, NULL, entitylocation.y - 3.0f, NULL, entitylocation.z - 2.8f, NULL };
						GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 0, 200, 255);
						GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);*/
						/*Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 0, 200, 255);*/
						ENTITY::SET_ENTITY_COLLISION(latestObj, collisionObj, true);

					}
				}
				if (Menu::Float("X Position", MoveX, -5.f, 5.f, .500000f)) {
					ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, MoveX, MoveY, MoveZ, roll1, yaw1, pitch1, 0, 1, 0, 0, 2, 1);
					RequestControlOfEnt(latestObj);
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					ENTITY::SET_ENTITY_COORDS(latestObj, MoveX, objCoords.y, objCoords.z, objRot.x, objRot.y, objRot.z, false);
				}
				if (Menu::Float("Y Position", MoveY, -5.f, 5.f, .500000f)) {
					ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, MoveX, MoveY, MoveZ, roll1, yaw1, pitch1, 0, 1, 0, 0, 2, 1);
					RequestControlOfEnt(latestObj);
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, MoveY, objCoords.z, objRot.x, objRot.y, objRot.z, false);
				}
				if (Menu::Float("Z Position", MoveZ, -5.f, 5.f, .500000f)) {
					ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, MoveX, MoveY, MoveZ, roll1, yaw1, pitch1, 0, 1, 0, 0, 2, 1);
					RequestControlOfEnt(latestObj);
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, objCoords.y, MoveZ, objRot.x, objRot.y, objRot.z, false); 
				}
				if (Menu::Float("Roll Position", roll1, 0.f, 360, 2.f)) {
					ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, MoveX, MoveY, MoveZ, roll1, yaw1, pitch1, 0, 1, 0, 0, 2, 1);
					RequestControlOfEnt(latestObj);                                                                //(Entity entity1, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, BOOL collision, BOOL isPed, int vertexIndex, BOOL fixedRot)
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					ENTITY::SET_ENTITY_ROTATION(latestObj, objRot.x, roll1, objRot.z, 1, true);
				}
				if (Menu::Float("Yaw Position", yaw1, 0.f, 360, 2.f)) {
					ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, MoveX, MoveY, MoveZ, roll1, yaw1, pitch1, 0, 1, 0, 0, 2, 1);
					RequestControlOfEnt(latestObj);
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					ENTITY::SET_ENTITY_ROTATION(latestObj, objRot.x, objRot.y, yaw1, 1, true);
				}
				if (Menu::Float("Pitch Position", pitch1, 0.f, 360, 2.f)) {
					ENTITY::ATTACH_ENTITY_TO_ENTITY(latestObj, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, MoveX, MoveY, MoveZ, roll1, yaw1, pitch1, 0, 1, 0, 0, 2, 1);
					RequestControlOfEnt(latestObj);
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					ENTITY::SET_ENTITY_ROTATION(latestObj, pitch1, objRot.y, objRot.z, 1, true);
				}
				if (Menu::Option("Delete")) {
					RequestControlOfEnt(latestObj);
					ENTITY::DELETE_ENTITY(&latestObj);
					spwndObjectsNames[selecObj] = NULL;
					spwndObjects[selecObj] = NULL;
				}
			}
			break;
			case funnycar:
			{
				Menu::Title("");
				Menu::SubTitle("Funny Car Builder");
				Menu::MenuOption("Funny Car Options", funnycar1);
			}
			break;
#pragma endregion


		}
		int opcount = Menu::Settings::optionCount;
		if (opcount >= 1)
		{
			Menu::End();
			Menu::OptionInfo;
		}
		else
		{
			
		}
		WAIT(0);
		YTD();
		MenuCopyRight();
		YTD3();
		YTD4();
		YTD5();
		YTD6();
		YTD7();
		YTD8();
		YTD9();
		YTD10();
		YTD11();
		YTD12();
		YTD13();
		YTD14();
		YTD15();
		drawvehicle;
	}
}


void ScriptMain() {
	srand(GetTickCount());

	dumbdumb();
}



