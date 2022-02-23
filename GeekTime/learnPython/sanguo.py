#!/usr/bin/env python3
# 统计三国中各个人物出现的次数

```
# 1. 读取人物名称
f = open('name.txt')
data = f.read()
print(data.split('|'))

# 2. 读取兵器名称
f2 = open('weapon.txt')
#data2 = f2.read()
i = 1
for line in f2.readlines():
	if i%2 == 1:
		print(line.strip('\n'))
	i += 1
	
# 3. 读取三国全文
f3 = open('sanguo.txt', encoding='GB18030')
print(f3.read().replace('\n',''))

