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

    bool is_error = false;

    char s_coeffs[MAX_INPUT_LEN] = {0}; // ����������� �� ����� ������
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
        printf("Error input string: %s\n", s_coeffs);
    }

    fclose(f);
    return is_error;
}

bool ReadConsoleEquation(Equation* equation) {
    printf("Enter the a, b, c:\n");
    return ReadFileEquation(equation, stdin);
}

void OutputSolution(Solution* solution) {
    assert(solution != nullptr);

    switch (solution->nroot){
    case ZeroRoots:
        printf("No roots\n");
        break;
    case OneRoots:
        printf("One root: x = %lg\n", solution->x1);
        break;
    case TwoRoots:
        printf("Two roots: x1 = %lg;  x2 = %lg\n", solution->x1, solution->x2);
        break;
    case InfRoots:
        printf("Infinity number of roots\n");
        break;
    case NotSolve:
    default:
        printf("SS_main() Error");
        break;
    }
}

void SolveAndOut(Equation* equation) {
    equation->solution.nroot = SolveSquareEquation(&equation->coeffs, &equation->solution);
    OutputSolution(&equation->solution);
}
