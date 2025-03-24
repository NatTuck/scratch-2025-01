
#define _GNU_SOURCE
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>


#include "xmalloc.h"

typedef struct size24_block {
    size_t size;
    struct size24_block* next;
    size_t _unused;
} size24_block;

static __thread size24_block* size24s = 0;

/*
typedef struct size72_block {
 ...
}

static __thread size72_block size72s = 0;
 */

void
size24_free(void* ptr)
{
    size24_block* block = ptr - 8;
    block->next = size24s;
    size24s = block;
}

void*
size24_malloc()
{
    if (size24s == 0) {
        size24_block* page = xmalloc(4088);
        for (int ii = 0; ii < 170; ++ii) {
            size24_free(&(page[ii]));
        }
    }

    size24_block* ptr = size24s;
    size24s = size24s->next;
    ptr->size = 24;
    return &(ptr->next);
}

void*
xmalloc(size_t bytes)
{
    printf("xmalloc(%ld) in thread %d\n", bytes, gettid());
    bytes += sizeof(size_t);

    if (bytes == 24) {
        return size24_malloc();
    }

    size_t* block = mmap(0, bytes, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    *block = bytes;
    return block + 1;
}

void
xfree(void* ptr)
{
    size_t* block = ptr - 8;

    printf("xfree(%ld) in thread %d\n", *block, gettid());

    if (*block == 24) {
        size24_free(block);
    }
    else {
        munmap(block, *block);
    }
}

void*
xrealloc(void* prev, size_t bytes)
{
    assert(0);
    size_t* sz = prev;
    sz -= 1;
    void* next = xmalloc(bytes);
    memcpy(next, prev, *sz);
    xfree(prev);
    return next;
}
