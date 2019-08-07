#include "Solution.h"

Solution *solution_initialize(const char *separator)
{
    Solution *new_solution = (Solution*) malloc(sizeof(Solution));
    new_solution->sep = (char*) malloc(strlen(separator));
    strcpy(new_solution->sep, separator);
    new_solution->stream = (char*) malloc(0);   
    new_solution->len_sol = 0;
    return new_solution;
}

void solution_finalize(Solution* sol)
{
    free(sol->stream);
    free(sol);
}

void solution_write(Solution *sol)
{
    FILE *f = fopen("solution.txt", "w");
    fprintf(f, sol->stream);
    fclose(f);
}

void solution_print(const Solution *sol)
{
    printf("%s\n", sol->stream);
}

void solution_concat_int(Solution *sol, int value)
{
    char* string = NULL;
    sprintf(string, "%d", value);
    solution_concat_string(sol, string);
}

void solution_concat_double(Solution *sol, double value)
{
    //char* string = NULL;
    //sprintf(string, "%f", value);
    //solution_concat_string(sol, string);
    double darr[1] = { value };
    char *arr = (char*) darr;
    solution_concat_string(sol, arr);
}

void solution_concat_string(Solution *sol, char* value)
{
    int len_value = strlen(value);
    sol->stream = (char*) realloc(sol->stream, len_value + sol->len_sol + 2);
    strcat(sol->stream, sol->sep);
    strcat(sol->stream, value);
    sol->len_sol = strlen(sol->stream);
}