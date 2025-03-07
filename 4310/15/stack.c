
#include <stdio.h>

int stack[5];
int stptr = 0;

void
stack_push(int xx)
{
    stack[stptr++] = xx;
}

int
stack_pop()
{
    return stack[--stptr];
}

int
main(int argc, char* argv[])
{
    int NN = 1000;

    for (int ii = 0; ii < NN; ++ii) {
        stack_push(ii);
    }

    for (int ii = 0; ii < NN; ++ii) {
        int yy = stack_pop();
        printf("%d\n", yy);
    }

    return 0;
}
