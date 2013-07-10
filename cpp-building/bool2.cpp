#include<iostream>
#include<cstring>
#include <stdio.h>
using namespace std;
#define TEST 0 
int lastChild(char a[], int n) {
    //a[n-1] must be F/V/)
    if (a[n - 1] != ')'){
        if (a[n - 2] == '!'){
            return n - 2;
        } else
            return n - 1;
    } else{
        int i = n - 2;
        int value = 1;
        for (; i >= 0; --i){
            if (a[i] == ')')
                value++;
            if (a[i] == '('){
                value--;
                if (value == 0){
                    //Got it. However, we should judge '!'
                    // loop for not !

                    if (i == 0)
                        return 0;
                    int j = i;
                    for (;j >0; --j){
                        if (a[j - 1] != '!')
                            return j;
                    }
                    return j;

                    /*
                       if ( i > 0){
                       if (a[i - 1] == '!')
                       return i - 1;
                       }else
                       return i;
                       */

                }
            }
        }
        cout << "Error, can not match ), please reinput" << endl;
    }
}

bool judgeBool(char a[], int n){
#if TEST
    cout << "begin number " << n;
    int k = 0;
    for (; k < n; ++k){
        cout << " " << a[k] ;
    }
    cout << endl;
#endif

    if ( n == 1){
        if (a[0] == 'F')
            return false;
        else if (a[0] == 'V')
            return true;
        else
            cout << "Error, please reinput" << endl;
    }

    if ( n == 2) {

        if ( a[0]!= '!' || a[1] != 'F' && a[1] != 'V')
            cout << "Error, please check input" << endl;

        //Because a[0] == '!'
        if (a[1] == 'F')
            return true;
        else
            return false;
    }

    int m = lastChild(a, n);
#if TEST
    cout << "last child position " << endl;
    //system("pause");
#endif
    bool result;
    //int p = m;
    if (a[m] == '(') {
        result = judgeBool(&a[m + 1], n - m - 2);

    } else if (a[m] == '!'){ //we can change here future


        if (a[m + 1] == '!' && a[m + 2] == '!' && a[m + 3] == '(' ){
            result = judgeBool(&a[m + 4], n - m - 5);
            if (result == true)
                result = false;
            else
                result = true;
        } else if (a[m + 1] == '!' && a[m + 2] == '(' ){
            result = judgeBool(&a[m + 3], n - m - 4);
        } else if (a[m + 1] == '('){
            result = judgeBool(&a[m + 2], n - m - 3);
            if (result == true)
                result = false;
            else
                result = true;
        } else {
            if (a[m + 1] == 'V')
                result = false;
            else
                result = true;
        }

    } else{
        result = judgeBool(&a[m], n - m);

    }

#if 0
    cout << "result is " ;
    if (result == true)
        cout << "true";
    else
        cout << "false";
    cout << endl;
#endif

    if (m == 0)
        return result;

    if ((result == true) && (a[m - 1] == '|'))
        return true;
    if ((result == false) && (a[m - 1] == '&'))
        return false;

    return judgeBool(a, m - 1);
}
int main(){
    char a[1000],b[1000];
    int l;
    while(1)
    {

        int m=0;
        cin.getline(b, 1000);
        //memset(b, 0, sizeof(b));
        //gets(b);
        if(b[0]=='\0')
            break;
        //strcpy(b, "F&!F | !V|!V & !F& !( F | F& (V | !F| !V| V& (V|F))) ");

        //cout << "begin next ..." << "[" << b << "]" <<endl;
        for(int i=0;b[i]!='\0';i++){
            if(b[i]!=' ')a[m++]=b[i];}
        a[m]='\0'; 
        l=strlen(a);
#if 0
        for(int i = 0; i < l; ++i){
            cout<<a[i]<<" ";
        }
        cout << endl;
#endif
        //if(l==1&&a[0]=='V'){cout<<"V"<<endl; continue;}
        //else{
        bool ret = judgeBool(a, l);
        if (ret == true)
            cout << "XXXV";
        else
            cout << "XXXF";
        cout <<endl;
        //}


    }

    return 0;
}
