#include <iostream>
#include <fstream>
using namespace std;

int sum;
int store[10];

void print()
{
    for(int i = 0; i < 10; ++i)
        cout<<store[i]<<" ";
    cout<<endl;
    ++sum;
}

void GetArran(int target, int count)
{
    if((target < 0)||(target > count*10))
        return;
    if(count == 1)
    {           
        store[count-1] = target;
        print();
        return;
    }
    for(int i = 0; i <= 10; ++i)
    {
        store[count-1] = i;
        GetArran(target - i, count - 1);
    }
}

int main()
{
    GetArran(90, 10);
    cout<<"总数："<<sum<<endl;

    return 0;
}
