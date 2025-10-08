#include <stdio.h>
#include <string.h>

#include "disciplina_controller.h"
#include "../utils/utils.h"

void subject_module()
{
    int option = 1;
    while (option)
    {
        printf("1 - Adicionar Disciplina\n");
        printf("2 - Listar Disciplinas\n");
        printf("3 - Listar Alunos da Disciplina\n");
        printf("4 - Atualizar Disciplina\n");
        printf("5 - Remover Disciplina\n");
        printf("0 - Sair\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 0:
            printf("Saindo do Modulo Disciplina...\n");
            return;

        case 1:
            for (total_subjects = 0; subjects[total_subjects].semester; total_subjects++);
            if (total_subjects >= TAM) {
                printf("Limite de disciplinas atingido!\n");
            } else { 
                add_subject(); }
            break;

        case 2:
            list_subjects();
            break;

        case 3:
            list_subject_students();
            break;

        case 4:
            update_subject();
            break;

        case 5:
            printf("Removendo Disciplina...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void add_subject()
{
    selected_subject = &subjects[total_subjects];

    printf("Adicionando Disciplina...\n");
    
    read_subject_name(subject_name, MAX_STR);
    read_subject_code(subject_code, MAX_CODE);
    read_subject_semester(subject_semester, MAX_STR);

    printf("Selecione um professor para a disciplina:\n");
    list_people(teachers);
    
    scanf("%d", &selected_teacher_id);
    getchar();

    for (total_teachers = 0; teachers[total_teachers].gender; total_teachers++);
    while ((selected_teacher_id > total_teachers) || (selected_teacher_id  <= 0)) {
        printf("ID invalido!\n");
        printf("Selecione um professor para a disciplina:\n");
        list_people(teachers);

        scanf("%d", &selected_teacher_id);
        getchar();
    }
    selected_teacher_id--;

    Subject new_subject;
    strncpy(new_subject.name, subject_name, MAX_STR);
    strncpy(new_subject.code, subject_code, MAX_CODE);
    new_subject.semester = atoi(subject_semester);
    new_subject.teacher = teachers[selected_teacher_id];
    *selected_subject = new_subject;
}

void update_subject()
{
    int option = 1;

    printf("Atualizando Disciplina...\n");
    list_subjects();

    printf("Digite o ID da Disciplina que deseja atualizar:\n");
    scanf("%d", &selected_subject_id);
    getchar();
    for (total_subjects = 0; subjects[total_subjects].semester; total_subjects++);
    while ((selected_subject_id > total_subjects) || (selected_subject_id  <= 0)) {
        printf("ID invalido!\n");
        printf("Digite o ID da Disciplina que deseja atualizar:\n");
        list_subjects();
        scanf("%d", &selected_subject_id);
        getchar();
    }
    selected_subject_id--;

    selected_subject = &subjects[selected_subject_id];
    while (option)
    {
        printf("Atualizando disciplina %s...\n", selected_subject->name);
        printf("Selecione qual campo deseja alterar\n");
        printf("1 - Nome\n");
        printf("2 - Codigo\n");
        printf("3 - Semestre\n");
        printf("4 - Professor\n");
        printf("5 - Adicionar Aluno\n");
        printf("6 - Remover Aluno\n");
        printf("0 - Voltar\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 0:
            printf("Saindo de Atualizar disciplina %s...\n", selected_subject->name);
            return;

        case 1:
            read_subject_name(subject_name, MAX_STR);
            strncpy(selected_subject->name, subject_name, MAX_STR);
            break;

        case 2:
            read_subject_code(subject_code, MAX_CODE);
            strncpy(selected_subject->code, subject_code, MAX_STR);
            break;

        case 3:
            read_subject_semester(subject_semester, MAX_STR);
            selected_subject->semester = atoi(subject_semester);
            break;

        case 4:
            printf("Selecione um professor para a disciplina:\n");
            list_people(teachers);
            scanf("%d", &selected_teacher_id);
            getchar();

            for (total_teachers = 0; teachers[total_teachers].gender; total_teachers++);
            while ((selected_teacher_id > total_teachers) || (selected_teacher_id  <= 0)) {
                printf("ID invalido!\n");
                printf("Selecione um professor para a disciplina:\n");
                list_people(teachers);
                scanf("%d", &selected_teacher_id);
                getchar();
            }
            selected_teacher_id--;

            selected_subject->teacher = teachers[selected_teacher_id];
            break;

        case 5:
            break;

        case 6:
            break;

        default:
            printf("Opção Inválida!\n");
        }
    }
}