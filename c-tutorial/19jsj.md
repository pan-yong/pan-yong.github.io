## 19计算机1班课堂记录

##### 5月6日

###### 一、复习

输入一行字符，删除所有c字母，不区分大小写。

```c
int main()
{
    char str[80];
    int i = 0, j = 0;
    gets(str);
    while(str[i]){
        if(str[i]!='c' && str[i] != 'C')
            
    }
}
```



###### 二、结构体的定义与访问

​	P123：例7-1

```c
int main()
{
    struct data     // 定义类型
    {
        int year;
        int month;
        int day;
    };
    
    struct data today; // 定义变量
    
    // 结构体成员的访问
    scanf("%d %d %d", &today.year, &today.month, &today.day);
    printf("%d年%d月%d日", &today.year, &today.month, &today.day);
}
```

P127 ：例7-3

```c
int main()
{
    struct {
        char no[10];
        char kc[20];
        int cj;
    }cjb1 = {"20190708", "ENGLISH", 85};
    
}
```

P128 ：例7-4

```c
```

P130：例7-5

```c
```

###### 作业

课后练习题：P135 ~ P138