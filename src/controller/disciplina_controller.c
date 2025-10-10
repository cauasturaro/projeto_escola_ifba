#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "disciplina_controller.h"

void select_teacher (Person *subject_teacher, int *teachers_count) {
    int selected_teacher_id = -1;

    printf("Selecione um professor para a disciplina:\n");
    list_teachers();
    
    scanf("%d", &selected_teacher_id);
    getchar();

    while ((selected_teacher_id > *teachers_count) || (selected_teacher_id  <= 0)) {
        printf("ID invalido!\n");
        printf("Selecione um professor para a disciplina:\n");
        list_teachers();

        scanf("%d", &selected_teacher_id);
        getchar();
    }
    selected_teacher_id--;
    *subject_teacher = teachers[selected_teacher_id];
}

void subject_module()
{   
    int option = 1;
    while (option)
    {
        subjects_menu(&option);
        switch (option)
        {
        case 0:
            printf("Saindo do Modulo Disciplina...\n");
            return;

        case 1:
            add_subject(&total_subjects, &total_teachers);
            break;

        case 2:
            list_subjects(&total_subjects);
            break;

        case 3:
            list_subject_students(&total_subjects);
            break;

        case 4:
            update_subject(&total_subjects, &total_teachers);
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

void add_subject(int * subject_count, int *teachers_count)
{
    if (total_subjects >= MAX_SUBJECTS) {
        printf("Limite de disciplinas atingido!\n");
        return;
    }
    
    printf("Adicionando Disciplina...\n");
    Subject new_subject;
    
    read_subject_name(new_subject.name, MAX_STR);
    read_subject_code(new_subject.code, MAX_CODE);
    read_subject_semester(new_subject.semester, MAX_STR);
    select_teacher(&new_subject.teacher, teachers_count);

    Subject *selected_subject = &subjects[(*subject_count)];
    *selected_subject = new_subject;
    (*subject_count)++;
    printf("Nova disciplina adicionada com sucesso!\n");
}

void update_subject(int *subjects_count, int *teachers_count)
{
    int option = 1;

    printf("Atualizando Disciplina...\n");
    list_subjects(subjects_count);

    printf("\nDigite o ID da Disciplina que deseja atualizar:\n");
    scanf("%d", &selected_subject_id);
    getchar();
    while ((selected_subject_id > *subjects_count) || (selected_subject_id  <= 0)) {
        printf("ID invalido!\n");
        printf("Digite o ID da Disciplina que deseja atualizar:\n");
        list_subjects(subjects_count);
        scanf("%d", &selected_subject_id);
        getchar();
    }
    selected_subject_id--;

    Subject *selected_subject = &subjects[selected_subject_id];
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
                read_subject_name(selected_subject->name, MAX_STR);
                break;

            case 2:
                read_subject_code(selected_subject->code, MAX_CODE);
                break;

            case 3:
                read_subject_semester(selected_subject->semester, MAX_STR);
                break;

            case 4:
                select_teacher(&selected_subject->teacher, teachers_count);
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
