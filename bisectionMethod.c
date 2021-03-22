#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.71828

// F(x)
float f(float x) {
    return x*x - 7;
}

int main() {
    float a, b;
    float tolError;

    // Input
    do {
        printf("Input interval a,b: ");
        scanf("%f %f", &a, &b);
        if(f(a)*f(b) >= 0)
            printf(("Invalid interval\n"));
    } while(f(a) * f(b) >= 0);

    printf("Input tolerable error: ");
    scanf("%f", &tolError);

    // Bisection Method

    int cnt = 0;
    float prev = a;
    while(1) {
        float x2 = (a + b)/2;
        float fx2 = f(x2);
        if(fx2 == 0) {
            printf("Solution: %.3f at iteration %d", x2, cnt+1);
            break;
        } else {
            if(f(x2)*f(a) <0) {
                b = x2;
            } else {
                a = x2;
            }
        }
        printf("Iteration %d x2: %.3f f(x2): %.3f\n", cnt+1, x2, f(x2));

        if(fabs(x2 - prev) < tolError) {
            printf("Solution: %.3f after %d iterations", x2, cnt+1);
            break;
        }
        cnt++;
        prev = x2;
    }
    return 0;
}