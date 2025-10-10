#include "./disciplina.h"

Subject subjects[MAX_SUBJECTS];
int total_subjects = 0;

Subject *selected_subject = 0;

int selected_subject_id = -1;
int selected_teacher_id = -1;

// // TESTE
// Subject subjects[MAX_SUBJECTS] = {
//     {
//         "Anatomia",
//         "BIO101",
//         "1",
//         {"004", "Diego Santos", 'M', "05/02/1998", "55566677788"},
//         {
//             {"001", "Ana Silva", 'F', "12/03/2000", "12345678900"}
//         },
//         1
//     },
//     {
//         "Farmacologia",
//         "FAR201",
//         "3",
//         {"005", "Elisa Rocha", 'F', "19/09/2002", "99988877766"},
//         {
//             {"002", "Bruno Costa", 'M', "25/07/1999", "98765432100"},
//         },
//         1
//     },
//     {
//         "Quimica",
//         "QUI301",
//         "2",
//         {"006", "Felipe Lima", 'M', "30/12/2000", "22233344455"},
//         {
//             {"003", "Carla Souza", 'F', "10/11/2001", "11122233344"}
//         },
//         1
//     }
// };

// int total_subjects = 3;

// int selected_subject_id = -1;
// int selected_teacher_id = -1;
