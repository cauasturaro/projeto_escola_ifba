// FUNCIONALIDADES DE CONTROLE DE DISCIPLINAS

#ifndef DISCIPLINA_CONTROLLER_H
#define DISCIPLINA_CONTROLLER_H

#include "controller.h"
#include "../model/disciplina.h"

void subject_module();
void add_subject(int *subject_count, int *teachers_count);
void update_subject(int *subjects_count, int *teachers_count);
void add_subject_student(Subject *selected_subject, int *students_count, int *total_students_count);
void remove_subject_student(Subject *selected_subject, int *students_count);
void remover_subject();

#endif
