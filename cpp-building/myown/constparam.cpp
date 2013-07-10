#include <iostream>  
#include <cstdio>  
using namespace std;  
void CheckPointerValue(void *pVoid)  
{  
    printf("the pointer's value is :%p/n",pVoid);  
}  
int main()  
{  
    int i = 100;  
    int *pInt = &i;  
    printf("original pointer's value = %p/n",pInt);  
    CheckPointerValue(pInt);  
    return 0;  
}  
