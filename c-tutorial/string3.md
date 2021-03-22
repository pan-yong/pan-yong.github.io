## 字符串应用

1. 下面程序功能是将已按升序排好序的两个字符串a和b中的字符按升序归并到字符串c中。请填空。

```c
#include<stdio.h>
#include<string.h>
int main()
{
    char a[]="acegikm", b[]="bdfhjlnpq", c[80], *p;
    int i = 0, j = 0, k = 0;
    while(a[i]!='\0' && b[j]!='\0')
    {
        if(a[i] < b[j]){
            c[k++] = ______________________;
        }
        else{
            c[k++] = ______________________;
        }
    }
    c[k] = '\0';
    if(_________) p = b + j;
    else p = a + i;
    strcat(c, p);
    puts(c);
    return 0;
}
```

2. 下面程序功能是将字符串s中所有字符c删除。请填空。

```c
#include<stdio.h>
int main()
{
    char s[80];
    int i, j;
    gets(s);
    for(i = j = 0; s[i]!='\0'; i++)
        if(s[i]!='c')__________;
    s[j] = '\0';
    puts(s);
    return 0;
}
```

3. 下面程序功能是从键盘输入一行字符，统计其中有多少个单词，单词之间用空格分隔。请填空。

```c
#include<stdio.h>
int main()
{
    char s[80], c1, c2;
    int i = 0, num = 0;
    gets(s);
    while(s[i]!='\0')
    {
        c1 = s[i];
        if(i==0)  c2= ' ';
        else c2 = s[i-1];
        if(____________) num++;
        i++;
    }
    printf("There are %d words.", num);
}
```

4. 