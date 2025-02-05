#include <stdio.h>


int
main(int argc, char* argv[])
{
    char buf[128];

    FILE* fh = fopen("msg.txt", "r");
    int yy = fread(buf, 1, 128, fh);
    buf[yy] = 0;
    fclose(fh);

    int count = 0;
    for (int ii = 0; buf[ii] != 0; ++ii) {
        if (buf[ii] == '\n') {
            count += 1;
        }
    }
    printf("# of lines is %d\n", count);
    return 0;
}
