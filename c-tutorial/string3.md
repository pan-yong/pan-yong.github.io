## 字符串高考题

###### 2020年高考

1. 下面程序运行结果是（             ）

```c
int main()
{
    char s1[] = "I love China", s2[] = "I love", *str1 = s1, *str2 = s2;
    int answer = 0;
    while(!(answer=*str1-*str2) && *str2){
        str1++;str2++;
    }
    if(answer < 0) answer = 1;
    else if(answer > 0) answer = -1;
    printf("answer=%d", answer);
}
```

###### 2019年高考

2. 下面程序运行结果是（             ）

```c
int fun(char *s)
{
    char *t = s;
    while(*t++);
    return t - s;
}
int main()
{
    char t[8] = "123456";
    printf("%d", fun(t));
}
```

3. 下面程序运行结果是（             ）

```c
int fun(char s[])
{
    int n = 0;
    while(*s <= '9' && *s >= '0'){
        n = 10*n + *s - '0';
        s++;
    }
    return n;
}
int main()
{
    printf("%d",fun("056a0"));
}
```

4. 下面程序运行结果是（             ）

```c
int f(char *s, char *t)
{
    int n = 0, num = 0;
    char *p, *r;
    while(*s)
    {
        p = s; r = t;
        while(*r)
            if(*r==*p){
                r++;p++;
            }else{
                break;
            }
        if(*r=='\0') num += 1;
        n++;s++;
    }
    return num;
}
int main()
{
    printf("the result is %d", f("aabdabc", "ab"));
}
```

###### 2018年高考

5. 下面程序运行结果是（                ）

```c
int main()
{
    char str[50] = "welcome2018";
    int i, n = 0;
    for(i = 0; str[i] != '\0'; i++)
        if('0' <= str[i] && str[i] <= '9')
            m = n*10 + str[i] - '0';
    printf("result=%d",n);
}
```

###### 2017年高考

6. 下面程序运行结果是（              ）

```c
int main()
{
    char a[]="abcdef", b[]="acdeea", *p1, *p2; int i;
    p1 = a; p2 = b;
    for(i = 0; i < 6; i++){
        if(*(p1+i) != *(p2+i))
            printf("%c", *(p1+i));
    }
}
```

7. 函数endsWith(char* str, char* substr)用于判断字符串str是否以子字符串substr结尾，是返回整数1，否返回整数0。以下程序只允许修改三行。

```c
L1 int endsWith(char* str, char* substr)
L2 {
L3		int sublen =0;
L4		while(str != '\0')
L5		{
L6			if(substr[sublen] !='\0')
L7			{
L8				sublen++;
L9			}
L10			str++;
Lll		}
L12		int i=0;
L13		for( ; i<sublen; i++)
L14		{
L15			char strCh = *str;
L16			char subCh = *--substr;
L17			if(strCh!=subCh)
L18			{
L19				return 0;
L20			}
L21		}
L22		return 1;
L23	}
```

###### 2016年高考

8. 下面程序运行结果是（              ）

```c
void f(char *p)
{
    char max, *q;
    int i = 0;
    max = p[i];
    while(p[i] != '\0')
    {
        if(max < p[i]){
            max = p[i]; q = p+i;
        }
        i++;
    }
    while(q > p){
        *q = *(q-1); q--;
    }
    p[0] = max;
}
int main()
{
    char str[80] = "abcde";
    f(str);puts(str);
}
```

9. 下面程序运行结果是（              ）

```c
int main()
{
    int i , x = 0, t = 1;
    char s[10] = "101010";
    for(i = strlen(s) - 1; i >= 0; i--, t <<= 1)
        if(s[i] != '0')
            x += t;
    printf("x=%d", x);
}
```

10. 下面程序输出结果是（            ）

```c
void f(char *from, char *to)
{
    while((*to++=*from++) != '\0');
}
int main()
{
    char s1[80] = "teacher!", s2[80] = "student!";
    f(s2, s1);
    printf("s1=%s\ns2=%s\n",s1,s2);
}
```

###### 2015年高考

11. 函数convertNum用于实现无符号十进制数到其它进制数的转换，转换结果的每一位以字符存储于字符数组s中（如十进制3转换为二进制后，数组s中存储的字符串为11），参数srclnt为待转换数据，d为转换的目标进制。函数convertNum转换成功返回l，失败返回0。以下程序只允许修改三行。

```c
L1    #include <stdio.h>
L2    #include <stdlib.h>
L3    #define M sizeof(unsigned int)*8
L4    int convertNum(unsigned srclnt,int d,char s[])
L5    {
L6        static char digits[]="0123456789ABCDEF";
L7        char buf[M+1];
L8        int j,i=M;
L9        if(d<2||d>16)
L1O       {
L11            s[0]=’\0';
L12            return 0;
L13       }
L14       buf[i]='\0';
L15       do
L16       {
L17            buf[--i]=digits[srclnt/d];
L18            srclnt=srclnt%d;
L19       }while(srclnt);
L20       for(j=0;buf[i]!=’\0';j++,i++)
L21       {
L22          s[j]=buf[i];
L23       };
L24       s[j+1]='\0';
L25       return 1;
L26   }
```

12. 下面函数，通过指针将一个字符串反向。如下程序的输出为：dcba。请填空。

```c
void strReverse(char *s)
{   char c, *p;
    _______________; 
    while(*p!='\0')
        p++;
    _______________;
    while(s<=p)
    {  c=*s;*s=*p; *p=c; s++;
       __________;
    }
}
main()
{   char a[10]="abcd";
    strReverse(a);
    printf("%s",a);
}
```

13. 输入一行文字，找出其中大写字母、小写字母、空格、数字及其它字符各有多少。请填空。

```c
int main()
{
    char str[40],*p,sl=0,s2=0,s3=0,s4=0,s5=0;
    gets(str);
    p=str;
    while(*p)
    {
         if(______________________________)  sl++;
         else if(_________________________)  s2++;
         else if(_________________________)  s3++;
         else if(_________________________)  s4++;
         else s5++;
         p++;
    }
    printf("大写字母：%d 小写字母：%d 数字：%d 空格：%d 其它：%d\n",s1, s2, s3, s4, s5);
}
```

###### 2014年高考

14. 以字符串的形式输入一个浮点数的字符串，通过程序转换成对应的浮点数，需要考虑输入数据的正负。

```c
#include <stdio.h>
#define N 12
int main() 
{   char src[N],ch;
	int i, j, count=0; 	// count 用于记录某字符为小数点后第几位
	int isPositive=1, isBefore=1; // // isPositive用于标示正负，isBefore用于标记小数点前或小数点后
	double result=0;
    gets(src);
	for(i=0; i<N; i++)
    {
		ch=src[i];
		if(ch!='\0')
         {
		    switch(ch)
             {
                case '-': isPositive=0; break;
                case '.': isBefore=0;break;
			   default:
					if(ch>='0'&&ch<='9')
                      {
						if(isBefore)
                        	______________________;
						else 
                          {
                        	   float temp=1;
                               ______________________;
                               for( j=0; j<count; j++){
                                   temp /= 10; 
							}
                               ______________________;
						}
					}
		     }
        }
        else break;
    }    
	if(!isPositive)
		_____________________;
	printf("%lf",result);
}
```

15. 函数`insert(char str1[], char str2[], int idx)` 实现在字符串`str1` 中的第`idx` 个字符后插入字符串`str2` ，如下程序的输出为：`abkkkcd` 。请填空。

```c
void insert(char str1[], char str2[], int idx)
{
    char *p = str1, *q; int i = 0;
    for(i = 0; i < idx; i++)
        p++;
    while(*str2!='\0')
    {
        q = p;
        while(*q != '\0')
            __________;
        while(q >= p){
            *(q+1) = *q;
            __________;
        }
        q++; *q = *str2; str2++;
        ______________;
    }
}
int main()
{
    char a[10] = "abcd", b[5] = "zyx";
    insert(a,b,2);
    printf("%s", a);
}
```

###### 2012高考

16. 下面程序接受键盘上的输入，直到按回车键为止，然后将输入的字符串输出，输出时如果原输入字符是英文大写字母则转成小写字母输出，如果是小写字母则转成大写字母输出，如果有连续的一个以上的空格时只输出一个空格。

```c
int main()
{
    char cx, pre = '\0';
    while(______________ != '\n')
    {
        if(cx != ' ')
            if(cx >= 'a' && cx <= 'z')
                putchar(cx - 32);
            else if(cx <= 'Z' && cx >= 'A')
                _______________;
            else
                putchar(cx);
        else
            if(pre != ' ') putchar(cx);
        __________________;
    }
}
```

17. 下面程序输出结果是（        ）

```c
int main()
{
    char ch[2][5] = {"1981", "0921"}, *p[2];
    int i, j, s = 0;
    for(i = 0; i < 2; i++)
        p[i] = ch[i];
    for(i = 0; i < 2; i++)
        for(j = 1; j <= 3; j+=2)
            s = 10 * s + p[i][j] - '0';
    printf("%d", s);
}
```

###### 2011年高考

18. 以下函数的功能是：在指针数组表示的字符串列表中查找特定的字符，指针数组以NULL指针结束，如果找到返回TRUE，否则返回FALSE。程序中有两处错误，将错误的行号及正确语句填入答题卡相应位置，不得增行或删行。

```c
L1	#include<stdio.h>
L2	#include<string.h>
L3	#define TRUE 1
L4	#define FALSE 0
L5	int find_string(char** strings,char value)
L6	{
L7		char* cur_str;
L8		if(*strings==NULL)
L9			return FALSE;
L10		while((cur_str=*strings)!=NULL
L11		{
L12			while(cur_str!="\0")
L13				if(*cur_str++==value)
L14					return TRUE;
L15		}
L16		return FALSE;
L17	}
```

19. 会计记帐时通常要求大整数用逗号进行分隔，下列函数实现将以分为单位的数字字符串转变为以元为单位，具体输出格式如表1所示。请填空。

<img src="images/image-20210324204702342.png" alt="image-20210324204702342" style="zoom:67%;" />

```c
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	char* dollars(char const* src)
	{
		int len,lenl,i;
		char *dst,*resultp;
		if(NULL==src)
			return NULL;
		len=strlen(src);
		lenl=len+len/3+2;
		dst=(char*)malloc(lenl);
		if(!dst)
		{
			return NULL;
		}
		__________________________;
		*dst='￥';  
		if(len>=3)
		{
			int i;
			for(i=len-2;i>0;)
			{
				*dst++=*src++;
				if( ___________________________ )  
					*dst++=',';
			}
		}
		else{	*dst++='0';	}
		*dst++='.';
		_______________________________________ ;
		*dst++=len<1?'0':*src;
		*dst=0;
		return resultp;
	}
```

###### 2010年高考

20. 下列函数rtrin_str实现的是删除字符串str尾部的所有空格。

```c
char* rtrim_str(char* str)
{	
    int n=______________;
	if(n<1)  return 0;
	while(n>0)
	{    if(*(str+n)!=' ')
		{
	    	_____________;      
			break;
		}
		else
	    	_____________;      
	}
	return str;
}
```

###### 2008年高考

21. 下列给定程序中,函数fun()的功能是:从n个字符串中找出最长的那个串,并将其地址作为函数值返回｡

```c
#include <string.h>
#include <stdio.h>
#define N 4
#define M 50
char *fun(char(*q)[M])
{   int i; char *p;
    _________________________________;
    for(i=0;i<N;i++)
    	if(_________________________)
    		________________________;
    return p;
}
int main()
{   char str[n][m]={"pingpong","basketball","field hockey","softball"}; char *longest;int i;
    longest=fun(str);
    printf("\nthe longest string:\n");
    puts(longest);
}
```

###### 2007年高考

22. 下面程序的功能是：从字符串str中，删除所有字母c，不区分大小写。输入字符串`abcCdefcfCg` ，删除后的字符串为`abdefg`。程序有两处错误，请指出所在行并改正。 

```c
L1   int main()
L2   {
L3       char str[81]; 
L4       int i = 0, j = 0;
L5       gets(str);
L6       while(str[i] != '\0')
L7       {
L8           if(str[i]!='c' || str[i] != 'C')
L9               str[j] = str[i];
L10          i++;
L11      }
L12      str[j] = '\0';
L13      printf("删除后的字符串：%s", str);
L14  }
```
