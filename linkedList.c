#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int Data;

typedef struct _Node{
    Data item;
    struct _Node* next;
}Node;

typedef struct{
    Node* head;
    int len;
} LinkedList;

void InitList(LinkedList *plist);

bool IsEmpty(LinkedList *plist);

void InsertMiddle(LinkedList *plist, int pos, Data item);

void RemoveMiddle(LinkedList *plist, int pos);

Data ReadItem(LinkedList *plist, int pos);

void PrintList(LinkedList *plist);

void ClearList(LinkedList *plist);

void RemoveFirst(LinkedList *plist);

LinkedList* Concatenate(LinkedList * plist1, LinkedList* plist2);

void Reverse(LinkedList* plist);

int main(){
    return 0;
}

void InitList(LinkedList *plist){
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->len = 0;

};

bool IsEmpty(LinkedList *plist){
    return plist -> len == 0;
};

void InsertMiddle(LinkedList *plist, int pos, Data item){
    Node* cur, *newNode;
    if(pos<0 | pos>plist->len){
        exit(1);
    }

    newNode=(Node *)malloc(sizeof(Node));
    newNode -> item = item;
    newNode -> next = NULL;

    cur = plist->head;
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    plist -> len++;
};

void RemoveMiddle(LinkedList *plist, int pos){
    Node* cur, *temp;
    if(pos<0 || pos>=plist->len){
        exit(1);
    }
    cur = plist->head;

    for(int i = 0; i<pos;i++){
        cur=cur->next;
    }
    temp=cur->next;
    cur->next=cur->next->next;
    plist->len--;
    free(temp);
};

Data ReadItem(LinkedList *plist, int pos){
    Node *cur;
    if(pos < 0 || pos >= plist->len){
        exit(1);
    }
    cur = plist->head->next;
    for(int i = 0; i<pos; i++){
        cur=cur->next;
    }
    return cur->item;
};

void PrintList(LinkedList *plist){

    for(Node* cur = plist->head->next; cur != NULL ; cur=cur->next){
        printf("%d", cur->item);
    }
};

void ClearList(LinkedList *plist){
    while(plist->head->next!=NULL){
        RemoveFirst(plist);
    }
    free(plist->head);
};

void RemoveFirst(LinkedList *plist){
    if(IsEmpty(plist)){
        exit(1);
    }
    Node *cur, *temp;
    cur = plist->head;
    temp = plist->head->next;
    cur -> next = cur -> next -> next;
    plist->len--;
    free(temp);
};

LinkedList *Concatenate(LinkedList *plist1, LinkedList *plist2){
    if(plist1->head = NULL){
        return plist2;
    }
    else if(plist2->head = NULL){
        return plist1;
    }
    else{
        Node *cur;
        cur = plist1->head->next;
        while(cur != NULL){
            cur = cur -> next;
        }
        cur -> next = plist2->head->next;
        plist1 -> len += plist2 -> len;
        free(plist2->head);
        return plist1;
        }
};

void Reverse(LinkedList *plist){
    Node *prev, *cur, *next;
    prev = NULL;
    cur = NULL;
    next = plist->head->next;
    while(next != NULL){
        prev = cur;
        cur = next;
        next = next -> next;
        cur->next = prev;
    }
    plist->head->next=cur;
};
