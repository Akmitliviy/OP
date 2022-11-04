
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void) {

	char *pstr, string[100], delimiter[100] = " a e i o u y , - ;"
							"\" ' : . ! ? ( ) 1 2 3 4 5 6 7 8 9 0";
	int counter = 0;
	
	puts("Enter sentence: ");
	gets(string);

	for (int i = 0; i < strlen(string); i++)
		*(string + i) = tolower(*(string + i));

	pstr = strtok(string, delimiter);
	if (pstr != NULL)
		counter += strlen(pstr);

	while (pstr != NULL) {

		pstr = strtok(NULL, delimiter);
		if(pstr != NULL)
			counter += strlen(pstr);
	}
	printf("\nNumber of  consonants is equal %d\n", counter);

	return 0;
}