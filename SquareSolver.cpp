#include <stdio.h>
#include <math.h>

const int SS_INF_CASE = -1; // Бесконечное количество корней

int SquareSolver(double a, double b, double c, double* x1, double* x2)
{
    if (a == 0){
        if (b == 0){
            return (c == 0) ? SS_INF_CASE : 0;
        }
        *x1 = *x2 = -c / b;
        return 1;
    }

    double d = b * b - 4 * a * c;
    if (d < 0){
        return 0;
    }
    else{
        double sqr_discr = sqrt(d);
        if (d > 0){
            *x1 = (-b - sqr_discr) / 2 / a;
            *x2 = (-b + sqr_discr) / 2 / a;
            return 2;
        }
        *x1 = *x2 = (-b - sqr_discr) / 2 / a; // d == 0
        return 1;
    }
}

int main()
{
    printf("Square Solver\nEnter the a, b, c:\n");

    double a = 0;
    double b = 0;
    double c = 0;

    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0;
    double x2 = 0;
    int nroot = SquareSolver(a, b, c, &x1, &x2);

    switch (nroot){
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("One root: x = %lg\n", x1);
            break;
        case 2:
            printf("Two roots: x1 = %lg;  x2 = %lg\n", x1, x2);
            break;
        case SS_INF_CASE:
            printf("Infinity number of roots\n");
            break;
        default:
            printf("SS_main() Error");
    }

    return 0;
}
