/**
    \file
*/
#ifndef color_print_h
#define color_print_h


const char GreenColor[] = "\033[3;32m";
const char RedColor[] = "\033[3;31m";
const char EndColor[] = "\033[0m";

void ColorPrint(const char color[], char* format, ...);

#endif
