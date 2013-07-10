#include <iostream>

using namespace std;

class A
{
public:
    virtual void func(){cout << "funcA" << endl;}
    virtual ~A(){cout<<"~A"<<endl;}
};

class B:public A
{
public:
    virtual void func(){cout << "funcB" << endl;}
    virtual ~B(){cout<<"~B"<<endl;}
};

void myNew(int* &p)
{
    p = new int;
}
int main()
{
    A* p = new B;
    p->func();
    delete p;

    cout << "===============" << endl;
    int* myp = NULL;
    myNew(myp);
    if (myp == NULL){
        cout << "fail" << endl;
    } else {
        cout << "ok" << endl;
    }
    return 0;
}
