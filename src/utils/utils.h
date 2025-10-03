#ifndef UTILS_H
#define UTILS_H

#include "../model/pessoa.h"

int validate_name(char name[]);
int validate_gender(char g);
int validate_cpf(char cpf[]);
int validate_ID(char id[]);
int validate_birth(char birth[]);

void read_id(char id[], int type);
void read_name(char name[]);
char read_gender();
void read_birth(char birth[]);
void read_cpf(char cpf[], int type, int ignore_index);

void clear_screen();
void pause_view();

#endif
