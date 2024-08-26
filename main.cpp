#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "structs_of_equation.h"
#include "testing.h"
#include "in_out.h"
#include "solve_equation.h"

static const int MAX_PATH_LEN = 257;
const int CMD_MODE = -999; // ������ �� cmd
// char buffer[] <--- input. sscanf(); Check Errors!
// Readme internet
// Сделать цветной вывод escape ansi sequences
// %e - включать/отключать экспоненциальный вывод из консоли

int main(int argc, const char* argv[])
{
    //getopt
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
        printf("\033[3;32m Square Solver\n");
        printf("If you want to use file input, write 1. Else, write 0\n\033[0m");

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
                printf("\033[3;32m Write the path to the file (or it`s name, if the file in the directory of the programm)\n\033[0m");

                char s[MAX_PATH_LEN] = {0};
                FlushInput();
                fgets(s, MAX_PATH_LEN, stdin); // TODO check error

                FILE* f = fopen(s, "r");
                
                if (f == nullptr) {
                    perror("\033[3;31m Error file name\033[0m");
                    break;
                }

                if (!ReadFileEquation(&equation, f)) {
                    SolveAndOut(&equation);
                }
                break;
            }
            default:
                printf("\033[3;31m Error mode\n\033[0m");
                return 1;
                break;
        }
    }

    return 0;
}
