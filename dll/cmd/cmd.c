#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define def __declspec(dllexport)

def int free_sth(void* ptr) {
    if (!ptr) return -1;
    free(ptr) ;
    return 0;
}
def int cmd(char* command) {
    if (!command) return -1;
    int ret = system(command);
    return (ret == 0) ? 0 : -1;
}

def int copy(const char* src, const char* des) {
    if (!src || !des) return -1;
    return CopyFileA(src, des, FALSE) ? 0 : -1;
}

def int move(const char* src, const char* des) {
    if (!src || !des) return -1;
    return MoveFileA(src, des) ? 0 : -1;
}

def int Rename(const char* src, const char* des) {
    return move(src, des);
}

def int rmfile(const char* path) {
    if (!path) return -1;
    return DeleteFileA(path) ? 0 : -1;
}

def int rmdir(const char* path) {
    if (!path) return -1;
    return RemoveDirectoryA(path) ? 0 : -1;
}

def int mkdir(const char* path) {
    if (!path) return -1;
    return CreateDirectoryA(path, NULL) ? 0 : -1;
}
def char* input(char* question) {
    if (!question) return -1;
    printf("%s", question);
    char buf[1024];
    fgets(buf, 1024, (__acrt_iob_func(0)));
    return buf;
}