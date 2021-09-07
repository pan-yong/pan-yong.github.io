## 字符类型

```c
#include<stdio.h>
main()
{
    char ch = 'A';
    printf("%c", ch);  // putchar(ch);
}
```

- 字符类型标识符  `char`

- 字符常量：用单引号括起来的一个字符，例如，'A' 

- ASCII：字符在内存中实际存的是整数，也就是对应的ASCII码，'A' 的ASCII值是65，'a'是97，'0'是48。

- 转义字符：

  ```tex
  '\n'
  '\t'
  '\\'
  '\''
  '\"'
  '\x41'
  '\101'
  ```

- 上机练习

```c
// 输出字符常量 'A'
main()
{
    char c1 = 'A';
    printf("%c %d\n", c1, c1);
    
    char c2 = 65;
    printf("%c %d\n", c2, c2);
    
    putchar('\x41');
    putchar('\101');
    
}
```

