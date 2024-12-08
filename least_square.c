#include <stdio.h>

void linear_least_squares(const double x[], const double y[], int n, double *m, double *c)
{
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;

    printf("-----------------------------------------------\n");
    printf("|   x   |   y   |   x^2   |   xy    |\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        double x2 = x[i] * x[i];
        double xy = x[i] * y[i];
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += xy;
        sum_x2 += x2;

        printf("| %5.2f | %5.2f | %7.2f | %7.2f |\n", x[i], y[i], x2, xy);
    }

    printf("-----------------------------------------------\n");
    printf("| Sum   | %5.2f | %7.2f | %7.2f |\n", sum_y, sum_x2, sum_xy);
    printf("-----------------------------------------------\n");

    double denominator = n * sum_x2 - sum_x * sum_x;
    if (denominator == 0)
    {
        fprintf(stderr, "Error: Denominator is zero. Cannot compute linear fit.\n");
        *m = 0;
        *c = 0;
        return;
    }

    *m = (n * sum_xy - sum_x * sum_y) / denominator;
    *c = (sum_y * sum_x2 - sum_x * sum_xy) / denominator;
}

int main()
{
    int n;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input arrays for x and y
    double x[n], y[n];

    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
    }

    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    double m, c;
    linear_least_squares(x, y, n, &m, &c);

    printf("\nBest-fit line: y = %.2fx + %.2f\n", m, c);

    return 0;
}


// x: 1 2 3 4 5 6 
// y : 1200 900 600 200 110 50 


