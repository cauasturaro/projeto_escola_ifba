#define MAX_STR 5
#define TAM 3
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
        int code;
        int semester;
        struct Person teacher;
        struct Person students[TAM];
    };
