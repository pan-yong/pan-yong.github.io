## 浮点型

```c
#include<stdio.h>
main()
{
    float r = 5.0;
    float area = 3.14 * r * r;
    printf("%f", area);
}

/*
float 单精度浮点型
%f    浮点输出
5.0   浮点常量     科学计数法：1.2e3 ，e的前后都要有数，e的后面只能是整数。
*/
```

###### 课堂练习

![image-20210906091612332](.\images\image-20210906091612332.png)

###### 上机练习

1. 编写程序，输出人的身体质量指数。计算公式：

$$
BMI = 体重 \div 身高^2。（体重单位：千克；身高单位：米）
$$

```c
#include <stdio.h>
main()
{
    float weight = 66.5;  // 体重  kg
    float height = 1.75;  // 身高  m
    float BMI;
    
    BMI = weight / (height * height);
    printf("%f", BMI);
}

/*
身体质量指数是国际上衡量人体胖瘦程度以及是否健康的一个常用指标。
BMI正常值在20至25之间，超过25为超重，30以上则属肥胖。
*/
```



2. 编写程序求一元二次方程的根。

$$
ax^2 + bx + c = 0
$$

$$
求根公式：x1 = \frac{-b + \sqrt{b^2 - 4ac}}{ 2*a} , x2 = \frac{-b - \sqrt{b^2 - 4ac}}{ 2*a}
$$

```c
#include <stdio.h>
#include <math.h>
main() 
{
    float a, b, c, d;
    a = 5, b = 17, c = 11;
    d = b * b - 4 * a * c;
    
    float x1, x2;
    
    x1 = (-b + sqrt(d)) / (2*a);
    x2 = (-b - sqrt(d)) / (2*a);
    
    printf("x1=%f x2=%f\n", x1, x2);
}
```



###### 小结

- 浮点数类型标识符：  `float` 和 `double`
- 浮点数的输出格式控制符：`%f`
- 浮点数常量的书写：
  - 3.1415926
  - .5 
  - 12e2 ，注意科学计数法要求e的前后都要有数且e的后面只能是整数。
- 上机练习
  - 输出圆的面积
  - 输出人的身体质量指数
  - 输出一元二次方程的根

