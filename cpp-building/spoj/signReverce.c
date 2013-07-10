#include <stdio.h>

int signReverse(int a)
{
    return ~a + 1;
}

int main()
{
    int a = 7, b = -11;
    printf("%d %d \n", signReverse(a), signReverse(b));
}
