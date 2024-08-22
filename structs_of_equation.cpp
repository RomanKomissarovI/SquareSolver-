#ifndef STRUCTS_OF_EQUATION_CPP
#define STRUCTS_OF_EQUATION_CPP

#include <assert.h>

struct coeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

void coeffs_ctor(coeffs* cf, double a, double b, double c) {
    assert(cf != nullptr);
    cf->a = a;
    cf->b = b;
    cf->c = c;
}

struct coeffs make_coeffs(double a, double b, double c) {
    struct coeffs cf;
    cf.a = a;
    cf.b = b;
    cf.c = c;
    return cf;
}

enum RootsCount {
    InfRoots  = -1, // Бесконечное количество корней
    OneRoots  = 1,
    TwoRoots  = 2,
    ZeroRoots = 0,
    NOT_SOLVE = -999, // ещё не решали
};

struct solution {
    double x1 = 0;
    double x2 = 0;
    RootsCount nroot = NOT_SOLVE;
};

void solution_ctor(solution* sol, double x1, double x2, RootsCount nroots) {
    assert(sol != nullptr);
    sol->x1 = x1;
    sol->x2 = x2;
    sol->nroot = nroots;
}

struct solution make_solution(double x1, double x2, RootsCount nroots) {
    struct solution sol;
    sol.x1 = x1;
    sol.x2 = x2;
    sol.nroot = nroots;
    return sol;
}

struct equation { // equation
    struct coeffs c;
    struct solution s;
};

#endif
