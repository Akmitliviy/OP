#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void DoesKeyWordExist(char*); 
int DoesKeySymbolsExist(char*, char*);

int main() {
	char string[50], subStr[30];
	char sentences[15][50];
	char* pStr, * stock;
	int numbOfSent = 0, counter = 0, SavedCounter = -1, sentNum = 0;

	//gets(string);

	//DoesKeyWordExist(string);

	//printf("\n\n");

	printf("Enter key word: ");
	scanf("%s", subStr);

	printf("\nEnter number of sentences: ");
	scanf("%d", &numbOfSent);

	getchar();
	for (int i = 0; i < numbOfSent; i++) {
		printf("\n\nEnter sentence: ");
		gets(*(sentences + i));
	}

	for (int i = 0; i < numbOfSent; i++) {
		stock = strtok(*(sentences + i), "  , . ! ? : ; ' \"");
		while (stock != NULL) {
			counter += DoesKeySymbolsExist(stock, subStr);
			stock = strtok(NULL, "  , . ! ? : ; ' \"");
		}
		printf("\n");
		printf("\nCounter of %d sentence is equal %d", i + 1, counter);
		if (counter > SavedCounter) {
			SavedCounter = counter;
			sentNum = i + 1;
		}
		counter = 0;
	}

	printf("\n\nSentence with the biggest number of key symbols: %d", sentNum);
}

void DoesKeyWordExist(char * string) {
	char  subStr[30];
	char* pStr;

	printf("Enter key word: ");
	scanf("%s", subStr);

	pStr = strstr(string, subStr);
	if (pStr != NULL)
		printf("Key word is exist");
	else
		printf("Key word does not exist");
}

int DoesKeySymbolsExist(char* string, char * subStr) {
	char* pStr;
	int counter = 1;

	for (int i = 0; i < strlen(subStr); i++) {
		if(strchr(string, subStr[i]) == NULL)
			counter  = 0;
	}

	return counter;
}