#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* reading();
char** sort_list(char **list, int size_list);
int number_of_file_lines(FILE *file);
int date_day();
int date_month();
int date_year();

#endif
