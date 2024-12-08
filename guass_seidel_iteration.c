#include <stdio.h>
#include <math.h>

void gaussSeidel(int n, double a[n][n + 1], double tol, int maxIter) {
    double x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0; // Initial guess
    }

    for (int iter = 1; iter <= maxIter; iter++) {
        double maxError = 0.0;
        for (int i = 0; i < n; i++) {
            double sum = a[i][n];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            double newX = sum / a[i][i];
            maxError = fmax(maxError, fabs(newX - x[i]));
            x[i] = newX;
        }

        if (maxError < tol) {
            printf("Converged in %d iterations.\n", iter);
            break;
        }
    }

    printf("The solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double a[n][n + 1];
    printf("Enter the augmented matrix row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    double tol;
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);

    int maxIter;
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIter);

    gaussSeidel(n, a, tol, maxIter);
    return 0;
}
