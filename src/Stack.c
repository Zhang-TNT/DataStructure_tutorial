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
