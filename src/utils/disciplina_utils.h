// FUNÇÕES UTILITÁRIAS PARA DISCIPLINA

#ifndef DISCIPLINA_UTILS_H
#define DISCIPLINA_UTILS_H

#include "utils.h"

int validate_code(char code[], int max_size);

void read_subject_name(char subject_name[], int tam_str);
void read_subject_code(char subject_code[], int tam_code);
void read_subject_semester(char subject_semester[], int tam_str);

#endif