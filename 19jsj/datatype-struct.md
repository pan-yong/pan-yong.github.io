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

