#include <stdio.h>

int main()
{
    int input;
    while(scanf("%d", &input) > 0){
        if (input == 42)
            break;
        printf("%d\n", input);
    }
}
