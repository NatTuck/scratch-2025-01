#ifndef VEC_H
#define VEC_H

typedef struct vec {
    int size;
    int cap;
    char** data;
} vec;

vec* new_vec(int cap0);
void push_back(vec* xs, char* text);
void free_vec(vec* xs);
void print_vec(vec* xs);
vec* tokenize(char* line);

#endif
