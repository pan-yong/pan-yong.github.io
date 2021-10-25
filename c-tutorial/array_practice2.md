## 一维数组的简单应用

1. 从键盘输入10个整数，将这10个数逆序输出。

```c
int main()
{
    int a[10], i;
    for(i = 0; i < 10; i++)
        scanf("%d", __________);
    for(________; i >= 0; ________)
        printf("%4d", a[i]);
    return 0;
}
```

2. 下面程序输出结果是（           ）

```c
int main()
{  
    int a[] = {8,5,4,3,2}, i, j, t;
    for(i = 0, j = 4; i < j; i++, j--){
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    for(i = 0; i < 5; i++)
        printf("%d", a[i]);
}
```

3. 下面程序运行结果是（        ）

```c
int main()
{
    int a[] = {1,2,3,4}, i, j = 1, s = 0;
    for(i = 3; i >= 0; i--)
    {
        s += a[i] * j;
        j = j * 10;
    }
    printf("s=%d",s);
}
```

4. 下面程序输出结果是（                  ）

```c
int main()
{   
    int a[20], i , m = 10, k = 8;
    for(i = 0; m > 0; i++){
        a[i] = m % k;
    }
    for(i--; i >= 0; i--)
        printf("%d", a[i]);
}
```

5. 下面程序输出结果是（         ）

```c
int main()
{
    int n = 132, i = 1, j, k , b[10];
    while( n!= 0)
    {
        j = n % 6;
        b[i] = j;
        n = n / 6;
        i = i + 1;
    }
    for(k = i - 1; k > 0; k--)
        printf("%d", b[k]);
    return 0;
}
```

6. 计算并输出一维数组`{9.8, 12, 45, 67, 23, 19.8, 2.55, 45, 37.5}` 中的最大值、最小值和平均值。

```c
int main()
{
    __________________________________;
    int i;
    float max = a[0];	// 最大值
    float min = a[0];	// 最小值
    float sum = 0, ave;	// 总和与平均值
    int n = sizeof(a) / sizeof(float);  // 数组元素个数
    
    // 1. 求最大值
    for(i = 1; i < n; i++)
        if(_____________)
            max = a[i];
    // 2. 求最小值
    for(i = 1; i < n; i++)
        if(a[i] < min)
            _____________;
    // 3. 求总和与平均值
    for(i = 0; i < n; i++)
        sum += a[i];
    ave = ________________;
    printf("最大值：%f	最小值：%f	平均值：%f", max, min, ave);
    return 0;
}
```

7. 从键盘输入10个整数，计算其中奇数的个数并输出。

```c
int main()
{
    int a[10], i, count = 0;
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < 10; i++)
        if(_______________)
            count++;
    printf("奇数个数：%d", count);
    return 0;
}
```

8. 统计10个学生成绩中，高于平均分的人数。

```c
int main()
{
    int i, sum = 0;
    _________________;
    float ave;
    // 1. 输入10个学生成绩
    for(i = 0; i < 10; i++)
        scanf("%d", &score[i]);
    // 2. 求总分、平均分
    for(i = 0; i < 10; i++)
        sum += score[i];
    ave = sum / 10.0;
    // 3. 统计高于平均分的人数
    for(i = 0; i < 10; i++)
        if(_______________)
            count++;
    printf("高于平均分的人数：%d", count);
    return 0;
}
```

9. 输出Fibonacci序列的前10个数。1，1，2，3，5，8......

```c
int main()
{   int i, a[10] = {1,1};
    for(i = 2; i < 10; i++)
        a[i] = _________________;	
    for(i = 0; i < 10; i++)
        printf("%4d", a[i]);
    return 0;
}
```

10. 统计数组中每个数字的个数

```c
int main()
{   int s[12]={1,2,3,4,4,3,2,1,1,1,2,3}, i;
    int c[5] = {0};						// c[i]表示数字i出现的次数。
    for(i = 0; i < 12; i++)
        ________________ ;						
    for(i = 1; i<5; i++)
        printf("数字%d 出现的次数是：%d次",i, c[i]);
    return 0;
}
```

11. 输入一个整数，转二进制输出

```c
#define N 32
int main()
{   int n, i = 0, b[N];
    scanf("%d", &n);
    do{
        ____________;	
        n = n / 2;
    }while(n);
    for(; i > 0; i--)
        printf("%d",______);	
}
```

12. 输入一组数字，例如`{3, 1, 4, 7, 2, 1, 1, 2, 2}`，输出次数出现最多的数字，并显示其出现的次数。

```c
int main()
{
    int a[] = {3, 1, 4, 7, 2, 1, 1, 2, 2};
    int n = sizeof(a) / sizeof(int), i;
    int b[100] = {0};	// b[i] 存放的是数字 i出现的次数。
    int max_i = 0;
    for(i = 0; i < n; i++)
        _____________;			
    for(i = 1; i < 100; i++)
        if(b[i] > b[max_i])		// 找b数组中最大值，对应的下标
            max_i = i;
    printf("出现次数最多的是：%d 出现次数：%d", max_i, b[max_i]);
}
```

13. 下面程序的功能是：把两个已按升序排列的整型数组合并成一个升序数组。请填空。

```c
int main()
{
    int a[3] = {5,9,19}, b[5] = {12,24,26,37,48}, c[10], i = 0, j = 0, k = 0;
    while(i < 3 && j < 5)
        if(_____________)
        {
            c[k] = b[j];k++;j++;
	    }
    	else
        {
            c[k] = a[i];k++;i++;
        }
    while(_____________)
    {
        c[k] = a[i]; k++;i++;
    }
    while(_____________)
    {
        c[k] = b[j]; k++;j++;
    }
    for(i = 0; i < k; i++)
        printf("%3d", c[i]);
    return 0;
}
```



###### 上机练习题

1. [题目 1025: [编程入门]数组插入处理](https://www.dotcpp.com/oj/problem1025.html)
2. [题目 1026: [编程入门]数字逆序输出](https://www.dotcpp.com/oj/problem1026.html)

3. [题目 1061: [二级C语言]计负均正](https://www.dotcpp.com/oj/problem1061.html)
4. [题目 2004: 统计成绩](https://www.dotcpp.com/oj/problem2004.html)
5. [题目 1053: [二级C语言]平均值计算](https://www.dotcpp.com/oj/problem1053.html)