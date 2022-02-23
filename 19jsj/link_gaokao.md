## 链表高考题

- （2017年高考）编写程序用于从键盘逐个读取整数，并将整数按照升序插入链表，每插入一个数后将链表中的数据都输出一次，当输入整数0时结束插入。

```c
#include<stdio.h>
#include<stdlib.h>
struct NumNode{
    int data;
    struct NumNode *next;
};
struct NumNode *insertToList(struct NumNode *head, int fdata)
{
    struct NumNode *p, *q;
    struct NumNode *newNode = (struct NumNode *)malloc(sizeof(struct NumNode));
    newNode->data = fdata;
    newNode->next = NULL;
    p = head;
    q = head;
    if(head == NULL)
    {
        _______________;
        return head;
    }
    while(p != NULL && fdata > p->data){
        q = p;
        p = p->next;
    }
    if(p != NULL)
    {
    	if(head == p){
            _____________________;   // newnode->next = head; head = newnode;
        }
        else{
            q->next = newNode;		// q->next = newnode; 
        }
        _________________________;   // newnode->next = p;
    }
    else
    {
        _________________________;  // q是尾结点   q->next = newnode;
    }
    return head;
}

void printList(struct NumNode *head)
{
    struct NumNode *p = head;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct NumNode *head = NULL;
    int i;
    scanf("%d", &i);
    while( i != 0)
    {
        _________________;
        printList(head);
        scanf("%d", &i);
    }
    return 0;
}
```

