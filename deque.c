#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE 100

typedef int Data;

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    int front, rear;
    Data items[MAX_DEQUE];
} Deque;

void InitDeque(Deque *deque);

bool IsFull(Deque *deque);

bool IsEmpty(Deque *deque);

Data PeekFront(Deque *deque);

Data PeekRear(Deque *deque);

void AddFront(Deque *deque, Data item);

void AddRear(Deque *deque, Data item);

void RemoveFront(Deque *deque);

void RemoveRear(Deque *deque);

int main(){

    return 0;
}

void InitDeque(Deque *deque){
    deque -> front = deque -> rear = 0;
};

bool IsFull(Deque *deque){
    return deque -> front == (deque -> rear + 1) % MAX_DEQUE;
};

bool IsEmpty(Deque *deque){
    return deque -> front == deque -> rear;
};

Data PeekFront(Deque *deque){
    if(IsEmpty(deque))
    {
        exit(1);
    }
    return deque -> items[deque -> front];
};

Data PeekRear(Deque *deque){
    if(IsEmpty(deque))
    {
        exit(1);
    }
    return deque -> items[deque -> rear];
};

void AddFront(Deque *deque, Data item){
    if(IsFull(deque))
    {
        exit(1);
    } 
    deque -> front = (deque -> front -1 + MAX_DEQUE) % MAX_DEQUE;
    deque -> items[deque -> front] = item;
};

void AddRear(Deque *deque, Data item){
    if(IsFull(deque))
    {
        exit(1);
    }
    deque->items[deque->rear] = item;
    deque->rear = (deque->rear + 1) % MAX_DEQUE;
};

void RemoveFront(Deque *deque){
    if(IsEmpty(deque)){
        exit(1);
    }
    deque -> front = (deque -> front + 1) % MAX_DEQUE;
};

void RemoveRear(Deque *deque){
    if(IsEmpty(deque))
    {
        exit(1);
    }
    deque->rear = (deque->rear + 1) % MAX_DEQUE;
};