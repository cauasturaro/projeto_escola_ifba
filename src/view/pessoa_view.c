#include <stdio.h>
#include "pessoa_view.h"

void list_students()
{
    printf("\nEstudantes\n");
    for (int i = 0; i < total_students; i++)
    {
        printf("> ID: %s | Name: %s | Gender: %c | Birth: %s | CPF: %s\n",
               students[i].id, students[i].name, students[i].gender,
               students[i].birth, students[i].CPF);
    }
}

void list_teachers()
{
    printf("\nProfessores\n");
    for (int i = 0; i < total_teachers; i++)
    {
        printf("> ID: %s | Name: %s | Gender: %c | Birth: %s | CPF: %s\n",
               teachers[i].id, teachers[i].name, teachers[i].gender,
               teachers[i].birth, teachers[i].CPF);
    }
}
