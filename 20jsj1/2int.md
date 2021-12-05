## 整型

[TOC]

###### 1. 整型常量

```c
// 15  十进制整型常量
#include<stdio.h>
main()
{
    printf("%d  ", 15);
    printf("%o  ", 15);
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





