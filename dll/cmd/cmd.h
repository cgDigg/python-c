#ifndef CBUILD_UTILS_H
#define CBUILD_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef BUILDING_DLL
#define DEF_API __declspec(dllexport)
#else
#define DEF_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

    DEF_API int free_sth(void* ptr);
    DEF_API int cmd(char* command);
    DEF_API int copy(const char* src, const char* des);
    DEF_API int move(const char* src, const char* des);
    DEF_API int Rename(const char* src, const char* des);
    DEF_API int rmfile(const char* path);
    DEF_API int rmdir(const char* path);
    DEF_API int mkdir(const char* path);
    DEF_API int input(const char* question, char* buffer, int buffer_size);

#ifdef __cplusplus
}
#endif

#endif // CBUILD_UTILS_H