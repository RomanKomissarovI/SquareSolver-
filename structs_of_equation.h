#ifndef STRUCTS_OF_EQUATION_h
#define STRUCTS_OF_EQUATION_h


struct Coeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

enum RootsCount {
    InfRoots  = -1, // Бесконечное количество корней
    OneRoots  = 1,
    TwoRoots  = 2,
    ZeroRoots = 0,
    NotSolve = -999,
};

struct Solution {
    double x1 = 0;
    double x2 = 0;
    RootsCount nroot = NotSolve;
};

struct Equation {
    struct Coeffs coeffs;
    struct Solution solution;
};
#endif // STRUCTS_OF_EQUATION_h
