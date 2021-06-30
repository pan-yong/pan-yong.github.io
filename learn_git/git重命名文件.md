## git重命名文件

- 重命名文件

  ```tex
  方法一：
  mv read readme.md
  git add readme.md
  git rm readme
  
  git复原数据，不保存上面的操作
  git reset --hard 
  
  方法二：
  git mv read readme.md

- 查看版本历史

```tex
git log
git log --graph
git help --web log
gitk 图形界面查看版本信息
```

