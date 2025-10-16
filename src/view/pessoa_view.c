#include "pessoa_view.h"

void list_students()
{
    list("------------Estudantes------------", students, total_students, sizeof(Person), personListagemAdapter);
}

void list_teachers()
{
    list("------------Professores------------", teachers, total_teachers, sizeof(Person), personListagemAdapter);
}

static Person *entidade_atual = NULL;
static int total_entidade_atual = 0;

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
            listar_ordenado_people_module(1);
            break;

        case 4:
            update_person(students, total_students, 1);
            break;

        case 5:
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
            listar_ordenado_people_module(2);
            break;

        case 4:
            update_person(teachers, total_teachers, 2);
            break;

        case 5:
            remover_teacher();
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void listar_ordenado_people_module(int tipo)
{
    int option = 1;
    while (option)
    {
        printf("Escolha a opcao de filtragem:\n");
        printf("1 - Nome\n");
        printf("2 - Genero\n");
        printf("3 - Data de Nascimento\n");
        printf("4 - Matricula\n");
        printf("5 - CPF\n");
        printf("0 - Sair\n");
        scanf("%d", &option);
        getchar();

        switch (tipo)
        {
        case 1:
            entidade_atual = students;
            total_entidade_atual = total_students;
            break;
        case 2:
            entidade_atual = teachers;
            total_entidade_atual = total_teachers;
            break;
        }

        switch (option)
        {
        case 0:
            printf("Saindo de Listar Filtado...\n");
            return;

        case 1:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_NAME);
            list("---- Dados Filtrados por Nome ----", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;

        case 2:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_GENDER);
            list("---- Dados Filtrados por Genero ----", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        case 3:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_BIRTH);
            list("---- Dados Filtrados por Data de Nascimento ----", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        case 4:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_REGISTRATION);
            list("---- Dados Filtrados por Matricula ----", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        case 5:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_STUDENT_CPF);
            list("---- Dados Filtrados por CPF ----", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}
