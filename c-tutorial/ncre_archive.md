###### 第64套

1. 函数fun的功能是：把形参a所指的数组中的奇数按原顺序依次存放到a[0]、a[1]、a[2]......中，把偶数从数组中删除，奇数个数通过函数值返回。

```c
#include<stdio.h>
#define N 9
int fun(int a[], int n)
{
    int i, j = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i]%2==______)
        {
            a[j] = a[i];
            ___________;
        }
    }
    return __________;
}
int main()
{
    int b[N] = {9,1,4,2,3,6,5,8,7}, i, n;
    printf("The original data: ");
    for(i = 0; i < N; i++)
        printf("%4d",b[i]);
   	printf("\n");
    n = fun(b, N);
    printf("The number of odd: %d\n", n);
    printf("The odd number:\n");
    for(i = 0; i < n; i++)
        printf("%4d", b[i]);
}
```

