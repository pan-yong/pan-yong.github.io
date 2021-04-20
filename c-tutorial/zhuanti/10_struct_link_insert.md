## 链表插入



###### 1. 插入一个结点到链表保持升序

```c
struct NumNode{
    int data;
    struct NumNode *next;
};
struct NumNode *insertToList(struct NumNode *head, int fdata)
{
    struct NumNode *p, *q;
    struct NumNode *newNode = (struct NumNode *)malloc(sizeof(struct NumNode));
    newNode->data = fdata;newNode->next = NULL;
    p = q = head;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    while(p != NULL && fdata > p->data){
        q = p;
        p = p->next;
    }
    // 在下面补全代码
    if(p){
        if(head == p){
            newNode->next = head;
            head = newNode;
        }
        else{
            q->next = newNode;
            newNode->next = p;
        }
    }
    else{
        q->next = newNode;
    }
    return head;
}
struct NumNode *insertToList(struct NumNode *head, int fdata)
{
    struct NumNode *p, *q;
    struct NumNode *newNode = (struct NumNode *)malloc(sizeof(struct NumNode));
    newNode->data = fdata;newNode->next = NULL;
    p = q = head;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    while(p->next != NULL && fdata > p->data){
        q = p;
        p = p->next;
    }
    // 在下面补全代码
    if(fdata <= p->data){
        if(p == head){
            newNode->next = head;
            head = newNode;
        }
        else{
            q->next = newNode;
            newNode->next = p;
        }
    }
    else{
        p->next = newNode;
    }
    return head;
}
struct NumNode *insertToList(struct NumNode *head, int fdata)
{
    struct NumNode *p, *q;
    struct NumNode *newNode = (struct NumNode *)malloc(sizeof(struct NumNode));
    newNode->data = fdata;newNode->next = NULL;
    p = q = head;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    if(fdata < head->data)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(p->next != NULL && fdata > p->next->data){
        q = p;
        p = p->next;
    }
    // 在下面补全代码
    newNode->next = p->next;
	p->next = newNode;
 
    return head;
}
```

###### 2. 头插入

```c
struct ListNode * AddAtHead( struct ListNode *head, int val)
{
    struct ListNode *p;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = head;
    head = p;
    return head;
}
```

###### 3. 尾插入

```c
struct ListNode * AddAtEnd( struct ListNode *head, int val)
{
    struct ListNode *p, *q;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = NULL;
    if(head == NULL)  
        head = p;
    else{
        q = head;
        while(q->next) 
            q = q->next;
        q->next = p;
    }
    return head;
}
```

###### 4. 插入在`index`位置

```c
#include<stdio.h>
struct ListNode{
	int val;
	struct ListNode* next;
};
struct ListNode *AddAtIndex(struct ListNode *head, int index, int val)
{
    int i = 1;
    struct ListNode *p , *q;
    
    if(index == 1){  // 插入到头 
    	q = (struct ListNode*)malloc(sizeof(struct ListNode));
        q->val = val;
        q->next = head;
        head = q;
        return head;
	}
    
    p = head;
    while(p && i < index - 1)  // 找第 index - 1 个结点
    {
        p = p->next;
        i++;
    }
    if(p)  	// q插入到 index 位置，也就是插入到p之后
    {
        q = (struct ListNode*)malloc(sizeof(struct ListNode));
        q->val = val;
        q->next = p->next;
        p->next = q;
    }
    else{
        printf("插入失败位置index=%d 不合法\n", index);
    }
    return head;    
}
void printList(struct ListNode *head)
{
	struct ListNode *p = head;
	while(p){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	int i = 0;
	struct ListNode *head = NULL;
	for(i = 1; i <= 5; i++)
	{
		head = AddAtIndex(head,1, i);
	}
	printList(head);
}
```

















