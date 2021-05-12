## C程序设计竞赛试题

###### A. [斜率计算](https://www.dotcpp.com/oj/problem1637.html)

输入两个点的坐标，即p1 = (x1, y1)和p2=(x2, y2)，求过这两个点的直线的斜率。如果斜率为无穷大输出`INF`。

样例输入

```c
1 2
1 4
```

样例输出

```c
INF
```



















###### B. [核桃的数量](https://www.dotcpp.com/oj/problem.php?id=1446)

小张是软件项目经理，他带领3个开发组。工期紧，今天都在加班呢。为鼓舞士气，小张打算给每个组发一袋核桃（据传言能补脑）。他的要求是：

1. 各组的核桃数量必须相同
2. 各组内必须能平分核桃（当然是不能打碎的）
3. 尽量提供满足1,2条件的最小数量（节约闹革命嘛）

输入：输入包含三个正整数a, b, c，表示每个组正在加班的人数，用空格分开（a,b,c< 30） 

输出：输出一个正整数，表示每袋核桃的数量。

样例输入：

```c
2 4 5
```

样例输出：

```c
20
```



















###### C. [IP判断](https://www.dotcpp.com/oj/problem1116.html)

在基于Internet的程序中，我们常常需要判断一个IP字符串的合法性。合法的IP是这样的形式：A.B.C.D
其中A、B、C、D均为位于[0, 255]中的整数。为了简单起见，我们规定这四个整数中不允许有前导零存在，如001这种情况。现在，请你来完成这个判断程序吧。

输入：输入由多行组成，每行是一个字符串，输入由“End of file”结束。字符串长度最大为30，且不含空格和不可见字符。

输出：对于每一个输入，单独输出一行。如果该字符串是合法的IP，输出Y，否则，输出N。

样例输入：

```c
1.2.3.4
a.b.c.d
267.43.64.12
12.34.56.bb
210.43.64.129
-123.4.5.6
```

样例输出：

```c
Y
N
N
N
Y
N
```

请补全下面代码：







```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
   char s[31] = {0};
   while(scanf("%s",s)!=EOF)
   {
       int i = 0, num = 0;
       for(i=0;_______(1)_______;i++)
       {
           if(isdigit(s[i]))
           {
               ___________(2)_____________;
               if(num > 255){
                   printf("N\n");
                   break;
               }
           }
           else if(s[i]=='.')
           {
               ___________(3)____________;
           }
           else 
           {
                printf("N\n");
                break;
            }  
       }  
       if(______(4)________)printf("Y\n");    
   }
}
```





###### D. [错误票据](https://www.dotcpp.com/oj/problem1458.html)

某涉密单位下发了某种票据，并要在年终全部收回。每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。你的任务是通过编程，找出断号的ID和重号的ID。假设断号不可能发生在最大和最小号。

输入：首先输入一个整数N(N< 100)表示后面数据行数。 接着读入N行数据。 每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000），请注意行内和行末可能有多余的空格。每个整数代表一个ID号。 

输出：程序输出两个整数m n，用空格分隔。 其中，m表示断号ID，n表示重号ID 。

样例输入：

```c
2
5 6 8 11 9
10 12 9
```

样例输出：

```c
7 9
```

请补全下面代码：













```c
#include<stdio.h>
int main()
{
    int N,a[100000]={0}, t, m, n, min = 100000;
    scanf("%d", &N);		   // N表示接下来有N行数据输入
    while(scanf("%d", &t)!=EOF) // 输入票据ID
    {
        if(_______) n = t;		 // 票据ID号t重复出现
        a[t] = 1;				// 标记ID号t出现过
        if(t < min) min = t;	 // 记录票据最小ID
    }
    m = min;
    while(1)
    {
        if(________)			// 找到断号ID
            break;
    } 
    printf("%d %d", m, n);		// 输出断号ID，重号ID
}
```















###### E. [洗牌](https://www.dotcpp.com/oj/problem1542.html)

小弱T在闲暇的时候会和室友打扑克，输的人就要负责洗牌。虽然小弱T不怎么会洗牌，但是他却总是输。渐渐地小弱T发现了一个规律：只要自己洗牌，自己就一定会输。所以小弱T认为自己洗牌不够均匀，就独创了一种小弱洗牌法。小弱洗牌法是这样做的：先用传统洗牌法将52张扑克牌（1到K各四张，除去大小王）打乱，放成一堆，然后每次从牌堆顶层拿一张牌。如果这张牌的大小是 P（1到K的大小分别为1到13），那么就把这张牌插入到当前手中第P张牌的后面。如果当前手中不足P张牌，那么就把这张牌放在最后。现在给你一对已经被打乱的牌，请你用小弱洗牌法进行洗牌，然后输出最后生成的序列。注意：小弱可能在第一次洗牌时弄丢了某些牌，这时请你输出一个-1来提醒他牌的数目不够。

输入：含N个用空格隔开的字符串表示牌堆从顶至底的每张扑克（1到K中的某个）。可能有多行。 数据规模和约定保证每个字符串都为1 2 3 4 5 6 7 8 9 10 J Q K中的一个。

输出：如果N为52，输出用小弱洗牌法洗牌后的序列，每个字符串用空格隔开。 否则请输出一个-1。

样例输入：

```c
4 6 K Q 5 1 Q 9 7 9 K 3 J 1 2 3 5
2
3 5 7 Q 7 10 8 4 9 7 8 9 4
10 6 2 8 2 10 10 Q 5 K J 1
J 8 3 K 4 1 6 J 6
```

样例输出：

```c
4 1 1 1 3 4 6 6 2 2 2 5 J 3 8 4 4 6 K J 8 J 10 10 K Q 2 5 7 8 10 9 3 7 9 8 7 1 10 5 6 3 Q K Q 5 Q 7 9 9 J K
```

请补全下面代码：





```c
#include<stdio.h>
#include<string.h>
// 函数功能：把扑克牌字符串转整数。
int cardToInt(char card[3])
{
    if(___________________________)
        return 10;
    else if(card[0] == 'J')  return 11;
    else if(card[0] == 'Q')  return 12;
    else if(card[0] == 'K')  return 13;
    else if(card[0] >= '0' && card[0] <= '9')
        return __________________;
}
// 函数功能：按照洗牌规则洗牌
void shuffleCards(char cards[][3], int n)
{
    int i = 0, j, p;  char tmpCard[3] = {0};
    for(i = 0; i < n; i++)
    {
        ____________________________; // 查看牌cards[i]大小
        if(p < i)	// 把牌cards[i]插入到下标为p的位置
        {  
            // 把牌cards[i]放入到tmpCard中
            strcpy(tmpCard, cards[i]); 
            j = i-1;
            while(______________)				
            {   
                // 扑克牌后移，空出下标为p的位置
                ___________________________; 
                j--;
            }
            // 把拿到的牌插入到下标为p的位置
            strcpy(cards[j+1],tmpCard); 
        }
    }
}
// 函数功能：输出每一张扑克牌
void printCards(char cards[][3], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%s ",cards[i]);
}
int main()
{
    char cards[52][3] = {0}, ch;
    int n = 0;
    while(scanf("%s",cards[n])!=EOF)  // 输入每一张扑克牌
        n++;
    
    if(n < 52)printf("-1");			// 牌数量不对，输出-1
    else{
        shuffleCards(cards,n);		// 洗牌
        printCards(cards,n);		// 输出扑克牌
    }
}
```

















###### F. [笨小猴](https://www.dotcpp.com/oj/problem1553.html)

笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个素数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

输入：输入文件只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。 

输出：输出文件共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。 

样例输入：

```c
error
```

样例输出：

```c
Lucky Word
2
```

请补全下面代码：

```c
#include<stdio.h>
#include<string.h>
// 函数功能：n是素数返回1，不是素数返回0.
int isPrime(int n)
{
   // 请补全代码
    
    
    
}
// 函数功能：
// 统计s中各字母出现的次数，返回出现最多次数与出现最小次数之差
int max_min(char s[])
{
    int i, c[26] = {0}, max, min;
    for(i = 0; s[i]; i++) //遍历s，统计各字母出现次数
        c[_______]++;
    
    // 找字母出现次数最大值
    max = 0;
    for(i = 0; i < 26; i++)
        if(c[i] > max) max = c[i];
    
    // 找字母出现次数最小值。注意s中没有出现过的字母，不包括在内。
    // 请在下面补全代码：
    
    
    return max - min;
}
int main()
{
    char s[100];
    gets(s);
    int maxn_minn = __________________;
    if(isPrime(maxn_minn)) 
        ____________________;
    else 
        ____________________;
    return 0;
}
```







###### G.[报时助手](https://www.dotcpp.com/oj/problem1468.html)

给定当前的时间，请用英文的读法将它读出来。时间用时h和分m表示，在英文的读法中，读一个时间的方法是：

如果m为0，则将时读出来，然后加上“o'clock”，如3:00读作“three o'clock”。

如果m不为0，则将时读出来，然后将分读出来，如5:30读作“five thirty”。

时和分的读法使用的是英文数字的读法，其中0~20读作：

0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 7:seven, 8:eight, 9:nine, 10:ten, 11:eleven, 12:twelve, 13:thirteen, 14:fourteen, 15:fifteen, 16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty。

30读作thirty，40读作forty，50读作fifty。

对于大于20小于60的数字，首先读整十的数，然后再加上个位数。如31首先读30再加1的读法，读作“thirty one”。

按上面的规则21:54读作“twenty one fifty four”，9:07读作“nine seven”，0:15读作“zero fifteen”。

输入：包含两个非负整数h和m，表示时间的时和分。非零的数字前没有前导0。h小于24，m小于60。 

输出：时间时刻的英文。 

样例输入：

```c
0 15 
```

样例输出：

```c
zero fifteen
```

请补全下面代码：

```c
#include<stdio.h>
void convert(int h, int m, char *time)
{
    // 数字0~20的英文转换表
     char *table[21]={"zero", "one", "two", 
                      "three", "four", "five",
                      "six",  "seven", "eight",
                      "nine", "ten",  "eleven", 
                      "twelve",  "thirteen",  "fourteen",
                      "fifteen", "sixteen",  "seventeen", 
                      "eighteen",  "nineteen",  "twenty"};
    
    // 把h转英文复制到time中
    if(h>=0 && h <= 20)
    {
         ______________________
         strcat(time, " ");
    }
    else if(h > 20){
        strcpy(time,table[20]);
        strcat(time, " ");
        strcat(time,___________);
        strcat(time, " ");
    }
    
    // 把m转英文追加到time后面
    if(m == 0){
        strcat(time,"o'clock");
    }
    else if(m>0&&m<=20){
        strcat(time, table[m]);
    }
    else if(m > 20 && m < 30){
        strcat(time, table[20]);
        strcat(time, " ");
        strcat(time, table[m-20]);
    }
    
    else if(m >= 30 && m < 40)
    {
       // 请补全代码
    }
    else if(m >= 40 && m < 50)
    {
        // 请补全代码
    }
    else if(m >= 50 && m < 60)
    {
        // 请补全代码
    }
        
}
int main()
{
    int h,m;
    scanf("%d %d", &h, &m);
    char time[100];
    convert(h,m,time);
    puts(time);
}
```
