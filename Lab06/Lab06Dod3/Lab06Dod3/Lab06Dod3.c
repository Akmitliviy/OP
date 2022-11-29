#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define ArithmeticalProgression(a1, a2, n) ((a1) + ((a2) - (a1)) * ((n) - 1))

int main() {
	int a1 = 0, a2 = 0, n = 0;

	printf("Enter first element: ");
	scanf("%d", &a1);

	printf("Enter second element: ");
	scanf("%d", &a2);

	printf("Enter number of desired element: ");
	scanf("%d", &n);

	printf("Desired element is %d", ArithmeticalProgression(a1, a2, n));

	return 0;
}