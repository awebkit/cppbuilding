#include <iostream>
#include <string.h>

using namespace std;

void comp1()
{
    int i,n,t,m;
    int a[43];
    cin>>n;
    while(n--)
    {
        memset(a,0,sizeof(a));     
        cin>>m;
        for(i=1;i<=m;++i)
        {
            cin>>t;
            int te=t;
            while(a[t])
            {
                t-=a[t];
                a[te]+=a[t];
            }
            a[te]++;
            cout<<a[te]<<" ";
        }
        cout<<endl;
    }
}

void comp2()
{
    int seq;
    cin >> seq;
    int n;

    int right, ret, j;
    int msg[50];
    while(seq--)
    {
        cin >> n;
        memset(msg, 0, sizeof(msg));
        int h = 0;
        for (int i = 0; i < n; ++i){
            int k;
            cin >> k;
            k = k + i;
            for (; h < k; ++h){
                msg[h] = '(';
            }
            msg[h] = ')';
            h++;
        }

        for (int i = 0; i < 2*n; ++i){
            if (msg[i] == ')'){
                right = 1;
                ret = 0;
                j = i -1;
                for(;right && j >= 0; j--){
                    if (msg[j] == '('){
                        right--;
                        ret++;
                    } else {
                        right++;
                    }
                }
                cout << ret << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    //comp1();
    comp2();
    return 0;
}
