#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdatomic.h>
#include <assert.h>
#include <sys/mman.h>


int
main()
{
    int* shared = mmap(0, 4096, PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    for (int ii = 0; ii < 10; ++ii) {
        shared[ii] = ii;
    }
    
    int cpid;

    if ((cpid = fork())) {
        printf("parent, sleep 1\n");
        sleep(1);

        // mutate array
        for (int ii = 0; ii < 10; ++ii) {
            shared[ii] = 10 * ii;
        }

        waitpid(cpid, 0, 0);
        puts("child done");
    }
    else {
        printf("child, print array\n");
        for (int ii = 0; ii < 10; ++ii) {
            printf("- %d\n", shared[ii]);
        }

        sleep(2);

        printf("child, print array\n");
        for (int ii = 0; ii < 10; ++ii) {
            printf("- %d\n", shared[ii]);
        }
    }


    return 0;
}
