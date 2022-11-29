#include<stdio.h>
#include<math.h>
#include"header.h"

int main() {
	int funcNumber;

	printf("Which function you want to use? \"1\" - first, \"2\" - second: ");
	scanf_s("%d", &funcNumber);
	tabulation(funcNumber);

}
double firstFunc(double x) {
	double y = 0;

	if (fabs((x * (1 - x))) < 0.000000001)
		y = NAN;
	else
		y = asin(sqrt(x)) / sqrt(x * (1 - x));

	return y;
}
int secondFunc(double x, double* y) {
	int ret;

	if (fabs((x * (1 - x))) < 0.000000001)
		*y = NAN;
	else
		*y = asin(sqrt(x)) / sqrt(x * (1 - x));

	if (*y > 0)
		ret = 1;
	else if (fabs(* y) < 0.000000001)
		ret = 0;
	else if (*y < 0)
		ret = -1;
	else
		ret = -2;

	return ret;
}
void tabulation(int funcNumber) {
	double h = 0, a = 0, b = 1, x = 0, y = 0;
	int funcReturn;


	switch (funcNumber)
	{
	case 1:
		printf("Please, enter step: ");
		scanf_s("%lf", &h);

		printf("x\t\ty\n\n");
		for (double x = a; x <= b; x += h) {
			y = firstFunc(x);
			if (isnan(y))
				printf("%lf\t%s\n", x, "not exist");
			else
				printf("%lf\t%lf\n", x, y);

		}
		break;
	case 2:
		printf("Please, enter step: ");
		scanf_s("%lf", &h);

		printf("x\t\ty\t\treturn\n\n");
		for (double x = a; x <= b; x += h) {
			funcReturn = secondFunc(x, &y);
			if (isnan(y))
				printf("%lf\t%s\t%s\n", x, "not exist", "not exist");
			else
				printf("%lf\t%lf\t%d\n", x, y, funcReturn);
		}
		break;
	default:
		printf("\nWrong number of function.\n");
		break;
	}
}