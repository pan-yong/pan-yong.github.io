## 结构体

[TOC]



###### 1. 结构体类型的申明

```c
struct 结构体名
{
    成员列表;
};

struct student
{
    int num;
    char name[20];
};
```

###### 2. 结构体变量的定义与初始化

```c
// 1) 先申明类型，再定义变量
struct student{
    int num;
    char name[20];
};
strcut student czy = {1000, "chenzhengyang"};
```

```c
// 2) 申明类型的同时定义变量
struct student{
    int num;
    char name[20];
}zs = {1001,"zhangsan"};
```

```c
// 3) 声明类型的同时，给类型起别名，通过别名定义变量
typedef struct student{
    int num;
    char name[20];
}STU;
STU ww = {1002, "wangwu"};
```

###### 3. 结构体成员变量的访问

```tex
结构体变量名.成员名
结构体指针->成员名
(*结构体指针).成员名
```

###### 4. 结构体数组

```c
struct stu{
    int num;
    char name[20];
}x[3] = {1,"zhangsan", 2, "lisi", 3, "wangwu"};
```

