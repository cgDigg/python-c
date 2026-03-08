// value.h
// value_.h
#ifndef VALUE__H
#define VALUE__H

#include <stddef.h> // for size_t

typedef struct ListNode {
    char* data;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    size_t size;
} List;

#ifdef __cplusplus
extern "C" {
#endif


#define VALUE_API __declspec(dllexport)


    VALUE_API char* get_element_(List* list, int index);
    VALUE_API int get_index_(List* list, const char* element);
    VALUE_API int check_list_(List* list);
    VALUE_API void add_element(List* list, const char* element);

#ifdef __cplusplus
}
#endif

#endif // VALUE__H