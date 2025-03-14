
import pprint

legs = {
    'dog': 4,
    'cat': 4,
    'chicken': 2,
    'spider': 8        
}

legs_list = [
    ('dog', 4),
    ('chicken', 2),
    ('cat', 4),
    ('spider', 8),
]

def get(xs, key):
    for (kk, vv) in xs:
        if kk == key:
            return vv
    raise Exception("key not found")
    
    
"""
Design a method that takes a list of numbers and
returns a list of how many times the number in
that positon appears in the list.

Example:
    input:  [7, 7, 1, 7, 2, 2, 7, 1, 3]
    output: [4, 4, 2, 4, 2, 2, 4, 2, 1]
"""

def repeats_v1(xs: list[int]) -> list[int]:
    """Do the thing described above."""
    
    ys = []
    
    for x in xs:
        count = 0
        
        for y in xs:
            if x == y:
                count += 1
        
        ys.append(count)
    
    return ys

def repeats(xs: list[int]) -> list[int]:
    """Do the thing described above."""
    
    ys = []
    
    counts = {}
    
#    for x in xs:
#        if x in counts:
#            counts[x] = counts[x] + 1
#        else:
#            counts[x] = 1
    for x in xs:
        count = counts.get(x, 0)
        counts[x] = count + 1    

    for x in xs:
        ys.append(counts[x])
    
    
    return ys

def test_repeats():
    assert (repeats([7, 7, 1, 7, 2, 2, 7, 1, 3]) ==
                    [4, 4, 2, 4, 2, 2, 4, 2, 1])
    
repeats([7, 7, 1, 7, 2, 2, 7, 1, 3])
    
    
"""
Given a drink menu and a list of drinks ordered,
calculate the price paid for each drink and give
a total.
"""

menu = {
    "Pineapple Juice": 3,
    "Old Fashioned": 12,
    "Coors Light": 8,
    "Spring Water": 34,
}

tab = [
    "Pineapple Juice",
    "Pineapple Juice",
    "Spring Water",
    "Coors Light",
    "Coors Light",
    "Coors Light",
    "Coors Light",
    "Coors Light",
    "Pineapple Juice",
]

def summarize_tab(menu, tab) -> None:
    
    counts = {}
    
    for name in tab:
        xx = counts.get(name, 0)
        counts[name] = xx + 1
    
    grand_total = 0
    
    for name in counts.keys():
        count = counts[name]
        total = count * menu[name]
        grand_total += total
        print(name, count, total)
    
    print("Total =", grand_total)
    

summarize_tab(menu, tab)

import re

offices = [
    "=== Office: Goat ===",
    "=== Office: Boat ===",
]

for ii in range(len(offices)):
    offices[ii] = re.sub(r"^\W{2}(.*)\W{2}$", "\\1", offices[ii])
  
    
print(offices)
    



















    
    