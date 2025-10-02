#include "./disciplina.h"

//
void menu();

void addSubject(char name[MAX_STR], int code, int semester, struct Person teacher);

void updateSubject();
void addSubjectStudent(struct Subject selectedSubject);
void addSubjectTeacher(struct Subject selectedSubject);

//Funções auxiliares (testes)
void listPeople(struct Person people[TAM]);
void listSubjects();
void listSubjectStudents(struct Subject selectedSubject);
//

int main()
{
    menu();

    return 0;
}

void menu()
{
    while (option)
    {
        printf("1 - Adicionar Disciplina\n");
        printf("2 - Listar Disciplinas\n");
        printf("3 - Atualizar Disciplina\n");
        printf("4 - Remover Disciplina\n");
        printf("0 - Sair\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 0:
            return;

        case 1:
            printf("Adicionando Disciplina...\n");

            // Verificação tamanho array
            for (nSubjects = 0; subjects[nSubjects].code; nSubjects++)
                ;
            if (nSubjects >= TAM)
            {
                printf("Limite de disciplinas atingido!\n");
            }
            else
            {
                printf("Qual o nome da disciplina?\n");
                fgets(subjectName, MAX_STR, stdin);
                subjectName[strcspn(subjectName, "\n")] = '\0';

                printf("Insira o código e semestre da disciplina %s, respectivamente:\n", subjectName);
                scanf("%d %d", &subjectCode, &subjectSemester);
                getchar();

                printf("Selecione um professor para a disciplina:\n");
                listPeople(teachers);
                scanf("%d", &selectedTeacherID);
                getchar();
                struct Person selectedTeacher = teachers[selectedTeacherID - 1];

                addSubject(subjectName, subjectCode, subjectSemester, selectedTeacher);
            }
            break;

        case 2:
            listSubjects();
            break;

        case 3:
            updateSubject();
            break;
        case 4:
            printf("Removendo Disciplina...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void addSubject(char name[MAX_STR], int code, int semester, struct Person teacher)
{
    struct Subject newSubject;
    strncpy(newSubject.name, name, MAX_STR);
    newSubject.code = code;
    newSubject.semester = semester;
    newSubject.teacher = teacher;

    subjects[nSubjects] = newSubject;
}

void updateSubject()
{
    printf("Atualizando Disciplina...\n");
    listSubjects();

    int selectedSubjectID = -1;
    printf("Digite o ID da Disciplina que deseja atualizar:\n");
    scanf("%d", &selectedSubjectID);
    getchar();

    // Verificar se o ID é válido;

    struct Subject *selectedSubject = &subjects[selectedSubjectID - 1]; // ERRO AQUI. CRIA UMA CÓPIA, MAS N MUDA DINAMICAMENTE O ITEM DO ARRAY
    printf("Selecione qual campo deseja alterar\n");
    printf("1 - Nome\n");
    printf("2 - Código\n");
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
        return;

    case 1:
        printf("Digite um novo nome para a disciplina %s:\n", selectedSubject->name);

        fgets(subjectName, MAX_STR, stdin);
        subjectName[strcspn(subjectName, "\n")] = '\0';

        strncpy(selectedSubject->name, subjectName, MAX_STR);
        break;

    case 2:
        printf("Digite um novo código para a disciplina %s:\n", selectedSubject->name);

        scanf("%d", &subjectCode);
        getchar();

        selectedSubject->code = subjectCode;
        break;

    case 3:
        printf("Digite um novo semestre para a disciplina %s:\n", selectedSubject->name);
        
        scanf("%d", &subjectSemester); //n tá atualizando o código
        getchar();

        selectedSubject->semester = subjectSemester;
        break;

    case 4:
        addSubjectTeacher(*selectedSubject);
        break;

    case 5:
        addSubjectStudent(*selectedSubject);
        break;

    case 6:
        break;

    default:
        printf("Opção Inválida!\n");
    }
}

// Melhorar o nome desse parâmetro
void addSubjectTeacher(struct Subject selectedSubject)
{
    printf("Selecione um novo professor para a disciplina %s:\n", selectedSubject.name);

    int selectedTeacher = -1;
    listPeople(teachers);
    scanf("%d", &selectedTeacher);
    getchar();

    selectedSubject.teacher = teachers[selectedTeacher];
}

void addSubjectStudent(struct Subject selectedSubject)
{
    printf("Selecione um novo aluno para a disciplina %s:\n", selectedSubject.name);

    for (nStudents = 0; selectedSubject.students[nSubjects].registration; nStudents++)
        ;
    if (nStudents >= TAM)
    {
        printf("Turma cheia!");
        return;
    }

    int selectedStudent = -1;
    listPeople(students);
    scanf("%d", &selectedStudent);
    getchar();
    selectedStudent--;

    selectedSubject.students[nStudents] = students[selectedStudent];
    listSubjectStudents(selectedSubject);
}

// Funções auxiliares
void listSubjects()
{
    printf("Listando Disciplinas...\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("Disciplina #%03d:\n", i + 1);
        printf("  Nome: %s\n", subjects[i].name);
        printf("  Codigo: %d\n", subjects[i].code);
        printf("  Semestre: %d\n", subjects[i].semester);
        printf("  Professor: %d\n", subjects[i].teacher.name);
    }
};

void listPeople(struct Person people[TAM])
{
    if (people[0].name == students[0].name)
    {
        for (int i = 0; i < TAM; i++)
        {
            if (people[i].registration > -1)
            {
                printf("Aluno #%03d:\n", i + 1);
                printf("  Nome: %s\n", people[i].name);
                printf("  ID: %d\n", people[i].registration);
                printf("  Sexo: %s\n", people[i].gender);
                printf("  Data de Nascimento: %d\n", people[i].dateOfBirth);
                printf("  CPF: %d\n", people[i].cpf);
            }
        }
    }
    else
    {
        for (int i = 0; i < TAM; i++)
        {
            if (people[i].registration > -1)
            {
                printf("Professor #%03d:\n", i + 1);
                printf("  Nome: %s\n", people[i].name);
                printf("  ID: %d\n", people[i].registration);
                printf("  Sexo: %s\n", people[i].gender);
                printf("  Data de Nascimento: %d\n", people[i].dateOfBirth);
                printf("  CPF: %d\n", people[i].cpf);
            }
        }
    }
};

void listSubjectStudents(struct Subject selectedSubject)
{
    printf("Disciplina %s:\n", selectedSubject.name);
    for (int i = 0; i < TAM; i++)
    {
        if (students[i].registration < -1)
        {
            printf("Aluno #%03d:\n", i + 1);
            printf("  Nome: %s\n", selectedSubject.students[i].name);
            printf("  ID: %d\n", selectedSubject.students[i].registration);
            printf("  Sexo: %s\n", selectedSubject.students[i].gender);
            printf("  Data de Nascimento: %s\n", selectedSubject.students[i].dateOfBirth);
            printf("  CPF: %s\n", selectedSubject.students[i].cpf);
        }
    }
};