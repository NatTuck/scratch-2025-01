#include <stdio.h>
#include <stdlib.h>

long glob1 = 7;

int
main(int argc, char* argv[])
{
    long local1 = 22;

    printf("global =    %p\n", &glob1);
    printf("local =     %p\n", &local1);
    printf("func arg =  %p\n", &argv);
    printf("arg array = %p\n", &(argv[0]));
    printf("arg text =  %p\n", &(argv[0][1]));
    printf("main =      %p\n", main);

    char* dyn1 = malloc(10);
    printf("dynamic =   %p\n", dyn1); 
    free(dyn1);

    return 0;
}
