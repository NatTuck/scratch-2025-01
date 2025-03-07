#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define NN 10

void*
thread_main(void* thread_arg)
{
    int xx = *((int*)thread_arg);
    printf("Thread %d: We're in a thread.\n", xx);
    *((int*)thread_arg) += xx;
    return thread_arg;
}

int
main(int argc, char* argv[])
{
    int nums[10];
    int rv;

    pthread_t threads[NN];

    printf("Starting %d threads.\n", NN);

    for (int ii = 0; ii < NN; ++ii) {
        nums[ii] = ii;

        rv = pthread_create(&(threads[ii]), 0, thread_main, &(nums[ii]));
        assert(rv == 0);
    }

    printf("Started %d threads.\n", NN);

    for (int ii = 0; ii < NN; ++ii) {
        void* ret;

        rv = pthread_join(threads[ii], &ret);
        int yy = *((int*) ret);
        printf("main: joined thread %d, got back %d\n", ii, yy);
    }
    
    printf("all threads done\n");
    return 0;
}
