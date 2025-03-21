
from random import randint


def random_list(nn: int) -> list[int]:
    ys = []
    
    for ii in range(0, nn):
        ys.append(randint(0, 99))
    
    return ys
    


def isort(xs: list[int]) -> list[int]:
    """Sort a list of ints."""
    ys = []
    
    # (n * (n-1)) / 2
    # insertion sort takes about n^2 operations
    
    for x in xs:  # call insert n times
        ys = insert(x, ys)
    return ys


def insert(x: int, ys: list[int]) -> list[int]:
    """Insert an int into a sorted list in sorted order."""
    zs = []
    
    for y in ys:      # 0..n operations
        if y <= x:
            zs.append(y)

    zs.append(x)

    for y in ys:
        if y > x:
            zs.append(y)

    return zs



def ssort(xs: list[int]) -> None:
    """Sort our input list, in place."""

    # Selection sort runs in n^2 time.
    
    # "done" is how many items we've selected
    for done in range(0, len(xs)):
        smallest_idx = done
       
        for ii in range(done, len(xs)):
            if xs[ii] < xs[smallest_idx]:
                smallest_idx = ii
        
        # Swap xs[done] with xs[smallest_idx]
        p = xs[done]
        xs[done] = xs[smallest_idx]
        xs[smallest_idx] = p


def merge(xs, ys):
    zs = []

    ii = 0 # position in xs
    jj = 0 # position in ys
    
    while ii < len(xs) or jj < len(ys):
        if ii >= len(xs):
            zs += ys[jj:]
            break
        
        if jj >= len(ys):
            zs += xs[ii:]
            break
        
        if xs[ii] < ys[jj]:
            # take next item from xs
            zs.append(xs[ii])
            ii += 1
        else:
            # take next item from ys
            zs.append(ys[jj])
            jj += 1
  
    return zs
        

    
def merge_sort(xs):
    sz = len(xs)
    
    if sz <= 1:
        return xs
    
    mid = sz // 2
    
    ys0 = merge_sort(xs[0:mid])
    ys1 = merge_sort(xs[mid:sz])
    
    return merge(ys0, ys1)
    
    
from math import log

def nsquared(n):
    return n * n

def nlogn(n):
    return n * log(n, 2)

print("n\tn*n\tn*log n")

for j in range(1, 21):
    i = j * 100
    print(i, "\t", nsquared(i), "\t", round(nlogn(i))) 





    
    
    
    
    