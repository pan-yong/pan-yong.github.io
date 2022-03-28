## 构建Go工程笔记

### 第一个Go程序
1. GOPATH
   把当前工程目录添加到 GOPATH，VSCode要重启，GOPAT环境变量才生效。

2. 目录结构
   src   源代码目录，自定义package都放在此目录下
   bin   二进制文件生成目录，编译命令 go build calc 

3. 单元测试
   由于项目已经设置了GOPATH，故可以在任意目录下执行：go test simplemath

### 第二个Go程序
4. pkg和bin目录
   go install algorithms/bubblesort
   可以看到在工程目录下会生成 pkg 文件夹

   go install sorter
   可以看到在工程目录bin下面生成可执行文件

5. Go语言使用感受：确实是更好的C语言


### 面向对象编程
在Go语言中，面向对象的神秘面纱被剥得一干二净。


### Windows PowerShell
将Windows PowerShell路径提示隐藏，仅显示当前文件夹名称
   
   打开文件：%userprofile%\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1

   添加内容：
   function prompt {
   $p = Split-Path -leaf -path (Get-Location)
   "$p> "
   }

   重启 PowerShell

   参考自：https://qa.1r1g.cn/superuser/ask/31277921/
