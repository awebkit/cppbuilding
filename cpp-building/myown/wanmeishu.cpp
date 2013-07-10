#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
#define P 100
int prime(int*); // 求质数表
int factor(int*, int, int*); // 求factor
int fsum(int*, int); // sum ot proper factor

int prime(int* pNum) {
    int i, j;
    int prime[N+1];
    for(i = 2; i <= N; i++)
        prime[i] = 1;
    for(i = 2; i*i <= N; i++) {
        if(prime[i] == 1) {
            for(j = 2*i; j <= N; j++) {
                if(j % i == 0)
                    prime[j] = 0;
            }
        }
    }
    for(i = 2, j = 0; i < N; i++) {
        if(prime[i] == 1)
            pNum[j++] = i;
    }
    return j;
}

int factor(int* table, int num, int* frecord) {
    int i, k;
    for(i = 0, k = 0; table[i] * table[i] <= num;) {
        if(num % table[i] == 0) {
            frecord[k] = table[i];
            k++;
            num /= table[i];
        }
        else
            i++;
    }
    frecord[k] = num;
    return k+1;
}

int fsum(int* farr, int c) {
    int i, r, s, q;
    i = 0;
    r = 1;
    s = 1;
    q = 1;
    /*
    printf("=========");
    for (int k = 0; k < c; ++k) {
        printf(" %d", farr[k]);
    }
    printf("\n");
    */
    while(i < c) {
        do {
            r *= farr[i];
            q += r;
            i++;
        } while(i < c-1 && farr[i-1] == farr[i]);
        s *= q;
        r = 1;
        q = 1;
    }
    return s / 2;
}

void perfect1()
{
    int ptable[N+1] = {0}; // 储存质数表
    int fact[N+1] = {0}; // 储存因式分解结果
    int count1, count2, i;
    count1 = prime(ptable);
    for(i = 0; i <= P; i++) {
        printf("check %d\n", i);
        count2 = factor(ptable, i, fact);

        if(i == fsum(fact, count2))
            printf("Perfect Number: %d\n", i);
    }
    printf("\n");
}

typedef long long LL;
LL data[70];
/*
 * Mul和Mul2的功能应该是一样的。只是
 * Mul考虑到了大数相乘的问题吧
 */
LL Mul(LL a, LL b, LL m)  
{  
    LL ans = 0;  
    while(b)  
    {  
        if(b & 1) 
            ans = (ans + a) % m;  
        a = (a*2)%m;  
        b /= 2;  
    }  
    return ans;  
}  
  
LL Mul2(LL a, LL b, LL m)  
{
    return a * b % m;
}

int Lucas_Lehmer(int p)
{
    if (p == 2)
        return 1;
    LL MOD = (1LL<<p)-1;  
    data[1] = 4;  
    for(int i = 2; i <= p-1; i++)  
    {  
        LL ans = Mul(data[i-1], data[i-1], MOD);  
        data[i] = (ans-2) % MOD;  
    }  
    if(data[p-1] == 0) return 1;  
    return 0; 
}

void perfect2()
{
    printf("perfect number 1\n");
    for(int i = 2; i <= 62; i++) {
        if (Lucas_Lehmer(i)){
            int meson = pow(2,i) - 1;
            int num = meson * (meson + 1) / 2;
            printf("meson num %d perfect number %d\n", i, num);
        }
    }
}

int main(void)
{
    perfect1();
    //perfect2();
    return 0;
}
