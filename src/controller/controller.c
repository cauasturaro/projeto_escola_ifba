#include "controller.h"

void remover(void *array, int *total, size_t element_size)
{

    int id_remover;
    id_remover = read_int_option("", 0, *total - 1);

    if (id_remover < 0 || id_remover >= *total)
    {
        printf("ID inválido!\n");
    }

    for (int i = id_remover; i < *total - 1; i++)
    {
        void *dest = (char *)array + i * element_size;
        void *src = (char *)array + (i + 1) * element_size;
        memcpy(dest, src, element_size);
    }
    (*total)--;
}