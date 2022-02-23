#!/usr/bin/env python3

# 常见异常

#a = '123'
#print(a[3])  		#IndexError

#d = {'a':1, 'b':2}
#print(d['c']) 		#KeyError

# ValueError
#try:
#	year = int(input('input year:'))  
#except ValueError:
#	print('年份要输入数字！')

# AttributeError
#a = 123
#a.append()

#try:
#	print(1/0)
#except (AttributeError, ValueError,KeyError,ZeroDivisionError) as e:
#	print('0不能做除数 %s' %e)
	
# 捕获所有错误信息
#try:
#	print(1/'a')
#except Exception as e:
#	print(' %s' %e)
	
# 自定义异常
#try:
#	raise NameError('helloError')
#except NameError:
#	print('my custom error')

try:
	a = open('name.txt')
except Exception as e:
	print(e)
finally:
	a.close()