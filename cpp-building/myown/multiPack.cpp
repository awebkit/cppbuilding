/*
 *
 N V
 Ci Wi Mi
 */
#include <iostream>

using namespace std;

const int N = 5;
const int V = 20;
typedef struct _obj{
    int c;
    int w;
    int m;
} obj;

int f[V + 1] = {0};
int l[V + 1] = {0};

void myPrint(int a[])
{
    for (int i = 0; i <= V; ++i)
        cout << a[i] << " ";
    cout << endl;
}
void zeroOnePack(int c, int w)
{
    cout << "zeroOnePack c:" << c << " w:" << w  << endl; 
    for (int v = V; v >= c; --v){
        //f[v] = max(f[v], f[v - c] + w);
        if (f[v] >= f[v - c] + w){
            f[v] = f[v];
            l[v] = v;
        } else {
            f[v] = f[v - c] + w;
            l[v] = v - c;
        }
    }
    myPrint(f); 
    cout << "================" << endl;
    myPrint(l); 
}

void completePack(int c, int w)
{
    cout << "completePack c:" << c << " w:" << w  << endl; 
    for (int v = c; v <= V; ++v){
        //f[v] = max(f[v], f[v - c] + w);
        if (f[v] >= f[v - c] + w){
            f[v] = f[v];
            l[v] = v;
        } else {
            f[v] = f[v - c] + w;
            l[v] = v - c;
        }
    }
    myPrint(f);
    cout << "================" << endl;
    myPrint(l);
}

void multiPack(int c, int w, int m)
{
    cout << "multiPack c:" << c << " w:" << w << " m:" << m << endl; 
    if (c * m >= V){ //complete package
        completePack(c, w);
        return;
    }

    int k = 1;
    while(k < m){
        zeroOnePack(k*c, k*w);
        m = m - k;
        k = 2*k;
    }
    zeroOnePack(m*c, m*w);
}

int main()
{
    obj t[N] = {
        {3, 4, 6},
        {5, 8, 1},
        {2, 3, 4},
        {6, 8, 4},
        {8, 20, 1}
    };

    for (int i = 0; i < N; ++i){
        multiPack(t[i].c, t[i].w, t[i].m);
    }
    
    cout << f[V] << endl;
    return 0;    
}
