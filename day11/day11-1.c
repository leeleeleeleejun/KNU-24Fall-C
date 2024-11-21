#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, D;
    double answer1, answer2;

    printf("a, b, c를 입력하세요.\n: ");
    scanf_s("%d %d %d", &a, &b, &c); 

    D = b * b - 4 * a * c;  
    if (D >= 0) {
        answer1 = (-b + sqrt(D)) / (2 * a);  
        answer2 = (-b - sqrt(D)) / (2 * a);
    }

    if (D < 0) {
        printf("근은 허근입니다.\n"); 
    }
    else if (D == 0) {
        printf("근은 %.2f(중근)입니다.\n", answer1);
    }
    else {
        printf("근은 %.2f와(과) %.2f입니다.\n", answer1, answer2);
    }

    return 0;
}
