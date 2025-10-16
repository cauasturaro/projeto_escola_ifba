// FUNÇÕES UTILITÁRIAS PARA PERSON

#ifndef PESSOA_UTILS_H
#define PESSOA_UTILS_H

#include "utils.h"

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

#endif
