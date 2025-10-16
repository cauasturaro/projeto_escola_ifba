#include <stdio.h>
#include "pessoa_view.h"
#include "../view/menu.h"
#include "../model/pessoa.h"
#include "../controller/pessoa_controller.h"

void list_people(const char *titulo, Person array[], int total)
{
    printf("\n%s\n", titulo);
    for (int i = 0; i < total; i++)
    {
        printf("> ID: %s | Name: %s | Gender: %c | Birth: %s | CPF: %s\n",
               array[i].registration, array[i].name, array[i].gender,
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

void students_module()
{
    int option = 1;
    while (option)
    {
        students_menu(&option);
        switch (option)
        {
        case 0:
            printf("Saindo do Modulo Aluno...\n");
            return;

        case 1:
            register_person(1);
            break;

        case 2:
            list_students();
            break;

        case 3:
            update_person(students, total_students, 1);
            break;

        case 4:
            printf("Removendo Aluno...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void teachers_module()
{
    int option = 1;
    while (option)
    {
        teachers_menu(&option);
        switch (option)
        {
        case 0:
            printf("Saindo do Modulo Professor...\n");
            return;

        case 1:
            register_person(2);
            break;

        case 2:
            list_teachers();
            break;

        case 3:
            update_person(teachers, total_teachers, 2);
            break;

        case 4:
            printf("Removendo Professor...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}