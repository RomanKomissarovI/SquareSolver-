#include <stdio.h>
#include "in-out.cpp"
#include "solve_equation.cpp"

void flush_input() {       // уничтожение символов до конца строки
    char c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
        printf("%c", c);
}

int main(int argc, const char* argv[])
{
    equation eq;
    printf("Square Solver\n");
    printf("If you want to use file input, write 1. Else, write 0\n");
    char mode = '0';
    scanf("%c", &mode);

    switch(mode) {
        case '0':
            read_console_eq(&eq);
            break;
        case '1':
            flush_input();
            read_file_eq(&eq);
            break;
        default:
            printf("Error mode\n");
            return 1;
            break;
    }

    //if (argc >= 2 && argv[1] == "--file") {
    //
    //}

    // Q is valid???
    eq.s.nroot = solve_square_eq(&eq.c, &eq.s); //square
    output(&eq.s);
    return 0;
}
