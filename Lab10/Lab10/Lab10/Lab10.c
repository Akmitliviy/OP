#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <ctype.h>

#define N 100
#define STR 200

int main() {
	char option;
	char path[STR];
	char tempStr[STR];
	struct book* SBook = calloc(1, sizeof(struct book));
	struct book* SFirstBook = NULL;
	struct book* SFree = NULL;

	printf("Enter path of file with list: ");
	scanf("%s", path);

	FILE* file = fopen(path, "r");

	while (!feof(file)) {

		fgets(tempStr, STR, file);
		SetStruct(tempStr, &SBook, &SFirstBook);
	}
	fclose(file);
	SBook->mNext = NULL;


	int elementIndex = 0;
	int onGoing = 1;
	getchar();
	while (onGoing) {
		printf("\n\nKeys: x - Exit, s - Show, o - Sort, a - Add, d - Delete, p - Delete books which names start with П К or Л\n\nPlease, choose option: ");
		option = getchar();

		switch (option){
		case 'o':
			Sort(&SBook, SFirstBook);
			break;
		case 's':
			Show(SBook, SFirstBook);
			break;
		case 'a':
			AddElement(&SBook, &SFirstBook);
			break;
		case 'd':
			printf("\nEnter number of element: ");
			scanf("%d", &elementIndex);
			DeleteElement(&SBook, &SFirstBook, elementIndex);
			break;
		case 'p':
			DeletePKL(&SBook, &SFirstBook);
			break;
		case 'x':
			onGoing = 0;
			if (SFirstBook) {
				SBook = SFirstBook;
				while (SBook->mNext) {
					SFree = SBook;
					SBook = SBook->mNext;
					free(SFree);
				}
			}
			break;
		default:
			printf("Wrong character!");
			break;
		}

		getchar();
	}

	return 0;
}