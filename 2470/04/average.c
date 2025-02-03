/*
 *     $ ./average 4
 *     > 10
 *     > 10
 *     > 20
 *     > 20
 *     The average is 15
 */

#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char* argv[])
{
    long nn = atol(argv[1]);
    long* xs = malloc(nn * sizeof(long));
    // long xs[nn];

    for (long ii = 0; ii < nn; ++ii) {
        scanf("%ld", &(xs[ii]));
    }

    long sum = 0;
    //for (long* ys = xs; ys < (xs + nn); ++ys) {
    //    sum += *ys;
    //}
    for (long ii = 0; ii < nn; ++ii) {
        //sum += xs[ii];
        //sum += *(xs + ii);
        //sum += *(ii + xs);
        sum += ii[xs];
    }

    long avg = sum / nn;
    printf("average = %ld\n", avg);

    free(xs);
    return 0;
}


