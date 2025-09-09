#ifndef FREELIST_H
#define FREELIST_H

typedef struct FreeListNode {
    struct FreeListNode* next;
} FreeListNode;

typedef struct FreeList {
    FreeListNode *head;
} FreeList;

FreeList freelist_init(void);
void freelist_push(FreeList* list, void* chunk);
void* freelist_pop(FreeList* list);

#endif // FREELIST_H
