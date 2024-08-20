#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
//#define
// #ifdef #if
// macros?
// #include
// -E

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

void getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == 'n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}

struct equation make_equation() {
    struct equation p;
    printf("Square Solver\n");
    printf("If you want to use file input, write 1. Else, write 0\n");
    char r = '0';
    scanf("%c", &r);
    if (r == '0') {
        printf("Enter the a, b, c:\n");
        scanf("%lf %lf %lf", &p.c.a, &p.c.b, &p.c.c);
    }
    else if (r == '1') {
        //printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");
        //char s[300];
        //getline(s, 256);
        //printf("%s\n\nqqqqq\n\n", s);

        FILE* f = fopen("input.txt", "r");
        fscanf(f, "%lf %lf %lf", &p.c.a, &p.c.b, &p.c.c);
        fclose(f);
    }
    return p;
}

bool IsZero(double x) {
    return fabs(x) <= EPS;
}

RootsCount solve(struct coeffs c, struct solution* s) {// const struct coeffs* coeffs, struct solution* solution
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

// ./program arg1 arg2
int main()
{
    equation Q;
    Q = make_equation();
    Q.s.nroot = solve(Q.c, &Q.s);
    output(Q.s);
    return 0;
}
