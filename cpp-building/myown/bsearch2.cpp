#include <iostream>

using namespace std;

int a[7] = {2, 3, 5, 5, 6, 7, 8};
int bsearch(int l, int n, int k)
{
#if 1
    l = -1;
    int u = n;
    //a[l] < k <= a[u]
    while(l + 1 != u){
        int m = (l+u)/2;
        if (a[m] < k)
            l = m;
        else
            u = m;
    }
    int p = u;
    if (p >= n || a[p] != k)
        p = -1;
    return p;
#endif
#if 0
    while (l < n) {
        int m = (l + n) / 2;

        if (a[m] < k){
            l = m + 1;
        } else if (a[m] == k) {
            return m;
        } else {
            n = m - 1;
        }
    }
    return -1;
#endif
}
int main()
{
    int tmp = bsearch(0, 7, 5);
    cout << "5 is " << tmp << endl;

    tmp = bsearch(0, 7, 4);
    cout << "4 is " << tmp << endl;

    return 0;
}
