#include "stdafx.h"
#include "Other.h"
#include "natives.h"
#include <ShlObj.h>
#include <fstream>
#include <filesystem>



bool cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}

void Other::ResetAppearance()
{
	PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
	PED::CLEAR_PED_DECORATIONS(PLAYER::PLAYER_PED_ID());
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, 0, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, 0, 0, 0);
}

int fam;
void Other::changeAppearance(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), fam, model - 1, texture, 1);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), fam, model, texture, 0);
	}
}

#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())

void Other::spawn_vehicle(char* toSpawn) {
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
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

void Other::CagePlayer(Ped ped)
{
	Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(ped, 0);
	Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
}

Vector3 TPCoords;
void Other::TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
        CAM::DO_SCREEN_FADE_OUT(15);
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
        CAM::DO_SCREEN_FADE_IN(15);
	}//
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}


const std::vector<std::string> vValues_ModSlotNames
{
	"CMOD_MOD_SPO",
	"CMOD_BUM_1",
	"CMOD_BUM_4",
	"CMOD_MOD_SKI",
	"CMOD_MOD_MUF",
	"CMOD_MOD_CHA",
	"CMOD_MOD_GRL",
	"CMOD_MOD_HOD",
	"CMOD_MOD_FEN",
	"CMOD_MOD_FEN",
	"CMOD_MOD_ROF",
	"CMOD_MOD_ENG",
	"CMOD_MOD_BRA",
	"CMOD_MOD_TRN",
	"CMOD_MOD_HRN",
	"CMOD_MOD_SUS",
	"CMOD_MOD_ARM",
	"Unknown 17",
	"CMOD_MOD_TUR",
	"Unknown 19",
	"Tyre Smoke",
	"Unknown 21",
	"CMOD_MOD_LGT",
	"CMOD_MOD_WHEM",
	"CMOD_WHE0_1",
	"CMM_MOD_S0",//"Plateholder",
	"CMM_MOD_S1",//"Vanity Plate",
	"CMM_MOD_S2",//"Trim Design",
	"CMM_MOD_S3",//"Ornament",
	"CMM_MOD_S4",//"Dash",
	"CMM_MOD_S5",//"Dial Design",
	"CMM_MOD_S6",//"Doorcards",
	"CMM_MOD_S7",//"Leather Seats",
	"CMM_MOD_S8",//"Steering Wheel",
	"CMM_MOD_S9",//"Column Shifter Lever",
	"CMM_MOD_S10",//"Plaque",
	"CMM_MOD_S11",//"Speakers",
	"CMM_MOD_S12",//"Trunk",
	"CMM_MOD_S13",//"Hydraulics",
	"CMM_MOD_S14",//"Engine Block",
	"CMM_MOD_S15",//"Air Filter",
	"CMM_MOD_S16",//"Struts",
	"CMM_MOD_S17",//"Arch Cover",
	"CMM_MOD_S18",//"Aerials",
	"CMM_MOD_S19",//"Trim",
	"CMM_MOD_S20",//"Tank",
	"CMM_MOD_S21",//"Windows",
	"CMM_MOD_S22",//"Unknown 47",
	"CMM_MOD_S23",//"Livery",
};

void Other::set_vehicle_max_upgrades(Vehicle vehicle, bool upgradeIt, bool invincible, INT8 plateType, std::string plateText,
	bool neonIt, UINT8 NeonR, UINT8 NeonG, UINT8 NeonB, INT16 prim_col_index, INT16 sec_col_index)
{
	bool null;
	int inull;
	if (!ENTITY::DOES_ENTITY_EXIST(vehicle) || !ENTITY::IS_ENTITY_A_VEHICLE(vehicle))
		return;

	int i;
	Vector3& Pos = ENTITY::GET_ENTITY_COORDS(vehicle, 1);

	//GTAvehicle(vehicle).RequestControl();

	if (VEHICLE::GET_VEHICLE_MOD_KIT(vehicle) != 0)
		VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);


	if (plateText.length() > 0)
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, (PCHAR)plateText.c_str());

	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehicle, plateType);


	if (upgradeIt) // upgrade
	{
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 18, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 20, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 22, 1);

		for (i = 0; i < vValues_ModSlotNames.size(); i++)
		{
			if (i >= 17 && i <= 22)
				continue;
			UINT8 modIndex = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1;
			if (i == VehicleMod::Horns)
				modIndex = 44;
			VEHICLE::SET_VEHICLE_MOD(vehicle, i, modIndex, 0);
		}
		VEHICLE::SET_VEHICLE_WINDOW_TINT(vehicle, 1);
	}

	if (neonIt) // neons
	{
		for (i = 0; i <= 3; i++)
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, i, TRUE);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, NeonR, NeonG, NeonB);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, NeonR, NeonG, NeonB);
	}

	WAIT(50);

	if (prim_col_index != -3) // basic paint primary
	{
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle);
		VEHICLE::GET_VEHICLE_COLOURS(vehicle, &i, &inull);
		VEHICLE::SET_VEHICLE_COLOURS(vehicle, prim_col_index, inull);
	}
	if (sec_col_index != -3) // basic paint secondary
	{
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle);
		VEHICLE::GET_VEHICLE_COLOURS(vehicle, &inull, &i);
		VEHICLE::SET_VEHICLE_COLOURS(vehicle, inull, sec_col_index);
	}

	WAIT(40);

}







/*
else {
                    Foxy_Engine::defuseEvent(GIVE_CONTROL_EVENT, true);
                }

else
                {
                   Foxy_Engine::defuseEvent(REQUEST_PICKUP_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GAME_CLOCK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GAME_WEATHER_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GIVE_WEAPON_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOVE_WEAPON_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(FIRE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_PTFX_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GAME_CLOCK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GAME_WEATHER_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(SCRIPT_ARRAY_DATA_VERIFY_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GIVE_CONTROL_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(WEAPON_DAMAGE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REQUEST_PICKUP_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REQUEST_MAP_PICKUP_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GAME_CLOCK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GAME_WEATHER_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(RESPAWN_PLAYER_PED_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GIVE_WEAPON_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(SCRIPTED_GAME_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(FIRE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(START_PROJECTILE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(ALTER_WANTED_LEVEL_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(CHANGE_RADIO_STATION_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(PLAYER_TAUNT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(PLAYER_CARD_STAT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(DOOR_BREAK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(SCRIPTED_GAME_EVENT, true);
                }

                 else//s                 tart
                 {
                R   ain_Engine::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(MARK_AS_NO_LONGER_NEEDED_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(CONVERT_TO_SCRIPT_ENTITY_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(SCRIPT_WORLD_STATE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(INCIDENT_ENTITY_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(CLEAR_AREA_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_STOP_SYNCED_SCENE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_START_PED_ARREST_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_START_PED_UNCUFF_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_ENTITY_AREA_STATUS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_GARAGE_OCCUPIED_STATUS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(PED_CONVERSATION_LINE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_PLAY_SOUND_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_BANK_REQUEST_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REQUEST_DOOR_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_TRAIN_REPORT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REQUEST_DETACHMENT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(GIVE_PICKUP_REWARDS_EVENT, true);
                }

                 else
                 {
                R   ain_Engine::defuseEvent(NETWORK_CRC_HASH_CHECK_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_RESPONDED_TO_THREAT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_SHOUT_TARGET_POSITION, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(PICKUP_DESTROYED_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(UPDATE_PLAYER_SCARS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_CHECK_EXE_SIZE_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_PTFX_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_PED_SEEN_DEAD_PED_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOVE_STICKY_BOMB_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_CHECK_CODE_CRCS_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(PED_PLAY_PAIN_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(CACHE_PLAYER_HEAD_BLEND_DATA_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REMOVE_PED_FROM_PEDGROUP_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REPORT_MYSELF_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
                }

                else
                {
                   Foxy_Engine::defuseEvent(NETWORK_CHECK_CATALOG_CRC, true);
                }


                if ()
                {
                    Foxy_Engine::defuseEvent(GIVE_CONTROL_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_PICKUP_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GAME_CLOCK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GAME_WEATHER_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GIVE_WEAPON_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOVE_WEAPON_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(FIRE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_PTFX_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GAME_CLOCK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GAME_WEATHER_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(SCRIPT_ARRAY_DATA_VERIFY_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_CONTROL_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GIVE_CONTROL_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(WEAPON_DAMAGE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_PICKUP_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_MAP_PICKUP_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GAME_CLOCK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GAME_WEATHER_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(RESPAWN_PLAYER_PED_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GIVE_WEAPON_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(SCRIPTED_GAME_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(FIRE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(START_PROJECTILE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(ALTER_WANTED_LEVEL_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(CHANGE_RADIO_STATION_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(PLAYER_TAUNT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(PLAYER_CARD_STAT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(DOOR_BREAK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(SCRIPTED_GAME_EVENT, true);
                }

                 if ()//s                 tart
                 {
                R   ain_Engine::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(MARK_AS_NO_LONGER_NEEDED_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(CONVERT_TO_SCRIPT_ENTITY_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(SCRIPT_WORLD_STATE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(INCIDENT_ENTITY_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(CLEAR_AREA_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_STOP_SYNCED_SCENE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_START_PED_ARREST_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_START_PED_UNCUFF_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_ENTITY_AREA_STATUS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_GARAGE_OCCUPIED_STATUS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(PED_CONVERSATION_LINE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_PLAY_SOUND_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_BANK_REQUEST_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_DOOR_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(EXPLOSION_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_TRAIN_REPORT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REQUEST_DETACHMENT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(KICK_VOTES_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(GIVE_PICKUP_REWARDS_EVENT, true);
                }

                 if ()
                 {
                R   ain_Engine::defuseEvent(NETWORK_CRC_HASH_CHECK_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_RESPONDED_TO_THREAT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_SHOUT_TARGET_POSITION, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(PICKUP_DESTROYED_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(UPDATE_PLAYER_SCARS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_CHECK_EXE_SIZE_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_PTFX_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_PED_SEEN_DEAD_PED_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOVE_STICKY_BOMB_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_CHECK_CODE_CRCS_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(PED_PLAY_PAIN_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(CACHE_PLAYER_HEAD_BLEND_DATA_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REMOVE_PED_FROM_PEDGROUP_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REPORT_MYSELF_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
                }

                if ()
                {
                   Foxy_Engine::defuseEvent(NETWORK_CHECK_CATALOG_CRC, true);
                }



*/