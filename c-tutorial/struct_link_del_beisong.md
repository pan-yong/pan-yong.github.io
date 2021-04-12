1. 已知head指向单链表的第一个结点，函数del的功能是删除值为num的结点。

```c
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; struct node *next;
};
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



