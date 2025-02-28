

def add1all(xs: list[int]) -> list[int]: 
    """Add one to each item in a list."""

    ys = []

    for x in xs:
        ys.append(x + 1)

    return ys


def test_add1all():
    assert add1all([]) == []
    assert add1all([2, 4, 6]) == [3, 5, 7]


# This might be a "procedure" rather than a "function".
def add1each(xs: list[int]) -> None:
    """Add one to each item in a list, in place."""

    for ii in range(0, len(xs)):
        xs[ii] += 1
        
        
def test_add1each():
    xs1 = [2, 4, 6]
    add1each(xs1)
    assert xs1 == [3, 5, 7]



def even_numbers(nn: int) -> list[int]:
    """List the first nn even numbers."""

    ys = []

    for ii in range(0, nn):
        ys.append(ii * 2)

    return ys

def test_even_numbers():
    assert even_numbers(5) == [0, 2, 4, 6, 8]





