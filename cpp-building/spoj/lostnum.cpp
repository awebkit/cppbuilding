//缺失的数字  by MoreWindows( http://blog.csdn.net/MoreWindows )   
#include <stdio.h>  
int main()  
{  
    printf("缺失的数字 --- by MoreWindows( http://blog.csdn.net/MoreWindows )  ---\n\n");  

    const int MAXN = 15;  
    int a[MAXN] = {1, 347, 6, 9, 13, 65, 889, 712, 889, 347, 1, 9, 65, 13, 712};  
    int lostNum = 0;  
    for (int i = 0; i < MAXN; i++)  
        lostNum ^= a[i];  
    printf("缺失的数字为:  %d\n", lostNum);     
    return 0;  
}  
