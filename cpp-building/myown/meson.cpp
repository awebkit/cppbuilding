#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
  
typedef long long LL;  
  
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

LL data[70];  
  
int Lucas_Lehmer(int p)  
{  
    LL MOD = (1LL<<p)-1;  
    data[1] = 4;  
    for(int i = 2; i <= p-1; i++)  
    {  
        //LL ans = Mul(data[i-1], data[i-1], MOD);  
        LL ans = Mul2(data[i-1], data[i-1], MOD);  
        //printf("ans is %lld, mod %lld\n", ans, MOD);
        data[i] = (ans-2) % MOD;  
        //printf("data is %lld\n", data[i]);
    }  
    if(data[p-1] == 0) return 1;  
    return 0;  
}  
  
void solve()  
{  
    LL n;  
    scanf("%lld", &n);  
    if(n == 2) { printf("yes\n"); return ;}  
    if(Lucas_Lehmer(n)) printf("yes\n");  
    else printf("no\n");  
}  
  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    while(T--)  
    {  
        solve();  
    }  
    return 0;  
}
