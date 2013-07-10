#include <iostream>

using namespace std;

void sushuji(int n)
{
    int a[10] = {0};
    int k = 0;
    for (int i = 2;n!=1 ;++i){
        while(n%i == 0){
            a[k++] = i;
            n = n/i;
        }
    }
    int i;
    for (i = 0; i < k - 1; ++i){
        cout << a[i] << " * ";
    }
    cout << a[i];
    cout << endl;
}

void yinshifenjie(int n)
{
    for(int i = 2; i * i <= n;) {
        if(n % i == 0) {
            cout << i << " * ";
            n /= i;
        }
        else
            i++;
    }
    cout << n << endl;
}

int main()
{
    //sushuji(24);
    //yinshifenjie(24);
    return 0;
}
