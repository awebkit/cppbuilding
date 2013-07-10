#include <iostream>
#include <stdio.h>

using namespace std;

//#define DEBUG  
  
#ifdef DEBUG  
#define debug(...) printf( __VA_ARGS__)   
#else  
#define debug(...)  
#endif
int w, h;
int count = 0;
char input[32][32];

void cnt(int i, int j)
{
    if (i < 0 || j < 0 || i > h - 1 || j > w - 1 || input[i][j] == '#')
        return;

    count++;
    input[i][j] = '#';
    cnt(i, j - 1);
    cnt(i - 1, j);
    cnt(i, j + 1);
    cnt(i + 1, j);
}
int main()
{
    while(1){
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        char s[32];
        count = 0;
        int starti, startj;
        for(int i = 0; i < h; ++i){
            fscanf(stdin, "%s", s);
            for (int j = 0; j < w; ++j){
                input[i][j] = s[j];
                if (s[j] == '@'){
                    starti = i;
                    startj = j;
                }
            }
        }

        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                debug("%c", input[i][j]);
            }
            debug("\n");
        }
        debug("start %d %d\n", starti, startj);
        cnt(starti, startj);
        printf("%d\n", count);
    }
    return 0;
}
