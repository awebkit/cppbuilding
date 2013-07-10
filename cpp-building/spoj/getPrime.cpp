#include <stdio.h>
#include <memory.h>

const int MAX = 100;
int pi;
int prime[MAX/3];
int flag[MAX/32];
void get_prime()
{
    pi = 0;
    memset(flag, 0, sizeof(flag));
    for (int i = 2; i < MAX; ++i){
        if (!((flag[i / 32] >> (i % 32)) & 1)){
            prime[pi++] = i;
            for (int j = i; j < MAX; j += i)
                flag[j / 32] |= (1 << (j % 32));
        }
    }
}
void print_prime()
{
    for (int i = 0; i < pi; ++i)
        printf("%d ", prime[i]);
    printf("\n");
}

int main()
{
    get_prime();
    print_prime();
    return 0;
}
