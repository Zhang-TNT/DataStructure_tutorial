#include <stdio.h>
// #include "SqList.h"
// #include "FuncDemo.h"
// #include "Stack.h"
#include "Queue.h"

int main()
{
    // /* static list */
    // printf("static list\n");
    // SqList_static sqlist1;
    // sqlist1.length = 0;
    // sqlist1.elem[0] = 1;
    // sqlist1.elem[1] = 2;
    // sqlist1.elem[2] = 3;
    // sqlist1.elem[3] = 4;
    // sqlist1.length = 4;
    // int temp_num = 0;
    // temp_num = SqList_static_LocateElem(sqlist1, 3);
    // printf("temp_num: %d\n", temp_num);
    // int temp_elem = 0;
    // temp_elem = SqList_static_GetElem(sqlist1, 2);
    // printf("temp_elem: %d\n", temp_elem);
    // SqList_static_Print(sqlist1);
    // SqList_static_Insert(&sqlist1, 3, 5);
    // SqList_static_Print(sqlist1);
    // printf("\n");
    // SqList_static_Delete(&sqlist1, 3);
    // SqList_static_Print(sqlist1);

    // /* dynamic list */
    // printf("dynamic list\n");
    // SqList_dynamic sqlist2;
    // SqList_dynamic_Init(&sqlist2);
    // int len = 0;
    // len = SqList_dynamic_Length(sqlist2);
    // printf("len: %d\n", len);
    // sqlist2.elem[0] = 1;
    // sqlist2.elem[1] = 2;
    // sqlist2.elem[2] = 3;
    // sqlist2.elem[3] = 4;
    // sqlist2.length = 4;
    // len = SqList_dynamic_Length(sqlist2);
    // printf("len: %d\n", len);
    // int temp_elem2 = 0;
    // SqList_dynamic_GetElem(sqlist2, 3, &temp_elem2);
    // printf("temp_elem2: %d\n", temp_elem2);
    // SqList_dynamic_Print(sqlist2);
    // SqList_dynamic_Insert(&sqlist2, 3, 5);
    // SqList_dynamic_Print(sqlist2);
    // printf("\n");
    // SqList_dynamic_Delete(&sqlist2, 3);
    // SqList_dynamic_Print(sqlist2);

    /* Link list*/
    /*printf("Link list\n");
    LinkList aLinkList;
    LinkList_Init(&aLinkList);
    LinkList_Print(aLinkList);
    printf("length = %d\n", LinkList_Length(aLinkList));
    LinkList_Insert(&aLinkList, 1, 1);
    LinkList_Insert(&aLinkList, 2, 2);
    LinkList_Insert(&aLinkList, 3, 3);
    LinkList_Insert(&aLinkList, 4, 4);
    LinkList_Print(aLinkList);
    printf("length = %d\n", LinkList_Length(aLinkList));
    LinkList_Delete(aLinkList, 3);
    LinkList_Print(aLinkList);
    printf("length = %d\n", LinkList_Length(aLinkList));
    LinkList_Insert(&aLinkList, 3, 5);
    LinkList_Print(aLinkList);
    printf("e located at %d\n", LinkList_LocateElem(aLinkList, 5));
    int temp = 0;
    LinkList_GetElem(aLinkList, 3, &temp);
    printf("temp = %d\n", temp);*/

    /* Stack */
    /*printf("Stack\n");
    SqStack aStack;
    Stack_Init(&aStack);
    int alength = Stack_Length(aStack);
    printf("alength = %d\n", alength);
    Stack_Push(&aStack, 1);
    Stack_Push(&aStack, 2);
    Stack_Push(&aStack, 3);
    Stack_Push(&aStack, 4);
    alength = Stack_Length(aStack);
    printf("alength = %d\n", alength);
    Stack_Print(aStack);
    int temp = 0;
    Stack_Pop(&aStack, &temp);
    printf("temp = %d\n", temp);
    Stack_Print(aStack);
    Stack_GetTop(aStack, &temp);
    printf("temp = %d\n", temp);
    Stack_Clear(&aStack);
    Stack_Print(aStack);*/
    /* Queue */
    /*printf("Queue\n");
    SqQueue aQueue;
    SqQueue_Init(&aQueue);
    int alength = SqQueue_Length(aQueue);
    printf("alength = %d\n", alength);
    SqQueue_EnQueue(&aQueue, 1);
    SqQueue_EnQueue(&aQueue, 2);
    SqQueue_EnQueue(&aQueue, 3);
    SqQueue_EnQueue(&aQueue, 4);
    alength = SqQueue_Length(aQueue);
    printf("alength = %d\n", alength);
    SqQueue_Traverse(aQueue);
    int temp = 0;
    SqQueue_DeQueue(&aQueue, &temp);
    printf("temp = %d\n", temp);
    SqQueue_Traverse(aQueue);*/
    /*printf("LkQueue with head node\n");
    LkQueue aQueue;
    LkQueue_withHead_Init(&aQueue);
    LkQueue_withHead_EnQueue(&aQueue, 1);
    LkQueue_withHead_EnQueue(&aQueue, 2);
    LkQueue_withHead_EnQueue(&aQueue, 3);
    LkQueue_withHead_EnQueue(&aQueue, 4);
    LkQueue_withHead_Traverse(aQueue);
    int temp = 0;
    LkQueue_withHead_DeQueue(&aQueue, &temp);
    printf("temp = %d\n", temp);
    LkQueue_withHead_Traverse(aQueue);*/
    printf("LkQueue without head node\n");
    LkQueue aQueue;
    LkQueue_withoutHead_Init(&aQueue);
    LkQueue_withoutHead_EnQueue(&aQueue, 1);
    LkQueue_withoutHead_EnQueue(&aQueue, 2);
    LkQueue_withoutHead_EnQueue(&aQueue, 3);
    LkQueue_withoutHead_EnQueue(&aQueue, 4);
    LkQueue_withoutHead_Traverse(aQueue);
    int temp = 0;
    LkQueue_withoutHead_DeQueue(&aQueue, &temp);
    printf("temp = %d\n", temp);
    LkQueue_withoutHead_Traverse(aQueue);

    return 0;
}
