#include <stdio.h>

int queue[20];
int front = -1;
int rear = -1;

void insertAtQueue(int value ,int size) {
    if (rear == size - 1) {
        printf("Queue is overflow.\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}
void deleteAtQueue() {
    int value;
    if (front == -1) {
        printf("Queue is underflow.\n");
    }
    else {
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        value = queue[front];
        front++;
        printf("Popped element from queue : %d\n" ,value);
    }
}
void display() {
    if (front == -1) {
        printf("Queue is underflow.\n");
    }
    else {
        printf("Elements of Queue.\n");
        for (int i = front; i <= rear; i++) {
            printf("Queue : %d\n" ,queue[i]);
        }
    }
}
int main() {
    int size;
    int choice;
    int value;
    printf("Enter size of queue : ");
    scanf("%d" ,&size);
    while (choice != 0) {
        printf("\n");
        printf("1. for insert element in queue.\n");
        printf("2. for delete element in queue.\n");
        printf("3. for display element in queue.\n");
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
                deleteAtQueue();
                break;
            case 3:
                display();
                break;
        }
    }
    printf("You are exit now.");   
    return 0;
} 