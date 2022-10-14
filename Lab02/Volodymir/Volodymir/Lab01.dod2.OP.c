#include<stdio.h>
#include<math.h>

int main(void) {
	//double y = 0, temp = 2, func, a, b, step;
	//int taylor;

	//printf("Enter A, B, step, precision: \n");               //Вводимо відрізок (A, B), крок, з яким будемо його проходити
	//scanf_s("%lf %lf %lf %d", &a, &b, &step, &taylor);       //та точність, з якою буде обраховуватися ряд тейлора

	//if (a > b || a <= -1 || a >= 1 || b <= -1 || b >= 1) printf("Wrong A or B!\n"); // ОДЗ
	//else {
	//	printf("\nx\t\ty\t\tfunc\n");
	//	for (double x = a; x < b; x = x + step) {
	//		for (int i = 0; i < taylor; i++) {
	//			temp = temp * (temp + 1) * pow(x, i + 1);    //Алгоритм
	//			if (i % 2 == 0) y += temp;
	//			else y -= temp;

	//			temp = i + 3;
	//		}

	//		func = pow(1.0 + x, -3.0);
	//		y = 1.0 - (1.0 / 2.0) * y;
	//		printf("%lf\t%lf\t%lf\n", x, y, func);           // Вивід функції

	//		y = 0;
	//		temp = 2;
	//	}
	//}

	int minFiveNumber = 10000;
	int maxFiveNumber = 100000;

	for (int i = minFiveNumber; i < maxFiveNumber; i++) {
		int result1 = i / 10000;
		int result2 = i / 1000 % 10;
		int result3 = i / 100 % 10;
		int result4 = i / 10 % 10;
		int result5 = i % 10;

		if ((result1 + result2 + result3 + result4 + result5) > 18) {
			printf("%d\n", i);
		}
	}

	return 0;
}