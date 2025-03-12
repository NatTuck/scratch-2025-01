
from math import sqrt

count = 0

def is_prime(xx: int, primes: list[int]) -> bool:
    global count

    #print("is_prime", xx, primes)

    #top = xx
    #top = 1 + xx // 2
    top = 1 + int(sqrt(xx))
    if top >= xx:
        top = xx

    #print("for candiate", xx, "top is", top)
        
    ii = 0
    while primes[ii] <= top:
        count += 1

        if xx % primes[ii] == 0:
            #print(xx, "not prime because", ii)
            return False

        ii += 1

    #print(xx, "is prime")
    return True


def list_primes(nn):
    """Find all the primes from 2 up to nn-1"""

    ys = [2, 3, 5, 7, 11]

    ii = 13
    while ii < nn:
        if is_prime(ii, ys):
            ys.append(ii)
        ii += 2

    return ys


def count_primes(nn):
    return len(list_primes(nn))



import sys

if __name__ == '__main__':
    nn = int(sys.argv[1])

    xs = list_primes(nn)
    
    if nn <= 100:
        print(xs)

    print("# of primes  = ", len(xs))
    print("# of modulos = ", count)
