
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vec.h"

char*
read_one_line()
{
    char tmp[100];
    tmp[99] = 0;
    fgets(tmp, 99, stdin);
    return strdup(tmp);
}


int
main(int argc, char* argv[])
{
    while (1) {
        char* line = read_one_line();
        vec* toks = tokenize(line);
        print_vec(toks);
        
        node* tree = parse(tokens);

        //int yy = eval(tree);
        //printf("%d\n", yy);
        free_vec(toks);
        free(line);
    }

    return 0;
}
