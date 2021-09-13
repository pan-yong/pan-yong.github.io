## 第一章：C语言基础知识

[TOC]

*2021.9.1*

##### 知识点1  输出 H·ello World

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

##### 知识点2  基本数据类型

基本数据类型

```tex
int        整型          32位        sizeof(int)
char       字符          8位         sizeof(char)
float      单精度浮点     32位
double     双精度浮点     64位
```

修饰符

```tex
1）signed 有符号，二进制最高位1表示负数，二进制最高位0表示正数。
   unsigned 无符号，只能修饰char和int。

2）short  只能修饰 int ，表示短整型。

3）long 只能修饰int 和 double。sizeof(long double) 16字节。sizeof(long int) 4字节。

```

课堂练习

```tex
// 进制转换
#include <stdio.h>
main()
{
    int a = 65;
    printf("%d %o %x", a, a, a);
}

// 输出身体质量指数 BMI = 体重 / (身高)^2
#include <stdio.h>
main()
{
    float weight = 67.5;
    float height = 1.75;
    float BMI;
    
    BMI = weight / (height * height);
    printf("%f", BMI);
}

// 对比 float 和 double
main()
{
    float a = 3.141592654;
    double b = 3.141592654;
    
    printf("%f\n", a);
    printf("%lf\n", b);
}

// 输出字符常量 'A'
main()
{
    char c1 = 'A';
    printf("%c %d\n", c1, c1);
    
    char c2 = 65;
    printf("%c %d\n", c2, c2);
    
    putchar('\x41');
    putchar('\101');
    
}

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

##### 知识点3  常量与变量

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

##### 知识点4  运算符与表达式

- 输入直径，输出圆的面积和周长。

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

- (2018高考) 若 `int a = 12; `  执行 `a /= a + 8` 后，a的值是（        ）

 ```tex
A. 1        B. 8         C. 9        D. 0
 ```

- 已知 `i = 3;`执行  `j = ++i;`后，i和j的值分别为（        ）

```tex
A. i = 4  j = 4     B. i = 4  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

- 已知 `i = 3;`执行  `j = i++;`后，i和j的值分别为（        ）

```tex
A. i = 4  j = 4     B. i = 4  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

- 已知 `i = 3;`执行  `j = --i;`后，i和j的值分别为（        ）

```tex
A. i = 2  j = 2     B. i = 4  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

- 已知 `i = 3;`执行  `j = i--;`后，i和j的值分别为（        ）

```tex
A. i = 2  j = 2     B. i = 2  j = 3     C. i = 3 j = 3     D. i = 3  j = 2
```

- （2012高考）下面程序输出结果是（        ）

```c
#include<stdio.h>
main()
{
    int a = 3, b = 4;
    a %= b += a+= (a+b);
    printf("%d,%d",a,b);
}
```

- 下面程序输出结果是（        ）

```c
#include<stdio.h>
main()
{
    int a, b, c;
    a = (b = 3, c = b+1);
    printf("%d, %d, %d", a, b, c);
}
```

- 下面程序输出结果是（        ）

```c
#include<stdio.h>
main()
{
    int a, b, c;
    a=b=3,c=b+1;
    printf("%d, %d, %d", a, b, c);
}
```



##### 知识点5  输入输出函数

###### printf("格式串", 表达式列表)

- `%d`  十进制整数，`%o` 八进制整数，`%x` 十六进制整数

- `%c` 字符
- `%f` 浮点数，默认保留六位小数。`%m.nf` ，保留n位小数，宽度不小于m
- `%e` 科学记数法输出浮点数
- `-` 左对齐。默认右对齐。
- `%%`  输出 `%`



###### scanf("格式串", 地址列表)

- `%lf`  输入`double` 类型浮点数

```c

// 从键盘输入一个值给y，正确的函数调用是：
double y;
_____________________________________
```

- 输入的数据要与格式串一致

```c
int a, b, c;
scanf("a=%d,b=%d,c=%d", &a, &b, &c);
/* 
则正确的输入形式是：
    A. a=5 b=6 c=7
    B. 5,6,7
    C. a=5,b=6,c=7
    D. 5  6  7
*/
```

```c
// 从键盘输入一个值给x，正确的函数调用是：
float x;
____________________________________
```

```c
scanf("%2d%*3d%2d", &a, &b);
// 当键盘输入1234567后，变量a,b的值分别是_____________________
```

```c
// 从键盘输入：4  5  6<回车>，下面程序运行结果是_______________
main()
{
    int i = 0, j = 0, k = 0;
    scanf("%d%*d%d", &i, &j, &k);
    printf("i=%d,j=%d,k=%d\n", i, j, k);
}
```

- `%d %f %s` 控制输入时，不接收空白字符（空格、换行、制表符），因为空白字符被当作一个输入的结束。

 ```c
 // 从键盘输入数据12345 67890，则输出结果是____________
 main()
 {
     int x;
     flaot y;
     scanf("%3d%f", &x, &y);
     printf("x=%d,y=%f\n", x, y);
 }
 ```

- `%c` 接收每一个字符

```c
/*
    下面程序执行，按如下输入数据，CR代表换行
    12<CR>
    34<CR>
    则程序输出结果是_____________
*/
main()
{
    char a,b,c,d,e,f;
    scanf("%c%c%c", &a, &b, &c);
    d=getchar();
    e=getchar();
    f=getchar();
    printf("%c%c%c%c", a, c, d,e);
}
```

###### putchar

输出单个字符。

```c
main()
{
    putchar('A');
    putchar(65);
    putchar('\101');
    putchar('\x41');
    putchar('\n');
}
```

###### getchar

从键盘获得一个字符

```c
main()
{
    char ch;
    ch = getchar();
    putchar(ch);
}
```



##### 知识点6  整型、浮点型、字符型数据在内存中的二进制形式

- `sizeof` 计算内存大小

```c
#include <stdio.h>
main()
{
    printf("char : %d\n", sizeof(char));
    printf("short: %d\n", sizeof(short));
    printf("int: %d\n", sizeof(int));
    printf("long: %d\n", sizeof(long));
    printf("整型常量: %d\n", sizeof(10));
    
    printf("float: %d\n", sizeof(float));
    printf("double: %d\n", sizeof(double));
    printf("实数常量：%d\n", sizeof(3.14));
}
```

- 整型数据在内存中的格式

```c
/*
1）补码

83转二进制：83 = 64 + 16 + 2 + 1 = (1010011)2
[83]原码： 00000000  00000000  00000000 01010011
[-83]原码：10000000  00000000  00000000 01010011
[-83]补码：11111111  11111111  11111111 10101101

2）二进制转十六进制：我们看一个数据在内存中到底是如何存储的，通常打印对应的十六进制值，然后转二进制查看。
十进制    十六进制    二进制
15        f          1111
14        e          1110
13        d          1101
12        c          1100
11        b          1011
10        a          1010
9         9          1001
8         8          1000
7         7          0111
6         6          0110
5         5          0101
4         4          0100
3         3          0011
2         2          0010
1         1          0001
0         0          0000
*/

// 下面程序运行结果是:_______________
main()
{
    int a = 83, b = -83;
    printf("%x\n",a);
    printf("%x\n",b);
}

// 下面程序运行结果是：______________
main()
{
    char ch;
    ch = 321;
    printf("%c", ch);
}
```

- 数据范围

```c
/*
1) char 

ASCII码范围：00000000 ~ 01111111  也就是：0 ~ 127

负数范围：[11111111]补 ~ [10000000]补
     [11111111]补 =[10000001]原= -1 
     [10000001]补 =[11111111]原= -127
     [10000000]补 =[11111111] + 1 溢出  表示 -2^8 = -128
     
所以char的范围是：-128 ~ 127

2）unsigned char
00000000 ~ 11111111 也就是：0 ~ 255

3）short
正数
01111111 11111111  = 2^15 - 1 = 32767
00000000 00000000  = 0

负数
[11111111 1111111]补码 = 0xffff
[10000000 00000001]原码= -1

[10000000 00000000]补码 = 0x8000
[11111111 11111111] + 1 溢出  表示 -2^15 = -32768

unsigned short
00000000 00000000  = 0
11111111 11111111  = 2^16 - 1 = 65535


4）int

正数
01111111 11111111 11111111 11111111  = 2^31 - 1
00000000 00000000 00000000 00000000

负数
[11111111 11111111 11111111 11111111]补码
[10000000 00000000 00000000 00000001]原码 = -1

[10000000 00000000 00000000 00000000]补码
[11111111 11111111 11111111 11111111] + 1 溢出  表示 - 2^31 = -2147483648

unsigned int 
00000000 00000000 00000000 00000000 = 0
11111111 11111111 11111111 11111111 = 2^32 - 1 = 4294967295
*/

main()
{
    char c1 = -1;
    char c2 = -127;
    char c3 = -128;
    printf("%x %x %x\n", c1, c2, c3);   // ffffffff  ffffff81  ffffff80
    
    int a1 = c1 , a2 = c2, a3 = c3;
    printf("%x %x %x\n", a1, a2, a3);
}

main()
{
    int a = 0x80000000; 
    printf("%d\n",a);  // 负最小值  -2147483648
}

main()
{
    unsigned short a = 0xffff;
    printf("%u\n", a);
}
```









