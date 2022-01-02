## 位运算

- (2021年高考) 下面程序运行结果是（            ）

```c
int main()
{   int a = 5, b = 6, result = 0;
    result = (a > b) ? (a>>1) : (b<<1);
    printf("result=%d\n", result);
}
```

- （2018年高考）若 `int a = 5, b;` 执行 `b = a>>2;` 后，`b` 的值是（        ）

```c
A. 10	B. 20	C. 1	D. 2
```

- (2009年高考）下面程序输出结果是（        ）

```c
int main()
{   
    int x=68;
	printf("%c,%d",x,~x);
}
```

- (2008年高考）下面程序输出结果是（        ）

```c
int main()
{	
    char a=55;
	a=~a&055;
	printf("%x,%o",a,a);
}
```

- (2007年高考）下面程序输出结果是（        ）

```c
int main()
{   
    int x = 4, y = 8, z;
	z = x<<2|y;
	printf("%d",z);
}
```

- （2020年高考）执行`int a = 3; a += a^2;` 后，则 `a` 的值是（        ）

```tex
A. 12	B. 9	C. 6	D. 4
```

- （2020年高考）下面程序运行结果是（        ）

```c
#include<stdio.h>
int main()
{
    int a[] = {118,65,128}, i;
    for (i = 0; i < 3; i++)
        printf("%c", (a[i])&(a[i]-1) ? 'N':'Y');
}
```

- （2019年高考）已知 `int a=1,b=2,c=3,x=(a^b)&c;`，则 `x` 的值为（        ）

```tex
A. 0	B. 1	C. 2	D. 3
```

- （2017年高考）函数 `countBit1` 用于统计某个字节中值为1的位的个数。

```c
unsigned int countBit1(char byteData)
{
    int i;
    unsigned int num = 0, tmpVal;
    for (i = 0; i < 8; i++)
    {
        tmpVal = __________;
        tmpVal &= 0x01;
        if (tmpval)
            ___________;
    }
    return num;
}
```

- (2011年高考）下面程序输出结果是（        ）

```c
#include<stdio.h>
int bits_count(unsigned value)
{   
    int count=0;
	for(count=0;value!=0;value>>=1)
		if((value&1)!=0)
            count++;
	return count;
}
int main(){
	printf("%d",bits_count(14));
}
```
