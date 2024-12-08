#include <stdio.h>

int main() {
    int n;
    double xSum = 0, ySum = 0, xySum = 0, x2Sum = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
        xSum += x[i];
        ySum += y[i];
        xySum += x[i] * y[i];
        x2Sum += x[i] * x[i];
    }

    // Calculate slope (m) and intercept (c)
    double m = (n * xySum - xSum * ySum) / (n * x2Sum - xSum * xSum);
    double c = (ySum - m * xSum) / n;

    printf("The regression line is: y = %.4lfx + %.4lf\n", m, c);

    return 0;
}

// Enter the number of data points: 3
// Enter the data points (x y):
// 1 2
// 2 3
// 3 4

