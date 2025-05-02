# Write a function in Python that takes a list of integers and returns that
# sequence of integers with all odd values doubled. 
# Show all 5 steps of the design recipe.

def double_odds(xs: list[int]) -> list[int]:
    """Double the odd integers"""
    ys = []

    for x in xs:
        if x % 2 == 1:
            x *= 2
        ys.append(x)

    return ys

"""
def std_pattern():
    ys = []

    for x in xs:
        ys.append(... x ...)

    return ys
"""


def test_double_odds():
    assert double_odds([1,2,3,4]) == [2, 2, 6, 4]
