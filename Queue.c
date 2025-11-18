#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = 0;
}

bool isFull(Queue* q) {
    return q->rear == MAX_SIZE;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY\n");
        return -1;
    }
    
    // Get the value at the front
    int dequeuedValue = q->items[q->front + 1];
    
    // Shift all elements to the left
    for (int i = q->front + 1; i < q->rear - 1; i++) {
        q->items[i] = q->items[i + 1];
    }
    
    // Decrease rear after the shift
    q->rear--;

    // Return the dequeued value
    return dequeuedValue;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printQueue(&q);  // Queue: 10 20 30 40

    dequeue(&q);  // Removes 10
    printQueue(&q);  // Queue: 20 30 40

    dequeue(&q);  // Removes 20
    printQueue(&q);  // Queue: 30 40

    dequeue(&q);  // Removes 30
    printQueue(&q);  // Queue: 40

    return 0;
}
