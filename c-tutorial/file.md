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

   