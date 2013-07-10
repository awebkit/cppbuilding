#include <iostream>

using namespace std;

class Animal{
public:
    int getWeight(){cout << "animal getweight" << endl;}
};

class Tiger:virtual public Animal{
public:
    Tiger(){cout << "tiger" << endl;}
};

class Lion:virtual public Animal{
public:
    Lion(){cout << "lion" << endl;}
};

class Liger:public Tiger, public Lion{
public:
    Liger(){cout << "liger" << endl;}
};

int main()
{
    Liger lg;
    lg.getWeight();

    return 0;
}
