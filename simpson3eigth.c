#include <stdio.h>
#include <math.h>

// Define the function to integrate
double function(double x) {
    return 1 / (1 + x * x);  // Example: f(x) = 1 / (1 + x^2)
}

double simpsonsThreeEighth(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Error: n must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return -1;
    }

    double h = (b - a) / n;  // Step size
    double result = function(a) + function(b);

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            result += 2 * function(a + i * h);
        } else {
            result += 3 * function(a + i * h);
        }
    }

    result *= 3 * h / 8;
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

    double result = simpsonsThreeEighth(a, b, n);
    if (result != -1) {
        printf("Result using Simpson's 3/8 Rule: %.6f\n", result);
    }

    return 0;
}


// Enter the number of intervals (multiple of 3): 3
// Enter lower limit (a): 0
// Enter upper limit (b): 1
