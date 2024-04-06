#include "stdafx.h"
#include "math.h"
#include "Vehicle.h"
#include "Local.h"
#include "GUI.h"
#include "Other.h"
#include "Offsets.h"


#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())
DWORD featureWeaponVehShootLastTime = 0;
DWORD featureWeaponVehShootLastTimeFire = 0;

bool Veh::cargod = false;
bool Veh::Boost = false;

bool Veh::Flying = false;
bool Veh::SportMode = false;
bool Veh::BeyBlade = false;
bool Veh::vehlaser = false;
float WheelSize = 0.f;
char* Veh::GlowThing = "";
char* Veh::GlowThing3 = "";
char* Veh::GlowThing2 = "";
int Veh::guntype = 0;
int bullettypePos = 0;
static char* Bullet_Type[] = {

 "weapon_grenadelauncher_smoke",
 "weapon_stinger",
 "weapon_bzgas",
 "weapon_flare",
 "weapon_fireextinguisher",
 "weapon_digiscanner",
 "weapon_airstrike_rocket",
 "vehicle_weapon_tank",
 "vehicle_weapon_space_rocket",
 "vehicle_weapon_player_laser"
,
 "vehicle_weapon_player_bullet"
,
 "vehicle_weapon_rotors"
,
 "vehicle_weapon_player_buzzard"
,
 "weapon_passenger_rocket"
,
 "weapon_vehicle_rocket"
,
 "vehicle_weapon_plane_rocket"
,
 "AMMO_RPG"
,
 "AMMO_TANK"
,
 "AMMO_SPACE_ROCKET"
,
 "AMMO_PLAYER_LASER"
,
 "AMMO_ENEMY_LASER"
,
 "AMMO_GRENADELAUNCHER"
,
 "AMMO_GRENADELAUNCHER_SMOKE"
,
 "weapon_snowball"
,
 "WEAPON_ASSAULTRIFLE_MK2"
,
 "WEAPON_CARBINERIFLE_MK2"
,
 "WEAPON_COMBATMG_MK2"
,
 "WEAPON_HEAVYSNIPER_MK2"
,
 "VEHICLE_WEAPON_BRUTUS2_50CAL_LASER"
,
 "WEAPON_PISTOL_MK2"
,
 "WEAPON_SMG_MK2"
,
 "WEAPON_SNSPISTOL_MK2"
,
 "WEAPON_REVOLVER_MK2"
,
 "WEAPON_SPECIALCARBINE_MK2"
,
 "WEAPON_BULLPUPRIFLE_MK2"
,
 "WEAPON_PUMPSHOTGUN_MK2"
,
 "WEAPON_MARKSMANRIFLE_MK2"
,
 "VEHICLE_WEAPON_CANNON_BLAZER"
,
 "VEHICLE_WEAPON_RUINER_BULLET"
,
 "VEHICLE_WEAPON_RUINER_ROCKET"
,
 "VEHICLE_WEAPON_TURRET_BOXVILLE"
,
 "VEHICLE_WEAPON_APC_CANNON"
,
 "VEHICLE_WEAPON_APC_MISSILE"
,
 "VEHICLE_WEAPON_APC_MG"
,
 "VEHICLE_WEAPON_ARDENT_MG"
,
 "VEHICLE_WEAPON_DUNE_MG"
,
 "VEHICLE_WEAPON_DUNE_GRENADELAUNCHER"
,
 "VEHICLE_WEAPON_DUNE_MINIGUN"
,
 "VEHICLE_WEAPON_HALFTRACK_DUALMG"
,
 "VEHICLE_WEAPON_HALFTRACK_QUADMG"
,
 "VEHICLE_WEAPON_INSURGENT_MINIGUN"
,
 "VEHICLE_WEAPON_NIGHTSHARK_MG"
,
 "VEHICLE_WEAPON_OPPRESSOR_MG"
,
 "VEHICLE_WEAPON_OPPRESSOR_MISSILE"
,
 "VEHICLE_WEAPON_TAMPA_MISSILE"
,
 "VEHICLE_WEAPON_TAMPA_MORTAR"
,
 "VEHICLE_WEAPON_TAMPA_FIXEDMINIGUN"
,
 "VEHICLE_WEAPON_TAMPA_DUALMINIGUN"
,
 "VEHICLE_WEAPON_TECHNICAL_MINIGUN"
,
 "VEHICLE_WEAPON_TRAILER_QUADMG"
,
 "VEHICLE_WEAPON_TRAILER_MISSILE"
,
 "VEHICLE_WEAPON_TRAILER_DUALAA"
,
 "VEHICLE_WEAPON_MOBILEOPS_CANNON"
,
 "VEHICLE_WEAPON_BOMBUSHKA_DUALMG"
,
 "VEHICLE_WEAPON_BOMBUSHKA_CANNON"
,
 "VEHICLE_WEAPON_DOGFIGHTER_MG"
,
 "VEHICLE_WEAPON_DOGFIGHTER_MISSILE"
,
 "VEHICLE_WEAPON_HAVOK_MINIGUN"
,
 "VEHICLE_WEAPON_HUNTER_MG"
,
 "VEHICLE_WEAPON_HUNTER_MISSILE"
,
 "VEHICLE_WEAPON_HUNTER_CANNON"
,
 "VEHICLE_WEAPON_HUNTER_BARRAGE"
,
 "VEHICLE_WEAPON_ROGUE_MG"
,
 "VEHICLE_WEAPON_ROGUE_CANNON"
,
 "VEHICLE_WEAPON_ROGUE_MISSILE"
,
 "VEHICLE_WEAPON_MICROLIGHT_MG"
,
 "VEHICLE_WEAPON_MOGUL_NOSE"
,
 "VEHICLE_WEAPON_MOGUL_DUALNOSE"
,
 "VEHICLE_WEAPON_MOGUL_TURRET"
,
 "VEHICLE_WEAPON_MOGUL_DUALTURRET"
,
 "VEHICLE_WEAPON_SEABREEZE_MG"
,
 "VEHICLE_WEAPON_TULA_NOSEMG"
,
 "VEHICLE_WEAPON_TULA_MG"
,
 "VEHICLE_WEAPON_TULA_DUALMG"
,
 "VEHICLE_WEAPON_TULA_MINIGUN"
,
 "VEHICLE_WEAPON_VIGILANTE_MG"
,
 "VEHICLE_WEAPON_VIGILANTE_MISSILE"
,
 "VEHICLE_WEAPON_AKULA_TURRET_SINGLE"
,
 "VEHICLE_WEAPON_AKULA_MISSILE"
,
 "VEHICLE_WEAPON_AKULA_TURRET_DUAL"
,
 "VEHICLE_WEAPON_AKULA_MINIGUN"
,
 "VEHICLE_WEAPON_AKULA_BARRAGE"
,
 "VEHICLE_WEAPON_CHERNO_MISSILE"
,
 "VEHICLE_WEAPON_COMET_MG"
,
 "VEHICLE_WEAPON_DELUXO_MG"
,
 "VEHICLE_WEAPON_DELUXO_MISSILE"
,
 "VEHICLE_WEAPON_KHANJALI_CANNON"
,
 "VEHICLE_WEAPON_KHANJALI_CANNON_HEAVY"
,
 "VEHICLE_WEAPON_KHANJALI_MG"
	,
	 "VEHICLE_WEAPON_KHANJALI_GL"
	,
	 "VEHICLE_WEAPON_REVOLTER_MG"
	,
	 "VEHICLE_WEAPON_SAVESTRA_MG"
	,
	 "VEHICLE_WEAPON_SUBCAR_MG"
	,
	 "VEHICLE_WEAPON_SUBCAR_MISSILE"
	,
	 "VEHICLE_WEAPON_SUBCAR_TORPEDO"
	,
	 "VEHICLE_WEAPON_THRUSTER_MG"
	,
	 "VEHICLE_WEAPON_THRUSTER_MISSILE"
	,
	 "VEHICLE_WEAPON_VISERIS_MG"
	,
	 "VEHICLE_WEAPON_VOLATOL_DUALMG"
	,
	 "VEHICLE_WEAPON_AVENGER_CANNON"
	,
	 "VEHICLE_WEAPON_MENACER_MG"
	,
	 "VEHICLE_WEAPON_MULE4_MG"
	,
	 "VEHICLE_WEAPON_MULE4_MISSILE"
	,
	 "VEHICLE_WEAPON_MULE4_TURRET_GL"
	,
	 "VEHICLE_WEAPON_OPPRESSOR2_MG"
	,
	 "VEHICLE_WEAPON_OPPRESSOR2_CANNON"
	,
	 "VEHICLE_WEAPON_OPPRESSOR2_MISSILE"
	,
	 "VEHICLE_WEAPON_POUNDER2_MINI"
	,
	 "VEHICLE_WEAPON_POUNDER2_MISSILE"
	,
	 "VEHICLE_WEAPON_POUNDER2_BARRAGE"
	,
	 "VEHICLE_WEAPON_SCRAMJET_MG"
	,
	 "VEHICLE_WEAPON_SCRAMJET_MISSILE"
	,
	 "VEHICLE_WEAPON_SPEEDO4_MG"
	,
	 "VEHICLE_WEAPON_SPEEDO4_TURRET_MG"
	,
	 "VEHICLE_WEAPON_SPEEDO4_TURRET_MINI"
	,
	 "VEHICLE_WEAPON_STRIKEFORCE_CANNON"
	,
	 "VEHICLE_WEAPON_STRIKEFORCE_BARRAGE"
	,
	 "VEHICLE_WEAPON_STRIKEFORCE_MISSILE"
	,
	 "VEHICLE_WEAPON_HACKER_MISSILE"
	,
	 "VEHICLE_WEAPON_HACKER_MISSILE_HOMING"
	,
	 "VEHICLE_WEAPON_MORTAR_KINETIC"
	,
	 "VEHICLE_WEAPON_SCARAB_50CAL"
	,
	 "VEHICLE_WEAPON_SCARAB2_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_BRUISER_50CAL"
	,
	 "VEHICLE_WEAPON_BRUISER2_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_ISSI4_50CAL"
	,
	 "VEHICLE_WEAPON_ISSI5_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_DEATHBIKE_DUALMINIGUN"
	,
	 "VEHICLE_WEAPON_DEATHBIKE2_MINIGUN_LASER"
	,
	 "VEHICLE_WEAPON_IMPERATOR_50CAL"
	,
	 "VEHICLE_WEAPON_IMPERATOR2_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_DOMINATOR4_50CAL"
	,
	 "VEHICLE_WEAPON_DOMINATOR5_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_FLAMETHROWER"
	,
	 "VEHICLE_WEAPON_FLAMETHROWER_SCIFI"
	,
	 "VEHICLE_WEAPON_ZR380_50CAL"
	,
	 "VEHICLE_WEAPON_ZR3802_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_SLAMVAN4_50CAL"
	,
	 "VEHICLE_WEAPON_SLAMVAN5_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_MONSTER3_GLKIN"
	,
	 "VEHICLE_WEAPON_IMPALER2_50CAL"
	,
	 "VEHICLE_WEAPON_IMPALER3_50CAL_LASER"
	,
	 "VEHICLE_WEAPON_BRUTUS_50CAL"
};

void WheelPTFX(char* streamName, char* PTFXName)
{
	uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	STREAMING::REQUEST_NAMED_PTFX_ASSET(streamName);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED1(streamName))
	{
		Vector3 pos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_lf"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos.x, pos.y, pos.z, 0.f, 0.f, 0.f, 0.4f, false, false, false);
		Vector3 pos1 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_lr"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos1.x, pos1.y, pos1.z, 0.f, 0.f, 0.f, 0.4f, false, false, false);
		Vector3 pos2 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_rf"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos2.x, pos2.y, pos2.z, 0.f, 0.f, 0.f, 0.4f, false, false, false);
		Vector3 pos3 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_rr"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos3.x, pos3.y, pos3.z, 0.f, 0.f, 0.f, 0.4f, false, false, false);
	}
	else STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
}

void Veh::CustomWheelPTFX1(char* streamName, char* PTFXName)
{
	uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	STREAMING::REQUEST_NAMED_PTFX_ASSET(streamName);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED1(streamName))
	{
		Vector3 pos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_lf"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos.x, pos.y, pos.z, 0.f, 0.f, 0.f, Menu::Settings::ptfxsizeveh, false, false, false);
	}
	else STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
}

void Veh::CustomWheelPTFX2(char* streamName, char* PTFXName)
{
	uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	STREAMING::REQUEST_NAMED_PTFX_ASSET(streamName);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED1(streamName))
	{
		Vector3 pos1 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_lr"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos1.x, pos1.y, pos1.z, 0.f, 0.f, 0.f, Menu::Settings::ptfxsizeveh, false, false, false);
	}
	else STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
}

void Veh::CustomWheelPTFX3(char* streamName, char* PTFXName)
{
	uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	STREAMING::REQUEST_NAMED_PTFX_ASSET(streamName);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED1(streamName))
	{
		Vector3 pos2 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_rf"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos2.x, pos2.y, pos2.z, 0.f, 0.f, 0.f, Menu::Settings::ptfxsizeveh, false, false, false);
	}
	else STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
}

void Veh::CustomWheelPTFX4(char* streamName, char* PTFXName)
{
	uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	STREAMING::REQUEST_NAMED_PTFX_ASSET(streamName);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED1(streamName))
	{
		Vector3 pos3 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_rr"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos3.x, pos3.y, pos3.z, 0.f, 0.f, 0.f, Menu::Settings::ptfxsizeveh, false, false, false);
	}
	else STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
}


bool customvehicleweapon = false;
void Veh::CustomVehicleWeapon(char* weaponbullet) {
	if (GetAsyncKeyState(VK_MULTIPLY))

		Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
	Player player = PLAYER::PLAYER_ID();
	bool bSelect = GetAsyncKeyState(VK_MULTIPLY); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() && PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY(weaponbullet); if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();
	}
}

void Veh::UpdateLoop()
{

	if (customvehicleweapon) {
		Veh::CustomVehicleWeapon(Bullet_Type[bullettypePos]);
	}



	if (Flying)
	{
		Flyingg();
	}
	if (SportMode)
	{
		Sportmod();
	}
	if (BeyBlade)
	{
		Beyblad();
	}
	else
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::SET_ENTITY_COLLISION(Veh, true, true);
		VEHICLE::SET_VEHICLE_GRAVITY(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), TRUE);
	}

	if (vehlaser)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.1f), v1.y + 1.0f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.1f), v1.y + 1.0f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 1.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 1.0f, 0.1f);

		if (ENTITY::DOES_ENTITY_EXIST(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 1))) 
		{
			GRAPHICS::DRAW_LINE(coords0from.x, coords0from.y, coords0from.z, coords0to.x, coords0to.y, coords0to.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(coords1from.x, coords1from.y, coords1from.z, coords1to.x, coords1to.y, coords1to.z, 0, 0, 200, 255);
		}
	}
	else
	{

	}

	if (cargod)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			ENTITY::SET_ENTITY_INVINCIBLE(veh, TRUE);
			ENTITY::SET_ENTITY_PROOFS(veh, 1, 1, 1, 1, 1, 1, 1, 1);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 0);
		}
	}

	HornBoost ? hornboost(true) : NULL;

	Rainbowcar ? rainbowcar(true) : NULL;

	CR ? cr(true) : NULL;

	DriveWater ? driveWater(true) : NULL;

	bikeNoFall ? bikenofall(true) : NULL;

	InstantBreak ? instantBreak(true) : NULL;

	LightMultiplier ? lightmultiplier(true) : NULL;

	SuspentionMultiplier ? suspentionmultiplier(true) : NULL;

	SuspentionMultiplier2 ? suspentionmultiplier2(true) : NULL;

	SuspentionMultiplier3 ? suspentionmultiplier3(true) : NULL;

	MassMultiplier ? massmultiplier(true) : NULL;

	BuoyancyMultiplier ? buoyancymultiplier(true) : NULL;


	FlyCar ? Flycar(true) : NULL;

	DV ? dv(true) : NULL;

	if (Boost)
	{
		Boostt();
	}
	else
	{

	}

	//Veh Weapons

	Shootrpg ? shootrpg(true) : NULL;
	Shootrpg1 ? shootrpg1(true) : NULL;
	Shootrpg2 ? shootrpg2(true) : NULL;
	Shootrpg3 ? shootrpg3(true) : NULL;
	Shootrpg4 ? shootrpg4(true) : NULL;
	Shootrpg5 ? shootrpg5(true) : NULL;
	Shootrpg6 ? shootrpg6(true) : NULL;
	Shootrpg7 ? shootrpg7(true) : NULL;
	Shootrpg8 ? shootrpg8(true) : NULL;

	//Veh Particles

	P1 ? px1(true) : NULL;
	P2 ? px2(true) : NULL;
	P3 ? px3(true) : NULL;
	P4 ? px4(true) : NULL;
	P5 ? px5(true) : NULL;
	P6 ? px6(true) : NULL;

	


	if (ToggleGlow)
	{
		uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

		if (Veh::Arm == true) //Right Arm
		{
			CustomWheelPTFX3(GlowThing, GlowThing3); 
		}
		else
		{

		}
		if (Veh::Arm2 == true)
		{
			CustomWheelPTFX1(GlowThing, GlowThing3); 
		}
		else
		{

		}
		if (Veh::Foot == true)
		{
			CustomWheelPTFX4(GlowThing, GlowThing3); 
		}
		else
		{

		}
		if (Veh::Foot2 == true) //Left
		{
			CustomWheelPTFX2(GlowThing, GlowThing3);
		}
		else
		{

		}
	}
}

bool Veh::HornBoost = false;
void Veh::hornboost(bool toggle) {
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, Menu::Settings::hornpower);
		}
	}
}

int Local::r = 255, Local::g = 0, Local::b = 0;
void RGBFade()
{
	if (Local::r > 0 && Local::b == 0) {
		Local::r--;
		Local::g++;
	}
	if (Local::g > 0 && Local::r == 0) {
		Local::g--;
		Local::b++;
	}
	if (Local::b > 0 && Local::g == 0) {
		Local::r++;
		Local::b--;
	}
}

bool Veh::Rainbowcar = false;
void Veh::rainbowcar(bool toggle)
{
	RGBFade();
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, Local::r, Local::g, Local::b);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, Local::r, Local::g, Local::b);
	VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, Local::r, Local::g, Local::b);
	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, Local::r, Local::g, Local::b);

}


//_SET_VEHICLE_NEON_LIGHTS_COLOUR


bool Veh::FlyCar = false;
void Veh::Flycar(bool toggle)
{
	int veh = PED::GET_VEHICLE_PED_IS_IN(playerPedId, 0);

	if (veh)
	{
		if (VEHICLE::IS_THIS_MODEL_A_CAR(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_BOAT(ENTITY::GET_ENTITY_MODEL(veh)))
		{
			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_THROTTLE_UP))
			{
				float Speed = ENTITY::GET_ENTITY_SPEED(veh) + 0.4;
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, Speed);
			}

			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_YAW_LEFT) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
			{
				Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(veh, 2);
				Rot.z = Rot.z + 1.0;
				ENTITY::SET_ENTITY_ROTATION(veh, Rot.x, Rot.y, Rot.z, 2, 1);
			}

			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_YAW_RIGHT) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
			{
				Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(veh, 2);
				Rot.z = Rot.z - 1.0;
				ENTITY::SET_ENTITY_ROTATION(veh, Rot.x, Rot.y, Rot.z, 2, 1);
			}
		}
	}
}

bool Veh::CR = false;
void Veh::cr(bool toggle)
{
	static Object container;
	auto selfVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 min, max;
	Vector3 cmin, cmax;
	auto c = ENTITY::GET_ENTITY_COORDS(selfVeh, 1);
	GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(selfVeh), &min, &max);
	GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_container_ld2"), &cmin, &cmax);

	if (!PED::IS_PED_ON_ANY_BIKE(PLAYER::PLAYER_PED_ID())) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
			notifyBottom("~r~Container rider requires a bike.");
			return;
		}
	}

	if (!STREAMING::HAS_MODEL_LOADED($("prop_container_ld2")))
		STREAMING::REQUEST_MODEL($("prop_container_ld2"));

	if (!ENTITY::DOES_ENTITY_EXIST(container) || !VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(selfVeh)) {
		static auto tickeer = GetTickCount();
		if ((GetTickCount() - tickeer) >= 1000) {
			if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_FLY_PITCH_UP_ONLY)) {
				tickeer = GetTickCount();
				ENTITY::APPLY_FORCE_TO_ENTITY(selfVeh, 0, 0, 0, 1.5, 0, 0, 0, 0, 1, 1, 1, 0, 1);
			}
		}
		static auto ticker = GetTickCount();
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0.f, 0.f, 0.f, 1, 1, 1, 0);
			ENTITY::DELETE_ENTITY(&container);
			OBJECT::DELETE_OBJECT(&container);
		}
		container = OBJECT::CREATE_OBJECT($("prop_container_ld2"), c.x, c.y, c.z - ((max.z / 2) + cmax.z), 1, 1, 0);
		ENTITY::SET_ENTITY_ROTATION(container, ENTITY::GET_ENTITY_PITCH(selfVeh), 0.f, ENTITY::GET_ENTITY_HEADING(selfVeh), 0, 0);
	}
}

float Veh::Speed = 1.0f;
float yaw, rotation, pitch, roll = 0.0f;
bool Backwardd = false;


Vector3 GET_CAMERA_DIRECTION23(float distance)
{
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924;
	float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));

	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;


}



void Veh::Sportmod()
{
	Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Vector3 rota = CAM::GET_GAMEPLAY_CAM_ROT(0.1);
	Vector3 dira = GET_CAMERA_DIRECTION23(0.1);
	ENTITY::SET_ENTITY_COLLISION(Veh, true, true);
	ENTITY::SET_ENTITY_ROTATION(Veh, rota.x, rota.y, rota.z, 0.1, 0.1);
	auto pos = ENTITY::GET_ENTITY_COORDS(Veh, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Veh, pos.x, pos.y, pos.z, true, true, true);

	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
	{
		Vector3 pos = add(&ENTITY::GET_ENTITY_COORDS(Veh, false), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 10.f));
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Veh, pos.x, pos.y, pos.z, true, true, true);
	}
}

void Veh::Beyblad()
{
	Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Vector3 rota = CAM::GET_GAMEPLAY_CAM_ROT(0.1);
	Vector3 dira = GET_CAMERA_DIRECTION23(0.1);
	Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Veh, 2);
	Rot.z = Rot.z + 1.0;
	ENTITY::SET_ENTITY_ROTATION(Veh, Rot.x, Rot.y, Rot.z, 2, 1);
	ENTITY::SET_ENTITY_COLLISION(Veh, false, false);

	float heading = ENTITY::GET_ENTITY_HEADING(Veh);
	ENTITY::SET_ENTITY_HEADING(Veh, heading >= 360.f ? 0 : heading + 2.5f);

}


void Veh::Flyingg()
{
	if (PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) != NULL)
	{
		VehicleInvisible1 = true;
		VEHICLE::SET_VEHICLE_GRAVITY(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false); 
		pitch = ENTITY::GET_ENTITY_PITCH(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));
		
		float Current = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));

		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::SET_ENTITY_COLLISION(Veh, false, false);

		if (GetAsyncKeyState(0x57)) //W key
		{
			Backwardd = false;
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, 0.0f, yaw, 2, true);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Current += Veh::Speed);
		}
		else if (GetAsyncKeyState(0x53)) //S key
		{
			Backwardd = true;
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, 0.0f, yaw, 2, true);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), (Current * -1.0f) - 1.0f);
		}
		else 
		{
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, roll, yaw, 2, true);
			if (Current > Veh::Speed && Backwardd)
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Current - 1.0f);
			}
			else
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0.0f);
			}
		}

		if (GetAsyncKeyState(0x41)) //A key
		{
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, roll, yaw += 1.0f, 2, true);
		}

		if (GetAsyncKeyState(0x44)) //D key
		{
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, roll, yaw -= 1.0f, 2, true);
		}

		if (GetAsyncKeyState(VK_SHIFT)) // SHIFT 
		{
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch -= 1.0f, roll, yaw, 2, true);
		}

		if (GetAsyncKeyState(VK_CONTROL)) // CONTROL 
		{
			ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch += 1.0f, roll, yaw, 2, true);
		}
	}
	else
	{
		VehicleInvisible1 = false;
	}
}

/*

int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);

		ENTITY::SET_ENTITY_COLLISION(Veh, false, false);

		if (GetAsyncKeyState(0x57)) // W key
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, Veh::Speed); // Speed = 50 fx
		}

		if (GetAsyncKeyState(0x41)) // A key
		{
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z + 1.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, 0, 0, Rot.z, 2, 1);
		}

		if (GetAsyncKeyState(0x44)) // D key
		{
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z - 1.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, 0, 0, Rot.z, 2, 1);
		}

		if (GetAsyncKeyState(0x53)) // S key
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, -1);
		}

		if (GetAsyncKeyState(VK_SPACE)) //VK_SPACE
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 1, 0, 0, 0, 1, false, true, true, true, true);
		}

		if (GetAsyncKeyState(VK_SHIFT)) //VK_SHIFT
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, -1, 0, 0, 0, 1, false, true, true, true, true);
		}

*/

bool Veh::DriveWater = false;
void Veh::driveWater(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float height = 0;
	WORLDPROBE::_SET_WAVES_INTENSITY(height);
	if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) {
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
			if (pos.z < containerCoords.z) {
				if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
					ENTITY::SET_ENTITY_COORDS(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
				else {
					RequestControlOfEnt(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
					ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
			}
		}
		else {
			Hash model = GAMEPLAY::GET_HASH_KEY("prop_container_ld2");
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
			container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
			RequestControlOfEnt(container);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, 0, 0);
		}
	}
	else {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			WAIT(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::_RESET_WAVES_INTENSITY();
		}
	}
}

bool Veh::bikeNoFall = false;
void Veh::bikenofall(bool toggle)
{
	PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), bikeNoFall);
}



/*bool Veh::GarageEditor = false;
void Veh::garageeditor(bool toggle)
{
	if (OBJECT::IS_GARAGE_EMPTY) {
		notifyMap("0 Vehicle detected");
	}
	else
	{

		VEHICLE::IS_VEHICLE_IN_GARAGE_AREA;
		OBJECT::IS_ANY_ENTITY_ENTIRELY_INSIDE_GARAGE;
		OBJECT::ARE_ENTITIES_ENTIRELY_INSIDE_GARAGE;
		VEHICLE::IS_THIS_MODEL_A_BIKE(ENTITY::GET_ENTITY_MODEL(iVar2)) || VEHICLE::IS_THIS_MODEL_A_CAR(ENTITY::GET_ENTITY_MODEL(iVar2)))

		FIRE::STOP_FIRE_IN_RANGE

			if (OBJECT::IS_ANY_ENTITY_ENTIRELY_INSIDE_GARAGE || OBJECT::ARE_ENTITIES_ENTIRELY_INSIDE_GARAGE)
			{


			}




	}
	
}*/





bool Veh::InstantBreak = false;
void Veh::instantBreak(bool toggle)
{
	if (GetAsyncKeyState(VK_KEY_R) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {

		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 0);
		}
		else
		{

		}
	}
	else
	{

	}
}

void Veh::spawn_vehicle(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(playerPedId, false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPedId);
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		//ENTITY::_SET_ENTITY_REGISTER(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		PED::SET_PED_INTO_VEHICLE(playerPedId, veh, -1);
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}

}

bool Veh::DV = false;
void Veh::dv(bool toggle)
{
	if (GetAsyncKeyState(VK_KEY_R) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) 
	{   
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 1);
	}
	else
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 0);
		notifyMap("Press R To Drift ");
	}
}



//VEHICLE_WEAPON_TANK

void Veh::CarGunMain()
{
	Menu::Title("");
	Menu::SubTitle("Vehicle Weapons");
	Menu::Toggle("Shells", Veh::Shootrpg);
	Menu::Toggle("Savage Bullets", Veh::Shootrpg1);
	Menu::Toggle("Laser", Veh::Shootrpg2);
	Menu::Toggle("Railgun", Veh::Shootrpg3);
	Menu::Toggle("Space Rocket", Veh::Shootrpg4);
	Menu::Toggle("RPG", Veh::Shootrpg5);
	if (Menu::Addintchar("Custom Bullet Type", Bullet_Type, bullettypePos, 0, 152)) { }
	Menu::Toggle("Custom Bullet", customvehicleweapon);
	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Toggle & Fire | Press +");
	}
	if (Menu::Settings::currentOption == 2) {
		Menu::OptionInfo("Toggle & Fire | Press +");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Toggle & Fire | Press +");
	}
	if (Menu::Settings::currentOption == 4) {
		Menu::OptionInfo("Toggle & Fire | Press +");
	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Toggle & Fire | Press +");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("153 Bullet Type");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Toggle & Fire | Press *");
	}
}


bool Veh::ToggleGlow;
bool Veh::Arm;
bool Veh::Arm2;
bool Veh::Foot;
bool Veh::Foot2;

int Veh::EffectsChar = 0;

static char* Veh::PTFXChar[] =
{
	 "No Effect", "Alien", "AlienX", "Clown", "Lightning", "Ghost", "Electric", "BankNotes", "Camera Flash", "FireWork", "Bullets Impact", "Boat Explosion", "Water Explosion", "Train Explosion", "Plane Explosion", "FBI Explosion", "Helicopter Explosion", "Light Explosion", "Magical Flowers", "Meth Smoke", "Car Impact", "Tire Smoke", "Burnout", "Starburst FW", "Fountain FW", "Shotburst FW", "Trailburst FW", "Beast","Mask Flames", "Judgement Ash", "Lens Dirt", "Alien Charging", "Alien Impact", "Alien Beam", "Laser", "Bomb Fuse", "Money Rain", "Champagne", "Pour Drinks",
};

void Veh::vp()
{
	Menu::Title("");
	Menu::SubTitle("Vehicle Particles");
	if (Menu::intchar("Glow", PTFXChar, Veh::EffectsChar, 0, 38))
	{
		if (Veh::EffectsChar == 0)
		{
			Veh::GlowThing = "";
			Veh::GlowThing3 = "";
		}
		if (Veh::EffectsChar == 1)
		{
			Veh::GlowThing = "scr_rcbarry1";
			Veh::GlowThing3 = "scr_alien_disintegrate";//done
		}
		if (Veh::EffectsChar == 2)
		{
			Veh::GlowThing = "scr_rcbarry1";
			Veh::GlowThing3 = "scr_alien_teleport";//done
		}
		if (Veh::EffectsChar == 3)
		{
			Veh::GlowThing = "scr_rcbarry2";
			Veh::GlowThing3 = "scr_clown_appears";//done
		}
		if (Veh::EffectsChar == 4)
		{
			Veh::GlowThing = "scr_rcbarry2";
			Veh::GlowThing3 = "scr_clown_death";//done
		}
		if (Veh::EffectsChar == 5)
		{
			Veh::GlowThing = "scr_agencyheist";
			Veh::GlowThing3 = "scr_fbi_dd_breach_smoke";
		}
		if (Veh::EffectsChar == 6)
		{
			Veh::GlowThing = "scr_agencyheistb";
			Veh::GlowThing3 = "scr_agency3b_elec_box";
		}
		if (Veh::EffectsChar == 7)
		{
			Veh::GlowThing = "scr_ornate_heist";
			Veh::GlowThing3 = "scr_heist_ornate_banknotes";
		}
		if (Veh::EffectsChar == 8)
		{
			Veh::GlowThing = "scr_rcpaparazzo1";
			Veh::GlowThing3 = "scr_rcpap1_camera";

		}
		if (Veh::EffectsChar == 9)
		{
			Veh::GlowThing = "proj_xmas_firework";
			Veh::GlowThing3 = "scr_firework_xmas_burst_rgw";

		}
		if (Veh::EffectsChar == 10)
		{
			Veh::GlowThing = "scr_martin1";
			Veh::GlowThing3 = "scr_sol1_sniper_impact";

		}
		if (Veh::EffectsChar == 11)//
		{
			Veh::GlowThing = "scr_oddjobtraffickingair";
			Veh::GlowThing3 = "scr_ojdg4_boat_exp";

		}
		if (Veh::EffectsChar == 12)
		{
			Veh::GlowThing = "scr_oddjobtraffickingair";
			Veh::GlowThing3 = "scr_ojdg4_water_exp";

		}
		if (Veh::EffectsChar == 13)
		{
			Veh::GlowThing = "scr_oddjobtraffickingair";
			Veh::GlowThing3 = "scr_drug_grd_train_exp";

		}
		if (Veh::EffectsChar == 14)
		{
			Veh::GlowThing = "scr_oddjobtraffickingair";
			Veh::GlowThing3 = "scr_drug_grd_plane_exp";

		}
		if (Veh::EffectsChar == 15)
		{
			Veh::GlowThing = "scr_agencyheist";
			Veh::GlowThing3 = "scr_fbi_exp_building";

		}
		if (Veh::EffectsChar == 16)
		{
			Veh::GlowThing = "scr_agencyheist";
			Veh::GlowThing3 = "scr_agency3b_heli_expl";//

		}
		if (Veh::EffectsChar == 17)
		{
			Veh::GlowThing = "scr_josh3";
			Veh::GlowThing3 = "scr_josh3_light_explosion";

		}
		if (Veh::EffectsChar == 18)
		{
			Veh::GlowThing = "scr_rcbarry2";
			Veh::GlowThing3 = "scr_exp_clown";

		}
		if (Veh::EffectsChar == 19)
		{
			Veh::GlowThing = "scr_familyscenem";
			Veh::GlowThing3 = "scr_meth_pipe_smoke";

		}
		if (Veh::EffectsChar == 20)
		{
			Veh::GlowThing = "scr_exile2";
			Veh::GlowThing3 = "scr_ex2_car_impact";

		}
		if (Veh::EffectsChar == 21)
		{
			Veh::GlowThing = "scr_mp_creator";
			Veh::GlowThing3 = "scr_mp_plane_landing_tyre_smoke";

		}
		if (Veh::EffectsChar == 22)
		{
			Veh::GlowThing = "scr_recartheft";
			Veh::GlowThing3 = "scr_wheel_burnout";

		}
		if (Veh::EffectsChar == 23)
		{
			Veh::GlowThing = "scr_indep_fireworks";
			Veh::GlowThing3 = "scr_indep_firework_starburst";

		}
		if (Veh::EffectsChar == 24)
		{
			Veh::GlowThing = "scr_indep_fireworks";
			Veh::GlowThing3 = "scr_indep_firework_fountain";

		}
		if (Veh::EffectsChar == 25)
		{
			Veh::GlowThing = "scr_indep_fireworks";
			Veh::GlowThing3 = "scr_indep_firework_shotburst";

		}
		if (Veh::EffectsChar == 26)
		{
			Veh::GlowThing = "scr_indep_fireworks";
			Veh::GlowThing3 = "scr_indep_firework_trailburst";

		}
		if (Veh::EffectsChar == 27)
		{
			Veh::GlowThing = "scr_powerplay";
			Veh::GlowThing3 = "scr_powerplay_beast_appear";

		}
		if (Local::EffectsChar == 28)
		{
			Local::GlowThing = "scr_impexp_jug";
			Local::GlowThing3 = "scr_ie_jug_mask_flame";

		}
		if (Local::EffectsChar == 29)
		{
			Local::GlowThing = "scr_bike_adversary";
			Local::GlowThing3 = "scr_adversary_judgement_ash";

		}
		if (Local::EffectsChar == 30)
		{
			Local::GlowThing = "scr_bike_adversary";
			Local::GlowThing3 = "scr_adversary_judgement_lens_dirt";

		}
		if (Local::EffectsChar == 31)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_charging";

		}
		if (Local::EffectsChar == 32)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_impact";

		}
		if (Local::EffectsChar == 33)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_beam";

		}
		if (Local::EffectsChar == 34)
		{
			Local::GlowThing = "scr_ch_finale";
			Local::GlowThing3 = "scr_ch_finale_laser";//

		}
		if (Local::EffectsChar == 35)
		{
			Local::GlowThing = "scr_stunts";
			Local::GlowThing3 = "scr_stunts_bomb_fuse";

		}
		if (Local::EffectsChar == 36)
		{
			Local::GlowThing = "scr_xs_celebration";
			Local::GlowThing3 = "scr_xs_money_rain";

		}
		if (Local::EffectsChar == 37)
		{
			Local::GlowThing = "scr_ba_club";
			Local::GlowThing3 = "scr_ba_club_champagne_spray";

		}
		if (Local::EffectsChar == 38)
		{
			Local::GlowThing = "scr_ba_club";
			Local::GlowThing3 = "scr_ba_club_drink_pour";

		}
	}
	Menu::Toggle("Enable", Veh::ToggleGlow);
	Menu::Float("Glow Scale", Menu::Settings::ptfxsizeveh, 0.f, 10.f);
	if (Menu::Option("~f~[ ~w~Vehicle Parts ~f~]")) {}
	Menu::Toggle("Right Front Wheel", Veh::Arm);
	Menu::Toggle("Left Front Wheel", Veh::Arm2);
	Menu::Toggle("Right Back Wheel", Veh::Foot);
	Menu::Toggle("Left Back Wheel", Veh::Foot2);


	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Choose Your Particle Effect | Enter To Select");
	}
	if (Menu::Settings::currentOption == 2) {
		Menu::OptionInfo("Enable Your Particles");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Size Of Particles");
	}
	if (Menu::Settings::currentOption == 4) {

	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Particles On Your Right Wheel");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("Particles On Your Left Wheel");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Particles On Your Right Wheel");
	}
	if (Menu::Settings::currentOption == 8) {
		Menu::OptionInfo("Particles On Your Left Wheel");
	}

}


bool Veh::Shootrpg = false;
void Veh::shootrpg(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}


}

//VEHICLE_WEAPON_PLAYER_LAZER
bool Veh::Shootrpg1 = false;
void Veh::shootrpg1(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLAYER_LAZER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//VEHICLE_WEAPON_ENEMY_LASER
bool Veh::Shootrpg2 = false;
void Veh::shootrpg2(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_ENEMY_LASER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//VEHICLE_WEAPON_OPPRESSOR_MISSILE
bool Veh::Shootrpg3 = false;
void Veh::shootrpg3(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//VEHICLE_WEAPON_SPACE_ROCKET
bool Veh::Shootrpg4 = false;
void Veh::shootrpg4(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//WEAPON_VEHICLE_ROCKET
bool Veh::Shootrpg5 = false;
void Veh::shootrpg5(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//VEHICLE_WEAPON_TANK
bool Veh::Shootrpg6 = false;
void Veh::shootrpg6(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_TANK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//VEHICLE_WEAPON_TANK
bool Veh::Shootrpg7 = false;
void Veh::shootrpg7(bool toggle)
{
	if (GetAsyncKeyState(VK_MULTIPLY))

		Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || !Shootrpg7) return;
	Player player = PLAYER::PLAYER_ID();
	bool bSelect = GetAsyncKeyState(VK_MULTIPLY); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_TANK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}


bool Veh::Shootrpg8 = false;
void Veh::shootrpg8(bool toggle)
{
	if (GetAsyncKeyState(VK_MULTIPLY))

		Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || !Shootrpg8) return;
	Player player = PLAYER::PLAYER_ID();
	bool bSelect = GetAsyncKeyState(VK_MULTIPLY); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_TANK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Veh::P = false;
void Veh::px(bool toggle)
{
	WheelPTFX("scr_rcbarry2", "scr_clown_appears");
}

bool Veh::P1 = false;
void Veh::px1(bool toggle)
{
	WheelPTFX("scr_rcbarry1", "scr_alien_disintegrate");
}

bool Veh::P2 = false;
void Veh::px2(bool toggle)
{
	WheelPTFX("scr_indep_fireworks", "scr_indep_firework_trailburst");
}
bool Veh::P3 = false;
void Veh::px3(bool toggle)
{
	WheelPTFX("scr_rcbarry1", "scr_alien_teleport");
}

bool Veh::P4 = false;
void Veh::px4(bool toggle)
{
	WheelPTFX("scr_rcbarry2", "scr_clown_appears");
}

bool Veh::P5 = false;
void Veh::px5(bool toggle)
{
	WheelPTFX("scr_agencyheistb", "scr_agency3b_elec_box");
}

bool Veh::P6 = false;
void Veh::px6(bool toggle)
{
	WheelPTFX("scr_rcbarry2", "scr_clown_death");
}

//Acrobatics

void Veh::Acro()
{
	Menu::Title("");
	Menu::SubTitle("Vehicle Acrobatics");
	//Menu::Break("Press it twice");
	if (Menu::Option("Kick Flip")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, 10.0f, 20.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
	}
	if (Menu::Option("Heel Flip")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, -2.0f, 0, 0, true, true, true, true, false, true);
	}
	if (Menu::Option("Back Flip")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, 2.0f, 0, true, true, true, true, false, true);
	}
	if (Menu::Option("Double Back Flip")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 12.0f, 0, 4.0f, 0, true, true, true, true, false, true);
	}
	if (Menu::Option("360")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 20.f, 0.0f, 20.f, 0.f, 0.f, 0, 1, 1, 1, 0, 1);
	}
	if (Menu::Option("Bunny Hop")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 7.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	if (Menu::Option("Launch Up")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	if (Menu::Option("Crush Vehicle")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -40.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	if (Menu::Option("Spinning Jump")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 20.f, 20.0f, 20.f, 0.f, 0.f, 0, 1, 1, 1, 0, 1);
	}
}

int reeekek() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}

bool Veh::TorqueMultiplier = false;
void Veh::torquemultiplier(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(playerVeh, Menu::Settings::torquevalue.r); 
	}
}

bool Veh::FrictionMultiplier = false;
void Veh::frictionmultiplier(bool toggle)
{
	Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
	VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(playerVeh, Menu::Settings::frictionvalue.r);
}

bool Veh::Suspention = false;
void Veh::suspention(bool toggle)
{
	Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
	VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(playerVeh, Menu::Settings::suspentionvalue.r);
}

bool Veh::PowerMultiplier = false;
void Veh::powermultiplier(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(playerVeh, Menu::Settings::powervalue.r); //done SET_VEHICLE_LIGHT_MULTIPLIER
	}
}


bool Veh::LightMultiplier = false;
void Veh::lightmultiplier(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
		VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(playerVeh, Menu::Settings::lightvalue.r); //done SET_VEHICLE_LIGHT_MULTIPLIER
	}
}


bool Veh::SuspentionMultiplier = false;
void Veh::suspentionmultiplier(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_SUSPENSION_HEIGHT }, Menu::Settings::powervalue.r);
	}
}


bool Veh::SuspentionMultiplier2 = false;
void Veh::suspentionmultiplier2(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE }, Menu::Settings::powervalue.r);
	}
}

bool Veh::SuspentionMultiplier3 = false;
void Veh::suspentionmultiplier3(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, 0x3DA }, Menu::Settings::powervalue.r);
	}
}


bool Veh::MassMultiplier = false;
void Veh::massmultiplier(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_MASS }, Menu::Settings::powervalue.r);
	}
}

bool Veh::BuoyancyMultiplier = false;
void Veh::buoyancymultiplier(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_BOUYANCY }, Menu::Settings::powervalue.r);
	}
}

bool WheelSizeBool = false;
void wheelsize()
{
	if (WheelSizeBool) {
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 0))
		{
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_WHEEL_SCALE_FRONT }, WheelSize);
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_WHEEL_SCALE_REAR }, WheelSize);
		}
	}
}



void Veh::Multi()
{
	Menu::Title("External Multipliers");
	Menu::SubTitle("External Vehcicle Stats Multiplier");
	if (Menu::Int("Acceleration", Menu::Settings::powervalue.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::powervalue.r = reeekek();
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_ACCELERATION }, Menu::Settings::powervalue.r);
		}
	}
	Menu::Toggle("Acceleration", Veh::PowerMultiplier);

	if (Menu::Int("Brake", Menu::Settings::torquevalue.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::torquevalue.r = reeekek();
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_BRAKEFORCE }, Menu::Settings::torquevalue.r);
		}
	}// set the override then the offsets 
	Menu::Toggle("Brake", Veh::TorqueMultiplier);  

	if (Menu::Int("Traction", Menu::Settings::frictionvalue.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::frictionvalue.r = reeekek();
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_VEHICLE , OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MAX }, Menu::Settings::frictionvalue.r);
		}
	}
	Menu::Toggle("Traction", Veh::FrictionMultiplier);

	if (Menu::Int("Camera", Menu::Settings::suspentionvalue.r, 1, 255))
	{

		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::suspentionvalue.r = reeekek();
			Memory::set_value<float>({ 0x8, 0xD30, 0x20, 0x38 }, Menu::Settings::suspentionvalue.r);
		}
	}
	Menu::Toggle("camera", Veh::Suspention);

	if (Menu::Int("Light", Menu::Settings::lightvalue.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::lightvalue.r = reeekek();
			
		}
	}
	Menu::Toggle("Light", Veh::LightMultiplier);



	if (Menu::Int("Suspention Heigh", Menu::Settings::Suspention.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::Suspention.r = reeekek();

		}
	}
	Menu::Toggle("Suspention Heigh", Veh::SuspentionMultiplier);

	if (Menu::Int("Suspention Force", Menu::Settings::Suspention2.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::Suspention2.r = reeekek();

		}
	}
	Menu::Toggle("Suspention Force", Veh::SuspentionMultiplier2);



	if (Menu::Int("Mass", Menu::Settings::Mass.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::Mass.r = reeekek();

		}
	}
	Menu::Toggle("Mass", Veh::MassMultiplier);


	if (Menu::Int("Buoyancy", Menu::Settings::Buoyancy.r, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::Buoyancy.r = reeekek();

		}
	}
	Menu::Toggle("Buoyancy", Veh::BuoyancyMultiplier);


	if (Menu::Float("Wheel Size", WheelSize, 1, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			WheelSize = reeekek();
		}
	}
	Menu::Toggle("Wheel Size", WheelSizeBool);
}

bool Veh::Boosttt = true;
int Veh::Boostttt = 30;
void Veh::Boostt()
{
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);

		if (Boosttt == true)
		{
			GRAPHICS::SET_TIMECYCLE_MODIFIER("RaceTurboLight");
		}
		else
		{
			GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		}

		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, Boostttt);
		}
		else
		{
			GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		}
	}
	else
	{
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
	}
}

