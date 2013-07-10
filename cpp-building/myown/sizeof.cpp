#include <iostream>

using namespace std;

class A{
public:
    A(){cout << "A()" <<endl;}
    void test(){cout<<"aa"<<endl;}
    virtual void f() {}
    virtual void b() {}
private:
    int m_a;
};
int main()
{
    A a;
    cout << sizeof(A) << endl;
}
