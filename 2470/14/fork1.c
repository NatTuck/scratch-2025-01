
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

// Interprocess communication:
//  - signals: man 7 signal
//  - shared memory: man 2 mmap

int
main(int argc, char* argv[])
{
    int opid = getpid();
    int ppid = getppid();

    printf("Hi, I'm %d, child of %d.\n", opid, ppid);

    int cpid;

    if ((cpid = fork())) {
        // we are in the parent
        int pid1 = getpid();
        int ppid1 = getppid();
        printf("[parent] Hi, I'm %d, child of %d.\n", pid1, ppid1);

        int st;
        wait(&st);
        printf("Wait gave back: %d\n", st);
    }
    else {
        // we are in the child
        int pid2 = getpid();
        int ppid2 = getppid();
        printf("[child] Hi, I'm %d, child of %d.\n", pid2, ppid2);

        usleep(1000);
    }

    printf("All done.\n");

    return 0;
}
