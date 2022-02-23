## 链表

<img src=".\images\link.png" alt="img" style="zoom: 25%;" />

##### 0. 结点的定义

```c
________ node{
    int num;
    __________ next;
};
```

##### 1. 结点的插入

- 新建结点`cur`  ： `struct node * cur = (struct node*)malloc(sizeof(struct node));`

  <img src=".\images\insert.png" alt="img" style="zoom: 25%;" />

- 将`cur`的`next`链接到`prev`的下一个结点`next`：`cur->next = prev->next;`

  <img src=".\images\insert2.png" alt="img" style="zoom: 25%;" />

- 将`prev`的`next`链接到`cur`：`prev->next = cur;`

  <img src=".\images\insert3.png" alt="img" style="zoom: 25%;" />

  示例：

  <img src=".\images\insert-demo.png" alt="img" style="zoom: 25%;" />

- 在链表开头插入：我们使用头结点`head`来代表整个列表

  - 初始化一个值为`9`的新结点`cur` ，链接到当前链表的前面：`cur->next = head;`

    <img src=".\images\insert-head.png" alt="img" style="zoom: 25%;" />

  - 指定新结点`cur`为新的头结点：`head = cur;`

    <img src=".\images\insert-head2.png" alt="img" style="zoom: 25%;" />

##### 2. 结点的删除

- 找到要删除结点`cur`的前驱`prev`：`prev = head; while(prev->next != cur) prev = prev->next;`

  <img src=".\images\findprev.png" alt="img" style="zoom: 25%;" />

- 将`prev`的`next`的指向`cur`的`next`：`prev->next = cur->next;`

  <img src=".\images\linkdel.png" alt="img" style="zoom: 25%;" />

- 释放`cur`结点内存：`free(cur); cur = NULL;`

- 删除第一个结点：`cur = head; head = head->next; free(cur);`

  <img src=".\images\screen-shot-2018-04-19-at-130024.png" alt="img" style="zoom: 25%;" />

  <img src=".\images\screen-shot-2018-04-19-at-130031.png" alt="img" style="zoom: 25%;" />

##### 3. 创建一个有n个结点的单链表

```c
________________ create(int n)
{   
    struct node *head, *p1, *p2;
    head = ______________________________________;
    scanf("%d", &head->num); head->next = NULL;
    p2 = head;
    while(--n){
        p1 = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &p1->num);
        p1->next = p2->next;  // 尾插入：p1插入到p2的尾部（p2始终是链表尾）
        _____________________;  
        p2 = p1;
    }
    return head;
}
```

##### 4. 链表的遍历

```c
void printlink(struct node *head)
{   struct node *p = head;
    while(p){
        printf("%d ", p->num);
        _____________________;
    }
}
```

##### 高考题

- （2013年高考）以下程序的功能是：读入一行字符，以回车结束，按输入时的逆序使用单向链表进行存储，先输入的位于链表尾，然后再遍历输出链表，如输入`abc↙`，链表结构如图所示，程序最后输出`cba`。

<img src=".\images\wps1.png" alt="img" style="zoom: 50%;" />

```c
#include<stdio.h>
struct node
{
	char value;
	struct node *link;
};
int main()
{
	struct node *top,*p;
	char c;
	top=NULL;
	while((c=getchar()) ____________ )
    {
    	p=(struct node *)malloc(sizeof(struct node));
    	p->value=c;
    	p->link=top;
     	__________________________________;
    }
    while(top)
    {
	    p=top;
    	top=top->link;
    	putchar(___________ );
    }
}
```

- (2020年高考)下面程序中定义了三个函数，其功能分别是添加链表结点、显示链表结点与删除来年表结点。如果添加的链表结点数据为“11，22，33，44，55”，则显示链表尾“11->22->33->44->55->End”。如果删除数据尾33的结点，则显示链表为“11->22->44->55->End”。请补充程序。

```c
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    _____________________;
};
struct Node *AppNode(struct Node *head);  // 添加结点
void   DisNode(struct Node *head);		 // 显示结点
struct Node *DelNode(struct Node *head, int nodeData);// 删除结点
int main()
{   int i = 0;
    struct Node *head = NULL;
    for(i = 0; i < 5; i++)
        head = AppNode(head);
    DisNode(head);
    head = DelNode(head, 33);
    DisNode(head);
}
struct Node *AppNode(struct Node *head)
{
    struct Node *p = NULL;
    _________________________;
    int data;
    p = _____________________;
    if(p == NULL){
        printf("No enough memory!");
        exit(0);
    }
    if(head == NULL)
        head = p;
    else{
        while(pr->next != NULL)
            pr = pr->next;
        pr->next = p;
    }
    pr = p;
    printf("input node data:");
    scanf("%d", &data);
    pr->data = data;
    pr->next = NULL;
    return head;
}
void DisNode(struct Node *head)
{
    struct Node *p = head;
    while(p != NULL){
        printf("%d->", p->data);
        p = p->next;
    }
    printf("End\n");
}
struct Node *DelNode(struct Node *head, int nodeData)
{
    struct Node *p = head, *pr = head;
    if(head == NULL){
        printf("No Linked Table!\n");
        return head;
    }
    while(nodeData != p->data && p->next != NULL){
        pr = p; 
        p = p->next;
    }
    if(________________)
    {
        if(p == head)
            head = p->next;
        else
            ______________________;
        free(p);
    }
    else
        printf("The Node has not found!");
    return head;
}
```

- （2014年高考）函数creatList()用于从键盘读入整数，并根据输入的顺序建立链表，当输入-1时结束键盘读取，链表创建完成，其中-1不存入链表，头节点不存储数据，在main函数中调用0 creatList()函数创建链表，随后遍历链表输出链表所保存的数据。以下程序只允许修改三行。

```c
Ll    #incIude <stdio.h>
L2    struct Node {
L3       int data;
L4       struct Node *next;
L5     };
L6    struct Node *creatList(){
L7        struct Node p, q, head;
L8        int a;
L9        head=(struct Node *) malloc(sizeof(struct Node));
L10       p=q=head;
L11       printf("Input an integer number,enter-l to end:\n");
L12       scanf("%d",&a);
L13       while(a!=-l){
L14          p=(struct Node *)malloc(sizeof(struct Node));
L15          p->data=a;
L16          q->next=p;
L17          q=p;
L18          p->next=NULL;
L19          scanf("%d",&a);
L20    }
L21    return head;
L22  }
L23  main(){
L24     struct Node *head，*p;
L25     head=creatList();
L26     p=head->next;
L27     while(p){
L28         printf("%d\n",p->data);
L29         p->next = p
L30     }
L31   }
```

- （2018年高考）下列程序的主函数中，通过函数调用，把N 名学生的成绩放入一个带头结点的链表中，h指向链表的头结点。函数fun的功能是：找出N名学生中的最高分并返回，请补充程序。

```c
#include<stdio.h>
#define N 8
struct slist{
    int s;
    _____________;
};
tyedef struct slist STREC;
int fun(STREC *h)
{   int max = h->s;
    while(____________){
        if( max < h->s )
            max = h->s;
        _________________;
    }
    return max;
}
STREC *creat(int *s)
{
    STREC *h, *p, *q; // h 表示链表头
    int i = 0;
    h = p = (STREC *) malloc(sizeof(STREC));
    p->s = 0;
    while( i < N)
    {
        q = (STREC *)malloc(sizeof(STREC));
        q->s = s[i++];
        p->next = q;
        __________________________________;
    }
    p->next = NULL;
    return h;
}
int main()
{   int s[N] = {85, 76, 69, 85, 91, 72, 64, 87}, max;
    STREC *head;
    ________________________________;
    max = fun(head);
    printf("max=%d\n", max);
}
```

## 联合体与枚举型

1. 下面程序输出结果是（            ）

```c
int main()
{   struct stu{ char name[10]; int age, sex;};
    printf("%d", sizeof(struct stu));
}
```

2. 下面程序输出结果是（            ）

```c
int main()
{   int a = 0x11223344;
    char *p = (char *)&a, b = *p, c = *(p+3);
    printf("%x %x",b, c);
}
```

3. 下面程序输出结果是（            ）

```c
int main()
{   union node{int a, char b;} x;
    x.a = 257;
    printf("%d", x.b);
}
```

4. 下面程序输出结果是（        ）

```c
int main()
{   enum Color{ red, blue, green, yellow=16, black, purple, pink};
    printf("%d %d", blue, purple);
}
```

## 文件

- `FILE * fp;`

- `FILE *fopen( const char * filename, const char * mode );`

  ```c
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

- `int fclose( FILE *fp );`

- `int fgetc(FILE *fp);`

-  `int fputc( int c, FILE *fp );`

##### 高考题

- （2020高考）下面程序的功能是把一个文件的内容拷贝到另一个文件，如果拷贝成功，则提示"File Copy Success!"。以下程序只允许修改两行。

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

- （2018高考）下列程序的功能是把文件A的内容追加到文件B中。例如文件A为“I’m ten”,文件B为“I’m a student”,追加之后，文件B的内容为“I’m a student! I’m ten”。

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

- （2017年高考）以下程序从键盘获取字符串输入，并将输入字符串追加写入C盘data.txt文件中去。以下程序只允许修改两行。

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

- （2013年高考）下面程序从文本文件test.txt逐个读入字符，并显示在屏幕上。

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

