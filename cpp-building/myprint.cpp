#include <stdio.h>

void myprint(int a[][10], int n, int m)
{
#if 0
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
#endif
    printf("(0, 0)");
    bool reverse = true;
    for (int count = 1; count <= (n + m - 2); ++count){
        for (int i = 0; i < n; ++i){
            if (i>count){
                reverse = !reverse;
                break;
            }
            for (int j = 0; j < m; ++j){
                if (j>count)
                    break;
                if (i+j == count){
                    if (!reverse)
                        printf("(%d, %d)", i, j);
                    else
                        printf("(%d, %d)", j, i);
                }
            }
        }
    }
}
int main()
{
    int n = 7;
    int m = 10;
    int a[7][10] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35, 36, 37, 38, 39},
        {40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
        {50, 51, 52, 53, 54, 55, 56, 57, 58, 59},
        {60, 61, 62, 63, 64, 65, 66, 67, 68, 69}
    };
    myprint(a, n, m);
    return 0;
}
