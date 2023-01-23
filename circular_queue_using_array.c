#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QUEUE_LENGTH 5

void enqueue(int);
void dequeue();
void display();
void search(int);
bool is_empty();
bool is_full();

int front = -1, rear = -1;
int queue[MAX_QUEUE_LENGTH];

int main()
{
  system("cls");
  int choice;

  do{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("Enter choice: (1/2/3/4): ");

    scanf("%d", &choice);

    switch(choice)
    {

      case 1:
        {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        enqueue(data);
        }
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
      {
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);
        search(ele);
        break;
      }
      case 0:
        exit(0);
        break;
      default:
        printf("Enter the default option\n");

    }

  }while(choice!=0);
  return 0;
}


void enqueue(int data){
  if(is_full()){
    printf("Queue is full!\n");
    return;
  }

  if(is_empty()){
    front=0;
  }
  rear = (rear +1) % MAX_QUEUE_LENGTH;
  queue[rear] = data;
  printf("Enqueued!\n");
}

void dequeue(){
  if(is_empty()){
    printf("Queue is empty\n");
    return;
  }

  if(front == rear){
    front = rear = -1;
    return;
  }
  front = (front + 1) % MAX_QUEUE_LENGTH;
  printf("Dequeued!\n");

}

void display(){
  if(is_empty()){
    printf("Queue is empty\n");
    return;
  }
  for(int i=front; i<=rear; i++){
    printf("%d ", queue[i]);
  }

  printf("\n");
}

void search(int data){
  bool found =false;
  for(int i = front; i<=rear; i++){
    if(queue[i] == data){
      printf("Element is found at position %d\n", i+1);
      found = true;
      break;
    }
  }

  if(!found){
    printf("Element is not found\n");
  }
}
bool is_empty(){
  return front == -1 && rear == -1;
}

bool is_full(){
  return (front == rear + 1) || (front == 0 && rear == MAX_QUEUE_LENGTH -1);
}
