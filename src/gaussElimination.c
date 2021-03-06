#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d",&n);
    
    // Create Augmented Matrix
    float mat[n][n+1];
    printf("Enter the elements of the matrix: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<=n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    // Partial-pivoting
    for(int i=0; i<n; i++) {
        int swap = i;
        for(int j=i+1; j<n; j++) {
            if(mat[i][j] > mat[swap][i])
                swap = j;
        }
        if(swap != i) {
            float temp;
            for(int k=0; k<=n; k++) {
                temp = mat[i][k];
                mat[i][k] = mat[swap][k];
                mat[swap][k] = temp;
            }
        }
    }

    // Upper-Triangle Form

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(fabs(mat[i][i]) < 0.000001) {
                printf("Equation is unsolvable as diagonal entry becomes zero\n");
                return 0;
            }
            float div = mat[j][i]/mat[i][i];
            for(int k=i; k<=n; k++) {
                mat[j][k] -= (div * mat[i][k]);
            }
        }
    }

    printf("Upper Triangle Form: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<=n; j++) {
            printf("%.3f ", mat[i][j]);
        }
        printf("\n");
    }

    // Back substitution
    float x[n];
    for(int i=0; i<n; i++) 
        x[i] = 0;
    x[n-1] = mat[n-1][n]/mat[n-1][n-1];
    for(int i=n-2; i>=0; i--) {
        float sum = 0;
        for(int j=i+1; j<n; j++) {
            sum += (mat[i][j]*x[j]);
        }
        x[i] = (mat[i][n] - sum)/mat[i][i];
    }
    printf("Solution: \n");
    for(int i=0; i<n; i++) {
        printf("x%d : %.3f\n", i+1, x[i]);
    }

    return 0;
}