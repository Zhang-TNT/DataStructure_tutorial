#include "SqList.h"

int SqList_static_Length(SqList_static L)
{
    return L.length;
}

int SqList_static_GetElem(SqList_static L, int i)
{
    if (i < 1 || i > L.length)
        return STATUS_ERROR;
    int e = L.elem[i - 1];
    return e;
}

int SqList_static_LocateElem(SqList_static L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

Status SqList_static_Insert(SqList_static *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return STATUS_ERROR;
    if (L->length == SQLIST_MAXSIZE)
        return STATUS_ERROR;
    for (int j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    L->length++;
    return STATUS_OK;
}

Status SqList_static_Delete(SqList_static *L, int i)
{
    if (i < 1 || i > L->length)
        return STATUS_ERROR;
    for (int j = i - 1; j < L->length - 1; j++)
    {
        L->elem[j] = L->elem[j + 1];
    }
    L->length--;
    return STATUS_OK;
}

void SqList_static_Print(SqList_static L)
{
    if (L.length == 0)
        printf("[]\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("L.elem[%d] = %d\n", i, L.elem[i]);
    }
}

Status SqList_dynamic_Init(SqList_dynamic *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * SQLIST_MAXSIZE);
    if (L->elem == NULL)
        return STATUS_ERROR;
    L->length = 0;
    return STATUS_OK;
}

int SqList_dynamic_Length(SqList_dynamic L)
{
    return L.length;
}

Status SqList_dynamic_GetElem(SqList_dynamic L, int i, ElemType *e)
{
    if (i < 1 || i > L.length)
        return STATUS_ERROR;
    *e = L.elem[i - 1];
    return STATUS_OK;
}

int SqList_dynamic_LocateElem(SqList_dynamic L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

Status SqList_dynamic_Insert(SqList_dynamic *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return STATUS_ERROR;
    if (L->length == SQLIST_MAXSIZE)
        return STATUS_ERROR;
    for (int j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    L->length++;
    return STATUS_OK;
}

Status SqList_dynamic_Delete(SqList_dynamic *L, int i)
{
    if (i < 1 || i > L->length)
        return STATUS_ERROR;
    for (int j = i - 1; j < L->length - 1; j++)
    {
        L->elem[j] = L->elem[j + 1];
    }
    L->length--;
    return STATUS_OK;
}

void SqList_dynamic_Print(SqList_dynamic L)
{
    if (L.length == 0)
        printf("[]\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("L.elem[%d] = %d\n", i, L.elem[i]);
    }
}

/* funcs for link list */
Status LinkList_Init(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return STATUS_ERROR;
    (*L)->next = NULL;
    return STATUS_OK;
}

int LinkList_Length(LinkList L)
{
    int len = 0;
    LNode *pTemp = L->next; // pTemp指向首元结点
    while (pTemp != NULL)
    {
        len++;
        pTemp = pTemp->next;
    }
    return len;
}

Status LinkList_GetElem(LinkList L, int i, ElemType *e)
{
    LNode *pTemp = L->next;
    int j = 1;
    while (pTemp != NULL && j < i)
    {
        pTemp = pTemp->next;
        j++;
    }
    if (pTemp == NULL || j > i)
        return STATUS_ERROR;
    *e = pTemp->data;
    return STATUS_OK;
}

int LinkList_LocateElem(LinkList L, ElemType e)
{
    LNode *pTemp = L->next;
    int i = 1;
    while (pTemp != NULL)
    {
        if (pTemp->data == e)
            return i;
        pTemp = pTemp->next;
        i++;
    }
    return 0;
}

Status LinkList_Insert(LinkList *L, int i, ElemType e)
{
    if (i < 1)
        return STATUS_ERROR;

    LNode *pTemp = (*L); // pTemp指向头结点
    int j = 0;
    while (pTemp != NULL && j < i - 1)
    {
        pTemp = pTemp->next;
        j++;
    }
    if (pTemp == NULL || j > i - 1)
        return STATUS_ERROR;
    LNode *pNode = (LNode *)malloc(sizeof(LNode));
    if (pNode == NULL)
        return STATUS_ERROR;
    pNode->data = e;
    pNode->next = pTemp->next;
    pTemp->next = pNode;
    return STATUS_OK;
}

Status LinkList_Delete(LinkList L, int i)
{
    LNode *pTemp = L->next; // pTemp指向首元结点
    int j = 1;
    while (pTemp != NULL && j < i - 1)
    {
        pTemp = pTemp->next;
        j++;
    }
    if (pTemp == NULL || j > i - 1)
        return STATUS_ERROR;
    LNode *pNode = pTemp->next;
    if (pNode == NULL)
        return STATUS_ERROR;
    pTemp->next = pNode->next;
    free(pNode);
    return STATUS_OK;
}

void LinkList_Print(LinkList L)
{
    LNode *pTemp = L->next; // pTemp指向首元结点
    int i = 0;
    if (pTemp == NULL)
        printf("[]\n");
    else
    {
        while (pTemp != NULL)
        {
            printf("L.elem[%d] = %d\n", i + 1, pTemp->data);
            pTemp = pTemp->next;
            i++;
        }
    }
    printf("\n");
}
