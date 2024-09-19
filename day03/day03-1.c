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
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� :  ");
	scanf_s("%d", &num);

	if (isPrimeNumber(num)) {
		printf("�ش� ���� �Ҽ��Դϴ�.");
	}
	else {
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.");
	}
}