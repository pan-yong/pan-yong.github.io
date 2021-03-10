## 文件

1. 把文本文件rczz01.txt中的内容读出来，输出到屏幕。

``` c
#include<stdio.h>
int main()
{
	FILE *fp;
	char c;
	if((fp = fopen("rczz01.txt", "r")) == NULL)
	{
		printf("error");
		exit(1);
	}
	while( (c=fgetc(fp)) != EOF)
		printf("%c",c);
	fclose(fp);
	return 0;
} 
```

