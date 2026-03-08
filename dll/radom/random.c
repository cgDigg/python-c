#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
__declspec(dllexport) int radom(int small_number, int large_number) {
	int min = small_number;
	int max = large_number;
	return min + rand() % (max - min + 1);
}
__declspec(dllexport) char radon_str(char* string, int index) {
	int ra = radom(0, strlen(string));
	char re = string[ra];
	return re;
}
__declspec(dllexport) int radon_strings(char* strings) {
	int len = strlen(strings) - 1;
    return radom(0, len);
}