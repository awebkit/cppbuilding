#include <stdio.h>
#include <string.h>

int a[] = {8, 5, 10, 9, 20, 15, 17, 18, 19, 15, 13, 12, 11, 13, 13};

void printA()
{
    int k = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < k; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int bsearch1(int t, int l, int u)
{
    int p;
    while(1){
        // t mustbe range(l, u)
        if (l > u) {
            p = -1;
            break;
        }
        int m = (l + u)/2;
        if (a[m] > t)
            u = m - 1;
        else if (a[m] == t){
            p = m;
            break;
        } else
            l = m + 1;
    }
    return p;
}

int bsearch2(int t, int l, int u)
{
    int p;
    if (l > u)
        return -1;
    int m = (l + u)/2;
    if (a[m] > t)
        return bsearch2(t, l, m-1);
    else if (a[m] == t){
        return m;
    } else
        return bsearch2(t, m+1, u);
}

void swap(int x, int y)
{
    if (a[x] == a[y]) return;
    a[x]^=a[y];
    a[y]^=a[x];
    a[x]^=a[y];
    /*
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
    */
}
void qsort(int l, int u)
{
    if (l > u)
        return;
    int m = l;
    for(int i = l+1; i <= u; ++i){
        //x[l+1...m] < a[l] && x[m+1...i-1] >= a[l]
        if (a[i] < a[l]){
            swap(++m, i);
        }
    }
    //assert(i==u && x[l+1...m] < a[l] && x[m+1 ... u-1] >=a[l]);
    swap(m, l);
    qsort(l, m-1);
    qsort(m+1, u);
}

int main()
{
    qsort(0, sizeof(a)/sizeof(a[0]) - 1);
    printA();

#if 0   
    int k = bsearch1(13, 0, sizeof(a)/sizeof(a[0]) - 1);
    if (k != -1)
        printf("pos is %d\n", k);
#endif
   
#if 1 
    int k = bsearch2(13, 0, sizeof(a)/sizeof(a[0]) - 1);
    if (k != -1)
        printf("pos is %d\n", k);
#endif

    printA();
}
