#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
char cmap[] = "22233344455566670778889990";

vector<int> ivector;
void myqsort(int l, int u)
{
    if (l >= u)
        return;

    int i = l;
    int j = u + 1;
    int t = ivector[l];
    while(1){
        do {
            i++;
        } while ((i <= u) && (ivector[i] < t) );
        do {
            j--;
        } while(ivector[j] > t); 
        if (i > j)
            break;
        int tmp = ivector[i];
        ivector[i] = ivector[j];
        ivector[j] = tmp;
    }   

    ivector[l] = ivector[j];

    ivector[j] = t;

    myqsort(l, j - 1); 
    myqsort(j + 1, u); 
}

int main()
{
    int m;
    cin >> m;
    //string s;
    char s[50];
    for(int j = 0;j < m; ++j){ 
        fscanf(stdin, "%s", s);
        //cin >> s;
        int num = 0;
        for (int i = 0; s[i]!='\0'; ++i) {
            char c = s[i];
            if (c >= '0' && c <='9'){
                num *= 10;
                num += c - '0';
            } else if ( (c >= 'A') && (c < 'Z') && (c != 'Q')){
                num *= 10;
                num += cmap[c - 'A'] - '0'; 
            }
        }
        ivector.push_back(num);
    }
    
    vector<int>::iterator it;
    myqsort(0, ivector.size() - 1);
    
    int count = 1;
    bool hasDuplicate = false;

    vector<int>::iterator end = ivector.end();
    for(it = ivector.begin() + 1; it < end; it++){
        count = 1;
        while (it < end && *it == *(it - 1)) {
            count++;
            it++;
        }
        if (count > 1) {
            printf("%03d-%04d %d\n", *(it - 1)/10000, *(it - 1)%10000, count);
            hasDuplicate = true;
        }
    }

    if (hasDuplicate == false)
        printf("No duplicates. \n");

    return 0;
}
