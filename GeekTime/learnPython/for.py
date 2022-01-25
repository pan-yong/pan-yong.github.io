#!/usr/bin/env python3

for i in range(1,13):
	print(i)

chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'
for year in range(2000, 2019):
	print('%s 年的生肖是 %s' %(year,chinese_zodiac[year%12]))


# 从1到10所有偶数的平方
	
alist = []
for i in range(1,11):
	if (i%2==0):
		alist.append(i*i)
print(alist)

blist = [i*i for i in range(1,11) if (i%2)==0]

z_num = {}
for i in zodiac_name:
	z_num[i] = 0

z_num = {i:0 for i in zodiac_name}