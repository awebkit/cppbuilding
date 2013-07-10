#include <stdio.h>

#define ASIZE 26
#define XSIZE 6

void print(int *t, int m)
{
    for (int i=0; i<m; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}

//壞字符規則計算
void preBmBc(char *x, int m, int bmBc[]) {  
    int i;  
    for (i = 0; i < ASIZE; ++i)         
        bmBc[i] = m;  

    for (i = 0; i < m - 1; ++i) {
        printf("i %d, x[i] %c, x[i] - 'a' %d : %d\n", i, x[i], x[i] - 'a', m - i - 1);
        bmBc[x[i]-'a'] = m - i - 1;    
    }
} 
//stuff輔助數組計算   
void suffixes(char *x, int m, int *suff) 
{    
    int f, g, i;   
    f = 0;            //上次匹配成功的位置
    suff[m - 1] = m;   
    g = m - 1;        //上次匹配失敗的位置
    for (i = m - 2; i >= 0; --i) {  
        if (i > g && suff[i + m - 1 - f] < i - g)  {
            printf("i %d between g f suff[%d] %d\n", i, i+m-1-f, suff[i + m - 1 -f]);
            suff[i] = suff[i + m - 1 - f];    
        } else {
           printf("i is not between\n");  
            if (i < g) { 
                g = i;
            }
            f = i;  
            while (g >= 0 && x[g] == x[g + m - 1 - f]){ //匹配成功則一直匹配 
                printf("match ====\n");
                --g;
            }
            printf("suff[%d] f - g = %d \n", i, f - g); 
            suff[i] = f - g;  
        }  
    }
}

void suffBaoli(char *x, int m, int* suff)
{  
    suff[m-1]=m;
    for (int i = m - 2; i>=0;--i){
        int q=i;
        while (q>=0&&x[q]==x[m-1-i+q]){
            printf("match q %d m-1-i+q %d\n", q, m-i-i+q);
            --q;
        }
        suff[i]=i-q;
    }
}  

//好後綴規則實現
void preBmGs(char *x, int m, int bmGs[]) {  
    int i, j, suff[XSIZE];  

    printf("calculate suffix:\n");
    //suffBaoli(x, m, suff);
    suffixes(x, m, suff);    
    printf("print suffix:\n");
    print(suff, XSIZE);

    for (i = 0; i < m; ++i)  //情況3
        bmGs[i] = m;  

    printf("after situation 3\n");
    print(bmGs, XSIZE);
    j = 0;  
    for (i = m - 1; i >= 0; --i)   //情況2 
        if (suff[i] == i + 1){  
            printf("suff[i] == i + 1, i is %d\n", i);
            for (; j < m - 1 - i; ++j)  
                if (bmGs[j] == m)  {
                    printf("bmGs[j] == m, j %d\n", j);
                    bmGs[j] = m - 1 - i;  
                }
        }

    for (i = 0; i <= m - 2; ++i){    //情況1  
        bmGs[m - 1 - suff[i]] = m - 1 - i;
    }
}  

int MAX(int a, int b)
{
    return a>b? a: b;
}

//BM算法主體部分，x为模式串，y为目標串
void BM(char *x, int m, char *y, int n) {  

    int i, j, bmGs[XSIZE], bmBc[ASIZE];  

    /* Preprocessing */  


    preBmBc(x, m, bmBc);  
    print(bmBc, ASIZE);

    preBmGs(x, m, bmGs);
    print(bmGs, XSIZE);

    /* Searching */  

    j = 0;  

    while (j <= n - m) {  
        for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);  
        if (i < 0) {  
            printf("xx %d \n",j);
            j += bmGs[0];
            printf("j n m is %d %d %d\n", j, n, m);
        }  
        else {
            //test bad char
            //printf("before j is %d, i is %d, y[] is %c\n", j, i, y[i+j]);
            //j += bmBc[y[i + j] - 'a'] - (m - 1 - i);

            //test good suffix
            //printf("j is %d, i is %d, gs is %d\n", j, i, bmGs[i]);
            //j += bmGs[i];
            //printf("j move to %d\n", j);
            
            j += MAX(bmGs[i], bmBc[y[i + j]-'a'] - m + 1 + i);  
        }

    }   
}  

int main()
{
    //char target[11] = "iabcdabcab";
    //char target[11] = "dabcabcdbb";
    char target[11] = "abacabdeab";
    char pattern[XSIZE+1] = "ababab";
    //char pattern[XSIZE+1] = "dabcab";

    BM(pattern, XSIZE, target, 10);

    return 0;
}
