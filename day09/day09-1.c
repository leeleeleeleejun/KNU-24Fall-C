#include <stdio.h>

struct Vector
{
	int x;
	int y;
	int z;
};

void one(struct Vector v1, struct Vector v2) {
	printf("벡터의 합은  x: %d   y: %d   z: %d \n", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
void two(struct Vector v1, struct Vector v2) {
	printf("벡터의 차는  x: %d   y: %d   z: %d \n", v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
void three(struct Vector v1, struct Vector v2) {
	printf("벡터의 외적은  x: %d   y: %d   z: %d \n", v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}
void four(struct Vector v1, struct Vector v2) {
	printf("벡터의 내적은  vec1 * vec2 = %d \n", v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

void cal(int num, struct Vector v1, struct Vector v2 ) {
	switch (num)
	{
	case 1: {
		one(v1, v2);
		break;
	}
	case 2: {
		two(v1, v2);
		break;
	}
	case 3: {
		three(v1, v2);
		break;
	}
	case 4: {
		four(v1, v2);
		break;
	}
	default:
		break;
	}
}



int main() {
	struct Vector v1, v2;
	int opr = 0;

	printf("첫번째 벡터(x, y, z) : ");
	scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
	printf("두번째 벡터(x, y, z) : ");
	scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

	printf("입력된 첫 번째 벡터 %d,  %d,  %d\n", v1.x, v1.y, v1.z);
	printf("입력된 두 번째 벡터 %d,  %d,  %d\n", v1.x, v1.y, v1.z);

	while (opr != 5)
	{	
	

		printf("-------------------\n 1. 벡터의 합\n 2. 벡터의 차 \n 3. 벡터의 외적 \n 4. 백터의 내적 \n 5. 종료 \n------------------- \n");
		printf("명령 입력 : ");
		scanf_s("%d", &opr);
		cal(opr, v1, v2);
	}
}