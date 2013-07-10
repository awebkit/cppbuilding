#include <iostream>   
#include <string>   
#include <stdio.h>

using namespace std;   

const  int  COUNT_OF_NUMBER  = 4;   
const  int  NUMBER_TO_BE_CAL = 24;   

int number[COUNT_OF_NUMBER] = {5, 5, 1, 0};   
bool found24 = false;

void  Search(int   n)   
{   
    if (n   ==   1) 
    {
        cout << "number[0]:" << number[0] << endl;   
        if (number[0] == NUMBER_TO_BE_CAL)
        {   
            found24 = true; 
        }   
    }

    for(int i=0;  i < n; i++) 
    { 
        for (int j = i + 1; j < n; j++) 
        {   
            int a, b;   
            a   =   number[i];   
            b   =   number[j];   
            number[j]  =  number[n - 1];   //递归之后，n比以前小一位，所以可以不停向前赋值  
            number[i]   =   a   +   b;   
            Search(n-1); 
            number[i]   =   a   -   b;   
            Search(n-1);  
            number[i]   =   b   -   a;   
            Search(n-1);  
            number[i]   =   a   *   b;   
            Search(n-1);  
            if (b != 0) 
            {   
                number[i] = a / b;   
                Search(n-1);   
            }     
            if (a != 0) 
            {   
                number[i]   =   b  /  a;   
                Search(n-1);   
            }   
            number[i]   =   a;                  //这4句语句是为了防止如果上面几种可能都失败了的话, 
            number[j]   =   b;                  //就把原来的赋值撤消回去,以无干扰的正确的进入到下一次 
            //expression[i]   =   expa;           //for循环队列中。 
            //expression[j]   =   expb;           // 
        } 
    } 
}   
int  main()   
{   
    cout<<"Please input 4 value of Cards:\n"; 

    cout<<endl; 
    
    Search(COUNT_OF_NUMBER) ; 
    if(found24==true) 
        printf("YES\n");
    else 
        printf("NO\n");
    //system("pause"); 
    return 0; 
}  
