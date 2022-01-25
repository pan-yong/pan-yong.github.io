#!/usr/bin/env python3

import re

def find_item(hero):
	with open('sanguo.txt',encoding='GB18030') as f:
		data = f.read().replace('\n', '')
		num = len(re.findall(hero, data))
	return num


# 读取人物信息
name_dict = {}
with open('name.txt') as f:
	for line in f:
		names = line.split('|')
		for name in names:
			num = find_item(name)
			name_dict[name] = num
print(name_dict)

# 读取武器信息
weapon_dict = {}
with open('weapon.txt') as f:
	i = 1
	for line in f:
		if i%2 == 1:
			name = line.strip('\n')
			num = find_item(name)
			weapon_dict[name] = num
		i = i + 1
print(weapon_dict)