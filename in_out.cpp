#ifndef IN_OUT_CPP
#define IN_OUT_CPP

#include <stdio.h>
#include <assert.h>
#include "structs_of_equation.cpp"

static const int MAX_PATH_LEN = 257;


void ReadConsoleEquation(Equation* equation) {
    assert(equation != nullptr);
    printf("Enter the a, b, c:\n");
    if (scanf("%lf %lf %lf", &(equation->coeffs.a), &(equation->coeffs.b), &(equation->coeffs.c)) != 3) {
        printf("Error input data\n");
    }
}

void ReadFileEquation(Equation* equation) {
    assert(equation != nullptr);
    printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");
    char s[MAX_PATH_LEN] = {0};
    scanf("%s", s);

    FILE* f = fopen(s, "r");
    if (fscanf(f, "%lf %lf %lf", &(equation->coeffs.a), &(equation->coeffs.b), &(equation->coeffs.c)) != 3) {
        printf("Error input data\n");
    }
    fclose(f);
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
#endif // IN_OUT_CPP
