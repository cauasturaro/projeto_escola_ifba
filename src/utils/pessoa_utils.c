#include "pessoa_utils.h"

void read_cpf(char cpf[], int type, int ignore_index)
{
    char temp[SIZE_CPF];
    while (1)
    {
        printf("Digite o CPF (apenas numeros): ");
        scanf("%s", temp);
        getchar();
        if (!validate_cpf(temp))
        {
            printf("CPF invalido! Digite novamente.\n");
            continue;
        }
        int duplicate = 0;
        if (type == 1)
        {
            for (int i = 0; i < total_students; i++)
            {
                if (i != ignore_index && strcmp(students[i].CPF, temp) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }
        }
        else if (type == 2)
        {
            for (int i = 0; i < total_teachers; i++)
            {
                if (i != ignore_index && strcmp(teachers[i].CPF, temp) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }
        }
        if (duplicate)
        {
            printf("CPF já cadastrado! Digite outro.\n");
            continue;
        }
        strcpy(cpf, temp);
        break;
    }
}

int validate_name(char name[])
{
    if (strlen(name) == 0)
        return 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        char c = name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')))
        {
            return 0;
        }
    }
    return 1;
}

int validate_gender(char g)
{
    return (g == 'M' || g == 'F' || g == 'm' || g == 'f');
}

int validate_cpf(char cpf[])
{
    int len = strlen(cpf);
    return len == 11;
}

int validate_registration(char id[])
{
    int len = strlen(id);
    if (len != 11)
        return 0;
    for (int i = 0; i < len; i++)
    {
        if (id[i] < '0' || id[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int validate_birth(char birth[])
{
    if (strlen(birth) != 10)
        return 0;
    if (birth[2] != '/' || birth[5] != '/')
        return 0;
    int day = (birth[0] - '0') * 10 + (birth[1] - '0');
    int month = (birth[3] - '0') * 10 + (birth[4] - '0');
    int year = (birth[6] - '0') * 1000 + (birth[7] - '0') * 100 + (birth[8] - '0') * 10 + (birth[9] - '0');
    if (day < 1 || day > 31)
        return 0;
    if (month < 1 || month > 12)
        return 0;
    if (year < 1900 || year > 2100)
        return 0;
    return 1;
}

void read_registration(char id[], int type)
{
    while (1)
    {
        printf("Digite o numero de matricula (11 dígitos): ");
        fgets(id, 100, stdin);
        id[strcspn(id, "\n")] = 0;

        if (strlen(id) == 0)
        {
            printf("Matricula vazia! Digite novamente.\n");
            continue;
        }

        if (!validate_registration(id))
        {
            printf("Matricula invalida! Digite novamente.\n");
            continue;
        }
        int duplicate = 0;
        if (type == 1)
        {
            for (int i = 0; i < total_students; i++)
            {
                if (strcmp(students[i].registration, id) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }
        }
        else if (type == 2)
        {
            for (int i = 0; i < total_teachers; i++)
            {
                if (strcmp(teachers[i].registration, id) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }
        }
        if (duplicate)
        {
            printf("Matricula ja cadastrada! Digite outra.\n");
            continue;
        }
        break;
    }
}

void read_name(char name[])
{
    printf("Digite o nome da pessoa: ");
    fgets(name, SIZE_NAME, stdin);
    int size = strlen(name);
    if (size > 0 && name[size - 1] == '\n')
    {
        name[size - 1] = '\0';
    }
    while (!validate_name(name))
    {
        printf("Nome invalido! Digite apenas letras: ");
        fgets(name, SIZE_NAME, stdin);
        size = strlen(name);
        if (size > 0 && name[size - 1] == '\n')
        {
            name[size - 1] = '\0';
        }
    }
}

char read_gender()
{
    char g;
    printf("Digite o sexo (M/F): ");
    scanf("%c", &g);
    getchar();
    if (g >= 'a' && g <= 'z')
    {
        g = g - 'a' + 'A';
    }
    while (!validate_gender(g))
    {
        printf("Sexo invalido! Digite M ou F: ");
        scanf("%c", &g);
        getchar();
    }
    return g;
}

void read_birth(char birth[])
{
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    fgets(birth, SIZE_BIRTH, stdin);
    int size = strlen(birth);
    if (size > 0 && birth[size - 1] == '\n')
    {
        birth[size - 1] = '\0';
    }
    while (!validate_birth(birth))
    {
        printf("Data invalida! Digite novamente (DD/MM/AAAA): ");
        fgets(birth, SIZE_BIRTH, stdin);
        size = strlen(birth);
        if (size > 0 && birth[size - 1] == '\n')
        {
            birth[size - 1] = '\0';
        }
    }
}