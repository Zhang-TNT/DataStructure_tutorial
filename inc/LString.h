#ifndef __LSTRING_H__
#define __LSTRING_H__

#include <stdio.h>

/* type define */
typedef char ElemType;

typedef enum _Status
{
    STATUS_ERROR = -1,
    STATUS_WARNING = 0,
    STATUS_OK = 1
} Status;

typedef struct _LStringNode
{
    ElemType data;
    struct _LStringNode *next;
} LStringNode, *LString;

typedef struct _LStringNode1
{
    ElemType data[4];
    struct _LStringNode1 *next;
} LStringNode1, *LString1;


#endif
