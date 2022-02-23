#!/usr/bin/env python3

list1 = [1,2,3]
it = iter(list1)  # 迭代器
print(next(it))
print(next(it))
print(next(it))


for i in range(10,20,2):  #迭代器   10 12 14 16 18
	print(i)

	
# 生成器  构建迭代器
def frange(start, stop, step):
	x = start
	while x < stop :
		yield x    
		x += step
		
for i in frange(10,20,0.5): 
	print(i)
	
 