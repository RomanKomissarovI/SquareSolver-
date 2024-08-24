#ifndef IN-OUT_CPP
#define IN-OUT_CPP

#include <stdio.h>
#include <assert.h>
#include "structs_of_equation.cpp"

static const int MAX_PATH_LEN = 257;


void read_console_eq(struct equation* Q) {
    assert(Q != nullptr);
    printf("Enter the a, b, c:\n");      // ReadCoeffsInteractive
    if (scanf("%lf %lf %lf", &(Q->c.a), &(Q->c.b), &(Q->c.c)) != 3) {
        printf("Error input data\n");
    }
}

void read_file_eq(struct equation* Q) {
    assert(Q != nullptr);
    printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");
    char s[MAX_PATH_LEN] = {0};
    scanf("%s", &s);

    FILE* f = fopen(s, "r");       // ReadCoeffsFile
    if (fscanf(f, "%lf %lf %lf", &(Q->c.a), &(Q->c.b), &(Q->c.c)) != 3) {
        printf("Error input data\n");
    }
    fclose(f);
}

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
#endif
