#include <stdio.h>
#include <stdlib.h>

int glob1 = 10;
int glob2 = 20;

const char* message = "Hello, there.";

int
main(int argc, char* argv[])
{
    int loc1 = 30;
    int loc2 = 40;

    printf("global data: %lx\n", &glob1);
    printf("stack: %lx\n", &loc1);
    printf("text: %lx\n", main);
    printf("constant data: %lx\n", message);

    char* dyn1 = malloc(8);
    char* dyn2 = malloc(8);

    printf("heap: %lx\n", dyn1);

    free(dyn2);
    free(dyn1);

    return 0;
}
