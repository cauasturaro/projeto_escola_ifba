#ifndef PESSOA_H
#define PESSOA_H

#define SIZE_ID 12
#define SIZE_NAME 100
#define SIZE_BIRTH 11
#define SIZE_CPF 16
#define MAX_PEOPLE 100

typedef struct
{
    char id[SIZE_ID];
    char name[SIZE_NAME];
    char gender;
    char birth[SIZE_BIRTH];
    char CPF[SIZE_CPF];
} Person;

extern Person students[MAX_PEOPLE];
extern Person teachers[MAX_PEOPLE];
extern int total_students;
extern int total_teachers;

#endif
