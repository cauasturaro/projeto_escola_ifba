#include <stdio.h>
#include <string.h>
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
