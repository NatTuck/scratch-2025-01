

# Two properties of lists:
#  - Lists allow duplicates.
#  - Lists care about order.

# New collection type: Set
#  - Sets ignore duplicates
#  - Sets ingore order

day1 = {"Alice", "Bob", "Carol", "Dave"}
day2 = {"Bob", "Alice", "Carol", "Dave", "Alice"}

if day1 == day2:
    print("It was the same people")
else:
    print("It was different people")


# Three standardard patterns

#def foo(aa: set[int]) -> None:
#    """Do something with each item in set."""
#    for a in aa:
#        a
#
#def bar(aa: set[int]) -> None:
#    """Do a set operation with a set."""
#    aa # With some standard set operation
#
#
#def baz() -> set[int]:
#    aa = set()
#    aa.add(7)
#    return aa

import math

def biggest(aa: set[int]) -> int:
    """Find biggest number in set."""

    yy = list(aa)[0]
    
    for a in aa:
        if a > yy:
            yy = a

    return yy

    
def test_biggest():
    assert biggest({1,2,3}) == 3
    assert biggest({30, 20, 25}) == 30



def items_in_set(xs: list[int], aa: set[int]) -> list[int]:
    """Return the items from the list that are in the set."""

    ys = []
    
    for x in xs:
        # We could loop:
        # for a in aa:

        if x in aa:
            ys.append(x)

    return ys


def test_items_in_set():
    assert items_in_set([2, 1, 2], {2, 4, 6}) == [2, 2]
    assert items_in_set([2, 4, 6, 8, 10, 12], {1, 2, 3, 4}) == [2, 4]
    
