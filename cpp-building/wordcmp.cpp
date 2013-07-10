#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//a 大于b，返回1
//a 等于b，返回0
//a 小于b，返回负数
int compare(char* a1, char* b1)
{
    cout << "a is " << a1 << "b is " << b1 << endl;

    char a[100];
    char b[100];
    strcpy(a, a1);
    strcpy(b, b1);
    int i = 0;
    for (i = 0; (a[i] != '\0') || (b[i] != '\0') ; ++i){
        
        if (a[i] < 97)
            a[i] += 32; 

        if (b[i] < 97)
            b[i] += 32; 

        if (a[i] > b[i]){
            return 1;
        } else if (a[i] < b[i])
            return -1;
    }
    if (a[i] == '\0')
        return -1;
    if (b[i] == '\0')
        return 1;
    //return strcasecmp(a, b);    
}

int main()
{
    char str[100];
    gets(str);

    //10个单词，最大长度32
    char word[10][32];
    int m = 0;
    int n = 0;
    for (int i = 0; ; ++i){
        if ((str[i] == ' ') || (str[i] == '\0')) {
            word[n++][m++] = '\0';
            m = 0;
            if (str[i] == '\0')
                break;
         } else {
            word[n][m++] = str[i];
        }
    }

    for (int i = 0; i < n; ++i){
        cout << word[i] << endl;
    }

    //sort begin

    char tmp[32];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            //if (a[j] > a[j+1]){
            if (compare(word[j], word[j+1]) > 0){
                strcpy(tmp, word[j]);
                strcpy(word[j], word[j+1]);
                strcpy(word[j+1], tmp);
            }
        } 
    }

    cout << "after sort:" <<endl;
    for (int i = 0; i < n; ++i){
        cout << word[i] << endl;
    }
    return 0;
}
