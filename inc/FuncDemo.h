#ifndef __FUNCDEMO_H__
#define __FUNCDEMO_H__

#define MONTHS 12

#include <stdio.h>
int my_factorial(int len);
int my_ageFactorial(int len);
void my_integerArrayPrint(int *arr, int len);
void my_bubbleSort(int *arr, int len);
void my_selectSort(int *arr, int len);
void my_rainfall(const float arr[][MONTHS]);

int *my_arrayInit(int len);
int my_arrayAccess(int *arr, int index);
void my_arrayInsert(int *arr, int size, int num, int index);
void my_arrayDelete(int *arr, int size, int index);
int my_arraySearch(int *arr, int size, int target);
int *my_arrayExtend(int *arr, int size, int enlarge);
void my_arrayTraverse(int *arr, int size);

void my_arraySubscript(int arr[5]);
void my_arrayPointer(int arr[5]);
void my_twoDimensionalArray(int arr[3][4]);
void my_pointerToArrayElement(int arr[3][4]);
void my_pointerToArray(int arr[3][4]);

#endif
