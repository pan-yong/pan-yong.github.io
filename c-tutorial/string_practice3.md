## 字符串应用

1. 下面程序功能是将已按升序排好序的两个字符串a和b中的字符按升序归并到字符串c中。请填空。

```c
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
}
```

2. 下面程序功能是将字符串s中所有字符c删除。请填空。

```c
int main()
{
    char s[80];  int i, j;
    gets(s);
    for(i = j = 0; s[i]!='\0'; i++)
        if(s[i]!='c')__________;
    s[j] = '\0';
    puts(s);
}
```

3. 下面程序功能是从键盘输入一行字符，统计其中有多少个单词，单词之间用空格分隔。请填空。

```c
int main()
{
    char s[80], c1, c2; int i = 0, num = 0;
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

4. 下面程序功能是将一个数字符串转换为一个整数，如将字符串`"-1234"` 转为`-1234`。请填空。

```c
int chunum(char *p)
{   int num = 0, k, len, j;
    len = strlen(p);
    for( ; _____________; p++)
    {
        k = ________________;
        j = --len;
        while(_________)
            k = k * 10;
        num += k;
    }
    return num;
}
int main()
{   char s[6];int n;
    gets(s);
    if(*s=='-') num = -chnum(s+1);
    else n = chnum(s);
    printf("%d", n);
}

```

5. 下面程序功能是将八进制正整数字符串转为十进制整数。请填空。

```c
int main()
{   char *p, s[6];
    int n;
    p = s;gets(p);
    n = _____________;
    while(__________ != '\0')
        n = n * 8 + *p - '0';
    printf("%d", n);
}
```

6. 下面程序功能是在字符串str中找出最大的字符并放在第一个位置上，并将该字符前的原字符顺序后移，如`chyab`变成`ychab`。请填空。

```c
int main()
{   char str[80], *p, *q, max;
    gets(str); p = str;
    max = *(p++);
    while(*p != '\0')
    {
        if(max < *p ){
            max = *p;
            ______________;
        }
        p++;
    }
    p = q;
    while(_______){
        *p = *(p-1);
        ______________;
    }
    *p = max;
    puts(p);
}
```
