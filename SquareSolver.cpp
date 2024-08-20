#include <stdio.h>
#include <math.h>
#include <assert.h>

const int SS_INF_CASE = -1; // Ѕесконечное количество корней
const double EPS = 10e-5; // погрешность

struct coeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

enum RootsCount {
    InfRoots = -1,
    OneRoots = 1,
    TwoRoots = 2,
    ZeroRoots = 0,
    NOT_SOLVE = -999,
};

struct solution {
    double x1 = 0;
    double x2 = 0;
    int nroot = NOT_SOLVE;
};

struct pair {
    struct coeffs c;
    struct solution s;
};

struct pair make_pair() {
    struct pair p;
    printf("Square Solver\nEnter the a, b, c:\n");
    scanf("%lf %lf %lf", &p.c.a, &p.c.b, &p.c.c);

    p.s.x1 = 0;
    return p;
}

int solve(struct coeffs c, struct solution* s) {// const struct coeffs* coeffs, struct solution* solution
    //assert((s->x1) != NULL);
    //assert(s->x2 != NULL);
    //assert(s->x1 != s->x2);

    if (fabs(c.a) <= EPS){
        if (fabs(c.b) <= EPS) {
            return (fabs(c.c) <= EPS) ? SS_INF_CASE : 0;
        }
        s->x1 = s->x2 = -c.c / c.b;
        return 1;
    }

    double d = c.b * c.b - 4 * c.a * c.c;
    if (d < 0){
        return 0;
    }
    else{
        double sqr_discr = sqrt(d);
        if (d > EPS){
            s->x1 = (-c.b - sqr_discr) / 2 / c.a;
            s->x2 = (-c.b + sqr_discr) / 2 / c.a;
            return 2;
        }
        s->x1 = s->x2 = (-c.b - sqr_discr) / 2 / c.a; // d == 0
        return 1;
    }
}

void output(struct coeffs c, struct solution* s) {
    if (s->nroot == NOT_SOLVE) {
        s->nroot = (RootsCount) solve(c, s);
    }
    int root = s->nroot;
    switch (root){
    case 0:
        printf("No roots\n");
        break;
    case 1:
        printf("One root: x = %lg\n", s->x1);
        break;
    case 2:
        printf("Two roots: x1 = %lg;  x2 = %lg\n", s->x1, s->x2);
        break;
    case SS_INF_CASE:
        printf("Infinity number of roots\n");
        break;
    default:
        printf("SS_main() Error");
        break;
    }
}

int main()
{
    pair Q;
    Q = make_pair();
    output(Q.c, &Q.s);
    return 0;
}
