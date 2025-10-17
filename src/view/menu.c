#include <stdio.h>
#include "menu.h"

void show_menu()
{
    printf("\n======== MENU PRINCIPAL ========\n");
    printf("1 - Modulo Aluno\n");
    printf("2 - Modulo Professor\n");
    printf("3 - Modulo Disciplina\n");
    printf("4 - Aniversariantes do mes\n");
    printf("5 - Buscar pessoas por nome\n");
    printf("6 - DEV MENU\n");
    printf("0 - Sair");
    printf("\n================================\n");
}

void subjects_menu(int *option)
{
    clear_screen();
    printf("\n======== MENU DISCIPLINAS ========\n");
    printf("1 - Adicionar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Listar Alunos da Disciplina\n");
    printf("4 - Listar Disciplinas Filtradas\n");
    printf("5 - Atualizar Disciplina\n");
    printf("6 - Remover Disciplina\n");
    printf("0 - Sair");
    printf("\n==================================\n");

    *option = read_int_option("Escolha uma opcao: ", 0, 6);
}

void update_subject_menu(int *option, Subject *selected_subject)
{

    clear_screen();
    printf("\n======== Atualizando %s ========\n", selected_subject->name);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar codigo\n");
    printf("3 - Alterar semestre\n");
    printf("4 - Alterar professor\n");
    printf("5 - Adicionar aluno\n");
    printf("6 - Remover aluno\n");
    printf("0 - Sair\n");
    printf("\n==================================\n");

    *option = read_int_option("Escolha uma opcao: ", 0, 6);
}

void students_menu(int *option)
{
    clear_screen();
    printf("\n======== MENU ALUNOS ========\n");
    printf("1 - Adicionar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Listar Alunos Filtrados\n");
    printf("4 - Atualizar Aluno\n");
    printf("5 - Remover Aluno\n");
    printf("0 - Sair");
    printf("\n=============================\n");

    *option = read_int_option("Escolha uma opcao: ", 0, 5);
}

void teachers_menu(int *option)
{
    clear_screen();
    printf("\n======== MENU PROFESSORES ========\n");
    printf("1 - Adicionar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Listar Professores Filtrados\n");
    printf("4 - Atualizar Professor\n");
    printf("5 - Remover Professor\n");
    printf("0 - Sair");
    printf("\n==================================\n");

    *option = read_int_option("Escolha uma opcao: ", 0, 5);
}

// --------- DEV MENU

void dev_menu(int *option)
{
    clear_screen();
    printf("\n======== MENU DE DESENVOLVEDOR ========\n");
    printf("1 - Adicionar 20 Alunos\n");
    printf("2 - Adicionar 20 Professores\n");
    printf("3 - Adicionar 5 Disciplinas\n");
    printf("4 - Remover todos os Alunos\n");
    printf("5 - Remover todos os Professores\n");
    printf("6 - Remover todas as Disciplinas\n");
    printf("7 - Mostrar totais\n");
    printf("0 - Sair\n");
    printf("=======================================\n");

    *option = read_int_option("Escolha uma opcao: ", 0, 7);
}

void dev_menu_module()
{
    int option = 1;
    while (option)
    {
        dev_menu(&option);
        switch (option)
        {
        case 0:
            printf("Saindo do Módulo de Desenvolvedor...\n");
            return;
        case 1:
            clear_screen();
            dev_add_students();
            break;
        case 2:
            clear_screen();
            dev_add_teachers();
            break;
        case 3:
            clear_screen();
            dev_add_subjects();
            break;
        case 4:
            clear_screen();
            dev_clear_students();
            break;
        case 5:
            clear_screen();
            dev_clear_teachers();
            break;
        case 6:
            clear_screen();
            dev_clear_subjects();
            break;
        case 7:
            clear_screen();
            dev_show_totals();
            break;
        default:
            printf("Opção inválida!\n");
            pause_view();
            break;
        }
    }
}