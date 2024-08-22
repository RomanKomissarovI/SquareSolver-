#ifndef SOLVE_EQUATION_CPP
#define SOLVE_EQUATION_CPP

#include <assert.h>
#include "structs_of_equation.cpp"
#include <math.h>

static const double EPS = 10e-5; // погрешность

bool IsZero(double x) {
    return fabs(x) <= EPS;
}

RootsCount solve_square_eq(struct coeffs* c, struct solution* s) {// const struct coeffs* coeffs, struct solution* solution
    assert(s != nullptr);
    assert(c != nullptr);
    if (IsZero(c->a)){
        if (IsZero(c->b)) {
            return (IsZero(c->c)) ? InfRoots : ZeroRoots;
        }
        s->x1 = s->x2 = -c->c / c->b;
        return OneRoots;
    }

    double d = c->b * c->b - 4 * c->a * c->c;
    if (IsZero(d)) {
        s->x1 = s->x2 = -c->b / 2 / c->a; // d == 0
        return OneRoots;
    }
    if (d < 0){
        return ZeroRoots;
    }
    else{
        double sqr_discr = sqrt(d);
        s->x1 = (-c->b - sqr_discr) / 2 / c->a;
        s->x2 = (-c->b + sqr_discr) / 2 / c->a;
        return TwoRoots;
    }
}
#endif
