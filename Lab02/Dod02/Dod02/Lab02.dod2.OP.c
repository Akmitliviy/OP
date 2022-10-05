#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main(void) {
	double y = 0, d = 1, func, a, b, counter;
	int accuracy;
	char c;
	int repeat = 1;

	while (repeat != 0) {
		printf("Enter A (|A| < 1): ");
		scanf_s("%lf", &a);

		printf("Enter B (|B| < 1): ");
		scanf_s("%lf", &b);

		printf("Enter step: ");
		scanf_s("%lf", &counter);

		printf("Enter accuracy: ");
		scanf_s("%d", &accuracy);

		if (fabs(a) < 1 && fabs(b) < 1) {
			printf("\nx\t\ty\t\tfunc\n");
			for (double x = a; x < b; x += counter) {
				for (int i = 0; i < accuracy; i++) {
					d = d * ((3.0 * (double)i + 1.0) * x / (3.0 * (double)i + 3.0));
					y += d;
				}

				func = pow(1.0 - x, -1.0 / 3.0);
				y += 1.0;
				printf("%lf\t%lf\t%lf\n", x, y, func);

				y = 0;
				d = 1;
			}
		}
		else {
			printf("A or B lie beyond the domain of a function!\n");
		}

		printf("\nEnter \"0\" to stop process, or any other number to continue: ");
		scanf_s("%d", &repeat);
		printf("\n");
	}

	return 0;
}