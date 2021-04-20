## 链表删除

###### 2020年高考题

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
{
    int i = 0;
    struct Node *head = NULL;
    for(i = 0; i < 5; i++)
        head = AppNode(head);
    DisNode(head);
    head = DelNode(head, 33);
    DisNode(head);
    return 0;
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

```c
struct Node *DelNode(struct Node *head, int nodeData)
{
    struct Node *p = head, *pr = head;
    if(head == NULL){
        printf("No Linked Table!\n");
        return head;
    }
    while( p && nodeData != p->data){
        pr = p; 
        p = p->next;
    }// 1) p == NULL 2)nodeData == p->data
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

```c
struct Node *DelNode(struct Node *head, int nodeData)
{
    struct Node *p = head, *pr = head;
    if(head == NULL){
        printf("No Linked Table!\n");
        return head;
    }
    if(nodeData == head->data)
        head = head->next;
    while( p->next && nodeData != p->next->data){
        p = p->next;
    }
    if(________________)    // p->next
    {
        ______________________;// q = p->next; p->next = q->next; free(q);
    }
    else
        printf("The Node has not found!");
    return head;
}
```

