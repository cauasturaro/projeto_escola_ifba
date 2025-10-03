#include <stdio.h>
#include "menu.h"
#include "pessoa_controller.h"
#include "pessoa_view.h"
#include "utils.h"

int main()
{
    int opcao;
    do
    {
        show_menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            register_person(1);
            list_students();

            break;
        case 2:
            register_person(2);
            break;
        case 3:
            list_students();
            pause_view();
            break;
        case 4:
            list_teachers();
            pause_view();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
