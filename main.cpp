#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "structs_of_equation.h"
#include "testing.h"
#include "in_out.h"
#include "solve_equation.h"
#include "color_print.h"

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
                ColorPrint(RedColor, "Error input data\n");
            }
        }
    }
    else {
        ColorPrint(GreenColor, "Square Solver %d %d\n");
        ColorPrint(GreenColor, "If you want to use file input, write 1. Else, write 0\n");

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
                ColorPrint(GreenColor, "Write the path to the file (or it`s name, if the file in the directory of the programm)\n");

                char s[MAX_PATH_LEN] = {0};
                fgets(s, MAX_PATH_LEN, stdin); // TODO check error

                int i = 0;
                while (s[i] != '\n') {
                    ++i;
                }
                s[i] = '\0';

                FILE* f = fopen("input.txt", "r");

                if (f == nullptr) {
                    ColorPrint(RedColor, "Error file nameeee\n");
                    break;
                }

                if (!ReadFileEquation(&equation, f)) {
                    SolveAndOut(&equation);
                }
                break;
            }
            default:
                ColorPrint(RedColor, "Error mode\n");
                return 1;
                break;
        }
    }

    return 0;
}
