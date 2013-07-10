#include "RefCounted.h"
#include "RefPtr.h"
#include <iostream>

using namespace std;

class A:public RefCounted<A>{
public:
    A(){cout << "A()" << endl;}
    ~A() {cout << "~A()" << endl;}
private:
    A(int a){cout << "A(a)" << endl;}

};

void func()
{
    RefPtr<A> a = adoptRef(new A());

}
int main()
{
    //func();
    
    RefPtr<A> a1 = new A();
    cout << "===========" << endl;
    RefPtr<A> a2;
    a2 = a1;
    cout << "*************" << endl;
    cout << "a1 count:" << a1.get()->refCount() << endl;
    RefPtr<A> a3(new A());
    RefPtr<A> a3 = new A();
    return 0;
}
