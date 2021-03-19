## 2021湖南对口招生二轮联考

###### 一、选择题

20. sizeof(double)是（   C     ）

```c
A. 函数调用		B. double 表达式		C. int型表达式		D. 非法表达式
```

21. 下列C语言运算符中，优先级最低的是（    A    )

```c
A. ?:			B. ~				C. &&			   D. +
```

22. 凡是函数中未指定存储类别的局部变量，其隐含的存储类别是（   A  ）

```c
A. 自动(auto)			B.静态(static)		C.外部(extern)	D. 寄存器(register)
```



###### 三、综合应用题

30. 下列程序功能是从f:盘读取chengji.txt中的数据，计算每一个学生的总分，并按总分降序排序，将排序好的数据写入f:盘chengji2.txt，请填空（对学生总分排序时不考虑并列名次）。

```tex
10010	wang	88	77	66
10011	sun		56	42	33
10012	li		78	98	65
10013	zhao	92	84	64
```

```c
#include<stdio.h>
#include<stdlib.h>
#define N 4
int main()
{
    struct student{
        char num[6];
        char name[10];
        int chinese, math, english, total, mc;
    }stu[N], temp;
    FILE *fp;
    int i, j;
    
    if(___________________ == NULL){	// (fp = fopen("f:\\chengji.txt","r"))
        printf("cannot open file");
        exit(0);
    }
    for(i = 0; i < N; i++)
    {
        fscanf("%s%s%d%d%d", stu[i].num, stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english);
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }
    fclose(fp);		// 试题缺陷
    
    for(i = 0; i < ________; i++)					// N - 1
        for(j = ______; j < N - i - 1; j++)			 // 0
            if(stu[j].total < stu[j+1].total)
            {
                temp = stu[j]; stu[j] = stu[j+1]; stu[j+1] = temp;
            }
    for(i = 0; i < N; i++)
        stu[i].mc = i + 1;
    
    for(i = 0; i < N; i++)
        printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", stu[i].num, stu[i].name, stu[i].chinese, stu[i].math, stu[i].english, stu[i].total, stu[i].mc);
    
    if((fp = fopen("f:\\chengji2.txt", "w"))==NULL){
        printf("cannot open file");
        exit(0);
    }
    for(i = 0; i < N; i++)
        fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d\t%d\n", stu[i].num, stu[i].name, stu[i].chinese, stu[i].math, stu[i].english, stu[i].total, stu[i].mc);
    __________________;			// fclose(fp)	
    return 0;
}
```

###### 四、程序分析题

32. 阅读下面程序，写出运行结果

    （1）下面程序运行结果是(               )

    ```c
    #include<stdio.h>
    #define 	BOT		(-2)
    #define		TOP		(BOT+5)
    #define		PRI(arg)	printf("%d\t", arg)
    #define		FOR(arg)	for(; (arg); (arg)--)
    int main()
    {
        int i = BOT, j = TOP;
        FOR(j)
            switch(j)
            {
                case 1:PRI(i++);
                case 2:PRI(j);break;
                default:PRI(i);
            }
    }
    // -2 2 -2 1
    ```

    （2）下面程序运行结果是(               )

    ```c
    #include<stdio.h>
    #include<string.h>
    int main()
    {
        char p[20] = {'a', 'b', 'c', 'd'}, q[]={"abc"};
        char r[]="abcde";
        strcpy(p+strlen(q), r);strcat(p,q);
        printf("%d %d\n",sizeof(p), strlen(p));
    }
    // 20  11
    ```

    （3）下面程序运行时，若输入119（空格）85（回车），则输出结果是(               )

    ```c
    #include<stdio.h>
    int gcd(int a, int b)
    {
        if(a%b==0) return b;
        return gcd(b,a%b);
    }
    int main()
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n",gcd(a,b));
        return 0;
    }
    // 17
    ```

    （4）下面程序运行结果是(               )

    ```c
    #include<stdio.h>
    int main()
    {
        int i, j, k = 0;
        for(j = 11; j <= 30; j++)
        {
            if(k%10==0)
                printf("\n");
            for(i = 2; i < j; i++)
            {
                if(!(j%i))break;
                if(i >= j-1){
                    printf("%d\t", j);
                    k++;
                }
            }
        }
        return 0;
    }
    // 11      13      17      19      23      29
    ```

    （5）下面程序运行结果是(               )

    ```c
    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
        int *p;
        char *q1, *q2;
        p = (int *)malloc(sizeof(int));
        q1 = (char *)p;
        q2 = q1 + 1;
        *q1 = 'A';
        *q2 = 'B';
        printf("%d", *p);
        return 0;
    }
    // 16961
    // 一个int，有多个字节，在内存中存储规则是，高位数据放在高地址位置，低位数据放在低地址位置。
    // 十六进制的   0x4241
    // 上面malloc后要 *p = 0，否则 int 有四个字节，高位两个字节的数据是内存随机值，导致结果不唯一。
    ```

    33. 程序填空题。

        （1）下列程序功能是将一个十进制数转换为一个二进制数。

        ```c
        #include<stdio.h>
        void Dec2Bin(int m)
        {
            int bin[32], j;
            for(j = 0; m != 0; j++)
            {
                bin[j] = m%2;
                ________________;			// m = m / 2
            }
            for(; j != 0; j--)
                printf("%d",_______);		// bin[j-1]
        }
        int main()
        {
        	int n;
        	scanf("%d", &n);
        	Dec2Bin(n);
        }
        ```

        （2）下列程序功能是删除一个字符串中的数字字符。

        ```c
        #include<stdio.h>
        #include<string.h>
        #include<ctype.h>
        void f(char *s)
        {
            int i = 0;
            while(s[i] != '\0')
            {
                if(isdigit(s[i]))strcpy(_________);		// s+i, s+i+1
                ______	i++;						  // else
            }
        }
        int main()
        {
        	char str[80];
            gets(str);
            f(str);
            puts(str);
        }
        ```

        34. 阅读程序，修改程序中的错误，不得增行或删行，也不得修改程序结构。请指出错误代码所在行号，并给出改行修改后的程序代码。

            （1）级数求和题

            ```c
            L7	改为	t = -t*x/(i++);
            L3	改为	while(fabs(t) >= eps);
            ```

            （2）找最大值和次最大值交换放到最前面

            ```c
            L4	改为	void fun(int a[], int n)
            L10	改为	max2=max1;m2=m1;
            L14	改为	max2=a[k];m2=k;
            ```

###### 五、程序设计题

35. 下列程序的功能是输入10个学生的成绩，在输入的同时对链表进行排序，程序对学生的成绩按从高到低输出，要求用链表实现。请补充程序。

```c
#include<stdio.h>
#include<stdlib.h>
struct Stu
{
    int score;
    struct Stu *next;
};
typedef struct Stu Node;
int main()
{
    int i;
    Node *head, *p, *q;
    head = _______________; // (Node *)malloc(sizeof(Node))  // 创建头结点
    if(head == NULL){
        printf("Memory is not enough!");
        return 0;
    }
    head->next = NULL;
    
    for(i = 0; i < 10; i++)
    {
        p = (Node*)malloc(sizeof(Node));	// 创建一个新结点p
        if(p == NULL){
            printf("Memory is not enough!");
        	return 0;
        }
        printf("Input the %dth student's score:", i+1);
        scanf("%d", &p->score);			   // 输入成绩
        
        q = head;
        while(_____________)	//q->next != NULL // 遍历链表
        {
            if(q->next->score < p->score)//如果链表中某个成绩比当前输入的成绩小，就跳出循环
                break;					// 在其前面插入当前输入的成绩
            ___________;	//q = q->next // 继续遍历直到遍历的成绩比当前输入的小
        }
        p->next = q->next;//当前成绩插入到链表中比其小的成绩前面
        q->next = p;
        
        __________________; //p = head->next
        while(p!=NULL)
        {
            printf("%d ",p->score);
            p = p->next;
        }
    }
    p = head;
    while(p->next != NULL)	//释放链表
    {
        q = p->next;
        p->next = q->next;
        _______________;	// free(q)
    }
    free(head);
    return 0;
}
```

