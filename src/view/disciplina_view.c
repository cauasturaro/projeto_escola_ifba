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
    if (*subject_count == 0) {
            printf("Nao ha disciplinas cadastradas");
            return;
        }

    printf("\n------------Disciplinas------------\n");
    for (int i = 0; i < (*subject_count); i++)
    {
        printf(">#%03d | Codigo: %s | Nome: %s | Semestre: %s | Professor: %s\n", 
            i+1, subjects[i].code, subjects[i].name, subjects[i].semester, subjects[i].teacher.name);
    }
}

void list_subject_students(Subject *selected_subject, int students_count)
{
    if (students_count == 0) {
        printf("%s nao possui alunos.", selected_subject->name);
        return;
    }

    printf("\n------------Alunos de %s------------\n", selected_subject->name);
    for (int i = 0; i < students_count && students[i].gender; i++)
    {
        printf("> ID: %s | Nome: %s | Genero: %c | Data de Nascimento: %s | CPF: %s\n",
               selected_subject->students[i].id, selected_subject->students[i].name, selected_subject->students[i].gender,
               selected_subject->students[i].birth, selected_subject->students[i].CPF);
    }
}
