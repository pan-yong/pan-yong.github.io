## [搜索插入位置](https://leetcode-cn.com/leetbook/read/array-and-string/cxqdh/)

方法一

```c
int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    while(i < numsSize && nums[i] < target)
        i++;
    return i;
}
```

方法二

```c
int searchInsert(int* nums, int numsSize, int target){
    int i = numsSize - 1;
    while(i >=0 && nums[i] >= target)
        i--;
    return i+1;
}
```

方法三

```c
int searchInsert(int* nums, int numsSize, int target)
{
   int left = 0, right = numsSize - 1, mid, ans;
   while(left <= right)
   {
       mid = (left + right) / 2;
       if(nums[mid] < target){
           ans = mid + 1;
           left = mid + 1;
       }
       else //if(nums[mid] >= target)
       {
           ans = mid;
           right = mid - 1;
       }
   }
   return ans;
}
```

