#include <stdio.h>
#include <string.h>
#include <math.h>
//link:  http://zh.wikipedia.org/wiki/%E4%BA%8C%E5%8F%89%E6%A0%91
#include "seqtree.h"
/* 二叉树的顺序存储的基本操作(23个)*/
#define ClearBiTree InitBiTree /* 在順序存儲結構中，兩函數完全一樣 */
#define DestroyBiTree InitBiTree /* 在順序存儲結構中，兩函數完全一樣 */

void InitBiTree(SqBiTree T)
{ /* 構造空二叉樹T。因為T是數組名，故不需要& */
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++)
        T[i]= Nil;
}

void CreateBiTree(SqBiTree T)
{ /* 按層序次序輸入二叉樹中結點的值(字符型或整型), 構造順序存儲的二叉樹T */
    int i=0;
#if CHAR /* 結點類型為字符 */
    int l;
    char s[MAX_TREE_SIZE];
    InitBiTree(T); /* 構造空二叉樹T */
    printf("請按層序輸入結點的值(字符)，空格表示空結點，結點數≦%d:\n",MAX_TREE_SIZE);
    //gets(s); /* 輸入字符串 */
    fgets(s, MAX_TREE_SIZE, stdin);
    l=strlen(s); /* 求字符串的長度 */
    for(;i<l;i++) /* 將字符串賦值給T */
        T[i]=s[i];
#else /* 結點類型為整型 */
    InitBiTree(T); /* 構造空二叉樹T */
    printf("請按層序輸入結點的值(整型)，0表示空結點，輸999結束。結點數≦%d:\n",MAX_TREE_SIZE);
    while(1)
    {
        scanf("%d",&T[i]);
        if(T[i]==999)
        {
            T[i]=Nil;
            break;
        }
        i++;
    }
#endif
    for(i=1;i<MAX_TREE_SIZE;i++)
        if(T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* 此非根結點(不空)無雙親 */
        {
#if CHAR
            printf("出現無雙親的非根結點, %c\n",T[i]);
#else
            printf("出現無雙親的非根結點, %d\n",T[i]);
#endif
        }
}

int BiTreeDepth(SqBiTree T)
{ /* 初始條件：二叉樹T存在。操作結果：返回T的深度 */
    int i,j=-1;
    for(i=MAX_TREE_SIZE-1;i>=0;i--) /* 找到最後一個結點 */
        if(T[i]!=Nil)
            break;
    i++; /* 為了便於計算 */
    do
        j++;
    while(i>=pow(2,j));   /*pow是原型為double pow( double x, double y ),計算x的y次方,h = log<sub>2</sub>k + 1來計算二叉樹的深度*/
    return j;
}

TElemType Value(SqBiTree T,position e)
{ /* 初始條件：二叉樹T存在，e是T中某個結點(的位置) */
    /* 操作結果：返回處於位置e(層,本層序號)的結點的值 */
    return T[(int)pow(2,e.level-1)+e.order-2];
}

void Print(SqBiTree T)
{ /* 逐層、按本層序號輸出二叉樹 */
    int j,k;
    position p;
    TElemType e;
    for(j=1;j<=BiTreeDepth(T);j++)
    {
        printf("第%d層: ",j);
        for(k=1;k<=pow(2,j-1);k++)
        {
            p.level=j;
            p.order=k;
            e=Value(T,p);
            if(e!=Nil)
#if CHAR
                printf("%d:%c",k,e);
#else
                printf("%d:%d",k,e);
#endif
        }
        printf("\n");
    }
}

Status BiTreeEmpty(SqBiTree T)
{ /* 初始條件：二叉樹T存在。操作結果：若T為空二叉樹，則返回TRUE，否則FALSE */
  if(T[0]==Nil) /* 根結點為空，則樹空 */
    return TRUE;
  else
    return FALSE;
}

void MyPrint(TElemType e)
{
#if CHAR
    printf("[%c]", e);
#else
    printf("[%d]", e);
#endif
}
void(*VisitFunc)(TElemType);
void InTraverse(SqBiTree T,int e)
{ /* InOrderTraverse()調用 */
  if(T[2*e+1]!=Nil) /* 左子樹不空 */
    InTraverse(T,2*e+1);
  VisitFunc(T[e]);
  if(T[2*e+2]!=Nil) /* 右子樹不空 */
    InTraverse(T,2*e+2);
}

void InOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{ /* 初始條件：二叉樹存在，Visit是對結點操作的應用函數 */
  /* 操作結果：中序遍歷T，對每個結點調用函數Visit一次且僅一次 */
  VisitFunc=Visit;
  if(!BiTreeEmpty(T)) /* 樹不空 */
    InTraverse(T,0);
  printf("\n");
}

void LevelOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{ /* 層序遍歷二叉樹 */
    int i=MAX_TREE_SIZE-1,j;
    while(T[i]==Nil)
        i--; /* 找到最後一個非空結點的序號 */
    for(j=0;j<=i;j++){ /* 從根結點起，按層序遍歷二叉樹 */
        if(T[j]!=Nil)
            Visit(T[j]); /* 只遍歷非空的結點 */
    }
    printf("\n");
}
int main()
{
    //ABCDE F  GH  I              J
    SqBiTree mytree;
    CreateBiTree(mytree);
    LevelOrderTraverse(mytree, &MyPrint);
    InOrderTraverse(mytree, &MyPrint);
    //Print(mytree);
    return 0;
}
