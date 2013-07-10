#include <iostream>

using namespace std;

int main()
{
    double income;
    double sum = 0.0;
    for(int i = 0; i < 12; ++i){
        cin >> income;
        sum += income;
    }
    cout << "$" << sum / 12 << endl;

    return 0;
}
