## 第二次联考巩固练习

1. 下列C语言的运算符中，优先级最低的是（        ）

```tex
A. >>        B. ^        C. |        D. !
```

2. 下列程序功能是从f:盘读取chengji.txt中的数据，计算每一个学生的总分，并按总分降序排序，将排序好的数据写入f:盘chengji2.txt，请填空（对学生总分排序时不考虑并列名次）。文件"chengji.txt"的内容如下：

```tex
10010	wang	88	77	66
10011	sun		56	42	33
10012	li		78	98	65
10013	zhao	92	84	64
```

```c
#include<stdio.h>
#include<stdlib.h>
#define N 4
struct student{
    char num[6];char name[10];int chinese, math, english, total, mc;
}stu[N], temp;

int main()
{
	FILE *fp;
    int i;
    if(__________________________________ == NULL ){
        printf("cannot open file");exit(0);
    }
    for(i = 0; i < N; i++)
    {
        ____________________________________________;
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }
    fclose(fp);
    
    for(i = 0; i < N-1; i++)
        for(j = 0; j < ________; j++)
            if(__________________________){
                temp = stu[j];stu[j] = stu[j+1];stu[j+1]=temp;
            }
    for(i = 0; i < N; i++) stu[i].mc = i + 1;
    
    if((fp = fopen("f:\\chengji2.txt", "w")) == NULL){
        printf("cannot open file");exit(0);
    }
    for(i = 0; i < N; i++)
        fprintf("fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].num, stu[i].name, stu[i].chinese,stu[i].math, stu[i].english, stu[i].total, stu[i].mc);
    flcose(fp);
    return 0;
}
```

3. 下面程序输出结果是（           ）

```c
#include<stdio.h>
#include<string.h>
int main()
{
    char p[15] = {'a', 'b', 'c', 'd', 'e'}, q[] = "ab", r[]="abcdef";
    strcpy(p+strlen(q), r);strcat(p,q);
    printf("%d %d",strlen(p),sizeof(p));
    return 0;
}
```

4. 下面函数isPrime是用来判断一个数是不是素数，如果是素数返回1，不是返回0。请填空。

```c
#include<stdio.h>
int isPrime(int n)
{
    int i;
    for(i = 2; i < n; i++)
    {
        if(____________) return 0;
        ________________ return 1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", isPrime(n));
    return 0;
}
```

5. 下列程序的功能是将一个十进制数n转换为一个十六进制输出。

```c
#include<stdio.h>
int main()
{
    char b[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int c[64], n, i = 0;
    scanf("%d", &n);
    do{
        c[i++] = ___________;
        n = n / 16;
    }while(n!=0);
    for(--i; i >= 0; --i)
        printf("%c",________);
    return 0;
}
```

6. 下面程序功能是删除字符串中的数字字符。

```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void f(char *s)
{
    char *p, *q;
    int i = 0;
    while(____________)
    {
        if(isdigit(s[i]))
        {
            for(_________________; *p != '\0'; p++,q++)
                *q = *p;
            _____________________;
	    }
        else i++;
    }
}
int main()
{
    char str[80];
    gets(str);
    f(str);
    puts(str);
}
```

