#include <stdio.h>

int exp(int x, int n)
{
    if (n == 0)
        return 1;

    int result = 1;
    for(int i = n; i > 0; ){
        //result = x^(n - i)
        if ((i & 1) == 0) {
            i /= 2;
            x *= x;
        } else {
            result *= x;
            i--;
        }
    }
    return result;
}

int mypower(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y == 1)
        return x;

    int k = y & 1;
    printf("y is %d k is %d\n", y, k);
#if 1
    if ((y & 1) == 0) {
        printf("even\n");
        return mypower(x*x, y>>1);
    } else {
        printf("odd\n");
        return x * mypower(x*x, y>>1);
    }
#endif
#if 0
    if (n & 1) {
        printf("odd\n");
        return x * mypower(x*x, n/2);
    } else {
        printf("even\n");
        return mypower(x*x, n/2);
    }
#endif
}

int main()
{
    int x = 5;
    int n = 15;
#if 0
    int y = exp(x, n);
#endif
#if 1
    int y = mypower(x, n);
#endif
    printf("5^15 is %d\n", y);

    return 0;
}
