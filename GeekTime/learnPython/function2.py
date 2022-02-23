#!/usr/bin/env python3

# 定义函数计算直线方程  y = ax + b

# 普通函数方式
def line(a, b, x):
	return a*x + b

print(line(3,4,5))
print(line(3,4,8))  # 调用不够优雅
print(line(1,3,9))


# 闭包的形式：返回内部函数
def a_line(a,b):
	def arg_y(x):
		return a*x+b
	return arg_y

line1 = a_line(3, 4) #调用更优雅
print(line1(5))
print(line1(8))
line2 = a_line(1,3)
print(line2(9))


# 闭包
def counter(first = 0):
	cnt = [first]
	def add_one():
		cnt[0] += 1
		return cnt[0]
	return add_one

num1 = counter(5)
print(num1())  # 调用1次，加1
print(num1())  # 调用1次，加1