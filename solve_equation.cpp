#include <assert.h>
#include <math.h>

#include "structs_of_equation.h"
#include "solve_equation.h"

static const double EPS = 10e-5;

bool IsZero(double x) {
    return fabs(x) <= EPS;
}

RootsCount SolveSquareEquation(Coeffs* coeffs, Solution* solution) {
    assert(solution != nullptr);
    assert(coeffs != nullptr);

    if (IsZero(coeffs->a)){
        if (IsZero(coeffs->b)) {
            return (IsZero(coeffs->c)) ? InfRoots : ZeroRoots;
        }

        solution->x1 = solution->x2 = -coeffs->c / coeffs->b;
        return OneRoots;
    }

    double d = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;
    if (IsZero(d)) {
        solution->x1 = solution->x2 = -coeffs->b / 2 / coeffs->a; // d == 0
        return OneRoots;
    }

    if (d < 0){
        return ZeroRoots;
    }
    else{
        double sqr_discr = sqrt(d);
        solution->x1 = (-coeffs->b - sqr_discr) / 2 / coeffs->a;
        solution->x2 = (-coeffs->b + sqr_discr) / 2 / coeffs->a;

        return TwoRoots;
    }
}
