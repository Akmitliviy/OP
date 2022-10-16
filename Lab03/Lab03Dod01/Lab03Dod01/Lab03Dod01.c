#include <stdio.h>
#include <math.h>

#define N 10

int main(void) {
	int minIndex = 0;
	double arithmeticMean = 0;
	double vector[N] = { 0 };

	printf("Enter 10 numbers:\n");
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", vector + i);
		arithmeticMean += vector[i];

		if (vector[i] < vector[minIndex])
			minIndex = i;
	}
	arithmeticMean /= N;

	for (int i = minIndex - 1; i >= 0; i--) {
		vector[i] /= arithmeticMean / 2;
	}

	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%.3lf\t", *(vector + i));
	}
}