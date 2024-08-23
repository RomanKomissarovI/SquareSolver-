#ifndef IN_OUT_CPP
#define IN_OUT_CPP

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs_of_equation.cpp"

static const int MAX_PATH_LEN = 257;

bool CheckCorrect(char s[]) {
    bool point = false;
    int i = 0;
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '.') {
            if (point == true || i == 0 || s[i + 1] == '\0') {
                return false;
            }
            point = true;
        }
        else if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void ReadConsoleEquation(Equation* equation) {
    assert(equation != nullptr);
    printf("Enter the a, b, c:\n");
    char s_a[100] = {0};
    char s_b[100] = {0};
    char s_c[100] = {0};
    if (scanf("%s %s %s", s_a, s_b, s_c) != 3) {
        printf("Error input data\n");
    }
    else if (!CheckCorrect(s_a) || !CheckCorrect(s_b) || !CheckCorrect(s_c)) {
        printf("Error input data\n");
    }
    else {
        equation->coeffs.a = atof(s_a);
        equation->coeffs.b = atof(s_b);
        equation->coeffs.c = atof(s_c);
    }
}

void ReadFileEquation(Equation* equation) {
    assert(equation != nullptr);
    printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");
    char s[MAX_PATH_LEN] = {0};
    scanf("%s", s);

    FILE* f = fopen(s, "r");

    char s_a[100] = {0};
    char s_b[100] = {0};
    char s_c[100] = {0};
    if (fscanf(f, "%s %s %s", s_a, s_b, s_c) != 3) {
        printf("Error input data\n");
    }
    else if (!CheckCorrect(s_a) || !CheckCorrect(s_b) || !CheckCorrect(s_c)) {
        printf("Error input data\n");
    }
    else {
        equation->coeffs.a = atof(s_a);
        equation->coeffs.b = atof(s_b);
        equation->coeffs.c = atof(s_c);
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
