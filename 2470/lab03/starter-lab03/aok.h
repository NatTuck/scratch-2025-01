#ifndef AOK_H
#define AOK_H

#include <stdio.h>
#include <stdlib.h>

static void
assert_okay(int rv, const char* file, int line)
{
    if (rv < 0) {
        fprintf(stderr, "Failure at %s:%d\n", file, line);
        perror("not okay");
        exit(1);
    }
}

#define aok(rv) assert_okay(rv, __FILE__, __LINE__)

#endif
