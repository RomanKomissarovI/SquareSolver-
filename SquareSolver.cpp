#include <stdio.h>
#include <math.h>

#define NDEBUG
#include <assert.h>
#include <string.h>
//#define
// #ifdef #if
// macros?
// #include
// -E

// $ print __LINE__ __FILE__ ....
// .cpp __LINE__ -E

//#define MY_NDEBUG
// assert(expr)
// if (expr == false) { print ....; exit(1); }
//void assert() {}.
//define assert ;

#if defined(MY_NDEBUG)
#define my_assert(a) if (!(a)) { \
        printf("Error in %s\n line = %d\n", __FILE__, __LINE__);  \
        printf("%s", 1);      \
     }
#else
#define my_assert(a)
#endif

#if defined(DEBUG)
#define $ printf("%d\n%s\n", __LINE__, __FILE__);
#else
#define $ ;
#endif

//#define DEBUG
//$ ---> ;

const int MAX_PATH_LEN = 257;
const double EPS = 10e-5; // погрешность

struct coeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

enum RootsCount {
    InfRoots  = -1, // Бесконечное количество корней
    OneRoots  = 1,
    TwoRoots  = 2,
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

void flush_input() {       // уничтожение символов до конца строки
    char c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
        printf("%c", c);
}

// struct equation* eq
void read_console_eq(struct equation* Q) {
    assert(Q != nullptr);
    printf("Enter the a, b, c:\n");      // ReadCoeffsInteractive
    scanf("%lf %lf %lf", &(Q->c.a), &(Q->c.b), &(Q->c.c));
}

void read_file_eq(struct equation* Q) {
    assert(Q != nullptr);
    printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");
    char s[MAX_PATH_LEN] = {0};
    scanf("%s", &s);

    FILE* f = fopen(s, "r");       // ReadCoeffsFile
    fscanf(f, "%lf %lf %lf", &(Q->c.a), &(Q->c.b), &(Q->c.c));
    fclose(f);
}

// CoeffsCtor  constructor
void coeffs_ctor(coeffs* cf, double a, double b, double c) {
    assert(cf != nullptr);
    cf->a = a;
    cf->b = b;
    cf->c = c;
}

struct coeffs make_coeffs(double a, double b, double c) {
    struct coeffs cf;
    cf.a = a;
    cf.b = b;
    cf.c = c;
    return cf;
}

// solution_ctor( solution* sol, double x1, double x2);
void solution_ctor(solution* sol, double x1, double x2, RootsCount nroots) {
    assert(sol != nullptr);
    sol->x1 = x1;
    sol->x2 = x2;
    sol->nroot = nroots;
}

struct solution make_solution(double x1, double x2, RootsCount nroots) {
    struct solution sol;
    sol.x1 = x1;
    sol.x2 = x2;
    sol.nroot = nroots;
    return sol;
}

bool IsZero(double x) {
    return fabs(x) <= EPS;
}
//
RootsCount solve_squar_eq(struct coeffs c, struct solution* s) {// const struct coeffs* coeffs, struct solution* solution
    assert(s != nullptr);
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

// struct solution* s = nullptr; (NULL == 0)
// ...
// ...
// ...
// output(s);
void output(struct solution* s) {
    assert(s != nullptr);

    switch (s->nroot){
    case ZeroRoots:
        printf("No roots\n");
        break;
    case OneRoots:
        printf("One root: x = %lg\n", s->x1);
        break;
    case TwoRoots:
        printf("Two roots: x1 = %lg;  x2 = %lg\n", s->x1, s->x2);
        break;
    case InfRoots:
        printf("Infinity number of roots\n");
        break;
    default:
        printf("SS_main() Error");
        break;
    }
}

int runtest(int nTest, struct coeffs c, struct solution s_ok) {
    struct solution s; //
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

void total_testing() {
    struct coeffs tests[] = {  make_coeffs(0, 0, 0),  make_coeffs(0, 0, 5),
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
        error = runtest(i + 1, tests[i], s_ok[i]);
        if (error)
            break;
    }
    if (!error)
        printf("Testing completed successfully\n");
}

// ./program arg1 arg2
int main()
{
    equation Q;
    printf("Square Solver\n");
    printf("If you want to use file input, write 1. Else, write 0\n");
    char r = '0';
    scanf("%c", &r);

    switch(r) {
        case '0':
            read_console_eq(&Q);
            break;
        case '1':
            flush_input();
            read_file_eq(&Q);
            break;
        default:
            printf("Error mode\n");
            break;
    }

    // Q is valid???
    Q.s.nroot = solve_squar_eq(Q.c, &Q.s); //square
    output(&Q.s);
    return 0;
}
