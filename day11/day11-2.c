#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x) - log10(1 / x);;
    //return x * x + 1;
}

double rectangleMethod(double a, double b, int n) {
    double dx = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * dx;
        sum += f(x) * dx;
    }

    return sum;
}

int main() {
    double a, b;
    int max_power, n = 1;

    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &a);

    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &b);

    printf("시행할 최대 구간을 입력하세요(2^n): ");
    scanf_s("%d", &max_power);

    printf("구간\t\t\t\t적분 결과\n");
    printf("-------------------------\n");

    for (int i = 0; i <= max_power; i++) {
        double result = rectangleMethod(a, b, n);
        printf("구간 %10d\t적분 결과: %10.6f\n", n, result);
        n *= 2;
    }

    return 0;
}