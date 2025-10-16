// FUNCIONALIDADES RELACIONADAS A MENUS EM VISUALIZAÇÃO

#ifndef MENU_H
#define MENU_H

#include "../model/pessoa.h"
#include "../model/disciplina.h"
#include "../utils/utils.h"

void show_menu();
void subjects_menu(int *option);
void update_subject_menu(int *option, Subject *selected_subject);
void students_menu(int *option);
void teachers_menu(int *option);

#endif