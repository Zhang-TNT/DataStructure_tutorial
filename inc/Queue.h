#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>

/* type define */

#define QUEUE_MAXSIZE 100

typedef int ElemType;


typedef struct _SqQueue
{
    ElemType elem[QUEUE_MAXSIZE];
    int front; // 队首指针,指向队首元素的前一个位置
    int rear;  // 队尾指针,指向队尾元素的后一个位置
} SqQueue;

typedef struct _LkQueueNode
{
    ElemType data;
    struct _LkQueueNode *next;
} LkQueueNode;

typedef struct _LkQueue
{
    LkQueueNode *front; // 队首
    LkQueueNode *rear;  // 队尾
} LkQueue;  // 链式队列



typedef enum _Status
{
    STATUS_ERROR = -1,
    STATUS_WARNING = 0,
    STATUS_OK = 1
} Status;

/* funcs for sequence queue declaration */
Status SqQueue_Init(SqQueue *Q);
int SqQueue_Length(SqQueue Q);
Status SqQueue_EnQueue(SqQueue *Q, ElemType e);
Status SqQueue_DeQueue(SqQueue *Q, ElemType *e);
void SqQueue_Traverse(SqQueue Q);

/* funcs for link queue declaration */
Status LkQueue_withHead_Init(LkQueue *Q);
Status LkQueue_withHead_EnQueue(LkQueue *Q, ElemType e);
Status LkQueue_withHead_DeQueue(LkQueue *Q, ElemType *e);
void LkQueue_withHead_Traverse(LkQueue Q);

Status LkQueue_withoutHead_Init(LkQueue *Q);
Status LkQueue_withoutHead_EnQueue(LkQueue *Q, ElemType e);
Status LkQueue_withoutHead_DeQueue(LkQueue *Q, ElemType *e);
void LkQueue_withoutHead_Traverse(LkQueue Q);

#endif
