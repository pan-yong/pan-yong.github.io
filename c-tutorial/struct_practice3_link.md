## 单链表

> 不带头结点的单链表

###### 0. 结点的定义

```c
________ node{
    int num;
    __________ next;
};
```

###### 1. 创建一个有n个结点的单链表

```c
__________ create(int n)
{   struct node *head, *p1, *p2;
    if( n < 1) return NULL;
    head = ______________________________________;
    scanf("%d", &head->num); head->next = NULL;
    p1 = p2 = head;
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

```c
struct node *create2(int n)
{   struct node *head, *p1;
    if(n < 1) return NULL;
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &head->num); head->next = NULL;
    while(--n){
        p1 = ___________________________________;
        scanf("%d", &p1->num);
        _____________________; // 头插入：p1插入到head的前面
        head = p1;
    }
    return head;
}
```

###### 2. 遍历

```c
void printlink(struct node *head)
{   struct node *p = head;
    while(p){
        printf("%d ", p->num);
        _____________________;
    }
}
```

###### 3.查找

```c
// 在链表中查找值为data的结点，找到则返回它的前驱结点，失败则返回NULL
struct node *find(struct node *head, int data)
{   struct node *p = head, *pr;
    while(p && p->num != data){
        _________________;
        p = p->next;
    }
    if(p) return pr;
    else return NULL;
}
```

###### 4. 删除

```c
struct node *delte(struct node *head, int data)
{   struct node *p1, *p2;
    if(head == NULL) return NULL;
    if(head->num == data){
         head = head->next;
         return head;
    }
    p2 = head; 
    while(p2 && p2->num != data){
        p1 = p2;
        p2 = p2->next;
    }
    if(_________)
        p1->next = __________;
    else
        printf("没有找到要删除的结点\n");
    return head;
}
```

###### 5. 在一个升序链表中插入一个数仍保持升序

```c
struct node *insert(struct node *head, int data) // 在一个升序链表中插入一个数仍保持升序
{
    struct node *p1, *p2, *pr;
    p1 = (struct node*)malloc(sizeof(struct node));
    p1->num = data;
    if(__________){			   // 链表尾空，直接把p1作为链表头返回
        head = p1; p1->next = NULL; return head;
    }
    if(p1->data <= head->num){	// p1比头结点还小，插入到head前，p1作为新的头返回
        p1->next = ___________;
        head = p1;
        return head;
    }
    p2 = head;
    while(p2 && _________){  // 查找插入点（前驱）
        pr = ________;
        p2 = p2->next;
    }
    pr->next = _________;	// 在p2之前（也就是pr之后）插入p1结点
    p1->next = _________;
    return head;
}

struct node *insert2(struct node *head, int data)//在一个升序链表中插入一个数仍保持升序
{
    struct node *p1, *p2, *pr;
    p1 = (struct node*)malloc(sizeof(struct node));
    p1->num = data;
    if(__________){			   // 链表尾空，直接把p1作为链表头返回
        head = p1; p1->next = NULL; return head;
    }
    if(p1->data <= head->num){	// p1比头结点还小，插入到head前，p1作为新的头返回
        p1->next = ___________;
        head = p1;
        return head;
    }
    p2 = head;
    while(p2->next && p2->next-num <= data){  // 查找插入点（前驱）
        p2 = p2->next;
    }
    p1->next = _________;   // 在p2之后插入p1结点
    p2->next = _________;	
    return head;
}
```

###### 6. 将一个单链表反序

```c
// 原链表结点数据依次是“ 1 2 3 4 5”，逆序链表后节点数据依次为“5 4 3 2 1”
struct node*reverse(struct node *head)
{
    struct node *h, *p, *q;
    if(head == NULL) return NULL;
    h = NULL; 		// 逆序后的链表头
    q = head; 		// 依次从原链表取结点
    p = head->next;  // 遍历原链表每一个结点
    while(p){
        q->next = h; // 把q插入到链表头
        h = q;       // q作为新的链表头
        q = p;		// 依次从原链表中取结点
        p = p->next; // p遍历原链表中每一个结点
    }
    q->next = h; h = q;
    return h;
}
```

###### 7. 将两个升序链表合并，仍然保持为升序

```c
struct node*merge(struct node *h1, struct node *h2)
{
    struct node *head, *p;
    if(h1->num < h2->num){ head = h1; h1 = h1->next; }
    else {head = h2; h2 = h2->next;}
    p = head;
    while(h1&&h2)
    {
        if(h1->num < h2->num){
            p->next = h1;
            p = h1;
            h1 = h1->next;
        }
        else{
            p->next = h2;
            p = h2;
            h2 = h2->next;
        }
    }
    if(h1) p->next = h1;
    if(h2) p->next = h2;
    return head;
}
```

