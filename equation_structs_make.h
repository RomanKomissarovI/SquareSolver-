#ifndef EQUATION_STRUCTS_MAKE_H
#define EQUATION_STRUCTS_MAKE_H

#include "structs_of_equation.h"

void CoeffsCtor(Coeffs* coeffs, double a, double b, double c);
Coeffs MakeCoeffs(double a, double b, double c);
void SolutionCtor(Solution* solution, double x1, double x2, RootsCount nroots);
Solution MakeSolution(double x1, double x2, RootsCount nroots);

#endif // EQUATION_STRUCTS_MAKE_H
