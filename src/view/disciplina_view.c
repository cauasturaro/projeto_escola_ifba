#include <stdio.h>

#include "./disciplina_view.h"
#include "../model/disciplina.h"

//FUNÇÕES AUX
void list_subjects()
{
    printf("Listando Disciplinas...\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("Disciplina #%03d:\n", i + 1);
        printf("  Nome: %s\n", subjects[i].name);
        printf("  Codigo: %s\n", subjects[i].code);
        printf("  Semestre: %d\n", subjects[i].semester);
        printf("  Professor: %s\n", subjects[i].teacher.name);
    }
};

void list_subject_students()
{
    printf("Listando alunos...\n");
    list_subjects();
    
    printf("Digite o ID da Disciplina que deseja listar alunos:\n");
    scanf("%d", &selected_subject_id);
    getchar();

    for (total_subjects = 0; subjects[total_subjects].semester; total_subjects++);
    while ((selected_subject_id > total_subjects) || (selected_subject_id  <= 0)) {
        printf("ID invalido!\n");
        list_subjects();
        printf("Digite o ID da disciplina que deseja listar alunos:\n");
        scanf("%d", &selected_subject_id);
        getchar();
    }

    selected_subject_id--;
    Subject *selected_subject = &subjects[selected_subject_id];

    printf("Disciplina %s:\n", selected_subject->name);
    for (int i = 0; i < TAM; i++)
    {
        if (students[i].gender)
        {
            printf("Aluno #%03d:\n", i + 1);
            printf("  Nome: %s\n", selected_subject->students[i].name);
            printf("  ID: %s\n", selected_subject->students[i].id);
            printf("  Sexo: %c\n", selected_subject->students[i].gender);
            printf("  Data de Nascimento: %s\n", selected_subject->students[i].birth);
            printf("  CPF: %s\n", selected_subject->students[i].CPF);
        }
    }
};
