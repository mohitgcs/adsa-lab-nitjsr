#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// ---------------- STACK IMPLEMENTATION ----------------
struct Stack {
    int arr[SIZE];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int x) {
    if (s->top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// ---------------- QUEUE WITH PUSH COSTLY ----------------
struct QueuePushCostly {
    struct Stack s1, s2;
};

void initQueuePushCostly(struct QueuePushCostly* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueuePushCostly(struct QueuePushCostly* q, int x) {
    // Move all from s1 to s2
    while (!isEmpty(&q->s1)) {
        push(&q->s2, pop(&q->s1));
    }
    // Push new element into s1
    push(&q->s1, x);
    // Move back to s1
    while (!isEmpty(&q->s2)) {
        push(&q->s1, pop(&q->s2));
    }
    printf("[PushCostly] Enqueued %d\n", x);
}

int dequeuePushCostly(struct QueuePushCostly* q) {
    if (isEmpty(&q->s1)) {
        printf("[PushCostly] Queue Empty!\n");
        return -1;
    }
    return pop(&q->s1);
}

// ---------------- QUEUE WITH POP COSTLY ----------------
struct QueuePopCostly {
    struct Stack s1, s2;
};

void initQueuePopCostly(struct QueuePopCostly* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueuePopCostly(struct QueuePopCostly* q, int x) {
    push(&q->s1, x);
    printf("[PopCostly] Enqueued %d\n", x);
}

int dequeuePopCostly(struct QueuePopCostly* q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("[PopCostly] Queue Empty!\n");
        return -1;
    }
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    struct QueuePushCostly q1;
    struct QueuePopCostly q2;

    initQueuePushCostly(&q1);
    initQueuePopCostly(&q2);

    // Test Push Costly
    printf("\n--- Testing Push-Costly Queue ---\n");
    enqueuePushCostly(&q1, 10);
    enqueuePushCostly(&q1, 20);
    enqueuePushCostly(&q1, 30);
    printf("[PushCostly] Dequeued: %d\n", dequeuePushCostly(&q1));
    printf("[PushCostly] Dequeued: %d\n", dequeuePushCostly(&q1));

    // Test Pop Costly
    printf("\n--- Testing Pop-Costly Queue ---\n");
    enqueuePopCostly(&q2, 100);
    enqueuePopCostly(&q2, 200);
    enqueuePopCostly(&q2, 300);
    printf("[PopCostly] Dequeued: %d\n", dequeuePopCostly(&q2));
    printf("[PopCostly] Dequeued: %d\n", dequeuePopCostly(&q2));
    enqueuePopCostly(&q2, 400);
    printf("[PopCostly] Dequeued: %d\n", dequeuePopCostly(&q2));

    return 0;
}

