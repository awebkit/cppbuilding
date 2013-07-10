#include <stdio.h>
#include <stdlib.h>

void swap( int* p1,int* p2 )
{
    int *p = (int*)malloc(4);;
    *p = *p1;
    *p1 = *p2;
    *p2 = *p;
}

int main()
{
    int p1 = 10;
    int p2 = 20;
    swap(&p1, &p2);

    printf("p1: %d, p2 :%d\n", p1, p2);

    return 0;
}
