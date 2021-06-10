// Newtons Forward Interpolation
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long fact(long n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n;
    printf("Enter the number of values:: ");
    scanf("%d", &n);

    double arr[n][2];
    printf("Enter the values [x, y]:: \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &arr[i][0], &arr[i][1]);
    }

    // Logic to develop difference table.
    double diffTable[n][n];
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = arr[i][1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            diffTable[j][i] = diffTable[j + 1][i - 1] - diffTable[j][i - 1];
        }
    }

    // Printing the difference table.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%lf\t|", diffTable[i][j]);
        }
        printf("\n");
    }

    /* Taking inputs. */
    double x;
    printf("Enter the value of x:: ");
    scanf("%lf", &x);

    double h = arr[1][0] - arr[0][0];
    double u = (x - arr[0][0]) / h;
    if (fabs(u) > 1) {
        printf("Value of u > 1. \n");
    }

    /* Newton's Forward Interpolation. */
    double y = 0;
    for (int i = 0; i < n; i++) {
        double mult = 1;
        for (int j = 0; j < i; j++) {
            mult *= (u - j);
        }
        y += (mult * diffTable[0][i]) / fact(i);
        printf("\n%d Approximation = %lf\n", i, y);
    }
    printf("\n");

    printf("*h = %lf\n", h);
    printf("*u = %lf\n", u);
    printf("The approximate value of y:: %lf\n", y);
    return 0;
}