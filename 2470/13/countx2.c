#include <stdio.h>


int
main(int argc, char* argv[])
{
    FILE* fh;
    if (argc == 2) {
        fh = fopen(argv[1], "r");
    }
    else {
        fh = stdin;
    }

    int xcount = 0;
    int lcount = 0;

    char tmp[100];
    long nn;

    while ((nn = fread(tmp, 1, 100, fh))) {
        for (int ii = 0; ii < nn; ++ii) {
            if (tmp[ii] == 'x') {
                xcount += 1;
            }
            if (tmp[ii] == '\n') {
                lcount += 1;
            }
        }
    }

    if (argc == 2) {
        fclose(fh);
    }

    printf("x = %d, l = %d\n", xcount, lcount);

    return 0;
}
