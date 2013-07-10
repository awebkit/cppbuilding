#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a[5] = {5,4,3,2,1};
    int b[5] = {6,5,4,3,2};

    int c[10];
    for (int i = 0; i < 10; ++i){
        c[i] = 0;
    }

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            c[i+j] += a[i] * b[j];
        }
    }

    //
    for (int i = 0; i< 9; ++i){
        c[i+1] += c[i]/10;
        c[i] = c[i]%10;
    }

    int j = 9;
    while(c[j] == 0)
        j--;
    for (int i = j; i >= 0; --i){
        printf("%d", c[i]);
    }
    printf("\n");

    return 0;
}
