#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs_of_equation.h"
#include "testing.h"
#include "in_out.h"
#include "solve_equation.h"

static const int MAX_PATH_LEN = 257;
const int CMD_MODE = -999; // запрос из cmd
// tests from file
// argc argv --- аргументы командной строки
// char buffer[] <--- input. sscanf(); Check Errors!
// g++ in console. In Windows .bat files. internet
// Doxygen
// Readme internet

int main(int argc, const char* argv[])
{
    Equation equation;

    if (argc >= 2) {
        if (!strcmp(argv[1], "tests")) {
            RunAllTests();
        }
        else if (!strcmp(argv[1], "--file")) {

            if (argc >= 3) {
                TestFileEquation(argv[2]);
            }
            else {
                printf("Error input data\n");
            }
        }
    }
    else {
        printf("Square Solver\n");
        printf("If you want to use file input, write 1. Else, write 0\n");

        char mode = '0';
        scanf("%c", &mode);

        switch(mode) {
            case '0':
                if (!ReadConsoleEquation(&equation)) {
                    SolveAndOut(&equation);
                }
                break;
            case '1':
            {
                printf("Write the path to the file (or it`s name, if the file in the directory of the programm)\n");

                char s[MAX_PATH_LEN] = {0};
                scanf("%s", s);

                FILE* f = fopen(s, "r");

                FlushInput();
                if (!ReadFileEquation(&equation, f)) {
                    SolveAndOut(&equation);
                }
                break;
            }
            default:
                printf("Error mode\n");
                return 1;
                break;
        }
    }

    return 0;
}
