#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain circularity
    }
    printf("Inserted %d\n", value);
}

// Delete element
int dequeue() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int value;
    if (front == rear) { // single element
        value = front->data;
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front; // maintain circularity
        free(temp);
    }
    return value;
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("Deleted: %d\n", dequeue());
    display();
    enqueue(50);
    display();
    return 0;
}

