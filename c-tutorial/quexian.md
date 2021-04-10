## 缺陷与陷阱

1. 下面代码输出结果是（                 ）

```c
int main()
{
    int i = 3;
    printf("%d %d", ++i, i++);
}
```

- Window Dev C++：函数参数是从后往前处理，先处理i++，后处理++i，输出的时候从前往后输出 5 3。

<img src="images/image-20210408095109555.png" alt="image-20210408095109555" style="zoom:50%;" />

- Android手机运行结果：

<img src="images/image-20210408095232406.png" alt="image-20210408095232406" style="zoom:20%;" />

- C语言，把上述行为称为未定义的。不同的编译器，处理的顺序不同。

2. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
struct tt{
    int n1; 
    char n2; 
    float n3;
    union uu { 
        int u1[2]; char u2[2]; 
    } su;
};
int main()
{
    printf("%d", sizeof(struct tt));		// Windows Dev-C++ 输出结果： 20
}
```

