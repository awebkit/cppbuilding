/*
   f(i,v) = max(f(i-1, v), f(i-1, v-ci) + wi);
     name   cost weight
   1 apple  200  5
   2 orange 300 6
   3 strawberry 400 8
   4 pear   600 10

   V 1000
   max(w)?
 */
#include <iostream>
#include <string.h>

using namespace std;

typedef struct _fruits{
    int cost;
    int weight;
} fruits;

const int n = 5;
int main()
{

    fruits obj[n] = {
        {20, 5},
        {30, 6},
        {50, 8},
        {40, 7},
        {60, 10}
    }; 

    int V = 100;
    
#if 0
    int f[n][V + 1];
    memset(f, 0, sizeof(f));
    //f[n][V] is the result
    for (int i = obj[0].cost; i<=V; ++i){
        f[0][i] = obj[0].weight;
    }
    for (int i = 1; i < n; ++i){
        int v;
        for (v = 0; v <= obj[i].cost - 1; ++v){
            f[i][v] = f[i-1][v];
            cout << f[i][v] << " ";
        }
        for (v= obj[i].cost; v <= V; ++v){
            f[i][v] = max(f[i-1][v], f[i-1][v-obj[i].cost] + obj[i].weight);
            cout << f[i][v] << " ";
        }
        cout << endl;
        cout << "===========" <<endl;
    }
    
    cout << f[4][V] << endl;
#endif

    int f[V+1];
    memset(f, 0, sizeof(f));

    for (int i = 0; i < n; ++i){
        for (int v = V; v >= obj[i].cost; --v){
            f[v] = max(f[v], f[v-obj[i].cost] + obj[i].weight);
            cout << v << ":" << f[v] << " ";
        }
        cout << "=========" << endl;
    }
    cout << "**********" <<endl;
    cout << f[V] << endl;
    return 0;
}
