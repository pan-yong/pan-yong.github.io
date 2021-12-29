## 选择结构程序设计单元测试

###### 一、选择题（每小题5分，共25分）

1. `C` 语言的 `if` 语句中，用作判断的条件表达式为（        ）

```tex
A. 任意表达式        B. 逻辑表达式        C. 关系表达式        D. 算术表达式
```

2. 下面程序输出结果是（        ）

```c
main()
{   int a = 2, b = -1, c = 2;
    if(a<b)
        if(b<0)
            c = 0;
    else
        c++;
    printf("%d",c);
}
A. 0        B. 1        C. 2        D. 3
```

3. 把以下四个表达式用作 `if` 语句的控制表达式时，有一个选项与其它三个选项含义不同，这个选项是（        ）

```tex
A. k%2        B. k%2==1        C. (k%2) != 0        D. !k%2 == 1
```

4. 下列程序的输出结果是（        ）

```c
main()
{   int x = 1, a = 0, b = 0;
    switch(x){
        case 0: b++;
        case 1: a++;
        case 2: a++;b++;
    }
    printf("a=%d,b=%d", a, b);
}
A. a=2,b=1        B. a=1,b=1        C. a=1,b=0        D. a=2,b=2 
```

5. 下面程序输出结果是（        ）

```c
main()
{   int a = 5, b = 4, c = 3, d = 2;
    if(a>b>c)
        printf("%d",d);
    else if((c-1>=d) == 1)
        printf("%d", d+1);
    else printf("%d", d+2);
}
A. 2         B. 3        C. 4        D. 编译时有错，无结果
```

###### 二、阅读程序，写出运行结果（每题5分，共50分）

6. 下面程序的运行结果是（            ）

```c
#include<stdio.h>
main()
{
    int x = 3, y = 0, a = 0, b = 0;
    switch(x++)
    {
        default:switch(y){
            case 0:a++;break;
            case 1:b++;break;
            }
        case 1: a++; b++; break;
        case 2: a++; b++;
    }
    printf("a=%d,b=%d",a,b);
}
```

7. 下面程序的运行结果是（            ）

```c
#include<stdio.h>
main()
{
    int a = 0, b = 1, c = 0, d = 20;
    if(a) d = d - 30;
    else if(!b)
    if(!c) d = 45;
    else d = 35;
    printf("d=%d",d);
}
```

8. 下列程序运行结果是（        ）

```c
#include<stdio.h>
main()
{
    int i = 0, j = 1, z = 2;
    if((j++||z++)&&i++) j++;
    printf("%d,%d,%d", i,j,z);
}
```

9. 下面程序运行结果是（        ）

```c
#include<stdio.h>
main()
{
    int x = 4, y = 2, z = 3;
    x += y+= z;
    printf("%d", (x<y?x++:y++));
}
```

10. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
main()
{
    int a = 2, b = 7, c = 5;
    switch(a>0)
    {
        case 1: switch(b<0){
            case 1:printf("@");break;
            case 2:printf("!");break;
        }
        case 0: switch(c==5){
            case 1:printf("*");break;
            default:printf("#");break;
        }
        default:printf("&");
    }
}
```

11. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
main()
{
    int m = 10, n = 0, p = 4, q = 20;
    if(m)
        if(n)
            q = 15 - m;
    else
        q = 25 + m;
    else if(p)
        q = q + p;
    printf("q=%d", q);
}
```

12. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
main()
{
    int a = -1, b = 0, c = 1, d = 0;
    if(++a||b--&&c++);
    d=a+b+c;
    printf("%d",d);
}
```

13. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
main()
{
    char ch1 = 'E';
    if(ch1 >= 'A')
        ch1++;
    else
        ch1 += 32;
    printf("ch1=%c", ch1);
}
```

14. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
main()
{
    char ch1 = 'a', ch2 = 'B', ch3 = 'E';
    if(ch1 > ch2)
        if(ch2 > ch3)
            ch3++;
    else --ch3;
    printf("c3=%c", ch3);
}
```

15. 输入 15.3 后的运行结果是（        ）

```c
#include<stdio.h>
main()
{
    float x , y;
    scanf("%f", &x);
    switch((int)x/10){
        case 0: y = 1.0; printf("y=%f", y); break;
        case 1: y = 2*x + 1; printf("y=%f", y); break;
        case 2: y = 3*x*x+2; printf("y=%f", y); break;
        default:printf("No definition.");
    }
}
```

###### 三、程序填空题（每空5分，共40分）

16. 某电力公司对其用户的收费规定如下。编写程序，输入用电数量，计算用户缴费额。请填空。

![image-20210922104655624](.\images\image-20210922104655624.png)

```c
#include<stdio.h>
main()
{
    float x, s;
    scanf("%f", &x);
    if(x < 0){
        printf("error"); exit(0);
    }
    else if(_______________)
        s = x * 0.5;
    else if(x < 400)
        s = 100 + (x - 200) * 0.65;
    else if(x < 600)
        s = 230 + (x-400)*0.8;
    else
        _____________________;
    printf("%f", s);
}
```

17. 输入年月日，判断这一天是这一年的第几天。

```c
#include<stdio.h>
main()
{
    int day, month, year, sum, leap;
    printf("请输入年月日，格式为：年,月,日（202,9,22）\n");
    scanf("%d,%d,%d", &year, &month, &day);
    switch(month)  // 先计算某月以前月份的总天数
    {
        case 1:sum=0;break;
        case 2:__________________; break;
        case 3:sum=59;break;
        case 4:sum=90;break;
        case 5:sum=120:break;
        case 6:sum=151;break;
        case 7:sum=181;break;
        case 8:sum=212;break;
        case 9:sum=243;break;
        case 10:sum=273;break;
        case 11:sum=304;break;
        case 12:sum=334;break;
        default:printf("data error.");break;
    }
    sum = sum + day;
    if(___________________________________) // 判断是不是闰年
        leap = 1;
    else leap = 0;
    if(leap == 1 && month > 2) // 如果是闰年且月份大于2，总天数应该加一天
        sum++;
    printf("这是这一年的第%d天", sum);
}
```

18. 输入三角形三边a、b、c，判断a、b、c能否构成三角形。如果能够构成三角形，则判断为何种类型的三角形（一般三角形、等腰三角形、等边三角形、直角三角形、等腰直角三角形）。

```c
#include<stdio.h>
main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if(____________________________)
        printf("不能构成三角形");
    else if(____________________________)
    if((a==b) || (b==c) || (c==a))
            printf("等腰直角三角形");
    else
            printf("直角三角形");
    else if(____________________________)
        printf("等边三角形");
    else if(____________________________)
        printf("等腰三角形");
    else 
        printf("一般三角形");
}
```

###### 四、程序改错题。（每空5分，共20分）

19. 设平面上一点M，其坐标为(x,y)，若M点在圆心为坐标原点(0,0)的单位圆（半径为1）上，则置key=1；落在圆外，则置key=2；落在圆内，则置key=0。下面程序由两处错误，请指出所在行，并改正。一下只允许修改两行。

```c
L1    #include<stdio.h>
L2    #include<math.h>
L3    main()
L4    {   float x, y, m;
L5        int key;
L6        scanf("%f,%f", x, y);
L7        m = sqrt(x*x+y*y);
L8        if(m!=1)
L9            key = 1;
L10       else if(m > 1)
L11           key = 2;
L12       else key = 0;
L13       printf("%d", key);
L14   }

________ 行修改为_________________________________

________ 行修改为_________________________________
```

20. 下面程序是根据用户输入三角形三边，判定和何种三角形，对于能构成三角形的，根据如下海伦公式计算面积，其中p是半周长（ p = (a+b+c)/2 ）， S是面积。下面程序汇总由两处错误，请指出所在行，并改正。

$$
S = \sqrt{(p(p-a)(p-b)(p-c))}
$$

```c
L1    #include<stdio.h>
L2    #include<math.h>
L3    main()
L4    {   float a, b, c;
L5        float p, s;
L6        printf("请输入三边的边长");
L7        scanf("%f,%f,%f", &a, &b, &c);
L8        if(a+b<c||b+c<a||a+c<b){
L9            p = (a+b+c)/2;
L10           s = sqrt(p*(p-a)*(p-b)*(p-c));
L11           printf("面积为：%f", s);
L12           if(a==b||b==c) 
L13               printf("等边三角形");
L14           else if(a==b||b==c||c==a)
L15               printf("等腰三角形");
L16           else if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
L17               printf("直角三角形");
L18           else
L19               printf("一般三角形");
L20       }
L21       else printf("不能构成三角形");
L22   }

________ 行修改为_________________________________
    
________ 行修改为_________________________________
```

