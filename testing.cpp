#ifndef TESTING_CPP
#define TESTING.CPP

#include <assert.h>
#include "solve_equation.cpp"

int runtest(int nTest, struct coeffs* c, struct solution* s_ok) {
    assert(c != nullptr);
    assert(s_ok != nullptr);
    struct solution s;
    s.x1 = s.x2 = 0;
    s.nroot = solve_square_eq(c, &s);
    if (s.nroot != s_ok->nroot || s.x1 != s_ok->x1 || s.x2 != s_ok->x2) {
        printf("Error Test %d: a = %lg; b = %lg; c = %lg; nroots = %d; x1 = %lg; x2 = %lg\n"
               "Expected values: nroots = %d; x1 = %lg; x2 = %lg\n",
               nTest, c->a, c->b, c->c, s.nroot, s.x1, s.x2,
               s_ok->nroot, s_ok->x1, s_ok->x2);
        return nTest;
    }
    return 0;
}

void total_testing() {
    struct coeffs tests[] = {make_coeffs(0, 0, 0),  make_coeffs(0, 0, 5),
                             make_coeffs(0, 5, 0),  make_coeffs(5, 0, 0),
                             make_coeffs(2, 0, -8), make_coeffs(4, 8, 0),
                             make_coeffs(0, 4, -8), make_coeffs(1, 1, 1),
                             make_coeffs(1, 2, 1),  make_coeffs(4, 8, 4)};
    struct solution s_ok[] = {make_solution(0, 0, InfRoots),   make_solution(0, 0, ZeroRoots),
                              make_solution(0, 0, OneRoots),   make_solution(0, 0, OneRoots),
                              make_solution(-2, 2, TwoRoots),  make_solution(-2, 0, TwoRoots),
                              make_solution(2, 2, OneRoots),   make_solution(0, 0, ZeroRoots),
                              make_solution(-1, -1, OneRoots), make_solution(-1, -1, OneRoots)};
    int error = 0, num_of_tests = sizeof(tests) / sizeof(tests[0]);
    for(int i = 0; i < num_of_tests; ++i) {  // sizeof / size of elem
        error = runtest(i + 1, &tests[i], &s_ok[i]);
    }
    if (!error)
        printf("Testing completed successfully\n");
}
#endif
