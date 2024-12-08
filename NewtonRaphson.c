#include <stdio.h>
#include <math.h>

// Function definition
double f(double x) {
    return x * x * x * x - x - 10;  // f(x) = x^4 - x - 10
}

// Derivative of the function
double df(double x) {
    return 4 * x * x * x - 1;  // Derivative: f'(x) = 4x^3 - 1
}

// Newton's method function
void newton(double x0, double tol) {
    double ans = x0;  // Initial guess for Newton's method
    double x1;

    // Newton's iteration loop
    do {
        x1 = ans;  // Store the current guess
        ans = x1 - (f(x1) / df(x1));  // Newton's update rule
        printf("Current approximation = %f, f(x) = %f\n", ans, f(ans));  // Print iteration details
    } while (fabs(x1 - ans) > tol);  // Stopping condition based on tolerance

    printf("The root is approximately: %f\n", ans);
}

int main() {
    double x0;
    
    // Input
    printf("Enter the initial guess: ");
    scanf("%lf", &x0);  // Corrected to %lf for double input

    double tol = 0.001;  // Tolerance value

    // Call Newton's method
    newton(x0, tol);

    return 0;
}

//input 2