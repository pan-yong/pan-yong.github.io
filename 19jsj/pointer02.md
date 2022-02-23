## 指针与字符串

<<<<<<< HEAD
1. unsigned int strlen(char *s);
=======
1. `unsigned int strlen(char *s);`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
unsigned int strlen(char *s) 
{   unsigned int n; 
 	for (n = 0; *s != '\0'; s++) 
 		n++; 
 	return n; 
}
unsigned int strlen(char *s) 
{   char *p = s; 
 	while (*p != '\0') 
 		p++; 
 	return p - s; 
}
```

<<<<<<< HEAD
2. char \*strcpy(char\* dest, const char \*src);
=======
2. `char *strcpy(char* dest, const char *src);`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
char *strcpy(char *s, char *t) 
{   int i = 0; 
    while ((s[i] = t[i]) != '\0') 
     	i++; 
    return s;
}
char *strcpy(char *s, char *t) 
{ 
    char *dest = s;
     while ((*s = *t) != '\0') { 
     	s++; t++; 
     } 
    return dest;
}
char *strcpy(char *s, char *t) 
{   char *dest = s;
    while ((*s++ = *t++) != '\0');
    return dest;
}
char *strcpy(char *s, char *t) 
{   char *dest = s;
    while (*s++ = *t++) ; 
    return dest;
}
```

<<<<<<< HEAD
3. char *strcat(char *dest, const char *src);
=======
3. `char *strcat(char *dest, const char *src);`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
 void strcat(char s[], char t[]) 
 {  /* strcat: concatenate t to end of s; s must be big enough */  
     int i = 0, j = 0; 
     while (s[i] != '\0') /* find end of s */ 
     	i++; 
     while ((s[i++] = t[j++]) != '\0') /* copy t */ 
     	; 
 }
```

<<<<<<< HEAD
4. int strcmp(const char *s1,const char *s2);
=======
4. `int strcmp(const char *s1,const char *s2);`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */ 
 int strcmp(char *s, char *t) 
 {   int i; 
     for (i = 0; s[i] == t[i]; i++) 
     	if (s[i] == '\0') 
     		return 0; 
     return s[i] - t[i]; 
 }
 int strcmp(char *s, char *t) 
 { 
 	for ( ; *s == *t; s++, t++) 
 		if (*s == '\0') 
 			return 0; 
 	return *s - *t; 
 }
```

<<<<<<< HEAD
5. reverse
=======
5. `reverse`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
 void reverse(char s[]) 
 {   /* reverse: reverse string s in place */ 
     int c, i, j; 
     for (i = 0, j = strlen(s)-1; i < j; i++, j--) { 
     	c = s[i]; s[i] = s[j]; s[j] = c; 
     } 
 }
```

<<<<<<< HEAD
6. squeeze
=======
6. `squeeze`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
 void squeeze(char s[], int c)  /* squeeze: delete all c from s */
 { 
     int i, j; 
     for (i = j = 0; s[i] != '\0'; i++) 
     	if (s[i] != c) 
     		s[j++] = s[i]; 
     s[j] = '\0'; 
 }
```

<<<<<<< HEAD
7. atoi
=======
7. `atoi`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
int atoi(char s[])   /* atoi: convert s to integer */ 
 {   int i, n = 0; 
     for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) 
     	n = 10 * n + (s[i] - '0'); 
     return n; 
 }
 int atoi(char s[])   /* atoi: convert s to integer; version 2 */ 
 {   int i, n, sign; 
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

<<<<<<< HEAD
8. itoa
=======
8. `itoa`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
void itoa(int n, char s[])   /* itoa: convert n to characters in s */ 
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

<<<<<<< HEAD
9. atof
=======
9. `atof`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
 double atof(char s[])  /* atof: convert string s to double */ 
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
```

10. 单词计数

```c
#include <stdio.h> 
 #define IN 1 /* inside a word */ 
 #define OUT 0 /* outside a word */ 
 int main()  /* count lines, words, and characters in input */ 
 {   int c, nl, nw, nc, state; 
     state = OUT; nl = nw = nc = 0; 
     while ((c = getchar()) != EOF) 
     {   ++nc; 
         if (c == '\n')  ++nl; 
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

<<<<<<< HEAD
11. trim
=======
11. `trim`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
/* trim: remove trailing blanks, tabs, newlines */ 
 int trim(char s[]) 
 {   int n; 
     for (n = strlen(s)-1; n >= 0; n--) 
     	if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') 
     		break; 
     s[n+1] = '\0'; 
     return n; 
 }
```

<<<<<<< HEAD
12. strindex
=======
12. `strindex`
>>>>>>> 6744dc1ef52e596fef0ffd83c8786183a33ac417

```c
 /* strindex: return index of t in s, -1 if none */ 
 int strindex(char s[], char t[]) 
 {   int i, j, k; 
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

13. 数字字符统计

```c
#include <stdio.h> 
 /* count digits, white space, others */ 
 int main() 
 {   int c, i, nwhite, nother; 
     int ndigit[10]; 
     nwhite = nother = 0; 
     for (i = 0; i < 10; ++i) 
     	ndigit[i] = 0; 
     while ((c = getchar()) != EOF) 
     	if (c >= '0' && c <= '9') 
     		++ndigit[c-'0']; 
     	else if (c == ' ' || c == '\n' || c == '\t') 
     		++nwhite; 
     	else 
     		++nother; 
     printf("digits ="); 
     for (i = 0; i < 10; ++i) 
     	printf(" %d", ndigit[i]); 
     printf(", white space = %d, other = %d\n", nwhite, nother); 
 }
```



###### 参考资料

- 《The C Programming Language》
