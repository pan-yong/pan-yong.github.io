## hello world



###### 1. 第一个简单的C程序

```c
#include<stdio.h>
main()
{
    printf("hello world");
}
```

```tex
#        预处理
include  包含
stdio.h  标准输入输出头文件
main(){} 主函数，C程序的入口，必须要有，且只有一个。
printf   输出函数
;        每条C语言语句以分号结束
```

###### 2. 函数

构成C程序的基本单位是函数。函数术语，源于数学，指根据一个或多个给定的参数进行数值计算的规则：
$$
f(x) = x + 1，g(y,z) = y^2 - z^2
$$
C语言中，函数是一组被赋予名字了的语句，所计算的值通过return返回，例如：

```c
#include<stdio.h>
int sum(int a, int b)
{
    return a + b;
}
int main()
{
    int z;
    z = sum(3,5);
    printf("%d", z);
    return 0;
}
```

```tex
int 表示整型。
int z 表示整型变量。
int a, int b 表示函数形式参数，调用时要对应传入两个int值。
int sum 表示函数的返回值是整型，函数的返回值通过return指定。
z = sum(3,5) 函数调用，函数的返回值通过z变量接收。
printf 输出函数，十进制整数输出z。
main 主函数，C程序的入口，默认是int类型，返回值 return 0 表示程序正常结束。
```



###### 3. C程序上机步骤

- [Dev C++](https://bloodshed-dev-c.en.softonic.com/) 编译器

```tex
第一步：打开Dev C++  -->  文件  -->  新建源代码 
第二步：编写代码，并保存。
第三步：编译  -->  链接  -->  运行（可执行二进制文件）
```

- 其它编译器

    - [在线编译器](https://c.runoob.com/compile/11/)
    - GCC编译器
    - Microsoft Visual C++ 2010

    

###### 4. 英文盲打练习

- 背记键盘，熟悉常用符号所在位置。

<img src=".\images\打字" alt="img" style="zoom:70%;" />

