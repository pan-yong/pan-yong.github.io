## [翻转字符串里的单词](https://leetcode-cn.com/leetbook/read/array-and-string/crmp5/)

方法一

```c
char tmp[10001];
char * reverseWords(char * s)
{
    //char *tmp;
    int i, j, k, n = 0, isfirst = 1;
    j = strlen(s) - 1;
    //tmp = (char*)malloc(j+2);
    while(j > 0)
    {
        while(j >= 0 && isspace(s[j]))
            j--;
        k = j; // the end of a word
        while(j >= 0 && !isspace(s[j]))
            j--;
        i = j+1;// the start of a word;
        if(i <= k && isfirst) isfirst = 0;
        else if(i <= k && !isfirst)tmp[n++] = ' ';
        while(i <= k){
            tmp[n++] = s[i++];
        }
            
    }
    tmp[n] = 0;
    return tmp;
}
```

方法二

```c
void reverseStr(char *s)
{
    int i = 0, j = strlen(s) - 1;
    char tmp;
    while(i <= j){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;j--;
    }
}

char * reverseWords(char * s)
{
    reverseStr(s);
    int n = 0, i, j = 0, k, len;
    len = strlen(s);
    while(s[j])
    {
        while(j < len && isspace(s[j]))
            j++;
        i = j; // the word start
        while(j < len && !isspace(s[j]))
            j++;
        k = j - 1; // the word end
        while(k >= i){
            s[n++] = s[k--];
        }
        s[n++]=' ';
    }
    s[n] = 0;
    return s;
}
```

