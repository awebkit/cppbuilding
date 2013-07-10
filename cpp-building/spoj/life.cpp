#include <iostream>
#include <string>

using namespace std;

int main()
{
    string number[10];
    int count = 0;
    bool first = true;
    for(int i = 0; getline(cin, number[i]); ++i){
        if (number[i].compare("42") == 0){
            first = false;
        }
        if (first)
            count++;
        if (number[i].empty())
            break;
    }

    for (int i = 0; i < count; ++i){
        cout << number[i] << endl;
    }
}
