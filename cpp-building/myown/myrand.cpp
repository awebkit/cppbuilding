#include <stdio.h>
#include <stdlib.h>

int myrand(int l, int u)
{
    return rand()%(u-l+1) + l;
}

int main()
{
    for (int i = 0; i < 10; ++i){
        int t = myrand(10, 20);
        printf("%d\n", t);
    }
    return 0;
}
