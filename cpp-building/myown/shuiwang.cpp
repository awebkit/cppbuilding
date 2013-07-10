#include<stdio.h>

int Find(int *ID, int n)
{
        int candidate, i;
        int ntimes;//the time water king appear

        for(i=0,ntimes=0; i<n; i++){
                printf(",,,,, %d\n", i);
                if(ntimes == 0){
                        printf("000 candidata %d\n", i);
                        candidate = ID[i];
                        ntimes = 1;
                }
                else{
                    if(candidate == ID[i]){
                        ntimes ++;
                        printf("candidata %d, times %d\n", i, ntimes);
                    } else{
                        ntimes --;
                    }
                }
        }
        return candidate;
}

int main()
{
        int a[7] = {2,3,3,3, 2, 2, 2};

        printf("the water king's id is %d\n", Find(a, 7));

        return 0;
}
