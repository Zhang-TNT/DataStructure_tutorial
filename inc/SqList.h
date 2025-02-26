#ifndef __SQLIST_H__
#define __SQLIST_H__

#define SQLIST_MAXSIZE 100

#include <stdio.h>

/* type define */
typedef enum _Status
{
    STATUS_ERROR = -1,
    STATUS_WARNING = 0,
    STATUS_OK = 1
} Status;

typedef int ElemType;

/* sequence list structure */
typedef struct _SqList_static
{
    ElemType elem[SQLIST_MAXSIZE];
    int length;
} SqList_static;

typedef struct _SqList_dynamic
{
    ElemType *elem;
    int length;
} SqList_dynamic;

/* link list structure */
typedef struct _LNode
{
    ElemType data;
    struct _LNode *next;
} LNode, *LinkList;
/* function declare*/
int SqList_static_Length(SqList_static L);
int SqList_static_GetElem(SqList_static L, int i);
int SqList_static_LocateElem(SqList_static L, ElemType e);
Status SqList_static_Insert(SqList_static *L, int i, ElemType e);
Status SqList_static_Delete(SqList_static *L, int i);
void SqList_static_Print(SqList_static L);

Status SqList_dynamic_Init(SqList_dynamic *L);
int SqList_dynamic_Length(SqList_dynamic L);
Status SqList_dynamic_GetElem(SqList_dynamic L, int i, ElemType *e);
int SqList_dynamic_LocateElem(SqList_dynamic L, ElemType e);
Status SqList_dynamic_Insert(SqList_dynamic *L, int i, ElemType e);
Status SqList_dynamic_Delete(SqList_dynamic *L, int i);
void SqList_dynamic_Print(SqList_dynamic L);

Status LinkList_Init(LinkList *L);
int LinkList_Length(LinkList L);
Status LinkList_GetElem(LinkList L, int i, ElemType *e);
int LinkList_LocateElem(LinkList L, ElemType e);
Status LinkList_Insert(LinkList *L, int i, ElemType e);
Status LinkList_Delete(LinkList L, int i);
void LinkList_Print(LinkList L);

#endif
