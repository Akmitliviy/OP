#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define STR 200
#define	NUMBER_OF_BOOKS 25

void SetStruct(char str[STR], struct book* Books, int step);
void Sort(struct book* Books, int numOfBooks); 
void Show(struct book* Books, int numOfBooks);

struct book {
	
	char author[N];
	char book[N];
	int year;
	int pages;
	int price;

};

int main() {
	char path[STR];
	char tempStr[STR];
	struct book Books[NUMBER_OF_BOOKS];
	printf("Enter path: ");
	scanf("%s", path);

	FILE* file = fopen(path, "r");

	int counter = 0;
	while(!feof(file)) {

		fgets(tempStr, STR, file);
		SetStruct(tempStr, Books, counter);

		counter++;
	}

	fclose(file);

	Sort(Books, counter);
	Show(Books, counter);

	return 0;
}

void SetStruct(char str[STR], struct book* Books, int step) {
	char* ptr;
	char* delimiter = "\t";
	int i = 0;
	ptr = strtok(str, delimiter);
	strcpy(Books[step].author, ptr);

	ptr = strtok(NULL, delimiter);
	strcpy(Books[step].book, ptr);

	ptr = strtok(NULL, delimiter);
	Books[step].year = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	Books[step].pages = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	Books[step].price = atoi(ptr);
}
void Sort(struct book* Books, int numOfBooks) {
	int averagePrice = 0;
	struct book tempBook;

	for (int i = 0; i < numOfBooks; i++) {
		averagePrice += Books[i].price;
	}
	averagePrice /= numOfBooks;

	for (int i = 0; i < numOfBooks - 1; i++)
		for (int j = numOfBooks - 1; j > i; j--)
			if (Books[j].price > averagePrice && strcmp(Books[j].book, Books[j - 1].book) < 0) {
				tempBook = Books[j - 1];
				Books[j - 1] = Books[j];
				Books[j] = tempBook;
			}
}
void Show(struct book* Books, int numOfBooks) {
	int maxAuthLen = 0, maxNameLen = 0, tempauth = 0, tempname = 0;

	for (int i = 0; i < numOfBooks; i++)
		if (strlen(Books[i].author) > maxAuthLen)
			maxAuthLen = strlen(Books[i].author);

	for (int i = 0; i < numOfBooks; i++)
		if (strlen(Books[i].book) > maxNameLen)
			maxNameLen = strlen(Books[i].book);
	printf("\n\nAuthor  \t\tName\t\t\t\t\tYear\t\tPages\t\tPrice\n\n");
	for (int i = 0; i < numOfBooks; i++) {
		printf("%s  ", Books[i].author);
		tempauth = strlen(Books[i].author);
		for (int j = 0; j < (maxAuthLen - tempauth) / 8; j++)
			printf("    ");
		printf("\t");

		printf("%s", Books[i].book);
		tempname = strlen(Books[i].book);
		for (int j = 0; j < (maxNameLen - tempname) / 8; j++)
			printf("    ");
		printf("\t");

		printf("%d\t\t", Books[i].year);
		printf("%d\t\t", Books[i].pages);
		printf("%d\n\n", Books[i].price);
	}

}