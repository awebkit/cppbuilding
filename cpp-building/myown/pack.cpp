#include <iostream>
using namespace std ; 
const  int V = 1000 ;  //总的体积 
const  int T = 5 ;    //物品的种类 
int f[V+1] ;
#define EMPTY                                      //可以不装满 
int w[T] = {8 , 10 , 4 , 5 , 5};        //价值 
int c[T] = {600 , 400 , 200 , 200 , 300};        //每一个的体积 
const int INF = -66536  ;

int package()
{
#ifdef EMPTY
    for(int i = 0 ; i <= V ;i++) //条件编译，表示背包可以不存储满
        f[i] = 0 ;    
#else
    f[0] = 0 ;
    for(int i = 1 ; i <= V ;i++)//条件编译，表示背包必须全部存储满
        f[i] = INF ;   
#endif

    for(int i = 0 ; i < T ; i++)
    {
        for(int v = V ; v >= c[i] ;v--) //必须全部从V递减到0
        //for(int v = c[i]; v <= V ;v++) //必须全部从V递减到0
        {              
            f[v] = max(f[v-c[i]] + w[i] , f[v])  ; //此f[v]实质上是表示的是i-1次之前的值。
            cout << v << ": " << f[v] <<" ";
        }
        cout<< endl;
        cout << "==========" <<endl;        
    }
    return f[V] ;        
}

int main()
{

    int temp = package();   
    cout<<temp<<endl;   

    return 0 ;    
} 
