#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "disciplina_controller.h"
#include "../view/pessoa_view.h"
#include "../view/disciplina_view.h"
#include "../utils/utils.h"
#include "../utils/disciplina_utils.h"

void select_teacher(Person *subject_teacher, int *teachers_count)
{
    char selected_teacher[MAX_STR] = "";
    int selected_teacher_id = -1;
    printf("\n");
    list_teachers();
    printf("Selecione um professor para a disciplina: ");
    fgets(selected_teacher, MAX_STR, stdin);
    selected_teacher[strcspn(selected_teacher, "\n")] = '\0';

    while (1)
    {
        if (!validate_numeric_string(selected_teacher))
        {
            printf("ID invalido! Digite apenas numeros.\n");
            printf("Selecione um professor para a disciplina: ");
            fgets(selected_teacher, MAX_STR, stdin);
            selected_teacher[strcspn(selected_teacher, "\n")] = '\0';
            continue;
        }
        selected_teacher_id = atoi(selected_teacher);

        if ((selected_teacher_id >= *teachers_count) || (selected_teacher_id < 0))
        {
            printf("ID invalido! Selecione um professor cadastrado.\n");
            printf("Selecione um professor para a disciplina: ");
            fgets(selected_teacher, MAX_STR, stdin);
            selected_teacher[strcspn(selected_teacher, "\n")] = '\0';
            continue;
        }

        break;
    }

    *subject_teacher = teachers[selected_teacher_id];
}

void add_subject(int *subject_count, int *teachers_count)
{
    if (total_subjects >= MAX_SUBJECTS)
    {
        printf("Limite de disciplinas atingido!\n");
        return;
    }

    if (total_teachers == 0)
    {
        printf("Nenhum professor disponivel.\n");
        return;
    }

    clear_screen();

    printf("======== ADICIONANDO DISCIPLINA ========\n");
    Subject new_subject;

    read_subject_name(new_subject.name, MAX_STR);
    read_subject_code(new_subject.code, MAX_CODE);
    read_subject_semester(new_subject.semester, MAX_STR);
    select_teacher(&new_subject.teacher, teachers_count);

    Subject *selected_subject = &subjects[(*subject_count)];
    *selected_subject = new_subject;
    (*subject_count)++;
    printf("\nNova disciplina adicionada com sucesso!\n\n");
}

void update_subject(int *subjects_count, int *teachers_count)
{
    if (!(*subjects_count))
    {
        printf("Nao ha disciplinas cadastradas.\n");
        pause_view();
        return;
    }

    int option = 1;

    list_subjects(subjects_count);

    selected_subject_id = read_int_option("Digite o ID da Disciplina que deseja atualizar: ", 0, *subjects_count - 1);

    while ((selected_subject_id >= *subjects_count) || (selected_subject_id < 0))
    {
        printf("ID invalido!\n");
        printf("Digite o ID da Disciplina que deseja atualizar:");
        list_subjects(subjects_count);
        selected_subject_id = read_int_option("Digite o ID da Disciplina que deseja atualizar: ", 0, *subjects_count - 1);
    }

    Subject *selected_subject = &subjects[selected_subject_id];
    while (option)
    {
        update_subject_menu(&option, selected_subject);

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
            add_subject_student(selected_subject, &selected_subject->students_count, &total_students);
            break;

        case 6:
            remove_subject_student(selected_subject, &selected_subject->students_count);
            break;

        default:
            printf("Opção Inválida!\n");
        }
    }
}

void add_subject_student(Subject *selected_subject, int *students_count, int *total_students_count)
{
    char selected_student[MAX_STR] = "";
    int selected_student_id = 0;

    if (*students_count >= MAX_STUDENTS)
    {
        printf("Turma cheia!\n");
        pause_view();
        return;
    }

    if (total_students == 0)
    {
        printf("Nao ha alunos cadastrados.\n");
        pause_view();
        return;
    }

    list_students();

    printf("Selecione um novo aluno para a disciplina: ");
    fgets(selected_student, MAX_STR, stdin);
    selected_student[strcspn(selected_student, "\n")] = '\0';

    while (1)
    {
        if (!validate_numeric_string(selected_student))
        {
            printf("ID invalido! Digite apenas numeros.\n");
            printf("Selecione um novo aluno para a disciplina: ");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }
        selected_student_id = atoi(selected_student);

        if ((selected_student_id >= *total_students_count) || (selected_student_id < 0))
        {
            printf("ID invalido! Selecione um aluno cadastrado.\n");
            printf("Selecione um novo aluno para a disciplina: ");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }

        break;
    }

    for (int i = 0; i < *students_count; i++)
    {
        if (!strcmp(selected_subject->students[i].CPF, selected_subject->students[selected_student_id].CPF))
        {
            printf("Este estudante ja cursa essa disciplina!\n");
            return;
        }
    }

    selected_subject->students[*students_count] = students[selected_student_id];
    (*students_count)++;
    printf("Aluno adicionado com sucesso!\n");
}

void remove_subject_student(Subject *selected_subject, int *students_count)
{
    if (*students_count == 0)
    {
        printf("\n----Essa turma nao possui alunos----\n");
        return;
    }

    char selected_student[MAX_STR] = "";
    int selected_student_id = 0;

    list_subject_students(students_count);
    printf("\nSelecione qual aluno deseja remover: ");
    fgets(selected_student, MAX_STR, stdin);
    selected_student[strcspn(selected_student, "\n")] = '\0';

    while (1)
    {
        if (!validate_numeric_string(selected_student))
        {
            printf("ID invalido! Digite apenas numeros.\n");
            printf("Selecione qual aluno deseja remover: ");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }
        selected_student_id = atoi(selected_student);

        if ((selected_student_id >= *students_count) || (selected_student_id < 0))
        {
            printf("ID invalido! Selecione um aluno dessa disciplina.\n");
            printf("Selecione qual aluno deseja remover: ");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }

        break;
    }

    for (int i = selected_student_id; i < *students_count - 1; i++)
    {
        selected_subject->students[i] = selected_subject->students[i + 1];
    }

    (*students_count)--;
    printf("Aluno removido com sucesso!\n");
}

void remover_subject()
{
    if (total_subjects == 0)
    {
        printf("Nao ha disciplinas cadastradas\n");
        pause_view();
        return;
    }

    list_subjects(&total_subjects);
    printf("\n");
    remover((void *)subjects, &total_subjects, sizeof(Subject));
}