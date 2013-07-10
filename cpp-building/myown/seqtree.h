#ifndef TREE_H
#define TREE_H

#define CHAR 1
#define INTEGER 0
#define Nil 0
#if CHAR
typedef char TElemType;
#endif

#if INTEGER
typedef int TElemType;
#endif
/* 二叉樹的順序存儲表示 */
#define MAX_TREE_SIZE 100 /* 二叉樹的最大結點數 */

typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0號單元存儲根結點 */

typedef struct
{
    int level,order; /* 結點的層,本層序號(按滿二叉樹計算) */
}position;
enum Status {
    FALSE,
    TRUE
};
/*
#define MAX_TREE_SIZE 100

typedef struct
{
    char data;
    int parent; // 双亲位置域
} PTNode;

typedef struct
{
      PTNode nodes[MAX_TREE_SIZE];
      int n; // 结点数 
} PTree;
*/
#endif
