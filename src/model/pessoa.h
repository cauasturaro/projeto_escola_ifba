// PESSOA (aluno ou professor) MODEL

#ifndef PESSOA_H
#define PESSOA_H

#include "model.h"

#define SIZE_REGISTRATION 12
#define SIZE_NAME 100
#define SIZE_BIRTH 11
#define SIZE_CPF 16
#define MAX_PEOPLE 100

typedef struct Person
{
    char name[SIZE_NAME];
    char registration[SIZE_REGISTRATION];
    char gender;
    char birth[SIZE_BIRTH];
    char CPF[SIZE_CPF];
    int enrolled_subjects;
} Person;

extern Person students[MAX_PEOPLE];
extern Person teachers[MAX_PEOPLE];
extern int total_students;
extern int total_teachers;

extern ListagemAdapter personListagemAdapter;
extern SortAdapter personSortAdapter;

#endif
