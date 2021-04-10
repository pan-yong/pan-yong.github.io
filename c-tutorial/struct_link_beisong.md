## 链表的创建、结点的删除

1. 写一个函数，创建n个结点的链表，返回链表的第一个节点地址。

```c
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; struct node *next;
};
struct node *create(int n)  // 尾插入算法
{
    struct node *head = NULL; // 链表头
    struct node *p;  // 链表尾
    struct node *q;  // 新结点
    int i;
    for(i = 1; i <= n; i++)
    {
        q = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        if(head == NULL) head = p = q;
        else{
            p->next = q;  // q插入到p的后面
            p = q;		 //  p始终指向链表尾
        }
    }
    p->next = NULL;		// 链表结束标识
    return head;
}

struct node *create2(int n)  // 头插入
{
    struct node *head = NULL;  // 链表头
    struct node *q ;  		  //  新结点
    while(n--)
    {
        q = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = head;
        head = q;
    }
    return head;
}
void print(struct node *h)
{
    while(h){
        printf("%4d", h->data);
        h = h->next;
    }
    printf("\n");
}
int main()
{   struct node *head = ____________________; // 创建10个结点的链表。
    print(head);
}
```

2. 已知head指向单链表的第一个结点，函数del的功能是删除值为num的结点。

```c
struct node *del(struct node *head, int num)
{
    struct node *p1, *p2;
    if(head)
    {
        p1 = head;
        while(____________________){
            p2 = p1; p1 = p1->next;
        }
        if(num == p1->data){
            if(p1 == head) _________________;
            else ___________________________;
            printf("delete : %d\n", num);
        }
        else printf("%d not been found!\n", num);
    }
    return head;
}

struct node *del2(struct node *head, int num)
{
    struct node *p1, *p2;
    if(head)
    {
        p1 = head;
        while(p1 && p1->data != num){
            p2 = p1; p1 = p1->next;
        }
        if(_________){
            if(p1 == head) _________________;
            else ___________________________;
            printf("delete : %d\n", num);
        }
        else printf("%d not been found!\n", num);
    }
    return head;
}

int main()
{
    struct node *head;
    head = create(10);
    print(head);
    __________________	// 删除链表中的数字1
    print(head);
    return 0;
}
```

