#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "type.h"
#define def __declspec(dllexport)
def int input(str prompt) {
	printf("%s", prompt);
	char input[100];
	scanf("%s", input);
	return input;
}
__declspec(dllexport) int strings_check(char* string1, char* string2) {
	if (string1 == ((void*)0) || string2 == ((void*)0))
	{
		return -1;
	}
	return (strcmp(string1, string2) == 0) ? 1 : 0;
}
def int output(str strings) {
	printf("%s", strings);
	return 0;
}

def int print(str strings) {
	printf("%s", strings);
	return 0;
}

