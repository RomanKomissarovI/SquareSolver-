/**
    \file
*/
#ifndef color_print_h
#define color_print_h


const char GreenColor[] = "\033[3;32m";
const char RedColor[] = "\033[3;31m";
const char EndColor[] = "\033[0m";

/**
    \brief Print in console with given color
    \param[in] color[] the color
    \param[in] format the format of string
    \param[in] ... what values must the function print
*/
void ColorPrint(const char color[], const char* format, ...);

#endif
