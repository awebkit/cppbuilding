/*
 * DP example
 */

/*
 * Factory
 * e    a11     a12     a13     a14     a15     a16     x
 * 2    7       9       3       4       8       4       3
 *          2|2     3|1     1|2     3|2     4|1
 * 4    8       5       6       4       5       7       2
 *   
 * j        1   2   3   4   5   6
 * f1[j]    9   18  20  24  32  35
 * f2[j]    12  16  22  25  30  37      f* = 38
 *
 * j        2   3   4   5   6
 * l1[j]    1   2   1   1   2
 * l2[j]    1   2   1   2   2   l* = 1 
 *
 *  f1[j]={ e1 + a11    j=1
 *        { min(f1[j-1]+a1j, f2[j-1]+t2j-1 +a1j)    j>=2
 *
 *  f2[j]={ e2 + a21    j=1
 *        { min(f2[j-1]+a2j, f1[j-1]+t1j-1+a2j)     j>=2
 */
#include <stdio.h>

int e1 = 2;
int e2 = 4;
int x1 = 3;
int x2 = 2;
int n = 6;
int a[3][7] = {
    {0},
    {0, 7, 9, 3, 4, 8, 4},
    {0, 8, 5, 6, 4, 5, 7}
};

int t[3][6] = {
    {0},
    {0, 2, 3, 1, 3, 4},
    {0, 2, 1, 2, 2, 1}
};

int f[3][7] = {0} ;
int l[3][7] = {0};

int fstar;
int lstar;
void fast_way()
{
    f[1][1] = e1 + a[1][1];
    f[2][1] = e2 + a[2][1];

    for (int j = 2; j <= n; ++j){
        if (f[1][j-1] + a[1][j] <= f[2][j-1] + t[2][j-1] + a[1][j]){
            f[1][j] = f[1][j-1] + a[1][j];
            l[1][j] = 1;
        } else {
            f[1][j] = f[2][j-1] + t[2][j-1] + a[1][j];
            l[1][j] = 2;
        }

        if (f[2][j-1] + a[2][j] <= f[1][j-1] + t[1][j-1] + a[2][j]){
            f[2][j] = f[2][j-1] + a[2][j];
            l[2][j] = 2;
        } else {
            f[2][j] = f[1][j-1] + t[1][j-1] + a[2][j];
            l[2][j] = 1;
        }
    }

    if (f[1][n] + x1 <= f[2][n] + x2) {
        fstar = f[1][n] + x1;
        lstar = 1;
    } else {
        fstar = f[2][n] + x2;
        lstar = 2;
    }
#if 1
    //print
    printf("f1: ");
    for (int i = 1; i <=n;++i){
        printf("%d ", f[1][i]);
    }
    printf("\n");
    printf("f2: ");
    for (int i = 1; i <=n;++i){
        printf("%d ", f[2][i]);
    }
    printf("\n");
    printf("l1: ");
    for (int i = 1; i <=n;++i){
        printf("%d ", l[1][i]);
    }
    printf("\n");
    printf("l2: ");
    for (int i = 1; i <=n;++i){
        printf("%d ", l[2][i]);
    }
    printf("\n");
    printf("fstar is %d\n", fstar);
    printf("lstar is %d\n", lstar);
#endif
}

void print_stations()
{
    int i = lstar;
    printf("line %d, station %d\n", i, n);

    for (int j = n; j >=2; --j){
        i = l[i][j];
        printf("line %d, station %d\n", i, j-1);
    }
}

int main()
{
    fast_way();
    print_stations();
    return 0;
}
