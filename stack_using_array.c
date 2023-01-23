#include "stdio.h"
#include "stdbool.h"
#define MAX 20

int push(int*, int, int);
int pop(int*, int);
bool isFull(int*, int);
bool isEmpty(int*, int);
int peek(int*, int);
void printStack(int*, int);
int searchElement(int*, int, int);

void main() {
	    int option = 1;
	    int stack[MAX];
	    int top = -1;
	    while (option != -1) {
		    printf("Stack implementation using arrays");
		    printf("\n---------------------------------");
		    printf("\n1) Push");
		    printf("\n2) Pop");
		    printf("\n3) Check is full");
		    printf("\n4) Check is empty");
		    printf("\n5) Peek");
		    printf("\n6) Search");
		    int choice;
		    printf("\nEnter choice: ");
		    scanf("%d", &choice);
		    switch(choice) {
		    	case 1: {
		    		if (isFull(stack, top)) {
		    			printf("Stack Overflow");
		    			break;
		    		}
		    		int element;
		    		printf("\nEnter element to push into stack: ");
		    		scanf("%d", &element);
		    		top = push(stack, element, top);
		    		printStack(stack, top);
		    		break;
		    	}
		    	case 2: {
		    		if (isEmpty(stack, top)) {
		    			printf("Stack Underflow");
		    			break;
		    		}
		    		printf("Popped successfully\n");
		    		top = pop(stack, top);
		    		if (top != -1) {
		    			printStack(stack, top);
		    		}
		    		break;
		    	}	
		    	case 3: {
		    		if (isFull(stack, top)) {
		    			printf("Stack is full");
		    			break;
		    		}
		    		printf("Stack is not full");
		    		break;
		    	}
		    	case 4: {
		    		if (isEmpty(stack, top)) {
		    			printf("Stack is empty");
		    			break;
		    		}
		    		printf("Stack is not empty");
		    		break;
		    	}
		    	case 5: {
		    		int topElement = peek(stack, top);
		    		printf("Top element of stack is %d", topElement);
		    		break;
		    	}
		    	case 6: {
		    		int ele;
		    		printf("Enter element to be search: ");
		    		scanf("%d", &ele);
		    		int foundIndex = searchElement(stack, top, ele);
		    		if (foundIndex != -1) {
		    			printf("Element is %d", stack[foundIndex]);
		    			break;
		    		} 
		    		printf("Element not found");
		    		break;
		    	}
		    	default: 
		    		printf("No such operation exists");
		    		break;
		    }
		    printf("\nDo you want to continue? ");
		    scanf("%d", &option);
	}
}

int searchElement(int* stack, int top, int ele) {
	int index = -1;
	for (int i = 0; i <= top; i++) {
		if (stack[i] == ele) {
			index = i;
			break;
		}
	}
	return index;
}

void printStack(int* stack, int top) {
	for (int i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int push(int* stack, int element, int top) {
	top++;
	stack[top] = element;
	return top;
}

int pop(int* stack, int top) {
	stack[top] = 0;
	top--;
	return top;
}

bool isFull(int* stack, int top) {
	if (top + 1 == MAX) return true;
	return false;
}

bool isEmpty(int* stack, int top) {
	if (top == -1) return true;
	return false;
}

int peek(int* stack, int top) {
	return stack[top];
}
