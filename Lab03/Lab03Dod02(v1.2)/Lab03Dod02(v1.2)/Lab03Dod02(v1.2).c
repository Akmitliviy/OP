#include <stdio.h>

#define N 15

int main(void) {
	int sum = 0;
	int a[N][N] = { 0 }, b[N][N] = { 0 }, c[N][N] = { 0 };

	printf("Enter A:\n{");
	for (int i = 0; i < N * N; i++) {
		*(*a + i) = rand() % 10;

		printf("%d, ", *(*a + i));
		if (i != 0 && (i + 1) % N == 0)
			printf("}\n{");
	}

	printf("Enter B:\n{");
	for (int i = 0; i < N * N; i++) {
		*(*b + i) = rand()%10;

		printf("%d, ", *(*b + i));
		if (i != 0 && (i + 1) % N == 0)
			printf("}\n{");
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
			sum = 0;
		}
	}

	for (int i = 0; i < N * N; i++) {
		printf("%d\t", *(*c + i));
		if (i != 0 && (i + 1) % N == 0)
			printf("\n");
	}

	return 0;
}