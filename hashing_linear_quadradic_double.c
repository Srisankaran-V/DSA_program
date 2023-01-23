#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAX_HASH_TABLE_SIZE 1000



int hash_fn(int key, int m );

int double_hash_fn(int key, int m, int n, int i);
int check_for_collision(int hash, int* table);
int insert_using_double_hash(int key, int m, int n, int* table, int size);
int search_using_double_hash(int key, int m, int n, int* table, int size);
int delete_using_double_hash(int key, int m, int n, int* table, int size);

int linear_probing(int key, int m, int i);
int insert_using_linear_probing(int key, int m, int* table, int size);
int delete_using_linear_probing(int key, int m, int* table, int size);
int search_using_linear_probing(int key, int m, int* table, int size);

int quadratic_probing(int key, int m, int i);
int insert_using_quadratic_probing(int key, int m, int* table, int size);
int delete_using_quadratic_probing(int key, int m, int* table, int size);
int search_using_quadratic_probing(int key, int m, int* table, int size);

void init_hash_table(int *table, unsigned int table_size);
void print_table(int* table, unsigned int table_size);



int main()
{

  printf("HASHING\n");

  int hash_table[MAX_HASH_TABLE_SIZE];
  unsigned int size;
  int c;
  printf("Enter the table size: ");
  scanf("%d", &size);
  init_hash_table(hash_table, size);

  do
  {
    printf("1. Insert using Double Hashing\n");
    printf("2. Search using Double Hashing\n");
    printf("3. Delete using Double Hashing\n\n");
    printf("4. Insert using Linear Probing\n");
    printf("5. Search using Linear Probing\n");
    printf("6. Delete using Linear Probing\n\n");
    printf("7. Insert using Quadratic Probing\n");
    printf("8. Search using Quadratic Probing\n");
    printf("9. Delete using Quadratic Probing\n\n");
    printf("10. Print\n");

    printf("Enter 0 to quit\n\n");
    printf("Enter choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
      if (insert_using_double_hash(ele, 11, 5, hash_table, size))
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
      scanf("%d", &ele);
      int hash = search_using_double_hash(ele, 11, 5, hash_table, size);
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
      scanf("%d", &ele);
      if (delete_using_double_hash(ele, 11, 5, hash_table, size))
      {
        printf("Element %d deleted\n\n", ele);
      }
      else
      {
        printf("Element is not in the hash table\n\n");
      }
      break;
    }
    case 4:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
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
    case 5:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
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
    case 6:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
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
    case 7:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
      if (insert_using_quadratic_probing(ele, 11, hash_table, size))
      {
        printf("Element inserted\n\n");
      }
      else
      {
        printf("The element cannot be inserted \n\n");
      }
      break;
    }
    case 8:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
      int hash = search_using_quadratic_probing(ele, 11, hash_table, size);
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
    case 9:
    {
      int ele;
      printf("Enter the element: ");
      scanf("%d", &ele);
      if (delete_using_quadratic_probing(ele, 11, hash_table, size))
      {
        printf("Element %d deleted\n\n", ele);
      }
      else
      {
        printf("Element is not in the hash table\n\n");
      }
      break;
    }
    case 10:
      print_table(hash_table, size);
      break;
    default:
      break;
    }
  }
  while(c!=0);

  return 0;
}



int hash_fn(int key, int m){
  return key % m;

}

int double_hash_fn(int key, int m, int n, int i){
  return hash_fn(key, m) + (i * hash_fn(key, n));
}

int check_for_collision(int hash, int* table){
  return table[hash] != -1;
}


int insert_using_double_hash(int key, int m, int n, int* table, int size){
  int hash = hash_fn(key, m) % size;
  int i = 0;
  while (check_for_collision(hash, table) && i < size-1){
    hash  = double_hash_fn(key, m, n, i) % size;
    i++;
  }

  if(i==size-1){
    return 0;
  }
  table[hash] = key;
  return 1;
}

int search_using_double_hash(int key, int m, int n, int* table, int size){
  int hash = hash_fn(key, m) % size;
  int i = 1;
  while (table[hash] != key && i < size - 1)
  {
    hash = double_hash_fn(key, m, n, i) % size;
    i++;
  }

  if(table[hash] == key){
    return hash;
  }
  else{
    return -1;
  }
}


int delete_using_double_hash(int key, int m, int n, int* table, int size){
  int hash = search_using_double_hash(key, m, n, table, size);
  if(hash!=-1){
    table[hash] = -1;
    return 1;
  }
  else{
    return 0;
  }
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

int quadratic_probing(int key, int m, int i){
  return hash_fn(key, m) + i * i;

}

int insert_using_quadratic_probing(int key, int m, int* table, int size){
  int hash = hash_fn(key, m) % size;

  int i = 0;
  while (check_for_collision(hash, table) && i < size - 1)
  {
    hash = quadratic_probing(key, m, i) % size;
    i++;
  }

  if(i==size-1){
    return 0;
  }
  table[hash] = key;
  return 1;
}


int search_using_quadratic_probing(int key, int m, int* table, int size){

  int hash = hash_fn(key, m) % size;
  int i=0;
  while(table[hash] != key && i < size -1){
    hash = quadratic_probing(key, m , i) % size;
    i++;
  }

  if(table[hash] == key){
    return hash;
  }
  else {
    return -1;
  }

}

int delete_using_quadratic_probing(int key, int m, int* table, int size){
  int hash = search_using_quadratic_probing(key, m, table, size);

  if(hash!=-1){
    table[hash] = -1;
    return 1;
  }
  else{
    return 0;
  }
}
/*
  Initialises a hash table with given table_size.
  Sets all the values to -1.
*/
void init_hash_table(int *table, unsigned int table_size)
{
  for (int i = 0; i < table_size; i++)
  {
    table[i] = -1;
  }
}

void print_table(int* table, unsigned int table_size){
  for (int i=0; i<table_size; i++){
    printf("%d\n", table[i]);
  }
}
