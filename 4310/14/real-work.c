
#include <stdio.h>
#include <assert.h>

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <semaphore.h>

int
main(int argc, char* argv[])
{
    sem_t* lock_a = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE,
                       MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    sem_init(lock_a, 1, 1);

    // imagine there's data guarded by lock_a

    sem_t* lock_b = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE,
                       MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    sem_init(lock_b, 1, 1); 

    // imagine there's data guarded by lock_b

    int cpid;

    puts("before fork");

    if ((cpid = fork())) {
        // parent


        sem_wait(lock_a);

        // do some work on the data guarded by lock a
        puts("prep account a");
        sleep(1);


        // now need to modify data b based on our work
        // done on a
        sem_wait(lock_b);

        // do something fast with and b
        puts("transfer a -> b");

        sem_post(lock_b);
        sem_post(lock_a);
    }
    else {
        // child

        sem_wait(lock_b);

        // do some work on the data guarded by lock b
        puts("prep account b");
        sleep(1);

        sem_wait(lock_a);

        // do something fast with b and a
        puts("transfer b -> a");

        sem_post(lock_a);
        sem_post(lock_b);
    }
    
    return 0;
}
