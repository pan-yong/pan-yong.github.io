

##### （〇）开篇词：为什么学习C语言

（1）C语言是一门最早期简单而通用的编程语言。是C++、Java、Go等的原型语言，了解C语言后，再学习其他语言，会更好理解，轻松许多。

（2）学习C语言，才能够去探索优秀软件内部实现细节，操作系统、编译器、数据库、网络协议等。

（3）有助于理解汇编、高速缓存、内存、寄存器、函数调用等，彻底理解计算机运作机制。



###### （1）前置知识：汇编语言

```assembly
MOV r/m, r
MOV r, r/m
MOV r/m, imm
```

这几条指令展示了数据通常所在的三个位置：

- r，寄存器，register
- m，内存，memory
- imm，立即数，immediate，即存在指令中的立即数

x86-64架构下，汇编中寄存器具体名称：

<img src="https://static001.geekbang.org/resource/image/ed/0b/ed27329a1fb82df016d60a196yybb00b.jpg?wh=1920x2474" alt="img" style="zoom: 33%;" />



###### （2）工具：汇编在线编译器

https://godbolt.org/

```c
// Type your code here, or load an example.
int square(int num) {
    return num * num;
}
```

```assembly
square(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        imul    eax, eax
        pop     rbp
        ret
```



###### （3）一个C程序的完整生命周期

![img](https://static001.geekbang.org/resource/image/95/c2/957691f0ac44315ebf5619d553df4ac2.jpg?wh=1920x571)



###### （4）C语言与其他语言的不同

C语言，命令式编程语言的抽象程度更低，这意味着该类语言的语法结构可以直接由相应的机器指令来实现。

Javascript，声明式编程语言，抽象程度更高，这类语言更倾向于以叙事的方式来描述程序逻辑，开发者无需关心语言背后在机器指令层面的实现细节。两种语言在使用上各有其适用场景，并无孰好孰坏之分。



## C核心语法

##### （一）数据与常量是如何被组织的？

C 程序中的各类语法结构，究竟是如何映射到机器指令上的？

###### （1）变量

定义变量需要：

- 给数据指定一个类型
- 为数据设置一个名称
- 通过 `=` 设定具体的值

```c
int x = -10;  // 定义一个整型变量；
char y = 'c';  // 定义一个字符变量；
double z = 2.0;  // 定义一个双精度浮点变量；
```

###### （2）常量

在 C 语言中，通过内联方式直接写到源代码中的字面量值一般被称为“常量”。const 修饰的变量是只读变量，在程序运行时才确定的，而常量是编译时就已确定，二者是不同的。

下面代码误用常量导致编译错误：

```c
#include <stdio.h>
int main(void) {
  const int vx = 10;
  const int vy = 10;
  int arr[vx] = {1, 2, 3};  // [错误1] 使用非常量表达式定义定长数组；
  switch(vy) {
    case vx: {  // [错误2] 非常量表达式应用于 case 语句；
      printf("Value matched!");
      break;
    }
  }
}
```

###### （3）数据的存储形式

- 整数：补码存储
- 浮点数：IEEE-754 浮点数标准



###### （4）数据的存储位置

![img](https://static001.geekbang.org/resource/image/e9/0c/e9bbce8219b8dd12992da0bcc9499e0c.jpg?wh=1920x805)



##### （二）运算符是如何工作的？

- 赋值 `=` 对应汇编指令 `MOV`
- 加号 `+` 对应汇编指令 `ADD` 
- `|` 对应汇编指令 `or`
- `if` 对应汇编指令 `cmp`
- 汇编还有跳转指令 `je` 等，综合实现C语言 `&&` , `*` 等运算符。
- `&` 取地址运算符对应汇编指令`lea`
- `sizeof` 运算符，是在编译时就计算出大小，以常量形式写入到汇编代码。



##### （三）表达式和语句（分支循环跳转）

- 表达式，按运算符优先级转为AST结构，后序遍历即可求出值。
- `if` 语句，汇编通过 `cmp,je,jne` 指令实现。



