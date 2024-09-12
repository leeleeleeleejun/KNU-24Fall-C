#include <stdio.h>

int main()
{
	int operation;
	printf("연산 타입: ");
	scanf_s("%d", &operation);

	double num1, num2;
	printf("첫번째 숫자: ");
	scanf_s("%lf", &num1);
	printf("두번째 숫자: ");
	scanf_s("%lf", &num2);

	double result = 0.0;
	if (operation == 1) {
		result = num1 + num2;
	}
	else if (operation == 2) {
		result = num1 - num2;
	}
	else {
		printf("잘못 입력하셨습니다.\n");
	}

	printf("result = %lf\n", result);

	return 0;
}