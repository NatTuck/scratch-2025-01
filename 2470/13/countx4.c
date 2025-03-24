#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char blob[8]; // read buffer
int  bptr = 0;

int
rdln(int fd, char* buf, long sz)
{
    int count;
    int optr = 0;

    while (1) {
        count = read(fd, blob + bptr, 8 - bptr);
        if (count == 0) {
            return 0;
        }
        bptr += count;
        printf("Read into blob: %.8s\n", blob);

        for (int ii = 0; ii < bptr; ++ii) {
            buf[optr++] = blob[ii];
            if (blob[ii] = '\n') {
                if (ii < bptr) {
                    memmove(blob,
                            blob + ii + 1,
                            bptr - (ii + 1));
                    bptr = 8 - (ii + 1);
                    goto have_line;
                }
            }
        }
    }
 have_line:
    return 1;
}

int
main(int argc, char* argv[])
{
    int fd;
    if (argc == 2) {
        fd = open(argv[1], 0);
    }
    else {
        fd = 0;
    }

    printf("Opened a file, fd = %d\n", fd);

    int xcount = 0;
    int lcount = 0;

    char line[100];
    line[99] = 0;

    while (rdln(fd, line, 99)) {
        lcount += 1;
        for (int ii = 0; line[ii]; ++ii) {
            if (line[ii] == 'x') {
                xcount += 1;
            }
        }
    }

    if (argc == 2) {
        close(fd);
    }

    printf("x = %d, l = %d\n", xcount, lcount);

    return 0;
}
