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

static SortAdapter current_sort_adapter;
static SortField current_field;

int comparar_entidades(const void *a, const void *b)
{
    const char *v1 = current_sort_adapter.get_field(a, current_field);
    const char *v2 = current_sort_adapter.get_field(b, current_field);
    return strcmp(v1, v2);
}

void ordenar(void *array, int total, size_t element_size, SortAdapter adapter, SortField field)
{
    current_sort_adapter = adapter;
    current_field = field;
    qsort(array, total, element_size, comparar_entidades);
}