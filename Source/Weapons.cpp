#include "stdafx.h"
#include "math.h"
#include "Weapons.h"
#include "Other.h"
#include "Offsets.h"

//0-145 
int Weap::LPNPos1 = 0;
static char* ListedPickupsName[] = {
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_custom_script",
		"pickup_health_standard",
		"pickup_armour_standard",
		"pickup_health_snack",
		"pickup_money_variable",
		"pickup_money_case",
		"pickup_money_wallet",
		"pickup_money_purse",
		"pickup_money_dep_bag",
		"pickup_money_med_bag",
		"pickup_money_paper_bag",
		"pickup_money_security_case",
		"PICKUP_GANG_ATTACK_MONEY",
		"pickup_weapon_pistol",
		"pickup_weapon_combatpistol",
		"PICKUP_WEAPON_PISTOL50",
		"pickup_weapon_appistol",
		"pickup_weapon_microsmg",
		"pickup_weapon_smg",
		"PICKUP_WEAPON_ASSAULTSMG",
		"pickup_weapon_assaultrifle",
		"pickup_weapon_carbinerifle",
		"pickup_weapon_advancedrifle",
		"pickup_weapon_mg",
		"pickup_weapon_combatmg",
		"pickup_weapon_pumpshotgun",
		"pickup_weapon_sawnoffshotgun",
		"pickup_weapon_assaultshotgun",
		"pickup_weapon_sniperrifle",
		"pickup_weapon_heavysniper",
		"pickup_weapon_grenadelauncher",
		"pickup_weapon_rpg",
		"pickup_weapon_minigun",
		"pickup_weapon_grenade",
		"pickup_weapon_smokegrenade",
		"pickup_weapon_stickybomb",
		"pickup_weapon_molotov",
		"PICKUP_WEAPON_STUNGUN",
		"pickup_weapon_fireextinguisher",
		"pickup_weapon_petrolcan",
		"pickup_weapon_loudhailer",
		"pickup_weapon_knife",
		"pickup_weapon_nightstick",
		"pickup_weapon_hammer",
		"pickup_weapon_bat",
		"pickup_weapon_crowbar",
		"pickup_weapon_golfclub",
		"pickup_ammo_bullet_mp",
		"pickup_ammo_missile_mp",
		"PICKUP_AMMO_GRENADELAUNCHER_MP",
		"PICKUP_AMMO_PISTOL",
		"PICKUP_AMMO_SMG",
		"PICKUP_AMMO_RIFLE",
		"PICKUP_AMMO_MG",
		"PICKUP_AMMO_SHOTGUN",
		"PICKUP_AMMO_SNIPER",
		"PICKUP_AMMO_GRENADELAUNCHER",
		"PICKUP_AMMO_RPG",
		"PICKUP_AMMO_MINIGUN",
		"PICKUP_AMMO_FLAREGUN",
		"PICKUP_AMMO_FIREWORK",
		"pickup_vehicle_health_standard",
		"PICKUP_VEHICLE_HEALTH_STANDARD_LOW_GLOW",
		"pickup_vehicle_armour_standard",
		"pickup_vehicle_weapon_pistol",
		"pickup_vehicle_weapon_combatpistol",
		"PICKUP_VEHICLE_WEAPON_PISTOL50",
		"pickup_vehicle_weapon_appistol",
		"pickup_vehicle_weapon_microsmg",
		"pickup_vehicle_weapon_smg",
		"pickup_vehicle_weapon_sawnoff",
		"PICKUP_VEHICLE_WEAPON_ASSAULTSMG",
		"pickup_vehicle_weapon_grenade",
		"pickup_vehicle_weapon_smokegrenade",
		"pickup_vehicle_weapon_stickybomb",
		"pickup_vehicle_weapon_molotov",
		"PICKUP_VEHICLE_MONEY_VARIABLE",
		"pickup_portable_crate_unfixed",
		"PICKUP_PORTABLE_CRATE_UNFIXED_LOW_GLOW",
		"pickup_portable_package",
		"PICKUP_PORTABLE_DLC_VEHICLE_PACKAGE",
		"pickup_submarine",
		"pickup_parachute",
		"pickup_handcuff_key",
		"pickup_camera",
		"PICKUP_WEAPON_BOTTLE",
		"PICKUP_WEAPON_SPECIALCARBINE",
		"PICKUP_WEAPON_SNSPISTOL",
		"PICKUP_WEAPON_BULLPUPRIFLE",
		"PICKUP_WEAPON_HEAVYPISTOL",
		"PICKUP_WEAPON_DAGGER",
		"PICKUP_WEAPON_VINTAGEPISTOL",
		"PICKUP_WEAPON_GUSENBERG",
		"PICKUP_WEAPON_FIREWORK",
		"PICKUP_WEAPON_MUSKET",
		"PICKUP_WEAPON_HOMINGLAUNCHER",
		"PICKUP_WEAPON_PROXMINE",
		"PICKUP_WEAPON_HATCHET",
		"PICKUP_WEAPON_RAILGUN",
		"PICKUP_WEAPON_FLAREGUN",
		"PICKUP_WEAPON_BULLPUPSHOTGUN",
		"PICKUP_WEAPON_MACHINEPISTOL",
		"PICKUP_WEAPON_MARKSMANPISTOL",
		"PICKUP_WEAPON_HEAVYSHOTGUN",
		"PICKUP_WEAPON_MARKSMANRIFLE",
		"PICKUP_WEAPON_COMPACTRIFLE",
		"PICKUP_WEAPON_DBSHOTGUN",
		"PICKUP_WEAPON_MACHETE",
		"PICKUP_WEAPON_FLASHLIGHT",
		"PICKUP_WEAPON_KNUCKLE",
		"PICKUP_WEAPON_COMBATPDW",
		"PICKUP_WEAPON_SWITCHBLADE",
		"PICKUP_WEAPON_REVOLVER",
		"PICKUP_WEAPON_AUTOSHOTGUN",
		"PICKUP_WEAPON_MINISMG",
		"PICKUP_WEAPON_COMPACTLAUNCHER",
		"PICKUP_WEAPON_PIPEBOMB",
		"PICKUP_WEAPON_POOLCUE",
		"PICKUP_WEAPON_BATTLEAXE",
		"PICKUP_WEAPON_WRENCH",
		"PICKUP_WEAPON_ASSAULTRIFLE_MK2",
		"PICKUP_WEAPON_CARBINERIFLE_MK2",
		"PICKUP_WEAPON_COMBATMG_MK2",
		"PICKUP_WEAPON_HEAVYSNIPER_MK2",
		"PICKUP_WEAPON_PISTOL_MK2",
		"PICKUP_WEAPON_SMG_MK2",
		"PICKUP_WEAPON_SNSPISTOL_MK2",
		"PICKUP_WEAPON_REVOLVER_MK2",
		"PICKUP_WEAPON_BULLPUPRIFLE_MK2",
		"PICKUP_WEAPON_SPECIALCARBINE_MK2",
		"PICKUP_WEAPON_PUMPSHOTGUN_MK2",
		"PICKUP_WEAPON_MARKSMANRIFLE_MK2",
		"PICKUP_WEAPON_DOUBLEACTION",
		"PICKUP_WEAPON_STONE_HATCHET",
		"PICKUP_WEAPON_NAVYREVOLVER",
		"PICKUP_PORTABLE_PACKAGE_LARGE_RADIUS",

};

static char* ListedPickupsName2[] = {
	    "bkr_prop_coke_boxeddoll",
		"vw_prop_vw_lux_card_01a",
		"vw_prop_vw_colle_sasquatch",
		"vw_prop_vw_colle_beast",
		"vw_prop_vw_colle_rsrgeneric",
		"vw_prop_vw_colle_rsrcomm",
		"vw_prop_vw_colle_pogo",
		"vw_prop_vw_colle_prbubble",
		"vw_prop_vw_colle_imporage",
		"vw_prop_vw_colle_alien",
		"tr_prop_tr_chest_01a",
		"pickup_health_standard",
		"pickup_armour_standard",
		"pickup_health_snack",
		"pickup_money_variable",
		"pickup_money_case",
		"pickup_money_wallet",
		"pickup_money_purse",
		"pickup_money_dep_bag",
		"pickup_money_med_bag",
		"pickup_money_paper_bag",
		"pickup_money_security_case",
		"PICKUP_GANG_ATTACK_MONEY",
		"pickup_weapon_pistol",
		"pickup_weapon_combatpistol",
		"PICKUP_WEAPON_PISTOL50",
		"pickup_weapon_appistol",
		"pickup_weapon_microsmg",
		"pickup_weapon_smg",
		"PICKUP_WEAPON_ASSAULTSMG",
		"pickup_weapon_assaultrifle",
		"pickup_weapon_carbinerifle",
		"pickup_weapon_advancedrifle",
		"pickup_weapon_mg",
		"pickup_weapon_combatmg",
		"pickup_weapon_pumpshotgun",
		"pickup_weapon_sawnoffshotgun",
		"pickup_weapon_assaultshotgun",
		"pickup_weapon_sniperrifle",
		"pickup_weapon_heavysniper",
		"pickup_weapon_grenadelauncher",
		"pickup_weapon_rpg",
		"pickup_weapon_minigun",
		"pickup_weapon_grenade",
		"pickup_weapon_smokegrenade",
		"pickup_weapon_stickybomb",
		"pickup_weapon_molotov",
		"PICKUP_WEAPON_STUNGUN",
		"pickup_weapon_fireextinguisher",
		"pickup_weapon_petrolcan",
		"pickup_weapon_loudhailer",
		"pickup_weapon_knife",
		"pickup_weapon_nightstick",
		"pickup_weapon_hammer",
		"pickup_weapon_bat",
		"pickup_weapon_crowbar",
		"pickup_weapon_golfclub",
		"pickup_ammo_bullet_mp",
		"pickup_ammo_missile_mp",
		"PICKUP_AMMO_GRENADELAUNCHER_MP",
		"PICKUP_AMMO_PISTOL",
		"PICKUP_AMMO_SMG",
		"PICKUP_AMMO_RIFLE",
		"PICKUP_AMMO_MG",
		"PICKUP_AMMO_SHOTGUN",
		"PICKUP_AMMO_SNIPER",
		"PICKUP_AMMO_GRENADELAUNCHER",
		"PICKUP_AMMO_RPG",
		"PICKUP_AMMO_MINIGUN",
		"PICKUP_AMMO_FLAREGUN",
		"PICKUP_AMMO_FIREWORK",
		"pickup_vehicle_health_standard",
		"PICKUP_VEHICLE_HEALTH_STANDARD_LOW_GLOW",
		"pickup_vehicle_armour_standard",
		"pickup_vehicle_weapon_pistol",
		"pickup_vehicle_weapon_combatpistol",
		"PICKUP_VEHICLE_WEAPON_PISTOL50",
		"pickup_vehicle_weapon_appistol",
		"pickup_vehicle_weapon_microsmg",
		"pickup_vehicle_weapon_smg",
		"pickup_vehicle_weapon_sawnoff",
		"PICKUP_VEHICLE_WEAPON_ASSAULTSMG",
		"pickup_vehicle_weapon_grenade",
		"pickup_vehicle_weapon_smokegrenade",
		"pickup_vehicle_weapon_stickybomb",
		"pickup_vehicle_weapon_molotov",
		"PICKUP_VEHICLE_MONEY_VARIABLE",
		"pickup_portable_crate_unfixed",
		"PICKUP_PORTABLE_CRATE_UNFIXED_LOW_GLOW",
		"pickup_portable_package",
		"PICKUP_PORTABLE_DLC_VEHICLE_PACKAGE",
		"pickup_submarine",
		"pickup_parachute",
		"pickup_handcuff_key",
		"pickup_camera",
		"PICKUP_WEAPON_BOTTLE",
		"PICKUP_WEAPON_SPECIALCARBINE",
		"PICKUP_WEAPON_SNSPISTOL",
		"PICKUP_WEAPON_BULLPUPRIFLE",
		"PICKUP_WEAPON_HEAVYPISTOL",
		"PICKUP_WEAPON_DAGGER",
		"PICKUP_WEAPON_VINTAGEPISTOL",
		"PICKUP_WEAPON_GUSENBERG",
		"PICKUP_WEAPON_FIREWORK",
		"PICKUP_WEAPON_MUSKET",
		"PICKUP_WEAPON_HOMINGLAUNCHER",
		"PICKUP_WEAPON_PROXMINE",
		"PICKUP_WEAPON_HATCHET",
		"PICKUP_WEAPON_RAILGUN",
		"PICKUP_WEAPON_FLAREGUN",
		"PICKUP_WEAPON_BULLPUPSHOTGUN",
		"PICKUP_WEAPON_MACHINEPISTOL",
		"PICKUP_WEAPON_MARKSMANPISTOL",
		"PICKUP_WEAPON_HEAVYSHOTGUN",
		"PICKUP_WEAPON_MARKSMANRIFLE",
		"PICKUP_WEAPON_COMPACTRIFLE",
		"PICKUP_WEAPON_DBSHOTGUN",
		"PICKUP_WEAPON_MACHETE",
		"PICKUP_WEAPON_FLASHLIGHT",
		"PICKUP_WEAPON_KNUCKLE",
		"PICKUP_WEAPON_COMBATPDW",
		"PICKUP_WEAPON_SWITCHBLADE",
		"PICKUP_WEAPON_REVOLVER",
		"PICKUP_WEAPON_AUTOSHOTGUN",
		"PICKUP_WEAPON_MINISMG",
		"PICKUP_WEAPON_COMPACTLAUNCHER",
		"PICKUP_WEAPON_PIPEBOMB",
		"PICKUP_WEAPON_POOLCUE",
		"PICKUP_WEAPON_BATTLEAXE",
		"PICKUP_WEAPON_WRENCH",
		"PICKUP_WEAPON_ASSAULTRIFLE_MK2",
		"PICKUP_WEAPON_CARBINERIFLE_MK2",
		"PICKUP_WEAPON_COMBATMG_MK2",
		"PICKUP_WEAPON_HEAVYSNIPER_MK2",
		"PICKUP_WEAPON_PISTOL_MK2",
		"PICKUP_WEAPON_SMG_MK2",
		"PICKUP_WEAPON_SNSPISTOL_MK2",
		"PICKUP_WEAPON_REVOLVER_MK2",
		"PICKUP_WEAPON_BULLPUPRIFLE_MK2",
		"PICKUP_WEAPON_SPECIALCARBINE_MK2",
		"PICKUP_WEAPON_PUMPSHOTGUN_MK2",
		"PICKUP_WEAPON_MARKSMANRIFLE_MK2",
		"PICKUP_WEAPON_DOUBLEACTION",
		"PICKUP_WEAPON_STONE_HATCHET",
		"PICKUP_WEAPON_NAVYREVOLVER",
		"PICKUP_PORTABLE_PACKAGE_LARGE_RADIUS",

};

#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())

double wDegreeToRadian(double n) {
	return n * 0.017453292519943295;
}

void notifyleftanommo(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}
void sppp()
{
	Hash cur;
	notifyleftanommo("Click Again For ~b~Ammo");
	if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &cur, 1))
	{
		if (WEAPON::IS_WEAPON_VALID(cur))
		{
			int maxAmmo;
			if (WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), cur, &maxAmmo))
			{
				WEAPON::SET_PED_AMMO(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);

				maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, 1);
				if (maxAmmo > 0)
					WEAPON::SET_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);
			}
		}
	}
}

Vector3 wRotationToDirection(Vector3 rot) {
	double num = wDegreeToRadian(rot.z);
	double num2 = wDegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}

Vector3 waddVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}

Vector3 wmultiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

Vector3 wrotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}

bool Weap::Bottrigger = false;

bool Weap::laser = false;

bool Weap::pedgun = false;

bool Weap::bulletforce = false;
bool Weap::bulletforcePed = false;
bool Weap::bulletforceHeli = false;
bool Weap::bulletforceStreetVehicle = false;
bool Weap::bulletforceReload = false;
bool Weap::bulletforceRecoil = false;


float testt = 1.0f;
void re()
{
	// common variables
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
	//mp_m_freemode_01
	Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);
	if (ENTITY::IS_ENTITY_DEAD(playerPed) || PLAYER::IS_PLAYER_BEING_ARRESTED(player, true))
		if (model != GAMEPLAY::GET_HASH_KEY("player_zero") && model != GAMEPLAY::GET_HASH_KEY("player_one") && model != GAMEPLAY::GET_HASH_KEY("mp_m_freemode_01") && model != GAMEPLAY::GET_HASH_KEY("player_two"))
		{
			notifyBottom("turning to ~g~normal~w~..");
			model = GAMEPLAY::GET_HASH_KEY("mp_m_freemode_01");
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model))
				WAIT(0);
			PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

			// wait until player is ressurected
			while (ENTITY::IS_ENTITY_DEAD(PLAYER::PLAYER_PED_ID()), PLAYER::IS_PLAYER_BEING_ARRESTED(player, true))
			{
				WAIT(0);
			}
		}
}

void Weap::UpdateLoop() {

	
	InfiniteAmmo ? infiniteammo(true) : NULL;

	ExplosiveAmmo ? explosiveammo(true) : NULL;

	RpG ? rpg(true) : NULL;

	RPG2 ? rpg2(true) : NULL;

	MoneyGun ? moneygun(true) : NULL;

	FireAmmo ? fireammo(true) : NULL;

	TPGun ? tpgun(true) : NULL;

	RapidFire ? rapidfire(true) : NULL;

	AirstrikeGun ? airstrikeGun(true) : NULL;

	Onehit ? onehit(true) : NULL;

	DeleteGun ? deletegun(true) : NULL;

	Aimbot ? aimbot(true) : NULL;

	Aimbot2 ? aimbot2(true) : NULL;

	NoRecoil ? noRecoil(true) : NULL;

	WaterShoot ? ShootWater(true) : NULL;

	FireShoot ? ShootFire(true) : NULL;

	GravityGunf ? gravityGun(true) : NULL;

	Gravity ? GravityGun(true) : NULL;

	PedGun ? pedGun(true) : NULL;

	ROPEGUN ? ropegun(true) : NULL;

	TeleyGun ? teleygun(true) : NULL;

	RainbowG ? Rainbow(true) : NULL;

	ShootCars ? shootCars(true) : NULL;

	ShootCars1 ? shootCars1(true) : NULL;

	ShootCars2 ? shootCars2(true) : NULL;

	ShootCars3 ? shootCars3(true) : NULL;

	ShootCars4 ? shootCars4(true) : NULL;

	ShootCars5 ? shootCars5(true) : NULL;

	GuidedMissileInsight ? guidedmissileinsight(true) : NULL;

	Flametrow ? flametrow(true) : NULL;


	Drivegun ? drivegun(true) : NULL;

	RpGun ? rpgun(true) : NULL;

	if (gravegun)
	{
		aGravityGun();
	}
	else
	{

	}

	if (somethinggun)
	{
		somethinggunn(ListedPickupsName[Weap::LPNPos1], ListedPickupsName2[Weap::LPNPos1]);
	}
	else
	{

	}

	if (laser)
	{
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, testt));

		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
		{
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 0, 0, 200, 255);
		}
			
	}

	if (pedgun) {

		Entity EntityTarget;

		{
			CONTROLS::DISABLE_CONTROL_ACTION(0, INPUT_ATTACK, TRUE);
			CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_ATTACK2, TRUE);
			CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK, TRUE);
			CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK2, TRUE);
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
			{
				if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
				{
					RequestControlOfEnt(EntityTarget);
					PLAYER::CHANGE_PLAYER_PED(PLAYER::PLAYER_ID(), EntityTarget, true, true);
					re();
				}
			}
		}
	
		//WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), WEAPON_COMBATPISTOL, 9999, false, true); i mean like i dont need this here 
	}

	if (bulletforce)
	{
		if (bulletforce == true)
		{
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, 0xB0 }, 100.f);
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, 0xDC }, 100.f);
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, 0xE0 }, 100.f);
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, 0xE4 }, 100.f);
		}
	}
	if (bulletforcePed)
	{
		if (bulletforcePed == true)
		{
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 900.f);
		}
	}
	if (bulletforceStreetVehicle)
	{
		if (bulletforceStreetVehicle == true)
		{
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_MUZZLE_VELOCITY }, 1000.f);
		}
	}
	if (bulletforceHeli)
	{
		if (bulletforceHeli == true)
		{
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_SPREAD }, 0.f);
		}
	}

	if (bulletforceReload)
	{
		if (bulletforceReload == true)
		{
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_RELOAD_SPEED }, 100.f);
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_RELOAD_MULTIPLY }, 100.f);
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_SHOT_TIME }, 0.f);
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 3.0);
		}
	}

	if (bulletforceRecoil)
	{
		if (bulletforceRecoil == true)
		{
			Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_RECOIL }, 0.f);
		}
	}



}

#define PROP_MONEY_BAG_02 -1666779307
#define PICKUP_MONEY_CASE 0x1E9A99F8

int Weap::Amount = 2000;

char* Weap::ModelThing2 = "";
char* Weap::ModelThing = "PICKUP_MONEY_VARIABLE";


bool Weap::somethinggun = false;
void Weap::somethinggunn(char* model_one, char* model_two)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		Vector3 coords;
		int hash_of_model = GAMEPLAY::GET_HASH_KEY(model_two);
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPedId, &coords))
		{
		//	OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY(model_one), coords.x, coords.y, coords.z, 0, Weap::Amount, hash_of_model, false, true);
			if (LPNPos1 == 0 || LPNPos1 == 1 || LPNPos1 == 2 || LPNPos1 == 3 || LPNPos1 == 4 || LPNPos1 == 5 || LPNPos1 == 6 || LPNPos1 == 7 || LPNPos1 == 8 || LPNPos1 == 9 || LPNPos1 == 10 || LPNPos1 == 11) {
				STREAMING::REQUEST_MODEL(hash_of_model);
				if (!STREAMING::HAS_MODEL_LOADED(hash_of_model)) {

				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, coords.x, coords.y, coords.z, 0, 1, hash_of_model, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_of_model);
				}
			}
			else if (LPNPos1 == 57 || LPNPos1 == 58 || LPNPos1 == 59 || LPNPos1 == 60 || LPNPos1 == 61 || LPNPos1 == 62 || LPNPos1 == 63 || LPNPos1 == 64 || LPNPos1 == 65 || LPNPos1 == 66 || LPNPos1 == 67 || LPNPos1 == 68 || LPNPos1 == 69 || LPNPos1 == 70) {
				int modelhash = GAMEPLAY::GET_HASH_KEY("prop_ld_ammo_pack_01");
				Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
				DWORD pickup = $(model_one);
				STREAMING::REQUEST_MODEL(modelhash);
				if (!STREAMING::HAS_MODEL_LOADED(modelhash)) {
					WAIT(0);
				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(pickup, coords.x, coords.y, coords.z, 0, 2500, modelhash, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(pickup);
				}
			}
			else if (LPNPos1 == 14 || LPNPos1 == 15 || LPNPos1 == 16 || LPNPos1 == 17 || LPNPos1 == 18 || LPNPos1 == 19 || LPNPos1 == 20 || LPNPos1 == 21 || LPNPos1 == 22 || LPNPos1 == 86) {
				Hash Variable = GAMEPLAY::GET_HASH_KEY(model_one);
				Hash hash_of_money_model = GAMEPLAY::GET_HASH_KEY("prop_cash_case_02");
				STREAMING::REQUEST_MODEL(hash_of_money_model);
				if (!STREAMING::HAS_MODEL_LOADED(hash_of_money_model)) {

				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(Variable, coords.x, coords.y, coords.z, 0, Weap::Amount, hash_of_money_model, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_of_money_model);
				}
			}
			else if (LPNPos1 != 14 || LPNPos1 != 15 || LPNPos1 != 16 || LPNPos1 != 17 || LPNPos1 != 18 || LPNPos1 != 19 || LPNPos1 != 20 || LPNPos1 != 21 || LPNPos1 != 22 || LPNPos1 != 86 ||
				LPNPos1 != 57 || LPNPos1 != 58 || LPNPos1 != 59 || LPNPos1 != 60 || LPNPos1 != 61 || LPNPos1 != 62 || LPNPos1 != 63 || LPNPos1 != 64 || LPNPos1 != 65 || LPNPos1 != 66 || LPNPos1 != 67 || LPNPos1 != 68 || LPNPos1 != 69 || LPNPos1 != 70 ||
				LPNPos1 != 0 || LPNPos1 != 1 || LPNPos1 != 2 || LPNPos1 != 3 || LPNPos1 != 4 || LPNPos1 != 5 || LPNPos1 != 6 || LPNPos1 != 7 || LPNPos1 != 8 || LPNPos1 != 9 || LPNPos1 != 10 || LPNPos1 != 11 || LPNPos1 != 57 || LPNPos1 != 58 || LPNPos1 != 59
				|| LPNPos1 != 60 || LPNPos1 != 61 || LPNPos1 != 62 || LPNPos1 != 63 || LPNPos1 != 64 || LPNPos1 != 65 || LPNPos1 != 66 || LPNPos1 != 67 || LPNPos1 != 68 || LPNPos1 != 69 || LPNPos1 != 70 || LPNPos1 != 14 || LPNPos1 != 15 || LPNPos1 != 16 || LPNPos1 != 17 || LPNPos1 != 18 || LPNPos1 != 19 || LPNPos1 != 20 || LPNPos1 != 21 || LPNPos1 != 22 || LPNPos1 != 86 ||
				LPNPos1 != 0 || LPNPos1 != 1 || LPNPos1 != 2 || LPNPos1 != 3 || LPNPos1 != 4 || LPNPos1 != 5 || LPNPos1 != 6 || LPNPos1 != 7 || LPNPos1 != 8 || LPNPos1 != 9 || LPNPos1 != 10 || LPNPos1 != 11) {
				Hash pickup = GAMEPLAY::GET_HASH_KEY(model_one);
				//Hash model_Stash = GAMEPLAY::GET_HASH_KEY("p_secret_weapon_02");
				STREAMING::REQUEST_MODEL(pickup);
				if (!STREAMING::HAS_MODEL_LOADED(pickup)) {

				}
				else {

					OBJECT::CREATE_AMBIENT_PICKUP(pickup, coords.x, coords.y, coords.z, 0, 1000000, 1, false, true);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(pickup);
				}
			}
		}
	}
}

bool Weap::InfiniteAmmo = false;
void Weap::infiniteammo(bool toggle)
{
	Hash cur;
	if (WEAPON::GET_CURRENT_PED_WEAPON(playerPedId, &cur, 1))
	{
		if (WEAPON::IS_WEAPON_VALID(cur))
		{
			int maxAmmo;
			if (WEAPON::GET_MAX_AMMO(playerPedId, cur, &maxAmmo))
			{
				WEAPON::SET_PED_AMMO(playerPedId, cur, maxAmmo);

				maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPedId, cur, 1);
				if (maxAmmo > 0)
					WEAPON::SET_AMMO_IN_CLIP(playerPedId, cur, maxAmmo);
			}
		}
	}
}

bool Weap::RpG = false;
void Weap::rpg(bool toggle)
{
	float startDistance = distanceBetween(CAM::GET_GAMEPLAY_CAM_COORD(), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distanceBetween(CAM::GET_GAMEPLAY_CAM_COORD(), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 0.25;
	endDistance += 1000.0;
	if (PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_RPG"); //WEAPON_FIREWORK
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
	}
}

bool Weap::RPG2 = false;
void Weap::rpg2(bool toggle)
{
	float startDistance = distanceBetween(CAM::GET_GAMEPLAY_CAM_COORD(), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distanceBetween(CAM::GET_GAMEPLAY_CAM_COORD(), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 0.25;
	endDistance += 1000.0;
	if (PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREWORK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
	}
}

void set_frame_flag(Frameflags flag) {
	*Memory::get_ptr<DWORD>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }) |= flag;
}

bool Weap::ExplosiveAmmo = false;
void Weap::explosiveammo(bool toggle)
{
	float startDistance = distanceBetween(CAM::GET_GAMEPLAY_CAM_COORD(), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distanceBetween(CAM::GET_GAMEPLAY_CAM_COORD(), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 0.25;
	endDistance += 1000.0;
	if (PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&wrotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
	}
}
#define pickup_money_security_case 233405277

bool Weap::MoneyGun = false;
void Weap::moneygun(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPedId, &coords))
		{
			Hash Variable = GAMEPLAY::GET_HASH_KEY("pickup_money_variable");
			Hash hash_of_money_model = GAMEPLAY::GET_HASH_KEY("prop_cash_case_02");
			STREAMING::REQUEST_MODEL(hash_of_money_model);
			if (!STREAMING::HAS_MODEL_LOADED(hash_of_money_model)) {

			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(Variable, coords.x, coords.y, coords.z, 0, Weap::Amount, hash_of_money_model, FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_of_money_model);
			}
		}
	}
}

#define vw_prop_vw_colle_pogo 2513890

bool Weap::RpGun = false;
void Weap::rpgun(bool toggle)
{
	/*Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	if (ENTITY::DOES_ENTITY_EXIST(playerPed)) {
		if (PED::IS_PED_SHOOTING(playerPed)) {
			float Tmp[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)Tmp);
			if (Tmp[0] != 0 || Tmp[2] != 0 || Tmp[4] != 0)
			{
				STREAMING::REQUEST_MODEL((vw_prop_vw_colle_pogo));
				while (!STREAMING::HAS_MODEL_LOADED((vw_prop_vw_colle_pogo)))WAIT(0);
				{
					OBJECT::CREATE_AMBIENT_PICKUP2((vw_prop_vw_colle_pogo), Tmp[0], Tmp[2], Tmp[4], 0, 2, (vw_prop_vw_colle_pogo), FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((vw_prop_vw_colle_pogo));
				}
			}
		}
	}*/

}

bool Weap::FireAmmo = false;
void Weap::fireammo(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPedId, &coords))
		{
			GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 3, 1000, true, false, .1);
			FIRE::ADD_OWNED_EXPLOSION(playerPedId, coords.x, coords.y, coords.z, 3, 1000, true, false, .1);
		}
	}
}

bool Weap::TPGun = false;
void Weap::tpgun(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPedId, &coords))
		{
			ENTITY::SET_ENTITY_COORDS(playerPedId, coords.x, coords.y, coords.z, 0, 0, 0, 1);
		}
	}
}

bool Weap::RapidFire = false;
void Weap::rapidfire(bool toggle)
{
	Player playerPed = playerPedId;
	if (!PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 1)) {
		PLAYER::DISABLE_PLAYER_FIRING(playerPedId, 1);
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 1.0f)));
		Vector3 endCoords = waddVector(startCoords, wmultiplyVector(gameplayCamDirection, 500.0f));
		Hash weaponhash;
		WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
		if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
			PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), endCoords.x, endCoords.y, endCoords.z, true);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
		}
	}
}

bool Weap::AirstrikeGun = false;
void Weap::airstrikeGun(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_SHOOTING(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
			WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
				WAIT(0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y + 20.f, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x + 20.f, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			

		}
	}
}

bool Weap::Onehit = false;
void Weap::onehit(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 CamCoords = CAM::_GET_GAMEPLAY_CAM_COORDS();
	Vector3 CamRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 CamDirection = wRotationToDirection(CamRotation);
	Vector3 StartCoords = waddVector(CamCoords, (wmultiplyVector(CamDirection, 1.0f)));
	Vector3 EndCoords = waddVector(StartCoords, wmultiplyVector(CamDirection, 500.0f));
	if (PED::IS_PED_SHOOTING(playerPed))
	{
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 250, true, GAMEPLAY::GET_HASH_KEY("WEAPON_REMOTESNIPER"), playerPed, true, true, -1.0f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 250, true, GAMEPLAY::GET_HASH_KEY("WEAPON_REMOTESNIPER"), playerPed, true, true, -1.0f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 250, true, GAMEPLAY::GET_HASH_KEY("WEAPON_REMOTESNIPER"), playerPed, true, true, -1.0f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 250, true, GAMEPLAY::GET_HASH_KEY("WEAPON_REMOTESNIPER"), playerPed, true, true, -1.0f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 250, true, GAMEPLAY::GET_HASH_KEY("WEAPON_REMOTESNIPER"), playerPed, true, true, -1.0f);
	}
}

bool Weap::DeleteGun = false;
void Weap::deletegun(bool toggle)
{
	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_ANY_PED_SHOOTING_IN_AREA)
	{
		Vector3 iCoord;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
		{
			GAMEPLAY::_CLEAR_AREA_OF_EVERYTHING(iCoord.x, iCoord.y, iCoord.z, 2, 0, 0, 0, 0);
		}
	}
}

bool Weap::Aimbot = false;
void Weap::aimbot(bool toggle)
{
	int player = PLAYER::PLAYER_ID();
	int playerPed = PLAYER::PLAYER_PED_ID();

	for (int i = 0; i < 32; i++)
	{
		if (i != player)
		{
			if (GetAsyncKeyState(VK_RBUTTON))
			{
				Ped targetPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				Vector3 targetPos = ENTITY::GET_ENTITY_COORDS(targetPed, 1);
				BOOL exists = ENTITY::DOES_ENTITY_EXIST(targetPed);
				BOOL dead = PLAYER::IS_PLAYER_DEAD(targetPed);

				if (exists && !dead)
				{
					float screenX, screenY;
					BOOL onScreen = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(targetPos.x, targetPos.y, targetPos.z, &screenX, &screenY);
					if (ENTITY::IS_ENTITY_VISIBLE(targetPed) && onScreen) //DOES_ENTITY_EXIST
					{
						if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, targetPed, 17))
						{
							Vector3 targetCoords = PED::GET_PED_BONE_COORDS(targetPed, 31086, 0, 0, 0);
							PED::SET_PED_SHOOTS_AT_COORD(playerPed, targetCoords.x, targetCoords.y, targetCoords.z, 1);

						}
					}
				}
			}
		}
	}
}

int Weap::AutoShootListPos = 1;
int Weap::ModeListPos = 1;
int Weap::TargetListPos = 1;
int Weap::MultiBulletsBool = 1;
int Weap::OriginListPos = 1;
int Weap::shootDelayInt = 1;
int Weap::SelectListPos = 1;


bool Weap::Aimbot2 = false;
void Weap::aimbot2(bool toggle)
{
	int PlayerId = PLAYER::PLAYER_ID();
	int PedId = PLAYER::PLAYER_PED_ID();

	if (IsKeyPressed(VK_RBUTTON) || AutoShootListPos == 2)
	{
		if (ModeListPos == 1 && IsKeyPressed(VK_LBUTTON)) PLAYER::DISABLE_PLAYER_FIRING(PlayerId, FALSE);
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		int PED[arrSize];
		PED[0] = numElements;
		int count = PED::GET_PED_NEARBY_PEDS(PedId, PED, -1);
		Ped closest = 0;
		if (PED != NULL)
		{
			for (int i = 0; i < count; i++)
			{
				int offsettedID = i * 2 + 2;
				if (PED[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(PED[offsettedID]))
				{
					for (int j = -1; j <= 2; ++j)
					{

						Any ped = PED[offsettedID];

						Vector3 ped_coords = ENTITY::GET_ENTITY_COORDS(ped, TRUE);
						Vector3 self_head_coords = PED::GET_PED_BONE_COORDS(PedId, 0x796e, 0, 0, 0);
						Vector3 ped_head_coords = PED::GET_PED_BONE_COORDS(ped, 0x796e, 0, 0, 0);
						GRAPHICS::DRAW_LINE(ped_head_coords.x, ped_head_coords.y, ped_head_coords.z, self_head_coords.x, self_head_coords.y, self_head_coords.z, 242, 179, 235, 200);



						Vector3 self_coords = ENTITY::GET_ENTITY_COORDS(PedId, TRUE);
						if (closest == 0) closest = ped;
						else if (GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(self_coords.x, self_coords.y, self_coords.z, ped_coords.x, ped_coords.y, ped_coords.z, TRUE) < GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(self_coords.x, self_coords.y, self_coords.z, ENTITY::GET_ENTITY_COORDS(closest, TRUE).x, ENTITY::GET_ENTITY_COORDS(closest, TRUE).y, ENTITY::GET_ENTITY_COORDS(closest, TRUE).z, TRUE) || SelectListPos == 1) closest = ped;//                                                                                                                            
						Hash weaponhash;
						WEAPON::GET_CURRENT_PED_WEAPON(PedId, &weaponhash, 1);
						if (!WEAPON::IS_WEAPON_VALID(weaponhash)) continue;
						float screenX, screenY;
						BOOL onScreen = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(ENTITY::GET_ENTITY_COORDS(closest, true).x, ENTITY::GET_ENTITY_COORDS(closest, true).y, ENTITY::GET_ENTITY_COORDS(closest, true).z, &screenX, &screenY);
						if (ModeListPos == 0) onScreen = TRUE;



						switch ((unsigned long long)TargetListPos) {
						case 0:
							if (!PED::IS_PED_A_PLAYER(ped)) continue;
							break;
						case 1:
							if (PED::IS_PED_A_PLAYER(ped)) continue;
							break;
						case 2:

							break;
						}
						PLAYER::DISABLE_PLAYER_FIRING(PlayerId, FALSE);
						int bones[] = { 0x0,0x2e28,0xe39f,0xf9bb,0x3779,0x83c,0xfedd,0xe175,0xb3fe,0xca72,0x9000,0xcc4d,0x512d,0x8aae,0x60e6,0x3fcf,0x5c57,0x192a,0xe0fd,0x5c01,0x60f0,0x60f1,0x60f2,0xfcd9,0xb1c5,0xeeeb,0x49d9,0x67f2, 0xff9, 0xffa, 0x67f3, 0x1049, 0x104a, 0x67f4, 0x1059, 0x105a, 0x67f5, 0x1029, 0x102a, 0x67f6, 0x1039, 0x103a, 0xeb95, 0x8cbd, 0xee4f, 0x1470, 0x58b7, 0x29d2, 0x9d4d, 0x6e5c, 0xdead, 0xe5f2, 0xfa10, 0xfa11, 0xe5f3, 0xfa60, 0xfa61, 0xe5f4, 0xfa70,0xfa71, 0xe5f5,0xfa40, 0xfa41,0xe5f6,0xfa50, 0xfa51,0x6f06, 0x188e,0xab22,0x90ff,0xbb0, 0x9995,0x796e, 0x322c,0xfe2c, 0xe3db,0xb2b6, 0x62ac,0x542e, 0x74ac,0xaa10, 0x6b52,0x4b88, 0x54c,0x2ba6, 0x9149,0x4ed2, 0xf18f,0x4f37, 0x4537,0xb4a0, 0x4324,0x508f,0xb93b,0xc33b,0xb987,0x8b93,0xdd1c };

						if (((closest != NULL && !ENTITY::IS_ENTITY_DEAD(closest) && onScreen) || SelectListPos == 1))
						{

							if (!ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(PedId, closest, 1000)) continue;
							notifyBottom("Killing Everything", 255, 0, 0, 255, 0.5f, 0.5f, 0.3f, 0.3f, true);

							PLAYER::DISABLE_PLAYER_FIRING(PlayerId, TRUE);


							Vector3 target_coords = PED::GET_PED_BONE_COORDS(closest, 0x796e, 0, 0, 0);



							if ((IsKeyPressed(VK_LBUTTON) || AutoShootListPos > 0) && GetTickCount() % (shootDelayInt > 0 ? shootDelayInt : 1) == 0)
							{
								if (MultiBulletsBool = 1)
								{
									for (int bone : bones)
									{
										if (OriginListPos == 1) self_head_coords = PED::GET_PED_BONE_COORDS(closest, bone, 0, 0, 0);
										PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), target_coords.x, target_coords.y, target_coords.z, true);
										GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(target_coords.x, target_coords.y, target_coords.z, self_head_coords.x, self_head_coords.y, self_head_coords.z, 50, 1, weaponhash, PedId, 1, 1, 0xbf800000);
									}
								}
								else GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(self_head_coords.x, self_head_coords.y, self_head_coords.z, target_coords.x, target_coords.y, target_coords.z, 50, 1, weaponhash, PedId, 1, 1, 0xbf800000);


							}

							GRAPHICS::DRAW_LINE(target_coords.x, target_coords.y, target_coords.z, self_head_coords.x, self_head_coords.y, self_head_coords.z, 242, 179, 235, 200);

							GRAPHICS::DRAW_MARKER(31, target_coords.x, target_coords.y, target_coords.z + 2, 0, 0, 0, 0, 180, 0, 0.5f, 0.5f, 0.5f, 242, 179, 235, 50, 0, 1, 1, 0, 0, 0, 0);

						}
					}
				}
			}
		}
	}
}

bool Weap::NoRecoil = false;
void Weap::noRecoil(bool toggle)
{    ///0x8 + 0x10D8 + 0x20 + 0x2F4
	if (Weap::NoRecoil)
	{
		Memory::set_value<float>({ 0x8, 0x10C8, 0x20, 0x2F4 }, 0);
		Memory::set_value<float>({ 0x8, 0x10C8, 0x20, 0x2F8 }, 0);
	}
	else
	{
		Memory::set_value<float>({ 0x8, 0x10C8, 0x20, 0x2F4 }, 1);
		Memory::set_value<float>({ 0x8, 0x10C8, 0x20, 0x2F8 }, 1);
	}
}

//#define OFFSET_PLAYER_INFO						0x10C8			//playerInfo struct
//0x8 = Max
//#define OFFSET_WEAPON_CURRENT			0x20			//from weapon manager
//#define OFFSET_WEAPON_RECOIL			0x2A4			//float set to 0
//#define OFFSET_ENTITY_ATTACKER			0x2A8			//base to a list of the last 3 entities that attacked the current entity

bool Weap::WaterShoot = false;
void Weap::ShootWater(bool toggle)
{
	Ped PedID = PLAYER::PLAYER_PED_ID();
	Vector3 pos;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PedID, &pos);
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID());
	FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 13, 5.f, true, false, 0.f);
}

bool Weap::FireShoot = false;
void Weap::ShootFire(bool toggle)
{
	Ped PedID = PLAYER::PLAYER_PED_ID();
	Vector3 pos;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PedID, &pos);
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID());
	FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 12, 5.f, true, false, 0.f);
}

bool Weap::grav_target_locked1 = false;
bool gunon = false;
bool Weap::GravityGunf = false;
Entity EntityTarget;
void Weap::gravityGun(bool toggle)
{

	/*DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = wRotationToDirection(rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 6;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));

	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{

		if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
		{
			EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
		}
		RequestControlOfEnt(EntityTarget);
		ENTITY::SET_ENTITY_HAS_GRAVITY(EntityTarget, false);
		if (IsKeyPressed(VK_LSHIFT))
			ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10.0f, dir.y * 10.0f, dir.z * -5.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
		else
			ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * -10.0f, dir.y * -10.0f, dir.z * +5.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);

		gunon = false;

	}
	if (gunon)
	{
		notifyBottom("Right click and You'll use the Force, Left Shit + Right click To Pull");
	}*/
		







	
	
	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = wRotationToDirection(rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 6;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();

	if (grav_target_locked1) //  FIXED, it is, it's using detected natives ok can you find other native for it? No, because only this one is working for it, you need to find signature for it.
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
		{
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

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
					0.0f, 0, 0, 1, 1, 0, 1);
				grav_target_locked1 = false;
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
			}
		}
	}
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		grav_target_locked1 = true;
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}
}


bool Weap::PedGun = false;
void Weap::pedGun(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		Hash panther = GAMEPLAY::GET_HASH_KEY("A_C_Panther");
		STREAMING::REQUEST_MODEL(panther);
		//notifyBottom("Model : ", bunny);
		while (!STREAMING::HAS_MODEL_LOADED(panther)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 0.0);

		if ( STREAMING::IS_MODEL_A_PED(panther))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(panther, &dim1, &dim2);

			offset = dim2.y * 1.6;
			//notifyBottom("Offset : ", offset);
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Ped bunned = PED::CREATE_PED(1, panther, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, true, true);

		ENTITY::SET_ENTITY_INVINCIBLE(bunned, true);

		ENTITY::APPLY_FORCE_TO_ENTITY(bunned, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(bunned);
	}
}


bool Weap::RainbowG = false;
void Weap::Rainbow(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static LPCSTR weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
		"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "", ""
	};
	for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
	{
		if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), rand() % 8);
		}
	}
}

//Yes you could do it with a char* hash, and don't ask me why I decided to do this. But fuck it

bool Weap::ShootCars = false;
void Weap::shootCars(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("LAZER");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Weap::ShootCars1 = false;
void Weap::shootCars1(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("ANNIHILATOR");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Weap::ShootCars2 = false;
void Weap::shootCars2(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("Oppressor");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Weap::ShootCars3 = false;
void Weap::shootCars3(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("VADER");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Weap::ShootCars4 = false;
void Weap::shootCars4(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("REBEL");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Weap::ShootCars5 = false;
void Weap::shootCars5(bool toggle)
{
	if (PED::IS_PED_SHOOTING(playerPedId))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("Adder");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPedId);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPedId, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = wRotationToDirection(gameplayCamRot);
		Vector3 startCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = waddVector(gameplayCam, (wmultiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Weap::GuidedMissileInsight = false;
void Weap::guidedmissileinsight(bool toggle)
{ 
	//w_smug_airmissile_01b , w_smug_airmissile_02, w_arena_airmissile_01a, xs_prop_arena_airmissile_01a, xm_prop_x17_silo_rocket_01,  missile model 
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static std::int32_t rocket, new_camera;
	static std::uint8_t y;
	int firing_mod_value = 0;
	if (PED::IS_PED_SHOOTING(playerPedId) && firing_mod_value == 0)
	{  
		 firing_mod_value = 1; //check the f
	}
	if (firing_mod_value == 1) {
		if (!ENTITY::DOES_ENTITY_EXIST(rocket)) { // if rocket doesn't exist 
			Vector3 position_to_start_on = ENTITY::GET_ENTITY_COORDS(playerPed, 1); // get my position
			rocket = OBJECT::CREATE_OBJECT($("xm_prop_x17_silo_rocket_01"), position_to_start_on.x + .5f, position_to_start_on.y + .5f, position_to_start_on.z + .5f, 1, 1, 0); // create the object 
			CAM::DESTROY_ALL_CAMS(true); // kill all cams 
			new_camera = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1); // create a camera 
			CAM::ATTACH_CAM_TO_ENTITY(new_camera, rocket, 0.f, 0.f, 0.f, 1); // attach the camera to the rocket 
			CAM::RENDER_SCRIPT_CAMS(true, true, 900, false, false); // render the camera
			CAM::SET_CAM_ACTIVE(new_camera, true); // turn the camera on 
			ENTITY::SET_ENTITY_VISIBLE(rocket, true, true); // set the rocket visible 
		}
		else {
			float groundZ;
			CAM::SET_CAM_ROT(new_camera, CAM::GET_GAMEPLAY_CAM_ROT(0).x, CAM::GET_GAMEPLAY_CAM_ROT(0).y, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 0); // follow my camera 
			ENTITY::SET_ENTITY_ROTATION(rocket, CAM::GET_GAMEPLAY_CAM_ROT(0).x, CAM::GET_GAMEPLAY_CAM_ROT(0).y, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 0, 1); // set the proper angle for the rocket whit the camera 
			auto coords_of_rocket = add(&ENTITY::GET_ENTITY_COORDS(rocket, 1), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), .8f)); // set the proper speed/angle of the camera 
			ENTITY::SET_ENTITY_COORDS(rocket, coords_of_rocket.x, coords_of_rocket.y, coords_of_rocket.z, 0, 0, 0, 0); // new pos for the rocket 
			WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1); // set the our model to be unarmed 
			UI::HIDE_HUD_AND_RADAR_THIS_FRAME(); // disable the radar 
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1); // block the firing of any weapon while in the rocket mod
			ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 1); // freeze our player model in place 
			UI::_0x0AFC4AF510774B47();// Block weapon wheel if missile still alive 
			GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(ENTITY::GET_ENTITY_COORDS(rocket, 1).x, ENTITY::GET_ENTITY_COORDS(rocket, 1).y, ENTITY::GET_ENTITY_COORDS(rocket, 1).z, &groundZ, 0); // get the ground coords 
			if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(rocket) || (std::abs(ENTITY::GET_ENTITY_COORDS(rocket, 1).z - groundZ) < .5f)) { // check if our bullet collided whit anything or is close to the ground 
				auto impact_coords = ENTITY::GET_ENTITY_COORDS(rocket, 1); ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 0); // keep us frozen for the time being 
				auto war = $("VEHICLE_WEAPON_TAMPA_MORTAR");
				if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				{
					WEAPON::REQUEST_WEAPON_ASSET(war, 31, false); // triger the loading of our weapon assets 
					while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
						WAIT(0);
				}
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x + .5f, impact_coords.y, impact_coords.z, impact_coords.x + .5f, impact_coords.y, impact_coords.z, 250, 1, war, playerPed, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x, impact_coords.y + .5f, impact_coords.z, impact_coords.x, impact_coords.y + .5f, impact_coords.z, 250, 1, war, playerPed, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x, impact_coords.y, impact_coords.z + .5f, impact_coords.x, impact_coords.y, impact_coords.z + .5f, 250, 1, war, playerPed, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x + .5f, impact_coords.y + .5f, impact_coords.z, impact_coords.x + .5f, impact_coords.y + .5f, impact_coords.z, 250, 1, war, playerPed, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x, impact_coords.y + .5f, impact_coords.z + .5f, impact_coords.x, impact_coords.y + .5f, impact_coords.z + .5f, 250, 1, war, playerPed, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x + .5f, impact_coords.y, impact_coords.z + .5f, impact_coords.x + .5f, impact_coords.y, impact_coords.z + .5f, 250, 1, war, playerPed, 1, 0, -1.0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(impact_coords.x, impact_coords.y, impact_coords.z, impact_coords.x, impact_coords.y, impact_coords.z, 250, 1, war, playerPed, 1, 0, -1.0);
				// trigger a drop of motars on  position close to the end of our rocket 

				ENTITY::DELETE_ENTITY(&rocket); // delete the rocket model 
				PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0); // keep us unable to shoot 
				CAM::RENDER_SCRIPT_CAMS(0, true, 700, 1, 1); // reset cam 
				CAM::DESTROY_CAM(new_camera, 1); // destroy old camera 
				firing_mod_value = 0; // reset rocket flying mod 
			}
		}
	}
	if (!GuidedMissileInsight) {
		CAM::DESTROY_CAM(new_camera, 1);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
		rocket = 0;
		y = 255;
		ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 0);
	}
	
}


//Full Weapon Custom

void Weap::maingunmenu()
{

	Menu::Title("");
	Menu::SubTitle("Weapons");
	Menu::MenuOption("Melee", Melee);//done
	Menu::MenuOption("DLC", New_DLC_foursix);//donne
	Menu::MenuOption("Handguns", Handguns);//done
	Menu::MenuOption("Machine Guns", MachineGuns);//done
	Menu::MenuOption("AR", Rifes);//done
	Menu::MenuOption("Sniper Rifles", SniperRifles);//done
	Menu::MenuOption("Shotguns", Shotgun);//done
	Menu::MenuOption("Heavy Guns", HeavyGuns);//done
	Menu::MenuOption("Thrown Weapons", ThrownWeapons);//done
	Menu::MenuOption("Mark II guns", II);//done
	Menu::MenuOption("tints", tints);//done

}

//done
void Weap::marktwoguns()
{
	Menu::Title("");
	Menu::SubTitle("MK2 Guns");
	Menu::MenuOption("Pistol MK II", MK2_Pistol);//done
	Menu::MenuOption("SMG Mk II", SMG_Mk_II);//done
	Menu::MenuOption("Assault Rifle Mk II", Assault_Rifle_Mk_II);//done
	Menu::MenuOption("Carbine Rifle Mk II", Carbine_Rifle_Mk_II);//done
	Menu::MenuOption("Combat MG Mk II", Combat_MG_Mk_II);//done
	Menu::MenuOption("Heavy Sniper Mk II", Heavy_Sniper_Mk_II);//done
	Menu::MenuOption("SNS Pistol Mk II", SNS_Pistol_Mk_II);//done
	Menu::MenuOption("Revolver Mk II", Revolver_Mk_II);//done
	Menu::MenuOption("Special Carbine Mk II", Special_Carbine_Mk_II);//done
	Menu::MenuOption("Bullpup Rifle Mk II", Bullpup_Rifle_Mk_II);//done
	Menu::MenuOption("Pump Shotgun Mk II", Pump_Shotgun_Mk_II);//done
	Menu::MenuOption("Marksman Rifle Mk II", Marksman_Rifle_Mk_II);//done
}
//done
void Weap::heavyguns()
{
	Menu::Title("");
	Menu::SubTitle("HeavyGuns");
	Menu::MenuOption("GrenadeLauncher", GrenadeLauncher);//done
	Menu::MenuOption("GrenadeLauncherSmoke", GrenadeLauncherSmoke);//done
	Menu::MenuOption("HomingLauncher", HomingLauncher);//done
	Menu::MenuOption("Railgun", Railgun);//done
	Menu::MenuOption("Firework", Firework);//done
	Menu::MenuOption("Minigun", Minigun);//done
	Menu::MenuOption("RPG", RPG);//done RPG
	Menu::MenuOption("CompactLauncher", CompactLauncher);//done
}
//done
void Weap::sniperrifles()
{
	Menu::Title("");
	Menu::SubTitle("SniperRifles");
	Menu::MenuOption("SniperRifle", sp);//done
	Menu::MenuOption("HeavySniper", HeavySniper);//done
	Menu::MenuOption("MarksmanRifle", MarksmanRifle);//done

}
//done
void Weap::rifes()
{
	Menu::Title("");
	Menu::SubTitle("AR");
	Menu::MenuOption("Assault Rifle", AssaultRifle);//done
	Menu::MenuOption("Carbine Rifle", CarbineRifle);//done
	Menu::MenuOption("Advanced Rifle", AdvancedRifle);//done
	Menu::MenuOption("Special Carbine", SpecialCarbine);//done
	Menu::MenuOption("Bullpup Rifle", BullpupRiflev2);//done
	Menu::MenuOption("Compact Rifle", CompactRifle);//done
	Menu::MenuOption("Military Rifle", MiliTaryrifle);//done
}
//done
void Weap::handguns()
{
	Menu::Title("");
	Menu::SubTitle("HandGuns");
	Menu::MenuOption("Pistol", Pistol);//done
	Menu::MenuOption("SNS pistol", sns);//done
	Menu::MenuOption("Heavy Pistol", heavy);//done
	Menu::MenuOption("Combat Pistol", combat);//done
	Menu::MenuOption("AP Pistol", app);//done
	Menu::MenuOption(".50 Cal Pistol", cal);//done
	Menu::MenuOption("Vintage Pistol", vintage);//done
	Menu::MenuOption("Revolver", Revolver);//done
	Menu::MenuOption("MarksmanPistol", MarksmanPistol);//done
	Menu::MenuOption("StunGun", StunGun);//done
	Menu::MenuOption("FlareGun", FlareGun);//done
}
//done
void Weap::shotgun()
{
	Menu::Title("");
	Menu::SubTitle("ShotGuns");
	Menu::MenuOption("PumpShotgun", pump);//done
	Menu::MenuOption("AssaultShotgun", AssaultShotgun);//done
	Menu::MenuOption("BullpupShotgun", BullpupShotgun);//done
	Menu::MenuOption("HeavyShotgun", HeavyShotgun);//done
	Menu::MenuOption("Musket", Musket);//done
	Menu::MenuOption("DoubleBarrelShotgun", DoubleBarrelShotgun);//done
	Menu::MenuOption("SawnoffShotgun", SawnoffShotgun);//done
	Menu::MenuOption("Autoshotgun", Autoshotgun);//done
	Menu::MenuOption("Combat Shotgun", combatSG);//done

}
//done
void Weap::machineguns()
{
	Menu::Title("");
	Menu::SubTitle("MachineGuns");
	Menu::MenuOption("SMG", smg);//donet
	Menu::MenuOption("MicroSMG", MicroSMG);//done
	Menu::MenuOption("AssultSMG", AssultSMG);//done
	Menu::MenuOption("CombatPDW", CombatPDW);//done
	Menu::MenuOption("MG", MG);//done
	Menu::MenuOption("Machine Pistol", MACHINE);//done
	Menu::MenuOption("CombatMG", CombatMG);//done
	Menu::MenuOption("Gusenberg", Gusenberg);//done

}
//done
void Weap::new_DLC_foursix()
{
	Menu::Title("");
	Menu::SubTitle("DLC 1.46 Weapnes");
	Menu::MenuOption("Widowmaker", RAYMINIGUN);//done
	Menu::MenuOption("Unholy Hellbringer", RAYCARBINE);//done
	Menu::MenuOption("Ray Pistol", RAYPISTOL);//done
}
//done
void Weap::Tints()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Tints");
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::thorwable()
{
	Menu::Title("");
	Menu::SubTitle("Thrown Weapons");

	if (Menu::Option("Give Fire Extinguisher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER"), 9999, 1, 1);
	}
	if (Menu::Option("Give Grenades"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADE"), 9999, 1, 1);
	}
	if (Menu::Option("Give StickyBomb"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_STICKYBOMB"), 9999, 1, 1);
	}
	if (Menu::Option("Give ProximityMine"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PROXMINE"), 9999, 1, 1);
	}
	if (Menu::Option("Give BZGas"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BZGAS"), 9999, 1, 1);
	}
	if (Menu::Option("Give Molotov"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MOLOTOV"), 9999, 1, 1);
	}
	if (Menu::Option("Give PetrolCan"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PETROLCAN"), 9999, 1, 1);
	}
	if (Menu::Option("Give Flare"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FLARE"), 9999, 1, 1);
	}
	if (Menu::Option("Give Ball"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BALL"), 9999, 1, 1);
	}
	if (Menu::Option("Give Snowball"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNOWBALL"), 9999, 1, 1);
	}
	if (Menu::Option("Give SmokeGrenade"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMOKEGRENADE"), 9999, 1, 1);
	}
	if (Menu::Option("Give PipeBomb"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PIPEBOMB"), 9999, 1, 1);
	}

}
//done
void Weap::meleee()
{

	Menu::Title("");
	Menu::SubTitle("Melee");
	Menu::MenuOption("Knuckle Duster", KnuckleDuster);
	Menu::MenuOption("Switch Blade", SwitchBlade);
	if (Menu::Option("Give Knife"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_KNIFE"), 9999, 1, 1);
	}
	if (Menu::Option("Give Night Stick"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_NIGHTSTICK"), 9999, 1, 1);
	}
	if (Menu::Option("Give Hammer"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HAMMER"), 9999, 1, 1);
	}
	if (Menu::Option("Give Bat"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BAT"), 9999, 1, 1);
	}
	if (Menu::Option("Give Crow Bar"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CROWBAR"), 9999, 1, 1);
	}
	if (Menu::Option("Give Golf Club"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GOLFCLUB"), 9999, 1, 1);
	}
	if (Menu::Option("Give Bottle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BOTTLE"), 9999, 1, 1);
	}
	if (Menu::Option("Give Dagger"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_DAGGER"), 9999, 1, 1);
	}
	if (Menu::Option("Give Hatchet"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HATCHET"), 9999, 1, 1);
	}
	if (Menu::Option("Give Machete"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHETE"), 9999, 1, 1);
	}
	if (Menu::Option("Give Flashlight"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FLASHLIGHT"), 9999, 1, 1);
	}
	if (Menu::Option("Give PoolCue"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_POOLCUE"), 9999, 1, 1);
	}
	if (Menu::Option("Give Wrench"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_WRENCH"), 9999, 1, 1);
	}
	if (Menu::Option("Give BattleAxe"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BATTLEAXE"), 9999, 1, 1);
	}
	if (Menu::Option("Give  Stone Hatchet"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_stone_hatchet"), 9999, 1, 1);
	}
}
//done
void Weap::knuckleduster()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Knuckle Duster");
	if (Menu::Option("Give KnuckleDuster"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), 9999, 1, 1);
	}
	if (Menu::Option("Varmod Ballas"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_BALLAS"));
	}
	if (Menu::Option("Varmod Base"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_BASE"));
	}
	if (Menu::Option("Varmod Diamond"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_DIAMOND"));
	}
	if (Menu::Option("Varmod Dollar"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_DOLLAR"));
	}
	if (Menu::Option("Varmod Hate"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_HATE"));
	}
	if (Menu::Option("Varmod King"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_KING"));
	}
	if (Menu::Option("Varmod Love"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_LOVE"));
	}
	if (Menu::Option("Varmod Pimp"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_PIMP"));
	}
	if (Menu::Option("Varmod Player"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_PLAYER"));
	}
	if (Menu::Option("Varmod Vagos"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_knuckle"), GAMEPLAY::GET_HASH_KEY("COMPONENT_KNUCKLE_VARMOD_VAGOS"));
	}
}
//done
void Weap::switchblade()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("SwitchBlade");
	if (Menu::Option("Give SwitchBlade"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SWITCHBLADE"), 9999, 1, 1);
	}
	if (Menu::Option("Default Handle"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SWITCHBLADE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SWITCHBLADE_VARMOD_BASE"));
	}
	if (Menu::Option("VIP Variant"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SWITCHBLADE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SWITCHBLADE_VARMOD_VAR1"));
	}
	if (Menu::Option("Bodyguard Variant"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SWITCHBLADE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SWITCHBLADE_VARMOD_VAR2"));
	}
}
//done
void Weap::Raygun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Widowmaker");
	if (Menu::Option("Give Widowmaker"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAYMINIGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Purple"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Ornage"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Pink"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
}
//done
void Weap::RAYCarbine()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Unholy Hellbringer");
	if (Menu::Option("Give Unholy Hellbringer"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAYCARBINE"), 9999, 1, 1);
	}
	if (Menu::Option("Purple"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
}
//done
void Weap::RAYPistol()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Up-n-atomizer");
	if (Menu::Option("Give Up-n-atomizer"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAYPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Pruple"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}

}
//done
void Weap::mk2tints()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Tints");
	if (Menu::Option("Classic Black"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Classic Gray"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Classic Two Tone"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Classic White"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Classic Beige"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("Classic Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Classic Blue"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Classic Earth"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
	if (Menu::Option("Classic Brown And Black"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 8);
	}
	if (Menu::Option("Red Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 9);
	}
	if (Menu::Option("Blue Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 10);
	}
	if (Menu::Option("Yellow Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 11);
	}
	if (Menu::Option("Orange Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 12);
	}
	if (Menu::Option("Bold Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 13);
	}
	if (Menu::Option("Bold Purple And Yellow"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 14);
	}
	if (Menu::Option("Bold Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 15);
	}
	if (Menu::Option("Bold Green And Purple"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 16);
	}
	if (Menu::Option("Bold Red Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 17);
	}
	if (Menu::Option("Bold Green Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 18);
	}
	if (Menu::Option("Bold Cyan Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 19);
	}
	if (Menu::Option("Bold Yellow Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 20);
	}
	if (Menu::Option("Bold Red And White"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 21);
	}
	if (Menu::Option("Bold Blue And White"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 22);
	}
	if (Menu::Option("Metallic Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 23);
	}
	if (Menu::Option("Metallic Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 25);
	}
	if (Menu::Option("Metallic Gray And Lilac"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 26);
	}
	if (Menu::Option("Metallic Purple And Lime"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 27);
	}
	if (Menu::Option("Metallic Red"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 28);
	}
	if (Menu::Option("Metallic Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 29);
	}
	if (Menu::Option("Metallic Blue"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 30);
	}
	if (Menu::Option("Metallic White And Aqua"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 31);
	}
	if (Menu::Option("Metallic Red And Yellow"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 32);
	}
}
/*MarksmanRifle Mk II*/
void Weap::MarksmanRifleMkII()
{
	Menu::Title("");
	Menu::SubTitle("Marksman Rifle Mk II");
	if (Menu::Option("Give Marksman Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_m);
	Menu::MenuOption("Scope", Scope_m);
	Menu::MenuOption("Muzzle", Muzzle_m);
	Menu::MenuOption("Attachment", Attachment_m);
	Menu::MenuOption("Barrel", Barrel_m);
	Menu::MenuOption("Camos", Camos_m);
	Menu::MenuOption("Tints", Tints_m);
}
//done
void Weap::camos_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK "), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}

}
//done
void Weap::barrel_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrel");

	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MRFL_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MRFL_BARREL_02"));
	}
}
//done
void Weap::attachment_m()
{
	Menu::Title("");
	Menu::SubTitle("Attachment");
	Hash WeapHash;
	if (Menu::Option("FlashLight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void Weap::scope_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scope");

	if (Menu::Option("Holographic Sight"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Large Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
	if (Menu::Option("Zoom Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_LARGE_FIXED_ZOOM_MK2"));
	}
}
//done
void Weap::magazine_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scope");

	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_INCENDIARY"));
	}
	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_FMJ"));
	}

}
/*pump shotgun Mk II*/
void Weap::pump_Shotgun_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Pump Shotgun Mk II");
	if (Menu::Option("Pump Shotgun Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_sg);
	Menu::MenuOption("Scope", Scope_sg);
	Menu::MenuOption("Muzzle", Muzzle_sg);
	Menu::MenuOption("Attachment", Attachment_sg);
	Menu::MenuOption("Camos", Camos_sg);
	Menu::MenuOption("Tints", Tints_sg);
}
//done
void Weap::muzzle_sg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzle");

	if (Menu::Option("Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_08"));
	}
}
//done
void Weap::camos_sg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::attachment_sg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachment");

	if (Menu::Option("Flashlight"))//
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_SUPP_03"));
	}
}
//done
void Weap::scope_sg()
{
	Menu::Title("");
	Menu::SubTitle("Scope");
	Hash WeapHash;
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_MK2"));
	}
}
//done
void Weap::magazine_sg()
{
	Menu::Title("");
	Menu::SubTitle("Magazine");
	Hash WeapHash;
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_01"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_INCENDIARY"));
	}
	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("Hellow Point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("Explosive Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_EXPLOSIVE"));
	}
}
/*bullpup Rifle Mk II*/
void Weap::bullpup_Rifle_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Bullpup Rifle Mk II");
	if (Menu::Option("Give  Bullpup Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_b);
	Menu::MenuOption("Scope", Scope_b);
	Menu::MenuOption("Muzzle", Muzzle_b);
	Menu::MenuOption("Attachment", Attachment_b);
	Menu::MenuOption("Barrel", Barrel_b);
	Menu::MenuOption("Camos", Camos_b);
	Menu::MenuOption("Tints", Tints_b);
}
//done
void Weap::camos_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");

	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzles");

	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void Weap::barrel_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrels");

	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_02"));
	}
}
//done
void Weap::attachment_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachments");

	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void Weap::scope_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scope");

	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_02_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_MK2"));
	}
}
//done
void Weap::magazine_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine"); 
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_FMJ"));
	}
}
/*Special Carbine Mk II*/
void Weap::special_Carbine_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Special Carbine Mk II");
	if (Menu::Option("Give Special Carbine Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_sc);
	Menu::MenuOption("Scope", Scope_sc);
	Menu::MenuOption("Muzzle", Muzzle_sc);
	Menu::MenuOption("Attachment", Attachment_sc);
	Menu::MenuOption("Barrel", Barrel_sc);
	Menu::MenuOption("Camos", Camos_sc);
	Menu::MenuOption("Tints", Tints_sc);
}
//done
void Weap::camos_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzles");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void Weap::barrel_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrels");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SC_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SC_BARREL_02"));
	}
}
//done
void Weap::attachment_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachments");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void Weap::scope_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scopes");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void Weap::magazine_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");

	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_FMJ"));
	}
}
/*Revolver MK 2*/
void Weap::revolver_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Revolver Mk II");
	if (Menu::Option("Give Revolver Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_r);
	Menu::MenuOption("Attachment", Attachment_r);
	Menu::MenuOption("Camos", Camos_r);
	Menu::MenuOption("Tints", Tints_r);
}
//done
void Weap::camos_r()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::attachment_r()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachments");

	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Compensator"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_COMP_03"));
	}
}
//done
void Weap::magazine_r()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazines");

	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_01"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_INCENDIARY"));
	}
	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))//check
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_FMJ"));
	}
}
/*SNS Pistol MK2*/
void Weap::sNS_Pistol_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("SNS Pistol Mk II");
	if (Menu::Option("Give SNS Pistol Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_sn);
	Menu::MenuOption("Attachment", Attachment_sn);
	Menu::MenuOption("Camos", Camos_sn);
	Menu::MenuOption("Tints", Tints_sn);
}
//done
void Weap::camos_sn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_10"));
	}
	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::attachment_sn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachment");
	if (Menu::Option("Mounted Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_RAIL_02"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH_03"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP_02"));
	}
	if (Menu::Option("Compensator"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_COMP_02"));
	}
}
//done
void Weap::magazine_sn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_TRACER"));
	}sppp();
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_FMJ"));
	}
}
/*Heavy Sinper MK 2*/
void Weap::heavy_Sniper_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Heavy Sniper Mk II");
	if (Menu::Option("Give Heavy Sniper Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_hs);
	Menu::MenuOption("Scope", Scope_hs);
	Menu::MenuOption("Muzzle", Muzzle_hs);
	Menu::MenuOption("Attachment", Attachment_hs);
	Menu::MenuOption("Barrel", Barrel_hs);
	Menu::MenuOption("Camos", Camos_hs);
	Menu::MenuOption("Tints", Tints_hs);
}
//done
void Weap::camos_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_10"));
	}
	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzles");
	if (Menu::Option("Squared Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_08"));
	}
	if (Menu::Option("Bell-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_09"));
	}
}
//done
void Weap::barrel_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrels");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_BARREL_02"));
	}
}
//done
void Weap::attachment_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachment");
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_SUPP_03"));
	}
}
//done
void Weap::scope_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scopes");
	if (Menu::Option("Zoom scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_LARGE_MK2"));
	}
	if (Menu::Option("Advanced Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MAX"));
	}
	if (Menu::Option("Night Vision Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_NV"));
	}
	if (Menu::Option("Thermal Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_THERMAL"));
	}
}
//done
void Weap::magazine_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_02"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_FMJ"));
	}
	if (Menu::Option("Explosive Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_EXPLOSIVE"));
	}

}
/*Combat MG MK2*/
void Weap::combat_MG_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Combat MG Mk II");
	if (Menu::Option("Give Combat MG Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_mg);
	Menu::MenuOption("Scope", Scope_mg);
	Menu::MenuOption("Muzzle", Muzzle_mg);
	Menu::MenuOption("Attachment", Attachment_mg);
	Menu::MenuOption("Barrel", Barrel_mg);
	Menu::MenuOption("Camos", Camos_mg);
	Menu::MenuOption("Tints", Tints_mg);
}
//done
void Weap::camos_mg()
{
	Hash WeapHash;

	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzles");
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void Weap::barrel_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrels");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MG_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MG_BARREL_02"));
	}
}
//done
void Weap::attachment_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachment");
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void Weap::scope_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scope");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void Weap::magazine_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_FMJ"));
	}
}
/*Carbine Rifle mk 2*/
void Weap::carbine_Rifle_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Carbine Rifle Mk II");
	if (Menu::Option("Give Carbine Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_c);
	Menu::MenuOption("Scope", Scope_c);
	Menu::MenuOption("Muzzle", Muzzle_c);
	Menu::MenuOption("Attachment", Attachment_c);
	Menu::MenuOption("Barrel", Barrel_c);
	Menu::MenuOption("Camos", Camos_c);
	Menu::MenuOption("Tints", Tints_c);
}
//done
void Weap::camos_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void Weap::barrel_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_CR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_CR_BARREL_02"));
	}

}
//done
void Weap::attachment_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachments");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void Weap::scope_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scopes");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void Weap::magazine_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_FMJ"));
	}
}
/*Assault Rifle mk 2*/
void Weap::assault_Rifle_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("Assault Rifle Mk II");
	if (Menu::Option("Give Assault Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_a);
	Menu::MenuOption("Scope", Scope_a);
	Menu::MenuOption("Muzzle", Muzzle_a);
	Menu::MenuOption("Attachment", Attachment_a);
	Menu::MenuOption("Barrel", Barrel_a);
	Menu::MenuOption("Camos", Camos_a);
	Menu::MenuOption("Tints", Tints_a);
}
//done
void Weap::camos_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_10"));
	}
	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_a()
{
	Hash WeapHash;
	Menu::Title(""); ("");
	Menu::SubTitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void Weap::barrel_a()
{
	Hash WeapHash;
	Menu::Title(""); ("");
	Menu::SubTitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_02"));
	}
}
//done
void Weap::attachment_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachments");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))//fixed
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void Weap::scope_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scope");
	if (Menu::Option("Holographic Sight"))//chec
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void Weap::magazine_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_FMJ"));
	}
}
/*MK2 SMG*/
void Weap::sMG_Mk_II()
{
	Menu::Title("");
	Menu::SubTitle("SMG Mk II");
	if (Menu::Option("Give SMG Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_s);
	Menu::MenuOption("Scope", Scope_s);
	Menu::MenuOption("Muzzle", Muzzle_s);
	Menu::MenuOption("Attachment", Attachment_s);
	Menu::MenuOption("Barrel", Barrel_s);
	Menu::MenuOption("Camos", Camos_s);
	Menu::MenuOption("Tints", Tints_s);
}
//done
void Weap::camos_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::muzzle_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Muzzles");
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void Weap::barrel_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SB_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SB_BARREL_02"));
	}
}
//done
void Weap::attachment_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachment");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
}
//done
void Weap::scope_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Scope");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS_SMG"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_02_SMG_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_SMG_MK2"));
	}
}
//done
void Weap::magazine_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazines");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_FMJ"));
	}
}
/*PISTOL MK2*/
void Weap::mK2_Pistol()
{
	Menu::Title("");
	Menu::SubTitle("Pistol MK II");
	if (Menu::Option("Give Pistol MK II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_p);
	Menu::MenuOption("Attachment", Attachment_p);
	Menu::MenuOption("Camos", Camos_p);
	Menu::MenuOption("Tints", Tints_P);
}
//done
void Weap::camos_p()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_IND_01"));
	}
}
//done
void Weap::attachment_p()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Attachment");
	if (Menu::Option("Mounted Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_RAIL"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH_02"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP_02"));
	}
	if (Menu::Option("Compensator"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_COMP"));
	}
}
//done
void Weap::magazine_p()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_FMJ"));
	}
}
// reg guns
//done
//pistol
void Weap::pistol()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Pistol");
	if (Menu::Option("Give Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_CLIP_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::marksmanPistol()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("MarksmanPistol");
	if (Menu::Option("Give MarksmanPistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::revolver()
{
	Hash WeapHash;
	Menu::Title("");

	Menu::SubTitle("Revolver");
	if (Menu::Option("Give Revolver"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER"), 9999, 1, 1);
	}
	if (Menu::Option("Varmod Goon"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_VARMOD_GOON"));
	}
	if (Menu::Option("Varmod Boss"))

	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_VARMOD_BOSS"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Weap::Vintage()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Vintage Pistol");
	if (Menu::Option("Give vintage Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_VINTAGEPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_VINTAGEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_VINTAGEPISTOL_CLIP_02"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_VINTAGEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::mACHINE()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Machine Pistol");
	if (Menu::Option("Give Machine Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MACHINEPISTOL_CLIP_02"));
	}
	if (Menu::Option("Drum Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MACHINEPISTOL_CLIP_03"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::App()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("AP pistol");
	if (Menu::Option("Give AP Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_APPISTOL_CLIP_02"));
	}
	if (Menu::Option("Gilded Gun Metal Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_APPISTOL_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}

//done

void Weap::call()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle(".50 Cal");
	if (Menu::Option("Give .50 Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL50_CLIP_02"));
	}
	if (Menu::Option("Platinum Pearl Deluxe Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL50_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::snss()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("SNS Pistol");
	if (Menu::Option("Give SNS Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_CLIP_02"));
	}
	if (Menu::Option("Etched Wood Grip Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::Combat()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Combat Pistol");
	if (Menu::Option("Give CombatPistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATPISTOL_CLIP_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATPISTOL_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::HEavy()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Heavy Pistol");
	if (Menu::Option("Give HeavyPistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYPISTOL_CLIP_02"));
	}
	if (Menu::Option("Etched Wood Grip Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYPISTOL_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::flareGun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("FlareGun");
	if (Menu::Option("Give FlareGun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::stunGun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("StunGun");
	if (Menu::Option("Give Stun Gun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//shotguns
void Weap::autoshotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Auto shotgun");
	if (Menu::Option("Give Auto shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_AUTOSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::sawnoffShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Sawn off Shotgun");
	if (Menu::Option("Give Sawn off Shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SAWNOFFSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("VarmodLuxe"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SAWNOFFSHOTGUN"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SAWNOFFSHOTGUN_VARMOD_LUXE"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::doubleBarrelShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Double Barrel");
	if (Menu::Option("Give Double Barrel"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_DBSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::HeavyshOtgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("HeavyShotgun");
	if (Menu::Option("Give HeavyShotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_heavyshotgun_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_heavyshotgun_clip_03"));
	}
	if (Menu::Option("Grip"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::bullpupShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("BullpupShotgun");
	if (Menu::Option("Give Bullpup Shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::assaultShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("AssaultShotgun");
	if (Menu::Option("Give AssaultShotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTSHOTGUN_CLIP_02"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::PumP()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("PumpShotgun");
	if (Menu::Option("Give PumpShotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_sr_supp"));
	}
	if (Menu::Option("Special finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::musket()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Musket");
	if (Menu::Option("Give Musket"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_musket"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
//SUB
void Weap::gusenberg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Gusenberg");
	if (Menu::Option("give Gusenberg"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GUSENBERG"), 9999, 1, 1);
	}
	if (Menu::Option("Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GUSENBERG"), GAMEPLAY::GET_HASH_KEY("component_gusenberg_clip_02"));
	}

	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Weap::assultSMG()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("AssaultSMG");
	if (Menu::Option("Give AssultSMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTSMG_CLIP_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTSMG_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Weap::microSMG()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("MicroSMG");
	if (Menu::Option("Give MicroSMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_microsmg_clip_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_macro"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Varmod Luxe"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MICROSMG_VARMOD_LUXE"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::ssmg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("SMG");
	if (Menu::Option("Give SMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_03"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_varmod_luxe"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::combatPDW()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("CombatPDW");
	if (Menu::Option("Give CombatPDW"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("component_combatpdw_clip_02"));
	}
	if (Menu::Option("Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("component_combatpdw_clip_03"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::combatMG()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("CombatMG");
	if (Menu::Option("Give CombatMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), 9999, 1, 1);
	}
	if (Menu::Option("Extended/Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("component_combatmg_clip_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
	}
	if (Menu::Option("Etched Gun Metal Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::MGg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("MG");
	if (Menu::Option("Give MG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), 9999, 1, 1);
	}
	if (Menu::Option("Extended/Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), GAMEPLAY::GET_HASH_KEY("component_mg_clip_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), GAMEPLAY::GET_HASH_KEY("component_at_scope_small_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), GAMEPLAY::GET_HASH_KEY("component_mg_varmod_lowrider"));
	}

	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//AR
//done
void Weap::Bullpupriflev2()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("BullpupRifle");
	if (Menu::Option("Give BullpupRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("component_bullpuprifle_clip_02"));
	}

	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Varmod Lowrider"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("component_bullpuprifle_varmod_low"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}

void Weap::Militaryrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Military Rifle");
	if (Menu::Option("Give Military Rifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Clip 1"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MILITARYRIFLE_CLIP_01"));
	}

	if (Menu::Option("Clip 2"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MILITARYRIFLE_CLIP_02"));
	}
	if (Menu::Option("Sight"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MILITARYRIFLE_SIGHT_01"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MILITARYRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}

void Weap::Combatsg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Combat Shotgun");
	if (Menu::Option("Give Combat shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATSHOTGUN"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATSHOTGUN"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}

//done
void Weap::Specialcarbine()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("SpecialCarbine");
	if (Menu::Option("Give SpecialCarbine"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_clip_03"));
	}

	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
	}
	if (Menu::Option("Varmod Lowrider"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_varmod_lowrider"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Weap::Advancedrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("AdvancedRifle");
	if (Menu::Option("Give AdvancedRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("component_advancedrifle_clip_02"));
	}

	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Varmod Luxe"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("component_advancedrifle_varmod_luxe"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::Carbinerifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("CarbineRifle");
	if (Menu::Option("Give CarbineRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_clip_03"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
	}
	if (Menu::Option("Varmod Luxe"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_varmod_luxe"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::assaultRifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("AssaultRifle");
	if (Menu::Option("Give AssaultRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_clip_03"));
	}
	if (Menu::Option("Scope"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO"));
	}
	if (Menu::Option("Varmod Luxe"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_varmod_luxe"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::Compactrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("CompactRifle");
	if (Menu::Option("Give CompactRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_compactrifle_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_compactrifle_clip_03"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//sinpers
void Weap::Marksmanrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("MarksmanRifle");
	if (Menu::Option("Give MarksmanRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_marksmanrifle_clip_02"));
	}

	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::spp()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("SniperRifle");
	if (Menu::Option("Give SniperRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNIPERRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNIPERRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_scope_max"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNIPERRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::Heavysniper()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("HeavySniper");
	if (Menu::Option("Give HeavySniper"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MAX"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//heavy guns
//done
void Weap::RPGg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("RPG");
	if (Menu::Option("Give RPG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RPG"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::MinigunN()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Minigun");
	if (Menu::Option("Give Minigun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::GrenadeLauncherR()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("GrenadeLauncher");
	if (Menu::Option("Give GrenadeLauncher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Weap::FireworkK()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Firework");
	if (Menu::Option("Give Firework"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FIREWORK"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::HomingLauncherr()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("HomingLauncher");
	if (Menu::Option("Give HomingLauncher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HOMINGLAUNCHER"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::GrenadeLauncherSmokee()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("GrenadeLauncherSmoke");
	if (Menu::Option("Give Smoke Launcher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::CompactLauncherr()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("CompactLauncher");
	if (Menu::Option("Give Compact Launcher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTLAUNCHER"), 25, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Weap::Railgunn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::SubTitle("Railgun");
	if (Menu::Option("Give Railgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}

void RequestControl(Entity input)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);

	int tick = 0;
	while (tick <= 50)
	{
		if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(input))
			WAIT(0);
		else
			return;
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);
		tick++;
	}
}

bool Weap::Gravity = false;
void Weap::GravityGun(bool toggle)
{

	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 5;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();
	if (equippedWeapon == WeaponPistol)
	{
		if (Gravity)
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
			{
				Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
				{
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}

				RequestControlOfEnt(EntityTarget);

				if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget)) ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

				if (GetAsyncKeyState(VK_LBUTTON))
				{
					AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
					Gravity = false;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
		}
		if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			Gravity = true;
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}
	}
}

char *ItoS22(int num)
{
	char buf[30];
	_snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}

bool Weap::gravegun = false;
bool Weap::grav_target_locked2 = false;
void Weap::aGravityGun()
{
	Entity EntityTarget;
	Hash equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 5;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();
	if (equippedWeapon == WeaponPistol)
	{
		if (grav_target_locked2)
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
			{
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

				if (GetAsyncKeyState(VK_LBUTTON))
				{
					AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
						0.0f, 0, 0, 1, 1, 0, 1);
					grav_target_locked2 = false;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
		}
		if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			grav_target_locked2 = true;
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}
	}

	char* host;
	if (NETWORK::NETWORK_IS_HOST()) {
		host = "~g~true";
	}
	else {
		host = "~g~false";
	}
	char* hoster;
	for (int i = 0; i <= 32; i++) {
		Ped Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		Player Host = NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0);
		if (Host == i) {
			hoster = PLAYER::GET_PLAYER_NAME(i);
		}
	}
	if (sizeof(hoster) / sizeof(char) > 2) {
		hoster = "~r~Unknown";
	}
	else {
		ostringstream hostercolored;
		hostercolored << "~g~" << hoster;
		hoster = (char*)hostercolored.str().c_str();
	}
//	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	Hash model = 0;
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1))
		model = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(playerPed, 1));
	char* vehicleModel = "";
	if (model != 0)
		vehicleModel = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(model);
	ostringstream playername;
	playername << "~g~" << PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()) << "~g~";
	std::string hoststring = (std::string)"Host: " + host;
	std::string PlayerNameString = (std::string)"Player Name: " + playername.str();
	std::string hostStr = (std::string)"Session Host: " + hoster;


	Menu::AddSmallInfo((char*)hoststring.c_str(), 0); // you have same problem here? Yes
	Menu::AddSmallInfo((char*)PlayerNameString.c_str(), 1);
	Menu::AddSmallInfo((char*)hostStr.c_str(), 2);
	if (model != 0) {
		ostringstream modelNameColored;

		modelNameColored << "~g~" << vehicleModel;
		std::string VehModel = (std::string)"Vehicle Model: " + modelNameColored.str();
		Menu::AddSmallInfo((char*)VehModel.c_str(), 3);
	}
	else {
		//Menu::AddSmallInfo("Vehicle Model: ~r~None"), 3;
	}
	

	int griefing, annoyingme, hate, offensiveLanguage, offensivetagplate, GameExploit, Exploits;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), &griefing, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), &annoyingme, 0);//Voice Chat
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), &hate, 0);//Voice Chat
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &offensiveLanguage, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), &offensivetagplate, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &GameExploit, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_EXPLOITS"), &Exploits, 0);
	std::string greifingreps = (std::string)"Griefing Reports: " + ItoS22(griefing);
	std::string haterps = (std::string)"[VOICE CHAT] Hate Reports: " + ItoS22(hate);//
	std::string expreps = (std::string)"Game Exploit Reports: " + ItoS22(GameExploit);
	std::string gameexpreps = (std::string)"Game Exploit Reports: " + ItoS22(Exploits);//
	if (NETWORK::NETWORK_IS_IN_SESSION()) {
		Menu::AddSmallInfo((char*)greifingreps.c_str(), 5);
		Menu::AddSmallInfo((char*)haterps.c_str(), 6);
		Menu::AddSmallInfo((char*)expreps.c_str(), 7);
		Menu::AddSmallInfo((char*)gameexpreps.c_str(), 8);
	}
	else {

	}
}

Entity rope_ent0;
Object first_rope;
bool attached_first;

bool Weap::ROPEGUN = false;
void Weap::ropegun(bool toggle)
{

	auto camCoords = CAM::GET_GAMEPLAY_CAM_COORD();
	auto farCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 100.f));
	auto ray = WORLDPROBE::_START_SHAPE_TEST_RAY(camCoords.x, camCoords.y, camCoords.z, farCoords.x, farCoords.y, farCoords.z, -1, PLAYER::PLAYER_PED_ID(), 7);
	BOOL hit; Vector3 endCoords; Vector3 surfaceNormal; Entity ent = 0;
	WORLDPROBE::GET_SHAPE_TEST_RESULT(ray, &hit, &endCoords, &surfaceNormal, &ent);

	if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM) || IsKeyPressed(VK_RBUTTON)) 
	{
		if (ENTITY::DOES_ENTITY_EXIST(ent) && (ENTITY::IS_ENTITY_A_PED(ent) || ENTITY::IS_ENTITY_A_VEHICLE(ent) || ENTITY::IS_ENTITY_AN_OBJECT(ent))) 
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) 
			{
				ROPE::ROPE_LOAD_TEXTURES();
				auto pweapon = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
				auto pwep_coord = ENTITY::GET_ENTITY_COORDS(pweapon, 1);
				if (!attached_first)
				{
					first_rope = ROPE::ADD_ROPE(pwep_coord.x, pwep_coord.y, pwep_coord.z, 0, 0, 0, distanceBetween(ENTITY::GET_ENTITY_COORDS(ent, 1), pwep_coord), 1, 300, 0.5f, 0.5f, false, true, true, 1.0f, false, 0);
					Vector3 c0 = pwep_coord;
					Vector3 c1 = ENTITY::GET_ENTITY_COORDS(ent, 1);
					
					ROPE::ATTACH_ENTITIES_TO_ROPE(first_rope, pweapon, ent, c0.x, c0.y, c0.z, c1.x, c1.y, c1.z, distanceBetween(ENTITY::GET_ENTITY_COORDS(ent, 1), pwep_coord) + 40.f, 0, 0, NULL, NULL);
					ROPE::ACTIVATE_PHYSICS(first_rope);
					
					rope_ent0 = ent;
					attached_first = true;
				}
				else 
				{
					ROPE::DELETE_ROPE(&first_rope);
					Vector3 c0 = ENTITY::GET_ENTITY_COORDS(rope_ent0, 1);
					Vector3 c1 = ENTITY::GET_ENTITY_COORDS(ent, 1);
					
					first_rope = ROPE::ADD_ROPE(pwep_coord.x, pwep_coord.y, pwep_coord.z, 0, 0, 0, distanceBetween(ENTITY::GET_ENTITY_COORDS(rope_ent0, 1), ENTITY::GET_ENTITY_COORDS(ent, 1)), 1, 300, 0.5f, 0.5f, false, true, true, 1.0f, false, 0);
					ROPE::ACTIVATE_PHYSICS(first_rope);
					ROPE::ATTACH_ENTITIES_TO_ROPE(first_rope, rope_ent0, ent, c0.x, c0.y, c0.z, c1.x, c1.y, c1.z, distanceBetween(ENTITY::GET_ENTITY_COORDS(rope_ent0, 1), ENTITY::GET_ENTITY_COORDS(ent, 1)), 0, 0, NULL, NULL);
					
					first_rope = NULL;
					attached_first = false;
				}
			}
		}
	}
	else { ROPE::DELETE_ROPE(&first_rope); attached_first = false; }
}

bool protelgun = true; bool goball = false; bool help = true;
bool voidgun_ = true;
Entity BALL1; Entity BALL2;
Vector3 ball1Coord; Vector3 ball2Coord;
Object poertal1; Object poertal2;
//imt void

bool Weap::TeleyGun = false;
void Weap::teleygun(bool toggle)
{
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsKeyPressed(VK_SHIFT))//Add A for controller
		goball = true;
	else
		goball = false;

	if (protelgun)
	{

		Entity ObjectHash1 = 1441141378;
		Entity ObjectHash2 = 2310559750;
		
		if (!goball)
		{
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &ball1Coord))
			{
				ENTITY::DELETE_ENTITY(&BALL1);
				if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash1))
				{
					if (STREAMING::IS_MODEL_VALID(ObjectHash1))
					{
						STREAMING::REQUEST_MODEL(ObjectHash1);
						if (STREAMING::HAS_MODEL_LOADED(ObjectHash1))
						{
							BALL1 = OBJECT::CREATE_OBJECT(ObjectHash1, ball1Coord.x, ball1Coord.y, ball1Coord.z, 1, 1, 1);
							ENTITY::FREEZE_ENTITY_POSITION(BALL1, true);
						}
					}
				}
			}
		}
		if (goball)
		{

			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &ball2Coord))
			{
				ENTITY::DELETE_ENTITY(&BALL2);
				if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash2))
				{
					if (STREAMING::IS_MODEL_VALID(ObjectHash2))
					{
						STREAMING::REQUEST_MODEL(ObjectHash2);
						if (STREAMING::HAS_MODEL_LOADED(ObjectHash2))
						{
							BALL2 = OBJECT::CREATE_OBJECT(ObjectHash2, ball2Coord.x, ball2Coord.y, ball2Coord.z, 1, 1, 1);
							ENTITY::FREEZE_ENTITY_POSITION(BALL2, true);

						}
					}
				}
			}
		}
		else
		{

		}
			


		if (ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL1))
		{
			if (ENTITY::DOES_ENTITY_EXIST(BALL2))
			{
				ball2Coord = ENTITY::GET_ENTITY_COORDS(BALL2, false);

				ENTITY::SET_ENTITY_COORDS(playerPed, ball2Coord.x + 1, ball2Coord.y, ball2Coord.z + 1, 0, 0, 1, 0);
				WAIT(0);
			}
			else
				notifyBottom("Spawn in ~bold~PORTAL ~o~2");
		}
		if (ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL2))
		{
			if (ENTITY::DOES_ENTITY_EXIST(BALL1))
			{
				ball1Coord = ENTITY::GET_ENTITY_COORDS(BALL1, false);
				ENTITY::SET_ENTITY_COORDS(playerPed, ball1Coord.x + 1, ball1Coord.y, ball1Coord.z + 1, 0, 0, 1, 0);
				WAIT(0);
			}
			else
				notifyBottom("Spawn in ~bold~PORTAL ~b~1");
		}
		if (!ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL2) && !ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL1))
		{
			if (!help)
			{
				if (!goball)
					notifyBottom("~bold~PORTAL ~b~1");
				if (goball)
					notifyBottom("~bold~PORTAL ~o~2");
			}
		}
		if (PED::IS_PED_SHOOTING(playerPed))
			help = false;
		notifyBottom("Press F12 To Delete The Portals/ Shift For Second Portal");
	}
	if (GetAsyncKeyState(VK_F12))
	{
		ENTITY::DELETE_ENTITY(&BALL1);
		ENTITY::DELETE_ENTITY(&BALL2);

	}
}

int Weap::TimePD;

bool Weap::Flametrow = false;
void Weap::flametrow(bool toggle)
{
	float XPos = 0, YPos = 0, ZPos = 0.0, XOff = 0, YOff = 270, ZOff = 0;
	auto playerPed = PLAYER::PLAYER_PED_ID();


	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_RBUTTON))
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
		if ((timeGetTime() - Weap::TimePD) > 3)
		{
			int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos,
				XOff, YOff, ZOff, SKEL_R_Hand, 1, 1, 1, 1);
			Weap::TimePD = timeGetTime();
		}
		STREAMING::REMOVE_PTFX_ASSET();
	}
}

bool Weap::Drivegun = false;
void Weap::drivegun(bool toggle)
{
	Vector3 Coord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &Coord))
	{
		int shootedcar = VEHICLE::GET_CLOSEST_VEHICLE(Coord.x, Coord.y, Coord.z, 3.0f, 0, 70);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), shootedcar, -1);
	}
}
