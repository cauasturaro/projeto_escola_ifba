#include <stdio.h>
#include <string.h>
#define size_name 100
#define size_birth 12
#define size_cpf 16
#define max_people 100

typedef struct {
    int id;
    char name[size_name];
    char gender;
    char birth[size_birth];
    char CPF[size_cpf];
}Person;

Person students[max_people];
Person teachers[max_people];
int total_students = 0;
int total_teachers = 0;

/*para lembrar: type vai ser mudada quando for falar sobre o prof ou do aluno
type = 1 -> aluno 
type = 2 -> professor */

void register_person(int type){
    Person new_person;
    if(type == 1){
        if(total_students >= max_people){
            printf("Error! Student limit reached.\n");
            return;
        }
    }
    else if (type == 2){
        if(total_teachers >= max_people){
            printf("Error! Teacher limit reached.\n");
        return;
        }
    }
    printf("Enter the registration number: ");
    scanf("%d", &new_person.id);
    getchar();
    printf("Enter the person's name: ");
    fgets(new_person.name, size_name, stdin);
    int size = strlen (new_person.name);
    if(size > 0 && new_person.name[size - 1] == '\n'){
        new_person.name[size - 1] = '\0';
    }
    printf("Enter the gender (M/F)");
    scanf("%c", new_person.gender);
    getchar();
    printf("Enter date of birth: ");
    fgets(new_person.birth, size_birth, stdin);
    int size = strlen (new_person.birth);
    if(size > 0 && new_person.birth[size - 1] == '\n'){
        new_person.birth[size - 1] = '\0';
    }
    printf("Enter the person's CPF number:");
    fgets(new_person.CPF, size_cpf, stdin);
    int size = strlen (new_person.CPF);
    if(size > 0 && new_person.CPF[size - 1] == '\n'){
        new_person.CPF[size - 1] = '\0';
    }
    if(type == 1){
        students[total_students] = new_person;
        total_students++;
    }
    else if (type == 2){
        teachers[total_teachers] = new_person;
        total_teachers++;
    }
}