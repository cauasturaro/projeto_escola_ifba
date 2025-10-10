#ifndef UTILS_H
#define UTILS_H

#include "../model/pessoa.h"

void string_to_uppercase (char str[]);

int validate_name(char name[]);

int validate_numeric_string(char numbers[]);
int validate_code(char code[], int max_size);

void read_subject_name (char subject_name[], int tam_str);
void read_subject_code (char subject_code[], int tam_code);
void read_subject_semester (char subject_semester[], int tam_str);

#endif
