#include <stdio.h>

void hello(const char* name)
{
    printf("Hello %s\n", name);
}

int main(int argc, char* argv[])
{
    hello(argv[1]);
    return 0;
}
