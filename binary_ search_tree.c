
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;

Node* createNode(int);
Node* insert(Node*, int);
Node* delete(Node*, int);
Node* minValueNode(Node*);
Node* maxValueNode(Node*);
void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
bool search(Node*, int);
int findHeight(Node*);
int max(int, int);
bool isEmpty(Node*);

void main() {
	int choice;
	Node* root = NULL;
	printf("\nBinary Search Tree Implementation\n");
	while (true) {
		printf("\n1) Insert");
		printf("\n2) Delete");
		printf("\n3) InOrder");
		printf("\n4) PreOrder");
		printf("\n5) PostOrder");
		printf("\n6) Height of tree");
		printf("\n7) Minimum value node in tree");
		printf("\n8) Maximum value node in tree");
		printf("\n9) IsEmpty");
		printf("\n10) Search");
		printf("\nEnter choice ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				int value;
				printf("Enter value to be inserted ");
				scanf("%d", &value);
				root = insert(root, value);
				printf("%d, inserted\n", value);
				break;
			}

			case 2: {
				int value;
				printf("Enter value to be deleted ");
				scanf("%d", &value);
				root = delete(root, value);
				printf("%d, deleted\n", value);
				break;
			}

			case 3: {
				inOrder(root);
				printf("\n");
				break;
			}

			case 4: {
				preOrder(root);
				printf("\n");
				break;
			}

			case 5: {
				postOrder(root);
				printf("\n");
				break;
			}

			case 6: {
				int height = findHeight(root);
				printf("Height of tree is %d\n", height);
				break;
			}

			case 7: {
				Node* minNode = minValueNode(root);
				printf("Min node is %d\n", minNode->data);
				break;
			}

			case 8: {
				Node* maxNode = maxValueNode(root);
				printf("Min node is %d\n", maxNode->data);
				break;
			}

			case 9: {
				if (isEmpty(root)) {
					printf("Tree is empty\n");
				} else {
					printf("Tree is not empty\n");
				}
				break;
			}

			case 10: {
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				if (search(root, value)) {
					printf("%d, exists\n", value);
				} else {
					printf("%d, not exists\n", value);
				}
				break;
			}
			
			default: break;
		}
	}
	// 8, 2, 1, 6, 7, 10, 17, 4
}

Node* insert(Node* root, int value) {
	if (root == NULL) return createNode(value);
	if (root->data > value) root->left = insert(root->left, value);
	else root->right = insert(root->right, value);
	return root;
}

Node* delete(Node* root, int value) {
	if (root == NULL) return root;
	if (value < root->data) {
		root->left = delete(root->left, value);
	}
	else if (value > root->data) {
		root->right = delete(root->right, value);
	}
	else {
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
	}
}

bool isEmpty(Node* root) {
	return root == NULL;
}

bool search(Node* root, int value) {
	if (root == NULL) return false;
	if (value == root->data) return true;
	if (value < root->data) return search(root->left, value);
	if (value > root->data) return search(root->right, value);
}

int max(int a, int b) {
	return a > b ? a : b;
}

int findHeight(Node* root) {
	if (root == NULL) return 0;
	return max(findHeight(root->left), findHeight(root->right)) ;
}

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* minValueNode(Node* root) {
	Node* temp = root;
	while (temp && temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* maxValueNode(Node* root) {
	Node* temp = root;
	while (temp && temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

void postOrder(Node* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

void inOrder(Node* root) {
	if (root == NULL) return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
