#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return x*x - 7;
}

float df(float x) {
    return 2*x;
}

int main() {
    int iter; // No of iterations
    float x0, tolError;

    printf("Input starting value and tolerable error along with number of iterations: ");
    scanf("%f %f %d", &x0, &tolError, &iter);

    if(f(x0) == 0) {
        printf("Root: %.3f", x0);
        return 0;
    } else {
        int cnt = 0;
        float prev = x0;
        while(cnt < iter) {
            float xr = x0 - f(x0)/df(x0);
            if(f(xr) == 0) {
                printf("Root: %.3f\n at iteration: %d\n", xr, cnt+1);
                break;
            } else if(fabs(f(xr-x0)) < tolError) {
                printf("Root : %.3f at iteration: %d\n", xr, cnt+1);
                break;
            } else {
                printf("Iteration: %d Root: %.3f\n", cnt+1, xr);
                x0 = xr;
                cnt++;
            }
        }
        
    }
    return 0;
}