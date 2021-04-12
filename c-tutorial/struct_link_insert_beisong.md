## 链表的插入

1. 尾插法。写一个函数，创建n个结点的链表，返回链表的第一个节点地址。

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
void print(struct node *h)
{
    while(h){
        printf("%4d", h->data);
        h = h->next;
    }
    printf("\n");
}
int main()
{   
    struct node *head = create(10); // 创建10个结点的链表。
    print(head);
}
```

2. 头插法。写一个函数，创建n个结点的链表，返回链表的第一个节点地址。

```c
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; struct node *next;
};
struct node *create2(int n)  // 头插入
{
    struct node *head = NULL;  // 链表头
    struct node *q ;  		  //  新结点
    while(n--)
    {
        q = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = head;		// 新结点插入到头前面
        head = q;			// 更新链表头
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
{   
    struct node *head = create2(10); // 创建10个结点的链表。
    print(head);
}
```

3. 插入一个数到链表中，保持降序。

```c
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; struct node *next;
};
struct node *insert(struct node *head, int data)  
{
    struct node *newnode, *p, *pr;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    
    if(head == NULL) {	
        head = newnode;
        return head;
    }    
    
    // 找插入点
    p = head;
    while(p && newnode->data < p->data) //p遍历链表，降序插入，data小继续往后面找插入点
    {
        pr = p;		// pr 是p的前驱
        p = p->next;
    }
    // 循环结束时，p==NULL ||  newnode->data >= p->data
    // p==NULL 说明链表中所有数据都比data大，所以data插入到链表尾部，即，插入到p的前面（pr后）
    // newnode->data > p->data 说明data插入在p的前面（pr的后面）
    
    // 也就是无论怎样，newnode都是插入在，p的前面
    if(p == head)
    
    
}
```

