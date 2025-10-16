#include <stdio.h>
#include "pessoa_view.h"

void list_students()
{
    list("------------Estudantes------------", students, total_students, sizeof(Person), personAdapter);
}

void list_teachers()
{
    list("------------Professores------------", teachers, total_teachers, sizeof(Person), personAdapter);
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
            remover_student();
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
            remover_teacher();
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}