#ifndef IN_OUT_H
#define IN_OUT_H

#include "structs_of_equation.h"
void FlushInput();
bool ReadConsoleEquation(Equation* equation);
bool ReadFileEquation(Equation* equation, FILE* f);
void OutputSolution(Solution* solution);
void SolveAndOut(Equation* equation)

#endif // IN_OUT_H
