## 文件

[TOC]

#### int fgetc(FILE \*stream)

C 库函数 **int fgetc(FILE \*stream)** 从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。该函数以无符号 char 强制转换为 int 的形式返回读取的字符，如果到达文件末尾或发生读错误，则返回 EOF。示例：

``` c
#include<stdio.h>
int main()
{
	FILE *fp;
	char c;
	if((fp = fopen("rczz01.txt", "r")) == NULL)
	{
		printf("open file error.");
		exit(1);
	}
	while( (c=fgetc(fp)) != EOF)
		printf("%c",c);
	fclose(fp);
	return 0;
} 
```

