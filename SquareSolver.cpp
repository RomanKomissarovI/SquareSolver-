#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
//#define
// #ifdef #if
// macros?
// #include
// -E

// $ print __LINE__ __FILE__ ....
// .cpp __LINE__ -E

#if defined(DEBUG)
#define $ printf("%d\n%s\n", __LINE__, __FILE__);
#else
#define $ ;
#endif

//#define DEBUG
//$ ---> ;


const double EPS = 10e-5; // погрешность

struct coeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

enum RootsCount {
    InfRoots = -1, // Бесконечное количество корней
    OneRoots = 1,
    TwoRoots = 2,
    ZeroRoots = 0,
    NOT_SOLVE = -999, // ещё не решали
};

struct solution {
    double x1 = 0;
    double x2 = 0;
    RootsCount nroot = NOT_SOLVE;
};

struct equation { // equation
    struct coeffs c;
    struct solution s;
};

void get_file_name(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = (char)c;
    }
    s[i] = '\0';
}

void flush_input() {
    char c = '5';
    c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
        printf("%c", c);
}

struct equation read_equation() {
    struct equation p;
    printf("Square Solver\n");
    printf("If you want to use file input, write 1. Else, write 0\n");
    char r = '0';
    scanf("%c", &r);
    flush_input(); // flush_input() { while '\n'}
    if (r == '0') {
        printf("Enter the a, b, c:\n");      // ReadCoeffsInteractive
        scanf("%lf %lf %lf", &p.c.a, &p.c.b, &p.c.c);
    }
    else if (r == '1') {
        printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");
        char s[300] = {0};
        get_file_name(s, 256);

        FILE* f = fopen(s, "r");       // ReadCoeffsFile
        fscanf(f, "%lf %lf %lf", &p.c.a, &p.c.b, &p.c.c);
        fclose(f);
    }
    return p;
}

struct coeffs make_coeffs(double a, double b, double c) {
    struct coeffs p;
    p.a = a;
    p.b = b;
    p.c = c;
    return p;
}

struct solution make_solution(double x1, double x2, RootsCount nroots) {
    struct solution p;
    p.x1 = x1;
    p.x2 = x2;
    p.nroot = nroots;
    return p;
}

bool IsZero(double x) {
    return fabs(x) <= EPS;
}

RootsCount solve_squar_eq(struct coeffs c, struct solution* s) {// const struct coeffs* coeffs, struct solution* solution
    if (IsZero(c.a)){
        if (IsZero(c.b)) {
            return (fabs(c.c) <= EPS) ? InfRoots : ZeroRoots;
        }
        s->x1 = s->x2 = -c.c / c.b;
        return OneRoots;
    }

    double d = c.b * c.b - 4 * c.a * c.c;
    if (d < 0){
        return ZeroRoots;
    }
    else{
        double sqr_discr = sqrt(d);
        if (d > EPS){
            s->x1 = (-c.b - sqr_discr) / 2 / c.a;
            s->x2 = (-c.b + sqr_discr) / 2 / c.a;
            return TwoRoots;
        }
        s->x1 = s->x2 = (-c.b - sqr_discr) / 2 / c.a; // d == 0
        return OneRoots;
    }
}

void output(struct solution s) {
    switch (s.nroot){
    case ZeroRoots:
        printf("No roots\n");
        break;
    case OneRoots:
        printf("One root: x = %lg\n", s.x1);
        break;
    case TwoRoots:
        printf("Two roots: x1 = %lg;  x2 = %lg\n", s.x1, s.x2);
        break;
    case InfRoots:
        printf("Infinity number of roots\n");
        break;
    default:
        printf("SS_main() Error");
        break;
    }
}

int RunTest(int nTest, struct coeffs c, struct solution s_ok) {
    struct solution s;
    s.x1 = s.x2 = 0;
    s.nroot = solve_squar_eq(c, &s);
    if (s.nroot != s_ok.nroot || s.x1 != s_ok.x1 || s.x2 != s_ok.x2) {
        printf(" Error Test %d: a = %lg; b = %lg; c = %lg; nroots = %d; x1 = %lg; x2 = %lg\n"
               "Expected values: nroots = %d; x1 = %lg; x2 = %lg\n",
               nTest, c.a, c.b, c.c, s.nroot, s.x1, s.x2,
               s_ok.nroot, s_ok.x1, s_ok.x2);
        return nTest;
    }
    return 0;
}

void Total_Testing() {
    struct coeffs tests[] = {make_coeffs(0, 0, 0), make_coeffs(0, 0, 5),
                               make_coeffs(0, 5, 0), make_coeffs(5, 0, 0),
                               make_coeffs(2, 0, -8), make_coeffs(4, 8, 0),
                               make_coeffs(0, 4, -8), make_coeffs(1, 1, 1),
                               make_coeffs(1, 2, 1), make_coeffs(4, 8, 4)};
    struct solution s_ok[] = {make_solution(0, 0, InfRoots), make_solution(0, 0, ZeroRoots),
                              make_solution(0, 0, OneRoots), make_solution(0, 0, OneRoots),
                              make_solution(-2, 2, TwoRoots), make_solution(-2, 0, TwoRoots),
                              make_solution(2, 2, OneRoots), make_solution(0, 0, ZeroRoots),
                              make_solution(-1, -1, OneRoots), make_solution(-1, -1, OneRoots)};
    for(int i = 0; i < 10; ++i) {
        RunTest(i + 1, tests[i], s_ok[i]);
    }
}

// ./program arg1 arg2
int main()
{
    equation Q;
    Q = read_equation(); // read_equation / input_coeffs
    Q.s.nroot = solve_squar_eq(Q.c, &Q.s);
    output(Q.s);
    return 0;
}
