//Hooking.cpp
#pragma once
#include "stdafx.h"
#include "Protections.h"
#include "stdafx.h"
#include "dllmain.h"
#include "ntifs.h"
#include "bcrypt.h"
//#include "auth.h"
#include "stuff.h"
#define crashed 474FL747J;
std::vector < std::string> gametitle = { 
"Foxy cheats free version",
"Foxy cheats free version (Spooky, where the owner stepped down due to fucking hate LMAO)",
"Foxy cheats free version (X-Cheats, where the dev dies every week)",
"Foxy cheats free version (X-Force, where... where... i should not say anything)",
"Foxy cheats free version (Distant, something so ass that it doesn't even deserve a roast)",
"Foxy cheats free version (Paragone, exit scamming dumbasses THREE TIME)",
"Foxy cheats free version (Anyone wanna be banned in 5 minutes? Buy Fragment)",
"Foxy cheats free version (Menu detected, opinion rejected)",
"Foxy Cheats free Version (Aurora, where the dev rename Yimmenu to prometheus then to aurora and use leaked OpMoneylua code)",
"Foxy Cheats Free Version (Aurora be like we can crash 2take1 but only whit there protection off)",
"Foxy Cheats Free Version (Newway, where the menu is soo pasted that the source can't compile most of the time)",
"Foxy Cheats Free Version (Liquid, where we thought shadow was a decent source to paste)",
"Foxy Cheats Free Version (Lightning-X, well no roast for you since you actually made a good menu)",
"Foxy Cheats Free Version (Stand, where we blame lua to get us detected when lua is simply native calling and globals...)",
"Foxy Cheats Free Version (Phantom-X where we can't make basket transaction but decent fun option)",
"Foxy cheats free version (2take1, where the dev is so focused on protection that it has less option then foxy free)",
"Foxy cheats free version (Spooky, where the dev run away and rename the menu to revenant)",
"Foxy cheats free version (Frontier, Absolute, Paragon where we value money more then be a decent human being)",
"Foxy cheats free version (Foxy, where the dev stop working on it 20 times in 3 years)",
"Foxy cheats free version (Ovr, where the dev made the best menu ever but won't release it)",
"Foxy cheats free version (Foxy, where we made a paid menu to never release it)",
"Foxy cheats free version (Raiden, imagine charging people money for a menu that isn't good as foxy)",
"Foxy cheats free version (Cherax, where the menu can be crash by invalid task and pizza boxes)",
"Foxy cheats free version (Liquid, where we pasted detected code in our menu to get our users banned)",
"Foxy cheats free version (Squad-X, where the menu is more pasted then p3trol)",
"Foxy cheats free version (Dura, where the menu is still pasted in 2023 by liquid)",
"Foxy cheats free version (Foxy, where free doesn't mean shitty)",
"Foxy cheats free version (Foxy, where you can fully control your lobby)",
"Foxy cheats free version (Crespo, where the dev beg for code to paste)",
"Foxy cheats free version (Delta, where the menu is so pasted that it's not even obfuscated or packed)",
"Foxy cheats free version (Ovix, where the menu is actually stable and decent for the price)",
"Foxy cheats free version (Ovix, where the menu is actually stable and decent for the price)",

};
int value;
void int_in_between(int min, int max) {
	GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 20);
}
int random_integer;
int lowest = 0, highest = 20;
int range = (highest - lowest);
int Randomint = lowest + int(range * rand() / (RAND_MAX + 1.0));
using namespace Memory;


int random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

typedef CPed* (*pGetPlayerCPed)(int64_t Player);
pGetPlayerCPed GetPlayerCPed;
string stopm = "";
typedef enum _MEMORY_INFORMATION_CLASS {
	MemoryBasicInformation
} MEMORY_INFORMATION_CLASS;
typedef NTSTATUS(*NtQueryVirtualMemory)(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T);

ScriptThread*(*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;
extern HMODULE _hmoduleDLL;
HMODULE Foxy_Engine::scriptDLL;
HWND m_hwnd;
NtQueryVirtualMemory OriginalNtQueryVirtualMemory = nullptr;

std::vector<LPVOID>		Foxy_Engine::m_hooks;
uint64_t*				Foxy_Engine::m_frameCount;
fpisPLAYERdead			Foxy_Engine::is_PLAYER_dead;
GetEventData1			Foxy_Engine::get_event_data;

fpPickupRewardMoneyIsApplicableToPlayer Foxy_Engine::PickupRewardMoneyIsApplicableToPlayer = nullptr;

fpGetPlayerName					Foxy_Engine::get_player_name;
//SetSessionWeather               Foxy_Engine::set_session_weather;
fpCreateAmbientPickup           Foxy_Engine::create_ambient_pickup;
fpTriggerScriptEvent			Foxy_Engine::trigger_script_event;
GetEventData                    Foxy_Engine::get_script_event_data;
fpAddOwnedExplosion				Foxy_Engine::add_owned_explosion;
fpAnticheatsig                  Foxy_Engine::Anticheatsig;
fpExplosionEventHandle          Foxy_Engine::ExplosionEventHandle = nullptr;
fpFreezeEventHandle             Foxy_Engine::FreezeEventHandle = nullptr;
fpblockmodelcrash               Foxy_Engine::blockmodelcrash = nullptr;
fpremove_weapon               Foxy_Engine::remove_weapon = nullptr;
fpGetLabelText                  Foxy_Engine::GetLabelText = nullptr;
BunkerResearch                  Foxy_Engine::BResearch;
fpStatSetInt		         	Foxy_Engine::stat_set_int;
fpgetmodelinfo		         	Foxy_Engine::GetModelInfo;
fpStatSetBool		        	Foxy_Engine::stat_set_bool;
fpChatMessage                   Foxy_Engine::get_chat_message;
fpAddressToEntity				Foxy_Engine::AddressToEntity;
fpGetPlayerAddress				Foxy_Engine::GetPlayerAddress;
fpPtrToHandle					Foxy_Engine::ptr_to_handle;
//fpSetSessionTime				Foxy_Engine::set_session_time_info;

clockTime*						Foxy_Engine::ClockTime;

fpCreateObject					Foxy_Engine::create_object;
fpHasModelLoaded				Foxy_Engine::has_model_loaded;
fpRequestModel					Foxy_Engine::request_model;
fpCreateVehicle					Foxy_Engine::create_vehicle;
fpGiveDelayedWeaponToPed		Foxy_Engine::give_delayed_weapon_to_ped;
fpSetVehicleMod					Foxy_Engine::set_vehicle_mod;

twoBytes*						owned_explossion_bypass_info;
twoBytes*						model_spawn_bypass_info;
Bytes24*						model_check_bypass_info;

bool Foxy_Engine::chat_cmd_on = false;
int Foxy_Engine::selectedChatPlayer = 0;
bool Foxy_Engine::command1on = false;
bool Foxy_Engine::command2on = false;
bool Foxy_Engine::action1_1 = false;
bool Foxy_Engine::action1_2 = false;
bool Foxy_Engine::action1_3 = false;
bool Foxy_Engine::action1_4 = false;
bool Foxy_Engine::action1_5 = false;
bool Foxy_Engine::action1_6 = false;
bool Foxy_Engine::action1_7 = false;
bool Foxy_Engine::action1_8 = false;
bool Foxy_Engine::action1_9 = false;
bool Foxy_Engine::action2 = false;

void *Foxy_Engine::invoker_return_address;

//CReplayInterface*		Foxy_Engine::m_replayIntf;

//static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Foxy_Engine::NativeRegistrationNew**						m_registrationTable;
static std::unordered_map<uint64_t, Foxy_Engine::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;

const int EVENT_COUNT = 78;
static std::vector<void*> EventPtr;
static char EventRestore[EVENT_COUNT] = {};

bool cleanupStarted = false;
bool cleanupRequested = false;
bool* is_session_started;
static HANDLE scriptFiber;
bool Foxy_Engine::spoof_rid = false;

char* Foxy_Engine::spoofed_rid = "1234321";
int Foxy_Engine::myCurrentHandle[76];
int Foxy_Engine::inputHandle[76];
bool Foxy_Engine::isThisMyHandle = false;

/* Start Hooking */

static std::size_t get_module_size(HMODULE hmod)
{
	auto dosHeader = PIMAGE_DOS_HEADER(hmod);
	auto ntHeader = PIMAGE_NT_HEADERS(PBYTE(hmod) + dosHeader->e_lfanew);

	return ntHeader->OptionalHeader.SizeOfImage;
}

void Foxy_Engine::networkHandleChecker()
{
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(PLAYER::PLAYER_ID(), &Foxy_Engine::myCurrentHandle[0], 13);
	if (NETWORK::NETWORK_ARE_HANDLES_THE_SAME(Foxy_Engine::inputHandle, Foxy_Engine::myCurrentHandle) && Foxy_Engine::spoof_rid) {
		Foxy_Engine::isThisMyHandle = true;
	}
	else {
		Foxy_Engine::isThisMyHandle = false;
	}
}

static uintptr_t* m_incrementStatEventVTable = nullptr;
bool(*f_incrementStatEventHandler)(char*, char*, float) = nullptr;
bool hookedIncrementStatEventHandler(char* a1, char* a2, float a3)
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	unsigned int hash = *reinterpret_cast<unsigned int*>(a1 + 48);
	unsigned int PlayerID = *reinterpret_cast<unsigned int*>(a1 + 52);
	switch (hash)
	{
	case 0xcbfd04a4 /* MPPLY_GAME_EXPLOITS */:
	case 0x0e7072cd /* MPPLY_VC_HATE */:
	case 0x9f79ba0b /* MPPLY_EXPLOITS */:
	case 0x762f9994 /* MPPLY_TC_ANNOYINGME */:
	case 0xb722d6c0 /* MPPLY_TC_HATE */:
		printf("Report: %#x From: %d Satus: Blocked", hash, PlayerID);
		return true;
	default:
		return f_incrementStatEventHandler(a1, a2, a3);
	}
}

int NotificationCrash(char* text, char* text2, char* Subject)
{
	YTD15();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("Foxy", "FoxyCrashLogo", true, 7, text2, Subject, 1.0, "___FREE");
	return UI::_DRAW_NOTIFICATION(1, 1);

}

void ReportProtection(bool b)
{
	if (!b)
		goto UNHOOK;

	f_incrementStatEventHandler = *reinterpret_cast<bool(**)(char*, char*, float)>(&m_incrementStatEventVTable[7]);
	*reinterpret_cast<bool(**)(char*, char*, float)>(&m_incrementStatEventVTable[7]) = &hookedIncrementStatEventHandler;
	return;

UNHOOK:
	if (!f_incrementStatEventHandler)
		return;

	*reinterpret_cast<bool(**)(char*, char*, float)>(&m_incrementStatEventVTable[7]) = f_incrementStatEventHandler;
	f_incrementStatEventHandler = nullptr;
}

void Foxy_Engine::Start(HMODULE hmoduleDLL)
{

	Log::Msg("Started Hooking");
	if ((int)hmoduleDLL < 0) {
		Log::Msg("Module Address: 0x%i", (int)hmoduleDLL * -1);
	}
	else {
		Log::Msg("Module Address: 0x%i", (int)hmoduleDLL);
	}
	_hmoduleDLL = hmoduleDLL;
	scriptDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	if (!InitializeHooks()) Cleanup();
}

BOOL Foxy_Engine::InitializeHooks()
{
	BOOL returnVal = TRUE;

	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	if (!iHook.Initialize()) {

		printf("Failed to initialize InputHook\n");
		returnVal = FALSE;
	}

	if (!HookNatives()) {

		printf("Succeed to initialize NativeHooks\n");
		returnVal = FALSE;
	}

	return returnVal;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Foxy_Engine::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

fpChatMessage OG_GET_MESSAGE = nullptr;
void __cdecl HK_GET_MESSAGE(__int64 a1, __int64 a2, __int64 a3, char* message) {
	if (Foxy_Engine::chat_cmd_on) {

		if (strcmp(message, "/snow on") == 0 && Foxy_Engine::command1on) {
			Foxy_Engine::action1_1 = true;
		}
		if (strcmp(message, "/snow off") == 0 && Foxy_Engine::command1on) {
			Foxy_Engine::action1_2 = true;
		}
		if (strcmp(message, "/kill all") == 0 && Foxy_Engine::command2on) {
			Foxy_Engine::action1_4 = true;
		}
	}
	return OG_GET_MESSAGE(a1, a2, a3, message);
}

uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}

Foxy_Engine::NativeHandler ORIG_GET_EVENT_DATA = NULL;
void *__cdecl MY_GET_EVENT_DATA(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		//Log::Msg("Hooking GET_EVENT_DATA");
		ORIG_GET_EVENT_DATA(cxt);
	}
	//Log::Msg("Event ID: %s", SCRIPT::GET_EVENT_DATA);
	return nullptr;
}

fpisPLAYERdead	OG_IS_PLAYER_DEAD = nullptr;
BOOL __cdecl HK_IS_PLAYER_DEAD()
{
	static uint64_t	last = 0;
	uint64_t		cur = *Foxy_Engine::m_frameCount;
	if (last != cur)
	{
		last = cur;
		Foxy_Engine::onTickInit();
	}


	return OG_IS_PLAYER_DEAD();
}

Foxy_Engine::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext* cxt)
{
	static int lastThread = 0;
	int threadId = SCRIPT::GET_ID_OF_THIS_THREAD();
	if (!lastThread)
	{
		char* name = SCRIPT::_GET_NAME_OF_THREAD(threadId);
		if (strcmp(name, "main_persistent") == 0)
		{
			lastThread = threadId;
			Log::Msg("Hooked Script NAME: %s ID: %i", name, threadId);
		}
	}
	if (threadId == lastThread) Foxy_Engine::onTickInit();
	ORIG_WAIT(cxt);
	return cxt;
}

Foxy_Engine::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void *__cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}


Foxy_Engine::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void *__cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Foxy_Engine::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void *__cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Foxy_Engine::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void *__cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Foxy_Engine::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void *__cdecl MY_CLEAR_PED_TASKS(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Foxy_Engine::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void *__cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Foxy_Engine::NativeHandler ORIG_CLONE_PED = NULL;
void *__cdecl MY_CLONE_PED(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}

fpMemberIdFromGamerHandle Foxy_Engine::member_id_from_gamer_handle;
fpMemberIdFromGamerHandle OG_MEMBER_ID_FROM_GAMER_HANDLE = nullptr;
bool __cdecl HK_MEMBER_ID_FROM_GAMER_HANDLE(int* networkHandle) {
	if (Foxy_Engine::spoof_rid) 
	{
		for (int i = 0; i < 13; i++) {
			Foxy_Engine::inputHandle[i] = networkHandle[i];
		}
		if (Foxy_Engine::isThisMyHandle) {
			return Foxy_Engine::spoofed_rid;
		}
	}
	return OG_MEMBER_ID_FROM_GAMER_HANDLE(networkHandle);
}

// Anti cheat
// Anti API Hooking Detection (They won't know you're blocking sig scanning)

typedef void* (*AntiCheatCheck)();
void* CheckPatching()
{
	return 0;
}
AntiCheatCheck OriginalDontUse = nullptr;

typedef SIZE_T(WINAPI* pVirtualQueryEx)(HANDLE, LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T);
pVirtualQueryEx OriginalVirtualQueryEx = NULL;
SIZE_T WINAPI VirtualQueryExHook(HANDLE hProcess, LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
	if (lpBuffer != nullptr)
	{
		uint64_t baseScan = (uint64_t)lpAddress;
		uint64_t endScan = (baseScan + dwLength);

		uint64_t moduleBase = (uint64_t)DLLInfo.lpBaseOfDll;
		uint64_t moduleEnd = (moduleBase + (uint64_t)DLLInfo.SizeOfImage);

		if ((baseScan >= moduleBase && endScan <= moduleEnd) || (endScan >= moduleBase && endScan <= moduleEnd))
		{
			lpBuffer->AllocationBase = 0;
			lpBuffer->AllocationProtect = 0;
			lpBuffer->State = MEM_FREE;
			lpBuffer->Protect = PAGE_NOACCESS;
			lpBuffer->Type = 0;
		}
	}
	return OriginalVirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength);
}

//done


typedef SIZE_T(WINAPI* pVirtualQuery)(LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T);
pVirtualQuery OriginalVirtualQuery = NULL;
SIZE_T WINAPI VirtualQueryHook(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
	if (lpBuffer != nullptr)
	{
		uint64_t baseScan = (uint64_t)lpAddress;
		uint64_t endScan = (baseScan + dwLength);

		uint64_t moduleBase = (uint64_t)DLLInfo.lpBaseOfDll;
		uint64_t moduleEnd = (moduleBase + (uint64_t)DLLInfo.SizeOfImage);

		if ((baseScan >= moduleBase && endScan <= moduleEnd) || (endScan >= moduleBase && endScan <= moduleEnd))
		{
			lpBuffer->AllocationBase = 0;
			lpBuffer->AllocationProtect = 0;
			lpBuffer->State = MEM_FREE;
			lpBuffer->Protect = PAGE_NOACCESS;
			lpBuffer->Type = 0;
		}
	}
	return OriginalVirtualQuery(lpAddress, lpBuffer, dwLength);
}

//done


NTSTATUS NtQueryVirtualMemoryHook(HANDLE processHandle, PVOID baseAddr, MEMORY_INFORMATION_CLASS memInfoClass, PVOID memInfo, SIZE_T memInfoLength, PSIZE_T retLength)
{
	uint64_t baseScan = (uint64_t)baseAddr;
	uint64_t endScan = (baseScan + memInfoLength);
	uint64_t moduleBase = (uint64_t)DLLInfo.lpBaseOfDll;
	uint64_t moduleEnd = (moduleBase + (uint64_t)DLLInfo.SizeOfImage);
	if ((baseScan >= moduleBase && endScan <= moduleEnd) || (endScan >= moduleBase && endScan <= moduleEnd))
	{
		cout << "Blocked memory scan at " << std::hex << baseScan << " ending at " << endScan << endl;
		return 0xC0000022;
	}
	return OriginalNtQueryVirtualMemory(processHandle, baseAddr, memInfoClass, memInfo, memInfoLength, retLength);
}

bool model_spawn_bypass(bool toggle)
{
	constexpr twoBytes patched = { 0x90, 0x90 };
	constexpr twoBytes restore = { 0x74, 0x05 };
	if (model_spawn_bypass_info == nullptr)
		return NULL;
	*model_spawn_bypass_info = toggle ? patched : restore;
	return true;
}

bool model_check_bypass(bool toggle)
{
	constexpr Bytes24 patched = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

	constexpr Bytes24 restore = { 0x48, 0x85, 0xC0, 0x0F, 0x84, 0x99,
		0x02, 0x00, 0x00, 0x8B, 0x48, 0x50, 0xC1, 0xE9, 0x04, 0xF6,
		0xC1, 0x01, 0x0F, 0x84, 0x8A, 0x02, 0x00, 0x00 };
	if (model_check_bypass_info == nullptr)
		return NULL;
	*model_check_bypass_info = toggle ? patched : restore;
	return true;
}

void* m_OriginalGetEventData = nullptr;
void* blockmodelcrash1 = nullptr;
bool protect = false;


bool crashHook(unsigned int model, DWORD* a2)
{
	auto result = static_cast<decltype(&crashHook)>(blockmodelcrash1)(model, a2);

	if (Protections::Crasherzz) {
		
		if ((model == GAMEPLAY::GET_HASH_KEY("sold_large_quadpad") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Slod quadpad Skidded Menu", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("slod_human") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Slod Human Skidded Menu", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("a_c_hampback") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Whale", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("a_f_o_indian_01") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Indian", "Foxy", "Reborn"); }
		//if ((model == GAMEPLAY::GET_HASH_KEY("A_C_Humpback") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Humpback Impulse", "Foxy", "Reborn"); }
		//if ((model == GAMEPLAY::GET_HASH_KEY("A_C_Fish") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Fish", "Foxy", "Reborn"); }
		//if ((model == GAMEPLAY::GET_HASH_KEY("A_C_KillerWhale") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Orcas", "Foxy", "Reborn"); }
		//if ((model == GAMEPLAY::GET_HASH_KEY("A_C_SharkHammer") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Shark Hammer", "Foxy", "Reborn"); }
		//if ((model == GAMEPLAY::GET_HASH_KEY("A_C_Dolphin") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Dolphin Robust", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("A_C_Husky") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Ped Models Crash Husky Flame Menu", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("hei_hw1_06_road") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Map Models Crash Foxy Menu", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("dt1_tc_dufo_core") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Map Models Crash Foxy Menu", "Foxy", "Reborn"); }
		if ((model == GAMEPLAY::GET_HASH_KEY("dt1_lod_slod3") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) { NotificationCrash("Map Models Crash Foxy Menu", "Foxy", "Reborn"); }
		if ((model == 0xCE6FDD6B) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Pick Up Kick", "Foxy", "Reborn"); }
		if ((model == 0x113FD533) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Pick Up Kick", "Foxy", "Reborn"); }
		if ((model == 0xceea3f4b) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x2592b5cf) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x9cf21e0f) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc1ce1183) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x49863e9c) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xcd93a7db) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x82cac433) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x74f24de) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x1c725a1) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x81fb3ff0) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x79b41171) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x781e451d) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xa5e3d471) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x6a27feb1) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x861d914d) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x8c049d17) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xffba70aa) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xe65ec0e4) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc3c00861) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x5f5dd65c) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc07792d4) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x53cfe80a) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xd9f4474c) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xcb2acc8) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc6899cde) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xd14b5ba3) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x32a9996c) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x69d4f974) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc2e75a21) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x1075651) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xe1aeb708) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xcbbb6c39) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x6fa03a5e) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xcf7a9a9d) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x34315488) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x45ef7804) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xac3de147) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xcafc1ec3) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xd971bbae) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xe764d794) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xf51f7309) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x1e78c9d) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xa49658fc) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x4f2526da) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x576ab4f6) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xd20b1778) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x54bc1cd8) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xce109c5c) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xe049c0ce) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x78de93d1) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xe5b89d31) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x5850e7b3) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x6aed0e4b) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc50a4285) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xb648a502) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x5e497511) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x47c14801) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xfd8bb397) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xef541728) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc2cc99d8) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x8fb233a4) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x24e08e1f) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x337b2b54) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x7367d224) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x919d9255) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x4484243f) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x3c91d42d) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x3353525a) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xc175f658) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x762657c6) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x94ac15b3) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x28014a56) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xe0a8bfc9) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x3a559c31) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x5fc8a70) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0x3b545487) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xb9402f87) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash", "Foxy", "Reborn"); }
		if ((model == 0xFBF7D21F) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Foxy Menu", "Foxy", "Reborn"); }
		/*
		if ((model == 386259036) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 450174759) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 1567950121) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 1734157390) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 1759812941) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 2040219850) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 1727217687) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == -993438434) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == -990984874) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == -818431457) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == -681705050) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == -568850501) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 3301528862) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 3303982422) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 3476535839) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 3726116795) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == -1231365640) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 3041841304) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 762327283) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }
		if ((model == 1057201338) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Hares", "Foxy", "Reborn"); }*/
		//if ((model == crashed) || model == GAMEPLAY::GET_HASH_KEY("Player_Zero")) { NotificationCrash("Object Crash Stand Killer", "Foxy", "Reborn"); }

		//0x474FL747J
		// to add 0xFBF7D21F |
		//if ((model == GAMEPLAY::GET_HASH_KEY("Models To Add") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) {}
		//if ((model == GAMEPLAY::GET_HASH_KEY("This Is An Example") || model == GAMEPLAY::GET_HASH_KEY("Player_Zero"))) {}

		return false;
	}	
	return result;
}

bool RedirProc(int eventGroup, int eventIndex, int* argStruct, int argStructSize)
{


	auto result = static_cast<decltype(&RedirProc)>(m_OriginalGetEventData)(eventGroup, eventIndex, argStruct, argStructSize);

	
	if (result && Protections::Kick && argStruct[0] == 3968834430 | // ceo ban
		argStruct[0] == -333038531 | //Kicks
		argStruct[0] == -1153009121 |
		argStruct[0] == -867805069 |
		argStruct[0] == 1046017888 |
		argStruct[0] == -1998642710 |
		argStruct[0] == 106447194 |
		argStruct[0] == 519946261 |
		argStruct[0] == 163985506 |
		argStruct[0] == 873197495 |
		argStruct[0] == -906869562 |
		argStruct[0] == -741569622 |
		argStruct[0] == -1434746202 |
		argStruct[0] == -797746128 |
		argStruct[0] == 1658079306 |
		argStruct[0] == 290191363 |
		argStruct[0] == -615831251 |
		argStruct[0] == -1926987112 |
		argStruct[0] == 1404046700 |
		argStruct[0] == -612288019 |
		argStruct[0] == -1441300790 |
		argStruct[0] == -1290756689 |
		argStruct[0] == -370669082 |
		argStruct[0] == 1780075204 |
		argStruct[0] == -632266118 |
		argStruct[0] == 426145626 |
		argStruct[0] == -814250534 |
		argStruct[0] == 569454533 |
		argStruct[0] == -1010395481 |
		argStruct[0] == 925877602 |
		argStruct[0] == -1179957982 |
		argStruct[0] == 900146065 |
		argStruct[0] == 297770348 |
		argStruct[0] == -1297785021 |
		argStruct[0] == 143196100 |
		argStruct[0] == -1818550779 |
		argStruct[0] == 2037380969 |
		argStruct[0] == 1070706073 |
		argStruct[0] == -1933245257 |
		argStruct[0] == 380850754 |
		argStruct[0] == -1924332863 |
		argStruct[0] == -1704719905 |
		argStruct[0] == 709335341 |
		argStruct[0] == 1152017566 |
		argStruct[0] == 498709856 |
		argStruct[0] == 1667907776 |
		argStruct[0] == -985688171 |
		argStruct[0] == -2017629233 |
		argStruct[0] == -709335341 |
		argStruct[0] == -13389525 |
		argStruct[0] == -1297785021 |
		argStruct[0] == -173662905 |
		argStruct[0] == 314667560 |
		argStruct[0] == -1411930028 |
		argStruct[0] == -514046096 |
		argStruct[0] == 1432301416 |
		argStruct[0] == -1246838892 |
		argStruct[0] == -1924332863 |
		argStruct[0] == -1302989626 |
		argStruct[0] == 1091694297 |
		argStruct[0] == 380850754 |
		argStruct[0] == -1933245257 |
		argStruct[0] == 275033734 |
		argStruct[0] == 459263416 |
		argStruct[0] == 1381803144 |
		argStruct[0] == -1153009121 |
		argStruct[0] == 634715799 |
		argStruct[0] == -1179957982 |
		argStruct[0] == 930233414 |
		argStruct[0] == 1152017566 |
		argStruct[0] == -1704719905 |
		argStruct[0] == -1900102430 |
		argStruct[0] == 1070706073 |
		argStruct[0] == -1964956981 |
		argStruct[0] == -452918768 |
		argStruct[0] == 420531845 |
		argStruct[0] == 2037380969 |
		argStruct[0] == -1010395481 |
		argStruct[0] == -712526240 |
		argStruct[0] == 1826420594 |
		argStruct[0] == -1708373442 |
		argStruct[0] == -841066582 |
		argStruct[0] == 1417640596 |
		argStruct[0] == -2120750352 |
		argStruct[0] == 566035618 | // movecamnope
		argStruct[0] == -1049031463 | // moneynope
		argStruct[0] == 111286607 | // banner
		argStruct[0] == 252265430 | // insurance 1365267338nope
		argStruct[0] == -125347541 | // inf loading // updated
		argStruct[0] == -327286343 | // ceo ban // updated
		argStruct[0] == 400031869 | // kick
		argStruct[0] == -2066829834 | // mission
		argStruct[0] == -701823896 | // ceo kick // updated
		argStruct[0] == -175474624 |// invite nope
		argStruct[0] == 189238289 | // transactiopn error // updated
		argStruct[0] == -163616977 | // wanted // upated
		argStruct[0] == -1089379066 | // veh kick // updated
		argStruct[0] == 1663317123 | // insurance message // updated 552065831
		argStruct[0] == 552065831 | // sound spam 1 updated
		argStruct[0] == -1441342807 | // sound spam 2 updated //-1618821911 // noti
		argStruct[0] == -1618821911 |//kicks
		argStruct[0] == 1097312011 |//Sound 1 done
		argStruct[0] == -1162153263 |//Sound 2 done 
		argStruct[0] == -2029779863 |//CEO Money done
		argStruct[0] == -1662268941 |//Personal Veh Destroyed Done
		argStruct[0] == -116602735 |//Bounty Done
		argStruct[0] == 1302185744 |//Trans Fail
		argStruct[0] == 639032041 |//Banner Effect
		argStruct[0] == -1333236192 |//Kick From Personal Veh
		argStruct[0] == -1648921703 |//CEO kick
		argStruct[0] == -738295409 |//CEO Ban
		argStruct[0] == 1097312011 |//Invite
		argStruct[0] == -171207973 |//Apartement Invite
		argStruct[0] == -345371965 |//Kick
		argStruct[0] == 764638896 |//Kick
		argStruct[0] == -545396442 |//send to job  764638896, -345371965
		argStruct[0] == 1300962917 |// Cayo Perico 1300962917
		argStruct[0] == -1789621123 |//kick
		argStruct[0] == 1317868303 |//kick
		argStruct[0] == -338399516 |//kick
		argStruct[0] == -2055958901 |
		argStruct[0] == 140694538775554 |
		argStruct[0] == 2649994851330 |
		argStruct[0] == 140695655022592 |
		argStruct[0] == 140694538682368 |
		argStruct[0] == 140694538682368 |
		argStruct[0] == 2649994821632 |
		argStruct[0] == 133987706 |
		argStruct[0] == 503630554027 |
		argStruct[0] == 140695658062763 |
		argStruct[0] == 2649994821632 |
		argStruct[0] == 502511173632 |
		argStruct[0] == 2649994821632 |
		argStruct[0] == -1252906024 |
		argStruct[0] == 1120313136 |
			argStruct[0] == -1656474008 |
			argStruct[0] == -1147284669 |
			argStruct[0] == 1537221257 |
			argStruct[0] == -1813981910 |
			argStruct[0] == 639032041 |
			argStruct[0] == -1320260596 |
			argStruct[0] == 1427741376 |
			argStruct[0] == -272926713 |
			argStruct[0] == 1337820848 |
			argStruct[0] == 299217086 |
			argStruct[0] == -148441291 |
			argStruct[0] == 1187364773 |
			argStruct[0] == -151720011 |
			argStruct[0] == -397188359 |
			argStruct[0] == -81613951 |
			argStruct[0] == -2105858993 |
			argStruct[0] == 297912845 |
			argStruct[0] == 888578819 |
			argStruct[0] == -1002348481 |
			argStruct[0] == 1694315389 |
			argStruct[0] == 1337206479 |
			argStruct[0] == -1264708915 |
			argStruct[0] == -44054089 |
			argStruct[0] == 27493799 |
			argStruct[0] == 247151081 |
			argStruct[0] == 1385748752 |
			argStruct[0] == 1871141598 |
			argStruct[0] == 1069230108 |
			argStruct[0] == 1163167720 |
			argStruct[0] == 220852783 |
			argStruct[0] == -1857757712 |
			argStruct[0] == -989654618 |
			argStruct[0] == -1382676328 |
			argStruct[0] == 1256866538 |
			argStruct[0] == -1753084819 |
			argStruct[0] == 1119864805 |
			argStruct[0] == -1833002148 |
			argStruct[0] == 202252150 |
			argStruct[0] == -1503282114 |
			argStruct[0] == 243981125 |
			argStruct[0] == -1836118977 |
			argStruct[0] == -169685950 |
			argStruct[0] == -2071141142 |
			argStruct[0] == -149227625 |
			argStruct[0] == 1433396036 |
			argStruct[0] == 1608876738 |
			argStruct[0] == 458875017 |
			argStruct[0] == 987018372 |
			argStruct[0] == -1587276086 |
			argStruct[0] == 813647057 |

		//extreme protection by foxy 

		argStruct[0] == -1949011582 |
		argStruct[0] == 1244135940 |
		argStruct[0] == 931185764 |
		argStruct[0] == 880269514 |
		argStruct[0] == -184087091 |
		argStruct[0] == 1120313136 |
		argStruct[0] == -438498801 |
		argStruct[0] == -2135614041 |
		argStruct[0] == -2042143896 |
		argStruct[0] == 2017765964 |
		argStruct[0] == 1881968783 |
		argStruct[0] == 620255745 |
		argStruct[0] == -1054826273 |
		argStruct[0] == -190197401 |
		argStruct[0] == 37950012 |
		argStruct[0] == 1949047749 |
		argStruct[0] == 189426737 |
		argStruct[0] == 440451836 |
		argStruct[0] == -1551731308 |
		argStruct[0] == 1027640676 |
		argStruct[0] == -1858793976 |
		argStruct[0] == 1466961423 |
		argStruct[0] == 1919572202 |
		argStruct[0] == 1401831542 |
		argStruct[0] == -1999145131 |
		argStruct[0] == 402719724 |
		argStruct[0] == 1525180252 |
		argStruct[0] == -1756175141 |
		argStruct[0] == 1715510245 |
		argStruct[0] == -801305185 |
		argStruct[0] == 1097312011 |
		argStruct[0] == 1717331426 |
		argStruct[0] == 1073357477 |
		argStruct[0] == 468940571 |
		argStruct[0] == 495824472 |
		argStruct[0] == -2033338628 |
		argStruct[0] == -962064463 |
		argStruct[0] == 931219308 |
		argStruct[0] == -1730227041 |
		argStruct[0] == 501406112 |
		argStruct[0] == -1042174840 |
		argStruct[0] == 314706334 |
		argStruct[0] == 1977655521 |
		argStruct[0] == -2122716210 |
		argStruct[0] == -1333236192 |
		argStruct[0] == -620075057 |
		argStruct[0] == -1542610935 |
		argStruct[0] == 1967155575 |
		argStruct[0] == 74423716 |
		argStruct[0] == -961190199 |
		argStruct[0] == -505351260 |
		argStruct[0] == 1217352219 |
		argStruct[0] == 877700249 |
		argStruct[0] == 639032041 |
		argStruct[0] == -1243454584 |
		argStruct[0] == -1243454584 |
		argStruct[0] == -116602735 |
		argStruct[0] == 2058632186 |
		argStruct[0] == 891272013 |
		argStruct[0] == 393068387 |
		argStruct[0] == 1140870402 |
		argStruct[0] == 1101235920 |
		argStruct[0] == -442306200 |
		argStruct[0] == -345371965 |
		argStruct[0] == -1379398115 |
		argStruct[0] == 575518757 |
		argStruct[0] == 889825697 |
		argStruct[0] == 764638896 |
		argStruct[0] == 1260307946 |
		argStruct[0] == 1430093873 |
		argStruct[0] == 550741583 |
		argStruct[0] == 858406863 |
		argStruct[0] == 1870047677 |
		argStruct[0] == -1249091994 |
		argStruct[0] == -49604647 |
		argStruct[0] == -338445752 |
		argStruct[0] == 1302185744 |
		argStruct[0] == -1975590661 |
		argStruct[0] == -922075519 |
		argStruct[0] == -1437574346 |
		argStruct[0] == -228458318 |
		argStruct[0] == 2131576964 |
		argStruct[0] == 177832320 |
		argStruct[0] == 1400694109 |
		argStruct[0] == 1166120552 |
		argStruct[0] == 145559396 |
		argStruct[0] == -2080461139 |
		argStruct[0] == 1070934291 |
		argStruct[0] == -1491386500 |
		argStruct[0] == 489321898 |
		argStruct[0] == -1633299070 |
		argStruct[0] == -638863591 |
		argStruct[0] == 405611573 |
		argStruct[0] == -547753294 |
		argStruct[0] == 40168385 |
		argStruct[0] == -1678014630 |
		argStruct[0] == 416104391 |
		argStruct[0] == 710791216 |
		argStruct[0] == -253630609 |
		argStruct[0] == -730739328 |
		argStruct[0] == -1657159979 |
		argStruct[0] == 1570956502 |
		argStruct[0] == -1705723814 |
		argStruct[0] == -1595515659 |
		argStruct[0] == 261991583 |
		argStruct[0] == -775470665 |
		argStruct[0] == -1698341613 |
		argStruct[0] == 714506292 |
		argStruct[0] == 1376408207 |
		argStruct[0] == 2142017165 |
		argStruct[0] == -1336925360 |
		argStruct[0] == 126014646 |
		argStruct[0] == -1290202385 |
		argStruct[0] == -402069102 |
		argStruct[0] == 2053227459 |
		argStruct[0] == -1372360252 |
		argStruct[0] == 1006436615 |
		argStruct[0] == 547957431 |
		argStruct[0] == 809657238 |
		argStruct[0] == -415666077 |
		argStruct[0] == 1188873208 |
		argStruct[0] == -1549630786 |
		argStruct[0] == 1060402116 |
		argStruct[0] == -504482199 |
		argStruct[0] == 89278042 |
		argStruct[0] == 1118933262 |
		argStruct[0] == -1990292823 |
		argStruct[0] == 1352706024 |
		argStruct[0] == 348119077 |
		argStruct[0] == 1240791382 |
		argStruct[0] == -948169674 |
		argStruct[0] == 2133081418 |
		argStruct[0] == -262341369 |
		argStruct[0] == 1000457834 |
		argStruct[0] == -375398087 |
		argStruct[0] == -1329008922 |
		argStruct[0] == 1841943281 |
		argStruct[0] == -852503405 |
		argStruct[0] == 925173178 |
		argStruct[0] == -1989372325 |
		argStruct[0] == 1303708261 |
		argStruct[0] == -1911813629 |
		argStruct[0] == 2098987581 |
		argStruct[0] == -865197423 |
		argStruct[0] == -1825953974 |
		argStruct[0] == -921073084 |
		argStruct[0] == 156856405 |
		argStruct[0] == -2060629306 |
		argStruct[0] == 262768112 |
		argStruct[0] == 421494533 |
		argStruct[0] == 1755988437 |
		argStruct[0] == -1493184845 |
		argStruct[0] == -1657017550 |
		argStruct[0] == -577286683 |
		argStruct[0] == 465570678 |
		argStruct[0] == -1632172694 |
		argStruct[0] == 1972484238 |
		argStruct[0] == 14345383 |
		argStruct[0] == 743968101 |
		argStruct[0] == 599029146 |
		argStruct[0] == 962465625 |
		argStruct[0] == 960916034 |
		argStruct[0] == -1459006650 |
		argStruct[0] == 778805747 |
		argStruct[0] == -1580390976 |
		argStruct[0] == 823645419 |
		argStruct[0] == -2065346036 |
		argStruct[0] == 1213808185 |
		argStruct[0] == 67004146 |
		argStruct[0] == 582648726 |
		argStruct[0] == -1031098030 |
		argStruct[0] == -1295633605 |
		argStruct[0] == 614999494 |
		argStruct[0] == -791577348 |
		argStruct[0] == 1294893057 |
		argStruct[0] == -171207973 |
		argStruct[0] == -568266702 |
		argStruct[0] == 1212829040 |
		argStruct[0] == 1345577858 |
		argStruct[0] == 767605081 |
		argStruct[0] == -977515445 |
		argStruct[0] == -365271546 |
		argStruct[0] == -455354067 |
		argStruct[0] == -1174459121 |
		argStruct[0] == 1096684293 |
		argStruct[0] == -1497250740 |
		argStruct[0] == -911939009 |
		argStruct[0] == 1347850743 |
		argStruct[0] == -920663435 |
		argStruct[0] == -1057419833 |
		argStruct[0] == -1596113101 |
		argStruct[0] == -1759105725 |
		argStruct[0] == -1336932351 |
		argStruct[0] == -1648921703 |
		argStruct[0] == -1437387234 |
		argStruct[0] == 2062282408 |
		argStruct[0] == 1692477431 |
		argStruct[0] == 1553508941 |
		argStruct[0] == 699592812 |
		argStruct[0] == 1417613287 |
		argStruct[0] == -2029779863 |
		argStruct[0] == 1596100569 |
		argStruct[0] == 392501634 |
		argStruct[0] == -909357184 |
		argStruct[0] == -1442614028 |
		argStruct[0] == 171064260 |
		argStruct[0] == -152440739 |
		argStruct[0] == -1353116588 |
		argStruct[0] == 835608275 |
		argStruct[0] == 1307476082 |
		argStruct[0] == -345908092 |
		argStruct[0] == 1365604007 |
		argStruct[0] == 1280085963 |
		argStruct[0] == -612371672 |
		argStruct[0] == -1488631377 |
		argStruct[0] == -1720012585 |
		argStruct[0] == -2042475657 |
		argStruct[0] == -240257097 |
		argStruct[0] == 1240585650 |
		argStruct[0] == 1192658057 |
		argStruct[0] == 243540311 |
		argStruct[0] == 1191422458 |
		argStruct[0] == -627821011 |
		argStruct[0] == 1129105265 |
		argStruct[0] == 1767220965 |
		argStruct[0] == 1664114676 |
		argStruct[0] == -1032273438 |
		argStruct[0] == 1665678974 |
		argStruct[0] == -1544167759 |
		argStruct[0] == -87967637 |
		argStruct[0] == -891346918 |
		argStruct[0] == -1729804184 |
		argStruct[0] == -1882923979 |
		argStruct[0] == 793694002 |
		argStruct[0] == -158787995 |
		argStruct[0] == 1620254541 |
		argStruct[0] == 1428412924 |
		argStruct[0] == -1713165973 |
		argStruct[0] == -1212832151 |
		argStruct[0] == 87315576 |
		argStruct[0] == 635120817 |
		argStruct[0] == 275957394 |
		argStruct[0] == -707133706 |
		argStruct[0] == 1623717033 |
		argStruct[0] == 420011712 |
		argStruct[0] == -738295409 |
		argStruct[0] == 1665839162 |
		argStruct[0] == -131274930 |
		argStruct[0] == 150294028 |
		argStruct[0] == 992970225 |
		argStruct[0] == -551637263 |
		argStruct[0] == 603010792 |
		argStruct[0] == -813003734 |
		argStruct[0] == 584503478 |
		argStruct[0] == -355297939 |
		argStruct[0] == -1789621123 |
		argStruct[0] == -338399516 |
		argStruct[0] == 1317868303 |
		argStruct[0] == 1119498954 |
		argStruct[0] == 1974064500 |
		argStruct[0] == 1699621593 |
		argStruct[0] == 1300962917 |
		argStruct[0] == 1410801811 |
		argStruct[0] == -647202696 |
		argStruct[0] == -966559987 |
		argStruct[0] == 1509139352 |
		argStruct[0] == 1437305856 |
		argStruct[0] == -1564435822 |
		argStruct[0] == 765000166 |
		argStruct[0] == 2099816323 |
		argStruct[0] == 1310197925 |
		argStruct[0] == -542139175 |
		argStruct[0] == 511933636 |
		argStruct[0] == 127054992 |
		argStruct[0] == 741525574 |
		argStruct[0] == 473998728 |
		argStruct[0] == 1642731136 |
		argStruct[0] == 2026253606 |
		argStruct[0] == -1245024507 |
		argStruct[0] == 1394622857 |
		argStruct[0] == 814210644 |
		argStruct[0] == 356369059 |
		argStruct[0] == -1185075112 |
		argStruct[0] == 1996378932 |
		argStruct[0] == -743046526 |
		argStruct[0] == -1014199946 |
		argStruct[0] == 474621183 |
		argStruct[0] == 1901047756 |
		argStruct[0] == 1644907640 |
		argStruct[0] == -1840682990 |
		argStruct[0] == 1843603007 |
		argStruct[0] == 483883516 |
		argStruct[0] == -1191687050 |
		argStruct[0] == 733106126 |
		argStruct[0] == 417206566 |
		argStruct[0] == -962439346 |
		argStruct[0] == -545396442 |
		argStruct[0] == 53977718 |
		argStruct[0] == 830707189 |
		argStruct[0] == 1198154717 |
		argStruct[0] == -1890951223 |
		argStruct[0] == -1252906024 |
		argStruct[0] == -1559754940 |
		argStruct[0] == 665709549 |
		argStruct[0] == 1922258436 |
		argStruct[0] == -435067392 |
		argStruct[0] == 324865135 |
		argStruct[0] == 331283186 |
		argStruct[0] == -363435150 |
		argStruct[0] == 1325156823 |
		argStruct[0] == 1483710319 |
		argStruct[0] == -496432604 |
		argStruct[0] == -727492889 |
		argStruct[0] == 194342417 |
		argStruct[0] == -1406618481 |
		argStruct[0] == -1879618040 |
		argStruct[0] == -1080429176 |
		argStruct[0] == -416183945 |
		argStruct[0] == -1455659794 |

			//1.57
			argStruct[0] == 1723452001 |
			argStruct[0] == 210491663 |
			argStruct[0] == -1780858740 |
			argStruct[0] == 277548576 |
			argStruct[0] == -132026059 |
			argStruct[0] == -851196171 |
			argStruct[0] == 1293299354 |
			argStruct[0] == 903362384 |
			argStruct[0] == 243981125 |
			argStruct[0] == 1848973789 |
			argStruct[0] == -1503282114 |
			argStruct[0] == 202252150 |
			argStruct[0] == -189552513 |
			argStruct[0] == -1896924387 |
			argStruct[0] == 1491104200 |
			argStruct[0] == 1150803197 |
			argStruct[0] == 1808453742 |
			argStruct[0] == 75217734 |
			argStruct[0] == -1648825077 |
			argStruct[0] == 597922279 |
			argStruct[0] == -1016027275 |
			argStruct[0] == 890117219 |
			argStruct[0] == -635501849 |
			argStruct[0] == -1521203907 |
			argStruct[0] == -675325833 |
			argStruct[0] == 1846223309 |
			argStruct[0] == 1472117290 |
			argStruct[0] == -1054422861 |
			argStruct[0] == -73352157 |
			argStruct[0] == -78017695 |
			argStruct[0] == 2018643992 |
			argStruct[0] == -352859634 |
			argStruct[0] == 1370240360 |

			argStruct[0] == 62705223 |

			argStruct[0] == -2000489950 |

			argStruct[0] == 214030117 |

			argStruct[0] == 1926582096 |

			argStruct[0] == -1830143324 |

			argStruct[0] == -279342915 |

			argStruct[0] == 690534430 |

			argStruct[0] == -1833002148 |

			argStruct[0] == -1005623606 |

			argStruct[0] == -2022389047 |

			argStruct[0] == 1618779170 |

			argStruct[0] == -53130764 |

			argStruct[0] == -1301508763 |

			argStruct[0] == -1413680798 |

			argStruct[0] == -1026386029 |

			argStruct[0] == 273726443 |

			argStruct[0] == 1659915470 |

			argStruct[0] == 575344561 |

			argStruct[0] == -1906146218 |

			argStruct[0] == 829201205 |

			argStruct[0] == 1358851648 |

			argStruct[0] == -859672259 |

			argStruct[0] == -1753084819 |

			argStruct[0] == -1500178943 |

			argStruct[0] == -863176541 |

			argStruct[0] == -397188359 |

			argStruct[0] == 1595854775 |

			argStruct[0] == 1933105669 |

			argStruct[0] == 624184651 |

			argStruct[0] == -1520160200 |

			argStruct[0] == -1005294040 |

			argStruct[0] == -1989758836 |

			argStruct[0] == -211878773 |

			argStruct[0] == -1318777899 |

			argStruct[0] == -178721456 |

			argStruct[0] == -325138340 |

			argStruct[0] == -1881357102 |



			argStruct[0] == 701013663 |



			argStruct[0] == -903212623 |

			argStruct[0] == 1816012469 |



			argStruct[0] == -1587276086 |

			argStruct[0] == 1649958326 |

			argStruct[0] == 578058101 |

			argStruct[0] == -515495966 |

			argStruct[0] == -1235041639 |

			argStruct[0] == -396894108 |

			argStruct[0] == -1023783113 |

			argStruct[0] == 1679855368 |

			argStruct[0] == 1863892872 |

			argStruct[0] == -1208850730 |

			argStruct[0] == -302187166 |

			argStruct[0] == -1656474008 |

			argStruct[0] == 1230210137 |

			argStruct[0] == -1448333980 |

			argStruct[0] == -1074756845 |

			argStruct[0] == 1229338575 |

			argStruct[0] == -505735987 |

			argStruct[0] == 1257857900 |

			argStruct[0] == -1900695287 |

			argStruct[0] == -16213980 |

			argStruct[0] == 59352546 |

			argStruct[0] == 1795076373 |

			argStruct[0] == 134867878 |

			argStruct[0] == -1145943081 |

			argStruct[0] == -2076396337 |

			argStruct[0] == 1950208850 |

			argStruct[0] == -2103999464 |

			argStruct[0] == -1016625751 |

			argStruct[0] == -1095711893 |

			argStruct[0] == -971907474 |

			argStruct[0] == -1566668579 |

			argStruct[0] == 1713679709 |

			argStruct[0] == -2100809716 |

			argStruct[0] == 1033875141 |

			argStruct[0] == 45192266 |

			argStruct[0] == 1864582447 |

			argStruct[0] == -2014392362 |

			argStruct[0] == 808437855 |

			argStruct[0] == 447050477 |

			argStruct[0] == -1157285407 |

			argStruct[0] == -959790325 |

			argStruct[0] == -1717096076 |

			argStruct[0] == 1954846099 |

			argStruct[0] == 1964309656 |

			argStruct[0] == 1006166687 |

			argStruct[0] == -65296432 |

			argStruct[0] == -911081209 |

			argStruct[0] == 168919469 |

			argStruct[0] == 932894951 |

			argStruct[0] == -37068802 |

			argStruct[0] == 226676030 |

			argStruct[0] == -1773075874 |

			argStruct[0] == -1927914708 |

			argStruct[0] == -1945247369 |

			argStruct[0] == -46298284 |

			argStruct[0] == -1705137662 |

			argStruct[0] == -1842341008 |

			argStruct[0] == 212052693 |

			argStruct[0] == -1705411017 |

			argStruct[0] == -933507377 |

			argStruct[0] == -257834583 |

			argStruct[0] == -588744584 |

			argStruct[0] == 1186109081 |

			argStruct[0] == -639979452 |

			argStruct[0] == 2120864071 |

			argStruct[0] == 959824647 |

			argStruct[0] == 2005618868 |

			argStruct[0] == -868839127 |

			argStruct[0] == 1800830029 |

			argStruct[0] == -1825938840 |

			argStruct[0] == -1533887418 |

			argStruct[0] == 1643877404 |

			argStruct[0] == 712678541 |

			argStruct[0] == -2017818728 |

			argStruct[0] == 1266208560 |

			argStruct[0] == -1529925410 |

			argStruct[0] == 987018372 |

			argStruct[0] == -1891495479 |

			argStruct[0] == -1959541747 |

			argStruct[0] == -1870308609 |

			argStruct[0] == -1785748887 |

			argStruct[0] == 458875017 |

			argStruct[0] == 27785517 |

			argStruct[0] == 662343702 |

			argStruct[0] == -978812630 |

			argStruct[0] == 1990909018 |

			argStruct[0] == -1484351810 |

			argStruct[0] == -1372589624 |

			argStruct[0] == 1210543720 |

			argStruct[0] == 1764386440 |

			argStruct[0] == -1190123899 |

			argStruct[0] == 384219567 |

			argStruct[0] == -810334939 |

			argStruct[0] == -1187407749 |

			argStruct[0] == 254526911 |

			argStruct[0] == -1924022050 |

			argStruct[0] == -979549154 |

			argStruct[0] == -544908807 |

			argStruct[0] == 675377079 |

			argStruct[0] == 678368510 |

			argStruct[0] == 2108029684 |

			argStruct[0] == 399742549 |

			argStruct[0] == 1622386523 |

			argStruct[0] == -1999269016 |

			argStruct[0] == -126133365 |

			argStruct[0] == -1639153173 |

			argStruct[0] == 1384138535 |

			argStruct[0] == -1794395648 |

			argStruct[0] == 1734770887 |

			argStruct[0] == -1649341354 |

			argStruct[0] == -1819246032 |

			argStruct[0] == -733604274 |

			argStruct[0] == -275229102 |

			argStruct[0] == 541344683 |

			argStruct[0] == -487303944 |

			argStruct[0] == 1735852781 |

			argStruct[0] == 241570528 |

			argStruct[0] == -654645351 |

			argStruct[0] == 486186480 |

			argStruct[0] == 1341149498 |

			argStruct[0] == 600486780 |

			argStruct[0] == 174461233 |

			argStruct[0] == -888636441 |

			argStruct[0] == -1532157118 |

			argStruct[0] == 1296795403 |

			argStruct[0] == 33277241 |

			argStruct[0] == 2120839242 |

			argStruct[0] == 1154988013 |

			argStruct[0] == 1209918357 |

			argStruct[0] == 1763836227 |

			argStruct[0] == -283884309 |

			argStruct[0] == 1287299127 |

			argStruct[0] == 493604397 |

			argStruct[0] == -988842806 |

			argStruct[0] == 1146815758 |

			argStruct[0] == 1519476362 |

			argStruct[0] == 1136772712 |

			argStruct[0] == -1723675897 |

			argStruct[0] == -390491000 |

			argStruct[0] == 23010443 |

			argStruct[0] == 641157117 |

			argStruct[0] == 1608876738 |

			argStruct[0] == -79150418 |

			argStruct[0] == 257478565 |

			argStruct[0] == 496476216 |

			argStruct[0] == 608132931 |

			argStruct[0] == -25619296 |

			argStruct[0] == -176858990 |

			argStruct[0] == -1605274399 |

			argStruct[0] == 1731962870 |

			argStruct[0] == -1277389265 |

			argStruct[0] == -181124995 |

			argStruct[0] == -1855721397 |

			argStruct[0] == 1472357458 |

			argStruct[0] == 665468344 |

			argStruct[0] == -212308547 |

			argStruct[0] == 975723848 |

			argStruct[0] == -720653448 |

			argStruct[0] == 900985860 |

			argStruct[0] == 200339862 |

			argStruct[0] == -95026574 |

			argStruct[0] == 2049240389 |

			argStruct[0] == 917535648 |

			argStruct[0] == 1517002797 |

			argStruct[0] == 1126437067 |

			argStruct[0] == -421711998 |

			argStruct[0] == 1164760553 |

			argStruct[0] == -1428764848 |

			argStruct[0] == 161038699 |

			argStruct[0] == -137439024 |

			argStruct[0] == 997078653 |

			argStruct[0] == -384079069 |

			argStruct[0] == -1514001560 |

			argStruct[0] == -347755611 |

			argStruct[0] == 1767220965 |

			argStruct[0] == 2051313650 |

			argStruct[0] == -1489802466 |

			argStruct[0] == -247110509 |

			argStruct[0] == 469112443 |

			argStruct[0] == -149227625 |

			argStruct[0] == 316678593 |

			argStruct[0] == -1918817181 |

			argStruct[0] == 282406360 |

			argStruct[0] == 1433396036 |

			argStruct[0] == 696123127 |

			argStruct[0] == 770242759 |

			argStruct[0] == -796052439 |

			argStruct[0] == -19131151 |

			argStruct[0] == -169685950 |

			argStruct[0] == 1134927454 |

			argStruct[0] == 515799090 |

			argStruct[0] == 1132500638 |

			argStruct[0] == 1216017047 |

			argStruct[0] == 1836414206 |

			argStruct[0] == 490383602 |

			argStruct[0] == 1455421717 |

			argStruct[0] == -795567983 |
			argStruct[0] == -341234598 |
			argStruct[0] == -525866785 |
			argStruct[0] == -419415284 |
			argStruct[0] == -1857108105 |
			argStruct[0] == -662216118 |
			argStruct[0] == 1098534904 |
			argStruct[0] == 649952111 |
			argStruct[0] == 1923828310 |
			argStruct[0] == 795867332 |
			argStruct[0] == 1305720168 |
			argStruct[0] == -1561004591 |
			argStruct[0] == 1463355688 |
			argStruct[0] == -2071141142 |
			argStruct[0] == 251577675 |
			argStruct[0] == -1836118977 |
			argStruct[0] == 1788162956 |
			argStruct[0] == -1479371259 |
			argStruct[0] == -1136752511 |
			argStruct[0] == -428995778 |
			argStruct[0] == 1119864805 |
			argStruct[0] == -699380547 |
			argStruct[0] == 1376436345 |
			argStruct[0] == 677429013 |
			argStruct[0] == -1758368969 |
			argStruct[0] == 1173618358 |
			argStruct[0] == -898207315 |
			argStruct[0] == 1287903621 |
			argStruct[0] == -1625031686 |
			argStruct[0] == 1873289193 |
			argStruct[0] == 1268963570 |
			argStruct[0] == -767611756 |
			argStruct[0] == -275700180 |
			argStruct[0] == 797978700 |
			argStruct[0] == -194543830 |
			argStruct[0] == -2063448951 |
			argStruct[0] == -299840140 |
			argStruct[0] == -504114839 |
			argStruct[0] == 1197757671 |
			argStruct[0] == 1490942189 |
			argStruct[0] == 1797631140 |
			argStruct[0] == 951147709 |
			argStruct[0] == -609583028 |
			argStruct[0] == 1824446546 |
			argStruct[0] == -771079131 |
			argStruct[0] == -1511043020 |
			argStruct[0] == -768666112 |
			argStruct[0] == 1298961960 |
			argStruct[0] == -760171613 |
			argStruct[0] == 43922647 |
			argStruct[0] == -1911026003 |
			argStruct[0] == 15745542 |
			argStruct[0] == -1147284669 |
			argStruct[0] == -299200920 |
			argStruct[0] == -2072214082 |
			argStruct[0] == -1568036440 |
			argStruct[0] == 1256866538 |
			argStruct[0] == -1382676328 |
			argStruct[0] == -1813981910 |
			argStruct[0] == -845729485 |
			argStruct[0] == -892744477 |
			argStruct[0] == -1722256522 |
			argStruct[0] == -114483526 |
			argStruct[0] == -171077681 |
			argStruct[0] == 38189494 |
			argStruct[0] == -2086228364 |
			argStruct[0] == -1727818500 |
			argStruct[0] == -655898431 |
			argStruct[0] == 1889984715 |
			argStruct[0] == 1166958622 |
			argStruct[0] == -1912844061 |
			argStruct[0] == 897248694 |



			//1.57 known tse
			argStruct[0] == 1764386440 | // give wanted
			argStruct[0] == 597922279 |// kick from vehicle
			argStruct[0] ==  1152266822 |// bounty
			argStruct[0] == -2041535807 | //appart
			argStruct[0] == 2092565704 | // kick
			//CEO-Kick
			argStruct[0] == -316948135 |

		//CEO-Ban
			argStruct[0] == 1355230914 |

	

		//Teleport To Island (Invite)
			argStruct[0] == -1479371259 |


		//Send To Mission 1
			argStruct[0] == -1147284669 |


		//Send To Mission 2 [Longer]
			argStruct[0] == 1249026189 | 


// nova crash event 

argStruct[0] == -72614 |
argStruct[0] == 63007 |
argStruct[0] == 59027 |
argStruct[0] == -12012 |
argStruct[0] == -26996 |
argStruct[0] == 33398 |
argStruct[0] == -33398 |
argStruct[0] == -1320260596 |
argStruct[0] == -65534 |
argStruct[0] == -1330780407 |
argStruct[0] == 479 |
argStruct[0] == 65534 |
argStruct[0] == 2147483647 |
argStruct[0] == -2147483647 |
argStruct[0] == -989654618 |
argStruct[0] == -1881357102 |
argStruct[0] == 1033875141 |
argStruct[0] == -601625146 |
argStruct[0] == -989654618 |
argStruct[0] == -1881357102 |
argStruct[0] == 1033875141 |
argStruct[0] == -601625146 |
argStruct[0] == -989654618 |
argStruct[0] == -1881357102 |
argStruct[0] == 1033875141 |
argStruct[0] == -601625146 |
argStruct[0] == -989654618 |
argStruct[0] == -1881357102 |
argStruct[0] == 1033875141 |
argStruct[0] == -877212109 |
argStruct[0] == -601625146 |
argStruct[0] == 868904806 |
argStruct[0] == 262276366 |
argStruct[0] == -747991709 |
argStruct[0] == 1545080914 |
argStruct[0] == -51510646 |
argStruct[0] == 1790326295 |
argStruct[0] == 389113600 |
argStruct[0] == -617567498 |
argStruct[0] == -601391132 |
argStruct[0] == -564503258 |
argStruct[0] == -601625146 |
argStruct[0] == -989654618 |
argStruct[0] == -1881357102 |
argStruct[0] == 1033875141 |
argStruct[0] == -601625146 |
argStruct[0] == -2043109205 |
argStruct[0] == -989654618 |
argStruct[0] == -1881357102 |
argStruct[0] == 153488394 |
argStruct[0] == 1033875141 |
argStruct[0] == 315658550 |

argStruct[0] == -353458099 | //1.67 KICK_TO_SP=
argStruct[0] == -1101672680 | //1.67 KICK_TO_SP2
argStruct[0] == -337848027 | //1.67 CEO_MONEY
argStruct[0] == -330501227 | //1.67 GTA_BANNER
argStruct[0] == 1517551547 | //1.67 BOUNTY
argStruct[0] ==  1655503526 | //1.67 PERSONAL_VEHICLE
argStruct[0] == -1704545346 | //1.67 REMOVE_WANTED_LEVEL
argStruct[0] ==  57493695 | //1.67 REMOTE_OFF_THE_RADAR
argStruct[0] == -1321657966 | // 1.67 ECLIPSETELEPORT
argStruct[0] == 373376135 | //1.67 SEND_TO_CAYO
argStruct[0] == -1604421397 | //1.6 7SE_CRASH_1
argStruct[0] == -375628860 | //1.6 7CRASH_2
argStruct[0] == 1103127469 | //1.67 TSE_CRASH
argStruct[0] == 323285304 | //1.67 TSE_CRASH_3
argStruct[0] == 1655503526 | //1.67 PERSONAL_VEH_DESTROYED
argStruct[0] == 109434679 | //1.67 PERSONAL_VEH_DESTROYED2
argStruct[0] == -901348601 | //1.67 NETWORK_BAIL
argStruct[0] == 259469385 | //1.67 FORCE_INTO_MISSION
argStruct[0] == 1186559054 | //1.67 FORCE_INTO_MISSION2
argStruct[0] == -305178342 | //1.67 REMOTE_OFF_RADAR
argStruct[0] == -1951335381 | //1.67 SEND_INTO_CUTSCENE
argStruct[0] == 1669592503 | //1.67 SEND_TO_LOCATION
argStruct[0] == 968269233 | //1.67 GIVE_COLLECTIBLES
argStruct[0] == 996099702 | //1.67 SOUND_SPAM
argStruct[0] == 1840946429 | //1.67 SPECTATE
argStruct[0] == 610587469 | //1.67 CEO_BAN
argStruct[0] == 234399205 | //1.67 CEO_KICK
argStruct[0] == -1253241415 | //1.67 WAREHOUSE_TELEPORT
argStruct[0] == -830063381 | //1.67 TRANSACTION_ERROR
argStruct[0] == -503325966 | //1.67 VEHICLE_KICK
argStruct[0] == 1450115979 | //1.67 START_ACTIVITY
argStruct[0] == -1541764116 | //1.67 INTERIOR_KICK
argStruct[0] == -1638522928 | //1.67 INTERIOR_CONTROL
argStruct[0] == -1013606569 | //1.67 SEND_SMS
argStruct[0] == -1906536929 | //1.67 CEO_RAID
argStruct[0] == 94410750 | //1.67 NOTIFY_BANK_STOLEN
argStruct[0] == -295926414 | //1.67 NOTIFY_MONEY_STOLEN
argStruct[0] == -242911964 | //1.67 NOTIFY_MONEY_REMOVED
		argStruct[0] == 140694538682368 )
	{

	if (argStruct[0] == -1330780407)
	{
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Crash TSE Nova User~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}

	if (argStruct[0] == -353458099) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Kick~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1101672680) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Kick~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -337848027) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: CEO Money~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -330501227) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Gta Banner_BANNER~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1517551547) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Bounty~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1655503526) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Personal Vehicle~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1704545346) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Remove Wanted Level~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] ==  57493695) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Off Radar~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1321657966) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Teleport~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 373376135) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Cayo Perico~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1604421397) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Crash~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -375628860) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Crash~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1103127469) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Crash~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 323285304) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Crash~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1655503526) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Destroy Vehicle~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 109434679) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Destroy Vehicle~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -901348601) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Kick~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 259469385) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Teleport Mission~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1186559054) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Teleport Mission~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -305178342) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Off Radar~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1951335381) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Cutscene*~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1669592503) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Teleport~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 968269233) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Give Collectibles~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 996099702) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Sound~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1840946429) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Spectate~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 610587469) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Ceo Ban~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 234399205) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Ceo Kick*~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1253241415) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Teleport WhareHouse~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -830063381) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Transaction Error~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -503325966) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Vehicle Kick*~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 1450115979) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Start An Activity~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1541764116) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Interior Kick~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1638522928) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Interior Control~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1013606569) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: SMS~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -1906536929) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: CEO Raid~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == 94410750) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Notification Money~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -295926414) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Notification Money~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
	if (argStruct[0] == -242911964) {
		char buf1[30];
		char sender[30];

		unsigned int Bit = (1 << argStruct[1]);
		char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
		char buf4[255];
		sprintf(buf4, "Status: Blocked~n~"
			"Event: Notification Money~n~"
			"Sender: %s~n~", Name);
		notifyMap(buf4);

	}
		if (argStruct[0] == 498709856)//-1330780407
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -333038531)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1153009121)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -867805069)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1998642710)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 106447194)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}


		if (argStruct[0] == 519946261)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 163985506)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 873197495)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 873197495)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -906869562)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -741569622)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1434746202)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -797746128)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1658079306)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 290191363)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -615831251)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -615831251)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1926987112)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1404046700)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 612288019)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1441300790)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1290756689)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1290756689)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -370669082)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1780075204)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -632266118)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -632266118)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 426145626)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 426145626)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -814250534)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 569454533)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1010395481)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 925877602)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1179957982)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 900146065)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 297770348)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1297785021)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 143196100)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1818550779)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 2037380969)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1070706073)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}


		if (argStruct[0] == -1933245257)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 380850754)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1924332863)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1704719905)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 709335341)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1152017566)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 709335341)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1152017566)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 498709856)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1667907776)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -985688171)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -2017629233)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -709335341)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -13389525)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1297785021)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -173662905)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 314667560)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1411930028)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -514046096)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1432301416)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1246838892)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1924332863)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1246838892)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1924332863)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1924332863)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1924332863)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1302989626)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1091694297)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 380850754)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1933245257)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 275033734)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 459263416)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1381803144)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1153009121)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 634715799)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1179957982)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 930233414)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1152017566)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1704719905)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1900102430)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1070706073)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1964956981)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -452918768)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 420531845)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 2037380969)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1010395481)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -712526240)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1826420594)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1708373442)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -841066582)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1417640596)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -2120750352)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 566035618)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Cam Stuff~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 566035618)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Cam Stuff~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1049031463)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Money Spam~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 111286607)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Banner~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 252265430)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Insurance~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 252265430)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Infinite Loading~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -125347541)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Infinite Loading~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -327286343)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Infinite Loading~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -327286343)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Ceo Ban~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -327286343)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Ceo Ban~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 400031869)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -2066829834)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -701823896)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -2066829834)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Mission~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -701823896)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Ceo Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -175474624)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Invite~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -189238289)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Transaction~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -163616977)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Wanted~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1089379066)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Vehicle Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1089379066)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Vehicle Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1663317123)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Insurance~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 1663317123)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Insurance~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == 552065831)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Sound Spam~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1441342807)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Sound Spam~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1618821911)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -2055958901)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}
		if (argStruct[0] == 1097312011)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Sound~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		if (argStruct[0] == -1162153263)//
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Error Message~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}
		if (argStruct[0] == -2029779863)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: CEOMONEY~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}
		if (argStruct[0] == -1662268941)//
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: DELETE MONEY~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}
		if (argStruct[0] == -116602735)//
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Bounty~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}
		if (argStruct[0] == -1333236192)//
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Veh Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -1648921703)//
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: CEO Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -738295409)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: CEO Ban~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 1097312011)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Remote Invite~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 1302185744)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Transaction Fail~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 639032041)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Banner Effect~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -171207973)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Skid Apart Invite~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -345371965)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 764638896)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -545396442)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Send To Job~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 1300962917)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Send To Cayo P~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -1789621123)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 1317868303)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -338399516)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -2055958901)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 140694538775554)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 2649994851330)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 140694538775554)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 133987706)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 503630554027)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 140695658062763)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 502511173632)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 2649994821632)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == 140694538682368)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);


		}
		if (argStruct[0] == -1252906024)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Mystrix Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}
		if (argStruct[0] == 1120313136)
		{
			char buf1[30];
			char sender[30];

			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Reset Cam~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);

		}

		//extremeprotection by foxy 


		if (argStruct[0] == -1949011582)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1244135940)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 931185764)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 880269514)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -184087091)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1120313136)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -438498801)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2135614041)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2042143896)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2017765964)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1881968783)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 620255745)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1054826273)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -190197401)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 37950012)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1949047749)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 189426737)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 440451836)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1551731308)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1027640676)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1858793976)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1466961423)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1919572202)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1401831542)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1999145131)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 402719724)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1525180252)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1756175141)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1715510245)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -801305185)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1097312011)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1717331426)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1073357477)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 468940571)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 495824472)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2033338628)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -962064463)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 931219308)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1730227041)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 501406112)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1042174840)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 314706334)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1977655521)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2122716210)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1333236192)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -620075057)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1542610935)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1967155575)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 74423716)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -961190199)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -505351260)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1217352219)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 877700249)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 639032041)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1243454584)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1243454584)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -116602735)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2058632186)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 891272013)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 393068387)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1140870402)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1101235920)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -442306200)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -345371965)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1379398115)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 575518757)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 889825697)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 764638896)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1260307946)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1430093873)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 550741583)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 858406863)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1870047677)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1249091994)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -49604647)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -338445752)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1302185744)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1975590661)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -922075519)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1437574346)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -228458318)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2131576964)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 177832320)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1400694109)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1166120552)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 145559396)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2080461139)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1070934291)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1491386500)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 489321898)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1633299070)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -638863591)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 405611573)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -547753294)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 40168385)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1678014630)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 416104391)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 710791216)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -253630609)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -730739328)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1657159979)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1570956502)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1705723814)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1595515659)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 261991583)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -775470665)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1698341613)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 714506292)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1376408207)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2142017165)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1336925360)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 126014646)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1290202385)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -402069102)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2053227459)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1372360252)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1006436615)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 547957431)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 809657238)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -415666077)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1188873208)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1549630786)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1060402116)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -504482199)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 89278042)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1118933262)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1990292823)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1352706024)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 348119077)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1240791382)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -948169674)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2133081418)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -262341369)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1000457834)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -375398087)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1329008922)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1841943281)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -852503405)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 925173178)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1989372325)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1303708261)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1911813629)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2098987581)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -865197423)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1825953974)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -921073084)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 156856405)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2060629306)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 262768112)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 421494533)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1755988437)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1493184845)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1657017550)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -577286683)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 465570678)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1632172694)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1972484238)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 14345383)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 743968101)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 599029146)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 962465625)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 960916034)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1459006650)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 778805747)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1580390976)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 823645419)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2065346036)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1213808185)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 67004146)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 582648726)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1031098030)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1295633605)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 614999494)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -791577348)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1294893057)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -171207973)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -568266702)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1212829040)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1345577858)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 767605081)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -977515445)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -365271546)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -455354067)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1174459121)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1096684293)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1497250740)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -911939009)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1347850743)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -920663435)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1057419833)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1596113101)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1759105725)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1336932351)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1648921703)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1437387234)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2062282408)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1692477431)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1553508941)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 699592812)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1417613287)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2029779863)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1596100569)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 392501634)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -909357184)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1442614028)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 171064260)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -152440739)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1353116588)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 835608275)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1307476082)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -345908092)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1365604007)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1280085963)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -612371672)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1488631377)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1720012585)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2042475657)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -240257097)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1240585650)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1192658057)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 243540311)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1191422458)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -627821011)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1129105265)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1767220965)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1664114676)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1032273438)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1665678974)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1544167759)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -87967637)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -891346918)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1729804184)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1882923979)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 793694002)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -158787995)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1620254541)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1428412924)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1713165973)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1212832151)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 87315576)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 635120817)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 275957394)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -707133706)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1623717033)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 420011712)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -738295409)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1665839162)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -131274930)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 150294028)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 992970225)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -551637263)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 603010792)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -813003734)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 584503478)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -355297939)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1789621123)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -338399516)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1317868303)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1119498954)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1974064500)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1699621593)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1300962917)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1410801811)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -647202696)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -966559987)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1509139352)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1437305856)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1564435822)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 765000166)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2099816323)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1310197925)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -542139175)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 511933636)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 127054992)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 741525574)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 473998728)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1642731136)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2026253606)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1245024507)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1394622857)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 814210644)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 356369059)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1185075112)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1996378932)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -743046526)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1014199946)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 474621183)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1901047756)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1644907640)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1840682990)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1843603007)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 483883516)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1191687050)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 733106126)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 417206566)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -962439346)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -545396442)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 53977718)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 830707189)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1198154717)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1890951223)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1252906024)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1559754940)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 665709549)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1922258436)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -435067392)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 324865135)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 331283186)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -363435150)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1325156823)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1483710319)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -496432604)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -727492889)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 194342417)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1406618481)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1879618040)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1080429176)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -416183945)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1455659794)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}



		if (argStruct[0] == 1764386440)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Send Police On You~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 597922279)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Vehicle Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1152266822)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: CEO Money~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2041535807)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Transaction Error~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2092565704)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick Single Player~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -316948135)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: CEO Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1355230914)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: CEO Ban~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}
		if (argStruct[0] == -1479371259)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Cayo Perico~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1147284669)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Send To Mission~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1656474008)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1147284669)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1537221257)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Sound [1]~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1813981910)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 639032041)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1320260596)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1427741376)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -272926713)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1337820848)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 299217086)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Insurance Notify~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -148441291)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1187364773)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Delete Wanted Lvl~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -151720011)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Bribe Police~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -397188359)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -81613951)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1906146218)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Sync Bounty~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2105858993)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 297912845)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 888578819)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1002348481)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1694315389)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1337206479)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1264708915)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -44054089)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 27493799)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 247151081)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1385748752)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1871141598)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1069230108)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1163167720)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 220852783)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1857757712)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -989654618)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1382676328)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1256866538)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1753084819)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1119864805)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1833002148)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 202252150)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1503282114)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 243981125)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1836118977)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -169685950)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2071141142)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -149227625)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1433396036)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1608876738)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 458875017)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 987018372)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1587276086)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 813647057)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 153488394)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick + Crash Keks [6] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1723452001)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 210491663)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1780858740)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 277548576)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -132026059)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -851196171)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1293299354)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 903362384)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 243981125)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1848973789)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1503282114)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 202252150)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -189552513)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1896924387)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1491104200)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1150803197)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1808453742)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 75217734)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1648825077)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 597922279)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1016027275)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 890117219)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -635501849)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1521203907)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -675325833)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1846223309)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1472117290)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1054422861)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -73352157)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -78017695)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 2018643992)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -352859634)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1370240360)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 62705223)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2000489950)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 214030117)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1926582096)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Crash Keks Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1830143324)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -279342915)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 690534430)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1833002148)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 315658550)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Keks Crash Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1005623606)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Vehicle Kick~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2022389047)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1618779170)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -53130764)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1301508763)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1413680798)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1026386029)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 273726443)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1659915470)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Set A Banner~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 575344561)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 829201205)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1358851648)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -859672259)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1753084819)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1500178943)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -863176541)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -397188359)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1595854775)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1933105669)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 624184651)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1520160200)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1005294040)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1989758836)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -211878773)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1318777899)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -178721456)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -325138340)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1881357102)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}




		if (argStruct[0] == 701013663)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}




		if (argStruct[0] == -903212623)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1816012469)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}




		if (argStruct[0] == -1587276086)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1649958326)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 578058101)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -515495966)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1235041639)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -396894108)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1023783113)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1679855368)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1863892872)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1208850730)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -302187166)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1656474008)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1230210137)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1448333980)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1074756845)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1229338575)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Delete Money Destroy Personal Vehicle~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -505735987)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1257857900)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1900695287)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -16213980)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 59352546)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1795076373)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 134867878)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1145943081)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2076396337)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1950208850)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2103999464)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1016625751)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1095711893)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -971907474)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1566668579)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1713679709)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2100809716)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1033875141)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 45192266)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1864582447)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2014392362)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 808437855)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 447050477)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1157285407)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -959790325)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1717096076)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1954846099)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick Keks [5] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1964309656)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick Keks [1] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1006166687)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -65296432)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -911081209)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 168919469)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 932894951)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -37068802)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 226676030)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1773075874)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1927914708)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1945247369)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -46298284)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1705137662)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1842341008)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 212052693)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1705411017)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -933507377)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -257834583)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -588744584)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1186109081)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -639979452)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 2120864071)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 959824647)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 2005618868)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -868839127)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1800830029)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1825938840)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1533887418)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1643877404)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 712678541)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2017818728)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1266208560)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1529925410)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 987018372)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1891495479)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1959541747)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1870308609)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1785748887)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 458875017)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 27785517)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 662343702)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -978812630)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1990909018)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1484351810)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1372589624)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1210543720)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1764386440)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1190123899)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 384219567)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -810334939)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1187407749)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 254526911)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1924022050)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -979549154)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -544908807)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 675377079)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 678368510)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 2108029684)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 399742549)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1622386523)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1999269016)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -126133365)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1639153173)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1384138535)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1794395648)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1734770887)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1649341354)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1819246032)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -733604274)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -275229102)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 541344683)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -487303944)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1735852781)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 241570528)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -654645351)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 486186480)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1341149498)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 600486780)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick Keks [4] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 174461233)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -888636441)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1532157118)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1296795403)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 33277241)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 2120839242)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1154988013)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1209918357)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1763836227)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1249026189)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick + Apart Keks [7] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -283884309)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1287299127)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 493604397)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -2043109205)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Crash Keks Lua/Nova Menu~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -988842806)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Crash Nova Menu/Keks Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1146815758)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1519476362)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1136772712)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1723675897)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -390491000)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 23010443)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 641157117)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1608876738)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -79150418)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 257478565)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 496476216)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 608132931)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -25619296)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -176858990)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1605274399)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1731962870)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1277389265)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -181124995)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1855721397)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1472357458)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 665468344)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -212308547)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 975723848)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Vehicle EMP~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -720653448)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 900985860)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 200339862)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -95026574)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 2049240389)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 917535648)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1517002797)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1126437067)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -421711998)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1164760553)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1428764848)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 161038699)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -137439024)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 997078653)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -384079069)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1514001560)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -347755611)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1767220965)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 2051313650)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1489802466)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -247110509)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 469112443)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -149227625)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 316678593)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -1918817181)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 282406360)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1433396036)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 696123127)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick Keks [2] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -877212109)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Keks Crash Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 770242759)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -796052439)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -19131151)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -169685950)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1134927454)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 515799090)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1132500638)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1216017047)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1836414206)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 490383602)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == 1455421717)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}


		if (argStruct[0] == -795567983)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -341234598)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -525866785)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -419415284)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1857108105)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -662216118)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1098534904)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 649952111)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1923828310)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 795867332)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1305720168)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1561004591)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1463355688)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2071141142)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 251577675)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1836118977)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1788162956)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1136752511)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -428995778)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1119864805)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -699380547)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1376436345)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 677429013)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1758368969)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1173618358)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -898207315)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1287903621)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1625031686)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1873289193)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1268963570)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -767611756)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -275700180)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 797978700)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -194543830)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2063448951)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -299840140)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -504114839)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1197757671)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1490942189)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1797631140)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 951147709)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -609583028)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1824446546)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -771079131)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1511043020)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -768666112)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1298961960)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -760171613)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 43922647)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Kick Keks [3] Lua~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1911026003)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 15745542)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1147284669)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -299200920)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2072214082)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Disown Vehicles~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1568036440)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1256866538)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1382676328)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1813981910)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -845729485)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -892744477)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1722256522)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -114483526)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -171077681)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 38189494)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -2086228364)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1727818500)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -655898431)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1889984715)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 1166958622)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == -1912844061)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}

		if (argStruct[0] == 897248694)
		{
			char buf1[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			char* Name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_PURPLELIGHT);
			char buf4[255];
			sprintf(buf4, "Status: Blocked~n~"
				"Event: Extreme Protection~n~"
				"Sender: %s~n~", Name);
			notifyMap(buf4);
		}





		return false;
	}
	return result;
}


fpGetEventData OG_GET_EVENT_DATA = nullptr;
bool HK_GET_EVENT_DATA(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount)
{
	auto handle = static_cast<decltype(&HK_GET_EVENT_DATA)>(OG_GET_EVENT_DATA)(eventGroup, eventIndex, args, argCount);

	if (handle && notify) 
	{

		Player player = args[1];
		const char* sender = Foxy_Engine::get_player_name(player);

		if (args[0] == 498709856)
		{
			notifyMap("Event: Kick Event\nSender: " + (std::string)sender + "\nStatus: Prevented");
			return false;
		}
		
	}
	return handle;
}

fpFreezeEventHandle ogFreezeEventHandle = nullptr;
bool hkFreezeEventHandle(std::uintptr_t thisptr, std::uintptr_t sourcePlayer, std::uintptr_t targetPlayer)
{
	if (FreezeProtection)
	{
		for (int i = 0; i < 33; i++) {
			auto senderName = PLAYER::GET_PLAYER_NAME(*(std::int8_t*)(sourcePlayer + i));

			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_BLUEDARK);
			notifyMap(
				"Freeze: Blocked~n~"
				"From: %s",
				senderName);
		}
		return true;
	}

	return ogFreezeEventHandle(thisptr, sourcePlayer, targetPlayer);
}


/**/
//std::hash<Hash> crashprotection = {
	/*0x3f039cba, 0x856cfb02, 0x2d7030f3, 0x2D7030F3, 0xC1CE1183,*/
//};
/*fpblockmodelcrash ogblockmodelcrash;
bool hkblockmodelcrash(Hash hash, DWORD* unused)
{
	if (crash_protection)
	{
		NULL;
	}
		/*if (crashprotection.find(hash) != crashprotection.end())
		{
			return false;
			char buf[255];
			sprintf(buf, "Crash object blocked, Hash: %s", hash);
			notifyMap(buf, true);
			return false;
		}
	}
	return ogblockmodelcrash(hash, unused);*/





#pragma pack(push, 1)
class CExplosionTag
{
public:
	const char *nameData;
	std::uint16_t nameSize;
	std::uint16_t nameCapacity;
	char pad[0x74];
};

class CExplosionTagList
{
public:
	CExplosionTag *data;
	std::uint16_t size;
	std::uint16_t capacity;
};

static_assert(sizeof(CExplosionTag) == 0x80, "");
static_assert(sizeof(CExplosionTagList) == 0x0C, "");
#pragma pack(pop)

const char *getExplosionName(int expTagId)
{
	static CExplosionTagList *expTagList = ([]
		{
			auto ptr = Memory::pattern("0F B7 05 ? ? ? ? 3B F8 7D 10 48 8B C7 48 C1 E0 07 48 03 05 ? ? ? ?").count(1).get(0).get<char>(21);
			ptr += *(std::int32_t*)(ptr) + sizeof(std::int32_t);

			return (CExplosionTagList*)ptr;
		}());

	if (expTagId < expTagList->size)
	{
		return expTagList->data[expTagId].nameData;
	}

	return "**Invalid**";
}

fpExplosionEventHandle ogExplosionEventHandle = nullptr;
bool hkExplosionEventHandle(std::uintptr_t thisptr, std::uintptr_t sourcePlayer, std::uintptr_t targetPlayer)
{
	if (Protections::ExplosionProtection)
	{
		for (int i = 0; i < 33; i++) {
			auto explosionName = getExplosionName(*(std::uint32_t*)(thisptr + 0x30));
			auto senderName = PLAYER::GET_PLAYER_NAME(*(std::int8_t*)(sourcePlayer + i));

			UI::_SET_NOTIFICATION_BACKGROUND_COLOR(HUD_COLOUR_RED);
			notifyMap(
				"Explosion : Blocked~n~"
				"Type : %s~n~"
				"From : %s",
				explosionName, senderName);
		}
		return true;
	}

	return ogExplosionEventHandle(thisptr, sourcePlayer, targetPlayer);
}

fpPickupRewardMoneyIsApplicableToPlayer ogPickupRewardMoneyIsApplicableToPlayer = nullptr;
bool hkPickupRewardMoneyIsApplicableToPlayer(void *thisptr, void *unk, void *ped)
{
	if (BlockMoney)
	{
		return false;
	}
	return ogPickupRewardMoneyIsApplicableToPlayer(thisptr, unk, ped);
}

fpGetLabelText ogGetLabelText = nullptr;
const char* __cdecl hkGetLabelText(void* this_, const char* label)
{

	if (std::strcmp(label, "HUD_JOINING") == 0)
	{
		return "Go online with Foxy";
	}
	if (std::strcmp(label, "HUD_QUITTING") == 0)
	{
		return "Quitting us that quick?";
	}
	if (std::strcmp(label, "PM_QUIT_MP") == 0)
	{
		return "Leaving Online with Foxy";
	}
	if (std::strcmp(label, "PM_ENTER_MP") == 0)
	{
		return "Go online with Foxy";
	}
	if (std::strcmp(label, "PM_EXIT_GAME") == 0)
	{
		return "Rage Quit";
	}
	if (std::strcmp(label, "PM_GO") == 0)
	{
		return "Go Online with Foxy";
	}
	if (std::strcmp(label, "PM_GOTO_STORE") == 0)
	{
		return "Scam me take2";
	}
	if (std::strcmp(label, "PM_FRIEND_FM") == 0)
	{
		return "A menu is better whit friend's";
	}
	if (std::strcmp(label, "PM_FIND_SESS") == 0)
	{
		return "Fuck that session";
	}
	if (std::strcmp(label, "HUD_TRANSP") == 0)
	{
		return "Transaction Error";
	}
	//New
	if (std::strcmp(label, "PM_PLAYLISTS") == 0)
	{
		return "Really modding in activities?";
	}
	if (std::strcmp(label, "PM_SWAP_CHAR") == 0)
	{
		return "Which character should i mod?";
	}
	if (std::strcmp(label, "PM_CREWS") == 0)
	{
		return "Oh right... Crew's are still a feature";
	}

	//PM_CREWS
	return ogGetLabelText(this_, label);
}


bool Foxy_Engine::HookNatives()
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	MH_Initialize();

	MH_STATUS status = MH_CreateHook(Foxy_Engine::is_PLAYER_dead, HK_IS_PLAYER_DEAD, (void**)& OG_IS_PLAYER_DEAD);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Foxy_Engine::is_PLAYER_dead) != MH_OK)
		return false;
	Foxy_Engine::m_hooks.push_back(Foxy_Engine::is_PLAYER_dead);

	MH_STATUS status0 = MH_CreateHook(Foxy_Engine::blockmodelcrash, crashHook, &blockmodelcrash1);
	if ((status0 != MH_OK && status0 != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Foxy_Engine::blockmodelcrash) != MH_OK)
	{
		return false;
	}

	status = MH_CreateHook(Foxy_Engine::get_event_data, RedirProc, &m_OriginalGetEventData);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Foxy_Engine::get_event_data) != MH_OK)
	{
		return false;
	}

	MH_STATUS status1 = MH_CreateHook(Foxy_Engine::GetLabelText, hkGetLabelText, (void**)&ogGetLabelText);
	if (status1 != MH_OK || MH_EnableHook(Foxy_Engine::GetLabelText) != MH_OK)
		return false;
	status = MH_CreateHook(Foxy_Engine::get_chat_message, HK_GET_MESSAGE, (void**)& OG_GET_MESSAGE);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Foxy_Engine::get_chat_message) != MH_OK)
		return false;
	Foxy_Engine::m_hooks.push_back(Foxy_Engine::get_chat_message);
	Foxy_Engine::m_hooks.push_back(Foxy_Engine::GetLabelText);
	Foxy_Engine::m_hooks.push_back(Foxy_Engine::get_event_data);
	//Log::Msg("protection hook Successfull!");
	MH_STATUS status4 = MH_CreateHook(Foxy_Engine::PickupRewardMoneyIsApplicableToPlayer, hkPickupRewardMoneyIsApplicableToPlayer, (void**)&ogPickupRewardMoneyIsApplicableToPlayer);
	if (status4 != MH_OK || MH_EnableHook(Foxy_Engine::PickupRewardMoneyIsApplicableToPlayer) != MH_OK)
		return false;
	Foxy_Engine::m_hooks.push_back(Foxy_Engine::PickupRewardMoneyIsApplicableToPlayer);
	MH_STATUS status5 = MH_CreateHook(Foxy_Engine::FreezeEventHandle, hkFreezeEventHandle, (void**)&ogFreezeEventHandle);
	if (status5 != MH_OK || MH_EnableHook(Foxy_Engine::FreezeEventHandle) != MH_OK)

		return false;
	// status = MH_CreateHook(Foxy_Engine::member_id_from_gamer_handle, HK_MEMBER_ID_FROM_GAMER_HANDLE, (void**)& OG_MEMBER_ID_FROM_GAMER_HANDLE);
	 // if (status != MH_OK || MH_EnableHook(Foxy_Engine::member_id_from_gamer_handle) != MH_OK)
	//     return false;
	//  Foxy_Engine::m_hooks.push_back(Foxy_Engine::member_id_from_gamer_handle);

	Foxy_Engine::m_hooks.push_back(Foxy_Engine::FreezeEventHandle);



	MH_STATUS status6 = MH_CreateHook(Foxy_Engine::ExplosionEventHandle, hkExplosionEventHandle, (void**)&ogExplosionEventHandle);
	if (status6 != MH_OK || MH_EnableHook(Foxy_Engine::ExplosionEventHandle) != MH_OK)
		return false;
	Foxy_Engine::m_hooks.push_back(Foxy_Engine::ExplosionEventHandle);
	
	printf("Script Event Hook Successful!\n");
	printf("Explosion Hook Successful!\n");
	printf("Crash Protections Hooks Successful!\n");
	printf("Native Hooks Successful!\n");
	printf("Freeze Hook Successful!\n");
	printf("Money hook Successful!\n");
	printf("Welcome to Foxy\n");
	printf("Open with f6 or Dpad Right + RB /n");
	return true;
}

void Foxy_Engine::RemoveHooking() noexcept
{
	MH_RemoveHook(Foxy_Engine::is_PLAYER_dead);
	MH_RemoveHook(Foxy_Engine::get_event_data);
	MH_RemoveHook(Foxy_Engine::GetLabelText);
	MH_RemoveHook(Foxy_Engine::get_chat_message);
	MH_RemoveHook(Foxy_Engine::PickupRewardMoneyIsApplicableToPlayer);
	MH_RemoveHook(Foxy_Engine::FreezeEventHandle);
	MH_RemoveHook(Foxy_Engine::blockmodelcrash);
	MH_RemoveHook(Foxy_Engine::ExplosionEventHandle);
	MH_RemoveHook(Foxy_Engine::GetPlayerAddress);
	MH_RemoveHook(Foxy_Engine::AddressToEntity);
	MH_RemoveHook(Foxy_Engine::BResearch);
	MH_RemoveHook(Foxy_Engine::get_script_event_data);
	MH_RemoveHook(Foxy_Engine::get_player_name);
	MH_RemoveHook(Foxy_Engine::create_ambient_pickup);
	MH_RemoveHook(Foxy_Engine::ClockTime);
	MH_RemoveHook(Foxy_Engine::ptr_to_handle);
	MH_RemoveHook(Foxy_Engine::stat_set_int);
	MH_RemoveHook(Foxy_Engine::stat_set_bool);
	MH_RemoveHook(Foxy_Engine::trigger_script_event);
	MH_RemoveHook(Foxy_Engine::set_vehicle_mod);
	MH_RemoveHook(Foxy_Engine::give_delayed_weapon_to_ped);
	MH_RemoveHook(Foxy_Engine::has_model_loaded);
	MH_RemoveHook(Foxy_Engine::create_vehicle);
	MH_RemoveHook(Foxy_Engine::request_model);
	MH_RemoveHook(Foxy_Engine::m_frameCount);


	fclose(stdout);
	fclose(stdin);
	fclose(stderr);
	FreeConsole();

	MH_Uninitialize();
	
}

void Foxy_Engine::Hook()
{
	MH_EnableHook(MH_ALL_HOOKS);
}

void Foxy_Engine::Unhook()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();
	//FreeLibraryAndExitThread(static_cast<HMODULE>(_hmoduleDLL), 1);
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();

	}
	catch (...)
	{
		AllocConsole();
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
		printf("Failed scriptFiber");
		WAIT(10000);
		exit(0);
		//Log::Fatal("Failed scriptFiber");
	}
}

void Foxy_Engine::RequestCleanup()
{
	cleanupRequested = true;
}

void Foxy_Engine::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = IsThreadAFiber() ? GetCurrentFiber() : ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}


void Foxy_Engine::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf(buf);
	//Log::Error(buf);
	Cleanup();
}
/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

BlipList* Foxy_Engine::GetBlipList()
{
	return m_blipList;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE* btMask, char* szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char* pStart = nullptr;
	char* pEnd = nullptr;
	char* res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void failPat(const char* name)
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf("Failed to find %s pattern.", name);
	WAIT(10000);
	//Log::Fatal("Failed to find %s pattern.", name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char* name,
	char* pat,
	char* mask,
	T** out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T* ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T * *)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char* name,
	char* pat,
	char* mask,
	T* out,
	int			skip = 0
)
{
	char* ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}


void mem_nop2(void* ptr, int size)
{
	memset(ptr, 0x90, size);
}

void Foxy_Engine::FindPatterns()
{

	HANDLE steam = GetModuleHandleA("steam_api64.dll");

	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	//auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");
	Foxy_Engine::GetModelInfo = static_cast<fpgetmodelinfo>(Memory::pattern("0F B7 05 ? ? ? ? 45 33 C9 4C 8B DA 66 85 C0 0F 84 ? ? ? ? 44 0F B7 C0 33 D2 8B C1 41 F7 F0 48 8B 05 ? ? ? ? 4C 8B 14 D0 EB 09 41 3B 0A 74 54").count(1).get(0).get<void>(0));
	Foxy_Engine::blockmodelcrash = static_cast<fpblockmodelcrash>(Memory::pattern("0F B7 05 ? ? ? ? 45 33 C9 4C 8B DA 66 85 C0 0F 84 ? ? ? ? 44 0F B7 C0 33 D2 8B C1 41 F7 F0 48 8B 05 ? ? ? ? 4C 8B 14 D0 EB 09 41 3B 0A 74 54").count(1).get(0).get<void>(0));
	//Foxy_Engine::blockmodelcrash = static_cast<fpblockmodelcrash>(Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 8B FA E8 ? ? ? ? 33 DB").count(1).get(0).get<void>(0));
	Foxy_Engine::GetLabelText = static_cast<fpGetLabelText>(Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8").count(1).get(0).get<void>(0));
	Foxy_Engine::FreezeEventHandle = static_cast<fpFreezeEventHandle>(Memory::pattern("0F B7 51 30 48 8B F1 48 8B 0D ? ? ? ? 45 33 C0 E8 ? ? ? ? 48 8B C8 48 8B F8").count(1).get(0).get<void>(-15));
	Foxy_Engine::ExplosionEventHandle = static_cast<fpExplosionEventHandle>(Memory::pattern("8A 42 2D 48 8B F2 48 8B F9 88 81 ? ? ? ? 80 3D").count(1).get(0).get<void>(-15));
	Foxy_Engine::Anticheatsig = static_cast<fpAnticheatsig>(Memory::pattern("80 3D ? ? ? ? ? 0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 08").count(1).get(0).get<void>(0)); 
	Foxy_Engine::PickupRewardMoneyIsApplicableToPlayer = static_cast<fpPickupRewardMoneyIsApplicableToPlayer>(Memory::pattern("49 8B 80 ? ? ? ? 48 85 C0 74 0C F6 80 ? ? ? ? ? 75 03").count(1).get(0).get<void>(0));
	Foxy_Engine::add_owned_explosion = static_cast<fpAddOwnedExplosion>(Memory::pattern("0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8").count(1).get(0).get<void>(0));




	/* SHV STUFF
	Foxy_Engine::add_owned_explosion = static_cast<fpAddOwnedExplosion>(Memory::pattern("48 8B 05 ? ? ? ? 41 0F BF C8").count(3).get(0).get<void>(0)); //Ped Pool
	Foxy_Engine::add_owned_explosion = static_cast<fpAddOwnedExplosion>(Memory::pattern("48 8B 05 ? ? ? ? F3 0F 59 F6 48 8B 08").count(3).get(0).get<void>(0)); //Vehicle Pool
	Foxy_Engine::add_owned_explosion = static_cast<fpAddOwnedExplosion>(Memory::pattern("48 8B 05 ? ? ? ? 8B 78 10 85 FF").count(3).get(0).get<void>(0)); //Object Pool
	Foxy_Engine::add_owned_explosion = static_cast<fpAddOwnedExplosion>(Memory::pattern("4C 8B 05 ? ? ? ? 40 8A F2 8B E9").count(3).get(0).get<void>(0)); //Pick Up Pool
	Foxy_Engine::add_owned_explosion = static_cast<fpAddOwnedExplosion>(Memory::pattern("48 8B C8 EB 02 33 C9 48 85 C9 74 26").count(-9).get(0).get<void>(0)); //Camera Pool
*/
	

	auto kekek = Memory::pattern("FF 27");
	for (int i = 0, end = kekek.size(); i < end; ++i)
	{
		auto addr = kekek.get(i).get<void>();

		MEMORY_BASIC_INFORMATION mbi{};
		if (VirtualQuery(addr, &mbi, sizeof(mbi)) == sizeof(mbi))
		{
			if (mbi.Protect == PAGE_EXECUTE_READWRITE)
			{
				invoker_return_address = addr;
				break;
			}
		}
	}

	setPat<twoBytes>("oebypass",
		"\x3B\xF8\x40\x0F\x94\xC7",
		"xxxxxx",
		&owned_explossion_bypass_info,
		false);

	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	
	printf("Foxy is now hooking, do not close this window.\n");
	printf("This is not an Online Menu \n");
	
	printf("Verifying patterns\n");

	printf("Searching for Frame Count\n");
	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Foxy_Engine::m_frameCount,
		true,
		2);
	printf("Found\n");

	printf("Searching for Player Status\n");
	setFn<fpisPLAYERdead>("get_player_status",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
		"xxxx?xxxxxxx????",
		&Foxy_Engine::is_PLAYER_dead);
	printf("Found\n");
	
	printf("Searching for Chat CMD\n");
//	setFn<fpChatMessage>("get_msg",
	//	"\x4D\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x48\x20",
	//	"xxxxx????xxxxxxxxxxxxxxxxxxx",
	//	&Foxy_Engine::get_chat_message);
	printf("Skipped\n");
	


	printf("Searching for Request Model\n");
	setFn<fpRequestModel>("request_model",
		"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Foxy_Engine::request_model);
	printf("Found\n");

	//printf("Searching for Create Object\n");
	//setFn<fpCreateObject>("create_object",
	//	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x60\x20\x55\x41\x55\x41\x56\x48\x8D\x68\xD9",
	//	"xxxxxxxxxxxxxxxxxxxxxxxxxxxx",
	//	&Foxy_Engine::create_object);
	//printf("Found\n");

	printf("Searching for Create Vehicle\n");
	setFn<fpCreateVehicle>("create_vehicle",
		"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
		"xxxx?xxxxxxxxxxxxxxxxxxxxxx",
		&Foxy_Engine::create_vehicle);
	printf("Found\n");

	printf("Searching for Has Model Loaded\n");
	setFn<fpHasModelLoaded>("has_model_loaded",
		"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
		"xxxx?xxxxxxxxxxxx",
		&Foxy_Engine::has_model_loaded);
	printf("Found\n");

	printf("Searching for Give Delayed Weapon\n");
	setFn<fpGiveDelayedWeaponToPed>("give_delayed_weapon_to_ped",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x63",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxxxxxxx",
		&Foxy_Engine::give_delayed_weapon_to_ped);
	printf("Found\n");

	printf("Searching for Set Vehicle Mod\n");
	setFn<fpSetVehicleMod>("set_vehicle_mod",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8A\xE9",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Foxy_Engine::set_vehicle_mod);
	printf("Found\n");

	printf("Searching for Replay Interface\n");
	/*
	setPat<CReplayInterface>("",
		"\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",
		"xxx????xxxx????xxx????xxx????xxxxxxx????",
		&Foxy_Engine::m_replayIntf,
		true,
		3,
		1);
	*/
	printf("Found\n");

	printf("Searching for Trigger Script Event\n");
	//setFn<fpTriggerScriptEvent>("trigger_script_event",
		//"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9",
		//"xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx",
		//&Foxy_Engine::trigger_script_event);
	printf("Found\n");

	printf("Searching for Set Stat\n");
	setFn<fpStatSetBool>("STB",
		"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
		"xxxx?xxxxxxxxx",
		&Foxy_Engine::stat_set_bool);
	printf("Found\n");

	printf("Searching for Set Stat\n");
	setFn<fpStatSetInt>("stats",
		"\x89\x54\x24\x10\x55\x53\x56\x57\x41\x57",
		"xxxxxxxxxx",
		&Foxy_Engine::stat_set_int);
	printf("Found\n");

	printf("Searching for Ptr Handle\n");
	setFn<fpPtrToHandle>("PTRH",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
		"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
		&Foxy_Engine::ptr_to_handle);
	printf("Found\n");



	printf("Searching for Get Event Data\n");
	setFn<GetEventData1>("EVD",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00", "xxxx?xxxxxxxxxxx????", &Foxy_Engine::get_event_data);
	printf("Found\n");



	printf("Searching for Owned Explosion\n");

	printf("Found\n");

	printf("Searching for Clock Time\n");
	setPat<clockTime>("CT",
		"\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B",
		"xxx????xxx????xxxx",
		&Foxy_Engine::ClockTime,
		true,
		3);
	printf("Found\n");

	printf("Searching for Create Ambient PickUp\n");
	setFn<fpCreateAmbientPickup>("create_ambient_pickup",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xC1\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF9\x41\x8B\xF0\x4C\x8B\xEA\xE8\x00\x00\x00\x00\x0F\xB7\x0D\x00\x00\x00\x00\x33\xFF\x44\x8B\xC7\x44\x8B\xD7\x44\x8B\xE0\x85\xC9\x7E\x1C\x48\x8B\x1D\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxx????",
		&Foxy_Engine::create_ambient_pickup);
	printf("Found\n");

	printf("Searching for Get Player Name\n");
	setFn<fpGetPlayerName>("get_player_name",
		"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
		"xxxxxxxx?????xxxx",
		&Foxy_Engine::get_player_name);
	printf("Found\n");

	printf("Searching for Get Script Data\n");
	setFn<GetEventData>("get_script_event_data",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????",
		&Foxy_Engine::get_script_event_data);
	printf("Found\n");

	printf("Searching for Bunker Research\n");
	setFn<BunkerResearch>("BR", "\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19", "xxxxxxxxx????x????xxxx", &Foxy_Engine::BResearch);
	printf("Found\n");


	printf("Searching for Entity Address\n");
	setFn<fpAddressToEntity>("address_to_entity",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
		"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
		&Foxy_Engine::AddressToEntity);
	printf("Found\n");

	printf("Searching for Get Player Address\n");
	setFn<fpGetPlayerAddress>("get_player_address",
		"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
		"xxxxxxxxxx????xx",
		&Foxy_Engine::GetPlayerAddress);
	printf("Found\n");



	char * c_location = nullptr;
	void * v_location = nullptr;

	Sleep(5000);


	//c_location = p_gameState.count(1).get(0).get<char>(2);
	//c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);


	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);


	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;


	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);


	printf("Looking for msbypass!\n");
	setPat <twoBytes>("msbypass",
		"\xD8\x48\x85\xC0\x74\x12\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05",
		"xxxxxxxxxxxxxxxxxxx",
		&model_spawn_bypass_info,
		false,
		17);
	printf("msbypass Successful!\n");

	printf("Looking for mcbypass!\n");
	//setPat <Bytes24>("mcbypass",
	//	"\xCE\x33\xC1\x0F\xBA\xF0\x1D\x8B\xC8\x33\x4D\x67",
	//	"xxxxxxxxxxxx",
	//	&model_check_bypass_info,
	//	false,
	//	40);

	
	printf("Looking for Model check!\n");
	CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
	auto ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
	ptr == nullptr ? Log::Error("Failed to find pattern") : Memory::nop(ptr, 24);
	printf("Model check Hook Successful!\n");

	printf("Looking for Model Spawn!\n");
	CPattern pattern_modelSpawn("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48", "xxxxxxxxxxx");
	ptr = pattern_modelSpawn.find(0).get(0).get<char>(8);
	ptr == nullptr ? Log::Error("Failed to find  pattern") : Memory::nop(ptr, 2);
	printf("Model Spawn Hook Successful!\n");





	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);


	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);


	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}
	printf("Event Hook Successful!\n");
	CrossMapping::initNativeMap();
	//while (*m_gameState != GameStatePlaying) {
		Sleep(200);
	//}
		printf("Script Event Hook Successful!\n");
		printf("Explosion Hook Successful!\n");
		printf("Native Hooks Successful!\n");
		printf("Freeze Hook Successful!\n");
		printf("Money hook Successful!\n");
		printf("Welcome to Foxy\n");
		printf("Open with f6 or Dpad Right + RB \n");
		m_hwnd = FindWindowA("grcWindow", nullptr);
		SetWindowTextA(m_hwnd, gametitle[random(0, 31)].c_str());
}

void Foxy_Engine::settooltips(int value) {
	
}
static Foxy_Engine::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Foxy_Engine::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Foxy_Engine::NativeHandler Foxy_Engine::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

//eGameState Foxy_Engine::GetGameState()
//{
	//return *m_gameState;
//}

uint64_t Foxy_Engine::getWorldPtr()
{
	return m_worldPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}




void Foxy_Engine::Cleanup()
{
	/*Log::Msg("Cleaning up hooks");
	for (int i = 0; i < m_hooks.size(); i++)
		if (MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
			Log::Error("Failed to unhook %p", (void*)m_hooks[i]);
	MH_Uninitialize();
	FreeLibraryAndExitThread(static_cast<HMODULE>(_hmoduleDLL), 1);*/
}

void owned_explossion_bypass(bool toggle)
{
	constexpr twoBytes patched = { 0x39, 0xDB };
	constexpr twoBytes restore = { 0x3B, 0xF8 };
	if (owned_explossion_bypass_info == nullptr)
		return;
	*owned_explossion_bypass_info = toggle ? patched : restore;
}

Vehicle create_vehicle(Hash model, Vector3 pos, float heading, BOOL networked = 1, BOOL unk2 = 0) {
	while (!Foxy_Engine::has_model_loaded(model)) Foxy_Engine::request_model(model), WAIT(50);
	model_spawn_bypass(true);
	Vehicle veh = Foxy_Engine::create_vehicle(model, &pos, heading, networked, unk2);
	model_spawn_bypass(false);
	return veh;
}

Ped create_ped(int pedType, Hash modelHash, float x, float y, float z, float heading, bool isNetworked, bool thisScriptCheck) {
	while (!Foxy_Engine::has_model_loaded(modelHash)) Foxy_Engine::request_model(modelHash), WAIT(50);
	model_spawn_bypass(true), model_check_bypass(true);
	Ped pedHandle = PED::CREATE_PED(pedType, modelHash, x, y, z, heading, isNetworked, thisScriptCheck);
	model_spawn_bypass(false), model_check_bypass(false);
	return pedHandle;
}

Object create_object(Hash modelHash, float x, float y, float z, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic) {
	while (!Foxy_Engine::has_model_loaded(modelHash)) Foxy_Engine::request_model(modelHash), WAIT(50);
	Object obj;
	model_check_bypass(true);
	Foxy_Engine::create_object(modelHash, x, y, z, 1, 1, 0, &obj, isNetwork, 1, dynamic);
	model_check_bypass(false);
	return obj;
}

Object create_object(Hash modelHash, Vector3 pos, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic) {
	while (!Foxy_Engine::has_model_loaded(modelHash)) Foxy_Engine::request_model(modelHash), WAIT(50);
	Object obj;
	model_check_bypass(true);
	Foxy_Engine::create_object(modelHash, pos.x, pos.y, pos.z, 1, 1, 0, &obj, isNetwork, 1, dynamic);
	model_check_bypass(false);
	return obj;
}



void Foxy_Engine::defuseEvent(RockstarEvent e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

__int64** Foxy_Engine::getGlobalPtr()
{
	return m_globalPtr;
}
