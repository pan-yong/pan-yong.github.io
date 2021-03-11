## 文件

### 一、库函数

- #### FILE *fopen( const char * filename, const char * mode );

  打开文件函数，filename是文件名，mode是打开模式。文件打开成功返回文件指针，打开失败返回NULL。

  ```text
  模式		描述
  "r"	打开一个文件，只读，文件必须先存在。
  "w"	创建一个新的文件，只能写。如果文件存在，清除原内容。
  "a"	以追加写模式打开一个文件。如果文件不存在，创建一个新的。
  "r+"	打开一个文件，可读可写。文件必须先存在。
  "w+"	创建一个新文件，可读可写。
  "a+"	打开一个文件，允许读和追加写。若文件不存在创建一个新的。
      
  如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：
  "rb", "wb", "ab", "rb+", "wb+", "ab+"
  ```

- #### int fclose( FILE *fp );

  关闭文件，并释放用于该文件的所有内存。成功关闭文件，**fclose( )** 函数返回零，如果关闭文件时发生错误，函数返回 **EOF**。

- #### int fgetc(FILE \*fp);

  从文件的当前位置读一个字符，并把文件标识符移动一个字节。函数以无符号 char 强制转换为 int 的形式返回读取的字符，如果到达文件末尾或发生读错误，则返回 EOF。

  ```c
  #include <stdio.h>
  
  int main () 
  {
     FILE *fp;
     int c;
     int n = 0;
    
     fp = fopen("file.txt","r");
     if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
     } 
     do {
        c = fgetc(fp);
        if( feof(fp) ) {
           break ;
        }
        printf("%c", c);
     } while(1);
     fclose(fp);
     return(0);
  }
  ```

- #### int fputc( int c, FILE *fp );

  把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符，如果发生错误，则会返回 **EOF**。示例：

  ```c
  #include <stdio.h>
  
  int main () 
  {
     FILE *fp;
     int ch;
  
     fp = fopen("file.txt", "w+");
     for( ch = 33 ; ch <= 100; ch++ ) {
        fputc(ch, fp);
     }
     fclose(fp);
  
     return(0);
  }
  ```

- #### char *fgets( char *buf, int n, FILE *fp );

  从文件读一行字符串到buf，最多读n-1个字符，文件少于n-1个字符或提前遇到换行，读字符结束。n一般传字符数组buf的长度。读取成功，返回buf。读取失败，返回NULL。

  ```c
  #include <stdio.h>
  int main () 
  {
     FILE *fp;
     char str[60];
  
     /* opening file for reading */
     fp = fopen("file.txt" , "r");
     if(fp == NULL) {
        perror("Error opening file");
        return(-1);
     }
     if( fgets (str, 60, fp)!=NULL ) {
        /* writing content to stdout */
        puts(str);
     }
     fclose(fp);
     
     return(0);
  }
  ```

- #### int fputs( const char *s, FILE *fp );

  把字符串写入到文件，不包含\0。写文件成功返回非负数，错误返回EOF。

  ```c
  #include <stdio.h>
  int main () 
  {
     FILE *fp;
     fp = fopen("file.txt", "w+");
     fputs("This is c programming.", fp);
     fputs("This is a system programming language.", fp);
     fclose(fp);
     return(0);
  }
  ```

- #### int fscanf(FILE *stream, const char *format, ...);

  从文件格式化读取数据。函数返回，成功读取内容的个数。

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  int main () 
  {
     char str1[10], str2[10], str3[10];
     int year;
     FILE * fp;
  
     fp = fopen ("file.txt", "w+");
     fputs("We are in 2021", fp);
     
     rewind(fp);
     fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
     
     printf("Read String1 |%s|\n", str1 );
     printf("Read String2 |%s|\n", str2 );
     printf("Read String3 |%s|\n", str3 );
     printf("Read Integer |%d|\n", year );
  
     fclose(fp);
     
     return(0);
  }
  ```

- #### int fprintf(FILE *stream, const char *format, ...);

  格式化数据写文件。如果写文件成功，返回写入字符的个数。否则返回一个负数。

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  
  int main () 
  {
     FILE * fp;
  
     fp = fopen ("file.txt", "w+");
     int n = fprintf(fp, "%s %s %s %d", "We", "are", "in", 2021);
     printf("%d", n);
     fclose(fp);
     
     return(0);
  }
  ```

- #### size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

  从文件读取数据到ptr所指的内存中，size是每个元素的大小，nmemb是元素的个数。返回值是成功读取元素的个数。如果，成功读取元素个数和nmemb不相等，则读到文件尾，可通过feof函数检测。

  ```c
  #include <stdio.h>
  #include <string.h>
  
  int main () 
  {
     FILE *fp;
     char c[] = "this is 18jsj1";
     char buffer[100];
  
     /* Open file for both reading and writing */
     fp = fopen("file.txt", "w+");
  
     /* Write data to the file */
     fwrite(c, strlen(c) + 1, 1, fp);
  
     /* Seek to the beginning of the file */
     fseek(fp, 0, SEEK_SET);
  	
  	int n;
     /* Read and display data */
     n = fread(buffer, strlen(c)+1, 1, fp);
     //n = fread(buffer, sizeof(char), strlen(c)+1, fp);
     //n = fread(buffer, sizeof(char), strlen(c)+100, fp); 
     printf("%s\n", buffer);
     printf("n = %d\n", n);
     printf("feof=%d\n",feof(fp));
     fclose(fp);
     
     return(0);
  }
  ```

- #### size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

  把ptr指向内存里的数据写入到文件，size是每个元素的大小，nmemb是元素的个数。写文件成功，返回成功写入元素的个数。如果成功写入元素个数，和nmemb不相等

  ```c
  #include<stdio.h>
  
  int main () 
  {
     FILE *fp;
     char str[] = "This is 18jsj";
  
     fp = fopen( "file.txt" , "w" );
     
     int n;
     //n = fwrite(str , 1 , sizeof(str) , fp );
     n = fwrite(str ,sizeof(str) , 1 , fp );
     printf("%d\n",n);
     fclose(fp);
    
     return(0);
  }
  ```

- #### int fseek(FILE *stream, long int offset, int whence)

  设置文件指针位置，whence偏移开始的地方，**SEEK_SET** 表示从文件头开始，**SEEK_CUR** 表示从文件当前位置开始，**SEEK_END** 表示从文件尾开始，offset是偏移量。移动成功返回0，移动失败返回非零值。

  ```c
  #include <stdio.h>
  
  int main () 
  {
     FILE *fp;
  
     fp = fopen("file.txt","w+");
     fputs("This is 18jsj1.", fp);
    
     fseek( fp, 7, SEEK_SET );
     fputs(" C Programming Language", fp);
  
     fclose(fp);
     
     return(0);
  }
  ```

- #### void rewind(FILE *stream)

  设置文件指针指向文件最开始的地方。

- #### int feof(FILE *stream);

  检测是否读到文件尾。如果是返回非零，如果不是返回0。

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
   #include<stdio.h>
   #include<string.h>
   #define N 10
   _________________
   {
       char num[N];
       int score;
   }SREC;
   int creat(SREC *std)
   {
       FILE *fp;
       int i;
       if((___________________________) == NULL)
           return 0;
       printf("output data to file!\n");
       for(i = 0; i < N; i++)
           fclose(fp);
       return 1;
   }
   int f(SREC *a, SREC *b, int l, int h);
   int main()
   {
       SREC s[N]={ {"001"，85},{"002”，76},
   				{"003"，69},{"004",85},{"005"，96},
   				{"006"，72},{"007"，56},{"008"，87},
   				{"009"，91},{"010"，45}};
                  
       SREC h[N]; /*h用来存放满足分数条件范围内的学生数据*/
   	int i,n,low,heigh,t; /* n用来存放满足分数条件范围内的学生人数*/
   	int result;	/* low、heigh分别用來存放分数范围的下界与上界*/
       
       result=creat(s); /* result表示文件写入操作是否成功*/
       if(result)
       {
           printf("\n low=");scanf("%d",&low);
           printf("\n heigh=");scanf("%d",&heigh);
           if(heigh < low){
               t = height;height=low;low=t;
           }
           n = ________________________________;
           if(n == 0)
               printf("here are no scores between %d—%d:\n", low, heigh);
           else
           {
               printf("the scores between %d—%d:\n",low,heigh);
               for(i = 0; i < n; i++)
                   printf("%s %4d \n",h[i].num,h[i].score);
               printf("\n");
           }
       }
       else{
           printf("Fail!\n");
       }
       return 0;
   }
   int f(SREC *a, SREC *b, int l, int h)
   {
       int i, j = 0, n;/*l、h分别用来存放分数范围的下界与上界*/
       for(i = 0; i < N; i++)
       {
           if(a[i].score>=l && a[i].score<=h)
           {
               ____________________________;
               b[j].score=a[i].score;
               j++;
           }
       }
       return j;
   }
   ```

6. （2015年高考）下面程序运行结果是（        ）

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

8. (2011年高考)随着信息化进程的不断推进，数据的安全性越来越受到人们的重视，数据加密技术是保证数据安全的重要手段。编程实现对C盘根目录下名为“new.dat”文件的数据进行加密，加密方式是将“new.dat”文件中每个字符与字符A进行异或运算，运算后的加密数据存储到“new.dat”文件中。

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
       	fflush(fp);  //  当fputc和fgetc交叉的时候，要首先使用fseek或者fflush
       }
       fclose(fp);
       return 0;
   }
   ```

9. （2010年高考）设文件studs.dat中存放着学生的基本信息，其基本信息用结构体来描述。以下程序的功能是：输入要读取的学生人数，利用malloc动态分配内存来存储从文件中读取的学生信息（以方便进一步管理），并输出读取的学号，姓名，专业。请将正确的内容填入答题卡的相应位置上，使程序完整。

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

10. (2009高考)以下程序的功能是：输入某公司50名职员的工号、姓名和地址并存入名为“company.txt”的磁盘文件。请将正确的内容填入答题卡相应位置中，使程序完整。

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

