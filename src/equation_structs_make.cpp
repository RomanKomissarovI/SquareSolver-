#include "equation_structs_make.h"
#include <assert.h>

void CoeffsCtor(Coeffs* coeffs, double a, double b, double c) {
    assert(coeffs != nullptr);

    coeffs->a = a;
    coeffs->b = b;
    coeffs->c = c;
}

Coeffs MakeCoeffs(double a, double b, double c) {
    struct Coeffs coeffs;

    coeffs.a = a;
    coeffs.b = b;
    coeffs.c = c;

    return coeffs;
}

void SolutionCtor(Solution* solution, double x1, double x2, RootsCount nroots) {
    assert(solution != nullptr);

    solution->x1 = x1;
    solution->x2 = x2;
    solution->nroot = nroots;
}

Solution MakeSolution(double x1, double x2, RootsCount nroots) {
    struct Solution solution;
    solution.x1 = x1;
    solution.x2 = x2;
    solution.nroot = nroots;

    return solution;
}
