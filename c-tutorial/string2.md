## 字符串函数

- strlen
- strcpy
- strcat
- strcmp

1. 下面程序运行结果是（            ）

```c
#include<stdio.h>
int main()
{
    char *p = "\ta\017bc";
    char *q = "\ta\018bc";
    char *r = "\ta\08abc";
    char *s = "abcde" + 2;
    printf("%d %d %d %d", strlen(p), strlen(q), strlen(r),strlen(s));
    return 0;
}
```

2. 下面程序段运行结果是（                       ）

```c
char a[] = "language", *p = a;
while(*p != 'u'){
	printf("%c", *p - 32);
    p++;
}
```

2. 下面程序段运行结果是（                  ）

```c
char p1[] = "abcdefgh", *p = p1;
p += 3;
printf("%d", strlen(strcpy(p, "ABCD")));
```

3. 