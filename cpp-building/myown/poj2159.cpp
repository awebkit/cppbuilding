#include <iostream>
#include <stdio.h>

using namespace std;
void swap(int* a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void bubbleSort(int* a, int n)
{
    for (int i = n - 1; i >= 0; --i){
        //i..n-1 sorted
        for (int j = i - 1;j >= 0; --j ){
            if (a[j] > a[i])
                swap(a, j, i);
        }
    }
}
#define MAX 26
int main()
{
    int cipher[MAX]={0};
    int clear[MAX]={0};

    //char m[MAX], n[MAX];
    //fscanf(stdin, "%s", m);
    //fscanf(stdin, "%s", n);
    string m, n;
    cin >> m >> n;

    int len = m.length();

    if (len != n.length()){
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < len; ++i){
        cipher[m[i] - 'A']++;
        clear[n[i] - 'A']++;
    }

    bubbleSort(cipher, MAX);
    bubbleSort(clear, MAX);

    int k = 0;
    for (; k < MAX; ++k){
        if (cipher[k] != clear[k]){
            break;
        }
    }

    if (k == MAX)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
