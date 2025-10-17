// FUNCIONALIDADES RELACIONADAS A MENUS EM VISUALIZAÇÃO

#ifndef MENU_H
#define MENU_H

#include "view.h"

void show_menu();
void subjects_menu(int *option);
void update_subject_menu(int *option, Subject *selected_subject);
void students_menu(int *option);
void teachers_menu(int *option);
void dev_menu_module();

#endif