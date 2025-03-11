#include "Queue.h"

/* funcs for sequence queue */
Status SqQueue_Init(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return STATUS_OK;
}

int SqQueue_Length(SqQueue Q)
{
    return (Q.rear - Q.front + QUEUE_MAXSIZE) % QUEUE_MAXSIZE;
}

Status SqQueue_EnQueue(SqQueue *Q, ElemType e)
{
    if((Q->rear + 1) % QUEUE_MAXSIZE == Q->front)
        return STATUS_ERROR;
    Q->elem[Q->rear] = e;                           // 将元素插入队尾
    Q->rear = (Q->rear + 1) % QUEUE_MAXSIZE;         // 队尾指针向后移
    return STATUS_OK;
}

Status SqQueue_DeQueue(SqQueue *Q, ElemType *e)
{
    if(Q->front == Q->rear)
        return STATUS_ERROR;
    *e = Q->elem[Q->front];                         // 读取队首元素
    Q->front = (Q->front + 1) % QUEUE_MAXSIZE;       // 队首指针向后移
    return STATUS_OK;
}

void SqQueue_Traverse(SqQueue Q)
{
    for (int i = Q.front; i != Q.rear; i = (i + 1) % QUEUE_MAXSIZE)
    {
        printf("Queue.elem[%d] = %d ", i, Q.elem[i]);
    }
    printf("\n");
}

/* funcs for link queue with head node */
Status LkQueue_withHead_Init(LkQueue *Q)
{
    Q->front = Q->rear = (LkQueueNode *)malloc(sizeof(LkQueueNode)); // 初始时队首指针和队尾指针指向头节点
    if (Q->front == NULL)
        return STATUS_ERROR;
    Q->front->next = NULL;  // 头节点的后继指针为空表示空队列
    return STATUS_OK;
}

Status LkQueue_withHead_EnQueue(LkQueue *Q, ElemType e)
{
    LkQueueNode *p = (LkQueueNode *)malloc(sizeof(LkQueueNode)); // 申请新节点
    if (p == NULL)
        return STATUS_ERROR;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; // 将新节点插入到队尾
    Q->rear = p;       // 队尾指针指向新节点
    return STATUS_OK;
}

Status LkQueue_withHead_DeQueue(LkQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear) // 队列为空
        return STATUS_ERROR;
    LkQueueNode *p = Q->front->next; // 新结点p指向队首元素
    *e = p->data;                    // 读取队首元素
    Q->front->next = p->next;        // 删除队首元素
    if (Q->front->next == NULL)      // 队列为空
        Q->rear = Q->front;          // 队尾指针指向头节点
    free(p);
    return STATUS_OK;
}

void LkQueue_withHead_Traverse(LkQueue Q)
{
    LkQueueNode *p = Q.front->next;
    int i = 0;
    while(p != NULL)
    {
        i++;
        printf("Queue.elem[%d] = %d ", i, p->data);
        p = p->next;
    }
    printf("\n");
}


/* funcs for link queue without head node */
Status LkQueue_withoutHead_Init(LkQueue *Q)
{
    Q->front = Q->rear = NULL;  // 初始时队首指针和队尾指针指向空
    return STATUS_OK;
}

Status LkQueue_withoutHead_EnQueue(LkQueue *Q, ElemType e)
{
    LkQueueNode *p = (LkQueueNode *)malloc(sizeof(LkQueueNode)); // 申请新节点
    if (p == NULL)
        return STATUS_ERROR;
    p->data = e;
    p->next = NULL;
    if(Q->front == NULL)    // 队列为空
        Q->front = Q->rear = p;
    else
    {
        Q->rear->next = p; // 将新节点插入到队尾
        Q->rear = p;       // 队尾指针指向新节点
    }
    return STATUS_OK;
}

Status LkQueue_withoutHead_DeQueue(LkQueue *Q, ElemType *e)
{
    if(Q->front == NULL) // 队列为空
        return STATUS_ERROR;
    LkQueueNode *p = Q->front; // 新结点p指向队首元素
    *e = p->data;               // 读取队首元素
    Q->front = p->next;         // 删除队首元素
    if(Q->rear == p)            // 队列为空
        Q->front = Q->rear = NULL;
    free(p);
    return STATUS_OK;
}

void LkQueue_withoutHead_Traverse(LkQueue Q)
{
    LkQueueNode *p = Q.front;
    int i = 0;
    while(p != NULL)
    {
        i++;
        printf("Queue.elem[%d] = %d ", i, p->data);
        p = p->next;
    }
    printf("\n");
}



