#include "Header.h"

void SetStruct(SBook** SFirstBook, char* str) {
	char* ptr = NULL;
	char* delimiter = "\t";

	SBook* TempBook = calloc(1, sizeof(SBook));

	if (!TempBook) {
		printf("\n\nSorry, can't allocate the memory\n\n");
	}

	ptr = strtok(str, delimiter);
	strcpy(TempBook->mAuthor, ptr);

	ptr = strtok(NULL, delimiter);
	strcpy(TempBook->mBook, ptr);

	ptr = strtok(NULL, delimiter);
	TempBook->mYear = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	TempBook->mPages = atoi(ptr);

	ptr = strtok(NULL, delimiter);
	TempBook->mPrice = atoi(ptr);

	if (!*SFirstBook) {
		*SFirstBook = TempBook;
	}
	else {
		SBook* SRunner = *SFirstBook;
		while (SRunner->mNext) {
			SRunner = SRunner->mNext;
		}
		SRunner->mNext = TempBook;
	}
}
void Show(SBook* SFirstBook) {
	printf("\n\n\t\tAuthor\t\t\t\t\tBook\t\t\tYear\tPages\tPrice\n\n\n");

	for(;SFirstBook; SFirstBook = SFirstBook->mNext){
		printf("%-42s \t%-49s\t\t%d\t%d\t%d\n\n", SFirstBook->mAuthor, SFirstBook->mBook, SFirstBook->mYear,
			SFirstBook->mPages, SFirstBook->mPrice);
	}
}
void Sort(SBook** SFirstBook) {
	SBook* SElement = *SFirstBook;
	SBook tempBook;
	SBook* BooksMinusOne = NULL;
	int averagePrice = 0, counter = 0;

	for (SElement = *SFirstBook; SElement->mNext; SElement = SElement->mNext) {
		averagePrice += SElement->mPrice;
		counter++;
	}
	averagePrice /= counter;

	for (int i = 0; i < counter - 1; i++) {
		for (int j = counter - 1; j > i; j--) {
			SElement = GetConcrete(*SFirstBook, j);
			BooksMinusOne = GetConcrete(*SFirstBook, j - 1);

			if (SElement->mPrice > averagePrice && strcmp(SElement->mBook, BooksMinusOne->mBook) < 0) {
				tempBook = *BooksMinusOne;
				*BooksMinusOne = *SElement;
				BooksMinusOne->mNext = tempBook.mNext;
				tempBook.mNext = SElement->mNext;
				*SElement = tempBook;
			}
		}
	}
	printf("\n\nList was successfully sorted!\n\n");
}
SBook* GetConcrete(SBook* SFirstBook, int index) {
	SBook* SElement = SFirstBook;
	while (index--) {
		SElement = SElement->mNext;
	}
	return SElement;
}
void DeleteElement(SBook** SFirstBook, int index) {
	SBook* SElement = *SFirstBook;
	SBook* PrevBook = SElement;

	if (index <= 0) {
		printf("WARNING: You entered the wrong index");
		return;
	}

	while (--index) {

		if (SElement->mNext == NULL) {
			printf("WARNING: You entered the wrong index");
			return;
		}

		PrevBook = SElement;
		SElement = SElement->mNext;

	}


	if (SElement->mNext == NULL) {
		PrevBook->mNext = NULL;
		free(SElement);
		SElement = NULL;
	}
	else if (SElement == *SFirstBook) {
		*SFirstBook = SElement->mNext;
		free(SElement);
		SElement = NULL;
	}
	else {
		PrevBook->mNext = SElement->mNext;
		free(SElement);
		SElement = NULL;
	}

	printf("\n\nElement was successfully deleted!\n\n");
}
void AddElement(SBook** SFirstBook) {
	SBook* SNewElement = malloc(sizeof(SBook));
	SBook** SElement = SFirstBook;
	SBook* SPrevBook = NULL;
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


	while (--index > 0) {
		SPrevBook = *SElement;
		*SElement = (*SElement)->mNext;
	}

	if (SPrevBook == NULL) {
		printf("WARNING: You entered the wrong index");
		return;
	}

	if (*SElement == NULL) {
		(*SElement)->mNext = SNewElement;
	}
	else if (*SElement == *SFirstBook) {
		SNewElement->mNext = *SElement;
		*SFirstBook = SNewElement;
	}
	else {
		SNewElement->mNext = *SElement;
		SPrevBook->mNext = SNewElement;
	}

	printf("\n\nElement was successfully added!\n\n");
}
void DeletePKL(SBook** SFirstBook) {
	SBook* SElement = SFirstBook;
	SBook* PrevBook = *SFirstBook;

	char P[3] = "П";
	char K[3] = "К";
	char L[3] = "Л";

	while (SElement) {
		if (SElement->mYear < 2000) {

			if (SElement->mNext == NULL) {
				PrevBook->mNext = SElement->mNext;
				free(SElement);
				SElement = NULL;
				continue;
			}
			else if (SElement == *SFirstBook) {
				*SFirstBook = SElement->mNext;
				free(SElement);
				SElement = *SFirstBook;
				continue;
			}
			else {
				PrevBook->mNext = SElement->mNext;
				free(SElement);
				SElement = PrevBook->mNext;
				continue;
			}
		}

		PrevBook = SElement;
		SElement = SElement->mNext;
	}

	printf("\n\nElements were successfully deleted!\n\n");
}
SBook* GetLast(SBook* SFirstBook) {
	SBook* SElement = SFirstBook;

	while (SElement->mNext) {
		SElement = SElement->mNext;
	}

	return SElement;
}
//void AddToEnd(SBook** SElement, SBook** SFirstBook) {
//	SBook* SNewElement = malloc(sizeof(SBook));
//
//	while ((*SElement)->mNext) {
//		*SElement = (*SElement)->mNext;
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
//	(*SElement)->mNext = SNewElement;
//}
//void GetLast(SBook** SElement) {
//	while ((*SElement)->mNext) {
//		*SElement = (*SElement)->mNext;
//	}
//}
//int deleteNetElement(SBook* pEl) {
//	int iRes = 0;
//	do {
//		if (!pEl || !pEl->mNext) {
//			break;
//		}
//		SBook* pBook = pEl;
//		pEl->mNext = pEl->mNext->mNext;
//		free(pBook);
//		iRes = 1;
//	} while (0);
//
//	return iRes;
//}
