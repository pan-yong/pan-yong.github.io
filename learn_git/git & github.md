## git & github

###### 1. git

- 最小配置

```tex
git config --global user.name "pan-yong"
git config --global user.email "passion.py@gmail.com"
git config --global --list

--global 表示对当前用户所有仓库有效
--local  表示只对某个仓库有效
--system 表示所有登陆的用户有效
```

- 在本地建立初始仓库

```tex
git init

或者

git init learn_git  
cd learn_git
```

- 工作区、暂存区、仓库

```tex
git status
git add .    
git commit -m "message"
git log
```



![image-20210628105228466](.\images\image-20210628105228466.png)

- 把本地仓库同步到远程github 仓库

```tex
git remote add origin git@github.com:GeekUniversity/learn_git.git

ssh-keygen -t rsa -C "passion.py@gmail.com"
cat id_rsa.pub  把公钥配置到Github

ssh -T git@github.com   测试本地仓库是否和远程仓库建立连接

git push -u origin master
```

