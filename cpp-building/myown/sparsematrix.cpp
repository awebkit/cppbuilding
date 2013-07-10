#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int num[5][3] = {{5, 6, 4},
        {1, 1, 3},
        {2, 3, 6},
        {3, 2, 9},
        {4, 4, 12}};
    int i, j, k = 1;
    printf("sparse matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", num[i][j]);
        }
        putchar('\n');
    }
    printf("\nmatrix还原:\n");
    for(i = 0; i < num[0][0]; i++) {
        for(j = 0; j < num[0][1]; j++) {
            if(k < num[0][2] &&
                    i == num[k][0] && j == num[k][1]) {
                printf("%4d ", num[k][2]);
                k++;
            }
            else
                printf("%4d ", 0);
        }
        putchar('\n');
    }
    return 0;
}

