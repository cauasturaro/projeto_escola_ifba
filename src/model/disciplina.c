#include "./disciplina.h"

Subject subjects[MAX_SUBJECTS];
int total_subjects = 0;

Subject *selected_subject = 0;

int selected_subject_id = -1;
int selected_teacher_id = -1;

const char *subjectGetId(const void *obj)
{
    return ((Subject *)obj)->code;
}

void subjectPrint(const void *obj, int id)
{
    const Subject *p = (Subject *)obj;
    printf("> ID: %d | Código: %s | Nome: %s | Semestre: %s | Professor: %s\n", id, p->code, p->name, p->semester, p->teacher.name);
}

Adapter subjectAdapter = {
    .getId = subjectGetId,
    .print = subjectPrint};
