// DISCIPLINA MODEL

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "model.h"

#define MAX_STR 20
#define MAX_CODE 8 // Aceita, no máximo, 6 caracteres --> esperado - 2 ('\n' e '\0')
#define MAX_SUBJECTS 4
#define MAX_STUDENTS 2

typedef struct Subject
{
    char name[MAX_STR];
    char code[MAX_CODE];
    char semester[MAX_STR];
    Person teacher;
    Person students[MAX_STUDENTS];
    int students_count;
} Subject;

extern Subject subjects[MAX_SUBJECTS];
extern int total_subjects;

extern int selected_subject_id;
extern int selected_teacher_id;

extern ListagemAdapter subjectAdapter;

#endif
