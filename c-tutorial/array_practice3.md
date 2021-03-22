## 一维数组基本操作

###### 一、遍历

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

###### 二、查找

1. 在数组a中查找x是否存在，若存在返回其下标值，否则返回-1。

```c
int find(int a[], int n, int x)	// 在数组中查找x，找到则返回在数组中的下标，没找到返回-1
{
    int i;
    for(i = 0; i < n; i++)
        if(_______________)
            return i;
    return -1;
}
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,0}, i, x;
    scanf("%d", &x);	// 输入要查询的x
    printf("%d", find(a,10, x));
}
```

2. 在数组a中找出最大值的下标位置，最小值的下标位置。

```c
int findMax(int a[], int n)	// 返回数组最大值的下标
{
    int max_i = 0, i;
    for(i = 1; i < n; i++)
        if(_______________)
            max_i = i;
    return max_i;
}
int findMin(int a[], int n)	// 返回数组最小值的下标
{
    int min_i = 0, i;
    for(i = 1; i < n; i++)
        if(a[i] < a[min_i])
            _____________;
    return min_i;
}
int main()
{
    int s[] = {3,-8,7,2,-1,4};
    printf("最大值是：%d，最大值的下标位置是：%d", getMax(s,6), findMax(s,6));
    printf("最小值是：%d，最小值的下标位置是：%d", getMin(s,6), findMin(s,6));
}
```

3. 下面程序输出结果是（          ）

```c
int main()
{
    int a[] = {89,88,76,70,68,58};
    int x = 70, mid, pos = -1, find = 0, low = 0, high = 5;
    while(!find && low <= high)
    {
        mid = (high + low) / 2;
        if(x > a[mid])
            high = mid - 1;
        else if(x < a[mid])
            low = mid + 1;
        else{
            pos = mid;
            find = 1;
        }
    }
    printf("pos=%d",pos);
}
```

4. 折半查找也称为二分查找，适用于有序数组，其查找的基本过程是：先确定待查记录所在的范围，然后逐步缩小范围，直到找到，或找不到该记录为止。假定数组按照升序排列，对于给定值K，从数组中间位置开始比较，如果当前数据元素的值等于k，则查找成功。否则，若k小于当前数据元素的值，则在数组的前半部继续查找；反之，则在数组的后半部继续查找，依次重复进行，直至获得查找成功或不成功的结果。请补充完成下列程序中的相应部分：

```c
int main()
{
    int key=0;
    printf("请输入要查找的数：");
    scanf("%d",&key);
    int data[10]={1,3,5,7,8,9,13,18,22,28};
    int ret=BinarySearch(key,data);
    if(ret>=0)
	    printf("\n %d 是数组中的第%d个数\n",key,ret+1);
    else
    	printf("\n %d在数组中未找到！\n",key);
}
int BinarySearch(int key,int data[])
{
    int low=0,high=9,middle;
    while(__________________){        	/*查找结束条件*/
    	int middle= _______________;    	/*获取数组中间位置*/
    	if(________________)            	/*如查当前数据元素的值等于k*/
    		return middle;    	/*返回所在位置*/
    	if(key<data[middle]) 	/*如果若k小于当前数据元素的值*/
     		______________; 	/*在数组的前半部继续查找*/
    	else
     		_______________;	/*在数组的后半部继续查找*/
    }
    return -1; 	/*返回查找不成功标记*/
}
```

###### 三、插入

1. 在数组尾插入一个数。

```c
int main()
{
    int a[10] = {1,2,3}, n = 3, i, x;	// 1. 定义数组  n表示数组元素个数   
    a[n++] = 99;				  // 2. 在数组尾插入 99 
    while(n < 10){				  // 3. 循环插入N个数到数组尾
        scanf("%d", &x);
        ________________;					// a[n++] = x;
    }
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);  // 输出数组所有的数
	return 0;
}
```

2. 数组有n个元素，在下标pos（pos<n）的位置插入x。

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

​	1. 删除数组尾的一个元素

```c
int main()
{
    int a[] = {1,2,3,4,5};
    int i, n = 5; 	 // 数组元素个数
	_________________;		//--n;  个数减1，相当于删除了数组最后一个元素 
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);
}
```

​	2. 删除数组中的元素x，后面的元素前移。

```c
int delet(int a[], int n, int x)
{
    int i = 0, j;
    while(a[i]!=x && i < n)		// 找到x元素的下标 i
        i++;
    if(i >= n) return 0;		// 没有找到x, 删除失败
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

