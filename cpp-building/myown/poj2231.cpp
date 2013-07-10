#include <iostream>
#include <stdio.h>

using namespace std;
#define MAXN 10010

long long int a[MAXN];

void qsort(int l, int u)
{
    if (l >= u)
        return;
    int i = l;
    int j = u + 1;
    long long int t = a[l];
    while(1){
        do {
            i++;
        }while(i <= u && a[i] < t);
        do {
            j--;
        }while(a[j] > t);

        if (i > j)
            break;
        long long int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    a[l] = a[j];
    a[j] = t;

    qsort(l, j - 1);
    qsort(j + 1, u);
}

int main()
{
    int n;
    fscanf(stdin, "%d", &n);
    //scanf("%d", &n);
    //cin >> n;

    for(int i = 0; i < n; ++i){
        fscanf(stdin, "%lld", &a[i]);
        //scanf("%d", &a[i]);
    }
    long long int vol = 0;
    qsort(0, n - 1);

    for (int i = 0; i < n; ++i){
        cout << " " << a[i];
    }
    cout << endl;
    for (int i = 0; i < n - 1; ++i){
        vol += (a[i + 1] - a[i])* (i + 1) * (n - 1 -i);
    }
    cout << vol*2 << endl;

    return 0;
}
