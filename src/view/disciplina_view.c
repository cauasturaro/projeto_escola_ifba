#include <stdio.h>

#include "./disciplina_view.h"
#include "../model/disciplina.h"

void subjects_menu (int * option) {
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

void list_subjects(int *subject_count)
{
    printf("\n------------Disciplinas------------\n");
    for (int i = 0; i < (*subject_count); i++)
    {
        printf("> Codigo: %s | Nome: %s | Semestre: %s | Professor: %s\n",
               subjects[i].code, subjects[i].name, subjects[i].semester, subjects[i].teacher.name);
    }
}

void list_subject_students(int *subject_count)
{
    printf("Listando alunos...\n");
    list_subjects(subject_count);

    printf("Digite o ID da Disciplina que deseja listar alunos:\n");
    scanf("%d", &selected_subject_id);
    getchar();

    while ((selected_subject_id > *subject_count) || (selected_subject_id  <= 0)) {
        printf("ID invalido!\n");
        list_subjects(subject_count);
        printf("Digite o ID da disciplina que deseja listar alunos:\n");
        scanf("%d", &selected_subject_id);
        getchar();
    }

    selected_subject_id--;
    Subject *selected_subject = &subjects[selected_subject_id];
    
    printf("\n------------Alunos de %s------------\n", selected_subject->name);
    for (int i = 0; i < MAX_STUDENTS && students[i].gender; i++)
    {
        printf("> ID: %s | Nome: %s | Genero: %c | Data de Nascimento: %s | CPF: %s\n",
               selected_subject->students[i].id, selected_subject->students[i].name, selected_subject->students[i].gender,
               selected_subject->students[i].birth, selected_subject->students[i].CPF);
    }
}
