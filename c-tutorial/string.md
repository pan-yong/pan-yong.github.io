## 字符串

> 字符串：是以'\0'结束的字符数组。

1. 字符串常量

```c
#include<stdio.h>
#include<string.h>
int main()
{
    char s[] = "perfect";	// 字符串常量，末尾自动带\0
    printf("字符串长度：%d\n", strlen(s) );		// 不包含\0字符个数
    printf("字符数组大小：%d\n", sizeof(s));		// 包含\0所占内存大小
}
```

2. 字符串输入输出
   - scanf / printf %s
   - gets / puts
   - scanf / printf %c
   - getchar / putchar

```c
#include<stdio.h>
int main()
{
    // 1. scanf/pirntf %s 控制字符串  输入输出
    char s[10];
    scanf("%s", s);		// scanf  以空白字符作为输入结束符，不能接收空格、制表符等
    printf("%s\n", s);
    
    // 2. gets/puts 	   控制字符串   输入输出
    char s2[80];
    gets(s2);			// gets 输入，能够接收空格、制表符
    puts(s2);			// puts 输出，自动带换行
    
    // 3. scanf/printf %c 单个字符处理
    char s3[10];
    int i;
    for(i = 0; i < 10; i++)
        scanf("%c", &s[i]);
    
    for(i = 0; i < 10; i++)
        printf("%c", s[i]);
    
    // 4. getchar/ putchar 单个字符处理
    char s4[10];
    int j;
    for(j = 0; j < 10; j++)
        s4[i] = getchar();
    for(j = 0; j < 10; j++)
        putchar(s4[j]);
    
    return 0;
}
```

3. 字符串常用函数
   - strlen(s)
   - strcpy(s1, s2)
   - strcat(s1, s2)
   - strcmp(s1, s2)

