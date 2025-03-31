
def addX(x):

    def inc():
        nonlocal x
        x = x + 1

    def add(y):
        return x + y

    return (add, inc)


(add3, inc) = addX(3)

print(add3(5)) # 8
print(add3(8)) # 11

inc()
inc()

print(add3(5)) # 10
print(add3(8)) # 13
