
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

int
main(int argc, char* argv[])
{
    int fd = open("/tmp/stdout.txt", O_CREAT | O_APPEND | O_WRONLY, 0600);
    close(1);
    dup(fd);
    close(fd);

    int cpid;

    if ((cpid = fork())) {
        // parent
        wait(0);
    }
    else {
        execlp("echo", "echo", "In", "Subprocess", NULL);
    }

    printf("All done.\n");

    return 0;
}
