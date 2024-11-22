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

    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%lf", &a);

    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%lf", &b);

    printf("������ �ִ� ������ �Է��ϼ���(2^n): ");
    scanf_s("%d", &max_power);

    printf("����\t\t\t\t���� ���\n");
    printf("-------------------------\n");

    for (int i = 0; i <= max_power; i++) {
        double result = rectangleMethod(a, b, n);
        printf("���� %10d\t���� ���: %10.6f\n", n, result);
        n *= 2;
    }

    return 0;
}