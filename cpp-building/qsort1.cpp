#include <stdio.h>

int a[9] = {4, 7, 3, 8, 2, 5, 0, 1, 9};
void isort(int n)
{
    for (int i = 1; i < n; ++i){
        //a[0,i-1] sorted
        int t = a[i];
        int j = i;
        for (; j>=0 && a[j-1]> t;--j){
            a[j] = a[j-1];
        }
        a[j] = t;
    }
}

void qsort1(int l, int u)
{
    if (l >= u)
        return;
    int m = l;
    for (int i = l+1; i <= u; ++i){
        //a[l+1, m] < a[l] &&
        //a[m+1, i-1] >= a[l]
        if (a[i] < a[l]){
            ++m;
            int t = a[i];
            a[i] = a[m];
            a[m] = t;
        }
    }
    int t = a[m];
    a[m] = a[l];
    a[l] = t;

    qsort1(l, m-1);
    qsort1(m+1, u);
}

int main()
{
    //qsort1(0, 8);
    isort(9);
    for (int i = 0; i < 9; ++i)
        printf("%d, ", a[i]);

    printf("\n");

    return 0;
}
