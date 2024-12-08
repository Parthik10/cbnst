#include <stdio.h>

// Function to solve a system of linear equations using Gaussian elimination
void solveSystem(int n, double matrix[n][n + 1], double result[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            result[i] -= matrix[i][j] * result[j];
        }
        result[i] /= matrix[i][i];
    }
}

int main() {
    int n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double sumX = 0, sumY = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    double sumXY = 0, sumX2Y = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }

    // Form the augmented matrix for the normal equations
    double matrix[3][4] = {
        {n, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}
    };

    double coefficients[3];
    solveSystem(3, matrix, coefficients);

    printf("The parabolic equation is: y = %.4lfx^2 + %.4lfx + %.4lf\n",
           coefficients[2], coefficients[1], coefficients[0]);

    return 0;
}

// Enter the number of data points: 4
// Enter the data points (x y):
// 1 6
// 2 11
// 3 18
// 4 27
