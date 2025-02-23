#include "FuncDemo.h"

int my_factorial(int len)
{
    int result = 0;
    if (len < 0)
    {
        return -1;
    }
    else if (len == 0 || len == 1)
    {
        return 1;
    }
    else
    {
        result = len * my_factorial(len - 1);
    }
    return result;
}

int my_ageFactorial(int len)
{
    int result = 0;
    if (len <= 0)
    {
        return -1;
    }
    else if (len == 1)
    {
        return 10;
    }
    else
    {
        result = my_ageFactorial(len - 1) + 2;
    }
    return result;
}

void my_integerArrayPrint(int *arr, int len)
{
    int temp = 1;
    for (int i = 0; i < len; i++, temp++)
    {
        printf("%d ", arr[i]);
        if (temp % 5 == 0)
            printf("\n");
    }
    printf("\n");
}

void my_bubbleSort(int *arr, int len)
{
    int temp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void my_selectSort(int *arr, int len)
{
    int temp = 0, minIndex;
    for (int i = 0; i < len - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void my_rainfall(const float arr[][MONTHS])
{
    printf("\tYEAR\t RAINFALL(inches)\n");
    float total, subtotal;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < MONTHS; j++)
            subtotal += arr[i][j];
        total += subtotal;
        printf("\t%5d %10.1f\n", i + 2010, subtotal);
        subtotal = 0;
    }
    printf("The yearly average rainfall is %5.1f inches\n", (total / 5));
    printf("\n");
    printf("MONTHLY AVERAGE RAINFALL\n");
    printf("\tJAN\tFEB\tMAR\tAPR\tMAY\tJUN\tJUL\tAUG\tSEP\tOCT\tNOV\tDEC\n");
    for (int i = 0; i < MONTHS; i++)
    {
        for (int j = 0; j < 5; j++)
            subtotal += arr[j][i];
        printf("\t%.1f", subtotal / 5);
        subtotal = 0;
    }
    printf("\n");
}

int *my_arrayInit(int len)
{
    int *pArr;
    pArr = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        pArr[i] = i;
    }
    return pArr;
}

int my_arrayAccess(int *arr, int index)
{
    return *(arr + index);
}

void my_arrayInsert(int *arr, int size, int num, int index)
{ // 大小为size的数组，在index位置插入数字num
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = num;
}

void my_arrayDelete(int *arr, int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int my_arraySearch(int *arr, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int *my_arrayExtend(int *arr, int size, int enlarge)
{
    int *pArr;
    pArr = (int *)malloc((size + enlarge) * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        pArr[i] = arr[i];
    }
    for (int i = size; i < size + enlarge; i++)
    {
        pArr[i] = 0;
    }
    return pArr;
}

void my_arrayTraverse(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void my_arraySubscript(int arr[5])
{
    for (int i = 0; i < 5; i++)
        printf("arr[%d] = %d\n", i + 1, arr[i]);
}

void my_arrayPointer(int arr[5])
{
    printf("the address of arr is %p\n", arr);
    for (int i = 0; i < 5; i++)
        printf("arr[%d] = %d\n", i + 1, *(arr + i));
    printf("the address of arr is %p\n", arr); // arr仍然是第一个元素的地址

    int *pArr = arr;
    printf("the address of pArr is %p\n", pArr);
    for (pArr = arr; pArr < arr + 5; pArr++)
        printf("arr[%d] = %d\n", pArr - arr, *pArr);
    printf("the address of pArr is %p\n", pArr); // pArr已经是最后一个元素的地址
}

void my_twoDimensionalArray(int arr[3][4])
{
    printf_s("the array is:\n");
    for (int i = 0; i < 3; i++)
    {
        int temp = 1;
        for (int j = 0; j < 4; j++, temp++)
        {
            printf("%2d ", arr[i][j]);
            if (temp % 4 == 0)
                printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    printf("**arr = %d\n", **arr);                         // **arr = arr[0][0]，即第一行第一个元素的值
    printf("*(*arr + 1) = %d\n", *(*arr + 1));             // *(*arr + 1) = arr[0][1]，即第一行第二个元素的值
    printf("**(arr + 1) = %d\n", **(arr + 1));             // **(arr + 1) = arr[1][0]，即第二行第一个元素的值
    printf("*(*(arr + 1) + 1) = %d\n", *(*(arr + 1) + 1)); // *(*(arr + 1) + 1) = arr[1][1]，即第二行第二个元素的值
}

void my_pointerToArrayElement(int arr[3][4])
{
    int *pArr = &arr[0][0]; // 指针pArr指向数组第一个元素
    for (pArr; pArr < arr[0] + 12; pArr++)
    {
        if ((pArr - arr[0]) % 4 == 0)
            printf("\n");
        printf("%2d ", *pArr);
    }
}

void my_pointerToArray(int arr[3][4])
{
    int(*pArr)[4] = arr; // 指针pArr指向数组第一行
    for (pArr; pArr < arr + 3; pArr++)
    {
        for (int *eArr = *pArr; eArr < *pArr + 4; eArr++) // 指针eArr指向数组每一行的元素
            printf("%2d ", *eArr);
        printf("\n");
    }
}
