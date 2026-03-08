// your_source.c
#include <string.h>
#include <windows.h>  // 如果只用标准库，其实可以去掉
#include "value_.h"
// 1. 通过索引获取元素
__declspec(dllexport) char* get_element_(List* list, int index) {
	if (list == NULL || index < 0 || (size_t)index >= list->size) {
		return NULL;
	}
	ListNode* current = list->head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;  // 注意：调用者不能 free！
}

// 2. 通过元素值查找索引
__declspec(dllexport) int get_index_(List* list, const char* element) {
	if (list == NULL || element == NULL) {
		return -1;  // 用 -1 表示未找到（不是 0！）
	}

	ListNode* current = list->head;
	int index = 0;

	while (current != NULL) {
		if (strcmp(current->data, element) == 0) {
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;  // 修复：不能 return "None"
}

// 3. 检查列表是否规范
__declspec(dllexport) int check_list_(List* list) {
	if (list == NULL) {
		return 0;
	}

	// 空列表必须 size == 0
	if (list->head == NULL) {
		return (list->size == 0) ? 1 : 0;
	}

	if (list->size == 0) {
		return 0; // 非空头但 size 为 0，非法
	}

	// 第一步：检测环（Floyd）
	ListNode* slow = list->head;
	ListNode* fast = list->head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return 0; // 有环
		}
	}

	// 第二步：遍历计数并检查 data 是否合法
	size_t count = 0;
	ListNode* current = list->head;
	while (current != NULL) {
		if (current->data == NULL) {
			return 0; // 节点数据为空，非法
		}
		count++;
		current = current->next;
	}

	return (count == list->size) ? 1 : 0;
}
__declspec(dllexport) void add_element(List* list, const char* element) {
	if (list == NULL || element == NULL) return;

	// 创建新节点
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) return; // 内存分配失败

	// 复制字符串内容（避免悬空指针）
	size_t len = strlen(element) + 1;
	newNode->data = (char*)malloc(len);
	if (newNode->data == NULL) {
		free(newNode);
		return;
	}
	strcpy_s(newNode->data, len, element);

	// 插入到头部
	newNode->next = list->head;
	list->head = newNode;
	list->size++;
}
// binary_utils.c
#include "binary.h"
#include <string.h>
#include <stdio.h>
__declspec(dllexport) int int_to_binary(uint64_t number, char* buffer, size_t buffer_size)
{
	if (buffer == NULL || buffer_size == 0) {
		return -1;
	}

	if (number == 0) {
		if (buffer_size < 2) return -1; // 至少需要 "0\0"
		buffer[0] = '0';
		buffer[1] = '\0';
		return 0;
	}

	char temp[65]; // 64 bits + '\0'
	int index = 0;

	while (number > 0) {
		temp[index++] = (number & 1) ? '1' : '0';
		number >>= 1;
	}

	// 检查目标缓冲区是否足够
	if ((size_t)index + 1 > buffer_size) {
		return -1; // 缓冲区太小
	}

	// 反向复制到 buffer（因为 temp 是低位在前）
	for (int i = 0; i < index; i++) {
		buffer[i] = temp[index - 1 - i];
	}
	buffer[index] = '\0';

	return 0;
}

__declspec(dllexport) int binary_to_int(const char* binary_str, uint64_t* result)
{
	if (binary_str == NULL || result == NULL) {
		return -1;
	}

	size_t len = strlen(binary_str);
	if (len == 0) {
		return -1;
	}

	uint64_t value = 0;

	for (size_t i = 0; i < len; i++) {
		char c = binary_str[i];
		if (c == '0') {
			// value = value * 2 + 0;
			if (value > UINT64_MAX / 2) {
				return -1; // 溢出
			}
			value <<= 1;
		}
		else if (c == '1') {
			if (value > (UINT64_MAX - 1) / 2) {
				return -1; // 溢出
			}
			value = (value << 1) | 1;
		}
		else {
			return -1; // 非法字符
		}
	}

	*result = value;
	return 0;
}