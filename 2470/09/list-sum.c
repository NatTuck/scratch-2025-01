
#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int head;
    struct cell* tail;
} cell;

cell*
cons(int hd, cell* tl)
{
    cell* xs = malloc(sizeof(cell));
    xs->head = hd;
    xs->tail = tl;
    return xs;
}

int
sum(cell* xs)
{
    if (xs) {
        return xs->head + sum(xs->tail);
    }
    return 0;
}

int
main(int argc, char* argv)
{
    cell* xs = cons(10, cons(20, cons(30, cons(40, 0))));
    printf("%p\n", xs);
    printf("%d\n", sum(xs));
    return 0;
}
   
