#include <stdio.h>
#include <math.h>

int main() {
	int counter = 0;
	double r;

	printf("Please enter Radius: ");
	scanf_s("%lf", &r);

	for (int x = -r; x < r; x++)
	{
		for (int y = -r; y < r; y++)
		{
			if (sqrt(pow(x, 2) + pow(y, 2)) < r) {
				counter++;
			}
		}
	}

	printf("Amount of suitable %d", counter);
	return 0;
}