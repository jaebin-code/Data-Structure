#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;
typedef int Data;

typedef struct _Node{
    Data item;
    struct _Node* prev;
    struct _Node* next;
}Node;

typedef struct{
    Node* head;
    int len;
}DoubleLinkedList;

void InitList(DoubleLinkedList *plist);