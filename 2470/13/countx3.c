#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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

    char tmp[100];
    long nn;

    while ((nn = read(fd, tmp, 100))) {
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
        close(fd);
    }

    printf("x = %d, l = %d\n", xcount, lcount);

    return 0;
}
