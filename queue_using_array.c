
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

void enqueue(int*, int);
int dequeue(int*);

bool isQueueFull();
bool isQueueEmpty();
void displayQueue(int*);

int front = -1, rear = -1;

void main() {
	printf("\nQueue implementation using arrays\n");
	int queue[MAX];
	int option = 1;
	while (true) {
		printf("\n1) Enqueue");
		printf("\n2) Dequeue");
		printf("\n3) Check if queue is full or not");
		printf("\n4) Check if queue is empty or not");
		printf("\n5) Display queue");
		int choice;
		printf("\nEnter choice ");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				printf("End of program");
				return;

			case 1:{
				if (front > rear) {
					printf("Queue is full\n");
					break;
				}
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				enqueue(queue, value);
				break;
			}

			case 2: {
				int dequeuedElement = dequeue(queue);
				if (!dequeuedElement) {
					printf("Can't be performed\n");
					break;
				}
				printf("Dequeued Element is %d\n", dequeuedElement);
				break;
			}

			case 3: {
				if (isQueueFull()) {
					printf("Queue is full\n");
					break;
				}
				printf("Queue is not full\n");
				break;
			}

			case 4: {
				if (isQueueEmpty()) {
					printf("Queue is empty\n");
					break;
				}
				printf("Queue is not empty\n");
				break;
			}

			case 5: {
				displayQueue(queue);
				break;
			}

			default:
				break;
		}
	}
}

void displayQueue(int* queue) {
	if (isQueueEmpty(queue)) {
		printf("Queue is empty\n");
		return;
	}
	if (front > rear) {
		printf("Queue is empty\n");
		return;
	}
	for (int i = front; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
}

void enqueue(int* queue, int value) {
	if (isQueueFull()) {
		printf("Queue is full\n");
		return;
	}
	queue[++rear] = value;
	if (front == -1) front++;
}

int dequeue(int* queue) {
	if (isQueueEmpty()) {
		front = rear = -1;		
		return front;
	}
	if (front > rear) {
		return 0;
	}
	int dequeuedElement = queue[front];
	++front;
	return dequeuedElement;	
}

bool isQueueEmpty() {
	return rear == -1;
}

bool isQueueFull() {
	return (rear + 1) == MAX;
}
