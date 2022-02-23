#!/usr/bin/env python3

def func (a, b, c):
	print('a=%s' %a)
	print('b=%s' %b)
	print('c=%s' %c)
	
func(1, 0, c=3)

# 获取参数个数
def howlong(first, *other):
	print(1+len(other))
	
howlong(1,2,3)