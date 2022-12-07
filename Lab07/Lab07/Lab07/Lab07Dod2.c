#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include "Header.h"

int main() {
	int funcNumber = 1;
	double step = 0;
	void (*pFunc)(double step);

	printf("Enter step: ");
	scanf("%lf", &step);

	printf("Please, enter number of function (1 - for, 2 - while, 3 - do while): ");
	scanf("%d", &funcNumber);
	printf("\n");

	switch (funcNumber) {
	case 1: 
		pFunc = funcFor;
		break;
	
	case 2:
		pFunc = funcWhile;
		break;

	case 3:
		pFunc = funcDoWhile;
		break;

	default: 
		printf("Sorry, but we don't have such a function. Default function will be used:\n\n");
		pFunc = funcFor;
		break;
	}

	(*pFunc)(step);

	return 0;
}

double GetY(double x) {
	double y = 0;

	if (x * (1.0 - x) <= 0.000000001)
		y = NAN;
	else
		y = (asin(sqrt(x))) / sqrt(x * (1.0 - x));

	return y;
}
void funcFor(double step) {
	double a = 0, b = 1, y;

	printf("via For\n\nx\t\ty\n\n");
	for (double x = a; x <= b; x += step) {
		y = GetY(x);

		if (isnan(y))
			printf("%lf\t%s\n", x, "not exist");
		else
			printf("%lf\t%lf\n", x, y);

	}
}
void funcWhile(double step) {
	double a = 0, b = 1, x = a, y;

	printf("via While\n\nx\t\ty\n\n");
	while (x <= b) {
		y = GetY(x);

		if (isnan(y))
			printf("%lf\t%s\n", x, "not exist");
		else
			printf("%lf\t%lf\n", x, y);

		x += step;
	}
}
void funcDoWhile(double step) {
	double a = 0, b = 1, x = a, y;
	printf("via Do while\n\nx\t\ty\n\n");
	do{
		y = GetY(x);

		if (isnan(y))
			printf("%lf\t%s\n", x, "not exist");
		else
			printf("%lf\t%lf\n", x, y);

		x += step;

	}while (x <= b);
}