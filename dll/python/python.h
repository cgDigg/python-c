#ifndef PYTHON_EMBED_H
#define PYTHON_EMBED_H
#pragma comment(lib, "python.lib")
#ifdef __cplusplus
extern "C" {
#endif

    // 函数声明（与实现中的 __declspec(dllexport) 对应）
    // 在 DLL 中导出，在使用方通过 __declspec(dllimport) 导入（可选）

#ifdef PYTHON_EMBED_EXPORTS
#define PYTHON_API __declspec(dllexport)
#else
#define PYTHON_API __declspec(dllimport)
#endif

    PYTHON_API int init_python(void);
    PYTHON_API int exit_python(void);
    PYTHON_API int run_python(char* file);
    PYTHON_API int run_python_string(char* code);
    PYTHON_API void cmd_python();
#ifdef __cplusplus
}
#endif

#endif // PYTHON_EMBED_H