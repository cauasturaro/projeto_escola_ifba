#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "disciplina_controller.h"

void select_teacher (Person *subject_teacher, int *teachers_count) {
    char selected_teacher[MAX_STR] = "";
    int selected_teacher_id = -1;

    printf("Selecione um professor para a disciplina:\n");
    list_teachers();
    fgets(selected_teacher, MAX_STR, stdin);
    selected_teacher[strcspn(selected_teacher, "\n")] = '\0';

     while (1) {
        if (!validate_numeric_string(selected_teacher)) {
            printf("ID invalido! Digite apenas numeros.\n");
            printf("Selecione um professor para a disciplina:\n");
            fgets(selected_teacher, MAX_STR, stdin);
            selected_teacher[strcspn(selected_teacher, "\n")] = '\0';
            continue;
        }
        selected_teacher_id = atoi(selected_teacher);

        if ((selected_teacher_id >= *teachers_count) || (selected_teacher_id < 0)) {
            printf("ID invalido! Selecione um professor existente.\n");
            printf("Selecione um professor para a disciplina:\n");
            fgets(selected_teacher, MAX_STR, stdin);
            selected_teacher[strcspn(selected_teacher, "\n")] = '\0';
            continue;
        }
        selected_teacher_id = atoi(selected_teacher);

        break;
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
            if (!total_subjects) {
                printf("Nao ha disciplinas cadastradas.\n");
            } else {
                list_subjects(&total_subjects);

                printf("Digite o ID da Disciplina que deseja listar alunos:\n");
                scanf("%d", &selected_subject_id);
                getchar();

                while ((selected_subject_id > total_subjects) || (selected_subject_id  <= 0)) {
                    printf("ID invalido!\n");
                    list_subjects(&total_subjects);
                    printf("Digite o ID da disciplina que deseja listar alunos:\n");
                    scanf("%d", &selected_subject_id);
                    getchar();
                }

                selected_subject_id--;
                Subject *selected_subject = &subjects[selected_subject_id];
                list_subject_students(selected_subject, selected_subject->students_count);
            }
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
    if (!(*subjects_count)) {
        printf("Nao ha disciplinas cadastradas.\n");
        return;
    }

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
        subjects_menu(&option);

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

    if (*students_count >= MAX_STUDENTS) { 
        printf("Turma cheia!\n"); 
        return;
    }

    list_students();
    
    printf("Selecione um novo aluno para a disciplina:\n");
    fgets(selected_student, MAX_STR, stdin);
    selected_student[strcspn(selected_student, "\n")] = '\0';
    
    while (1) {
        if (!validate_numeric_string(selected_student)) {
            printf("ID invalido! Digite apenas numeros.\n");
            printf("Selecione um novo aluno para a disciplina:\n");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }
        selected_student_id = atoi(selected_student);

        if ((selected_student_id > *total_students_count) || (selected_student_id <= 0)) {
            printf("ID invalido! Selecione um aluno existente.\n");
            printf("Selecione um novo aluno para a disciplina:\n");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }
        selected_student_id = atoi(selected_student);

        break;
    }

    selected_student_id--;
    for (int i = 0; i < *students_count; i++){
        if (*selected_subject->students[i].CPF == *selected_subject->students[selected_student_id].CPF) {
            printf("Este estudante ja cursa essa disciplina!\n");
            return;
        }
    }

    selected_subject->students[*students_count] = students[selected_student_id];
    (*students_count)++;
    printf("Aluno adicionado com sucesso!\n");
}

void remove_subject_student (Subject *selected_subject, int *students_count) {
    if (*students_count == 0) {
        printf("\n----Essa turma nao possui alunos----\n");
        return;
    }

    char selected_student[MAX_STR] = "";
    int selected_student_id = 0;

    list_subject_students(selected_subject, *students_count);
    printf("Selecione qual aluno deseja remover:\n");
    fgets(selected_student, MAX_STR, stdin);
    selected_student[strcspn(selected_student, "\n")] = '\0';

    while (1) {
        if (!validate_numeric_string(selected_student)) {
            printf("ID invalido! Digite apenas numeros.\n");
            printf("Selecione qual aluno deseja remover:\n");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }
        selected_student_id = atoi(selected_student);

        printf("\nn tem letra, aluno %d\n", selected_student_id);
        if ((selected_student_id > *students_count) || (selected_student_id <= 0)) {
            printf("ID invalido! Selecione um aluno dessa disciplina.\n");
            printf("Selecione qual aluno deseja remover:\n");
            fgets(selected_student, MAX_STR, stdin);
            selected_student[strcspn(selected_student, "\n")] = '\0';
            continue;
        }
        selected_student_id = atoi(selected_student);
        
        break;
    }

    selected_student_id--;
    for (int i = selected_student_id; i < *students_count; i++) {
        selected_subject->students[i] = selected_subject->students[i];
    }

    (*students_count)--;
    printf("Aluno removido com sucesso!\n");
}
