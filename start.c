#include <stdio.h>
#include <string.h>
#define size_id 12
#define size_name 100
#define size_birth 11
#define size_cpf 16
#define max_people 100

typedef struct {
    char id[size_id];
    char name[size_name];
    char gender;
    char birth[size_birth];
    char CPF[size_cpf];
}Person;

Person students[max_people];
Person teachers[max_people];
int total_students = 0;
int total_teachers = 0;

int validate_name(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        char c = name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' '))) {
            return 0; 
        }
    }
    return 1; 
}

int validate_gender(char g) {
    return (g == 'M' || g == 'F' || g == 'm' || g == 'f');
}

int validate_cpf(char cpf[]) {
    int len = strlen(cpf);

    if (len != 11) return 0; 

    for (int i = 0; i < len; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return 0;
        }
    }
    return 1; 
}

int validate_ID(char id[]){
    int len = strlen(id);
    if(len > 11 || len < 1) return 0;

    for(int i = 0; i < len; i++){
        if(id[i] < '0' || id[i] > '9'){
            return 0;
        }
    }
    return 1;
}

int validate_birth(char birth[]){
    if(strlen(birth) != 10) return 0;
    if(birth[2] != '/' || birth[5] != '/') return 0;

    int day = (birth[0] - '0') * 10 + (birth[1] - '0');
    int month = (birth[3] - '0') * 10 + (birth[4] - '0');
    int year = (birth[6] - '0') * 1000 + (birth[7] - '0') * 100 + (birth[8] - '0') * 10 + (birth[9] - '0');

    
    if(day < 1 || day > 31) return 0;
    if(month < 1 || month > 12) return 0;
    if(year < 1900 || year > 2100) return 0;

    return 1;
}

void read_id (char id[]){
    printf("Enter the registration number: ");
    scanf("%s", id);
    getchar();
    while(!validate_ID(id)){
        printf("Invalid ID! Please enter again: ");
        scanf("%s", id);
        getchar();
    }
}

void read_name (char name[]){
    printf("Enter the person's name: ");
    fgets(name, size_name, stdin);
    int size = strlen (name);
    if(size > 0 && name[size - 1] == '\n'){
        name[size - 1] = '\0';
    }

    while (!validate_name(name)){
        printf("Invalid name! Please enter only letters: ");
        fgets(name, size_name, stdin);
        size = strlen (name);
        if(size > 0 && name[size - 1] == '\n'){
        name[size - 1] = '\0';
        }
    }
}

char read_gender() {
    char g;
    printf("Enter the gender (M/F): ");
    scanf("%c", &g);
    getchar();
    if (g >= 'a' && g <= 'z') {
        g = g - 'a' + 'A';
    }
    while(!validate_gender(g)){
        printf("Invalid gender! Enter M or F: ");
        scanf("%c", &g);
        getchar();
    }
    return g;
}

void read_birth (char birth[]){
    printf("Enter date of birth (DD/MM/YYYY): ");
    fgets(birth, size_birth, stdin);
    int size = strlen (birth);
    if(size > 0 && birth[size - 1] == '\n'){
        birth[size - 1] = '\0';
    }
    while(!validate_birth(birth)){
        printf("Invalid birth! Please enter again: ");
        fgets(birth, size_birth, stdin);
        size = strlen (birth);
        if(size > 0 && birth[size - 1] == '\n'){
            birth[size - 1] = '\0';
        }
    }
}

void read_cpf (char cpf[]){
    printf("Enter the person's CPF number (only numbers): ");
    scanf("%s", cpf);
    getchar();
    while(!validate_cpf(cpf)){
        printf("Invalid CPF! Please enter again: ");
        scanf("%s", cpf);
        getchar();
    }
}

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

    printf("\nRegistering a new person. \n"); 

    read_id(new_person.id);

    read_name(new_person.name);

    new_person.gender = read_gender();

    read_birth(new_person.birth);

    read_cpf(new_person.CPF);

    if(type == 1){
        students[total_students] = new_person;
        total_students++;
        printf("Student successfully registered.\n\n");
    }
    else if (type == 2){
        teachers[total_teachers] = new_person;
        total_teachers++;
        printf("Successfully registered teacher.\n\n");
    }
}

void list_students(){
    printf("\nStudents\n");
    for(int i=0; i<total_students; i++){
        printf("> ID: %s | Name: %s | Gender: %c | Birth: %s | CPF: %s\n",
               students[i].id, students[i].name, students[i].gender,
               students[i].birth, students[i].CPF);
    }
}

void list_teachers(){
    printf("\nTeachers\n");
    for(int i=0; i<total_teachers; i++){
        printf("> ID: %s | Name: %s | Gender: %c | Birth: %s | CPF: %s\n",
               teachers[i].id, teachers[i].name, teachers[i].gender,
               teachers[i].birth, teachers[i].CPF);
    }
}


void update_person(Person array[], int total) {
    char id[size_id];
    printf("Enter the ID for the update: ");
    scanf("%s", id);
    getchar();

    int index = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(array[i].id, id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ID not found.\n");
        return;
    }

    int option = 0;
    do {
        printf("Updating ID %s.\n", array[index].id);
        printf("1 - Change name\n");
        printf("2 - Change gender\n");
        printf("3 - Change birthday\n");
        printf("4 - Change CPF\n");
        printf("0 - Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar();
        printf("\n");

        switch (option) {
            case 1: {
                char temp[size_name];
                printf("Enter new name: ");
                fgets(temp, size_name, stdin);
                int len = strlen(temp);
                if (len > 0 && temp[len - 1] == '\n') temp[len - 1] = '\0';

                if (validate_name(temp)) {
                    strcpy(array[index].name, temp);
                } else {
                    printf("Invalid name!\n");
                }
                break;
            }
            case 2: {
                char g;
                printf("Enter new gender (M/F): ");
                scanf("%c", &g);
                getchar();

                if (g >= 'a' && g <= 'z') {
                    g = g - 'a' + 'A';
                }
                if (validate_gender(g)) {
                    array[index].gender = g;
                } else {
                    printf("Invalid gender!\n");
                }
                break;
            }
            case 3: {
                char temp[size_birth];
                printf("Enter new date of birth (DD/MM/YYYY): ");
                fgets(temp, size_birth, stdin);
                int len = strlen(temp);
                if (len > 0 && temp[len - 1] == '\n') temp[len - 1] = '\0';

                if (validate_birth(temp)) {
                    strcpy(array[index].birth, temp);
                } else {
                    printf("Invalid date of birth!\n");
                }
                break;
            }
            case 4: {
                char temp[size_cpf];
                printf("Enter new CPF (only numbers): ");
                scanf("%s", temp);
                getchar();
                while(!validate_cpf(temp)){
                    printf("Invalid CPF! Please enter again: ");
                    scanf("%s", temp);
                    getchar();
                }
                strcpy(array[index].CPF, temp);
                break;
            }
            case 0:
                printf("No updates.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 0);
}

/*
para atualizar o cadastro de alunos vai ser puxada a função update_person(students, total_students);
para atualizar o cadastro de professores vai ser puxada a função update_person(teachers, total_teachers);
*/

int main(){
    register_person(1);
    list_students();
    update_person(students, total_students);
    list_students();
    return 0;
}

/* 
    no menu, quando for registrar o aluno vai ser puxada a função register_person(1)
    quando for registrar o professor vai ser puxado a função register_person(2)

*/