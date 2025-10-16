// FUNCIONALIDADES ESPECÍFICAS DE DISCIPLINAS EM VISUALIZAÇÃO

#ifndef DISCIPLINA_VIEW_H
#define DISCIPLINA_VIEW_H

#include "../model/disciplina.h"
#include "../controller/disciplina_controller.h"
#include "../view/menu.h"
#include "../view/view.h"

void subject_module();
void list_subjects(int *subject_count);
void list_subject_students(Subject *selected_subject, int students_count);

#endif
