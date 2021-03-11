### 一、库函数

### 二、常见错误

### 三、历年高考题

1. （2020高考）下面程序的功能是把一个文件的内容拷贝到另一个文件，如果拷贝成功，则提示"File Copy Success!"。以下程序只允许修改两行。

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

   

2. （2019高考）下面程序功能是：输入一个整数n，建立链表，把0~n-1中整数作为链表结点键值并把链表内容保存到文件output.dat中。如果n=5，则文件中存储的内容为“0->1->2->3->4”。

   ```c
   #include<stdio.h>
   typedef struct ss{
       int data;
       _______________________;
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

3. （2018高考）下列程序的功能是把文件A的内容追加到文件B中。例如文件A为“I’m ten”,文件B为“I’m a student”,追加之后，文件B的内容为“I’m a student! I’m ten”。

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

4. （2017年高考）以下程序从键盘获取字符串输入，并将输入字符串追加写入C盘data.txt文件中去。以下程序只允许修改两行。

   ```c
   L1	int main()
   L2	{
   L3		FILE *fp;
   L4		char buf[100], *fileName="c:\\data.txt";
   L5		gets(buf);
   L6		if((fp=fopen(fileName,"w"))!=NULL)
   L7		{
   L8			puts(buf);
   L9			fclose(fp);
   L10		}
   L11	}
   ```

5. （2016年高考）学生的记录由学号和成绩组成，N名学生的数据己放入主函数中的结构体数组s中。 函数creat()的功能是把结构体数组中的数据写入到二进制文件record.dat中。函数f() 的功能是：把指定分数范围内的学生数据放在指针b所指的结构体中，分数范围内的学生人数由函数值返问。例如，输入的分数是60、69，则应当把分数在60〜69的学生数据输出，包含60分和69分的学生数据。

   ```c
   #include <stdio.h>
   #include <string.h>
   #define N 10
   ______________________
   { 
       char num[N];
   	int score;
   }SREC;
   int creat(SREC * std)
   { 
       FILE * fp;
       int i;
   	if((_________________________)==NULL)
   		return 0;
   	printf("\n output data to file! \n");
   	for(i=0;i<N;i++)
   		__________________________________
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

6. （2015年高考）下面程序运行结果是

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