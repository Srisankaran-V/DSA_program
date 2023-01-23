#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAX 5

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node Node;

Node *front = NULL, *rear = NULL;
int length = -1;

Node* createNewNode(int);
void enqueue(int);
int dequeue();
bool isQueueFull();
bool isQueueEmpty();
void displayQueue();

void main() {
	printf("\nQueue implementation using linked list\n");
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
				if (length+1 == MAX) {
					printf("Queue is full\n");
					break;
				}
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				enqueue(value);
				length++;
				break;
			}

			case 2: {
				int dequeuedElement = dequeue();
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
				displayQueue();
				break;
			}

			default:
				break;
		}
	}
}

Node* createNewNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void enqueue(int value) {
	if (isQueueFull()) {
		printf("Queue is full");
		return;
	}
	Node* newNode = createNewNode(value);
	if (front == NULL) {
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}

int dequeue() {
	int element;
	if (isQueueEmpty()) {
		return 0;
	}
	if (front == NULL && rear == NULL) {
		printf("Queue is empty\n");
		return 0;
	} 
	Node* temp = front;
	if (front == rear) {
		element = rear->data;
		front = rear = NULL;
	} else {
		front = temp->next;
		element = temp->data;
	}
	return element;
}

bool isQueueFull() {
	return front == rear && (length + 1) == MAX;
}

bool isQueueEmpty() {
	return length == 0;
}

void displayQueue() {
	if (isQueueEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	if (front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	Node* current = front;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
