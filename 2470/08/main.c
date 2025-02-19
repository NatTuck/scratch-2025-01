
#include <stdio.h>

#include "list.h"
#include "list.h"

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

  cons_cell* ys = list_copy(xs->tail);
  ys = cons(20, ys);
  
  int bb = biggest(ys);
  printf("biggest = %d\n", bb);
  
  list_free(xs);
  list_free(ys);
  return 0;
}
