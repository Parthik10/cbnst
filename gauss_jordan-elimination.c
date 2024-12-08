#include <stdio.h>

void gaussJordan(int n, double a[n][n + 1]) {
    for (int i = 0; i < n; i++) {
        double pivot = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = a[j][i];
                for (int k = 0; k <= n; k++) {
                    a[j][k] -= factor * a[i][k];
                }
            }
        }
    }

    printf("The solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, a[i][n]);
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

    gaussJordan(n, a);
    return 0;
}
