#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include <time.h>
#include <ctype.h>

void string_to_uppercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            str[i] = str[i] - 'a' + 'A'; // to_uppercase(str[i]); msm coisa
        }
    }
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear"); // Linux / macOS
#endif
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pause_view()
{
    printf("Pressione ENTER para continuar...");
    getchar();
}

int validate_numeric_string(char numbers[])
{
    for (int i = 0; numbers[i] != '\0'; i++)
    {
        if (numbers[i] < '0' || numbers[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

SortAdapter current_sort_adapter;
SortField current_field;

int comparar_entidades(const void *a, const void *b)
{
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;

    if (current_field == SORT_BY_GENDER)
    {
        if (p1->gender == p2->gender)
            return 0;
        if (p1->gender == 'F')
            return -1; // F antes
        return 1;      // M depois
    }

    // resto da comparação usando strings, datas, etc.
    const char *v1 = current_sort_adapter.get_field(a, current_field);
    const char *v2 = current_sort_adapter.get_field(b, current_field);

    if (current_field == SORT_BY_BIRTH)
    {
        int d1, m1, y1, d2, m2, y2;
        sscanf(v1, "%d/%d/%d", &d1, &m1, &y1);
        sscanf(v2, "%d/%d/%d", &d2, &m2, &y2);

        if (y1 != y2)
            return y1 - y2;
        if (m1 != m2)
            return m1 - m2;
        return d1 - d2;
    }

    return strcmp(v1, v2);
}

void ordenar(void *array, int total, size_t element_size, SortAdapter adapter, SortField field)
{
    current_sort_adapter = adapter;
    current_field = field;
    qsort(array, total, element_size, comparar_entidades);
}

void gerar_numero_aleatorio(char *str, int length)
{
    for (int i = 0; i < length; i++)
        str[i] = '0' + rand() % 10;
    str[length] = '\0';
}

int read_int_option(const char *prompt, int min, int max)
{
    char buffer[8];
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            clearerr(stdin);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        int valid = 1;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!isdigit((unsigned char)buffer[i]))
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            printf("Entrada invalida! Digite apenas numeros.\n");
            continue;
        }

        value = atoi(buffer);

        if (value < min || value > max)
        {
            printf("Entrada fora do intervalo (%d-%d).\n", min, max);
            continue;
        }

        return value;
    }
}

// ----------------------------- DEV UTILS -----------------------------

void dev_add_students(void)
{
    if (total_students + 20 > MAX_PEOPLE)
    {
        printf("Erro! Não há espaço suficiente para adicionar 20 alunos.\n");
        pause_view();
        return;
    }

    for (int i = 0; i < 20; i++)
    {
        Person p;
        memset(&p, 0, sizeof(Person)); // limpa memória

        gerar_numero_aleatorio(p.registration, 11);

        snprintf(p.name, sizeof(p.name), "Aluno_%02d", total_students + 1);

        p.gender = (rand() % 2 == 0) ? 'M' : 'F';

        int dia = rand() % 28 + 1;
        int mes = rand() % 12 + 1;
        int ano = rand() % 30 + 1995; // 1995 a 2024
        snprintf(p.birth, sizeof(p.birth), "%02d/%02d/%04d", dia, mes, ano);

        gerar_numero_aleatorio(p.CPF, 11);

        students[total_students++] = p;
    }

    printf("\n20 alunos adicionados automaticamente com sucesso!\n");
    pause_view();
}

void dev_add_teachers(void)
{
    if (total_teachers + 20 > MAX_PEOPLE)
    {
        printf("Erro! Não há espaço suficiente para adicionar 20 professores.\n");
        pause_view();
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        Person p;
        memset(&p, 0, sizeof(Person));

        gerar_numero_aleatorio(p.registration, 11);

        snprintf(p.name, 26, "Professor_%02d", total_teachers + 1);

        p.gender = (rand() % 2 == 0) ? 'M' : 'F';

        int dia = rand() % 28 + 1;
        int mes = rand() % 12 + 1;
        int ano = rand() % 50 + 1965; // 1965 a 2014
        snprintf(p.birth, sizeof(p.birth), "%02d/%02d/%04d", dia, mes, ano);

        gerar_numero_aleatorio(p.CPF, 11);

        teachers[total_teachers++] = p;
    }

    printf("\n20 professores adicionados automaticamente com sucesso!\n");
    pause_view();
}

void dev_add_subjects(void)
{
    if (total_subjects + 5 > MAX_SUBJECTS)
    {
        printf("Erro! Não há espaço suficiente para adicionar 5 disciplinas.\n");
        pause_view();
        return;
    }

    if (total_teachers == 0)
    {
        printf("Nenhum professor disponivel. Adicione professores primeiro.\n");
        pause_view();
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        Subject s;
        memset(&s, 0, sizeof(Subject)); // limpeza

        snprintf(s.name, sizeof(s.name), "Disciplina_%d", total_subjects + 1);

        snprintf(s.code, sizeof(s.code), "INF%03d", total_subjects + 1);

        int sem = rand() % 12 + 1;
        snprintf(s.semester, sizeof(s.semester), "%d", sem);

        s.teacher = teachers[rand() % total_teachers];
        s.students_count = 0;

        memset(s.students, 0, sizeof(s.students));

        subjects[total_subjects++] = s;
    }

    printf("\n5 disciplinas adicionadas automaticamente com sucesso!\n");
    pause_view();
}

void dev_clear_students(void)
{
    total_students = 0;
    printf("\nTodos os alunos foram removidos!\n");
    pause_view();
}

void dev_clear_teachers(void)
{
    total_teachers = 0;
    printf("\nTodos os professores foram removidos!\n");
    pause_view();
}

void dev_clear_subjects(void)
{
    total_subjects = 0;
    printf("\nTodas as disciplinas foram removidas!\n");
    pause_view();
}

void dev_show_totals(void)
{
    printf("\n========= DADOS GERAIS =========\n");
    printf("Total de estudantes: %d\n", total_students);
    printf("Total de professores: %d\n", total_teachers);
    printf("Total de disciplinas: %d\n", total_subjects);
    printf("================================\n\n");

    pause_view();
}
