/*
 * DP example 2
 */
/*
 * 
 * m[i,j] = { 0     i=j
 *          { min{m[i,k] + m[k+1,j] + pi-1pkpj} i<j  i<=k<j
 *
 * Example input:
 * A1   30x35
 * A2   35x15
 * A3   15x5
 * A4   5x10
 * A5   10x20
 * A6   20x25
 *
 * MATRIX-CHAIN-ORDER(p)
 *  n = length(p)-1
 *  for i = 1 to n
 *    do m[i,i] = 0
 *  for l = 2 to n //l is the chain length
 *    do for i = 1 to n-l+1
 *        do j = i+l-1
 *          m[i,j] = MAX
 *          for k = i to j-1
 *            do q = m[i,k] + m[k+1,j] +pi-1pkpj
 *               if q<m[i,j]
 *                 then m[i,j] = q
 *                      s[i,j] = k
 *  return m and s
 */
#include <stdio.h>

const int NUM = 7;
int p[NUM] = {30, 35, 15, 5, 10, 20, 25};

const unsigned int MAXINT= 40000000;
int m[NUM][NUM];
int s[NUM][NUM];

void matrix_chain_order()
{
    int n = NUM - 1;
    for (int i =1; i <=n; ++i){
        m[i][i] = 0;
    }
    for (int l = 2; l <=n; ++l){
        for (int i = 1; i <=n-l+1; ++i){
            int j = i + l -1;
            m[i][j] = MAXINT;
            for (int k = i; k <= j-1; ++k){
                int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
#if 1
    //print
    printf("m:\n");
    for (int i = 0; i < NUM; ++i){
        for (int j = 0; j < NUM; ++j)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
    //
    printf("s:\n");
    for (int i = 0; i < NUM; ++i){
        for (int j = 0; j < NUM; ++j)
            printf("%d ", s[i][j]);
        printf("\n");
    }
    printf("\n");
#endif
}
/*
 * 
 * PRINT-OPTIMAL-PARENS(s, i, j)
 *  if (i=j)
 *    then print "A"i
 *    else print "("
 *         PRINT-OPTIMAL-PARENS(s, i, s[i,j])
 *         PRINT-OPTIMAL-PARENS(s, s[i,j]+1, j)
 *         print ")"
 */
void print_optimal_parens(int i, int j)
{
    if (i == j)
        printf("A%d",i);
    else {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    matrix_chain_order();
    print_optimal_parens(1, NUM-1);
    printf("\n");
    return 0;
}
