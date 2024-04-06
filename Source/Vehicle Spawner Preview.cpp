#include "stdafx.h"
#include "Vehicle Spawner Preview.h"
#include "Something.h"


int pearlescentColor, wheelColor;

typedef int vehicle1234;

using namespace Menu;
using namespace Reee;

#define Addoption      Menu::Option
#define Addtitle       Menu::Title
#define Addsubtitle    Menu::SubTitle
#define addint         Menu::Int
#define Addint         Menu::AInt
#define Addsub         Menu::MenuOption
#define Addbool        Menu::Toggle

void Spawner::UpdateLoop() {

	if (Spawner::Neon)
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 4, 1); 	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 5, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 6, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 7, 1);
	}
	else
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 4, 0); 	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 5, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 6, 0); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 7, 0);
	}
	if (Spawner::nopooptries)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 1);
	}
	else
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
	}
	if (Spawner::Turbobo)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
	}
	else
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 0);
	}
	if (Spawner::Lightt)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
	}
	else
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 0);
	}

	hasXenon ? ToggleXenon(true) : NULL;

}

bool Spawner::hasXenon = true;
bool Spawner::hasNeons = true;
void Spawner::ToggleXenon(int VehID)
{
	if (hasXenon)
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 0);
		hasXenon = false;
	}
	else
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 1);
		hasXenon = true;
	}
}

void Spawner::MercenariespinSpawnergift()
{
	Menu::Title("");
	Menu::SubTitle("Mercenaries");

	if (Settings::currentOption == 1) {
		previewCar("AVENGER3");
	}
	if (Settings::currentOption == 2) {
		previewCar("BRIGHAM");
	}
	if (Settings::currentOption == 3) {
		previewCar("BUFFALO5");
	}
	if (Settings::currentOption == 4) {
		previewCar("CLIQUE2");
	}
	if (Settings::currentOption == 5) {
		previewCar("CONADA2");
	}
	if (Settings::currentOption == 6) {
		previewCar("COUREUR");
	}
	if (Settings::currentOption == 7) {
		previewCar("GAUNTLET6");
	}
	if (Settings::currentOption == 8) {
		previewCar("INDUCTOR");
	}
	if (Settings::currentOption == 9) {
		previewCar("INDUCTOR2");
	}
	if (Settings::currentOption == 10) {
		previewCar("L35");
	}
	if (Settings::currentOption == 11) {
		previewCar("MONSTROCITI");
	}
	if (Settings::currentOption == 12) {
		previewCar("RAIJU");
	}
	if (Settings::currentOption == 13) {
		previewCar("RATEL");
	}
	if (Settings::currentOption == 14) {
		previewCar("STINGERTT");
	}
	if (Settings::currentOption == 15) {
		previewCar("STREAMER216");
	}
	if (Settings::currentOption == 16) {
		previewCar("SPEEDO5");
	}
	if (Addoption("Avenger 3"))
	{
		GiftVehicle2("AVENGER3");
	}
	if (Addoption("Brigham"))
	{
		GiftVehicle2("BRIGHAM");
	}
	if (Addoption("Buffalo 5"))
	{
		GiftVehicle2("BUFFALO5");
	}
	if (Addoption("Clique 2"))
	{
		GiftVehicle2("CLIQUE2");
	}
	if (Addoption("Conada 2"))
	{
		GiftVehicle2("CONADA2");
	}
	if (Addoption("Coureur"))
	{
		GiftVehicle2("COUREUR");
	}
	if (Addoption("Gauntlet 6"))
	{
		GiftVehicle2("GAUNTLET6");
	}
	if (Addoption("Inductor"))
	{
		GiftVehicle2("INDUCTOR");
	}
	if (Addoption("Inductor 2"))
	{
		GiftVehicle2("INDUCTOR2");
	}
	if (Addoption("L35"))
	{
		GiftVehicle2("L35");
	}
	if (Addoption("Monstrociti"))
	{
		GiftVehicle2("MONSTROCITI");
	}
	if (Addoption("Raiju"))
	{
		GiftVehicle2("RAIJU");
	}
	if (Addoption("Ratel"))
	{
		GiftVehicle2("RATEL");
	}
	if (Addoption("Stingertt"))
	{
		GiftVehicle2("STINGERTT");
	}
	if (Addoption("Streamer 216"))
	{
		GiftVehicle2("STREAMER216");
	}
	if (Addoption("Speedo 5"))
	{
		GiftVehicle2("SPEEDO5");
	}
}

void Spawner::MercenariespinSpawner()
{
	Menu::Title("");
	Menu::SubTitle("Mercenaries");

	if (Settings::currentOption == 1) {
		previewCar("AVENGER3");
	}
	if (Settings::currentOption == 2) {
		previewCar("BRIGHAM");
	}
	if (Settings::currentOption == 3) {
		previewCar("BUFFALO5");
	}
	if (Settings::currentOption == 4) {
		previewCar("CLIQUE2");
	}
	if (Settings::currentOption == 5) {
		previewCar("CONADA2");
	}
	if (Settings::currentOption == 6) {
		previewCar("COUREUR");
	}
	if (Settings::currentOption == 7) {
		previewCar("GAUNTLET6");
	}
	if (Settings::currentOption == 8) {
		previewCar("INDUCTOR");
	}
	if (Settings::currentOption == 9) {
		previewCar("INDUCTOR2");
	}
	if (Settings::currentOption == 10) {
		previewCar("L35");
	}
	if (Settings::currentOption == 11) {
		previewCar("MONSTROCITI");
	}
	if (Settings::currentOption == 12) {
		previewCar("RAIJU");
	}
	if (Settings::currentOption == 13) {
		previewCar("RATEL");
	}
	if (Settings::currentOption == 14) {
		previewCar("STINGERTT");
	}
	if (Settings::currentOption == 15) {
		previewCar("STREAMER216");
	}
	if (Settings::currentOption == 16) {
		previewCar("SPEEDO5");
	}
	if (Addoption("Avenger 3"))
	{
		SpawnVehicle("AVENGER3");
	}
	if (Addoption("Brigham"))
	{
		SpawnVehicle("BRIGHAM");
	}
	if (Addoption("Buffalo 5"))
	{
		SpawnVehicle("BUFFALO5");
	}
	if (Addoption("Clique 2"))
	{
		SpawnVehicle("CLIQUE2");
	}
	if (Addoption("Conada 2"))
	{
		SpawnVehicle("CONADA2");
	}
	if (Addoption("Coureur"))
	{
		SpawnVehicle("COUREUR");
	}
	if (Addoption("Gauntlet 6"))
	{
		SpawnVehicle("GAUNTLET6");
	}
	if (Addoption("Inductor"))
	{
		SpawnVehicle("INDUCTOR");
	}
	if (Addoption("Inductor 2"))
	{
		SpawnVehicle("INDUCTOR2");
	}
	if (Addoption("L35"))
	{
		SpawnVehicle("L35");
	}
	if (Addoption("Monstrociti"))
	{
		SpawnVehicle("MONSTROCITI");
	}
	if (Addoption("Raiju"))
	{
		SpawnVehicle("RAIJU");
	}
	if (Addoption("Ratel"))
	{
		SpawnVehicle("RATEL");
	}
	if (Addoption("Stingertt"))
	{
		SpawnVehicle("STINGERTT");
	}
	if (Addoption("Streamer 216"))
	{
		SpawnVehicle("STREAMER216");
	}
	if (Addoption("Speedo 5"))
	{
		SpawnVehicle("SPEEDO5");
	}
}

void Spawner::DrugwarspinSpawnergift()
{
	Menu::Title("");
	Menu::SubTitle("Drug Wars");

	if (Settings::currentOption == 1) {
		previewCar("BRIOSO3");
	}
	if (Settings::currentOption == 2) {
		previewCar("CORSITA");
	}
	if (Settings::currentOption == 3) {
		previewCar("DRAUGUR");
	}
	if (Settings::currentOption == 4) {
		previewCar("GREENWOOD");
	}
	if (Settings::currentOption == 5) {
		previewCar("CONADA");
	}
	if (Settings::currentOption == 6) {
		previewCar("KANJOSJ");
	}
	if (Settings::currentOption == 7) {
		previewCar("LM87");
	}
	if (Settings::currentOption == 8) {
		previewCar("OMNISEGT");
	}
	if (Settings::currentOption == 9) {
		previewCar("POSTLUDE");
	}
	if (Settings::currentOption == 10) {
		previewCar("RHINEHART");
	}
	if (Settings::currentOption == 11) {
		previewCar("RUINER4");
	}
	if (Settings::currentOption == 12) {
		previewCar("SENTINEL4");
	}
	if (Settings::currentOption == 13) {
		previewCar("SM722");
	}
	if (Settings::currentOption == 14) {
		previewCar("TENF");
	}
	if (Settings::currentOption == 15) {
		previewCar("TENF2");
	}
	if (Settings::currentOption == 16) {
		previewCar("TORERO2");
	}
	if (Settings::currentOption == 17) {
		previewCar("VIGERO2");
	}
	if (Settings::currentOption == 18) {
		previewCar("WEEVIL2");
	}
	if (Addoption("Brioso 3"))
	{
		GiftVehicle2("BRIOSO3");
	}
	if (Addoption("Corsita"))
	{
		GiftVehicle2("CORSITA");
	}
	if (Addoption("Draugur"))
	{
		GiftVehicle2("DRAUGUR");
	}
	if (Addoption("Greenwood"))
	{
		GiftVehicle2("GREENWOOD");
	}
	if (Addoption("Conada"))
	{
		GiftVehicle2("CONADA");
	}
	if (Addoption("Kanjosj"))
	{
		GiftVehicle2("KANJOSJ");
	}
	if (Addoption("Lm87"))
	{
		GiftVehicle2("LM87");
	}
	if (Addoption("Omnisegt"))
	{
		GiftVehicle2("OMNISEGT");
	}
	if (Addoption("Postlude"))
	{
		GiftVehicle2("POSTLUDE");
	}
	if (Addoption("Rhinehart"))
	{
		GiftVehicle2("RHINEHART");
	}
	if (Addoption("Ruiner 4"))
	{
		GiftVehicle2("RUINER4");
	}
	if (Addoption("Sentinel 4"))
	{
		GiftVehicle2("SENTINEL4");
	}
	if (Addoption("Sm722"))
	{
		GiftVehicle2("SM722");
	}
	if (Addoption("Tenf"))
	{
		GiftVehicle2("TENF");
	}
	if (Addoption("Tenf 2"))
	{
		GiftVehicle2("TENF2");
	}
	if (Addoption("Torero 2"))
	{
		GiftVehicle2("TORERO2");
	}
	if (Addoption("Vigero 2"))
	{
		GiftVehicle2("VIGERO2");
	}
	if (Addoption("Weevil 2"))
	{
		GiftVehicle2("WEEVIL2");
	}
}

void Spawner::DrugwarspinSpawner()
{
	Menu::Title("");
	Menu::SubTitle("Drug Wars");

	if (Settings::currentOption == 1) {
		previewCar("BRIOSO3");
	}
	if (Settings::currentOption == 2) {
		previewCar("CORSITA");
	}
	if (Settings::currentOption == 3) {
		previewCar("DRAUGUR");
	}
	if (Settings::currentOption == 4) {
		previewCar("GREENWOOD");
	}
	if (Settings::currentOption == 5) {
		previewCar("CONADA");
	}
	if (Settings::currentOption == 6) {
		previewCar("KANJOSJ");
	}
	if (Settings::currentOption == 7) {
		previewCar("LM87");
	}
	if (Settings::currentOption == 8) {
		previewCar("OMNISEGT");
	}
	if (Settings::currentOption == 9) {
		previewCar("POSTLUDE");
	}
	if (Settings::currentOption == 10) {
		previewCar("RHINEHART");
	}
	if (Settings::currentOption == 11) {
		previewCar("RUINER4");
	}
	if (Settings::currentOption == 12) {
		previewCar("SENTINEL4");
	}
	if (Settings::currentOption == 13) {
		previewCar("SM722");
	}
	if (Settings::currentOption == 14) {
		previewCar("TENF");
	}
	if (Settings::currentOption == 15) {
		previewCar("TENF2");
	}
	if (Settings::currentOption == 16) {
		previewCar("TORERO2");
	}
	if (Settings::currentOption == 17) {
		previewCar("VIGERO2");
	}
	if (Settings::currentOption == 18) {
		previewCar("WEEVIL2");
	}
	if (Addoption("Brioso 3"))
	{
		SpawnVehicle("BRIOSO3");
	}
	if (Addoption("Corsita"))
	{
		SpawnVehicle("CORSITA");
	}
	if (Addoption("Draugur"))
	{
		SpawnVehicle("DRAUGUR");
	}
	if (Addoption("Greenwood"))
	{
		SpawnVehicle("GREENWOOD");
	}
	if (Addoption("Conada"))
	{
		SpawnVehicle("CONADA");
	}
	if (Addoption("Kanjosj"))
	{
		SpawnVehicle("KANJOSJ");
	}
	if (Addoption("Lm87"))
	{
		SpawnVehicle("LM87");
	}
	if (Addoption("Omnisegt"))
	{
		SpawnVehicle("OMNISEGT");
	}
	if (Addoption("Postlude"))
	{
		SpawnVehicle("POSTLUDE");
	}
	if (Addoption("Rhinehart"))
	{
		SpawnVehicle("RHINEHART");
	}
	if (Addoption("Ruiner 4"))
	{
		SpawnVehicle("RUINER4");
	}
	if (Addoption("Sentinel 4"))
	{
		SpawnVehicle("SENTINEL4");
	}
	if (Addoption("Sm722"))
	{
		SpawnVehicle("SM722");
	}
	if (Addoption("Tenf"))
	{
		SpawnVehicle("TENF");
	}
	if (Addoption("Tenf 2"))
	{
		SpawnVehicle("TENF");
	}
	if (Addoption("Torero 2"))
	{
		SpawnVehicle("TORERO2");
	}
	if (Addoption("Vigero 2"))
	{
		SpawnVehicle("VIGERO2");
	}
	if (Addoption("Weevil 2"))
	{
		SpawnVehicle("WEEVIL2");
	}
}

void Spawner::tunerspinSpawnergift()
{
	Menu::Title("");
	Menu::SubTitle("Tuner");

	if (Settings::currentOption == 1) {
		previewCar("CALICO");
	}
	if (Settings::currentOption == 2) {
		previewCar("COMET6");
	}

	if (Settings::currentOption == 3) {
		previewCar("CYPHER");
	}

	if (Settings::currentOption == 4) {
		previewCar("DOMINATOR7");
	}
	if (Settings::currentOption == 5) {
		previewCar("DOMINATOR8");
	}
	if (Settings::currentOption == 6) {
		previewCar("EUROS");
	}
	if (Settings::currentOption == 7) {
		previewCar("FUTO2");
	}

	if (Settings::currentOption == 8) {
		previewCar("GROWLER");
	}

	if (Settings::currentOption == 9) {
		previewCar("JESTER4");
	}

	if (Settings::currentOption == 10) {
		previewCar("PREVION");
	}

	if (Settings::currentOption == 11) {
		previewCar("REMUS");
	}
		if (Settings::currentOption == 12) {
			previewCar("RT3000");
		}

		if (Settings::currentOption == 13) {
			previewCar("SULTAN3");
		}
		if (Settings::currentOption == 14) {
			previewCar("TAILGATER2");
		}
		if (Settings::currentOption == 15) {
			previewCar("VECTRE");
		}
		if (Settings::currentOption == 16) {
			previewCar("WARRENER2");
		}
		if (Settings::currentOption == 17) {
			previewCar("ZR350");
		}
		if (Addoption("Calico"))
		{
			GiftVehicle2("CALICO");
		}
		if (Addoption("Comet 6"))
		{
			GiftVehicle2("COMET6");
		}
		if (Addoption("Cypher"))
		{
			GiftVehicle2("CYPHER");
		}
		if (Addoption("Dominator 7"))
		{
			GiftVehicle2("DOMINATOR7");
		}
		if (Addoption("Dominator 8"))
		{
			GiftVehicle2("DOMINATOR8");
		}
		if (Addoption("Euros"))
		{
			GiftVehicle2("EUROS");
		}
		if (Addoption("Futo 2"))
		{
			GiftVehicle2("FUTO2");
		}
		if (Addoption("Growler"))
		{
			GiftVehicle2("GROWLER");
		}
		if (Addoption("Jester 4"))
		{
			GiftVehicle2("JESTER4");
		}
		if (Addoption("Previon"))
		{
			GiftVehicle2("PREVION");
		}
		if (Addoption("Remus"))
		{
			GiftVehicle2("REMUS");
		}
		if (Addoption("RT3000"))
		{
			GiftVehicle2("RT3000");
		}
		if (Addoption("Sultan 3"))
		{
			GiftVehicle2("SULTAN3");
		}
		if (Addoption("Tailgater 2"))
		{
			GiftVehicle2("TAILGATER2");
		}
		if (Addoption("Vectre"))
		{
			GiftVehicle2("VECTRE");
		}
		if (Addoption("Warrener"))
		{
			GiftVehicle2("WARRENER2");
		}
		if (Addoption("ZR350"))
		{
			GiftVehicle2("ZR350");
		}
}

void Spawner::tunerspinSpawner()
{
	Menu::Title("");
	Menu::SubTitle("Tuner");

	if (Settings::currentOption == 1) {
		previewCar("CALICO");
	}
	if (Settings::currentOption == 2) {
		previewCar("COMET6");
	}

	if (Settings::currentOption == 3) {
		previewCar("CYPHER");
	}

	if (Settings::currentOption == 4) {
		previewCar("DOMINATOR7");
	}
	if (Settings::currentOption == 5) {
		previewCar("DOMINATOR8");
	}
	if (Settings::currentOption == 6) {
		previewCar("EUROS");
	}
	if (Settings::currentOption == 7) {
		previewCar("FUTO2");
	}

	if (Settings::currentOption == 8) {
		previewCar("GROWLER");
	}

	if (Settings::currentOption == 9) {
		previewCar("JESTER4");
	}

	if (Settings::currentOption == 10) {
		previewCar("PREVION");
	}

	if (Settings::currentOption == 11) {
		previewCar("REMUS");
	}
	if (Settings::currentOption == 12) {
		previewCar("RT3000");
	}

	if (Settings::currentOption == 13) {
		previewCar("SULTAN3");
	}
	if (Settings::currentOption == 14) {
		previewCar("TAILGATER2");
	}
	if (Settings::currentOption == 15) {
		previewCar("VECTRE");
	}
	if (Settings::currentOption == 16) {
		previewCar("WARRENER2");
	}
	if (Settings::currentOption == 17) {
		previewCar("ZR350");
	}
	if (Addoption("Calico"))
	{
		SpawnVehicle("CALICO");
	}
	if (Addoption("Comet 6"))
	{
		SpawnVehicle("COMET6");
	}
	if (Addoption("Cypher"))
	{
		SpawnVehicle("CYPHER");
	}
	if (Addoption("Dominator 7"))
	{
		SpawnVehicle("DOMINATOR7");
	}
	if (Addoption("Dominator 8"))
	{
		SpawnVehicle("DOMINATOR8");
	}
	if (Addoption("Euros"))
	{
		SpawnVehicle("EUROS");
	}
	if (Addoption("Futo 2"))
	{
		SpawnVehicle("FUTO2");
	}
	if (Addoption("Growler"))
	{
		SpawnVehicle("GROWLER");
	}
	if (Addoption("Jester 4"))
	{
		SpawnVehicle("JESTER4");
	}
	if (Addoption("Previon"))
	{
		SpawnVehicle("PREVION");
	}
	if (Addoption("Remus"))
	{
		SpawnVehicle("REMUS");
	}
	if (Addoption("RT3000"))
	{
		SpawnVehicle("RT3000");
	}
	if (Addoption("Sultan 3"))
	{
		SpawnVehicle("SULTAN3");
	}
	if (Addoption("Tailgater 2"))
	{
		SpawnVehicle("TAILGATER2");
	}
	if (Addoption("Vectre"))
	{
		SpawnVehicle("VECTRE");
	}
	if (Addoption("Warrener"))
	{
		SpawnVehicle("WARRENER2");
	}
	if (Addoption("ZR350"))
	{
		SpawnVehicle("ZR350");
	}

}

void Spawner::cayospinSpawnergift()
{
	Menu::Title("");
	Menu::SubTitle("Cayo Perico");
	if (Settings::currentOption == 1) {
		previewCar("ALKONOST");
	}
	if (Settings::currentOption == 2) {
		previewCar("ANNIHILATOR2");
	}
	if (Settings::currentOption == 3) {
		previewCar("AVISA");
	}
	if (Settings::currentOption == 4) {
		previewCar("BRIOSO2");
	}
	if (Settings::currentOption == 5) {
		previewCar("DINGHY5");
	}
	if (Settings::currentOption == 6) {
		previewCar("ITALIRSX");
	}
	if (Settings::currentOption == 7) {
		previewCar("KOSATKA");
	}
	if (Settings::currentOption == 8) {
		previewCar("LONGFIN");
	}
	if (Settings::currentOption == 9) {
		previewCar("MANCHEZ2");
	}
	if (Settings::currentOption == 10) {
		previewCar("PATROLBOAT");
	}
	if (Settings::currentOption == 11) {
		previewCar("SEASPARROW2");
	}
	if (Settings::currentOption == 12) {
		previewCar("SLAMTRUCK");
	}
	if (Settings::currentOption == 13) {
		previewCar("SQUADDIE");
	}
	if (Settings::currentOption == 14) {
		previewCar("TOREADOR");
	}
	if (Settings::currentOption == 15) {
		previewCar("VERUS");
	}
	if (Settings::currentOption == 16) {
		previewCar("VETIR");
	}
	if (Settings::currentOption == 17) {
		previewCar("VETO");
	}
	if (Settings::currentOption == 18) {
		previewCar("VETO2");
	}
	if (Settings::currentOption == 19) {
		previewCar("WEEVIL");
	}
	if (Settings::currentOption == 20) {
		previewCar("WINKY");
	}
	if (Addoption("Alkonost"))
	{
		GiftVehicle2("ALKONOST");
	}
	if (Addoption("Annihilator 2"))
	{
		GiftVehicle2("ANNIHILATOR2");
	}
	if (Menu::Option("Avisa"))
	{
		GiftVehicle2("AVISA");
	}
	if (Addoption("Brioso 2"))
	{
		GiftVehicle2("BRIOSO2");
	}
	if (Addoption("Dinghy 5"))
	{
		GiftVehicle2("DINGHY5");
	}
	if (Addoption("Itali RSX"))
	{
		GiftVehicle2("ITALIRSX");
	}
	if (Addoption("Kosatka"))
	{
		GiftVehicle2("KOSATKA");
	}
	if (Addoption("Longfin"))
	{
		GiftVehicle2("LONGFIN");
	}
	if (Addoption("Manchez 2"))
	{
		GiftVehicle2("MANCHEZ2");
	}
	if (Addoption("Patrol Boat"))
	{
		GiftVehicle2("PATROLBOAT");
	}
	if (Addoption("Sea Sparrow 2"))
	{
		GiftVehicle2("SEASPARROW2");
	}
	if (Addoption("Slam Truck"))
	{
		GiftVehicle2("SLAMTRUCK ");
	}
	if (Addoption("Squaddie"))
	{
		GiftVehicle2("SQUADDIE");
	}
	if (Addoption("Toreador"))
	{
		GiftVehicle2("TOREADOR");
	}
	if (Addoption("Versus"))
	{
		GiftVehicle2("VERUS");
	}
	if (Addoption("Vetir"))
	{
		GiftVehicle2("VETIR");
	}
	if (Addoption("Veto"))
	{
		GiftVehicle2("VETO");
	}
	if (Addoption("Veto"))
	{
		GiftVehicle2("VETO2");
	}
	if (Addoption("Weevil"))
	{
		GiftVehicle2("WEEVIL");
	}
	if (Addoption("Winky"))
	{
		GiftVehicle2("WINKY");
	}
}

void Spawner::summerspinSpawnergift()
{
	Menu::Title("");
	Menu::SubTitle("Summer Update");
	if (Settings::currentOption == 1) {
		previewCar("CLUB");
	}
	if (Settings::currentOption == 2) {
		previewCar("COQUETTE4");
	}
	if (Settings::currentOption == 3) {
		previewCar("DUKES3");
	}
	if (Settings::currentOption == 4) {
		previewCar("GAUNTLET5");
	}
	if (Settings::currentOption == 5) {
		previewCar("GLENDALE2");
	}
	if (Settings::currentOption == 6) {
		previewCar("MANANA2");
	}
	if (Settings::currentOption == 7) {
		previewCar("OPENWHEEL1");
	}
	if (Settings::currentOption == 8) {
		previewCar("OPENWHEEL2");
	}
	if (Settings::currentOption == 9) {
		previewCar("PENUMBRA2");
	}
	if (Settings::currentOption == 10) {
		previewCar("PEYOTE3");
	}
	if (Settings::currentOption == 11) {
		previewCar("SEMINOLE2");
	}
	if (Settings::currentOption == 12) {
		previewCar("TIGON");
	}
	if (Settings::currentOption == 13) {
		previewCar("YOSEMITE3");
	}
	if (Settings::currentOption == 14) {
		previewCar("YOUGA3");
	}
	if (Addoption("Club"))
	{
		GiftVehicle2("CLUB");
	}
	if (Addoption("Coquette 4"))
	{
		GiftVehicle2("COQUETTE4");
	}
	if (Menu::Option("Dukes 3"))
	{
		GiftVehicle2("DUKES3");
	}
	if (Addoption("Gauntlet 5"))
	{
		GiftVehicle2("GAUNTLET5");
	}
	if (Addoption("Glendale 2"))
	{
		GiftVehicle2("GLENDALE2");
	}
	if (Addoption("Manana 2"))
	{
		GiftVehicle2("MANANA2");
	}
	if (Addoption("OpenWheel 1"))
	{
		GiftVehicle2("OPENWHEEL1");
	}
	if (Addoption("OpenWheel 2"))
	{
		GiftVehicle2("OPENWHEEL2");
	}
	if (Addoption("Penumbra 2"))
	{
		GiftVehicle2("PENUMBRA2");
	}
	if (Addoption("Peyote 3"))
	{
		GiftVehicle2("PEYOTE3");
	}
	if (Addoption("Seminole 2"))
	{
		GiftVehicle2("SEMINOLE2");
	}
	if (Addoption("Tigon"))
	{
		GiftVehicle2("TIGON");
	}
	if (Addoption("Yosemite 3"))
	{
		GiftVehicle2("YOSEMITE3");
	}
	if (Addoption("Youga 3"))
	{
		GiftVehicle2("YOUGA3");
	}



}

void Spawner::CasinospinSpawnergift()
{
	Menu::Title("");

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
	if (Addoption("Caracara 2"))
	{
		GiftVehicle2("CARACARA2");
	}
	if (Addoption("Drafter"))
	{
		GiftVehicle2("DRAFTER");
	}
	if (Addoption("Dynasty"))
	{
		GiftVehicle2("DYNASTY");
	}
	if (Addoption("Emerus"))
	{
		GiftVehicle2("EMERUS");
	}
	if (Addoption("Gauntlet 3"))
	{
		GiftVehicle2("GAUNTLET3");
	}
	if (Addoption("Gauntlet 4"))
	{
		GiftVehicle2("GAUNTLET4");
	}
	if (Addoption("Hellion"))
	{
		GiftVehicle2("HELLION");
	}
	if (Addoption("Issi 7"))
	{
		GiftVehicle2("ISSI7");
	}
	if (Addoption("Jagular"))
	{
		GiftVehicle2("JUGULAR");
	}
	if (Addoption("Locust"))
	{
		GiftVehicle2("LOCUST");
	}
	if (Addoption("Nebula"))
	{
		GiftVehicle2("NEBULA");
	}
	if (Addoption("Neo"))
	{
	  GiftVehicle2("NEO");
	}
	if (Addoption("Novak"))
	{
		GiftVehicle2("NOVAK");
	}
	if (Addoption("Paragon"))
	{
		GiftVehicle2("PARAGON");
	}
	if (Addoption("S 80"))
	{
		GiftVehicle2("S80");
	}
	if (Addoption("Thrax"))
	{
		GiftVehicle2("THRAX");
	}
	if (Addoption("Zion 3"))
	{
		GiftVehicle2("ZION3");
	}
	if (Addoption("Zorrusso"))
	{
		GiftVehicle2("ZORRUSSO");
	}
}


void Spawner::SSspinSpawnergift()
{
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

	if (Addoption("Adder"))
	{
		GiftVehicle2("ADDER");
	}
	if (Addoption("Autarch"))
	{
		GiftVehicle2("autarch");
	}
	if (Addoption("Banshee"))
	{
		GiftVehicle2("BANSHEE2");
	}
	if (Addoption("Bullet"))
	{
		GiftVehicle2("BULLET");
	}
	if (Addoption("Cheetah"))
	{
		GiftVehicle2("CHEETAH");
	}
	if (Addoption("Deluxo"))
	{
		GiftVehicle2("deluxo");
	}
	if (Addoption("Entity XF"))
	{
		GiftVehicle2("ENTITYXF");
	}
	if (Addoption("FMJ"))
	{
		GiftVehicle2("FMJ");
	}
	if (Addoption("Sheava"))
	{
		GiftVehicle2("SHEAVA");
	}
	if (Addoption("Infernus"))
	{
		GiftVehicle2("INFERNUS");
	}
	if (Addoption("Nero"))
	{
		GiftVehicle2("NERO");
	}
	if (Addoption("Nero 2"))
	{
		GiftVehicle2("NERO2");
	}
	if (Addoption("Osiris"))
	{
		GiftVehicle2("OSIRIS");
	}
	if (Addoption("LE7B"))
	{
		GiftVehicle2("LE7B");
	}
	if (Addoption("Deveste"))
	{
		GiftVehicle2("DEVESTE");
	}
	if (Addoption("ItaliGTB"))
	{
		GiftVehicle2("ITALIGTB");
	}
	if (Addoption("ItaliGTB 2"))
	{
		GiftVehicle2("ITALIGTB2");
	}
	if (Addoption("Pfister 811"))
	{
		GiftVehicle2("PFISTER811");
	}
	if (Addoption("Prototipo"))
	{
		GiftVehicle2("PROTOTIPO");
	}
	if (Addoption("Adder"))
	{
		GiftVehicle2("REAPER");
	}
	if (Addoption("Sultan RS"))
	{
		GiftVehicle2("SULTANRS");
	}
	if (Addoption("T 20"))
	{
		GiftVehicle2("t20");
	}
	if (Addoption("Tempesta"))
	{
		GiftVehicle2("TEMPESTA");
	}
	if (Addoption("Turismo R"))
	{
		GiftVehicle2("turismor");
	}
	if (Addoption("Tyrus"))
	{
		GiftVehicle2("tyrus");
	}
	if (Addoption("Tezeract"))
	{
		GiftVehicle2("tezeract");
	}
	if (Addoption("Entity2"))
	{
		GiftVehicle2("entity2");
	}
	if (Addoption("Vacca"))
	{
		GiftVehicle2("VACCA");
	}
	if (Addoption("Voltic"))
	{
		GiftVehicle2("VOLTIC");
	}
	if (Addoption("Zentorno"))
	{
		GiftVehicle2("ZENTORNO");
	}
	if (Addoption("Visione"))
	{
		GiftVehicle2("visione");
	}
	if (Addoption("Vigilante"))
	{
		GiftVehicle2("Vigilante");
	}
	if (Addoption("Penetrator"))
	{
		GiftVehicle2("PENETRATOR");
	}
	if (Addoption("GP 1"))
	{
		GiftVehicle2("gp1");
	}
}



void Spawner::sportspinSpawnergift()
{
	Menu::Title("");
	Menu::SubTitle("Sport");


	if (Settings::currentOption == 1) {
		previewCar("ALPHA");
	}
	if (Settings::currentOption == 2) {
		previewCar("BANSHEE");
	}
	if (Settings::currentOption == 3) {
		previewCar("flashgt");
	}
	if (Settings::currentOption == 4) {
		previewCar("BESTIAGTS");
	}
	if (Settings::currentOption == 5) {
		previewCar("BLISTA2");
	}
	if (Settings::currentOption == 6) {
		previewCar("BLISTA3");
	}
	if (Settings::currentOption == 7) {
		previewCar("ITALIGTO");
	}
	if (Settings::currentOption == 8) {
		previewCar("SCHLAGEN");
	}
	if (Settings::currentOption == 9) {
		previewCar("BUFFALO");
	}
	if (Settings::currentOption == 10) {
		previewCar("BUFFALO2");
	}
	if (Settings::currentOption == 11) {
		previewCar("BUFFALO3");
	}
	if (Settings::currentOption == 12) {
		previewCar("swinger");
	}
	if (Settings::currentOption == 13) {
		previewCar("comet4");
	}
	if (Settings::currentOption == 14) {
		previewCar("comet5");
	}
	if (Settings::currentOption == 15) {
		previewCar("CARBONIZZARE");
	}
	if (Settings::currentOption == 16) {
		previewCar("COMET2");
	}
	if (Settings::currentOption == 17) {
		previewCar("COQUETTE");
	}
	if (Settings::currentOption == 18) {
		previewCar("cyclone");
	}
	if (Settings::currentOption == 19) {
		previewCar("ELEGY");
	}
	if (Settings::currentOption == 20) {
		previewCar("ELEGY2");
	}
	if (Settings::currentOption == 21) {
		previewCar("FELTZER2");
	}
	if (Settings::currentOption == 22) {
		previewCar("FUROREGT");
	}
	if (Settings::currentOption == 23) {
		previewCar("FUSILADE");
	}
	if (Settings::currentOption == 24) {
		previewCar("FUTO");
	}
	if (Settings::currentOption == 25) {
		previewCar("JESTER");
	}
	if (Settings::currentOption == 26) {
		previewCar("JESTER2");
	}
	if (Settings::currentOption == 27) {
		previewCar("dominator3");
	}
	if (Settings::currentOption == 28) {
		previewCar("KHAMELION");
	}
	if (Settings::currentOption == 39) {
		previewCar("KURUMA");
	}
	if (Settings::currentOption == 30) {
		previewCar("ZR380");
	}
	if (Settings::currentOption == 31) {
		previewCar("ZR3802");
	}
	if (Settings::currentOption == 32) {
		previewCar("ZR3803");
	}
	if (Settings::currentOption == 33) {
		previewCar("KURUMA2");
	}
	if (Settings::currentOption == 34) {
		previewCar("LYNX");
	}
	if (Settings::currentOption == 35) {
		previewCar("MASSACRO");
	}
	if (Settings::currentOption == 36) {
		previewCar("MASSACRO2");
	}
	if (Settings::currentOption == 37) {
		previewCar("pariah");
	}
	if (Settings::currentOption == 38) {
		previewCar("raiden");
	}
	if (Settings::currentOption == 39) {
		previewCar("NINEF");
	}
	if (Settings::currentOption == 40) {
		previewCar("NINEF2");
	}
	if (Settings::currentOption == 41) {
		previewCar("OMNIS");
	}
	if (Settings::currentOption == 42) {
		previewCar("PENUMBRA");
	}
	if (Settings::currentOption == 43) {
		previewCar("RAPIDGT");
	}
	if (Settings::currentOption == 44) {
		previewCar("tyrant");
	}
	if (Settings::currentOption == 45) {
		previewCar("hotring");
	}
	if (Settings::currentOption == 46) {
		previewCar("ellie");
	}
	if (Settings::currentOption == 47) {
		previewCar("RAPIDGT2");
	}
	if (Settings::currentOption == 48) {
		previewCar("RAPTOR");
	}
	if (Settings::currentOption == 49) {
		previewCar("SCHAFTER3");
	}
	if (Settings::currentOption == 50) {
		previewCar("SCHAFTER4");
	}
	if (Settings::currentOption == 51) {
		previewCar("taipan");
	}
	if (Settings::currentOption == 52) {
		previewCar("SCHWARZER");
	}
	if (Settings::currentOption == 53) {
		previewCar("jester3");
	}
	if (Settings::currentOption == 54) {
		previewCar("SEVEN70");
	}
	if (Settings::currentOption == 55) {
		previewCar("SULTAN");
	}
	if (Settings::currentOption == 56) {
		previewCar("SURANO");
	}
	if (Settings::currentOption == 57) {
		previewCar("SPECTER");
	}
	if (Settings::currentOption == 58) {
		previewCar("SPECTER2");
	}
	if (Settings::currentOption == 59) {
		previewCar("scramjet");
	}
	if (Settings::currentOption == 60) {
		previewCar("TAMPA2");
	}
	if (Settings::currentOption == 61) {
		previewCar("TROPOS");
	}
	if (Settings::currentOption == 62) {
		previewCar("VERLIERER2");
	}
	if (Settings::currentOption == 63) {
		previewCar("RUINER2");
	}
	if (Settings::currentOption == 64) {
		previewCar("PHANTOM2");
	}
	if (Settings::currentOption == 65) {
		previewCar("RUSTON");
	}

	if (Addoption("Alpha"))
	{
		GiftVehicle2("ALPHA");
	}
	if (Addoption("Bravado Banshee"))
	{
		GiftVehicle2("BANSHEE");
	}
	if (Addoption("Vapid Flash GT"))
	{
		GiftVehicle2("flashgt");
	}
	if (Addoption("Grotti Bestia GTS"))
	{
		GiftVehicle2("BESTIAGTS");
	}
	if (Addoption("Dinka Blista Compact"))
	{
		GiftVehicle2("BLISTA2");
	}
	if (Addoption("Dinka Go Go Money Blista"))
	{
		GiftVehicle2("BLISTA3");
	}
	if (Addoption("Grotti Itali GTO"))
	{
		GiftVehicle2("ITALIGTO");
	}
	if (Addoption("Benefactor Schlagen GT"))
	{
		GiftVehicle2("SCHLAGEN");
	}
	if (Addoption("Bravado Buffalo"))
	{
		GiftVehicle2("BUFFALO");
	}
	if (Addoption("Bravado Buffalo S"))
	{
		GiftVehicle2("BUFFALO2");
	}
	if (Addoption("Bravado Sprunk Buffalo"))
	{
		GiftVehicle2("BUFFALO3");
	}
	if (Addoption("Ocelot Swinger"))
	{
		GiftVehicle2("swinger");
	}
	if (Addoption("Phister Comet Safari"))
	{
		GiftVehicle2("comet4");
	}
	if (Addoption("Phister Comet SR"))
	{
		GiftVehicle2("comet5");
	}
	if (Addoption("Grotti Carbonizzare"))
	{
		GiftVehicle2("CARBONIZZARE");
	}
	if (Addoption("Phister Comet"))
	{
		GiftVehicle2("COMET2");
	}
	if (Addoption("Inverto Coquette"))
	{
		GiftVehicle2("COQUETTE");
	}
	if (Addoption("Coil Cyclone"))
	{
		GiftVehicle2("cyclone");
	}
	if (Addoption("Annis Elegy Retro Custom"))
	{
		GiftVehicle2("ELEGY");
	}
	if (Addoption("Annis Elegy RH8"))
	{
		GiftVehicle2("ELEGY2");
	}
	if (Addoption("Benefactor Feltzer"))
	{
		GiftVehicle2("FELTZER2");
	}
	if (Addoption("Lampadeti Furore GT"))
	{
		GiftVehicle2("FUROREGT");
	}
	if (Addoption("Schyster Fusilade"))
	{
		GiftVehicle2("FUSILADE");
	}
	if (Addoption("Karin Futo"))
	{
		GiftVehicle2("FUTO");
	}
	if (Addoption("Dinka Jester"))
	{
		GiftVehicle2("JESTER");
	}
	if (Addoption("Dinka Jester (racecar)"))
	{
		GiftVehicle2("JESTER2");
	}
	if (Addoption("Vapid Dominator GTX"))
	{
		GiftVehicle2("dominator3");
	}
	if (Addoption("Hijak Khamelion"))
	{
		GiftVehicle2("KHAMELION");
	}
	if (Addoption("Karin Kuruma"))
	{
		GiftVehicle2("KURUMA");
	}
	if (Addoption("Annis Apocalypse ZR380"))
	{
		GiftVehicle2("ZR380");
	}
	if (Addoption("Annis Future Shock ZR380"))
	{
		GiftVehicle2("ZR3802");
	}
	if (Addoption("Annis Nightmare ZR380"))
	{
		GiftVehicle2("ZR3803");
	}
	if (Addoption("Karin Karuma (armoured)"))
	{
		GiftVehicle2("KURUMA2");
	}
	if (Addoption("Ocelot Lynx"))
	{
		GiftVehicle2("LYNX");
	}
	if (Addoption("Dewbauchdee Massacro"))
	{
		GiftVehicle2("MASSACRO");
	}
	if (Addoption("Dewbauchdee Massacro (racecar)"))
	{
		GiftVehicle2("MASSACRO2");
	}
	if (Addoption("Ocelot Pariah"))
	{
		GiftVehicle2("pariah");
	}
	if (Addoption("Coil Raiden"))
	{
		GiftVehicle2("raiden");
	}
	if (Addoption("Obey 9F"))
	{
		GiftVehicle2("NINEF");
	}
	if (Addoption("Obey 9F Cabrio"))
	{
		GiftVehicle2("NINEF2");
	}
	if (Addoption("Obey Omnis"))
	{
		GiftVehicle2("OMNIS");
	}
	if (Addoption("Maibatsu Penumbra"))
	{
		GiftVehicle2("PENUMBRA");
	}
	if (Addoption("Dewbauchee Rapid GT"))
	{
		GiftVehicle2("RAPIDGT");
	}
	if (Addoption("Overflod Tyrant"))
	{
		GiftVehicle2("tyrant");
	}
	if (Addoption("Declasse Hotring Sabre"))
	{
		GiftVehicle2("hotring");
	}
	if (Addoption("Vapid Ellie"))
	{
		GiftVehicle2("ellie");
	}
	if (Addoption("Dewbauchee Rapid GT (convertable)"))
	{
		GiftVehicle2("RAPIDGT2");
	}
	if (Addoption("BF Raptor"))
	{
		GiftVehicle2("RAPTOR");
	}
	if (Addoption("Benefactor Schafter V12"))
	{
		GiftVehicle2("SCHAFTER3");
	}
	if (Addoption("Benefactor Schafter LWB"))
	{
		GiftVehicle2("SCHAFTER4");
	}
	if (Addoption("Chevel Taipan"))
	{
		GiftVehicle2("taipan");
	}
	if (Addoption("Schwartzer"))
	{
		GiftVehicle2("SCHWARZER");
	}
	if (Addoption("Dinka Jester Classic"))
	{
		GiftVehicle2("jester3");
	}
	if (Addoption("Dewbauchee Seven-70"))
	{
		GiftVehicle2("SEVEN70");
	}
	if (Addoption("Karin Sultan"))
	{
		GiftVehicle2("SULTAN");
	}
	if (Addoption("Benefactor Surano"))
	{
		GiftVehicle2("SURANO");
	}
	if (Addoption("Dewbauchee Specter"))
	{
		GiftVehicle2("SPECTER");
	}
	if (Addoption("Dewbauchee Specter Custom"))
	{
		GiftVehicle2("SPECTER2");
	}
	if (Addoption("Declasse Scramjet"))
	{
		GiftVehicle2("scramjet");
	}
	if (Addoption("Declasse Drift Tampa"))
	{
		GiftVehicle2("TAMPA2");
	}
	if (Addoption("Lampadati Tropos Rallye"))
	{
		GiftVehicle2("TROPOS");
	}
	if (Addoption("Bravado Verlierer"))
	{
		GiftVehicle2("VERLIERER2");
	}
	if (Addoption("Imponte Ruiner 2000"))
	{
		GiftVehicle2("RUINER2");
	}
	if (Addoption("JoBuilt Phantom Wedge"))
	{
		GiftVehicle2("PHANTOM2");
	}
	if (Addoption("Hijak Ruston"))
	{
		GiftVehicle2("RUSTON");
	}

}
void Spawner::sportclassicsspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Sport Classics");

	if (Settings::currentOption == 1) {
		previewCar("BTYPE");
	}
	if (Settings::currentOption == 2) {
		previewCar("BTYPE2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BTYPE3");
	}
	if (Settings::currentOption == 4) {
		previewCar("CASCO");
	}
	if (Settings::currentOption == 5) {
		previewCar("COQUETTE2");
	}
	if (Settings::currentOption == 6) {
		previewCar("TULIP");
	}
	if (Settings::currentOption == 7) {
		previewCar("VAMOS");
	}
	if (Settings::currentOption == 8) {
		previewCar("FELTZER3");
	}
	if (Settings::currentOption == 9) {
		previewCar("JB700");
	}
	if (Settings::currentOption == 10) {
		previewCar("gt500");
	}
	if (Settings::currentOption == 11) {
		previewCar("neon");
	}
	if (Settings::currentOption == 12) {
		previewCar("hermes");
	}
	if (Settings::currentOption == 13) {
		previewCar("hustler");
	}
	if (Settings::currentOption == 14) {
		previewCar("MAMBA");
	}
	if (Settings::currentOption == 15) {
		previewCar("MANANA");
	}
	if (Settings::currentOption == 16) {
		previewCar("MONROE");
	}
	if (Settings::currentOption == 17) {
		previewCar("PEYOTE");
	}
	if (Settings::currentOption == 18) {
		previewCar("PIGALLE");
	}
	if (Settings::currentOption == 19) {
		previewCar("STINGER");
	}
	if (Settings::currentOption == 20) {
		previewCar("viseris");
	}
	if (Settings::currentOption == 21) {
		previewCar("z190");
	}
	if (Settings::currentOption == 22) {
		previewCar("STINGERGT");
	}
	if (Settings::currentOption == 23) {
		previewCar("TORNADO");
	}
	if (Settings::currentOption == 24) {
		previewCar("revolter");
	}
	if (Settings::currentOption == 25) {
		previewCar("IMPALER");
	}
	if (Settings::currentOption == 26) {
		previewCar("IMPALER2");
	}
	if (Settings::currentOption == 27) {
		previewCar("IMPALER3");
	}
	if (Settings::currentOption == 28) {
		previewCar("IMPALER4");
	}
	if (Settings::currentOption == 39) {
		previewCar("TORNADO2");
	}
	if (Settings::currentOption == 30) {
		previewCar("TORNADO3");
	}
	if (Settings::currentOption == 31) {
		previewCar("TORNADO4");
	}
	if (Settings::currentOption == 32) {
		previewCar("TORNADO5");
	}
	if (Settings::currentOption == 33) {
		previewCar("TORNADO6");
	}
	if (Settings::currentOption == 34) {
		previewCar("DEVIANT");
	}
	if (Settings::currentOption == 35) {
		previewCar("IMPERATOR");
	}
	if (Settings::currentOption == 36) {
		previewCar("IMPERATOR2");
	}
	if (Settings::currentOption == 37) {
		previewCar("IMPERATOR3");
	}
	if (Settings::currentOption == 38) {
		previewCar("ZTYPE");
	}
	if (Settings::currentOption == 39) {
		previewCar("INFERNUS2");
	}
	if (Settings::currentOption == 40) {
		previewCar("TURISMO2");
	}
	if (Settings::currentOption == 41) {
		previewCar("CLIQUE");
	}

	if (Addoption("Albanny Roosevelt"))
	{
		GiftVehicle2("BTYPE");
	}
	if (Addoption("Albanny Franken Strange"))
	{
		GiftVehicle2("BTYPE2");
	}
	if (Addoption("Albanny Roosevelt Valor"))
	{
		GiftVehicle2("BTYPE3");
	}
	if (Addoption("Lampadati Casco"))
	{
		GiftVehicle2("CASCO");
	}
	if (Addoption("Invetero Coquette BlackFin"))
	{
		GiftVehicle2("COQUETTE2");
	}
	if (Addoption("Declass Tulip"))
	{
		GiftVehicle2("TULIP");
	}
	if (Addoption("Declass Vamos"))
	{
		GiftVehicle2("VAMOS");
	}
	if (Addoption("Benefactor Stirling GT"))
	{
		GiftVehicle2("FELTZER3");
	}
	if (Addoption("Dewbauchee JB 700"))
	{
		GiftVehicle2("JB700");
	}
	if (Addoption("Grotti GT500"))
	{
		GiftVehicle2("gt500");
	}
	if (Addoption("Phister Neon"))
	{
		GiftVehicle2("neon");
	}
	if (Addoption("Albany Hermes"))
	{
		GiftVehicle2("hermes");
	}
	if (Addoption("Vapid Hustler"))
	{
		GiftVehicle2("hustler");
	}
	if (Addoption("Declasse Mamba"))
	{
		GiftVehicle2("MAMBA");
	}
	if (Addoption("Albany Manana"))
	{
		GiftVehicle2("MANANA");
	}
	if (Addoption("Pegassi Monroe"))
	{
		GiftVehicle2("MONROE");
	}
	if (Addoption("Vapid Peyote"))
	{
		GiftVehicle2("PEYOTE");
	}
	if (Addoption("Lampadati Pigalle"))
	{
		GiftVehicle2("PIGALLE");
	}
	if (Addoption("Benefactor Stirling GT"))
	{
		GiftVehicle2("STINGER");
	}
	if (Addoption("Lampaditi Viseris"))
	{
		GiftVehicle2("viseris");
	}
	if (Addoption("Karin 190z"))
	{
		GiftVehicle2("z190");
	}
	if (Addoption("Stinger GT"))
	{
		GiftVehicle2("STINGERGT");
	}
	if (Addoption("Declasse Tornado"))
	{
		GiftVehicle2("TORNADO");
	}
	if (Addoption("Albany Roosevelt"))
	{
		GiftVehicle2("revolter");
	}
	if (Addoption("Vapid Clique"))
	{
		GiftVehicle2("IMPALER");
	}
	if (Addoption("Vapid Apocalypse Imperator"))
	{
		GiftVehicle2("IMPALER2");
	}
	if (Addoption("Vapid Future Shock Imperator"))
	{
		GiftVehicle2("IMPALER3");
	}
	if (Addoption("Vapid Nightmare Imperator"))
	{
		GiftVehicle2("IMPALER4");
	}
	if (Addoption("Declasse Tornado (convertable)"))
	{
		GiftVehicle2("TORNADO2");
	}
	if (Addoption("Declasse Tornado (old)"))
	{
		GiftVehicle2("TORNADO3");
	}
	if (Addoption("Declasse Tornado (mexican)"))
	{
		GiftVehicle2("TORNADO4");
	}
	if (Addoption("Declasse Tornado Custom"))
	{
		GiftVehicle2("TORNADO5");
	}
	if (Addoption("Declasse Tornado Rat-Rod"))
	{
		GiftVehicle2("TORNADO6");
	}
	if (Addoption("Schyster Deviant"))
	{
		GiftVehicle2("DEVIANT");
	}
	if (Addoption("Vapid Apocalypse Imperator"))
	{
		GiftVehicle2("IMPERATOR");
	}
	if (Addoption("Vapid Future Shock Imperator"))
	{
		GiftVehicle2("IMPERATOR2");
	}
	if (Addoption("Vapid Nightmare Imperator"))
	{
		GiftVehicle2("IMPERATOR3");
	}
	if (Addoption("Truffade Z-Type"))
	{
		GiftVehicle2("ZTYPE");
	}
	if (Addoption("Pegassi Infernus Classic"))
	{
		GiftVehicle2("INFERNUS2");
	}
	if (Addoption("Grotti Turismo Classic"))
	{
		GiftVehicle2("TURISMO2");
	}
	if (Addoption("Vapid Clique"))
	{
		GiftVehicle2("CLIQUE");
	}

}
void Spawner::SUVspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("SUV");


	if (Settings::currentOption == 1) {
		previewCar("BALLER");
	}
	if (Settings::currentOption == 2) {
		previewCar("BALLER2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BALLER3");
	}
	if (Settings::currentOption == 4) {
		previewCar("BALLER4");
	}
	if (Settings::currentOption == 5) {
		previewCar("BALLER5");
	}
	if (Settings::currentOption == 6) {
		previewCar("TOROS");
	}
	if (Settings::currentOption == 7) {
		previewCar("BALLER6");
	}
	if (Settings::currentOption == 8) {
		previewCar("BJXL");
	}
	if (Settings::currentOption == 9) {
		previewCar("CAVALCADE");
	}
	if (Settings::currentOption == 10) {
		previewCar("CAVALCADE2");
	}
	if (Settings::currentOption == 11) {
		previewCar("CONTENDER");
	}
	if (Settings::currentOption == 12) {
		previewCar("DUBSTA");
	}
	if (Settings::currentOption == 13) {
		previewCar("DUBSTA2");
	}
	if (Settings::currentOption == 14) {
		previewCar("streiter");
	}
	if (Settings::currentOption == 15) {
		previewCar("FQ2");
	}
	if (Settings::currentOption == 16) {
		previewCar("GRANGER");
	}
	if (Settings::currentOption == 17) {
		previewCar("GRESLEY");
	}
	if (Settings::currentOption == 18) {
		previewCar("riata");
	}
	if (Settings::currentOption == 19) {
		previewCar("PATRIOT");
	}
	if (Settings::currentOption == 20) {
		previewCar("RADI");
	}
	if (Settings::currentOption == 21) {
		previewCar("ROCOTO");
	}
	if (Settings::currentOption == 22) {
		previewCar("SEMINOLE");
	}
	if (Settings::currentOption == 23) {
		previewCar("SERRANO");
	}
	if (Settings::currentOption == 24) {
		previewCar("XLS");
	}
	if (Settings::currentOption == 25) {
		previewCar("XLS2");
	}

	if (Addoption("Gallivanter Baller"))
	{
		GiftVehicle2("BALLER");
	}
	if (Addoption("Gallivanter Baller (second generation)"))
	{
		GiftVehicle2("BALLER2");
	}
	if (Addoption("Baller LE"))
	{
		GiftVehicle2("BALLER3");
	}
	if (Addoption("Gallivanter Baller LE LWB"))
	{
		GiftVehicle2("BALLER4");
	}
	if (Addoption("Gallivanter Baller LE (Armored)"))
	{
		GiftVehicle2("BALLER5");
	}
	if (Addoption("Pegassi Toros"))
	{
		GiftVehicle2("TOROS");
	}
	if (Addoption("Baller LE LWB (Armored)"))
	{
		GiftVehicle2("BALLER6");
	}
	if (Addoption("Karin BeeJay XL"))
	{
		GiftVehicle2("BJXL");
	}
	if (Addoption("Albany Cavalcade"))
	{
		GiftVehicle2("CAVALCADE");
	}
	if (Addoption("Albany Cavalcade (second generation)"))
	{
		GiftVehicle2("CAVALCADE2");
	}
	if (Addoption("Vapid Contender"))
	{
		GiftVehicle2("CONTENDER");
	}
	if (Addoption("Benefactor Dubsta"))
	{
		GiftVehicle2("DUBSTA");
	}
	if (Addoption("Benefactor Dubsta 6x6"))
	{
		GiftVehicle2("DUBSTA2");
	}
	if (Addoption("Benefactor Streiter"))
	{
		GiftVehicle2("streiter");
	}
	if (Addoption("Fathom FQ 2"))
	{
		GiftVehicle2("FQ2");
	}
	if (Addoption("Declasse Granger"))
	{
		GiftVehicle2("GRANGER");
	}
	if (Addoption("Bravado Gresley"))
	{
		GiftVehicle2("GRESLEY");
	}
	if (Addoption("Vapid Riata"))
	{
		GiftVehicle2("riata");
	}
	if (Addoption("Emperor Habanero"))
	{
		GiftVehicle2("HABANERO");
	}
	if (Addoption("Enus Huntley S"))
	{
		GiftVehicle2("HUNTLEY");
	}
	if (Addoption("Dundreary Landstalker"))
	{
		GiftVehicle2("LANDSTALKER");
	}
	if (Addoption("Canis Mesa"))
	{
		GiftVehicle2("MESA");
	}
	if (Addoption("Canis Mesa Grande(Merryweather)"))
	{
		GiftVehicle2("MESA2");
	}
	if (Addoption("Mammoth Patriot"))
	{
		GiftVehicle2("PATRIOT");
	}
	if (Addoption("Vapid Radius"))
	{
		GiftVehicle2("RADI");
	}
	if (Addoption("Obey Rocoto"))
	{
		GiftVehicle2("ROCOTO");
	}
	if (Addoption("Canis Seminole"))
	{
		GiftVehicle2("SEMINOLE");
	}
	if (Addoption("Benefactor Serrano"))
	{
		GiftVehicle2("SERRANO");
	}
	if (Addoption("Benefactor XLS"))
	{
		GiftVehicle2("XLS");
	}
	if (Addoption("Benefactor XLS (Armored)"))
	{
		GiftVehicle2("XLS2");
	}
}
void Spawner::TrailerspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Trailer");

	if (Settings::currentOption == 1) {
		previewCar("ARMYTANKER");
	}
	if (Settings::currentOption == 2) {
		previewCar("ARMYTRAILER");
	}
	if (Settings::currentOption == 3) {
		previewCar("terbyte");
	}
	if (Settings::currentOption == 4) {
		previewCar("pounder2");
	}
	if (Settings::currentOption == 5) {
		previewCar("ARMYTRAILER2");
	}
	if (Settings::currentOption == 6) {
		previewCar("BALETRAILER");
	}
	if (Settings::currentOption == 7) {
		previewCar("BOATTRAILER");
	}
	if (Settings::currentOption == 8) {
		previewCar("DOCKTRAILER");
	}
	if (Settings::currentOption == 9) {
		previewCar("FREIGHTTRAILER");
	}
	if (Settings::currentOption == 10) {
		previewCar("GRAINTRAILER");
	}
	if (Settings::currentOption == 11) {
		previewCar("PROPTRAILER");
	}
	if (Settings::currentOption == 12) {
		previewCar("RAKETRAILER");
	}
	if (Settings::currentOption == 13) {
		previewCar("TANKER");
	}
	if (Settings::currentOption == 14) {
		previewCar("TANKER2");
	}
	if (Settings::currentOption == 15) {
		previewCar("TR2");
	}
	if (Settings::currentOption == 16) {
		previewCar("TR3");
	}
	if (Settings::currentOption == 17) {
		previewCar("TR4");
	}
	if (Settings::currentOption == 18) {
		previewCar("pbus2");
	}
	if (Settings::currentOption == 19) {
		previewCar("mule4");
	}
	if (Settings::currentOption == 20) {
		previewCar("TRAILERLOGS");
	}
	if (Settings::currentOption == 21) {
		previewCar("TRAILERS");
	}
	if (Settings::currentOption == 22) {
		previewCar("TRAILERS2");
	}
	if (Settings::currentOption == 23) {
		previewCar("TRAILERS3");
	}
	if (Settings::currentOption == 24) {
		previewCar("TRAILERSMALL");
	}
	if (Settings::currentOption == 25) {
		previewCar("TRFLAT");
	}
	if (Settings::currentOption == 26) {
		previewCar("TVTRAILER");
	}

	if (Addoption("Army Trailer(Tanker)"))
	{
		GiftVehicle2("ARMYTANKER");
	}
	if (Addoption("Army Trailer"))
	{
		GiftVehicle2("ARMYTRAILER");
	}
	if (Addoption("Benefactor Terrorbyte"))
	{
		GiftVehicle2("terbyte");
	}
	if (Addoption("MTL Pounder"))
	{
		GiftVehicle2("pounder2");
	}
	if (Addoption("civilian Army Trailer"))
	{
		GiftVehicle2("ARMYTRAILER2");
	}
	if (Addoption("Bale Trailer"))
	{
		GiftVehicle2("BALETRAILER");
	}
	if (Addoption("Boat Trailer"))
	{
		GiftVehicle2("BOATTRAILER");
	}
	if (Addoption("Dock Trailer"))
	{
		GiftVehicle2("DOCKTRAILER");
	}
	if (Addoption("Freight Trailer"))
	{
		GiftVehicle2("FREIGHTTRAILER");
	}
	if (Addoption("Grain Trailer"))
	{
		GiftVehicle2("GRAINTRAILER");
	}
	if (Addoption("Prop Trailer"))
	{
		GiftVehicle2("PROPTRAILER");
	}
	if (Addoption("Rake Trailer"))
	{
		GiftVehicle2("RAKETRAILER");
	}
	if (Addoption("Tanker"))
	{
		GiftVehicle2("TANKER");
	}
	if (Addoption("Tanker(2)"))
	{
		GiftVehicle2("TANKER2");
	}
	if (Addoption("Car Carrier Trailer"))
	{
		GiftVehicle2("TR2");
	}
	if (Addoption("yacht Trailer"))
	{
		GiftVehicle2("TR3");
	}
	if (Addoption("Car Carrier Trailer(With Cars)"))
	{
		GiftVehicle2("TR4");
	}
	if (Addoption("Vapid Festival Bus"))
	{
		GiftVehicle2("pbus2");
	}
	if (Addoption("Maibatsu Mule"))
	{
		GiftVehicle2("mule4");
	}
	if (Addoption("Trailer (logs)"))
	{
		GiftVehicle2("TRAILERLOGS");
	}
	if (Addoption("Trailers"))
	{
		GiftVehicle2("TRAILERS");
	}
	if (Addoption("Trailers"))
	{
		GiftVehicle2("TRAILERS2");
	}
	if (Addoption("Trailers"))
	{
		GiftVehicle2("TRAILERS3");
	}
	if (Addoption("Trailer (small)"))
	{
		GiftVehicle2("TRAILERSMALL");
	}
	if (Addoption("Flat bed"))
	{
		GiftVehicle2("TRFLAT");
	}
	if (Addoption("TV Trailer"))
	{
		GiftVehicle2("TVTRAILER");
	}

}
void Spawner::TranspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Trans");

	if (Settings::currentOption == 1) {
		previewCar("CABLECAR");
	}
	if (Settings::currentOption == 2) {
		previewCar("FREIGHT");
	}
	if (Settings::currentOption == 3) {
		previewCar("FREIGHTCAR");
	}
	if (Settings::currentOption == 4) {
		previewCar("FREIGHTCONT1");
	}
	if (Settings::currentOption == 5) {
		previewCar("FREIGHTCONT2");
	}
	if (Settings::currentOption == 6) {
		previewCar("FREIGHTGRAIN");
	}
	if (Settings::currentOption == 7) {
		previewCar("METROTRAIN");
	}
	if (Settings::currentOption == 8) {
		previewCar("TANKERCAR");
	}

	if (Addoption("Cable Car"))
	{
		GiftVehicle2("CABLECAR");
	}
	if (Addoption("Freight"))
	{
		GiftVehicle2("FREIGHT");
	}
	if (Addoption("Freight Car"))
	{
		GiftVehicle2("FREIGHTCAR");
	}
	if (Addoption("Freight Count(1)"))
	{
		GiftVehicle2("FREIGHTCONT1");
	}
	if (Addoption("Freight Count(2)"))
	{
		GiftVehicle2("FREIGHTCONT2");
	}
	if (Addoption("Freight Grain"))
	{
		GiftVehicle2("FREIGHTGRAIN");
	}
	if (Addoption("Metro Train"))
	{
		GiftVehicle2("METROTRAIN");
	}
	if (Addoption("Tank Car"))
	{
		GiftVehicle2("TANKERCAR");
	}
}
void Spawner::UtilityspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Utility");


	if (Settings::currentOption == 1) {
		previewCar("AIRTUG");
	}
	if (Settings::currentOption == 2) {
		previewCar("CADDY");
	}
	if (Settings::currentOption == 3) {
		previewCar("CADDY2");
	}
	if (Settings::currentOption == 4) {
		previewCar("DOCKTUG");
	}
	if (Settings::currentOption == 5) {
		previewCar("FORKLIFT");
	}
	if (Settings::currentOption == 6) {
		previewCar("MOWER");
	}
	if (Settings::currentOption == 7) {
		previewCar("RIPLEY");
	}
	if (Settings::currentOption == 8) {
		previewCar("SADLER");
	}
	if (Settings::currentOption == 9) {
		previewCar("SADLER2");
	}
	if (Settings::currentOption == 10) {
		previewCar("SCRAP");
	}
	if (Settings::currentOption == 11) {
		previewCar("TOWTRUCK");
	}
	if (Settings::currentOption == 12) {
		previewCar("TOWTRUCK2");
	}
	if (Settings::currentOption == 13) {
		previewCar("kamacho");
	}
	if (Settings::currentOption == 14) {
		previewCar("TRACTOR");
	}
	if (Settings::currentOption == 15) {
		previewCar("TRACTOR2");
	}
	if (Settings::currentOption == 16) {
		previewCar("TRACTOR3");
	}
	if (Settings::currentOption == 17) {
		previewCar("yosemite");
	}
	if (Settings::currentOption == 18) {
		previewCar("UTILLITRUCK");
	}
	if (Settings::currentOption == 19) {
		previewCar("UTILLITRUCK2");
	}
	if (Settings::currentOption == 20) {
		previewCar("UTILLITRUCK3");
	}
	if (Settings::currentOption == 21) {
		previewCar("BISON");
	}
	if (Settings::currentOption == 22) {
		previewCar("BISON2");
	}
	if (Settings::currentOption == 23) {
		previewCar("BISON3");
	}
	if (Settings::currentOption == 24) {
		previewCar("BOBCATXL");
	}
	if (Settings::currentOption == 25) {
		previewCar("BOXVILLE");
	}
	if (Settings::currentOption == 26) {
		previewCar("BOXVILLE2");
	}
	if (Settings::currentOption == 27) {
		previewCar("BOXVILLE3");
	}
	if (Settings::currentOption == 28) {
		previewCar("BOXVILLE4");
	}
	if (Settings::currentOption == 39) {
		previewCar("BURRITO");
	}
	if (Settings::currentOption == 30) {
		previewCar("BURRITO2");
	}
	if (Settings::currentOption == 31) {
		previewCar("BURRITO3");
	}
	if (Settings::currentOption == 32) {
		previewCar("BURRITO4");
	}
	if (Settings::currentOption == 33) {
		previewCar("speedo4");
	}
	if (Settings::currentOption == 34) {
		previewCar("BURRITO5");
	}
	if (Settings::currentOption == 35) {
		previewCar("CAMPER");
	}
	if (Settings::currentOption == 36) {
		previewCar("GBURRITO");
	}
	if (Settings::currentOption == 37) {
		previewCar("GBURRITO2");
	}
	if (Settings::currentOption == 38) {
		previewCar("JOURNEY");
	}
	if (Settings::currentOption == 39) {
		previewCar("MINIVAN");
	}
	if (Settings::currentOption == 40) {
		previewCar("MINIVAN2");
	}
	if (Settings::currentOption == 41) {
		previewCar("PARADISE");
	}
	if (Settings::currentOption == 42) {
		previewCar("PONY");
	}
	if (Settings::currentOption == 43) {
		previewCar("PONY2");
	}
	if (Settings::currentOption == 44) {
		previewCar("RUMPO");
	}
	if (Settings::currentOption == 45) {
		previewCar("RUMPO2");
	}
	if (Settings::currentOption == 46) {
		previewCar("RUMPO3");
	}
	if (Settings::currentOption == 47) {
		previewCar("SPEEDO");
	}
	if (Settings::currentOption == 48) {
		previewCar("SPEEDO2");
	}
	if (Settings::currentOption == 49) {
		previewCar("SURFER");
	}
	if (Settings::currentOption == 50) {
		previewCar("SURFER2");
	}
	if (Settings::currentOption == 51) {
		previewCar("TACO");
	}
	if (Settings::currentOption == 52) {
		previewCar("YOUGA");
	}
	if (Settings::currentOption == 53) {
		previewCar("YOUGA2");
	}

	if (Addoption("HVY Airtug"))
	{
		GiftVehicle2("AIRTUG");
	}
	if (Addoption("Caddy"))
	{
		GiftVehicle2("CADDY");
	}
	if (Addoption("Caddy(2)"))
	{
		GiftVehicle2("CADDY2");
	}
	if (Addoption("HVY Docktug"))
	{
		GiftVehicle2("DOCKTUG");
	}
	if (Addoption("Fork Lift"))
	{
		GiftVehicle2("FORKLIFT");
	}
	if (Addoption("Mower"))
	{
		GiftVehicle2("MOWER");
	}
	if (Addoption("HVY Ripley"))
	{
		GiftVehicle2("RIPLEY");
	}
	if (Addoption("Sadler"))
	{
		GiftVehicle2("SADLER");
	}
	if (Addoption("Sadler(Snow)"))
	{
		GiftVehicle2("SADLER2");
	}
	if (Addoption("Vapid Scrap"))
	{
		GiftVehicle2("SCRAP");
	}
	if (Addoption("Tow Truck"))
	{
		GiftVehicle2("TOWTRUCK");
	}
	if (Addoption("Vapid Towtruck"))
	{
		GiftVehicle2("TOWTRUCK2");
	}
	if (Addoption("Canis Kamacho"))
	{
		GiftVehicle2("kamacho");
	}
	if (Addoption("Tractor(Rusty)"))
	{
		GiftVehicle2("TRACTOR");
	}
	if (Addoption("Tractor"))
	{
		GiftVehicle2("TRACTOR2");
	}
	if (Addoption("Tractor(Snow)"))
	{
		GiftVehicle2("TRACTOR3");
	}
	if (Addoption("Yosemite"))
	{
		GiftVehicle2("yosemite");
	}
	if (Addoption("Cherry Picker"))
	{
		GiftVehicle2("UTILLITRUCK");
	}
	if (Addoption("Flatbed Utility Truck"))
	{
		GiftVehicle2("UTILLITRUCK2");
	}
	if (Addoption("Utility Truck(Pick-Up)"))
	{
		GiftVehicle2("UTILLITRUCK3");
	}
	if (Addoption("Bravado Bison"))
	{
		GiftVehicle2("BISON");
	}
	if (Addoption("Bison(McGill-Olsen)"))
	{
		GiftVehicle2("BISON2");
	}
	if (Addoption("Bison(Mighty Bush)"))
	{
		GiftVehicle2("BISON3");
	}
	if (Addoption("Vapid Bobcat XL"))
	{
		GiftVehicle2("BOBCATXL");
	}
	if (Addoption("BoxVille(LSDWP)"))
	{
		GiftVehicle2("BOXVILLE");
	}
	if (Addoption("BoxVille(GoPostal)"))
	{
		GiftVehicle2("BOXVILLE2");
	}
	if (Addoption("BoxVille(The Humane Labs)"))
	{
		GiftVehicle2("BOXVILLE3");
	}
	if (Addoption("BoxVille(Post OP)"))
	{
		GiftVehicle2("BOXVILLE4");
	}
	if (Addoption("Burrito(LSWP)"))
	{
		GiftVehicle2("BURRITO");
	}
	if (Addoption("Burrito(Bugstars)"))
	{
		GiftVehicle2("BURRITO2");
	}
	if (Addoption("Burrito(second generation)"))
	{
		GiftVehicle2("BURRITO3");
	}
	if (Addoption("Burrito"))
	{
		GiftVehicle2("BURRITO4");
	}
	if (Addoption("Vapid Speedo Custom"))
	{
		GiftVehicle2("speedo");
	}
	if (Addoption("Burrito(Snow)"))
	{
		GiftVehicle2("BURRITO5");
	}
	if (Addoption("Camper Van"))
	{
		GiftVehicle2("CAMPER");
	}
	if (Addoption("Burrito(Lost MC Gang)"))
	{
		GiftVehicle2("GBURRITO");
	}
	if (Addoption("Burrito(standard Gang)"))
	{
		GiftVehicle2("GBURRITO2");
	}
	if (Addoption("Journey"))
	{
		GiftVehicle2("JOURNEY");
	}
	if (Addoption("Vapid Minivan"))
	{
		GiftVehicle2("MINIVAN");
	}
	if (Addoption("Vapid Minivan Custom"))
	{
		GiftVehicle2("MINIVAN2");
	}
	if (Addoption("Bravado Paradise"))
	{
		GiftVehicle2("PARADISE");
	}
	if (Addoption("Pony"))
	{
		GiftVehicle2("PONY");
	}
	if (Addoption("Pony(2)"))
	{
		GiftVehicle2("PONY2");
	}
	if (Addoption("Bravado Rumpo"))
	{
		GiftVehicle2("RUMPO");
	}
	if (Addoption("Bravado Rumpo(2)"))
	{
		GiftVehicle2("RUMPO2");
	}
	if (Addoption("Bravado Rumpo Custom"))
	{
		GiftVehicle2("RUMPO3");
	}
	if (Addoption("Vapid Speedo Custom"))
	{
		GiftVehicle2("SPEEDO");
	}
	if (Addoption("Vapid Clown Van"))
	{
		GiftVehicle2("SPEEDO2");
	}
	if (Addoption("BF Surfer"))
	{
		GiftVehicle2("SURFER");
	}
	if (Addoption("BF Surfer(Rusty)"))
	{
		GiftVehicle2("SURFER2");
	}
	if (Addoption("Brute Taco Van"))
	{
		GiftVehicle2("TACO");
	}
	if (Addoption("Bravado Youga"))
	{
		GiftVehicle2("YOUGA");
	}
	if (Addoption("Bravado Youga Classic"))
	{
		GiftVehicle2("YOUGA2");
	}
}
void Spawner::BoatspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Boat");


	if (Settings::currentOption == 1) {
		previewCar("DINGHY");
	}
	if (Settings::currentOption == 2) {
		previewCar("DINGHY2");
	}
	if (Settings::currentOption == 3) {
		previewCar("DINGHY3");
	}
	if (Settings::currentOption == 4) {
		previewCar("DINGHY4");
	}
	if (Settings::currentOption == 5) {
		previewCar("JETMAX");
	}
	if (Settings::currentOption == 6) {
		previewCar("MARQUIS");
	}
	if (Settings::currentOption == 7) {
		previewCar("PREDATOR");
	}
	if (Settings::currentOption == 8) {
		previewCar("SEASHARK");
	}
	if (Settings::currentOption == 9) {
		previewCar("SEASHARK2");
	}
	if (Settings::currentOption == 10) {
		previewCar("SEASHARK3");
	}
	if (Settings::currentOption == 11) {
		previewCar("SPEEDER");
	}
	if (Settings::currentOption == 12) {
		previewCar("SPEEDER2");
	}
	if (Settings::currentOption == 13) {
		previewCar("SQUALO");
	}
	if (Settings::currentOption == 14) {
		previewCar("SUBMERSIBLE");
	}
	if (Settings::currentOption == 15) {
		previewCar("SUBMERSIBLE2");
	}
	if (Settings::currentOption == 16) {
		previewCar("SUNTRAP");
	}
	if (Settings::currentOption == 17) {
		previewCar("TORO");
	}
	if (Settings::currentOption == 18) {
		previewCar("TORO2");
	}
	if (Settings::currentOption == 19) {
		previewCar("TROPIC");
	}
	if (Settings::currentOption == 20) {
		previewCar("TROPIC2");
	}
	if (Settings::currentOption == 21) {
		previewCar("TUG");
	}

	if (Addoption("Nagasaki Dinghy(4-seater)"))
	{
		GiftVehicle2("DINGHY");
	}
	if (Addoption("Nagasaki Dinghy(2-seater)"))
	{
		GiftVehicle2("DINGHY2");
	}
	if (Addoption("Nagasaki Dinghy(Heists)"))
	{
		GiftVehicle2("DINGHY3");
	}
	if (Addoption("Nagasaki Dinghy(Yacht)"))
	{
		GiftVehicle2("DINGHY4");
	}
	if (Addoption("Shitzu Jetmax"))
	{
		GiftVehicle2("JETMAX");
	}
	if (Addoption("Dinka Marquis"))
	{
		GiftVehicle2("MARQUIS");
	}
	if (Addoption("Police Predator"))
	{
		GiftVehicle2("PREDATOR");
	}
	if (Addoption("Speedophile Seashark"))
	{
		GiftVehicle2("SEASHARK");
	}
	if (Addoption("Speedophile Seashark(Lifeguard )"))
	{
		GiftVehicle2("SEASHARK2");
	}
	if (Addoption("Speedophile Seashark(Yacht)"))
	{
		GiftVehicle2("SEASHARK3");
	}
	if (Addoption("Pegassi Speeder"))
	{
		GiftVehicle2("SPEEDER");
	}
	if (Addoption("Pegassi Speeder(Yacht)"))
	{
		GiftVehicle2("SPEEDER2");
	}
	if (Addoption("Shitzu Squalo"))
	{
		GiftVehicle2("SQUALO");
	}
	if (Addoption("Submersible"))
	{
		GiftVehicle2("SUBMERSIBLE");
	}
	if (Addoption("Tractor"))
	{
		GiftVehicle2("SUBMERSIBLE2");
	}
	if (Addoption("Kraken"))
	{
		GiftVehicle2("SUNTRAP");
	}
	if (Addoption("Lampadati Toro"))
	{
		GiftVehicle2("TORO");
	}
	if (Addoption("Lampadati Toro(Yacht)"))
	{
		GiftVehicle2("TORO2");
	}
	if (Addoption("Shitzu Tropic"))
	{
		GiftVehicle2("TROPIC");
	}
	if (Addoption("Shitzu Tropic(Yacht)"))
	{
		GiftVehicle2("TROPIC2");
	}
	if (Addoption("Tug"))
	{
		GiftVehicle2("TUG");
	}

}
void Spawner::CommercialspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Commercial");

	if (Settings::currentOption == 1) {
		previewCar("BENSON");
	}
	if (Settings::currentOption == 2) {
		previewCar("BIFF");
	}
	if (Settings::currentOption == 3) {
		previewCar("HAULER");
	}
	if (Settings::currentOption == 4) {
		previewCar("MULE");
	}
	if (Settings::currentOption == 5) {
		previewCar("MULE2");
	}
	if (Settings::currentOption == 6) {
		previewCar("MULE3");
	}
	if (Settings::currentOption == 7) {
		previewCar("PACKER");
	}
	if (Settings::currentOption == 8) {
		previewCar("PHANTOM");
	}
	if (Settings::currentOption == 9) {
		previewCar("POUNDER");
	}
	if (Settings::currentOption == 10) {
		previewCar("STOCKADE");
	}
	if (Settings::currentOption == 11) {
		previewCar("STOCKADE3");
	}

	if (Addoption("Benson"))
	{
		GiftVehicle2("BENSON");
	}
	if (Addoption("HVY Biff"))
	{
		GiftVehicle2("BIFF");
	}
	if (Addoption("Jobuilt Hauler"))
	{
		GiftVehicle2("HAULER");
	}
	if (Addoption("Mule"))
	{
		GiftVehicle2("MULE");
	}
	if (Addoption("Mule(2)"))
	{
		GiftVehicle2("MULE2");
	}
	if (Addoption("Mule Custom"))
	{
		GiftVehicle2("MULE3");
	}
	if (Addoption("Packer"))
	{
		GiftVehicle2("PACKER");
	}
	if (Addoption("Jobuilt Phantom"))
	{
		GiftVehicle2("PHANTOM");
	}
	if (Addoption("MTL Pounder "))
	{
		GiftVehicle2("POUNDER");
	}
	if (Addoption("Stockade"))
	{
		GiftVehicle2("STOCKADE");
	}
	if (Addoption("Stockade(Snow)"))
	{
		GiftVehicle2("STOCKADE3");
	}

}

void Spawner::CompactsspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Compacts");

	if (Settings::currentOption == 1) {
		previewCar("RCBANDITO");
	}
	if (Settings::currentOption == 2) {
		previewCar("BLISTA");
	}
	if (Settings::currentOption == 3) {
		previewCar("SLAMVAN4");
	}
	if (Settings::currentOption == 4) {
		previewCar("SLAMVAN5");
	}
	if (Settings::currentOption == 5) {
		previewCar("SLAMVAN6");
	}
	if (Settings::currentOption == 6) {
		previewCar("issi3");
	}
	if (Settings::currentOption == 7) {
		previewCar("ISSI4");
	}
	if (Settings::currentOption == 8) {
		previewCar("ISSI5");
	}
	if (Settings::currentOption == 9) {
		previewCar("ISSI6");
	}
	if (Settings::currentOption == 10) {
		previewCar("DILETTANTE");
	}
	if (Settings::currentOption == 11) {
		previewCar("DILETTANTE2");
	}
	if (Settings::currentOption == 12) {
		previewCar("freecrawler");
	}
	if (Settings::currentOption == 13) {
		previewCar("ISSI2");
	}
	if (Settings::currentOption == 14) {
		previewCar("PANTO");
	}
	if (Settings::currentOption == 15) {
		previewCar("PRAIRIE");
	}
	if (Settings::currentOption == 16) {
		previewCar("gb200");
	}
	if (Settings::currentOption == 17) {
		previewCar("michelli");
	}
	if (Settings::currentOption == 18) {
		previewCar("RHAPSODY");
	}
	if (Settings::currentOption == 19) {
		previewCar("sentinel3");
	}
	if (Settings::currentOption == 20) {
		previewCar("retinue");
	}

	if (Addoption("RC Bandito"))
	{
		GiftVehicle2("RCBANDITO");
	}
	if (Addoption("Blista "))
	{
		GiftVehicle2("BLISTA");
	}
	if (Addoption("Grotti Brioso"))
	{
		GiftVehicle2("BRIOSO");
	}
	if (Addoption("Apocalypse Slamvan"))
	{
		GiftVehicle2("SLAMVAN4");
	}
	if (Addoption("Nightmare Slamvan"))
	{
		GiftVehicle2("SLAMVAN5");
	}
	if (Addoption("Future Shock Slamvan"))
	{
		GiftVehicle2("SLAMVAN6");
	}
	if (Addoption("Apocalypse Issi"))
	{
		GiftVehicle2("issi3");
	}
	if (Addoption("Nightmare Issi"))
	{
		GiftVehicle2("ISSI4");
	}
	if (Addoption("Future Shock Issi"))
	{
		GiftVehicle2("ISSI5");
	}
	if (Addoption("Issi 6"))
	{
		GiftVehicle2("ISSI6");
	}
	if (Addoption("Dilettante"))
	{
		GiftVehicle2("DILETTANTE");
	}
	if (Addoption("Merryweather Dilettante"))
	{
		GiftVehicle2("DILETTANTE2");
	}
	if (Addoption("Canis Freecrawler"))
	{
		GiftVehicle2("freecrawler");
	}
	if (Addoption("Issi"))
	{
		GiftVehicle2("ISSI2");
	}
	if (Addoption("Panto"))
	{
		GiftVehicle2("PANTO");
	}
	if (Addoption("Bollokan Prairie"))
	{
		GiftVehicle2("PRAIRIE");
	}
	if (Addoption("Vapid GB200"))
	{
		GiftVehicle2("gb200");
	}
	if (Addoption("Michelli GT"))
	{
		GiftVehicle2("michelli");
	}
	if (Addoption("Declasse Rhapsody"))
	{
		GiftVehicle2("RHAPSODY");
	}
	if (Addoption("ubermacht Sentinel Classic"))
	{
		GiftVehicle2("sentinel3");
	}
	if (Addoption("Vapid Retinue"))
	{
		GiftVehicle2("retinue");
	}
}

void Spawner::CoupesspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Coupes");


	if (Settings::currentOption == 1) {
		previewCar("COGCABRIO");
	}
	if (Settings::currentOption == 2) {
		previewCar("EXEMPLAR");
	}
	if (Settings::currentOption == 3) {
		previewCar("F620");
	}
	if (Settings::currentOption == 4) {
		previewCar("FELON");
	}
	if (Settings::currentOption == 5) {
		previewCar("FELON2");
	}
	if (Settings::currentOption == 6) {
		previewCar("JACKAL");
	}
	if (Settings::currentOption == 7) {
		previewCar("ORACLE");
	}
	if (Settings::currentOption == 8) {
		previewCar("ORACLE2");
	}
	if (Settings::currentOption == 9) {
		previewCar("SENTINEL");
	}
	if (Settings::currentOption == 10) {
		previewCar("SENTINEL2");
	}
	if (Settings::currentOption == 11) {
		previewCar("WINDSOR2");
	}
	if (Settings::currentOption == 12) {
		previewCar("WINDSOR2");
	}
	if (Settings::currentOption == 13) {
		previewCar("savestra");
	}
	if (Settings::currentOption == 14) {
		previewCar("ZION");
	}
	if (Settings::currentOption == 15) {
		previewCar("ZION2");
	}

	if (Addoption("Enus Cognoscenti Cabrio"))
	{
		GiftVehicle2("COGCABRIO");
	}
	if (Addoption("Dewbauchee Exemplar"))
	{
		GiftVehicle2("EXEMPLAR");
	}
	if (Addoption("Ocelot F620"))
	{
		GiftVehicle2("F620");
	}
	if (Addoption("Lampadati Felon"))
	{
		GiftVehicle2("FELON");
	}
	if (Addoption("Lampadati Felon GT"))
	{
		GiftVehicle2("FELON2");
	}
	if (Addoption("Ocelot Jackal"))
	{
		GiftVehicle2("JACKAL");
	}
	if (Addoption("Ubermacht Oracle "))
	{
		GiftVehicle2("ORACLE");
	}
	if (Addoption("Ubermacht Oracle XS"))
	{
		GiftVehicle2("ORACLE2");
	}
	if (Addoption("Ubermacht Sentinel"))
	{
		GiftVehicle2("SENTINEL");
	}
	if (Addoption("Ubermacht Sentinel XS"))
	{
		GiftVehicle2("SENTINEL2");
	}
	if (Addoption("Enus Windsor"))
	{
		GiftVehicle2("WINDSOR");
	}
	if (Addoption("Enus Windsor Drop"))
	{
		GiftVehicle2("WINDSOR2");
	}
	if (Addoption("Annis Savestra"))
	{
		GiftVehicle2("savestra");
	}
	if (Addoption("Ubermacht Zion"))
	{
		GiftVehicle2("ZION");
	}
	if (Addoption("Ubermacht Zion Cabrio"))
	{
		GiftVehicle2("ZION2");
	}
}
void Spawner::CyclesspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Cycles");

	if (Settings::currentOption == 1) {
		previewCar("BMX");
	}
	if (Settings::currentOption == 2) {
		previewCar("CRUISER");
	}
	if (Settings::currentOption == 3) {
		previewCar("FIXTER");
	}
	if (Settings::currentOption == 4) {
		previewCar("SCORCHER");
	}
	if (Settings::currentOption == 5) {
		previewCar("TRIBIKE");
	}
	if (Settings::currentOption == 6) {
		previewCar("TRIBIKE2");
	}
	if (Settings::currentOption == 7) {
		previewCar("TRIBIKE3");
	}

	if (Addoption("Enus Cognoscenti Cabrio"))
	{
		GiftVehicle2("BMX");
	}
	if (Addoption("Dewbauchee Exemplar"))
	{
		GiftVehicle2("CRUISER");
	}
	if (Addoption("Ocelot F620"))
	{
		GiftVehicle2("FIXTER");
	}
	if (Addoption("Lampadati Felon"))
	{
		GiftVehicle2("SCORCHER");
	}
	if (Addoption("Lampadati Felon GT"))
	{
		GiftVehicle2("TRIBIKE");
	}
	if (Addoption("Ocelot Jackal"))
	{
		GiftVehicle2("TRIBIKE2");
	}
	if (Addoption("Ubermacht Oracle "))
	{
		GiftVehicle2("TRIBIKE3");
	}
}
void Spawner::EmergencyspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Emergency");

	if (Settings::currentOption == 1) {
		previewCar("AMBULANCE");
	}
	if (Settings::currentOption == 2) {
		previewCar("FBI");
	}
	if (Settings::currentOption == 3) {
		previewCar("FBI2");
	}
	if (Settings::currentOption == 4) {
		previewCar("FIRETRUK");
	}
	if (Settings::currentOption == 5) {
		previewCar("LGUARD");
	}
	if (Settings::currentOption == 6) {
		previewCar("PBUS");
	}
	if (Settings::currentOption == 7) {
		previewCar("PRANGER");
	}
	if (Settings::currentOption == 8) {
		previewCar("POLICE");
	}
	if (Settings::currentOption == 9) {
		previewCar("POLICE2");
	}
	if (Settings::currentOption == 10) {
		previewCar("POLICE3");
	}
	if (Settings::currentOption == 11) {
		previewCar("POLICE4");
	}
	if (Settings::currentOption == 12) {
		previewCar("POLICEB");
	}
	if (Settings::currentOption == 13) {
		previewCar("POLICEOLD1");
	}
	if (Settings::currentOption == 14) {
		previewCar("POLICEOLD2");
	}
	if (Settings::currentOption == 15) {
		previewCar("POLICET");
	}
	if (Settings::currentOption == 16) {
		previewCar("SHERIFF");
	}
	if (Settings::currentOption == 17) {
		previewCar("SHERIFF2");
	}
	if (Settings::currentOption == 18) {
		previewCar("RIOT");
	}
	if (Settings::currentOption == 19) {
		previewCar("RIOT2");
	}

	if (Addoption("Ambulance"))
	{
		GiftVehicle2("AMBULANCE");
	}
	if (Addoption("FBI Car"))
	{
		GiftVehicle2("FBI");
	}
	if (Addoption("FBI Rancher"))
	{
		GiftVehicle2("FBI2");
	}
	if (Addoption("FireTruck"))
	{
		GiftVehicle2("FIRETRUK");
	}
	if (Addoption("Declasse Lifeguard"))
	{
		GiftVehicle2("LGUARD");
	}
	if (Addoption("Police Bus"))
	{
		GiftVehicle2("PBUS");
	}
	if (Addoption("Declasse Park Ranger"))
	{
		GiftVehicle2("PRANGER");
	}
	if (Addoption("Police Car"))
	{
		GiftVehicle2("POLICE");
	}
	if (Addoption("Buffalo Police Car"))
	{
		GiftVehicle2("POLICE2");
	}
	if (Addoption("Vapid Police Car"))
	{
		GiftVehicle2("POLICE3");
	}
	if (Addoption("Stockade(Snow)"))
	{
		GiftVehicle2("POLICE4");
	}
	if (Addoption("Western Motorcycle Company Police Bike"))
	{
		GiftVehicle2("POLICEB");
	}
	if (Addoption("Declasse Police Rancher(Snow)"))
	{
		GiftVehicle2("POLICEOLD1");
	}
	if (Addoption("Albany Police Roadcruiser(Snow)"))
	{
		GiftVehicle2("POLICEOLD2");
	}
	if (Addoption("Declasse Police Transporter"))
	{
		GiftVehicle2("POLICET");
	}
	if (Addoption("Vapid Sheriff Cruiser"))
	{
		GiftVehicle2("SHERIFF");
	}
	if (Addoption("Declasse Sheriff SUV"))
	{
		GiftVehicle2("SHERIFF2");
	}
	if (Addoption("Brute Police Riot"))
	{
		GiftVehicle2("RIOT");
	}
	if (Addoption("RCV"))
	{
		GiftVehicle2("RIOT2");
	}

}
void Spawner::HelicoptersspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Helicopter");

	if (Settings::currentOption == 1) {
		previewCar("akula");
	}
	if (Settings::currentOption == 2) {
		previewCar("ANNIHILATOR");
	}
	if (Settings::currentOption == 3) {
		previewCar("BLIMP");
	}
	if (Settings::currentOption == 4) {
		previewCar("BLIMP2");
	}
	if (Settings::currentOption == 5) {
		previewCar("BLIMP3");
	}
	if (Settings::currentOption == 6) {
		previewCar("BUZZARD");
	}
	if (Settings::currentOption == 7) {
		previewCar("BUZZARD2");
	}
	if (Settings::currentOption == 8) {
		previewCar("CARGOBOB");
	}
	if (Settings::currentOption == 9) {
		previewCar("CARGOBOB2");
	}
	if (Settings::currentOption == 10) {
		previewCar("CARGOBOB3");
	}
	if (Settings::currentOption == 11) {
		previewCar("CARGOBOB4");
	}
	if (Settings::currentOption == 12) {
		previewCar("FROGGER");
	}
	if (Settings::currentOption == 13) {
		previewCar("FROGGER2");
	}
	if (Settings::currentOption == 14) {
		previewCar("MAVERICK");
	}
	if (Settings::currentOption == 15) {
		previewCar("havok");
	}
	if (Settings::currentOption == 16) {
		previewCar("hunter");
	}
	if (Settings::currentOption == 17) {
		previewCar("POLMAV");
	}
	if (Settings::currentOption == 18) {
		previewCar("SAVAGE");
	}
	if (Settings::currentOption == 19) {
		previewCar("SKYLIFT");
	}
	if (Settings::currentOption == 20) {
		previewCar("SUPERVOLITO");
	}
	if (Settings::currentOption == 21) {
		previewCar("SUPERVOLITO2");
	}
	if (Settings::currentOption == 22) {
		previewCar("SWIFT");
	}
	if (Settings::currentOption == 23) {
		previewCar("seasparrow");
	}
	if (Settings::currentOption == 24) {
		previewCar("SWIFT2");
	}
	if (Settings::currentOption == 25) {
		previewCar("VALKYRIE");
	}
	if (Settings::currentOption == 26) {
		previewCar("VALKYRIE2");
	}
	if (Settings::currentOption == 27) {
		previewCar("VOLATUS");
	}

	if (Addoption("Akula"))
	{
		GiftVehicle2("akula");
	}
	if (Addoption("Annihilator"))
	{
		GiftVehicle2("ANNIHILATOR");
	}
	if (Addoption("Atomic Blimp"))
	{
		GiftVehicle2("BLIMP");
	}
	if (Addoption("Xero Blimp"))
	{
		GiftVehicle2("BLIMP2");
	}
	if (Addoption("Black Blimp"))
	{
		GiftVehicle2("BLIMP3");
	}
	if (Addoption("Buzzard Attack Chopper"))
	{
		GiftVehicle2("BUZZARD");
	}
	if (Addoption("Buzzard (normal)"))
	{
		GiftVehicle2("BUZZARD2");
	}
	if (Addoption("Cargobob"))
	{
		GiftVehicle2("CARGOBOB");
	}
	if (Addoption("Cargobob 893 (black)"))
	{
		GiftVehicle2("CARGOBOB2");
	}
	if (Addoption("Cargobob (TP Enterprises)"))
	{
		GiftVehicle2("CARGOBOB3");
	}
	if (Addoption("Cargobob(Black)"))
	{
		GiftVehicle2("CARGOBOB4");
	}
	if (Addoption("Frogger"))
	{
		GiftVehicle2("FROGGER");
	}
	if (Addoption("Frogger (TP Enterprises)"))
	{
		GiftVehicle2("FROGGER2");
	}
	if (Addoption("Maverick"))
	{
		GiftVehicle2("MAVERICK");
	}
	if (Addoption("Nagasaki Havok"))
	{
		GiftVehicle2("havok");
	}
	if (Addoption("FH-1 Hunter"))
	{
		GiftVehicle2("hunter");
	}
	if (Addoption("Police Maverick"))
	{
		GiftVehicle2("POLMAV");
	}
	if (Addoption("Savage"))
	{
		GiftVehicle2("SAVAGE");
	}
	if (Addoption("Skylift"))
	{
		GiftVehicle2("SKYLIFT");
	}
	if (Addoption("Buckingham SuperVolito"))
	{
		GiftVehicle2("SUPERVOLITO");
	}
	if (Addoption("Buckingham SuperVolito Carbon"))
	{
		GiftVehicle2("SUPERVOLITO2");
	}
	if (Addoption("Buckingham Swift"))
	{
		GiftVehicle2("SWIFT");
	}
	if (Addoption("Sea Sparrow"))
	{
		GiftVehicle2("seasparrow");
	}
	if (Addoption("Buckingham Swift Deluxe"))
	{
		GiftVehicle2("SWIFT2");
	}
	if (Addoption("Valkyrie"))
	{
		GiftVehicle2("VALKYRIE");
	}
	if (Addoption("Valkyrie MOD.O"))
	{
		GiftVehicle2("VALKYRIE2");
	}
	if (Addoption("Buckingham Volatus"))
	{
		GiftVehicle2("VOLATUS");
	}

}
void Spawner::IndustrialspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Industrial");

	if (Settings::currentOption == 1) {
		previewCar("BULLDOZER");
	}
	if (Settings::currentOption == 2) {
		previewCar("CUTTER");
	}
	if (Settings::currentOption == 3) {
		previewCar("DUMP");
	}
	if (Settings::currentOption == 4) {
		previewCar("FLATBED");
	}
	if (Settings::currentOption == 5) {
		previewCar("GUARDIAN");
	}
	if (Settings::currentOption == 6) {
		previewCar("HANDLER");
	}
	if (Settings::currentOption == 7) {
		previewCar("MIXER");
	}
	if (Settings::currentOption == 8) {
		previewCar("MIXER2");
	}
	if (Settings::currentOption == 9) {
		previewCar("RUBBLE");
	}
	if (Settings::currentOption == 10) {
		previewCar("TIPTRUCK");
	}
	if (Settings::currentOption == 11) {
		previewCar("TIPTRUCK2");
	}
	if (Settings::currentOption == 12) {
		previewCar("CERBERUS");
	}
	if (Settings::currentOption == 13) {
		previewCar("CERBERU2");
	}
	if (Settings::currentOption == 14) {
		previewCar("CERBERU3");
	}

	if (Addoption("HVY Dozer"))
	{
		GiftVehicle2("BULLDOZER");
	}
	if (Addoption("HVY Cutter"))
	{
		GiftVehicle2("CUTTER");
	}
	if (Addoption("HVY Dump"))
	{
		GiftVehicle2("DUMP");
	}
	if (Addoption("MTL Flatbed"))
	{
		GiftVehicle2("FLATBED");
	}
	if (Addoption("Vapid Guardian"))
	{
		GiftVehicle2("GUARDIAN");
	}
	if (Addoption("Dock Handler"))
	{
		GiftVehicle2("HANDLER");
	}
	if (Addoption("HVY Mixer"))
	{
		GiftVehicle2("MIXER");
	}
	if (Addoption("HVY Mixer (dirty)"))
	{
		GiftVehicle2("MIXER2");
	}
	if (Addoption("JoBuilt Rubble"))
	{
		GiftVehicle2("RUBBLE");
	}
	if (Addoption("Brute Tipper (full)"))
	{
		GiftVehicle2("TIPTRUCK");
	}
	if (Addoption("Brute Tipper (empty)"))
	{
		GiftVehicle2("TIPTRUCK2");
	}
	if (Addoption("MTL Apocalypse Cerberus"))
	{
		GiftVehicle2("CERBERUS");
	}
	if (Addoption("MTL Future Shock Cerberus"))
	{
		GiftVehicle2("CERBERUS2");
	}
	if (Addoption("MTL Nightmare Cerberus"))
	{
		GiftVehicle2("CERBERUS3");
	}

}
void Spawner::MilitaryspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Military");

	if (Settings::currentOption == 1) {
		previewCar("BARRACKS");
	}
	if (Settings::currentOption == 2) {
		previewCar("BARRACKS2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BARRACKS3");
	}
	if (Settings::currentOption == 4) {
		previewCar("caracara");
	}
	if (Settings::currentOption == 5) {
		previewCar("barrage");
	}
	if (Settings::currentOption == 6) {
		previewCar("oppressor2");
	}
	if (Settings::currentOption == 7) {
		previewCar("thruster");
	}
	if (Settings::currentOption == 8) {
		previewCar("CRUSADER");
	}
	if (Settings::currentOption == 9) {
		previewCar("SCARAB2");
	}
	if (Settings::currentOption == 10) {
		previewCar("SCARAB3");
	}
	if (Settings::currentOption == 11) {
		previewCar("RHINO");
	}
	if (Settings::currentOption == 12) {
		previewCar("menacer");
	}
	if (Settings::currentOption == 13) {
		previewCar("khanjali");
	}
	if (Settings::currentOption == 14) {
		previewCar("SCARAB");
	}

	if (Addoption("Barracks (black)"))
	{
		GiftVehicle2("BARRACKS");
	}
	if (Addoption("HVY Barracks Semi"))
	{
		GiftVehicle2("BARRACKS2");
	}
	if (Addoption("Barracks (dirty)"))
	{
		GiftVehicle2("BARRACKS3");
	}
	if (Addoption("Vapid Caracara"))
	{
		GiftVehicle2("caracara");
	}
	if (Addoption("Barrage"))
	{
		GiftVehicle2("barrage");
	}
	if (Addoption("Pegassi Oppressor Mk.II"))
	{
		GiftVehicle2("oppressor2");
	}
	if (Addoption("Mamouth Thruster"))
	{
		GiftVehicle2("thruster");
	}
	if (Addoption("Canis Crusader"))
	{
		GiftVehicle2("CRUSADER");
	}
	if (Addoption("HVY Future Shock Scarab"))
	{
		GiftVehicle2("SCARAB2");
	}
	if (Addoption("HVY Nightmare Scarab"))
	{
		GiftVehicle2("SCARAB3");
	}
	if (Addoption("Rhino Tank"))
	{
		GiftVehicle2("RHINO");
	}
	if (Addoption("HVY Menacer"))
	{
		GiftVehicle2("menacer");
	}
	if (Addoption("TM-02 Khanjali"))
	{
		GiftVehicle2("khanjali");
	}
	if (Addoption("HVY Apocalypse Scarab"))
	{
		GiftVehicle2("SCARAB");
	}
}
void Spawner::MotorcyclespinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Motorcycle");


	if (Settings::currentOption == 1) {
		previewCar("AKUMA");
	}
	if (Settings::currentOption == 2) {
		previewCar("AVARUS");
	}
	if (Settings::currentOption == 3) {
		previewCar("BAGGER");
	}
	if (Settings::currentOption == 4) {
		previewCar("BATI");
	}
	if (Settings::currentOption == 5) {
		previewCar("BATI2");
	}
	if (Settings::currentOption == 6) {
		previewCar("DEATHBIKE");
	}
	if (Settings::currentOption == 7) {
		previewCar("DEATHBIKE2");
	}
	if (Settings::currentOption == 8) {
		previewCar("DEATHBIKE3");
	}
	if (Settings::currentOption == 9) {
		previewCar("BF400");
	}
	if (Settings::currentOption == 10) {
		previewCar("CARBONRS");
	}
	if (Settings::currentOption == 11) {
		previewCar("CHIMERA");
	}
	if (Settings::currentOption == 12) {
		previewCar("DAEMON");
	}
	if (Settings::currentOption == 13) {
		previewCar("DAEMON2");
	}
	if (Settings::currentOption == 14) {
		previewCar("DEFILER");
	}
	if (Settings::currentOption == 15) {
		previewCar("DOUBLE");
	}
	if (Settings::currentOption == 16) {
		previewCar("ENDURO");
	}
	if (Settings::currentOption == 17) {
		previewCar("ESSKEY");
	}
	if (Settings::currentOption == 18) {
		previewCar("FAGGIO");
	}
	if (Settings::currentOption == 19) {
		previewCar("FAGGIO2");
	}
	if (Settings::currentOption == 20) {
		previewCar("FAGGIO3");
	}
	if (Settings::currentOption == 21) {
		previewCar("GARGOYLE");
	}
	if (Settings::currentOption == 22) {
		previewCar("HAKUCHOU");
	}
	if (Settings::currentOption == 23) {
		previewCar("HAKUCHOU2");
	}
	if (Settings::currentOption == 24) {
		previewCar("HEXER");
	}
	if (Settings::currentOption == 25) {
		previewCar("INNOVATION");
	}
	if (Settings::currentOption == 26) {
		previewCar("LECTRO");
	}
	if (Settings::currentOption == 27) {
		previewCar("MANCHEZ");
	}
	if (Settings::currentOption == 28) {
		previewCar("NEMESIS");
	}
	if (Settings::currentOption == 39) {
		previewCar("NIGHTBLADE");
	}
	if (Settings::currentOption == 30) {
		previewCar("PCJ");
	}
	if (Settings::currentOption == 31) {
		previewCar("RATBIKE");
	}
	if (Settings::currentOption == 32) {
		previewCar("RUFFIAN");
	}
	if (Settings::currentOption == 33) {
		previewCar("SANCHEZ");
	}
	if (Settings::currentOption == 34) {
		previewCar("SANCHEZ2");
	}
	if (Settings::currentOption == 35) {
		previewCar("SANCTUS");
	}
	if (Settings::currentOption == 36) {
		previewCar("SHOTARO");
	}
	if (Settings::currentOption == 37) {
		previewCar("SOVEREIGN");
	}
	if (Settings::currentOption == 38) {
		previewCar("THRUST");
	}
	if (Settings::currentOption == 39) {
		previewCar("VADER");
	}
	if (Settings::currentOption == 40) {
		previewCar("VINDICATOR");
	}
	if (Settings::currentOption == 41) {
		previewCar("VORTEX");
	}
	if (Settings::currentOption == 42) {
		previewCar("WOLFSBANE");
	}
	if (Settings::currentOption == 43) {
		previewCar("ZOMBIEA");
	}
	if (Settings::currentOption == 44) {
		previewCar("ZOMBIEB");
	}
	if (Settings::currentOption == 45) {
		previewCar("DIABLOUS");
	}
	if (Settings::currentOption == 46) {
		previewCar("DIABLOUS2");
	}
	if (Settings::currentOption == 47) {
		previewCar("DIABLOUS2");
	}
	if (Settings::currentOption == 48) {
		previewCar("FCR");
	}
	if (Settings::currentOption == 49) {
		previewCar("FCR2");
	}
	if (Settings::currentOption == 50) {
		previewCar("oppressor");
	}

	if (Addoption("Dinka Akuma"))
	{
		GiftVehicle2("AKUMA");
	}
	if (Addoption("LCC Avarus"))
	{
		GiftVehicle2("AVARUS");
	}
	if (Addoption("Western Bagger"))
	{
		GiftVehicle2("BAGGER");
	}
	if (Addoption("Pegassi Bati 801"))
	{
		GiftVehicle2("BATI");
	}
	if (Addoption("Pegassi Bati 801RR"))
	{
		GiftVehicle2("BATI2");
	}
	if (Addoption("Western Apocalypse Deathbike"))
	{
		GiftVehicle2("DEATHBIKE");
	}
	if (Addoption("Western Future Shock Deathbike"))
	{
		GiftVehicle2("DEATHBIKE2");
	}
	if (Addoption("Western Nightmare Deathbike"))
	{
		GiftVehicle2("DEATHBIKE3");
	}
	if (Addoption("Nagasaki BF400"))
	{
		GiftVehicle2("BF400");
	}
	if (Addoption("Nagasaki Carbon RS"))
	{
		GiftVehicle2("CARBONRS");
	}
	if (Addoption("Nagasaki Chimera"))
	{
		GiftVehicle2("CHIMERA");
	}
	if (Addoption("Western Cliffhanger"))
	{
		GiftVehicle2("DAEMON");
	}
	if (Addoption("Western Daemon"))
	{
		GiftVehicle2("DAEMON2");
	}
	if (Addoption("Western Daemon (alternate)"))
	{
		GiftVehicle2("DEFILER");
	}
	if (Addoption("Dinka Double-T"))
	{
		GiftVehicle2("DOUBLE");
	}
	if (Addoption("Dinka Enduro"))
	{
		GiftVehicle2("ENDURO");
	}
	if (Addoption("Pegassi Esskey"))
	{
		GiftVehicle2("ESSKEY");
	}
	if (Addoption("Pegassi Faggio Sport"))
	{
		GiftVehicle2("FAGGIO");
	}
	if (Addoption("Pegassi Faggio"))
	{
		GiftVehicle2("FAGGIO2");
	}
	if (Addoption("Pegassi Faggio Mod"))
	{
		GiftVehicle2("FAGGIO3");
	}
	if (Addoption("Western Gargoyle"))
	{
		GiftVehicle2("GARGOYLE");
	}
	if (Addoption("Shitzu Hakuchou"))
	{
		GiftVehicle2("HAKUCHOU");
	}
	if (Addoption("Shitzu Hakuchou Drag"))
	{
		GiftVehicle2("HAKUCHOU2");
	}
	if (Addoption("LCC Hexer"))
	{
		GiftVehicle2("HEXER");
	}
	if (Addoption("LCC Innovation"))
	{
		GiftVehicle2("INNOVATION");
	}
	if (Addoption("Principe Lectro"))
	{
		GiftVehicle2("LECTRO");
	}
	if (Addoption("Maibatsu Manchez"))
	{
		GiftVehicle2("MANCHEZ");
	}
	if (Addoption("Principe Nemesis"))
	{
		GiftVehicle2("NEMESIS");
	}
	if (Addoption("Western Nightblade"))
	{
		GiftVehicle2("NIGHTBLADE");
	}
	if (Addoption("Shitzu PCJ 600"))
	{
		GiftVehicle2("PCJ");
	}
	if (Addoption("Western Rat Bike"))
	{
		GiftVehicle2("RATBIKE");
	}
	if (Addoption("Maibatsu Sanchez (livery)"))
	{
		GiftVehicle2("SANCHEZ");
	}
	if (Addoption("Maibatsu Sanchez"))
	{
		GiftVehicle2("SANCHEZ2");
	}
	if (Addoption("LCC Sanctus"))
	{
		GiftVehicle2("SANCTUS");
	}
	if (Addoption("Nagasaki Shotaro"))
	{
		GiftVehicle2("SHOTARO");
	}
	if (Addoption("Western Sovereign"))
	{
		GiftVehicle2("SOVEREIGN");
	}
	if (Addoption("Dinka Thrust"))
	{
		GiftVehicle2("THRUST");
	}
	if (Addoption("Shitzu Vader"))
	{
		GiftVehicle2("VADER");
	}
	if (Addoption("Dinka Vindicator"))
	{
		GiftVehicle2("VINDICATOR");
	}
	if (Addoption("Pegassi Vortex"))
	{
		GiftVehicle2("VORTEX");
	}
	if (Addoption("Western Wolfsbane"))
	{
		GiftVehicle2("WOLFSBANE");
	}
	if (Addoption("Western Zombie Bobber"))
	{
		GiftVehicle2("ZOMBIEA");
	}
	if (Addoption("Western Zombie Chopper"))
	{
		GiftVehicle2("ZOMBIEB");
	}
	if (Addoption("Principe Diablous"))
	{
		GiftVehicle2("DIABLOUS");
	}
	if (Addoption("Principe Diablous Custom"))
	{
		GiftVehicle2("DIABLOUS2");
	}
	if (Addoption("Pegassi FCR 1000"))
	{
		GiftVehicle2("FCR");
	}
	if (Addoption("Pegassi FCR 1000 Custom"))
	{
		GiftVehicle2("FCR2");
	}
	if (Addoption("Oppressor"))
	{
		GiftVehicle2("oppressor");
	}

}
void Spawner::MusclespinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Muscle");


	if (Settings::currentOption == 1) {
		previewCar("BLADE");
	}
	if (Settings::currentOption == 2) {
		previewCar("BUCCANEER");
	}
	if (Settings::currentOption == 3) {
		previewCar("BUCCANEER2");
	}
	if (Settings::currentOption == 4) {
		previewCar("CHINO");
	}
	if (Settings::currentOption == 5) {
		previewCar("CHINO2");
	}
	if (Settings::currentOption == 6) {
		previewCar("DOMINATOR4");
	}
	if (Settings::currentOption == 7) {
		previewCar("DOMINATOR5");
	}
	if (Settings::currentOption == 8) {
		previewCar("DOMINATOR6");
	}
	if (Settings::currentOption == 9) {
		previewCar("COQUETTE3");
	}
	if (Settings::currentOption == 10) {
		previewCar("DOMINATOR");
	}
	if (Settings::currentOption == 11) {
		previewCar("DOMINATOR2");
	}
	if (Settings::currentOption == 12) {
		previewCar("DUKES");
	}
	if (Settings::currentOption == 13) {
		previewCar("DUKES2");
	}
	if (Settings::currentOption == 14) {
		previewCar("GAUNTLET");
	}
	if (Settings::currentOption == 15) {
		previewCar("GAUNTLET2");
	}
	if (Settings::currentOption == 16) {
		previewCar("FACTION");
	}
	if (Settings::currentOption == 17) {
		previewCar("FACTION2");
	}
	if (Settings::currentOption == 18) {
		previewCar("FACTION3");
	}
	if (Settings::currentOption == 21) {
		previewCar("HOTKNIFE");
	}
	if (Settings::currentOption == 22) {
		previewCar("LURCHER");
	}
	if (Settings::currentOption == 23) {
		previewCar("MOONBEAM");
	}
	if (Settings::currentOption == 24) {
		previewCar("MOONBEAM2");
	}
	if (Settings::currentOption == 25) {
		previewCar("NIGHTSHADE");
	}
	if (Settings::currentOption == 26) {
		previewCar("PHOENIX");
	}
	if (Settings::currentOption == 27) {
		previewCar("PICADOR");
	}
	if (Settings::currentOption == 28) {
		previewCar("RATLOADER");
	}
	if (Settings::currentOption == 29) {
		previewCar("rapidgt3");
	}
	if (Settings::currentOption == 30) {
		previewCar("RATLOADER2");
	}
	if (Settings::currentOption == 31) {
		previewCar("RUINER");
	}
	if (Settings::currentOption == 32) {
		previewCar("RUINER2");
	}
	if (Settings::currentOption == 33) {
		previewCar("RUINER3");
	}
	if (Settings::currentOption == 34) {
		previewCar("SABREGT");
	}
	if (Settings::currentOption == 35) {
		previewCar("SABREGT2");
	}
	if (Settings::currentOption == 36) {
		previewCar("SLAMVAN");
	}
	if (Settings::currentOption == 37) {
		previewCar("SLAMVAN2");
	}
	if (Settings::currentOption == 38) {
		previewCar("SLAMVAN3");
	}
	if (Settings::currentOption == 39) {
		previewCar("STALION");
	}
	if (Settings::currentOption == 40) {
		previewCar("STALION2");
	}
	if (Settings::currentOption == 41) {
		previewCar("TAMPA");
	}
	if (Settings::currentOption == 42) {
		previewCar("VIGERO");
	}
	if (Settings::currentOption == 43) {
		previewCar("VIRGO");
	}
	if (Settings::currentOption == 44) {
		previewCar("VIRGO2");
	}
	if (Settings::currentOption == 45) {
		previewCar("VIRGO3");
	}
	if (Settings::currentOption == 46) {
		previewCar("VOODOO");
	}
	if (Settings::currentOption == 47) {
		previewCar("VOODOO2");
	}

	if (Addoption("Vapid Blade"))
	{
		GiftVehicle2("BLADE");
	}
	if (Addoption("Albany Buccaneer"))
	{
		GiftVehicle2("BUCCANEER");
	}
	if (Addoption("Albany Buccaneer Custom"))
	{
		GiftVehicle2("BUCCANEER2");
	}
	if (Addoption("Vapid Chino"))
	{
		GiftVehicle2("CHINO");
	}
	if (Addoption("Vapid Chino Custom"))
	{
		GiftVehicle2("CHINO2");
	}
	if (Addoption("Vapid Apocalypse Dominator"))
	{
		GiftVehicle2("DOMINATOR4");
	}
	if (Addoption("Vapid Future Shock Dominator"))
	{
		GiftVehicle2("DOMINATOR5");
	}
	if (Addoption("Vapid Nightmare Dominator"))
	{
		GiftVehicle2("DOMINATOR6");
	}
	if (Addoption("Invetro Coquette Blackfin"))
	{
		GiftVehicle2("COQUETTE3");
	}
	if (Addoption("Vapid Dominator"))
	{
		GiftVehicle2("DOMINATOR");
	}
	if (Addoption("Vapid Pisswasser Dominator"))
	{
		GiftVehicle2("DOMINATOR2");
	}
	if (Addoption("Imponte Dukes"))
	{
		GiftVehicle2("DUKES");
	}
	if (Addoption("Imponte Duke o'Death"))
	{
		GiftVehicle2("DUKES2");
	}
	if (Addoption("Bravado Gauntlet"))
	{
		GiftVehicle2("GAUNTLET");
	}
	if (Addoption("Bravado Redwood Gauntlet"))
	{
		GiftVehicle2("GAUNTLET2");
	}
	if (Addoption("Willard Faction"))
	{
		GiftVehicle2("FACTION");
	}
	if (Addoption("Willard Faction Custom"))
	{
		GiftVehicle2("FACTION2");
	}
	if (Addoption("Willard Faction Custom Donk"))
	{
		GiftVehicle2("FACTION3");
	}
	if (Addoption("Vapid Hotknife"))
	{
		GiftVehicle2("HOTKNIFE");
	}
	if (Addoption("Albany Lurcher"))
	{
		GiftVehicle2("LURCHER");
	}
	if (Addoption("Declasse Moonbeam"))
	{
		GiftVehicle2("MOONBEAM");
	}
	if (Addoption("Declasse Moonbeam Custom"))
	{
		GiftVehicle2("MOONBEAM2");
	}
	if (Addoption("Imponte Nightshade"))
	{
		GiftVehicle2("NIGHTSHADE");
	}
	if (Addoption("Imponte Phoenix"))
	{
		GiftVehicle2("PHOENIX");
	}
	if (Addoption("Cheval Picador"))
	{
		GiftVehicle2("PICADOR");
	}
	if (Addoption("Rat-Loader"))
	{
		GiftVehicle2("RATLOADER");
	}
	if (Addoption("Dewbauchee Raid GT Classic"))
	{
		GiftVehicle2("rapidgt3");
	}
	if (Addoption("Bravado Rat Truck"))
	{
		GiftVehicle2("RATLOADER2");
	}
	if (Addoption("Imponte Ruiner"))
	{
		GiftVehicle2("RUINER");
	}
	if (Addoption("Imponte Ruiner 2000"))
	{
		GiftVehicle2("RUINER2");
	}
	if (Addoption("Imponte Ruiner (wrecked)"))
	{
		GiftVehicle2("RUINER3");
	}
	if (Addoption("Declasse Sabre Turbo"))
	{
		GiftVehicle2("SABREGT");
	}
	if (Addoption("Declasse Sabre Turbo"))
	{
		GiftVehicle2("SABREGT2");
	}
	if (Addoption("Vapid Slamvan"))
	{
		GiftVehicle2("SLAMVAN");
	}
	if (Addoption("Vapid Lost Slamvan"))
	{
		GiftVehicle2("SLAMVAN2");
	}
	if (Addoption("Vapid Slamvan Custom"))
	{
		GiftVehicle2("SLAMVAN3");
	}
	if (Addoption("Declasse Stallion"))
	{
		GiftVehicle2("STALION");
	}
	if (Addoption("Declasse Burger Shot Stallion"))
	{
		GiftVehicle2("STALION2");
	}
	if (Addoption("Declasse Tampa"))
	{
		GiftVehicle2("TAMPA");
	}
	if (Addoption("Declasse Vigero"))
	{
		GiftVehicle2("VIGERO");
	}
	if (Addoption("Albany Virgo"))
	{
		GiftVehicle2("VIRGO");
	}
	if (Addoption("Dundreary Virgo Classic Custom"))
	{
		GiftVehicle2("VIRGO2");
	}
	if (Addoption("Dundreary Virgo Classic"))
	{
		GiftVehicle2("VIRGO3");
	}
	if (Addoption("Declasse Voodoo Custom"))
	{
		GiftVehicle2("VOODOO");
	}
	if (Addoption("Declassse Voodoo"))
	{
		GiftVehicle2("VOODOO2");
	}
}
void Spawner::OffRoadspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("OffRoad");


	if (Settings::currentOption == 1) {
		previewCar("BRUISER");
	}
	if (Settings::currentOption == 2) {
		previewCar("BRUISER2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BRUISER3");
	}
	if (Settings::currentOption == 4) {
		previewCar("BRUTUS");
	}
	if (Settings::currentOption == 5) {
		previewCar("BRUTUS2");
	}
	if (Settings::currentOption == 6) {
		previewCar("BRUTUS3");
	}
	if (Settings::currentOption == 7) {
		previewCar("BFINJECTION");
	}
	if (Settings::currentOption == 8) {
		previewCar("BIFTA");
	}
	if (Settings::currentOption == 9) {
		previewCar("BLAZER");
	}
	if (Settings::currentOption == 10) {
		previewCar("BLAZER2");
	}
	if (Settings::currentOption == 11) {
		previewCar("BLAZER3");
	}
	if (Settings::currentOption == 12) {
		previewCar("BLAZER34");
	}
	if (Settings::currentOption == 13) {
		previewCar("BODHI2");
	}
	if (Settings::currentOption == 14) {
		previewCar("BRAWLER");
	}
	if (Settings::currentOption == 15) {
		previewCar("DLOADER");
	}
	if (Settings::currentOption == 16) {
		previewCar("DUBSTA3");
	}
	if (Settings::currentOption == 17) {
		previewCar("DUNE");
	}
	if (Settings::currentOption == 18) {
		previewCar("DUNE2");
	}
	if (Settings::currentOption == 21) {
		previewCar("INSURGENT");
	}
	if (Settings::currentOption == 22) {
		previewCar("INSURGENT2");
	}
	if (Settings::currentOption == 23) {
		previewCar("KALAHARI");
	}
	if (Settings::currentOption == 24) {
		previewCar("MESA3");
	}
	if (Settings::currentOption == 25) {
		previewCar("MONSTER");
	}
	if (Settings::currentOption == 26) {
		previewCar("MONSTER3");
	}
	if (Settings::currentOption == 27) {
		previewCar("MONSTER4");
	}
	if (Settings::currentOption == 28) {
		previewCar("MONSTER5");
	}
	if (Settings::currentOption == 29) {
		previewCar("RANCHERXL");
	}
	if (Settings::currentOption == 30) {
		previewCar("RANCHERXL2");
	}
	if (Settings::currentOption == 31) {
		previewCar("REBEL");
	}
	if (Settings::currentOption == 32) {
		previewCar("REBEL2");
	}
	if (Settings::currentOption == 33) {
		previewCar("SANDKING");
	}
	if (Settings::currentOption == 34) {
		previewCar("SANDKING2");
	}
	if (Settings::currentOption == 35) {
		previewCar("TECHNICAL");
	}
	if (Settings::currentOption == 36) {
		previewCar("TROPHYTRUCK");
	}
	if (Settings::currentOption == 37) {
		previewCar("TROPHYTRUCK2");
	}
	if (Settings::currentOption == 38) {
		previewCar("TECHNICAL2");
	}
	if (Settings::currentOption == 39) {
		previewCar("DUNE4");
	}
	if (Settings::currentOption == 40) {
		previewCar("DUNE5");
	}
	if (Settings::currentOption == 41) {
		previewCar("BLAZER5");
	}

	if (Addoption("Benefactor Apocalypse Bruiser"))
	{
		GiftVehicle2("BRUISER");
	}
	if (Addoption("Benefator Future Shock Bruiser"))
	{
		GiftVehicle2("BRUISER2");
	}
	if (Addoption("Benefactor Nightmare Bruiser"))
	{
		GiftVehicle2("BRUISER3");
	}
	if (Addoption("Declasse Apocalypse Brutus"))
	{
		GiftVehicle2("BRUTUS");
	}
	if (Addoption("Declasse Future Shock Brutus"))
	{
		GiftVehicle2("BRUTUS2");
	}
	if (Addoption("Declasse Nightmare Brutus"))
	{
		GiftVehicle2("BRUTUS3");
	}
	if (Addoption("BF Injection"))
	{
		GiftVehicle2("BFINJECTION");
	}
	if (Addoption("BF Bifta"))
	{
		GiftVehicle2("BIFTA");
	}
	if (Addoption("Nagasaki Blazer"))
	{
		GiftVehicle2("BLAZER");
	}
	if (Addoption("Nagasaki Blazer Lifeguard"))
	{
		GiftVehicle2("BLAZER2");
	}
	if (Addoption("Nagasaki Hot Rod Blazer"))
	{
		GiftVehicle2("BLAZER3");
	}
	if (Addoption("Nagasaki Streeet Blazer"))
	{
		GiftVehicle2("BLAZER4");
	}
	if (Addoption("Canis Bodhi"))
	{
		GiftVehicle2("BODHI2");
	}
	if (Addoption("Coil Brawler"))
	{
		GiftVehicle2("BRAWLER");
	}
	if (Addoption("Bravado Duneloader"))
	{
		GiftVehicle2("DLOADER");
	}
	if (Addoption("Benefactor Dubsta 6x6"))
	{
		GiftVehicle2("DUBSTA3");
	}
	if (Addoption("BF Dune Buggy"))
	{
		GiftVehicle2("DUNE");
	}
	if (Addoption("Space Docker"))
	{
		GiftVehicle2("DUNE2");
	}
	if (Addoption("HVY Insurgent Pick-up"))
	{
		GiftVehicle2("INSURGENT");
	}
	if (Addoption("HVY Insurgent"))
	{
		GiftVehicle2("INSURGENT2");
	}
	if (Addoption("Canis Kalahari"))
	{
		GiftVehicle2("KALAHARI");
	}
	if (Addoption("Cheval Marshall"))
	{
		GiftVehicle2("MARSHALL");
	}
	if (Addoption("Canis Mesa"))
	{
		GiftVehicle2("MESA3");
	}
	if (Addoption("Vapid Liberator"))
	{
		GiftVehicle2("MONSTER");
	}
	if (Addoption("Bravado Apocalypse Sasquatch"))
	{
		GiftVehicle2("MONSTER3");
	}
	if (Addoption("Bravado Future Shock Sasquatch"))
	{
		GiftVehicle2("MONSTER4");
	}
	if (Addoption("Bravado Nightmare Sasquatch"))
	{
		GiftVehicle2("MONSTER5");
	}
	if (Addoption("Declasse Rancher XL"))
	{
		GiftVehicle2("RANCHERXL");
	}
	if (Addoption("Declasse Rancher XL (Snow)"))
	{
		GiftVehicle2("RANCHERXL2");
	}
	if (Addoption("Karin Rusty Rebel"))
	{
		GiftVehicle2("REBEL");
	}
	if (Addoption("Karin Rebel"))
	{
		GiftVehicle2("REBEL2");
	}
	if (Addoption("Vapid Sandking XL"))
	{
		GiftVehicle2("SANDKING");
	}
	if (Addoption("Vapid Sandking SWB"))
	{
		GiftVehicle2("SANDKING2");
	}
	if (Addoption("Karin Technical"))
	{
		GiftVehicle2("TECHNICAL");
	}
	if (Addoption("Vapid Trophy Truck"))
	{
		GiftVehicle2("TROPHYTRUCK");
	}
	if (Addoption("Vapid Trophy Truck"))
	{
		GiftVehicle2("TROPHYTRUCK2");
	}
	if (Addoption("Karin Technical Aqua"))
	{
		GiftVehicle2("TECHNICAL2");
	}
	if (Addoption("Ramp Buggy (Spoiler)"))
	{
		GiftVehicle2("DUNE4");
	}
	if (Addoption("Ramp Buggy"))
	{
		GiftVehicle2("DUNE5");
	}
	if (Addoption("Nagasaki Blazer Aqua"))
	{
		GiftVehicle2("BLAZER5");
	}
}
void Spawner::PlanesspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Planes");


	if (Settings::currentOption == 1) {
		previewCar("alphaz1");
	}
	if (Settings::currentOption == 2) {
		previewCar("avenger");
	}
	if (Settings::currentOption == 3) {
		previewCar("BESRA");
	}
	if (Settings::currentOption == 4) {
		previewCar("bombushka");
	}
	if (Settings::currentOption == 5) {
		previewCar("CARGOPLANE");
	}
	if (Settings::currentOption == 6) {
		previewCar("CUBAN800");
	}
	if (Settings::currentOption == 7) {
		previewCar("DODO");
	}
	if (Settings::currentOption == 8) {
		previewCar("DUSTER");
	}
	if (Settings::currentOption == 9) {
		previewCar("HYDRA");
	}
	if (Settings::currentOption == 10) {
		previewCar("JET");
	}
	if (Settings::currentOption == 11) {
		previewCar("LAZER");
	}
	if (Settings::currentOption == 12) {
		previewCar("LUXOR");
	}
	if (Settings::currentOption == 13) {
		previewCar("LUXOR2");
	}
	if (Settings::currentOption == 14) {
		previewCar("seabreeze");
	}
	if (Settings::currentOption == 15) {
		previewCar("tula");
	}
	if (Settings::currentOption == 16) {
		previewCar("MAMMATUS");
	}
	if (Settings::currentOption == 17) {
		previewCar("MILJET");
	}
	if (Settings::currentOption == 18) {
		previewCar("NIMBUS");
	}
	if (Settings::currentOption == 21) {
		previewCar("ROGUE");
	}
	if (Settings::currentOption == 22) {
		previewCar("STARLING");
	}
	if (Settings::currentOption == 23) {
		previewCar("PYRO");
	}
	if (Settings::currentOption == 24) {
		previewCar("MOGUL");
	}
	if (Settings::currentOption == 25) {
		previewCar("MICROLIGHT");
	}
	if (Settings::currentOption == 26) {
		previewCar("MOLOTOK");
	}
	if (Settings::currentOption == 27) {
		previewCar("NOKOTA");
	}
	if (Settings::currentOption == 28) {
		previewCar("HOWARD");
	}
	if (Settings::currentOption == 29) {
		previewCar("SHAMAL");
	}
	if (Settings::currentOption == 30) {
		previewCar("STRIKEFORCE");
	}
	if (Settings::currentOption == 31) {
		previewCar("STUNT");
	}
	if (Settings::currentOption == 32) {
		previewCar("TITAN");
	}
	if (Settings::currentOption == 33) {
		previewCar("VELUM");
	}
	if (Settings::currentOption == 34) {
		previewCar("VELUM2");
	}
	if (Settings::currentOption == 35) {
		previewCar("VESTRA");
	}
	if (Settings::currentOption == 36) {
		previewCar("VOLATOL");
	}

	if (Addoption("Buckingham Alpha-Z1"))
	{
		GiftVehicle2("alphaz1");
	}
	if (Addoption("Mammoth Avenger"))
	{
		GiftVehicle2("avenger");
	}
	if (Addoption("Western Besra"))
	{
		GiftVehicle2("BESRA");
	}
	if (Addoption("RM-10 Bombushka"))
	{
		GiftVehicle2("bombushka");
	}
	if (Addoption("Cargoplane"))
	{
		GiftVehicle2("CARGOPLANE");
	}
	if (Addoption("Cuban 800"))
	{
		GiftVehicle2("CUBAN800");
	}
	if (Addoption("Mammoth Dodo"))
	{
		GiftVehicle2("DODO");
	}
	if (Addoption("Duster"))
	{
		GiftVehicle2("DUSTER");
	}
	if (Addoption("Mammoth Hydra"))
	{
		GiftVehicle2("HYDRA");
	}
	if (Addoption("Jet"))
	{
		GiftVehicle2("JET");
	}
	if (Addoption("P-996 Lazer"))
	{
		GiftVehicle2("LAZER");
	}
	if (Addoption("Buckingham Luxor"))
	{
		GiftVehicle2("LUXOR");
	}
	if (Addoption("Buckingham Luxor Deluxe"))
	{
		GiftVehicle2("LUXOR2");
	}
	if (Addoption("Western Seabreeze"))
	{
		GiftVehicle2("seabreeze");
	}
	if (Addoption("Western Seabreeze"))
	{
		GiftVehicle2("tula");
	}
	if (Addoption("Mammatus"))
	{
		GiftVehicle2("MAMMATUS");
	}
	if (Addoption("Buckingham Miljet"))
	{
		GiftVehicle2("MILJET");
	}
	if (Addoption("Buckingham Nimbus"))
	{
		GiftVehicle2("NIMBUS");
	}
	if (Addoption("Western Rogue"))
	{
		GiftVehicle2("ROGUE");
	}
	if (Addoption("LF-22 Starling"))
	{
		GiftVehicle2("STARLING");
	}
	if (Addoption("Pyro"))
	{
		GiftVehicle2("PYRO");
	}
	if (Addoption("Mammoth Mogul"))
	{
		GiftVehicle2("mogul");
	}
	if (Addoption("Nagasaki Ultralight"))
	{
		GiftVehicle2("microlight");
	}
	if (Addoption("V-65 Molotok"))
	{
		GiftVehicle2("molotok");
	}
	if (Addoption("P-45 Nokota"))
	{
		GiftVehicle2("nokota");
	}
	if (Addoption("Buckingham Howard NX-25"))
	{
		GiftVehicle2("howard");
	}
	if (Addoption("Buckinghma Shamal"))
	{
		GiftVehicle2("SHAMAL");
	}
	if (Addoption("B-11 Strikeforce"))
	{
		GiftVehicle2("strikeforce");
	}
	if (Addoption("Mallard"))
	{
		GiftVehicle2("STUNT");
	}
	if (Addoption("Titan"))
	{
		GiftVehicle2("TITAN");
	}
	if (Addoption("Velum"))
	{
		GiftVehicle2("VELUM");
	}
	if (Addoption("Velum 5-seater"))
	{
		GiftVehicle2("VELUM2");
	}
	if (Addoption("Buckingham Vestra"))
	{
		GiftVehicle2("VESTRA");
	}
	if (Addoption("Volatol"))
	{
		GiftVehicle2("volatol");
	}
}
void Spawner::SedansspinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Sedans");


	if (Settings::currentOption == 1) {
		previewCar("ASEA");
	}
	if (Settings::currentOption == 2) {
		previewCar("ASEA2");
	}
	if (Settings::currentOption == 3) {
		previewCar("ASTEROPE");
	}
	if (Settings::currentOption == 4) {
		previewCar("COG55");
	}
	if (Settings::currentOption == 5) {
		previewCar("COG552");
	}
	if (Settings::currentOption == 6) {
		previewCar("COGNOSCENTI");
	}
	if (Settings::currentOption == 7) {
		previewCar("COGNOSCENTI2");
	}
	if (Settings::currentOption == 8) {
		previewCar("EMPEROR3");
	}
	if (Settings::currentOption == 9) {
		previewCar("FUGITIVE");
	}
	if (Settings::currentOption == 10) {
		previewCar("GLENDALE");
	}
	if (Settings::currentOption == 11) {
		previewCar("INGOT");
	}
	if (Settings::currentOption == 12) {
		previewCar("INTRUDER");
	}
	if (Settings::currentOption == 13) {
		previewCar("LIMO2");
	}
	if (Settings::currentOption == 14) {
		previewCar("PREMIER");
	}
	if (Settings::currentOption == 15) {
		previewCar("PRIMO");
	}
	if (Settings::currentOption == 16) {
		previewCar("PRIMO2");
	}
	if (Settings::currentOption == 17) {
		previewCar("REGINA");
	}
	if (Settings::currentOption == 18) {
		previewCar("ROMERO");
	}
	if (Settings::currentOption == 21) {
		previewCar("SCHAFTER2");
	}
	if (Settings::currentOption == 22) {
		previewCar("SCHAFTER5");
	}
	if (Settings::currentOption == 23) {
		previewCar("SCHAFTER6");
	}
	if (Settings::currentOption == 24) {
		previewCar("STANIER");
	}
	if (Settings::currentOption == 25) {
		previewCar("STRATUM");
	}
	if (Settings::currentOption == 26) {
		previewCar("STRETCH");
	}
	if (Settings::currentOption == 27) {
		previewCar("SUPERD");
	}
	if (Settings::currentOption == 28) {
		previewCar("SURGE");
	}
	if (Settings::currentOption == 29) {
		previewCar("TAILGATER");
	}
	if (Settings::currentOption == 30) {
		previewCar("WARRENER");
	}
	if (Settings::currentOption == 31) {
		previewCar("WASHINGTON");
	}

	if (Addoption("Declasse Asea"))
	{
		GiftVehicle2("ASEA");
	}
	if (Addoption("Declasse Asea (Snow)"))
	{
		GiftVehicle2("ASEA2");
	}
	if (Addoption("Karin Asterope"))
	{
		GiftVehicle2("ASTEROPE");
	}
	if (Addoption("Enus Cognoscenti 55"))
	{
		GiftVehicle2("COG55");
	}
	if (Addoption("Enus Cognoscenti 55 (armoured)"))
	{
		GiftVehicle2("COG552");
	}
	if (Addoption("Enus Cognoscenti"))
	{
		GiftVehicle2("COGNOSCENTI");
	}
	if (Addoption("Enus Cognoscenti (armoured)"))
	{
		GiftVehicle2("COGNOSCENTI2");
	}
	if (Addoption("Albany Emperor"))
	{
		GiftVehicle2("EMPEROR");
	}
	if (Addoption("Albany Emperor (dirty)"))
	{
		GiftVehicle2("EMPEROR2");
	}
	if (Addoption("Albany Emperor (Snow)"))
	{
		GiftVehicle2("EMPEROR3");
	}
	if (Addoption("Cheval Fugitive"))
	{
		GiftVehicle2("FUGITIVE");
	}
	if (Addoption("Benefactor Glendale"))
	{
		GiftVehicle2("GLENDALE");
	}
	if (Addoption("Vulcan Ingot"))
	{
		GiftVehicle2("INGOT");
	}
	if (Addoption("Karin Intruder"))
	{
		GiftVehicle2("INTRUDER");
	}
	if (Addoption("Benefactor Turreted Limo"))
	{
		GiftVehicle2("LIMO2");
	}
	if (Addoption("Declasse Premier"))
	{
		GiftVehicle2("PREMIER");
	}
	if (Addoption("Albany Primo"))
	{
		GiftVehicle2("PRIMO");
	}
	if (Addoption("Albany Primo Custom"))
	{
		GiftVehicle2("PRIMO2");
	}
	if (Addoption("Dundreary Regina"))
	{
		GiftVehicle2("REGINA");
	}
	if (Addoption("Chariot Romero Hearse"))
	{
		GiftVehicle2("ROMERO");
	}
	if (Addoption("Benefactor Schafter"))
	{
		GiftVehicle2("SCHAFTER2");
	}
	if (Addoption("Benefactor Schafter V12 (armoured)"))
	{
		GiftVehicle2("SCHAFTER5");
	}
	if (Addoption("Benefactor Schafter LWB (armoured)"))
	{
		GiftVehicle2("SCHAFTER6");
	}
	if (Addoption("Vapid Stanier"))
	{
		GiftVehicle2("STANIER");
	}
	if (Addoption("Zinconium Stratum"))
	{
		GiftVehicle2("STRATUM");
	}
	if (Addoption("Dundreary Stretch"))
	{
		GiftVehicle2("STRETCH");
	}
	if (Addoption("Enus Super Diamond"))
	{
		GiftVehicle2("SUPERD");
	}
	if (Addoption("Cheval Surge"))
	{
		GiftVehicle2("SURGE");
	}
	if (Addoption("Obey Tailgater"))
	{
		GiftVehicle2("TAILGATER");
	}
	if (Addoption("Vulcan Warrener"))
	{
		GiftVehicle2("WARRENER");
	}
	if (Addoption("Albany Washington"))
	{
		GiftVehicle2("WASHINGTON");
	}
}
void Spawner::ServicespinSpawnergift()
{
	Addtitle("");
	Addsubtitle("Service");
	if (Settings::currentOption == 1) {
		previewCar("AIRBUS");
	}
	if (Settings::currentOption == 2) {
		previewCar("BRICKADE");
	}
	if (Settings::currentOption == 3) {
		previewCar("BUS");
	}
	if (Settings::currentOption == 4) {
		previewCar("COACH");
	}
	if (Settings::currentOption == 5) {
		previewCar("RALLYTRUCK");
	}
	if (Settings::currentOption == 6) {
		previewCar("RENTALBUS");
	}
	if (Settings::currentOption == 7) {
		previewCar("TAXI");
	}
	if (Settings::currentOption == 8) {
		previewCar("MIXER2");
	}
	if (Settings::currentOption == 9) {
		previewCar("patriot2");
	}
	if (Settings::currentOption == 10) {
		previewCar("TOURBUS");
	}
	if (Settings::currentOption == 11) {
		previewCar("TRASH");
	}
	if (Settings::currentOption == 12) {
		previewCar("TRASH2");
	}
	if (Settings::currentOption == 13) {
		previewCar("WASTELANDER");
	}

	if (Addoption("Airport Bus"))
	{
		GiftVehicle2("AIRBUS");
	}
	if (Addoption("MTL Brickade"))
	{
		GiftVehicle2("BRICKADE");
	}
	if (Addoption("MTL Brickade"))
	{
		GiftVehicle2("BUS");
	}
	if (Addoption("Dashound"))
	{
		GiftVehicle2("COACH");
	}
	if (Addoption("MTL Dune"))
	{
		GiftVehicle2("RALLYTRUCK");
	}
	if (Addoption("Rental Shuttle Bus"))
	{
		GiftVehicle2("RENTALBUS");
	}
	if (Addoption("Taxi"))
	{
		GiftVehicle2("TAXI");
	}
	if (Addoption("Mammoth Patriot Stretch"))
	{
		GiftVehicle2("patriot2");
	}
	if (Addoption("Tourbus"))
	{
		GiftVehicle2("TOURBUS");
	}
	if (Addoption("Trashmaster"))
	{
		GiftVehicle2("TRASH");
	}
	if (Addoption("Trashmaster (dirty)"))
	{
		GiftVehicle2("TRASH2");
	}
	if (Addoption("MTL Wastelander"))
	{
		GiftVehicle2("WASTELANDER");
	}
}
















void Spawner::cayospinSpawner()
{
	Menu::Title("");
	Menu::SubTitle("Cayo Perico");
	if (Settings::currentOption == 1) {
		previewCar("ALKONOST");
	}
	if (Settings::currentOption == 2) {
		previewCar("ANNIHILATOR2");
	}
	if (Settings::currentOption == 3) {
		previewCar("AVISA");
	}
	if (Settings::currentOption == 4) {
		previewCar("BRIOSO2");
	}
	if (Settings::currentOption == 5) {
		previewCar("DINGHY5");
	}
	if (Settings::currentOption == 6) {
		previewCar("ITALIRSX");
	}
	if (Settings::currentOption == 7) {
		previewCar("KOSATKA");
	}
	if (Settings::currentOption == 8) {
		previewCar("LONGFIN");
	}
	if (Settings::currentOption == 9) {
		previewCar("MANCHEZ2");
	}
	if (Settings::currentOption == 10) {
		previewCar("PATROLBOAT");
	}
	if (Settings::currentOption == 11) {
		previewCar("SEASPARROW2");
	}
	if (Settings::currentOption == 12) {
		previewCar("SLAMTRUCK");
	}
	if (Settings::currentOption == 13) {
		previewCar("SQUADDIE");
	}
	if (Settings::currentOption == 14) {
		previewCar("TOREADOR");
	}
	if (Settings::currentOption == 15) {
		previewCar("VERUS");
	}
	if (Settings::currentOption == 16) {
		previewCar("VETIR");
	}
	if (Settings::currentOption == 17) {
		previewCar("VETO");
	}
	if (Settings::currentOption == 18) {
		previewCar("VETO2");
	}
	if (Settings::currentOption == 19) {
		previewCar("WEEVIL");
	}
	if (Settings::currentOption == 20) {
		previewCar("WINKY");
	}
	if (Addoption("Alkonost"))
	{
		SpawnVehicle("ALKONOST");
	}
	if (Addoption("Annihilator 2"))
	{
		SpawnVehicle("ANNIHILATOR2");
	}
	if (Menu::Option("Avisa"))
	{
		SpawnVehicle("AVISA");
	}
	if (Addoption("Brioso 2"))
	{
		SpawnVehicle("BRIOSO2");
	}
	if (Addoption("Dinghy 5"))
	{
		SpawnVehicle("DINGHY5");
	}
	if (Addoption("Itali RSX"))
	{
		SpawnVehicle("ITALIRSX");
	}
	if (Addoption("Kosatka"))
	{
		SpawnVehicle("KOSATKA");
	}
	if (Addoption("Longfin"))
	{
		SpawnVehicle("LONGFIN");
	}
	if (Addoption("Manchez 2"))
	{
		SpawnVehicle("MANCHEZ2");
	}
	if (Addoption("Patrol Boat"))
	{
		SpawnVehicle("PATROLBOAT");
	}
	if (Addoption("Sea Sparrow 2"))
	{
		SpawnVehicle("SEASPARROW2");
	}
	if (Addoption("Slam Truck"))
	{
		SpawnVehicle("SLAMTRUCK ");
	}
	if (Addoption("Squaddie"))
	{
		SpawnVehicle("SQUADDIE");
	}
	if (Addoption("Toreador"))
	{
		SpawnVehicle("TOREADOR");
	}
	if (Addoption("Versus"))
	{
		SpawnVehicle("VERUS");
	}
	if (Addoption("Vetir"))
	{
		SpawnVehicle("VETIR");
	}
	if (Addoption("Veto"))
	{
		SpawnVehicle("VETO");
	}
	if (Addoption("Veto"))
	{
		SpawnVehicle("VETO2");
	}
	if (Addoption("Weevil"))
	{
		SpawnVehicle("WEEVIL");
	}
	if (Addoption("Winky"))
	{
		SpawnVehicle("WINKY");
	}
}

void Spawner::summerspinSpawner()
{
	Menu::Title("");
	Menu::SubTitle("Summer Update");
	if (Settings::currentOption == 1) {
		previewCar("CLUB");
	}
	if (Settings::currentOption == 2) {
		previewCar("COQUETTE4");
	}
	if (Settings::currentOption == 3) {
		previewCar("DUKES3");
	}
	if (Settings::currentOption == 4) {
		previewCar("GAUNTLET5");
	}
	if (Settings::currentOption == 5) {
		previewCar("GLENDALE2");
	}
	if (Settings::currentOption == 6) {
		previewCar("MANANA2");
	}
	if (Settings::currentOption == 7) {
		previewCar("OPENWHEEL1");
	}
	if (Settings::currentOption == 8) {
		previewCar("OPENWHEEL2");
	}
	if (Settings::currentOption == 9) {
		previewCar("PENUMBRA2");
	}
	if (Settings::currentOption == 10) {
		previewCar("PEYOTE3");
	}
	if (Settings::currentOption == 11) {
		previewCar("SEMINOLE2");
	}
	if (Settings::currentOption == 12) {
		previewCar("TIGON");
	}
	if (Settings::currentOption == 13) {
		previewCar("YOSEMITE3");
	}
	if (Settings::currentOption == 14) {
		previewCar("YOUGA3");
	}
	if (Addoption("Club"))
	{
		SpawnVehicle("CLUB");
	}
	if (Addoption("Coquette 4"))
	{
		SpawnVehicle("COQUETTE4");
	}
	if (Menu::Option("Dukes 3"))
	{
		SpawnVehicle("DUKES3");
	}
	if (Addoption("Gauntlet 5"))
	{
		SpawnVehicle("GAUNTLET5");
	}
	if (Addoption("Glendale 2"))
	{
		SpawnVehicle("GLENDALE2");
	}
	if (Addoption("Manana 2"))
	{
		SpawnVehicle("MANANA2");
	}
	if (Addoption("OpenWheel 1"))
	{
		SpawnVehicle("OPENWHEEL1");
	}
	if (Addoption("OpenWheel 2"))
	{
		SpawnVehicle("OPENWHEEL2");
	}
	if (Addoption("Penumbra 2"))
	{
		SpawnVehicle("PENUMBRA2");
	}
	if (Addoption("Peyote 3"))
	{
		SpawnVehicle("PEYOTE3");
	}
	if (Addoption("Seminole 2"))
	{
		SpawnVehicle("SEMINOLE2");
	}
	if (Addoption("Tigon"))
	{
		SpawnVehicle("TIGON");
	}
	if (Addoption("Yosemite 3"))
	{
		SpawnVehicle("YOSEMITE3");
	}
	if (Addoption("Youga 3"))
	{
		SpawnVehicle("YOUGA3");
	}



}



void Spawner::sportspinSpawner()
{
	Menu::Title("");
	Menu::SubTitle("Sport");


	if (Settings::currentOption == 1) {
		previewCar("ALPHA");
	}
	if (Settings::currentOption == 2) {
		previewCar("BANSHEE");
	}
	if (Settings::currentOption == 3) {
		previewCar("flashgt");
	}
	if (Settings::currentOption == 4) {
		previewCar("BESTIAGTS");
	}
	if (Settings::currentOption == 5) {
		previewCar("BLISTA2");
	}
	if (Settings::currentOption == 6) {
		previewCar("BLISTA3");
	}
	if (Settings::currentOption == 7) {
		previewCar("ITALIGTO");
	}
	if (Settings::currentOption == 8) {
		previewCar("SCHLAGEN");
	}
	if (Settings::currentOption == 9) {
		previewCar("BUFFALO");
	}
	if (Settings::currentOption == 10) {
		previewCar("BUFFALO2");
	}
	if (Settings::currentOption == 11) {
		previewCar("BUFFALO3");
	}
	if (Settings::currentOption == 12) {
		previewCar("swinger");
	}
	if (Settings::currentOption == 13) {
		previewCar("comet4");
	}
	if (Settings::currentOption == 14) {
		previewCar("comet5");
	}
	if (Settings::currentOption == 15) {
		previewCar("CARBONIZZARE");
	}
	if (Settings::currentOption == 16) {
		previewCar("COMET2");
	}
	if (Settings::currentOption == 17) {
		previewCar("COQUETTE");
	}
	if (Settings::currentOption == 18) {
		previewCar("cyclone");
	}
	if (Settings::currentOption == 19) {
		previewCar("ELEGY");
	}
	if (Settings::currentOption == 20) {
		previewCar("ELEGY2");
	}
	if (Settings::currentOption == 21) {
		previewCar("FELTZER2");
	}
	if (Settings::currentOption == 22) {
		previewCar("FUROREGT");
	}
	if (Settings::currentOption == 23) {
		previewCar("FUSILADE");
	}
	if (Settings::currentOption == 24) {
		previewCar("FUTO");
	}
	if (Settings::currentOption == 25) {
		previewCar("JESTER");
	}
	if (Settings::currentOption == 26) {
		previewCar("JESTER2");
	}
	if (Settings::currentOption == 27) {
		previewCar("dominator3");
	}
	if (Settings::currentOption == 28) {
		previewCar("KHAMELION");
	}
	if (Settings::currentOption == 39) {
		previewCar("KURUMA");
	}
	if (Settings::currentOption == 30) {
		previewCar("ZR380");
	}
	if (Settings::currentOption == 31) {
		previewCar("ZR3802");
	}
	if (Settings::currentOption == 32) {
		previewCar("ZR3803");
	}
	if (Settings::currentOption == 33) {
		previewCar("KURUMA2");
	}
	if (Settings::currentOption == 34) {
		previewCar("LYNX");
	}
	if (Settings::currentOption == 35) {
		previewCar("MASSACRO");
	}
	if (Settings::currentOption == 36) {
		previewCar("MASSACRO2");
	}
	if (Settings::currentOption == 37) {
		previewCar("pariah");
	}
	if (Settings::currentOption == 38) {
		previewCar("raiden");
	}
	if (Settings::currentOption == 39) {
		previewCar("NINEF");
	}
	if (Settings::currentOption == 40) {
		previewCar("NINEF2");
	}
	if (Settings::currentOption == 41) {
		previewCar("OMNIS");
	}
	if (Settings::currentOption == 42) {
		previewCar("PENUMBRA");
	}
	if (Settings::currentOption == 43) {
		previewCar("RAPIDGT");
	}
	if (Settings::currentOption == 44) {
		previewCar("tyrant");
	}
	if (Settings::currentOption == 45) {
		previewCar("hotring");
	}
	if (Settings::currentOption == 46) {
		previewCar("ellie");
	}
	if (Settings::currentOption == 47) {
		previewCar("RAPIDGT2");
	}
	if (Settings::currentOption == 48) {
		previewCar("RAPTOR");
	}
	if (Settings::currentOption == 49) {
		previewCar("SCHAFTER3");
	}
	if (Settings::currentOption == 50) {
		previewCar("SCHAFTER4");
	}
	if (Settings::currentOption == 51) {
		previewCar("taipan");
	}
	if (Settings::currentOption == 52) {
		previewCar("SCHWARZER");
	}
	if (Settings::currentOption == 53) {
		previewCar("jester3");
	}
	if (Settings::currentOption == 54) {
		previewCar("SEVEN70");
	}
	if (Settings::currentOption == 55) {
		previewCar("SULTAN");
	}
	if (Settings::currentOption == 56) {
		previewCar("SURANO");
	}
	if (Settings::currentOption == 57) {
		previewCar("SPECTER");
	}
	if (Settings::currentOption == 58) {
		previewCar("SPECTER2");
	}
	if (Settings::currentOption == 59) {
		previewCar("scramjet");
	}
	if (Settings::currentOption == 60) {
		previewCar("TAMPA2");
	}
	if (Settings::currentOption == 61) {
		previewCar("TROPOS");
	}
	if (Settings::currentOption == 62) {
		previewCar("VERLIERER2");
	}
	if (Settings::currentOption == 63) {
		previewCar("RUINER2");
	}
	if (Settings::currentOption == 64) {
		previewCar("PHANTOM2");
	}
	if (Settings::currentOption == 65) {
		previewCar("RUSTON");
	}

	if (Addoption("Alpha"))
	{
		SpawnVehicle("ALPHA");
	}
	if (Addoption("Bravado Banshee"))
	{
		SpawnVehicle("BANSHEE");
	}
	if (Addoption("Vapid Flash GT"))
	{
		SpawnVehicle("flashgt");
	}
	if (Addoption("Grotti Bestia GTS"))
	{
		SpawnVehicle("BESTIAGTS");
	}
	if (Addoption("Dinka Blista Compact"))
	{
		SpawnVehicle("BLISTA2");
	}
	if (Addoption("Dinka Go Go Money Blista"))
	{
		SpawnVehicle("BLISTA3");
	}
	if (Addoption("Grotti Itali GTO"))
	{
		SpawnVehicle("ITALIGTO");
	}
	if (Addoption("Benefactor Schlagen GT"))
	{
		SpawnVehicle("SCHLAGEN");
	}
	if (Addoption("Bravado Buffalo"))
	{
		SpawnVehicle("BUFFALO");
	}
	if (Addoption("Bravado Buffalo S"))
	{
		SpawnVehicle("BUFFALO2");
	}
	if (Addoption("Bravado Sprunk Buffalo"))
	{
		SpawnVehicle("BUFFALO3");
	}
	if (Addoption("Ocelot Swinger"))
	{
		SpawnVehicle("swinger");
	}
	if (Addoption("Phister Comet Safari"))
	{
		SpawnVehicle("comet4");
	}
	if (Addoption("Phister Comet SR"))
	{
		SpawnVehicle("comet5");
	}
	if (Addoption("Grotti Carbonizzare"))
	{
		SpawnVehicle("CARBONIZZARE");
	}
	if (Addoption("Phister Comet"))
	{
		SpawnVehicle("COMET2");
	}
	if (Addoption("Inverto Coquette"))
	{
		SpawnVehicle("COQUETTE");
	}
	if (Addoption("Coil Cyclone"))
	{
		SpawnVehicle("cyclone");
	}
	if (Addoption("Annis Elegy Retro Custom"))
	{
		SpawnVehicle("ELEGY");
	}
	if (Addoption("Annis Elegy RH8"))
	{
		SpawnVehicle("ELEGY2");
	}
	if (Addoption("Benefactor Feltzer"))
	{
		SpawnVehicle("FELTZER2");
	}
	if (Addoption("Lampadeti Furore GT"))
	{
		SpawnVehicle("FUROREGT");
	}
	if (Addoption("Schyster Fusilade"))
	{
		SpawnVehicle("FUSILADE");
	}
	if (Addoption("Karin Futo"))
	{
		SpawnVehicle("FUTO");
	}
	if (Addoption("Dinka Jester"))
	{
		SpawnVehicle("JESTER");
	}
	if (Addoption("Dinka Jester (racecar)"))
	{
		SpawnVehicle("JESTER2");
	}
	if (Addoption("Vapid Dominator GTX"))
	{
		SpawnVehicle("dominator3");
	}
	if (Addoption("Hijak Khamelion"))
	{
		SpawnVehicle("KHAMELION");
	}
	if (Addoption("Karin Kuruma"))
	{
		SpawnVehicle("KURUMA");
	}
	if (Addoption("Annis Apocalypse ZR380"))
	{
		SpawnVehicle("ZR380");
	}
	if (Addoption("Annis Future Shock ZR380"))
	{
		SpawnVehicle("ZR3802");
	}
	if (Addoption("Annis Nightmare ZR380"))
	{
		SpawnVehicle("ZR3803");
	}
	if (Addoption("Karin Karuma (armoured)"))
	{
		SpawnVehicle("KURUMA2");
	}
	if (Addoption("Ocelot Lynx"))
	{
		SpawnVehicle("LYNX");
	}
	if (Addoption("Dewbauchdee Massacro"))
	{
		SpawnVehicle("MASSACRO");
	}
	if (Addoption("Dewbauchdee Massacro (racecar)"))
	{
		SpawnVehicle("MASSACRO2");
	}
	if (Addoption("Ocelot Pariah"))
	{
		SpawnVehicle("pariah");
	}
	if (Addoption("Coil Raiden"))
	{
		SpawnVehicle("raiden");
	}
	if (Addoption("Obey 9F"))
	{
		SpawnVehicle("NINEF");
	}
	if (Addoption("Obey 9F Cabrio"))
	{
		SpawnVehicle("NINEF2");
	}
	if (Addoption("Obey Omnis"))
	{
		SpawnVehicle("OMNIS");
	}
	if (Addoption("Maibatsu Penumbra"))
	{
		SpawnVehicle("PENUMBRA");
	}
	if (Addoption("Dewbauchee Rapid GT"))
	{
		SpawnVehicle("RAPIDGT");
	}
	if (Addoption("Overflod Tyrant"))
	{
		SpawnVehicle("tyrant");
	}
	if (Addoption("Declasse Hotring Sabre"))
	{
		SpawnVehicle("hotring");
	}
	if (Addoption("Vapid Ellie"))
	{
		SpawnVehicle("ellie");
	}
	if (Addoption("Dewbauchee Rapid GT (convertable)"))
	{
		SpawnVehicle("RAPIDGT2");
	}
	if (Addoption("BF Raptor"))
	{
		SpawnVehicle("RAPTOR");
	}
	if (Addoption("Benefactor Schafter V12"))
	{
		SpawnVehicle("SCHAFTER3");
	}
	if (Addoption("Benefactor Schafter LWB"))
	{
		SpawnVehicle("SCHAFTER4");
	}
	if (Addoption("Chevel Taipan"))
	{
		SpawnVehicle("taipan");
	}
	if (Addoption("Schwartzer"))
	{
		SpawnVehicle("SCHWARZER");
	}
	if (Addoption("Dinka Jester Classic"))
	{
		SpawnVehicle("jester3");
	}
	if (Addoption("Dewbauchee Seven-70"))
	{
		SpawnVehicle("SEVEN70");
	}
	if (Addoption("Karin Sultan"))
	{
		SpawnVehicle("SULTAN");
	}
	if (Addoption("Benefactor Surano"))
	{
		SpawnVehicle("SURANO");
	}
	if (Addoption("Dewbauchee Specter"))
	{
		SpawnVehicle("SPECTER");
	}
	if (Addoption("Dewbauchee Specter Custom"))
	{
		SpawnVehicle("SPECTER2");
	}
	if (Addoption("Declasse Scramjet"))
	{
		SpawnVehicle("scramjet");
	}
	if (Addoption("Declasse Drift Tampa"))
	{
		SpawnVehicle("TAMPA2");
	}
	if (Addoption("Lampadati Tropos Rallye"))
	{
		SpawnVehicle("TROPOS");
	}
	if (Addoption("Bravado Verlierer"))
	{
		SpawnVehicle("VERLIERER2");
	}
	if (Addoption("Imponte Ruiner 2000"))
	{
		SpawnVehicle("RUINER2");
	}
	if (Addoption("JoBuilt Phantom Wedge"))
	{
		SpawnVehicle("PHANTOM2");
	}
	if (Addoption("Hijak Ruston"))
	{
		SpawnVehicle("RUSTON");
	}

}
void Spawner::sportclassicsspinSpawner()
{
	Addtitle("");
	Addsubtitle("Sport Classics");

	if (Settings::currentOption == 1) {
		previewCar("BTYPE");
	}
	if (Settings::currentOption == 2) {
		previewCar("BTYPE2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BTYPE3");
	}
	if (Settings::currentOption == 4) {
		previewCar("CASCO");
	}
	if (Settings::currentOption == 5) {
		previewCar("COQUETTE2");
	}
	if (Settings::currentOption == 6) {
		previewCar("TULIP");
	}
	if (Settings::currentOption == 7) {
		previewCar("VAMOS");
	}
	if (Settings::currentOption == 8) {
		previewCar("FELTZER3");
	}
	if (Settings::currentOption == 9) {
		previewCar("JB700");
	}
	if (Settings::currentOption == 10) {
		previewCar("gt500");
	}
	if (Settings::currentOption == 11) {
		previewCar("neon");
	}
	if (Settings::currentOption == 12) {
		previewCar("hermes");
	}
	if (Settings::currentOption == 13) {
		previewCar("hustler");
	}
	if (Settings::currentOption == 14) {
		previewCar("MAMBA");
	}
	if (Settings::currentOption == 15) {
		previewCar("MANANA");
	}
	if (Settings::currentOption == 16) {
		previewCar("MONROE");
	}
	if (Settings::currentOption == 17) {
		previewCar("PEYOTE");
	}
	if (Settings::currentOption == 18) {
		previewCar("PIGALLE");
	}
	if (Settings::currentOption == 19) {
		previewCar("STINGER");
	}
	if (Settings::currentOption == 20) {
		previewCar("viseris");
	}
	if (Settings::currentOption == 21) {
		previewCar("z190");
	}
	if (Settings::currentOption == 22) {
		previewCar("STINGERGT");
	}
	if (Settings::currentOption == 23) {
		previewCar("TORNADO");
	}
	if (Settings::currentOption == 24) {
		previewCar("revolter");
	}
	if (Settings::currentOption == 25) {
		previewCar("IMPALER");
	}
	if (Settings::currentOption == 26) {
		previewCar("IMPALER2");
	}
	if (Settings::currentOption == 27) {
		previewCar("IMPALER3");
	}
	if (Settings::currentOption == 28) {
		previewCar("IMPALER4");
	}
	if (Settings::currentOption == 39) {
		previewCar("TORNADO2");
	}
	if (Settings::currentOption == 30) {
		previewCar("TORNADO3");
	}
	if (Settings::currentOption == 31) {
		previewCar("TORNADO4");
	}
	if (Settings::currentOption == 32) {
		previewCar("TORNADO5");
	}
	if (Settings::currentOption == 33) {
		previewCar("TORNADO6");
	}
	if (Settings::currentOption == 34) {
		previewCar("DEVIANT");
	}
	if (Settings::currentOption == 35) {
		previewCar("IMPERATOR");
	}
	if (Settings::currentOption == 36) {
		previewCar("IMPERATOR2");
	}
	if (Settings::currentOption == 37) {
		previewCar("IMPERATOR3");
	}
	if (Settings::currentOption == 38) {
		previewCar("ZTYPE");
	}
	if (Settings::currentOption == 39) {
		previewCar("INFERNUS2");
	}
	if (Settings::currentOption == 40) {
		previewCar("TURISMO2");
	}
	if (Settings::currentOption == 41) {
		previewCar("CLIQUE");
	}

	if (Addoption("Albanny Roosevelt"))
	{
		SpawnVehicle("BTYPE");
	}
	if (Addoption("Albanny Franken Strange"))
	{
		SpawnVehicle("BTYPE2");
	}
	if (Addoption("Albanny Roosevelt Valor"))
	{
		SpawnVehicle("BTYPE3");
	}
	if (Addoption("Lampadati Casco"))
	{
		SpawnVehicle("CASCO");
	}
	if (Addoption("Invetero Coquette BlackFin"))
	{
		SpawnVehicle("COQUETTE2");
	}
	if (Addoption("Declass Tulip"))
	{
		SpawnVehicle("TULIP");
	}
	if (Addoption("Declass Vamos"))
	{
		SpawnVehicle("VAMOS");
	}
	if (Addoption("Benefactor Stirling GT"))
	{
		SpawnVehicle("FELTZER3");
	}
	if (Addoption("Dewbauchee JB 700"))
	{
		SpawnVehicle("JB700");
	}
	if (Addoption("Grotti GT500"))
	{
		SpawnVehicle("gt500");
	}
	if (Addoption("Phister Neon"))
	{
		SpawnVehicle("neon");
	}
	if (Addoption("Albany Hermes"))
	{
		SpawnVehicle("hermes");
	}
	if (Addoption("Vapid Hustler"))
	{
		SpawnVehicle("hustler");
	}
	if (Addoption("Declasse Mamba"))
	{
		SpawnVehicle("MAMBA");
	}
	if (Addoption("Albany Manana"))
	{
		SpawnVehicle("MANANA");
	}
	if (Addoption("Pegassi Monroe"))
	{
		SpawnVehicle("MONROE");
	}
	if (Addoption("Vapid Peyote"))
	{
		SpawnVehicle("PEYOTE");
	}
	if (Addoption("Lampadati Pigalle"))
	{
		SpawnVehicle("PIGALLE");
	}
	if (Addoption("Benefactor Stirling GT"))
	{
		SpawnVehicle("STINGER");
	}
	if (Addoption("Lampaditi Viseris"))
	{
		SpawnVehicle("viseris");
	}
	if (Addoption("Karin 190z"))
	{
		SpawnVehicle("z190");
	}
	if (Addoption("Stinger GT"))
	{
		SpawnVehicle("STINGERGT");
	}
	if (Addoption("Declasse Tornado"))
	{
		SpawnVehicle("TORNADO");
	}
	if (Addoption("Albany Roosevelt"))
	{
		SpawnVehicle("revolter");
	}
	if (Addoption("Vapid Clique"))
	{
		SpawnVehicle("IMPALER");
	}
	if (Addoption("Vapid Apocalypse Imperator"))
	{
		SpawnVehicle("IMPALER2");
	}
	if (Addoption("Vapid Future Shock Imperator"))
	{
		SpawnVehicle("IMPALER3");
	}
	if (Addoption("Vapid Nightmare Imperator"))
	{
		SpawnVehicle("IMPALER4");
	}
	if (Addoption("Declasse Tornado (convertable)"))
	{
		SpawnVehicle("TORNADO2");
	}
	if (Addoption("Declasse Tornado (old)"))
	{
		SpawnVehicle("TORNADO3");
	}
	if (Addoption("Declasse Tornado (mexican)"))
	{
		SpawnVehicle("TORNADO4");
	}
	if (Addoption("Declasse Tornado Custom"))
	{
		SpawnVehicle("TORNADO5");
	}
	if (Addoption("Declasse Tornado Rat-Rod"))
	{
		SpawnVehicle("TORNADO6");
	}
	if (Addoption("Schyster Deviant"))
	{
		SpawnVehicle("DEVIANT");
	}
	if (Addoption("Vapid Apocalypse Imperator"))
	{
		SpawnVehicle("IMPERATOR");
	}
	if (Addoption("Vapid Future Shock Imperator"))
	{
		SpawnVehicle("IMPERATOR2");
	}
	if (Addoption("Vapid Nightmare Imperator"))
	{
		SpawnVehicle("IMPERATOR3");
	}
	if (Addoption("Truffade Z-Type"))
	{
		SpawnVehicle("ZTYPE");
	}
	if (Addoption("Pegassi Infernus Classic"))
	{
		SpawnVehicle("INFERNUS2");
	}
	if (Addoption("Grotti Turismo Classic"))
	{
		SpawnVehicle("TURISMO2");
	}
	if (Addoption("Vapid Clique"))
	{
		SpawnVehicle("CLIQUE");
	}

}
void Spawner::SUVspinSpawner()
{
	Addtitle("");
	Addsubtitle("SUV");


	if (Settings::currentOption == 1) {
		previewCar("BALLER");
	}
	if (Settings::currentOption == 2) {
		previewCar("BALLER2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BALLER3");
	}
	if (Settings::currentOption == 4) {
		previewCar("BALLER4");
	}
	if (Settings::currentOption == 5) {
		previewCar("BALLER5");
	}
	if (Settings::currentOption == 6) {
		previewCar("TOROS");
	}
	if (Settings::currentOption == 7) {
		previewCar("BALLER6");
	}
	if (Settings::currentOption == 8) {
		previewCar("BJXL");
	}
	if (Settings::currentOption == 9) {
		previewCar("CAVALCADE");
	}
	if (Settings::currentOption == 10) {
		previewCar("CAVALCADE2");
	}
	if (Settings::currentOption == 11) {
		previewCar("CONTENDER");
	}
	if (Settings::currentOption == 12) {
		previewCar("DUBSTA");
	}
	if (Settings::currentOption == 13) {
		previewCar("DUBSTA2");
	}
	if (Settings::currentOption == 14) {
		previewCar("streiter");
	}
	if (Settings::currentOption == 15) {
		previewCar("FQ2");
	}
	if (Settings::currentOption == 16) {
		previewCar("GRANGER");
	}
	if (Settings::currentOption == 17) {
		previewCar("GRESLEY");
	}
	if (Settings::currentOption == 18) {
		previewCar("riata");
	}
	if (Settings::currentOption == 19) {
		previewCar("PATRIOT");
	}
	if (Settings::currentOption == 20) {
		previewCar("RADI");
	}
	if (Settings::currentOption == 21) {
		previewCar("ROCOTO");
	}
	if (Settings::currentOption == 22) {
		previewCar("SEMINOLE");
	}
	if (Settings::currentOption == 23) {
		previewCar("SERRANO");
	}
	if (Settings::currentOption == 24) {
		previewCar("XLS");
	}
	if (Settings::currentOption == 25) {
		previewCar("XLS2");
	}

	if (Addoption("Gallivanter Baller"))
	{
		SpawnVehicle("BALLER");
	}
	if (Addoption("Gallivanter Baller (second generation)"))
	{
		SpawnVehicle("BALLER2");
	}
	if (Addoption("Baller LE"))
	{
		SpawnVehicle("BALLER3");
	}
	if (Addoption("Gallivanter Baller LE LWB"))
	{
		SpawnVehicle("BALLER4");
	}
	if (Addoption("Gallivanter Baller LE (Armored)"))
	{
		SpawnVehicle("BALLER5");
	}
	if (Addoption("Pegassi Toros"))
	{
		SpawnVehicle("TOROS");
	}
	if (Addoption("Baller LE LWB (Armored)"))
	{
		SpawnVehicle("BALLER6");
	}
	if (Addoption("Karin BeeJay XL"))
	{
		SpawnVehicle("BJXL");
	}
	if (Addoption("Albany Cavalcade"))
	{
		SpawnVehicle("CAVALCADE");
	}
	if (Addoption("Albany Cavalcade (second generation)"))
	{
		SpawnVehicle("CAVALCADE2");
	}
	if (Addoption("Vapid Contender"))
	{
		SpawnVehicle("CONTENDER");
	}
	if (Addoption("Benefactor Dubsta"))
	{
		SpawnVehicle("DUBSTA");
	}
	if (Addoption("Benefactor Dubsta 6x6"))
	{
		SpawnVehicle("DUBSTA2");
	}
	if (Addoption("Benefactor Streiter"))
	{
		SpawnVehicle("streiter");
	}
	if (Addoption("Fathom FQ 2"))
	{
		SpawnVehicle("FQ2");
	}
	if (Addoption("Declasse Granger"))
	{
		SpawnVehicle("GRANGER");
	}
	if (Addoption("Bravado Gresley"))
	{
		SpawnVehicle("GRESLEY");
	}
	if (Addoption("Vapid Riata"))
	{
		SpawnVehicle("riata");
	}
	if (Addoption("Emperor Habanero"))
	{
		SpawnVehicle("HABANERO");
	}
	if (Addoption("Enus Huntley S"))
	{
		SpawnVehicle("HUNTLEY");
	}
	if (Addoption("Dundreary Landstalker"))
	{
		SpawnVehicle("LANDSTALKER");
	}
	if (Addoption("Canis Mesa"))
	{
		SpawnVehicle("MESA");
	}
	if (Addoption("Canis Mesa Grande(Merryweather)"))
	{
		SpawnVehicle("MESA2");
	}
	if (Addoption("Mammoth Patriot"))
	{
		SpawnVehicle("PATRIOT");
	}
	if (Addoption("Vapid Radius"))
	{
		SpawnVehicle("RADI");
	}
	if (Addoption("Obey Rocoto"))
	{
		SpawnVehicle("ROCOTO");
	}
	if (Addoption("Canis Seminole"))
	{
		SpawnVehicle("SEMINOLE");
	}
	if (Addoption("Benefactor Serrano"))
	{
		SpawnVehicle("SERRANO");
	}
	if (Addoption("Benefactor XLS"))
	{
		SpawnVehicle("XLS");
	}
	if (Addoption("Benefactor XLS (Armored)"))
	{
		SpawnVehicle("XLS2");
	}
}
void Spawner::TrailerspinSpawner()
{
	Addtitle("");
	Addsubtitle("Trailer");

	if (Settings::currentOption == 1) {
		previewCar("ARMYTANKER");
	}
	if (Settings::currentOption == 2) {
		previewCar("ARMYTRAILER");
	}
	if (Settings::currentOption == 3) {
		previewCar("terbyte");
	}
	if (Settings::currentOption == 4) {
		previewCar("pounder2");
	}
	if (Settings::currentOption == 5) {
		previewCar("ARMYTRAILER2");
	}
	if (Settings::currentOption == 6) {
		previewCar("BALETRAILER");
	}
	if (Settings::currentOption == 7) {
		previewCar("BOATTRAILER");
	}
	if (Settings::currentOption == 8) {
		previewCar("DOCKTRAILER");
	}
	if (Settings::currentOption == 9) {
		previewCar("FREIGHTTRAILER");
	}
	if (Settings::currentOption == 10) {
		previewCar("GRAINTRAILER");
	}
	if (Settings::currentOption == 11) {
		previewCar("PROPTRAILER");
	}
	if (Settings::currentOption == 12) {
		previewCar("RAKETRAILER");
	}
	if (Settings::currentOption == 13) {
		previewCar("TANKER");
	}
	if (Settings::currentOption == 14) {
		previewCar("TANKER2");
	}
	if (Settings::currentOption == 15) {
		previewCar("TR2");
	}
	if (Settings::currentOption == 16) {
		previewCar("TR3");
	}
	if (Settings::currentOption == 17) {
		previewCar("TR4");
	}
	if (Settings::currentOption == 18) {
		previewCar("pbus2");
	}
	if (Settings::currentOption == 19) {
		previewCar("mule4");
	}
	if (Settings::currentOption == 20) {
		previewCar("TRAILERLOGS");
	}
	if (Settings::currentOption == 21) {
		previewCar("TRAILERS");
	}
	if (Settings::currentOption == 22) {
		previewCar("TRAILERS2");
	}
	if (Settings::currentOption == 23) {
		previewCar("TRAILERS3");
	}
	if (Settings::currentOption == 24) {
		previewCar("TRAILERSMALL");
	}
	if (Settings::currentOption == 25) {
		previewCar("TRFLAT");
	}
	if (Settings::currentOption == 26) {
		previewCar("TVTRAILER");
	}

	if (Addoption("Army Trailer(Tanker)"))
	{
		SpawnVehicle("ARMYTANKER");
	}
	if (Addoption("Army Trailer"))
	{
		SpawnVehicle("ARMYTRAILER");
	}
	if (Addoption("Benefactor Terrorbyte"))
	{
		SpawnVehicle("terbyte");
	}
	if (Addoption("MTL Pounder"))
	{
		SpawnVehicle("pounder2");
	}
	if (Addoption("civilian Army Trailer"))
	{
		SpawnVehicle("ARMYTRAILER2");
	}
	if (Addoption("Bale Trailer"))
	{
		SpawnVehicle("BALETRAILER");
	}
	if (Addoption("Boat Trailer"))
	{
		SpawnVehicle("BOATTRAILER");
	}
	if (Addoption("Dock Trailer"))
	{
		SpawnVehicle("DOCKTRAILER");
	}
	if (Addoption("Freight Trailer"))
	{
		SpawnVehicle("FREIGHTTRAILER");
	}
	if (Addoption("Grain Trailer"))
	{
		SpawnVehicle("GRAINTRAILER");
	}
	if (Addoption("Prop Trailer"))
	{
		SpawnVehicle("PROPTRAILER");
	}
	if (Addoption("Rake Trailer"))
	{
		SpawnVehicle("RAKETRAILER");
	}
	if (Addoption("Tanker"))
	{
		SpawnVehicle("TANKER");
	}
	if (Addoption("Tanker(2)"))
	{
		SpawnVehicle("TANKER2");
	}
	if (Addoption("Car Carrier Trailer"))
	{
		SpawnVehicle("TR2");
	}
	if (Addoption("yacht Trailer"))
	{
		SpawnVehicle("TR3");
	}
	if (Addoption("Car Carrier Trailer(With Cars)"))
	{
		SpawnVehicle("TR4");
	}
	if (Addoption("Vapid Festival Bus"))
	{
		SpawnVehicle("pbus2");
	}
	if (Addoption("Maibatsu Mule"))
	{
		SpawnVehicle("mule4");
	}
	if (Addoption("Trailer (logs)"))
	{
		SpawnVehicle("TRAILERLOGS");
	}
	if (Addoption("Trailers"))
	{
		SpawnVehicle("TRAILERS");
	}
	if (Addoption("Trailers"))
	{
		SpawnVehicle("TRAILERS2");
	}
	if (Addoption("Trailers"))
	{
		SpawnVehicle("TRAILERS3");
	}
	if (Addoption("Trailer (small)"))
	{
		SpawnVehicle("TRAILERSMALL");
	}
	if (Addoption("Flat bed"))
	{
		SpawnVehicle("TRFLAT");
	}
	if (Addoption("TV Trailer"))
	{
		SpawnVehicle("TVTRAILER");
	}

}
void Spawner::TranspinSpawner()
{
	Addtitle("");
	Addsubtitle("Trans");

	if (Settings::currentOption == 1) {
		previewCar("CABLECAR");
	}
	if (Settings::currentOption == 2) {
		previewCar("FREIGHT");
	}
	if (Settings::currentOption == 3) {
		previewCar("FREIGHTCAR");
	}
	if (Settings::currentOption == 4) {
		previewCar("FREIGHTCONT1");
	}
	if (Settings::currentOption == 5) {
		previewCar("FREIGHTCONT2");
	}
	if (Settings::currentOption == 6) {
		previewCar("FREIGHTGRAIN");
	}
	if (Settings::currentOption == 7) {
		previewCar("METROTRAIN");
	}
	if (Settings::currentOption == 8) {
		previewCar("TANKERCAR");
	}

	if (Addoption("Cable Car"))
	{
		SpawnVehicle("CABLECAR");
	}
	if (Addoption("Freight"))
	{
		SpawnVehicle("FREIGHT");
	}
	if (Addoption("Freight Car"))
	{
		SpawnVehicle("FREIGHTCAR");
	}
	if (Addoption("Freight Count(1)"))
	{
		SpawnVehicle("FREIGHTCONT1");
	}
	if (Addoption("Freight Count(2)"))
	{
		SpawnVehicle("FREIGHTCONT2");
	}
	if (Addoption("Freight Grain"))
	{
		SpawnVehicle("FREIGHTGRAIN");
	}
	if (Addoption("Metro Train"))
	{
		SpawnVehicle("METROTRAIN");
	}
	if (Addoption("Tank Car"))
	{
		SpawnVehicle("TANKERCAR");
	}
}
void Spawner::UtilityspinSpawner()
{
	Addtitle("");
	Addsubtitle("Utility");


	if (Settings::currentOption == 1) {
		previewCar("AIRTUG");
	}
	if (Settings::currentOption == 2) {
		previewCar("CADDY");
	}
	if (Settings::currentOption == 3) {
		previewCar("CADDY2");
	}
	if (Settings::currentOption == 4) {
		previewCar("DOCKTUG");
	}
	if (Settings::currentOption == 5) {
		previewCar("FORKLIFT");
	}
	if (Settings::currentOption == 6) {
		previewCar("MOWER");
	}
	if (Settings::currentOption == 7) {
		previewCar("RIPLEY");
	}
	if (Settings::currentOption == 8) {
		previewCar("SADLER");
	}
	if (Settings::currentOption == 9) {
		previewCar("SADLER2");
	}
	if (Settings::currentOption == 10) {
		previewCar("SCRAP");
	}
	if (Settings::currentOption == 11) {
		previewCar("TOWTRUCK");
	}
	if (Settings::currentOption == 12) {
		previewCar("TOWTRUCK2");
	}
	if (Settings::currentOption == 13) {
		previewCar("kamacho");
	}
	if (Settings::currentOption == 14) {
		previewCar("TRACTOR");
	}
	if (Settings::currentOption == 15) {
		previewCar("TRACTOR2");
	}
	if (Settings::currentOption == 16) {
		previewCar("TRACTOR3");
	}
	if (Settings::currentOption == 17) {
		previewCar("yosemite");
	}
	if (Settings::currentOption == 18) {
		previewCar("UTILLITRUCK");
	}
	if (Settings::currentOption == 19) {
		previewCar("UTILLITRUCK2");
	}
	if (Settings::currentOption == 20) {
		previewCar("UTILLITRUCK3");
	}
	if (Settings::currentOption == 21) {
		previewCar("BISON");
	}
	if (Settings::currentOption == 22) {
		previewCar("BISON2");
	}
	if (Settings::currentOption == 23) {
		previewCar("BISON3");
	}
	if (Settings::currentOption == 24) {
		previewCar("BOBCATXL");
	}
	if (Settings::currentOption == 25) {
		previewCar("BOXVILLE");
	}
	if (Settings::currentOption == 26) {
		previewCar("BOXVILLE2");
	}
	if (Settings::currentOption == 27) {
		previewCar("BOXVILLE3");
	}
	if (Settings::currentOption == 28) {
		previewCar("BOXVILLE4");
	}
	if (Settings::currentOption == 39) {
		previewCar("BURRITO");
	}
	if (Settings::currentOption == 30) {
		previewCar("BURRITO2");
	}
	if (Settings::currentOption == 31) {
		previewCar("BURRITO3");
	}
	if (Settings::currentOption == 32) {
		previewCar("BURRITO4");
	}
	if (Settings::currentOption == 33) {
		previewCar("speedo4");
	}
	if (Settings::currentOption == 34) {
		previewCar("BURRITO5");
	}
	if (Settings::currentOption == 35) {
		previewCar("CAMPER");
	}
	if (Settings::currentOption == 36) {
		previewCar("GBURRITO");
	}
	if (Settings::currentOption == 37) {
		previewCar("GBURRITO2");
	}
	if (Settings::currentOption == 38) {
		previewCar("JOURNEY");
	}
	if (Settings::currentOption == 39) {
		previewCar("MINIVAN");
	}
	if (Settings::currentOption == 40) {
		previewCar("MINIVAN2");
	}
	if (Settings::currentOption == 41) {
		previewCar("PARADISE");
	}
	if (Settings::currentOption == 42) {
		previewCar("PONY");
	}
	if (Settings::currentOption == 43) {
		previewCar("PONY2");
	}
	if (Settings::currentOption == 44) {
		previewCar("RUMPO");
	}
	if (Settings::currentOption == 45) {
		previewCar("RUMPO2");
	}
	if (Settings::currentOption == 46) {
		previewCar("RUMPO3");
	}
	if (Settings::currentOption == 47) {
		previewCar("SPEEDO");
	}
	if (Settings::currentOption == 48) {
		previewCar("SPEEDO2");
	}
	if (Settings::currentOption == 49) {
		previewCar("SURFER");
	}
	if (Settings::currentOption == 50) {
		previewCar("SURFER2");
	}
	if (Settings::currentOption == 51) {
		previewCar("TACO");
	}
	if (Settings::currentOption == 52) {
		previewCar("YOUGA");
	}
	if (Settings::currentOption == 53) {
		previewCar("YOUGA2");
	}

	if (Addoption("HVY Airtug"))
	{
		SpawnVehicle("AIRTUG");
	}
	if (Addoption("Caddy"))
	{
		SpawnVehicle("CADDY");
	}
	if (Addoption("Caddy(2)"))
	{
		SpawnVehicle("CADDY2");
	}
	if (Addoption("HVY Docktug"))
	{
		SpawnVehicle("DOCKTUG");
	}
	if (Addoption("Fork Lift"))
	{
		SpawnVehicle("FORKLIFT");
	}
	if (Addoption("Mower"))
	{
		SpawnVehicle("MOWER");
	}
	if (Addoption("HVY Ripley"))
	{
		SpawnVehicle("RIPLEY");
	}
	if (Addoption("Sadler"))
	{
		SpawnVehicle("SADLER");
	}
	if (Addoption("Sadler(Snow)"))
	{
		SpawnVehicle("SADLER2");
	}
	if (Addoption("Vapid Scrap"))
	{
		SpawnVehicle("SCRAP");
	}
	if (Addoption("Tow Truck"))
	{
		SpawnVehicle("TOWTRUCK");
	}
	if (Addoption("Vapid Towtruck"))
	{
		SpawnVehicle("TOWTRUCK2");
	}
	if (Addoption("Canis Kamacho"))
	{
		SpawnVehicle("kamacho");
	}
	if (Addoption("Tractor(Rusty)"))
	{
		SpawnVehicle("TRACTOR");
	}
	if (Addoption("Tractor"))
	{
		SpawnVehicle("TRACTOR2");
	}
	if (Addoption("Tractor(Snow)"))
	{
		SpawnVehicle("TRACTOR3");
	}
	if (Addoption("Yosemite"))
	{
		SpawnVehicle("yosemite");
	}
	if (Addoption("Cherry Picker"))
	{
		SpawnVehicle("UTILLITRUCK");
	}
	if (Addoption("Flatbed Utility Truck"))
	{
		SpawnVehicle("UTILLITRUCK2");
	}
	if (Addoption("Utility Truck(Pick-Up)"))
	{
		SpawnVehicle("UTILLITRUCK3");
	}
	if (Addoption("Bravado Bison"))
	{
		SpawnVehicle("BISON");
	}
	if (Addoption("Bison(McGill-Olsen)"))
	{
		SpawnVehicle("BISON2");
	}
	if (Addoption("Bison(Mighty Bush)"))
	{
		SpawnVehicle("BISON3");
	}
	if (Addoption("Vapid Bobcat XL"))
	{
		SpawnVehicle("BOBCATXL");
	}
	if (Addoption("BoxVille(LSDWP)"))
	{
		SpawnVehicle("BOXVILLE");
	}
	if (Addoption("BoxVille(GoPostal)"))
	{
		SpawnVehicle("BOXVILLE2");
	}
	if (Addoption("BoxVille(The Humane Labs)"))
	{
		SpawnVehicle("BOXVILLE3");
	}
	if (Addoption("BoxVille(Post OP)"))
	{
		SpawnVehicle("BOXVILLE4");
	}
	if (Addoption("Burrito(LSWP)"))
	{
		SpawnVehicle("BURRITO");
	}
	if (Addoption("Burrito(Bugstars)"))
	{
		SpawnVehicle("BURRITO2");
	}
	if (Addoption("Burrito(second generation)"))
	{
		SpawnVehicle("BURRITO3");
	}
	if (Addoption("Burrito"))
	{
		SpawnVehicle("BURRITO4");
	}
	if (Addoption("Vapid Speedo Custom"))
	{
		SpawnVehicle("speedo");
	}
	if (Addoption("Burrito(Snow)"))
	{
		SpawnVehicle("BURRITO5");
	}
	if (Addoption("Camper Van"))
	{
		SpawnVehicle("CAMPER");
	}
	if (Addoption("Burrito(Lost MC Gang)"))
	{
		SpawnVehicle("GBURRITO");
	}
	if (Addoption("Burrito(standard Gang)"))
	{
		SpawnVehicle("GBURRITO2");
	}
	if (Addoption("Journey"))
	{
		SpawnVehicle("JOURNEY");
	}
	if (Addoption("Vapid Minivan"))
	{
		SpawnVehicle("MINIVAN");
	}
	if (Addoption("Vapid Minivan Custom"))
	{
		SpawnVehicle("MINIVAN2");
	}
	if (Addoption("Bravado Paradise"))
	{
		SpawnVehicle("PARADISE");
	}
	if (Addoption("Pony"))
	{
		SpawnVehicle("PONY");
	}
	if (Addoption("Pony(2)"))
	{
		SpawnVehicle("PONY2");
	}
	if (Addoption("Bravado Rumpo"))
	{
		SpawnVehicle("RUMPO");
	}
	if (Addoption("Bravado Rumpo(2)"))
	{
		SpawnVehicle("RUMPO2");
	}
	if (Addoption("Bravado Rumpo Custom"))
	{
		SpawnVehicle("RUMPO3");
	}
	if (Addoption("Vapid Speedo Custom"))
	{
		SpawnVehicle("SPEEDO");
	}
	if (Addoption("Vapid Clown Van"))
	{
		SpawnVehicle("SPEEDO2");
	}
	if (Addoption("BF Surfer"))
	{
		SpawnVehicle("SURFER");
	}
	if (Addoption("BF Surfer(Rusty)"))
	{
		SpawnVehicle("SURFER2");
	}
	if (Addoption("Brute Taco Van"))
	{
		SpawnVehicle("TACO");
	}
	if (Addoption("Bravado Youga"))
	{
		SpawnVehicle("YOUGA");
	}
	if (Addoption("Bravado Youga Classic"))
	{
		SpawnVehicle("YOUGA2");
	}
}
void Spawner::BoatspinSpawner()
{
	Addtitle("");
	Addsubtitle("Boat");


	if (Settings::currentOption == 1) {
		previewCar("DINGHY");
	}
	if (Settings::currentOption == 2) {
		previewCar("DINGHY2");
	}
	if (Settings::currentOption == 3) {
		previewCar("DINGHY3");
	}
	if (Settings::currentOption == 4) {
		previewCar("DINGHY4");
	}
	if (Settings::currentOption == 5) {
		previewCar("JETMAX");
	}
	if (Settings::currentOption == 6) {
		previewCar("MARQUIS");
	}
	if (Settings::currentOption == 7) {
		previewCar("PREDATOR");
	}
	if (Settings::currentOption == 8) {
		previewCar("SEASHARK");
	}
	if (Settings::currentOption == 9) {
		previewCar("SEASHARK2");
	}
	if (Settings::currentOption == 10) {
		previewCar("SEASHARK3");
	}
	if (Settings::currentOption == 11) {
		previewCar("SPEEDER");
	}
	if (Settings::currentOption == 12) {
		previewCar("SPEEDER2");
	}
	if (Settings::currentOption == 13) {
		previewCar("SQUALO");
	}
	if (Settings::currentOption == 14) {
		previewCar("SUBMERSIBLE");
	}
	if (Settings::currentOption == 15) {
		previewCar("SUBMERSIBLE2");
	}
	if (Settings::currentOption == 16) {
		previewCar("SUNTRAP");
	}
	if (Settings::currentOption == 17) {
		previewCar("TORO");
	}
	if (Settings::currentOption == 18) {
		previewCar("TORO2");
	}
	if (Settings::currentOption == 19) {
		previewCar("TROPIC");
	}
	if (Settings::currentOption == 20) {
		previewCar("TROPIC2");
	}
	if (Settings::currentOption == 21) {
		previewCar("TUG");
	}

	if (Addoption("Nagasaki Dinghy(4-seater)"))
	{
		SpawnVehicle("DINGHY");
	}
	if (Addoption("Nagasaki Dinghy(2-seater)"))
	{
		SpawnVehicle("DINGHY2");
	}
	if (Addoption("Nagasaki Dinghy(Heists)"))
	{
		SpawnVehicle("DINGHY3");
	}
	if (Addoption("Nagasaki Dinghy(Yacht)"))
	{
		SpawnVehicle("DINGHY4");
	}
	if (Addoption("Shitzu Jetmax"))
	{
		SpawnVehicle("JETMAX");
	}
	if (Addoption("Dinka Marquis"))
	{
		SpawnVehicle("MARQUIS");
	}
	if (Addoption("Police Predator"))
	{
		SpawnVehicle("PREDATOR");
	}
	if (Addoption("Speedophile Seashark"))
	{
		SpawnVehicle("SEASHARK");
	}
	if (Addoption("Speedophile Seashark(Lifeguard )"))
	{
		SpawnVehicle("SEASHARK2");
	}
	if (Addoption("Speedophile Seashark(Yacht)"))
	{
		SpawnVehicle("SEASHARK3");
	}
	if (Addoption("Pegassi Speeder"))
	{
		SpawnVehicle("SPEEDER");
	}
	if (Addoption("Pegassi Speeder(Yacht)"))
	{
		SpawnVehicle("SPEEDER2");
	}
	if (Addoption("Shitzu Squalo"))
	{
		SpawnVehicle("SQUALO");
	}
	if (Addoption("Submersible"))
	{
		SpawnVehicle("SUBMERSIBLE");
	}
	if (Addoption("Tractor"))
	{
		SpawnVehicle("SUBMERSIBLE2");
	}
	if (Addoption("Kraken"))
	{
		SpawnVehicle("SUNTRAP");
	}
	if (Addoption("Lampadati Toro"))
	{
		SpawnVehicle("TORO");
	}
	if (Addoption("Lampadati Toro(Yacht)"))
	{
		SpawnVehicle("TORO2");
	}
	if (Addoption("Shitzu Tropic"))
	{
		SpawnVehicle("TROPIC");
	}
	if (Addoption("Shitzu Tropic(Yacht)"))
	{
		SpawnVehicle("TROPIC2");
	}
	if (Addoption("Tug"))
	{
		SpawnVehicle("TUG");
	}

}
void Spawner::CommercialspinSpawner()
{
	Addtitle("");
	Addsubtitle("Commercial");

	if (Settings::currentOption == 1) {
		previewCar("BENSON");
	}
	if (Settings::currentOption == 2) {
		previewCar("BIFF");
	}
	if (Settings::currentOption == 3) {
		previewCar("HAULER");
	}
	if (Settings::currentOption == 4) {
		previewCar("MULE");
	}
	if (Settings::currentOption == 5) {
		previewCar("MULE2");
	}
	if (Settings::currentOption == 6) {
		previewCar("MULE3");
	}
	if (Settings::currentOption == 7) {
		previewCar("PACKER");
	}
	if (Settings::currentOption == 8) {
		previewCar("PHANTOM");
	}
	if (Settings::currentOption == 9) {
		previewCar("POUNDER");
	}
	if (Settings::currentOption == 10) {
		previewCar("STOCKADE");
	}
	if (Settings::currentOption == 11) {
		previewCar("STOCKADE3");
	}

	if (Addoption("Benson"))
	{
		SpawnVehicle("BENSON");
	}
	if (Addoption("HVY Biff"))
	{
		SpawnVehicle("BIFF");
	}
	if (Addoption("Jobuilt Hauler"))
	{
		SpawnVehicle("HAULER");
	}
	if (Addoption("Mule"))
	{
		SpawnVehicle("MULE");
	}
	if (Addoption("Mule(2)"))
	{
		SpawnVehicle("MULE2");
	}
	if (Addoption("Mule Custom"))
	{
		SpawnVehicle("MULE3");
	}
	if (Addoption("Packer"))
	{
		SpawnVehicle("PACKER");
	}
	if (Addoption("Jobuilt Phantom"))
	{
		SpawnVehicle("PHANTOM");
	}
	if (Addoption("MTL Pounder "))
	{
		SpawnVehicle("POUNDER");
	}
	if (Addoption("Stockade"))
	{
		SpawnVehicle("STOCKADE");
	}
	if (Addoption("Stockade(Snow)"))
	{
		SpawnVehicle("STOCKADE3");
	}

}

void Spawner::CompactsspinSpawner()
{
	Addtitle("");
	Addsubtitle("Compacts");

	if (Settings::currentOption == 1) {
		previewCar("RCBANDITO");
	}
	if (Settings::currentOption == 2) {
		previewCar("BLISTA");
	}
	if (Settings::currentOption == 3) {
		previewCar("SLAMVAN4");
	}
	if (Settings::currentOption == 4) {
		previewCar("SLAMVAN5");
	}
	if (Settings::currentOption == 5) {
		previewCar("SLAMVAN6");
	}
	if (Settings::currentOption == 6) {
		previewCar("issi3");
	}
	if (Settings::currentOption == 7) {
		previewCar("ISSI4");
	}
	if (Settings::currentOption == 8) {
		previewCar("ISSI5");
	}
	if (Settings::currentOption == 9) {
		previewCar("ISSI6");
	}
	if (Settings::currentOption == 10) {
		previewCar("DILETTANTE");
	}
	if (Settings::currentOption == 11) {
		previewCar("DILETTANTE2");
	}
	if (Settings::currentOption == 12) {
		previewCar("freecrawler");
	}
	if (Settings::currentOption == 13) {
		previewCar("ISSI2");
	}
	if (Settings::currentOption == 14) {
		previewCar("PANTO");
	}
	if (Settings::currentOption == 15) {
		previewCar("PRAIRIE");
	}
	if (Settings::currentOption == 16) {
		previewCar("gb200");
	}
	if (Settings::currentOption == 17) {
		previewCar("michelli");
	}
	if (Settings::currentOption == 18) {
		previewCar("RHAPSODY");
	}
	if (Settings::currentOption == 19) {
		previewCar("sentinel3");
	}
	if (Settings::currentOption == 20) {
		previewCar("retinue");
	}

	if (Addoption("RC Bandito"))
	{
		SpawnVehicle("RCBANDITO");
	}
	if (Addoption("Blista "))
	{
		SpawnVehicle("BLISTA");
	}
	if (Addoption("Grotti Brioso"))
	{
		SpawnVehicle("BRIOSO");
	}
	if (Addoption("Apocalypse Slamvan"))
	{
		SpawnVehicle("SLAMVAN4");
	}
	if (Addoption("Nightmare Slamvan"))
	{
		SpawnVehicle("SLAMVAN5");
	}
	if (Addoption("Future Shock Slamvan"))
	{
		SpawnVehicle("SLAMVAN6");
	}
	if (Addoption("Apocalypse Issi"))
	{
		SpawnVehicle("issi3");
	}
	if (Addoption("Nightmare Issi"))
	{
		SpawnVehicle("ISSI4");
	}
	if (Addoption("Future Shock Issi"))
	{
		SpawnVehicle("ISSI5");
	}
	if (Addoption("Issi 6"))
	{
		SpawnVehicle("ISSI6");
	}
	if (Addoption("Dilettante"))
	{
		SpawnVehicle("DILETTANTE");
	}
	if (Addoption("Merryweather Dilettante"))
	{
		SpawnVehicle("DILETTANTE2");
	}
	if (Addoption("Canis Freecrawler"))
	{
		SpawnVehicle("freecrawler");
	}
	if (Addoption("Issi"))
	{
		SpawnVehicle("ISSI2");
	}
	if (Addoption("Panto"))
	{
		SpawnVehicle("PANTO");
	}
	if (Addoption("Bollokan Prairie"))
	{
		SpawnVehicle("PRAIRIE");
	}
	if (Addoption("Vapid GB200"))
	{
		SpawnVehicle("gb200");
	}
	if (Addoption("Michelli GT"))
	{
		SpawnVehicle("michelli");
	}
	if (Addoption("Declasse Rhapsody"))
	{
		SpawnVehicle("RHAPSODY");
	}
	if (Addoption("ubermacht Sentinel Classic"))
	{
		SpawnVehicle("sentinel3");
	}
	if (Addoption("Vapid Retinue"))
	{
		SpawnVehicle("retinue");
	}
}

void Spawner::CoupesspinSpawner()
{
	Addtitle("");
	Addsubtitle("Coupes");


	if (Settings::currentOption == 1) {
		previewCar("COGCABRIO");
	}
	if (Settings::currentOption == 2) {
		previewCar("EXEMPLAR");
	}
	if (Settings::currentOption == 3) {
		previewCar("F620");
	}
	if (Settings::currentOption == 4) {
		previewCar("FELON");
	}
	if (Settings::currentOption == 5) {
		previewCar("FELON2");
	}
	if (Settings::currentOption == 6) {
		previewCar("JACKAL");
	}
	if (Settings::currentOption == 7) {
		previewCar("ORACLE");
	}
	if (Settings::currentOption == 8) {
		previewCar("ORACLE2");
	}
	if (Settings::currentOption == 9) {
		previewCar("SENTINEL");
	}
	if (Settings::currentOption == 10) {
		previewCar("SENTINEL2");
	}
	if (Settings::currentOption == 11) {
		previewCar("WINDSOR2");
	}
	if (Settings::currentOption == 12) {
		previewCar("WINDSOR2");
	}
	if (Settings::currentOption == 13) {
		previewCar("savestra");
	}
	if (Settings::currentOption == 14) {
		previewCar("ZION");
	}
	if (Settings::currentOption == 15) {
		previewCar("ZION2");
	}

	if (Addoption("Enus Cognoscenti Cabrio"))
	{
		SpawnVehicle("COGCABRIO");
	}
	if (Addoption("Dewbauchee Exemplar"))
	{
		SpawnVehicle("EXEMPLAR");
	}
	if (Addoption("Ocelot F620"))
	{
		SpawnVehicle("F620");
	}
	if (Addoption("Lampadati Felon"))
	{
		SpawnVehicle("FELON");
	}
	if (Addoption("Lampadati Felon GT"))
	{
		SpawnVehicle("FELON2");
	}
	if (Addoption("Ocelot Jackal"))
	{
		SpawnVehicle("JACKAL");
	}
	if (Addoption("Ubermacht Oracle "))
	{
		SpawnVehicle("ORACLE");
	}
	if (Addoption("Ubermacht Oracle XS"))
	{
		SpawnVehicle("ORACLE2");
	}
	if (Addoption("Ubermacht Sentinel"))
	{
		SpawnVehicle("SENTINEL");
	}
	if (Addoption("Ubermacht Sentinel XS"))
	{
		SpawnVehicle("SENTINEL2");
	}
	if (Addoption("Enus Windsor"))
	{
		SpawnVehicle("WINDSOR");
	}
	if (Addoption("Enus Windsor Drop"))
	{
		SpawnVehicle("WINDSOR2");
	}
	if (Addoption("Annis Savestra"))
	{
		SpawnVehicle("savestra");
	}
	if (Addoption("Ubermacht Zion"))
	{
		SpawnVehicle("ZION");
	}
	if (Addoption("Ubermacht Zion Cabrio"))
	{
		SpawnVehicle("ZION2");
	}
}
void Spawner::CyclesspinSpawner()
{
	Addtitle("");
	Addsubtitle("Cycles");

	if (Settings::currentOption == 1) {
		previewCar("BMX");
	}
	if (Settings::currentOption == 2) {
		previewCar("CRUISER");
	}
	if (Settings::currentOption == 3) {
		previewCar("FIXTER");
	}
	if (Settings::currentOption == 4) {
		previewCar("SCORCHER");
	}
	if (Settings::currentOption == 5) {
		previewCar("TRIBIKE");
	}
	if (Settings::currentOption == 6) {
		previewCar("TRIBIKE2");
	}
	if (Settings::currentOption == 7) {
		previewCar("TRIBIKE3");
	}

	if (Addoption("Enus Cognoscenti Cabrio"))
	{
		SpawnVehicle("BMX");
	}
	if (Addoption("Dewbauchee Exemplar"))
	{
		SpawnVehicle("CRUISER");
	}
	if (Addoption("Ocelot F620"))
	{
		SpawnVehicle("FIXTER");
	}
	if (Addoption("Lampadati Felon"))
	{
		SpawnVehicle("SCORCHER");
	}
	if (Addoption("Lampadati Felon GT"))
	{
		SpawnVehicle("TRIBIKE");
	}
	if (Addoption("Ocelot Jackal"))
	{
		SpawnVehicle("TRIBIKE2");
	}
	if (Addoption("Ubermacht Oracle "))
	{
		SpawnVehicle("TRIBIKE3");
	}
}
void Spawner::EmergencyspinSpawner()
{
	Addtitle("");
	Addsubtitle("Emergency");

	if (Settings::currentOption == 1) {
		previewCar("AMBULANCE");
	}
	if (Settings::currentOption == 2) {
		previewCar("FBI");
	}
	if (Settings::currentOption == 3) {
		previewCar("FBI2");
	}
	if (Settings::currentOption == 4) {
		previewCar("FIRETRUK");
	}
	if (Settings::currentOption == 5) {
		previewCar("LGUARD");
	}
	if (Settings::currentOption == 6) {
		previewCar("PBUS");
	}
	if (Settings::currentOption == 7) {
		previewCar("PRANGER");
	}
	if (Settings::currentOption == 8) {
		previewCar("POLICE");
	}
	if (Settings::currentOption == 9) {
		previewCar("POLICE2");
	}
	if (Settings::currentOption == 10) {
		previewCar("POLICE3");
	}
	if (Settings::currentOption == 11) {
		previewCar("POLICE4");
	}
	if (Settings::currentOption == 12) {
		previewCar("POLICEB");
	}
	if (Settings::currentOption == 13) {
		previewCar("POLICEOLD1");
	}
	if (Settings::currentOption == 14) {
		previewCar("POLICEOLD2");
	}
	if (Settings::currentOption == 15) {
		previewCar("POLICET");
	}
	if (Settings::currentOption == 16) {
		previewCar("SHERIFF");
	}
	if (Settings::currentOption == 17) {
		previewCar("SHERIFF2");
	}
	if (Settings::currentOption == 18) {
		previewCar("RIOT");
	}
	if (Settings::currentOption == 19) {
		previewCar("RIOT2");
	}

	if (Addoption("Ambulance"))
	{
		SpawnVehicle("AMBULANCE");
	}
	if (Addoption("FBI Car"))
	{
		SpawnVehicle("FBI");
	}
	if (Addoption("FBI Rancher"))
	{
		SpawnVehicle("FBI2");
	}
	if (Addoption("FireTruck"))
	{
		SpawnVehicle("FIRETRUK");
	}
	if (Addoption("Declasse Lifeguard"))
	{
		SpawnVehicle("LGUARD");
	}
	if (Addoption("Police Bus"))
	{
		SpawnVehicle("PBUS");
	}
	if (Addoption("Declasse Park Ranger"))
	{
		SpawnVehicle("PRANGER");
	}
	if (Addoption("Police Car"))
	{
		SpawnVehicle("POLICE");
	}
	if (Addoption("Buffalo Police Car"))
	{
		SpawnVehicle("POLICE2");
	}
	if (Addoption("Vapid Police Car"))
	{
		SpawnVehicle("POLICE3");
	}
	if (Addoption("Stockade(Snow)"))
	{
		SpawnVehicle("POLICE4");
	}
	if (Addoption("Western Motorcycle Company Police Bike"))
	{
		SpawnVehicle("POLICEB");
	}
	if (Addoption("Declasse Police Rancher(Snow)"))
	{
		SpawnVehicle("POLICEOLD1");
	}
	if (Addoption("Albany Police Roadcruiser(Snow)"))
	{
		SpawnVehicle("POLICEOLD2");
	}
	if (Addoption("Declasse Police Transporter"))
	{
		SpawnVehicle("POLICET");
	}
	if (Addoption("Vapid Sheriff Cruiser"))
	{
		SpawnVehicle("SHERIFF");
	}
	if (Addoption("Declasse Sheriff SUV"))
	{
		SpawnVehicle("SHERIFF2");
	}
	if (Addoption("Brute Police Riot"))
	{
		SpawnVehicle("RIOT");
	}
	if (Addoption("RCV"))
	{
		SpawnVehicle("RIOT2");
	}

}
void Spawner::HelicoptersspinSpawner()
{
	Addtitle("");
	Addsubtitle("Helicopter");

	if (Settings::currentOption == 1) {
		previewCar("akula");
	}
	if (Settings::currentOption == 2) {
		previewCar("ANNIHILATOR");
	}
	if (Settings::currentOption == 3) {
		previewCar("BLIMP");
	}
	if (Settings::currentOption == 4) {
		previewCar("BLIMP2");
	}
	if (Settings::currentOption == 5) {
		previewCar("BLIMP3");
	}
	if (Settings::currentOption == 6) {
		previewCar("BUZZARD");
	}
	if (Settings::currentOption == 7) {
		previewCar("BUZZARD2");
	}
	if (Settings::currentOption == 8) {
		previewCar("CARGOBOB");
	}
	if (Settings::currentOption == 9) {
		previewCar("CARGOBOB2");
	}
	if (Settings::currentOption == 10) {
		previewCar("CARGOBOB3");
	}
	if (Settings::currentOption == 11) {
		previewCar("CARGOBOB4");
	}
	if (Settings::currentOption == 12) {
		previewCar("FROGGER");
	}
	if (Settings::currentOption == 13) {
		previewCar("FROGGER2");
	}
	if (Settings::currentOption == 14) {
		previewCar("MAVERICK");
	}
	if (Settings::currentOption == 15) {
		previewCar("havok");
	}
	if (Settings::currentOption == 16) {
		previewCar("hunter");
	}
	if (Settings::currentOption == 17) {
		previewCar("POLMAV");
	}
	if (Settings::currentOption == 18) {
		previewCar("SAVAGE");
	}
	if (Settings::currentOption == 19) {
		previewCar("SKYLIFT");
	}
	if (Settings::currentOption == 20) {
		previewCar("SUPERVOLITO");
	}
	if (Settings::currentOption == 21) {
		previewCar("SUPERVOLITO2");
	}
	if (Settings::currentOption == 22) {
		previewCar("SWIFT");
	}
	if (Settings::currentOption == 23) {
		previewCar("seasparrow");
	}
	if (Settings::currentOption == 24) {
		previewCar("SWIFT2");
	}
	if (Settings::currentOption == 25) {
		previewCar("VALKYRIE");
	}
	if (Settings::currentOption == 26) {
		previewCar("VALKYRIE2");
	}
	if (Settings::currentOption == 27) {
		previewCar("VOLATUS");
	}

	if (Addoption("Akula"))
	{
		SpawnVehicle("akula");
	}
	if (Addoption("Annihilator"))
	{
		SpawnVehicle("ANNIHILATOR");
	}
	if (Addoption("Atomic Blimp"))
	{
		SpawnVehicle("BLIMP");
	}
	if (Addoption("Xero Blimp"))
	{
		SpawnVehicle("BLIMP2");
	}
	if (Addoption("Black Blimp"))
	{
		SpawnVehicle("BLIMP3");
	}
	if (Addoption("Buzzard Attack Chopper"))
	{
		SpawnVehicle("BUZZARD");
	}
	if (Addoption("Buzzard (normal)"))
	{
		SpawnVehicle("BUZZARD2");
	}
	if (Addoption("Cargobob"))
	{
		SpawnVehicle("CARGOBOB");
	}
	if (Addoption("Cargobob 893 (black)"))
	{
		SpawnVehicle("CARGOBOB2");
	}
	if (Addoption("Cargobob (TP Enterprises)"))
	{
		SpawnVehicle("CARGOBOB3");
	}
	if (Addoption("Cargobob(Black)"))
	{
		SpawnVehicle("CARGOBOB4");
	}
	if (Addoption("Frogger"))
	{
		SpawnVehicle("FROGGER");
	}
	if (Addoption("Frogger (TP Enterprises)"))
	{
		SpawnVehicle("FROGGER2");
	}
	if (Addoption("Maverick"))
	{
		SpawnVehicle("MAVERICK");
	}
	if (Addoption("Nagasaki Havok"))
	{
		SpawnVehicle("havok");
	}
	if (Addoption("FH-1 Hunter"))
	{
		SpawnVehicle("hunter");
	}
	if (Addoption("Police Maverick"))
	{
		SpawnVehicle("POLMAV");
	}
	if (Addoption("Savage"))
	{
		SpawnVehicle("SAVAGE");
	}
	if (Addoption("Skylift"))
	{
		SpawnVehicle("SKYLIFT");
	}
	if (Addoption("Buckingham SuperVolito"))
	{
		SpawnVehicle("SUPERVOLITO");
	}
	if (Addoption("Buckingham SuperVolito Carbon"))
	{
		SpawnVehicle("SUPERVOLITO2");
	}
	if (Addoption("Buckingham Swift"))
	{
		SpawnVehicle("SWIFT");
	}
	if (Addoption("Sea Sparrow"))
	{
		SpawnVehicle("seasparrow");
	}
	if (Addoption("Buckingham Swift Deluxe"))
	{
		SpawnVehicle("SWIFT2");
	}
	if (Addoption("Valkyrie"))
	{
		SpawnVehicle("VALKYRIE");
	}
	if (Addoption("Valkyrie MOD.O"))
	{
		SpawnVehicle("VALKYRIE2");
	}
	if (Addoption("Buckingham Volatus"))
	{
		SpawnVehicle("VOLATUS");
	}

}
void Spawner::IndustrialspinSpawner()
{
	Addtitle("");
	Addsubtitle("Industrial");

	if (Settings::currentOption == 1) {
		previewCar("BULLDOZER");
	}
	if (Settings::currentOption == 2) {
		previewCar("CUTTER");
	}
	if (Settings::currentOption == 3) {
		previewCar("DUMP");
	}
	if (Settings::currentOption == 4) {
		previewCar("FLATBED");
	}
	if (Settings::currentOption == 5) {
		previewCar("GUARDIAN");
	}
	if (Settings::currentOption == 6) {
		previewCar("HANDLER");
	}
	if (Settings::currentOption == 7) {
		previewCar("MIXER");
	}
	if (Settings::currentOption == 8) {
		previewCar("MIXER2");
	}
	if (Settings::currentOption == 9) {
		previewCar("RUBBLE");
	}
	if (Settings::currentOption == 10) {
		previewCar("TIPTRUCK");
	}
	if (Settings::currentOption == 11) {
		previewCar("TIPTRUCK2");
	}
	if (Settings::currentOption == 12) {
		previewCar("CERBERUS");
	}
	if (Settings::currentOption == 13) {
		previewCar("CERBERU2");
	}
	if (Settings::currentOption == 14) {
		previewCar("CERBERU3");
	}

	if (Addoption("HVY Dozer"))
	{
		SpawnVehicle("BULLDOZER");
	}
	if (Addoption("HVY Cutter"))
	{
		SpawnVehicle("CUTTER");
	}
	if (Addoption("HVY Dump"))
	{
		SpawnVehicle("DUMP");
	}
	if (Addoption("MTL Flatbed"))
	{
		SpawnVehicle("FLATBED");
	}
	if (Addoption("Vapid Guardian"))
	{
		SpawnVehicle("GUARDIAN");
	}
	if (Addoption("Dock Handler"))
	{
		SpawnVehicle("HANDLER");
	}
	if (Addoption("HVY Mixer"))
	{
		SpawnVehicle("MIXER");
	}
	if (Addoption("HVY Mixer (dirty)"))
	{
		SpawnVehicle("MIXER2");
	}
	if (Addoption("JoBuilt Rubble"))
	{
		SpawnVehicle("RUBBLE");
	}
	if (Addoption("Brute Tipper (full)"))
	{
		SpawnVehicle("TIPTRUCK");
	}
	if (Addoption("Brute Tipper (empty)"))
	{
		SpawnVehicle("TIPTRUCK2");
	}
	if (Addoption("MTL Apocalypse Cerberus"))
	{
		SpawnVehicle("CERBERUS");
	}
	if (Addoption("MTL Future Shock Cerberus"))
	{
		SpawnVehicle("CERBERUS2");
	}
	if (Addoption("MTL Nightmare Cerberus"))
	{
		SpawnVehicle("CERBERUS3");
	}

}
void Spawner::MilitaryspinSpawner()
{
	Addtitle("");
	Addsubtitle("Military");

	if (Settings::currentOption == 1) {
		previewCar("BARRACKS");
	}
	if (Settings::currentOption == 2) {
		previewCar("BARRACKS2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BARRACKS3");
	}
	if (Settings::currentOption == 4) {
		previewCar("caracara");
	}
	if (Settings::currentOption == 5) {
		previewCar("barrage");
	}
	if (Settings::currentOption == 6) {
		previewCar("oppressor2");
	}
	if (Settings::currentOption == 7) {
		previewCar("thruster");
	}
	if (Settings::currentOption == 8) {
		previewCar("CRUSADER");
	}
	if (Settings::currentOption == 9) {
		previewCar("SCARAB2");
	}
	if (Settings::currentOption == 10) {
		previewCar("SCARAB3");
	}
	if (Settings::currentOption == 11) {
		previewCar("RHINO");
	}
	if (Settings::currentOption == 12) {
		previewCar("menacer");
	}
	if (Settings::currentOption == 13) {
		previewCar("khanjali");
	}
	if (Settings::currentOption == 14) {
		previewCar("SCARAB");
	}

	if (Addoption("Barracks (black)"))
	{
		SpawnVehicle("BARRACKS");
	}
	if (Addoption("HVY Barracks Semi"))
	{
		SpawnVehicle("BARRACKS2");
	}
	if (Addoption("Barracks (dirty)"))
	{
		SpawnVehicle("BARRACKS3");
	}
	if (Addoption("Vapid Caracara"))
	{
		SpawnVehicle("caracara");
	}
	if (Addoption("Barrage"))
	{
		SpawnVehicle("barrage");
	}
	if (Addoption("Pegassi Oppressor Mk.II"))
	{
		SpawnVehicle("oppressor2");
	}
	if (Addoption("Mamouth Thruster"))
	{
		SpawnVehicle("thruster");
	}
	if (Addoption("Canis Crusader"))
	{
		SpawnVehicle("CRUSADER");
	}
	if (Addoption("HVY Future Shock Scarab"))
	{
		SpawnVehicle("SCARAB2");
	}
	if (Addoption("HVY Nightmare Scarab"))
	{
		SpawnVehicle("SCARAB3");
	}
	if (Addoption("Rhino Tank"))
	{
		SpawnVehicle("RHINO");
	}
	if (Addoption("HVY Menacer"))
	{
		SpawnVehicle("menacer");
	}
	if (Addoption("TM-02 Khanjali"))
	{
		SpawnVehicle("khanjali");
	}
	if (Addoption("HVY Apocalypse Scarab"))
	{
		SpawnVehicle("SCARAB");
	}
}
void Spawner::MotorcyclespinSpawner()
{
	Addtitle("");
	Addsubtitle("Motorcycle");


	if (Settings::currentOption == 1) {
		previewCar("AKUMA");
	}
	if (Settings::currentOption == 2) {
		previewCar("AVARUS");
	}
	if (Settings::currentOption == 3) {
		previewCar("BAGGER");
	}
	if (Settings::currentOption == 4) {
		previewCar("BATI");
	}
	if (Settings::currentOption == 5) {
		previewCar("BATI2");
	}
	if (Settings::currentOption == 6) {
		previewCar("DEATHBIKE");
	}
	if (Settings::currentOption == 7) {
		previewCar("DEATHBIKE2");
	}
	if (Settings::currentOption == 8) {
		previewCar("DEATHBIKE3");
	}
	if (Settings::currentOption == 9) {
		previewCar("BF400");
	}
	if (Settings::currentOption == 10) {
		previewCar("CARBONRS");
	}
	if (Settings::currentOption == 11) {
		previewCar("CHIMERA");
	}
	if (Settings::currentOption == 12) {
		previewCar("DAEMON");
	}
	if (Settings::currentOption == 13) {
		previewCar("DAEMON2");
	}
	if (Settings::currentOption == 14) {
		previewCar("DEFILER");
	}
	if (Settings::currentOption == 15) {
		previewCar("DOUBLE");
	}
	if (Settings::currentOption == 16) {
		previewCar("ENDURO");
	}
	if (Settings::currentOption == 17) {
		previewCar("ESSKEY");
	}
	if (Settings::currentOption == 18) {
		previewCar("FAGGIO");
	}
	if (Settings::currentOption == 19) {
		previewCar("FAGGIO2");
	}
	if (Settings::currentOption == 20) {
		previewCar("FAGGIO3");
	}
	if (Settings::currentOption == 21) {
		previewCar("GARGOYLE");
	}
	if (Settings::currentOption == 22) {
		previewCar("HAKUCHOU");
	}
	if (Settings::currentOption == 23) {
		previewCar("HAKUCHOU2");
	}
	if (Settings::currentOption == 24) {
		previewCar("HEXER");
	}
	if (Settings::currentOption == 25) {
		previewCar("INNOVATION");
	}
	if (Settings::currentOption == 26) {
		previewCar("LECTRO");
	}
	if (Settings::currentOption == 27) {
		previewCar("MANCHEZ");
	}
	if (Settings::currentOption == 28) {
		previewCar("NEMESIS");
	}
	if (Settings::currentOption == 39) {
		previewCar("NIGHTBLADE");
	}
	if (Settings::currentOption == 30) {
		previewCar("PCJ");
	}
	if (Settings::currentOption == 31) {
		previewCar("RATBIKE");
	}
	if (Settings::currentOption == 32) {
		previewCar("RUFFIAN");
	}
	if (Settings::currentOption == 33) {
		previewCar("SANCHEZ");
	}
	if (Settings::currentOption == 34) {
		previewCar("SANCHEZ2");
	}
	if (Settings::currentOption == 35) {
		previewCar("SANCTUS");
	}
	if (Settings::currentOption == 36) {
		previewCar("SHOTARO");
	}
	if (Settings::currentOption == 37) {
		previewCar("SOVEREIGN");
	}
	if (Settings::currentOption == 38) {
		previewCar("THRUST");
	}
	if (Settings::currentOption == 39) {
		previewCar("VADER");
	}
	if (Settings::currentOption == 40) {
		previewCar("VINDICATOR");
	}
	if (Settings::currentOption == 41) {
		previewCar("VORTEX");
	}
	if (Settings::currentOption == 42) {
		previewCar("WOLFSBANE");
	}
	if (Settings::currentOption == 43) {
		previewCar("ZOMBIEA");
	}
	if (Settings::currentOption == 44) {
		previewCar("ZOMBIEB");
	}
	if (Settings::currentOption == 45) {
		previewCar("DIABLOUS");
	}
	if (Settings::currentOption == 46) {
		previewCar("DIABLOUS2");
	}
	if (Settings::currentOption == 47) {
		previewCar("DIABLOUS2");
	}
	if (Settings::currentOption == 48) {
		previewCar("FCR");
	}
	if (Settings::currentOption == 49) {
		previewCar("FCR2");
	}
	if (Settings::currentOption == 50) {
		previewCar("oppressor");
	}

	if (Addoption("Dinka Akuma"))
	{
		SpawnVehicle("AKUMA");
	}
	if (Addoption("LCC Avarus"))
	{
		SpawnVehicle("AVARUS");
	}
	if (Addoption("Western Bagger"))
	{
		SpawnVehicle("BAGGER");
	}
	if (Addoption("Pegassi Bati 801"))
	{
		SpawnVehicle("BATI");
	}
	if (Addoption("Pegassi Bati 801RR"))
	{
		SpawnVehicle("BATI2");
	}
	if (Addoption("Western Apocalypse Deathbike"))
	{
		SpawnVehicle("DEATHBIKE");
	}
	if (Addoption("Western Future Shock Deathbike"))
	{
		SpawnVehicle("DEATHBIKE2");
	}
	if (Addoption("Western Nightmare Deathbike"))
	{
		SpawnVehicle("DEATHBIKE3");
	}
	if (Addoption("Nagasaki BF400"))
	{
		SpawnVehicle("BF400");
	}
	if (Addoption("Nagasaki Carbon RS"))
	{
		SpawnVehicle("CARBONRS");
	}
	if (Addoption("Nagasaki Chimera"))
	{
		SpawnVehicle("CHIMERA");
	}
	if (Addoption("Western Cliffhanger"))
	{
		SpawnVehicle("DAEMON");
	}
	if (Addoption("Western Daemon"))
	{
		SpawnVehicle("DAEMON2");
	}
	if (Addoption("Western Daemon (alternate)"))
	{
		SpawnVehicle("DEFILER");
	}
	if (Addoption("Dinka Double-T"))
	{
		SpawnVehicle("DOUBLE");
	}
	if (Addoption("Dinka Enduro"))
	{
		SpawnVehicle("ENDURO");
	}
	if (Addoption("Pegassi Esskey"))
	{
		SpawnVehicle("ESSKEY");
	}
	if (Addoption("Pegassi Faggio Sport"))
	{
		SpawnVehicle("FAGGIO");
	}
	if (Addoption("Pegassi Faggio"))
	{
		SpawnVehicle("FAGGIO2");
	}
	if (Addoption("Pegassi Faggio Mod"))
	{
		SpawnVehicle("FAGGIO3");
	}
	if (Addoption("Western Gargoyle"))
	{
		SpawnVehicle("GARGOYLE");
	}
	if (Addoption("Shitzu Hakuchou"))
	{
		SpawnVehicle("HAKUCHOU");
	}
	if (Addoption("Shitzu Hakuchou Drag"))
	{
		SpawnVehicle("HAKUCHOU2");
	}
	if (Addoption("LCC Hexer"))
	{
		SpawnVehicle("HEXER");
	}
	if (Addoption("LCC Innovation"))
	{
		SpawnVehicle("INNOVATION");
	}
	if (Addoption("Principe Lectro"))
	{
		SpawnVehicle("LECTRO");
	}
	if (Addoption("Maibatsu Manchez"))
	{
		SpawnVehicle("MANCHEZ");
	}
	if (Addoption("Principe Nemesis"))
	{
		SpawnVehicle("NEMESIS");
	}
	if (Addoption("Western Nightblade"))
	{
		SpawnVehicle("NIGHTBLADE");
	}
	if (Addoption("Shitzu PCJ 600"))
	{
		SpawnVehicle("PCJ");
	}
	if (Addoption("Western Rat Bike"))
	{
		SpawnVehicle("RATBIKE");
	}
	if (Addoption("Maibatsu Sanchez (livery)"))
	{
		SpawnVehicle("SANCHEZ");
	}
	if (Addoption("Maibatsu Sanchez"))
	{
		SpawnVehicle("SANCHEZ2");
	}
	if (Addoption("LCC Sanctus"))
	{
		SpawnVehicle("SANCTUS");
	}
	if (Addoption("Nagasaki Shotaro"))
	{
		SpawnVehicle("SHOTARO");
	}
	if (Addoption("Western Sovereign"))
	{
		SpawnVehicle("SOVEREIGN");
	}
	if (Addoption("Dinka Thrust"))
	{
		SpawnVehicle("THRUST");
	}
	if (Addoption("Shitzu Vader"))
	{
		SpawnVehicle("VADER");
	}
	if (Addoption("Dinka Vindicator"))
	{
		SpawnVehicle("VINDICATOR");
	}
	if (Addoption("Pegassi Vortex"))
	{
		SpawnVehicle("VORTEX");
	}
	if (Addoption("Western Wolfsbane"))
	{
		SpawnVehicle("WOLFSBANE");
	}
	if (Addoption("Western Zombie Bobber"))
	{
		SpawnVehicle("ZOMBIEA");
	}
	if (Addoption("Western Zombie Chopper"))
	{
		SpawnVehicle("ZOMBIEB");
	}
	if (Addoption("Principe Diablous"))
	{
		SpawnVehicle("DIABLOUS");
	}
	if (Addoption("Principe Diablous Custom"))
	{
		SpawnVehicle("DIABLOUS2");
	}
	if (Addoption("Pegassi FCR 1000"))
	{
		SpawnVehicle("FCR");
	}
	if (Addoption("Pegassi FCR 1000 Custom"))
	{
		SpawnVehicle("FCR2");
	}
	if (Addoption("Oppressor"))
	{
		SpawnVehicle("oppressor");
	}

}
void Spawner::MusclespinSpawner()
{
	Addtitle("");
	Addsubtitle("Muscle");


	if (Settings::currentOption == 1) {
		previewCar("BLADE");
	}
	if (Settings::currentOption == 2) {
		previewCar("BUCCANEER");
	}
	if (Settings::currentOption == 3) {
		previewCar("BUCCANEER2");
	}
	if (Settings::currentOption == 4) {
		previewCar("CHINO");
	}
	if (Settings::currentOption == 5) {
		previewCar("CHINO2");
	}
	if (Settings::currentOption == 6) {
		previewCar("DOMINATOR4");
	}
	if (Settings::currentOption == 7) {
		previewCar("DOMINATOR5");
	}
	if (Settings::currentOption == 8) {
		previewCar("DOMINATOR6");
	}
	if (Settings::currentOption == 9) {
		previewCar("COQUETTE3");
	}
	if (Settings::currentOption == 10) {
		previewCar("DOMINATOR");
	}
	if (Settings::currentOption == 11) {
		previewCar("DOMINATOR2");
	}
	if (Settings::currentOption == 12) {
		previewCar("DUKES");
	}
	if (Settings::currentOption == 13) {
		previewCar("DUKES2");
	}
	if (Settings::currentOption == 14) {
		previewCar("GAUNTLET");
	}
	if (Settings::currentOption == 15) {
		previewCar("GAUNTLET2");
	}
	if (Settings::currentOption == 16) {
		previewCar("FACTION");
	}
	if (Settings::currentOption == 17) {
		previewCar("FACTION2");
	}
	if (Settings::currentOption == 18) {
		previewCar("FACTION3");
	}
	if (Settings::currentOption == 21) {
		previewCar("HOTKNIFE");
	}
	if (Settings::currentOption == 22) {
		previewCar("LURCHER");
	}
	if (Settings::currentOption == 23) {
		previewCar("MOONBEAM");
	}
	if (Settings::currentOption == 24) {
		previewCar("MOONBEAM2");
	}
	if (Settings::currentOption == 25) {
		previewCar("NIGHTSHADE");
	}
	if (Settings::currentOption == 26) {
		previewCar("PHOENIX");
	}
	if (Settings::currentOption == 27) {
		previewCar("PICADOR");
	}
	if (Settings::currentOption == 28) {
		previewCar("RATLOADER");
	}
	if (Settings::currentOption == 29) {
		previewCar("rapidgt3");
	}
	if (Settings::currentOption == 30) {
		previewCar("RATLOADER2");
	}
	if (Settings::currentOption == 31) {
		previewCar("RUINER");
	}
	if (Settings::currentOption == 32) {
		previewCar("RUINER2");
	}
	if (Settings::currentOption == 33) {
		previewCar("RUINER3");
	}
	if (Settings::currentOption == 34) {
		previewCar("SABREGT");
	}
	if (Settings::currentOption == 35) {
		previewCar("SABREGT2");
	}
	if (Settings::currentOption == 36) {
		previewCar("SLAMVAN");
	}
	if (Settings::currentOption == 37) {
		previewCar("SLAMVAN2");
	}
	if (Settings::currentOption == 38) {
		previewCar("SLAMVAN3");
	}
	if (Settings::currentOption == 39) {
		previewCar("STALION");
	}
	if (Settings::currentOption == 40) {
		previewCar("STALION2");
	}
	if (Settings::currentOption == 41) {
		previewCar("TAMPA");
	}
	if (Settings::currentOption == 42) {
		previewCar("VIGERO");
	}
	if (Settings::currentOption == 43) {
		previewCar("VIRGO");
	}
	if (Settings::currentOption == 44) {
		previewCar("VIRGO2");
	}
	if (Settings::currentOption == 45) {
		previewCar("VIRGO3");
	}
	if (Settings::currentOption == 46) {
		previewCar("VOODOO");
	}
	if (Settings::currentOption == 47) {
		previewCar("VOODOO2");
	}

	if (Addoption("Vapid Blade"))
	{
		SpawnVehicle("BLADE");
	}
	if (Addoption("Albany Buccaneer"))
	{
		SpawnVehicle("BUCCANEER");
	}
	if (Addoption("Albany Buccaneer Custom"))
	{
		SpawnVehicle("BUCCANEER2");
	}
	if (Addoption("Vapid Chino"))
	{
		SpawnVehicle("CHINO");
	}
	if (Addoption("Vapid Chino Custom"))
	{
		SpawnVehicle("CHINO2");
	}
	if (Addoption("Vapid Apocalypse Dominator"))
	{
		SpawnVehicle("DOMINATOR4");
	}
	if (Addoption("Vapid Future Shock Dominator"))
	{
		SpawnVehicle("DOMINATOR5");
	}
	if (Addoption("Vapid Nightmare Dominator"))
	{
		SpawnVehicle("DOMINATOR6");
	}
	if (Addoption("Invetro Coquette Blackfin"))
	{
		SpawnVehicle("COQUETTE3");
	}
	if (Addoption("Vapid Dominator"))
	{
		SpawnVehicle("DOMINATOR");
	}
	if (Addoption("Vapid Pisswasser Dominator"))
	{
		SpawnVehicle("DOMINATOR2");
	}
	if (Addoption("Imponte Dukes"))
	{
		SpawnVehicle("DUKES");
	}
	if (Addoption("Imponte Duke o'Death"))
	{
		SpawnVehicle("DUKES2");
	}
	if (Addoption("Bravado Gauntlet"))
	{
		SpawnVehicle("GAUNTLET");
	}
	if (Addoption("Bravado Redwood Gauntlet"))
	{
		SpawnVehicle("GAUNTLET2");
	}
	if (Addoption("Willard Faction"))
	{
		SpawnVehicle("FACTION");
	}
	if (Addoption("Willard Faction Custom"))
	{
		SpawnVehicle("FACTION2");
	}
	if (Addoption("Willard Faction Custom Donk"))
	{
		SpawnVehicle("FACTION3");
	}
	if (Addoption("Vapid Hotknife"))
	{
		SpawnVehicle("HOTKNIFE");
	}
	if (Addoption("Albany Lurcher"))
	{
		SpawnVehicle("LURCHER");
	}
	if (Addoption("Declasse Moonbeam"))
	{
		SpawnVehicle("MOONBEAM");
	}
	if (Addoption("Declasse Moonbeam Custom"))
	{
		SpawnVehicle("MOONBEAM2");
	}
	if (Addoption("Imponte Nightshade"))
	{
		SpawnVehicle("NIGHTSHADE");
	}
	if (Addoption("Imponte Phoenix"))
	{
		SpawnVehicle("PHOENIX");
	}
	if (Addoption("Cheval Picador"))
	{
		SpawnVehicle("PICADOR");
	}
	if (Addoption("Rat-Loader"))
	{
		SpawnVehicle("RATLOADER");
	}
	if (Addoption("Dewbauchee Raid GT Classic"))
	{
		SpawnVehicle("rapidgt3");
	}
	if (Addoption("Bravado Rat Truck"))
	{
		SpawnVehicle("RATLOADER2");
	}
	if (Addoption("Imponte Ruiner"))
	{
		SpawnVehicle("RUINER");
	}
	if (Addoption("Imponte Ruiner 2000"))
	{
		SpawnVehicle("RUINER2");
	}
	if (Addoption("Imponte Ruiner (wrecked)"))
	{
		SpawnVehicle("RUINER3");
	}
	if (Addoption("Declasse Sabre Turbo"))
	{
		SpawnVehicle("SABREGT");
	}
	if (Addoption("Declasse Sabre Turbo"))
	{
		SpawnVehicle("SABREGT2");
	}
	if (Addoption("Vapid Slamvan"))
	{
		SpawnVehicle("SLAMVAN");
	}
	if (Addoption("Vapid Lost Slamvan"))
	{
		SpawnVehicle("SLAMVAN2");
	}
	if (Addoption("Vapid Slamvan Custom"))
	{
		SpawnVehicle("SLAMVAN3");
	}
	if (Addoption("Declasse Stallion"))
	{
		SpawnVehicle("STALION");
	}
	if (Addoption("Declasse Burger Shot Stallion"))
	{
		SpawnVehicle("STALION2");
	}
	if (Addoption("Declasse Tampa"))
	{
		SpawnVehicle("TAMPA");
	}
	if (Addoption("Declasse Vigero"))
	{
		SpawnVehicle("VIGERO");
	}
	if (Addoption("Albany Virgo"))
	{
		SpawnVehicle("VIRGO");
	}
	if (Addoption("Dundreary Virgo Classic Custom"))
	{
		SpawnVehicle("VIRGO2");
	}
	if (Addoption("Dundreary Virgo Classic"))
	{
		SpawnVehicle("VIRGO3");
	}
	if (Addoption("Declasse Voodoo Custom"))
	{
		SpawnVehicle("VOODOO");
	}
	if (Addoption("Declassse Voodoo"))
	{
		SpawnVehicle("VOODOO2");
	}
}
void Spawner::OffRoadspinSpawner()
{
	Addtitle("");
	Addsubtitle("OffRoad");


	if (Settings::currentOption == 1) {
		previewCar("BRUISER");
	}
	if (Settings::currentOption == 2) {
		previewCar("BRUISER2");
	}
	if (Settings::currentOption == 3) {
		previewCar("BRUISER3");
	}
	if (Settings::currentOption == 4) {
		previewCar("BRUTUS");
	}
	if (Settings::currentOption == 5) {
		previewCar("BRUTUS2");
	}
	if (Settings::currentOption == 6) {
		previewCar("BRUTUS3");
	}
	if (Settings::currentOption == 7) {
		previewCar("BFINJECTION");
	}
	if (Settings::currentOption == 8) {
		previewCar("BIFTA");
	}
	if (Settings::currentOption == 9) {
		previewCar("BLAZER");
	}
	if (Settings::currentOption == 10) {
		previewCar("BLAZER2");
	}
	if (Settings::currentOption == 11) {
		previewCar("BLAZER3");
	}
	if (Settings::currentOption == 12) {
		previewCar("BLAZER34");
	}
	if (Settings::currentOption == 13) {
		previewCar("BODHI2");
	}
	if (Settings::currentOption == 14) {
		previewCar("BRAWLER");
	}
	if (Settings::currentOption == 15) {
		previewCar("DLOADER");
	}
	if (Settings::currentOption == 16) {
		previewCar("DUBSTA3");
	}
	if (Settings::currentOption == 17) {
		previewCar("DUNE");
	}
	if (Settings::currentOption == 18) {
		previewCar("DUNE2");
	}
	if (Settings::currentOption == 21) {
		previewCar("INSURGENT");
	}
	if (Settings::currentOption == 22) {
		previewCar("INSURGENT2");
	}
	if (Settings::currentOption == 23) {
		previewCar("KALAHARI");
	}
	if (Settings::currentOption == 24) {
		previewCar("MESA3");
	}
	if (Settings::currentOption == 25) {
		previewCar("MONSTER");
	}
	if (Settings::currentOption == 26) {
		previewCar("MONSTER3");
	}
	if (Settings::currentOption == 27) {
		previewCar("MONSTER4");
	}
	if (Settings::currentOption == 28) {
		previewCar("MONSTER5");
	}
	if (Settings::currentOption == 29) {
		previewCar("RANCHERXL");
	}
	if (Settings::currentOption == 30) {
		previewCar("RANCHERXL2");
	}
	if (Settings::currentOption == 31) {
		previewCar("REBEL");
	}
	if (Settings::currentOption == 32) {
		previewCar("REBEL2");
	}
	if (Settings::currentOption == 33) {
		previewCar("SANDKING");
	}
	if (Settings::currentOption == 34) {
		previewCar("SANDKING2");
	}
	if (Settings::currentOption == 35) {
		previewCar("TECHNICAL");
	}
	if (Settings::currentOption == 36) {
		previewCar("TROPHYTRUCK");
	}
	if (Settings::currentOption == 37) {
		previewCar("TROPHYTRUCK2");
	}
	if (Settings::currentOption == 38) {
		previewCar("TECHNICAL2");
	}
	if (Settings::currentOption == 39) {
		previewCar("DUNE4");
	}
	if (Settings::currentOption == 40) {
		previewCar("DUNE5");
	}
	if (Settings::currentOption == 41) {
		previewCar("BLAZER5");
	}

	if (Addoption("Benefactor Apocalypse Bruiser"))
	{
		SpawnVehicle("BRUISER");
	}
	if (Addoption("Benefator Future Shock Bruiser"))
	{
		SpawnVehicle("BRUISER2");
	}
	if (Addoption("Benefactor Nightmare Bruiser"))
	{
		SpawnVehicle("BRUISER3");
	}
	if (Addoption("Declasse Apocalypse Brutus"))
	{
		SpawnVehicle("BRUTUS");
	}
	if (Addoption("Declasse Future Shock Brutus"))
	{
		SpawnVehicle("BRUTUS2");
	}
	if (Addoption("Declasse Nightmare Brutus"))
	{
		SpawnVehicle("BRUTUS3");
	}
	if (Addoption("BF Injection"))
	{
		SpawnVehicle("BFINJECTION");
	}
	if (Addoption("BF Bifta"))
	{
		SpawnVehicle("BIFTA");
	}
	if (Addoption("Nagasaki Blazer"))
	{
		SpawnVehicle("BLAZER");
	}
	if (Addoption("Nagasaki Blazer Lifeguard"))
	{
		SpawnVehicle("BLAZER2");
	}
	if (Addoption("Nagasaki Hot Rod Blazer"))
	{
		SpawnVehicle("BLAZER3");
	}
	if (Addoption("Nagasaki Streeet Blazer"))
	{
		SpawnVehicle("BLAZER4");
	}
	if (Addoption("Canis Bodhi"))
	{
		SpawnVehicle("BODHI2");
	}
	if (Addoption("Coil Brawler"))
	{
		SpawnVehicle("BRAWLER");
	}
	if (Addoption("Bravado Duneloader"))
	{
		SpawnVehicle("DLOADER");
	}
	if (Addoption("Benefactor Dubsta 6x6"))
	{
		SpawnVehicle("DUBSTA3");
	}
	if (Addoption("BF Dune Buggy"))
	{
		SpawnVehicle("DUNE");
	}
	if (Addoption("Space Docker"))
	{
		SpawnVehicle("DUNE2");
	}
	if (Addoption("HVY Insurgent Pick-up"))
	{
		SpawnVehicle("INSURGENT");
	}
	if (Addoption("HVY Insurgent"))
	{
		SpawnVehicle("INSURGENT2");
	}
	if (Addoption("Canis Kalahari"))
	{
		SpawnVehicle("KALAHARI");
	}
	if (Addoption("Cheval Marshall"))
	{
		SpawnVehicle("MARSHALL");
	}
	if (Addoption("Canis Mesa"))
	{
		SpawnVehicle("MESA3");
	}
	if (Addoption("Vapid Liberator"))
	{
		SpawnVehicle("MONSTER");
	}
	if (Addoption("Bravado Apocalypse Sasquatch"))
	{
		SpawnVehicle("MONSTER3");
	}
	if (Addoption("Bravado Future Shock Sasquatch"))
	{
		SpawnVehicle("MONSTER4");
	}
	if (Addoption("Bravado Nightmare Sasquatch"))
	{
		SpawnVehicle("MONSTER5");
	}
	if (Addoption("Declasse Rancher XL"))
	{
		SpawnVehicle("RANCHERXL");
	}
	if (Addoption("Declasse Rancher XL (Snow)"))
	{
		SpawnVehicle("RANCHERXL2");
	}
	if (Addoption("Karin Rusty Rebel"))
	{
		SpawnVehicle("REBEL");
	}
	if (Addoption("Karin Rebel"))
	{
		SpawnVehicle("REBEL2");
	}
	if (Addoption("Vapid Sandking XL"))
	{
		SpawnVehicle("SANDKING");
	}
	if (Addoption("Vapid Sandking SWB"))
	{
		SpawnVehicle("SANDKING2");
	}
	if (Addoption("Karin Technical"))
	{
		SpawnVehicle("TECHNICAL");
	}
	if (Addoption("Vapid Trophy Truck"))
	{
		SpawnVehicle("TROPHYTRUCK");
	}
	if (Addoption("Vapid Trophy Truck"))
	{
		SpawnVehicle("TROPHYTRUCK2");
	}
	if (Addoption("Karin Technical Aqua"))
	{
		SpawnVehicle("TECHNICAL2");
	}
	if (Addoption("Ramp Buggy (Spoiler)"))
	{
		SpawnVehicle("DUNE4");
	}
	if (Addoption("Ramp Buggy"))
	{
		SpawnVehicle("DUNE5");
	}
	if (Addoption("Nagasaki Blazer Aqua"))
	{
		SpawnVehicle("BLAZER5");
	}
}
void Spawner::PlanesspinSpawner()
{
	Addtitle("");
	Addsubtitle("Planes");


	if (Settings::currentOption == 1) {
		previewCar("alphaz1");
	}
	if (Settings::currentOption == 2) {
		previewCar("avenger");
	}
	if (Settings::currentOption == 3) {
		previewCar("BESRA");
	}
	if (Settings::currentOption == 4) {
		previewCar("bombushka");
	}
	if (Settings::currentOption == 5) {
		previewCar("CARGOPLANE");
	}
	if (Settings::currentOption == 6) {
		previewCar("CUBAN800");
	}
	if (Settings::currentOption == 7) {
		previewCar("DODO");
	}
	if (Settings::currentOption == 8) {
		previewCar("DUSTER");
	}
	if (Settings::currentOption == 9) {
		previewCar("HYDRA");
	}
	if (Settings::currentOption == 10) {
		previewCar("JET");
	}
	if (Settings::currentOption == 11) {
		previewCar("LAZER");
	}
	if (Settings::currentOption == 12) {
		previewCar("LUXOR");
	}
	if (Settings::currentOption == 13) {
		previewCar("LUXOR2");
	}
	if (Settings::currentOption == 14) {
		previewCar("seabreeze");
	}
	if (Settings::currentOption == 15) {
		previewCar("tula");
	}
	if (Settings::currentOption == 16) {
		previewCar("MAMMATUS");
	}
	if (Settings::currentOption == 17) {
		previewCar("MILJET");
	}
	if (Settings::currentOption == 18) {
		previewCar("NIMBUS");
	}
	if (Settings::currentOption == 21) {
		previewCar("ROGUE");
	}
	if (Settings::currentOption == 22) {
		previewCar("STARLING");
	}
	if (Settings::currentOption == 23) {
		previewCar("PYRO");
	}
	if (Settings::currentOption == 24) {
		previewCar("MOGUL");
	}
	if (Settings::currentOption == 25) {
		previewCar("MICROLIGHT");
	}
	if (Settings::currentOption == 26) {
		previewCar("MOLOTOK");
	}
	if (Settings::currentOption == 27) {
		previewCar("NOKOTA");
	}
	if (Settings::currentOption == 28) {
		previewCar("HOWARD");
	}
	if (Settings::currentOption == 29) {
		previewCar("SHAMAL");
	}
	if (Settings::currentOption == 30) {
		previewCar("STRIKEFORCE");
	}
	if (Settings::currentOption == 31) {
		previewCar("STUNT");
	}
	if (Settings::currentOption == 32) {
		previewCar("TITAN");
	}
	if (Settings::currentOption == 33) {
		previewCar("VELUM");
	}
	if (Settings::currentOption == 34) {
		previewCar("VELUM2");
	}
	if (Settings::currentOption == 35) {
		previewCar("VESTRA");
	}
	if (Settings::currentOption == 36) {
		previewCar("VOLATOL");
	}

	if (Addoption("Buckingham Alpha-Z1"))
	{
		SpawnVehicle("alphaz1");
	}
	if (Addoption("Mammoth Avenger"))
	{
		SpawnVehicle("avenger");
	}
	if (Addoption("Western Besra"))
	{
		SpawnVehicle("BESRA");
	}
	if (Addoption("RM-10 Bombushka"))
	{
		SpawnVehicle("bombushka");
	}
	if (Addoption("Cargoplane"))
	{
		SpawnVehicle("CARGOPLANE");
	}
	if (Addoption("Cuban 800"))
	{
		SpawnVehicle("CUBAN800");
	}
	if (Addoption("Mammoth Dodo"))
	{
		SpawnVehicle("DODO");
	}
	if (Addoption("Duster"))
	{
		SpawnVehicle("DUSTER");
	}
	if (Addoption("Mammoth Hydra"))
	{
		SpawnVehicle("HYDRA");
	}
	if (Addoption("Jet"))
	{
		SpawnVehicle("JET");
	}
	if (Addoption("P-996 Lazer"))
	{
		SpawnVehicle("LAZER");
	}
	if (Addoption("Buckingham Luxor"))
	{
		SpawnVehicle("LUXOR");
	}
	if (Addoption("Buckingham Luxor Deluxe"))
	{
		SpawnVehicle("LUXOR2");
	}
	if (Addoption("Western Seabreeze"))
	{
		SpawnVehicle("seabreeze");
	}
	if (Addoption("Western Seabreeze"))
	{
		SpawnVehicle("tula");
	}
	if (Addoption("Mammatus"))
	{
		SpawnVehicle("MAMMATUS");
	}
	if (Addoption("Buckingham Miljet"))
	{
		SpawnVehicle("MILJET");
	}
	if (Addoption("Buckingham Nimbus"))
	{
		SpawnVehicle("NIMBUS");
	}
	if (Addoption("Western Rogue"))
	{
		SpawnVehicle("ROGUE");
	}
	if (Addoption("LF-22 Starling"))
	{
		SpawnVehicle("STARLING");
	}
	if (Addoption("Pyro"))
	{
		SpawnVehicle("PYRO");
	}
	if (Addoption("Mammoth Mogul"))
	{
		SpawnVehicle("mogul");
	}
	if (Addoption("Nagasaki Ultralight"))
	{
		SpawnVehicle("microlight");
	}
	if (Addoption("V-65 Molotok"))
	{
		SpawnVehicle("molotok");
	}
	if (Addoption("P-45 Nokota"))
	{
		SpawnVehicle("nokota");
	}
	if (Addoption("Buckingham Howard NX-25"))
	{
		SpawnVehicle("howard");
	}
	if (Addoption("Buckinghma Shamal"))
	{
		SpawnVehicle("SHAMAL");
	}
	if (Addoption("B-11 Strikeforce"))
	{
		SpawnVehicle("strikeforce");
	}
	if (Addoption("Mallard"))
	{
		SpawnVehicle("STUNT");
	}
	if (Addoption("Titan"))
	{
		SpawnVehicle("TITAN");
	}
	if (Addoption("Velum"))
	{
		SpawnVehicle("VELUM");
	}
	if (Addoption("Velum 5-seater"))
	{
		SpawnVehicle("VELUM2");
	}
	if (Addoption("Buckingham Vestra"))
	{
		SpawnVehicle("VESTRA");
	}
	if (Addoption("Volatol"))
	{
		SpawnVehicle("volatol");
	}
}
void Spawner::SedansspinSpawner()
{
	Addtitle("");
	Addsubtitle("Sedans");


	if (Settings::currentOption == 1) {
		previewCar("ASEA");
	}
	if (Settings::currentOption == 2) {
		previewCar("ASEA2");
	}
	if (Settings::currentOption == 3) {
		previewCar("ASTEROPE");
	}
	if (Settings::currentOption == 4) {
		previewCar("COG55");
	}
	if (Settings::currentOption == 5) {
		previewCar("COG552");
	}
	if (Settings::currentOption == 6) {
		previewCar("COGNOSCENTI");
	}
	if (Settings::currentOption == 7) {
		previewCar("COGNOSCENTI2");
	}
	if (Settings::currentOption == 8) {
		previewCar("EMPEROR3");
	}
	if (Settings::currentOption == 9) {
		previewCar("FUGITIVE");
	}
	if (Settings::currentOption == 10) {
		previewCar("GLENDALE");
	}
	if (Settings::currentOption == 11) {
		previewCar("INGOT");
	}
	if (Settings::currentOption == 12) {
		previewCar("INTRUDER");
	}
	if (Settings::currentOption == 13) {
		previewCar("LIMO2");
	}
	if (Settings::currentOption == 14) {
		previewCar("PREMIER");
	}
	if (Settings::currentOption == 15) {
		previewCar("PRIMO");
	}
	if (Settings::currentOption == 16) {
		previewCar("PRIMO2");
	}
	if (Settings::currentOption == 17) {
		previewCar("REGINA");
	}
	if (Settings::currentOption == 18) {
		previewCar("ROMERO");
	}
	if (Settings::currentOption == 21) {
		previewCar("SCHAFTER2");
	}
	if (Settings::currentOption == 22) {
		previewCar("SCHAFTER5");
	}
	if (Settings::currentOption == 23) {
		previewCar("SCHAFTER6");
	}
	if (Settings::currentOption == 24) {
		previewCar("STANIER");
	}
	if (Settings::currentOption == 25) {
		previewCar("STRATUM");
	}
	if (Settings::currentOption == 26) {
		previewCar("STRETCH");
	}
	if (Settings::currentOption == 27) {
		previewCar("SUPERD");
	}
	if (Settings::currentOption == 28) {
		previewCar("SURGE");
	}
	if (Settings::currentOption == 29) {
		previewCar("TAILGATER");
	}
	if (Settings::currentOption == 30) {
		previewCar("WARRENER");
	}
	if (Settings::currentOption == 31) {
		previewCar("WASHINGTON");
	}

	if (Addoption("Declasse Asea"))
	{
		SpawnVehicle("ASEA");
	}
	if (Addoption("Declasse Asea (Snow)"))
	{
		SpawnVehicle("ASEA2");
	}
	if (Addoption("Karin Asterope"))
	{
		SpawnVehicle("ASTEROPE");
	}
	if (Addoption("Enus Cognoscenti 55"))
	{
		SpawnVehicle("COG55");
	}
	if (Addoption("Enus Cognoscenti 55 (armoured)"))
	{
		SpawnVehicle("COG552");
	}
	if (Addoption("Enus Cognoscenti"))
	{
		SpawnVehicle("COGNOSCENTI");
	}
	if (Addoption("Enus Cognoscenti (armoured)"))
	{
		SpawnVehicle("COGNOSCENTI2");
	}
	if (Addoption("Albany Emperor"))
	{
		SpawnVehicle("EMPEROR");
	}
	if (Addoption("Albany Emperor (dirty)"))
	{
		SpawnVehicle("EMPEROR2");
	}
	if (Addoption("Albany Emperor (Snow)"))
	{
		SpawnVehicle("EMPEROR3");
	}
	if (Addoption("Cheval Fugitive"))
	{
		SpawnVehicle("FUGITIVE");
	}
	if (Addoption("Benefactor Glendale"))
	{
		SpawnVehicle("GLENDALE");
	}
	if (Addoption("Vulcan Ingot"))
	{
		SpawnVehicle("INGOT");
	}
	if (Addoption("Karin Intruder"))
	{
		SpawnVehicle("INTRUDER");
	}
	if (Addoption("Benefactor Turreted Limo"))
	{
		SpawnVehicle("LIMO2");
	}
	if (Addoption("Declasse Premier"))
	{
		SpawnVehicle("PREMIER");
	}
	if (Addoption("Albany Primo"))
	{
		SpawnVehicle("PRIMO");
	}
	if (Addoption("Albany Primo Custom"))
	{
		SpawnVehicle("PRIMO2");
	}
	if (Addoption("Dundreary Regina"))
	{
		SpawnVehicle("REGINA");
	}
	if (Addoption("Chariot Romero Hearse"))
	{
		SpawnVehicle("ROMERO");
	}
	if (Addoption("Benefactor Schafter"))
	{
		SpawnVehicle("SCHAFTER2");
	}
	if (Addoption("Benefactor Schafter V12 (armoured)"))
	{
		SpawnVehicle("SCHAFTER5");
	}
	if (Addoption("Benefactor Schafter LWB (armoured)"))
	{
		SpawnVehicle("SCHAFTER6");
	}
	if (Addoption("Vapid Stanier"))
	{
		SpawnVehicle("STANIER");
	}
	if (Addoption("Zinconium Stratum"))
	{
		SpawnVehicle("STRATUM");
	}
	if (Addoption("Dundreary Stretch"))
	{
		SpawnVehicle("STRETCH");
	}
	if (Addoption("Enus Super Diamond"))
	{
		SpawnVehicle("SUPERD");
	}
	if (Addoption("Cheval Surge"))
	{
		SpawnVehicle("SURGE");
	}
	if (Addoption("Obey Tailgater"))
	{
		SpawnVehicle("TAILGATER");
	}
	if (Addoption("Vulcan Warrener"))
	{
		SpawnVehicle("WARRENER");
	}
	if (Addoption("Albany Washington"))
	{
		SpawnVehicle("WASHINGTON");
	}
}
void Spawner::ServicespinSpawner()
{
	Addtitle("");
	Addsubtitle("Service");
	if (Settings::currentOption == 1) {
		previewCar("AIRBUS");
	}
	if (Settings::currentOption == 2) {
		previewCar("BRICKADE");
	}
	if (Settings::currentOption == 3) {
		previewCar("BUS");
	}
	if (Settings::currentOption == 4) {
		previewCar("COACH");
	}
	if (Settings::currentOption == 5) {
		previewCar("RALLYTRUCK");
	}
	if (Settings::currentOption == 6) {
		previewCar("RENTALBUS");
	}
	if (Settings::currentOption == 7) {
		previewCar("TAXI");
	}
	if (Settings::currentOption == 8) {
		previewCar("MIXER2");
	}
	if (Settings::currentOption == 9) {
		previewCar("patriot2");
	}
	if (Settings::currentOption == 10) {
		previewCar("TOURBUS");
	}
	if (Settings::currentOption == 11) {
		previewCar("TRASH");
	}
	if (Settings::currentOption == 12) {
		previewCar("TRASH2");
	}
	if (Settings::currentOption == 13) {
		previewCar("WASTELANDER");
	}

	if (Addoption("Airport Bus"))
	{
		SpawnVehicle("AIRBUS");
	}
	if (Addoption("MTL Brickade"))
	{
		SpawnVehicle("BRICKADE");
	}
	if (Addoption("MTL Brickade"))
	{
		SpawnVehicle("BUS");
	}
	if (Addoption("Dashound"))
	{
		SpawnVehicle("COACH");
	}
	if (Addoption("MTL Dune"))
	{
		SpawnVehicle("RALLYTRUCK");
	}
	if (Addoption("Rental Shuttle Bus"))
	{
		SpawnVehicle("RENTALBUS");
	}
	if (Addoption("Taxi"))
	{
		SpawnVehicle("TAXI");
	}
	if (Addoption("Mammoth Patriot Stretch"))
	{
		SpawnVehicle("patriot2");
	}
	if (Addoption("Tourbus"))
	{
		SpawnVehicle("TOURBUS");
	}
	if (Addoption("Trashmaster"))
	{
		SpawnVehicle("TRASH");
	}
	if (Addoption("Trashmaster (dirty)"))
	{
		SpawnVehicle("TRASH2");
	}
	if (Addoption("MTL Wastelander"))
	{
		SpawnVehicle("WASTELANDER");
	}
}

bool Spawner::Turbobo, Spawner::Lightt, Spawner::checkss, Spawner::nopooptries, Spawner::Neon = false;//LSC bool





int secondaryColor, primaryColor, modType, Red, Blue, Green, TR, TG, TB, Prim_, Sec_, SR, SB, SG, red, green, blue, Tint_, engine, brakes, armoor, trans, sup, Bespoke, Originals, NR, NG, NB = 0;// LSC

void Spawner::MLSC()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int rooff = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 10);
	int hoood = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 7);
	int grille = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 6);
	int side = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 3);
	int exhaust = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 4);
	int roll = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 5);
	int fenderr = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 9);
	int spo = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 0);
	int vehicleModCount1 = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 1);
	int vehicleModCount2 = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 2);
	Addtitle("");
	Addsubtitle("LSC");
	//Addsub("Armour", Armour); no need to use this anymore
	Addint("Armour", armoor, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 16, armoor, 0); }
	//Addsub("Brakes", Brakes); no need to use this anymore
	Addint("Brakes", brakes, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 12, brakes, 0); }
	//Addsub("Engine", Engine); no need to use this anymore
	Addint("Engine", engine, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 11, brakes, 0); }
	Hash hithere = ENTITY::GET_ENTITY_MODEL(veh);
	if (VEHICLE::IS_THIS_MODEL_A_BIKE(hithere) == true)
	{
		if (vehicleModCount1 != 0)
		{
			Addsub("Fairing", fbumper);
		}

	}
	else
	{
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (vehicleModCount1 != 0)
			{
				Addsub("Front Bumper", fbumper);
			}
		}
		else
		{

		}
	}
	{
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (vehicleModCount2 != 0)
			{
				Addsub("Rear Bumper", rbumper);
			}
		}
		else
		{

		}
	}
	if (VEHICLE::IS_THIS_MODEL_A_BIKE(hithere) == true)
	{
		if (rooff != 0)
		{
			Addsub("Saddle bags", Roof);//done
		}


	}
	else
	{
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (rooff != 0)
			{
				Addsub("Roof", Roof);//done
			}
		}
		else
		{

		}
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (hoood != 0)
		{
			Addsub("Hood", Hood);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (grille != 0)
		{
			Addsub("Grill", Grill);//done
		}
	}
	else
	{

	}
	//Addsub("Roof", Roof);//done
	Addsub("Light", Light);//done
	Addsub("Plate", Plate);//done			
	//Addsub("Girlle", Girll);//done
//	Addint("Horns", horns, 0, 49); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 14, horns, 0); }
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (side != 0)
		{
			Addsub("Skirts", Skirts);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (exhaust != 0)
		{
			Addsub("Exhaust", Exhaust);//done
		}
	}
	else
	{

	}
	if (VEHICLE::IS_THIS_MODEL_A_BIKE(hithere) == true)
	{
		if (roll != 0)
		{
			Addsub("Frame", Rollcage);//done	
		}
	}
	else
	{
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (roll != 0)
			{
				Addsub("Rollcage", Rollcage);//done				
			}
		}
		else
		{

		}
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (fenderr != 0)
		{
			Addsub("Fenders", Fenders);//done
		}
	}
	else
	{

	}
	Addsub("Respray", Resprayss);// done
	//Addsub("Fenders", Fenders);//done
	//Addsub("Transmission", Trans);//done
	Addint("Transmission", trans, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_MOD(veh, 13, trans, 1); }
	//Addsub("Suspension", Suspension);//done no need fo r it since int
	Addint("Suspension", sup, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_MOD(veh, 15, sup, 1); }
	Addbool("Turbo", Turbobo);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (spo != 0)
		{
			Addsub("Spoiler", Spoiler);//done
		}
	}
	else
	{

	}
	//Addsub("Wheels", wheels);// done

	Addint("Window Tint", Tint_, 0, 6); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_WINDOW_TINT(VehID, Tint_); }


}

void Spawner::Bennyss()
	{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int rooff = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 10);
	int hoood = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 7);
	int grille = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 6);
	int side = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 3);
	int exhaust = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 4);
	int roll = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 5);
	int Aerialss = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 43);
	int vTank = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 38);
	int vTrunk = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 37);
	int vHydrulics = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 45);
	int fenderr = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 9);
	int spo = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 0);
	int vehicleModCount1 = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 1);
	int vehicleModCount2 = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 2);
	Addtitle("");
	VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
	Addsubtitle("Bennys");
	//Addsub("Armour", Armour);
	Addint("Armour", armoor, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 16, armoor, 0); }
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Aerialss != 0)
		{
			Addsub("Aerials", Aerials);//do
		}
	}
	else
	{

	}
	Addint("Brakes", brakes, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 12, brakes, 0); }
	//	Addsub("Brakes", Brakes);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vehicleModCount2 != 0)
		{
			Addsub("Front Bumper", fbumper);
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vehicleModCount1 != 0)
		{
			Addsub("Rear Bumper", rbumper);
		}
	}
	else
	{

	}
	Addsub("Engine", ee);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (rooff != 0)
		{
			Addsub("Roof", Roof);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (hoood != 0)
		{
			Addsub("Hood", Hood);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (grille != 0)
		{
			Addsub("Girlle", Grill);//done
		}
	}
	else
	{

	}
	Addsub("Light", Light);//done
//	Addint("Horns", horns, 0, 49); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 14, horns, 0); }
	Addsub("Respray", rResprayss);// 
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (side != 0)
		{
			Addsub("Skirts", Skirts);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (exhaust != 0)
		{
			Addsub("Exhaust", Exhaust);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (roll != 0)
		{
			Addsub("Rollcage", Rollcage);//done				
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (fenderr != 0)
		{
			Addsub("Fenders", Fenders);//done
		}
	}
	else
	{

	}
	Addsub("Interior", inside);
	Addsub("Plates", plateeee);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vHydrulics != 0)
		{
			Addsub("Hydraulics", Hydrulics);
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vTrunk != 0)
		{
			Addsub("Trunk", Trunk);
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vTank != 0)
		{

			Addsub("Tank", Tank);
		}
	}
	else
	{

	}
	//Addsub("Transmission", Trans);
	//Addsub("Suspension", Suspension);
	Addint("Suspension", sup, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_MOD(veh, 15, sup, 1); }
	Addint("Transmission", trans, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_MOD(veh, 13, trans, 1); }
	Addbool("Turbo", Turbobo);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (spo != 0)
		{
			Addsub("Spoiler", Spoiler);//done
		}
	}
	else
	{

	}
	Addsub("Wheels", wheels);
	Addint("Window Tint", Tint_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_WINDOW_TINT(VehID, Tint_); }

}
	
void Spawner::wars()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int rooff = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 10);
	int hoood = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 7);
	int grille = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 6);
	int side = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 3);
	int exhaust = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 4);
	int roll = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 5);
	int Aerialss = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 43);
	int vTank = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 38);
	int vTrunk = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 37);
	int vHydrulics = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 45);
	int fenderr = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 9);
	int spo = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 0);
	int vehicleModCount1 = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 1);
	int vehicleModCount2 = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 2);
	Addtitle("");
	Addtitle("");
	Addint("Armour", armoor, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 16, armoor, 0); }
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Aerialss != 0)
		{
			Addsub("body spikes", Aerials);//do
		}
	}
	else
	{

	}
	Addint("Brakes", brakes, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 12, brakes, 0); }
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vehicleModCount2 != 0)
		{
			//Addsub("Front Bumper", fbumper);
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vehicleModCount1 != 0)
		{
			Addsub("Rear Bumper", rbumper);
		}
	}
	else
	{

	}
	Addint("Engine", engine, 0, 4); { int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(veh, engine); VEHICLE::SET_VEHICLE_MOD(veh, 12, engine, 0); }//done
	//Addsub("Engine", ee);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (rooff != 0)
		{
			Addsub("Roof", Roof);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (hoood != 0)
		{
			Addsub("Hood", Hood);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (grille != 0)
		{
			Addsub("Girlle", Grill);//done
		}
	}
	else
	{

	}
	Addsub("Light", Light);//done
	//Addint("Horns", horns, 0, 49); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns); VEHICLE::SET_VEHICLE_MOD(VehID, 14, horns, 0); }
	Addsub("Respray", rrResprayss);// 
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (side != 0)
		{
			Addsub("Skirts", Skirts);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (exhaust != 0)
		{
			Addsub("Exhaust", Exhaust);//done
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (roll != 0)
		{
			Addsub("Body Armor", Rollcage);//done				
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (fenderr != 0)
		{
			Addsub("Guns", Fenders);//done
		}
	}
	else
	{

	}
	//Addsub("Interior", inside);
	Addsub("Plates", plateeee);
	Addsub("Jump", Struts);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vHydrulics != 0)
		{
			Addsub("Guns", Hydrulics);
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vTrunk != 0)
		{
			Addsub("Trunk", Trunk);
		}
	}
	else
	{

	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (vTank != 0)
		{

			Addsub("Tank", Tank);
		}
	}
	else
	{

	}
	//Addsub("Transmission", Trans);
	//Addsub("Suspension", Suspension);
	Addint("Suspension", sup, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_MOD(veh, 15, sup, 1); }
	Addint("Transmission", trans, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_MOD(veh, 13, trans, 1); }
	Addbool("Turbo", Turbobo);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (spo != 0)
		{
			Addsub("Spoiler", Spoiler);//done
		}
	}
	else
	{

	}
	Addsub("Wheels", wheels);
	Addint("Window Tint", Tint_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_); VEHICLE::SET_VEHICLE_WINDOW_TINT(VehID, Tint_); }

}

#define Vehicle                 vehicle


void Spawner::brightcolors()
{			
	Addtitle("");

	Addsubtitle("Bright Colours");
	if (Addoption("Electric Lime")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 204, 255, 00);
		}
	}
	if (Addoption("Fluoresent Yellow")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 204, 255, 0);
		}
	}
	if (Addoption("Fuchsia")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 205);
		}
	}
	if (Addoption("Turquoise")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 255, 0);
		}
	}
	if (Addoption("Silver")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 192, 192, 192);
		}
	}
	if (Addoption("Hot Pink")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 255);
		}
	}
	if (Addoption("Lime Green")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 134, 236, 0);
		}
	}
	if (Addoption("Purple")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 137, 0, 255);
		}
	}
	if (Addoption("Light Blue")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 191, 255);
		}
	}
	if (Addoption("Midnight Blue")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 25, 25, 112);
		}
	}
	if (Addoption("Aventador Orange")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 69, 0);
		}
	}
	if (Addoption("Cream")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 253, 208);
		}
	}
	if (Addoption("White")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 255, 255);
		}
	}
	if (Addoption("Green")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 43, 183, 62);
		}
	}
	if (Addoption("Gold")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 122, 86, 3);
		}
	}
	if (Addoption("Grey")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 128, 128, 128);
		}
	}
	if (Addoption("~o~R~y~a~r~n~p~d~b~o~g~m")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);

		}
	}
}
	
	
void Spawner::sbright1()
{
	Addtitle("");
	Addtitle("");

	Addsubtitle("Bright Colours");
	if (Addoption("Electric Lime")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 204, 255, 00);
		}
	}
	if (Addoption("Fluoresent Yellow")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 204, 255, 0);
		}
	}
	if (Addoption("Fuchsia")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 0, 205);
		}
	}
	if (Addoption("Turquoise")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 255, 0);
		}
	}
	if (Addoption("Silver")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 192, 192, 192);
		}
	}
	if (Addoption("Hot Pink")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 0, 255);
		}
	}
	if (Addoption("Lime Green")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 134, 236, 0);
		}
	}
	if (Addoption("Purple")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 137, 0, 255);
		}
	}
	if (Addoption("Light Blue")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 191, 255);
		}
	}
	if (Addoption("Midnight Blue")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 25, 25, 112);
		}
	}
	if (Addoption("Aventador Orange")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 69, 0);
		}
	}
	if (Addoption("Cream")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 253, 208);
		}
	}
	if (Addoption("White")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 255, 255);
		}
	}
	if (Addoption("Green")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 43, 183, 62);
		}
	}
	if (Addoption("Gold")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 122, 86, 3);
		}
	}
	if (Addoption("Grey")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 128, 128, 128);
		}
	}
	if (Addoption("~o~R~y~a~r~n~p~d~b~o~g~m")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
		}
	}
}
		
		
void Spawner::Resprayss1()
{
	Addtitle("");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int Livreyg = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 48);
	Addsubtitle("Respray");
	Addsub("RGB Colours", ResprayssED);
	Addsub("Primary Colours", Primaryyy);
	Addsub("Secondary Colours", Secondaryyy);
	Addsub("Primary Bright Colours", pbright);
	Addsub("Secondary Bright Colours", sbright);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Livreyg != 0)
		{
			Addsub("Livery", Livrey);
		}
	}
	else
	{

	}

}

void Spawner::ResprayssED1()
{
	Addtitle("");
	Addsubtitle("Respray");


	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Addint("RED Primary", Red, 0, 255);
	Addint("GREEN Primary", Green, 0, 255);
	Addint("BLUE Primary", Blue, 0, 255);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Red, Green, Blue);
	}
	if (Menu::Option("~f~[ ~w~Secondary ~f~]")) {}
	Addint("RED Secondary", SR, 0, 255);
	Addint("GREEN Secondary", SG, 0, 255);
	Addint("BLUE Secondary", SB, 0, 255);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SR, SG, SB);
	}
}
		
void Spawner::Smoke1()
{
	Addtitle("");
	Addsubtitle("Tire Smoke");
	Addsub("RGB Tyre smoke picker", tTRGB);
	if (Addoption("White")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 254, 254, 254);
		notifyMap("Tire Smoke: White");
	}

	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 1, 1, 1);
		notifyMap("Tire Smoke: Black");
	}

	if (Addoption("Blue")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 0, 255);
		notifyMap("Tire Smoke: ~b~Blue");
	}

	if (Addoption("Yellow")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 255, 0);
		notifyMap("Tire Smoke: ~y~Yellow");
	}

	if (Addoption("Purple")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 150, 0, 255);
		notifyMap("Tire Smoke: ~p~Purple");
	}

	if (Addoption("Orange")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 175, 0);
		notifyMap("Tire Smoke: ~o~Orange");
	}

	if (Addoption("Green")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 255, 0);
		notifyMap("Tire Smoke: ~g~Green");
	}

	if (Addoption("Red")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 0, 0);
		notifyMap("Tire Smoke: ~r~Red");
	}

	if (Addoption("Pink")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 0, 255);
		notifyMap("Tire Smoke: ~p~Pink");
	}

	if (Addoption("~r~P~w~A~b~T~r~R~w~I~b~O~r~T")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 0, 0);
		notifyMap("Tire Smoke: ~r~P~w~A~b~T~r~R~w~I~b~O~r~T");
	}
}
		
		
void Spawner::TRGB1()
{
	Addtitle("");

	Addsubtitle("RGB Smoke Picker");
	Addint("RED", TR, 0, 255);
	Addint("GREEN", TG, 0, 255);
	Addint("BLUE", TB, 0, 255);
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, TR, TG, TB);
	}
}
		
void Spawner::Primaryyy1()
{
	Addtitle("");

	Addsubtitle("Primary Color");
	Addsub("Color picker", picker);
	Addsub("Chrome", Chrome);
	Addsub("Classic/Metallic", ClassicMetallic);
	Addsub("Matte", Matte);
	Addsub("Metals", Metals);
	Addsub("pearlescent", pearlescents);
}
	
void Spawner::Chrome1()
{
	Addtitle("");


	Addsubtitle("Chrome");
	if (Addoption("Chrome"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_COLOURS(veh, 120, secondaryColor);
	}
}

void Spawner::ClassicMetallic1()
{
	Addtitle("");


	Addsubtitle("Classic/Metallic");
	//Classic/Metallic
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 0, secondaryColor);
	}
	if (Addoption("Carbon Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 147, secondaryColor);
	}
	if (Addoption("Graphite"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 1, secondaryColor);
	}
	if (Addoption("Anhracite Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 1, secondaryColor);
	}
	if (Addoption("Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 2, secondaryColor);
	}
	if (Addoption("Dark Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 3, secondaryColor);
	}
	if (Addoption("Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 4, secondaryColor);
	}
	if (Addoption("Bluish Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 5, secondaryColor);
	}
	if (Addoption("Rolled Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 6, secondaryColor);
	}
	if (Addoption("Shadow Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 7, secondaryColor);
	}
	if (Addoption("Stone  Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 8, secondaryColor);
	}
	if (Addoption("Midnight   Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 9, secondaryColor);
	}
	if (Addoption("Cast Iron Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 10, secondaryColor);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 27, secondaryColor);
	}
	if (Addoption("Torino  Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 28, secondaryColor);
	}
	if (Addoption("Formula   Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 29, secondaryColor);
	}
	if (Addoption("Lava Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 150, secondaryColor);
	}
	if (Addoption("Blaze Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 30, secondaryColor);
	}
	if (Addoption("Grace Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, 31, secondaryColor);
	}
	if (Addoption("Garnet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, 32, secondaryColor);
	}
	if (Addoption("Sunset Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 33, secondaryColor);
	}
	if (Addoption("Cabernet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 34, secondaryColor);
	}
	if (Addoption("Wine Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 143, secondaryColor);
	}
	if (Addoption("Candy Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 35, secondaryColor);
	}
	if (Addoption("Hot Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 135, secondaryColor);
	}
	if (Addoption("Pfsiter Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 137, secondaryColor);
	}
	if (Addoption("Salmon Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 136, secondaryColor);
	}
	if (Addoption("Sunrise Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 36, secondaryColor);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 38, secondaryColor);
	}
	if (Addoption("Bright Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 138, secondaryColor);
	}
	if (Addoption("Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 99, secondaryColor);
	}
	if (Addoption("Bronze"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 90, secondaryColor);
	}
	if (Addoption("Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 88, secondaryColor);
	}
	if (Addoption("Race Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 91, secondaryColor);
	}
	if (Addoption("Dew Yelow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, 92, secondaryColor);
	}
	if (Addoption("Drak Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 49, secondaryColor);
	}
	if (Addoption("Racing Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 50, secondaryColor);
	}
	if (Addoption("Sea Gren"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 51, secondaryColor);
	}
	if (Addoption("Olive Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 52, secondaryColor);
	}
	if (Addoption("Bright Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 53, secondaryColor);
	}
	if (Addoption("Gasoline Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 54, secondaryColor);
	}
	if (Addoption("Lime Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 92, secondaryColor);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 141, secondaryColor);
	}
	if (Addoption("Galaxy Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 61, secondaryColor);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 62, secondaryColor);
	}
	if (Addoption("Saxgon Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 63, secondaryColor);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 64, secondaryColor);
	}
	if (Addoption("Mariner Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 65, secondaryColor);
	}
	if (Addoption("Harbor Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 66, secondaryColor);
	}
	if (Addoption("Diamond Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 67, secondaryColor);
	}
	if (Addoption("Surf Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 68, secondaryColor);
	}
	if (Addoption("Nautical Blue"))
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 69, secondaryColor);
	}
	if (Addoption("Ultra Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 70, secondaryColor);
	}
	if (Addoption("Light Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 74, secondaryColor);
	}
	if (Addoption("Chocolate Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 96, secondaryColor);
	}
	if (Addoption("Bison Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 101, secondaryColor);
	}
	if (Addoption("Creeen Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 95, secondaryColor);
	}
	if (Addoption("Feltzer Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 94, secondaryColor);
	}
	if (Addoption("Maple Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 97, primaryColor);
	}
	if (Addoption("Beechwood Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 103, secondaryColor);
	}
	if (Addoption("Sienna Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 104, secondaryColor);
	}
	if (Addoption("Saddle Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 98, secondaryColor);
	}
	if (Addoption("Moss Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 100, secondaryColor);
	}
	if (Addoption("WoodBeech Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 102, secondaryColor);
	}
	if (Addoption("Straw Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 99, secondaryColor);
	}
	if (Addoption("Bleached  Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 106, secondaryColor);
	}
	if (Addoption("Schafter Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 71, secondaryColor);
	}
	if (Addoption("Spinnaker  Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 72, secondaryColor);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 142, secondaryColor);
	}
	if (Addoption("Bright Purple"))
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 145, secondaryColor);
	}
	if (Addoption("Cream"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 107, secondaryColor);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 111, secondaryColor);
	}
	if (Addoption("Frost White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 112, secondaryColor);
	}

}

void Spawner::Matte1()
{
	Addtitle("");

	Addsubtitle("Matte");
	//Mate
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, 12, secondaryColor);
	}
	if (Addoption("Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 13, secondaryColor);
	}
	if (Addoption("Light Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 14, secondaryColor);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 131, secondaryColor);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 83, secondaryColor);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 82, secondaryColor);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 84, secondaryColor);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 149, secondaryColor);
	}
	if (Addoption("Schafter"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 148, secondaryColor);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 39, secondaryColor);
	}
	if (Addoption("Dark Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 40, secondaryColor);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 41, secondaryColor);
	}
	if (Addoption("Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 42, secondaryColor);
	}
	if (Addoption("Forest Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 151, secondaryColor);
	}
	if (Addoption("Foliage Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 155, secondaryColor);
	}
	if (Addoption("Olive Darb"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 152, secondaryColor);
	}
	if (Addoption("Dark Earth"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 153, secondaryColor);
	}
	if (Addoption("Desert Tan"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 154, secondaryColor);
	}
}

void Spawner::Metals1()
{
	Addtitle("");

	Addsubtitle("Metals");
	//Metals
	if (Addoption("Brushed Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 117, secondaryColor);
	}
	if (Addoption("Brushed Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 118, secondaryColor);
	}
	if (Addoption("Brushed Aluminum"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 119, secondaryColor);
	}
	if (Addoption("Pure Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 158, secondaryColor);
	}
	if (Addoption("Brushed Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, 159, secondaryColor);
	}
}
		
void Spawner::Chromep()
{
	Addtitle("");

	Addsubtitle("Chrome");
	if (Addoption("Chrome"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

		//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

		VEHICLE::SET_VEHICLE_COLOURS(veh, 120, secondaryColor);
	}
}

//case ClassicMetallicp:
//{			Addtitle("");

//Addsubtitle("Classic/Metallic");
////Classic/Metallic
//if (Addoption("Black"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 0, secondaryColor);
//}
//if (Addoption("Carbon Black"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 147, secondaryColor);
//}
//if (Addoption("Graphite"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 1, secondaryColor);
//}
//if (Addoption("Anhracite Black"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 1, secondaryColor);
//}
//if (Addoption("Black Steel"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 2, secondaryColor);
//}
//if (Addoption("Dark Steel"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 3, secondaryColor);
//}
//if (Addoption("Silver"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 4, secondaryColor);
//}
//if (Addoption("Bluish Silver"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 5, secondaryColor);
//}
//if (Addoption("Rolled Steel"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 6, secondaryColor);
//}
//if (Addoption("Shadow Silver"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 7, secondaryColor);
//}
//if (Addoption("Stone  Silver"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 8, secondaryColor);
//}
//if (Addoption("Midnight   Silver"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 9, secondaryColor);
//}
//if (Addoption("Cast Iron Silver"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 10, secondaryColor);
//}
//if (Addoption("Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 27, secondaryColor);
//}
//if (Addoption("Torino  Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 28, secondaryColor);
//}
//if (Addoption("Formula   Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 29, secondaryColor);
//}
//if (Addoption("Lava Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 150, secondaryColor);
//}
//if (Addoption("Blaze Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 30, secondaryColor);
//}
//if (Addoption("Grace Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
//	VEHICLE::SET_VEHICLE_COLOURS(veh, 31, secondaryColor);
//}
//if (Addoption("Garnet Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
//	VEHICLE::SET_VEHICLE_COLOURS(veh, 32, secondaryColor);
//}
//if (Addoption("Sunset Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 33, secondaryColor);
//}
//if (Addoption("Cabernet Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 34, secondaryColor);
//}
//if (Addoption("Wine Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 143, secondaryColor);
//}
//if (Addoption("Candy Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 35, secondaryColor);
//}
//if (Addoption("Hot Pink"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 135, secondaryColor);
//}
//if (Addoption("Pfsiter Pink"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 137, secondaryColor);
//}
//if (Addoption("Salmon Pink"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 136, secondaryColor);
//}
//if (Addoption("Sunrise Orange"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 36, secondaryColor);
//}
//if (Addoption("Orange"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 38, secondaryColor);
//}
//if (Addoption("Bright Orange"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 138, secondaryColor);
//}
//if (Addoption("Gold"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 99, secondaryColor);
//}
//if (Addoption("Bronze"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 90, secondaryColor);
//}
//if (Addoption("Yellow"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 88, secondaryColor);
//}
//if (Addoption("Race Yellow"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 91, secondaryColor);
//}
//if (Addoption("Dew Yelow"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
//	VEHICLE::SET_VEHICLE_COLOURS(veh, 92, secondaryColor);
//}
//if (Addoption("Drak Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 49, secondaryColor);
//}
//if (Addoption("Racing Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 50, secondaryColor);
//}
//if (Addoption("Sea Gren"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 51, secondaryColor);
//}
//if (Addoption("Olive Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 52, secondaryColor);
//}
//if (Addoption("Bright Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 53, secondaryColor);
//}
//if (Addoption("Gasoline Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 54, secondaryColor);
//}
//if (Addoption("Lime Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 92, secondaryColor);
//}
//if (Addoption("Midnight Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 141, secondaryColor);
//}
//if (Addoption("Galaxy Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 61, secondaryColor);
//}
//if (Addoption("Dark Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 62, secondaryColor);
//}
//if (Addoption("Saxgon Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 63, secondaryColor);
//}
//if (Addoption("Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 64, secondaryColor);
//}
//if (Addoption("Mariner Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 65, secondaryColor);
//}
//if (Addoption("Harbor Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 66, secondaryColor);
//}
//if (Addoption("Diamond Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 67, secondaryColor);
//}
//if (Addoption("Surf Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 68, secondaryColor);
//}
//if (Addoption("Nautical Blue"))
//{

//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 69, secondaryColor);
//}
//if (Addoption("Ultra Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 70, secondaryColor);
//}
//if (Addoption("Light Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 74, secondaryColor);
//}
//if (Addoption("Chocolate Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 96, secondaryColor);
//}
//if (Addoption("Bison Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 101, secondaryColor);
//}
//if (Addoption("Creeen Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 95, secondaryColor);
//}
//if (Addoption("Feltzer Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 94, secondaryColor);
//}
//if (Addoption("Maple Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 97, primaryColor);
//}
//if (Addoption("Beechwood Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 103, secondaryColor);
//}
//if (Addoption("Sienna Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 104, secondaryColor);
//}
//if (Addoption("Saddle Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 98, secondaryColor);
//}
//if (Addoption("Moss Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 100, secondaryColor);
//}
//if (Addoption("WoodBeech Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 102, secondaryColor);
//}
//if (Addoption("Straw Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 99, secondaryColor);
//}
//if (Addoption("Bleached  Brown"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 106, secondaryColor);
//}
//if (Addoption("Schafter Purple"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 71, secondaryColor);
//}
//if (Addoption("Spinnaker  Purple"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 72, secondaryColor);
//}
//if (Addoption("Midnight Purple"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 142, secondaryColor);
//}
//if (Addoption("Bright Purple"))
//{

//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 145, secondaryColor);
//}
//if (Addoption("Cream"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 107, secondaryColor);
//}
//if (Addoption("Ice White"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 111, secondaryColor);
//}
//if (Addoption("Frost White"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 112, secondaryColor);
//}

//}
//break;
//case Mattep:
//{			Addtitle("");

//Addsubtitle("Matte");
////Mate
//if (Addoption("Black"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 12, secondaryColor);
//}
//if (Addoption("Grey"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 13, secondaryColor);
//}
//if (Addoption("Light Grey"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 14, secondaryColor);
//}
//if (Addoption("Ice White"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 131, secondaryColor);
//}
//if (Addoption("Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 83, secondaryColor);
//}
//if (Addoption("Dark Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 82, secondaryColor);
//}
//if (Addoption("Midnight Blue"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 84, secondaryColor);
//}
//if (Addoption("Midnight Purple"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 149, secondaryColor);
//}
//if (Addoption("Schafter"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 148, secondaryColor);
//}
//if (Addoption("Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 39, secondaryColor);
//}
//if (Addoption("Dark Red"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 40, secondaryColor);
//}
//if (Addoption("Orange"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 41, secondaryColor);
//}
//if (Addoption("Yellow"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 42, secondaryColor);
//}
//if (Addoption("Forest Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 151, secondaryColor);
//}
//if (Addoption("Foliage Green"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 155, secondaryColor);
//}
//if (Addoption("Olive Darb"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 152, secondaryColor);
//}
//if (Addoption("Dark Earth"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 153, secondaryColor);
//}
//if (Addoption("Desert Tan"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 154, secondaryColor);
//}
//}
//break;
//case Metalsp:
//{			Addtitle("");

//Addsubtitle("Metals");
////Metals
//if (Addoption("Brushed Steel"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 117, secondaryColor);
//}
//if (Addoption("Brushed Black Steel"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 118, secondaryColor);
//}
//if (Addoption("Brushed Aluminum"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 119, secondaryColor);
//}
//if (Addoption("Pure Gold"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 158, secondaryColor);
//}
//if (Addoption("Brushed Gold"))
//{
//	int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
//	//VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR
//	VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

//	VEHICLE::SET_VEHICLE_COLOURS(veh, 159, secondaryColor);
//}

//}
//break;

		
void Spawner::Secondaryyy1()
{
	Addtitle("");
	Addsubtitle("Secondary Color");
	Addsub("Color picker", picker);
	Addsub("Chrome", Chromes);
	Addsub("Classic/Metallic", ClassicMetallics);
	Addsub("Matte", Mattes);
	Addsub("Metals", Metalss);
	Addsub("pearlescent", pearlescents);
}
		
		
void Spawner::pearlescents1()
{
	Addtitle("");
	Addsubtitle("Pearlescents");
	if (Addoption("Chrome"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 120, wheelColor);
	}

	if (Menu::Option("~f~[ ~w~Classic/Metallic ~f~]")) {}
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 0, wheelColor);
	}
	if (Addoption("Carbon Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 147, wheelColor);
	}
	if (Addoption("Graphite"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 1, wheelColor);
	}
	if (Addoption("Anhracite Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 1, wheelColor);
	}
	if (Addoption("Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 2, wheelColor);
	}
	if (Addoption("Dark Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 3, wheelColor);
	}
	if (Addoption("Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 4, wheelColor);
	}
	if (Addoption("Bluish Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 5, wheelColor);
	}
	if (Addoption("Rolled Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 6, wheelColor);
	}
	if (Addoption("Shadow Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 7, wheelColor);
	}
	if (Addoption("Stone Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 8, wheelColor);
	}
	if (Addoption("Midnight Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 9, wheelColor);
	}
	if (Addoption("Cast Iron Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 10, wheelColor);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 27, wheelColor);
	}
	if (Addoption("Torino Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 28, wheelColor);
	}
	if (Addoption("Formula Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 29, wheelColor);
	}
	if (Addoption("Lava Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 150, wheelColor);
	}
	if (Addoption("Blaze Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 30, wheelColor);
	}
	if (Addoption("Grace Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 31, wheelColor);
	}
	if (Addoption("Garnet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 32, wheelColor);
	}
	if (Addoption("Sunset Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 33, wheelColor);
	}
	if (Addoption("Cabernet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 34, wheelColor);
	}
	if (Addoption("Wine Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 143, wheelColor);
	}
	if (Addoption("Candy Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 35, wheelColor);
	}
	if (Addoption("Hot Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 135, wheelColor);
	}
	if (Addoption("Pfsiter Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 137, wheelColor);
	}
	if (Addoption("Salmon Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 136, wheelColor);
	}
	if (Addoption("Sunrise Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 36, wheelColor);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 38, wheelColor);
	}
	if (Addoption("Bright Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 138, wheelColor);
	}
	if (Addoption("Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 99, wheelColor);
	}
	if (Addoption("Bronze"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 90, wheelColor);
	}
	if (Addoption("Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 88, wheelColor);
	}
	if (Addoption("Race Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 91, wheelColor);
	}
	if (Addoption("Dew Yelow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 92, wheelColor);
	}
	if (Addoption("Drak Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 49, wheelColor);
	}
	if (Addoption("Racing Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 50, wheelColor);
	}
	if (Addoption("Sea Gren"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 51, wheelColor);
	}
	if (Addoption("Olive Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 52, wheelColor);
	}
	if (Addoption("Bright Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 53, wheelColor);
	}
	if (Addoption("Gasoline Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 54, wheelColor);
	}
	if (Addoption("Lime Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 92, wheelColor);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 141, wheelColor);
	}
	if (Addoption("Galaxy Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 61, wheelColor);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 62, wheelColor);
	}
	if (Addoption("Saxgon Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 63, wheelColor);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 64, wheelColor);
	}
	if (Addoption("Mariner Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 65, wheelColor);
	}
	if (Addoption("Harbor Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 66, wheelColor);
	}
	if (Addoption("Diamond Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 67, wheelColor);
	}
	if (Addoption("Surf Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 68, wheelColor);
	}
	if (Addoption("Nautical Blue"))
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 69, wheelColor);
	}
	if (Addoption("Ultra Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 70, wheelColor);
	}
	if (Addoption("Light Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 74, wheelColor);
	}
	if (Addoption("Chocolate Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 96, wheelColor);
	}
	if (Addoption("Bison Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 101, wheelColor);
	}
	if (Addoption("Creeen Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 95, wheelColor);
	}
	if (Addoption("Feltzer Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 94, wheelColor);
	}
	if (Addoption("Maple Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 97, primaryColor);
	}
	if (Addoption("Beechwood Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 103, wheelColor);
	}
	if (Addoption("Sienna Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 104, wheelColor);
	}
	if (Addoption("Saddle Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 98, wheelColor);
	}
	if (Addoption("Moss Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 100, wheelColor);
	}
	if (Addoption("WoodBeech Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 102, wheelColor);
	}
	if (Addoption("Straw Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 99, wheelColor);
	}
	if (Addoption("Bleached Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 106, wheelColor);
	}
	if (Addoption("Schafter Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 71, wheelColor);
	}
	if (Addoption("Spinnaker Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 72, wheelColor);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 142, wheelColor);
	}
	if (Addoption("Bright Purple"))
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 145, wheelColor);
	}
	if (Addoption("Cream"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 107, wheelColor);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 111, wheelColor);
	}
	if (Addoption("Frost White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);;
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 112, wheelColor);
	}

	if (Menu::Option("~f~[ ~w~Matte ~f~]")) {};
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 12, wheelColor);
	}
	if (Addoption("Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 13, wheelColor);
	}
	if (Addoption("Light Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 14, wheelColor);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 131, wheelColor);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 83, wheelColor);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 82, wheelColor);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 84, wheelColor);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 149, wheelColor);
	}
	if (Addoption("Schafter"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 148, wheelColor);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 39, wheelColor);
	}
	if (Addoption("Dark Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 40, wheelColor);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 41, wheelColor);
	}
	if (Addoption("Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 42, wheelColor);
	}
	if (Addoption("Forest Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 151, wheelColor);
	}
	if (Addoption("Foliage Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 155, wheelColor);
	}
	if (Addoption("Olive Darb"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 152, wheelColor);
	}
	if (Addoption("Dark Earth"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 153, wheelColor);
	}
	if (Addoption("Desert Tan"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 154, wheelColor);
	}

	if (Menu::Option("~f~[ ~w~Metals ~f~]")) {}
	if (Addoption("Brushed Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 117, wheelColor);
	}
	if (Addoption("Brushed Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 118, wheelColor);
	}
	if (Addoption("Brushed Aluminum"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 119, wheelColor);
	}
	if (Addoption("Pure Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 158, wheelColor);
	}
	if (Addoption("Brushed Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 159, wheelColor);
	}
}


//#pragma region Picker 1 - xx  hmmmmmmmm
void Spawner::picker1()
{
	Addtitle("");

	Addsubtitle("Colour picker");
	Addint("Secondary Color", Sec_, 0, 150); { int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0); VEHICLE::SET_VEHICLE_COLOURS(veh, Prim_, Sec_); }
	Addint("Primary Color", Prim_, 0, 159); { int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0); VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0); VEHICLE::SET_VEHICLE_COLOURS(veh, Prim_, Sec_); }
}



void Spawner::Chromes1()
{
	Addtitle("");
	Addsubtitle("Chrome");
	if (Addoption("Chrome"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 120);
	}
}
	

#pragma endregion
#pragma region Respray Classic/Metallic
void Spawner::ClassicMetallics1()
{
	Addtitle("");
	Addsubtitle("Classic/Metallic");
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 0);
	}
	if (Addoption("Carbon Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 147);
	}
	if (Addoption("Graphite"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 1);
	}
	if (Addoption("Anhracite Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 11);
	}
	if (Addoption("Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 2);
	}
	if (Addoption("Dark Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 3);
	}
	if (Addoption("Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 4);
	}
	if (Addoption("Bluish Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 5);
	}
	if (Addoption("Rolled Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 6);
	}
	if (Addoption("Shadow Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 7);
	}
	if (Addoption("Stone  Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 8);
	}
	if (Addoption("Midnight Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 9);
	}
	if (Addoption("Cast Iron Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 10);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 27);
	}
	if (Addoption("Torino  Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 28);
	}
	if (Addoption("Formula Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 29);
	}
	if (Addoption("Lava Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 150);
	}
	if (Addoption("Blaze Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 30);
	}
	if (Addoption("Grace Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 31);
	}
	if (Addoption("Garnet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 32);
	}
	if (Addoption("Sunset Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 33);
	}
	if (Addoption("Cabernet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 34);
	}
	if (Addoption("Wine Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 143);
	}
	if (Addoption("Candy Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 35);
	}
	if (Addoption("Hot Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 135);
	}
	if (Addoption("Pfsiter Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 137);
	}
	if (Addoption("Salmon Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 136);
	}
	if (Addoption("Sunrise Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 36);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 38);
	}
	if (Addoption("Bright Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 138);
	}
	if (Addoption("Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 99);
	}
	if (Addoption("Bronze"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 90);
	}
	if (Addoption("Yellow"))
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 88);
	}
	if (Addoption("Race Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 91);
	}
	if (Addoption("Dew Yelow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 92);
	}
	if (Addoption("Drak Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 49);
	}
	if (Addoption("Racing Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 50);
	}
	if (Addoption("Sea Gren"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 51);
	}
	if (Addoption("Olive Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 52);
	}
	if (Addoption("Bright Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 53);
	}
	if (Addoption("Gasoline Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 54);
	}
	if (Addoption("Lime Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 92);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 141);
	}
	if (Addoption("Galaxy Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 61);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 62);
	}
	if (Addoption("Saxgon Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 63);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 64);
	}
	if (Addoption("Mariner Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 65);
	}
	if (Addoption("Harbor Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 66);
	}
	if (Addoption("Diamond Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 67);
	}
	if (Addoption("Surf Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 68);
	}
	if (Addoption("Nautical Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 69);
	}
	if (Addoption("Ultra Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 70);
	}
	if (Addoption("Light Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 74);
	}
	if (Addoption("Chocolate Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 96);
	}
	if (Addoption("Bison Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 101);
	}
	if (Addoption("Creeen Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 95);
	}
	if (Addoption("Feltzer Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 94);
	}
	if (Addoption("Maple Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 97);
	}
	if (Addoption("Beechwood Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 103);
	}
	if (Addoption("Sienna Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 104);
	}
	if (Addoption("Saddle Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 98);
	}
	if (Addoption("Moss Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 100);
	}
	if (Addoption("WoodBeech Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 102);
	}
	if (Addoption("Straw Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 99);
	}
	if (Addoption("Bleached  Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 106);
	}
	if (Addoption("Schafter Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 71);
	}
	if (Addoption("Spinnaker  Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 72);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 142);
	}
	if (Addoption("Bright Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 145);
	}
	if (Addoption("Cream"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 107);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 111);
	}
	if (Addoption("Frost White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 112);
	}
}
		
#pragma endregion

void Spawner::SecondaryStuff()
{
	Addtitle("");
	Addsubtitle("Secondary Color");
	Addsub("Color picker", picker);
	Addsub("Chrome", Chromes);
	Addsub("Classic/Metallic", ClassicMetallics);
	Addsub("Matte", Mattes);
	Addsub("Metals", Metalss);
	Addsub("pearlescent", pearlescents);
}

#pragma region Secondary Matte
		
void Spawner::Mattes1()
{
	Addtitle("");

	Addsubtitle("Matte");
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 12);
	}
	if (Addoption("Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 13);
	}
	if (Addoption("Light Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 14);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 131);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 83);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 82);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 84);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 149);
	}
	if (Addoption("Schafter"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 148);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 39);
	}
	if (Addoption("Dark Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 40);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 41);
	}
	if (Addoption("Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 42);
	}
	if (Addoption("Forest Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 151);
	}
	if (Addoption("Foliage Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 155);
	}
	if (Addoption("Olive Darb"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 152);
	}
	if (Addoption("Dark Earth"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 153);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
	}
	if (Addoption("Desert Tan"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);

		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 154);
	}
}
#pragma endregion

#pragma region Secondary Metals
void Spawner::Metalss1()
{
	Addtitle("");

	Addsubtitle("Metals");
	if (Addoption("Brushed Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 117);
	}
	if (Addoption("Brushed Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 117);
	}
	if (Addoption("Brushed Aluminum"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 119);
	}
	if (Addoption("Pure Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 158);
	}
	if (Addoption("Brushed Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_COLOURS(veh, &primaryColor, &secondaryColor);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primaryColor, 159);
	}
}
#pragma endregion

#pragma region wheels
void Spawner::Wheels()
{
	Addtitle("");
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	Addsubtitle("Wheels");
	Addsub("Rims", Rims);
	Addsub("Accessories", sSmoke);
	Hash hithere = ENTITY::GET_ENTITY_MODEL(veh);
	if (VEHICLE::IS_THIS_MODEL_A_BIKE(hithere) == true)
	{
		Addsub("Bike Wheels", BackWheels);
	}
	else
	{
	}
	Addsub("Wheel Colour", wheelcolour);
	Addbool("bulletproof tires", nopooptries);
}

void Spawner::Rims1()
{
	{			Addtitle("");

	Addsubtitle("Rims");
	Addsub("Highend", Highendrims);
	Addsub("Lowrider", Lowriderrims);
	Addsub("Muscle", Musclerims);
	Addsub("Offroad", Offroadrims);
	Addsub("Sport", Sportrims);
	Addsub("SUV", SUVrims);
	Addsub("Tuner", Tunerrims);
	Addsub("Benny's Bespoke", B);
	Addsub("Benny's Originals", O);
	}
}

void Spawner::SUV33()
{

	Addtitle("");

	Addsubtitle("SUV");

	if (Addoption("Benefactor")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("Cosmo")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 2, 0);
	}
	if (Addoption("Royal Six")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 4, 0);
	}
	if (Addoption("Fagorme")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 5, 0);
	}
	if (Addoption("Deluxe")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 6, 0);
	}
	if (Addoption("Iced Out")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 7, 0);
	}
	if (Addoption("Cognoscenti")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 8, 0);
	}
	if (Addoption("Supernova")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 10, 0);
	}
	if (Addoption("Obey RS")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 11, 0);
	}
	if (Addoption("LozSPrimaryyyd Baller")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 12, 0);
	}
	if (Addoption("Extravaganzo")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 13, 0);
	}
	if (Addoption("Split Six")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 14, 0);
	}
	if (Addoption("Empowered")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 15, 0);
	}
	if (Addoption("Sunrise")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 16, 0);
	}
	if (Addoption("Dash VIP")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 3);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 17, 0);
	}
}

void Spawner::Lowrider34()
{
	Addtitle("");

	Addsubtitle("Lowrider");
	if (Addoption("Flare")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 0, 0);
	}
	if (Addoption("Wired")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("Triple Golds")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 2, 0);
	}
	if (Addoption("Big Worm")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 3, 0);
	}
	if (Addoption("Seven Fives")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 4, 0);
	}
	if (Addoption("Split Six")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 5, 0);
	}
	if (Addoption("Fresh Mesh")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 6, 0);
	}
	if (Addoption("Lead Sled")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 7, 0);
	}
	if (Addoption("Turbine")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 8, 0);
	}
	if (Addoption("Super Fin")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 9, 0);
	}
	if (Addoption("Classic Rod")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 10, 0);
	}
	if (Addoption("Dollar")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 11, 0);
	}
	if (Addoption("Dukes")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 12, 0);
	}
	if (Addoption("Low Five")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 13, 0);
	}
	if (Addoption("Gooch")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 14, 0);

	}
}

void Spawner::Spawnstrim35()
{
	Addtitle("");
	Addsubtitle("Sports");

	if (Addoption("Inferno")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 0, 0);
	}
	if (Addoption("Deep Five")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("LozSPrimaryyyd Mk. V")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 2, 0);
	}
	if (Addoption("Diamond Cut")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 3, 0);
	}
	if (Addoption("Feroci RR")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 5, 0);
	}
	if (Addoption("FiftyNine")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 6, 0);
	}
	if (Addoption("Synthetic Z")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 8, 0);
	}
	if (Addoption("Organic Type 0")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 9, 0);
	}
	if (Addoption("GT One")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 11, 0);
	}
	if (Addoption("S Racer")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 15, 0);
	}
	if (Addoption("Venum")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 16, 0);
	}
	if (Addoption("Cosmo")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 17, 0);
	}
	if (Addoption("Dash VIP")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 18, 0);
	}
	if (Addoption("Ice Kid")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 0);
	}
	if (Addoption("Split Six")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 24, 0);
	}
}

void Spawner::OffRoad36()
{
	Addtitle("");
	Addsubtitle("Off road");

	if (Addoption("Raider")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 0, 0);
	}
	if (Addoption("Mudslinger")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("Nevis")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 2, 0);
	}
	if (Addoption("Cairngorm")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 3, 0);
	}
	if (Addoption("Amazon")) {// A to Z
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 4, 0);
	}
	if (Addoption("Challenger")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 5, 0);
	}
	if (Addoption("Dune Basher")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 6, 0);
	}
	if (Addoption("Five Star")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 7, 0);
	}
	if (Addoption("Rock Crawler")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 8, 0);
	}
	if (Addoption("Mil Spec Steelie")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 4);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 9, 0);
	}
}

void Spawner::Musclespin37()
{
	Addtitle("");
	Addsubtitle("Muscle");

	if (Addoption("Classic Five")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 0, 0);
	}
	if (Addoption("Dukes")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("Muscle Freak")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 2, 0);
	}
	if (Addoption("Kracka")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 3, 0);
	}
	if (Addoption("Azreal")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 4, 0);
	}
	if (Addoption("Mecha")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 5, 0);
	}
	if (Addoption("Black Top")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 6, 0);
	}
	if (Addoption("Drag SPL")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 7, 0);
	}
	if (Addoption("Revolver")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 8, 0);
	}
	if (Addoption("Classic Rod")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 9, 0);
	}
	if (Addoption("Spooner")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 11, 0);
	}
	if (Addoption("Five Star")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 12, 0);
	}
	if (Addoption("Old School")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 13, 0);
	}
	if (Addoption("El Jefe")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 14, 0);
	}
	if (Addoption("Mercenary")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 17, 0);
	}
}

void Spawner::plate()
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "FMMC_KEY_TIP", "", "", "", "", "", 8);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	char* plateText = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, plateText);
}

void Spawner::plade71()
{
	Addtitle("");
	Addsubtitle("Plate");
	if (Addoption("Change Plate")) {
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				int veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
				VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
				int currmod = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh);
				if (currmod < 5)
				{
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, currmod + 1);
					UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LS_CUSTOMS", "CHAR_LS_CUSTOMS", 1, 7, "Plate Upgrades", "Changed!", 1, "", false, true);
					UI::_DRAW_NOTIFICATION(5000, 1);
				}
				else
				{
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 0);
				}
			}
		}
	}
	if (Addoption("Change Plate Text")) { plate(); }
}

void Spawner::NeonOptions()
{
	Addsubtitle("Neon Options");
	Addtitle("");
	Addint("Red", NR, 0, 255);
	Addint("Green", NG, 0, 255);
	Addint("Blue", NB, 0, 255);
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, NR, NG, NB);
	}
}

void Spawner::NeonOptions2()
{
	Addtitle("");
	Addsubtitle("Neon Options");
	if (Option("Enable Xenon")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		ToggleXenon(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
	}
	if (Option("Enable Neons")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 0, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 2, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 3, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 4, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 5, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 6, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 7, 1);
	}
	if (Option("Red")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 0, 0);
	}
	if (Option("Green")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 255, 0);
	}
	if (Option("Blue")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 0, 255);
	}
	if (Option("Hot Pink")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 226, 35, 157);
	}
	if (Option("Yellow")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 244, 0);
	}
	if (Option("Orange")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 91, 0);
	}
	if (Option("Aqua")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 40, 255, 255);
	}
	if (Option("White")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 255, 255);
	}
	if (Option("Magenta")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 102, 0, 35);
	}
	if (Option("Purple")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 53, 0, 83);
	}
	if (Option("Dark Green")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 118, 0);
	}
	if (Option("Rose Red")) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 161, 0, 0);
	}
}

void Spawner::light()
{
	Addtitle("");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Addsubtitle("Light");
	Addsub("Neno Light/UnderGlow", Neonnn);
	Addbool("XenosLight", Lightt);
	if (Lightt == true)
	{
		if (Addoption("White"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 0);
		}
		if (Addoption("Blue"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 1);
		}
		if (Addoption("Electric Blue"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 2);
		}
		if (Addoption("Mint Green"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 3);
		}
		if (Addoption("Lime Green"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 4);
		}
		if (Addoption("Yellow"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 5);
		}
		if (Addoption("Golden Shower"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 6);
		}
		if (Addoption("Orange"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 7);
		}
		if (Addoption("Red"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 8);
		}
		if (Addoption("Pony Pink"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 9);
		}
		if (Addoption("Hot Pink"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 10);
		}
		if (Addoption("Purple"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 11);
		}
		if (Addoption("Black light"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 12);
		}
	}
	else
	{

	}
}

void Spawner::frontbumerstuff()
{
	Addtitle("");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Addsubtitle("Front Bumper");
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 1);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 1);

	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 1, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 1, i, 1);
				}
			}
		}
	}
}

void Spawner::reabomberstuff()
{
	Addtitle("");

	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Addsubtitle("Rear Bumper");
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 2);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 2);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 2, i));
		{
			if (mod == NULL)
			{
				mod = "Name not found";
			}
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 2, i, 1);
				}
			}
		}
	}
}

void Spawner::HoodStuff()
{
	Addtitle("");
	Addsubtitle("Hood");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 7);
	bool currmod = VEHICLE::GET_VEHICLE_MOD(veh, modType);// not being used yet
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 7, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 7, i, 1);
				}
			}
		}
	}
}

void Spawner::RoofStuff()
{
	Addtitle("");
	Addsubtitle("Roof");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 10);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 10);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 10, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 10, i, 1);
				}
			}
		}
	}
}

void Spawner::GrillStuff()
{
	Addtitle("");
	Addsubtitle("Grill");

	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 6);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 6);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 6, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 6, i, 1);
				}
			}
		}
	}
}

void Spawner::SkirtsStuff()
{
	Addtitle("");
	Addsubtitle("Side Skirts");

	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 3);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 3);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 3, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 3, i, 1);
				}
			}
		}
	}
}

void Spawner::ExhaustStuff()
{
	Addtitle("");
	Addsubtitle("Exhaust");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 4);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 4);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 4, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 4, i, 1);
				}
			}
		}
	}
}

void Spawner::Highend17()
{
	Addtitle("");
	Addsubtitle("Highend");
	if (Addoption("Shadow")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 0, 0);
	}
	if (Addoption("Hypher")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("Blade")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 2, 0);
	}
	if (Addoption("Diamond")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 3, 0);
	}
	if (Addoption("Supa Gee")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 4, 0);
	}
	if (Addoption("Chromatic Z")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 5, 0);
	}
	if (Addoption("Obey RS")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 7, 0);
	}
	if (Addoption("GT Chrome")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 8, 0);
	}
	if (Addoption("Cheetah RR")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 9, 0);
	}
	if (Addoption("Solar")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 10, 0);
	}
	if (Addoption("Split Ten")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 11, 0);
	}
	if (Addoption("Dash VIP")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 12, 0);
	}
	if (Addoption("LozSPrimaryyyd Ten")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 13, 0);
	}
	if (Addoption("Carbon Shadow")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 15, 0);
	}
	if (Addoption("Carbon S Racer")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 7);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 0);
	}
}



void Spawner::Tuner()
{
	Addtitle("");

	Addtitle("");
	Addsubtitle("Tuner");

	if (Addoption("Cosmo")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 0, 0);

	}
	if (Addoption("Super Mesh")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);
	}
	if (Addoption("Driftmeister")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 4, 0);
	}
	if (Addoption("El Quatro")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 6, 0);
	}
	if (Addoption("Dubbed")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 7, 0);
	}
	if (Addoption("Slideways")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 9, 0);
	}
	if (Addoption("Countersteer")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 12, 0);
	}
	if (Addoption("Endo v.2 Dish")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 14, 0);
	}
	if (Addoption("Choku-Dori")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 16, 0);
	}
	if (Addoption("Chicane")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 17, 0);
	}
	if (Addoption("Saisoku")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 18, 0);
	}
	if (Addoption("Dished Eight")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 0);
	}
	if (Addoption("Battle VIII")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 22, 0);
	}
	if (Addoption("Rally Master")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 23, 0);
	}
}

void Spawner::BW()
{
	Addtitle("");
	Addsubtitle("Bike Wheels");
	if (Addoption("Front Wheels"))
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);


		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			int nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 23) - 1;
			int currmod = VEHICLE::GET_VEHICLE_MOD(veh, 23);
			if (currmod < nummods)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, 23, currmod + 1, 0);


			}
			else
			{

				VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);

			}
		}
	}
	if (Addoption("Back Wheel"))
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);


		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			int nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 24) - 1;
			int currmod = VEHICLE::GET_VEHICLE_MOD(veh, 24);
			if (currmod < nummods)
			{

				VEHICLE::SET_VEHICLE_MOD(veh, 24, currmod + 1, 0);

			}
			else
			{

				VEHICLE::SET_VEHICLE_MOD(veh, 24, 1, 0);

			}

		}

	}
}

void Spawner::SpoilerStuff()
{
	Addtitle("");
	Addsubtitle("Spoiler");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 0);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 0);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 0, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 0, i, 1);
				}
			}
		}
	}
}

void Spawner::PlateeStuff()
{
	Addtitle("");
	Addsubtitle("Plate Holder");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 25);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 25);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 25, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 25, i, 1);
				}
			}
		}
	}
}

void Spawner::RollcageStuff()
{
	Addtitle("");
	Addsubtitle("Rollcage");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	vehicle1234 veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	vehicle1234 VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 5);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 5);
	for (int i = 0; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 5, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Addoption(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, 5, i, 1);
				}
			}
		}
	}
}



#pragma region Wheel colours
void Spawner::wheelclass()
{
	Addtitle("");
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 0);
	}
	if (Addoption("Carbon Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 147);
	}
	if (Addoption("Anhracite Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 11);
	}
	if (Addoption("Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 2);
	}
	if (Addoption("Dark Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 3);
	}
	if (Addoption("Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 4);
	}
	if (Addoption("Bluish Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 5);
	}
	if (Addoption("Rolled Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 6);
	}
	if (Addoption("Shadow Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 7);
	}
	if (Addoption("Stone  Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 8);
	}
	if (Addoption("Midnight   Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 9);
	}
	if (Addoption("Cast Iron Silver"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 10);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 27);
	}
	if (Addoption("Torino  Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 28);
	}
	if (Addoption("Formula   Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 29);
	}
	if (Addoption("Lava Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 150);
	}
	if (Addoption("Blaze Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 30);
	}
	if (Addoption("Grace Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 31);
	}
	if (Addoption("Garnet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 32);
	}
	if (Addoption("Sunset Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 33);
	}
	if (Addoption("Cabernet Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 34);
	}
	if (Addoption("Wine Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 143);
	}
	if (Addoption("Candy Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 35);


	}
	if (Addoption("Hot Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);

		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 135);
	}
	if (Addoption("Pfsiter Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 137);
	}
	if (Addoption("Salmon Pink"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 136);
	}
	if (Addoption("Sunrise Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 36);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 38);
	}
	if (Addoption("Bright Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 138);
	}
	if (Addoption("Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 99);
	}
	if (Addoption("Bronze"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 90);
	}
	if (Addoption("Yellow"))
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 88);
	}
	if (Addoption("Race Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 91);
	}
	if (Addoption("Dew Yelow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 92);
	}
	if (Addoption("Drak Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 49);
	}
	if (Addoption("Racing Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 50);
	}
	if (Addoption("Sea Gren"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 51);
	}
	if (Addoption("Olive Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 52);
	}
	if (Addoption("Bright Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 53);
	}
	if (Addoption("Gasoline Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 54);
	}
	if (Addoption("Lime Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 92);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 141);
	}
	if (Addoption("Galaxy Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 61);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 62);
	}
	if (Addoption("Saxgon Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 63);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 64);
	}
	if (Addoption("Mariner Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 65);
	}
	if (Addoption("Harbor Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 66);
	}
	if (Addoption("Diamond Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 67);
	}
	if (Addoption("Surf Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 68);
	}
	if (Addoption("Nautical Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 69);
	}
	if (Addoption("Ultra Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 70);
	}
	if (Addoption("Light Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 74);
	}
	if (Addoption("Chocolate Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 96);
	}
	if (Addoption("Bison Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 101);
	}
	if (Addoption("Creeen Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 95);
	}
	if (Addoption("Feltzer Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 94);
	}
	if (Addoption("Maple Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 97);
	}
	if (Addoption("Beechwood Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 103);
	}
	if (Addoption("Sienna Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 104);
	}
	if (Addoption("Saddle Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 98);
	}
	if (Addoption("Moss Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 100);
	}
	if (Addoption("WoodBeech Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 102);
	}
	if (Addoption("Straw Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 99);
	}
	if (Addoption("Bleached  Brown"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 106);
	}
	if (Addoption("Schafter Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 71);
	}
	if (Addoption("Spinnaker  Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 72);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 142);
	}
	if (Addoption("Bright Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 145);
	}
	if (Addoption("Cream"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 107);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 111);
	}
	if (Addoption("Frost White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 112);
	}
}

void Spawner::wheelmatte()
{
	Addtitle("");
	if (Addoption("Black"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 12);
	}
	if (Addoption("Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 13);
	}
	if (Addoption("Light Grey"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 14);
	}
	if (Addoption("Ice White"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 131);
	}
	if (Addoption("Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 83);
	}
	if (Addoption("Dark Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 82);
	}
	if (Addoption("Midnight Blue"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 84);
	}
	if (Addoption("Midnight Purple"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 149);
	}
	if (Addoption("Schafter"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 148);
	}
	if (Addoption("Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 39);
	}
	if (Addoption("Dark Red"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 40);
	}
	if (Addoption("Orange"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 41);
	}
	if (Addoption("Yellow"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 42);
	}
	if (Addoption("Forest Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 151);
	}
	if (Addoption("Foliage Green"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 155);
	}
	if (Addoption("Olive Darb"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 152);
	}
	if (Addoption("Dark Earth"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 153);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);
	}
	if (Addoption("Desert Tan"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 154);
	}
}

void Spawner::wheelmetal()
{
	Addtitle("");
	if (Addoption("Brushed Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 117);
	}
	if (Addoption("Brushed Black Steel"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 117);
	}
	if (Addoption("Brushed Aluminum"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 119);
	}
	if (Addoption("Pure Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 158);
	}
	if (Addoption("Brushed Gold"))
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescentColor, &wheelColor);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearlescentColor, 159);
	}
}
		

		




		




















































































































