#include <iostream>

using namespace std;

int compZero1(int n)
{
    int count = 0;
    while((n % 10) == 0){
        count++;
        n /= 10;
    }
   return count; 
}
int compZero2(int n)
{
    int count = 0;
    while((n /= 5) != 0){
        count += n;
    }

    return count;
}

int main()
{
    int n = 20;

    int tmp = 1;
    for (int i = 5; i <= 20; i += 5){
        tmp *= i *2;
    }
    cout << "tmp is " << tmp << endl;
    int test = compZero1(tmp);

    cout << " " << test << endl; 

    int out = compZero2(n);

    cout << " " << out << endl;
}
