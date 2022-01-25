#!/usr/bin/env python3

# 将小说的主要人物记录在文件中

file1 = open('name.txt','w')
file1.write('诸葛亮')
file1.close()

file2 = open('name.txt')
print(file2.read())

file3 = open('name.txt','a')
file3.write('刘备')
file3.close()

file4 = open('name.txt')
print (file4.readline())
file4.close()

file5 = open('name.txt')
for line in file5.readlines():
	print(line)
	print('========')
	
file5.tell()
file5.seek(0)