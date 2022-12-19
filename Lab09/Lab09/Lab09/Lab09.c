#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* GetSumOfLineElements(int** matrix, int* lineSize, int matrixSize);

int main() {
	int n = 0, m = 0;
	printf("Enter number of lines in matrix: ");
	scanf("%d", &n);

	int** matrix = calloc(n, sizeof(int*));
	int* sizeOfMatrix = calloc(n, sizeof(int));
	if (!matrix || !sizeOfMatrix)
		printf("\nLack of memory :(");
	else {
		for (int i = 0; i < n; i++) {
			printf("\nEnter number of elements in line %d: ", i + 1);
			scanf("%d", &m);
			matrix[i] = calloc(m, sizeof(int));
			sizeOfMatrix[i] = m;

			printf("Enter elements of line %d\n", i + 1);
			for (int k = 0; k < m; k++) {
				printf("Element %d: ", k + 1);
				scanf("%d", &matrix[i][k]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < sizeOfMatrix[i]; j++)
				printf("%d\t", matrix[i][j]);
			printf("\n");
		}
	}
	
	int* sum = GetSumOfLineElements(matrix, sizeOfMatrix, n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("Sum of elements of %d line is equal %d\n", i + 1, sum[i]);
	}

	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);

	free(sizeOfMatrix);

	return 0;
}
int* GetSumOfLineElements(int** matrix, int* lineSize, int matrixSize) {
	int* sum = calloc(matrixSize, sizeof(int));

	if (!sum)
		printf("\nLack of memory :(");
	else {
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < lineSize[i]; j++) {
				sum[i] += matrix[i][j];
			}
		}
	}
	return sum;
}