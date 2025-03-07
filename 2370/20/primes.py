
from math import sqrt

count = 0

def is_prime(xx: int) -> bool:
    global count

    #top = xx
    #top = 1 + xx // 2
    top = 1 + int(sqrt(nn))
    if top >= xx:
        top = xx

    for ii in range(2, top):
        count += 1

        if xx % ii == 0:
            #print(xx, "not prime because", ii)
            return False

    #print(xx, "is prime")
    return True


def list_primes(nn):
    """Find all the primes from 2 up to nn-1"""

    ys = []
    
    for ii in range(2, nn):
        if is_prime(ii):
            ys.append(ii)

    return ys


def count_primes(nn):
    return len(list_primes(nn))



import sys

if __name__ == '__main__':
    nn = int(sys.argv[1])

    if nn <= 100:
        print(list_primes(nn))
        count = 0

    print("# of primes  = ", count_primes(nn))
    print("# of modulos = ", count)
