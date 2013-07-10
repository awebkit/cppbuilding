/*
 * 8*8 棋盘，输入x y（从0开始）
 * 输出能否走完棋盘
 */
#include <iostream>
#include <string.h>

using namespace std;

struct cord{
    int xPos;
    int yPos;
};
const int row = 8;
const int col = 8;

int record[row][col] = {0};
int travel(int x, int y)
{
    const int dir = 8;
    // 8 direction
    const cord pos[dir] = {
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1}
    };

    cord next[dir];
    memset(next, 0, sizeof(next));
    int stepX = x;
    int stepY = y;
    record[x][y] = 1;
    int exist[dir] = {0};
    int min = 0;
    for (int step = 2; step <= (row * col); ++step){
        //reset
        for (int m = 0; m < dir; ++m){
            exist[m] = 0;
        }

        int l = 0;

        //try 8 directions
        for (int i = 0; i < dir; ++i){
            int tmpX = stepX + pos[i].xPos;
            int tmpY =  stepY + pos[i].yPos;

            //check
            if (tmpX < 0 || tmpY < 0 || tmpX > (col - 1)  || tmpY > (row - 1)){
                continue;
            }
            //record it if it is ok
            if (record[tmpX][tmpY] == 0){
                next[l].xPos = tmpX;
                next[l].yPos = tmpY;
                l++;
            }
        }
        //

        int count = l;
        
        if (count == 0){
            return 0;
        } else if (count == 1){
            min = 0;
        } else {
            //minimal dir of next
            for (int j = 0; j < count; ++j){
                for (int k = 0; k < dir; ++k){
                    int tmpX = next[j].xPos+ pos[k].xPos;
                    int tmpY = next[j].yPos + pos[k].yPos;
                    //check
                    if (tmpX < 0 || tmpY < 0 || tmpX > (col - 1)  || tmpY > (row - 1)){
                        continue;
                    }
                    //record it if it is ok
                    if (record[tmpX][tmpY] == 0){
                        //
                        exist[j]++;
                    }
                }
            }
            //
            int tmp = exist[0];
            min = 0;
            for (int j = 0; j < count; ++j){
                if (tmp > exist[j]){
                    tmp = exist[j];
                    min = j;
                }
            }
        }

        //go minimal dir
        stepX = next[min].xPos;
        stepY = next[min].yPos;
        record[stepX][stepY] = step;
    }
    return 1;
}

int main()
{
    int startX, startY;
    cin >> startX >> startY;
    cout << "startX startY" << startX << " " << startY << endl;
    if (travel(startX, startY)){
        cout << "can travel the world" << endl;
    } else {
        cout << "can NOT travel the world" << endl;
    }

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            cout << record[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
