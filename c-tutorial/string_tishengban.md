###### 2019年高考

1. 下面程序运行结果是（             ）

```c
int fun(char *s)
{   char *t = s;
    while(*t++);
    return t - s;
}
int main()
{
    char t[8] = "123456";
    printf("%d", fun(t));
}
```

2. 下面程序运行结果是（             ）

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

3. 下面程序运行结果是（             ）

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

4. 下面程序运行结果是（                ）

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

5. 下面程序运行结果是（              ）

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

6. 函数endsWith(char* str, char* substr)用于判断字符串str是否以子字符串substr结尾，是返回整数1，否返回整数0。以下程序只允许修改三行。

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

7. 下面程序运行结果是（              ）

```c
void f(char *p)
{
    char max, *q;int i = 0;
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

8. 下面程序运行结果是（              ）

```c
int main()
{   int i , x = 0, t = 1;char s[10] = "101010";
    for(i = strlen(s) - 1; i >= 0; i--, t <<= 1)
        if(s[i] != '0')
            x += t;
    printf("x=%d", x);
}
```

9. 下面程序输出结果是（            ）

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

10. 函数convertNum用于实现无符号十进制数到其它进制数的转换，转换结果的每一位以字符存储于字符数组s中（如十进制3转换为二进制后，数组s中存储的字符串为11），参数srclnt为待转换数据，d为转换的目标进制。函数convertNum转换成功返回l，失败返回0。以下程序只允许修改三行。

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

11. 下面函数，通过指针将一个字符串反向。如下程序的输出为：dcba。请填空。

```c
void strReverse(char *s)
{   char c, *p;
    ____________________; 
    while(*p!='\0')  p++;
    ____________________;
    while(s<=p)
    {  c=*s;*s=*p; *p=c; s++;
       _________________;
    }
}
main()
{   char a[10]="abcd";
    strReverse(a);
    printf("%s",a);
}
```

12. 输入一行文字，找出其中大写字母、小写字母、空格、数字及其它字符各有多少。请填空。

```c
int main()
{   char str[40],*p = str,sl=0,s2=0,s3=0,s4=0,s5=0;
    gets(str);
    while(*p)
    {    if(______________________________)  sl++;
         else if(_________________________)  s2++;
         else if(_________________________)  s3++;
         else if(_________________________)  s4++;
         else s5++;
         p++;
    }
    printf("大写字母：%d 小写字母：%d 数字：%d 空格：%d 其它：%d\n",s1, s2, s3, s4, s5);
}
```

