#include <stdio.h>
#include <stdlib.h>
int postfix(char*); // 中序转后序
int priority(char); // 决定运算子优先顺序

int main(void) {
    char input[80];
    printf("输入中序运算式:");
    scanf("%s", input);
    postfix(input);
    return 0;
}

int postfix(char* infix) {
    int i = 0, top = 0;
    char stack[80] = {'\0'};
    char op;
    while(1) {
        op = infix[i];
        switch(op) {
            case '\0':
                while(top > 0) {
                    printf("%c", stack[top]);
                    top--;
                }
                printf("\n");
                return 0;
                // 运算子堆叠
            case '(':
                if(top < (sizeof(stack) / sizeof(char))) {
                    top++;
                    stack[top] = op;
                }
                break;
            case '+': case '-': case '*': case '/':
                while(priority(stack[top]) >= priority(op)) {
                    printf("%c", stack[top]);
                    top--;
                }
                // 存入堆叠
                if(top < (sizeof(stack) / sizeof(char))) {
                    top++;
                    stack[top] = op;
                }
                break;
                // 遇 ) 输出至 (
            case ')':
                while(stack[top] != '(') {
                    printf("%c", stack[top]);
                    top--;
                }
                top--; // 不输出(
                break;
                // 运算元直接输出
            default:
                printf("%c", op);
                break;
        }
        i++;
    }
}

int priority(char op) {
    int p;
    switch(op) {
        case '+': case '-':
            p = 1;
            break;
        case '*': case '/':
            p = 2;
            break;
        default:
            p = 0;
            break;
    }
    return p;
}
