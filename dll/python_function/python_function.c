// python_function.c
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>

static char* str_concat(const char* a, const char* b) {
	if (!a) a = "";
	if (!b) b = "";
	size_t len = strlen(a) + strlen(b) + 1;
	char* buf = (char*)malloc(len);
	if (buf) {
		strcpy_s(buf, len, a);
		strcat_s(buf, len, b);
	}
	return buf;
}

__declspec(dllexport) int add_(int number1, int number2) {
	return number1 + number2;
}

__declspec(dllexport) int cmd_run(const char* cmd) {
	if (!cmd) return -1;
	return system(cmd);
}

__declspec(dllexport) int python_in_path_check(void) {
	int result = system("python -c \"print('ok')\" > nul 2>&1");
	return (result == 0) ? 1 : 0;
}

__declspec(dllexport) int print_str(const char* string) {
	if (string) {
		fputs(string, stdout);
		fflush(stdout);
	}
	return 0;
}

__declspec(dllexport) int time_down(int time_ms) {
	Sleep(time_ms);
	return 0;
}

__declspec(dllexport) int start_python(void) {
	return python_in_path_check();
}

__declspec(dllexport) int multiply(int a, int b) {
	int result = 0;
	int i;
	for (i = 0; i < b; i++) {
		result += a;
	}
	return result;
}

__declspec(dllexport) int strings_equal(char* string1, char* string2) {
	if (!string1 && !string2) return 1;
	if (!string1 || !string2) return 0;
	return (strcmp(string1, string2) == 0) ? 1 : 0;
}

__declspec(dllexport) int python_run_module(char* module_) {
	char* cmd;
	int result;

	if (!module_) {
		print_str("Error: module is NULL\n");
		return 1;
	}

	if (!start_python()) {
		print_str("No Python in system PATH\n");
		return 1;
	}

	cmd = str_concat("python -m ", module_);
	if (!cmd) {
		print_str("Out of memory\n");
		return 1;
	}

	result = system(cmd);
	free(cmd);
	return result;
}
__declspec(dllexport) int dll_run_int(char* dll, char* function_, char* arg) {
	if (!dll || !function_) {
		print_str("Error: dll or function name is NULL\n");
		return 1;
	}

	HMODULE Hdll = LoadLibraryA(dll);
	if (!Hdll) {
		print_str("Error: could not load DLL\n");
		return 1;
	}
	typedef int (*fun)(char*);
	fun func = (fun)GetProcAddress(Hdll, function_);
	if (!func) {
		print_str("Error: could not find function in DLL\n");
		FreeLibrary(Hdll);
		return 1;
	}
	int result = func(arg);

	FreeLibrary(Hdll);
	return result;
}
__declspec(dllexport) int error(char* have_father_windows, char* title, char* message_) {
	HWND hwnd = NULL;
	if (have_father_windows != NULL && strcmp(have_father_windows, "NULL") != 0) {
		MessageBoxA(
			((void*)0),
			message_ ? message_ : "(null)",
			title ? title : "Error",
			0x00000010L | 0x00000000L
		);
	}
		return 1;
}