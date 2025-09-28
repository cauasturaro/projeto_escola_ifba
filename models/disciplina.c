#include <ctype.h>
#include <stdio.h>
#include <string.h>
// #include "../view/disciplina_view.c"
#include "./disciplina.h"

void addSubject (struct Subject array[TAM], char name[MAX_STR], int code, int semester);

void menu() // erro ao colocar em outro arquivo, loop infinito e não executa co scanf
{
    int option = 1;

    while (option)
    {
        printf("1 - Adicionar Disciplina\n");
        printf("2 - Listar Disciplinas\n");
        printf("3 - Atualizar Disciplina\n");
        printf("4 - Remover Disciplina\n");
        printf("5 - Adicionar Aluno à Disciplina\n"); // Conflito com a crase
        printf("6 - Remover Aluno\n");
        printf("0 - Sair\n");
        scanf("%d", &option);

            switch (option)
            {
            case 0:
                return;

            case 1:
                printf("Adicionando Disciplina...\n");
                break;

            case 2:
                printf("Listando Disciplinas...\n");
                break;

            case 3:
                printf("Atualizando Disciplina...\n");
                break;

            case 4:
                printf("Removendo Disciplina...\n");
                break;

            case 5:
                printf("Adicionando Aluno à Disciplina...\n");
                break;

            case 6:
                printf("Removendo Aluno da Disciplina...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}

int main()
{
    struct Subject subjects[TAM] = {
        {"Ma", 101, 1},
        {"Fi", 202, 2}
    };

    addSubject(subjects, "Port", 001, 2);
    
    for (int i = 0; i < TAM; i++) {
        printf("Disciplina %d:\n", i);
        printf("  Nome: %s\n", subjects[i].name);
        printf("  Codigo: %d\n", subjects[i].code);
        printf("  Semestre: %d\n\n", subjects[i].semester);
    }

    return 0;
}

void addSubject (struct Subject array[TAM], char name[MAX_STR], int code, int semester) {
    int iCont;
    
    int nSubjects;
    for (nSubjects = 0; array[nSubjects].code; nSubjects++) {}

    if (nSubjects > TAM) {
        printf("Limite de disciplinas atingido!");
        return;
    }

    struct Subject newSubject;
    strncpy(newSubject.name, name, MAX_STR); // É a melhor função??
    newSubject.code = code;
    newSubject.semester = semester;

    array[nSubjects] = newSubject;
}