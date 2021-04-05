## 结构体与联合体

1. 下面程序输出结果是（            ）

```c
int main()
{   struct stu{ char name[10]; int age, sex;};
    printf("%d", sizeof(struct stu));
}
```

2. 下面程序输出结果是（            ）

```c
int main()
{   int a = 0x11223344;
    char *p = (char *)&a, b = *p, c = *(p+3);
    printf("%x %x",b, c);
}
```

3. 下面程序输出结果是（            ）

```c
int main()
{   union node{int a, char b;} x;
    x.a = 257;
    printf("%d", x.b);
}
```

4. 下面程序运行结果是（        ）

```c
union myun{
    struct {int x, y, z} u;  int k;
}a;
int main()
{   a.u.x = 4; a.u.y = 5; a.u.z = 6; a.k = 0;
    printf("%d", a.u.x);
}
```

5. 下面程序输出结果是（           ）

```c
union U{ char st[4]; int I; int j;};
struct A{int c; union U u; } a;
int main(){
    printf("%d",sizeof(a));
}
```

6. 下面程序输出结果是（        ）

```c
int main()
{   union {char i[2]; int k;} r;
    r.i[0] = 2; r.i[1] = 0;
    printf("%d", r.k);
}
```

7. 下面程序输出结果是（        ）

```c
int main()
{   union {int i[2]; int k; char c[4];} r, *s = &r;
    s->i[0] = 0x39; s->i[1] = 0x38;
    printf("%c", s->c[0]);
}
```

8. 下面程序输出结果是（        ）

```c
int main()
{
    enum Color{ red, blue, green, yellow=16, black, purple, pink};
    printf("%d %d", blue, purple);
}
```

9. 下面程序输出结果是（        ）

```c
typedef int A[5];
int main()
{   A a; int i;
    for(i = 0; i < 5; i++)
        a[i] = 2*i;
    for(i = 0; i < 5; i++)
        printf("%d", a[i]);
}
```

10. 下面程序输出结果是（            ）

```c
void amovep(int *p, int a[][4], int n)
{   int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < 4; j++)
            *p++ = a[i][j];
}
int main()
{   int *p, a[3][4] = {{1,3,5},{2,4,6}};
    p = (int *) malloc( sizeof(int)*10);
    amovep(p, a, 3);
    printf("%d %d", p[2], p[5]);
    free(p);
}
```

11. 下面程序输出结果是（        ）

```c
struct HAR{int x,y; struct HAR *p;}h[2];
int main()
{
    h[0].x = 1; h[0].y = 2; h[0].p = &h[1];
    h[1].x = 3; h[1].y = 4; h[1].p = &h[0];
    printf("%d %d", (h[0].p)->x, (h[1].p)->y);
}
```

