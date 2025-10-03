#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_uppercase (char str[]) { // tem função p isso já ####
    for (int i = 0; str[i] != '\0'; i++) {
            if ((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] = str[i] - 'a' + 'A';
        }
    }
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

int validate_number(char numbers[]) {
    for (int i = 0; numbers[i] != '\0'; i++) {
        if (numbers[i] < '0' || numbers[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int validate_code(char code[], int max_size) {
    int i = 0;
    int max = max_size - 2;

    int size = strlen(code);
    
    if (size != max) { return 0; }
    
    char letters[(max/2) + 1];
    char numbers[(max/2) + 1];

    for(int i = 0; i < max; i++) {
        if (i < (max/2)) {
            letters[i] = code[i];
        } else {
            numbers[i - (max/2)] = code[i];
        }
    }

    letters[(max/2)] = '\0';
    numbers[(max/2)] = '\0';

    if (!validate_name(letters) || !validate_number(numbers)) return 0;

    to_uppercase(letters);
    strncpy(code, letters, max_size);
    strcat(code, numbers);

    return 1;
}

void read_subject_name (char subjectName[], int tam_str) {    
    printf("Insira o nome da disciplina:\n");
    fgets(subjectName, tam_str, stdin);
    subjectName[strcspn(subjectName, "\n")] = '\0';
    while (!validate_name(subjectName)) {
        printf("Nome invalido! Digite apenas letras.\n");
        printf("Insira o nome da disciplina:\n");
        fgets(subjectName, tam_str, stdin);
        subjectName[strcspn(subjectName, "\n")] = '\0';
    }
    to_uppercase(subjectName);
}

void read_subject_code (char subjectCode[], int tam_code) {
    printf("Insira o codigo da disciplina (Ex.: INF019):\n");
    fgets(subjectCode, tam_code, stdin);
    subjectCode[strcspn(subjectCode, "\n")] = '\0';
    while (!validate_code(subjectCode, tam_code)) {
        printf("Codigo invalido! Siga o padrao: INF009.\n");
        printf("Insira o codigo da disciplina (Ex.: INF019):\n");
        fgets(subjectCode, tam_code, stdin);
        subjectCode[strcspn(subjectCode, "\n")] = '\0';
    }
}

void read_subject_semester (char subjectSemester[], int tam_str) {
    printf("Insira o semestre da disciplina:\n");
    fgets(subjectSemester, tam_str, stdin);
    subjectSemester[strcspn(subjectSemester, "\n")] = '\0';
    while (!validate_number(subjectSemester)) {
        printf("Semestre invalido! Digite apenas numeros.\n");
        printf("Insira o semestre da disciplina:\n");
        fgets(subjectSemester, tam_str, stdin);
        subjectSemester[strcspn(subjectSemester, "\n")] = '\0';
    }
    printf("chegou: %s", subjectSemester);
}