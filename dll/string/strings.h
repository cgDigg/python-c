#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#pragma comment(lib, "string.lib")
#ifdef __cplusplus
extern "C" {
#endif
	__declspec(dllimport) int string_length(const char* str);
	__declspec(dllimport) int strings_check(char* string1, char* string2);
	__declspec(dllimport) const char* string_add(char* string1, char* string2, int butter_size);
	__declspec(dllimport) void string_free(const char* str);
#ifdef __cplusplus
}
#endif

#endif // STRING_UTILS_H