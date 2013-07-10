#include <iostream>

using namespace std;

class A{
public:
    A(int a):m_a(a) {}
    void print() const{cout << m_a << endl;}
    void print(int a) const{}
private:
    int& m_a;
};

int main()
{
    A* a = new A(10);
    a->print();
    int c = 10;
    int& b = c;
    const A& consta = *a;
    consta.print();

    consta.print(c);

    return 0;
}
