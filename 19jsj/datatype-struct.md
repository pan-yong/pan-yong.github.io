## 结构体

- 下面程序运行结果是（            ）

```c
#include<stdio.h>
int main()
{
    struct stu
    {
        char name[12];
        int age;
        int sex;
    };
    struct stu zs = {"张三", 18,1};
    printf("%d", sizeof(zs));
    return 0;
}
```

- 输入坐标平面上的一点 `(x,y)` ，求该点到原点`(0,0)`的距离。

```c
#include<stdio.h>
#include<math.h>

_____(1)________ Node
{
    float x;
    float y;
};
int main()
{
    struct Node point;
    scanf("%f %f", &point.x, &point.y);
    float d;
    d = sqrt(________(2)___________);
    printf("%f", d);
}
```

- 下面程序输出结果是（        ）

```c
int main()
{
    struct c{
        int x, y;
    }s[2] = {1,3,2,7};
    printf("%d", s[0].x * s[1].x);
}
```

- 下面程序输出结果是（        ）

```c
struct KeyWord
{
    char Key[20];
    int ID;
} kw[] = {"void", 1, "char", 2, "int", 3, "float",4,"double",5};
int main()
{
    printf("%c,%d",kw[3].Key[0], kw[3].ID);
}
```

- 给《我是歌手》大赛栏目设计计票程序。请填空。

```c
#include<stdio.h>
struct node
{
    int count;
    char name[20];
};
struct node a[3] = {0,"lilei", 0, "zhangsan", 0, "lisi"};
int main()
{
    int i, j;
    _______________;
    for (i = 1; i <= 100; i++) // 100人参与投票
    {
        scanf("%s", name1);  // 输入姓名投票
        for (j = 0; j < 3; j++){
            if (_______________ ) // 与选手名字相通，对应票数加一
            {
                a[j].count++; break;
            }
        }
    }
    for (i = 0; i < 3; i++) //输出每个人的票数
        printf("%s:%d\n",a[i].name, a[i].count);
}
```

- 下面程序输出结果是（        ）

```c
struct date{
    int year, month, day;
};
struct s{
    struct date birthday;
    char name[20];
}x[4] = ;
```



