#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun()
{
    static int i = 0;
    static char a = 3;
    if(--a) fun();
    printf("%d, %d\n", a, ++i);
}

int main()
{
    fun();
    printf("next\n");
    fun();

    return 0;
}
