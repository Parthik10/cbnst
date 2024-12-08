#include <stdio.h>

double factorial(int n) {
    if (n == 0 || n == 1) return 1.0;
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n][n];
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i][0]);
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    printf("The difference table is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%lf ", y[i][j]);
        }
        printf("\n");
    }

    double xp;
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xp);

    double h = x[1] - x[0];
    double u = (xp - x[0]) / h;
    double result = y[0][0];
    double uTerm = 1;

    for (int i = 1; i < n; i++) {
        uTerm *= (u - i + 1);
        result += (uTerm * y[0][i]) / factorial(i);
    }

    printf("The interpolated value at x = %.2lf is y = %.5lf\n", xp, result);
    return 0;
}
