
#include <stdio.h>
#include <assert.h>

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <semaphore.h>

/// A billion
const long TOP = 1000 * 1000 * 1000;
const long NPP = TOP / 10;

int
main(int argc, char* argv[])
{
    sem_t* lock = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE,
                       MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    sem_init(lock, 1, 1); 

    long* sum = mmap(0, sizeof(long), PROT_READ|PROT_WRITE,
                     MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    *sum = 0;

    pid_t kids[10];

    for (int pp = 0; pp < 10; ++pp) {
        if ((kids[pp] = fork())) {
            // parent
        }
        else {
            // child # pp

            long i0 = NPP * pp;
            long iN = i0 + NPP;

            for (long ii = i0; ii < iN; ++ii) {
                if (ii % 101 == 0) {
                    sem_wait(lock);
                    *sum += ii;
                    sem_post(lock);
                }
            }

            munmap(sum, sizeof(long));
            exit(0);
        }
    }

    for (int pp = 0; pp < 10; ++pp) {
        waitpid(kids[pp], 0, 0);
    }
    
    printf("sum = %ld\n", *sum);
    
    return 0;
}
