#include<stdio.h>
int a=0;int count=0;

void MysteryFunc(int b){
    int tmp = 1;
    //printf("***************** %d %p\n", b, &tmp);
    if(b==0){
        count++;
        printf("%d:%d\n",count,a);
    }

    a=a+b;

    for(int i=b-1;i>=0;--i){
        //printf("======== %d %p\n", i, &tmp);
        MysteryFunc(i);
    }
}

int main()
{
    MysteryFunc(2);
    printf("\n%d\n",a);
    return 0;
}
