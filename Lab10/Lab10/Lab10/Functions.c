#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Header.h"

#define STR 200

void SetStruct(char str[STR], struct book** SBook, struct book** SFirstBook) {
	char* ptr;
	char* delimiter = "\t";
	int i = 0;

	ptr = strtok(str, delimiter);
	strcpy((*SBook)->mAuthor, ptr);

	ptr = strtok(NULL, delimiter);
	strcpy((*SBook)->mBook, ptr);

	ptr = strtok(NULL, delimiter);
	(*SBook)->mYear = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	(*SBook)->mPages = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	(*SBook)->mPrice = atoi(ptr);


	if (!*SFirstBook) {
		*SFirstBook = *SBook;
	}

	struct book* TempBooks = calloc(1, sizeof(struct book));

	(*SBook)->mNext = TempBooks;
	*SBook = TempBooks;
}
void Show(struct book* SBook, struct book* SFirstBook) {

	int maxAuthLen = 0, maxNameLen = 0, tempauth = 0, tempname = 0;

	for (SBook = SFirstBook; SBook->mNext; SBook = SBook->mNext)
		if (strlen(SBook->mAuthor) > maxAuthLen)
			maxAuthLen = strlen(SBook->mAuthor);

	for (SBook = SFirstBook; SBook->mNext; SBook = SBook->mNext)
		if (strlen(SBook->mBook) > maxNameLen)
			maxNameLen = strlen(SBook->mBook);

	printf("\n\nAuthor  \t\tName\t\t\t\t\tYear\t\tPages\t\tPrice\n\n");


	for (SBook = SFirstBook; SBook->mNext; SBook = SBook->mNext) {

		printf("%s  ", SBook->mAuthor);
		if (strpbrk(SBook->mAuthor, "abcdefghigklmnopqrstuvwxyz")) {
			tempauth = maxAuthLen / 2 - strlen(SBook->mAuthor);
			for (int j = 0; j <= tempauth; j++)
				printf(" ");
		}
		else {
			tempauth = maxAuthLen - strlen(SBook->mAuthor);
			for (int j = 0; j <= tempauth / 2; j++)
				printf(" ");
		}

		printf("\t%s  ", SBook->mBook);
		if (strpbrk(SBook->mBook, "abcdefghigklmnopqrstuvwxyz")) {
			tempname = maxNameLen / 2 - strlen(SBook->mBook);
			for (int j = 0; j <= tempname; j++)
				printf(" ");
		}
		else {
			tempname = maxNameLen - strlen(SBook->mBook);
			for (int j = 0; j <= tempname / 2; j++)
				printf(" ");
		}
		printf("\t%d\t\t", SBook->mYear);
		printf("%d\t\t", SBook->mPages);
		printf("%d\n\n", SBook->mPrice);
	}
}
void Sort(struct book** SBook, struct book* SFirstBook) {
	int averagePrice = 0;
	struct book tempBook;
	struct book* BooksMinusOne = NULL;
	int counter = 0;

	for (*SBook = SFirstBook; (*SBook)->mNext; *SBook = (*SBook)->mNext) {
		averagePrice += (*SBook)->mPrice;
		counter++;
	}
	averagePrice /= counter;

	for (int i = 0; i < counter - 1; i++) {
		for (int j = counter - 1; j > i; j--) {
			GetConcrete(SBook, SFirstBook, j);
			GetConcrete(&BooksMinusOne, SFirstBook, j - 1);

			if ((*SBook)->mPrice > averagePrice && strcmp((*SBook)->mBook, BooksMinusOne->mBook) < 0) {
				tempBook = *BooksMinusOne;
				*BooksMinusOne = **SBook;
				BooksMinusOne->mNext = tempBook.mNext;
				tempBook.mNext = (*SBook)->mNext;
				**SBook = tempBook;
			}
		}
	}
	printf("\n\nList was successfully sorted!\n\n");
}
void GetConcrete(struct book** SBook, struct book* SFirstBook, int index) {
	*SBook = SFirstBook;
	while (index--) {
		*SBook = (*SBook)->mNext;
	}
}
void DeleteElement(struct book** SBook, struct book** SFirstBook, int index) {
	struct book* PrevBook = calloc(1, sizeof(struct book));
	*SBook = *SFirstBook;
	while (--index) {
		PrevBook = *SBook;
		*SBook = (*SBook)->mNext;

		if (*SBook == NULL) {
			*SBook = PrevBook;
			printf("WARNING: You entered the wrong index");
			return;
		}
	}


	if ((*SBook)->mNext == NULL) {
		PrevBook->mNext = (*SBook)->mNext;
		free(*SBook);
		*SBook = NULL;
	}
	else if (*SBook == *SFirstBook) {
		*SFirstBook = (*SBook)->mNext;
		free(*SBook);
		*SBook = NULL;
	}
	else {
		PrevBook->mNext = (*SBook)->mNext;
		free(*SBook);
		*SBook = NULL;
	}

	printf("\n\nElement was successfully deleted!\n\n");
}
void AddElement(struct book** SBook, struct book** SFirstBook) {
	struct book* SNewElement = malloc(sizeof(struct book));
	struct book* SPrevBook = calloc(1, sizeof(struct book));
	int index = 0;

	getchar();

	printf("\nPlease, enter author's name: ");
	gets(SNewElement->mAuthor);
	printf("\nPlease, enter book's name: ");
	gets(SNewElement->mBook);
	printf("\nPlease, enter book's year: ");
	scanf("%d", &SNewElement->mYear);
	printf("\nPlease, enter number of pages: ");
	scanf("%d", &SNewElement->mPages);
	printf("\nPlease, enter book's price: ");
	scanf("%d", &SNewElement->mPrice);


	printf("\nPlease, enter index where I should paste your element: ");
	scanf("%d", &index);

	*SBook = *SFirstBook;
	while (--index) {
		SPrevBook = *SBook;
		*SBook = (*SBook)->mNext;
	}

	if (SPrevBook == NULL) {
		printf("WARNING: You entered the wrong index");
		return;
	}

	if (*SBook == NULL) {
		(*SBook)->mNext = SNewElement;
	}
	else if (*SBook == *SFirstBook) {
		SNewElement->mNext = *SBook;
		*SFirstBook = SNewElement;
	}
	else {
		SNewElement->mNext = *SBook;
		SPrevBook->mNext = SNewElement;
	}

	printf("\n\nElement was successfully added!\n\n");
}
void DeletePKL(struct book** SBook, struct book** SFirstBook) {
	struct book* PrevBook = *SFirstBook;
	char P[3] = "П";
	char K[3] = "К";
	char L[3] = "Л";

	*SBook = *SFirstBook;
	while (*SBook) {
		if (strncmp((*SBook)->mBook, P, 2) == 0 || strncmp((*SBook)->mBook, K, 2) == 0 || strncmp((*SBook)->mBook, L, 2) == 0) {

			if ((*SBook)->mNext == NULL) {
				PrevBook->mNext = (*SBook)->mNext;
				free(*SBook);
				*SBook = NULL;
				continue;
			}
			else if (*SBook == *SFirstBook) {
				*SFirstBook = (*SBook)->mNext;
				free(*SBook);
				*SBook = *SFirstBook;
				continue;
			}
			else {
				PrevBook->mNext = (*SBook)->mNext;
				free(*SBook);
				*SBook = PrevBook->mNext;
				continue;
			}
		}

		PrevBook = *SBook;
		*SBook = (*SBook)->mNext;
	}

	printf("\n\nElements were successfully deleted!\n\n");
}
//void AddToEnd(struct book** SBook, struct book** SFirstBook) {
//	struct book* SNewElement = malloc(sizeof(struct book));
//
//	while ((*SBook)->mNext) {
//		*SBook = (*SBook)->mNext;
//	}
//
//	getchar();
//
//	printf("\nPlease, enter author's name: ");
//	gets(SNewElement->mAuthor);
//	printf("\nPlease, enter book's name: ");
//	gets(SNewElement->mBook);
//	printf("\nPlease, enter book's year: ");
//	scanf("%d", &SNewElement->mYear);
//	printf("\nPlease, enter number of pages: ");
//	scanf("%d", &SNewElement->mPages);
//	printf("\nPlease, enter book's price: ");
//	scanf("%d", &SNewElement->mPrice);
//	SNewElement->mNext;
//
//	(*SBook)->mNext = SNewElement;
//}
//void GetLast(struct book** SBook) {
//	while ((*SBook)->mNext) {
//		*SBook = (*SBook)->mNext;
//	}
//}
//int deleteNetElement(struct book* pEl) {
//	int iRes = 0;
//	do {
//		if (!pEl || !pEl->mNext) {
//			break;
//		}
//		struct book* pBook = pEl;
//		pEl->mNext = pEl->mNext->mNext;
//		free(pBook);
//		iRes = 1;
//	} while (0);
//
//	return iRes;
//}