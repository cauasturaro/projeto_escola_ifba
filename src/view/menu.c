#include <stdio.h>
#include "menu.h"

void show_menu()
{
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1 - Modulo Aluno\n");
    printf("2 - Modulo Professor\n");
    printf("3 - Modulo Disciplina\n");
    printf("4 - Aniversariantes do mes\n");
    printf("5 - Buscar por nome\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void subjects_menu(int *option)
{
    printf("\n--- MENU DISCIPLINAS ---\n");
    printf("1 - Adicionar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Listar Alunos da Disciplina\n");
    printf("4 - Atualizar Disciplina\n");
    printf("5 - Remover Disciplina\n");
    printf("0 - Sair\n");
    scanf("%d", option);
    getchar();
}

void update_subject_menu(int *option, Subject *selected_subject)
{
    printf("\n--- Atualizando %s ---\n", selected_subject->name);
    printf("1 - Alterar nome\n");
    printf("2 - Alterar codigo\n");
    printf("3 - Alterar semestre\n");
    printf("4 - Alterar professor\n");
    printf("5 - Adicionar aluno\n");
    printf("6 - Remover aluno\n");
    printf("0 - Sair\n");
    scanf("%d", option);
    getchar();
}

void students_menu(int *option)
{
    printf("\n--- MENU ALUNOS ---\n");
    printf("1 - Adicionar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Listar Alunos Filtrados\n");
    printf("4 - Atualizar Aluno\n");
    printf("5 - Remover Aluno\n");
    printf("0 - Sair\n");
    scanf("%d", option);
    getchar();
}

void teachers_menu(int *option)
{
    printf("\n--- MENU PROFESSORES ---\n");
    printf("1 - Adicionar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Listar Professores Filtrados\n");
    printf("5 - Atualizar Professor\n");
    printf("6 - Remover Professor\n");
    printf("0 - Sair\n");
    scanf("%d", option);
    getchar();
}