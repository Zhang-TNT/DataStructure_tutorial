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
