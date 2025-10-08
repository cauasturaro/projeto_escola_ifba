#include "./disciplina.h"

Subject subjects[TAM];
int total_subjects = 0;

Subject *selected_subject = 0;
char subject_name[MAX_STR] = "";
char subject_code[MAX_CODE] = "";
char subject_semester[MAX_STR] = "";

int selected_subject_id = -1;
int selected_teacher_id = -1;