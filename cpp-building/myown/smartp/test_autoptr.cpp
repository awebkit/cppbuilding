#include "auto_ptr.h"
#include "test_class.h"
int main()
{
    // constructor
    SimpleAutoPointer<BaseClass> p1(new BaseClass);

    // non-const copy constructor
    SimpleAutoPointer<BaseClass> p2 = p1;

    // non-const assignment constructor
    SimpleAutoPointer<BaseClass> p3;
    p3 = p2;

    // release
    SimpleAutoPointer<BaseClass> p4(p3.release());

    // value access
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
    cout << p3.get() << endl; 
    cout << p4.get() << endl; 

    p4->print();
    (*p4).print();

    // reset
    p4.reset(new BaseClass);
    cout << p4.get() << endl; 

    // upper-cast
    SimpleAutoPointer<BaseClass> p5(new DerivedClass);
    SimpleAutoPointer<DerivedClass> p6(new DerivedClass);

    cout << p5.get() << endl;
    cout << p6.get() << endl;

    p5 = p6;

    cout << p5.get() << endl;
    cout << p6.get() << endl;

    // problem: const copy constructor and assignment operator
    // SimpleAutoPointer<BaseClass> p7 = SimpleAutoPointer<BaseClass>(new BaseClass);
    // p4 = SimpleAutoPointer<BaseClass>(new BaseClass);
}
