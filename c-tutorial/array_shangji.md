## 数组上机练习

###### 教材课后练习：P95

1. 从键盘输入10个整数，将这10个数逆序输出。

```c
#include<stdio.h>
int main()
{
    int a[10], i;
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for(i = 9; i >= 0; i--)
        printf("%4d", a[i]);
    return 0;
}
```

2. 计算并输出一维数组`{9.8, 12, 45, 67, 23, 19.8, 2.55, 45, 37.5}` 中的最大值、最小值和平均值。

```c
#include<stdio.h>
int main()
{
    float a[] = {9.8, 12, 45, 67, 23, 19.8, 2.55, 45, 37.5};
    int n = sizeof(a) / sizeof(float);
    int i;
    float max = a[0];	// 最大值
    float min = a[0];	// 最小值
    float sum = 0, ave;	// 总和与平均值
    
    // 1. 求最大值
    for(i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    
    // 2. 求最小值
    for(i = 1; i < n; i++)
        if(a[i] < min)
            min = a[i];
   
    // 3. 求总和与平均值
    for(i = 0; i < n; i++)
        sum += a[i];
    ave = sum / n;
    
    printf("最大值：%f	最小值：%f	平均值：%f", max, min, ave);
    return 0;
}
```

3. 从键盘输入10个整数，计算其中奇数的个数并输出。

```c
#include<stdio.h>
int main()
{
    int a[10], i, count = 0;
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < 10; i++)
        if(a[i] % 2 == 1)
            count++;
    printf("奇数个数：%d", count);
    return 0;
}
```

4. 统计10个学生成绩中，高于平均分的人数。

```c
#include<stdio.h>
int main()
{
    int scores[10], i, sum = 0;
    float ave;
    
    // 1. 输入10个学生成绩
    for(i = 0; i < 10; i++)
        scanf("%d", &score[i]);
    
    // 2. 求总分、平均分
    for(i = 0; i < 10; i++)
        sum += a[i];
    ave = sum / 10.0;
    
    // 3. 统计高于平均分的人数
    for(i = 0; i < 10; i++)
        if(a[i] > ave)
            count++;
    
    printf("高于平均分的人数：%d", count);
    return 0;
}
```

5. 输入一组数字，例如`{3, 1, 4, 7, 2, 1, 1, 2, 2}`，输出次数出现最多的数字，并显示其出现的次数。

```c
#include<stdio.h>
int main()
{
    int a[] = {3, 1, 4, 7, 2, 1, 1, 2, 2};
    int n = sizeof(a) / sizeof(int), i;
    int b[100] = {0}, max_i = 0;
    for(i = 0; i < n; i++)
        b[a[i]]++;
    for(i = 1; i < 100; i++)
        if(b[i] > b[max_i])
            max_i = i;
    printf("出现次数最多的是：%d 出现次数：%d", max_i, b[max_i]);
}
```

###### dotcpp网站习题

1. [题目 1025: [编程入门]数组插入处理](https://www.dotcpp.com/oj/problem1025.html)
2. [题目 1026: [编程入门]数字逆序输出](https://www.dotcpp.com/oj/problem1026.html)

3. [题目 1061: [二级C语言]计负均正](https://www.dotcpp.com/oj/problem1061.html)
4. [题目 2004: 统计成绩](https://www.dotcpp.com/oj/problem2004.html)
5. [题目 1053: [二级C语言]平均值计算](https://www.dotcpp.com/oj/problem1053.html)