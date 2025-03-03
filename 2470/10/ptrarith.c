
#include <stdio.h>

int
main()
{
    /*
    char* hello = "Hello, Pointers";
    puts(hello);
    puts(hello + 3);

    
    int ys[] = {1, 2, 3, 0};
    int* xs = ys;

    printf("xs = %p\n", xs);
    char* tmp = (char*) xs;
    tmp += 1;
    xs = (int*) tmp;
    printf("xs = %p\n", xs);

    for (int ii = 0; xs[ii]; ++ii) {
        printf("%d ", xs[ii]);
    }
    printf("\n");

    return 0;
    */

    int ys[] = {1, 1, 0, 0};
    int* xs = (int*)((char*)(ys) + 1);

    for (int ii = 0; xs[ii]; ++ii) {
        printf("%d ", xs[ii]);
    }
    printf("\n");

    printf("bytes =\n");
    char* bs = (char*) ys;
    for (int ii = 0; ii < 16; ++ii) {
        printf("byte #%d is %d\n", ii, bs[ii]);
    }

    return 0;
}
