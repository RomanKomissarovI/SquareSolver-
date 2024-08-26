#include <stdio.h>
#include <assert.h>

//#include "structs_of_equation.h"
#include "equation_structs_make.h"
#include "solve_equation.h"
#include "testing.h"

static int RunTest(int nTest, Coeffs* coeffs, Solution* solution_ok);

static int RunTest(int nTest, Coeffs* coeffs, Solution* solution_ok) {
    assert(coeffs != nullptr);
    assert(solution_ok != nullptr);

    Solution solution;
    solution.x1 = solution.x2 = 0;
    solution.nroot = SolveSquareEquation(coeffs, &solution);

    if (solution.nroot != solution_ok->nroot
        || !IsZero(solution.x1 - solution_ok->x1)
        || !IsZero(solution.x2 - solution_ok->x2)) {

        printf("\033[3;31m Error Test %d: a = %lg; b = %lg; c = %lg; nroots = %d; x1 = %lg; x2 = %lg\n"
               "Expected values: nroots = %d; x1 = %lg; x2 = %lg\n\033[0m",
               nTest, coeffs->a, coeffs->b, coeffs->c, solution.nroot, solution.x1, solution.x2,
               solution_ok->nroot, solution_ok->x1, solution_ok->x2);

        return nTest;
    }

    return 0;
}

// tests from file
// 1 2 3 2 -4 -5.23
// 4 2 4 2 -7 3.09
void RunAllTests() {
    Coeffs tests[] = {{0, 0, 0},  MakeCoeffs(0, 0, 5),
                      MakeCoeffs(0, 5, 0),  MakeCoeffs(5, 0, 0),
                      MakeCoeffs(2, 0, -8), MakeCoeffs(4, 8, 0),
                      MakeCoeffs(0, 4, -8), MakeCoeffs(1, 1, 1),
                      MakeCoeffs(1, 2, 1),  MakeCoeffs(4, 8, 4)};

    Solution solution_ok[] = {MakeSolution(0, 0, InfRoots),   MakeSolution(0, 0, ZeroRoots),
                              MakeSolution(0, 0, OneRoots),   MakeSolution(0, 0, OneRoots),
                              MakeSolution(-2, 2, TwoRoots),  MakeSolution(-2, 0, TwoRoots),
                              MakeSolution(2, 2, OneRoots),   MakeSolution(0, 0, ZeroRoots),
                              MakeSolution(-1, -1, OneRoots), MakeSolution(-1, -1, OneRoots)};

    int error = 0;
    int num_of_tests = sizeof(tests) / sizeof(tests[0]);
    for(int i = 0; i < num_of_tests; ++i) {  // sizeof / size of elem
        error |= RunTest(i + 1, &tests[i], &solution_ok[i]);
    }

    if (!error)
        printf("\033[3;32m Testing completed successfully\n\033[0m");
}

void TestFileEquation(const char* path_file) {
    assert(path_file != nullptr);

    Coeffs coeffs; // init
    Solution solution;

    FILE* f = fopen(path_file, "r");

    int i = 0;
    int eof = 0; // -1????
    while (1) {  // while (true) for ( ;; ) for()????
        int nroot = 0;
        if ((eof = fscanf(f, "%lf %lf %lf %lf %lf %d", &coeffs.a, &coeffs.b, &coeffs.c,
                          &solution.x1, &solution.x2, &nroot)) != 6) {
            if (!eof)
                printf("\033[3;31m Error input data\n\033[0m");
            break;
        }
        solution.nroot = (RootsCount)nroot;

        if (!RunTest(i + 1, &coeffs, &solution))
            printf("\033[3;32m OK\n\033[0m");
        ++i;
    }

    fclose(f);
}
