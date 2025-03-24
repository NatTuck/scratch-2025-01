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

    char line[100];
    line[99] = 0;

    while (fgets(line, 99, fh)) {
        lcount += 1;
        for (int ii = 0; line[ii]; ++ii) {
            if (line[ii] == 'x') {
                xcount += 1;
            }
        }
    }

    if (argc == 2) {
        fclose(fh);
    }

    printf("x = %d, l = %d\n", xcount, lcount);

    return 0;
}
