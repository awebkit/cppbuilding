#include <stdio.h>

void judge(int num, int key)
{
    if ((num & (1 << key)) != 0)  
        printf("指定位上为1");  
    else  
        printf("指定位上为0"); 
}

int main()
{
    judge(8, 2);
    judge(7, 2);
}
