
def sort_ints(xs: list[int]) -> list[int]:
    """Sort a list of integers."""

    ys = []

    for x in xs:
        ys = insert(x, ys)

    return ys



def test_sort_ints():
    assert sort_ints([]) == []
    assert sort_ints([1, 2]) == [1, 2]
    assert (sort_ints([32, 14, 81, -16, 0, 29, 31]) ==
        [-16, 0, 14, 29, 31, 32, 81])
    
    
def insert(x: int, ys: list[int]) -> list[int]:
    """Insert x into ys such that the result is
    in ascending order"""
    
    zs = []
    
    for y in ys:
        if y < x:
            zs.append(y)
        
    zs.append(x)
    
    for y in ys:
        if y >= x:
            zs.append(y)
    
    return zs
        
def test_insert():
    assert insert(5, []) == [5]
    assert insert(2, [5]) == [2, 5]
    assert insert(5, [2]) == [2, 5]
    assert insert(5, [5, 5, 6, 7]) == [5, 5, 5, 6, 7]
    
    
from collections import namedtuple

EmptyType = namedtuple("Empty", [])

empty = EmptyType()
Cell = namedtuple("Cell", ["first", "rest"])


example1 = Cell(2, Cell(3, Cell(5, empty)))

def print_cells(xs):
    """Print a cell list like a regular list"""
    if xs == empty:
        return
    
    (first, rest) = xs
    
    print(str(first) + ", ")
    print_cells(rest)
    
def sum_cells(xs):
    """Sum the integers in cell list"""
    if xs == empty:
        return 0
    
    (first, rest) = xs
    
    return first + sum_cells(rest)
    

ys = [1,2,4,5]

def sum_ints(xs):
    yy = 0
    for x in xs:
        yy += x
    return yy


def sum_ints_r(xs):
    if len(xs) == 0:
        return 0
    
    return xs[0] + sum_ints_r(xs[1:])





    
    
    
    
    
    
    
    
    
    


    
    
    
    
    
    
    
    
    