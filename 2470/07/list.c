
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct cons_cell {
  int head;
  struct cons_cell* tail;
} cons_cell;

cons_cell* empty = 0;


cons_cell*
cons(int hd, cons_cell* tl)
{
  cons_cell* xs = malloc(sizeof(cons_cell));
  xs->head = hd;
  xs->tail = tl;
  return xs;
}

void
list_print(cons_cell* xs)
{
  if (xs == empty) {
    return;
  }
  
  printf("%d\n", xs->head);
  list_print(xs->tail);
}

void
list_free(cons_cell* xs)
{
  if (xs == empty) {
    return;
  }

  int aa = xs->head;

  list_free(xs->tail);
  free(xs);
}

int
biggest(cons_cell* xs)
{
  if (xs == empty) {
    return INT_MIN;
  }

  int aa = xs->head;
  int bb = biggest(xs->tail);
  if (aa > bb) {
    return aa;
  }
  else {
    return bb;
  }
}

int
main(int argc, char* argv[])
{
  cons_cell* xs = empty;
  xs = cons(5, xs);
  xs = cons(10, xs);
  xs = cons(15, xs);
  list_print(xs);


  int aa = biggest(xs);
  printf("biggest = %d\n", aa);

  cons_cell* ys = xs->tail;
  ys = cons(20, ys);
  
  int bb = biggest(ys);
  printf("biggest = %d\n", bb);
  
  list_free(xs);
  list_free(ys);
  return 0;
}
