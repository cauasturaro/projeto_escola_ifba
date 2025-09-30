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

void read_id(char id[], int type){
    while(1) {
        printf("Digite o numero de matricula: ");
        scanf("%s", id);
        getchar();

        if (!validate_ID(id)) {
            printf("Matricula invalida! Digite novamente.\n");
            continue;
        }

        int duplicate = 0;
        if (type == 1) { 
            for(int i = 0; i < total_students; i++){
                if(strcmp(students[i].id, id) == 0){
                    duplicate = 1;
                    break;
                }
            }
        } else if (type == 2) { 
            for(int i = 0; i < total_teachers; i++){
                if(strcmp(teachers[i].id, id) == 0){
                    duplicate = 1;
                    break;
                }
            }
        }

        if(duplicate){
            printf("ID já cadastrado! Digite outro.\n");
            continue;
        }

        break; 
    }
}

void read_name (char name[]){
    printf("Digite o nome da pessoa: ");
    fgets(name, size_name, stdin);
    int size = strlen (name);
    if(size > 0 && name[size - 1] == '\n'){
        name[size - 1] = '\0';
    }

    while (!validate_name(name)){
        printf("Nome invalido! Digite apenas letras: ");
        fgets(name, size_name, stdin);
        size = strlen (name);
        if(size > 0 && name[size - 1] == '\n'){
        name[size - 1] = '\0';
        }
    }
}

char read_gender() {
    char g;
    printf("Digite o sexo (M/F): ");
    scanf("%c", &g);
    getchar();
    if (g >= 'a' && g <= 'z') {
        g = g - 'a' + 'A';
    }
    while(!validate_gender(g)){
        printf("Sexo invalido! Digite M ou F: ");
        scanf("%c", &g);
        getchar();
    }
    return g;
}

void read_birth (char birth[]){
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    fgets(birth, size_birth, stdin);
    int size = strlen (birth);
    if(size > 0 && birth[size - 1] == '\n'){
        birth[size - 1] = '\0';
    }
    while(!validate_birth(birth)){
        printf("Data invalida! Digite novamente (DD/MM/AAAA): ");
        fgets(birth, size_birth, stdin);
        size = strlen (birth);
        if(size > 0 && birth[size - 1] == '\n'){
            birth[size - 1] = '\0';
        }
    }
}

void read_cpf(char cpf[], int type, int ignore_index) {
    char temp[size_cpf];

    while(1){
        printf("Digite o CPF (apenas numeros): ");
        scanf("%s", temp);
        getchar();

        if(!validate_cpf(temp)){
            printf("CPF invalido! Digite novamente.\n");
            continue;
        }

        int duplicate = 0;
        if(type == 1){
            for(int i = 0; i < total_students; i++){
                if(i != ignore_index && strcmp(students[i].CPF, temp) == 0){
                    duplicate = 1;
                    break;
                }
            }
        } else if(type == 2){
            for(int i = 0; i < total_teachers; i++){
                if(i != ignore_index && strcmp(teachers[i].CPF, temp) == 0){
                    duplicate = 1;
                    break;
                }
            }
        }

        if(duplicate){
            printf("CPF já cadastrado! Digite outro.\n");
            continue;
        }

        strcpy(cpf, temp);
        break;
    }
}

void register_person(int type){
    Person new_person;
    if(type == 1){
        if(total_students >= max_people){
            printf("Erro! Limite de estudantes atingido.\n");
            return;
        }
    }
    else if (type == 2){
        if(total_teachers >= max_people){
            printf("Erro! Limite de estudantes atingido.\n");
        return;
        }
    }

    printf("\nRegistrando uma nova pessoa. \n"); 

    read_id(new_person.id, type);

    read_name(new_person.name);

    new_person.gender = read_gender();

    read_birth(new_person.birth);

    read_cpf(new_person.CPF, type, -1);

    if(type == 1){
        students[total_students] = new_person;
        total_students++;
        printf("Estudante registrado com sucesso.\n\n");
    }
    else if (type == 2){
        teachers[total_teachers] = new_person;
        total_teachers++;
        printf("Professor registrado com sucesso.\n\n");
    }
}

void list_students(){
    printf("\nEstudantes\n");
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


void update_person(Person array[], int total, int type) {
    char id[size_id];
    printf("Digite o ID para atualizacao: ");
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
        printf("ID nao encontrado.\n");
        return;
    }

    int option = 0;
    do {
        printf("Atualizando o ID %s.\n", array[index].id);
        printf("1 - Atualizar nome\n");
        printf("2 - Atualizar genero\n");
        printf("3 - Atualizar data de aniversario\n");
        printf("4 - Atualizar CPF\n");
        printf("0 - Sair\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &option);
        getchar();
        printf("\n");

        switch (option) {
            case 1: {
                char temp[size_name];
                read_name(temp); 
                strcpy(array[index].name, temp);
                break;
            }
            case 2: {
                char g = read_gender(); 
                array[index].gender = g; 
                break;
            }
            case 3: {
                char temp[size_birth];
                read_birth(temp);
                strcpy(array[index].birth, temp);
                break;
            }
            case 4: {
                read_cpf(array[index].CPF, type, index);
                break;
            }
            case 0:
                printf("Saindo das atualizacoes.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
     } while (option != 0);
}

/*
para atualizar o cadastro de alunos vai ser puxada a função update_person(students, total_students, 1);
para atualizar o cadastro de professores vai ser puxada a função update_person(teachers, total_teachers, 2);
*/

int main(){
    register_person(1);
    list_students();
    update_person(students, total_students, 1);
    list_students();
    return 0;
}

/* 
    no menu, quando for registrar o aluno vai ser puxada a função register_person(1)
    quando for registrar o professor vai ser puxado a função register_person(2)

*/