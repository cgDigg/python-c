#ifndef FUNCTION_H
#define FUNCTION_H
#pragma conment(lib, "function.lib")
#ifdef __cplusplus
extern "C" {
#endif
#include <windows.h>
#ifdef UTILS_DLL_STATIC
#define UTILS_API
#else
#ifdef UTILS_DLL_EXPORTS
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif
#endif

	__declspec(dllimport) int __stdcall error_(const char* error_information);
	__declspec(dllimport) int __stdcall error_w(const char* error_information, const char* error_title);
	__declspec(dllimport) BOOL __stdcall hide_question(const char* question,char* output_buffer,size_t buffer_size);
	__declspec(dllimport) int __stdcall hide_and_with(const char* question,char* output_buffer,size_t buffer_size,char hide_char);
	__declspec(dllimport) int __stdcall get_argc(void);
	__declspec(dllimport) BOOL __stdcall get_argv(int index, char* buffer, int buffer_size);
	__declspec(dllimport) int __stdcall wait_for_key(void);
	__declspec(dllimport) int __stdcall keybord_getch();
	__declspec(dllimport) int Error_windows(const char* Error);
	__declspec(dllimport) const char* string_add(const char* string1, const char* string2, int butter_size);
	__declspec(dllimport) void free_string(char* address);
	typedef char* (*CallbackFunc)(void);
	typedef char* (*DllFunction)(CallbackFunc);
	__declspec(dllimport) int run_dll_no_header(const char* dll_name, const char* function_name);
	__declspec(dllimport) int show_hide_cursor(int mode);
	__declspec(dllimport) int show_message(char* title, char* imformation, long enter);
	__declspec(dllimport) int check(const char* string1, const char* string2);

#ifdef __cplusplus
}
#endif

#endif // UTILS_DLL_H