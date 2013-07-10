#include <iostream>

using namespace std;

class A{
public:
    A(){cout<<"A()"<<endl;}
};

class B{
public:
    B(){cout<<"B()"<<endl;}
    B(int a):m_a(a) {cout<<"B(a)" <<endl;}
private:
    int m_a;
};

class C : public A, public B{
public:
    C(){cout<<"C()"<<endl;}
};

int main()
{
    C* c = new C();
    return 0;
}
