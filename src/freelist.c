#include <stddef.h>

#include "freelist.h"

FreeList freelist_init(void) {
    return (FreeList) {
        .head = NULL
    };
}

void freelist_push(FreeList* list, void* chunk) {
    FreeListNode* node = (FreeListNode*)chunk;
    node->next = list->head;
    list->head = node;
}

void* freelist_pop(FreeList* list) {
    if (!list->head) return NULL;
    FreeListNode* node = list->head;
    list->head = node->next;
    return (void*)node;
}

void freelist_reset(FreeList* list) {
    list->head = NULL;
}
