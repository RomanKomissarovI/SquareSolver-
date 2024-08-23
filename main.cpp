#include <stdio.h>
#include <string.h>
#include "in_out.cpp"
#include "solve_equation.cpp"
#include "testing.cpp"

const int CMD_MODE = -999; // запрос из cmd
// tests from file
// argc argv --- аргументы командной строки
// char buffer[] <--- input. sscanf(); Check Errors!
// g++ in console. In Windows .bat files. internet
// Doxygen

void FlushInput() {       // уничтожение символов до конца строки
    int c = getchar();

    //EOF? char c = (char)getchar
    while (c != '\n' && c != EOF)
        c = getchar();
        printf("%c", c);
}

int main(int argc, const char* argv[])
{
    Equation equation;
    if (argc >= 2) {
        if (!strcmp(argv[1], "tests")) {
            RunAllTests();
        }
        else if (!strcmp(argv[1], "--file")) {
            Equation equation;
            if (argc >= 3) {
                TestFileEquation(argv[2]);
            }
            else
                printf("Error input data\n");
        }
    }
    else {
        printf("Square Solver\n");
        printf("If you want to use file input, write 1. Else, write 0\n");
        char mode = '0';
        scanf("%c", &mode);

        switch(mode) {
            case '0':
                ReadConsoleEquation(&equation);
                break;
            case '1':
                FlushInput();
                ReadFileEquation(&equation);
                break;
            default:
                printf("Error mode\n");
                return 1;
                break;
        }

        equation.solution.nroot = SolveSquareEquation(&equation.coeffs, &equation.solution);
        OutputSolution(&equation.solution);
    }
    return 0;
}
