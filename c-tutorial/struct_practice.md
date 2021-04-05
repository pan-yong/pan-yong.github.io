## 结构体变量的定义与访问

1. 以下结构体类型申明和变量定义中，正确的是（        ）

```c
A. struct SS{char flag; float x;}        B. struct {char flag; float x;} SS;
   struct SS a, b;                          SS a, b;
C. struct SS{char flag; float x};        D. typedef  {char flag; float x}SS;
   struct SS a,b;                           SS a, b;
```

2. 以下对结构体类型变量st的定义中，错误的是（        ）

```c
A. struct {char c; int a;} st;              B. struct {char c; int a;} TT;  struct TT st;
C. typedef struct {char c; int a;} TT;      D. #define TT struct
   TT st;                                      TT{char c; int a;} st;
```

3. 对下面语句叙述正确的是（        ）

```c
typedef struct REC{ char c; int a[4]; }REC1;
A. 可以用REC定义结构体变量              B. REC1是struct REC类型的变量
C. REC是struct类型变量                 D. 可以用REC1定义结构体变量   
```

4. 有下面定义和赋值，则不能输出n中data的值的是（        ）

```c
struct SNode{ int id, data; }n, *p = &n;
A. p.data        B. n.data         C. p->data        D.(*p).data
```

5. 下面代码对data中的a正确的引用是（        ）

```c
struct kk{ int a; float b; }data, *p=&data;
A. (*p).data.a        B. (*p).a        C. p->data.a        D. p.data.a
```

6. 已知学生记录及变量的定义如下，能给s中的year成员赋值1984的语句是（        ）

```c
struct student{
    int no; char name[20]; char sex;
    struct {int year, month, day;} birth;
}s, *ps = &s;
A. s.year = 1984;    B. ps.year = 1984;    C. ps->year=1984;    D. s.birth.year=1984;
```

7. 修改下面程序中的两行错误。

```c
struct node{ int count; char name[20]; }a, *p = &a;
int main()
{   
    scanf("%d %s", a.count, a.name);
    printf("%d %s",p.count, p.name);
}
_______ 行改为_____________________________
_______ 行改为_____________________________
```

8. 下面程序段输出结果是（            ）

```c
struct c{ int x, y; }s[2] = {1,3,2,7};
printf("%d", s[0].x * s[1].x);
```

9. 下面程序段输出结果是（            ）

```c
struct country{
    int num; char name[10];
}x[5] = {1, "China", 2, "USA", 3, "France", 4, "England", 5, "Spanish"};
struct country *p = x + 2;
printf("%d,%c", p->num, (*p).name[2]);
```

10. 下面程序段输出结果是（        ）

```c
struct date{ int year, month, day;};
struct s{
    struct date birthday; char name[20];
}x[2] = { {2008,10,1,"Guangzhou"}, {2009,12,25,"Tianjin"} };
printf("%s,%d", x[0].name, x[1].birthday.year);
```

11. 下面程序运行结果是（        ）

```c
struct s{ int x, y; } data[2] = {10,100,20,200};
int main()
{   struct s *p =data;
    printf("%d ", ++(p->x));  printf("%d", (++p)->y);
}
```

12. 下面程序运行结果是（         ）

```c
struct st{ int x; int *y; };
int dt[4] = {10,20,30,40};
struct st aa[4] = {50, &dt[0], 60, &dt[1], 70, &dt[2], 80, &dt[3]};
int main()
{   struct st *p = aa;
    printf("%d ", ++p->x); printf("%d ", (++p)->x); printf("%d ", ++(*p->y));
}
```

13. 下面程序运行结果是（                     ）

```c
struct STU{int num; float score;};
void f1(struct STU p){
    struct STU s[2] = {{20044, 550},{20045, 537}};
    p.num = s[0].num; p.score = s[0].score;
}
void f2(struct STU *p){
    struct STU s[2] = {{20044, 550},{20045, 537}};
    p->num = s[1].num; p->score = s[1].score;
}
int main()
{   struct STU s[2] = {{20041, 703}, {20042, 580}};
    f1(s[0]); f2(&s[1]);
    printf("%d %.0f\n", s[0].num, s[0].score);
	printf("%d %.0f", s[0].num, s[0].score);
}
```

