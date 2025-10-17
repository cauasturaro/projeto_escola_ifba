#include <stdio.h>
#include "./disciplina_view.h"

void list_subjects(int *subject_count)
{
    if (*subject_count == 0)
    {
        printf("Nao ha disciplinas cadastradas\n");
        return;
    }

    list("========== DISCIPLINAS ==========", subjects, total_subjects, sizeof(Subject), subjectListagemAdapter);
}

void list_subject_students(int *subject_count)
{
    if (!total_subjects)
    {
        printf("Nao ha disciplinas cadastradas.\n");
        return;
    }

    list_subjects(subject_count);

    printf("Digite o ID da Disciplina que deseja listar alunos:\n");
    scanf("%d", &selected_subject_id);
    getchar();

    while ((selected_subject_id >= total_subjects) || (selected_subject_id < 0))
    {
        printf("ID invalido!\n");
        list_subjects(subject_count);
        printf("Digite o ID da disciplina que deseja listar alunos:\n");
        scanf("%d", &selected_subject_id);
        getchar();
    }

    Subject *selected_subject = &subjects[selected_subject_id];

    if ((selected_subject->students_count) == 0)
    {
        clear_screen();
        printf("%s Nao possui alunos.\n\n", selected_subject->name);
        return;
    }

    printf("\n========== ALUNOS DE %s ==========\n", selected_subject->name);
    for (int i = 0; i < selected_subject->students_count; i++)
    {
        printf("> ID: %d | Matricula: %s | Nome: %s | Genero: %c | Data de Nascimento: %s | CPF: %s\n",
               i, selected_subject->students[i].registration, selected_subject->students[i].name, selected_subject->students[i].gender,
               selected_subject->students[i].birth, selected_subject->students[i].CPF);
    }
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
            clear_screen();
            add_subject(&total_subjects, &total_teachers);
            pause_view_without_clear_buffer();
            break;

        case 2:
            clear_screen();
            list_subjects(&total_subjects);
            pause_view_without_clear_buffer();
            break;

        case 3:
            clear_screen();
            list_subject_students(&total_subjects);
            pause_view_without_clear_buffer();
            break;
        case 4:
            clear_screen();
            listar_ordenado_subject_module();
            break;

        case 5:
            clear_screen();
            update_subject(&total_subjects, &total_teachers);
            pause_view();
            break;

        case 6:
            clear_screen();
            remover_subject();
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void listar_ordenado_subject_module()
{
    if (total_subjects == 0)
    {
        printf("Nao ha disciplinas cadastradas\n");
        return;
    }

    int option = 1;
    while (option)
    {
        printf("======== SELECIONE A OPCAO DE FILTRAGEM ========\n");
        printf("1 - Nome\n");
        printf("2 - Codigo\n");
        printf("3 - Semestre\n");
        printf("4 - Quantidade de Alunos\n");
        printf("0 - Sair");
        printf("\n=============================================\n");

        scanf("%d", &option);
        getchar();

        clear_screen();

        switch (option)
        {
        case 0:
            printf("Saindo de Listar Filtrado...\n");
            return;

        case 1:
            ordenar(subjects, total_subjects, sizeof(Subject), subjectSortAdapter, SORT_BY_NAME);
            list("======== DADOS FILTRADOS POR NOME ========", subjects, total_subjects, sizeof(Subject), subjectListagemAdapter);
            break;

        case 2:
            ordenar(subjects, total_subjects, sizeof(Subject), subjectSortAdapter, SORT_BY_CODE);
            list("======== DADOS FILTRADOS POR CODIGO ========", subjects, total_subjects, sizeof(Subject), subjectListagemAdapter);
            break;
        case 3:
            ordenar(subjects, total_subjects, sizeof(Subject), subjectSortAdapter, SORT_BY_SEMESTER);
            list("======== DADOS FILTRADOS POR SEMESTRE ========", subjects, total_subjects, sizeof(Subject), subjectListagemAdapter);
            break;
        case 4:
            ordenar(subjects, total_subjects, sizeof(Subject), subjectSortAdapter, SORT_BY_STUDENT_COUNT);
            list("======== DADOS FILTRADOS POR QUANTIDADE DE ALUNOS ========", subjects, total_subjects, sizeof(Subject), subjectListagemAdapter);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}