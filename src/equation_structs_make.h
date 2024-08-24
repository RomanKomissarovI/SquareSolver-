/**
  \file
*/

#ifndef EQUATION_STRUCTS_MAKE_H
#define EQUATION_STRUCTS_MAKE_H

#include "structs_of_equation.h"

/**
    \brief Write the coefficients to the struct Coeffs
    \param[in,out] coeffs ptr to struct Coeffs
    \param[in] a the coefficient a
    \param[in] b the coefficient b
    \param[in] c the coefficient c
*/

void CoeffsCtor(Coeffs* coeffs, double a, double b, double c);

/**
    \brief Make a struct Coeffs from coefficients-arguments
    \param[in] a the coefficient a
    \param[in] b the coefficient b
    \param[in] c the coefficient c
    \return struct coeffs with given values
*/

Coeffs MakeCoeffs(double a, double b, double c);

/**
    \brief Write the solution to the struct Solution
    \param[in,out] solution ptr to struct Solution
    \param[in] x1 the first root
    \param[in] x2 the second root
    \param[in] nroots the number of roots
*/

void SolutionCtor(Solution* solution, double x1, double x2, RootsCount nroots);

/**
    \brief Make a struct Solution from arguments
    \param[in] x1 the first root
    \param[in] x2 the second root
    \param[in] nroots the number of roots
    \return struct Solution with given values
*/

Solution MakeSolution(double x1, double x2, RootsCount nroots);

#endif // EQUATION_STRUCTS_MAKE_H
