#include <stdio.h>


int main() {
	int i, j, k;
	int length;
	printf("층 수 입력 :");

	scanf_s("%d", &length);
	printf("%d층 피라미드\n", length);

	for (i = 0; i < length; i++) {
		for (j = 0; j < length - i; j++) {
			printf(" ");
		}
		for (k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}