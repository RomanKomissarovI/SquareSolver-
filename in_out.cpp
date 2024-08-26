/**
  \file
*/ 

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "structs_of_equation.h"
#include "solve_equation.h"

#include "in_out.h"

static const int MAX_INPUT_LEN = 151;

/**
    \brief Read a string from file
    \param[out] s The input string
    \param[in] max_len Max len of the input string
    \param[in] f Name of file
    \return Len of the string
*/
static int GetLineFile(char s[], int max_len, FILE* f);

/**
    \brief Read a string from stdin
    \param[out] s The input string
    \param[in] max_len Max len of the input string
    \return Len of the string
*/
// int GetLine(char s[], int max_len);

void FlushInput() {       // ����������� �������� �� ����� ������
    int c = getchar();

    //EOF? char c = (char)getchar
    while (c != '\n' && c != EOF)
        c = getchar();
}

static int GetLineFile(char s[], int max_len, FILE* f) {
    int c, i;
    c = fgetc(f);
    for (i = 0; i < max_len && c != '\n' && c != EOF; ++i) {
        s[i] = (char)c;
        c = fgetc(f);
    }
    if (s[i] == '\n') {
        s[i++] = (char)c;
    }
    s[i] = '\0';
    return i;
}

bool ReadFileEquation(Equation* equation, FILE* f) {
    assert(equation != nullptr);
    assert(f != nullptr);

    bool is_error = false;

    char s_coeffs[MAX_INPUT_LEN] = {0}; 
    FlushInput();
    GetLineFile(s_coeffs, MAX_INPUT_LEN - 1, f);

    char* ptrEnd = nullptr;
    equation->coeffs.a = strtod(s_coeffs, &ptrEnd);
    if (*ptrEnd == '\0') {
        is_error = true;
    }

    equation->coeffs.b = strtod(ptrEnd, &ptrEnd);
    if (*ptrEnd == '\0') {
        is_error = true;
    }

    equation->coeffs.c = strtod(ptrEnd, &ptrEnd);
    if (*ptrEnd != '\0') {
        is_error = true;
    }

    if (is_error)
    {
        printf("\033[3;31m Error input string: %s\n\033[0m", s_coeffs);
    }

    fclose(f);
    return is_error;
}

bool ReadConsoleEquation(Equation* equation) {
    printf("\033[3;32m Enter the a, b, c in one string:\n\033[0m");
    return ReadFileEquation(equation, stdin);
}

void OutputSolution(Solution* solution) {
    assert(solution != nullptr);

    switch (solution->nroot){
    case ZeroRoots:
        printf("\033[3;32m No roots\n\033[0m");
        break;
    case OneRoots:
        printf("\033[3;32m One root: x = %lg\n\033[0m", solution->x1);
        break;
    case TwoRoots:
        printf("\033[3;32m Two roots: x1 = %lg;  x2 = %lg\n\033[0m", solution->x1, solution->x2);
        break;
    case InfRoots:
        printf("\033[3;32m Infinity number of roots\n\033[0m");
        break;
    case NotSolve:
    default:
        printf("\033[3;32m SS_main() Error\033[0m");
        break;
    }
}

void SolveAndOut(Equation* equation) {
    equation->solution.nroot = SolveSquareEquation(&equation->coeffs, &equation->solution);
    OutputSolution(&equation->solution);
}
