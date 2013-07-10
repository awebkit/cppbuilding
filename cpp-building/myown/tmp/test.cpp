#include <iostream>

using namespace std;

class A{
public:
    void func() {cout << "xxx" <<endl;}
    void func2(){m_t++;}
    int m_t;
};
int main()
{
    A* a = 0;
    a->func();
    cout << &A::func() << endl;
    //a->func2();
    return 0;
}
