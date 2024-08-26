#include "color_print.h"
#include <stdarg.h>
#include <stdio.h>

void ColorPrint(const char color[], char* format, ...)
{

    printf("%s", color);
    int d;
    double f;
    char* s;
    va_list factor;
    va_start(factor, format);

    for(char *c = format;*c; c++)
    {
        if(*c!='%')
        {
            printf("%c", *c);
            continue;
        }
        switch(*++c)    // если символ - %, то переходим к следующему символу
        {
            case 'd':
                d = va_arg(factor, int);
                printf("%d", d);
                break;
            case 'l':
                if (*++c == 'f') {
                    f = va_arg(factor, double);
                    printf("%.2lf", f);
                    break;
                }
            case 's':
                s = va_arg(factor, char*);
                printf("%s", s);
                break;
            default:
                printf("%c", *c);
        }
    }
    printf("%s", EndColor);
    va_end(factor);
}
