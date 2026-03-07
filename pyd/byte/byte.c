// mybin.c
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static PyObject*
byte_int_to_binary(PyObject* self, PyObject* args)
{
    long long number;
    if (!PyArg_ParseTuple(args, "L", &number)) {
        return NULL;
    }

    if (number < 0) {
        PyErr_SetString(PyExc_ValueError, "Input must be a non-negative integer");
        return NULL;
    }

    if (number == 0) {
        return PyUnicode_FromString("0");
    }

    // 计算二进制位数（最多64位）
    char buffer[65]; // 64 bits + '\0'
    int index = 0;
    unsigned long long n = (unsigned long long)number;

    while (n > 0) {
        buffer[index++] = (n & 1) ? '1' : '0';
        n >>= 1;
    }

    // 反转
    char result[65];
    for (int i = 0; i < index; i++) {
        result[i] = buffer[index - 1 - i];
    }
    result[index] = '\0';

    return PyUnicode_FromString(result);
}

// binary_to_int: 二进制字符串 → 整数
static PyObject*
byte_binary_to_int(PyObject* self, PyObject* args)
{
    const char* binary_str;
    if (!PyArg_ParseTuple(args, "s", &binary_str)) {
        return NULL;
    }

    if (binary_str == NULL || strlen(binary_str) == 0) {
        PyErr_SetString(PyExc_ValueError, "Input string is empty or NULL");
        return NULL;
    }

    uint64_t value = 0;
    size_t len = strlen(binary_str);

    for (size_t i = 0; i < len; i++) {
        char c = binary_str[i];
        if (c == '0') {
            if (value > UINT64_MAX / 2) {
                PyErr_SetString(PyExc_OverflowError, "Binary string too large (overflow)");
                return NULL;
            }
            value <<= 1;
        }
        else if (c == '1') {
            if (value > (UINT64_MAX - 1) / 2) {
                PyErr_SetString(PyExc_OverflowError, "Binary string too large (overflow)");
                return NULL;
            }
            value = (value << 1) | 1;
        }
        else {
            PyErr_SetString(PyExc_ValueError, "Invalid character in binary string");
            return NULL;
        }
    }

    // Python int 支持任意精度，但这里 value 是 uint64_t
    // 使用 PyLong_FromUnsignedLongLong 安全转换
    return PyLong_FromUnsignedLongLong(value);
}

// 方法表
static PyMethodDef MyBinMethods[] = {
    {"int_to_binary",  byte_int_to_binary, METH_VARARGS, "Convert non-negative int to binary string"},
    {"binary_to_int",  byte_binary_to_int, METH_VARARGS, "Convert binary string to integer"},
    {NULL, NULL, 0, NULL}
};

// 模块定义
static struct PyModuleDef mybinmodule = {
    PyModuleDef_HEAD_INIT,
    "byte",           // 模块名
    "A binary conversion module written in C.", // 文档
    -1,
    MyBinMethods
};

// 初始化函数（必须命名为 PyInit_<模块名>）
PyMODINIT_FUNC
PyInit_byte(void)
{
    return PyModule_Create(&mybinmodule);
}