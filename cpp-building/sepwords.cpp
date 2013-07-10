#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int i,j;
    int m = 0;
    int a[101];
    char str[101];
    gets(str);
    cout << "str is " << str << endl;

    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]==' ') && (str[i+1]!=' '))
            a[m++]=i+1;
    }

    //test
    for(i = 0; i < m; i++){
        cout << a[i] << endl;
    }
   
    for(i = m - 1;i>=0;i--)
    {
        for(j=a[i];str[j]!='\0'&&str[j]!=' ';j++)
        {
            //printf("%c", str[j]);
            cout<<str[j];
        }
        //printf("\n");
        cout<<endl;
    }

    if(str[0]!=' ')
    {
        for(i=0;str[i]!='\0'&&str[i]!=' ';i++)
            cout<<str[i];
    }
    //system("pause");
    return 0;
}
