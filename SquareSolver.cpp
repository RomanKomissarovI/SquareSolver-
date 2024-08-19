#include <stdio.h>
#include <math.h>

void qvad(double a, double b, double c)
{
    if (a == 0){
        if (b == 0){
            if (c == 0){
                printf("Infinity\n");
            }
            else{
                printf("None\n");
            }
        }
        else{
            printf("%lf\n", (-c) / b);
        }
    }
    else{
        double d = b * b - 4 * a * c;
        if (d > 0){
            printf("%lf\n", (-b - sqrt(d)) / 2 / a);
            printf("%lf\n", (-b + sqrt(d)) / 2 / a);
        }
        else if (d == 0){
            printf("%lf\n", (-b - sqrt(d)) / 2 / a);
        }
        else{
            printf("None\n");
        }
    }
}

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    qvad(a, b, c);
    return 0;
}
