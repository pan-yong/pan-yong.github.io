## Week01 Homework

[TOC]

#### 1. 听课笔记

##### 数组

###### 合并有序数组

主体思路和细节分开，这个思路很赞。简单一句话，听后觉得这个思路很简单，但是这样简洁的表达，我做不到。

 ```c
// 举例：
// 合并有序数组
// 主体思路：从后往前分别扫描nums1, nums2, 大的数放到nums1尾
// 细节：扫描数组时，注意边界
void merge(int* nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int k = n + m - 1;
    int i = m - 1;
    int j = n - 1;
    for(; k >= 0; k--)
    {
        if( j < 0 || i>=0 && nums1[i] > nums2[j])
            nums1[k] = nums1[i--];
        else
            nums1[k] = nums2[j--];
    }
}
 ```



###### 删除有序数组中的重复项

```c
// 主体思路：从第2个元素开始，到前面去搜索，有重复项直接跳过，没有重复项保留到数组。
int removeDuplicates(int *nums, int numsSize)
{
    int i, j, k = 1;
    for(i = 1; i < numsSize; i++)
    {
        for(j = 0; j < k; j++)
            if(nums[i] == nums[j])
                break;
        if(j >= k)
            nums[k++] = nums[i];
    }
}

// 老师的思路更清晰：相邻不相等的,保留。
int removeDuplicates(int *nums, int numsSize)
{
    int n = 0, i;
    for(i = 0; i < numsSize; i++)
        if(i == 0 || nums[i] != nums[i-1])
            nums[n++] = nums[i];
    return n;
}

```

##### 链表

原来，带头节点的链表，这个头结点是保护节点，以免出现NULL的操作。

###### 反转链表

```c
struct ListNode* reverseList(struct ListNode *head)
{
    struct ListNode *top = NULL, *p = head, *q;
    while(p)
    {
        q = p->next;
        p->next = top;
        top = p;
        p = q;
    }
    return top;
}
// 要求：5分钟之内  写出来
```

###### K个一组翻转链表

```c
struct ListNode* reverseList(struct ListNode *p, struct ListNode *r)
{
    struct ListNode *top = p, 
}
```

我们可以背模块，但是不要背题。

#### 2. 阅读作业

#### 3. 刷题作业



###### 加一

https://leetcode-cn.com/problems/plus-one/

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int *result = (int *)malloc(sizeof(int)*(digitsSize+1));
    int i;
    for(i = digitsSize)
    
    return result;
}
```

