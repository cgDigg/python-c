#include <windows.h>
#ifndef LIBRARY_H
#define LIBRARY_H
#if _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif
__declspec(dllexport)  int dll_run_int(char* dll, char* function_, char* arg) {
	if (!dll || !function_) {
		MessageBoxA(
			NULL,
			"Error: invalid arguments",
			"Error",
			MB_OK | MB_ICONERROR
		);
		return 1;
	}

	HMODULE Hdll = LoadLibraryA(dll);
	if (!Hdll) {
		MessageBoxA(
			NULL,
			"Error: could not load DLL",
			"Error",
			0x00000000L | 0x00000010L
		);
		return 1;
	}
	typedef int (*fun)(char*);
	fun func = (fun)GetProcAddress(Hdll, function_);
	if (!func) {
		MessageBoxA(
			NULL,
			"Error: could not find function",
			"Error",
			MB_OK | MB_ICONERROR
		);
		FreeLibrary(Hdll);
		return 1;
	}
	int result = func(arg);

	FreeLibrary(Hdll);
	return result;
}
#endif