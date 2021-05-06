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
            str[j++] = str[i];
        i++;
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

###### 作业

课后练习题：P137 T2
输入年月日，输出该日期是当年的第几天。
```c
#include<stdio.h>
static int day_tab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
struct date{
    int year, month, day;
};
int day_of_year(struct date pd)
{
    int day = pd.day;
    int year = pd.year;
    int leap = year%4==0&&year%100!=0||year%400==0;
    int i;
    for(i = 0; i < pd.month; i++)
        day += day_tab[leap][i];
    return day;
}
int main()
{
    struct date pd;
    scanf("%d %d %d", &pd.year, &pd.month, &pd.day);
    printf("%d", day_of_year(pd));
    return 0;
}
```
