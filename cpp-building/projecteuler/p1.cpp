#include <stdio.h>
#define TEST 0

#define MAX 10000

int stupidCalc()
{
    int count = 0;

    for (int i = 0; i < MAX; ++i){
        if (i%3 == 0) {
            count += i;
        }else if (i%5 == 0) {
            count += i;
        }
    }

    return count;
}

int sumDiv(int num)
{
    int p = MAX/num;
    return num * p * (p + 1) /2; 
}

int smartCalc()
{
    return sumDiv(3) + sumDiv(5) - sumDiv(15);
}

int main()
{
    int count;
#if TEST
    count = stupidCalc();
#else
    count = smartCalc();
#endif
    printf("count is %d\n", count);
}
