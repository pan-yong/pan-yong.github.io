## 字符串函数

- unsigned int strlen(char *s);
- char \*strcpy(char\* dest, const char \*src);
- char *strcat(char *dest, const char *src);
- int strcmp(const char *s1,const char *s2);

1. 下面程序运行结果是（            ）

```c
int main()
{
    char *p = "\ta\017bc";
    char *q = "\ta\018bc";
    char *r = "\ta\08abc";
    char *s = "abcde" + 2;
    printf("%d %d %d %d", strlen(p), strlen(q), strlen(r),strlen(s));
}
```

2. 下面程序段运行结果是（                  ）

```c
int main()
{
    char p1[] = "abcdefgh", *p = p1;
    p += 3;
    printf("%d", strlen(strcpy(p, "ABCD")));
}
```

3. strlen

```c
int strlen(char *s) 
{ 
 	int n; 
 	for (n = 0; *s != '\0', s++) 
 		n++; 
 	return n; 
}
int strlen(char *s) 
{ 
 	char *p = s; 
 	while (*p != '\0') 
 		p++; 
 	return p - s; 
}
```

4. strcpy

```c
char *strcpy(char *s, char *t) 
{ 
    int i = 0; 
    while ((s[i] = t[i]) != '\0') 
     	i++; 
    return s;
}
char *strcpy(char *s, char *t) 
{ 
     while ((*s = *t) != '\0') { 
     	s++; t++; 
     } 
    return s;
}
char *strcpy(char *s, char *t) 
{ 
 	while ((*s++ = *t++) != '\0');
    return s;
}
char *strcpy(char *s, char *t) 
{ 
 	while (*s++ = *t++) ; 
}
```

5. strcat

```c
/* strcat: concatenate t to end of s; s must be big enough */ 
 void strcat(char s[], char t[]) 
 { 
     int i, j; 
     i = j = 0; 
     while (s[i] != '\0') /* find end of s */ 
     	i++; 
     while ((s[i++] = t[j++]) != '\0') /* copy t */ 
     	; 
 }
```

5. strcmp

```c
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */ 
 int strcmp(char *s, char *t) 
 { 
     int i; 
     for (i = 0; s[i] == t[i]; i++) 
     	if (s[i] == '\0') 
     		return 0; 
     return s[i] - t[i]; 
 }

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */ 
 int strcmp(char *s, char *t) 
 { 
 	for ( ; *s == *t; s++, t++) 
 		if (*s == '\0') 
 			return 0; 
 	return *s - *t; 
 }
```

6. reverse

```c
 /* reverse: reverse string s in place */ 
 void reverse(char s[]) 
 { 
     int c, i, j; 
     for (i = 0, j = strlen(s)-1; i < j; i++, j--) { 
     	c = s[i]; s[i] = s[j]; s[j] = c; 
     } 
 }
```

7. squeeze

```c
/* squeeze: delete all c from s */ 
 void squeeze(char s[], int c) 
 { 
     int i, j; 
     for (i = j = 0; s[i] != '\0'; i++) 
     	if (s[i] != c) 
     		s[j++] = s[i]; 
     s[j] = '\0'; 
 }
```

7. atoi

```c
/* atoi: convert s to integer */ 
 int atoi(char s[]) 
 { 
     int i, n = 0; 
     for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) 
     	n = 10 * n + (s[i] - '0'); 
     return n; 
 }

/* atoi: convert s to integer; version 2 */ 
 int atoi(char s[]) 
 { 
     int i, n, sign; 
     for (i = 0; isspace(s[i]); i++) /* skip white space */ 
     	; 
     sign = (s[i] == '-') ? -1 : 1; 
     if (s[i] == '+' || s[i] == '-') /* skip sign */ 
     	i++; 
     for (n = 0; isdigit(s[i]); i++) 
     	n = 10 * n + (s[i] - '0'); 
     return sign * n; 
 }
```

8. itoa

```c
/* itoa: convert n to characters in s */ 
 void itoa(int n, char s[]) 
 { 
     int i, sign; 
     if ((sign = n) < 0) /* record sign */ 
     	n = -n; /* make n positive */ 
     i = 0; 
     do { /* generate digits in reverse order */ 
     	s[i++] = n % 10 + '0'; /* get next digit */ 
     } while ((n /= 10) > 0); /* delete it */ 
     if (sign < 0) 
     	s[i++] = '-'; 
     s[i] = '\0'; 
     reverse(s); 
 }
```

7. atof

```c
#include<stdio.h>
#include<string.h>
#include <ctype.h> 
 /* atof: convert string s to double */ 
 double atof(char s[]) 
 { 
     double val, power; 
     int i, sign; 
     for (i = 0; isspace(s[i]); i++) /* skip white space */ 
     		; 
     sign = (s[i] == '-') ? -1 : 1; 
     if (s[i] == '+' || s[i] == '-') 
     	i++; 
     for (val = 0.0; isdigit(s[i]); i++) 
     	val = 10.0 * val + (s[i] - '0'); 
     if (s[i] == '.') 
     	i++; 
     for (power = 1.0; isdigit(s[i]); i++) { 
     	val = 10.0 * val + (s[i] - '0'); 
     	power *= 10; 
     } 
     return sign * val / power; 
 }
int main()
{
    char *p = "123.456";
    printf("%.3lf", atof(p));
}
```

8. 单词计数

```c
#include <stdio.h> 
 #define IN 1 /* inside a word */ 
 #define OUT 0 /* outside a word */ 
 /* count lines, words, and characters in input */ 
 main() 
 { 
     int c, nl, nw, nc, state; 
     state = OUT; 
     nl = nw = nc = 0; 
     while ((c = getchar()) != EOF) 
     { 
     	++nc; 
         if (c == '\n') 
            ++nl; 
         if (c == ' ' || c == '\n' || c = '\t') 
            state = OUT; 
         else if (state == OUT) { 
            state = IN; 
            ++nw; 
         } 
     } 
     printf("%d %d %d\n", nl, nw, nc); 
 }
```

9. trim

```c
/* trim: remove trailing blanks, tabs, newlines */ 
 int trim(char s[]) 
 { 
     int n; 
     for (n = strlen(s)-1; n >= 0; n--) 
     	if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') 
     		break; 
     s[n+1] = '\0'; 
     return n; 
 }
```

10. strindex

```c
 /* strindex: return index of t in s, -1 if none */ 
 int strindex(char s[], char t[]) 
 { 
     int i, j, k; 
     for (i = 0; s[i] != '\0'; i++) 
     { 
     	for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
     		; 
     	if (k > 0 && t[k] == '\0') 
     		return i; 
     } 
     return -1; 
 }
```

