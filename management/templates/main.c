#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Solution.h"

int main() {
    /*
    char *str;


    str = (char *) malloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %u\n", str, str);

    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);
    */
    const char *separator = ",";
    Solution *s = solution_initialize(separator);
    solution_concat_double(s, 11.23);
    solution_concat_double(s, -11111343.244400);
    solution_concat_double(s, 244.0123456789);
    solution_print(s);

    solution_finalize(s);
    return 0;
}


