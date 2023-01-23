#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define size 5
char arr[size];
int top=-1;



void push()
{
    char value;
    printf("enter the character : ");
    scanf("%s",&value);
    if(isalpha(value)>0)
    {
       if(top<size-1){
        
        if(arr[top]==value)
        {
            printf("\nvalue cant be perform\n");
        }
        else{
            {
                top++;
                arr[top]=value;
            }
        }
        }
       else{
           printf("Stack is full\n");
       }
    }
    else{
        printf("\nenter character only\n");
    }
    }

void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%c\t",arr[i]);
    }    
}
void occurence()
{
    char value;
    printf("\nenter the char to find occurence : ");
    scanf("%s",&value);
    int temp=top;
    int count=0;
    for(int i=top;i>=0;i--)
    {
        if(value==arr[i])
        {
            count=count+1;
        }
    }
    printf("\nthe number of occurence %d\n",count);
}
void pop()
{
    if(top==-1)
    {
        printf("\nunderflow");
    }
    top--;
    printf("\nelement poped");
    
}

void main()
{
    int choice;
    printf("\nstack implementation");
    while(1)
    {
        printf("\nenter choice b/w 1 to 4\n1.push\n2.display\n3.occurence\n4.pop\n0.exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                occurence();
                break;
            }
            case 4:
            {
                pop();
                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
        }
       
        
    }
    
}
