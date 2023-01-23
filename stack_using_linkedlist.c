

#include "stdio.h"
#include "stdlib.h"

struct Node {
	int data;
	struct Node *next;
};

struct Node* createNode(int);

struct Node* head, *tail;

void main() {
	int option = 1;
	int top = -1;
	int size;
	printf("Enter size of stack: ");
	scanf("%d", &size);
	while (option != -1) {
		printf("\nStack implementation using linked list");
		printf("\n--------------------------------------");
		printf("\n1) Push");
		printf("\n2) Pop");
		printf("\n3) check if stack is full");
		printf("\n4) check if stack is empty");
		printf("\n5) Peek");
		printf("\n6) print stack");
		printf("\n7) search\n");
		int choice;
		printf("\nWhat do you want to do? ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				if (top == size-1) {
					printf("\nStack overflow\n");
					break;
				}
				int value;
				printf("Enter value: ");
				scanf("%d", &value);
				struct Node* newNode = createNode(value);
				if (top == -1) {
					head = newNode;
					tail = head;
					top++;
					break;
				}
				tail->next = newNode;
				tail = newNode;
				top++;
				break;
			}
			case 2: {
				if (top == -1) {
					printf("\nStack Underflow\n");
					break;
				}
				struct Node* temp = head;
				if (top == 0) {
					head = tail = NULL;
					top--;
					break;
				} 
				while (temp->next != tail) {
					temp = temp->next;
				}
				temp->next = NULL;
				tail = temp;
				top--;
				break;
			}
			case 3:
				if (top == size-1) {
					printf("\nStack is full\n");
					break;		
				}
				printf("\nStack is not full\n");
				break;
				
			case 4:
				if (top == -1) {
					printf("\nStack is empty\n");
					break;
				}
				printf("\nStack is not empty\n");
				break;
				
			case 5:
				if (top == -1) break;
				printf("%d", tail->data);
				break;
				
			case 6: {
				if (top == -1) {
					printf("\nStack is empty\n");
					break;
				}
				struct Node* temp = head;
				printf("\n");
				while (temp->next != NULL) {
					printf("%d ", temp->data);
					temp = temp->next;
				}
				printf("%d", tail->data);
				printf("\n");
				break;
			}
			
			case 7: {
				int val;
				printf("Enter value: ");
				scanf("%d", &val);
				struct Node* temp = head;
				while (temp != NULL) {
					if (temp->data == val) {
						printf("\nelement found %d\n", temp->data);
						return;
					}
					temp = temp->next;
				}
				printf("Element not found");
				break;
			}
				 
			default: {
				printf("\nNothing");
				break;
			}
		}
	}
}

struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
