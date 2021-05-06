## 字符数组与字符串

> 字符串：是以'\0'结束的字符数组。字符串常量：双引号括起来的一串字符，末尾自动带\0。

1. 下面对字符数组s初始化，错误的语句是（        ）

```c
A. char s[5]={"abc"};	  B. char s[5]={'a','b','c'};		
C. char s[5]="abcd";	  D. char s[5]="abcde";
```

2. 下面程序输出结果是（        ）

```c
int main()
{   char s[] = "perfect", b[9] = "perfect"
    printf("%d %d %d", strlen(s), sizeof(s),sizeof(b));	
}
```

3. 下面程序段的运行结果是（        ）

```c
char c[5] = {'a','b','\0','c','\0'};
printf("%s", c);
	A. 'a' 'b'        B. ab        C. ab c 
```

4. 有两个字符数组a[80]和b[80]，则正确的输出形式（        ）

```c
A. puts(a,b);		B. printf("%s,%s",a[],b[]);		C. putchar(a,b);		D. puts(a), puts(b);
```

5. 有两个字符数组a[80]和b[80]，则正确的输入形式是（        ）

```c
A. gets(a,b);		B. scanf("%s%s",a,b);	C. scanf("%s%s",&a,&b);		D.gets("a"),gets("b");
```

6. 下面程序运行结果是（        ）

```c
char a[3], b[] = "China";
a = b;  printf("%s", a);
A. 运行后将输出China		B. 运行后将输出Ch		C. 运行后将输出Chi	D. 编译出错
```

7. 下面程序功能是输出两个字符串中对应相等的字符，请填空。

```c
char x[] = "programming", y[] = "Fortran";
int i = 0;
while(x[i]!='\0' && y[i] != '\0')
    if(x[i]==y[i]) printf("%c",__________);
    else i++;
```

8. 下面程序段的运行结果是（            ）

```c
char c[] = "\t\v\\\0will\n", d[] = "ab\n\\012\\\"" ;
printf("%d %d",strlen(c), strlen(d));
```

9. 下面程序运行结果是（        ）

```c
int main()
{   char a[] = "morming", t;
    int i, j = 0;
    for(i = 1; i < 7; i++)
        if(a[j] < a[i]) j = i;
    t = a[j];a[j] = a[7];a[7]=t;
    printf("%s", a);
    return 0;
}
```

10. 下面程序运行结果是（            ）

```c
int main()
{   char a1[5], a2[5], a3[5], a4[5];
    scanf("%s%s", a1, a2);
    gets(a3);gets(a4);
    puts(a1);puts(a2);
    puts(a3);puts(a4);
    return 0;
}
输入数据为：
    aa bb<回车>
    cc dd<回车>
则程序运行结果是____________
    A.aa         B. aa        C. aa	     D. aa bb
      bb            bb           bb         cc
                    cc           cc dd      dd
      cc dd         dd           ee
```

11. 下面程序输出结果是（        ）

```c
#include<stdio.h>
#define N 6
int main()
{
    char c[N];
    int i = 0;
    for(; i < N; c[i]=getchar(), i++);
    for(i = 0;i < N; i++) putchar(c[i]);
    return 0;
}
从键盘输入: ab<回车>
            c<回车>
            def<回车>
则程序运行结果是______________
    A. abcdef        B. a          C. b            D. ab
                        b             c               c
                        c             d               d
                        d
                        e
                        f
```

12. 当运行一些程序时，从键盘输入`AhaMA Aha<回车>` ，则下面程序的运行结果是（                                  ）

```c
#include<stdio.h>
int main()
{
    char s[80], c = 'a';
    int i = 0;
    scanf("%s", s);
    while(s[i]!='\0')
    {
        if(s[i]==c) s[i] -= 32;
        else if(s[i]==c-32) s[i] +=32;
        i++;
    }
    printf("%s", s);
    return 0;
}
```

13. 下面程序运行结果是（               ）

```c
#include<stdio.h>
int main()
{
    char str[]="SSSWLIA",c;
    int k;
    for(k = 2; (c=str[k])!='\0'; k++)
    {
        switch(c){
            case 'I': ++k;break;
            case 'L': continue;
            default: putchar(c); continue;
        }
        putchar('*');
    }
    return 0;
}
```

14. 下面程序运行结果是（        ）

```c
#include<stdio.h>
int main()
{
    int x = 117, i = 0;
    char a[5];
    do{
        switch(x%16){
            case 10: a[i] = 'A'; break;
            case 11: a[i] = 'B'; break;
            case 12: a[i] = 'C'; break;
            case 13: a[i] = 'D'; break;
            case 14: a[i] = 'E'; break;
            case 15: a[i] = 'F'; break;
            default: a[i] = '0' + x%16; break;
        }
        i++;  x = x / 16;
    }while(x != 0);
    for(x = i - 1; x >= 0; x--)
        printf("%c", a[x]);
    return 0;
}
```

15. 下面程序功能是在一个字符数组中查找一个指定的字符，若数组中含有该字符，则输出该字符在数组中第一次出现的位置（下标值），否则输出-1。请填空。

```c
#include<stdio.h>
#include<string.h>
int find(char a[], char ch)
{
    int n, i;
    n = _________________;
    for(i = 0; i < n; i++)
        if(_____________){
			return i;
        }
    return -1;
}
int main()
{
    char c = 'a', t[50];
    gets(t);
    printf("%d", find(t,c));
    return 0;
}
```

16. 下面程序功能是从键盘输入一个大写英文字母，按顺序输出3个相邻的字母，输入的字母在中间。例如，若输入Z则，输出YZA；若输入A，则输出ZAB；若输入B，则输出ABC。请填空。

```c
#include<stdio.h>
int main()
{
    char a[3], c;
    int i;
    c = getchar();
    a[1] = c;
    if(c == 'Z'){
        ______________;
        a[2] = 'A';
    }
    else if(c == 'A'){
        a[0] = 'Z';
        ________________;
    }
    else{
        a[0] = c - 1;
        a[2] = c + 1;
    }
    for(i = 0; i < 3; i++)
        putchar(a[i]);
    return 0;
}
```

