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
