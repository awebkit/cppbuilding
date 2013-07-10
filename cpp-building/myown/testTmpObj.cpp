#include <iostream>
#include <string>

using namespace std;


class A{
public:
    A(string){cout<< "A()" << endl;}
    static void upper(string&){cout<<"upper()" << endl;}
};
int main()
{
    //char toBeChanged[] = "changeme"; //no temp object for non const reference
    string toBeChanged("changeme");
    A::upper(toBeChanged);
    return 0;
}
