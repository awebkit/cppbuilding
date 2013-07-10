#include <stdio.h>
#include <stdlib.h>

int Line=10;//标记行
int List=10;//标记列

// 迷宫路径，大小可以随意改变  但入口必为(1,1) 出口必为(Line-2,List-2)  
int Maze[10][10]={
        1,1,1,1,1,1,1,1,1,1,
        1,0,1,0,0,0,1,0,0,1,
        1,0,0,0,1,0,0,0,0,1,
        1,0,1,1,1,1,0,1,0,1,
        1,0,0,0,1,1,0,1,0,1,
        1,1,1,0,0,0,1,1,0,1,
        1,0,1,0,0,0,1,0,0,1,
        1,0,0,1,1,1,0,0,0,1,
        1,1,0,0,0,0,0,1,0,1,
        1,1,1,1,1,1,1,1,1,1};
                    
////存储迷宫的路径      
typedef struct _Path
{
    int H;
    int L;
    struct _Path *next;
    struct _Path *front;    
}Path;

Path *head,*p,*q;

//初始化链表
void init()
{
    q=p=head=(Path *)malloc(sizeof(Path));
    if(head==NULL)
    {
        printf("存储空间分配错误\n");
    }
    head->H=head->L=0;
    head->next=NULL;
    head->front=NULL;
}

//创建链表，记录走出迷宫的路径
void Creat_link(int x,int y)
{
    q->next=p=(Path *)malloc(sizeof(Path));
    if(p==NULL)
    {
        printf("存储空间分配错误\n");
    }
    p->H=x;
    p->L=y;
    (head->H)+=1;
    p->next=NULL;
    p->front=q;
    q=p;    
}

//删除链表空间
void Delete_link_o_Node(Path *p)
{   Path *a;
    a=p;
    while(a!=NULL)
    {   (head->H)-=1;
        a=p->next;
        free(p);
        p=a;
    }
}

//打印走出路径
void print_Maze_Path()
{
    Path *a;
    int i=1;
    a=head->next;
    while(a!=NULL)
    {
        printf("第%3d步:(%d,%d);\n",i,a->H,a->L);
        i++;
        a=a->next;  
    }   
}

//走出迷宫算法
void Algorithm()
{   
    int x=1,y=1;
    while(1)
    {   
        if(((x==(Line-2))&&(y==(List-2))))//判断是否到出口
        {   
            Creat_link(x,y);
            printf("总共走了%d步，具体路径如下：\n",head->H);
            
            print_Maze_Path();
            return;
        }
        if(Maze[x+1][y]==0)//判断下方是否有通路
        {
            Creat_link(x,y);
            Maze[x][y]=2;
            x+=1;   
            continue;
        }
        if(Maze[x][y+1]==0)//判断右
        {
            Creat_link(x,y);
            Maze[x][y]=2;
            y+=1;           
            continue;
        }
        if(Maze[x-1][y]==0)//判断左
        {
            Creat_link(x,y);
            Maze[x][y]=2;
            x-=1;
            continue;
        }
        if(Maze[x][y-1]==0)//判断上
        {
            Creat_link(x,y);
            Maze[x][y]=2;
            y-=1;
            continue;
        }
        if((Maze[x+1][y]==2)&&(((x+1)==p->H)&&((y==p->L))))//没有通路的情况下，按原路返回
        {   
            q=p->front;
            Delete_link_o_Node(p);
            Maze[x][y]=3;
            p=q;
            p->next=NULL;
            x+=1;   
            continue;
        }
        if((Maze[x][y+1]==2)&&(((x)==p->H)&&(((y+1)==p->L))))
        {
            q=p->front;
            Delete_link_o_Node(p);
            Maze[x][y]=3;
            p=q;
            p->next=NULL;
            y+=1;
            continue;
        }
        if((Maze[x-1][y]==2)&&(((x-1)==p->H)&&((y==p->L))))
        {
            q=p->front;
            Delete_link_o_Node(p);
            Maze[x][y]=3;
            p=q;
            p->next=NULL;
            x-=1;   
            continue;
        }
        if((Maze[x][y-1]==2)&&((x==p->H)&&(((y-1)==p->L))))
        {
            q=p->front;
            Delete_link_o_Node(p);
            Maze[x][y]=3;
            p=q;
            p->next=NULL;
            y-=1;
            continue;
        }
        printf("走到(%d,%d)是没有可走的路！\n具体路径如：\n");
        print_Maze_Path();
        return;
    }
}

//打印迷宫
void print_Maze()
{   
    int i,j;
    for(i=0;i<Line;i++)
    {
        for(j=0;j<List;j++)
            printf("%d ",Maze[i][j]);
        printf("\n");       
        
    }
}


int main(int argc,char *argv[])
{
    init();
    print_Maze();
    Algorithm();
    Delete_link_o_Node(head);
    return 0;
}
