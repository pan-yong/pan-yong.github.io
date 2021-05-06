## [最长公共前缀](https://leetcode-cn.com/leetbook/read/array-and-string/ceda1/)

方法一：暴力查找

```c
int getMinStrlen(char **str, int strsSize)
{
    int minlen, i , tmplen;
    minlen = strlen(str[0]);
    for(i = 1; i < strsSize; i++)
    {
        tmplen = strlen(str[i]);
        if(tmplen < minlen)
            minlen = tmplen;
    }
    return minlen;
}
int hasCommonPrefix(char *s1, char *s2, int len)
{
    int i;
    for(i = 0; i < len; i++)
        if(s1[i] != s2[i])
            return 0;
    return 1;
}
char *longestCommonPrefix(char ** strs, int strsSize)
{
	int len, i;
    if(strsSize <= 0) return "";
    len = getMinStrlen(strs, strsSize);
    for(; len > 0; len--)
    {
        for(i = 1; i < strsSize; i++)
            if(!hasCommonPrefix(strs[0], strs[i], len))
                break;
        if(i >= strsSize){
            char *p = (char *)malloc(len+1);
            memcpy(p, strs[0], len);
            p[len] = '\0';
            return p;
        }
    }
    return "";
}
```

方法二：横向扫描

```c
char *getCommonPrefix(char *s1, char *s2)
{
    int i;
    for(i = 0; s1[i] && s2[i]; i++)
        if(s1[i] != s2[i])
            break;
    s1[i] = 0;
    return s1;
}
char *longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize <= 0) return "";
    char *comStr = (char *)malloc(strlen(strs[0]) +1);
    strcpy(comStr, strs[0]);
    int i;
    for(i = 1; i < strsSize; i++)
    {
        comStr = getCommonPrefix(comStr, strs[i]);
        if(comStr[0]==0) return "";
    }
    return comStr;
}
```

方法三：纵向扫描

```c
char *longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize <= 0) return "";

    int i, j, len;
    len = strlen(strs[0]);
    for(j = 0; j < len; j++)
    {
        char c = strs[0][j];
        for(i = 1; i < strsSize; i++)
            if(strs[i][j] != c)  
            {
                if(j == 0) return "";
                else{
                    char *p = (char *)malloc(j+1);
                    memcpy(p, strs[0], j);
                    p[j] = 0;
                    return p;
                }
            } 
    }
    return strs[0];   
}
```

方法四：二分查找