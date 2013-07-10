#include <iostream>

using namespace std;

class A{
public:
    A(int x, int y){cout << "A(x, y)" << endl;}

    int m_x;
    int m_y;
    A(const A&) {cout << "Acopy" <<endl;}
    A& operator=(const A&) {cout << "=" << endl;}
};


int main()
{
    A a1(10, 10);
    //A a2(2, 5);

    A a2 = a1;

    return 0;
}
