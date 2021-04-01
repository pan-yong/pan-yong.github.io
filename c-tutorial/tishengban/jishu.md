## 级数专题

*2021.4.1*

###### 2020年高考

1. 下列给定程序中函数f的功能是：根据形参(x,n)，计算如下公式的值。例如，若x=2，n=10;则输出为：sin(2)=0.909347。以下程序只允许修改三行。

$$
sinx = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \frac{x^9}{9!} + ...
$$

```c
#include<stdio.h>
double f(int x, int n)
{
    int i, j;
    double t, xt;
    int sign;
    double s = 0;
    for(i = 1; i < n; i += 2){
        t = 1; xt = 1;
        for(j = 1; j <= i; j++){
            t = t *j;
            xt = xt * xt;
        }
        s += xt / t;
        sign = - sign;
    }
}
```



###### 2018年高考

1. 下列程序中，函数fun的功能是；根据形参m，计算如下公式的值。以下程序只允许修改三行。

$$
y = 1 + \frac{1}{2*2} + \frac{1}{3*3} + \frac{1}{4*4} + ... + \frac{1}{m*m}
$$

```c
#include<stdio.h>
void fun(int m)
{
    double y = 1.0;
    int i;
    for(i = 2; i < m; i++)
        y += I/(I+I);
    return (y);
}
int main()
{
    int n = 5;
    printf("The result is %lf", fun(n));
    return 0;
}
```



###### ncre02

1. 下面程序功能是计算如下公式的值。例如，若m=2000，则输出0.000160。修改程序中的两处错误。
   $$
   y = \frac{1}{100*100} + \frac{1}{200*200} + ...+\frac{1}{m*m}
   $$

```c
#include<stdio.h>
fun(int m)
{
    double y = 0, d;
    int i;
    for(i = 100, i <= m, i+= 100){
		d = (double)i * (double)*;
         y += 1.0 / d;
    }
    return y;
}
int main()
{
    int n = 2000;
    printf("The result is %lf", fun(n));
    return 0;
}
```

```tex
________ 行改为__________________________________

________ 行改为__________________________________
```

###### ncre03

2. 下面程序fun函数的功能是计算如下公式An的值。若n=10，则输出0.617977。修改程序中的两处错误。

$$
A1 = 1，A2 = \frac{1}{1+A_1}，A3 = \frac{1}{1+A_2}，...，An = \frac{1}{1+A_{n-1}}
$$

```c
#include<stdio.h>
int fun(int n)
{
    float A = 1; int i;
    for(i = 2; i < n; i++)
        A = 1.0 / (1+A);
    return A;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%f", fun(n));
}
```

###### ncre10

3. 下面程序功能是计算如下公式的值。例如，输入5，输出-0.283333。修改程序中的两处错误。

$$
t = \frac{1}{2} - \frac{1}{3} - \frac{1}{4} - ... - \frac{1}{m}
$$

```c
#include<stdio.h>
double fun(int m)
{
    double t;
    int i;
    for(i = 2; i <= m; i++)
        t = 1.0 - 1/i;
    return t;
}
int main()
{
    int m;
    scanf("%d", &m);
    printf("%f", fun(m));
}
```

###### ncre18

4. 下面程序功能是计算如下数列的前n项之和。例如，输入5，输出8.391667。修改程序中的两处错误。

$$
\frac{2}{1}+\frac{3}{2}+\frac{5}{3}+\frac{8}{5}+\frac{13}{8}...
$$

```c
#include<stdio.h>
fun(int n)
{
    int a = 2, b = 1, c, k;
    double s = 0;
    for(k = 1; k <= n; k++)
    {
        s = s + a/b;
        c = a; a = a + b; b = c;
    }
    return s;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%f", fun(n));
}
```

###### ncre20

5. 下面程序函数fun的功能是求公式p的值，m与n为正整数且m>n。例如m=12,n=8时，运行结果为495.000000。修改程序中的两处错误。

$$
p = \frac{m!}{n!(m-n)!} , m!= 1*2*3...*m
$$

```c
float fun(int m, int n)
{
    int a = 1, b = 1, c = 1, i;
    for(i = 1; i <= n; i++)
    {
        a *= i;
        if(i <= n)
            b *= i;
        if(i <= m - n)
            c *= i;
    }
    return a/(b*c);
}
int main()
{
    printf("%f", fun(12,8));
}
```

###### ncre22

6. 下面程序函数fun的功能是求公式S的值，例如k=10时，函数返回值为1.533852。修改程序中的两处错误。

$$
S = \frac{2^2}{1*3}*\frac{4^2}{3*5}*\frac{6^2}{5*7}*...*\frac{(2k)^2}{(2k-1)*(2k+1)}
$$

```c
#include<stdio.h>
float fun(int k)
{
    int n = 1; 
    float s = 1, w, p, q;
    while(n <= k)
    {
        w = 2*n;
        p = w - 1;
        q = w + 1;
        s *= w*w/p*q;
    }
    return s;
}
int main()
{
    printf("%f", fun(10));
}
```

