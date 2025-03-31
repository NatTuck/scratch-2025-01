
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "vec.h"

vec*
new_vec(int cap0)
{
    vec* tmp = malloc(sizeof(vec));
    tmp->cap = cap0;
    tmp->size = 0;
    tmp->data = malloc(cap0 * sizeof(char*));
    return tmp;
}

void
push_back(vec* xs, char* text)
{
    xs->data[xs->size++] = strdup(text);
}

void
free_vec(vec* xs)
{
    for (int ii = 0; ii < xs->size; ++ii) {
        free(xs->data[ii]);
    }
    free(xs);
}

void
print_vec(vec* xs)
{
    for (int ii = 0; ii < xs->size; ++ii) {
        printf("- %s\n", xs->data[ii]);
    }
}

vec*
tokenize(char* text)
{
    vec* ys = new_vec(10);

    char tmp[100];
    tmp[0] = 0;
    int jj = 0; // tmp index

    for (int ii = 0; ii < strlen(text); ++ii) {
        if (isdigit(text[ii])) {
            tmp[jj++] = text[ii];
        }

        if (text[ii] == '+' || text[ii] == '-' || text[ii] == '*' || text[ii] == '/') {
            if (tmp[0] != 0) {
                tmp[jj] = 0;
                push_back(ys, tmp);
                tmp[0] = 0;
                jj = 0;
            }

            tmp[0] = text[ii];
            tmp[1] = 0;
            push_back(ys, tmp);
        }
    }

    if (tmp[0] != 0) {
        tmp[jj] = 0;
        push_back(ys, tmp);
        tmp[0] = 0;
        jj = 0;
    }

    return ys;
}
