#include "pessoa_view.h"

void list_students()
{

    if (total_students == 0)
    {
        printf("Nao ha alunos cadastrados\n");
        return;
    }

    list("================ ESTUDANTES ================", students, total_students, sizeof(Person), personListagemAdapter);
}

void list_teachers()
{
    if (total_teachers == 0)
    {
        printf("Nao ha professores cadastrados\n");
        return;
    }

    list("================ PROFESSORES ================", teachers, total_teachers, sizeof(Person), personListagemAdapter);
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
            clear_screen();
            register_person(1);
            break;

        case 2:
            clear_screen();
            list_students();
            pause_view_without_clear_buffer();
            break;

        case 3:
            clear_screen();
            listar_ordenado_people_module(1);
            break;

        case 4:
            clear_screen();
            list_students();
            update_person(students, total_students, 1);
            break;

        case 5:
            clear_screen();
            remover_student();
            pause_view_without_clear_buffer();
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
            clear_screen();
            register_person(2);
            break;

        case 2:
            clear_screen();
            list_teachers();
            pause_view_without_clear_buffer();
            break;

        case 3:
            clear_screen();
            listar_ordenado_people_module(2);
            break;

        case 4:
            clear_screen();
            list_teachers();
            update_person(teachers, total_teachers, 2);
            break;

        case 5:
            clear_screen();
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
        printf("======== SELECIONE A OPCAO DE FILTRAGEM ========\n");
        printf("1 - Nome\n");
        printf("2 - Genero\n");
        printf("3 - Data de Nascimento\n");
        printf("4 - Matricula\n");
        printf("5 - CPF\n");
        printf("0 - Sair");
        printf("\n=============================================\n");

        option = read_int_option("Escolha uma das opcoes: ", 0, 5);

        clear_screen();

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
            list("============ DADOS FILTRADOS POR NOME ============", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;

        case 2:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_GENDER);
            list("============ DADOS FILTRADOS POR GENERO ============", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        case 3:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_BIRTH);
            list("============ DADOS FILTRADOS POR DATA DE NASCIMENTO ============", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        case 4:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_REGISTRATION);
            list("============ DADOS FILTRADOS POR MATRICULA ============", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        case 5:
            ordenar(entidade_atual, total_entidade_atual, sizeof(Person), personSortAdapter, SORT_BY_STUDENT_CPF);
            list("============ DADOS FILTRADOS POR CPF ============", entidade_atual, total_entidade_atual, sizeof(Person), personListagemAdapter);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}
