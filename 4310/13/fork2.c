#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

int
main()
{
    int opid = getpid();
    int opar = getppid();
    int cpid;

    if ((cpid = fork())) {
        // we call fork once, it returns twice

        waitpid(cpid, 0, 0);
        puts("child done");
    }
    else {
        int fd = open("/tmp/stdout.txt", O_CREAT | O_APPEND | O_WRONLY, 0644);
        close(1);
        dup(fd);
        close(fd);

        execlp("echo", "echo", "this", "is", "echo", NULL);
        // we call exec once, it returns zero times

        printf("this print will never happen if exec succeeds\n");
    }


    return 0;
}
