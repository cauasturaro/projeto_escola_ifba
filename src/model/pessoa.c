#include "pessoa.h"

Person students[MAX_PEOPLE];
Person teachers[MAX_PEOPLE];
int total_students = 0;
int total_teachers = 0;

const char *person_get_id(const void *obj)
{
    return ((Person *)obj)->registration;
}

const char *person_get_sort_field(const void *obj, SortField field)
{
    const Person *p = (const Person *)obj;

    switch (field)
    {
    case SORT_BY_NAME:
        return p->name;
    case SORT_BY_GENDER:
    {
        static char gender_str[2]; // para transformar char em string; static para que não seja apagado após o retorno e ponteiro continaur válido
        gender_str[0] = p->gender;
        gender_str[1] = '\0';
        return gender_str;
    }
    case SORT_BY_BIRTH:
        return p->birth;
    case SORT_BY_REGISTRATION:
        return p->registration;
    case SORT_BY_STUDENT_CPF:
        return p->CPF;
    default:
        return "";
    }
}

void person_print(const void *obj, int id)
{
    const Person *p = (Person *)obj;
    printf("> ID: %d | Matrícula: %s | Nome: %s | Genero: %c | Data de Nascimento: %s | CPF: %s\n",
           id, p->registration, p->name, p->gender, p->birth, p->CPF);
}

ListagemAdapter personListagemAdapter = {
    .get_id = person_get_id,
    .print = person_print};

SortAdapter personSortAdapter = {
    .get_field = person_get_sort_field,
    .print = person_print};