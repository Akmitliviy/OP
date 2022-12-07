#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int calculator(int n, ...);

int main() {

	printf("Number of numbers: %d\n", calculator(8, -1, 5, 6, 7, -2, 2, 4, -3));

	return 0;
}

int calculator(int n, ...) {
	int term, counter = 0;

	va_list arg_list;
	va_start(arg_list, n);

	for (int i = 0; i < n; i++) {
		term = va_arg(arg_list, int);

		if (!(term % 2) && term > 0)
			counter++;
	}

	return counter;
}