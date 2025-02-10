#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
counta(char* text)
{
    int count = 0;
    for (int ii = 0; text[ii]; ++ii) {
        if (text[ii] == 'a') {
            ++count;
        }
    }
    return count;
}

int
main()
{
    char tmp[100];

    FILE* words = fopen("/usr/share/dict/words", "r");

    char** top = badalloc(10 * sizeof(char*));
    for (int ii = 0; ii < 10; ++ii) {
        top[ii] = 0;
    }

    while (fgets(tmp, 100, words)) {
        long ll = strlen(tmp);
        tmp[ll - 1] = 0;

        for (int ii = 0; ii < 10; ++ii) {
            int aa = top[ii] ? counta(top[ii]) : 0;
            int bb = counta(tmp);

            if (bb > aa) {
                badfree(top[ii]);
                top[ii] = badalloc(strlen(tmp) + 1);
                memcpy(top[ii], tmp, strlen(tmp) + 1);
                break;
            }
        }
    }

    for (int ii = 0; ii < 10; ++ii) {
        puts(top[ii]);
        badfree(top[ii]);
    }

    badfree(top);

    fclose(words);
    return 0;
}
