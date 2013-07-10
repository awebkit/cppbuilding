#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
void perm(T* p, int n, int m)
{
    if (m == n){
        for (int i = 0; i < m; ++i){
            cout << " " << p[i];
        }
        cout << endl;
        return;
    } else {
        for (int i = m; i < n; ++i){
            swap(p[i], p[m]);
            perm(p, n, m + 1);
            swap(p[i], p[m]);
        }
    }
}

int main()
{
    //char a[] = "abcde";
    char a[] = "abc";
    perm(a, strlen(a), 0);
    return 0;
}
