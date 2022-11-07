#include <stdio.h>

int stack[10];
int tos = -1;

void push(int element ,int sizeOfStack) {
    int value;
    if (tos == sizeOfStack - 1) {
        printf("Stack is overflow.\n");
    }
    else {
        tos++;
        stack[tos] = value;
    }
}
void pop() {
    int value;
    if (tos == -1) {
        printf("Stack is underflow.\n");
    }
    else {
        value = stack[tos];
        tos--;
    }
}
void peep() {
    int value;
    if (tos == -1) {
        printf("Stack is underflow.\n");
    }
    else {
        printf("The peeped element or element at top of stack: %d\n" ,stack[tos]);
    }
}
void update(int ch) {
    if (tos == -1) {
        printf("Stack is underflow.\n");
    }
    else {
        stack[tos] = ch;
    }
}
void display() {
    if (tos == -1) {
        printf("Stack is underflow.\n");
    }
    else {
        for (int i = tos; i >= 0; i--) {
            printf("Stack : %d\n" ,stack[i]);
        }
    }
}
int main() {
    int choice;
    int member;
    int change;
    int size;
    printf("Enter size of stack : ");
    scanf("%d" ,&size);
    while (choice != 0) {
        printf("\n");
        printf("1. for insert element in stack.\n");
        printf("2. for delete element in stack.\n");
        printf("3. for peep element in stack.\n");
        printf("4. for change element in stack.\n");
        printf("5. for display element in stack.\n");
        printf("0. for exit.\n");
        printf("\n");
        printf("Enter choice : ");
        scanf("%d" ,&choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter element for stack : ");
                scanf("%d" ,&member);
                push(member ,size);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                printf("Enter change element at top of stack : ");
                scanf("%d" ,&change);
                update(change);
                break;
            case 5:
                display();
                break;
        }
    }
    printf("You are exit now.");   
    return 0;
} 