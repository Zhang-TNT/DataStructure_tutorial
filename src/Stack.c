#include "Stack.h"

void Stack_Init(SqStack *S)
{
    S->top = -1; // 初始化栈为空
}

void Stack_Clear(SqStack *S)
{
    S->top = -1; // 清空栈
}

int Stack_Length(SqStack S)
{
    return S.top + 1;
}

Status Stack_GetTop(SqStack S, ElemType *e)
{
    if (S.top == -1)
        return STATUS_ERROR;
    *e = S.elem[S.top];
    return STATUS_OK;
}

Status Stack_Push(SqStack *S, ElemType e)
{
    if (S->top == STACK_MAXSIZE - 1)
        return STATUS_ERROR;
    S->top++;            // 栈顶指针向上移
    S->elem[S->top] = e; // 将元素插入栈顶
    // S->elem[++S->top] = e;
    return STATUS_OK;
}

Status Stack_Pop(SqStack *S, ElemType *e)
{
    if (S->top == -1)
        return STATUS_ERROR;
    *e = S->elem[S->top];
    S->top--; // 栈顶指针向下移
    return STATUS_OK;
}

void Stack_Print(SqStack S)
{
    for (int i = S.top; i > -1; i--)
    {
        printf("Stack.elem[%d] = %d \n", i, S.elem[i]);
    }
    printf("\n");
}

Status SharingStack_Push(SqStack_shared *S, ElemType e, int stackNum)
{
    if (S->top1 + 1 == S->top2) // 栈满
        return STATUS_ERROR;
    if (stackNum == 1) // 栈1
        S->elem[++S->top1] = e;
    else if (stackNum == 2) // 栈2
        S->elem[--S->top2] = e;
    return STATUS_OK;
}

Status SharingStack_Pop(SqStack_shared *S, ElemType *e, int stackNum)
{
    if (stackNum == 1) // 栈1
    {
        if (S->top1 == -1)
            return STATUS_ERROR;
        *e = S->elem[S->top1--];
    }
    else if (stackNum == 2) // 栈2
    {
        if (S->top2 == STACK_MAXSIZE)
            return STATUS_ERROR;
        *e = S->elem[S->top2++];
    }
    return STATUS_OK;
}
