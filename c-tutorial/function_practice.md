## 函数练习

1. 下面程序输出结果是（               ）

```c
int add(int a, int b){
    return a+b;
}
int main()
{
    int x = 3, y = 4;
    printf("%d", add(x,y));
}
```

2. 下面函数功能是返回1~n的和，请填空。

```c
______ sum(int n)
{
    int i, s;
    s = ______;
    for(i = 1; i <= n; i++ )
        s += i;
    return ______;
}
int main()
{
    printf("%d", sum(100));
}
```

3. 下面函数功能是输入10个整数，逆序输出。

```c
void printarray(__________)
{
    int i;
    for(i = n-1; i >=0; i--)
        printf("%4d", a[i]);
}
int main()
{
    int a[10], i;
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);  // 输入数据到数组
    printarray(a, 10);       // 调用函数，逆序输出数组
}
```

4. 输出一维数组`{9.8, 12, 45, 67, 23, 19.8, 2.55, 45, 37.5}`中的最大值、最小值和平均值。

```c
float getMax(float a[], int n)
{
    
}
float getMin(float a[], int n)
{
    
}
float getAve(float a[], int n)
{
    
}
int main()
{
    float a[]={9.8, 12, 45, 67, 23, 19.8, 2.55, 45, 37.5}, n = sizeof(a)/sizeof(float);
    printf("最大值:%.2f\n",________________);
    printf("最小值:%.2f\n",________________);
    printf("平均值:%.2f\n",________________);
}
```

5. 字符串链接函数。

```c
void mystrcat(char s1[], char s2[])
{
    
}
int main()
{
    
}
```

6. 字符串长度函数。

```c
int mystrlen(char s[])
{
    
}
int main()
{
    
}
```

