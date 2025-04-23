#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "htab.h"

int htab_hash(const char* text)
{
    int yy = 0;
    for (int ii = 0; ii < strlen(text); ++ii) {
        yy = yy * 7 + text[0] + ii;
    }
    return yy;
}

htab* htab_empty(int cap)
{
    htab* tab = malloc(sizeof(htab));
    tab->cap = cap;
    tab->size = 0;
    tab->data = malloc(tab->cap * sizeof(pair*));
    for (int ii = 0; ii < tab->cap; ++ii) {
        tab->data[ii] = 0;
    }
    return tab;
}

void htab_put(htab* tab, const char* key, const char* val)
{
    pair* pa = malloc(sizeof(pair));
    pa->key = strdup(key);
    pa->val = strdup(val);

    int slot = htab_hash(key) % tab->cap;
    if (tab->data[slot] != 0) {
        printf("Oh no, it's a collision on %s at %d\n", key, slot);
        exit(1);
    }

    tab->data[slot] = pa;
}

const char* htab_get(htab* tab, const char* key)
{
    int slot = htab_hash(key) % tab->cap;
    if (tab->data[slot] == 0) {
        printf("Oh no, no such key %s.", key);
        exit(1);
    }

    return tab->data[slot]->val;
}

void htab_free(htab* tab)
{
    for (int ii = 0; ii < tab->cap; ++ii) {
        if (tab->data[ii]) {
            free(tab->data[ii]->key);
            free(tab->data[ii]->val);
            free(tab->data[ii]);
        }
    }
    free(tab->data);
    free(tab);
}
