## 第一章：C语言基础知识

[TOC]

*2021.9.1*

###### 知识点1  输出 Hello World

```c
#include<stdio.h>
main()
{
    printf("Hello World.\n");
}
```

代码讲解

```tex
1）
#        预处理
include  包含
stdio.h  标准输入输出头文件（键盘鼠标显示器）

2）
主函数
main()
{}

C程序的基本单位是函数。main函数是程序的入口，有且只有一个。main函数可以写在文件的任何地方。

3）
print  输出函数。引号里的内容会输出到屏幕。分号是一句话的结束。

4）编写代码的过程
打开代码编辑器，新建文件，输入源代码--> 编译 --> 链接 --> （生成可执行二进制文件）运行

```

课堂练习

```tex
// 1）随机请同学上台，编写代码输出自己的名字

// 2) 找出下面代码错误所在行并改正
include<stdio.h>
mian(
{
    printf("Hello)
}

// 3) 教材P17 选择题

```



###### 知识点2  基本数据类型

基本数据类型

```tex
int        整型          32位        sizeof(int)
char       字符          8位         sizeof(char)
float      单精度浮点     32位
double     双精度浮点     64位
```

修饰符

```tex
1）signed 有符号，二进制最高位1表示负数，二进制最高位0表示正数。unsigned 无符号。只能修饰char和int。

2）short  只能修饰 int ，表示短整型。

3）long 只能修饰int 和 double。sizeof(long double) 是16字节。sizeof(long int) 是4字节。

```

课堂练习

```tex
// 编写程序，通过sizeof 输出每个基础类型的大小。

#include<stdio.h>
int main()
{
    printf("char:%d\n", sizeof(char));
    printf("short:%d\n", sizeof(short));
    printf("int:%d\n", sizeof(int));
    printf("long:%d\n", sizeof(long));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
	printf("long double:%d\n", sizeof(long double));
}
```



###### 知识点3  常量与变量

- 整型常量

```tex
-1234
01234    八进制，以0开头
0x1234   十六进制，以0x开头
0L       long类型的十进制整数常量
```

- 浮点型常量

```tex
1) 十进制小数书写
  1.0    默认是double类型
  .5
  6.
  
main()
{
    printf("%d", sizeof(1.0));
}

2）科学计数法书写
  1.234e2    默认是double类型
书写规则：e的前面和后面必须要有数，e的后面只能是整数。
错误写法：1.0e1.2 和 .e2   

```

- 字符型常量

```tex
1)字符常量：
单引号括起来的单个字符，例如，'A'
字符在内存中实际是以8位二进制整数形式存储的，即ASCII码，A是65， a是97，0是48等。
main()
{
    putchar('A');
    putchar(65);
    putchar('0');
    putchar(48);
    putchar('\n');
}

2)转义字符
'\n'
'\t'
'\\'
'\''
'\"'
'\x41'
'\101'

3)字符输出
printf("%c", 'A');
putchar('A');

```

- 宏常量

```tex
// 宏常量制作简单的替换
#define PI 3.14
```



- 变量

```tex
在程序运行过程中用来存储值的称为变量。变量和内存对应，必须先定义再使用。变量定义时，名字只能由字母、数字、下换线组成且第一个字母只能是字母或下换线。

变量名不能使用系统关键字，P2表1-1，32个关键字。
```

```c
// 找出错误并修改：________________
#include<stdio.h>
main
{
    int a;
    a = 5;
    printf("%d\n", a);
}
```

```c
// 找出错误并修改：________________
#incude<stdio.h>
main()
{
    int a, b;
    a = 1
    b = 2
    printf("%d", a+b);
}
```

```c
// 找出错误并修改：________________
#include<stdio.h>
main()
{
    int x;
    x = 3;
    y = 5;
    z = x * y;
    printf("z=%d", z);
}
```





## HelloWorld

例2：输入直径，输出圆的面积和周长

```c
#define PI 3.141592654
int main()
{
    float d;
    __________________;  // 输入直径
    
    float r;    
    r = ________;        // 求半径
   
    float len ;       
    len = _____________; // 求周长PI * d
    
    float area;       
    area = ___________;  // 求面积
    
    __________________;  // 输出面积和周长
}
```

例3：(2018高考) 若 `int a = 12; `  执行 `a /= a + 8` 后，a的值是（        ）

 ```tex
A. 1        B. 8         C. 9        D. 0
 ```

例4：已知 `i = 3;`执行  `j = ++i;`后，i和j的值分别为（        ）

```tex
A. i = 4  j = 4     B. i = 4  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

例5：已知 `i = 3;`执行  `j = i++;`后，i和j的值分别为（        ）

```tex
A. i = 4  j = 4     B. i = 4  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

例6：已知 `i = 3;`执行  `j = --i;`后，i和j的值分别为（        ）

```tex
A. i = 2  j = 2     B. i = 4  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

例7：已知 `i = 3;`执行  `j = i--;`后，i和j的值分别为（        ）

```tex
A. i = 2  j = 2     B. i = 2  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```



###### 小结

1. main函数，输出函数 printf，输入函数 scanf

2. 运算符  =  ,  /=，

3. 递增++，递减--



