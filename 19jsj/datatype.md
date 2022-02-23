## 数据类型

#### （一）基本数据类型

- 基本数据类型：`char`, `int`, `float` 。文档：https://wangdoc.com/clang/types.html

<img src="images/datatype.png" alt="img" style="zoom: 25%;" />

- 位运算：`&` , `|` , `~` , `^`, `<<` , `>>`。文档：https://wangdoc.com/clang/operator.html

<img src="images/operator.png" alt="img" style="zoom: 25%;" />



- 二进制补码：C语言中，整数是以二进制补码进行存储的，最高位为符号位， `0`表示正，`1`表示负数。正数的补码等于原码，负数的补码等于原码的反码加1。

```c
00000000 00000000 00000000 01010011  // 83的原码，最高位0表示正数
10000000 00000000 00000000 01010011  //-83的原码，最高位1表示负数
11111111 11111111 11111111 10101100  // 反码=按位取反，符号位不变
11111111 11111111 11111111 10101101  // 补码=反码+1。十六进制形式 0xffffffad
```

#### （二）指针与数组

- 指针：https://wangdoc.com/clang/pointer.html

<img src="images/pointer.png" alt="img" style="zoom: 25%;" />

- 数组：https://wangdoc.com/clang/array.html

<img src="images/array.png" alt="img" style="zoom: 25%;" />

#### （三）结构体联合体和枚举型

- `struct` 结构：https://wangdoc.com/clang/struct.html

<img src="images/struct.png" alt="img" style="zoom: 25%;" />

- `Union` 结构：https://wangdoc.com/clang/union.html

<img src="images/union.png" alt="img" style="zoom: 25%;" />

- `Enum` 类型：https://wangdoc.com/clang/enum.html

<img src="images/enum" alt="img" style="zoom: 25%;" />

