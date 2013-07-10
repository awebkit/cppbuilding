#include <stdio.h>  
int main()  
{  
    printf("     对数组中指定位置上置位和判断该位\n");  
    printf("--- by MoreWindows( http://blog.csdn.net/MoreWindows )  ---\n\n");  
    //在数组中在指定的位置上写1  
    int b[5] = {0};  
    int i;  
    //在第i个位置上写1  
    for (i = 0; i < 40; i += 3)  
        b[i / 32] |= (1 << (i % 32));  
    //输出整个bitset  
    for (i = 0; i < 40; i++)  
    {  
        if ((b[i / 32] >> (i % 32)) & 1)  
            putchar('1');  
        else   
            putchar('0');  
    }  
    putchar('\n');  
    return 0;  
} 
