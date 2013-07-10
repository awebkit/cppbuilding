#include <stdio.h>

#define LOG(args...) printf(args)

int main()
{
    int a = 10;
    LOG("test %d\n", a);

    return 0;
}
