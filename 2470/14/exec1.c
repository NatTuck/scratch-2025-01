
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int
main(int argc, char* argv[])
{
    int cpid;

    if ((cpid = fork())) {
        // parent
        int st;
        wait(&st);
        printf("Wait gave back: %d\n", st);
    }
    else {
        // we are in the child
        execlp("echo", "echo", "In", "Subprocess", NULL);
    }

    printf("All done.\n");

    return 0;
}
