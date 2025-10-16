// FUNCIONALIDADES DE CONTROLE DE PESSOAS

#ifndef PESSOA_CONTROLLER_H
#define PESSOA_CONTROLLER_H

#include "../model/pessoa.h"
#include "../controller/controller.h"
#include "../utils/utils.h"

void register_person(int type);
void update_person(Person array[], int total, int type);
// TIPO 1 = STUDENT | TIPO 2 = TEACHER

void remover_student();
void remover_teacher();

#endif
