#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Header.h"

#define N 10000


time_t t;
int arr[N];
int arrSave[N];

int main() {

	Initialize(arr, N);
	CopyArr(arrSave, arr, N);
	//Show(arr, N);

	ShowTime("Quick sort has started at: ");
	qs_sort(arr, 0, N - 1);
	ShowTime("Quick sort has ended at: ");

	//arrSave[4] = 909;
	printf(isSorted(arr, N));
	printf(isEqual(arr, arrSave, N));

	//Show(arr, N);
	CopyArr(arr, arrSave, N);
	//Show(arr, N);
	printf("\n");


	ShowTime("Bubble has started at: ");
	bubbleSort(arr, N);
	ShowTime("Bubble has ended at: ");

	printf(isSorted(arr, N));
	printf(isEqual(arr, arrSave, N));
	
	//Show(arr, N);

	return 0;
}

void Initialize(int* arr, long size) {
	for (int i = 0; i < size; i++) 
		arr[i] = rand()%100;

}
void Show(int* arr, long size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void CopyArr(int* destination, int* source, long size) {
	for (int i = 0; i < size; i++)
		destination[i] = source[i];
}
void ShowTime(char* message) {
	char output[50];
	char timeStr[20];

	strcpy(output, message);

	time(&t);
	strftime(timeStr, 20, "[%H:%M:%S]", localtime(&t));
	printf("%s\n", strcat(output, timeStr));
}

void bubbleSort(int* arr, long size) {

	for (int i = 0; i < size - 1; i++)
		for (int j = size - 1; j > i; j--)
			if (arr[j] < arr[j - 1])
				swap(arr, j, j - 1);
}

void swap(int array[], long pos1, long pos2)
{
	long tmp;
	tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}
void qs_sort(int array[], long start, long end)
{
	long head = start, tail = end - 1, tmp;
	long diff = end - start;
	long pe_index;

	if (diff < 1) return;
	if (diff == 1)
		if (array[start] > array[end]) {
			swap(array, start, end);
			return;
		}

	long m = (start + end) / 2;
	if (array[start] <= array[m]) {
		if (array[m] <= array[end]) pe_index = m;
		else if (array[end] <= array[start]) pe_index = start;
		else pe_index = end;
	}
	else {
		if (array[start] <= array[end]) pe_index = start;
		else if (array[end] <= array[m]) pe_index = m;
		else pe_index = end;
	}
	long pe = array[pe_index];
	swap(array, pe_index, end);
		while (1) {
			while (array[head] < pe)
				++head;
			while (array[tail] > pe && tail > start)
				--tail;
			if (head >= tail) break;
			swap(array, head++, tail--);
		}
	swap(array, head, end);
	long mid = head;
	qs_sort(array, start, mid - 1);
	qs_sort(array, mid + 1, end);
}

char* isSorted(int* arr, long size) {

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return "\nUnsorted\n";
		}
	}
	return "\nSorted\n";
}
char* isEqual(int* arr1, int* arr2, long size) {
	int counter = 0;
	float copiedArr2[N];

	for (int i = 0; i < size; i++)
		copiedArr2[i] = arr2[i];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr1[i] == copiedArr2[j]) {
				copiedArr2[j] = NAN;
				counter++;
				break;
			}

		}
	}

	if(counter == size) return "\nArrays are equal\n";
	
	return "\nArrays are NOT equal\n";
}