## hello world

##### 1. 第一个简单的C程序

```c
#include<stdio.h>
main()
{
    printf("hello world\n");
}
```

```tex
代码说明：
所有代码必须使用英文输入法输入
#        预处理
include  包含
stdio.h  标准输入输出头文件
main(){} 主函数，C程序的入口，必须要有且只有一个。
printf   输出函数
\n       表示换行
;        每条C语言语句以分号结束
//       单行注释 
/**/     多行注释

```

编写C程序步骤:

```tex
第1步：打开编辑器。
第2步：编写源代码。
第3步：编译-->链接-->运行（可执行二进制文件）
```

##### 2. 编写C程序的工具

编写C程序的工具有很多，macOS、Windows、Linux、我们使用的手机、甚至使用浏览器[在线编译器](https://c.runoob.com/compile/11/)等都可以编写C程序。

**Windows**

- [Dev C++](https://bloodshed-dev-c.en.softonic.com/) 

  ```tex
  Dev C++  -->  文件  -->  新建源代码 --> 编写代码保存  --> 编译链接运行
  ```

- gcc + vscode

- Microsoft Visual C++ 2010 

**macOS**

- CodeRunner
- gcc + vscode
- Xcode



##### 3.编译错误的处理

当编写的代码不符合语法规则时，编译器会报错。我们要学会查看编译器给出的错误信息，根据提示修改代码。初学者常见错误：

- 没写分号

  > 编译器给出了错误所在行，及期待的修改信息。英语不认识？搜索查询，就这么几个单词，多查几次就会了。

  <img src=".\images\debugerror.png" alt="image-20211209095835237" style="zoom:60%;" />

  

- 函数少打了括号

  > 有的时候编译器并不能准确的给出错误信息，但是根据报错提示，可以大致定位错误所在行。

  <img src=".\images\functionerror.png" alt="image-20211209103446412" style="zoom:680%;" />

  

- 代码符号使用了中文输入法

  > 编译器有时候报很多奇怪的错误，不要怕，也许很容易解决。下图错误，把中文输入法切换为英文输入法，改写引号即可。

  <img src=".\images\shurufaerror.png" alt="image-20211209104802390" style="zoom:90%;" />

- 函数名拼写错误

  > 不同的平台，不同的编译器，报错信息会有差异。下面是一条Windows系统Dev C++编译器给出的报错信息。

  <img src=".\images\mainerror.png" alt="image-20211209102933736" style="zoom:60%;" />

  

- 初学者还有一个问题，就是打字问题，效率极低。要么指法不规范，输入用手指一个一个点，要么不记得一些符号在键盘上的位置，一个字符盯着键盘找半天。平时打字不常用但在C语言中常用的符号：`#  %  &  (  ) ; : '  "  <  >  ` 等，要刻意练习。

  > 初学者，要练习英文盲打，熟悉常用符号所在位置。

  <img src=".\images\打字" alt="img" style="zoom:70%;" />



##### 作业

- 修改下面程序中的错误

  ```tex
  （1）
      #include<stdio.h>
      int main
      {
          printf("hello, world");
          return 0;
      }
  ```

  ```tex
  （2）
      #include<stdio.h>
      int main()
      {
          printf("hello, world")
          return 0;
      }
  ```

  ```tex
  （3）
      include<stdio.h>
      main()
      {
          printf("hello, world");
          return 0;
      }
  ```

- 输出一如下图形：

  ```tex
  A
  BC
  DEF
  GHIJ
  KLMNO
  PQRSTU
  V
  W
  X
  Y
  Z
  ```

- 输出你的中文名字

  ```tex
  windows下可以通过下面一行代码设置字体颜色：
  
  system("color F5"); 
  
  两个十六进制数，第一个为背景，第二个则为前景
  0 = 黑色 8 = 灰色
  1 = 蓝色 9 = 淡蓝色
  2 = 绿色 A = 淡绿色
  3 = 湖蓝色 B = 淡浅绿色
  4 = 红色 C = 淡红色
  5 = 紫色 D = 淡紫色
  6 = 黄色 E = 淡黄色
  7 = 白色 F = 亮白色
  ```

- [题目 1001: [编程入门]第一个HelloWorld程序](https://www.dotcpp.com/oj/problem1001.html)



##### 小结

本节主要编写了第一个C程序，介绍了编写C程序的工具，以及编译错误的处理。知道了如何开始上机编写C程序。



##### 参考资料

- [《C程序设计语言》](https://book.douban.com/subject/1139336/)

- [dotcpp](https://www.dotcpp.com/)：编程题可以上这个网站提交，在线判题，验证代码是否正确。
