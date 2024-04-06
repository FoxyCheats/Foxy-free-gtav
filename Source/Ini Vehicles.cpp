#include "stdafx.h"
#include "Ini Function.h"
#include "Ini Vehicles.h"
#include <filesystem>

/*
#ifndef __has_include
static_assert(false, "__has_include not supported");
#else
#  if __cplusplus >= 201703L && __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#  endif
#endif*/

#pragma pack(push, 1)
typedef struct
{
	float X, Y, Z, RotX, RotY, RotZ;
	Hash hash;
} ObjectInfo;
#pragma pack(pop)

int inipos = 0;
std::vector<char*> ini1 =
{
	"###ZCUFO Flying",
	"###ZCUFO Flying",
	"##AAA_True_Ghostrider",
	"##AIRBORNE ZENTORNO",
	"##Airship",
	"##Destroyer",
	"##German Tank",
	"##German Tank2",
	"##Military TANK TRANSPORT",
	"##MOBILE WINDMILL",
	"##SCOOPER",
	"##Secret Military Robot #1",
	"##Secret Military Robot #2",
	"##TANK MAN",
	"##TugBoat Speeder",
	"##TURISMO BEAST",
	"##Unknown",
	"##ZENTORNO HUNTER",
	"##Zentoro Extra Engine",
	"$#0SubmarineCargoPlaneRocket",
	"$$%^&&##0",
	"$%^&#0CleanerRampCar",
	"[AIR] AIRBORN ZENTORNO (Medusa Menu)",
	"[AIR] Airborne Zentorno",
	"[AIR] ATOMIC FROGGER (Medusa Menu)",
	"[AIR] Atomic Frogger",
	"[AIR] Bucket Heli",
	"[AIR] Cargo Plane Aqua",
	"[AIR] Cargo Plane WIth Ramp",
	"[AIR] Hydra UFO",
	"[AIR] Radar Skylift",
	"[AIR] Radar Titan",
	"[AIR] Sky Rex",
	"[AIR] Super Jumbo Jet",
	"[AIR] Super Marquis",
	"[AIR] Trippy Blimp",
	"[AIR] Weaponized Cargo Plane",
	"[BAD ASS] Adder",
	"[BAD ASS] Bulldozer",
	"[BAD ASS] Coach",
	"[BAD ASS] Coast Gaurd",
	"[BAD ASS] Copper",
	"[BAD ASS] Jester",
	"[BAD ASS] Limo",
	"[BAD ASS] Marshall",
	"[BAD ASS] Osirus",
	"[BAD ASS] Progen T20",
	"[BAD ASS] Ruiner",
	"[BAD ASS] Sultan",
	"[BAD ASS] Truck",
	"[BAD ASS] Turismo",
	"[BIKES] Bati-Arcade",
	"[BIKES] Hakuchou Shotaro",
	"[BIKES] Insane Tron",
	"[BIKES] True Ghostrider",
	"[COPS] FIB Undercover SUV",
	"[COPS] Kalahari Police",
	"[COPS] Patrol Car",
	"[COPS] Police Aqua",
	"[COPS] Undercover Cop",
	"[COPS]Police Tractor",
	"[EXTREME] Camper",
	"[EXTREME] Police",
	"[EXTREME] Rocket Voltic",
	"[FUN] Boat",
	"[FUN] Cart",
	"[FUN] Quad",
	"[FUN] Ramp Truck",
	"[GANJA] Dubsta 6x6",
	"[GANJA] Mini",
	"[GANJA] Police",
	"[GANJA] Stoned Ranger",
	"[GANJA] Truck",
	"[HYBRIDS] Alien Mesa",
	"[HYBRIDS] Aqua Primo",
	"[HYBRIDS] Catapult Truck",
	"[HYBRIDS] Crane Dump Truck",
	"[HYBRIDS] Crazy Insurgent Windmills",
	"[HYBRIDS] Crazy Tank Windmills",
	"[HYBRIDS] Crusher Bus",
	"[HYBRIDS] Crusher Tank",
	"[HYBRIDS] Dragon Radar",
	"[HYBRIDS] Duke O Death Truck",
	"[HYBRIDS] EMP Truck",
	"[HYBRIDS] Feltuma",
	"[HYBRIDS] FMJ Reaper",
	"[HYBRIDS] JB700 Aqua",
	"[HYBRIDS] JetSki Sanchez",
	"[HYBRIDS] Lazer Marshall",
	"[HYBRIDS] ManMan",
	"[HYBRIDS] Multimedia Moonbeam",
	"[HYBRIDS] NSA Truck",
	"[HYBRIDS] Power Truck",
	"[HYBRIDS] Rhapsody Banshee",
	"[HYBRIDS] RV Dubsta",
	"[HYBRIDS] Savage Marshall",
	"[HYBRIDS] Shotaro Hakuchou",
	"[HYBRIDS] Space Truck",
	"[HYBRIDS] Space Wastelander",
	"[HYBRIDS] Space Zentorno",
	"[HYBRIDS] Sub Buzzard",
	"[HYBRIDS] Tank Marshall",
	"[HYBRIDS] Tank O Bob",
	"[HYBRIDS] Train Marshall",
	"[HYBRIDS] Turismo Beast",
	"[HYBRIDS] Ultimate Workstation",
	"[HYBRIDS] Zentorno Hunter",
	"[MILITARY] Artillery Barracks",
	"[MILITARY] Artillery Guardian",
	"[MILITARY] Assault Bifta",
	"[MILITARY] Assault Buggy",
	"[MILITARY] Bomb Tug",
	"[MILITARY] Combat Crusader",
	"[MILITARY] Heavy Insurgent",
	"[MILITARY] High Voltage Insurgent",
	"[MILITARY] Hydra Tank",
	"[MILITARY] Jeep Transport",
	"[MILITARY] Mesa Scout",
	"[MILITARY] Missile Rebel",
	"[MILITARY] Tank Transport",
	"[OFF-ROAD] CRUSHER",
	"[OFF-ROAD] Grave Digger",
	"[OFF-ROAD] Monster Ambulance",
	"[OFF-ROAD] Monster Transporter",
	"[OFF-ROAD] Panto",
	"[OFF-ROAD] Rolls Royce",
	"[RANDOM] Cheetah Covered",
	"[RANDOM] Coffin Hotrod",
	"[RANDOM] Crazy Tank Windmills",
	"[RANDOM] Drunk Burritos",
	"[RANDOM] Dynamite Fishing",
	"[RANDOM] FIRE ENGINE",
	"[RANDOM] HotDog Blazer",
	"[RANDOM] Multimedia Moonbeam",
	"[RANDOM] NSA Truck",
	"[RANDOM] Nuke",
	"[RANDOM] Radar Skylift",
	"[RANDOM] Radar Titan",
	"[RANDOM] Smoke Van",
	"[RANDOM] Toy Car",
	"[RANDOM] Ultimate Workstation",
	"[RANDOM]CargoPlaneTower",
	"[RANDOM]Scooper",
	"[RANDOM]Street Jet",
	"[RIOT] Bike",
	"[RIOT] Bus",
	"[RIOT] Buzzard",
	"[RIOT] Pickup",
	"[RIOT] Tank",
	"[RIOT] Trevor",
	"[ROCKET] Blazer Aqua",
	"[ROCKET] Bus",
	"[ROCKET] BusV2",
	"[ROCKET] Dubsta 6x6",
	"[ROCKET] Nero",
	"[ROCKET] Tempesta",
	"[ROCKET] Wedge",
	"[SUPER HYBRID] Man Man",
	"[SUPER HYBRID] Power Truck",
	"[TOXIC] Bifta",
	"[TOXIC] Cargo Bob",
	"[TOXIC] Dinghy",
	"[TOXIC] Kalahari",
	"[TOXIC] Marshall",
	"[UH] Arcade Rider",
	"[UH] Big Beta Robot",
	"[UH] BigBot ManMan",
	"[UH] Camper Extreme",
	"[UH] Christmas Joy",
	"[UH] Cops Patrol Car",
	"[UH] Crane Dump",
	"[UH] Crane Slow",
	"[UH] Crusher Bus",
	"[UH] Disco Golfcart",
	"[UH] Dragon Radar",
	"[UH] Fying Airship Yacht",
	"[UH] Ghostrider",
	"[UH] HydraMarshall",
	"[UH] InsurgentMonster",
	"[UH] Monster Duke O Death",
	"[UH] Police Boat",
	"[UH] Police Buss",
	"[UH] Radar Titan",
	"[UH] Ramp Dump Truck",
	"[WATER] Lifeguard Dinghy",
	"[WATER] Sea Quad",
	"[WTF] The Bus",
	"[WTF] The Machine",
	"[WTF] The Robot",
	"[XMAS] Bati",
	"[XMAS] Big Truck",
	"[XMAS] Christmas Joy",
	"[XMAS] Franken-Stange",
	"[XMAS] Frogger",
	"[XMAS] Mesa",
	"[XMAS] Small Truck",
	"[XMAS] Zentorno",
	"_C50K1_ AirStunts 2.0",
	"_C50K1_ AirStunts",
	"_C50K1_ BetaRobot",
	"_C50K1_ BlackMonster 2.0",
	"_C50K1_ BlackMonster",
	"_C50K1_ BmxTrash",
	"_C50K1_ Circle",
	"_C50K1_ CleanerRampCar",
	"_C50K1_ CraneFast",
	"_C50K1_ CraneSlow",
	"_C50K1_ Delorean 2.0",
	"_C50K1_ Delorean",
	"_C50K1_ Export",
	"_C50K1_ FlyCarrier 2.0",
	"_C50K1_ FlyCarrier",
	"_C50K1_ FlyMountChiliad",
	"_C50K1_ FlyYacht 2.0",
	"_C50K1_ FlyYacht",
	"_C50K1_ InsurgentMonster 2.0",
	"_C50K1_ InsurgentMonster",
	"_C50K1_ KenBlock",
	"_C50K1_ KeyWest2014",
	"_C50K1_ KeyWest2014Prop",
	"_C50K1_ LOGO 2",
	"_C50K1_ LOGO",
	"_C50K1_ MadMaxVehicles 6.6.6",
	"_C50K1_ MadMaxVehicles OLD",
	"_C50K1_ MadMaxVehicles",
	"_C50K1_ MassiveRoadCleaner",
	"_C50K1_ PimpCar",
	"_C50K1_ RoadCleaner",
	"_C50K1_ RocketbusJordan",
	"_C50K1_ RocketTrailer",
	"_C50K1_ RuinerTrash",
	"_C50K1_ Something",
	"_C50K1_ SubmarineCargoPlane",
	"_C50K1_ SubmarineCargoPlaneRocket",
	"_C50K1_ Supermoto",
	"_C50K1_ TheWeedloader",
	"_C50K1_ TugCarrier",
	"_C50K1_ TugYacht",
	"_C50K1_ TuningPhantom",
	"_C50K1_ TuningPhantomWedge",
	"_C50K1_ TuningPorsche",
	"_C50K1_ TurboPhantom",
	"_C50K1_ TurboPhantomWedge",
	"_C50K1_ UFO",
	"_C50K1_ WeedWorkTrack",
	"_C50K1_ WeedWorktrack2",
	"_C50K1_ WeedWorkTrailer",
	"~g~420 Planedra",
	"~o~FlyCarrier 2.0",
	"~o~Mayve FlyYacht",
	"~p~BIGBOT APC WaterBot  ",
	"~p~FLY BacktoTheFuture Deluxo  ",
	"~p~FutureX80",
	"~p~FutureZentorno",
	"~p~ROBOT-SYXAPUK",
	"~p~SubmarineCargoPlane",
	"~r~Life Invader Vader",
	"~r~Overpowered RoadCleaner",
	"BIKE Airport Express",
	"BIKE Bushcycle",
	"BIKE JoshuaTrain",
	"bike",
	"Bike1-fsx",
	"C5K01 - Rocket Submarine",
	"C5K01 - Scorpion",
	"C5K01 - WeedMan",
	"C50K1 - Back to the Future",
	"C50K1 - Boating Botanical",
	"C50K1 - CleanerRamp",
	"C50K1 - Cops icles",
	"C50K1 - Crazy Insurgent",
	"C50K1 - Discoverer",
	"C50K1 - Flying Carrier",
	"C50K1 - Flying Mine",
	"C50K1 - Flying Star",
	"C50K1 - Flying Yacht",
	"C50K1 - Speaker Up ",
	"C50K1 - XmasAdder",
	"C50K1__FullSpeakerTuning",
	"C50K1__FutureX80",
	"C50K1__PredatorMinigun",
	"C50K1__ROBOT-SYXAPUK",
	"CARGOPLANEparking",
	"CARGOPLANEparkingbyChrisObjex",
	"CargoPlaneTowerByEinar",
	"CargoPlaneWIthRamp",
	"Carnical Truck 1",
	"Carnical Truck 2",
	"CARNIVAL PLANE (byChrisObjex)",
	"CARNIVAL PLANE",
	"CARNIVAL TRUCK 1 (byChrisObjex)",
	"CARNIVAL TRUCK 1",
	"CARNIVAL TRUCK 2 (byChrisObjex)",
	"CARNIVAL TRUCK 2",
	"CARNIVAL TRUCK 3 (byChrisObjex)",
	"CARNIVAL TRUCK 3",
	"CARNIVALPLANE",
	"CARNIVALTRUCK",
	"CARNIVALTRUCK2",
	"CARNIVALTRUCK3",
	"FLOWER CAR (byChrisObjex)",
	"FLOWER CAR (Medusa Menu)",
	"FLOWER CAR",
	"FLOWER STRETCH (byChrisObjeX)",
	"FLOWER STRETCH (Medusa Menu)",
	"FLOWER STRETCH",
	"FLOWER ZENTORNO (byChris0bjeX)",
	"FLOWER ZENTORNO (Medusa Menu)",
	"FLOWER ZENTORNO",
	"FLOWERCAR",
	"FLOWERSTRETCH",
	"FLOWERSTRETCHbyChrisObjeX",
	"FLOWERZENTORNO",
	"FLOWERZENTORNObyChris0bjeX",
	"FLY 420 Hydra",
	"FLY 420 Hydra - By JamezModz",
	"FLY BacktoTheFuture Deluxo  ",
	"FLY BacktoTheFuture Deluxo - By JamezModz",
	"FLY BigAssBlimp  ",
	"FLY BigAssBlimp - By JamezModz",
	"FLY BigAssBlimp",
	"FLY FlightGTA 101",
	"FLY FlightGTA 101 - By JamezModz",
	"FLY FlightGTA 101",
	"FLY Hitler Deluxo - By JamezModz",
	"FLY House Plane  ",
	"FLY House Plane - By JamezModz",
	"FLY House Plane ",
	"Fly House Plane",
	"FLY Letz Go Bowling  ",
	"FLY Letz Go Bowling - By JamezModz",
	"FLY Letz Go Bowling",
	"FLY Mr HappyHeli",
	"FLY Mr HappyJet",
	"FLY Mr. HappyHeli",
	"FLY Mr. HappyHeli - By JamezModz",
	"FLY Mr. HappyJet",
	"FLY Mr. HappyJet - By JamezModz",
	"FLY PassMeMyCrayons  ",
	"FLY PassMeMyCrayons - By JamezModz",
	"FLY PassMeMyCrayons",
	"FLY SavageTire",
	"FLY SavageTire - By JamezModz",
	"FLY SavageTire",
	"FLY Subcopter",
	"FLY Subcopter - By JamezModz",
	"FLY Subcopter",
	"FLY TiredBlimp",
	"FLY TiredBlimp - By JamezModz",
	"FLY TiredBlimp",
	"FLY UFO v2.0",
	"FLY UFO v2.0 - By JamezModz",
	"FLY UFO",
};

void Ini::IniMenu()
{
	Menu::Title("");
	Menu::SubTitle("Modded Vehicles");
	if (Menu::ListVector("Ini Vehicles", ini1, inipos))
		Ini::LoadPreset(ini1[inipos]);
	//for (const auto& entry : fs::directory_iterator(path))
}


std::vector<std::string> listFiles(LPCSTR directory)
{
	std::vector<std::string> tempVector;
	int fileCount = 0;
	std::stringstream tempStringStream;
	/*for (auto & collectedFiles : std::experimental::filesystem::v1::directory_iterator(directory)) {
		tempStringStream << collectedFiles;
		std::string testing = tempStringStream.str();
		if (testing.substr(testing.find_last_of(".") + 1) == "mp3") {
			unsigned foundAmount = testing.find_last_of("/");
			std::string TempHolder = testing.substr(0, foundAmount);
			std::string TempHolder2 = testing.substr(foundAmount + 1);
			tempVector.push_back(TempHolder2.substr(0, TempHolder2.find(".", 0)));
		}
	}*/
	return tempVector;
}
std::string FloatToString(float flt) {
	std::ostringstream ss;
	ss << flt;
	std::string str(ss.str());
	return str;
}

float StringToFloat(std::string str) {
	return ::atof(str.c_str());
}
Vehicle SpawnVehicleH(DWORD model, Vector3 coords, bool tpinto = 0, float heading = 0.0f) {
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::erstelle_fahr(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		if (tpinto) {
			ENTITY::SET_ENTITY_HEADING(veh, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}
std::vector<int> ToggleTypes = { 17, 18, 19, 20, 21, 22 };
std::vector<int> ModTypes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 23, 24, 26, 25, 48, 37, 27, 28, 30, 33, 34, 35, 38, 39, 45 };
std::vector<Object> Spawned;
void printf(std::string f) {
	printf(f.c_str());
}
Object AttachObjectToVehicleByHash(Hash hash, float x, float y, float z, float rotx, float roty, float rotz, Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) {
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
		//CMenu::notifyBottom("~r~You need to be in a vehicle to load a preset !");
		return -1;
	}
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		Vector3 co = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(hash, co.x, co.y, co.z, 1, 0, 0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(obj);
		ENTITY::FREEZE_ENTITY_POSITION(obj, 1);
		printf("Calling");
		ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, veh, 0, x, y, z, rotx, roty, rotz, 1, 0, 1, 0, 2, 1);
		WAIT(25);
		return obj;
	}
	else {
		printf("Not in image");
		return -1;
	}
}
bool DoesFileExists(std::string path) {
	if (std::ifstream(path)) return true;
	return false;
}
void WriteVehicle(std::string name, Vehicle veh) {
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini";
	for (int i = 0; i < ModTypes.size(); i++) {
		WritePrivateProfileStringA("Vehicle", FloatToString(ModTypes[i]).c_str(), FloatToString(VEHICLE::GET_VEHICLE_MOD(veh, ModTypes[i])).c_str(), iniPath.c_str());
	}
	int HUDColour, HUDLightsColour;
	//VEHICLE::_GET_INTERIOR_DASH_LIGHT_COLOR(veh, &HUDLightsColour);
	//VEHICLE::_GET_INTERIOR_COATING_COLOR(veh, &HUDColour);
	WritePrivateProfileStringA("Vehicle", "DashColor", FloatToString(HUDColour).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "DashLightColor", FloatToString(HUDLightsColour).c_str(), iniPath.c_str());
	int PpaintType = 0;
	int Pcolor = 0;
	int SpaintType = 0;
	int Scolor = 0;
	int Sr, Sg, Sb, Pr, Pg, Pb;
	int Prnd;
	int pearlescent, wheelColor;
	int wheelType = VEHICLE::GET_VEHICLE_WHEEL_TYPE(veh);
	int PlateIndex = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh);
	char* PlateText = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT(veh);
	bool Bulletproof = !VEHICLE::GET_VEHICLE_TYRES_CAN_BURST(veh);
	bool CustomTyres = VEHICLE::GET_VEHICLE_MOD_VARIATION(veh, 23);
	WritePrivateProfileStringA("Vehicle", "Bulletproof", FloatToString(Bulletproof).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "CustomTyres", FloatToString(CustomTyres).c_str(), iniPath.c_str());
	int NeonR, NeonG, NeonB, SmokeR, SmokeG, SmokeB;
	bool NeonEnabled;
	VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(veh, &NeonR, &NeonG, &NeonB);
	VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &SmokeR, &SmokeG, &SmokeB);
	if (VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0)) NeonEnabled = 1;
	for (int i = 0; i < ToggleTypes.size(); i++) {
		WritePrivateProfileStringA("Vehicle", std::string("TOGGLE_" + FloatToString(ToggleTypes[i])).c_str(), FloatToString(VEHICLE::IS_TOGGLE_MOD_ON(veh, ToggleTypes[i])).c_str(), iniPath.c_str());
	}
	int WindowTintIndex = VEHICLE::GET_VEHICLE_WINDOW_TINT(veh);
	WritePrivateProfileStringA("Vehicle", "NeonEnabled", FloatToString(NeonEnabled).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "NeonR", FloatToString(NeonR).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "NeonG", FloatToString(NeonG).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "NeonB", FloatToString(NeonB).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SmokeR", FloatToString(SmokeR).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SmokeG", FloatToString(SmokeG).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SmokeB", FloatToString(SmokeB).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "WindowTint", FloatToString(WindowTintIndex).c_str(), iniPath.c_str());
	VEHICLE::GET_VEHICLE_MOD_COLOR_1(veh, &PpaintType, &Pcolor, &Prnd);
	VEHICLE::GET_VEHICLE_MOD_COLOR_2(veh, &SpaintType, &Scolor);
	VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &Pr, &Pg, &Pb);
	VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &Sr, &Sg, &Sb);
	VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescent, &wheelColor);
	std::ostringstream os; os << ENTITY::GET_ENTITY_MODEL(veh);
	WritePrivateProfileStringA("Vehicle", "Model", os.str().c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryPaintT", FloatToString(PpaintType).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryPaintT", FloatToString(SpaintType).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryPaint", FloatToString(Pcolor).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryPaint", FloatToString(Scolor).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "Pearlescent", FloatToString(pearlescent).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryR", FloatToString(Pr).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryG", FloatToString(Pg).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryB", FloatToString(Pb).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryR", FloatToString(Sr).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryG", FloatToString(Sg).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryB", FloatToString(Sb).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "WheelsColor", FloatToString(wheelColor).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "WheelsType", FloatToString(wheelType).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "Unknown", FloatToString(Prnd).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "Unknown", FloatToString(PlateIndex).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PlateText", PlateText, iniPath.c_str());
	for (int i = 0; i < 10; i++) {
		if (VEHICLE::DOES_EXTRA_EXIST(veh, i)) {
			WritePrivateProfileStringA("Vehicle", std::string("Extra_" + FloatToString(i)).c_str(), FloatToString(VEHICLE::IS_VEHICLE_EXTRA_TURNED_ON(veh, i)).c_str(), iniPath.c_str());
		}
	}
}

void WritePreset(std::string name, float id, float x, float y, float z, float rotx, float roty, float rotz, Hash model) {
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini"; //change path
	if (!std::ifstream(iniPath)) std::ofstream file(iniPath);
	if (DoesFileExists(iniPath)) {
		return;
	}
	std::string X = FloatToString(x);
	std::string Y = FloatToString(y);
	std::string Z = FloatToString(z);
	std::string RotX = FloatToString(rotx);
	std::string RotY = FloatToString(roty);
	std::string RotZ = FloatToString(rotz);
	std::string Model = FloatToString(model);
	std::string Id = FloatToString(id);
	WritePrivateProfileStringA(Id.c_str(), "X", X.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "Y", Y.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "Z", Z.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "RotX", RotX.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "RotY", RotY.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "RotZ", RotZ.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "Model", Model.c_str(), iniPath.c_str());
}
void SavePreset(std::vector<ObjectInfo> ObjectList, std::string name, bool bWriteVehicle = 0) {
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini"; //change path
	if (bWriteVehicle) WriteVehicle(name, PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
	for (int i = 0; i < ObjectList.size(); i++) {
		std::ostringstream os;
		os << ObjectList[i].hash;
		ObjectList[i].X = round(ObjectList[i].X * 10000) / 10000;
		ObjectList[i].Y = round(ObjectList[i].Y * 10000) / 10000;
		ObjectList[i].Z = round(ObjectList[i].Z * 10000) / 10000;
		ObjectList[i].RotX = round(ObjectList[i].RotX * 10000) / 10000;
		ObjectList[i].RotY = round(ObjectList[i].RotY * 10000) / 10000;
		ObjectList[i].RotZ = round(ObjectList[i].RotZ * 10000) / 10000;
		WritePrivateProfileStringA(FloatToString(i).c_str(), "X", FloatToString(ObjectList[i].X).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "Y", FloatToString(ObjectList[i].Y).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "Z", FloatToString(ObjectList[i].Z).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "RotX", FloatToString(ObjectList[i].RotX).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "RotY", FloatToString(ObjectList[i].RotY).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "RotZ", FloatToString(ObjectList[i].RotZ).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "Model", os.str().c_str(), iniPath.c_str());
		printf("\r\n<SAVE # " + FloatToString(i) + " > \r\n");
		printf("\r\nName:" + name);
		printf("\r\X:" + FloatToString(ObjectList[i].X));
		printf("\r\nY:" + FloatToString(ObjectList[i].Y));
		printf("\r\nZ:" + FloatToString(ObjectList[i].Z));
		printf("\r\nRotX:" + FloatToString(ObjectList[i].RotX));
		printf("\r\nRotY:" + FloatToString(ObjectList[i].RotY));
		printf("\r\nRotZ:" + FloatToString(ObjectList[i].RotZ));
		printf("\r\n< END OF SAVE # " + FloatToString(i) + " > \r\n");
	}
	//CMenu::notifyBottom("Preset Saved !");
}
std::string ReadPresetKey(std::string name, std::string section, std::string key) {
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini";
	if (!std::ifstream(iniPath)) {
		std::ofstream file(iniPath);
	}
	char retVal[255];
	GetPrivateProfileStringA(section.c_str(), key.c_str(), "", retVal, 255, iniPath.c_str());
	return retVal;
}
bool DoesPresetKeyExists(std::string name, std::string section, std::string key) {
	return ReadPresetKey(name, section, key).length() > 0;
}
int GetNumberOfObjectFromFile(std::string name) {
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini";
	int no = 0;
	for (int i = 0; i < 150; i++) {
		if (DoesPresetKeyExists(name, FloatToString(i), "X")) {
			no++;
		}
		else {
			return no;
		}
	}
	return no;
}
DWORD StringToDWORD(std::string str) {
	DWORD doubleWord;
	std::string dwordHexString = str;
	std::stringstream dwordStream;
	dwordStream << dwordHexString;
	dwordStream >> std::hex >> doubleWord;
	return doubleWord;
}
int st(std::string txt) { return atoi(txt.c_str()); }
Vehicle LoadVehicle(std::string name) {
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini";
	if (DoesPresetKeyExists(name, "Vehicle", "Model")) {
		Hash Model = static_cast<DWORD>(atoll(ReadPresetKey(name, "Vehicle", "Model").c_str()));
		Vehicle veh = SpawnVehicleH(Model, ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0, 5, 0), 1);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		int WheelsType;
		WheelsType = st(ReadPresetKey(name, "Vehicle", "WheelsType"));
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, WheelsType);
		bool CustomTyres = st(ReadPresetKey(name, "Vehicle", "CustomTyres"));
		for (int i = 0; i < ModTypes.size(); i++) {
			int mod = st(ReadPresetKey(name, "Vehicle", FloatToString(ModTypes[i])));
			VEHICLE::SET_VEHICLE_MOD(veh, ModTypes[i], mod, CustomTyres);
		}
		int HUDColor = st(ReadPresetKey(name, "Vehicle", "DashColor"));
		int HUDLightsColor = st(ReadPresetKey(name, "Vehicle", "DashLightColor"));
		TEST::_SET_INTERIOR_DASH_LIGHT_COLOR(veh, HUDLightsColor);
		TEST::_SET_INTERIOR_COATING_COLOR(veh, HUDColor);
		std::string PlateText;
		int NeonR, NeonG, NeonB, SmokeR, SmokeG, SmokeB, BulletProof;
		bool NeonEnabled;
		for (int i = 0; i < ToggleTypes.size(); i++) {
			int mod = st(ReadPresetKey(name, "Vehicle", std::string("TOGGLE_" + FloatToString(ToggleTypes[i])).c_str()));

			VEHICLE::TOGGLE_VEHICLE_MOD(veh, ToggleTypes[i], mod);
		}
		int WindowTintIndex = st(ReadPresetKey(name, "Vehicle", "WindowTint"));
		NeonEnabled = st(ReadPresetKey(name, "Vehicle", "NeonEnabled"));
		NeonR = st(ReadPresetKey(name, "Vehicle", "NeonR"));
		NeonG = st(ReadPresetKey(name, "Vehicle", "NeonG"));
		NeonB = st(ReadPresetKey(name, "Vehicle", "NeonB"));
		SmokeR = st(ReadPresetKey(name, "Vehicle", "SmokeR"));
		SmokeG = st(ReadPresetKey(name, "Vehicle", "SmokeG"));
		SmokeB = st(ReadPresetKey(name, "Vehicle", "SmokeB"));
		BulletProof = st(ReadPresetKey(name, "Vehicle", "Bulletproof"));
		if (BulletProof == 1) {
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
		}
		if (NeonEnabled) {
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, NeonR, NeonG, NeonB);
		}
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, WindowTintIndex);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, SmokeR, SmokeG, SmokeB);
		int PrimaryPaintType, SecondaryPaintType, PrimaryPaintID, SecondaryPaintID, Pearlescent, PrimaryR, PrimaryG, PrimaryB, SecondaryR, SecondaryG, SecondaryB, WheelsColor, Unknown, PlateIndex;
		PrimaryPaintType = st(ReadPresetKey(name, "Vehicle", "PrimaryPaintT"));
		SecondaryPaintType = st(ReadPresetKey(name, "Vehicle", "SecondaryPaintT"));
		PrimaryPaintID = st(ReadPresetKey(name, "Vehicle", "PrimaryPaint"));
		SecondaryPaintID = st(ReadPresetKey(name, "Vehicle", "SecondaryPaint"));
		Pearlescent = st(ReadPresetKey(name, "Vehicle", "Pearlescent"));
		PrimaryR = st(ReadPresetKey(name, "Vehicle", "PrimaryR"));
		PrimaryG = st(ReadPresetKey(name, "Vehicle", "PrimaryG"));
		PrimaryB = st(ReadPresetKey(name, "Vehicle", "PrimaryB"));
		SecondaryR = st(ReadPresetKey(name, "Vehicle", "SecondaryR"));
		SecondaryG = st(ReadPresetKey(name, "Vehicle", "SecondaryG"));
		SecondaryB = st(ReadPresetKey(name, "Vehicle", "SecondaryB"));
		WheelsColor = st(ReadPresetKey(name, "Vehicle", "WheelsColor"));
		Unknown = st(ReadPresetKey(name, "Vehicle", "Unknown"));
		PlateIndex = st(ReadPresetKey(name, "Vehicle", "PlateIndex"));
		PlateText = ReadPresetKey(name, "Vehicle", "PlateText");
		VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, PrimaryPaintType, PrimaryPaintID, Unknown);
		VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, SecondaryPaintType, SecondaryPaintID);
		VEHICLE::SET_VEHICLE_COLOURS(veh, PrimaryPaintID, SecondaryPaintID);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, Pearlescent, WheelsColor);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, PrimaryR, PrimaryG, PrimaryB);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SecondaryR, SecondaryG, SecondaryB);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, PlateIndex);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, (char*)PlateText.c_str());
		//CMenu::notifyBottom("~g~Successfully loaded vehicle. !");
		for (int i = 0; i < 10; i++) {
			if (VEHICLE::DOES_EXTRA_EXIST(veh, i)) {
				int ExtraToggle = st(ReadPresetKey(name, "Vehicle", "Extra_" + FloatToString(i)));
				if (ExtraToggle == 1) {
					VEHICLE::SET_VEHICLE_EXTRA(veh, i, 0);
				}
				else {
					VEHICLE::SET_VEHICLE_EXTRA(veh, i, -1);
				}
			}
		}
		return veh;
	}
	return -1;
}

ObjectInfo ReadCustomPreset(std::string name, int id) {
	ObjectInfo oi;
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + name + ".ini";
	std::ostringstream ID; ID << id;
	oi.hash = static_cast<DWORD>(atoll(ReadPresetKey(name, ID.str(), "Model").c_str()));
	oi.X = StringToFloat((char*)ReadPresetKey(name, ID.str(), "X").c_str());
	oi.Y = StringToFloat((char*)ReadPresetKey(name, ID.str(), "Y").c_str());
	oi.Z = StringToFloat((char*)ReadPresetKey(name, ID.str(), "Z").c_str());
	oi.RotX = StringToFloat((char*)ReadPresetKey(name, ID.str(), "RotX").c_str());
	oi.RotY = StringToFloat((char*)ReadPresetKey(name, ID.str(), "RotY").c_str());
	oi.RotZ = StringToFloat((char*)ReadPresetKey(name, ID.str(), "RotZ").c_str());
	return oi;
}

std::vector<std::string> listPresets(LPCSTR directory)
{
	std::vector<std::string> tempVector;
	int fileCount = 0;
	std::stringstream tempStringStream;
	/*for (auto& collectedFiles : fs::directory_iterator(directory)) {
		tempStringStream << collectedFiles;
		std::string testing = tempStringStream.str();
		if (testing.substr(testing.find_last_of(".") + 1) == "ini") {
			unsigned foundAmount = testing.find_last_of("/\\");
			std::string TempHolder = testing.substr(0, foundAmount);
			std::string TempHolder2 = testing.substr(foundAmount + 1);
			tempVector.push_back(TempHolder2.substr(0, TempHolder2.find(".", 0)));
		}
	}
	return tempVector;*/
}


void Ini::LoadPreset(std::string name) {
	Vehicle veh = LoadVehicle(name);
	for (int i = 0; i < GetNumberOfObjectFromFile(name); i++) {
		if (veh != -1) {
			ObjectInfo preset = ReadCustomPreset(name, i);
			Object ob = AttachObjectToVehicleByHash(preset.hash, preset.X, preset.Y, preset.Z, preset.RotX, preset.RotY, preset.RotZ, veh);
			Spawned.push_back(ob);
		}
		else {
			if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
				//CMenu::notifyBottom("You need to be in a vehicle to do this"); return;
			}
			ObjectInfo preset = ReadCustomPreset(name, i);
			Object ob = AttachObjectToVehicleByHash(preset.hash, preset.X, preset.Y, preset.Z, preset.RotX, preset.RotY, preset.RotZ);
			Spawned.push_back(ob);
		}
	}
}





