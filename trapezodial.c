#include <stdio.h>
#include <math.h>

// Define the function to integrate
double function(double x) {
    return 1 / (1 + x * x);  // Example: f(x) = 1 / (1 + x^2)
}

// Trapezoidal Rule Implementation
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double result = function(a) + function(b);  // Add the first and last terms

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        result += 2 * function(x);  // Add twice the function value for intermediate points
    }

    result *= h / 2;  // Multiply by h/2 as per trapezoidal formula
    return result;
}

int main() {
    double a, b;
    int n;

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter number of intervals (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Number of intervals (n) must be greater than zero.\n");
        return 1;
    }

    double result = trapezoidalRule(a, b, n);
    printf("Result using Trapezoidal Rule: %.6f\n", result);

    return 0;
}


// Enter the number of intervals: 4
// Enter lower limit (a): 0
// Enter upper limit (b): 1
