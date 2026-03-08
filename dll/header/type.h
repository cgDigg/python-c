#include <windows.h>
typedef struct Any {} Any;
typedef char* str;
typedef short int16;
typedef int int32;
typedef long int64;
typedef void None;
#define NONE ((None)0)
#define MAGIC_NUMBER 0xDEADBEEF
#define MAGIC_NUMBER_SIZE sizeof(MAGIC_NUMBER)
#define MAGIC_NUMBER_OFFSET (sizeof(int32))
#define MAGIC_NUMBER_END (MAGIC_NUMBER_OFFSET + MAGIC_NUMBER_SIZE)
#define MAGIC_NUMBER_CHECK(ptr) (*(int32*)(ptr) == MAGIC_NUMBER)
#define MAGIC_NUMBER_SET(ptr) (*(int32*)(ptr) = MAGIC_NUMBER)
#define TYPE_MAGIC_NUMBER 0xDEADBEEF
#define TYPE_MAGIC_NUMBER_SIZE sizeof(TYPE_MAGIC_NUMBER)
#define def __declspec(dllexport)
#define strdef def str
#define import __declspec(dllimport)
#define anydef def Any
#define NONEdef def None
#define bytedef def int32
#define shortdef def int16
#define intdef def int64
#define bool __stdcall
#define normal_return return 0
#define error_return return -1
#define normal_return_void return