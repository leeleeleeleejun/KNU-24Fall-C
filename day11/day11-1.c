#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, D;
    double answer1, answer2;

    printf("a, b, c�� �Է��ϼ���.\n: ");
    scanf_s("%d %d %d", &a, &b, &c); 

    D = b * b - 4 * a * c;  
    if (D >= 0) {
        answer1 = (-b + sqrt(D)) / (2 * a);  
        answer2 = (-b - sqrt(D)) / (2 * a);
    }

    if (D < 0) {
        printf("���� ����Դϴ�.\n"); 
    }
    else if (D == 0) {
        printf("���� %.2f(�߱�)�Դϴ�.\n", answer1);
    }
    else {
        printf("���� %.2f��(��) %.2f�Դϴ�.\n", answer1, answer2);
    }

    return 0;
}
