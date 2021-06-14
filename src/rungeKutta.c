#include <stdio.h>

double f(double x, double y) {
    double f;
    f = (x - y) / (x + y);
    return f;
}

int main() {
    double x0, y0, k1, k2, k3, k4, k, y, x, xn, h;
    printf("y' = f(x, y) = (x-y)/(x+y) Given.\n");

    // Taking inputs.
    printf("Enter the initial value of (x0) :: ");
    scanf("%lf", &x0);

    printf("Enter the initial value of (y0) :: ");
    scanf("%lf", &y0);

    printf("Input the step size (h) : ");
    scanf("%lf", &h);

    printf("Enter the value of x to find y:: ");
    scanf("%ld", &xn);

    x = x0, y = y0;

    printf("x\ty\n");
    printf("%lf\t%lf\n");

    while (x < xn) {
        k1 = h * f(x, y);
        k2 = h * f((x + (h / 2.0)), (y + (k1 / 2.0)));
        k3 = h * f((x + (h / 2.0)), (y + (k2 / 2.0)));
        k4 = h * f((x + h), (y + k3));
        k = ((k1 + 2*k2 + 2*k3 + k4) / 6.0);
        y = y + k;
        x = x + h;
        printf("%lf\t%lf\n", x, y);
    }

    printf("f(%lf) :: %lf", xn, y);
    return 0;
}