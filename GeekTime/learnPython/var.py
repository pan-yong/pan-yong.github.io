#!/usr/bin/env python3

var = 123

def func():
	print(var)  #访问全局变量
	

def func2():
	var = 456
	print(var) #访问局部变量
	

def func3():
	global var
	var = 789  #访问全局变量
	print(var)
	
func()
func2()
func3()
func()