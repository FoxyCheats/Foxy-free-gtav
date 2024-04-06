//Log.cpp
#include "stdafx.h"
#include <time.h>
#include <cstdio>

char g_logFile[MAX_PATH];
char g_debugLogFile[MAX_PATH];

#define CHARS_FOR_BUFF 4096
#define CHARS_FOR_PARAMS 3500

static bool useFileOutput = true;

void Log::Init(HMODULE hModule) {
	memset(g_logFile, 0, sizeof(g_logFile));

	if (GetModuleFileNameA(hModule, g_logFile, MAX_PATH) != 0) {
		size_t slash = -1;

		for (size_t i = 0; i < strlen(g_logFile); i++) {
			if (g_logFile[i] == '/' || g_logFile[i] == '\\') {
				slash = i;
			}
		}
		char chLogBuff[CHARS_FOR_BUFF];
		char szTimestamp[30];
		struct tm current_tm;
		time_t current_time = time(NULL);

		localtime_s(&current_tm, &current_time);
		sprintf_s(szTimestamp, "%%s\n");
		sprintf_s(chLogBuff, szTimestamp,"[Foxy] Started Hooking:");
		//sprintf_s(chLogBuff, szTimestamp,"[Foxy] Started Dumping Natives:");
	//	CrossMapping::dumpNativeMappingCache();

		AllocConsole();
		   cout << "Authorization successful" << endl;
		HWND hwnd = GetConsoleWindow();
		HMENU hmenu = GetSystemMenu(hwnd, FALSE);
		EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
		SetConsoleTitle(_T("Foxy Console"));
		PlaySound(L"C:\\Foxy\\Music\\injection.wav", NULL, SND_ASYNC);
		   freopen("conin$", "r", stdin);
		   freopen("conout$", "w", stdout);
		   freopen("conout$", "w", stderr);
		printf("Welcome to Foxy Free Menu Version 0.9.18 For GTA V\n");
		//printf("\n");
		//printf("Foxy Free Is Hooking Don't Close Me:\n"); //SetWindowTextA(g_Pointers->m_hwnd, outtaPocketTitles[randNum].c_str());
		//printf("\n");
		if (slash != -1) {
			g_logFile[slash + 1] = '\0';
			strcpy_s(g_debugLogFile, g_logFile);
			strcat_s(g_debugLogFile, "Foxy.log");

			FILE* file;
			if ((fopen_s(&file, g_debugLogFile, "w")) == 0)
			{
				fprintf_s(file, "%s", chLogBuff);
				fclose(file);
			}
			OutputDebugStringA("[Foxy] Started Hooking:");
		}
		else {
			useFileOutput = false;
		}
	}
	else {
		useFileOutput = false;
	}
}

#ifdef _DEBUG
void Log::Debug(const char* fmt, ...)
{

	va_list va_alist;
	char chLogBuff[CHARS_FOR_BUFF];
	char chParameters[CHARS_FOR_PARAMS];
	char szTimestamp[30];
	struct tm current_tm;
	time_t current_time = time(NULL);

	localtime_s(&current_tm, &current_time);
	sprintf_s(szTimestamp, "DEBUG: %%s\n", current_tm.tm_hour, current_tm.tm_min, current_tm.tm_sec);

	va_start(va_alist, fmt);
	_vsnprintf_s(chParameters, sizeof(chParameters), fmt, va_alist);
	va_end(va_alist);
	sprintf_s(chLogBuff, szTimestamp, chParameters);

	if (useFileOutput) {
		FILE* file;
		if ((fopen_s(&file, g_debugLogFile, "a")) == 0)
		{
			fprintf_s(file, "%s", chLogBuff);
			fclose(file);
		}
	}
	sprintf_s(chLogBuff, "%s\n", chParameters);
	OutputDebugStringA(chLogBuff);

}
#endif

void Log::Msg(const char* fmt, ...) {
	va_list va_alist;
	char chLogBuff[CHARS_FOR_BUFF];
	char chParameters[CHARS_FOR_PARAMS];
	char szTimestamp[30];
	struct tm current_tm;
	time_t current_time = time(NULL);

	localtime_s(&current_tm, &current_time);
	sprintf_s(szTimestamp, "%%s\n");

	va_start(va_alist, fmt);
	_vsnprintf_s(chParameters, sizeof(chParameters), fmt, va_alist);
	va_end(va_alist);
	sprintf_s(chLogBuff, szTimestamp, chParameters);
	if (useFileOutput) {
		FILE* file;
		if ((fopen_s(&file, g_debugLogFile, "a")) == 0)
		{
			fprintf_s(file, "%s", chLogBuff);
			fclose(file);
		}
	}
	sprintf_s(chLogBuff, "%s\n", chParameters);
	OutputDebugStringA(chLogBuff);
}


void Log::Error(const char* fmt, ...) {
	va_list va_alist;
	char chLogBuff[CHARS_FOR_BUFF];
	char chParameters[CHARS_FOR_PARAMS];
	char szTimestamp[30];
	struct tm current_tm;
	time_t current_time = time(NULL);
	FILE* file;

	localtime_s(&current_tm, &current_time);
	sprintf_s(szTimestamp, "ERROR: %%s\n", current_tm.tm_hour, current_tm.tm_min, current_tm.tm_sec);

	va_start(va_alist, fmt);
	_vsnprintf_s(chParameters, sizeof(chParameters), fmt, va_alist);
	va_end(va_alist);
	sprintf_s(chLogBuff, szTimestamp, chParameters);
	if ((fopen_s(&file, g_debugLogFile, "a")) == 0)
	{
		fprintf_s(file, "%s", chLogBuff);
		fclose(file);
	}

	MessageBoxA(NULL, chLogBuff, "ERROR", MB_ICONERROR);
}

void Log::Fatal(const char* fmt, ...) {
	va_list va_alist;
	char chLogBuff[CHARS_FOR_BUFF];
	char chParameters[CHARS_FOR_PARAMS];
	char szTimestamp[30];
	struct tm current_tm;
	time_t current_time = time(NULL);
	FILE* file;

	localtime_s(&current_tm, &current_time);
	sprintf_s(szTimestamp, "FATAL: %%s\n", current_tm.tm_hour, current_tm.tm_min, current_tm.tm_sec);

	va_start(va_alist, fmt);
	_vsnprintf_s(chParameters, sizeof(chParameters), fmt, va_alist);
	va_end(va_alist);
	sprintf_s(chLogBuff, szTimestamp, chParameters);
	if ((fopen_s(&file, g_debugLogFile, "a")) == 0)
	{
		fprintf_s(file, "%s", chLogBuff);
		fclose(file);
	}

	MessageBoxA(NULL, chLogBuff, "FATAL ERROR", MB_ICONERROR);

	ExitProcess(0);
}
