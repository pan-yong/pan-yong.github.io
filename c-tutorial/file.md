## 文件

[TOC]



#### 一、库函数

##### FILE *fopen( const char * filename, const char * mode );

##### int fclose( FILE *fp );

##### int fgetc(FILE \*stream);

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

##### int fputc( int c, FILE *fp );

把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符，如果发生错误，则会返回 **EOF**。

##### char *fgets( char *buf, int n, FILE *fp );

##### int fputs( const char *s, FILE *fp );

##### int fscanf(FILE *stream, const char *format, ...);

##### int fprintf(FILE *stream, const char *format, ...);

##### size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

##### size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);



#### 二、常见错误

#### 三、历年高考题

1. （2018高考）下列程序的功能是把文件A的内容追加到文件B中。例如文件A为“I’m ten”,文件B为“I’m a student”,追加之后，文件B的内容为“I’m a student! I’m ten”。

```c
#include<stdio.h>
int main()
{
    _______________________;
    char ch;
    if((fp1 = fopen("A.txt","r")) != NULL)
    {
        if((fp2 = fopen("B.txt","a")) != NULL)
        {
            while((ch=fgetc(fp1)) != EOF)
                _____________________;
            fclose(fp1);
            fclose(fp2);
        }
        else{
            printf("file B can not be opened\n");
            _______________;
            exit(0);
        }
    }
    else{
        printf("file A can not be opened\n");
        exit(0);
    }
}
```



2. （2019高考）下面程序功能是：输入一个整数n，建立链表，把0~n-1中整数作为链表结点键值并把链表内容保存到文件output.dat中。如果n=5，则文件中存储的内容为“0->1->2->3->4”

```C
#include<stdio.h>
typedef struct ss{
    int data;
    _____________;
}NODE;
void fun(int n, char *filename)
{
    NODE *h, *p, *s;
    ______________________;
    int i;
    h = p = (NODE *)malloc(sizeof(NODE));
    h->data = 0;
    for(i = 1; i < n; i++)
    {
        s = (NODE *)malloc(sizeof(NODE));
        s->data = i;
        __________________;
        p=p->next;
    }
    p->next = NULL;
    
    if((fp = fopen(filename,"w"))==NULL)
    {
        printf("Can not open output.dat!\n");
        exit(0);
    }
    ________________________;
    while(p)
    {
        fprintf(pf, "%3d", p->data);
        if(p->next != NULL)
            fprintf(pf, "->");
        p = p->next;
    }
    fprintf(pf,"\n");
    fclose(fp);
    
    p = h;
    while(p)
    {
        s = p;
        p = p->next;
        ____________________; /*释放分配的内存空间*/
    }
}

int main()
{
    char *filename = "output.dat";
    int n;
    scanf("%d", &n);
    fun(n, filename);
    return 0;
}
```



3. （2020高考）下面程序的功能是把一个文件的内容拷贝到另一个文件，如果拷贝成功，则提示"File Copy Success!"。以下程序只允许修改两行。

```c
L1    #include<stdio.h>
L2    int main()
L3    {
L4        FILE *fpSrc;  /*源文件*/
L5        FILE *fpDes;  /*目标文件*/
L6        int ch;
L7        if((fpSrc=fopen("src.txt", "r"))==NULL){
L8            printf("File Cannot Open!");
L9            exit(0);
L10       }
L11       if((fpDes=fopen("des.txt", "r"))==NULL){
L12           printf("File Cannot Open!");
L13           exit(0);
L14       }
L15       while((ch=fgetc(fpSrc))!=EOF)
L16           if((fputs(ch,fpSrc))==EOF)
L17               return 0;
L18       printf("File Copy Success!");
L19       return 0;
L20   }
```

4. (2009高考)以下程序的功能是：输入某公司50名职员的工号、姓名和地址并存入名为“company.txt”的磁盘文件。请将正确的内容填入答题卡相应位置中，使程序完整。

   ```c
   #include<stdio.h>
   struct Employee
   {
       int EmpId;
       char EmpName[10];
       char EmpAdd[30];
   }Emp[50];
   void save()
   {
       ________________;
       int i;
       if((fp = fopen("company.txt", "wb"))==NULL){
           printf("cannot open file\n");
           return ;
       }
       for(i = 0; i < 50; i++)
       {
           if( fwrite(_______________) != 1)
               printf("file write error\n");
       }
       fclose(fp);
   }
   int main()
   {
       int i;
       for(i = 0; i < 50; i++)
           scanf("%d,%s,%s",__________,Emp[i].EmpName,Emp[i].EmpAdd);
       save();
       return 0;
   }
   ```

   

5. （2010年高考）设文件studs.dat中存放着学生的基本信息，其基本信息用结构体来描述。以下程序的功能是：输入要读取的学生人数，利用malloc动态分配内存来存储从文件中读取的学生信息（以方便进一步管理），并输出读取的学号，姓名，专业。请将正确的内容填入答题卡的相应位置上，使程序完整。

```c
#include<stdio.h>
#include<stdlib.h>
struct student{
    long int num;
    char name[10];
    char major[10];
};
FILE *fp;
int main()
{
    struct student st, *pst;
    int i, num, realnum;
    printf("请输入读取的学生数：");
    scanf("%d", &num);
    pst = (struct student*)malloc(____________);
    if(!pst) return ;
    fp = fopen("studs.dat", "rb");
    if(NULL == fp){
        ______________________;
        return ;
    }
    realnum = 0;
    printf("%s\t%s\t%s\n", "number", "name", "major");
    /*文件包含的学生数量可能少于输入的人数*/
    for(i = 0; i < ___________; i++)
    {
        fread(pst+i, sizeof(struct student), 1, fp);
        realnum++;
        ______________________;
        printf("%d\t%ld\t%s\t%s\n", realnum, st.num, st.name, st.major);
    }
    free(pst);
    fclose(fp);
}
```

6. (2011年高考)随着信息化进程的不断推进，数据的安全性越来越受到人们的重视，数据加密技术是保证数据安全的重要手段。编程实现对C盘根目录下名为“new.dat”文件的数据进行加密，加密方式是将“new.dat”文件中每个字符与字符A进行异或运算，运算后的加密数据存储到“new.dat”文件中。

```c
#include<stdio.h>
int main()
{
    char ch;
    FILE *fp;
    fp = fopen("C:\\new.dat", "r+");
    if(fp == NULL){
        printf("Cannot open new.dat file.\n");
        return ;
    }
    while((ch=fgetc(fp)) != EOF)
    {
    	ch = ch ^ 'A';
    	fseek(fp,-1,1);
    	fputc(ch,fp);
    	fseek(fp,0,1);  //  当fputc和fgetc交叉的时候要首先使用fseek确定操作的位置
    }
    fclose(fp);
    return 0;
}
```

7. （2013年高考）下面程序从文本文件test.txt逐个读入字符，并显示在屏幕上。

```c
#include<stdio.h>
int main()
{
    FILE *fp;
    char ch, *filename = "test.txt";
    if((fp=_______(filename,"r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    while(!______(fp))
    {
        ch = fgetc(fp);
        if(ch != EOF) putchar(ch);
    }
    fclose(fp);
    return 0;
}
```

8. （2015年高考）下面程序运行结果是（        ）

```c
#include<stdio.h>
int main()
{    
    FILE *fp;
    int x[6]={0,1,2,3,4,5},i;
    fp=fopen("test.dat","wb");
    fwrite(x,sizeof(int),3,fp);
    rewind(fp);
    fread(x,sizeof(int),3,fp);
    for(i=0; i<6; i++)
         printf("%d",x[i]);
    fclose(fp);
    return 0;
}
```

9. （2016年高考）学生的记录由学号和成绩组成，N名学生的数据己放入主函数中的结构体数组s中。 函数creat()的功能是把结构体数组中的数据写入到二进制文件record.dat中。函数f() 的功能是：把指定分数范围内的学生数据放在指针b所指的结构体中，分数范围内的学生人数由函数值返问。例如，输入的分数是60、69，则应当把分数在60〜69的学生数据输出，包含60分和69分的学生数据。

```c
#include <stdio.h>
#include <string.h>
#define N 10
________________
{ 
    char num[N];
	int score;
}SREC;
int creat(SREC * std)
{ 
    FILE * fp;
    int i;
	if((_____________)==NULL)
		return 0;
	printf("\n output data to file! \n");
	for(i=0;i<N;i++)
		_____________
	fclose(fp);
	return 1;
} /*creat()函数结束*/

int f(SREC *a，SREC *b，int l,int h);

int main( )
{ 
    SREC s[N]={{"001"，85}，{"002”，76}，
				{"003"，69}，{"004",85}，{"005"，96}，
				{"006"，72}，{"007"，56}，{"008"，87}，
				{"009"，91}，{"010"，45}};
	SREC h[N]; /*h用来存放满足分数条件范围内的学生数据*/
	int i,n,low,heigh,t; /* n用来存放满足分数条件范围内的学生人数*/
	int result;	/* low、heigh分别用來存放分数范围的下界与上界*/
               
	result=creat(s); /* result表示文件写入操作是否成功*/
	if(result)
	{ 
        printf("\n low=");scanf("%d",&low);
		printf("\n heigh=");scanf("%d",&heigh);
		if(heigh<low)
		{ 
            t=heigh;heigh=low;low=t; 
        }
		n=_________________;
		if(n==0)
			printf("there are no scores between %d—%d:\n",low,heigh);
		else
		{ 
            printf("the scores between %d—%d:\n",low,heigh);
			for(i=0;i<n;i++)
				printf("%s %4d \n",h[i].num,h[i].score);
			printf("\n"); 
     	}
	}
	else
		printf("Fail!\n”)； 
    return 0;
}/*main( )函数结束*/
               
int f(SREC *a，SREC *b,int l，int h) /* b用来存放满足分数条件范围内的学生数据*/
{ 
    int i,j=0，n;	/* l、h分别用来存放分数范围的下界与上界*/
	for(i=0;i<N:i++)
	{ 
        if(a[i].score>=l && a[i].score<=h)
    	{
            _____________________;
     		b[j].score=a[i].score;
			j++;
    	}
	}
	return j;
}
```



10. （2017年高考）以下程序从键盘获取字符串输入，并将输入字符串追加写入C盘data.txt文件中去。以下程序只允许修改两行。

```c
L1	void main()
L2	{
L3		FILE *fp;
L4		char buf[100], *fileName="c://data.txt";
L5		gets(buf);
L6		if((fp=fopen(fileName,"w"))!=NULL)
L7		{
L8			puts(buf);
L9			fclose(fp);
L10		}
L11	}
```

