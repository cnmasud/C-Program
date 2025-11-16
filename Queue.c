#include<stdbool.h>
#include<stdio.h>

#define MAX_SIZE 100

typedef struct {
	int items[MAX_SIZE];
	int front;
	int rear;
} Queue;


void initializeQueue(Queue* q){
	q->front = -1;
	q->rear = 0;
}

bool isFull(Queue* q){
	return(q->rear == MAX_SIZE);
}

bool isEmpty(Queue* q){
	return(q->front == q->rear -1);
}

void  enqueue(Queue* q, int value){
	if(isFull(q)){
		printf("Queue is FULL");
		return;
	}
	q->items[q->rear] = value;
	q->rear++;
}


int peekQueue(Queue* q){
	if(isEmpty(q)){
		printf("Queue is EMPTY");
		return -1;
	}
	return q->items[q->front+1];
	
}

void Dequeue(Queue* q){
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	q->front++;
}

void printQueue(Queue* q){
	if(isEmpty(q)){
		printf("Queue is EMPTY");
		return;
	}
	printf("Current Queue : ");
	for(int i = q->front +1; i<q->rear; i++){
		printf("%d ", q->items[i]);
	}
	printf("\n");
}


int main(){
	Queue q;
	initializeQueue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);

	printQueue(&q);

	
	printf("Front Element : %d", peekQueue(&q));
	printf("\n");


	Dequeue(&q);
	printQueue(&q);
	return 0;

}