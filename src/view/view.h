// FUNCIONALIDADES GLOBAIS DE VISUALIZAÇÃO

#ifndef VIEW_H
#define VIEW_H

#include "../model/adapter.h";

void list(const char *titulo, void *array, int total, size_t element_size, Adapter adapter);
// Título da lista, array de objetos (students, teacher, subjects), número total de elementos,
// tamanho de cada elemento, adapter (que é o adapter entre person e subjects)

#endif