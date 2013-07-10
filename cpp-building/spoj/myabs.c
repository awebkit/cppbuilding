#include <stdio.h>
int myabs(int num)
{
    int a = num >> 31;
    return ((num ^ a) - a);
}

int main()
{
    int a = -9;
    int b = 30;
    printf("%d %d\n", myabs(a), myabs(b));
}
