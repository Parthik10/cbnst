#include <stdio.h>

void gaussElimination(int n, double a[n][n + 1]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    double x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    printf("The solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
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

    gaussElimination(n, a);
    return 0;
}
