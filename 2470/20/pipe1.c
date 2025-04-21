#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int cpid;
    int fds[2];

    int rv = pipe(fds);
    assert(rv == 0);

    int p_read = fds[0];
    int p_write = fds[1];

    if ((cpid = fork())) {
        close(p_read);

        printf("In parent, pid = %d, child is = %d\n", getpid(), cpid);
        // parent
        char msg[] = "Hello, pipe.\n";
        rv = write(p_write, msg, strlen(msg));
        assert(rv >= 0);
    } else {
        close(p_write);

        printf("In child, pid = %d\n", getpid());

        // child
        char tmp[100];
        rv = read(p_read, tmp, 100);
        assert(rv >= 0);

        tmp[rv] = 0;
        rv = write(1, tmp, strlen(tmp));
        assert(rv >= 0);
    }

    return 0;
}
