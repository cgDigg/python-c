#include <stdlib.h>
#include <stdio.h>
#define dll __declspec(dllexport)
extern "C" {
	__declspec(dllexport) char* change_int_to_str(int string) {
		char* re;
		re = (char*)malloc(32);
		if (re) {
			snprintf(re, 32, "%d", string);
		}
		return re;
	}
	__declspec(dllexport) int free_str(char* str) {
		str=(char*)malloc(32);
		free(str);
		return 0;
	}
	__declspec(dllexport) char* add(const char* string1, const char* string2) {
		char cmd[256];
		snprintf(cmd, sizeof(cmd), string1, string2);
		return cmd;
	}
}