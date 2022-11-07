#include <stdio.h>

int queue[20];
int front = -1;
int rear = -1;

void insertAtQueue(int value ,int size) {
    if (front == (rear + 1) % size) {
        printf("Circular queue is overflow.\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        queue[rear] = value;
        rear = (rear + 1) % size;
    }
}
void deleteAtQueue(int size) {
    int value;
    if (front == -1) {
        printf("Circular queue is underflow.\n");
    }
    else {
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        value = queue[front];
        printf("Deleted element : %d\n" ,value);
        front = (front + 1) % size;
    }
}
void display() {
    if (front == -1) {
        printf("Circular queue is undeflow.\n");
    }
    printf("Elements of queue.\n");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("Circular Queue : %d\n" ,queue[i]);
        }
    }
    else {
        for (int i = front; i <= rear; i++) {
            printf("Circular Queue : %d\n" ,queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("Circular Queue : %d\n" ,queue[i]);
        }
    }
}
int main() {
    int choice;
    int size;
    int value;
    while (choice != 0) {
        printf("\n");
        printf("1. for insert element in circular queue.\n");
        printf("2. for delete element in circular queue.\n");
        printf("3. for display element in circular queue.\n");
        printf("0. for exit.\n");
        printf("\n");
        printf("Enter choice : ");
        scanf("%d" ,&choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter element : ");
                scanf("%d" ,&value);
                insertAtQueue(value ,size);
                break;
            case 2:
                deleteAtQueue(size);
                break;
            case 3:
                display();
                break;
        }
    }
    printf("You are exit now.");   
    return 0;
} 