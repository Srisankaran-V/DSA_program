#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNewNode(int);
void insertAtBeginning(int);
void insertAtEnd(int);
void insertBeforeGivenNode(int, int);
void insertAfterGivenNode(int, int);
void insertAtSpecificPos(int, int);
void deleteAtBeginning();
void deleteAtEnd();
void deleteBeforeGivenNode(int);
void deleteAfterGivenNode(int);
void deleteAtSpecificPos(int);
int searchElement(int);
void displayList();
bool isLinkedListEmpty();

Node *head, *tail = NULL;

void main() {
    int option = 1;
    int choice;
    while (option) {
        printf("\nSingly Linked List");
        printf("\n------------------\n");
        printf("\n1) Insert at beginning ");
        printf("\n2) Insert at end ");
        printf("\n3) Insert before given node ");
        printf("\n4) Insert after given node ");
        printf("\n5) Delete at beginning ");
        printf("\n6) Delete at end ");
        printf("\n7) Delete before given node ");
        printf("\n8) Delete after given node ");
        printf("\n9) Search an element in linkedlist ");
        printf("\n10) Insert at specific Position ");
        printf("\n11) Delete at specific Position ");
        printf("\n12) Display the linkedlist ");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                option = 0;
                printf("\nThank you for using linked list :)");
                break;

            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            }
            
            case 2:{
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            }

            case 3: {
                int value, node;
                printf("\nEnter value: ");
                scanf("%d", &value);
                printf("\nEnter node: ");
                scanf("%d", &node);
                insertBeforeGivenNode(value, node);
                break;
            }

            case 4: {
                int value, node;
                printf("Enter value: ");
                scanf("%d", &value);
                printf("\nEnter node: ");
                scanf("%d", &node);
                insertAfterGivenNode(value, node);
                break;
            }
                
            case 5:
                deleteAtBeginning();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7: {
                int node;
                printf("Enter node: ");
                scanf("%d", &node);
                deleteBeforeGivenNode(node);
                break;
            }

            case 8: {
                int node;
                printf("Enter node: ");
                scanf("%d", &node);
                deleteAfterGivenNode(node);
                break;
            }

            case 9: {
                int ele;
                printf("Enter element to be searched ");
                scanf("%d", &ele);
                int res = searchElement(ele);
                if (res) {
                    printf("Element exists");
                    break;
                }
                printf("Element not exists");
                break;
            }

            case 10: {
                int pos, value;
                printf("\nEnter position: ");
                scanf("%d", &pos);
                printf("\nEnter value: ");
                scanf("%d", &value);
                insertAtSpecificPos(value, pos);
                break;
            }

            case 11: {
                int pos;
                printf("\nEnter position: ");
                scanf("%d", &pos);
                deleteAtSpecificPos(pos);
                break;
            }   

            case 12:
                displayList();
                break;

            default:
                option= 0;
                printf("\nThank you for using us :)");
                break;
        }
    }
}

void insertAtSpecificPos(int value, int pos) {
    Node* newNode = createNewNode(value);
    Node* temp = head;
    int i = 1;
    while (i < pos-1) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtSpecificPos(int pos) {
    Node* temp = head, *prev = NULL;
    int i = 0;
    while (i < pos-1) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
}

Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int searchElement(int value) {
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void insertAtEnd(int value) {
    Node* newNode = createNewNode(value);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = createNewNode(value);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertBeforeGivenNode(int value, int node) {
    Node* newNode = createNewNode(value);
    Node* temp = head;
    if (temp->data == node) {
        insertAtBeginning(value);
        return;
    }
    while (temp->next != NULL) {
        if (temp->next->data == node) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

void insertAfterGivenNode(int value, int node) {
    Node* newNode = createNewNode(value);
    Node* temp = head;
    if (tail->data == node) {
        insertAtEnd(value);
        return;
    }
    while (temp->next != NULL) {
        if (temp->data == node) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
}

void deleteAtBeginning() {
    if (isLinkedListEmpty()) return;
    Node* temp = head;
    head = temp->next;
    free(temp);
}

void deleteAtEnd() {
    if (isLinkedListEmpty()) return;
    Node* temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    tail = prev;
    tail->next = NULL;
    free(temp);
}

void deleteBeforeGivenNode(int node) {
    if (isLinkedListEmpty()) return;
    Node* temp = head, *prev = NULL, *next = head->next;
    if (temp->data == node) {
        printf("\nOperation can't be perfomed");
        return;
    }
    while (temp->next != NULL) {
        if (next->data == node) {
            if (head == temp) {
                head = next;
            }
            prev->next = next;
            free(temp);
        }
        prev = temp;
        temp = next;
        next = next->next;
    }
}

void deleteAfterGivenNode(int node) {
    if (isLinkedListEmpty()) return;
    Node* prev = head, *temp = head->next;
    if (tail->data == node) {
        printf("\nOperation can't be performed");
        return;
    }
    while (prev->next != NULL) {
        if (prev->data == node) {
            if (temp == tail) {
                tail = temp;
            }
            prev->next = temp->next;
            free(temp);
            break;
        }   
        prev = temp;
        temp = temp->next;
    }
}

bool isLinkedListEmpty() {
    if (head == NULL) {
        printf("Linked list is empty");
        return true;
    }
    return false;
}

void displayList() {
    Node* temp = head;
    printf("\n");
    while (temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
