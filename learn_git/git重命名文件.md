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

