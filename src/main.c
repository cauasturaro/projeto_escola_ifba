#include <stdio.h>
#include "menu.h"

#include "../view/disciplina_view.h"
#include "../view/pessoa_view.h"

#include "pessoa_controller.h"
#include "pessoa_view.h"
#include "utils.h"

int main()
{
    int opcao = 1;
    while (opcao)
    {
        show_menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            clear_screen();
            students_module();
            break;
        case 2:
            clear_screen();
            teachers_module();
            break;
        case 3:
            clear_screen();
            subject_module();
            break;
        case 0:
            clear_screen();
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
