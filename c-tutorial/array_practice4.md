## 一维数组历年高考题

###### 2020年高考

1. 7个待测样本中有且仅有一个样本指标超标，为了找到这唯一超标样本，采用3个检测试剂盒进行检测。方法如下∶把7个样本按1，2，3，…，7进行编号，并将其编号转换为相应的3位二进制数;把可重复使用的3个检测试剂盒进行编号，分别对应 3 位二进制数的每一位;如果样本编号3位二进制中的某位为1，就用相应二进制位（编号）的试剂盒进行检测;按上述方法对每一个待测样本进行检测;最后，检测为阳性（设定值为1）试剂盒编号组成的二进制数就是超标样本的编号。下面程序功能就是完成上述检测方法并输出超标样本编号，即∶"flag=7"。请补充完整。

   ```c
   int main()
   {  
       int sample[8] = {0,0,0,0,0,0,0,1}; /*样本编号，第7个数值为1表明其超标*/
   	int test[3] = {0};/*检测试剂盒编号，test[0]对应二进制最低位，test[2]对应最高位*/
   	int i, j, k ,base = 1, flag = 0;
   	for(i = 1; i <= 7; i++)
   	{
   		___________________
   		j = 0;
   		while(____________){
   			if(k%2==1)
   				test[j] = test[j] || sample[i];
   			_______________;
   			j++;
   		}	
   	}
   	for(i = 0; i < 3; i++){
   		flag += test[i]*base;
   		____________________;
   	}
   	printf("flag=%d", flag);
   	return 0;
   } 
   ```

   2. 下面程序输出结果是（            ）

   ```c
   int main()
   {
   	int a[] = {118, 65, 128}, i;
   	for(i = 0; i < 3; i++)
   		printf("%c", (a[i])&(a[i]-1) ? 'N' : 'Y');
   	return 0;
   }
   ```

   3. 下面程序输出结果是（            ）

   ```c
   #include<stdio.h>
   int main()
   {
       int a[] = {89,88,76,70,68,58};
       int x = 70, min, pos = -1, find = 0, low = 0, high = 5;
       while(!find && low <= high)
       {
           min = (high + low) / 2;
           if(x > a[mid])
               low = mid + 1;
           else if(x < a[mid])
               high = mid - 1;
           else{
               pos = mid;
               find = 1;
           }
       }
       printf("pos=%d",pos);
       return 0;
   }
   ```

###### 2019年高考

4. 下面程序功能是统计5个同学成绩（1~100间的整数）中低于平均成绩的人数并输出，请补全以下代码。

```c
#include<stdio.h>
int main()
{  
    int i,count=0;
    __________________________;
   	float ave=0.0;
   	printf("input 5 scores:\n");
   	for(i=0;i<5;i++)
   	{
     	_____________________;
     	ave+=score[i];
	}
  	__________________________;   
    for(i=0;i<5;i++)
  		if(_____________)
    		count++;
	printf("%2d",count);
}
```

###### 2018年高考

5. 入夏标志着春夏季节完成转换，气候学上入夏的标准是必须要连续5天日平均气温达到22℃或以上，则这连续5天中的第一天为入夏日。函数fun的功能是判断5月份是否入夏并输出有关信息，若入夏就返回是哪天，否则返回-1。请补全下列代码。

```c
#include<stdio.h>
int fun(int a[], int n)	/*a存放某月的每日气温值，n存放的是此月的天数*/
{
    int i, c = 0;
    for(i = 0; i < n; i++)
    {
        if(____________){
            c++;
            if(c >= 5)____________;
            else ____________;
        }
        ______________;
    }
    return -1;
}
int main()
{
    int t[31]={20,21,22,22,19,18,18,19,22,23,
               22,21,20,21,24,22,25,24,23,
               21,23,22,21,22,25,26,30,28,27,28};
    int d;
    d=fun(t,31);
    if(d==-1)
        printf("Not in summer\n");
    else
        printf("5-%d in summer\n",d+1);
    return 0；
}
```

6. 下面程序输出结果是（                  ）

```c
#include<stdio.h>
int main()
{
    int a[20], i , m = 10, k = 8;
    for(i = 0; m > 0; i++){
        a[i] = m % k;
    }
    for(i--; i >= 0; i--)
        printf("%d", a[i]);
    return 0;
}
```

###### 2017年高考

7. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
void fun(int b[])
{
    int j;
    for(j = 0; j < 3; j++)
        b[j] = j;
}
int main()
{
    int a[3] = {1,2,3}, k;
    fun(a);
    for(k = 0; k < 3; k++)
        printf("%d", a[k]);
    return 0;
}
```

8. 下面程序的运行结果是（        ）

```c
#include<stdio.h>
int main()
{
    char a[] = {'a','b','c','d','e','f','g','h','\n','\0'};
    int x = sizeof(a);
    int y = strlen(a);
    printf("%d %d", x, y);
}
```

###### 2015年高考题

9. 下面函数fun的功能是：依次取出字符串中所有数字字符，形成新的字符串，并取代原字符串。以下程序只允许修改两行。

```c
Ll   #include <stdio.h>
L2   void fun (char s[ ]){
L3      int i=0,j=0;
L4      for( ; s[i]!='\0’; i++)
L5      if(s[i]>='0' & s[i]<='9'){
L6       s[j]=s[i];
L7        j--;
L8       }
L9      s[j]='\0';
LlO    }
```

10. 下面程序运行结果是（        ）

```c
int f(int x[], int n)
{
    int i, r = 1;
    for(i = 0; i <= n; i++)
        r = r * x[i];
    return r;
}
int main()
{
    int s, a[] = {2,7,3,1,5,4,6,8};
    s = f(a,3);
    printf("%d\n", s);
}
```

###### 2013年高考

11. 下面程序运行结果是（        ）

```c
int main()
{
    int a[9]={1,2,3,4,5,6,7,8};
    int *p=a, sum=0;
    for( ;p<a+8;p++)
    	if(*p%2==0) sum=sum+*p;
    printf("%d",sum);
}
```

12. 下面程序运行结果是（        ）

```c
void f(int *q)
{   int i;
    for(i=0;i<3;i++)
	    (*q)--;
}
int main()
{   int a[5]={8,7,6},i;
    f(a);
    for(i=0;i<3;i++)
    	printf("%d",a[i]);
}
```

###### 2010年高考

13. 下面程序运行结果是（        ）

```c
void fun(int *a)
{  
    *a = *(a-1) + *(a+1);
}
int main()
{
    int i = 0, s = 0, arr[5] = {1,3,5,7,9};
    fun(arr+2);
    for(; i < 5; i++)
        s += arr[i];
    printf("%d", s);
}
```

###### 2009年高考

14. 以下程序的功能是：从一个整数队列中找出值最大的数，若有多个则取最先得到的那一个。以下程序，请将错误处的行号及正确语句填入答题卡相应位置中。

```c
L1	#include <stdio.h>
L2	int *findMax(int a[],int n)
L3	{
L4		int i,j,max;
L5		for(i=1,j=0,max=a[0];i<n;i++)
L6		{	if(a[i]>max)
L7			{	j=i;
L8				max=a[i];	}
L9		}
L10		return *(a+j);}
L11	main()
L12	{
L13		int i,a[50];
L14		printf("enter array:");
L15		for(i=0;i<50;i++)
L16			scanf("%d",&a[i]);
L17		printf("%d",findMax(a,50));
L18	}
```

15. 下面程序输出结果是（        ）

```c
#include<stdio.h>
void f(int arr[])
{
    int i = 0;
    for(; arr[i] <= 10; i+=2)
        printf("%d", arr[i]);
}
int main()
{
    int arr[] = {2,4,6,8,10,12};
    f(arr+1);
    return 0;
}
```

###### 2008年高考

16. 下面程序输出结果是（         ）

```c
#include<stdio.h>
int main()
{
    int n = 132, i = 1, j, k , b[10];
    while( n!= 0){
        j = n % 6;b[i] = j;
        n = n / 6;i = i + 1;
    }
    for(k = i - 1; k > 0; k--)
        printf("%d", b[k]);
    return 0;
}
```

###### 其他习题

17. 下面程序运行结果是（        ）

```c
#include<stdio.h>
int main()
{
    int a[] = {1,2,3,4}, i, j = 1, s = 0;
    for(i = 3; i >= 0; i--){
        s += a[i] * j;
        j = j * 10;
    }
    printf("s=%d",s);
}
```

18. 下面程序输出结果是（        ）

```c
int main()
{
	char ch[] = {"123abc456"};
	int i, s = 0;
	for(i = 0; ch[i] >= '0' && ch[i] <= '9'; i++)
		s = 10*s + ch[i] - '0';
	printf("%d",s);
	return 0;
}
```

19. 下面程序输出结果是（           ）

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

19. 函数fun的功能是：把形参a所指的数组中的奇数按原顺序依次存放到a[0]、a[1]、a[2]......中，把偶数从数组中删除，奇数个数通过函数值返回。

    ```c
    #include<stdio.h>
    #define N 9
    int fun(int a[], int n)
    {
        int i, j = 0;
        for(i = 0; i < n; i++)
        {
            if(a[i]%2==______){
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
        n = fun(b, N);
        printf("\n The number of odd: %d\n", n);
        for(i = 0; i < n; i++)
            printf("%4d", b[i]);
    }
    ```

20. 下面函数fun的功能是：计算数组元素中所有值为正数的平均值（不包括0）。主函数中，从键盘输入若干个数放入数组中，用0结束输入，并将0放在数组最后一个元素中。例如：数组中元素的值依次是`39,-47,21,2,-8,15,0`，则程序运行输出结果为`19.250000` 。求修改程序中的错误。

```c
L1  #include<stdio.h>
L2  double fun(int x[])
L3  {
L4      int sum = 0;
L5      int c = 0, i = 0;
L6      while(x[i] != 0)
L7      {
L8       	if(x[i] > 0){
L9              sum += x[i];
L10             c++;
L11         }    
L12         i++;
L13 	}
L14     sum \=c;
L15     return sum;
L16 }
L17 int main()
L18 {
L19     int x[1000], i = 0;
L20     do{
L21         scanf("%d", &x[i]);
L22    }while(x[i++] != 0);
L23    printf("%lf\n", fun(x));
L24     return 0;
L25 }
```

21. 下面函数fun的功能是：删除数组中值为x的元素，变量n是数组元素个数，删除成功返回数组中元素个数，删除失败返回-1。假定数组中不存在重复数字。下面程序中有两行错误，请指出错误所在行，并给出该行修改后的代码。

```c
L1  #include<stdio.h>
L2  #define N 20
L3  int fun(int *a, int n, int x)
L4  {
L5      int p = 0, i;
L6      while(x != a[p])
L7          p = p + 1;
L8      if(p<n)
L9          return -1;
L10     else{
L11         for(i = p; i < n - 1; i++)
L12             a[i+1] = a[i];
L13         return n-1;
L14     }
L15 }
L16 int main()
L17 {
L18     int w[N] = {-3,0,1,5,7,99,10,15,30,90}, x, n = 10, i;
L19     scanf("%d", &x);
L20     n = fun(w,n,x);
L21     if(n == -1)
L22         printf("No be found!\n");
L23     else{
L24         printf("The data after deleted:\n");
L25         for(i = 0; i < n; i++)
L26             printf("%5d", w[i]);
L27     }
L28 }
```

