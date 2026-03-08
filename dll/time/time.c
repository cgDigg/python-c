#include <time.h>
#define a __declspec(dllexport)
struct tm get_utc_time(void) {
    time_t rawtime;
    time(&rawtime);
    return *gmtime(&rawtime);  // gmtime 返回 UTC 时间
}

// 获取本地时间（struct tm）
struct tm get_local_time(void) {
    time_t rawtime;
    time(&rawtime);
    return *localtime(&rawtime);  // localtime 返回本地时间
}

// 以下函数默认使用本地时间（你也可以改为 UTC，只需替换 localtime 为 gmtime）

a int get_current_year(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_year + 1900;  // tm_year 是从 1900 开始的偏移
}

a int get_current_month(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_mon + 1;      // tm_mon 范围是 0~11，所以 +1
}

a int get_current_day(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_mday;         // tm_mday: 1~31
}

a int get_current_hour(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_hour;         // 0~23
}

a int get_current_minute(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_min;          // 0~59
}

a int get_current_second(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_sec;          // 0~60（支持闰秒）
}