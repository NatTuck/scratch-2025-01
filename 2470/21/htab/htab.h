#ifndef HTAB_H
#define HTAB_H

typedef struct pair {
    char* key;
    char* val;
} pair;

typedef struct htab {
    int size;
    int cap;
    pair** data; // Array of (cap) pair pointers.
} htab;

int htab_hash(const char* text);
htab* htab_empty(int cap);
void htab_put(htab* tab, const char* key, const char* val);
const char* htab_get(htab* tab, const char* key);
void htab_free(htab* tab);

#endif
