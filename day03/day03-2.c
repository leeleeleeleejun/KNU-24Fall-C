#include <stdio.h>
int cal (int first, int num, int answer) {
	if (num != 1) {
		cal(first, num - 1, answer * num);
	}
	else {
		printf("%d! = %d", first, answer);
	}
}


int main() {
	int num;
	printf("계산할 팩토리얼 값 입력 : ");
	scanf_s("%d", &num);

	if (num == 1 || num == 0) {
		printf("%d! = 1", num);
		return;
	}
	cal(num, num, 1);
}