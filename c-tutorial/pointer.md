## 指针

> 内存的每一个存储单元，都有一个地址编号，方便操纵数据，以字节为单位。专门用来存放地址的变量，即指针变量。



1. 下面程序输出结果是（        ）

```c
#include<stdio.h>
int main()
{
    int x = 1, y = 2;
    int *ip;	// ip is a pointer to int
    ip = &x;	// ip now points to x
    y = *ip;	
    *p = 0;
    printf("%d %d", x, y);
    return 0;
}
```