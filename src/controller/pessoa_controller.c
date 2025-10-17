#include "pessoa_controller.h"

void register_person(int type)
{
    Person new_person;

    if (type == 1)
    {
        if (total_students >= MAX_PEOPLE)
        {
            printf("Erro! Limite de estudantes atingido.\n");
            return;
        }
    }
    else if (type == 2)
    {
        if (total_teachers >= MAX_PEOPLE)
        {
            printf("Erro! Limite de professores atingido.\n");
            return;
        }
    }

    printf("\nRegistrando uma nova pessoa. \n");

    read_registration(new_person.registration, type);
    read_name(new_person.name);
    new_person.gender = read_gender();
    read_birth(new_person.birth);
    read_cpf(new_person.CPF, type, -1);

    if (type == 1)
    {
        students[total_students++] = new_person;
        printf("Estudante registrado com sucesso.\n\n");
    }
    else if (type == 2)
    {
        teachers[total_teachers++] = new_person;
        printf("Professor registrado com sucesso.\n\n");
    }
}

void update_person(Person array[], int total, int type)
{
    char id[SIZE_REGISTRATION];
    printf("Digite a matricula para atualizacao: ");
    scanf("%s", id);
    getchar();

    int index = -1;
    for (int i = 0; i < total; i++)
    {
        if (strcmp(array[i].registration, id) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Matricula nao encontrada.\n");
        return;
    }

    int option = 0;
    do
    {
        printf("Atualizando a matricula %s.\n", array[index].registration);
        printf("1 - Atualizar nome\n");
        printf("2 - Atualizar genero\n");
        printf("3 - Atualizar data de aniversario\n");
        printf("4 - Atualizar CPF\n");
        printf("0 - Sair\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {
            char temp[SIZE_NAME];
            read_name(temp);
            strcpy(array[index].name, temp);
            break;
        }
        case 2:
        {
            char g = read_gender();
            array[index].gender = g;
            break;
        }
        case 3:
        {
            char temp[SIZE_BIRTH];
            read_birth(temp);
            strcpy(array[index].birth, temp);
            break;
        }
        case 4:
        {
            read_cpf(array[index].CPF, type, index);
            break;
        }
        case 0:
            printf("Saindo das atualizacoes.\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (option != 0);
}

void remover_student()
{
    list_students();
    printf("\n");
    printf("Digite o ID do aluno a ser removido: ");
    remover((void *)students, &total_students, sizeof(Person));
}

void remover_teacher()
{
    list_teachers();
    printf("\n");
    printf("Digite o ID do professor a ser removido: ");
    remover((void *)teachers, &total_teachers, sizeof(Person));
}

void birthdays_by_month(){
    int month;
    
    printf("Digite o mes para ver os aniversariantes (1-12): ");
    scanf("%d", &month);
    
    if(month < 1 || month > 12){
        printf("Mes invalido.\n");
        return;
    }
    
    printf("\n=== Aniversariantes do mes %02d ===\n", month);
    int found = 0;
    
    for (int i = 0; i < total_students; i++)
    {
        int birth_month = (students[i].birth[3] - '0') * 10 + (students[i].birth[4] - '0');

        if (birth_month == month)
        {
            printf("Estudante: %s | Nascimento: %s\n", students[i].name, students[i].birth);
            found = 1;
        }
    }

    for (int i = 0; i < total_teachers; i++)
    {
        int birth_month = (teachers[i].birth[3] - '0') * 10 + (teachers[i].birth[4] - '0');

        if (birth_month == month)
        {
            printf("Professor: %s | Nascimento: %s\n", teachers[i].name, teachers[i].birth);
            found = 1;
        }
    }

    if (!found)
        printf("Nenhum aniversariante encontrado neste mes.\n");
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
}

void search_by_name(){
    char search[100];
    int found = 0;

    printf("Digite pelo menos 3 letras do nome a ser buscado: ");
    scanf(" %[^\n]", search);

    if (strlen(search) < 3) {
        printf("Você deve digitar pelo menos 3 letras.\n");
        return;
    }
    to_lowercase(search); 

    printf("\n======== Resultados da busca por '%s' ========\n", search);

    int printed_students = 0;
    for (int i = 0; i < total_students; i++) {
        char name_copy[100];
        strcpy(name_copy, students[i].name);
        to_lowercase(name_copy);

        if (strstr(name_copy, search)) {
            if (!printed_students) {
            printf("\nAlunos:\n");
            printed_students = 1;
            }
            printf("> Nome: %s, Matricula: %s\n", students[i].name, students[i].registration);
            found = 1;
        }
    }

    int printed_teachers = 0;
    for (int i = 0; i < total_teachers; i++) {
        char name_copy[100];
        strcpy(name_copy, teachers[i].name);
        to_lowercase(name_copy);

        if (strstr(name_copy, search)) {
            if(!printed_teachers) {
                printf("\nProfessores:\n");
                printed_teachers = 1;
            }
            printf("> Nome: %s, Matricula: %s\n", teachers[i].name, teachers[i].registration);
            found = 1;
        }
    }
    if (!found) printf("Nenhuma pessoa encontrada com essas letras.\n");
}