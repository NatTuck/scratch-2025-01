
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
is_prime(long xx)
{
    for (long ii = 2; ii < xx; ++ii) {
        if (xx % ii == 0) {
            return 0;
        }
    }
    return 1;
}

int
main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("nope");
        exit(1);
    }

    long nn = atol(argv[1]);

    long primes[nn < 3 ? 3 : nn];
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;

    long cc = 7;
    long ii = 3;
    while (ii <= nn) {
        printf("ii = %ld, cc = %ld\n", ii, cc);
        while (1) {
            if (is_prime(cc)) {
                printf("Conditoin was true\n");
                primes[ii] = cc;
                break;
            }
            cc++;
        }
        cc++;
        ii++;
    }

    printf("prime #%ld = %ld\n", nn, primes[nn]);
    return 0;
}
