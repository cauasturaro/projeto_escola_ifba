#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

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
    clear_buffer();
    getchar();
}

void pause_view_without_clear_buffer()
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