// based on cs3650 starter code
#include "pages.h"

#define _GNU_SOURCE
#include <string.h>

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const int PAGE_COUNT = 256;
const int NUFS_SIZE = 4096 * 256; // 1MB

static int pages_fd = -1;
static void* pages_base = 0;

void pages_init(const char* path)
{
    pages_fd = open(path, O_CREAT | O_RDWR, 0644);
    if (pages_fd == -1) {
        fprintf(stderr, "image name: %s\n", path);
        perror("image open failed");
        assert(pages_fd != -1);
    }

    int rv = ftruncate(pages_fd, NUFS_SIZE);
    assert(rv == 0);

    pages_base = mmap(0, NUFS_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, pages_fd, 0);
    assert(pages_base != MAP_FAILED);
}

void pages_free()
{
    int rv = munmap(pages_base, NUFS_SIZE);
    assert(rv == 0);
}

void* pages_get_page(int pnum)
{
    return pages_base + 4096 * pnum;
}

typedef struct dirent {
    char name[100];
    int inode_number; // mode, size in inode
    // other stuff?
} dirent;

dirent*
get_root_dir()
{
    return (dirent*)pages_get_page(0);
}

// Disk layout:
// - Block 0 is the directory.
//
//
//
