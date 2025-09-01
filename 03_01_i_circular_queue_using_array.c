#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
int isFull() {
    return (front == (rear + 1) % SIZE);
}
int isEmpty() {
    return (front == -1);
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) 
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    return data;
}
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(30);
    display();
    printf("Deleted: %d\n", dequeue());
    display();
    enqueue(78);
    enqueue(60);
    display();
    return 0;
}
