#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <string.h>
#include "../model/pessoa.h"
#include "../model/adapter.h"

#include "../view/view.h"
#include "../view/disciplina_view.h"
#include "../view/pessoa_view.h"
#include "../view/menu.h"

#include "../utils/pessoa_utils.h"
#include "../utils/disciplina_utils.h"
#include "../utils/utils.h"

void remover(void *array, int *total, size_t element_size);
// array de elementos, ponteiro de total de objetos no array, tamanho de cada elemento

#endif