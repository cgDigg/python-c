// utils_dll.c
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_INPUT_LEN 256

// 1. 控制台错误打印
__declspec(dllexport) int __stdcall error_(const char* error_information) {
	if (error_information) {
		printf("Error: %s\n", error_information);
	}
	return 0;
}

// 2. 弹窗错误提示
__declspec(dllexport) int __stdcall error_w(const char* error_information, const char* error_title) {
	MessageBoxA(
		NULL,
		error_information ? error_information : "Unknown error",
		error_title ? error_title : "Error",
		MB_ICONERROR | MB_OK
	);
	return 0;
}

// 3. 隐藏输入（无回显）
__declspec(dllexport) BOOL __stdcall hide_question(
	const char* question,
	char* output_buffer,
	size_t buffer_size
) {
	if (!output_buffer || buffer_size == 0) return FALSE;
	if (!question) question = "";

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode, old_mode;

	if (!GetConsoleMode(hStdin, &mode)) {
		return FALSE;
	}

	old_mode = mode;
	SetConsoleMode(hStdin, mode & ~ENABLE_ECHO_INPUT);

	printf("%s", question);
	fflush(stdout);

	output_buffer[0] = '\0';
	if (fgets(output_buffer, (int)buffer_size, stdin) == NULL) {
		SetConsoleMode(hStdin, old_mode);
		return FALSE;
	}

	SetConsoleMode(hStdin, old_mode);

	// 去掉换行符（兼容 \r\n 和 \n）
	size_t len = strlen(output_buffer);
	if (len > 0 && output_buffer[len - 1] == '\n') {
		output_buffer[len - 1] = '\0';
		if (len > 1 && output_buffer[len - 2] == '\r') {
			output_buffer[len - 2] = '\0';
		}
	}

	printf("\n");
	return TRUE;
}

// 4. 带 * 显示的密码输入
__declspec(dllexport) int __stdcall hide_and_with(
	const char* question,
	char* output_buffer,
	size_t buffer_size,
	char hide_char
) {
	if (!output_buffer || buffer_size == 0) return -1;
	if (!question) question = "";

	printf("%s", question);
	fflush(stdout);

	size_t i = 0;
	int ch;

	while (i < buffer_size - 1) {
		ch = _getch();

		if (ch == '\r' || ch == '\n') {
			break;
		}
		else if (ch == '\b' || ch == 127) {
			if (i > 0) {
				printf("\b \b");
				fflush(stdout);
				i--;
			}
		}
		else if (ch >= 32 && ch <= 126) {
			output_buffer[i++] = (char)ch;
			putchar(hide_char);
			fflush(stdout);
		}
		// 忽略控制字符、方向键等
	}

	output_buffer[i] = '\0';
	printf("\n");
	return (int)i;
}

// 5. 获取命令行参数个数
__declspec(dllexport) int __stdcall get_argc() {
	int argc;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (argv) LocalFree(argv);
	return argc;
}

// 6. 获取第 index 个命令行参数（UTF-8 编码）
__declspec(dllexport) BOOL __stdcall get_argv(int index, char* buffer, int buffer_size) {
	if (!buffer || buffer_size <= 0) return FALSE;

	int argc;
	LPWSTR* wargv = CommandLineToArgvW(GetCommandLineW(), &argc);

	if (!wargv || index < 0 || index >= argc) {
		if (wargv) LocalFree(wargv);
		return FALSE;
	}

	int len = WideCharToMultiByte(CP_UTF8, 0, wargv[index], -1, buffer, buffer_size, NULL, NULL);
	LocalFree(wargv);

	return (len > 0 && len <= buffer_size);
}

// 7. 【新增】等待并返回用户按下的键
// 返回值说明：
//   > 0: 普通 ASCII 字符（如 'a'=97）
//   < 0: 特殊键（如 -72 表示 ↑，-80 表示 ↓）
//   0: 错误或未知
__declspec(dllexport) int __stdcall wait_for_key() {
	int ch = _getch();

	if (ch == 0 || ch == 0xE0) {
		int ext = _getch();
		return -ext; // 用负数表示扩展键
	}

	return ch;
}

// DllMain（可选）
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
__declspec(dllexport) int __stdcall keybord_getch() {
	return _getch();
}
__declspec(dllexport) int Error_windows(const char* Error) {
	MessageBoxA(
		NULL,
		Error,
		"Error!",
		MB_ICONERROR | MB_OK
	);
	return 0;
}
__declspec(dllexport) const char* string_add(const char* string1, const char* string2,int butter_size) {
	char* butter=(char*)malloc(butter_size);
	if (butter_size>strlen(string1)+strlen(string2))
	{
		snprintf(butter, (size_t)butter_size, "%s%s", string1, string2);
		return butter;
	}
	else {
		return NULL;
	}

}
__declspec(dllexport) void free_string(char* address) {
	free(address);
}
__declspec(dllexport) int print(const char* string) {
	printf(string);
	return 0;
}
// 1. 定义回调函数的类型：无参，返回 char*
typedef char* (*CallbackFunc)(void);

// 2. 定义 DLL 中目标函数的类型：接受 CallbackFunc，返回 char*
typedef char* (*DllFunction)(CallbackFunc);

// 3. 回调函数示例
char* my_callback(void) {
	return "Hello from callback!";
}

// 4. 导出函数（如果你在写另一个 DLL，可加 __declspec(dllexport)）
__declspec(dllexport) int run_dll_no_header(const char* dll_name, const char* function_name) {
	HMODULE hDll = LoadLibraryA(dll_name);
	if (!hDll) {
		MessageBoxA(NULL, "Cannot load DLL", "Error", MB_ICONERROR | MB_OK);
		return -1;
	}

	// 获取 DLL 中的函数地址
	DllFunction func = (DllFunction)GetProcAddress(hDll, function_name);
	if (!func) {
		MessageBoxA(NULL, "Cannot find function in DLL", "Error", MB_ICONERROR	 | MB_OK);
		FreeLibrary(hDll);
		return -2;
	}

	// 调用 DLL 函数，传入回调
	char* result = func(my_callback);
	if (result) {
		MessageBoxA(NULL, result, "Result", MB_OK);
	}

	// 注意：如果 DLL 返回的 result 是由 DLL 分配的内存，
	// 你可能需要 DLL 提供 free 函数来释放，否则可能崩溃！

	FreeLibrary(hDll); // 如果不再需要 DLL，可以释放
	return 0;
}
__declspec(dllexport) int show_hide_cursor(int mode) {
	HANDLE consoleHandle = GetStdHandle(((DWORD)-11));
	CONSOLE_CURSOR_INFO info;
	if (mode==1)
	{
		info.bVisible = TRUE;
		return 1;
	}
	else {
		if (mode==0)
		{
			info.bVisible = FALSE;
			return 0;
		}
		else {
			return -1;
		}
	}
}
__declspec(dllexport) int show_message(char* title, char* imformation, long enter) {
	MessageBoxA(
		NULL,
		imformation,
		title,
		enter
	);
	return 1;
}
__declspec(dllexport) int check(const char* string1, const char* string2) {
	if (string1 == NULL || string2 == NULL) {
		return 0; // 或根据需求处理空指针
	}
	return (strcmp(string1, string2) == 0) ? 1 : 0;
}
