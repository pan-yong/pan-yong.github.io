## 预处理

1. 宏定义：`#define PI 3.141592654`

2. 文件包含：`#include<stdio.h>`

3. 条件编译：`#ifdef ` ，`#ifndef` ，`#if`

#####  练习题

- 下面程序输出结果是（        ）

```c
int main()
{   
    int b = 17;
    #define A 2
    int y = 3 + A;
    printf("%d", y);
    #undef A
    printf("%d", b);
}
```

- 下面程序`for`循环执行次数是（        ）

 ```c
 #define N 2
 #define M N+1
 #define NUM 2*M+1
 int main()
 {   int i;
     for (i = 1; i <= NUM; i++)
         printf("%d\n", i);
 }
 ```

```tex
A. 5次	B. 6次	C. 7次	D. 8次
```

- 下面程序输出结果是（        ）

```c
#define PT 5.5
#define S(x)  PT*x*x
int main()
{   int a = 1, b = 2;
    printf("%4.1f\n", S(a+b));
}
```

- （2008年高考）下列程序运行结果是（        ）

```c
#define TEXT(x,y) x+y
int main()
{   
    float c  = 2 * TEXT(3.2, 5.4) / 2;
    printf("%.1f", c);
}
```

- 下面程序输出结果是（        ）

```c
#include<stdio.h>
#define f(x)	x*x
int main()
{   
    int i = f(4+4)/f(2+2);
    printf("%d", i);
}
```

- 下面程序输出结果是（        ）

```c
#include<stdio.h>
#define f(x)  (x)*x
int main()
{   
    int i = f(4+4)/f(2+2);
    printf("%d", i);
}
```

- 下列选项中，在任何情况下计算平方数是不会引起二义性的宏定义是（        ）

```c
A. #define POWER(x)  x*x        
B. #define POWER(x)  (x)*(x)
C. #define POWER(x)  (x*x)      
D. #define POWER(x)  ((x)*(x))
```

- 下面程序输出结果是（        ）

```c
#include<stdio.h>
#define FUN(x,y)  (x)>(y)?(x):(y)
int main()
{   
    int a = 16, b = 2, t;
    t = 10 * FUN(a, b)*10;
    printf("%d", t);
}
```

- 下面运行结果是（        ）

```c
#include<stdio.h>
#define M
int main()
{   
    int a = 3, b = 5, c;
    #ifdef M
    	c = a > b ? a : b;
    #else
    	c = a > b ? b : a;
    #endif
    printf("%d", c);
}
```

- 下面运行结果是（        ）

```c
#include<stdio.h>
int main()
{   
    int a = 3, b = 5, c;
    #ifndef M
    	c = a > b ? a : b;
    #else
    	c = a > b ? b : a;
    #endif
    printf("%d", c);
}
```

- 下面运行结果是（        ）

```c
#include<stdio.h>
#define M 0
int main()
{   
    int a = 3, b = 5, c;
    #if M
    	c = a > b ? a : b;
    #else
    	c = a > b ? b : a;
    #endif
    printf("%d", c);
}
```

- 下面运行结果是（        ）

```c
#include<stdio.h>
#define M 1
int main()
{   
    int a = 3, b = 5, c;
    #if M == 1
    	c = a > b ? a : b;
    #elif M == 2
    	c = a > b ? b : a;
    #else
    	c = 8;
    #endif
    printf("%d", c);
}
```

- 下面运行结果是（        ）

```c
#include<stdio.h>
#define M 3
int main()
{   
    int a = 3, b = 5, c;
    #if M == 1
    	c = a > b ? a : b;
    #elif M == 2
    	c = a > b ? b : a;
    #else
    	c = 8;
    #endif
    printf("%d", c);
}
```

###### 小结

- 预处理：以`#`开头，是在编译前完成的，只做简单的替换，不做正确性检查。
- 三种预处理：`宏定义` ，`头文件包含` ，`条件编译` 。
- 带参数的宏与函数的区别：宏参数实在编译前处理，只是进行简单替换，并不进行计算。函数参数在调用时处理，并分配内存。宏替换，只占编译时间，并不影响运行时间。但是，函数调用是在程序运行时执行，会影响程序运行时间。

- 条件编译三种形式：

```c
#ifdef  宏标识符
	程序段1
#else
    程序段2
#endif
```

```c
#ifndef  宏标识符
	程序段1
#else
    程序段2
#endif
```

```c
#if 表达式
	程序段1
#else
    程序段2
#endif
```

*参考文档*：https://wangdoc.com/clang/preprocessor.html

<img src="images/image-20220103200053221.png" alt="image-20220103200053221" style="zoom: 15%;" />

