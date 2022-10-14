#include <stdio.h>
#include <math.h>

int main(void) {
	int number, numberShadow = 0, saved, l = 0;

	printf("Enter number: ");
	scanf_s("%d", &number);
	saved = number;

	while (pow(10, l) < number) {
		l++;
	}

	for (int i = l - 1; i >= 0; i--) {
		numberShadow += number % 10 * pow(10, i);
		number /= 10;
	}

	if (numberShadow == saved)
		printf("\nIt is a palindrome: %d = %d\n", numberShadow, saved);
	else
		printf("\nIt's not a palindrome: %d != %d\n", numberShadow, saved);

	return 0;
}