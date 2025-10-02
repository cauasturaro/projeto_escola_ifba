#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR 20
#define TAM 3
struct Person
{
    int registration;
    char name[MAX_STR];
    char gender[MAX_STR];
    int dateOfBirth;
    int cpf;
};

struct Person nullPerson = {-1, "", "", -1, -1};

struct Person students[TAM] = {
    {10, "Diego Martins", "Masculino", 19930711, 444555666},
    {11, "Fernanda Alves", "Feminino", 20010725, 777888999},
    {12, "Gustavo Pereira", "Masculino", 19991201, 222333444}
};
struct Person teachers[TAM] = {
    {1, "Ana Silva", "Feminino", 19980521, 123456789},
    {2, "Bruno Souza", "Masculino", 20001015, 987654321},
    {3, "Carla Lima", "Feminino", 19951230, 111222333}
};

struct Subject
{
    char name[MAX_STR];
    int code;
    int semester;
    struct Person teacher;
    struct Person students[TAM];
};
struct Subject subjects[TAM] = {
    {"Ma", 101, 1},
    {"Fi", 202, 2}
};

int option = 1;
int nSubjects = 0;

char subjectName[MAX_STR] = "";
int subjectCode, subjectSemester;

int nStudents;

int selectedTeacherID;