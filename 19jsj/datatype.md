## 数据类型

#### （一）基本数据类型

- 基本数据类型：`char`, `int`, `float` 。文档：https://wangdoc.com/clang/types.html

<img src="images/datatype.png" alt="img" style="zoom: 25%;" />

- 位运算：`&` , `|` , `~` , `^`, `<<` , `>>`。文档：https://wangdoc.com/clang/operator.html

<img src="images/operator.png" alt="img" style="zoom: 25%;" />

- 二进制补码：C语言中整数是以二进制补码进行存储的，最高位为符号位， `0`表示正，`1`表示负数。正数的补码等于原码，负数的补码等于原码的反码加1。

```c
00000000 00000000 00000000 01010011  // 83的原码，最高位0表示正数
10000000 00000000 00000000 01010011  //-83的原码，最高位1表示负数
11111111 11111111 11111111 10101100  // 反码=按位取反，符号位不变
11111111 11111111 11111111 10101101  // 补码=反码+1。十六进制形式 0xffffffad
```

```c
int main()
{
    int a = -83;
    printf("%x", a);//输出 ffffffad
}
```

```c
思考：
1) -8在内存中的存储形式是________________    -1在内存中的存储形式是________________
    
2) 字符型常量在内存中存放的是____  
    A. ASCII码    B.BCD码    C. 内部码  D. 十进制码    
    
3）下面程序运行结果是__________
#include<stdio.h>
int main()
{
    char a;
    a = 324;
    printf("%c", a);
    return 0;
}
```

#### （二）指针与数组

- 指针：https://wangdoc.com/clang/pointer.html

<img src="images/pointer.png" alt="img" style="zoom: 25%;" />

- 数组：https://wangdoc.com/clang/array.html

<img src="images/array.png" alt="img" style="zoom: 25%;" />

#### （三）结构体联合体和枚举型

- `struct` 结构：https://wangdoc.com/clang/struct.html

<img src="images/struct.png" alt="img" style="zoom: 25%;" />

- `Union` 结构：https://wangdoc.com/clang/union.html

<img src="images/union.png" alt="img" style="zoom: 25%;" />

- `Enum` 类型：https://wangdoc.com/clang/enum.html

<img src="images/enum" alt="img" style="zoom: 25%;" />

#### 练习1：位运算

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

- （2020年高考）下面程序运行结果是（        ）

```c
#include<stdio.h>
int main()
{
    unsigned int a = 6;
    int b = -20;
    (a+b>6) ? puts("sum>6") : puts("sum<=6");
}
```

