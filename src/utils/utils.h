// FUNÇẼOS UTILITÁRIAS

#ifndef UTILS_H
#define UTILS_H

#include "../model/pessoa.h"

void string_to_uppercase(char str[]);
void clear_screen();
void pause_view();

int validate_name(char name[]);
int validate_gender(char g);
int validate_cpf(char cpf[]);
int validate_registration(char id[]);
int validate_birth(char birth[]);

void read_registration(char id[], int type);
void read_name(char name[]);
char read_gender();
void read_birth(char birth[]);
void read_cpf(char cpf[], int type, int ignore_index);

int validate_numeric_string(char numbers[]);
int validate_code(char code[], int max_size);

void read_subject_name(char subject_name[], int tam_str);
void read_subject_code(char subject_code[], int tam_code);
void read_subject_semester(char subject_semester[], int tam_str);

#endif