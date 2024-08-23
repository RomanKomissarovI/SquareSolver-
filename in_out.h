#ifndef IN_OUT_H
#define IN_OUT_H

void FlushInput();
void ReadConsoleEquation(Equation* equation);
void ReadFileEquation(Equation* equation, FILE* f);
void OutputSolution(Solution* solution);

#endif // IN_OUT_H
