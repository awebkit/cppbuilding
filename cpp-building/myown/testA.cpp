#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void func(const char* str, int len)
{
    /*
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < ){
        }
    }
    */
    /*
    if (len == 1){
        cout << " " << str << endl;
        return;
    }

    char tmp[len];
    char tmp2[len];

    for (int i = 0; i < len; ++i){
        //
        strcpy(tmp, str);
        strcpy(tmp2, str);
        strcpy(tmp + i, tmp2 + i + 1);
        //cout << " tmp " << tmp << " " << str[i] <<endl;
        // 
        func(tmp , len - 1);
        func(&str[i], 1);

        cout << "==========" <<endl;
    }
    */
}

int main()
{
    const char* a = "abcde";
    func(a, strlen(a));
    return 0;
}
