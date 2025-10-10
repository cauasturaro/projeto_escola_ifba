#include <stdio.h>
#include "menu.h"
#include "../utils/utils.h"

void show_menu()
{
    clear_screen();
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1 - Cadastrar estudante\n");
    printf("2 - Cadastrar professor\n");
    printf("3 - Listar estudantes\n");
    printf("4 - Listar professores\n");
    printf("5 - Modulo disciplina\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}
