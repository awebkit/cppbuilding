#include <iostream>
using namespace std;

namespace mytest{
class A{
public:
    void func() {cout << "func " << endl;}
};
}
using namespace mytest;

int main()
{
    A* a = new A();

    a->func();

    delete a;

    return 0;
}
