#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100

typedef int Data;

typedef enum {false, true} bool;

typedef struct
{
    int front, rear;
    Data items[MAX_QUEUE];
} Queue;

void InitQueue(Queue *pqueue);

bool IsFull(Queue *pqueue);

bool IsEmpty(Queue *pqueue);

Data Peek(Queue *pqueue);

void EnQueue(Queue *pqueue, Data item);

void DeQueue(Queue *pqueue);

int main()
{
    Queue myQueue;
    InitQueue(&myQueue);

    // Use queue operations

    return 0;
}

void InitQueue(Queue * pqueue)
{
    pqueue->front = 0;
    pqueue->rear = 0;
}

bool IsFull(Queue * pqueue)
{
    return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}

bool IsEmpty(Queue * pqueue)
{
    return pqueue->front == pqueue->rear;
}

Data Peek(Queue * pqueue)
{
    if (IsEmpty(pqueue))
    {
        exit(1);
    }
    return pqueue->items[pqueue->front];
}

void Enqueue(Queue * pqueue, Data item)
{
    if (IsFull(pqueue))
    {
        exit(1);
    }
    pqueue->items[pqueue->rear] = item;
    pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

void Dequeue(Queue * pqueue)
{
    if (IsEmpty(pqueue))
    {
        exit(1);
    }
    pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}