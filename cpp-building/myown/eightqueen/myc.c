#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int queen[MAX];
int sum = 0;

void show()
{
    int i = 0;
    for (i = 0; i < MAX; ++i){
        printf("(%d, %d)", i, queen[i]);
    }
    printf("\n");
}

int check(int n)
{
    int i = 0;
    for (i = 0; i < n; ++i){
        if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i)){
            return 1;
        }
    }
    return 0;
}

void put(int n)
{
    int i = 0;
    for (i = 0; i < MAX; ++i){
        queen[n] = i;
        if (!check(n)){
            if (n == MAX - 1){
                show();
                sum++;
            } else {
                put(n + 1);
            }
        }
    }
}

int main()
{
    put(0);
    printf("%d\n", sum);

    return 0;
}
