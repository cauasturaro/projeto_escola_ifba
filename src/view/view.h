// FUNCIONALIDADES GLOBAIS DE VISUALIZAÇÃO

#ifndef VIEW_H
#define VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/adapter.h"
#include "../model/pessoa.h"
#include "../model/disciplina.h"

#include "../controller/controller.h"
#include "../controller/pessoa_controller.h"
#include "../controller/disciplina_controller.h"

#include "../utils/disciplina_utils.h"
#include "../utils/pessoa_utils.h"
#include "../utils/utils.h"

#include "menu.h"

void list(const char *titulo, void *array, int total, size_t element_size, Adapter adapter);
// Título da lista, array de objetos (students, teacher, subjects), número total de elementos,
// tamanho de cada elemento, adapter (que é o adapter entre person e subjects)

#endif