#include <stdio.h>
#include <string.h>

#define FUNCTION1 0
#define FUNCTION2 0
#define FUNCTION3 1
char a[9] = "abcdefgh";

//n,m 的最大公约数
int gcd(int n, int m) 
{
    if (n > m){
        n ^= m;
        m ^= n;
        n ^= m;
    }
    if (m == 0)
        return n;
    else
        return gcd(m, n % m);
}

void rotate(int rotdist)
{
    int n = strlen(a);
    int i = 0;
     
    for (;i<gcd(rotdist, n);++i){
        int j = i;
        char t = a[j];
        while(1){
            int k = j + rotdist;
            if (k >= n)
                k -= n;
            if (k == i)
                break;
            a[j] = a[k];
            j = k;
        }
        a[j] = t;
    }
    return;
}

void swap(char a, char b)
{
    char c = a;
    a = b;
    b = c;
}

void reverse(int begin, int len)
{
    for (int i = 0; i < len/2; ++i){
        //swap(a[begin + i], a[begin + len - 1 + i]);
        char c = a[begin + i];
        a[begin + i] = a[begin + len - 1 - i];
        a[begin + len - 1 - i] = c;
    }
    return;
}
void myswap(int x, int y, int m)
{
    char tmp[m];
    //a[x...x+m-1] swap a[y...y+m-1]
    strncpy(tmp, &a[x], m);
    strncpy(&a[x], &a[y], m);
    strncpy(&a[y], tmp, m);
    //delete tmp;
}
void myrotate(int rotdist)
{
    int n =strlen(a);

    int i = rotdist;
    int p = rotdist;
    int j = n - i;
    while(i != j){
        if (i > j){
            myswap(p-i, p, j);
            i -= j;
        } else {
            myswap(p-i, p + j - i, i);
            j -= i;
        }
    }
    myswap(p - i, p, i);
}
int main()
{
    //rotate(a, 3);
#if FUNCTION1
    reverse(0, 3);
    reverse(3, 5);
    reverse(0, 8);
#endif

#if FUNCTION2
    rotate(3);
#endif

#if FUNCTION3
    myrotate(5);
#endif

    printf("a is %s\n", a);
}
