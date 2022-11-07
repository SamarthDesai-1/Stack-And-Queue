#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int size = 100;
int stack[100];
int tos = -1;

enum itemList {operand ,oper ,leftbracket ,rightbracket};

void push(char c) {
    if (tos == size - 1) {
        printf("Stack is overflow.\n");
    }
    else {
        stack[tos] = c;
        tos++; 
    }
}
char pop() {
    char x;
    if (tos == -1) {
        printf("Stack is underflow.\n");
        x = ' ';
    }
    else {
        x = stack[tos];
        tos--;
    }
    return x;
}
enum itemList symbolType(char c) {
    enum itemList symbol;
    if (isalpha(c)) {
        symbol = operand;
    }
    else if (c == '(') {
        symbol = leftbracket;
    }
    else if (c == ')') {
        symbol = rightbracket;
    }
    else {
        symbol = oper;
    }
    return (symbol);
}
int precedence(char c) {
    int priority;
    switch (priority) {
        case '+':
        case '-':
            priority = 1;
            break;
        case '*':        
        case '/':
            priority = 2;
            break;
        case '(':
            priority = 0;
            break;    
    }
    return (priority);
}
int main() {
    char infix[100] ,post[100];
    int loopYn; // means loop
    char item;
    int stempty = 1;
    int p = 0;
    int x;
    printf("Enter an infix expression : ");
    gets(infix);
    int len;
    int i = 0;
    len = strlen(infix);
    while (i < len) {
        loopYn = 1; // means loop is true;
        item = infix[i];
        switch(symbolType(item)) {
            case operand:
                post[p] = item;
                p++;
                break;
            case oper:
                if (stempty == 1) {
                    push(item);
                }
                else {
                    do {
                        x = pop();
                        if (precedence(x) >= precedence(item)) {
                            post[p] = x;
                            p++;
                            loopYn = 0; // means loop is false
                        }
                        else {
                            loopYn = 1;
                        }
                    } while (stempty == 0 && loopYn == 0);
                }
                if (loopYn == 1) {
                    push(x);
                    push(item);
                }
                else {
                    push(item);
                }
                break;
            case leftbracket:
                push(item);
                break;
            case rightbracket:
                x = pop();
                while (x != '(') {
                    post[p] = x;
                    p++;
                    x = pop();
                }
                break;
        }
        i++;
    }
    while (tos != -1) {
        post[p] = pop();
        p++;
    }
    printf("Postfix Expression.\n");
    for (int i = 0; i <= p - 1; i++) {
        printf("%c" ,post[i]);
    }
    return 0;
} 