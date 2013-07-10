#ifndef LINK_TREE_H
#define LINK_TREE_H

//#define NULL 0
#define CHAR 0
#define INTEGER 1
#if CHAR
typedef char TElemType;
#endif
#if INTEGER
typedef int TElemType;
#endif
enum Status {
    OK,
    ERROR 
};
/* 二叉樹的三叉鏈表存儲表示 */
typedef struct BiTPNode
{
    TElemType data;
    struct BiTPNode *parent,*lchild,*rchild; /* 雙親、左右孩子指針 */
}BiTPNode,*BiPTree;
#endif
