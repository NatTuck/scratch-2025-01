


def mystery(xx: int) -> int:
    print(xx)
    
    if xx == 1:
        print("done")
        return 0
    
    if xx % 2 == 0:
        return 1 + mystery(xx // 2)
    
    return 1 + mystery(xx * 3 + 1)
    
    

if __name__ == '__main__':
    print("calls =", mystery(3))