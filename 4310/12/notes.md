
```C
void* malloc(size_t sz);
void* realloc(void* ptr, size_t sz);
void free(void* ptr);
```

Free list:

```C
typedef struct free_cell {   // sizeof(free_cell) == 16
    // void* addr; This is the address of the free_cell structure itself.
    size_t sz;
    struct free_cell* next;
} free_cell;

free_cell* free_list_head = 0;
```

Example:

```C
int* xs[10];

for (int ii = 0; ii < 10; ++ii) { xs[ii] = malloc(sizeof(int)); xs[ii][0] = ii; }
for (int ii = 0; ii < 5; ++ii) { free(xs[2*ii]); }
for (int ii = 0; ii < 5; ++ii) { xs[ii] = malloc(sizeof(int)); }
```

