# DataStructure_tutorial
> Data Structure tutorial for C

## Introduction

> 计算机解决一个具体问题：从具体问题抽象出一个适当的数学模型；设计一个解此数学模型的算法；编写程序，测试、调整直至得到最终解答

1. 数学知识复习

    证明数据结构分析中结论的两个常用方法是**归纳法**和**反证法**。

    + 归纳法

        第一步证明*基准情况*，对于小群体事件的正确性；第二步进行*归纳假设*；第三步使用这个假设对下一个值进行证明。

    + 反证法

        反证法是通过假设定理不成立，然后证明该假设导致某个已知的性质不成立，从而说明原假设是错误的。

2. 递归

    有时候数学函数以不太标准的形式来定义，当一个函数用它自己来定义时就称为**递归（recursive）**，递归调用将反复进行直到基准情形出现。递归的四个基本法则

    + 基准情形

        基准情形不用递归就能求解

    + 不断推进

        递归调用总朝着基准情形方向推进

    + 设计法则

        假设所有递归调用都能运行

    + 合成效益法则

        在求解一个问题的同一实例时，切勿在不同的递归调用中做重复性工作

    案例1. 递归方法求阶乘$n!$

    数学分析：若$f(n)$表示$n!$，则满足$f(n) = n\times f(n-1)$，基准情形是$n=0$或$n=1$时，$f(n)=1$。代码实现如下

    ```c
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
    ```

    案例2. 有5各学生坐一起，问第5个学生年龄，说其比第4个大2岁；问第4个年龄，说其比第3个大2岁；问第3个年龄，说其比第2个大2岁；问第2个年龄，说其比第1个大2岁；问第1个年龄，说其10岁。求第5个学生年龄

    数学分析：若$f(n)$表示第$n$个学生的年龄，则满足$f(n)=f(n-1)+2$，基准情形是$n=1$时，$f(n)=10$。代码实现如下

    ```c
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
    ```

3. 编程机制

    C编程的基本策略是，用程序把源代码文件转换为可执行文件，即**编译**和**链接**。编译器把源代码转换为目标代码（`.obj`），链接器把中间代码和其他代码合并，生成可执行文件（`.exe`），目标文件和可执行文件都由机器语言指令组成。

## Review

### 2.1 数据和C

1. 常量

    数据类型在程序使用之前就预先设定好，在整个程序的运行过程中没有变化，称为**常量**（constant），在常量末尾加专用字符，强制指定常量类型，例如`3.14159f`，`31415U`，`10LU`等。有以下几种

    + 整形常量

        整数是没有小数部分的数。

    + 实型常量

        实型是带有小数部分的数。计算机把实数分为**小数部分**和**指数部分**来表示，两种表示方法

        + 小数形式：`3.1415`
        + 指数形式：`e`或`E`表示底数10，前后必须有数字，且后面必须为整数，`3.16E2`表示`316`。

    + 字符常量

        普通字符：用单引号括起来的一个字符，本质是`int`型的ASCII码

        转义字符：以`\`开头的字符

    + 字符串常量

        用双引号把若干个字符常量括起来

    + 符号常量

        用`#define`指令，指定用一个符号名称代表一个常量，符号常量**不占内存**，只是一个临时符号，代表一个值，在预编译后这个符号就不存在了，符号常量用大写字母表示。

2. 变量

    数据类型在程序的运行过程中会被改变或被赋值，称为**变量**（variable），变量必须**先定义初始化后使用**，变量名实际上是以一个名字代表的一个存储地址，未赋值的变量的值由编译器决定。有以下几种

    + 整型变量

        关键字`int`，一般占4个字节，`short`比`int`占用的内存少，`long`比`int`占用的内存多。提供附属关键字`short`、`long`、`long long`和`unsigned`。在打印时，`unsigned int`使用转义字符`%u`；`long`使用转义字符`%ld`；十六进制使用转义字符`%x`或`%#x`；八进制使用转义字符`%o`或`%#o`；内存地址使用转义字符`%p`。

    + 实型变量

        关键字`float`，一般占4个字节，`double`比`float`占用内存多，实型的表示类似科学计数法，指数计数法。提供附属关键字`double`和`long double`。在使用指数计数法时，`e`的两侧必须有数字，且右侧必须为整数，例如`float num = 6.63e-3;`。在打印时，转换说明`%f`为十进制计数法打印；转换说明`%e`为指数计数法打印。`NaN`为浮点类型。实型数据不能加修饰符`signed`或`unsigned`。

    + 字符变量

        关键字`char`，一般占1个字节，`char`类型用于存储字符，但技术层面`char`是整型，`char`实际上存储的是整型，即ASCII码，65代表`A`，97代表`a`。`char`被定义为8位的存储单元，在初始化时使用单引号`''`进行赋值，使用转换说明`%c`进行字符打印。

    + 常变量

        在定义变量时，加关键字`const`，常变量**所在期间其值不能改变**，有类型并且占内存。

3. 存储方式

   + 常量
   
       常量的存储位置可分为**只读数据段**、**代码段**、**栈**和**数据段**这几种情况。
   
       + 只读数据段：常量、`const`全局常量等，只读
       + 代码段：存储程序的机器指令
       + 栈：局部`const`变量，动态分配的内存区域
       + 数据段：非常量变量于此存储
   
       字面常量存储在只读数据段或代码段；`#define`常量不占用存储空间；`const`全局常量在只读数据段，`const`局部常量在栈中；字符串常量在只读数据段。
   
   + 变量
   
       变量的存储方式可分为**静态存储方式**和**动态存储方式**。
   
       + 静态：由系统分配
       + 动态：开发者进行动态分配
   
4. 存储类别

    C语言有以下关键字作为存储类别说明符：`auto`、`register`、`static`、`extern`、`_Thread_local`。

    + `auto`：由系统管理分配内存，只能用于块作用域的变量声明中，一般可以省略关键字

    + `register`：将变量归为寄存器存储类别，以最快速度访问，同时地址不被释放

    + `static`：用于块作用域声明，能保留其存储单元不被释放，但是只有在执行块内的代码时才能访问；且由于静态存储长期占用内存不释放降低了程序效率，同时调用多次后的当前值往往未知；如需对某些外部变量加以限制，只允许在本文件中被引用而不被其他文件引用，可使用关键字`static`对外部变量进行声明；还可用于限制函数的作用域。

    + `extern`：作为扩展作用域使用，如下

        + 在一个文件内扩展外部变量的作用域

            在定义点之前的函数引用外部变量，需要在引用之前使用关键字`extern`对该变量作**外部变量声明**，案例如下

            ```c
            int main()
            {
                extern int a, b, c;	// 把外部变量a, b, c作用域扩展至此
                return 0;
            }
            int a, b, c;	// 定义外部变量a, b, c
            ```

        + 将外部变量的作用域扩展到其他文件

            工程中其他文件如引用当前文件中的外部变量，需要在其他文件中使用关键字`extern`对当前文件中的外部变量作**外部变量声明**，案例如下

            ```c
            // file1.c
            int A;
            int main()
            {
                return 0;
            }
            
            // file2.c
            extern int A;	// 将file1.c中的外部变量A作用域扩展至此
            func()
            {
                int a = A;
            }
            ```

            关键字`extern`还可用于扩展函数的作用域。

    + `_Thread_local`：定义线程局部存储

    根据函数能否被其他源文件调用，可将函数分为**内部函数**和**外部函数**

    + 内部函数

        只能被本文件中的其他函数所调用，在定义时添加关键字`static`进行静态声明

    + 外部函数

        可供其他文件调用，在定义时添加关键字`extern`进行外部声明

    查找内存地址，可使用`&`运算符，使用转义字符`%p`进行打印，以十六进制形式表示。

5. 类型限定符

    通常用类型和存储类别来描述一个变量，恒常性、易变形、严格性和原子性，分别用关键字`const`、`volatility`、`restrict`和`_Atomic`声明。

    + `const`：限定变量为只读
    + `volatile`：告诉编译器该变量的值可能会在程序之外被修改，因此编译器不应对其进行优化
    + `restrict`：允许编译器优化某部分代码以更好地支持计算，只能用于指针，表明该指针是访问数据对象的唯一且初始的方式
    + `_Atomic`：确保对变量的操作是不可分割的，在多线程环境下要么完全执行，要么完全不执行，不会被打断，可避免竞争条件，多线程同时访问和修改共享变量时。

### 2.2 数组

1. 一维数组

    数组是按顺序存储的一系列类型相同的值，从0开始索引，使用方括号表面元素个数，大括号表明所含元素，一般使用符号常量表示数组大小，**在定义数组时，必须指定数组大小**。这里举冒泡排序算法为例

    ```c
    // 每次将相邻两个进行比较，然后移位
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
    ```

    选择法是先将10个数中最小的数与`a[0]`对换；再将剩余9个数中最小的数与`a[1]`对换；依此类推，总共需要9次。用选择法对数据进行排序

    ```c
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
    ```

    

2. 多维数组

    二维数组常称为**矩阵**，由行（row）和列（column）的排列形式。C语言中，**不能省略高维的大小说明**。二维数组中元素排列的顺序是按行存放，在内存中先顺序存放第1行的元素，再放第2行的元素，依次存放剩余。多维数组元素在内存中的排列顺序：第一维的下标变化最慢，最右边的下标变化最快。

    案例，气象研究员Tempest Cloud为完成她的研究项目要分析5年内每个月的降 水量数据，她首先要解决的问题是如何表示数据。

    ```c
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
    ```

    

3. 字符数组

    用双引号括起来的内容称为**字符串常量**，不可被更改。字符串是存放在字符型数组中，当元素个数小于数组长度，剩余元素自动定为**空字符**`\0`。字符串以空字符`\0`作为结束标志，由C系统自动添加。使用格式符`%c`输入或输出一个字符，格式符`%s`输入或输出一串字符，在进行字符串的输入时**系统把空格字符作为输入的字符串之间的分隔符**。函数`scanf()`使用格式说明符`%s`时，默认读取直到第一个空白符为止的字符序列，**空格之后的所有字符会留在输入缓冲区中**，这就会导致回车键作为第二次输入。

    字符串处理函数

    + `puts(string)`函数，自带换行符
    + `gets(string)`函数，获取键盘输入字符串
    + `strcat(str1, str2)`函数，把`str2`接到`str1`后面，结果存放在`str1`中。
    + `strcpy(str1, str2)`和`strncpy(str1, str2, n)`函数，把`str2`复制到`str1`中；把`str2`中前`n`各字符复制到`str1`中。
    + `strcmp(str1, str2)`函数，比较`str1`和`str2`，**小写字母比大写字母大**，两者相同时函数值为0；`str1>str2`时，函数值为正整数；`str1<str2`时，函数值为负整数。
    + `strlen(str)`函数，返回字符串的实际长度
    + `strlwr(str)`函数，将字符串中大写字母转换为小写字母
    + `strupr(str)`函数，将字符串中小写字母转换为大写字母

    初始化字符数组和初始化指针指向字符串有区别，如下

    ```c
    char str[] = "Hello World!";
    const char *pstr = "Hello World!";
    // 数组名str是常量，不可进行变量操作，如str++
    // 指针名pstr是变量，可进行变量操作，如pstr++
    
    // 未加const关键字的数组的元素是变量，但数组名是常量
    char *str = "Hello World!";
    str[0] = 'F';               // 字符串常量是不可变的
    printf("Hello World!\n");
    printf("%s\n", str);
    
    char str[] = "Hello World!";
    str[0] = 'F';				// 正常，字符数组元素运行被修改
    printf("%s\n", str);
    ```

    

4. 数组常用操作

    1. + 初始化

            分为两种初始化方式：无初始值、给定初始值。大多数编译系统在未指定初始值的情况下会将数组元素初始化为0。

            ```c
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
            ```

        + 访问元素

            数组元素被存储在连续的内存空间中，只需要给定数组内存地址和元素索引即可完成对元素的访问。

            ```C
            // 对元素的访问，时间复杂度为O(1)
            int my_arrayAccess(int *arr, int index)
            {
                return *(arr + index);
            }
            ```

        + 插入元素

            数组元素在内存中是“紧挨着的”，若想在数组中见插入一个元素，需要将该位置及之后的所有元素都向后移动一位，并且数组长度必须足够大。

            ```c
            // 数组元素的插入时间复杂度为O(n)
            void my_arrayInsert(int *arr, int size, int num, int index)
            { // 大小为size的数组，在index位置插入数字num
                for (int i = size - 1; i >= index; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[index] = num;
            }
            ```

        + 删除元素

            删除某处索引的元素，需要将该索引之后的所有元素向前移动一位。

            ```c
            // 数组元素的删除时间复杂度为O(n)
            void my_arrayDelete(int *arr, int size, int index)
            {
                for (int i = index; i < size - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
            }
            ```

        + 遍历元素

            通过索引遍历数组。

            ```c
            void my_arrayTraverse(int *arr, int size)
            {
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            ```

        + 查找元素

            数组中查找指定元素需要遍历数组，对每轮索引进行判断。

            ```c
            int my_arraySearch(int *arr, int size, int target)
            {
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] == target)
                        return i;
                }
                return -1;
            }
            ```

        + 扩容数组

            复杂的系统环境中，无法保证数组容量的安全扩展，**数组长度一般不可变**。现常用新建立一个更大的数组，将原数组元素按位复制到新数组。

            ```c
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
            ```

    **注意**：在定义了一个数组后，**该数组名是地址，是常量**，不能进行变量操作。字符数组由若干个元素组成，每个元素中放一个字符；而字符指针变量中存放的是地址，指向字符串第1个字符的地址；编译时为字符数组分配若干个存储单元，**为字符指针变量只分配一个存储单元**；指针变量可改变，字符数组名为常量不可改变；**字符数组中的元素可被改变，字符指针指向的字符串常量不可被改变**，`char *p = "hello"; *(p + 2) = 'r'`这种写法错误。

### 2.3 指针

1. 定义

    程序中定义了一个变量，在对程序进行编译时会给这个变量分配内存单元，该内存单元存放变量的值，该内存单元的地址即为变量的位置，**地址指向变量单元**，称地址为**指针**。C语言中的地址包括**位置信息**和其所指向的数据的**类型信息**，亦称为“带类型的地址”。变量地址可使用格式说明符`%p`打印。指针作为函数参数时，传递的是参数的地址，而不是参数的全部内容

    ```c
    int a = 10, b = 20;
    int *a_pointer = &a, *b_pointer = &b; // 定义两个整型指针变量
    printf("original a = %d, b = %d\n", a, b);
    printf("*a_pointer = %d, *b_pointer = %d\n", *a_pointer, *b_pointer);
    
    // 引用指针变量
    int num = 100;
    int *p;
    p = &num;	// 给指针变量p赋值，指向num
    printf("%d\n", *p);	// 引用指针变量指向的变量
    printf("%X\n", p);	// 引用指针变量的值
    
    // 指针变量作函数参数
    void swap(int *p1, int *p2)
    {
        int temp;
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
    
    // 用数组名、指针作函数参数，下面两种写法等价
    void print_array1(int a[], int len)
    {
        for(int i = 0; i < len; i++) printf("%d\n", a[i]);
    }
    
    void print_array2(int *P, int len)
    {
        for(int i = 0; i < len; i++, p++) printf("%d\n", *p);
    }
    ```

    符号`*`是指针运算符，用于访问指针变量所指向的对象。数组名是该数组首元素的地址，因此可通过指针引用数组。**指针变量的值可以被改变，数组名不可被改变**。

2. 方法

    引用一个数组元素，有以下两种方法

    + 下标法：`p[i]`
    + 指针法：`*(p++)`

    ```c
    // 两种方法遍历数组
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
    ```

    

3. 指针与多维数组

    对于多维数组，以二维数组`a[3][4]`为例。

    二维数组名`a`代表的是第一行的起始地址

    那么`a+1`为第二行的起始地址，`a[i]`相当于一个指针，指向第`i`行

    可认为`a`相当于一个双重指针，指向第一行这个数组，`(a+i)`指向第`i`行这个数组

    ```c
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
    
    ```

    **注意**：`a[i]`和`a`的区别在于，`a[i]`是一维指针，`a`是二维指针；`a[i]`是指向列元素的，`a`是指向行（一维数组）的。

    + 指向数组元素的指针变量

        ```c
        void my_pointerToArrayElement(int arr[3][4])
        {
            int *pArr = &arr[0][0];	// 指针pArr指向数组第一个元素
            for (pArr; pArr < arr[0] + 12; pArr++)
            {
                if ((pArr - arr[0]) % 4 == 0)
                    printf("\n");
                printf("%2d ", *pArr);
            }
        }
        ```

        

    + 指向由m个元素组成的一维数组的指针变量，即指向一维数组的指针

        例如定义`int (*p)[4];`是一个指向长度为4的`int`型数组，并且只能指向一个包含4个元素的一维数组。

        ```c
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
        ```

        **注意**：不可使用`int **p = arr;`，这是因为`*p`的类型未知，因此要保证指针的**基类型**一致。

    

4. 指针与函数

    函数在定义完后，编译时会被分配一段内存空间，该空间的起始地址即为该函数的入口地址。

    + 指向函数的指针

        **函数名代表函数的起始地址**，函数名就是函数的指针。函数指针可以被用来作为函数参数，接收函数指针的这个函数可以回调函数指针所指向的函数。

        ```c
        int (*p)(int, int);// 定义了一个指向函数的指针变量`p`，该函数类型为整型且有两个整型参数。
        int max(int x, int y);
        int a, b, c;
        p = max;
        c = (*p)(a, b);// 调用函数max()
        
        void Hello_print()
        {
            print("Hello\n");
        }
        
        void func_example(void (*ptr)())// 函数指针作为其参数，ptr指向一个函数，这个函数不带参数、无返回值
        {
            ptr();// 调用ptr所指向的哪个函数
        }
        
        void (*temp_func)();// 定义一个无参、无返回值的函数指针temp_func
        temp_func = Hello_print;
        
        int main()
        {
            func_example(temp_func);// 通过函数func_example()回调Hello_print()
        }
        ```

        

    + 返回指针的函数

        函数返回指针，一般形式`int *fun(int xn, int yn);`，相当于该函数返回一个地址。

    + 指针数组和多重指针

        数组的组成元素均为指针类型，称为**指针数组**，每一个元素都存放一个地址，如`int *p[4];`定义了一个大小为4的**整型指针数组**，适用于**指向若干个字符串**，类似二维数组。案例如下

        ```c
        char *name[] = {"Nancy", "Mia", "Kristin", "Sophia"};	// 每一个元素指向一个字符串
        ```

        指向指针的指针变量，亦称为**多重指针**。一般形式`char **p;`相当于`char*(*p);`，指向指针的指针变量存储的是所指向的指针的地址，相当于嵌套映射。

        ```c
        char **p;
        p = name + 2;				// p指向"Kristin"
        printf("%p\n", *p);			// 输出"Kristin"地址
        printf("%s\n", *p);			// 输出"Kristin"
        printf("%c\n", *(p[2]));	// 输出'i'
        ```

        **注意**：在定义指针时，一定要及时对其进行初始化，否则该指针所指向的内存单元不可预料。

### 2.4 内存分配

当声明一个数据类型时，其所需的内存在编译时就被分配，在离开其作用域后内存自动释放。由于在声明数组时，必须指定数组长度使用动态内存分配在运行时为其分配内存。对内存的动态分配有以下库函数

+ 用`void *malloc(unsigned int size);`开辟动态存储区

    在内存中动态存储区中分配一个长度为`size`**连续空间**，返回所分配区域的第一个字节的地址，分配失败则返回空指针（NULL）。

+ 用`void *calloc(unsigned n, unsigned size);`开辟动态存储区

    在内存的动态存储区中分配`n`个长度为`size`的连续空间，一般用于保存数组，即**动态数组**。返回所分配存储区域的第一个字节的地址，分配失败则返回空指针（NULL）。

+ 用`void *realloc(void *p, unsigend int size);`重新分配动态存储区

    在已用`malloc`或`calloc`函数分配了动态空间后想改变其大小，可用`realloc`函数重新分配，将`p`指向的动态空间大小改编为`size`，改变失败则返回空指针（NULL）。

+ 用`free(void *p);`释放动态存储区

    释放指针`p`所指向的动态空间，无返回值。

以上函数的声明在`stdlib.h`头文件中，结果是获得动态存储区的起始地址。`void`指针类型为“指向空类型”，在赋值时应注意**类型转换**。要注意的是在分配到存储区后，得到的是该区域第一个字节的地址，要使用该区域就必须使用指针。案例如下

### 2.5 内存中的栈和堆

1. 栈
2. 堆

### 2.6 建立数据类型

1. 结构体
2. 共用体
3. 枚举类型

## DataStructure & Algorithm

> 数据结构包括**逻辑结构（抽象关系）**、**存储结构**和**数据运算**，对数据类型进行抽象，**抽象数据类型**（Abstract Data Type, ADT）包括三部分：数据对象、数据关系和基本操作。

### 3.1 算法

**算法**是为了解决问题而规定的一个有限长的操作序列。一个算法必须满足以下五个特性

+ **有穷性**：有穷步骤
+ **确定性**：每种情况都有确定的结果
+ **可行性**：每一步骤可行
+ **输入**：有零个或多个输入
+ **输出**：有一个或多个输出

算法优劣的评价标准

+ 正确性：在合理的数据输入下，能在有限的运行时间内得到正确结果
+ 可读性：便于理解
+ 健壮性：当输入数据非法时，能做出正确反应
+ 高效性：包括时间和空间两方面，执行效率高和占用存储容量合理

一个程序的运行时间，依赖于算法的好坏和问题的输入规模。算法效率的度量方法主要有两类，事后统计法和事前分析估算法，通常采用**事前分析估算法**。

一条语句的重复执行次数称作**语句频度**（Frequency Count）。案例如下

```c
for(int i = 1; i <= n; i++)						// 频度为n+1
{
    for(int j = 1; j <= n; j++)					// 频度为n*(n+1)
    {
        c[i][j] = 0;						  // 频度为n^2
        for(int k = 1; k <= n; k++)				// 频度为n^2*(n+1)
            c[i][j] = c[i][j] + a[i][k] * b[k][j];	// 频度为n^3
    }
}
```

该算法中所有语句频度之和$T(n)$是结束$n$的函数，用$f(n)$表示，也就是算法的执行时间与$f(n)$成正比。

1. 算法的时间复杂度定义

    用"O"表示数量级，则上述算法可记作$T(n) = O(f(n))=O(n^3)$，表示随问题规模$n$的增大，算法执行时间的增长率和$f(n)$的增长率相同，称作算法的**渐近时间复杂度**，简称**时间复杂度**。

2. 算法的空间复杂度定义

    空间复杂度$S(n)$定义为该算法所消耗的存储空间，记作$S(n)=O(g(n))$，一般指所占用临时的工作单元数有关。

算法的时间复杂度和空间复杂度是相互影响的，通常假设运算空间充足，以时间复杂度作为算法优劣的衡量标准。

### 3.2 线性表

由有限个数据特性相同的元素构成的序列称为**线性表**，一般表示为$L = (a_1,a_2,...,a_n)$。对于非空的线性表或线性结构，有以下特点

+ 存在唯一一个“第一个”数据元素$a_1$，表头元素
+ 存在唯一一个“最后一个”数据元素$a_n$，表尾元素
+ 出第一个外，结构中的每个元素均只有一个前驱
+ 除最后一个外，结构中的每个元素均只有一个后继

![image-20250225205124061](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250225205124061.png)

对线性表进行数据类型抽象：

```c
ADT List{
    数据对象：D = {ai|ai belong to ElemSet}
    数据关系：R = {<ai-1, ai>|ai-1}
    基本操作：
        InitList(&L)：初始化，构造一个空的线性表
        LengthList(L)：求表长，返回线性表L的长度
        LocateElem(L, e)：按值查找，在L中查找值为e的元素
        GetElem(L, i)：按位查找，在L中查找第i位的元素
 	    ListInsert(&L, i, e)：插入操作，在i位插入元素e
 	    ListDelete(&L, i, &e)：删除操作，e返回删除元素的值
 	    PrintList(L)：输出操作，顺序打印表L元素
 	    EmptyList(L)：判空操作
 	    DestroyList(&L)：销毁操作，销毁线性表并释放L的内存空间
 	    ClearList(&L)：清空操作
}
```

#### 3.2.1 线性表的顺序表示和实现

线性表的顺序表示是**用一段地址连续的存储单元**依次存储线性表的数据元素（顺序表索引从1开始），这种表示称作线性表的顺序存储结构或顺序映像，逻辑位序和物理位序均相差1，称这种存储结构的线性表为**顺序表**。示意图如下

![image-20250225205636641](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250225205636641.png)

线性表的每个数据元素的类型都相同，即可用C语言中的一维数组来实现顺序存储结构，有两种方式

```c
// 静态分配
#define MAXSIZE 100
typedef int ElemType;
typedef struct _SqList_static	// 顺序表存储结构
{
    ElemType elem[MAXSIZE];
    int length;
}SqList_static;
// 动态分配，主要用于有指针操作的语言
#define MAXSIZE 100
typedef int ElemType;
typedef struct _SqList_dynamic
{
    ElemType *elem;
    int length;
}SqList_dynamic;
SqList_dynamic L;
L.elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
```

假设线性表中每个元素占用$l$个存储单元，那么线性表中第$i+1$个元素的存储位置$LOC(a_{i+1})$和第$i$个元素的存储位置$LOC(a_i)$之间满足关系$LOC(a_{i+1})=LOC(a_i)+l$，一般来说线性表的第$i$个元素$a_i$的存储位置为$LOC(a_i)=LOC(a_1)+(i-1)l$，其中$LOC(a_1)$是线性表的**起始位置**或**基地址**。顺序表内相邻元素有相邻的存储位置，**物理位置相邻**，顺序存储结构是一种随机存取的存储结构。

1. 初始化

    构造一个空的顺序表：为L动态分配一个预定义大小的数组空间，使`elem`指向这段空间的基地址；将表的当前长度设为0。

    + 为顺序表$L$分配数组空间（静态和动态），使数据$elem$指向该段空间的基地址
    + 将表的当前长度设为0

    静态分配适合于没有指针操作的语言，实现代码如下

    ```c
    SqList_static sqlist1;	// 顺序表
    sqlist1.length = 0;		// 初始化长度
    sqlist1.elem[0] = 1;
    sqlist1.elem[1] = 2;
    sqlist1.elem[2] = 3;
    sqlist1.elem[3] = 4;
    sqlist1.length = 4;		// 存储玩数据
    ```

    动态分配适合有指针操作的语言，实现代码如下

    ```c
    Status SqList_dynamic_Init(SqList_dynamic *L)
    {
        L->elem = (ElemType *)malloc(sizeof(ElemType) * SQLIST_MAXSIZE);
        if (L->elem == NULL)
            return STATUS_ERROR;
        L->length = 0;
        return STATUS_OK;
    }
    ```

    

2. 取值

    取值操作是根据指定位置序号$i$，获取顺序表中的第$i$个数据元素的值，将其存在参数$e$中，并返回`STATUS_OK`；位置序号不合理，则返回`STATUS_INFEASIBLE`。

    + 判断指定位置$i$是否合法，非法则返回`STATUS_INFEASIBLE`
    + 将第$i$个位置数据元素值`L.elem[i-1]`赋给参数`e`

    静态分配实现代码如下

    ```c
    int SqList_static_GetElem(SqList_static L, int i)
    {
        if (i < 1 || i > L.length)
            return STATUS_ERROR;
        int e = L.elem[i - 1];
        return e;
    }
    ```

    动态分配实现代码如下

    ```c
    Status SqList_dynamic_GetElem(SqList_dynamic L, int i, ElemType *e)
    {
        if (i < 1 || i > L.length)
            return STATUS_ERROR;
        *e = L.elem[i - 1];
        return STATUS_OK;
    }
    ```

    

3. 查找

    查找操作是根据指定的元素值$e$，查找顺序表中第1个与$e$相等的元素，查找成功则返回位置序号；查找失败则返回0。

    + 从第一个元素起，依次比较`L.elem[i]`和`e`，相匹配则返回序号`i+1`
    + 查找失败则返回0

    静态分配实现代码如下

    ```c
    int SqList_static_LocateElem(SqList_static L, ElemType e)
    {
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
        return 0;
    }
    ```

    动态分配实现代码如下

    ```c
    int SqList_dynamic_LocateElem(SqList_dynamic L, ElemType e)
    {
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
        return 0;
    }
    ```

    

4. 插入

    插入操作是在表的$i$个位置插入一个新的数据元素$e$，使长度为$n$的线性表变为长度为$n+1$的线性表，数据元素$a_i$及其后续数据元素均向后移动一位，在算法上需要从最后一个元素即第$n$个元素开始依次向后移动一个位置，直至第$i$个元素，共移动$(n-i+1)$个数据元素。

    + 判断插入位置$i$是否合法，非法则返回`STATUS_INFEASIBLE`
    + 判断顺序表存储空间是否充足，不够则返回`STATUS_OVERFLOW`
    + 将第$n$个至第$i$个位置的元素依次向后移动一位，空出第$i$个位置
    + 将要插入的元素$e$放入第$i$个位置
    + 表长加1

    静态分配实现代码如下

    ```c
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
    ```

    动态分配实现代码如下

    ```c
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
    ```

    顺序表在进行数据元素的插入时，时间主要耗费在元素的移动上，移动元素的个数取决于插入元素的位置。

5. 删除

    删除操作是将表中的第$i$个元素删除，将长度为$n$的线性表变为长度为$n-1$的线性表，数据元素$a_i$其后续数据元素均向前移动一位，在算法上需要从第$i+1$个元素开始依次向前移动一个位置，直至第$n$个元素，共移动$(n-i)$个元素。

    + 判断删除位置$i$是否合法，非法则返回`STATUS_INFEASIBLE`
    + 将第$i+1$个至第$n$个位置的元素依次向前移动一个位置
    + 表长减1

    静态分配实现代码如下

    ```c
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
    ```

    动态分配实现代码如下

    ```c
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
    ```

    

6. 打印

    打印操作是将表中的数据元素依次打印。

    + 判断表长度是否非空
    + 遍历打印数据元素

    静态分配实现代码如下

    ```c
    void SqList_static_Print(SqList_static L)
    {
        if (L.length == 0)
            printf("[]\n");
        for (int i = 0; i < L.length; i++)
        {
            printf("L.elem[%d] = %d\n", i, L.elem[i]);
        }
    }
    ```

    动态分配实现代码如下

    ```c
    void SqList_dynamic_Print(SqList_dynamic L)
    {
        if (L.length == 0)
            printf("[]\n");
        for (int i = 0; i < L.length; i++)
        {
            printf("L.elem[%d] = %d\n", i, L.elem[i]);
        }
    }
    ```

    

7. 获取表长度

    返回表长度

    静态分配实现代码如下

    ```c
    int SqList_static_Length(SqList_static L)
    {
        return L.length;
    }
    ```

    动态分配实现代码如下

    ```c
    void SqList_dynamic_Print(SqList_dynamic L)
    {
        if (L.length == 0)
            printf("[]\n");
        for (int i = 0; i < L.length; i++)
        {
            printf("L.elem[%d] = %d\n", i, L.elem[i]);
        }
    }
    ```

    

#### 3.2.2 线性表的链式表示和实现

线性表的链式表示是**用一组任意的存储单元存储线性表的数据元素**。为表示每个数据元素$a_i$，除了存储其本身的信息之外，还需要存储一个指示其后续的信息，这两部分信息组成数据元素$a_i$的存储映像，称为**结点**，每个结点包括两个域：数据域和指针域。$n$个结点链接成一个链表，即为线性表的链式存储结构。数据元素间的逻辑关系是由结点中的指针指示的，这种存储结构为非顺序映像或链式映像。

根据链表结点所含指针个数、指针指向和指针连接方式，可将链表分为单链表、循环链表、双向链表、二叉链表、十字链表、邻接表、邻接多重表等，其中单链表、循环链表、双向链表用于实现线性表的链式存储结构，其他形式多用于实现树和图等非线性结构。下图所示为线性表的单链表存储结构，**整个链表的存取必须从头指针开始进行**，头指针为链表中的第一个结点（基地址），最后一个结点指针为空。

![image-20250225221806339](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250225221806339.png)

通常将链表化成使用箭头相链接的结点序列，结点之间的箭头表示指针域中的指针，只需要表示线性表中数据元素之间的逻辑顺序即可，**单链表可由头指针唯一确定**。C语言中使用“结构指针”来描述

```c
// 单链表存储结构
typedef struct _LNode
{
    int data;
    struct _LNode *next;
}LNode;
```

这里对首元结点、头结点和头指针三个概念加以说明

![image-20250226195914911](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250226195914911.png)

+ 首元结点：链表中存储第一个数据元素的结点
+ 头结点：首元结点前附设的一个结点，数据域不存储信息（或存储与数据元素类型相同的附加信息），指针域指向首元结点；头结点作用：便于首元结点处理、便于空表和非空表的统一处理
+ 头指针：指向链表中第一个结点的指针，若没有头结点时指向首元结点，是链表必要元素

注：引入头结点后，头指针的指向始终为头结点，虽然会占用内存；未引入头结点，头指针的指向会发生改变。

1. 初始化

    构建一个指向头指针的指针，即一个二重指针，生成一个新结点，二重指针指向该结点（头结点），头结点指针域为NULL。

    + 生成新结点作为头结点，由头指针指向该结点
    + 头结点指针域置空

    带头节点代码实现如下

    ```c
    // 初始化参数必须是指针，即指向头指针的指针
    Status LinkList_Init(LinkList *L)
    {
        *L = (LNode *)malloc(sizeof(LNode));	// 头指针指向头节点
        if (*L == NULL)
            return STATUS_ERROR;
        (*L)->next = NULL;	// 头节点指针域为NULL
        return STATUS_OK;
    }
    ```

    不带头节点代码实现如下

    ```c
    ```

    

2. 取值

    取值操作只能从链表的首元结点出发，顺着链域`next`逐个结点向下访问。

    + 用指针`p`指向首元结点，用`j`做计数器
    + 从首元结点开始依次顺着链域`next`向下访问，只要当前结点指针`p`不为空，且没有到达序号`i`的结点，循环执行：`p`指向下一个结点，计数器`j`加1
    + 退出循环时，如果指针`p`为空或`j`大于`i`时，说明指定的序号`i`不合法；否则取值成功，有`j=i`，`p`所指的结点即为要找的`i`号数据元素，用参数`e`保存数据

    带头结点代码实现如下

    ```c
    Status LinkList_GetElem(LinkList L, int i, ElemType *e)
    {
        LNode *pTemp = L->next;	// 指向首元结点
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
    ```

    不带头结点代码实现如下

    ```c
    ```

    

3. 查找

    查找操作是从链表首元结点出发，依次将结点值与给定值$e$进行比较，返回目标结点地址。

    + 用指针指向首元结点
    + 从首元结点出发顺着链域向下查找，当前结点$p$指针域不为空且数据域不等于给定值$e$执行循环操作：$p$指向下一个结点
    + 查找成功则返回$p$，失败则返回`STATUS_ERROR`

    带头结点代码实现如下

    ```c
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
    ```

    不带头结点代码实现如下

    ```c
    ```

    

4. 插入

    插入操作是在表的第$i$个位置插入一个值为$e$的新结点$s$，插入到$a_{i-1}$到$a_i$之间。

    + 查找结点$a_{i-1}$
    + 创建新结点$s$，数据域为$e$，指针域为$a_i$
    + 将结点$a_{i-1}$的指针域更改为结点$s$

    带头结点代码实现如下

    ```c
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
    ```

    不带头结点代码实现如下

    ```c
    ```

    

5. 删除

    删除操作是将链表中的第$i$个位置的结点$p$删除，首先找到其前驱结点$o$，然后修改$o$的指针域即可。

    + 查找结点$a_{i-1}$，由指针$p$指向该结点
    + 临时保存结点$a_i$的地址在$q$中
    + 将结点$*p$的指针域指向$a_i$的后继结点
    + 释放结点$a_i$的空间

    带头结点代码实现如下

    ```c
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
    ```

    不带头结点代码实现如下

    ```c
    ```

    

6. 打印

    打印链表数据域操作是从链表头指针$phead$出发，顺着链域向下遍历，在链域不为`NULL`条件下打印数据域。

    + 新建结点指向首元结点
    + 顺着首元结点向下检索直到尾节点

    带头结点代码实现如下

    ```c
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
    ```

    不带头结点代码实现如下

    ```c
    ```

    

7. 获取长度

    求链表长度操作是从链表的头指针$phead$出发，设置计数器，顺着链域向下寻找，在链域不为`NULL`前提下进行计数，直至遇到`NULL`计数结束，即为链表长度。

    + 新建结点指向首元结点
    + 新建计数器从零开始计数
    + 顺着首元结点向下检索，结点指针域不为NULL则计数器加1，直到尾节点

    带头结点代码实现如下

    ```c
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
    ```

    不带头结点代码实现如下

    ```c
    ```

#### 3.2.3 顺序表和链表比较

+ 空间性能

    顺序表必须预先分配空间，已造成存储空间浪费或空间溢出；链表不需预先分配空间，元素个数没有限制。

    由于链表每个结点还要额外设置指针域，从存储密度上讲是不经济的。

+ 时间性能

    顺序表是一种随机存取结构，存取元素时间复杂度为$O(1)$；链表存取元素必须检索全链表，存取元素时间复杂度为$O(n)$。

#### 3.2.4 其他链表

对于单链表，结点中的指针域只存储了向后的指针，不能满足一些复杂问题，因此提出以下链表。

+ 循环链表

    将单链表中终端尾节点指针由NULL改为指向头节点，就使得整个单链表形成一个换，这种头尾相接的单链表称为**单循环链表**。示意图如下

    ![image-20250226212555556](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250226212555556.png)

+ 双向链表

    双向链表就是在单链表的每个结点中，在设置一个指向其前驱结点的指针域，使得链表可以双向检索。

    ![image-20250226212848349](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250226212848349.png)

#### 3.2.5 线性表的应用

线性表是其他数据结构的基础，因此应用非常广泛。

### 3.3 栈与队列

#### 3.3.1 栈

1. 定义

    栈（stack）是限定**仅在表尾进行插入或删除操作的线性表**。表尾称为**栈顶**，表头称为**栈底**；栈是自动管理的内存区域，系统进行自动分配和释放内存，采取先进后出**（FILO）**的原则，连续存储数据。栈的示意图如下所示

    ![image-20250226214033219](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250226214033219.png)

    栈对线性表的插入和删除位置进行了限制，**但并没有对元素进出的时间进行限制**，事先进入的元素也可最先出栈。

2. 栈的抽象数据类型

    对栈来说，将其插入和删除操作，改名为`push`和`pop`，即压栈和弹栈。基本操作还有栈的初始化、栈的长度、获取栈顶元素等，栈的抽象数据类型如下

    ```c
    ADT Stack{
            数据对象：D = {ai|ai belong to ElemSet}
        	数据关系：R = {<ai-1, ai>|ai-1, ai belong to D}
        	基本操作：
                InitStack(&S)：初始化
                DestroyStack(&S)：销毁
                ClearStack(&S)：清空
                StackEmpty(S)：是否空栈
                StackLength(S)：栈长度
                GetTop(S)：返回栈顶元素
                Push(&S, e)：将e压入栈
                Pop(&S, &e)：删除栈顶元素，用e返回
                StackTraverse(S)：遍历栈
    }ADT Stack

3. 表示和实现

    既然栈是线性表的特例，那么栈也有**顺序栈**、**链式栈**两种存储表示方式。

    + 顺序栈

        栈普通情况、空栈和栈满的情况示意图可表示如下

        ![image-20250307201400792](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250307201400792.png)
    
        顺序栈可表示如下
    
        ```c
        /* sequence Stack structure static */
        typedef struct _SqStack
        {
            ElemType elem[SQLIST_MAXSIZE];
            int top;
        } SqStack;
        
        /* sequence Stack structure dynamic */
        typedef struct _SqStack_dynamic
        {
            ElemType *elem;
            int top;
        } SqStack_dynamic;
        
        ```
    
        + 初始化
    
            顺序栈的初始化操作就是为顺序栈分配一块内存空间，将栈置为空。
    
            ```c
            void Stack_Init(SqStack *S)
            {
                S->top = -1; // 初始化栈为空
            }
            ```
    
            
    
        + 清空栈
    
            顺序栈的清空操作就是将栈置为空，丢弃所存储的数据。
    
            ```c
            void Stack_Clear(SqStack *S)
            {
                S->top = -1; // 清空栈
            }
            ```
    
            
    
        + 压栈
    
            顺序栈的压栈操作就是在栈顶插入一个新的元素
    
            ```c
            Status Stack_Push(SqStack *S, ElemType e)
            {
                if (S->top == STACK_MAXSIZE - 1)
                    return STATUS_ERROR;
                S->top++;            // 栈顶指针向上移
                S->elem[S->top] = e; // 将元素插入栈顶
                // S->elem[++S->top] = e;
                return STATUS_OK;
            }
            ```
    
            压栈操作可视化表示如下
    
            ![image-20250307201820165](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250307201820165.png)
    
        + 弹栈
    
            顺序栈的弹栈操作就是删除栈顶元素
    
            ```c
            Status Stack_Pop(SqStack *S, ElemType *e)
            {
                if (S->top == -1)
                    return STATUS_ERROR;
                *e = S->elem[S->top];
                S->top--; // 栈顶指针向下移
                return STATUS_OK;
            }
            ```
    
            
    
        + 获取栈顶元素
    
            顺序栈的获取栈顶元素操作
    
            ```c
            Status Stack_GetTop(SqStack S, ElemType *e)
            {
                if (S.top == -1)
                    return STATUS_ERROR;
                *e = S.elem[S.top];
                return STATUS_OK;
            }
            ```
    
            
    
        + 栈长度
    
            顺序栈的长度
    
            ```c
            int Stack_Length(SqStack S)
            {
                return S.top + 1;
            }
            ```
    
            
    
        + 栈遍历打印
    
            顺序栈的遍历打印
    
            ```c
            void Stack_Print(SqStack S)
            {
                for (int i = S.top; i > -1; i--)
                {
                    printf("Stack.elem[%d] = %d \n", i, S.elem[i]);
                }
                printf("\n");
            }
            ```
    
        + 共享栈
    
            共享栈使用同一段内存空间，一个栈的栈底为数组始端“0”处，另一个栈的栈底为数组末端“n-1”处，两栈向中间靠拢。共享栈可视化如下
    
            ![image-20250307202050989](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250307202050989.png)
    
            两栈共享空间结构代码实现如下
    
            ```c
            /* sharing sequence Stack structure */
            typedef struct _SqStack_shared
            {
                ElemType elem[STACK_MAXSIZE];
                int top1;
                int top2;
            } _SqStack_shared;
            
            Status SharingStack_Push(SqStack_shared *S, ElemType e, int stackNum)
            {
                if (S->top1 + 1 == S->top2) // 栈满
                    return STATUS_ERROR;
                if (stackNum == 1) // 栈1
                    S->elem[++S->top1] = e;
                else if (stackNum == 2) // 栈2
                    S->elem[--S->top2] = e;
                return STATUS_OK;
            }
            
            Status SharingStack_Pop(SqStack_shared *S, ElemType *e, int stackNum)
            {
                if (stackNum == 1) // 栈1
                {
                    if (S->top1 == -1)
                        return STATUS_ERROR;
                    *e = S->elem[S->top1--];
                }
                else if (stackNum == 2) // 栈2
                {
                    if (S->top2 == STACK_MAXSIZE)
                        return STATUS_ERROR;
                    *e = S->elem[S->top2++];
                }
                return STATUS_OK;
            }
            ```
    
            栈1为空时，top1=-1；栈2为空时，top2=n。两者栈顶相差1时，为栈满。两个栈的压栈和弹栈操作恰好相反。
    
    + 链式栈
    
        由于单链表有头指针，栈只是栈顶来做插入和删除操作，将栈顶放在链表的头部，栈底即为链表的尾部；链式栈基本不存在栈满的情况，链栈的结构代码表示如下
        
        ```c
        /* 链式栈结构如下 */
        typedef struct _StackNode
        {
            ElemType data;
            struct _StackNode *next;
        }StackNode, *LinkStackPtr;
        
        typedef struct _LinkStack
        {
            LinkStackPtr top;		// 栈顶
            int count;				// 栈中元素的个数
        }LinkStack;
        
        /* 另一种链式栈结构 */
        typedef struct _StackNode
        {
            ElemType data;
            struct _StackNode *next;
        }StackNode, *LinkStack;
        ```
        
        + 初始化
        
            顺序栈的初始化操作就是为顺序栈分配一块内存空间，将栈置为空。
        
            ```c
            ```
        
            

#### 3.3.2 栈的应用

> 在软件应用中，如浏览器网页的后退键，能返回之前所浏览的网页；还有编辑软件这撤销功能，可撤销上次操作。这些功能的实现都是通过**栈**这种数据结构实现。

1. 递归

    将一个直接调用自己或通过一系列的调用语句间接地调用自己地函数，称作递归函数。

    斐波那契数列案例，前面两项之和构成了后一项：$f(n)=f(n-1)+f(n-2)$，条件是$n=0$时有$f(n)=0$和$n=1$时有$f(n)=1$。递归实现代码如下

    ```c
    int Fbi(int n)
    {
        if(n < 2) return n == 0 ? 0 : 1;
        return Fbi(n - 1) + Fbi(n - 2)
    }
    ```

    在前行阶段，对于每一层递归，函数的局部变量、参数值以及返回地址都被压入栈中；退回阶段，位于栈顶的局部变量、参数值和返回地址被弹出，用于返回调用层次中执行代码的其余部分。

    

2. 四则运算表达式

    不需要括号的后缀表达式，称作“逆波兰”；标准四则运算表达式称作“中缀表达式”。



#### 3.3.3 队列

> 

1. 定义

    队列（queue）是一种先进先出（FIFO）的线性表，**限定仅在表的一端进行插入元素，而在另一端删除元素**，允许插入的一端称为**队尾**，允许删除的一端称为**队头**。队列的示意图如下所示

    ![image-20250310220656453](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250310220656453.png)

    

2. 队列的抽象数据类型

    基本操作还有队列的初始化、队列的长度、插入新元素。队列的抽象数据类型如下

    ```c
    ADT Queue{
            数据对象：D = {ai|ai belong to ElemSet}
        	数据关系：R = {<ai-1, ai>|ai-1, ai belong to D}
        	基本操作：
                InitQueue(&Q)：初始化
                DestroyQueue(&Q)：销毁
                ClearQueue(&Q)：清空
                QueueEmpty(Q)：是否空栈
                QueueLength(Q)：栈长度
                GetHead(Q, *e)：读取队头元素
                EnQueue(*Q, e)：插入尾部元素
                DeQueue(*Q, *e)：删除队头元素
                QueueTraverse(Q)：遍历栈
    }ADT Queue
    ```

    

3. 表示和实现

    队列作为一种特殊线性表，同样存在两种存储方式

    + 顺序队列

        顺序队列的出队时间复杂度为$O(n)$，引入两个指针，队头`front`和队尾`rear`，入队时，队尾指针`rear`加1；出队时，队头指针`front`加1。为避免“假溢出”现象发生，引入**循环队列**，头尾相连的顺序存储结构。

        ![image-20250311092814516](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311092814516.png)
    
        为判断队列是否满，定义条件`(rear - front + QueueSize) % QueueSize`。循环队列顺序结构代码实现如下
    
        ```c
        typedef struct _SqQueue
        {
            ElemType data[MAXSIZE];
            int front;
            int rear;
        }SqQueue;
        ```

        + 初始化
    
            静态分配一个大小为`MAXSIZE`的数组空间，头尾指针置为零，表示队列为空。
    
            ```c
            Status SqQueue_Init(SqQueue *Q)
            {
                Q->front = 0;
                Q->rear = 0;
                return STATUS_OK;
            }
            ```
    
            
    
        + 入队
    
            判断队列是否满；在队尾插入一个新的元素；尾指针加1。
    
            ```c
            Status SqQueue_EnQueue(SqQueue *Q, ElemType e)
            {
                if((Q->rear + 1) % QUEUE_MAXSIZE == Q->front)
                    return STATUS_ERROR;
                Q->elem[Q->rear] = e;                           // 将元素插入队尾
                Q->rear = (Q->rear + 1) % QUEUE_MAXSIZE;         // 队尾指针向后移
                return STATUS_OK;
            }
            ```
    
            
    
        + 出队
    
            判断队列是否为空；保存队头元素；头指针加1。
    
            ```c
            Status SqQueue_DeQueue(SqQueue *Q, ElemType *e)
            {
                if(Q->front == Q->rear)
                    return STATUS_ERROR;
                *e = Q->elem[Q->front];                         // 读取队首元素
                Q->front = (Q->front + 1) % QUEUE_MAXSIZE;       // 队首指针向后移
                return STATUS_OK;
            }
            ```
    
            
    
        + 遍历
    
            从头指针开始，递增加1，只要不等于尾指针，即可完成遍历。
    
            ```c
            void SqQueue_Traverse(SqQueue Q)
            {
                for (int i = Q.front; i != Q.rear; i = (i + 1) % QUEUE_MAXSIZE)
                {
                    printf("Queue.elem[%d] = %d ", i, Q.elem[i]);
                }
                printf("\n");
            }
            ```
    
            
    
    + 链式队列
    
        队列的顺序存储，算法时间性能不高，同时面临着溢出风险，引出链式队列，本质是特殊（尾进头出）的单链表。同链表结构，这里也分为带头结点和不带头结点两种结构。
      
      ![image-20250311095143089](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311095143089.png)
      
      链队列数据结构如下
      
      ```c
      typedef struct _LkQueueNode
      {
          ElemType data;
          struct _LkQueueNode *next;
      } LkQueueNode;
      
      typedef struct _LkQueue
      {
          LkQueueNode *front; // 队首
          LkQueueNode *rear;  // 队尾
      } LkQueue;  // 链式队列
      ```
      
      + 初始化
      
          带头结点和不带头结点初始化有所区别
      
          ```c
          Status LkQueue_withHead_Init(LkQueue *Q)
          {
              Q->front = Q->rear = (LkQueueNode *)malloc(sizeof(LkQueueNode)); // 初始时队首指针和队尾指针指向头节点
              if (Q->front == NULL)
                  return STATUS_ERROR;
              Q->front->next = NULL;  // 头节点的后继指针为空表示空队列
              return STATUS_OK;
          }
          
          Status LkQueue_withoutHead_Init(LkQueue *Q)
          {
              Q->front = Q->rear = NULL;  // 初始时队首指针和队尾指针指向空
              return STATUS_OK;
          }
          ```
      
          
      
      + 入队
      
          带头结点链队列入队非常方便，不带头结点链队列则需考虑空队列情况
      
          ```c
          Status LkQueue_withHead_EnQueue(LkQueue *Q, ElemType e)
          {
              LkQueueNode *p = (LkQueueNode *)malloc(sizeof(LkQueueNode)); // 申请新节点
              if (p == NULL)
                  return STATUS_ERROR;
              p->data = e;
              p->next = NULL;
              Q->rear->next = p; // 将新节点插入到队尾
              Q->rear = p;       // 队尾指针指向新节点
              return STATUS_OK;
          }
          
          Status LkQueue_withoutHead_EnQueue(LkQueue *Q, ElemType e)
          {
              LkQueueNode *p = (LkQueueNode *)malloc(sizeof(LkQueueNode)); // 申请新节点
              if (p == NULL)
                  return STATUS_ERROR;
              p->data = e;
              p->next = NULL;
              if(Q->front == NULL)    // 队列为空
                  Q->front = Q->rear = p;
              else
              {
                  Q->rear->next = p; // 将新节点插入到队尾
                  Q->rear = p;       // 队尾指针指向新节点
              }
              return STATUS_OK;
          }
          ```
      
          
      
      + 出队
      
          带头结点链队列出队非常方便，不带头结点链队列需要考虑空队列情况
      
          ```c
          Status LkQueue_withHead_DeQueue(LkQueue *Q, ElemType *e)
          {
              if (Q->front == Q->rear) // 队列为空
                  return STATUS_ERROR;
              LkQueueNode *p = Q->front->next; // 新结点p指向队首元素
              *e = p->data;                    // 读取队首元素
              Q->front->next = p->next;        // 删除队首元素
              if (Q->front->next == NULL)      // 队列为空
                  Q->rear = Q->front;          // 队尾指针指向头节点
              free(p);
              return STATUS_OK;
          }
          
          
          Status LkQueue_withoutHead_DeQueue(LkQueue *Q, ElemType *e)
          {
              if(Q->front == NULL) // 队列为空
                  return STATUS_ERROR;
              LkQueueNode *p = Q->front; // 新结点p指向队首元素
              *e = p->data;               // 读取队首元素
              Q->front = p->next;         // 删除队首元素
              if(Q->rear == p)            // 队列为空
                  Q->front = Q->rear = NULL;
              free(p);
              return STATUS_OK;
          }
          ```
      
          
      
      + 遍历
      
          只需从头结点递增遍历到尾结点即可
      
          ```c
          void LkQueue_withHead_Traverse(LkQueue Q)
          {
              LkQueueNode *p = Q.front->next;
              int i = 0;
              while(p != NULL)
              {
                  i++;
                  printf("Queue.elem[%d] = %d ", i, p->data);
                  p = p->next;
              }
              printf("\n");
          }
          
          void LkQueue_withoutHead_Traverse(LkQueue Q)
          {
              LkQueueNode *p = Q.front;
              int i = 0;
              while(p != NULL)
              {
                  i++;
                  printf("Queue.elem[%d] = %d ", i, p->data);
                  p = p->next;
              }
              printf("\n");
          }
          ```

#### 3.3.4 其他队列类型

单端队列规定一端入队，一端出队；改变此规定可演化其他类型队列

+ 双端队列

    ![image-20250311105707160](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311105707160.png)

+ 三段

#### 3.3.5 案例分析与实现

> 为加深栈与队列的理解，这里结合实际案例进行分析

+ 数制转换

    将一个十进制整数N转换为八进制数时，需要把N与8求余得到各位依次进栈，高位在栈底，低位在栈顶；依次出栈即为八进制数

    ```c
    void conversion(int N)
    {
        while(N)
        {
            push(S, N % 8);
            N = N / 8;			// 时间复杂度为log8(n)
        }
        while(!StackEmpty(S))
        {
            Pop(S, e);
            printf(e);
        }
    }
    ```

    

+ 括号匹配检验

    借助一个栈，每当读入一个左括号直接入栈；等待匹配的右括号将栈顶的左括号出栈。

    

+ 舞伴问题

    先入对的男士或女士先出队配成舞伴，男士和女士分别设置两个队列。



### 3.4 串、数组和广义表

#### 3.4.1 串的定义

> 串（string）是一种特殊的线性表，其数据元素是一个字符

串是由零个或多个字符组成的有限序列，又称**字符串**，用双引号表示。串的抽象数据类型

```c
ADT 串(string)
Data
串中元素仅由一个字符组成，相邻元素具有前驱和后继关系。
Operation
    StrAssign(T，*chars):生成一个其值等于字符串常量chars的串T。
    StrCopy(T，S):串s存在，由串s复制得串T。
    Clearstring(s):串S存在，将串清空。
    StringEmpty(S):若串S为空，返回true，否则返回false。
    strLength(s):返回串s的元素个数，即串的长度。
    strCompare(S,T):若S>T,返回值>0,若S=T,返回0,若S<T,返回值<0。
    Concat(T，S1，s2):用T返回由S1和S2联接而成的新串。
    Substring(Sub,S,pos,len):串s存在,1≤pos≤strLength(s)，
    月0≤len≤strLength(s)-pos+1，用Sub返回串s的第pos个字符起长度为1en的子串。
    Index(S,T,pos):串S和T存在，T是非空串,1Spos≤strLength(s)。若主串s中存在和串T值相同的子串，则返回它在主串s中第pos个字符之后第一次出现的位置，否则返回0。
    Replace(S,T,V):串S、T和V存在，T是非空串。用V替换主串s中出现的所有与T相等的不重叠的子串。
    StrInsert(S,pos,T):串s和T在,1≤pos≤strLength(s)+1。在串s的第pos个字符之前插入串T。
    StrDelete(s,pos,len):串s存在,1≤pos≤strLength(s)-len+1.从串s中删除第pos个字符起长度为 1en的子串。
    
endADT
```

#### 3.4.2 串的存储结构

串作为一种特殊的线性表，有两种基本存储结构：顺序存储和链式存储

1. 串的顺序存储结构

    用一组地址连续的存储单元来存储串中的字符序列，一般将实际串长度值保存在数组的0下标位置。

    ![image-20250311111729895](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311111729895.png)

    

2. 串的链式存储结构

    顺序串的插入和删除操作不方便，同时有溢出风险。引出链式串，每个结点即可存放一个字符，也可存放多个字符。

    ![image-20250311113724556](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311113724556.png)

    链式串存储结构如下

    ```c
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
    ```

    

#### 3.4.3 模式匹配算法

子串的定位运算称作**串的模式匹配**，一定在主串中存在的才叫“子串”。著名的模式匹配算法有BF算法和KMP算法

1. BF

     不一定是从主串第一个位置开始，可以指定主串中查找的起始位置`pos`，算法步骤如下

    + 利用计数指针`i`和`j`分别指示主串`S`和模式`T`中当前正待比较的字符位置，`i`初值为`pos`，`j`初值为1；
    + 如果两个串均未比较到串尾，即`i`和`j`均分别小于等于`S`和`T`的长度时，循环执行以下操作
        + `S[i].ch`和`T[i].ch`比较，相等则比较后续字符
        + 不等，则指针后退重新开始匹配，从主串下一个字符起重新和模式的第一个字符比较
    + 如果`j>T.length`，说明模式`T`中的每个字符依次和主串`S`中的一个连续的字符序列相等，则匹配成功，返回和模式`T`中第一个字符相等的字符在主串`S`中的序号；不成功，返回0。

    主串`S="ababcabcacbab"`，模式`T="abcac"`的BF算法匹配流程如下

    ![image-20250311171723850](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311171723850.png)

2. KMP

    朴素模式匹配算法低效，KMP算法可大大避免重复遍历的情况。每趟匹配过程中出现字符比较不等时，不需回溯`i`指针，而是利用已经得到的“部分匹配”的结果将模式向右“滑动”尽可能多的一段距离后，继续进行比较。KMP算法匹配流程如下

    ![image-20250311172454977](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311172454977.png)

    在第一趟匹配中出现字符不等时，仅需将模式向右移动两个字符的位置继续进行`i=3`、`j=1`时的字符比较。

#### 3.4.4 数组

> 数组是由类型相同的数据元素构成的有序集合，矩阵可用二维数组来表示。但对于高阶矩阵，以及很多值相同的元素时，为节省存储空间，采取压缩存储。

+ 堆成矩阵

    $n$阶矩阵元素满足$a_{ij}=a_{ji}$，可将$n^2$个元素压缩至$n\cdot (n+1)/2$个。

+ 三角矩阵

    $n$阶矩阵上三角/下三角元素为常数或0，只需存储不同元素的三角部分，再加一个存储常数的空间。

+ 对角矩阵

    非零元素都集中在以主对角线为中心的带状区域中，其余元素皆为零。

#### 3.4.5 广义表

> 广义表是线性表的推广，也称列表。

广义表一般记作：$LS=(a_1, a_2,...,a_n)$，有以下3个结论

+ 广义表的元素可以是子表，子表的元素还可以是子表
+ 广义表可为其他广义表所共享
+ 广义表可以是一个递归的表

广义表通常采用链式存储结构，有两种

1. 头尾链表的存储结构

    

2. 扩展线性链表的存储结构

### 3.5  树

#### 3.5.1 定义

**树**是$n$个结点的有限集，或为空树，或为非空树。树是一种递归定义的数据结构。树是一种一对多的数据结构，在任意一颗非空树中

+ 有且仅有一个特定的称为根的结点
+ 其余结点（$n>1$）可分为$m$个互不相交的有限集，每个集合本身又是一棵树，称为根的子树

![image-20250311204117855](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311204117855.png)

注意：**根**唯一，子树的个数没有限制，但它们一定是互不相交的；除了根节点，任一个结点都有且仅有一个前驱，可有0个或多个后继。

基本术语

+ 结点

    树中的一个独立单元

+ 结点的度

    结点拥有的子树数称为结点的度

+ 树的度

    各结点度的最大值

+ 叶子

    度为0的结点称为叶子或终端结点

+ 非终端结点

    度不为0的结点称为非终端结点或分支结点

+ 双亲和孩子

    节点的子树的根称为该节点的孩子，该节点称为孩子的双亲

+ 兄弟

    同一个双亲的孩子之间互称兄弟

+ 祖先

    从根到该节点所经分支上的**所有结点**

+ 子孙

    以某结点为根的子树中的任一结点称为该结点的子孙

+ 层次

    结点的层次从根开始定义起，根为第一层

+ 堂兄弟

    双亲在同一层的结点互为堂兄弟

+ 树的深度

    树中结点最大层次称为树的高度

+ 有序树和无序树

    将树中结点的各子树看成从左至右是有次序的，称有序树；否则称无序树。

+ 森林

    有$m$棵互不相同的树的集合，对树中每个结点而言，子树的集合称为森林。

对比线性表和树的结构，二者有很大不同，对比如下所示

![image-20250311220125001](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250311220125001.png)

根据树的结构定义，加上树的一组基本操作构成树的抽象数据类型

```c
ADT Tree{
数据对象 D:D是具有相同特性的数据元素的集合。
数据关系 R:若D为空集，则称为空树;
    若D仅含一个数据元素，则R为空集，否则R={H}，H是如下二元关系:
    (1)在口中存在唯一的称为根的数据元素root，它在关系 H下无前驱;
    (2)若D-{root}≠中，则存在D-{root}的一个划分D，D2，…，Dm(m>0)，对任意j≠k(1≤j，k≤m)有D;nDk =Φ，且对任意的i(1≤i≤m)，唯一存在数据元素X;∈D;，有<root,x:>eH;
    (3)对应于D-{root}的划分，H-{<root,x>，…，<root,x>=有唯一的一个划分H，H2，…
    H(m>0)，对任意j≠k(1≤j，k≤m)有HnHk-φ，且对任意i(1≤i≤m),H;是D,上的二元关系，(D:，{Hi})是一棵符合本定义的树，称为根 root 的子树。
基本操作 P:
    InitTree(&T)
    操作结果:构造空树 T。
    DestroyTree(&T)
    初始条件:树T存在。
    操作结果:销毁树 T。
    CreateTree(sT,definition)
    初始条件:definition 给出树T的定义。
    操作结果:按 definition 构造树 T。
    ClearTree(&T)
    初始条件:树T存在。
    操作结果:将树T清为空树。
    TreeEmpty(T)
    初始条件:树T存在。
    操作结果:若T为空树，则返回true，否则false。
    TreeDepth(T)
    初始条件:树T存在。
    操作结果:返回T的深度。
    Root(T)
    初始条件:树T存在。
    操作结果:返回T的根。
    Value(T,cur e)
    初始条件:树T存在，cure是T中某个结点。
    操作结果:返回cur e的值。
    Assiqn(T,cur e,value)
    初始条件:树T存在，cure是T中某个结点。
    操作结果:结点 cur e赋值为 value。
    Parent(T,cur e)i
    初始条件:树T存在，cure是T中某个结点。
    操作结果:若cure是T的非根结点，则返回它的双亲，否则函数值为“空”。
    LeftChild(T,cur e)
    初始条件:树存在，cure是T中某个结点。
    操作结果:若cure是T的非叶子结点，则返回它的最左孩子，否则返回“空”。
    RightSibling(T,cur e)
    初始条件:树T存在，cur_e是T中某个结点。
    操作结果:若cur_e有右兄弟，则返回它的右兄弟，否则兩数值为“空”。
    InsertChild(&T,p，i,c)
    初始条件:树T存在，p指向T中某个结点，1≤i≤p所指结点的度+1，非空树c与T不相交。
    操作结果:插人c为T中p指结点的第i棵子树。
    DeleteChild(&T，p，i)
    初始条件:树T存在，p指向T中某个结点，1≤i≤p指结点的度。
    操作结果:删除T中p所指结点的第i棵子树。
    TraverseTree(T)
    初始条件:树T存在。
    操作结果:按某种次序对T的每个结点访问一次。
}ADT Tree
```

#### 3.5.2 树的存储结构

+ 双亲表示法

    每个结点不一定有孩子，但是一定有且仅有一个双亲。以一组连续空间（顺序结构）存储树的结点，**在每个结点中，附设一个指示器指示其双亲结点在数组中的位置**。类似链表结点，双亲表示法定义代码表示如下

    ```c
    typedef int ElemType;
    
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
    ```

    案例，将下图中的树结构用树双亲表示

    ![image-20250312102310455](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312102310455.png)

    将其结构图和逻辑关系绘制成表格，结果如下图所示

    ![image-20250312102407510](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312102407510.png)

    这样可以根据`parent`指针很容易找到其双亲，但是要找到孩子必须遍历才行，可以增加一个结点（称**长子域**，最左边的孩子），如下表所示

    ![image-20250312103428631](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312103428631.png)

    若要关注兄弟之间的关系，双亲表示法无法体现这样的关系，需要增加一个结点（称**次子域**，最右边的孩子），如下表所示

    ![image-20250312104011333](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312104011333.png)

    要关注什么关系，设计对应的存储结构，保证时间复杂度最小。

+ 孩子表示法

    由于树中每个结点可能有多颗子树，可考虑多重链表，**每个结点有多个指针域，其中每个指针指向一颗子树的根结点**。有两种方案

    1. 方案一

        指针域的个数等于树的度（指向该节点的孩子），结构如下所示

        ![image-20250312104603008](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312104603008.png)

        案例表示如下图所示

        ![image-20250312104804132](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312104804132.png)

        对于各结点的度相差很大时，会很浪费空间，存在空指针域。

    2. 方案二

        指针域的个数等于该节点的度，专门取一个位置存储结点指针域的个数，结构如下表所示

        ![image-20250312105609743](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312105609743.png)

        结点包含，数据域、度域和指针域。案例实现如下

        ![image-20250312105716262](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312105716262.png)

        这种结构克服了空间上的浪费，但是要维护结点的度的数值，在运算上带来时间上的损耗。

    把每个结点放在一个顺序存储结构的数组中是合理的，但每个结点的孩子有多少未知，因此需要再对每个结点的孩子建立一个单链表体现它们的关系。把每个结点的孩子结点排列起来，以单链表作存储结构，头指针组成一个线性表，存进一个一维数组中。如下图所示

    ![image-20250312110245966](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312110245966.png)

    为此需要设计两种结点结构，一个是孩子链表的孩子结点，存放孩子；另一个是表头数组的表头结点，存放数据。代码实现如下

    ```c
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
    ```

    但是这种方法无法知道双亲是谁，可增加一个双亲域。如下图所示

    ![image-20250312111614490](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312111614490.png)

+ 孩子兄弟表示法

    任一棵树，其结点的第一个孩子如果存在就是唯一的，右兄弟如果存在也是唯一的，设置两个指针，分别指向该结点的第一个孩子和此结点的右兄弟。结点结构如下表所示

    ![image-20250312112641337](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312112641337.png)

    结构定义代码如下所示

    ```c
    typedef struct _CSNode
    {
        ElemType data;
        struct _CSNode *firstchild, *nextSibling;
    }CSNode, *CSTree; // 孩子结点
    ```

    案例示意图如下图所示

    ![image-20250312112944861](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312112944861.png)

    当然，要找到某个结点的双亲，需要再增加一个双亲域。

#### 3.5.3 二叉树

**二叉树**是$n$个结点所构成的集合，或为空树，或为非空树。对于非空树$T$满足

+ 有且仅有一个称之为根的结点
+ 除根结点以外的其余结点分为两个互不相交的子集$T_1$和$T_2$（次序不能任意颠倒），分别成为$T4$的左子树和右子树，且$T_1$和$T_2$本身又都是二叉树

二叉树可以有5种基本形态，如下图所示

![image-20250312113741224](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312113741224.png)

在了解完二叉树定义后，介绍一些特殊的二叉树

+ 斜树

    所有结点都只有左子树的二叉树称作**左斜树**；所有结点都只有右子树的二叉树称作**右斜树**。斜树每一层都只有一个结点，结点的个数与二叉树的深度相同，本质上线性表是树的一种特殊表现形式。

+ 满二叉树

    所有分支结点都存在左子树和右子树，并且所有叶子都在同一层上，成这样的二叉树为**满二叉树**。

    特点如下

    + 叶子只能出现在最下一层
    + 非叶子结点的度一定是2
    + 在同样深度的二叉树中，满二叉树的结点个数最多

+ 完全二叉树

    对一颗具有$n$个结点的二叉树按层序编号，**编号为$i$的结点与同样深度的满二叉树中编号为$i$的结点在二叉树中位置完全相同**，则这棵二叉树称为完全二叉树。

    特定如下

    + 叶子结点只能出现在最下两层
    + 最下层叶子一定集中在左部连续位置
    + 倒数两层，若有叶子结点，一定都在右部连续位置
    + 如果结点度为1，则该结点只有左孩子
    + 同样结点数的二叉树，完全二叉树深度最小

#### 3.5.4 二叉树的性质

1. 性质1

    在二叉树的第$i$层**至多**有$2^{i-1}$个结点

2. 性质2

    深度为$K$的二叉树**至多**有$2^K-1$个结点

3. 性质3

    对任一颗二叉树$T$，如果其终端结点数为$n_0$，度为2的结点数为$n_2$，则有$n_0=n_2+1$。

4. 性质4

    具有$n$个结点的完全二叉树深度为$[log_2n]+1$（$[x]$表示不大于$x$的最大整数）

5. 性质5

    对一颗有$n$个结点的完全二叉树的结点按层序编号，对任一结点$j$有

    + $j=1$，结点$j$是二叉树的根，无双亲；$j>1$，双亲是结点$[j/2]$
    + $2j>n$，则结点$j$无左孩子；否则其左孩子是结点$2i$
    + $2j+1>n$，则结点$j$无右孩子；否则其右孩子是结点$2j+1$

#### 3.5.5 二叉树的存储结构

二叉树也可采用顺序存储和链式存储两种方式

1. 顺序存储

    用一维数组存储二叉树中的结点，并且结点的存储位置就是数组下标要能体现结点之间的逻辑关系。一颗完全二叉树如下图

    ![image-20250312142639053](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312142639053.png)

    该树在数组中的位置如下图所示

    ![image-20250312142714561](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312142714561.png)

    可以看出树的逻辑关系与性质5完全对应。对于一般二叉树，必须将其按完全二叉树编号，不存在的结点设置为$\wedge$，如下图所示

    ![image-20250312144522389](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312144522389.png)

    

2. 链式存储

    由于顺序结构对于一般二叉树会造成存储空间的极大浪费，因此一般二叉树更适合链式存储结构。设计一个包含一个数据域和两个指针域的结点，有此类结点组成的链表称之为**二叉链表**。结构示意图如下

    ![image-20250312144840735](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312144840735.png)

    结点定义代码如下

    ```c
    typedef struct _BiTNode
    {
        ElemType data;
        struct _BiTNode *lchild, *rchild;   // 左右孩子指针
    }BiTNode, *BiTree;
    ```

    上述结构对于查找孩子十分方便，但要找到双亲结点，则只能从根开始遍历寻找，可添加一个双亲域，组成三叉链表

    ```c
    typedef struct _BiTNode
    {
        ElemType data;
        struct _BiTNode *lchild, *rchild, *parent;   // 左右孩子指针，双亲指针
    }BiTNode, *BiTree;
    ```

#### 3.5.6 遍历二叉树

二叉树的遍历是指从根结点出发，按照某种次序依次访问二叉树中的所有结点，使得每个结点被访问依次且仅被访问一次。二叉树主要分以下四种

+ 前序遍历

    若二叉树为空，则空操作返回；否则先访问根结点，然后前序遍历左子树，再前序遍历右子树。示意图如下

    ![image-20250312151804389](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312151804389.png)

    实现代码如下

    ```c
    void PreOrderTraverse(BiTree T)
    {
        if(T == NULL) return;
        printf("data: %d\n", T->data);
        PreOrderTraverse(T->lchild);    // 先序遍历左子树
        PreOrderTraverse(T->rchild);    // 先序遍历右子树
    }
    ```

    

+ 中序遍历

    若二叉树为空，则空操作返回；否则从根结点开始，中序遍历根结点的左子树，然后是访问根结点，最后中序遍历右子树。示意图如下

    ![image-20250312151919702](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312151919702.png)

    实现代码如下

    ```c
    void InOrderTraverse(BiTree T)
    {
        if(T == NULL) return;
        InOrderTraverse(T->lchild);     // 中序遍历左子树
        printf("data: %d\n", T->data);
        InOrderTraverse(T->rchild);     // 中序遍历右子树
    }
    ```

    

+ 后序遍历

    若二叉树为空，则空操作返回；否则从左到右先叶子后结点的方式遍历访问左右子树，最后是访问根结点。示意图如下

    ![image-20250312152018274](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312152018274.png)

    实现代码如下

    ```c
    void PostOrderTraverse(BiTree T)
    {
        if(T == NULL) return;
        PostOrderTraverse(T->lchild);   // 后序遍历左子树
        PostOrderTraverse(T->rchild);   // 后序遍历右子树
        printf("data: %d\n", T->data);
    }
    ```

    

+ 层序遍历

    若二叉树为空，则空操作返回；否则从树的第一层，也就是根结点开始访问，从上而下逐层遍历，在同一层中，按从左到右的顺序对结点逐个访问。示意图如下

    ![image-20250312152150087](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312152150087.png)

    代码实现如下

    ```c
    /*
     - 初始化一个辅助队列
     - 根结点入队
     - 若队列非空，则队头结点出队，访问该结点，并将其左、右孩子插入队尾
     - 重复第三步操作直至队空
    */
    void LevelOrderTraverse(BiTree T)
    {
        LinkQueue Q;
        InitQueue(Q);
        BiTree p;
        EnQueue(Q, T);
        while(!IsEmpty(Q))
        {
            DeQueue(Q, p);
            visit(p);
            if(p->lchild != NULL) EnQueue(Q, p->lchild);
            if(p->rchild != NULL) EnQueue(Q, p->rchild);
        }
    
    }
    ```

    

#### 3.5.7 二叉树的构造和线索二叉树

若只给出一颗二叉树的前/中/后/层序遍历序列中的一种，不能唯一确定一颗二叉树。

```c
void CreateBiTree(BiTree *T)
{
    ElemType data1;
    *T = (BiTree)malloc(sizeof(BiTree));
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
}
```

遍历二叉树实质上是对一个非线性结构进行线性化操作，使每个结点在这些线性序列中有且仅有一个直接前驱和直接后继。引入线索二叉树来保存这些在动态过程中得到的有关前驱和后继的信息，在每个结点在增设两个标志域`ltag`和`rtag`，这两个标志与只存放0或1。结点结构如下表所示

![image-20250312162251591](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312162251591.png)

案例示意图如下

![image-20250312162342014](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312162342014.png)

实现代码如下

```c
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
```

线索化的实质就是将二叉链表中的空指针改为指向前驱或后继的线索，**线索化的过程就是在便利的过程中修改空指针的过程**。

#### 3.5.8 树、森林

1. 树转换为二叉树

    树结构如下图所示

    ![image-20250312163321107](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312163321107.png)

    + 加线，在所有兄弟结点之间加一条连线

        ![image-20250312163459445](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312163459445.png)

    + 去线，对树中每个结点，只保留其与第一个孩子结点的连线，删除其与其他孩子结点之间的连线

        ![image-20250312163542987](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312163542987.png)

    + 层次调整，以树的根结点为轴心，将整棵树顺时针旋转一定角度，使之结构层次分明

        ![image-20250312164353479](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312164353479.png)

2. 森林转换为二叉树

    森林是由若干棵树组成，森林中的每一棵树都是兄弟，可以按照兄弟的处理方法操作。森林结构如下

    ![image-20250312164525900](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312164525900.png)

    + 把每棵树转换为二叉树

        ![image-20250312164658690](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312164658690.png)

    + 第一颗二叉树不动，从第二课二叉树开始，依次把后一颗二叉树的根结点作为前一棵二叉树的根结点的右孩子，用线连接起来。

        ![image-20250312164716990](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312164716990.png)

3. 二叉树转换为树

    二叉树转换为树是树转换为二叉树的逆过程。二叉树如下

    ![image-20250312164905504](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312164905504.png)

    + 加线，若某结点的左孩子结点存在，则将这个左孩子的有孩子结点、右孩子的右孩子结点、右孩子的右孩子的右孩子结点...，就是左孩子的$n$个右孩子结点都作为此结点的孩子。将该结点与这些右孩子结点用线连接起来。

        ![image-20250312165209925](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312165209925.png)

    + 去线，删除原二叉树中所有结点与其右孩子结点的连线。

        ![image-20250312165510795](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312165510795.png)

4. 二叉树转换为森林

    判断一颗二叉树能转换为一棵树还是森林，就是要看这棵二叉树的根结点有没有右孩子，有就是森林，没有就是一棵树。

    ![image-20250312165709901](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312165709901.png)

    + 从根结点开始，若右孩子存在，则把右孩子结点的连线删除

        ![image-20250312165833217](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312165833217.png)

    + 再查看分离后的二叉树，若右孩子存在，则连线删除，直到所有右孩子连线都删除为止

        ![image-20250312165843891](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312165843891.png)

    + 再将每颗分离后的二叉树转换为树即可

        ![image-20250312165942891](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312165942891.png)

#### 3.5.9 哈夫曼树

1. 定义

    **哈夫曼树**又称最优树，是一类带权路径长度最短的树。给出如下概念定义

    + 路径：从树中的一个结点到另一个结点之间的分支构成这两个结点之间的路径
    + 路径长度：路径上的分支数目称作路径长度
    + 树的路径长度：从树根到每一结点的路径长度之和
    + 权：赋予某个实体的一个量，是对实体的某个或某些属性的数值化描述
    + 结点的带权路径长度：从该结点到树根之间的路径长度与结点上权的乘积
    + 树的带权路径长度：树中所有叶子结点的带权路径长度之和，常记作$WPL=\sum_k^nw_kl_k$
    + 哈夫曼树：假设有$m$个权值，可构造一颗含$n$个叶子结点的二叉树，每个叶子结点的权为$w_1$，则其中带权路径长度$WPL$最小的二叉000000树称作最优二叉树或哈夫曼树。

2. 构造算法

    二叉树结构如下

    ![image-20250312173113206](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312173113206.png)

    + 先把有权值的叶子结点按照从小到大的顺序排列成一个有序序列

    + 取头两个最小权值的结点作为一个新结点$N_1$的两个子结点，较小的是左孩子

        ![image-20250312173331233](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312173331233.png)

    + 将$N_1$替换$A$与$E$，插入有序序列中，保持从小到大排列

    + 重复步骤2，将$N_1$与B作为一个新结点$N_2$的两个子结点

        ![image-20250312173430821](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312173430821.png)

    + 将$N_2$替换$N_1$和B，插入有序序列中，保持从小到大排列

    + 重复步骤2，将$N_2$与D作为一个新结点$N_3$的两个子结点

        ![image-20250312205740108](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312205740108.png)

    + 将$N_3$替换$N_2$与D，插入有序序列中，保持从小到大排列

    + 重复步骤2，将$N_3$和C作为一个新结点T的两个子结点

        ![image-20250312205944794](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312205944794.png)

    构造哈夫曼树的哈夫曼算法可总结如下

    ![image-20250312210203055](https://cdn.jsdelivr.net/gh/Zhang-TNT/markdown-imgs@main/imgs/image-20250312210203055.png)

    

3. 应用

    哈夫曼编码进行数据压缩

### 3.6 图

#### 3.6.1 定义

图是由顶点的有穷非空集合和顶点之间边的集合组成的，通常表示为G，V是图G中顶点的集合，E是图G中边的集合。

### 3.7 查找

### 3.8 排序

