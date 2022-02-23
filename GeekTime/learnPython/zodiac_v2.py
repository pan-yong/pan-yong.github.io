#!/usr/bin/env python3

zodiac_name = (u'魔蝎座', u'水瓶座', u'双鱼座', u'白羊座',u'金牛座', u'双子座',
	u'巨蟹座',u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座')

zodiac_days = ((1,20), (2,19), (3,21), (4,21), (5,21), (6,22),
	(7,23),(8,23),(9,23),(10,23),(11,23),(12,23))

month = int(input('请输入月份：'))
day = int(input('请输入日期：'))

# for 循环实现星座转换
for zd_num in range(len(zodiac_days)):
	if zodiac_days[zd_num] >= (month, day):
		print(zodiac_name[zd_num])
		break
	elif month == 12 and day > 23:
		print(zodiac_name[0])
		break
#zodiac_day = filter(lambda x: x<=(month,day), zodiac_days)
#zodac_len = len(list(zodiac_day)) % 12
#print(zodiac_name[zodac_len])

# while 循环实现星座转换
n = 0
if month == 12 and day > 23:
	print(zodiac_name[0])
else:
	while zodiac_days[n] < (month, day):
		n = n + 1
	print(zodiac_name[n])