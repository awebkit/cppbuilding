#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10000

int ca[MAX];

int mycompare(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> ca[i];
    }
    qsort(ca, n, sizeof(int), mycompare);

    cout << ca[n/2] << endl;

    return 0;
}
