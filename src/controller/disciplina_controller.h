#ifndef DISCIPLINA_CONTROLLER_H
#define DISCIPLINA_CONTROLLER_H

#include "../model/disciplina.h"
#include "../view/disciplina_view.h"
#include "../view/pessoa_view.h"
#include "../utils/utils.h"

void subject_module();
void add_subject(int * subject_count, int *teachers_count);
void update_subject(int *subjects_count, int *teachers_count);
void add_subject_student(Subject *selected_subject, int *students_count, int *total_students_count);
void remove_subject_student (Subject *selected_subject, int *students_count);

#endif
