#include <iostream>
using namespace std;

//计算n的阶乘
int factor(int n)
{
    int result=1;
    for(;n>0;n--)
    {
        result *=n;
    }
    return result;
}

//把数组pT中的元素从start到last前移一个位置
template<typename T>
void copy(T* pT, int start, int last)
{    
    int pos;
    for(pos=start; pos <=last; pos++)
    { 
        pT[pos-1]=pT[pos];
    }
}
/*
获得一个排列，元素数组放在in中，结果在out中，count是in中元素的个数, index是下标
*/
template<typename T>
int GetPermutation(const T * in, T* out, int count, int index)
{
    int pos;
    int m;
    typedef const T* CPT;

    CPT* pcopy = new CPT[count];
    for(pos=0; pos < count; pos++)
    {
        pcopy[pos] = in+pos;
    }

    int base=factor(count-1);
    //index = index %base;
    for(m=count-1; m>0; m--)
    {
        out[m]= *pcopy[index/base];
        copy(pcopy, 1+index/base,m);
        //cout << "index " << index << " base " << base << endl;
        index = index %base;
        base = base/m;
    }

    out[0]=*pcopy[0];
    delete []pcopy;
    return 0;
}

int main(int, char*[])
{
    char arr[]="abc";
    char arr1[4];
    arr1[3] =0;
    int i;
    for(i=0; i < 6; i++)
    {
        GetPermutation(arr, arr1,3,i);
        cout << i << " " << arr1 << endl;
    }
    return 0;
} 
