#include <stdio.h>

void swap(int* pnum1, int* pnum2) {
	int a = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = a;
}

int main() {
	int num1 = 10;
	int num2 = 100;

	int* pnum1 = &num1;
	int* pnum2 = &num2;
	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);
	swap(pnum1, pnum2);
	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);

	return 0;
}