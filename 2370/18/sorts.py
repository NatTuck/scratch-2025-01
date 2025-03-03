
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
        
                
        
    
    
    
    