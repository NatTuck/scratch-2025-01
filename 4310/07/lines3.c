
#include <fcntl.h>
#include <unistd.h>

int myopen(const char*, int);

int
main(int argc, char* argv[])
{
    char buf[128];

    int fd = myopen("msg.txt", O_RDONLY);

    int yy = read(fd, buf, 128);
    buf[yy] = 0;
    close(fd);

    int count = 0;
    for (int ii = 0; buf[ii] != 0; ++ii) {
        if (buf[ii] == '\n') {
            count += 1;
        }
    }
    
    char outb[10];
    outb[0] = '0' + count;
    outb[1] = '\n';
    outb[2] = '0';

    write(1, outb, 2);
    return 0;
}
