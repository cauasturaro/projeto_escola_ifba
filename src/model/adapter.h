// Adapter

#ifndef ADAPTER_H
#define ADAPTER_H

typedef struct
{
    const char *(*getId)(const void *obj);  // ponteiro pra função que retornar um char (registration ou code)
    void (*print)(const void *obj, int id); // ponteiro pra função de exibição
} Adapter;

#endif
