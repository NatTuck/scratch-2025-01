#include <stdio.h>

int*
f1()
{
    int yy = 5;
    return &yy;
}

int
main(int argc, char* argv[])
{
    int* yyptr = f1();
    printf("%d\n", *yyptr);
    return 0;
}
