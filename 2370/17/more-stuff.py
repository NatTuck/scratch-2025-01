
#xs = [1, 2, 3]
#print(xs)

#ys = xs

#ys[1] = 4

#print(xs)
#print(ys)


#x = 2

#print(x)

#y = x

#y += 1

#print(x)
#print(y)

# Primitive / simple / atomic types
#
#  - int, float, boolean, ...
#
# Object / complex / composites types
#
#  - List, Tuple, Object, ...


#def inc_first(vv: tuple[int, int]) -> tuple[int, int]:
#    (a, b) = vv
#    return (a + 1, b)

#x = (1, 2)
#print(x)

#y = x
#y = inc_first(x)
#print(x)
#print(y)

def capsize(x):
    (a, b) = x
    a[0] += 1
    

goat = ([1, 2], 3)
boat = goat

#print(goat)
#print(boat)

capsize(boat)

#print(goat)
#print(boat)



def add3(x):
    x = x + 1
    x = x + 1
    x = x + 1
    return x

aa = 12
bb = add3(aa)










