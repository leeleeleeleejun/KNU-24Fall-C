#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			array[i][j] = rand() % 20 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE]) {
	printf("배열 출력 : \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	int moving = ((int*)array);
	int result = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < SIZE * SIZE; i++) {
		printf("현재 위치 (%d , %d),", x, y);
		printf("배열의 값 %d \n", ((int*)array)[i]);

		result = ((int*)array)[i];
		x += ((int*)array)[i] / 10;
		y += ((int*)array)[i] % 10;
		if (y >= 10) {
			x += y / 10;
			y = y % 10;
		}
		i += ((int*)array)[i] - 1;
	}
	printf("더 이상 이동할 수 없습니다. \n");

	printf("종료  위치 (%d , %d),", x, y);
	printf("배열의 값 %d \n", result);
}

int main() {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return;
}

