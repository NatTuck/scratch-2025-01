
#include <stdio.h>

#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK_SIZE  100
int stack[STACK_SIZE];
int stptr = 0;          // index of next push
pthread_mutex_t mutex;
pthread_cond_t   condv; // associated with the above mutex


void
stack_push(int xx)
{
    // precondition: the stack isn't full
    pthread_mutex_lock(&mutex);
    while (stptr >= STACK_SIZE) {
        pthread_cond_wait(&condv, &mutex);
    }
    stack[stptr++] = xx;
    pthread_cond_broadcast(&condv);
    pthread_mutex_unlock(&mutex);
}

int
stack_pop()
{
    // logical precondition: the stack isn't empty
    pthread_mutex_lock(&mutex); // first, take the lock
    while (stptr <= 0) {
        pthread_cond_wait(&condv, &mutex);
    }
    int yy = stack[--stptr];
    pthread_cond_broadcast(&condv);
    pthread_mutex_unlock(&mutex);
    return yy;
}

void*
producer_thread(void* arg)
{
    int nn = *((int*) arg);
    free(arg);

    for (int ii = 0; ii < nn; ++ii) {
        stack_push(ii);
    }

    return 0;
}

int
main(int argc, char* argv[])
{
    pthread_t threads[2];
    pthread_mutex_init(&mutex, 0);

    int NN = 1000;

    for (int ii = 0; ii < 2; ++ii) {
        int* nn = malloc(sizeof(int));
        *nn = NN;
        int rv = pthread_create(&(threads[ii]), 0, producer_thread, nn);
        assert(rv == 0);
    }

    for (int ii = 0; ii < 2*NN; ++ii) {
        int yy = stack_pop();
        printf("%d\n", yy);
    }

    return 0;
}
