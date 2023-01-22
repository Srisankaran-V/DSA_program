#include<stdio.h>
#include<stdlib.h>

int size = 0;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i){
    if(size == 1){
        printf("\nOnly one element is present");
    }
    else{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < size && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < size && arr[r] > arr[largest]){
        largest = r;
    }
    if(i != largest){
        swap(&arr[largest],&arr[i]);
        heapify(arr,size,largest);
    }
    }
}

void Insert(int arr[], int val){
    if(size == 0){
        arr[0] = val;
        size = size+1;
    }
    else{
        
        arr[size] = val;
        size = size+1;
    }
    printf("\n%d", size);
    for(int i = (size/2)-1; i >=0; i--){
        heapify(arr, size, i);
    }
    
}

void Delete(int arr[], int num){
    int i = 0;
    for(i = 0; i < size; i++){
        if(num == arr[i])
        break;
    }
    swap(&arr[i], &arr[size-1]);
    size -= 1;
     for(int i = (size/2)-1; i >=0; i--){
        heapify(arr, size, i);
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; ++i ){
        printf("\narr[%d]-> %d", i, arr[i]);
    }
}

void main(){
    int arr[10] = {}, choice, val;
    while(1){
        printf("\n0.Exit\n1.Insert\n2.Display\n3.Delete\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("\nValue: ");
                scanf("%d", &val);
                Insert(arr, val);
                break;
            case 2:
                display(arr,size);
                break;
            case 3:
                 printf("\nDelete : ");
                scanf("%d", &val);
                Delete(arr, val);
                break;
        }
    }
}
