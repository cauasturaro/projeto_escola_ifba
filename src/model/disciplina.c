#include <stdio.h>
#include "./disciplina.h"

Subject subjects[MAX_SUBJECTS];
int total_subjects = 0;

Subject *selected_subject = 0;

int selected_subject_id = -1;
int selected_teacher_id = -1;

const char *subject_get_id(const void *obj)
{
    return ((Subject *)obj)->code;
}

void subject_print(const void *obj, int id)
{
    const Subject *p = (Subject *)obj;
    printf("> ID: %d | Código: %s | Nome: %s | Semestre: %s | Professor: %s\n", id, p->code, p->name, p->semester, p->teacher.name);
}

ListagemAdapter subjectAdapter = {
    .getId = subject_get_id,
    .print = subject_print};
