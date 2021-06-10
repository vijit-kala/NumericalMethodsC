#include <math.h>
#include <stdio.h>

double f(double x) { return (1 / (1 * x * x)); }

int main() {
    double lower, upper, stepSize, k;
    int subInterval;

    // Taking inputs.
    printf("Enter the lower limit of integration:: ");
    scanf("%lf", &lower);
    printf("Enter the upper limit of integration:: ");
    scanf("%lf", &upper);
    printf("Enter the number of sub intervals:: ");
    scanf("%d", &subInterval);

    if (subInterval % 3 != 0) {
        printf("Sub-intervals must be a multiple of 3.\n");
        return 0;
    }

    stepSize = (upper - lower) / subInterval;
    double sum = 0.0;
    sum = f(upper) + f(lower);

    for (int i = 1; i <= subInterval - 1; i++) {
        double val = lower + i * stepSize;
        if (i % 3 != 0)
            sum += 2 * f(val);
        else
            sum += 3 * f(val);
    }
    sum = (sum * stepSize * 3) / 8.0;
    printf("Value of the integral:: %lf\n", sum);

    return 0;
}