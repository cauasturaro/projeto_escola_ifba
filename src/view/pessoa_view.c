#include <stdio.h>
#include "pessoa_view.h"
#include "../model/pessoa.h"

void list_people(const char *titulo, Person array[], int total)
{
    printf("\n%s\n", titulo);
    for (int i = 0; i < total; i++)
    {
        printf("> ID: %s | Name: %s | Gender: %c | Birth: %s | CPF: %s\n",
               array[i].id, array[i].name, array[i].gender,
               array[i].birth, array[i].CPF);
    }
}

void list_students()
{
    list_people("------------Estudantes------------", students, total_students);
}

void list_teachers()
{
    list_people("------------Professores------------", teachers, total_teachers);
}
