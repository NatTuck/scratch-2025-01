#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int
main()
{
    int opid = getpid();
    int opar = getppid();
    int cpid;

    printf("[o] this is %d, child of %d\n", opid, opar);

    if ((cpid = fork())) {
        printf("[p] this is %d, child of %d\n", opid, opar);
    }
    else {
        printf("[c] this is %d, child of %d\n", opid, opar);
    }

    printf("[after] this is %d, child of %d\n", opid, opar);

    return 0;
}
