#include <stdio.h>
#include <stdlib.h>

typedef struct Node{  
    int key;  
    struct Node *left;  
    struct Node *right;  
}Lnode;  
void buildTree(Lnode **head)  
{  
    Lnode *p=NULL;  
    int value;  
    scanf("%d",&value);  
    if(value ==-1)  
    {  
        *head=NULL;  
    }  
    else  
    {  

        p = (Lnode *)malloc(sizeof(Lnode));  
        p->key = value;  
        *head=p;  
        buildTree(&((*head)->left));  
        buildTree(&((*head)->right));  
    }  
    return;  

}  
void traverse(Lnode *p)  
{  
    if(p==NULL)  
        return;  
    printf("%d ",p->key);  
    traverse(p->left);  
    traverse(p->right);  
}  
void traverseList(Lnode *p)  
{  
    while(p!=NULL)  
    {  
        printf("%d ",p->key);  
        p=p->right;  
    }  
}  
void convertList(Lnode *head,Lnode **lastNode)  
{  
    Lnode *current = head;  
    if(head == NULL)  
        return;  
    if(head->left) {
        convertList(head->left,lastNode);  
    }
    head->left = *lastNode;  
    if(*lastNode != NULL) { 
        (*lastNode)->right=head;  
    }
    *lastNode=current;  
    if(head->right) {
        convertList(head->right,lastNode);  
    }
}  
Lnode *buildDouble(Lnode *head)  
{  
    Lnode *lastNode = NULL;  
    Lnode *p=NULL;  
    convertList(head,&lastNode);  
    p=lastNode;  
    while(p->left != NULL)  
    {  
        p=p->left;  
    }  
    return p;   

}  
int main()  
{  

    Lnode *head=NULL;  
    Lnode *listHead=NULL;  
    int totalNum= 10;  
    int index =0;  
    int value=0;      
    buildTree(&head);  
    traverse(head);  
    printf("\n");  
    listHead = buildDouble(head);  
    traverseList(listHead);  
    printf("\n");  
    return 0;  
}  
