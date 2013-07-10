#include <iostream>
#include <string.h>
using namespace std;
/*
 * Nk = (N/(k-1)!)%k
 * k is index
 */

int factor(int n)
{
    int result = 1;
    for (;n>0;--n){
        result *= n;
    }

    return result;
}

void copy(char* p, int start, int last)
{
    for (int pos = start; pos <= last; ++pos){
        p[pos - 1] = p[pos];
    }
}

void GetPermutation(const char* in, char* out, int count, int index)
{
    char pCopy[count]; 
    strcpy(pCopy, in);

    int base = factor(count - 1);

    //index = index% base;
    for(int m = count - 1; m > 0; --m){
        out[m] = pCopy[index/base];

        copy(pCopy,  1 + index/base, m);
        //strncpy(pCopy + index/base, pCopy);
        index = index % base;
        base = base / m;
    }
    out[0] = pCopy[0];

    return;
}

int main()
{
    char a[] = "abc";
    
    char out[4];
    for (int i = 0; i < 6; ++i){
        GetPermutation(a, out, 4, i);
        cout << out << endl;
    }
    return 0;
}
