

def sum1(xs: list[int]) -> int:
    """Calculate the sum of the numbers."""

    yy = 0

    for x in xs:
        yy += x
    
    return yy


def sum2(xs: list[int]) -> int:
    """Calculate the sum of the numbers."""
    
    # The base case needs to return
    # with no recursive call.
    if len(xs) == 0:
        return 0
    
    # The general case makes a recursive call
    # which must be on a smaller intance of the problem.
    return xs[0] + sum2(xs[1:])



if __name__ == '__main__':
    xs = [1,2,3,4]
    print(sum1(xs))
    print(sum2(xs))