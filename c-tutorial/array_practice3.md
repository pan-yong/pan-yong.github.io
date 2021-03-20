## 一维数组基本操作

###### 遍历

1. 输入10个数，逆序输出。

```c
#include<stdio.h>
int main()
{
    ____________________;
    int i;
    for(i = 0; i < 10; i++){
        scanf("%d", _______);
    }
    for(i = 9; i >= 0; _______){
        printf("%d ", a[i]);
    }
    return 0;
}
```

2. 输出数组中最大值和最小值。

```c
#include<stdio.h>
int getMax(int a[], int n)	// 返回数组最大值
{
    int i, max = a[0];
    for(i = 1; i < n; i++)
    {
        if(_____________)
            max = a[i];
    }
    return max;
}
int getMin(int a[], int n)	// 返回数组最小值
{
    int i, min = a[0];
    for(i = 1; i < n; i++)
    {
        if(a[i] < min)
            _______________;
    }
    return min;
}
int main()
{
    int a[10] = {2,5,3,1,6,8,9,10,0,7}, max, min;
    max = getMax(a, 10);
    min = getMin(a, 10);
    printf("最大值是：%d\n", max);
    printf("最小值是：%d\n", min);
    return 0;
}
```

3. 下面程序的功能是：把两个已按升序排列的整型数组合并成一个升序数组。请填空。

```c
#include<stdio.h>
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



###### 查找

