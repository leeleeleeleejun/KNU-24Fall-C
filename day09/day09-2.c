#include <stdio.h>
#define SIZE 5
#define MAX 100

struct Product
{
	int id;
	char name[MAX];
	int price;
};

void printProduct(struct Product product) {
	printf("��ǰid : %d\n��ǰ�� : %s\n���� : %d\n", product.id, product.name, product.price);
}

int main() {
	struct Product pro[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("��ǰ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
		printf("��ǰid : ");
		scanf_s("%d", &pro[i].id);
		if (pro[i].id == 0) break;
		printf("��ǰ�� : ");
		scanf_s("%s", pro[i].name, (unsigned int)sizeof(pro[i].name));
		printf("��ǰ ���� : ");
		scanf_s("%d", &pro[i].price);
	}

	printf("<<�Էµ� ��ǰ ���>>\n");

	for (int j = 0; j < i; j++) {
		printProduct(pro[j]);
	}

}