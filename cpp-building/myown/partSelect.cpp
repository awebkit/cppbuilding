#include <stdio.h>

void find(const char* source, char* result, int n)
{
    if (n == 1){
        while(*source){
            printf("source %s\n", source);
            printf("%s - %c\n",result, *source++);
        }
    } else {
        int i, j;
        for (i=0;source[i]!=0;++i);
        for (j=0;result[j]!=0 && j < (n+1);++j);
        for (;i>=n;--i){
            printf("source %s result %s\n", source, result);
            result[j] = *source++;
            result[j+1] = '\0';
            find(source, result, n - 1);
        }

    }
}

int main()
{
    const int n = 3;
    const char *source = "abcde";
    char result[n+1] = {0};

    find(source, result, n);
    return 0;
}
