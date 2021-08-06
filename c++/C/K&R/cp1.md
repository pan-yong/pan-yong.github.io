## 第一章  导言

[TOC]

第一章的优点，使读者尽快地编写出有用的程序，仅凭这一点，就远超其他C语言书。作为教师，在教学中就非常值得借鉴和参考。以下阅读笔记，是感受作者写书的逻辑，从中学习备课，学会如何教。

##### 1.1 入门

```c
#incluce <stdio.h>
main()
{
    printf("hello, world\n");
}
// 这段程序的详细解释说明，见教材P2～P3。
```

###### 练习 1-1 运行 `hello, world` 程序，再有意去掉程序中的部分内容，看看会得到什么出错信息。

```tex
// 找错
#incluce <stdio.h>
mian()
{
    printf("hello, world\n");
}
```

```c
#incluce <stdio.h>
main()
{
    printf("hello, world\n")
}
```

```c
#incluce <stdio.h>
main()
{
    printf("hello, world\n');
}
```

###### 练习 1-2  printf 输出转义字符

```tex
#incluce <stdio.h>
main()
{
    printf("\n");
    printf("\t");
    pirntf("\y");
}
```

##### 1.2 变量与算术表达式

```c
// 打印华氏温度与摄氏温度对照表  C = (5/9)(F-32)
// 当fahr = 0, 20, 40, ..., 300时，分别打印华氏温度与摄氏温度对照表
#include <stdio.h>
main()
{
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    while (fahr <= upper){
        celsius = 5 * (fahr - 32) / 9; // 注意 5/9 值为0
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
/* 这段程序设计知识点：
1. 类型
2. 变量定义
3. 分号，一条语句的结束
4. 赋值运算符
5. while语句
6. 算术运算符 + - * /
7. 语句块
8. printf语句  %d  %3d   %f  %3.1f  %O %f %c 
*/

```

###### 练习 1-3 修改温度转换程序，在转换表顶部打印一个标题

```c
printf("Fahr  Celsius\n");
```

###### 练习 1-4 打印摄氏温度转为华氏温度的转换表

```c
#include <stdio.h>

main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
 
    printf("Celsius  Fahr\n");
    celsius = lower;
    while(celsius <= upper){
        fahr = 9 * celsius / 5 + 32;
        printf("%3.0f  %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
```

##### 1.3 `for` 语句

```c
#include <stdio.h>

main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f", fahr, (5.0/9.0)*(fahr - 32));
}
```

##### 1.4 符号常量

```c
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

main()
{
    int fahr;
    
    for(fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%3d %6.1f", fahr, (5.0/9.0)*(fahr - 32));
}
```

##### 1.5 字符输入输出

###### 1.5.1 文件复制

```c
#include <stdio.h>

main()
{
    char c;
    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}
```

```c
#include <stdio.h>

main()
{
    char c;
    while ( (c = getchar() ) != EOF){
        putchar(c);
    }
}
// 对比
// c = getchar() != EOF
```

###### 1.5.2 字符计数

```c
#include <stdio.h>

main()
{
    long nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
```

```c
#include <stdio.h>

main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```

###### 1.5.3 行计数

```c
#include <stdio.h>
main()
{
    char c;
    int nl = 0;
    
    while ((c = getchar()) != EOF)
        if(c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

###### 练习1-8 统计空格、制表符与换行符个数

```c
#include <stdio.h>
main()
{
    char c;
    int nb = 0; // numbers of blanks
    int nt = 0; // numbers of tabs
    int nl = 0; // numbers of newlines
    while ((c = getchar()) != EOF){
        if(c == ' ')
            ++nb;
        if(c == '\t')
            ++nt;
        if(c == '\n')
            ++nl;
    }
    printf("%d %d %d", nb, nt, nl);
}
```

###### 练习1-9 将输入复制输出，连续的多个空格用一个空格代替

```c
#include <stdio.h>
#define NONBLANK 'a'
main()
{
    char c, pre = NONBLANK;
    while((c = getchar()) != EOF)
    {
        if(c != ' ' || c == ' ' && pre != ' ')
            putchar(c);
        pre = c;
    }
        
}
```

###### 1.5.4 单词计数

```c
#include <stdio.h>
#define OUT 0
#define IN  1

main()
{
    char c;
    int nw = 0, state = OUT;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if(stats == OUT){
            ++nw;
            state = IN;
        }
    }
    printf("%d\n", nw);
}
```

###### 练习1-11 如何测试单词计数程序？如果存在某种错误，什么样的输入最可能发现这类错误？

###### 练习1-12 编写程序，每行一个单词输出

```c
#include <stdio.h>
#define OUT 0
#define IN  1

main()
{
    char c;
    int nw = 0, state = OUT;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == IN)
                putchar('\n');
            state = OUT;
        }   
        else if(stats == OUT){
            putchar(c);
            state = IN;
        }
        else
            putchar(c);
    }
}
```

##### 1.6 数组

写一个程序，统计各个数字、空白字符（空格、制表符、换行）及其他字符出现次数。

```c
#include <stdio.h>

main()
{
    char c;
    int ndigit[10] = {0}, nwhite = 0, nother = 0;
    
    while ((c=getchar()) != EOF)
    {
        if(c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if(c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }
    printf("dights =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d", nwhite, nother);
}
```

###### 练习1-13 打印输入单词的长度直方图。水平直方图比较容易，垂直方向直方图困难一些。

```c
// print horizontal histogram
#include <stdio.h>

#define MAXSHIT	15
#define MAXWORD 11
#define IN  1
#define OUT 0

main()
{
    int c, i, nc, state;
    int len; 			// length of each bar
    int maxvalue; 		//max value for wl[]
    int ovflow;   		// number of overfow words
    int wl[MAXWORD]; 	// word length counters
    
    state = OUT;
    nc = 0;
    ovflow = 0;
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if(nc > 0)
                if(nc < MAXWORD)
                    ++wl[nc];
            	else
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT) {
            state = IN;
            nc = 1;
        }
        else
            ++nc;
    }
    
    maxvlaue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];
    
    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = wl[i] * MAXSHIT / maxvalue) <= 0)
                len = 1;
        }
        else
            len = 0;
        while (len > 0){
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    
    if (ovflow > 0)
        printf("There are %d word >= %d\n", ovflow, MAXWORD);
}
```

