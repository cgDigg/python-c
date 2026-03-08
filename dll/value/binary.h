// binary_utils.h
#ifndef BINARY_UTILS_H
#define BINARY_UTILS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


#define API __declspec(dllexport)

	/**
	 * 将非负整数转换为二进制字符串
	 * @param number: 输入的非负整数
	 * @param buffer: 输出缓冲区（调用者分配）
	 * @param buffer_size: 缓冲区大小（至少应为 65 字节以支持 64 位）
	 * @return: 成功返回 0，失败返回 -1
	 */
	API int int_to_binary(uint64_t number, char* buffer, size_t buffer_size);

	/**
	 * 将二进制字符串转换为整数
	 * @param binary_str: 输入的二进制字符串（仅含 '0'/'1'）
	 * @param result: 输出整数指针
	 * @return: 成功返回 0，失败返回 -1
	 */
	API int binary_to_int(const char* binary_str, uint64_t* result);

#ifdef __cplusplus
}
#endif

#endif // BINARY_UTILS_H