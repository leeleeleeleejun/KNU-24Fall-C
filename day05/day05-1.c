#include <stdio.h>
#include <stdlib.h>

int main() {

	int N;
	int* stud_num;
	char** name;
	int* score;

	printf("�л� �� �Է� : ");
	scanf_s("%d", &N);

	stud_num = (int*)malloc(sizeof(int) * N);

	name = (char**)malloc(N * sizeof(char*));

	score = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		printf("�й� : ");
		scanf_s("%d", &stud_num[i]);
		printf("�̸� : ");
		scanf_s("%s", name[i], 100);
		printf("���� : ");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("�й�: %d, �̸�: %s, ����: %d\n", stud_num[i], name[i], score[i]);
	}

	free(stud_num);
	free(name);
	free(score);

	return 0;
}