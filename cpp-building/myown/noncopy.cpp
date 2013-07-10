#include <iostream>
using namespace std;

class Noncopyable {
    Noncopyable(const Noncopyable&) {cout<< "copy ct" << endl;}
    Noncopyable& operator=(const Noncopyable&) {cout << "= ct" << endl;}
protected:
    Noncopyable() { } 
    ~Noncopyable() { } 
}; 

class Test : public Noncopyable{
public:
    Test(){}
};

int main()
{
    //Test *t = new Test();
    Test a, b;
    a = b;
}
