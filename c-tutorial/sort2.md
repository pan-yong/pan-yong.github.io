## 练习

1. 下面程序输出结果是（            ）

```c
#include<stdio.h>
#define N 10
void fun(int aa[],int n)
{
	   int I,j=0,k=0,t = aa[n], bb[N];
	   for(I=0;I<N;I++)
	   {
	     if(aa[I]>t) bb[j++]=aa[I];
	     if(aa[I]<t) aa[k++]=aa[I];
	   }
	   aa[k++]=t;
	   for(I=0;I<j;I++,k++)
	     aa[k]=bb[I];
}
main()
{
	int i,aa[N]={33,67,42,25,58,76,85,16,41,56};
    fun(aa,2);
    for(i=0;i<N;i++)
	    printf("%4d",aa[i]);
    return 0;
}
```

2. 下面程序输出结果是（        ）

```c
void swap(int v[], int i, int j)
{
	int t;
    t = v[i] ; v[i] = v[j]; v[j] = t;
}
void f(int v[], int left, int right)
{   
    int i, last;
    swap(v, left, (left+right)/2); 
    last = left;
    for(i = left + 1; i <= right; i++) 
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
}
int main()
{
    int a[10] = {33,67,42,25,58,76,85,16,41,56}, i;
    f(a, 0, 9);
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}
```

3. 下面程序输出结果是（        ）

```c
void f(int arr[], int left, int right)
{   
    int i = left, j = right, v = arr[left];
    while(i < j)
    {
        while(i < j && arr[j] >= v) j--;	
        if(i < j) arr[i++] = arr[j];		
        while(i < j && arr[i] <= v) i++;
        if(i < j) arr[j--] = arr[i];		
    }
    arr[i] = v; 						
}
int main()
{
    int a[10] = {33,67,42,25,58,76,85,16,41,56}, i;
    f(a, 0, 9);
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
}
```

4. 下面程序输出结果是（        ）

```c
int main()
{
    char a[5][10] = {"cc", "aa", "bb", "ee", "dd"}, t[10];
    int i, j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4 - i; j++)
            if(strcmp(a[j], a[j+1]) < 0){
                strcpy(t, a[j]); strcpy(a[j], a[j+1]); strcpy(a[j+1], t);
            }
    for(i = 0; i < 5; i++)
        printf("%s ", a[i]);
    return 0;
}
```

5. 下面程序输出结果是（            ）     cs

```c
int main()
{
    char a[5][10] = {"cc", "aa", "bb", "ee", "dd"}, t[10];
    int i, j;
    for(i = 0; i < 4; i++)
        for(j = i+1; j < 5; j++)
            if(strcmp(a[i], a[j]) > 0){
                strcpy(t, a[j]); strcpy(a[j], a[i]); strcpy(a[i], t);
            }
    for(i = 0; i < 5; i++)
        printf("%s ", a[i]);
}
```

