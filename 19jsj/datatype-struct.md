## 结构体

- (2009年高考)下面程序运行结果是（        ）

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
    printf("%d", sizeof(struct stu));
    return 0;
}
```



- 输入坐标平面上的一点 `(x,y)` ，求该点到原点`(0,0)`的距离。

```c
#include<stdio.h>
#include<math.h>

_____________ Node
{
    float x;
    float y;
};
int main()
{
    struct Node point;
    scanf("%f %f", &point.x, &point.y);
    float d;
    d = sqrt(point.x * point.x + point.y * point.y);
    printf("%f", d);
}
```

