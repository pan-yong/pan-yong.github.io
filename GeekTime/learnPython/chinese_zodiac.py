#!/usr/bin/env python3

# 记录生肖，根据年份判断生肖
chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'

year = 2022
print(chinese_zodiac[year%12])

print('狗' in chinese_zodiac)
print(chinese_zodiac[0:4])
print(chinese_zodiac + ' 2022')
print(chinese_zodiac *3)