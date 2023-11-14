#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef enum { false, true } bool; // 수정: false와 true를 대문자로 변경
#define MAX_STACK 100000

typedef struct {
    Data items[MAX_STACK];
    int top;
} Stack1;

void InitStack(Stack1 *pstack);
bool IsFull(Stack1 *pstack);
bool IsEmpty(Stack1 *pstack);
void Push(Stack1 *pstack, Data num);
void Pop(Stack1 *pstack);
void Peek(Stack1 *pstack);

int main() {
    return 0;
}

void InitStack(Stack1 *pstack) {
    pstack->top = -1;
}

bool IsFull(Stack1 *pstack) {
    return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack1 *pstack) {
    return pstack->top == -1;
}

void Push(Stack1 *pstack, Data num) {
    if (IsFull(pstack)) {
        exit(1);
    }
    pstack->items[++(pstack->top)] = num;
}

void Pop(Stack1 *pstack) {
    if (!IsEmpty(pstack)) {
        --(pstack->top);
    }
}

void Peek(Stack1 *pstack) {
    if (IsEmpty(pstack)) {
        printf("%d\n", -1); // 수정: 개행 문자('\n') 추가
    } else {
        printf("%d\n", pstack->items[pstack->top]); // 수정: 개행 문자('\n') 추가
    }
}
