#ifndef __STACK_H__
#define __STACK_H__

#define STACK_MAXSIZE 100

#include <stdio.h>

/* type define */
typedef enum _Status
{
    STATUS_ERROR = -1,
    STATUS_WARNING = 0,
    STATUS_OK = 1
} Status;

typedef int ElemType;

/* sequence Stack structure static */
typedef struct _SqStack
{
    ElemType elem[STACK_MAXSIZE];
    int top;
} SqStack;

/* sequence Stack structure dynamic */
typedef struct _SqStack_dynamic
{
    ElemType *elem;
    int top;
} SqStack_dynamic;

/* sharing sequence Stack structure */
typedef struct _SqStack_shared
{
    ElemType elem[STACK_MAXSIZE];
    int top1;
    int top2;
} _SqStack_shared;

/* function declare*/
/* static stack operation*/
void Stack_Init(SqStack *S);
void Stack_Clear(SqStack *S);
Status Stack_Push(SqStack *S, ElemType e);
Status Stack_Pop(SqStack *S, ElemType *e);
Status Stack_GetTop(SqStack S, ElemType *e);
int Stack_Length(SqStack S);
void Stack_Print(SqStack S);

#endif
