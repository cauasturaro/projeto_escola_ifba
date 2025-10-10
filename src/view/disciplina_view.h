#ifndef DISCIPLINA_VIEW_H
#define DISCIPLINA_VIEW_H

#include "../model/disciplina.h"

void subjects_menu(int * option);
void list_subjects(int *subject_count);
void list_subject_students(Subject *selected_subject, int students_count);

#endif
