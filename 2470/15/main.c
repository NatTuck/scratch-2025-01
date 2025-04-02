
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vec.h"
#include "ast.h"

char*
read_one_line()
{
    char tmp[100];
    tmp[99] = 0;
    char* rv = fgets(tmp, 99, stdin);
    if (rv) {
        return strdup(tmp);
    }
    else {
        return 0;
    }
}


int
main(int argc, char* argv[])
{
    while (1) {
        char* line = read_one_line();
        if (!line) {
            free(line);
            break;
        }

        vec* toks = tokenize(line);
        printf("toks =\n");
        print_vec(toks);
        printf("\n");
        
        node* tree = parse(toks);
        printf("tree =\n");
        print_tree(tree);
        printf("\n");

        int result = eval(tree);
        printf("result = %d\n", result);

        free_vec(toks);
        free(line);
    }

    return 0;
}
