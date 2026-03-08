#include <stdio.h>
#include <string.h>
#include <stdlib.h>
__declspec(dllexport) int string_length(const char *str) {
	if (str == ((void*)0)) {
		return -1; // Return -1 for NULL strings
	}
	return strlen(str);
}
__declspec(dllexport) int strings_check(char* string1, char* string2) {
	if (string1 == ((void*)0) | string2 == ((void*)0))
	{
		return -1;
	}
	return (strcmp(string1, string2) == 0) ? 1 : 0;
}
__declspec(dllexport) const char* string_add(char* string1,char* string2, int butter_size) {
	if (string1 == ((void*)0) || string2 == ((void*)0)) {
		return NULL; // Return NULL for NULL strings
	}
	char* butter = (char*)malloc(butter_size);
	if (butter_size > strlen(string1) + strlen(string2)) {
		snprintf(butter, (size_t)butter_size, "%s%s", string1, string2);
		return butter;
	} else {
		free(butter); // Free memory if not enough space
		return NULL;
	}
}
__declspec(dllexport) void string_free(const char* str) {
	if (str != ((void*)0)) {
		free((void*)str); // Cast to void* for free
	}
}
