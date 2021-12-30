## 输出函数

```c
// 下面程序输出结果是_________
main()
{
    int x = 10;
    printf("x=%d,%o,%x, %X", x, x, x, x);
}
```

```c
// 下面程序输出结果是_________
main()
{
    float a = 12.0;
    int   b = 34;
    printf("%f, %d", a, b);
}
```

```c
// 下面程序输出结果是_________
main()
{
    int a = 25, b = 025, c = 0x25;
    char x, y;
    printf("%d %d %d\n", a, b, c);
    x = 'A' + '8' - '3';
    y =  x + '8' - '5';
    printf("%d %c\n", x, y);
}
```

```c
// 下面程序输出结果是_________
main()
{
    int x = 10, y = 65;
    printf("x=%d&&y=%c\n", x--, ++y);
}
```

```c
// 宽度, 默认右对齐，负号左对齐
// 下面程序输出结果是_____________
main()
{
    int a = 10, b = 20;
    printf("%4d%4d\n", a, b);
    printf("%-4d%-4d\n", a, b);
}
```

