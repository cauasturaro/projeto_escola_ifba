#include "./disciplina.h"

struct Person
{
    int registration;
    char name[MAX_STR];
    char gender[MAX_STR];
    int dateOfBirth;
    int cpf;
};

struct Subject
{
    char name[MAX_STR];
    char code[MAX_CODE];
    int semester;
    struct Person teacher;
    struct Person students[TAM];
};

struct Subject subjects[TAM];

int total_subjects = 0;
int total_teachers;

struct Subject *selectedSubject;

// campos temporários p validação antes da atrubuição ao elemento real
char subjectName[MAX_STR] = "";
char subjectCode[MAX_CODE] = "";
char subjectSemester[MAX_STR] = "";




//ARRAYS TESTE ********************************************************
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

subjects[TAM] = {
    {"Ma", "INF019", 1, 
        {1, "Ana Silva", "Feminino", 19980521, 123456789}, 
        {{10, "Diego Martins", "Masculino", 19930711, 444555666}, {11, "Fernanda Alves", "Feminino", 20010725, 777888999}}},
    {"Fi", "INF088", 2}
};