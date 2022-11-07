#include <stdio.h>
#include <ctype.h>
#include <string.h>

int tos = -1;
int stack[100];
const int size = 100;

enum itemList {oper ,opernd};
enum itemList symbolType(char c) {
    enum itemList symbol;
    if (isalpha(c)) {
        symbol = opernd;
    }
    else {
        symbol = oper;
    }
    return (symbol);
}
void push(char c) {
    if (tos == size - 1) {
        printf("Stack is overflow.\n");
    }
    else {
        tos++;
        stack[tos] = c; 
    }
}
int pop() {
    char c;
    if (tos == -1) {
        printf("Stack is undeflow.\n");
    }
    else {
        c = stack[tos];
        tos--;
    }
    return (c);
}
int main() {
    char post[100];
    int p = 0;
    int i = 0;
    int item;
    int val1 ,val2 ,val3 ,val;
    printf("Enter postfix expression : ");
    gets(post);
    int len;
    len = strlen(post);
    while (i < len) {
        item = post[i];
        switch(symbolType(item)) {
            case opernd:
                printf("Enter th value for %c : " ,item);
                scanf("%d" ,&val);
                push(val);
                break;
            case oper:
                switch(item) {
                    case '+':
                        val1 = pop();
                        val2 = pop();
                        val3 = val1 + val2;
                        push(val3);
                        break;
                    case '-':
                        val1 = pop();
                        val2 = pop();
                        val3 = val1 - val2;
                        push(val3);
                        break;
                    case '*':
                        val1 = pop();
                        val2 = pop();
                        val3 = val1 * val2;
                        push(val3);
                        break;
                    case '/':
                        val1 = pop();
                        val2 = pop();
                        val3 = val1 / val2;
                        push(val3);
                        break;
                }
                break;
        }
        i++;
    }
    printf("Expression : %d\n" ,pop());
    return 0;
} 
