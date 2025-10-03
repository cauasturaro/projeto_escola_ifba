#include "../models/disciplina.h"
#include "../models/disciplina.c"

void subjectModule()
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
                addSubject(); }
            break;

        case 2:
            listSubjects();
            break;

        case 3:
            listSubjects();
            break;

        case 4:
            updateSubject();
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

void addSubject()
{
    selectedSubject = &subjects[total_subjects];

    printf("Adicionando Disciplina...\n");
    
    read_subject_name(subjectName, MAX_STR);
    read_subject_code(subjectCode, MAX_CODE);
    read_subject_semester(subjectSemester, MAX_STR);

    int selectedTeacherID = -1;
    printf("Selecione um professor para a disciplina:\n");
    listPeople(teachers);
    scanf("%d", &selectedTeacherID);
    getchar();

    for (total_teachers = 0; teachers[total_teachers].registration; total_teachers++);
    while ((selectedTeacherID > total_teachers) || (selectedTeacherID  <= 0)) {
        printf("ID invalido!\n");
        printf("Selecione um professor para a disciplina:\n");
        listPeople(teachers);
        scanf("%d", &selectedTeacherID);
        getchar();
    }
    selectedTeacherID--;

    struct Subject newSubject;
    strncpy(newSubject.name, subjectName, MAX_STR);
    strncpy(newSubject.code, subjectCode, MAX_CODE);
    newSubject.semester = atoi(subjectSemester);
    newSubject.teacher = teachers[selectedTeacherID];
    *selectedSubject = newSubject;
}

void updateSubject()
{
    int option = 1;
    int selectedTeacherID = -1;
    int selectedSubjectID = -1;

    printf("Atualizando Disciplina...\n");
    listSubjects();

    printf("Digite o ID da Disciplina que deseja atualizar:\n");
    scanf("%d", &selectedSubjectID);
    getchar();
    for (total_subjects = 0; subjects[total_subjects].semester; total_subjects++);
    while ((selectedSubjectID > total_subjects) || (selectedSubjectID  <= 0)) {
        printf("ID invalido!\n");
        printf("Digite o ID da Disciplina que deseja atualizar:\n");
        listSubjects();
        scanf("%d", &selectedSubjectID);
        getchar();
    }
    selectedSubjectID--;

    selectedSubject = &subjects[selectedSubjectID];
    while (option)
    {
        printf("Atualizando disciplina %s...\n", selectedSubject->name);
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
            printf("Saindo de Atualizar disciplina %s...\n", selectedSubject->name);
            return;

        case 1:
            read_subject_name(subjectName, MAX_STR);
            strncpy(selectedSubject->name, subjectName, MAX_STR);
            break;

        case 2:
            read_subject_code(subjectCode, MAX_CODE);
            strncpy(selectedSubject->code, subjectCode, MAX_STR);
            break;

        case 3:
            read_subject_semester(subjectSemester, MAX_STR);
            selectedSubject->semester = atoi(subjectSemester);
            break;

        case 4:
            printf("Selecione um professor para a disciplina:\n");
            listPeople(teachers);
            scanf("%d", &selectedTeacherID);
            getchar();

            for (total_teachers = 0; teachers[total_teachers].registration; total_teachers++);
            while ((selectedTeacherID > total_teachers) || (selectedTeacherID  <= 0)) {
                printf("ID invalido!\n");
                printf("Selecione um professor para a disciplina:\n");
                listPeople(teachers);
                scanf("%d", &selectedTeacherID);
                getchar();
            }
            selectedTeacherID--;

            selectedSubject->teacher = teachers[selectedTeacherID];
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

