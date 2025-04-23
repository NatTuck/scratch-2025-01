#include <stdio.h>

#include "htab.h"

int main(int argc, char* argv[])
{
    htab* noises = htab_empty(64);
    htab_put(noises, "cow", "moo");
    htab_put(noises, "dog", "bark");
    htab_put(noises, "chicken", "bawk");
    htab_put(noises, "sheep", "baaa");
    htab_put(noises, "goat", "aaaaaaaaa");

    printf("A cow says: %s\n", htab_get(noises, "cow"));

    htab_free(noises);

    return 0;
}
