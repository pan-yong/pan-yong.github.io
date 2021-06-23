## Homework01



###### 1. 合并有序数组

> 老师：写程序，主体思路和细节分开。这句话，很受启发。

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

###### 2. 删除有序数组中的重复项

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
// 注意细节：边界值i=0时的情形判断
int removeDuplicates(int *nums, int numsSize)
{
    int n = 0, i;
    for(i = 0; i < numsSize; i++)
        if(i == 0 || nums[i] != nums[i-1])
            nums[n++] = nums[i];
    return n;
}
```

###### 移动零

```c
// 主体思路：不是零的数据保留下来
void moveZeroes(int* nums, int numsSize){
    int i , n = 0;
    for(i = 0; i < numsSize; i++)
        if(nums[i] != 0)
            nums[n++] = nums[i];
    while(n < numsSize)
        nums[n++] = 0;
}
```

###### [加一](https://leetcode-cn.com/problems/plus-one/)

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int *result, i;
    
    for(i = 0; i < digitsSize; i++)
        if(digits[i] != 9)
            break;
    if(i >= digitsSize) // 全部是9
    {
        result = (int *) malloc(sizeof(int) * (digitsSize+1));
        memset(result,0, sizeof(int) * (digitsSize+1));
        *result = 1;
        *returnSize = digitsSize + 1;
        return result;
    }
    else{
        for(i = digitsSize - 1; i >= 0; i--)
            if(digits[i] == 9)
                digits[i] = 0;
        	else{
                digits[i] = digits[i] + 1;
                break;
            }
        *returnSize = digitsSize;   
        return digits;
    }
}

// 改进
// 整体思路：从个位开始加一，有进位继续加，没有进位结束。
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i;
    for(i = digitsSize - 1; i >= 0; i--)
    {
        digits[i]++;
        digits[i] %= 10;  
        if(digits[i] != 0){
            *returnSize = digitsSize;
            return digits;
        } 
    }
    *returnSize = digitsSize + 1;
    int* result = (int *)malloc(sizeof(int)*(*returnSize));
    memset(result,0, sizeof(int) * (*returnSize));
    *result = 1;
    return result;
}
```



> 原来，带头节点的链表，这个头结点是保护节点，以免出现NULL的操作。

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

###### 合并两个有序链表

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode*head = (struct ListNode*)malloc(sizeof(struct ListNode)), *p = head;
    head->next = NULL;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            p->next = l1;
            p = l1;
            l1= l1->next;
        }
        else{
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }
    if(l1)p->next = l1;
    if(l2)p->next = l2;
    return p = head->next, free(head), p;
}
```

###### 有效的括号

```c
// 思路：用数组来模拟栈，遇到左括号进栈，遇到右括号则检查和栈顶括号是否匹配
bool isValid(char * s)
{
    char stack[10001];
    int  slen = 0;
    while(*s)
    {
        if(*s == '(' || *s == '{' || *s == '[')
            stack[slen++] = *s;
        else if(*s == ')')
        {
            if(slen > 0 && stack[slen-1] == '(')
                slen--;
            else 
                return 0;
        }
        else if(*s == ']')
        {
            if(slen > 0 && stack[slen-1] == '[')
                slen--;
            else 
                return 0;
        }
        else if(*s == '}')
        {
            if(slen > 0 && stack[slen-1] == '{')
                slen--;
            else 
                return 0;
        }
        s++;
    }
    return slen == 0;
}

// 改进
```



###### K个一组翻转链表

```c
struct ListNode* reverseList(struct ListNode *p, struct ListNode *r)
{
    struct ListNode *top = p, 
}
```

> 我们可以背模块，但是不要背题。



##### 前缀和

###### [1248. 统计「优美子数组」](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/)

```c
int numberOfSubarrays(int* nums, int numsSize, int k)
{
    int s[50001] = {0}, count[50001] = {1,0}, i, j;

    for(i = 1; i <= numsSize; i++)
    {
        s[i] = s[i-1] + nums[i-1] % 2;
        count[s[i]]++;
    }    
    
    int ans = 0;
    /*
    for(i = 1; i <= numsSize; i++)
        for(j = 0; j < i; j++)
            if (s[i] - s[j] == k)
                ans++;
    */

    for(i = 1; i <= numsSize; i++)
        if(s[i] - k >= 0)
            ans += count[s[i] - k];
    return ans;
}
```



###### [304. 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)

```c
```















