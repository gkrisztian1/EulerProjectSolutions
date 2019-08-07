#ifndef UNTITLED_SOLUTION_H
#define UNTITLED_SOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Solution
{
  char* sep;
  char* stream;
  int len_sol;
} Solution;

//void solution_initialize(Solution* sol, const char separator);
Solution *solution_initialize(const char *separator);
void solution_finalize(Solution* sol);
void solution_write(Solution *sol);
void solution_print(const Solution *sol);

void solution_concat_int(Solution *sol, int value);
void solution_concat_double(Solution *sol, double value);
void solution_concat_string(Solution *sol, char* value);


#endif //UNTITLED_SOLUTION_H
