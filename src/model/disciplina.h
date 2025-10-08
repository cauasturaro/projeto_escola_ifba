#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "./pessoa.h"

#define MAX_STR 20
#define MAX_CODE 8 //Aceita, no máximo, 6 caracteres --> esperado - 2 ('\n' e '\0')
#define TAM 3

typedef struct
{
    char name[MAX_STR];
    char code[MAX_CODE];
    int semester;
    Person teacher;
    Person students[TAM];
} Subject;

// é extern mesmo????????
extern Subject subjects[TAM];
extern int total_subjects;

// campos temporários p validação antes da atrubuição ao elemento real
extern Subject *selected_subject;
extern char subject_name[MAX_STR];
extern char subject_code[MAX_CODE];
extern char subject_semester[MAX_STR];

extern int selected_subject_id;
extern int selected_teacher_id;

#endif