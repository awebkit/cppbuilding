#include <iostream>
#include <stdlib.h>

#define MAX 100010

int ra[MAX];

using namespace std;

int myCompare(const void *a, const void *b){
    return *(int* )a - *(int* )b;
}

int main()
{
    int n,m;
    string sepline;
    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> ra[i];
    }
    qsort(ra, n, sizeof(int), myCompare);
    cin >> sepline;

    cin >> m;
    int* ans = new int[m];
    for (int i = 0; i < m; ++i){
        cin >> ans[i];
    }

    for (int i = 0; i < m; ++i){
        cout << ra[ans[i] - 1]<<endl;
    }

    return 0;
}
