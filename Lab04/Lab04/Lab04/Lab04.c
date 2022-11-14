
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char string[100], delimiter[100] = " a e i o u y";
	int counter = 0;
	
	puts("Enter sentence: ");
	gets(string);

	for (int i = 0; i < strlen(string); i++)
		*(string + i) = tolower(*(string + i));

	for (int i = 0; i < strlen(string); i++) {
		if (isalpha(*(string + i)) && strchr(delimiter, *(string + i)) == NULL)
			counter++;
	}
	printf("\nNumber of  consonants is equal %d\n", counter);

	return 0;
}