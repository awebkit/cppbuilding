#include <new>
#include <iostream>
#include <stdlib.h>

using namespace std;

class A{
public:
    A(int size){
        cout << "A(size)" << endl;
    }
    void* operator new(size_t size) {
        cout<< "new "<<endl;
        return (void*)malloc(size);
    };

    void operator delete(void* p){
        cout << "delete " << p << endl;
    }

    void* operator new(size_t, void* buffer){
        cout << "new buffer" << endl;
        return  buffer;
    }

    static A* constructA(void* buffer, int size){
        cout << "constructA" << endl;
        return new (buffer) A(size);
    }
};

int main()
{
    A* a = new A(10);
    cout << a << endl;
    delete a;
    cout << "==================" << endl;
    void* buffer = malloc(100);
    cout << buffer << endl;
    A* b = A::constructA(buffer, 10);
    cout << b << endl;
    
    return 0;
}
