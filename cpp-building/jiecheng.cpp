#include <stdio.h>

int calc(int a[])
{
    a[0] = 1;
    int startPos = 0;
    for (int i = 2; i <= 100; ++i){
        //{i < 100 && startPos < 200}
        //
        for (int j = startPos; j >= 0; --j){
            //{j <= startPos && j >=0}
            a[j] *= i;
        }
        //
        for (int k = 0; k <= startPos; ++k){
            //{k >=0 && k <=startPos}
            a[k+1] += a[k] / 10;
            a[k] %= 10;
            if ((k == startPos) && (a[k+1] != 0)){
                startPos++;
            }
        }
    }
    return startPos;
}

int main()
{
    int a[200] = {0};
    int start = calc(a);
    for (int i = start; i >= 0; --i ){
        printf("%d", a[i]);
    }
    printf("/n");
    return 0;
}
