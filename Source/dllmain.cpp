// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

DWORD WINAPI ControlThread(LPVOID lpParam)
{
	Foxy_Engine::Start((HMODULE)lpParam);
	return 0;
}
MODULEINFO DLLInfo;
bool ErasePEHeader(HMODULE hModule) // hModule = handle to DLL
{
	if ((DWORD)hModule == 0) return 0;
	DWORD IMAGE_NT_HEADER = *(int*)((DWORD)hModule + 60);
	for (int i = 0; i < 0x108; i++)
		*(BYTE*)(IMAGE_NT_HEADER + i) = 0;
	for (int i = 0; i < 120; i++)
		*(BYTE*)((DWORD)hModule + i) = 0;
	return 1;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		GetModuleInformation(GetCurrentProcess(), hModule, &DLLInfo, sizeof(MODULEINFO));
		//  ErasePEHeader(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Foxy_Engine::Cleanup();
		break;
	}
	return TRUE;
}
