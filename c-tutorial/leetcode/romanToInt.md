## [13. 罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/)

方法一

```c
int romanToInt(char * s)
{
    int num = 0;
    while(*s)
    {
        switch(*s)
        {
            case 'I': 
                if(*(s+1) == 'V')
                    num += 4, s++;
                else if(*(s+1) == 'X')
                    num += 9, s++;
                else
                    num += 1;
                break;
            case 'V': num += 5;break;
            case 'X': 
                if(*(s+1)=='L')
                    num += 40, s++;
                else if(*(s+1) == 'C')
                    num += 90, s++;
                else
                    num += 10;
                break;
            case 'L': num += 50;break;
            case 'C': 
                if(*(s+1)=='D')
                    num += 400, s++;
                else if(*(s+1) == 'M')
                    num += 900, s++;
                else
                    num += 100;
                break;
            case 'D': num += 500;break;
            case 'M': num += 1000;break;
        }
        s++;
    }
    return num;
}
```

方法二

```c
int getValue(char ch)
{
    switch(ch)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
int romanToInt(char * s)
{
    int sum = 0, num, pre;
    pre = getValue(*s);
    while(*++s)
    {
        num = getValue(*s);
        if(pre < num)
            sum -= pre;
        else
            sum += pre;
        pre = num;
    }
    sum += pre;
    return sum;
}
```

