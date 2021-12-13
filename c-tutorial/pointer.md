## 指针与地址

> 内存的每一个存储单元，都有一个地址编号，用来存放这个地址的变量即指针变量。

1.下面程序输出结果是（        ）

```c
int main()
{
    int x = 1, y = 2, *ip;	// ip is a pointer to int
    ip = &x;			   // ip now points to x
    y = *ip;	
    *ip = 0;
    printf("%d %d", x, y);	
}
```

2.下面程序fun函数的功能是交换主函数中两个变量a、b的值。请填空。

```c
void swap(_____________)	// 指针作为函数形参
{
    int t;
    t = *x;*x=*y;*y=t;
}
int main()
{
    int a = 1, b = 2;
    printf("a=%d,b=%d\n",a,b);
    swap(____________);		   // 指针作为函数实参
    printf("a=%d,b=%d\n",a,b);
}
```

3.下面程序输出结果是（        ）

```c
int main()
{
    char *s = "%s,%%a=%d,%%b=%d\n";
    int a = -5, b = 5;
    a += b;
    printf(s, "%%%%", a, b);	 // 字符串其实是指针
}
```

4.下面程序输出结果是（        ）

```c
int *f(int *x, int *y)      // 指针作为函数返回值
{
    return *x < *y ? x : y;
}
int main()
{
    int a = 6, b = 7, *p, *q, *r;
    p = &a; q = &b; r = f(p,q);
    printf("%d,%d,%d", *p, *q, *r);	
}
```

## 指针与一维数组

> 相同点：指针存的是地址，数组名也是地址。对于`int a[10], *p =a;`，`a[i]`等价于 `*(a+i)` 、`*(p+i)` 、`p[i]`。数组作为函数参数时，传的数组名是数组首地址，也就是指针。

> 不同点：数组名的值不能变所以不能`a++`，而指针变量可以`p++`，常用指针遍历数组：`for (p = a; p < a + 10; p++)`   *p;
>

1.设有定义语句`int m[]={2,4,6,8}, *k = m;` ，则以下选项中表达式值为6的是（        ）

```tex
A. *(k+2)         B. k+2        C. *k+2        D. *k += 2	
```

2.以下程序输出结果是（        ）

```c
int main()
{   int a[10] = {19,23,44,17,37,28,49,36}, *p;
    p = a;    p += 3;		// p是 int *， p+3的值，偏移三个int。
    printf("%d", *p + 3);		
}
```

3.以下程序输出结果是（        ）

```c
int main()
{   int x[] = {0,1,2,3,4,5,6,7,8,9}, s = 0, i, *p = &x[0];
    for(i = 1; i < 10; i+=2)  s += *(p+i);
    printf("sum=%d", s);	
}
```

4.以下程序输出结果是（        ）

```c
int main()
{   int x[] = {1,2,3,4,5}, y = 0, i, *p =  &x[3];
    for(i = 0; i <= 3; i++){
        y += *p;   --p;
    }
    printf("%d", y);		
}
```

5.以下程序输出结果是（        ）

```c
void fun(int *a, int *max, int *min)
{   int i;  *max = *min = *a;
    for(i = 1; i < 9; i++){
        if(*max < *(a+i))  *max = *(a+i);
        if(*min > *(a+i))  *min = *(a+i);
    }
}
int main()
{   int a[9] = {76, 78, 45, 90, 34, 52, 12, 66, 38}, max, min;
    fun(a, &max, &min);		
    printf("%d %d", max, min);	
}
```

6.以下程序输出结果是（        ）

```c
#define N 7
int fun(int *a, int *x)
{   
    int i, j = 0;
    for(i = 0; i < N; i++)
        if(*(a+i) < 60)
        {
            *(x+j) = *(a+i); 
            j++;
        }
    return j;
}
int main()
{   
    int a[N] = {22,99,44,66,55,88,33}, x[N], i, k;
    k = fun(a, x);
    for(i = 0; i < k; i++)
        printf("%3d", x[i]);	
}
```

7.以下程序输出结果是（        ）

```c
int find(int *a, int n, int x)
{   
    int *p = a;
    while(p < a + n && *p != x) 
        p++;
    if(p < a+n) return p-a;		// p - a 地址差表示之间相差多少个 int 
    else return -1;
}
int main()
{   
    int a[10] = {1,2,3,4,5,6,7,8,9,10}, x = 4;
    printf("%d", find(a,10,x));		
}
```

8.以下程序在a数组中查找与x相同的元素所在位置。请填空。

```c
int main()
{   
    int a[11], x, i;
    for(i = 1; i <= 10; i++)  
        scanf("%d", a+i);
    scanf("%d", &x);
    i = 10;
    while( x!=*(a+i) && i > 0)
        ___________;		
    if(______) printf("%5d's position is : %d\n", x, i);	
    else printf("%d Not been found!", x);
}
```

9.以下程序输出结果是（        ）

```c
#define N 6
void fun(int *a)
{   int i, t =  *a;
    for(i = 0; i < N - 1; i++)  *(a+i) = *(a+i+1);
    *(a+i) = t;
}
int main()
{   int a[N] = {11,66,33,77,55,99},  *p;
    fun(a);
    for(p = a; p < a + N; p++)   printf("%3d", *p);	
}
```

10.以下程序把x插入到a数组中下标为k的位置中，然后输出数组中所有元素。请填空。

```c
int main()
{   int a[51], k, x, i, n;
    scanf("%d", &n);
    for(i = 1; i<=n; i++)  scanf("%d", a+i);
    scanf("%d %d", &k, &x);
    if( k > 0 && k <= n+1){
        for(______________)		
            *(a+i+1) = *(a+i);
        *(_____) = x;			
        __________________;		
    }
    for(i = 1; i <= n; i++)
        printf("%4d", *(a+i));
}
```

11.下面程序运行结果是（        ）

```c
int main()
{   int a[10] = {5,12,7,3,2,9,20,15,6}, n = 9, k = 5, x = 6, i;
    if( k > 0 && k <= n+1){
        for(i = n-1; i >= k; i--)
            *(a+i+1) = *(a+i);
        *(a+k) = x;
        n++;
    }
    for(i = 0; i< n; i++)  printf("%d ", *(a+i));	
}
```

12.以下程序是把一个十进制整数转为二进制数。请填空。

```c
int main()
{   int b[16], x, k=-1, r, i;
    scanf("%d", x);
    do{ r = x % 2; k++;
        *(______) = r;
        x / = 2;
    }while(_______);
    for(i = k; i >= 0; i--)  printf("%d", *(____));
}
```