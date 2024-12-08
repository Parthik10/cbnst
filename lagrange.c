#include <stdio.h>

// Function to calculate Lagrange Interpolation
double LagrangeInterpolation(double x[], double y[], int n, double xp) {
    double yp = 0.0; // Interpolated value at xp

    // Iterate through each term of the Lagrange polynomial
    for (int i = 0; i < n; i++) {
        double term = y[i]; // Start with y[i] for the ith term
        for (int j = 0; j < n; j++) {
            if (i != j) { // Avoid division by zero
                term *= (xp - x[j]) / (x[i] - x[j]); // Calculate the term
            }
        }
        yp += term; // Add the term to the result
    }
    return yp; // Return the interpolated value
}

int main() {
    int n;
    
    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    double x[n], y[n], xp;

    // Input the x values
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    // Input the y values
    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    // Input the point to interpolate
    printf("Enter the point to interpolate (xp): ");
    scanf("%lf", &xp);

    // Perform Lagrange interpolation
    double yp = LagrangeInterpolation(x, y, n, xp);

    // Output the interpolated value
    printf("The interpolated value at x = %.2lf is y = %.5lf\n", xp, yp);

    return 0;
}


// Enter the number of data points: 3
// Enter the x values:
// 1 2 3
// Enter the y values:
// 2 4 6
// Enter the point to interpolate (xp): 2.5
