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
    float max = a[0];
    int i;
    for(i = 1; i < n; i++)
        if(__________)
            max = ______;
    return max;
}
float getMin(float a[], int n)
{
    float min = a[0];
    int i;
    for(i = 1; i < n; i++)
        if(__________)
            min = ______;
    return min;
}
float getAve(float a[], int n)
{
    int i;
    float sum = 0, ave;
    for(i = 0; i < n; i++)
        sum += ______;
    ave = ___________;
    return ave;
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
    int i = 0, j = 0;
    while(_____) i++;
    while(s2[j] != '\0')
        ___________;
    s1[i] = '\0';
}
int main()
{
    char s1[80] = "welcome", s2[80] = "HR";
    mystrcat(s1, s2);
    printf("%s", s1);
}
```

6. 字符串长度函数。

```c
int mystrlen(char s[])
{
    int i = 0;
    while(s[i] != '\0')
        _______;
    return i;
}
int main()
{
    char s[] = "heihei";
    printf("%d", mystrlen(s));
}
```

