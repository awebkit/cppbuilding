#include <stdio.h>
#include <assert.h>

int binSearchRecurse(int a[], int l, int u, int key)
{
    //assert(key in range[l, u])
    if (l > u)
        return -1;

    int m = (l + u) / 2;
    if (a[m] < key){
        binSearchRecurse(a, m + 1, u, key);
    } else if (a[m] == key) {
        return m;
    } else {
        binSearchRecurse(a, l, m - 1, key);
    }
}
int binSearch(int a[], int l, int u, int key)
{
    while(1){
        //assert(key in range[l,u]);
        if (l > u)
            return -1;
        int m = (l + u) / 2;
        if (a[m] < key){
            l = m + 1;
        } else if (a[m] == key){
            return m;
        } else {
            u = m - 1;
        }
    }
}

int binSearch2(int a[], int begin, int end, int key)
{
    int l = begin - 1;
    int u = end + 1;
    while (l + 1 != u){
        //invariant: x[l] < t && x[u] >=t && l<u
        int m = (l + u) / 2;
        if (a[m] < key)
            l = m;
        else
            u = m;
    }
   //assert l+1 = u && x[l] < t  && x[u] >=t
    int p = u;
    if (p >= end + 1 || a[p] != key)
        p = -1;
    return p;
    //
}
int main()
{
    int n = 10;
    int a[10] = {10, 20, 32, 32, 32, 40, 50, 60, 100, 120};
    //int ret = binSearchRecurse(a, 0, n-1, 32);
    int ret = binSearch(a, 0, n-1, 32);
    //int ret = binSearch2(a, 0, n-1, 32);
    printf("ret is %d\n", ret);
    return 0;
}
