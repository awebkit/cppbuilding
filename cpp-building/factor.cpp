#include <stdio.h>

using namespace std;

int factor(int n)
{
    int answer;
    if (n == 1)
        return 1;
    answer = factor(n - 1) * n;
    return answer;
}
/*
int factor(int n)
{
    int t, answer;
    answer = 1;

    for (t = 1; t <= n; ++t)
        answer = answer * t;

    return answer;
}
*/

int main()
{
   int a = factor(6);
   printf("factor is %d\n", a);

   return 0;
}
