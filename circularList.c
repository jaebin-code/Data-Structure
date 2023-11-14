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
    struct _Node* next;
}Node;

typedef struct
{
    Node* tail;
    int len;
}CircularList;

void InsertInitItem(CircularList* plist, Data item);
void InsertFirst(CircularList* plist, Data item);
void InsertMiddle(CircularList* plist, int pos, Data item);
void InsertLast(CircularList* plist, Data item);
void RemoveInitItem(CircularList *plist);
void RemoveFirst(CircularList *plist);
void RemoveMiddle(CircularList *plist, int pos);
void RemoveLast(CircularList *plist);

int main(){
    return 0;
}

void InsertInitItem(CircularList *plist, Data item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> item = item;
    newNode -> next = newNode;
    plist -> tail = newNode;
    plist -> len = 0;
};
void InsertFirst(CircularList *plist, Data item){
    if(plist->len = 0){
        InsertInitItem(plist,item);
    }
    else{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->item = item;
        newNode->next = plist -> tail -> next;
        plist->tail->next = newNode;
        plist->len++;
    }
};
void InsertMiddle(CircularList *plist, int pos, Data item){
    if (plist->len == 0)
    {
        InsertInitItem(plist, item);
    }
    else{
        Node *cur = plist->tail;

        for(int i = 0; i<pos; i++){
            cur = cur->next;
        }
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->item = item;
        newNode->next = cur->next;
        cur->next = newNode;
        plist->len++;
    }
};
void InsertLast(CircularList *plist, Data item){
    if (plist->len == 0)
    {
        InsertInitItem(plist, item);
    }
    else{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->item = item;
        newNode->next = plist->tail->next;
        plist->tail->next = newNode->next;
        plist->tail = newNode;
        plist->len++;
    }
};
void RemoveInitItem(CircularList *plist){
    if (plist->len == 0)
    {
        exit(1);
    }
    else
    {
        free(plist->tail);
        plist->len--;
        plist->tail = NULL;
    }
};
void RemoveFirst(CircularList *plist){
    if (plist->len == 1)
    {
        RemoveInitItem(plist);
    }
    else
    {
        Node *temp;
        temp = plist->tail->next;
        plist->tail->next = plist->tail->next->next;
        free(temp);
        plist->len--;

    }
};
void RemoveMiddle(CircularList *plist, int pos){
    if (plist->len == 1){
        RemoveInitItem(plist);
    }
    else{
        Node *cur, *temp;
        cur = plist->tail;
        for(int i = 0; i<pos; i++){
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
        plist->len--;
    }
};
void RemoveLast(CircularList *plist){
    if (plist->len == 1)
    {
        RemoveInitItem(plist);
    }
    else
    {
        Node *cur, *temp;
        cur = plist->tail;
        for(int i = 0; i < plist->len-1; i++){
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = plist->tail->next;
        plist->tail = cur;
        free(temp);
        plist->len--;
    }
};