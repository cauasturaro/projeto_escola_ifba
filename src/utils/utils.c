#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

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

void string_to_uppercase (char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] = str[i] - 'a' + 'A'; // to_uppercase(str[i]); msm coisa
        }
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
    printf("chegou: %s", subject_semester);
}
