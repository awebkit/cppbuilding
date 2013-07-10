#include <stdio.h>
#include <stdlib.h>

typedef char eleType;  // 定义链表中的数据类型

typedef struct listnode  { // 定义单链表结构
    eleType data;
    struct listnode *next;
}node;

node *create(int n) {  // 创建单链表，n为节点个数
    node *p = (node *)malloc(sizeof(node));
    node *head = p;  head->data = 'A';
    for(int i='B'; i<'A'+n; i++) {   
        p = (p->next = (node *)malloc(sizeof(node)));
        p->data = i;
        p->next = NULL; 
    }
    return head;
}

void print(node *head) { // 按链表顺序输出链表中元素
    for(; head; head = head->next)
        printf("%c ", head->data);
    printf("\n");
}

node *reverse(node *head, node *pre) { // 逆转单链表函数。这是笔试时需要写的最主要函数
    node *p=head->next;
    head->next = pre;
    if(p) return reverse(p, head);
    else  return head;
}

int main(int argc, char* argv[]) {
    node *head = create(6);
    print(head);
    head = reverse(head, NULL);
    print(head);

    return 0;
}
