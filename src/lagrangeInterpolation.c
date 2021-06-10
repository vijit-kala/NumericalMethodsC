#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of values available:: ");
    scanf("%d", &n);

    double x[n];
    double y[n];

    // Taking inputs.
    printf("Enter the values [x, y]:: \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Inputting value of x.
    double x1;
    printf("Enter the value of x:: ");
    scanf("%lf", &x1);

    double sum = 0;

    for (int i = 0; i < n; i++) {
        double mult = 1;
        mult *= y[i];
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (mult == 0)
                break;
            mult *= (x1 - x[j]) / (x[i] - x[j]);
        }
        sum += mult;
    }

    printf("Value of y is:: %lf\n", sum);
    return 0;
}