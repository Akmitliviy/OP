#include <stdio.h>
int main() {

    int num, numShadow, min, max;

    printf("Enter 8-digit number: ");
    scanf_s("%d", &num);

    numShadow = num;

    min = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;    
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 < min) min = numShadow % 10;
    numShadow = num;

    max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;
    numShadow = numShadow / 10;

    if (numShadow % 10 > max) max = numShadow % 10;

    printf("Max digit is: %d\nMin digit is: %d", max, min);
    return 0;
}