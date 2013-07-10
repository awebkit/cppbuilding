#include <iostream>

using namespace std;

class A{
public:
    A(){cout << "A" << endl;}
    virtual ~A() = 0;
};

A::~A()
{
    cout << "~A" << endl;
}
class A1 : public A{
public:
    A1() {cout << "A1" << endl;}
    ~A1(){cout << "~A1" << endl;}
};
int main()
{
    A a;
    A1 a1;
    //A a;
    //A* b = new A;
}
