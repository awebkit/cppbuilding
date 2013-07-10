#include <iostream>
#include <algorithm>

using namespace std;

void Print(int a[], int n)
{
    for (int i = 0; i < n; ++i){
        cout << " " << a[i];
    }

    cout << endl;
}
bool nextPrem(int a[], int n)
{
    //check first number that larger than before.
    int i;
    for ( i = n - 2; i >= 0; --i){
        if (a[i + 1] > a[i])
            break;
    }
    if (i < 0)
        return false;

    int m = i;
    i = n -1;
    for (; i > m; --i){
        if (a[i] > a[m]){
            break;
        }
    }
    swap(a[i], a[m]);

    sort(a+m+1, a+n);
    Print(a, n);
    return true;
}

void fullArray(int a[], int n)
{
    Print(a, n);
    while(nextPrem(a, n));
}
int main()
{
    int test[] = {1, 2, 3, 4};
    fullArray(test, 4);

    return 0;
}
