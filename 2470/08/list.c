
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "list.h"

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

cons_cell*
list_copy(cons_cell* xs)
{
  if (xs == 0) {
    return 0;
  }

  return cons(xs->head, list_copy(xs->tail));
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

