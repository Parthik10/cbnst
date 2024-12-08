#include <stdio.h>

// Define the differential equation dy/dx = f(x, y)
double function(double x, double y) {
    return x + y;  // Example: dy/dx = x + y
}

// Runge-Kutta 4th Order Implementation
void rungeKutta(double x0, double y0, double h, double xn) {
    double x = x0, y = y0;
    printf("x\t\ty\n");
    while (x <= xn) {
        printf("%.4f\t%.4f\n", x, y);

        double k1 = h * function(x, y);
        double k2 = h * function(x + h / 2, y + k1 / 2);
        double k3 = h * function(x + h / 2, y + k2 / 2);
        double k4 = h * function(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6; 
        x = x + h;
    }
}

int main() {
    double x0, y0, h, xn;

    printf("Enter initial x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter final x (xn): ");
    scanf("%lf", &xn);

    rungeKutta(x0, y0, h, xn);
    return 0;
}

// Enter initial values (x0 and y0): 0 1
// Enter the step size h: 0.2
// Enter the value of x to calculate y: 0.4
