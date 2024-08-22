#ifndef STRUCTS_OF_EQUATION_CPP
#define STRUCTS_OF_EQUATION_CPP

#include <assert.h>

struct Coeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

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

enum RootsCount {
    InfRoots  = -1, // Бесконечное количество корней
    OneRoots  = 1,
    TwoRoots  = 2,
    ZeroRoots = 0,
    NotSolve = -999, // ещё не решали    --> caps???
};

struct Solution {
    double x1 = 0;
    double x2 = 0;
    RootsCount nroot = NotSolve;
};

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

struct Equation { // equation
    struct Coeffs coeffs; // Coeffs coeffs;         equation.coeffs.a = 2;
    struct Solution solution;
};

#endif // STRUCTS_OF_EQUATION_CPP
