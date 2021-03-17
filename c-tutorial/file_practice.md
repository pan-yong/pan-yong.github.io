## 文件练习

1. 把文本文件rczz01.txt中内容输出在屏幕。

```c
#include<stdio.h>
int main()
{
	FILE *fp;
	char c;
	if((___________________________) == NULL)ie
	{
		printf("error");
		exit(1);
	}
	while( (c=__________________) != EOF)
		printf("%c",c);
	fclose(fp);
	return 0;
} 
```

2. 从键盘输入一串字符，写入到li2.txt文件当中去，直到输入#结束。

```c
#include<stdio.h>
int main()
{
	FILE *fp;
	char c;
	if((fp=fopen("li2.txt",_____)) == NULL)
	{
		printf("error");
		exit(1);
	}
	while((c=getchar()) != '#')
		____________;
	fclose(fp);
	return 0;
}
```

3. 从文件li3.txt里，读取一行字符串，输出到屏幕。

```c
#include<stdio.h>
int main()
{
	FILE *fp;
	char str[128];
	if((fp=fopen("li3.txt","r"))==NULL)
	{
		printf("error");
		exit(1);
	}
	__________________________________
	puts(str);
	fclose(fp);
	return 0;
}
```

4. 【例4】从键盘输入一行字符，写入到文件li4.txt中。

```c
#include<stdio.h>
int main()
{
	FILE *fp;
	char str[128];
	gets(str);
	if((fp=fopen("li4.txt","w")) == NULL)
	{
		printf("error");
		exit(1);
	}
	____________________;
	fclose(fp);
	return 0;
}
```

5. 【例题5】从键盘输入10个整数，以文本形式，写入到li5.txt中

```c
#include<stdio.h>
int main()
{
	int i, x;
	FILE *fp;
	if((fp=fopen("li5.txt","w"))==NULL)
	{
		printf("error");
		exit(1);
	}
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &x);
		_____________________________;
	}
	fclose(fp);
	return 0;
}
```

6. 【例题6】从li5.txt文本文件中，读出10个整数，输出到屏幕。

```c
#include<stdio.h>
int main()
{
	int i, x;
	FILE *fp;
	if((fp=fopen("li5.txt","r"))==NULL)
	{
		printf("error");
		exit(1);
	}
	for(i = 0; i < 10; i++)
	{
		_______________________________;
		printf("%d\n",x);
	}
	fclose(fp);
}
```

7. 把一个浮点数数组以二进制方式写入文件fc.dat中。

```c
#include<stdio.h>
int main()
{
	FILE *fp;
	if((fp=fopen("fc.dat","wb"))==NULL)
	{
		printf("error");
		exit(1);
	}
	float a[6] = {15.2,-24.3, 5.04, 0.71, 50.6, 50.5};
	____________________________________________
	fclose(fp);
	return 0;
}
```

8. 从二进制文件fc.dat中读出6个浮点数到数组，然后输出到屏幕。

```c
#include<stdio.h>
int main()
{
	int i;
	float b[6];
	FILE *fp;
	if((fp=fopen("fc.dat","rb"))==NULL)
	{
		printf("error");
		exit(1);
	}
	_______________________________________________
	for(i = 0; i < 6; i++)
		printf("%.2f ", b[i]);
	fclose(fp);
	return 0;
}
```

9. 输入三个学生信息（姓名、分数），保存到二进制文件fd.dat中。然后，从fd.dat中读出三个学生信息（姓名，分数），输出分数最高者的姓名和分数

```c
#include<stdio.h>
#define N 3
typedef struct node{
	char name[64];
	int  score;
}STU;
int main()
{
	STU s, a[N];
	int i,min_i;
	FILE *fp;
	if((fp=fopen("fd.dat","wb"))==NULL){
		printf("error");
		exit(1);
	}
	for(i = 0; i < N; i++)
	{
		scanf("%s %d", s.name, &s.score);
		________________________________    // 写文件
	}
	fclose(fp);
    if((fp=fopen("fd.dat","rb"))==NULL)
	{
		printf("error");
		exit(1);
	}
	____________________________________;   //  读文件
	fclose(fp);
	
	for(min_i = 0, i = 1; i < N; i++)
		if(a[i].score > a[min_i].score)
			min_i = i;
	printf("%s %d", a[min_i].name, a[min_i].score);

}
```

