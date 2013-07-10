#include "linktree.h"
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;
/* 二叉樹的三叉鏈表存儲的基本操作(21個) */
#define ClearBiTree DestroyBiTree /* 清空二叉樹和銷毀二叉樹的操作一樣 */
void InitBiTree(BiPTree *T)
{ /* 操作結果：構造空二叉樹T */
    *T=NULL;
}

void DestroyBiTree(BiPTree *T)
{ /* 初始條件：二叉樹T存在。操作結果：銷毀二叉樹T */
    if(*T) /* 非空樹 */
    {
        if((*T)->lchild) /* 有左孩子 */
            DestroyBiTree(&(*T)->lchild); /* 銷毀左孩子子樹 */
        if((*T)->rchild) /* 有右孩子 */
            DestroyBiTree(&(*T)->rchild); /* 銷毀右孩子子樹 */
        free(*T); /* 釋放根結點 */
        *T=NULL; /* 空指針賦0 */
    }
}

void BSTCreate(BiPTree *T, int array[], int size)
{
    if (size <= 0){
        T = NULL;
        return;
    }
    int m = size >> 1;
    *T = (BiPTree)malloc(sizeof(BiTPNode));
    (*T)->data = array[m];
    (*T)->parent = NULL;

    BSTCreate(&(*T)->lchild, array, m);
    if ((*T)->lchild)
        (*T)->lchild->parent = *T;
    BSTCreate(&(*T)->rchild, &array[m+1], size - m - 1);
    if ((*T)->rchild)
        (*T)->rchild->parent = *T;

}
void CreateBiTree(BiPTree *T)
{ /* 按先序次序輸入二叉樹中結點的值(可為字符型或整型，在主程中定義)，*/
    /* 構造三叉鏈表表示的二叉樹T */
    TElemType ch;
#if CHAR
    scanf("%c",&ch);
#endif
#if INTEGER
    scanf("%d",&ch);
#endif
    if(ch==0){ /* 空 */
        *T=NULL;
    }else
    {
        *T=(BiPTree)malloc(sizeof(BiTPNode)); /* 動態生成根結點 */
        if(!*T)
            exit(-1);
        (*T)->data=ch; /* 給根結點賦值 */
        (*T)->parent=NULL; /* 根結點無雙親 */
        CreateBiTree(&(*T)->lchild); /* 構造左子樹 */
        if((*T)->lchild) /* 有左孩子 */
            (*T)->lchild->parent=*T; /* 給左孩子的雙親域賦值 */
        CreateBiTree(&(*T)->rchild); /* 構造右子樹 */
        if((*T)->rchild) /* 有右孩子 */
            (*T)->rchild->parent=*T; /* 給右孩子的雙親域賦值 */
    }
}

bool BiTreeEmpty(BiPTree T)
{ /* 初始條件：二叉樹T存在。操作結果：若T為空二叉樹，則返回TRUE，否則FALSE */
    if(T)
        return false;
    else
        return true;
}

int BiTreeDepth(BiPTree T)
{ /* 初始條件：二叉樹T存在。操作結果：返回T的深度 */
    int i,j;
    if(!T)
        return 0; /* 空樹深度為0 */
    if(T->lchild)
        i=BiTreeDepth(T->lchild); /* i為左子樹的深度 */
    else
        i=0;
    if(T->rchild)
        j=BiTreeDepth(T->rchild); /* j為右子樹的深度 */
    else
        j=0;
    return i>j?i+1:j+1; /* T的深度為其左右子樹的深度中的大者+1 */
}

TElemType Root(BiPTree T)
{ /* 初始條件：二叉樹T存在。操作結果：返回T的根 */
    if(T)
        return T->data;
    else
        return NULL;
}

TElemType Value(BiPTree p)
{ /* 初始條件：二叉樹T存在，p指向T中某個結點。操作結果：返回p所指結點的值 */
    return p->data;
}

void Assign(BiPTree p,TElemType value)
{ /* 給p所指結點賦值為value */
    p->data=value;
}
BiPTree Point(BiPTree T,TElemType e)
{ /* 返回二叉樹T中指向元素值為e的結點的指針。加 */
    while(T){
        if (T->data > e)
            T = T->lchild;
        else if (T->data == e)
            return T;
        else
            T = T->rchild;
    }
    return NULL;
#if 0
    LinkQueue q;
    QElemType a;
    if(T) /* 非空樹 */
    {
        InitQueue(&q); /* 初始化隊列 */
        EnQueue(&q,T); /* 根結點入隊 */
        while(!QueueEmpty(q)) /* 隊不空 */
        {
            DeQueue(&q,&a); /* 出隊，隊列元素賦給a */
            if(a->data==e)
                return a;
            if(a->lchild) /* 有左孩子 */
                EnQueue(&q,a->lchild); /* 入隊左孩子 */
            if(a->rchild) /* 有右孩子 */
                EnQueue(&q,a->rchild); /* 入隊右孩子 */
        }
    }
    return NULL;
#endif
}
TElemType Parent(BiPTree T,TElemType e)
{ /* 初始條件：二叉樹T存在，e是T中某個結點 */
    /* 操作結果：若e是T的非根結點，則返回它的雙親，否則返回＂空＂*/
    BiPTree a;
    if(T) /* 非空樹 */
    {
        a=Point(T,e); /* a是結點e的指針 */
        if(a&&a!=T) /* T中存在結點e且e是非根結點 */
            return a->parent->data; /* 返回e的雙親的值 */
    }
    return NULL; /* 其餘情況返回空 */
}

TElemType LeftChild(BiPTree T,TElemType e)
{ /* 初始條件：二叉樹T存在，e是T中某個結點。操作結果：返回e的左孩子。若e無左孩子,則返回"空" */
    BiPTree a;
    if(T) /* 非空樹 */
    {
        a=Point(T,e); /* a是結點e的指針 */
        if(a&&a->lchild) /* T中存在結點e且e存在左孩子 */
            return a->lchild->data; /* 返回e的左孩子的值 */
    }
    return NULL; /* 其餘情況返回空 */
}

TElemType RightChild(BiPTree T,TElemType e)
{ /* 初始條件：二叉樹T存在，e是T中某個結點。操作結果：返回e的右孩子。若e無右孩子,則返回"空" */
    BiPTree a;
    if(T) /* 非空樹 */
    {
        a=Point(T,e); /* a是結點e的指針 */
        if(a&&a->rchild) /* T中存在結點e且e存在右孩子 */
            return a->rchild->data; /* 返回e的右孩子的值 */
    }
    return NULL; /* 其餘情況返回空 */
}

TElemType LeftSibling(BiPTree T,TElemType e)
{ /* 初始條件：二叉樹T存在，e是T中某個結點 */
    /* 操作結果：返回e的左兄弟。若e是T的左孩子或無左兄弟，則返回＂空＂*/
    BiPTree a;
    if(T) /* 非空樹 */
    {
        a=Point(T,e); /* a是結點e的指針 */
        if(a&&a!=T&&a->parent->lchild&&a->parent->lchild!=a) /* T中存在結點e且e存在左兄弟 */
            return a->parent->lchild->data; /* 返回e的左兄弟的值 */
    }
    return NULL; /* 其餘情況返回空 */
}

TElemType RightSibling(BiPTree T,TElemType e)
{ /* 初始條件：二叉樹T存在，e是T中某個結點 */
    /* 操作結果：返回e的右兄弟。若e是T的右孩子或無右兄弟，則返回＂空＂*/
    BiPTree a;
    if(T) /* 非空樹 */
    {
        a=Point(T,e); /* a是結點e的指針 */
        if(a&&a!=T&&a->parent->rchild&&a->parent->rchild!=a) /* T中存在結點e且e存在右兄弟 */
            return a->parent->rchild->data; /* 返回e的右兄弟的值 */
    }
    return NULL; /* 其餘情況返回空 */
}
Status InsertChild(BiPTree p,int LR,BiPTree c) /* 形參T無用 */
{ /* 初始條件：二叉樹T存在，p指向T中某個結點，LR為0或1，非空二叉樹c與T不相交且右子樹為空 */
    /* 操作結果：根據LR為0或1，插入c為T中p所指結點的左或右子樹。p所指結點 */
    /*           的原有左或右子樹則成為c的右子樹 */
    if(p) /* p不空 */
    {
        if(LR==0)
        {
            c->rchild=p->lchild;
            if(c->rchild) /* c有右孩子(p原有左孩子) */
                c->rchild->parent=c;
            p->lchild=c;
            c->parent=p;
        }
        else /* LR==1 */
        {
            c->rchild=p->rchild;
            if(c->rchild) /* c有右孩子(p原有右孩子) */
                c->rchild->parent=c;
            p->rchild=c;
            c->parent=p;
        }
        return OK;
    }
    return ERROR; /* p空 */
}

Status DeleteChild(BiPTree p,int LR) /* 形參T無用 */
{ /* 初始條件：二叉樹T存在，p指向T中某個結點，LR為0或1 */
    /* 操作結果：根據LR為0或1，刪除T中p所指結點的左或右子樹 */
    if(p) /* p不空 */
    {
        if(LR==0) /* 刪除左子樹 */
            ClearBiTree(&p->lchild);
        else /* 刪除右子樹 */
            ClearBiTree(&p->rchild);
        return OK;
    }
    return ERROR; /* p空 */
}
void PreOrderTraverse(BiPTree T,void(*Visit)(BiPTree))
{ /* 先序遞歸遍歷二叉樹T */
    if(T)
    {
        Visit(T); /* 先訪問根結點 */
        PreOrderTraverse(T->lchild,Visit); /* 再先序遍歷左子樹 */
        PreOrderTraverse(T->rchild,Visit); /* 最後先序遍歷右子樹 */
    }
}
void InOrderTraverse(BiPTree T,void(*Visit)(BiPTree))
{ /* 中序遞歸遍歷二叉樹T */
    if(T)
    {
        InOrderTraverse(T->lchild,Visit); /* 中序遍歷左子樹 */
        Visit(T); /* 再訪問根結點 */
        InOrderTraverse(T->rchild,Visit); /* 最後中序遍歷右子樹 */
    }
}
void PostOrderTraverse(BiPTree T,void(*Visit)(BiPTree))
{ /* 後序遞歸遍歷二叉樹T */
    if(T)
    {
        PostOrderTraverse(T->lchild,Visit); /* 後序遍歷左子樹 */
        PostOrderTraverse(T->rchild,Visit); /* 後序遍歷右子樹 */
        Visit(T); /* 最後訪問根結點 */
    }
}
#if 0
void LevelOrderTraverse(BiPTree T,void(*Visit)(BiPTree))
{ /* 層序遍歷二叉樹T(利用隊列) */
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(&q);
        EnQueue(&q,T);
        while(!QueueEmpty(q))
        {
            DeQueue(&q,&a);
            Visit(a);
            if(a->lchild!=NULL)
                EnQueue(&q,a->lchild);
            if(a->rchild!=NULL)
                EnQueue(&q,a->rchild);
        }
    }
}
#else
void LevelOrderTraverse(BiPTree T,void(*Visit)(BiPTree))
{
    queue<BiPTree> myq;
    if(T)
    {
        myq.push(T);
        while(!myq.empty())
        {
            BiPTree t = myq.front();
            myq.pop();
            Visit(t);
            if(t->lchild!=NULL)
                myq.push(t->lchild);
            if(t->rchild!=NULL)
                myq.push(t->rchild);
        }
    }
}
#endif
void MyPrint(BiPTree T)
{
#if CHAR
    printf("[%c]\n", T->data); 
#endif
#if INTEGER
    printf("[%d]\n", T->data); 
#endif
}

BiPTree Min(BiPTree T)
{
    BiPTree x = T;
    while(x->lchild)
        x = x->lchild;
    return x;
}

BiPTree ReverseMin(BiPTree T)
{
    if (T->lchild)
        return ReverseMin(T->lchild);
    return T;
}

int main()
{
#if 0
    printf("二叉查找树，try '100 90 80 0 0 92 0 0 110 105 0 0 0'\n");
    BiPTree* t = (BiPTree* )malloc(sizeof(BiPTree*));
    CreateBiTree(t);
#else
    BiPTree* t = (BiPTree* )malloc(sizeof(BiPTree*));
    //int array[5] = {1, 2, 3, 4, 5};
    int array[6] = {80, 90, 92, 100, 105, 110};
    BSTCreate(t, array, 6);
#endif
    printf("in order traverse\n");
    InOrderTraverse(*t, &MyPrint);
    printf("pre order traverse\n");
    PreOrderTraverse(*t, &MyPrint);
    
    printf("level order traverse\n");
    LevelOrderTraverse(*t, &MyPrint);
    printf("find min\n");
    BiPTree e = Min(*t);
    //e = ReverseMin(*t);
    MyPrint(e);
    return 0;
}
