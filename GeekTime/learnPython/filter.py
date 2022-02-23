#!/usr/bin/env python3

#help(filter)
a = [1,2,3,4,5,6,7]
b = list(filter(lambda x: x > 2, a))
print(b)

#help(map)
c = [1,2,3]
d = [4,5,6]
e = list(map(lambda x,y:x+y , c, d))
print(e)


#help(reduce)
from functools import reduce
r = reduce(lambda x,y: x+y, [2,3,4], 1)  #(((1+2)+3)+4)
print(r)


#help(zip)

for i in zip((1,2,3), (4,5,6)):
	print(i)
	
	
dicta = {'a':'aa' , 'b':'bb'}
dictb = zip(dicta.values(), dicta.keys())
print(dict(dictb))