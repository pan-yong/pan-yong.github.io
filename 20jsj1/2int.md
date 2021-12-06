## 整型

例1：计算箱子的空间重量。运输公司对于占据了卡车或飞机的宝贵空间的又大又轻的箱子，通常按照体积而不是重量来计费，具体公式是：空间重量 = 体积 / 194。如果空间重量大于实际重量，那么运费按照空间重量来计费。下面程序功能是计算一个箱子的空间重量。

```c
#include<stdio.h>
int main()
{
    int height, length, width, volume, weight;
    height = 8;
    length = 12;
    width = 10;
    volume = length * width * height;
    weight = (volume + 193) / 194;
    printf("%d", weight);
    return 0;
}
```

```tex
说明：
int height, length, width, volume, weight;  定义变量：高、长、宽、体积、空间重量。
height = 8;  length = 12;  width = 10; 给长宽高变量赋值。变量就像一个盒子，用来存储数据。变量必须先定义再使用。
```



例2：输入一个华氏温度，输出对应摄氏温度，转换公式： C = 5/9 (F - 32)。

```c
#include<stdio.h>
int main()
{
    int F, C;
    scanf("%d", &F);
    C = 5*(F - 32)/9;
    printf("%d",C);
    return 0;
}
```

```tex
说明：
int F, C;  定义两个整型变量。变量就像一个盒子，用来存储数据。变量必须先定义再使用。
scanf("%d", &F); 输入函数，%d表示输入一个十进制整数，&F表示变量F的内存地址，也就是输入的整数放到内存&F位置。
C = 5*(F-32)/9;  右边表达式运算结果赋值给C变量。注意不能写成5/9，其值为0，因为C语言中整数/整数结果还是整数。
printf("%d", C); 输出函数，%d表示输出一个十进制整数，对应输出内容为C变量的值
```



###### 1. 整型常量

```c
// 15  十进制整型常量
#include<stdio.h>
main()
{
    printf("%d\n", 15);
    printf("%o\n", 15);
    printf("%x\n", 15);
}

/* 格式控制符      
%d  十进制整数输出    
%o  八进制整数输出    
%x  十六进制整数输出 
*/
```

```c
// 015  八进制整型常量   
#include<stdio.h>
main()
{
    printf("%d %o %x\n", 015, 015, 015);
}
```

```c
//0x15  十六进制整型常量
```



###### 2. 课堂作业

```tex

75转十六进制________，转八进制__________

0x75转八进制________，转十进制__________

075转十进制_________，转十六进制________

```

```c
#include<stdio.h>
main()
{
    int a = 75;
    printf("%x %o\n", a, a);
    
    int b = 0x75;
    printf("%#o %d\n", b, b);
    
    int c = 075;
    printf("%d %#x\n", c, c);
}
```



###### 3. 上机作业

```c
// 下面程序输出结果是_________
#include<stdio.h>
main()
{
    int u = 010, v = 0x10, w = 10;
    printf("%d %d %d", u, v, w);
}
```

```c
// 下面程序输出结果是_________
#include<stdio.h>
main()
{
    int k = 15;
    printf("%d,%o,%x", k, k, k);
}
```

```c
// 找出错误并修改：________________
#include<stdio.h>
main
{
    int a;
    a = 5;
    printf("%d\n", a%2);
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
    printf("%d", a/b);
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

###### 4. 课堂小结

- 整型类型标识符： `int` 
- 整型常量的书写：十进制（65）、八进制（0101）、十六进制（0x41）
- 输出控制符： `%d`  `%o`  `%x`
- 变量
  - 必须先定义再使用
  - 变量名：只能由字母、数字、下划线组成，且第一个字符只能是字母或下划线。





