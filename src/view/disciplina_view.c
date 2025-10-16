#include <stdio.h>

#include "./disciplina_view.h"
#include "../model/disciplina.h"
#include "../view/menu.h"

void list_subjects(int *subject_count)
{
    if (*subject_count == 0)
    {
        printf("Nao ha disciplinas cadastradas\n");
        return;
    }

    printf("\n------------Disciplinas------------\n");
    for (int i = 0; i < (*subject_count); i++)
    {
        printf(">#%03d | Codigo: %s | Nome: %s | Semestre: %s | Professor: %s\n",
               i + 1, subjects[i].code, subjects[i].name, subjects[i].semester, subjects[i].teacher.name);
    }
}

void list_subject_students(Subject *selected_subject, int students_count)
{
    if (!total_subjects)
    {
        printf("Nao ha disciplinas cadastradas.\n");
        return;
    }

    if (students_count == 0)
    {
        printf("%s nao possui alunos.", selected_subject->name);
        return;
    }

    printf("\n------------Alunos de %s------------\n", selected_subject->name);
    for (int i = 0; i < students_count && students[i].gender; i++)
    {
        printf("> ID: %s | Nome: %s | Genero: %c | Data de Nascimento: %s | CPF: %s\n",
               selected_subject->students[i].registration, selected_subject->students[i].name, selected_subject->students[i].gender,
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
            add_subject(&total_subjects, &total_teachers);
            break;

        case 2:
            list_subjects(&total_subjects);
            break;

        case 3:
            if (!total_subjects)
            {
                printf("Nao ha disciplinas cadastradas.\n");
            }
            else
            {
                list_subjects(&total_subjects);

                printf("Digite o ID da Disciplina que deseja listar alunos:\n");
                scanf("%d", &selected_subject_id);
                getchar();

                while ((selected_subject_id > total_subjects) || (selected_subject_id <= 0))
                {
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
