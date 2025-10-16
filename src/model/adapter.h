// Adapter

#ifndef ADAPTER_H
#define ADAPTER_H

typedef enum
{
    SORT_BY_NAME,
    SORT_BY_GENDER,
    SORT_BY_BIRTH,
    SORT_BY_REGISTRATION,
    SORT_BY_CODE,
    SORT_BY_SEMESTER,
    SORT_BY_STUDENT_COUNT,
    SORT_BY_STUDENT_CPF
} SortField;

typedef struct
{
    const char *(*get_field)(const void *obj, SortField field); // função que retorna de acordo com campo de ordenação escolhido
    void (*print)(const void *obj, int id);                     // função de exibição
} SortAdapter;

typedef struct
{
    const char *(*get_id)(const void *obj); // ponteiro pra função que retornar um char (registration ou code)
    void (*print)(const void *obj, int id); // ponteiro pra função de exibição
} ListagemAdapter;

#endif
