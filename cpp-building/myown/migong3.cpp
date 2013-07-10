#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define INIT_SIZE 100 //存储空间初始分配量
#define INCREMENT 10  //存储空间分配增量
typedef struct{       
         int r; //迷宫中r行c列的位置
         int c;
}PostType;
typedef struct{
         int  ord;      //当前位置在路径上的序号
         PostType seat;//当前坐标
         int  di;       //往下一坐标的方向
}SElemType;        //栈内元素类型
typedef struct{
         SElemType* base;
         SElemType* top;
         int stackSize;
}Stack;             //栈类型
Status InitStack(Stack &S){  //构造空栈S
         S.base=(SElemType*)malloc(INIT_SIZE *sizeof(SElemType));
         if(!S.base)
                   exit(OVERFLOW);//存储分配失败
         S.top=S.base;
         S.stackSize=INIT_SIZE;
         return OK;
}//InitStack
Status StackEmpty(Stack S){         
//若s为空返回TRUE,否则返回FALSE
         if(S.top==S.base)
                   return TRUE;
         return FALSE;
}//StackEmpty

Status Push(Stack &S,SElemType e){
    //插入元素e为新的栈顶元素
    if(S.top-S.base >=S.stackSize){//栈满，加空间
        S.base=(SElemType *)realloc(S.base,(S.stackSize+INCREMENT)*sizeof(SElemType));
        if(!S.base)
            exit(OVERFLOW);   //存储分配失败
        S.top=S.base+S.stackSize;
        S.stackSize+=INCREMENT;
    }
    *S.top++=e;
    return OK;
}//push

Status Pop(Stack &S,SElemType &e){//若栈不空删除栈顶元素用e返回并返回OK，否则返回ERROR
         if(S.top==S.base)
                   return ERROR;
         e=*--S.top;
         return OK;
}//Pop

#define MAXLEN 10//迷宫包括外墙最大行列数目
typedef struct{
         int r;
         int c;
         char adr[MAXLEN][MAXLEN];
}MazeType;   //迷宫类型
Status InitMaze(MazeType &maze){ //初始化迷宫，把初始化改为输入就能够进行动态建立迷宫
         int i,j;        
         maze.r=8;maze.c=8; //迷宫行和列数
         for(i=0;i<10;i++){//迷宫行外墙
                   maze.adr[0][i]='#';
                   maze.adr[9][i]='#';
         }
         for(i=0;i<10;i++){//迷宫列外墙
                   maze.adr[i][0]='#';
                   maze.adr[i][9]='#';
         }
         for(i=1;i<9;i++)
                   for(j=1;j<9;j++)
                            maze.adr[i][j]='1';//初始化迷宫
  //设定通道块上的不通的路块 
   maze.adr[1][3]='#';maze.adr[1][7]='#';maze.adr[2][3]='#';maze.adr[2][7]='#';maze.adr[3][5]='#';maze.adr[3][6]='#';
   maze.adr[4][2]='#';maze.adr[4][3]='#';maze.adr[4][4]='#';maze.adr[5][4]='#';maze.adr[6][2]='#';maze.adr[6][6]='#';
   maze.adr[7][2]='#';maze.adr[7][3]='#';maze.adr[7][4]='#';maze.adr[7][6]='#';maze.adr[7][7]='#';maze.adr[8][1]='#';
         return OK;
}//InitMaze         

Status Pass(MazeType maze,PostType curpos){
//判断当前位置是否可通
         if(maze.adr[curpos.r][curpos.c]==1)//可通
                   return TRUE;
         else
                   return FALSE;
}//Pass
Status FootPrint(MazeType &maze,PostType curpos){
//走过并且可通
         maze.adr[curpos.r][curpos.c]=3;//"*"表示可通
         return OK;
}//FootPrint
PostType NextPos(PostType &curpos,int i){
    //探索下一位置并返回下一位置的坐标
    PostType cpos;
    cpos=curpos;
    switch(i){        //1.2.3.4分别表示东,南,西,北方向
        case 1 : cpos.c+=1; break;
        case 2 : cpos.r+=1; break;
        case 3 : cpos.c-=1; break;
        case 4 : cpos.r-=1; break;
        default: exit(ERROR);  
    }
    return cpos;
}//Nextpos

Status MarkPrint(MazeType &maze,PostType curpos){
//曾走过但不通留下标记并返回OK
         maze.adr[curpos.r][curpos.c]='@';//"@"表示曾走过但不通
         return OK;
}//MarkPrint
Status MazePath(MazeType &maze,PostType start,PostType end){
    //迷宫maze存在从入口start到end的通道则求得一条存放在栈中
    Stack S;
    PostType curpos;
    int curstep;//当前序号,1.2.3.4分别表示东,南,西,北方向
    SElemType e;
    InitStack(S);
    curpos=start; //设置"当前位置"为"入口位置"
    curstep=1;   //探索第一步
    do{   
        if(Pass(maze,curpos)){     //当前位置可以通过,
            FootPrint(maze,curpos);//留下足迹
            e.ord=curstep;
            e.seat=curpos;
            e.di=1;
            Push(S,e);              //加入路径
            if(curpos.r==end.r&& curpos.c==end.c)
                return TRUE; //到达出口             
            curpos=NextPos(curpos,1); //下一位置是当前位置的东邻
            curstep++;       //探索下一步                            
        }
        else{        //当前位置不通
            if(!StackEmpty(S)){        
                Pop(S,e);
                while(e.di==4 && !StackEmpty(S)){
                    MarkPrint(maze,e.seat);
                    Pop(S,e);         //留下不能通过的标记,并退一步
                }//while
                if(e.di < 4){
                    e.di++;//换下一个方向探索
                    Push(S,e);            
                    curpos=NextPos(e.seat,e.di);//设定当前位置是该新方向上的相邻
                }
            }
        }
    }while(!StackEmpty(S));
    return OK;
}//MazePath

void PrintMaze(MazeType &maze){ //
    int i,j;
    printf("用心形代表迷宫的从入口到出口的一条路径\n");
    printf("用#代表墙和不通的地方用@代表曾走过的通道块但不通\n");
    printf("用笑脸代表可以通过的通道块\n");
    printf("  ");
    for(i=0;i<10;i++)//打印列数名
        printf("%4d",i);
    printf("\n\n");
    for(i=0;i<10;i++){
        printf("%2d",i);//打印行名 
        for(j=0;j<10;j++)
            printf("%4c",maze.adr[i][j]);//输出迷宫//当前位置的标记          
        printf("\n\n");
    }
    printf("通道块坐标：");
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(maze.adr[i][j]==3)
                printf("(%d,%d)",i,j);
    printf("===============================\n");
}//PrintMaze

int main( ){     //主函数
    MazeType maze;
    PostType start,end;
    InitMaze(maze);//初始化并创建迷宫
    start.r=1;start.c=1;//迷宫入口坐标
    end.c=8;end.r=8; //迷宫出口坐标
    PrintMaze(maze);
    MazePath(maze,start,end);
    
    PrintMaze(maze);//打印路径

    return 0;
}
