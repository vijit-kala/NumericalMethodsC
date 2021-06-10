#include <math.h>
#include <stdio.h>

double f(double x) { return (1 / (1 * x * x)); }

int main() {
    double x0, xn, h, y[100], x[100], sum = 0, ans;
    int i, n;

    // Taking inputs.
    printf("Enter the lower limit:: ");
    scanf("%lf", &x0);

    printf("Enter the upper limit:: ");
    scanf("%lf", &xn);
    printf("Enter the number of observations:: ");
    scanf("%d", &n);

    // Calculating the step size.
    h = (xn - x0) / n;
    printf("Interval size:: %lf\n", h);
    printf("x\ty\n");

    for (int i = 0; i <= n; i++) {
        x[i] = x0 + i * h;
        y[i] = f(x[i]);
        printf("%lf\t%lf\n", x[i], y[i]);
    }

    sum = 0;
    double sum1 = y[0] + y[n];
    for (int i = 1; i < n; i++) {
        sum += y[i];
    }

    sum *= 2;
    ans = (h * (sum1 + sum)) / 2.0;
    printf("Value of integral :: %lf\n", ans);
    return 0;
}