#include "../models/disciplina.h"
#include "../models/disciplina.c"

//FUNÇÕES AUX
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

void listSubjects()
{
    printf("Listando Disciplinas...\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("Disciplina #%03d:\n", i + 1);
        printf("  Nome: %s\n", subjects[i].name);
        printf("  Codigo: %s\n", subjects[i].code);
        printf("  Semestre: %d\n", subjects[i].semester);
        printf("  Professor: %s\n", subjects[i].teacher.name);
    }
};
