#include <iostream>
using namespace std;

template <class T>
class Pair {
    T value1, value2;
public:
    Pair (T first, T second){
       value1=first;
       value2=second;
    }
    T module() {return 0;}
};
template <>
class Pair<int> {
    int value1, value2;
public:
    Pair(int first, int second){
        value1=first;
        value2=second;
    }
    int module() ; //{ return (value1 % value2); } this definition is OK too.
};

int Pair<int>::module()
{
    return (value1 % value2);
}

int main() {
    Pair <int> myints (100,75);
    Pair <float> myfloats (100.0,75.0);
    cout << myints.module() << '\n';
    cout << myfloats.module() << '\n';
    return 0;
}
