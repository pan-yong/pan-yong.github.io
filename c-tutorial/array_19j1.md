## 一维数组基本操作

###### 一、遍历

1. 输出数组中最大值和最小值。

```c
#include<stdio.h>
int main()
{
    int a[10] = {2,5,3,1,6,8,9,10,0,7}, max = a[0], min=a[0], i;
    for(i = 1; i < 10; i++)
    {
        if(______________)
            max = a[i];		// 记住最大值
        if(a[i] < min)
            ____________; 	// 记住最小值
    }
    printf("最大值是：%d\n", max);
    printf("最小值是：%d\n", min);
    return 0;
}
```

###### 二、查找

1. 在数组a中查找x是否存在，若存在返回其下标值，否则返回-1。

```c
int main()
{   
    int a[10] = {1,2,3,4,5,6,7,8,9,0}, i, x, pos = -1;
    scanf("%d", &x);	// 输入要查询的x
    for(i = 0; i < n; i++)
        if(_______________)
        {
            pos = i; break;
        }
    printf("%d", pos);
}
```

2. 在数组a中找出最大值的下标位置，最小值的下标位置。

```c
int main()
{
    int s[] = {3,-8,7,2,-1,4}, i, max_i = 0, min_i = 0;
    for(i = 1; i< 6; i++)
    {
        if(____________)
            max_i = i;		// 记住最大值下标
        if(a[i] < a[min_i])
            _____________;   // 记住最小值下标
    }
    printf("最大值是：%d，最大值的下标位置是：%d",a[max_i], max_i);
    printf("最小值是：%d，最小值的下标位置是：%d",a[min_i], min_i);
}
```

###### 三、插入

1. 数组有n个元素，在下标pos（pos<n）的位置插入x。

```c
#include<stdio.h>
int main()
{
    int a[20] = {3,7,10,12,18,20}, i, j;
    int x = 15, pos = 4;// 把15插入到数组下标为4的位置
    for(j = 5; j >= pos; j--)// 数据后移空出pos位置
        a[j+1] = a[j];
    a[pos] = x;				// 把数据插入到pos的位置
    for(i = 0; i < 7; i++)
        printf("%4d", a[i]);
    return 0;
}
```

3. 在一个升序数组中，插入一个数，使其依然保持升序。

```c
#include<stdio.h>
int main()
{
    int a[20] = {3,7,10,12,18,20}, x = 15, i, j, n;
    i = 6;	    // 初始元素个数
    j = i - 1;	// 从后往前找插入点
    while(j >= 0 && ____________)  // a[j] > x
    {
        __________________;		// 后移元素
        j--;
    }    
    a[j+1] = x;				// 插入x
    n = i + 1;    			// 元素个数增加1
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);
    return 0;
}
```

###### 四、删除

​	1. 删除数组中的元素x，后面的元素前移。

```c
int delet(int a[], int n, int x)
{
    int i = 0, j;
    while(a[i]!=x && i < n)		// 找到x元素的下标 i
        i++;
    if(i >= n) return ;		// 没有找到x, 直接返回
    for( j = i + 1; j < n; j++)
        ________________;		// 每个元素前移1个位置，覆盖删除x
    return 1;					// 删除x成功
}
int main()
{
    int a[] = {3,5,7,2,4,6,1,8,0,9},n = 10, x = 6, i;
    if( delet(a,n,x) ) --n;
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);
    return 0;
}
```

