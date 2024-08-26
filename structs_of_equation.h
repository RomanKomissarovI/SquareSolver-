/**
  \file
*/

#ifndef STRUCTS_OF_EQUATION_h
#define STRUCTS_OF_EQUATION_h

#include <assert.h>

/**
    Coefficients of the equation
*/

struct Coeffs {
    double a;
    double b;
    double c;
};
/**
    Possible options Solution.nroot
*/
enum RootsCount {
    InfRoots  = -1, ///< infinity number roots
    OneRoots  = 1,  ///< one root
    TwoRoots  = 2,  ///< two roots
    ZeroRoots = 0,  ///< zero roots
    NotSolve = -999,///< the equation hasn`t solved yet
};

/**
    Solution of the equation
*/

struct Solution {
    double x1;               ///< the first root
    double x2;               ///< the second root
    RootsCount nroot;        ///< number of roots
};

/**
    Equation
*/

struct Equation {
    struct Coeffs coeffs;        ///< the coefficients
    struct Solution solution;    ///< the solution
};
#endif // STRUCTS_OF_EQUATION_h
