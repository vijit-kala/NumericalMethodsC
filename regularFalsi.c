#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return x*x - 7;
}

int main() {
    float x0, x1;
    float tolError;

    // Input
    do {
        printf("Input interval a,b: ");
        scanf("%f %f", &x0, &x1);
        if(f(x0)*f(x1) >= 0)
            printf(("Invalid interval\n"));
    } while(f(x1) * f(x0) >= 0);

    printf("Input tolerable error: ");
    scanf("%f", &tolError);

    // Regular Falsi method

    int cnt = 0;
    float prev = x0;
    while(1) {
        float x2 = (x0*f(x1) - x1*f(x0))/(f(x1) - f(x0));
        float fx2 = f(x2);
        if(fx2 == 0) {
            printf("Solution: %.3f at iteration: %d\n", x2, cnt+1);
            break;
        } else {
            if(f(x2)*f(x0) < 0)
                x1 = x2;
            else 
                x0 = x2;
        }
        printf("Iteration: %d Root: %.3f\n", cnt+1, x2);
        if(fabs(x2-prev) < tolError) {
            printf("Solution after %d iterations : %.3f\n", cnt+1, x2);
            break;
        }
        cnt++;
        prev = x2;
    }
    return 0;
}