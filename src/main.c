#include <stdio.h>
#include "menu.h"

#include "disciplina_controller.h"
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
            clear_screen();
            register_person(1);
            list_students();

            break;
        case 2:
            clear_screen();
            register_person(2);
            break;
        case 3:
            clear_screen();
            list_students();
            pause_view();
            break;
        case 4:
            clear_screen();
            list_teachers();
            pause_view();
            break;
        case 5:
            clear_screen();
            subject_module();
            pause_view();
            break;
        case 0:
            clear_screen();
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
