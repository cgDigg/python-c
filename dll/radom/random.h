// mylib.h
#pragma comment(lib, "radon.lib")
#ifndef MYLIB_H
#define MYLIB_H

#ifdef _WIN32
#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#else
#define MYLIB_API __declspec(dllimport)
#endif
#else
    // 支持 GCC/Clang（Linux/macOS）：默认无修饰
#define MYLIB_API
#endif

#ifdef __cplusplus
extern "C" {
#endif
    MYLIB_API int radom(int small_number, int large_number);
    MYLIB_API char radon_str(char* string, int index);
#ifdef __cplusplus
}
#endif

#endif // MYLIB_H