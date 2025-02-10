
#include <stdio.h>

void* memcache[10];  // freed memory blocks
int   mc_size = 0;   // how many blocks stored in cache


void*
badalloc(long size)
{
    void* yy;
    if (size >= 100) {
        yy = getmem(size);        
        printf("ba(%ld) -> %p (big)\n", size, yy);
        return yy;
    }

    // Requested size is < 100
    if (mc_size > 0) {
        yy = memcache[--mc_size]; 
        printf("ba(%ld) -> %p (cached)\n", size, yy);
        return yy;
    }

    yy = getmem(100);
    printf("ba(%ld) -> %p (100)\n", size, yy);
    return yy;
}

void
badfree(void* ptr)
{   
    if (mc_size < 10) {
        memcache[mc_size++] = ptr;
    }
}


