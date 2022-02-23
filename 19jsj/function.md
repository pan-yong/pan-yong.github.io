## 函数的定义

函数定义的形式为：

```tex
类型说明符  函数名 (形参列表)
{
    函数体;
}
```

```c
void display()
{
    printf("hello, world.\n");
}
int main()
{
    display();
    return 0;
}
```

（1）函数名

只能由字母、数字、下划线组成，且首字母不能是数字。函数名的取名要尽量反应函数的功能作用，让人易读易理解。

（2）函数体

函数的执行流程，从主函数开始，从上往下一行一行执行，到主函数尾结束。调用函数时，程序跳转到被调函数的开头，然后一行一行往下，执行到函数尾，而后返回到主调函数，接着往下执行。

```c
void f(int x){
    printf("%d", x*x);
}
void display(){
    f(6);
    printf("this is display function.\n");
}
int main(){
    display();
    return 0;
}
```

（3）函数形参

```c
void display(float a[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%.0f ", a[i]);
}
int main(){
    float a[10] = {1,3,5,7,9,2,4,6,8,0};
    display(a, 10);
}
```

（4）函数返回值

```c
int add(int x, int y){
    return x+y;
}
int max(int x, int y){
    return x > y ? x : y;
}
int min(int x, int y){
    return x < y ? x : y;
}
int sum(int n){
    int s = 0, i;
    for (i = 1; i <= n; i++)
        s += i;
    return s;
}
```

（5）函数的申明

变量要先声明再使用，函数也一样，也要先申明再使用。

```tex
类型说明符  函数名(形参);
```

例如：

```c
int max(int x, int y);
void display(float a[], int n);
```

在函数的申明中，参数名称并不重要，只有参数类型是必需的，因此也可以这样写：

```c
int max(int, int);
void display(float [], int);
```



## 函数的应用

（1） 写一个函数，函数名为factorial，函数传入一个整数n，函数返回n!

（2）写一个函数，函数名为isPrime，函数传入一个整数n，是素数返回1，不是素数返回0

（3）写一个函数，函数名为is_ps，用来判断一个数是不是平方数。

（4）写一个函数，函数名为is_pal，用来判断一个数是不是回文数。

（5）写一个函数，返回一维数组中最大值。

（6）输入七条边，计算如图五边形的面积。

<img src="C:\Users\py\AppData\Roaming\Typora\typora-user-images\image-20220220081758177.png" alt="image-20220220081758177" style="zoom:50%;" />

（7）更多练习：教材P120编程题。



## 2021年高考题

（30）计算圆的面积s，请补全下列代码。

```c
#include<stdio.h>

_______(1)________  3.14
    
_______(2)________

int main(void)
{
    float r = 2.5; //圆的半径
    float area = 0.0; //圆的面积
    area = _______(3)________  //获得圆的面积
    printf("area=%f\n", ______(4)______); //输出圆的面积
    return 0;
}
float ComputeArea(float r)
{
    return (PI*r*r);
}
```



## 级数专题练习

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
    return s;
}
```

```tex
_____行有错，改为____________________________
_____行有错，改为____________________________
_____行有错，改为____________________________
```

###### 2018年高考

2. 下列程序中，函数fun的功能是；根据形参m，计算如下公式的值。以下程序只允许修改三行。

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

```tex
_____行有错，改为____________________________
_____行有错，改为____________________________
_____行有错，改为____________________________
```

###### 2020第二次联考

3. 下面程序的功能是输入整数x和eps，求下面多项式公式的和，直到最后一项小于eps。以下程序只允许修改两行。

$$
S = 1 - x + \frac{x^2}{2!} - \frac{x^3}{3!} +...
$$

```c
#include<stdio.h>
#include<math.h>
int main()
{
    float x , eps, s = 1, t = 1, i = 1;
    scanf("%f%f", &x, &eps);
    do
    {   t = -t * x / ++i;
        s += t;
    }while(fabs(t) < eps);
    printf("%f", s);
}
```

```tex
_____行有错，改为____________________________
_____行有错，改为____________________________
```

