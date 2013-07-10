#include <iostream>

using namespace std;

struct A{
private:
    void* operator new(unsigned int) {}
    ~A(){}
};

int main()
{
    A a;
    //A* b = new A;
}
