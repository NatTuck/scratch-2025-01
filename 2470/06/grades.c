
#include <stdio.h>
#include <stdlib.h>

char* students[] = {
    "Alice",
    "Bob",
    "Carol",
    "Dave",
    "Erin",
    "Frank",
};


char* assignments[] = {
    "HW01",
    "HW02",
    "HW03",
    "HW04"
};

int
idx(int ii, int jj)
{
    return 4 * ii + jj;
}

int
main(int argc, char* argv[]) 
{
    int* grades1D = malloc(6 * 4 * sizeof(int));

    /*
    int** grades2D = malloc(6 * sizeof(int*));
    for (int ii = 0; ii < 6; ++ii) {
        grades2D[ii] = malloc(4 * sizeof(int));
    }
    */

    for (int ii = 0; ii < 6; ++ii) {
        for (int jj = 0; jj < 4; ++jj) {
            //grades2D[ii][jj] = (67 * ii + jj) % 100;
            grades1D[idx(ii, jj)] = (67 * ii + jj) % 100;
        }
    }

    printf("\t");
    for (int ii = 0; ii < 4; ++ii) {
        printf("%s\t", assignments[ii]);
    }
    printf("\n");
   

    for (int ii = 0; ii < 6; ++ii) {
        printf("%s\t", students[ii]);

        for (int jj = 0; jj < 4; ++jj) {
            printf("%d\t", grades1D[idx(ii, jj)]);
        }

        printf("\n");
    }

    int highest = 0;
    char* name = "dunno";

    for (int ii = 0; ii < 6; ++ii) {
        
        int total_grade = 0;
        for (int jj = 0; jj < 4; ++jj) {
            total_grade += grades1D[idx(ii, jj)];
        }
        printf("Total score for %s is %d\n", students[ii], total_grade);

        if (total_grade > highest) {
            highest = total_grade;
            name = students[ii];
        }
    }

    printf("\nStudent with Highest Homework Total: %s\n", name);

    return 0;
}






