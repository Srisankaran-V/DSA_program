#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#define MAX_BOOK 1000

typedef struct Book {
	char bookTitle[30];
	char authorName[30];
	int totalNoOfCopies;
	int yearOfPublished;
} Book;

int addBooks(Book*, int);
void issueBook(Book*, int, char*);
void returnBook(Book*, int, char*);
void getDetailsByYear(Book*, int, int);
void askChoice();
void printBookDetails(Book*, int);
int getTotalCopies(Book*, int, char*);

void main() {
	system("COLOR 2");
	printf("\n****** Library Management System ******\n");
	printf("---------------------------------------\n");
	int noOfBooks = 0;
	Book b[MAX_BOOK];
	int choice;
	askChoice();
	printf("\nEnter choice: ");
	scanf("%d", &choice);

	while (choice) {
		switch(choice) {
			char bookName[30];
			int year;
			case 1:
				printf("\nEnter book name: ");
				scanf("%s", bookName);
				issueBook(b, noOfBooks, bookName);
				break;

			case 2: {
				printf("\nEnter book name: ");
				scanf("%s", bookName);
				returnBook(b, noOfBooks, bookName);
				printBookDetails(b, noOfBooks);
				break;
			}

			case 3:
				printf("\nEnter year of book published: ");
				scanf("%d", &year);
				getDetailsByYear(b, noOfBooks, year);
				break;

			case 4:
				printf("\nEnter book name: ");
				scanf("%s", bookName);
				int totalCopies = getTotalCopies(b, noOfBooks, bookName);
				if (totalCopies == -1) {
					printf("\nNo such book exists.");
					break;
				}
				printf("\nTotal copies: %d\n", totalCopies);
				break;

			case 5: {
				int option = 1;
				while (option) {
					noOfBooks = addBooks(b, noOfBooks);
					printf("Do you continue? ");
					scanf("%d", &option);
				}
				printBookDetails(b, noOfBooks);
				break;
			}

			default:
				printf("\nTry other options");
				break;
		}
		printf("---------------------------------------");
		printf("\n");
		askChoice();
		printf("\nEnter choice: ");
		scanf("%d", &choice);
	}
	printf("\nThank you for using us!!!");
}

void askChoice() {
	printf("\nWhat do you want to do? \n");
	printf("\n1) Issue book to student");
	printf("\n2) Return book to Library");
	printf("\n3) Get book details by year");
	printf("\n4) Check availability of book's copies");
	printf("\n5) To Add Books to Library\n");
}

void getDetailsByYear(Book* b, int noOfBooks, int year) {
	bool isAnyBook = false;
	for (int i = 0; i < noOfBooks; i++) {
		if (b[i].yearOfPublished == year) {
			isAnyBook = true;
			printf("%s has %d copies left.", b[i].bookTitle, b[i].totalNoOfCopies);
		}
	}
	if (!isAnyBook) {
		printf("\nNo books published in the year %d", year);
	}	
}

int getTotalCopies(Book* b, int noOfBooks, char* bookName) {
	int index = -1;
	for (int i = 0; i < noOfBooks; i++) {
		if (strcmp(b[i].bookTitle, bookName) == 0) {
			index = i;
		}
	}
	if (index == -1) return -1;
	return b[index].totalNoOfCopies;
}

void issueBook(Book* b, int noOfBooks, char* bookName) {
	int index = -1;
	for (int i = 0; i < noOfBooks; i++) {
		if (strcmp(b[i].bookTitle, bookName) == 0) {
			index = i;
		}
	}
	if (index == -1) {
		printf("\nNo such book exists");
		return;
	}
	if (b[index].totalNoOfCopies <= 0) {
		printf("\nSorry! not available:( ");
		return;
	}
	b[index].totalNoOfCopies = --b[index].totalNoOfCopies; 
	printBookDetails(b, noOfBooks);
}

void returnBook(Book* b, int noOfBooks, char* bookName) {
	int index = -1;
	for (int i = 0; i < noOfBooks; i++) {
		if (strcmp(b[i].bookTitle, bookName) == 0) {
			index = i;
		}
	}
	if (index == -1) {
		printf("\nNo such book exists");
		return;
	}
	b[index].totalNoOfCopies = ++b[index].totalNoOfCopies; 	
}

int addBooks(Book* b, int noOfBooks) {
	printf("\nEnter title of book: ");
	scanf(" \n%s", b[noOfBooks].bookTitle);
	getchar();
	printf("Enter author name of book: ");
	scanf(" \n%s", b[noOfBooks].authorName);
	printf("Enter total number of copies: ");
	scanf("%d", &b[noOfBooks].totalNoOfCopies);
	printf("Enter the year book published: ");
	scanf("%d", &b[noOfBooks].yearOfPublished);
	printf("\n");
	return ++noOfBooks;
}

void printBookDetails(Book* b, int noOfBooks) {
	printf("\n\n");
	printf("*** Library ***");
	printf("\n---------------\n");
	for (int i = 0; i < noOfBooks; i++) {
		printf("\nBook Id: %d", i+1);
		printf("\nBook Title: %s", b[i].bookTitle);
		printf("\nAuthor Name: %s", b[i].authorName);
		printf("\nTotal Copies: %d", b[i].totalNoOfCopies);
		printf("\nYear Published: %d\n", b[i].yearOfPublished);
	}
	printf("\n");
	printf("\n");
}
