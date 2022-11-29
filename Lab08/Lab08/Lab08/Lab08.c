#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50
#define STR 100
#define	NUMBER_OF_STUDENTS 25

void SetStruct(char str[STR], struct student *pointer, int step);

struct student {
	
	char surname[N];
	char name[N];
	char dateOfBirth[N];
	double grades[N];

};

int main() {
	char path[STR];
	char tempStr[STR];
	struct student PI18[NUMBER_OF_STUDENTS];
	printf("Enter path: ");
	scanf("%s", path);

	FILE* file = fopen(path, "r");

	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {

		fgets(tempStr, STR, file);
		SetStruct(tempStr, PI18, i);
	}

	return 0;
}

void SetStruct(char str[STR], struct student* studn, int step) {
	char* ptr;
	char* delimiter = "  \t";
	int i = 0;
	ptr = strtok(str, delimiter);
	strcpy((studn + step)->surname, ptr);

	ptr = strtok(NULL, delimiter);
	strcpy((studn + step)->name, ptr);

	ptr = strtok(NULL, delimiter);
	strcpy((studn + step)->dateOfBirth, ptr);

	ptr = strtok(NULL, delimiter);
	for (; ptr; i++) {
		(studn + step)->grades[i] = atof(ptr);
		ptr = strtok(NULL, delimiter);

	}

	printf("%s    \t", (studn + step)->name);
	printf("%s    \t", (studn + step)->surname);
	printf("%s\t", (studn + step)->dateOfBirth);
	for (int j = 0; j < i; j++) {
		printf("%lf\t", (studn + step)->grades[j]);
	}
	printf("\n\n");
}