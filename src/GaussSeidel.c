#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int n;
  printf("Enter the dimensions:: ");
  scanf("%d", &n);
  double mat[n][n+1];
  
  // Input 
  printf("Enter the elements of the augmented matrix [A|B]:: \n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<=n; j++) {
      scanf("%lf", &mat[i][j]);
    }
  }
  
  // Printing Augmented Matrix
  printf("Augmented Matrix:: \n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<=n; j++) {
      if(j == n)
        printf(" | ");
      printf("%.3lf ", mat[i][j]);
    }
    printf("\n");
  }
  
  /* Checking validity of matrix for gauss seidel */
  double sum_diag = 0;
  for(int i=0; i<n; i++) {
    if(mat[i][i] == 0) {
      printf("Since element is zero cannot apply gauss seidel method\n");
      return 0;
    }
    sum_diag += fabs(mat[i][i]);
  }
  
  double sum_all = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      sum_all += fabs(mat[i][j]);
    }
  }
  
  if(sum_all > (2 * sum_diag)) {
    printf("Cannot apply Gauss-Seidel method\n");
    return 0;
  }
  
  double *x = (double *) malloc(sizeof(double) * n);
  double *xprev = (double *)malloc(sizeof(double) * n);
  
  memset(x, 0, n);
  memset(xprev, 0, n);
  
  int no_of_digits = 3;
  double tolError = 0.5 * pow(10, -no_of_digits);
  
  int flag = 0, iteration = 0;
  
  while(flag != n) {
    for(int i=0; i<n; i++) {
      double sum = 0;
      for(int j=0; j<i; j++) {
        sum += mat[i][j] * x[j];
      }
      for(int j=i+1; j<n; j++) {
        sum += mat[i][j] * xprev[j];
      }
      x[i] = (mat[i][n] - sum) / mat[i][i];
    }
    for(int i=0; i<n; i++) {
      if(fabs(x[i] - xprev[i]) < tolError)
        flag++;
    }
    
    // Storing x to xprev
    double *temp;
    temp = x;
    x = xprev;
    xprev = temp;
  }
  
  printf("Final Result::\n");
  for(int i=0; i<n; i++)
    printf("x%d = %.3lf\t", i, xprev[i]);
  free(xprev);
  free(x);
  return 0;
}
