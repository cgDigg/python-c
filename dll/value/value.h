// value.h
#ifndef VALUE_H
#define VALUE_H

#include <stddef.h>  // for size_t

// 支持 Windows DLL 导出/导入
#ifdef _WIN32
#ifdef BUILDING_DLL
#define VALUE_API __declspec(dllexport)
#else
#define VALUE_API __declspec(dllimport)
#endif
#else
	// Linux/macOS 不需要特殊处理
#define VALUE_API
#endif

// 前向声明 ListNode（因为 List 要用它）
struct ListNode;

// 定义 List 结构体（对外暴露，方便调试；也可隐藏）
typedef struct {
	struct ListNode* head;
	size_t size;
} List;

// 完整定义 ListNode（内部节点）
typedef struct ListNode {
	char* data;               // 存储字符串
	struct ListNode* next;    // 指向下一个节点
} ListNode;

// =============== 函数接口声明 ===============
// 注意：所有函数操作的都是 List*（指针）

// 创建和销毁（
VALUE_API List* create_list(void);
VALUE_API void destroy_list(List* list);

// 添加元素
VALUE_API void list_push_back(List* list, const char* str);
VALUE_API void list_push_front(List* list, const char* str);

// 查询
VALUE_API char* get_element_(List* list, int index);           // 按索引取值
VALUE_API int get_index_(List* list, const char* element);     // 按值找索引

// 校验
VALUE_API int check_list_(List* list);                         // 是否结构合法

// 辅助
VALUE_API size_t list_size_(List* list);                       // 获取长度

#endif // VALUE_H