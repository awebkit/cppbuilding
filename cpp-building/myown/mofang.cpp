#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(void) {
    int i, j, key;
    int square[N+1][N+1] = {0};
    i = 0;
    j = (N+1) / 2;
    for(key = 1; key <= N*N; key++) {
        if((key % N) == 1)
            i++;
        else {
            i--;
            j++;
        }
        if(i == 0)
            i = N;
        if(j > N)
            j = 1;
        square[i][j] = key;
        printf("i %d j %d key %d\n", i, j, key);
    }
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++)
            printf("%2d ", square[i][j]);
        printf("\n");
    }
    return 0;
}

