#include "Tree.h"
#include "Queue.h"

void PreOrderTraverse(BiTree T)
{
    if(T == NULL) return;
    printf("data: %d\n", T->data);
    PreOrderTraverse(T->lchild);    // 先序遍历左子树
    PreOrderTraverse(T->rchild);    // 先序遍历右子树
}

void InOrderTraverse(BiTree T)
{
    if(T == NULL) return;
    InOrderTraverse(T->lchild);     // 中序遍历左子树
    printf("data: %d\n", T->data);
    InOrderTraverse(T->rchild);     // 中序遍历右子树
}

void PostOrderTraverse(BiTree T)
{
    if(T == NULL) return;
    PostOrderTraverse(T->lchild);   // 后序遍历左子树
    PostOrderTraverse(T->rchild);   // 后序遍历右子树
    printf("data: %d\n", T->data);
}

void CreateBiTree(BiTree *T)
{
    ElemType data1;
    *T = (BiTree)malloc(sizeof(BiTree));
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
}



