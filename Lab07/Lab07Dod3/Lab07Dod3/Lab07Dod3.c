#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void SetGet(int step);

int main() {
	int depth = 0;

	printf("Enter number of input values: ");
	scanf("%d", &depth);

	printf("\n\n");
	SetGet(depth);

	return 0;
}
void SetGet(int step) {
	char n[20];
	if (step == 0) {
		printf("\n");
		return;
	}
	scanf("%s", n);
	printf("\n");
	SetGet(step - 1);

	printf("%s\n\n", n);
}