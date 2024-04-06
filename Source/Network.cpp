#include "stdafx.h"
#include "Network.h"
#include "Protections.h"
#include "All Players.h"
#include "Offsets.h"
#include "Local.h"

static char* WeatherChar[] = {
	"EXTRASUNNY",
	"CLEAR",
	"CLOUDS",
	"SMOG",
	"FOGGY",
	"OVERCAST",
	"RAIN",
	"THUNDER",
	"CLEARING",
	"NEUTRAL",
	"SNOW",
	"BLIZZARD",
	"SNOWLIGHT",
	"XMAS",
	"HALLOWEEN",
	"BLACK SCREEN"
}; // Remote Weather 

int WeatherCharInt = 0;
int spooflvl = -99999;
int spoofkd = 99999;
int spoofbank = 13370000;
int spoofwallet = 13370000;
int spoofkill = 13370000;


void LobbyWeather(int number)
{
	
}

int NotificationCEO1(char* text, char* text2, char* Subject)
{
	YTD13();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("Foxy", "FoxyLogo", true, 7, text2, Subject, 1.0, "___FREE");
	return UI::_DRAW_NOTIFICATION(1, 1);

}

BOOL IsPlayerFriend(Player player)
{
	int handle[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
	return NETWORK::NETWORK_IS_FRIEND(&handle[0]);
}

bool Network::dropall = false;
bool Network::Foxyuser = true;
bool Network::Spoofkd = false;
bool Network::Spoofmoney = false;
bool Network::Spoofkill = false;


bool Network::burtonMoney = false;
bool Network::burtonrp = false;
bool Network::HeliMoney = false;
bool Network::Helirp = false;
bool Network::AirportMoney = false;
bool Network::Airportrp = false;
bool Network::EasterEgg1 = false;
bool Network::easteregg2 = false;


#define Playerlocation ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1)
#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())
#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0x1E9A99F8 
#define prop_ld_health_pack 0x113FD533
#define PICKUP_HEALTH_STANDARD 0x1E9A99F8
#define pickup_money_security_case 233405277
#define PROP_MONEY_BAG_02 -1666779307
#define Rp_Statues_01 1298470051 //alien
#define Rp_Statues_02 437412629 //Princess
#define nocolle 1737847354 //beast
#define colle 1955542584 //beast
#define customscript 738282662 //Custom pickup script skid use 0x2C014CA6
#define Rp_Card_01 1226474661 //queen
#define Rp_Card_02 3642186697 //jack
#define Rp_Card_03 158316850 //king

void Network::UpdateLoop() {
	orbitalfucker ? orbitalfuckeR(true) : NULL;

	if (dropall)
	{
		for (int i = 0; i < 32; i++)
		{
			if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
			Vector3 pp = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), 0);
			STREAMING::REQUEST_MODEL(-1666779307);
			if ((timeGetTime() - Local::TimePD2) > 2000.0f)
			{
				if (STREAMING::HAS_MODEL_LOADED(-1666779307)) //==1
				{
					OBJECT::CREATE_AMBIENT_PICKUP(0xDE78F17E, pp.x, pp.y, pp.z + 0, 1000, 2500, -1666779307, 0, 1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(-1666779307);
				}
			}
		}
	}

	if (Foxyuser)
	{
		globalHandle(1590682).At(PLAYER::PLAYER_ID(), 871).At(211).At(16).As<int>() = 999999;//1590682
	}
	if (Spoofkd)
	{

		globalHandle(1590682).At(PLAYER::PLAYER_ID(), 871).At(211).At(26).As<int>() = spoofkd;// 1590446

	}
	if (Spoofmoney)
	{
		//spoof wallet money
		globalHandle(1590682).At(PLAYER::PLAYER_ID(), 871).At(211).At(3).As<int>() = spoofwallet;

		//spoof bank money
		globalHandle(1590682).At(PLAYER::PLAYER_ID(), 871).At(211).At(56).As<int>() = spoofbank;

	}
	if (Spoofkill)
	{
		//spoof kills
		globalHandle(1590682).At(PLAYER::PLAYER_ID(), 871).At(211).At(28).As<int>() = spoofkill;

	}
	if (burtonMoney)
	{
		Hash MoneyHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_lux_card_01a");
		STREAMING::REQUEST_MODEL(MoneyHASH);
		if (!STREAMING::HAS_MODEL_LOADED(MoneyHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -372.533752f, -135.402649f, 39.f, 0, 2500, MoneyHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(MoneyHASH);
		}
	}
	if (burtonrp)
	{
		Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");
		STREAMING::REQUEST_MODEL(RPHASH);
		if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -372.533752f, -131.402649f, 39.f, 0, 1, RPHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
		}
	}
	if (HeliMoney)
	{
		Hash MoneyHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_lux_card_01a");
		STREAMING::REQUEST_MODEL(MoneyHASH);
		if (!STREAMING::HAS_MODEL_LOADED(MoneyHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -695.529f, -1451.844f, 5.010f, 0, 2500, MoneyHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(MoneyHASH);
		}
	}
	if (Helirp)
	{
		Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");
		STREAMING::REQUEST_MODEL(RPHASH);
		if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -700.820f, -1446.950f, 5.010f, 0, 1, RPHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
		}
	}


	if (AirportMoney)
	{
		Hash MoneyHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_lux_card_01a");
		STREAMING::REQUEST_MODEL(MoneyHASH);
		if (!STREAMING::HAS_MODEL_LOADED(MoneyHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -982.282f, -2999.507f, 14.010f, 0, 2500, MoneyHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(MoneyHASH);
		}
	}
	if (Airportrp)
	{
		Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");
		STREAMING::REQUEST_MODEL(RPHASH);
		if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -978.023f, -2993.428f, 14.010f, 0, 1, RPHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
		}
	}




	if (EasterEgg1)
	{
		Hash MoneyHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_lux_card_01a");
		STREAMING::REQUEST_MODEL(MoneyHASH);
		if (!STREAMING::HAS_MODEL_LOADED(MoneyHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -915.815f, -2519.299f, 47.010f, 0, 2500, MoneyHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(MoneyHASH);
		}
	}
	if (easteregg2)
	{
		Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");
		STREAMING::REQUEST_MODEL(RPHASH);
		if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, -915.815f, -2519.299f, 47.010f, 0, 1, RPHASH, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
		}
	}




}


void Network::ESPMenu() {

	Menu::Title("");
	Menu::SubTitle("ESP");
	Menu::Toggle("Name ESP", AP::nesp);
	Menu::Toggle("Reg ESP", AP::Regesp);
}



static std::vector<DWORD64> NameAddresses;
std::vector<DWORD64> getNameAdresses()
{
	return NameAddresses;
}

//OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_NAME_LOCAL 0x7C
#define Offset1 0x08 // done 
#define Offset2 0x10A8// done 
#define Offset3 0xFC //0xA4

void AllocateNameAddresses() {

	static DWORD64 LocalNameAddress = NULL;

	LocalNameAddress = Memory::get_multilayer_pointer(Foxy_Engine::getWorldPtr(), { Offset1, Offset2, Offset3 });

	if (NameAddresses.empty())
	{
		std::string CurrentMask;
		const char* NameToScan = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
		for (uint8_t i = 0; i < strlen(NameToScan); i++) CurrentMask += "x";
		const char *mask = CurrentMask.c_str();

		for (DWORD64 addr : Memory::get_string_addresses(NameToScan)) {
			char buff[100];
			_snprintf_s(buff, sizeof(buff), "OtherName\t\t 0x%p (0x%.8X)", addr, addr - Memory::get_base());
			NameAddresses.push_back((addr));
		}

		if (LocalNameAddress)
			NameAddresses.push_back((LocalNameAddress));
	}
}

void AnimationsForAll(char* dict, char* anim)
{
	for (int i = 0; i < 32; i++)
	{
		int targ_ped = PLAYER::GET_PLAYER_PED(i);
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		if (i != PLAYER::PLAYER_ID())
		{
			RequestControlOfEnt(targ_ped);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(targ_ped);
			AI::CLEAR_PED_TASKS(targ_ped);
			AI::CLEAR_PED_SECONDARY_TASK(targ_ped);
			int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
			ENTITY::SET_ENTITY_COORDS(targ_ped, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			STREAMING::REQUEST_ANIM_DICT(dict);
			if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
			{
				int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
				NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NETWORK::NET_TO_PED(i), sceneID, dict, anim, 1.0f, 1.0f, 269, 0, 100.0f, false);
				NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
			}
		}
	}
}

MODULEINFO g_MainModuleInfo1 = { 0 };
void Network::SetName(const std::string& name)
{
	AllocateNameAddresses();
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;

	char	buffer[0x20] = {};  // posbase
	char*	pSearch = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()) + 0xFC; //Offset_Player_Info_Name
	size_t	curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);

	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;

		if (++match < curLen)
		{
			++i;
			continue;
		}

		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;

	LABEL_RESET:
		i = match = 0;
	}
	int VectorSize = getNameAdresses().size();
	int i = 0;
	for (DWORD64 Address : getNameAdresses()) {
		i++;
		strncpy((char*)Address, &name[0], newLen);
	}
	notifyMap(Menu::Tools::StringToChar("~b~Setting New Name To " + (std::string)name));
	notifyMap("~q~Join a new session to apply the new name");
}

int StuffTime;

void TimeStuff(int hour) {

}

char* StringToChar(std::string string)
{
	return _strdup(string.c_str());
}



void Network::MainMenu()
{
	Menu::Title("");
	Menu::SubTitle("Network");
	Menu::MenuOption("Players", players);
	Menu::MenuOption("Recovery", recovery);
	Menu::MenuOption("Protections", protections);
	Menu::MenuOption("ESP", ESPMENU);
	Menu::MenuOption("Spoof Sub", spooferkek);
	Menu::MenuOption("Preset Drop Location", DropAllMenu);
	Menu::MenuOption("Friends", friendlist);
	Menu::Toggle("Drop All", Network::dropall);
	Menu::Toggle("Inferno Super Power", Local::GODOFRAIN);
	
	Menu::Toggle("Off The Radar", Local::OffRadar);
	if (Menu::Option("Doom Players")) {
		for (int i = 0; i < 32; i++)
		{
			Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Hash beach_fire = GAMEPLAY::GET_HASH_KEY("prop_beach_fire");
			STREAMING::REQUEST_MODEL(beach_fire);
			while (!STREAMING::HAS_MODEL_LOADED(beach_fire)) WAIT(0);
			if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
			{
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
				{
					Object object = OBJECT::CREATE_OBJECT(beach_fire, 0, 0, 0, true, true, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(object, playerHandle, 0x4B5, 0, 0, 0, 0, 0, 0, false, false, false, false, 2, true);
				}
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(beach_fire);
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
	if (Menu::Option("Explode Session")) {
		for (int i = 0; i < 33; i++)
		{
			if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
			{
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f);
			}
		}
	}
	Menu::Toggle("Unlimited Orbital Cannon", Network::orbitalfucker);

	/*if (Menu::Option("Cayo Perico Party")) {

		for (int i = 0; i < 32; i++) {
			{
				unsigned int Bit = (1 << i);;
				DWORD64 args[4] = { 1300962917, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 0 };
				Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);


			}
		}
	}*/
	//if (Menu::Option("Meditation For all")) { AnimationsForAll("rcmcollect_paperleadinout@", "meditiate_idle"); }
	//missfbi3ig_0", "shit_loop_trev" "rcmcollect_paperleadinout@", "meditiate_idle"

	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Players Sub");
	}
	if (Menu::Settings::currentOption == 2) {
		Menu::OptionInfo("Recovery Sub");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Protections Sub");
	}
	if (Menu::Settings::currentOption == 4) {
		Menu::OptionInfo("ESP Sub");
	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Spoof Sub");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("Preset Drop Location Sub");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Friend List Sub");
	}
	if (Menu::Settings::currentOption == 8) {
		Menu::OptionInfo("Drop Money To Everyone Around You");
	}
	if (Menu::Settings::currentOption == 9) {
		Menu::OptionInfo("Online Super Powers");
	}
	if (Menu::Settings::currentOption == 10) {
		Menu::OptionInfo("Hides Your Blip From Others Radar");
	}
	if (Menu::Settings::currentOption == 11) {
		Menu::OptionInfo("You'll See");
	}
	if (Menu::Settings::currentOption == 12) {
		Menu::OptionInfo("Kick Everyone Out Of Their Vehicle");
	}
	if (Menu::Settings::currentOption == 13) {
		Menu::OptionInfo("Kill Everyone With An Explosion");
	}
	if (Menu::Settings::currentOption == 14) {
		Menu::OptionInfo("No Cooldown On The Orbital Cannon");
	}
}


/*bool isPlayerSkid(Player p) {
	int SkidValue = 0;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);


}*/


bool isplayerFoxyuser(Player p)
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int FoxyValue = 0;
		Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
		string VIPUser;
		int Foxystat = globalHandle(1590682).At(p, 871).At(211).At(16).As<int>();
		if (Foxystat == 999999)
		{
			FoxyValue += 10;
		}

		if (FoxyValue = 10)
		{
			return true;
		}
		return false;
	}

}

bool isPlayerModder(Player p) 
{
	int modderValue = 0;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	bool hasGodmode = PLAYER::GET_PLAYER_INVINCIBLE(ped);
	int alpha = ENTITY::GET_ENTITY_ALPHA(ped);
	
	int total_money = globalHandle(1590682).At(p, 871).At(211).At(56).As<int>(); //done
	int wallet_money = globalHandle(1590682).At(p, 871).At(211).At(3).As<int>();  //done
	int level = globalHandle(1590682).At(p, 871).At(211).At(6).As<int>(); //done
	int kills = globalHandle(1590682).At(p, 871).At(211).At(28).As<int>(); //done
	int deaths = globalHandle(1590682).At(p, 871).At(211).At(29).As<int>(); //done
	float kd = globalHandle(1590682).At(p, 871).At(211).At(26).As<float>(); //done
	int bank_money = total_money - wallet_money;
	Hash player_model = ENTITY::GET_ENTITY_MODEL(ped);

	int max_legit_money = 8000000;
	int max_legit_level = 1000;
	int max_legit_deaths = 100000;
	int max_legit_kills = 1000000;
	float max_legit_kd = 12.0f;

	Hash legit_model[] = 
	{
		GAMEPLAY::GET_HASH_KEY("mp_m_freemode_01"),
		GAMEPLAY::GET_HASH_KEY("mp_f_freemode_01")
	};

	if (player_model != legit_model[0] && player_model != legit_model[1]) {
		modderValue += 10;
	}

	if (alpha < 25) {
		modderValue += 1;
	}

	if (level > max_legit_level)
	{
		modderValue += 3;
	}

	if (wallet_money > max_legit_money) 
	{
		modderValue += 2;
	}

	if (bank_money > max_legit_money)
	{
		modderValue += 3;
	}

	if (kd > max_legit_kd) {
		modderValue += 1;
		if (kills > max_legit_kills)
		{
			modderValue += 1;
		}
		if (deaths > max_legit_deaths) 
		{
			modderValue += 1;
		}
	}

	if (modderValue > 10) 
	{
		return true;
	}
	return false;
}

bool Network::orbitalfucker = false;
void Network::orbitalfuckeR(bool toggle) {

	Foxy_Engine::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ORBITAL_CANNON_COOLDOWN"), 0, 0);
	Foxy_Engine::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_ORBITAL_CANNON_COOLDOWN"), 0, 0);
}

void Network::KickAll()
{
	for (int i = 0; i < 32; i++)  {
		{
			unsigned int Bit = (1 << i);;
			DWORD64 args[4] = { 1300962917, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 0 };
			Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);


		}
	}
}

bool Network::Liststyle = false;

void Network::Players()
{
	Menu::Title("");
	Menu::SubTitle("Players");
	Menu::Toggle("Player List Style", Network::Liststyle);
	if (Network::Liststyle)
	{
		for (int i = 0; i < 32; i++)
		{
			char* playerName;
			char NameBuffer[255];
			int armor = PLAYER::GET_PLAYER_MAX_ARMOUR(i);
			Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			if (PLAYER::IS_PLAYER_PLAYING(i)) {

				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~q~Me~s~] ~s~[~y~Host~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~q~Me~s~] ~s~[~y~Host~s~] ~s~[~y~Foxy Free~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~q~Me~s~] ~s~[~y~Foxy Free~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID())
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~q~Me~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (isPlayerModder(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Host~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (isPlayerModder(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Host~s~] ~s~[~y~Foxy Free~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (isPlayerModder(i) && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Foxy Free~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (isPlayerModder(i))
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~r~Modder~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (IsPlayerFriend(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~b~Friend~s~] ~s~[~y~Host~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (IsPlayerFriend(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~b~Friend~s~] ~s~[~y~Host~s~] ~s~[~y~Foxy Free~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~y~Host~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (IsPlayerFriend(i))
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~g~Friend~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (IsPlayerFriend(i) && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
				{
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~g~Friend~s~]  ~s~[~y~Foxy Free~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else if (NETWORK::NETWORK_IS_PLAYER_TALKING(i)) {
					char* Name = PLAYER::GET_PLAYER_NAME(i);
					sprintf(NameBuffer, "%s ~s~[~HUD_COLOUR_PURPLE~Talking~s~]", Name);
					Name = NameBuffer;
					Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
				}
				else
				{
					Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), Onlineselecc) ? selectedPlayer = i : NULL;

				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 32; i++)
		{
			char* playerName;
			char NameBuffer[255];
			int armor = PLAYER::GET_PLAYER_MAX_ARMOUR(i);
			Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			

			if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~q~Me~s~] ~s~[~y~Host~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~q~Me~s~] ~s~[~y~Host~s~] ~s~[~y~Foxy Free~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~q~Me~s~] ~s~[~y~Foxy Free~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID())
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~q~Me~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (isPlayerModder(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Host~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (isPlayerModder(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Host~s~] ~s~[~y~Foxy Free~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (isPlayerModder(i) && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Foxy Free~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (isPlayerModder(i))
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~r~Modder~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (IsPlayerFriend(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~b~Friend~s~] ~s~[~y~Host~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (IsPlayerFriend(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~b~Friend~s~] ~s~[~y~Host~s~] ~s~[~y~Foxy Free~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~y~Host~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (IsPlayerFriend(i))
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~g~Friend~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (IsPlayerFriend(i) && PLAYER::GET_PLAYER_MAX_ARMOUR(selectedPlayer) == 956)
			{
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~g~Friend~s~]  ~s~[~y~Foxy Free~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else if (NETWORK::NETWORK_IS_PLAYER_TALKING(i)) {
				char* Name = PLAYER::GET_PLAYER_NAME(i);
				sprintf(NameBuffer, "%s ~s~[~HUD_COLOUR_PURPLE~Talking~s~]", Name);
				Name = NameBuffer;
				Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
			}
			else
			{
				Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), Onlineselecc) ? selectedPlayer = i : NULL;

			}
			
		}
	}
}




int GlobForNeverWanted(int plr) {
	return globalHandle(GLOBAL_FOR_REMOVE_WANTED_LEVEL + (1 + (plr * 614)) + 532).As<int>();
}

bool kickPlayer(int selectedPlayer, int type) {
	if (type == -2) {
		DWORD64 args[3] = { FORCE_TO_NEW_SESSION, selectedPlayer, GlobForNeverWanted(selectedPlayer) };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	if (type == -1) {	//auto trigger all kicks [>=1]
		if (kickPlayer(selectedPlayer, 0)) notifyMap("host kicked");
		else {
			for (int x = 45; x <= 1; x--) {
				kickPlayer(selectedPlayer, x);
			}
		}
	}
	else if (type == 0) {
		NETWORK::NETWORK_SESSION_KICK_PLAYER(selectedPlayer);
		return true;
	}
	else if (type == 1) {
		DWORD64 args[4] = { KICK_1, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 2) {
		DWORD64 args[3] = { KICK_2, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 3) {
		DWORD64 args[4] = { KICK_3, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 4) {
		DWORD64 args[5] = { KICK_4, selectedPlayer, 0, 111 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 5) {
		DWORD64 args[3] = { KICK_5, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 6) {
		DWORD64 args[4] = { KICK_6, selectedPlayer, 50 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 7) {
		DWORD64 args[4] = { KICK_7, selectedPlayer, 20, 1 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 8) {
		DWORD64 args[4] = { KICK_8, selectedPlayer, 20 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 9) {
		DWORD64 args[4] = { KICK_9, selectedPlayer, 20, 1 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 10) {
		DWORD64 args[4] = { KICK_10, selectedPlayer, 20 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 11) {
		DWORD64 args[4] = { KICK_11, selectedPlayer, 20 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 12) {
		DWORD64 args[6] = { KICK_12, selectedPlayer, 0, 0, 0, 36 };
		Foxy_Engine::trigger_script_event(1, args, 6, 1 << selectedPlayer);
	}
	else if (type == 13) {
		DWORD64 args[3] = { KICK_13, selectedPlayer, 36 };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 14) {
		DWORD64 args[3] = { KICK_14, selectedPlayer, -4294967260/*36*/ };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 15) {
		DWORD64 args[4] = { KICK_15, selectedPlayer, 32 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 16) {
		DWORD64 args[5] = { KICK_16, selectedPlayer, 0, 0, 32 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 17) {
		DWORD64 args[5] = { KICK_17, selectedPlayer, 0, 0, 32 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 18) {
		DWORD64 args[5] = { KICK_18, selectedPlayer, 4 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 19) {
		DWORD64 args[5] = { KICK_19, selectedPlayer, 7 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 20) {
		DWORD64 args[6] = { KICK_20, selectedPlayer, 0, 59 };
		Foxy_Engine::trigger_script_event(1, args, 6, 1 << selectedPlayer);
	}
	else if (type == 21) {
		DWORD64 args[5] = { KICK_21, selectedPlayer, 0, 59 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 22) {
		DWORD64 args[4] = { KICK_22, selectedPlayer, 0, 59 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 23) {
		DWORD64 args[4] = { KICK_23, selectedPlayer, 62 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 24) {
		DWORD64 args[4] = { KICK_24, selectedPlayer, 0, 26 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 25) {
		DWORD64 args[5] = { KICK_25, selectedPlayer, 0, 26 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 26) {
		DWORD64 args[4] = { KICK_26, selectedPlayer, 0, 26 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 27) {
		DWORD64 args[3] = { KICK_27, selectedPlayer, 3 };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 28) {
		DWORD64 args[24] = { KICK_28, selectedPlayer, 180 };
		Foxy_Engine::trigger_script_event(1, args, 24, 1 << selectedPlayer);
	}
	else if (type == 29) {
		DWORD64 args[5] = { KICK_29, selectedPlayer, 64 };
		Foxy_Engine::trigger_script_event(1, args, 5, 1 << selectedPlayer);
	}
	else if (type == 30) {
		DWORD64 args[3] = { KICK_30, selectedPlayer, 32 };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 31) {
		DWORD64 args[4] = { KICK_31, selectedPlayer, 62 };
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 32) {
		DWORD64 args[18] = { KICK_32, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args, 18, 1 << selectedPlayer);
	}
	else if (type == 33) {
		DWORD64 args[3] = { KICK_33, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args, 3, 1 << selectedPlayer);
	}
	else if (type == 34) {
		DWORD64 args[13] = { KICK_34, selectedPlayer, 123 }; //fix
		Foxy_Engine::trigger_script_event(1, args, 13, 1 << selectedPlayer);
	}
	else if (type == 35) {
		DWORD64 args1[4] = { KICK_35, selectedPlayer };
		Foxy_Engine::trigger_script_event(1, args1, 4, 1 << selectedPlayer);
	}
	else if (type == 36) {
		DWORD64 args[21];
		*args = KICK_36;
		args[1] = selectedPlayer;
		args[19] = 125;
		Foxy_Engine::trigger_script_event(1, args, 21, 1 << selectedPlayer);
	}
	else if (type == 37) {
		DWORD64 args[4] = { KICK_37, selectedPlayer, 1, 124 };//need check false alarm
		Foxy_Engine::trigger_script_event(1, args, 4, 1 << selectedPlayer);
	}
	else if (type == 38) {
		DWORD64 args[10] = { KICK_38, selectedPlayer, 1, 10000, 32/*n0*/, 0, 1, 46, 1, 40 };
		Foxy_Engine::trigger_script_event(1, args, 10, 1 << selectedPlayer);
	}
	else if (type == 39) {
		DWORD64 args[10] = { KICK_39, selectedPlayer, 1, 10000, 32, 0, 1, 36, 1, 40 };
		Foxy_Engine::trigger_script_event(1, args, 10, 1 << selectedPlayer);
	}
	else if (type == 40) {
		DWORD64 args[25];
		*args = KICK_40, args[1] = selectedPlayer, args[2] = 180;
		args[24] = GlobForNeverWanted(selectedPlayer);
		Foxy_Engine::trigger_script_event(1, args, 25, 1 << selectedPlayer);
	}
}

//bool time[3];

/*			Menu::Toggle("Entity Pool Crash [Crash Yourself + Other Player]", SPlayer::poolcrash2);
			if (Menu::Option("Husky Crash"))
			{
				if (SPlayer::SpectateBool == true)
				{
					notifyMap("You can't crash the player, while spactating said player");
				}
				else
				{
					int Ped_Hash;
					int i = 0;
					while (i < 75)
					{
						i++;
						Ped_Hash = GAMEPLAY::GET_HASH_KEY("a_c_husky");
						{
							STREAMING::REQUEST_MODEL(Ped_Hash);
							if (STREAMING::HAS_MODEL_LOADED(Ped_Hash));
							{
								Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
								int Handle = PED::CREATE_PED(1, Ped_Hash, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), TRUE, TRUE);
								if (ENTITY::DOES_ENTITY_EXIST(Handle))
								{
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
								}
							}
						}
					}
					WAIT(200);
					notifyMap("Husky Crash Done");
				}
			}
			if (Menu::Option("Cargo Crash"))
			{
				if (SPlayer::SpectateBool == true)
				{
					notifyMap("You can't crash the player, while spactating said player");
				}
				else
				{
					int Ped_Hash;
					int i = 0;
					while (i < 75)
					{
						i++;
						int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
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
					Vector3 GetPlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
					FIRE::ADD_EXPLOSION(GetPlayerCoords.x, GetPlayerCoords.y, GetPlayerCoords.z, 29, 999, true, false, 10);
					PED::EXPLODE_PED_HEAD(PLAYER::GET_PLAYER_PED(selectedPlayer), 0x145F1012);
					notifyMap("Crashed");
				}
			}
			
			
			
			
			
			
			
					if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) && isplayerFoxyuser(i) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~b~Me~s~] ~s~[~y~Host~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}
		else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && isplayerFoxyuser(i))
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~b~Me~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}
		else if (isPlayerModder(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) && isplayerFoxyuser(i) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~y~Host~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}
		else if (isPlayerModder(i) && isplayerFoxyuser(i))
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~r~Modder~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}
		else if (IsPlayerFriend(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) && isplayerFoxyuser(i) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~b~Friend~s~] ~s~[~y~Host~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}
		else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) && isplayerFoxyuser(i) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~y~Host~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}
		else if (IsPlayerFriend(i) && isplayerFoxyuser(i))
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~g~Friend~s~] ~s~[~p~Foxy~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, Onlineselecc) ? selectedPlayer = i : NULL;
		}*/