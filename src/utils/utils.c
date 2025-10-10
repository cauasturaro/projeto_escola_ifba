#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void string_to_uppercase (char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] = str[i] - 'a' + 'A'; // to_uppercase(str[i]); msm coisa
        }
    }
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear"); // Linux / macOS
#endif
}

void pause_view()
{
    printf("Pressione ENTER para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // para limpar buffer
    getchar();
}

int validate_name(char name[])
{
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
    if (len > 11 || len < 1)
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
        printf("Digite o numero de matricula: ");
        scanf("%s", id);
        getchar();
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
            printf("Matricula já cadastrada! Digite outra.\n");
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

int validate_numeric_string(char numbers[]) {
    for (int i = 0; numbers[i] != '\0'; i++) {
        if (numbers[i] < '0' || numbers[i] > '9') // ## dá p fazer um isdigit(c)? return 1 : return 0;
        {
            return 0;
        }
    }
    return 1;
}

int validate_code(char code[], int max_size) {
    int max = max_size - 2;

    int size = strlen(code);
    
    if (size != max) { return 0; }
    
    char *letters = malloc((max/2) + 1);
    char *numbers= malloc((max/2) + 1);

    for(int i = 0; i < max; i++) {
        if (i < (max/2)) {
            letters[i] = code[i];
        } else {
            numbers[i - (max/2)] = code[i];
        }
    }

    letters[(max/2)] = '\0';
    numbers[(max/2)] = '\0';

    if (!validate_name(letters) || !validate_numeric_string(numbers)) return 0;

    string_to_uppercase(letters);
    strncpy(code, letters, max_size);
    strcat(code, numbers);

    return 1;
}

void read_subject_name (char subject_name[], int tam_str) {    
    printf("Insira o nome da disciplina:\n");
    fgets(subject_name, tam_str, stdin);
    subject_name[strcspn(subject_name, "\n")] = '\0';
    while (!validate_name(subject_name)) {
        printf("Nome invalido! Digite apenas letras.\n");
        printf("Insira o nome da disciplina:\n");
        fgets(subject_name, tam_str, stdin);
        subject_name[strcspn(subject_name, "\n")] = '\0';
    }
    string_to_uppercase(subject_name);
}

void read_subject_code (char subject_code[], int tam_code) {
    printf("Insira o codigo da disciplina (Ex.: INF019):\n");
    fgets(subject_code, tam_code, stdin);
    subject_code[strcspn(subject_code, "\n")] = '\0';
    while (!validate_code(subject_code, tam_code)) {
        printf("Codigo invalido! Siga o padrao: INF009.\n");
        printf("Insira o codigo da disciplina (Ex.: INF019):\n");
        fgets(subject_code, tam_code, stdin);
        subject_code[strcspn(subject_code, "\n")] = '\0';
    }
}

void read_subject_semester (char subject_semester[], int tam_str) {
    printf("Insira o semestre da disciplina:\n");
    fgets(subject_semester, tam_str, stdin);
    subject_semester[strcspn(subject_semester, "\n")] = '\0';
    while (!validate_numeric_string(subject_semester)) {
        printf("Semestre invalido! Digite apenas numeros.\n");
        printf("Insira o semestre da disciplina:\n");
        fgets(subject_semester, tam_str, stdin);
        subject_semester[strcspn(subject_semester, "\n")] = '\0';
    }
}
