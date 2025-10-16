#include "pessoa.h"

Person students[MAX_PEOPLE];
Person teachers[MAX_PEOPLE];
int total_students = 0;
int total_teachers = 0;

const char *personGetId(const void *obj)
{
    return ((Person *)obj)->registration;
}

void personPrint(const void *obj, int id)
{
    const Person *p = (Person *)obj;
    printf("> ID: %d | Matrícula: %s | Nome: %s | Genero: %c | Data de Nascimento: %s | CPF: %s\n",
           id, p->name, p->registration, p->gender, p->birth, p->CPF);
}

Adapter personAdapter = {
    .getId = personGetId,
    .print = personPrint};
