#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define STR 200

void SetStruct(char str[STR], struct book* Books, struct book* Start);
void Show(struct book* Books, struct book* Start, int counter);

struct book {

	char author[N];
	char book[N];
	int year;
	int pages;
	int price;

	struct book* next;
};
int main() {
	int size = 1;
	char path[STR];
	char tempStr[STR];
	struct book* Books = calloc(size, sizeof(struct book));
	struct book* Start = NULL;

	printf("Enter path of file with list: ");
	scanf("%s", path);

	FILE* file = fopen(path, "r");

	int counter = 0;
	while (!feof(file)) {

		fgets(tempStr, STR, file);
		SetStruct(tempStr, &Books, &Start);
		
	/*	char* ptr;
		char* delimiter = "\t";
		int i = 0;

		ptr = strtok(tempStr, delimiter);
		strcpy(Books->author, ptr);

		ptr = strtok(NULL, delimiter);
		strcpy(Books->book, ptr);

		ptr = strtok(NULL, delimiter);
		Books->year = atoi(ptr);

		ptr = strtok(NULL, delimiter);
		Books->pages = atoi(ptr);

		ptr = strtok(NULL, delimiter);
		Books->price = atoi(ptr);


		if (!Start) {
			Start = Books;
		}

		struct book* TempBooks = calloc(1, sizeof(struct book));

		Books->next = TempBooks;
		Books = TempBooks;

		counter++;*/
	}
	Books->next = NULL;

	/*int maxAuthLen = 0, maxNameLen = 0, tempauth = 0, tempname = 0;

	for (Books = Start; Books->next; Books = Books->next)
		if (strlen(Books->author) > maxAuthLen)
			maxAuthLen = strlen(Books->author);

	for (Books = Start; Books->next; Books = Books->next)
		if (strlen(Books->book) > maxNameLen)
			maxNameLen = strlen(Books->book);

	printf("\n\nAuthor  \t\tName\t\t\t\t\tYear\t\tPages\t\tPrice\n\n");

	for (Books = Start; Books->next; Books = Books->next) {

		printf("%s  ", Books->author);
		tempauth = strlen(Books->author);
		for (int j = 0; j < (maxAuthLen - tempauth) / 8; j++)
			printf("    ");
		printf("\t");

		printf("%s", Books->book);
		tempname = strlen(Books->book);
		for (int j = 0; j < (maxNameLen - tempname) / 8; j++)
			printf("    ");
		printf("\t");

		printf("%d\t\t", Books->year);
		printf("%d\t\t", Books->pages);
		printf("%d\n\n", Books->price);
	}*/
	Show(Books, Start, counter);

	return 0;
}

void SetStruct(char str[STR], struct book* Books, struct book* Start) {
	char* ptr;
	char* delimiter = "\t";
	int i = 0;

	ptr = strtok(str, delimiter);
	strcpy(Books->author, ptr);

	ptr = strtok(NULL, delimiter);
	strcpy(Books->book, ptr);

	ptr = strtok(NULL, delimiter);
	Books->year = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	Books->pages = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	Books->price = atoi(ptr);


	if (!Start) {
		Start = Books;
	}

	struct book* TempBooks = calloc(1, sizeof(struct book));

	Books->next = TempBooks;
	Books = TempBooks;
}

void Show(struct book* Books, struct book* Start, int counter) {

	int maxAuthLen = 0, maxNameLen = 0, tempauth = 0, tempname = 0;

	for (Books = Start; Books->next; Books = Books->next)
		if (strlen(Books->author) > maxAuthLen)
			maxAuthLen = strlen(Books->author);

	for (Books = Start; Books->next; Books = Books->next)
		if (strlen(Books->book) > maxNameLen)
			maxNameLen = strlen(Books->book);

	printf("\n\nAuthor  \t\tName\t\t\t\t\tYear\t\tPages\t\tPrice\n\n");

	
	for (Books = Start; Books->next; Books = Books->next) {

		printf("%s  ", Books->author);
		tempauth = strlen(Books->author);
		for (int j = 0; j < (maxAuthLen - tempauth) / 8; j++)
			printf("    ");
		printf("\t");

		printf("%s", Books->book);
		tempname = strlen(Books->book);
		for (int j = 0; j < (maxNameLen - tempname) / 8; j++)
			printf("    ");
		printf("\t");

		printf("%d\t\t", Books->year);
		printf("%d\t\t", Books->pages);
		printf("%d\n\n", Books->price);
	}
}