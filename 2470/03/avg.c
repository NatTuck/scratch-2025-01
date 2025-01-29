#include <stdio.h>

int
main(int argc, char* argv[])
{
    int nn;
    puts("How many numbers?");
    scanf("%d", &nn);

    printf("You requested %d numbers.\n", nn);
    return 0;
}
