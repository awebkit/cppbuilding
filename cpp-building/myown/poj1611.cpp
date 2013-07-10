/*并查集的基本应用——POJ1611*/

/************************************************************************
  大致题意：一共有n个学生(编号0 至 n-1)，m个组，一个学生可以同时加入不同的组。
  现在有一种传染病，如果一个学生被感染，那么和他同组的学生都会被感染。现在已
  知0号学生被感染，问一共有多少个人被感染。


  首先将每个学生都初始化为一个集合，然后将同组的学生合并，设置一个数组num[]
  来记录每个集合中元素的个数，最后只要输出0号学生所在集合中元素的个数即可。

 **************************************************************************/


#include<iostream>
using namespace std;
//num[]数组存储节点所在的集合的总个数
//father[]数组存储dina
int num[30001],father[30001];
//初始化用，把每一个点定义为一个集合
void makeSet(int x){
    father[x]=x;//定义跟节点的标志：即为与父亲数组的值相同
    num[x]=1;
}
/**********************************************************/
//查找x元素所在的集合，返回根节点
//并且采用递归方式压缩路径，使得每一个点都指向根节点
int findSet(int x){
    if(x!=father[x])//只有根节点的父亲节点才与自己的值相同
        x=findSet(father[x]);
    return x;//此时的x已经被层层修改为最根的那个节点
}
void unionSet(int a,int b){
    a = findSet(a);
    b = findSet(b);
    if(a==b)return;//在同一个集合中，直接退出
    //此if，else语句将小集合合并到大集合中
    //用来平衡树的左右形状，减少整体层数
    if(num[a]<=num[b]){
        father[a]=b;
        num[b]+=num[a];//更新集合的个数
    }
    else{
        father[b]=a;
        num[a]+=num[b];
    }
}

int main(){
    int m,n;
    while(cin>>m>>n&&(m!=0||n!=0)){
        for(int i=0;i<m;i++)makeSet(i);
        int t,first,next;
        while(n--){
            cin>>t>>first;
            for(int j=1;j<t;j++){
                cin>>next;
                unionSet(first,next);
            }
        }
        cout<<num[findSet(0)]<<endl;
    }
    return 0;
}
