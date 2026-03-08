// time_utils.h
#pragma comment(lib, "time.lib")
#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#ifdef _WIN32
#ifdef TIME_UTILS_EXPORTS
    // 编译 DLL 时定义 TIME_UTILS_EXPORTS，导出函数
#define TIME_API __declspec(dllexport)
#else
    // 使用 DLL 时不定义，导入函数
#define TIME_API __declspec(dllimport)
#endif
#else
    // 非 Windows（如 Linux/macOS）使用 GCC/Clang，不需要 __declspec
#define TIME_API
#endif

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

    // 获取 UTC 时间结构体（值拷贝）
    TIME_API struct tm get_utc_time(void);

    // 获取本地时间结构体
    TIME_API struct tm get_local_time(void);

    // 获取当前时间各分量（默认本地时间）
    TIME_API int get_current_year(void);
    TIME_API int get_current_month(void);
    TIME_API int get_current_day(void);
    TIME_API int get_current_hour(void);
    TIME_API int get_current_minute(void);
    TIME_API int get_current_second(void);

#ifdef __cplusplus
}
#endif

#endif // TIME_UTILS_H