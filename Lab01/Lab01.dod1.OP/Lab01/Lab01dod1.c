#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    const double z = 3.25;

    printf("Program calculate this expression:\n(x + 3(x - y) + x^2)/((x - y)^z + x^2)\n\nEnter x: ");
    scanf_s("%lf", &x);

    printf("Enter y: ");
    scanf_s("%lf", &y);

    if (x - y <= 0 || pow((x - y), z) + pow(x, 2) == 0)
        printf("\nSorry, but we can't perform this operation, because values of variables you chose lie beyond the domain of a function\n");
    else {
        double b = (x + 3 * (x - y) + pow(x, 2)) / (pow((x - y), z) + pow(x, 2));

        printf("\nResult is %lf\n", b);
    }
    return 0;
}