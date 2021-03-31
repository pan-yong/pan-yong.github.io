## 字符串库函数的使用

1. 以下能正确定义字符串
2. 下面程序运行结果是（            ）

```c
int main()
{
    char *p = "\ta\017bc";
    char *q = "\ta\018bc";
    char *r = "\ta\08abc";
    char *s = "abcde" + 2;
    printf("%d %d %d %d", strlen(p), strlen(q), strlen(r),strlen(s));
}
```

2. 下面程序段运行结果是（                  ）

```c
int main()
{
    char p1[] = "abcdefgh", *p = p1;
    p += 3;
    printf("%d", strlen(strcpy(p, "ABCD")));
}
```

3. 