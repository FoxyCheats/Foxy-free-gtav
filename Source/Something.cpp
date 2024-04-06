#include "stdafx.h"
#include "Something.h"

bool Reee::spawnincar = false;
bool Reee::vehSpawnFade = false;
bool Reee::spawnmaxed = false;
bool Reee::skyplane = false;
bool Reee::Vehinfo = false;
bool Reee::spbypass = false;
bool Reee::GiftVehicle = false;
bool Reee::SetGodMode = false;
bool Reee::RandomModdedColor = false;
bool Reee::LicensePlate = false;

Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
void Reee::TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}//
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())

void Reee::BypassOnlineVehicleKick(Vehicle vehicle)
{
	if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle) || NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(vehicle))
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehicle);
		int netid = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(vehicle);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
	}
	DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
	int networkId = NETWORK::VEH_TO_NET(vehicle);
	if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(vehicle))
	{
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
	}
}


void Reee::spawn_vehicle(char* toSpawn) {
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

void Reee::SpawnVehicle(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)); // i don't need it want to see ?
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

		if (Reee::SetGodMode)
		{
			PLAYER::SET_PLAYER_INVINCIBLE(veh, true);
		}
		if (Reee::spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		if (Reee::vehSpawnFade) {
			NETWORK::NETWORK_FADE_IN_ENTITY(veh, 1);
		}
		if (Reee::spawnmaxed)
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
		if (Reee::spbypass) {
			globalHandle(0x41183A).As<BOOL>() = 1;
			globalHandle(4267883).As<BOOL>() = 1;
			globalHandle(4266905).As<BOOL>() = 1;
			globalHandle(4268190).As<BOOL>() = 1;
			globalHandle(4270934).As<BOOL>() = 1;
			globalHandle(4540731).As<BOOL>() = 1;
			globalHandle(0x9090).As<BOOL>() = 1;
		}
		else {
			globalHandle(0x41183A).As<BOOL>() = 0;
			globalHandle(4267883).As<BOOL>() = 0;
			globalHandle(4266905).As<BOOL>() = 0;
			globalHandle(4268190).As<BOOL>() = 0;
			globalHandle(4270934).As<BOOL>() = 0;
			globalHandle(4540731).As<BOOL>() = 0;
			globalHandle(0x9090).As<BOOL>() = 0;
		}
		if (Reee::skyplane) {
			if (VEHICLE::IS_THIS_MODEL_A_PLANE(model)) {
				VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
				WAIT(600);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 200.0);
				VEHICLE::CONTROL_LANDING_GEAR(veh, 0);
			}
		}
		
	    if (Reee::GiftVehicle)
		{
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(playerPed);
			int hashplayer = NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(playerPed);
			DECORATOR::DECOR_SET_INT(veh, "Player_Vehicle", hashplayer);
		}
		if (Reee::LicensePlate) {
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Foxy");
		}
		if (RandomModdedColor) {
			int perle = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 153);
			int wheel = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 153);
			int primaryc, secondaryc = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 153);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &perle, &wheel);;
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 135, wheel);
			VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
			VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryc, &secondaryc);
			VEHICLE::SET_VEHICLE_COLOURS(veh, primaryc, secondaryc);
		}
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

char* ItoS222(int num)
{
	char buf[30];
	_snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}



void Reee::previewmodelchanger(char* modelname) {
	static Ped model;
	static int timer;

	if (modelname == NULL) {
		ENTITY::DELETE_ENTITY(&model);
		goto skipTick; // you don't need the wait

	}
	Hash hash = GAMEPLAY::GET_HASH_KEY(modelname);
	Ped Player = PLAYER::PLAYER_PED_ID();

	float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
	if (STREAMING::IS_MODEL_VALID(hash))
	{
		if (ENTITY::GET_ENTITY_MODEL(model) == hash) {
			float heading = ENTITY::GET_ENTITY_HEADING(model);

			Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, 0, 4.0f, 0.5f);
			ENTITY::SET_ENTITY_COORDS(model, Coords.x, Coords.y, Coords.z, false, false, false, false);

			ENTITY::SET_ENTITY_HEADING(model, heading >= 360.f ? 0 : heading + 0.5f);
			ENTITY::SET_ENTITY_COLLISION(model, false, false);
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(model);

			goto skipTick;
		}
		else {
			ENTITY::DELETE_ENTITY(&model);
		}


		STREAMING::REQUEST_MODEL(hash);
		if (!STREAMING::HAS_MODEL_LOADED(hash)) goto skipTick;
		Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, 0, 4.0f, 0.5f);
		model = PED::CREATE_PED(26 ,hash, Coords.x, Coords.y, Coords.z, heading, true, true);
		ENTITY::SET_ENTITY_COLLISION(model, false, false);
		ENTITY::SET_ENTITY_ALPHA(model, 150, 0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
	}
	else {
		ENTITY::DELETE_ENTITY(&model);
	}

skipTick:;
}



void Reee::previewCar(char* carname) {
	static Vehicle Veh;
	static int timer;

	if (carname == NULL) {
		ENTITY::DELETE_ENTITY(&Veh);
		goto skipTick; // you don't need the wait

	}
	Hash hash = GAMEPLAY::GET_HASH_KEY(carname);
	Ped Player = PLAYER::PLAYER_PED_ID();

	drawvehicle(carname);

	/*	int scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE((char*)"mp_car_stats_01");
		if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(scaleform));
		{
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)carname);
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)carname);
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)carname);
			GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(scaleform, (char*)"SET_VEHICLE_INFOR_AND_STATS");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Top Speed");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Acceleration");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Braking");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Traction");
			GRAPHICS::DRAW_SCALEFORM_MOVIE(scaleform, Menu::Settings::menuX + 0.245f, 0.18 - 0.2000f, 0.907f, 0.919f, 255, 255, 255, 255, 0);

		}


		
		int scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE((char*)"mp_car_stats_01");
		if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(scaleform));
		{
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)carname);
			GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(scaleform, (char*)"SET_VEHICLE_INFOR_AND_STATS");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)carname);
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Vehicle Stat Menu");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"MPCarHUD");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)carname);
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Top Speed");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Acceleration");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Braking");
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING((char*)"Traction");


			float vehiclemaxspeed = VEHICLE::_GET_VEHICLE_MODEL_MAX_SPEED(GAMEPLAY::GET_HASH_KEY((char*)Veh));
			float vehicleacceleration = VEHICLE::GET_VEHICLE_MODEL_ACCELERATION(GAMEPLAY::GET_HASH_KEY((char*)Veh)) * 100;
			float vehiclehandbrake = VEHICLE::_GET_VEHICLE_MODEL_HAND_BRAKE(GAMEPLAY::GET_HASH_KEY((char*)Veh)) * 100;
			float vehiclemaxtraction = VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION(GAMEPLAY::GET_HASH_KEY((char*)Veh)) * 100 / 10;

			int vehiclemaxspeed1 = static_cast<int>(vehiclemaxspeed);
			int vehicleacceleration1 = static_cast<int>(vehicleacceleration);
			int vehiclehandbrake1 = static_cast<int>(vehiclehandbrake);
			int vehiclemaxtraction1 = static_cast<int>(vehiclemaxtraction);

			//GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemaxspeed1);
		//	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehicleacceleration1);
			//GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclehandbrake1);
			//GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemaxtraction1);

			GRAPHICS::DRAW_SCALEFORM_MOVIE(scaleform, Menu::Settings::menuX + 0.245f, 0.18 - 0.2000f, 0.907f, 0.919f, 255, 255, 255, 255, 0);

		}
*/
	float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
	if (STREAMING::IS_MODEL_VALID(hash))
	{
		if (ENTITY::GET_ENTITY_MODEL(Veh) == hash) {
			float heading = ENTITY::GET_ENTITY_HEADING(Veh);

			Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, 0, 4.0f, 0.5f);
			ENTITY::SET_ENTITY_COORDS(Veh, Coords.x, Coords.y, Coords.z, false, false, false, false);

			ENTITY::SET_ENTITY_HEADING(Veh, heading >= 360.f ? 0 : heading + 0.5f);
			ENTITY::SET_ENTITY_COLLISION(Veh, false, false);
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(Veh);

			goto skipTick;
		}
		else {
			ENTITY::DELETE_ENTITY(&Veh);
		}


		STREAMING::REQUEST_MODEL(hash);
		if (!STREAMING::HAS_MODEL_LOADED(hash)) goto skipTick;

		Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, 0, 4.0f, 0.5f);


		Veh = VEHICLE::CREATE_VEHICLE(hash, Coords.x, Coords.y, Coords.z, heading, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(Veh);
		ENTITY::SET_ENTITY_COLLISION(Veh, false, false);
		ENTITY::SET_ENTITY_ALPHA(Veh, 150, 0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		if (Reee::Vehinfo) {
			int  Gethash, GetSpeed, GetAcce, GetBrake, GetTrac;
			Gethash = GAMEPLAY::GET_HASH_KEY(carname);
			std::string Vehhash = (std::string)"Hash: " + ItoS222(Gethash);
			Menu::AddSmallInfo((char*)Vehhash.c_str(), 1);

			GetSpeed = VEHICLE::_GET_VEHICLE_MODEL_MAX_SPEED(hash);
			std::string Vehspeed = (std::string)"Max Speed: " + ItoS222(GetSpeed);
			Menu::AddSmallInfo((char*)Vehspeed.c_str(), 2);

			GetAcce = VEHICLE::GET_VEHICLE_MODEL_ACCELERATION(hash);
			std::string Vehacce = (std::string)"Acceleration: " + ItoS222(GetAcce);
			Menu::AddSmallInfo((char*)Vehacce.c_str(), 3);

			GetBrake = VEHICLE::_GET_VEHICLE_MODEL_HAND_BRAKE(hash);
			std::string Vehbrake = (std::string)"Brake: " + ItoS222(GetBrake);
			Menu::AddSmallInfo((char*)Vehbrake.c_str(), 4);

			GetTrac = VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION(hash);
			std::string Vehtrac = (std::string)"Traction: " + ItoS222(GetTrac);
			Menu::AddSmallInfo((char*)Vehtrac.c_str(), 5);

			drawvehicle(carname);
		}
	}
	else {
		ENTITY::DELETE_ENTITY(&Veh);
	}

skipTick:;
	if (Reee::Vehinfo) {
		int  Gethash, GetSpeed, GetAcce, GetBrake, GetTrac;
		Gethash = GAMEPLAY::GET_HASH_KEY(carname);
		std::string Vehhash = (std::string)"Hash: " + ItoS222(Gethash);
		Menu::AddSmallInfo((char*)Vehhash.c_str(), 1);

		GetSpeed = VEHICLE::_GET_VEHICLE_MODEL_MAX_SPEED(hash);
		std::string Vehspeed = (std::string)"Max Speed: " + ItoS222(GetSpeed);
		Menu::AddSmallInfo((char*)Vehspeed.c_str(), 2);

		GetAcce = VEHICLE::GET_VEHICLE_MODEL_ACCELERATION(hash);
		std::string Vehacce = (std::string)"Acceleration: " + ItoS222(GetAcce);
		Menu::AddSmallInfo((char*)Vehacce.c_str(), 3);

		GetBrake = VEHICLE::_GET_VEHICLE_MODEL_HAND_BRAKE(hash);
		std::string Vehbrake = (std::string)"Brake: " + ItoS222(GetBrake);
		Menu::AddSmallInfo((char*)Vehbrake.c_str(), 4);

		GetTrac = VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION(hash);
		std::string Vehtrac = (std::string)"Traction: " + ItoS222(GetTrac);
		Menu::AddSmallInfo((char*)Vehtrac.c_str(), 5);
		drawvehicle(carname);
	}

}

Object mapMods[250];
int mapModsIndex = 0;
void Reee::PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(hash, x, y, z, 1, 0, 0);
		//SET_ENTITY_HEADING(obj, heading);
		//SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 2, 1);
		ENTITY::SET_ENTITY_LOD_DIST(obj, 696969);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(obj);
		ENTITY::FREEZE_ENTITY_POSITION(obj, 1);
		ENTITY::SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 0, 1);
		mapMods[mapModsIndex] = obj;
		if (mapModsIndex <= 250) mapModsIndex++;
		WAIT(25);
	}
}




void Reee::GiftVehicle2(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	int hashplayer = NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(selectedPlayer);
	if (STREAMING::IS_MODEL_VALID(model))	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(player, FALSE);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, Coords.x, Coords.y, Coords.z, heading, true, true);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		DECORATOR::DECOR_SET_INT(veh, "Player_Vehicle", hashplayer);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 0);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 0, 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}





