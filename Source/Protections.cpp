#include "stdafx.h"
#include "math.h"
#include "Protections.h"
#include "Network.h"

bool Protections::reccontrolblocc = false;


void Protections::RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void Protections::RequestControlOfid(DWORD netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 12)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void RequestControlOfidg(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

char* objects[139] = { "vw_prop_vw_colle_rsrgeneric", "apa_mp_apa_yacht", "apa_mp_apa_yacht_jacuzzi_ripple1", "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
bool Protections::Swap1 = false;

void Protections::UpdateLoop()
{
	Kick ? kick(true) : NULL;

	Crasherzz ? crasherzz(true) : NULL;

	ExplosionProtection ? explosionprotection(true) : NULL;


	AntiCrash ? anticrash(true) : NULL;

	RockstarCheck ? RockstarAdminCheck(true) : NULL;

	if (Crashh)
	{
		crashh();

		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
		for (int i = 0; i < 136; i++) {
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::PLAYER_PED_ID())) {
				RequestControlOfEnt(obj);
				int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
				Protections::RequestControlOfid(netID);
				ENTITY::DETACH_ENTITY(obj, 1, 1);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
					ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
					ENTITY::DELETE_ENTITY(&obj);
				}
			}
		}

		
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


}





void RequestControlOfgae(Entity netid) {
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25) {
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void Protections::MainMenu()
{
	Menu::Title("");
	Menu::SubTitle("Protections");
	Menu::MenuOption("Script Events", ne);
	Menu::MenuOption("Network Events", se);
	Menu::MenuOption("War Protection", warprotection);
	Menu::MenuOption("Attachments", a);
	Menu::Toggle("R* Admin Detection", Protections::RockstarCheck);
	
}

void Protections::nee()
{
	

}

void Protections::see()
{
	Menu::Title("");
	Menu::SubTitle("Script Events");
	Menu::Toggle("Block Suspicious Script Events", Protections::Kick);
	
	if (Menu::Settings::currentOption == 1) {/*Roupa Personalizada*/
		Menu::OptionInfo("Block Kicks, Infinite Loading, Ceo Bans etc");
	}
	if (Menu::Settings::currentOption == 1) {/*Roupa Personalizada*/
		Menu::OptionInfo("Block Kicks, Infinite Loading, Ceo Bans etc");
	}

}

void Protections::aa()
{
	Menu::Title("");
	Menu::SubTitle("Attachments");
	Menu::Toggle("Block Peds", cloneprotection);
	Menu::Toggle("Block Cars", Protections::Crash);
	//Menu::Toggle("Block Objects", Protections::Crashh);

	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Block Common Peds");
	}
	if (Menu::Settings::currentOption == 2) {
		Menu::OptionInfo("Block Common Cars");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Block Common Objects");
	}
}

int Admins[] = {
	133709045, 64234321, 131973478, 103019313, 103054099, 104041189, 110470958, 119266383, 119958356, 121397532, 121698158, 123839036, 123849404, 121943600, 129159629, 18965281, 216820, 56778561, 99453545, 99453882
};

bool Protections::RockstarCheck = false;
void Protections::RockstarAdminCheck(bool toggle)
{
	
	if (NETWORK::NETWORK_IS_SESSION_ACTIVE())
	{
		
		char* Admins1 = "133709045";
		char* Admins2 = "64234321";
		char* Admins3 = "131973478";
		char* Admins4 = "103019313";
		char* Admins5 = "103054099";
		char* Admins6 = "104041189";
		char* Admins7 = "110470958";
		char* Admins8 = "119266383";
		char* Admins9 = "119958356";
		char* Admins10 = "121397532";
		char* Admins11 = "121698158";
		char* Admins12 = "123839036";
		char* Admins13 = "123849404";
		char* Admins14 = "121943600";
		char* Admins15 = "129159629";
		char* Admins16 = "18965281";
		char* Admins17 = "216820";
		char* Admins18 = "56778561";
		char* Admins19 = "99453545";
		char* Admins20 = "99453882";


		for (int i = 0; i < 36; i++)
		{
			std::string rockstarID;
			int NETWORK_HANDLE[76];
			NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, NETWORK_HANDLE, 13);
			rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);

			if (rockstarID == Admins1)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins2)
			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins3)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins4)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins5)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins6)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins7)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins8)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins9)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins10)
			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins11)

			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins12)

			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins13)

			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins14)

			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins15)

			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins16)

			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins17)
			{
				notifyMap("R* admin detected.");
			}
			if (rockstarID == Admins18)

			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins19)
			{
				notifyMap("R* admin detected.");
			}

			if (rockstarID == Admins20)
			{
				notifyMap("R* admin detected.");
			}
			
		}
	}
	else
	{
		NULL;
	}
}

bool Protections::AntiCrash = false;
void Protections::anticrash(bool toggle) 
{
	Hash crashModelHashes[] = { 0xceea3f4b, 0x2592b5cf, 0x9cf21e0f, 0xc1ce1183, 0x49863e9c, 0xcd93a7db, 0x82cac433, 0x74f24de,  0x1c725a1,  0x81fb3ff0,
	0x79b41171, 0x781e451d, 0xa5e3d471, 0x6a27feb1, 0x861d914d, 0x8c049d17, 0xffba70aa, 0xe65ec0e4, 0xc3c00861, 0x5f5dd65c,
	0xc07792d4, 0x53cfe80a, 0xd9f4474c, 0xcb2acc8,  0xc6899cde, 0xd14b5ba3, 0x32a9996c, 0x69d4f974, 0xc2e75a21, 0x1075651,
	0xe1aeb708, 0xcbbb6c39, 0x6fa03a5e, 0xcf7a9a9d, 0x34315488, 0x45ef7804, 0xac3de147, 0xcafc1ec3, 0xd971bbae, 0xe764d794,
	0xf51f7309, 0x1e78c9d,  0xa49658fc, 0x4f2526da, 0x576ab4f6, 0xd20b1778, 0x54bc1cd8, 0xce109c5c, 0xe049c0ce, 0x78de93d1,
	0xe5b89d31, 0x5850e7b3, 0x6aed0e4b, 0xc50a4285, 0xb648a502, 0x5e497511, 0x47c14801, 0xfd8bb397, 0xef541728, 0xc2cc99d8,
	0x8fb233a4, 0x24e08e1f, 0x337b2b54, 0x7367d224, 0x919d9255, 0x4484243f, 0x3c91d42d, 0x3353525a, 0xc175f658, 0x762657c6,
	0x94ac15b3, 0x28014a56, 0xe0a8bfc9, 0x3a559c31, 0x5fc8a70,  0x3b545487, 0xb9402f87
	};

	Player player = PLAYER::PLAYER_ID();
	Vector3 coords = coordsOf(player);
	Ped clone;
	PED::GET_CLOSEST_PED(coords.x, coords.y, coords.z, 4.0, 0, 1, &clone, 0, 0, -1);
	if (ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(clone, PLAYER::PLAYER_PED_ID())) {
		RequestControlOfEnt(clone);
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(clone);
		Protections::RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		ENTITY::DETACH_ENTITY(clone, 1, 1);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, 1, 1);
		ENTITY::DELETE_ENTITY(&clone);
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&clone);
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z - 1000, 0, 0, 0, 1);
	}

	for each (Hash h in crashModelHashes) {
		if (OBJECT::IS_OBJECT_NEAR_POINT(h, coords.x, coords.y, coords.z, 2.0f)) {
			Object a = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 2.0f, h, false, true, true);
			RequestControlOfEnt(a);
			int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(a);
			Protections::RequestControlOfid(netID);
			NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
			ENTITY::DETACH_ENTITY(a, 1, 1);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, 1, 1);
			ENTITY::DELETE_ENTITY(&a);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&a);
			ENTITY::SET_ENTITY_COORDS(player, coords.x, coords.y, coords.z - 1000, 0, 0, 0, 1);
		}
	}
}



bool Protections::Crash = false;
void Protections::crash()
{
	if (Crash == true)
	{
		Hash crashModelHashes[] = 
		{ 
			0x856cfb02
		};
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		
		Player player = PLAYER::PLAYER_ID();
		Vector3 coordss = coordsOf(player);
		Ped clone;
		GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
		PED::GET_CLOSEST_PED(coords.x, coords.y, coords.z, 4.0, 0, 1, &clone, 0, 0, -1);
		if (ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(clone, PLAYER::PLAYER_PED_ID())) {
			RequestControlOfEnt(clone);
			int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(clone);
			RequestControlOfgae(netID);
			NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
			ENTITY::DETACH_ENTITY(clone, 1, 1);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, 1, 1);
			ENTITY::DELETE_ENTITY(&clone);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&clone);
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z - 1000, 0, 0, 0, 1);
		}

		for each(Hash h in crashModelHashes)
		{
			if (OBJECT::IS_OBJECT_NEAR_POINT(h, coords.x, coords.y, coords.z, 2.0f)) {
				Object a = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 2.0f, h, false, true, true);
				RequestControlOfEnt(a);
				int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(a);
				RequestControlOfgae(netID);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
				ENTITY::DETACH_ENTITY(a, 1, 1);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, 1, 1);
				ENTITY::DELETE_ENTITY(&a);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&a);
				ENTITY::SET_ENTITY_COORDS(player, coords.x, coords.y, coords.z - 1000, 0, 0, 0, 1);
			}
		}
	}
	else if (Crash == false)
	{

	}
	else
	{

	}

	
}

std::vector<Hash> crashhh = {
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


bool Protections::Crashh = false;
void Protections::crashh()
{
	if (Crashh == true)
	{

		
		Foxy_Engine::defuseEvent(REQUEST_DETACHMENT_EVENT, true);
		char* objects[136] = { "prop_juicestand", "prop_weed_01", "p_v_43_safe_s", "p_spinning_anus_s", "prop_ld_toilet_01", "prop_xmas_tree_int", "prop_windmill_01","slod_large_quadped","slod_small_quadped", };
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
		for (int i = 0; i < 7; i++) {
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::PLAYER_PED_ID()))
			{
				RequestControlOfEnt(obj);
				int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
				RequestControlOfidg(netID);
				ENTITY::DETACH_ENTITY(obj, 1, 1);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj))
				{
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
					ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
					ENTITY::DELETE_ENTITY(&obj);
				}
			}
		}
	}
	else if (Crashh == false)
	{

	}
	else
	{

	}


}

bool Protections::Crasherzz = false;
void Protections::crasherzz(bool toggle)
{// crash me 

}

bool Protections::ExplosionProtection = false;
void Protections::explosionprotection(bool toggle)
{// explode me 

}

//bool ExplosionProtection = false;

bool Protections::Kick = false;
void Protections::kick(bool toggle)
{
	globalHandle(1386431).At(591).As<int>() = 591; //Freemode
	globalHandle(1386431).At(506).As<int>() = 506; //Freemode
	globalHandle(1386431).At(33).As<int>() = 33; //Freemode
	globalHandle(1386431).At(63).As<int>() = 63; //Freemode

	globalHandle(1386431).At(506).As<int>() = 506; //Infinite Loading

	globalHandle(1386431).At(33).As<int>() = 33; //Sound Spam
	globalHandle(1377446).At(594).As<int>() = 594;
	globalHandle(1377446).At(595).As<int>() = 595;
	globalHandle(1382674).At(594).As<int>() = 594;
	globalHandle(1382674).At(499).As<int>() = 499;
	globalHandle(1382674).At(295).As<int>() = 295;
	globalHandle(1382674).At(16).As<int>() = 16;
	globalHandle(1382674).At(21).As<int>() = 21;
	globalHandle(1382674).At(677).As<int>() = 677;
	globalHandle(1382674).At(601).As<int>() = 601;
	globalHandle(1382674).At(23).As<int>() = 23;
	globalHandle(1382674).At(24).As<int>() = 24;
	globalHandle(1377446).At(594).As<int>() = 594;
	globalHandle(1377446).At(595).As<int>() = 595;
	globalHandle(1377446).At(594).As<int>() = 594; //SP kick
	globalHandle(1377446).At(595).As<int>() = 595; //kick
	globalHandle(1382674).At(584).As<int>() = 584; //new nonhost kick?
	globalHandle(1382674).At(610).As<int>() = 610; //new sp kick?
	globalHandle(1382674).At(610).As<int>() = 610; //SP kick
	globalHandle(1382674).At(609).As<int>() = 609; //kick
	globalHandle(1382674).At(295).As<int>() = 295; //Mission
	globalHandle(1382674).At(350).As<int>() = 350; //Transaction
	globalHandle(1382674).At(0).As<int>() = 0; //notification, money msg, banner
	globalHandle(1382674).At(61).As<int>() = 61; //gentle kick from car
	globalHandle(1382674).At(584).As<int>() = 584; //new nonhost kick
	globalHandle(1382674).At(2).As<int>() = 2; //rotate camera
	globalHandle(1382674).At(16).As<int>() = 16;
	globalHandle(1382674).At(21).As<int>() = 21;
	globalHandle(1382674).At(677).As<int>() = 677;
	globalHandle(1382674).At(601).As<int>() = 601;
	globalHandle(1382674).At(23).As<int>() = 23;
	globalHandle(1382674).At(24).As<int>() = 24;
	globalHandle(1382674).At(651).As<int>() = 651;
	globalHandle(1382674).At(582).As<int>() = 582;
	globalHandle(1382674).At(584).As<int>() = 584;
	globalHandle(1382674).At(532).As<int>() = 532;
	globalHandle(1382674).At(688).As<int>() = 688;
	globalHandle(1382674).At(455).As<int>() = 455;

	globalHandle(1382674).At(23).As<int>() = 23;

	globalHandle(1382674).At(23).As<int>() = 23;
	globalHandle(1382674).At(532).As<int>() = 532;
	globalHandle(1377446).At(523).As<int>() = 523;
	globalHandle(1377446).At(545).As<int>() = 545;
	globalHandle(1382674).At(536).As<int>() = 536; //ceo kick
	globalHandle(1382674).At(558).As<int>() = 558; //ceo ban
	globalHandle(1382674).At(532).As<int>() = 532; //ceo kick 2
	globalHandle(1382674).At(532).As<int>() = 532;
	
	
}







/*__int64 crashHook(unsigned int model, DWORD* a2)
{
	if (g_running) {
		if ((model == joaat("slod_human")) && m_protect_ped_crash) {
			return false;
			model = 0xE6CB661E;
			return false;
			map_notification("CHAR_BLOCKED", "<C>Protection</C>", "Ped", "Crash");
			return false;
		}
		if ((model == joaat("sold_large_quadpad") || model == GAMEPLAY::GET_HASH_KEY("sold_small_quadpad")) && m_protect_ped_crash) {
			return false;
			model = 0xE6CB661E;
			return false;
			map_notification("CHAR_BLOCKED", "<C>Protection</C>", "Quad Ped", "Crash");
			return false;
		}
		if ((model == joaat("a_c_hampback")) && m_protect_whale_crash) {
			return false;
			model = 0xE6CB661E;
			return false;
			map_notification("CHAR_BLOCKED", "<C>Protection</C>", "Whale", "Crash");
			return false;
		}
		if ((model == joaat("a_f_o_indian_01")) && m_protect_curry_crash) {
			return false;
			model = 0xE6CB661E;
			return false;
			map_notification("CHAR_BLOCKED", "<C>Protection</C>", "curry", "Crash");
			return false;
		}
		return Oghook(model, a2);
	}
	return false;
	//return Oghook(hash, unused);
}


std::vector<Hash> crash_objects = {
	0x3f039cba, 0x856cfb02, 0x2d7030f3
};
ecrash Oghook;
__int64 crashHook(Hash hash, DWORD* unused)
{
	if (Hooking::crash_protection)
	{
		if (crash_objects.find(hash) != crash_objects.end())
		{
			return false;
			char buf[255];
			sprintf(buf, "Crash object blocked, Hash: %s", hash);
			notifyMap(buf, true);
			return false;
		}
	}
	return Oghook(hash, unused);



	if (ImGui::Button("Crash", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
					{
						g_fiber_pool->queue_job([=]
						{
							std::int32_t ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
							g_pointers->m_remove_weapon(ped, -0000000000);
							g_pointers->m_remove_weapon(ped, -000000000001);
							g_pointers->m_remove_weapon(ped, -0xFFFFFFFFFFFFFF);
							g_pointers->m_remove_weapon(ped, 0);

							Any _events_f[12] = { -988842806, selectedPlayer, -72614, 63007, 59027, -12012, -26996, 33398, 33398, 63007, -72614, 59027 };// crash event
							g_pointers->m_Trigger_Script_Event(1, _events_f, 12, 1 << selectedPlayer);

							Any _events_fs[4] = { -1320260596, selectedPlayer, -1330780407, 479 };// crash event
							g_pointers->m_Trigger_Script_Event(1, _events_fs, 4, 1 << selectedPlayer);

							Any _events_a[46] = { -2043109205, selectedPlayer, -2147483647, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534 };
							Any _events_p[46] = { -988842806, selectedPlayer, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534,65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, -2147483647, 65534, 65534, 65534, -2147483647 };
							Any _events_c[46] = { 153488394, selectedPlayer, -2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -877212109, -601625146 };
							Any _events_g[46] = { -988842806, selectedPlayer, 868904806, 262276366, -747991709, 1545080914, -51510646, 1790326295, 389113600, -617567498, -601391132, -564503258, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550, -601625146 - 2043109205, -989654618, -988842806, -1881357102, 153488394, 1249026189, 1033875141, 315658550 };

							g_pointers->m_Trigger_Script_Event(1, _events_g, 46, 1 << selectedPlayer);
							g_pointers->m_Trigger_Script_Event(1, _events_a, 46, 1 << selectedPlayer);
							g_pointers->m_Trigger_Script_Event(1, _events_p, 46, 1 << selectedPlayer);
							g_pointers->m_Trigger_Script_Event(1, _events_c, 46, 1 << selectedPlayer);
						});
					}
					pointer.add("RPW", "48 89 5C 24 ? 57 48 83 EC 20 8B FA E8 ? ? ? ? 33 DB", [this](memory::handle ptr) {
			m_remove_weapon = ptr.as<functions::remove_weapon>();
		});




			if (Menu::Float("Move X", AODMoveX1, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODMoveX1 = NumberKeyboard();
				}
			}

			if (Menu::Float("Move Y", AODMoveY1, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODMoveY1 = NumberKeyboard();
				}
			}
			if (Menu::Float("Move Z", AODMoveZ1, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODMoveZ1 = NumberKeyboard();
				}
			}

			if (Menu::Float("Move Pitch", AODpitch1, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODpitch1 = NumberKeyboard();
				}
			}
			if (Menu::Float("Move Roll", AODroll1, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODroll1 = NumberKeyboard();
				}
			}

			if (Menu::Float("Move Yaw", AODyaw1, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODyaw1 = NumberKeyboard();
				}
			}


			if (Menu::Float("Move X 2", AODMoveX2, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODMoveX2 = NumberKeyboard();
				}
			}

			if (Menu::Float("Move Y 2", AODMoveY2, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODMoveY2 = NumberKeyboard();
				}
			}
			if (Menu::Float("Move Z 2", AODMoveZ2, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODMoveZ2 = NumberKeyboard();
				}
			}

			if (Menu::Float("Move Pitch 2", AODpitch2, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODpitch2 = NumberKeyboard();
				}
			}
			if (Menu::Float("Move Roll 2", AODroll2, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODroll2 = NumberKeyboard();
				}
			}

			if (Menu::Float("Move Yaw 2", AODyaw2, 0.01f, 360.f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					AODyaw2 = NumberKeyboard();
				}
			}


			Kick 1 = 1964309656
Kick 2 = 696123127
Kick 3 = 43922647
Kick 4 = 600486780
Kick 5 = 1954846099
Kick 6 = 153488394
Kick 7 = 1249026189
Kick 8 = 515799090
Kick 9 = 1463355688
Kick 10 = -1382676328
Kick 11 = 1256866538
Kick 12 = 515799090
Kick 13 = -1813981910
Kick 14 = 202252150
Kick 15 = -19131151
Kick 16 = -635501849
Kick 17 = 1964309656
Crash 1 = -988842806
Crash 2 = -2043109205
Crash 3 = 1926582096
Crash 4 = 153488394
Script host crash 1 = 315658550
Script host crash 2 = -877212109
Disown personal vehicle = -2072214082
Vehicle EMP = 975723848
Destroy personal vehicle = 1229338575
Kick out of vehicle = -1005623606
Remove wanted level = 1187364773
Give OTR or ghost organization = -397188359
Block passive = 1472357458
Send to mission = -1147284669
Send to Perico island = -1479371259
Apartment invite = 1249026189
CEO ban = 1355230914
Dismiss or terminate from CEO = -316948135
Insurance notification = 299217086
Transaction error = -2041535807
CEO money = 1152266822
Bounty = -1906146218
Banner = 1659915470
Sound 1 = 1537221257
Sound 2 = -1162153263
Bribe authorities = -151720011
Single Player kick = 2092565704



}*/