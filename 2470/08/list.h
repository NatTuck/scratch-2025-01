#ifndef LIST_H
#define LIST_H

typedef struct cons_cell {
  int head;
  struct cons_cell* tail;
} cons_cell;

extern cons_cell* empty;

cons_cell* cons(int hd, cons_cell* tl);
void list_print(cons_cell* xs);
cons_cell* list_copy(cons_cell* xs);
void list_free(cons_cell* xs);
int biggest(cons_cell* xs);

#endif
