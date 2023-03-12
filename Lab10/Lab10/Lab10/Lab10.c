#include "Header.h"

int main() {

	char option;
	char path[STR];
	char tempStr[STR];
	SBook* SFirstBook = NULL;
	SBook* SFree = NULL; 
	SBook* Stemp = NULL;

	printf("Enter path of file with list: ");
	scanf("%s", path);

	FILE* file = fopen(path, "r");

	while (!feof(file)) {
		fgets(tempStr, STR, file);
		SetStruct(&SFirstBook, tempStr);
	}
	fclose(file);


	int elementIndex = 0;
	int onGoing = 1;
	getchar();
	while (onGoing) {
		printf("\n\nKeys: x - Exit, s - Show, o - Sort, a - Add, d - Delete, p - Delete books which names start with П К or Л\n\nPlease, choose option: ");
		option = getchar();

		switch (option){
		case 'o':
			Sort(&SFirstBook);
			break;
		case 's':
			Show(SFirstBook);
			break;
		case 'a':
			AddElement(&SFirstBook);
			break;
		case 'd':
			printf("\nEnter number of element: ");
			scanf("%d", &elementIndex);
			DeleteElement(&SFirstBook, elementIndex);
			break;
		case 'p':
			DeletePKL(&SFirstBook);
			break;
		case 'x':
			onGoing = 0;
			if (SFirstBook) {
				SBook* EElement = &SFirstBook;
				while (EElement) {
					SFree = EElement;
					EElement = EElement->mNext;
					free(SFree);

				}
				SFree = NULL;
				SFirstBook = NULL;
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