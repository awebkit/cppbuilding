#include <iostream>

using namespace std;

class A{
public:
    friend A* cache();
    void f1(){cout<< "f1" << endl;}
    void f2(){cout<< "f2" << endl;}
private:
    A(){cout<<"A()" <<endl;}
};
A* cache()
{
    static A* a = new A();
    return a;
}
int main()
{
    cache()->f1();
    cache()->f2();
    return 0;
}
