/**
  \file
*/

#ifndef IN_OUT_H
#define IN_OUT_H

#include "structs_of_equation.h"

/**
    Delete all symbols until the end of the string
*/

void FlushInput();

/**
    \brief Read an equation from stdin
    \param[in,out] equation input equation
    \return is error ?
*/

bool ReadConsoleEquation(Equation* equation);

/**
    \brief Read an equation from file
    \param[in,out] equation input equation
    \param [in] f The FILE ptr
    \return is error ?
*/

bool ReadFileEquation(Equation* equation, FILE* f);

/**
    \brief Write the roots in console
    \param[in,out] solution the solution
*/

void OutputSolution(Solution* solution);

/**
    \brief Write the roots in console
    \param[in,out] equation the equation
*/

void SolveAndOut(Equation* equation);

#endif // IN_OUT_H
