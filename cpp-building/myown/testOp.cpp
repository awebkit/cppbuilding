#include <iostream>
#include <string>


using namespace std;
class A{
public:
    A(string a):m_a(a){}
    A(){}
private:
    //void operator=(const A& a){cout<<"="<<endl;}
    //A(const A& a){cout<<"A" << endl;}
    string m_a;
};
int main()
{
    A a1("test");
    A a2;
    a2 = a1;

    A a3(a1);
    return 0;
}
