#!/usr/bin/env python3

# 函数更简洁的写法：lambda表达式

def true():
	return True

# 简化
def true(): return True
	
# 更进一步简化  把函数名也省略掉
lambda : True

# 再看一个例子
def add(x, y):
	return x + y

def add(x,y): return x+y

lambda x,y: x+y

