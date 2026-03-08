#include "Python.h"
__declspec(dllexport) int init_python(void)
{
    Py_Initialize();
    return 0;
}
__declspec(dllexport) int exit_python(void)
{
    Py_Finalize();
    return 0;
}
    __declspec(dllexport) int run_python(char *file)
{
        PyRun_SimpleFileExFlags((file), ("python.py"), 0, ((void*)0));
    return 0;
}   
    __declspec(dllexport) int run_python_string(char *code)
{
        PyRun_SimpleStringFlags((code), ((void*)0));
    return 0;
}
    __declspec(dllexport) void cmd_python() {
        PyRun_InteractiveLoopFlags(((__acrt_iob_func(0))), ("<stdin>"), ((void*)0));
}
