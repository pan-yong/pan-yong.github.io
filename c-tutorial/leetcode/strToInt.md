## [把字符串转换成整数](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/)

```c
int strToInt(char* str)
{
    int i = 0, num = 0, sign;
    const int bnd = 214748364;
    
    while(isspace(str[i]) && str[i]) i++;
    sign = (str[i] == '-' ? -1 : 1);
    if(str[i]=='-'||str[i]=='+') i++;
    
    while(str[i] && str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10  - '0' + str[i];  // 不能写成  num * 10  + str[i] - '0'  可能会溢出
        i++; 
        if(num == bnd)
        {             
            if(sign < 0 && str[i] >= '8' && str[i] <= '9')
                return -2147483648;
            else if(sign > 0 && str[i] >= '7' && str[i] <= '9')
                return 2147483647;
        }
        else if(num > bnd){
            if(str[i] >= '0' && str[i] <= '9')
                if(sign < 0) return -2147483648;
                else return 2147483647;
        }
    }
    if(sign < 0) num = -num;
    return num;
}

```

