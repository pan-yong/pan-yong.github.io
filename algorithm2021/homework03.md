## 第三周  树与图

#### [355. 设计推特](https://leetcode-cn.com/problems/design-twitter/)





#### 课堂笔记

1. 二叉树的定义

```c++
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
}
```

```python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
```

```java
public class TreeNode{
    public int val;
    public TreeNode left, right;
    public TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}
```

```tex
疑问：
1. C++ / Python / Java 语法

```

2. 二叉树的遍历

- 前序：根--左子树--右子树
- 中序：左子树--根--右子树
- 后序：左子树--右子树--根
- 层次序
- 广度优先遍历
- 深度优先遍历