#include <stdio.h>
#include <stdlib.h>

// Function for which integral will be calculated.
double f(double x) { return (1 / (1 + x)); }

int main() {
    int i, n;
    double lowLim, upLim, h, y[1000], sumOdd, sumEven, ans, x[1000];
    printf("Enter the values of upper limit(upLim), lower limit(lowLim) and "
           "number of observations(n).\n");
    scanf("%lf %lf %d", &lowLim, &upLim, &n);

    // Now finding number of intervals or step size.
    n = (upLim - lowLim) / h;
    if (n ^ 1)
        n += 1;
    h = (upLim - lowLim) / n;

    printf("%lf interval size: %d\n", h, n);
    printf("x\ty\n");

    // Now calculating y.
    for (int i = 0; i <= n; i++) {
        x[i] = lowLim + i * h;
        y[i] = f(x[i]);
        printf("%lf\t%lf\n", x[i], y[i]);
    }

    // sumOdd is the sum of Odd terms.
    // sumEven is the sum of Even terms.
    sumOdd = 0;
    sumEven = 0;

    for (int i = 1; i < n; i++) {
        if (i % 2 == 1)
            sumOdd += y[i];
        else
            sumEven += y[i];
    }

    // Now applying Simpson's 1/3 rule.
    ans = h / 3 * (y[0] + y[n] + 4 * (sumOdd) + 2 * sumEven);
    printf("Value of the integral I:: %lf\n", ans);
    return 0;
}