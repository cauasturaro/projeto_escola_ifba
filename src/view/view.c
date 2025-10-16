#include <stdio.h>
#include <stdlib.h>

#include "view.h"

void list(const char *titulo, void *array, int total, size_t element_size, Adapter adapter)
{
    printf("\n%s\n", titulo);

    for (int i = 0; i < total; i++)
    {
        void *obj = (char *)array + i * element_size;
        adapter.print(obj, i);
    }
}
