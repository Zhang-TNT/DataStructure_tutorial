#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int ElemType;

/* 双亲表示法 */
typedef struct _PTNode
{
    ElemType data;  // 结点数据
    int parent;     // 双亲位置
}PTNode;// 结点结构

typedef struct _PTree
{
    PTNode nodes[MAX_TREE_SIZE];    // 结点数组，下标从0开始
    int rootPos, nodeNum;           // 根的位置和结点数
}PTree;

/* 孩子表示法 */
typedef struct _CTNode
{
    int child;
    struct _CTNode *next;
}CTNode, *ChildPtr; // 孩子结点

typedef struct _CTBox
{
    ElemType data;
    ChildPtr firstchild;
}CTBox; // 结点结构

typedef struct _CTree
{
    CTBox nodes[MAX_TREE_SIZE];     // 结点数组，下标从0开始
    int rootPos, nodeNum;           // 根的位置和结点数
}CTree; // 树结构

/* 孩子兄弟表示法 */
typedef struct _CSNode
{
    ElemType data;
    struct _CSNode *firstchild, *nextSibling;
}CSNode, *CSTree; // 孩子结点

/* 二叉树的二叉链表结点 */
typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode *lchild, *rchild;   // 左右孩子指针
}BiTNode, *BiTree;

typedef enum _Status
{
    STATUS_ERROR = -1,
    STATUS_WARNING = 0,
    STATUS_OK = 1
} Status;

/* 线索二叉树 */
typedef enum _PointerTag
{
    Link,
    Thread
}PointerTag;

typedef struct _BiThrNode
{
    ElemType data;
    struct _BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

#endif
