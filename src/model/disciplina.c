#include "disciplina.h"

Subject subjects[MAX_SUBJECTS];
int total_subjects = 0;

Subject *selected_subject = 0;

int selected_subject_id = -1;
int selected_teacher_id = -1;

const char *subject_get_id(const void *obj)
{
    return ((Subject *)obj)->code;
}

const char *subject_get_sort_field(const void *obj, SortField field)
{
    const Subject *s = (const Subject *)obj;
    static char count_str[8];

    switch (field)
    {
    case SORT_BY_NAME:
        return s->name;
    case SORT_BY_CODE:
        return s->code;
    case SORT_BY_SEMESTER:
        return s->semester;
    case SORT_BY_STUDENT_COUNT:
        snprintf(count_str, sizeof(count_str), "%d", s->students_count);
        return count_str;
    default:
        return "";
    }
}

void subject_print(const void *obj, int id)
{
    const Subject *p = (Subject *)obj;
    printf("> ID: %d | Codigo: %s | Nome: %s | Semestre: %s | Professor: %s\n", id, p->code, p->name, p->semester, p->teacher.name);
}

ListagemAdapter subjectListagemAdapter = {
    .get_id = subject_get_id,
    .print = subject_print};

SortAdapter subjectSortAdapter = {
    .get_field = subject_get_sort_field,
    .print = subject_print};
