## [寻找数组的中心索引](https://leetcode-cn.com/leetbook/read/array-and-string/yf47s/)

方法一

```c
int pivotIndex(int* nums, int numsSize)
{
    int piv, i, j, s1, s2;
    for(piv = 0; piv < numsSize; piv++)
    {
        for(i = 0, s1 = 0; i < piv; i++)
            s1 += nums[i];
        for(j = piv + 1, s2 = 0; j < numsSize; j++)
            s2 += nums[j];
        if(s1 == s2)
            return piv;
    }
    return -1;
}
```

方法二

```c
int pivotIndex(int* nums, int numsSize)
{
    int total = 0, i, s = 0;
    for(i = 0; i < numsSize; i++)
        total += nums[i];
    for(i = 0; i < numsSize; i++)
    {
        if(2*s + nums[i] == total)
            return i;
        s += nums[i];
    }
    return -1;
}
```

