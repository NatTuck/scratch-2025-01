
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* words[100];

int
main(int argc, char* argv[])
{
    char word[1000];

    FILE* fd = fopen("/usr/share/dict/words", "r");

    int words_size = 100;
    char **words = malloc(words_size * sizeof(char*));

    int ii = 0;
    while(fgets(word, 1000, fd)) {
        char* tmp = malloc(strlen(word));
        for (int jj = 0; jj < strlen(word) + 1; ++jj) {
            tmp[jj] = word[jj];
        }

        words[ii] = tmp;
        ii++;
        if (ii > 10000) {
            break;
        }

        if (ii >= words_size / 2) {
            // Our array is full.
            int new_size = words_size + 100;
            char** tmp = malloc(new_size * sizeof(char*));
            for (int jj = 0; jj < words_size; ++jj) {
                tmp[jj] = words[jj];
            }
            words = tmp;
            words_size = new_size;
        }
    }

    int nn = ii;
    printf("nn = %d\n", nn);

    int* lengths = malloc(nn * sizeof(int));

    for (ii = 0; ii < nn; ++ii) {
        lengths[ii] = strlen(words[ii]);
    }
   
    int max_index = 0;
    for (ii = 0; ii < nn; ++ii) {
        if (lengths[ii] > lengths[max_index]) {
            max_index = ii;
        }
    }

    printf("Longest word is [%s] with length [%d] at index [%d]\n",
            words[max_index], lengths[max_index], max_index);
    
    for (ii = 0; ii < nn; ++ii) {
        free(words[ii]);
    }

    free(words);
    fclose(fd);
    return 0;
}


