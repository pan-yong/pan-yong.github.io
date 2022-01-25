#!/usr/bin/env python3

chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'

year = int(input('请输入出生年份: '))
if chinese_zodiac[year%12] == '虎' :
	print("虎年运势...")

