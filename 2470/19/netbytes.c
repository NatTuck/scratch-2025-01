
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int xx = 258;

    char* xbytes = (char*)&xx;

    for (int ii = 0; ii < 4; ++ii) {
        printf("x byte #%d = %d\n", ii, xbytes[ii]);
    }

    int nn = htonl(xx);

    char* nbytes = (char*)&nn;

    for (int ii = 0; ii < 4; ++ii) {
        printf("n byte #%d = %d\n", ii, nbytes[ii]);
    }

    return 0;
}
