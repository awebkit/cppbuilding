#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DEBUG  
  
#ifdef DEBUG  
#define debug(...) printf( __VA_ARGS__)   
#else  
#define debug(...)  
#endif
struct BiNode
{
    char name[32];
    BiNode *lchild, *rchild;
    int count;
};

class BiSortTree{
public:
    BiSortTree() {}

    void create();

    void insertBiNode(BiNode* root, char* s);

    void inorderPrint(BiNode* root);

    BiNode* getRoot() {return root;}
private:
    BiNode* root;
    int sum;
};

void BiSortTree::create()
{
    char name[32];
    gets(name);

    root = new BiNode;
    root->lchild = 0;
    root->rchild = 0;

    strcpy(root->name, name);
    root->count = 1;

    sum = 1;

    while(gets(name) && strlen(name) > 0){
        insertBiNode(root, name);
        sum++;
    }
}

void BiSortTree::insertBiNode(BiNode* root, char* s)
{
    debug("insert %s\n", s);
    int judge = strcmp(s, root->name);
    if (judge == 0 ) {
        root->count++;
    } else if ( judge < 0) {
        if (root->lchild){
            insertBiNode(root->lchild, s);
        }else {
            BiNode* node = new BiNode;
            node->lchild = node->rchild = 0;
            strcpy(node->name, s);
            node->count = 1;
            root->lchild = node;
        }
    } else {
        if (root->rchild)
            insertBiNode(root->rchild, s);
        else {
            BiNode* node = new BiNode;
            node->lchild = node->rchild = 0;
            strcpy(node->name, s);
            node->count = 1;
            root->rchild = node;
        }
    }
}

void BiSortTree::inorderPrint(BiNode* root)
{
    if (root->lchild)
        inorderPrint(root->lchild);
    debug("%s %d", root->name, root->count);
    printf("%s %.4f\n", root->name, (root->count * 100.0) / sum);
    if (root->rchild)
        inorderPrint(root->rchild);
}

int main()
{
    BiSortTree* tree = new BiSortTree();
    tree->create();
    tree->inorderPrint(tree->getRoot());
    return 0;
}
