
people = ["Alice", "Bob", "Carol", "Dave", "Erin", "Frank"]


# Design a function that, given a list of strings,
# determines the total length of all the strings combined.

def total_length(xs: list[str]) -> int:
    """Get total length of strings in list."""
    yy = 0
    for xx in xs:
        yy += len(xx)
    return yy

    ## Standard pattern
    #   (declare the int we return)
    # yy = 0
    #   (loop through our list)
    # for xx in xs:
    #   (use each item)
    #    xx
    #   (return an int)
    # return yy

def test_total_length():
    assert total_length(["aa", "bbb"]) == 5


def smallest(xs: list[int]) -> int:
    """Find the smallest number in the 
       list of non-negative integers."""
    if len(xs) == 0:
        raise Exception("empty list")
    
    yy = xs[0]
    for xx in xs:
        if xx < yy:
            yy = xx
    return yy

def test_smallest():
    assert smallest([5, 6, 10, 2]) == 2
    assert smallest([10, 20, 15, 12]) == 10



# Design a function that doubles each
# number in a list, producing a new list.

def double_all(xs: list[int]) -> list[int]:
    """Double each integer in list."""
    ys = []
    for xx in xs:
        ys.append(xx * 2) 
    return ys    


def test_double_all():
    assert double_all([]) == []
    assert double_all([1, 2, 3]) == [2, 4, 6]


# A cash register contains pennies, nickles,
# dimes, and quarters.
#
# We want to return the total value of all
# the coins in the register, except for pennies
# from 1923 - we want a count of those.

from collections import namedtuple

Coin = namedtuple("Coin", ["type", "year"])
Result = namedtuple("Result", ["value", "penny_count"])

def register_total(coins: list[Coin]) -> Result:
    """Count coins in register, handle 1923 pennies special."""
    value = 0
    penny_count = 0
    
    for coin in coins:
        (type, year) = coin
        
        if type == "penny" and year == 1923:
            penny_count += 1
        else:
            value += coin_value(type)
    
    return Result(value, penny_count)

def test_register_total():
    coins = [
        Coin("penny", 1927), 
        Coin("penny", 1923),
        Coin("nickle", 1972),
        Coin("dime", 1881),
    ]
    assert register_total(coins) == Result(16, 1)


def coin_value(name):
    """How many cents is a coin worth"""
    if type == "penny": return 1
    if type == "nickle": return 5
    if type == "dime": return 10
    if type == "quarter": return 25
    raise Exception("unknown coin")

def test_coin_value()
    assert coin_value("penny") == 1
    assert coin_value("nickle") == 5
    assert coin_value("dime") == 10
    assert coin_value("quarter") == 25
    

