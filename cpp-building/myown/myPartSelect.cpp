#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void find(const char* source, char* result, int n)
{
    int len = strlen(source);
    if (n == 0){
        printf("%s\n", result);
    } else {
        int i;
        int j;
        for (j = 0; *(result+j) != 0; ++j);
        for (i = 0; i < len - n + 1; ++i){
            result[j] = *source;
            result[j+1] = '\0';
            source++;
            find(source, result, n - 1);
        }
    }
}

int main()
{
    const int n = 3;
    const char* source = "abcde";
    char result[n+1] = {0};

    find(source, result, n);

    return 0;
}
