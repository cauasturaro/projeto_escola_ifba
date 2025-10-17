// FUNÇẼOS UTILITÁRIAS

#ifndef UTILS_H
#define UTILS_H

#include "../model/pessoa.h"
#include "../view/pessoa_view.h"

void string_to_uppercase(char str[]);

void clear_buffer();
void clear_screen();
void pause_view();
void pause_view_without_clear();

int validate_numeric_string(char numbers[]);

void ordenar(void *array, int total, size_t element_size, SortAdapter adapter, SortField field);

#endif