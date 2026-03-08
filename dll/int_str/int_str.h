/* int_str.h */

#ifndef INT_STR_H
#define INT_STR_H

#ifdef __cplusplus
extern "C" {
#endif
	__declspec(dllimport) char* change_int_to_str(int string);
	__declspec(dllimport) int free_str(char* str);

#ifdef __cplusplus
}
#endif

#endif /* INT_STR_H */