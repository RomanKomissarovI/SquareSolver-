/**
  \file
*/

#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include "structs_of_equation.h"

/**
    \brief Write the roots of equation to the solution
    \param[in] coeffs coefficients of equation
    \param[in, out] solution solution of equation
    \return number of roots (solution.nroot)
*/

RootsCount SolveSquareEquation(Coeffs* coeffs, Solution* solution);

/**
    \brief Check if the digit is Zero
    \param[in] x the digit
    \return true if zero, false else
*/

bool IsZero(double x);

#endif // SOLVE_EQUATION_H
