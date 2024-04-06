#include "stdafx.h"
#include "Hooking.h"
#include "return_spoof.hpp"

static NativeManagerContext g_context;

static UINT64 g_hash;

void(*scrNativeCallContext::SetVectorResults)(scrNativeCallContext*) = nullptr;

void nativeInit(UINT64 hash) {

	g_context.Reset();
	g_hash = hash;
}

void nativePush64(UINT64 value) {

	g_context.Push(value);
}

uint64_t* nativeCall()
{
	auto fn = Foxy_Engine::GetNativeHandler(g_hash);

	if (fn != nullptr)
	{
		static void* exceptionAddress;

		__try
		{
			spoof_call(Foxy_Engine::invoker_return_address, fn, (scrNativeCallContext*)(&g_context));
			scrNativeCallContext::SetVectorResults(&g_context);
		}
		__except (exceptionAddress = (GetExceptionInformation())->ExceptionRecord->ExceptionAddress, EXCEPTION_EXECUTE_HANDLER)
		{
			AllocConsole();
			freopen("conin$", "r", stdin);
			freopen("conout$", "w", stdout);
			freopen("conout$", "w", stderr);
			printf("executing native 0x%016llx at address %p.\n", g_hash, exceptionAddress);
            WAIT(1000);
		}
	}

	return reinterpret_cast<uint64_t*>(g_context.GetResultPointer());
}
