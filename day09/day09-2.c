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
	printf("상품id : %d\n상품명 : %s\n가격 : %d\n", product.id, product.name, product.price);
}

int main() {
	struct Product pro[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("상품정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
		printf("상품id : ");
		scanf_s("%d", &pro[i].id);
		if (pro[i].id == 0) break;
		printf("상품명 : ");
		scanf_s("%s", pro[i].name, (unsigned int)sizeof(pro[i].name));
		printf("상품 가격 : ");
		scanf_s("%d", &pro[i].price);
	}

	printf("<<입력된 상품 목록>>\n");

	for (int j = 0; j < i; j++) {
		printProduct(pro[j]);
	}

}