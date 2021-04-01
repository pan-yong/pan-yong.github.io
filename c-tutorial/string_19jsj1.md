## 字符串

> 思考以下程序输出结果，并上机运行验证。

1. 下面程序段运行结果是（          ）

```c
#include<stdio.h>
int main()
{
    char c[5] = {'a', 'b','\0', 'c'};
    printf("%d %d %s %c\n" strlen(c), sizeof(c), c, c[3]);
}
```

2. 下面程序运行结果是（        ）

```c
int main()
{   
    char s[] = "18jsj1"; 
    int i, n = 0;
    for(i = 0; s[i] != '\0'; i++)
        n++;
    printf("%d", n);
}
```

3. 下面程序运行结果是（        ）

```c
int main()
{    
    char a[100] = "hi", b[100] = "world"; 
 	int i = 0;
     while(b[i] != '\0'){
		a[i] = b[i];
         i++;
     }
 	a[i] = '\0';
 	puts(a[i]);
}
```

4. 下面程序运行结果是（        ）

```c
#include<stdio.h>
int main()
{
    char a[100] = "hi", b[100] = "world"; int i = 0, j = 0;
    while(a[i]) i++;
    while(b[j]!='\0') a[i++] = b[j++];
    a[i] = '\0';
    puts(a);
}
```

5. 下面程序运行结果是（         ）

```c
int main()
{
    char a[100] = "hi", b[100] = "world"; 
    int i = 0, j = 0, ans;
    for(i = 0; a[i]==b[i]; i++)
        if(a[i] == '\0'){
            ans = 0;
            break;
		}
    if(a[i] > b[i]) ans = 1;
    else if(a[i] < b[i]) ans = -1;
    printf("%d", ans);
}
```

6. 下面程序运行结果是（            ）

```c
int main()
{   
    char a[100] = "hi", b[100] = "world"; 
    int len, cmp;
    
    len = strlen(a); 
    printf("%d\n", len);
    
    strcat(a,b); 
    printf("%s\n", a);
    
    strcpy(a,b); 
    printf("%s\n", a);
    
    cmp = strcmp(a,b);
    printf("%d", cmp);
}
```

7. 下面程序运行结果是（         ）

```c
int main()
{   
    char ch[7] = "12ab56"; 
    int i, s = 0;
    for(i = 0; ch[i]>='0' && ch[i] <= '9'; i++)
        s = 10*s + ch[i] - '0';
    printf("%d", s);
}
```

8. 下面程序运行结果是（        ）

```c
int main()
{   
    char a[] = "morming", t; 
    int i, j = 0;
    for(i = 1; i < 7; i++)
        if(a[j] < a[i]) j = i;
    t = a[j]; a[j] = a[7]; a[7] = t;
    puts(a);
}
```

9. 下面程序运行结果是（        ）

```c
int main()
{   
    int i, r; 
    char s1[80] = "Time", s2[80] = "Tom";
    for(i = r = 0; s1[i]!='\0' && s2[i] != '\0'; i++)
        if(s1[i] == s2[i])
            if(s1[i] >= 'a' && s1[i] <= 'z')
                printf("%c",s1[i] - 32);
    		else
                printf("%c", s1[i] + 32);
    	else
            printf("*");
}
```

10. 下面程序运行结果是（        ）

```c
int main()
{   
    int i = 0; 
 	char a[] = "abm", b[] = "aqid", c[10];
    while(a[i]!='\0' && b[i] != '\0')
    {
        if(a[i] >= b[i]) c[i] = a[i] - 32;
        else c[i] = b[i] - 32;
        i++;
    }
    c[i] = '\0';
    puts(c);
}
```

