
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <sys/mman.h>


// Interprocess communication:
//  - signals: man 7 signal
//  - shared memory: man 2 mmap

int
main(int argc, char* argv[])
{
    int* xs = mmap(0, 4096, PROT_READ|PROT_WRITE,
                   MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    
    int cpid;

    if ((cpid = fork())) {
        // we are in the parent
        usleep(2000);

        for (int ii = 0; ii < 10; ++ii) {
            printf("xs[%d] = %d\n", ii, xs[ii]);
        }

        wait(0);

        for (int ii = 0; ii < 10; ++ii) {
            printf("xs[%d] = %d\n", ii, xs[ii]);
        }

    }
    else {
        // we are in the child

        for (int ii = 0; ii < 10; ++ii) {
            xs[ii] = ii;
        }

        usleep(4000);

        for (int ii = 0; ii < 10; ++ii) {
            xs[ii] = 10 * ii;
        }
    }


    return 0;
}
