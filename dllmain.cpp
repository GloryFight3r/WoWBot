#include <Windows.h>
#include "loadScreen.h"

VOID ExecWorkerRoutine() {
    //MessageBoxA(NULL, "DAS", "DAS", MB_OK);
    renderWindow();
}

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);

        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ExecWorkerRoutine, NULL, 0, NULL);
    }
    return TRUE;
}