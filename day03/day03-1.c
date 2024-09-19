#include <stdio.h>
#include<math.h>

int isPrimeNumber (int num) {
	if (num == 0 || num == 1)	return 0;

	for (int i = 2; i <= sqrt(num);  i++)	{
		if (num % i == 0) return 0;
	}
	
	return 1;
}

int main() {
	int num;
	printf("소수인지 확인할 수를 입력하세요 :  ");
	scanf_s("%d", &num);

	if (isPrimeNumber(num)) {
		printf("해당 수는 소수입니다.");
	}
	else {
		printf("해당 수는 소수가 아닙니다.");
	}
}