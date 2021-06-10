#include <stdio.h>

double func(float x, float y) {
    double f;
    f = (x - y) / (x + y);
    return f;
}

int main() {
    double x0, y0, x, y, h, xn, k;
    printf("y' = f(x, y) = (x-y)/(x+y) Given.\n ");

    printf("Enter initial value for x (x_0): ");
    scanf("%lf", &x0);
    printf("Enter initial value for y (y_0): ");
    scanf("%lf", &y0);
    printf("Enter the spacing value for x (h): ");
    scanf("%lf", &h);
    printf("Enter x for which y is to be calculated (x_n): ");
    scanf("%ld", &xn);

    x = x0;
    y = y0;

    printf("x\ty\n");
    printf("%lf\t%lf\n", x, y);

    while (x < xn) {
        k = h * func(x, y);
        y = y + k;
        x = x + h;
        printf("%lf\t%lf\n", x, y);
    }

    printf("f(%lf) = %lf\n", xn, y);
    return 0;
}