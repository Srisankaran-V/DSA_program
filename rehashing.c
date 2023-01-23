#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hash_fn(int, int);
int rehashing(int*, int, int);

int linear_probing(int key, int m, int i);
int insert_using_linear_probing(int key, int m, int* table, int size);
int delete_using_linear_probing(int key, int m, int* table, int size);
int search_using_linear_probing(int key, int m, int* table, int size);

void init_hash_table(int **table, unsigned int table_size);
void print_table(int* table, unsigned int table_size);

int check_for_collision(int hash, int* table){
    return table[hash] != -1;
}
int curr_size = 0;
int size = 0;
double load = 0.0;

int main() {
    printf("Enter size of hashtable ");
    scanf_s("%d", &size);
    int* hash_table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        hash_table[i] = -1;
    }
    printf("REHASHING\n\n");
    int choice;

    do {
        printf("REHASHING load: %lf\n\n", load);

        double LOAD_LIMIT = 0.75;
        if (load > LOAD_LIMIT) {
            size = rehashing(hash_table, 11, size);
            load = 0;
        }
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("Enter choice ");
        scanf_s("%d", &choice);
        switch(choice) {
            case 0: 
                free(hash_table);
                return 0;

            case 1:
                {
                    int ele;
                    printf("Enter the element: ");
                    scanf_s("%d", &ele);
                    if (insert_using_linear_probing(ele, 11, hash_table, size))
                    {
                        printf("Element inserted\n\n");
                    }
                    else
                    {
                        printf("The element cannot be inserted \n\n");
                    }
                    break;
                }
            case 2:
                {
                    int ele;
                    printf("Enter the element: ");
                    scanf_s("%d", &ele);
                    int hash = search_using_linear_probing(ele, 11, hash_table, size);
                    if (hash!=-1)
                    {
                        printf("Element %d found at index %d\n\n", ele, hash);
                    }
                    else
                    {
                        printf("Element is not in the hash table\n\n");
                    }
                    break;
                }
            case 3:
                {
                    int ele;
                    printf("Enter the element: ");
                    scanf_s("%d", &ele);
                    if (delete_using_linear_probing(ele, 11, hash_table, size))
                    {
                        printf("Element %d deleted\n\n", ele);
                    }
                    else
                    {
                        printf("Element is not in the hash table\n\n");
                    }
                    break;
                }

            case 4: {
                        print_table(hash_table, size);
                        break;
                    } 
            default:
                    break;
        }
    }
    while(choice!=0);
}



int hash_fn(int key, int m){
    return key % m;
}

int rehashing(int* hash_table, int m, int size){
    load = 0;
    int prev=size;
    size*=2;
    int* temp;
    // reallocating new hash_table
    temp = realloc(hash_table, size * sizeof(int));
    if(temp == NULL){
        fprintf(stderr, "ERROR: Cannot allocate memory\n");
        return 0;
    }
    hash_table=temp;
    printf("\nREHASHING\n");
    for(int i=prev; i<size; i++)
    {
        hash_table[i] = -1;
    }

    return size; 
}
int linear_probing(int key, int m, int i){
    return hash_fn(key, m) + i;

}
int insert_using_linear_probing(int key, int m, int* table, int size){
    int hash = hash_fn(key, m) % size;

    int i = 0;
    while (check_for_collision(hash, table) && i < size - 1)
    {
        hash = linear_probing(key, m, i) % size;
        i++;
    }

    if(i==size-1){
        return 0;
    }
    table[hash] = key;
    curr_size++;
    load = (1.0 * curr_size) / size;
    return 1;
}


int search_using_linear_probing(int key, int m, int* table, int size){

    int hash = hash_fn(key, m) % size;
    int i=0;
    while(table[hash] != key && i < size -1){
        hash = linear_probing(key, m , i) % size;
        i++;
    }

    if(table[hash] == key){
        return hash;
    }
    else {
        return -1;
    }

}

int delete_using_linear_probing(int key, int m, int* table, int size){
    int hash = search_using_linear_probing(key, m, table, size);

    if(hash!=-1){
        table[hash] = -1;
        return 1;
    }
    else{
        return 0;
    }
}

void print_table(int* table, unsigned int table_size){
    for (int i=0; i<table_size; i++){
        printf("%d\n", table[i]);
    }
}
