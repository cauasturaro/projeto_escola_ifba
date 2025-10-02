#include <stdio.h>
#include "controller/pessoa_controller.h"
#include "view/pessoa_view.h"

int main()
{
    register_person(1);
    list_students();
    update_person(students, total_students, 1);
    list_students();
    return 0;
}
