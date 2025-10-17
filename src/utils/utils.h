// FUNÇẼOS UTILITÁRIAS

#ifndef UTILS_H
#define UTILS_H

#include "../model/pessoa.h"
#include "../view/pessoa_view.h"

int read_int_option(const char *prompt, int min, int max);

void string_to_uppercase(char str[]);

void clear_buffer();
void clear_screen();
void pause_view();
void pause_view();

int validate_numeric_string(char numbers[]);

void ordenar(void *array, int total, size_t element_size, SortAdapter adapter, SortField field);

void dev_add_students(void);
void dev_add_teachers(void);
void dev_add_subjects(void);
void dev_clear_students(void);
void dev_clear_teachers(void);
void dev_clear_subjects(void);
void dev_show_totals(void);

#endif