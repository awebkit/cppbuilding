#include <stdio.h>
#define TEST_RECURSE 0
#define MAX 4000000

int recurseFibonacci(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return recurseFibonacci(n-1) + recurseFibonacci(n-2);
}

int didaiFibonacci(int n)
{
    int a = 1;
    int b = 2;
    int c = a + b;
    if (n == 1)
        return a;
    if (n == 2)
        return b;

    for (int i = 3; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int count = 3;
    for(; ;++count){
#if TEST_RECURSE
        if (recurseFibonacci(count) > MAX)
#else
        if (didaiFibonacci(count) > MAX)
#endif
            break;
    }
    printf("count is %d\n", count);

    long result = 0;
    for (int i = 2; i < count;){
#if TEST_RECURSE
        result += recurseFibonacci(i);
#else
        result += didaiFibonacci(i);
#endif
        i += 3;
    }
    printf("result is %ld\n", result);
}
