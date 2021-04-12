## 函数

[TOC]

###### 1. 函数的定义

```tex
类型说明符  函数名(形参列表)
{
	语句;
}
```

```c
int max(int x, int y)
{
    int z = x > y ? x : y;
    return z;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", max(a,b));
}
```

###### 2. 函数的申明与调用

```c
int max(int x, int y); 
int sum(int n);		   // 函数声明
int main()
{
    int a = 5, b = 6, c;
    c = max(a, b);		// 函数调用
    printf("%d", c);
}
int sum(int n)			// 函数定义 , 求1+2+...+n
{
    int i, total = 0;
    for(i = 1; i <= n; i++)
        total += i;
    return total;
}
```

###### 3. 函数形参

```c
// 1）基础类型变量作为函数形参
void swap1(int a, int b)
{
    int t;
    t = a; a = b; b = t;
}
// 2）指向基础类型的指针作为函数形参
void swap2(int *pa, int *pb)
{
    int t;
    t = *pa;*pa=*pb;*pb=t;
}
int main()
{
    int a = 3, b = 4;
    swap1(a,b);printf("%d %d\n",a,b);
    swap2(&a,&b);printf("%d %d\n", a, b);
}
```

```c
// 3）一维数组名作为函数形参
void printfa(int a[], int n) // a 是一维数组首地址，是指向int的指针， int *a;
{
    int i;
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);
}

// 4）二维数组名作为函数形参
void printfa2(int a[][4], int n) // a是二维数组首地址，是指向一维数组的指针, int (*a)[4];
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 4; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

// 5) 指针数组名作为函数形参
int main(int argc, char *argv[]) //argv是一维数组名，数组里的每个元素都是一个指针，int **p;
{
    int i;
    for(i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
}
```

###### 4. 变量作用域与存储方式

```c
//1)局部变量 auto  
//  作用域（空间）：只在{}内部有效.                     例1：P108 例6-8 
//  生命周期（时间）：函数调用时生成，函数调用结束释放    例2：P119 T3  例3：swap(int a, int b)


//2)全局变量 extern 
//  作用域（空间）：在全局有效            例1：P109 例6-9  例2：P118  T1
//  生命周期（时间）：程序运行期一直存在   例3：P110 例6-10  局部变量、全局变量同名时，优先访问离自己进的局部变量
//  

//3)静态变量 static 一直
//  作用域（空间）：  只在{}内部有效      例1：P112 例6-11
//  生命周期（时间）：程序运行期一直存在   例2：P119 T2

//4)寄存器变量 register
//  很少用。
```

###### 5. 递归调用

```tex
递归函数三要素
1）函数自己调用自己
2）每次递归调用函数形参发生变化
3）函数内有递归结束条件
```

```c
// 求 n! = 1*2*...*n
int fac(int n)
{
    if(n <= 1) return 1;
    else return n*fac(n-1);
}

// 求Fibonacci序列第n项
int fib(int n)
{
    if(n <= 2) return 1;
    else return fib(n-1) + fib(n-2);
}
```

###### 