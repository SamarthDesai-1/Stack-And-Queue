#include <stdio.h>

int deque[20];
int front = -1;
int rear = -1;

// insertion element using front
void insertAtDeque(int value ,int size) {
    if (front == 0) {
        printf("Deque is overflow.\n");
    }
    else {
        if (rear == -1) {
            front = size;
            rear = size;
        }
        deque[front] = value;
        front--;
        if (rear == size) {
            rear = size - 1;
        }
    }
}
// deletion element using front
void deleteAtDeque(int size) {
    int value;
    if (front == -1) {
        printf("Deque is underflow.\n");
    }
    else {
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        value = deque[front];
        front++;
    }
}
void display() {
    if (front == -1) {
        printf("Deque is underflow.\n");
    }
    else {
        printf("Elements of deque.\n");
        for (int i = front; i <= rear; i++) {
            printf("Deque : %d\n" ,deque[i]);
        }
    }
}
int main() {
    int choice;
    int size;
    int value;
    printf("Enter size of deque : ");
    scanf("%d" ,&size);
     while (choice != 0) {
        printf("\n");
        printf("1. for insert element in deque.\n");
        printf("2. for delete element in deque.\n");
        printf("3. for display element in deque.\n");
        printf("0. for exit.\n");
        printf("\n");
        printf("Enter choice : ");
        scanf("%d" ,&choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter element : ");
                scanf("%d" ,&value);
                insertAtDeque(value ,size);
                break;
            case 2:
                deleteAtDeque(size);
                break;
            case 3:
                display();
                break;
        }
    } 
    printf("You are exit now.");   
    return 0;
} 