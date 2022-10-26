#include<stdio.h>
#include<math.h>

int main(void) {
	double taylor = 0, d = 1, func, a, b, counter, epsilon;
	int i = 0;

	printf("Enter A (|A| < 1): ");
	scanf_s("%lf", &a);

	printf("Enter B (|B| < 1): ");
	scanf_s("%lf", &b);

	printf("Enter step: ");
	scanf_s("%lf", &counter);

	printf("Enter epsilon: ");
	scanf_s("%lf", &epsilon);

	if (a < b && fabs(a) < 1 && fabs(b) < 1) {
		printf("\nx\t\ttaylor\t\tfunc\n");
		for (double x = a; x - 0.00000001 <= b; x += counter) {
			while (fabs(d) > epsilon) {
				d *= ((3.0 * (double)i + 1.0) * x / (3.0 * (double)i + 3.0));
				taylor += d;
				i++;
			}

			func = pow(1.0 - x, -1.0 / 3.0);
			taylor += 1.0;
			printf("%lf\t%lf\t%lf\n", x, taylor, func);

			taylor = 0;
			d = 1;
			i = 0;
		}
	}
	else {
		printf("\nA or B lie beyond the domain of a function!\n");
	}

	return 0;
}